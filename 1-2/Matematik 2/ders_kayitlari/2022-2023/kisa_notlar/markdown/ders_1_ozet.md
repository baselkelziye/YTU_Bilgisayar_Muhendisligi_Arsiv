# Ders 1 Çalışma Özeti

## Genel Konular

- Dönem tanışması ve motivasyon konuşması.
- Dönemin konu planı: diziler, seriler, Taylor ve Maclaurin serileri, serilerin uygulamaları, çok değişkenli fonksiyonlar (limit, türev, integral).
- Dizi (sequence) tanımı ve genel terim yazma.
- Sınırlı dizi, alt sınır, üst sınır, en büyük alt sınır (infimum, "ebas") ve en küçük üst sınır (supremum, "eküs").
- Monoton (artan ve azalan) diziler.
- Dizinin limiti, yakınsak (convergent) ve ıraksak (divergent) dizi.
- Limit kuralları, sandviç (sıkıştırma) teoremi, L'Hôpital kuralının dizilerde kullanımı.
- Monoton dizi teoremi ve sıkça kullanılan limitler.
- $1^\infty$ belirsizliği için pratik kural.
- Seriye (series) giriş: kısmi toplamlar dizisi, yakınsak ve ıraksak seri.
- Geometrik seri, $p$-serisi, harmonik seri, teleskopik seri.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dersi geçmek için değil, öğrenmek için dinleyin. Bilgiyi sorularla hafızaya yerleştirin.
- Dizi, tanım kümesi doğal sayılar olan bir fonksiyondur: $a:\mathbb{N}\to\mathbb{R}$. $a_{1/2}$ gibi bir terim olmaz.
- Dizinin karakterini sonlu sayıdaki terimler değil, sonsuz sayıdaki terimler belirler. İlk birkaç terim ne olursa olsun, kuyruk bir sayıya yaklaşıyorsa dizi yakınsaktır.
- $\sin x / x$ limiti ($x\to 0$) ile $\sin n / n$ limiti ($n\to\infty$) karıştırılmamalı. Birincisi $1$, ikincisi $0$'dır.
- $\sin(n\pi)$ bir dizidir ve her terimi $0$'dır, yani dizi $0$'a yakınsar. $\sin(\pi x)$ fonksiyonunun $x\to\infty$ için limiti ise yoktur. Fark $n$'nin doğal sayı olmasıdır.
- Sınav test şeklinde, yaklaşık 20 soru. İşlem hatası yapma lüksü yok. Bol soru çözün.
- Dönem başında Mat 1'i almadan Mat 2'ye geçen öğrenci 3-4 haftada tek değişkenli limit ve integral konularını telafi etmeli. Çok değişkenli fonksiyonlar konusu bu altyapıyı ister.

## Kısa Tekrar Notları

- Genel terim örnekleri:
  - $2, 4, 6, 8, \dots$ için $a_n = 2n$. 50. terim $100$, 77. terim $154$.
  - $1, \sqrt2, \sqrt3, \dots$ için $a_n=\sqrt n$.
  - $1, -\tfrac12, \tfrac13, -\tfrac14, \dots$ için $a_n = \dfrac{(-1)^{n+1}}{n}$.
- Sınırlı dizi: her $n$ için $|a_n|\le K$ olacak bir $K$ varsa dizi sınırlıdır.
- Monoton artan: her $n$ için $a_n < a_{n+1}$. Terimler pozitifse $\dfrac{a_{n+1}}{a_n} > 1$ ile de gösterilir.
- Yakınsak dizi sınırlıdır. Tersi doğru değildir: $(-1)^n$ sınırlıdır ama yakınsak değildir.
- Monoton dizi teoremi: monoton ve sınırlı dizi yakınsaktır.
- Sıkça kullanılan limitler ($n\to\infty$):
  - $\sqrt[n]{n} \to 1$
  - $x>0$ için $\sqrt[n]{x}\to 1$
  - $|x|<1$ için $x^n \to 0$
  - her $x$ için $\dfrac{x^n}{n!} \to 0$
  - $\left(1+\dfrac{x}{n}\right)^n \to e^x$
- $1^\infty$ kuralı: $a_n\to 0$, $b_n\to\infty$ ve $a_n b_n \to \lambda$ ise $(1+a_n)^{b_n} \to e^{\lambda}$.
- Seri: $\sum a_n$ serisinin kısmi toplamı $S_n = a_1+\dots+a_n$. $S_n\to S$ ise seri yakınsaktır ve toplamı $S$'dir.
- Geometrik seri: $\sum_{n=1}^{\infty} a r^{n-1}$. $|r|<1$ ise toplam $\dfrac{a}{1-r}$, $|r|\ge 1$ ise ıraksak.
- $p$-serisi: $\sum \dfrac{1}{n^p}$. $p>1$ ise yakınsak, $p\le 1$ ise ıraksak. Harmonik seri ($p=1$) ıraksaktır.

## Detaylı Açıklamalar

### Dersin açılışı

- Hoca kendini Matematik bölümünde fonksiyonel analiz alanında çalışan öğretim üyesi olarak tanıtıyor.
- Grup mekatronik mühendisliği öğrencilerinden oluşuyor. Derse yaklaşık 75-84 öğrenci katılıyor.
- Şubat 2023 depremleri sonrası dersler online (Zoom) yapılıyor.
- Hoca, araştırma alanında yaklaşım teorisi (approximation theory) ve Fourier, Laplace dönüşümleri gibi konulara değiniyor. MR cihazlarında bu dönüşümlerin kullanıldığını örnek veriyor.
- Konu başlıkları Matematik bölümünün sitesindeki servis dersleri sayfasında var.
- Kaynak olarak internetteki ders notlarını (YTÜ Matematik notları) gösteriyor. Hocanın yazdığı kitap henüz yayımlanmamış.

### Dizi

**Tanım**

- Belli bir kurala göre sıralanmış sayılar $a_1, a_2, a_3, \dots$ bir dizidir.
- $n$ sayısına indis denir, doğal sayıdır.
- Dizi, doğal sayılardan reel sayılara tanımlı bir fonksiyondur.

**Örnek 1 (işaret değiştiren dizi):** $1, -\tfrac12, \tfrac13, -\tfrac14, \dots$

- Paydalar $n$, yani mutlak değer $\dfrac1n$.
- İşaret bir artı, bir eksi gidiyor. $(-1)^n$ ilk terimi eksi yapar. Bu yüzden $(-1)^{n+1}$ kullanılır.
- Sonuç: $a_n=\dfrac{(-1)^{n+1}}{n}$.

**Dizilerle işlemler:** dizi bir sabitle çarpılınca her terim o sayıyla çarpılır. İki dizinin toplamı, farkı ve bölümü terim terim yapılır.

### Sınırlı diziler, ebas ve eküs

- Bir dizi hem alttan hem üstten sınırlıysa sınırlıdır.
- **Örnek 2:** $a_n=\dfrac1n$ için $0 < a_n \le 1$. Dizi sınırlıdır.
- **Örnek 3:** $a_n = 2n$ sınırsızdır. Terimler sonsuza gider.
- **Örnek 4:** $(-1)^n$ dizisi $-1$ ile $1$ arasında değer alır, sınırlıdır.
- En büyük alt sınır (ebas, infimum) ve en küçük üst sınır (eküs, supremum):
  - $(-1)^n$ için ebas $-1$, eküs $1$.
  - $a_n=\dfrac{n}{n+1}$ için terimler $\tfrac12, \tfrac23, \tfrac34, \dots$ Ebas $\tfrac12$, eküs $1$. Terimler $1$'e yaklaşır ama $1$'e ulaşmaz.
  - Üstten sınırsız, alttan $1$ ile sınırlı bir dizide eküs yoktur, ebas $1$'dir. Bu dizinin ifadesi altyazıda anlaşılmıyor.

### Monoton diziler

- $a_n<a_{n+1}$ ise monoton artan, $a_n>a_{n+1}$ ise monoton azalan.
- Geniş anlamda ($\le$ ile) artan diziye azalmayan, ($\ge$ ile) azalan diziye artmayan dizi denir.
- **Örnek 5:** $a_n=\dfrac{n}{n+1}$
  - $\dfrac{a_{n+1}}{a_n} = \dfrac{(n+1)^2}{n(n+2)} = \dfrac{n^2+2n+1}{n^2+2n} > 1$
  - Dizi monoton artandır.
- **Örnek 6:** $1, \tfrac12, \tfrac14, \tfrac18, \dots$ geometrik dizisi, ortak çarpan $\tfrac12$.
  - $\dfrac{a_{n+1}}{a_n} = \tfrac12 < 1$
  - Dizi monoton azalandır.

### Dizinin limiti

**Tanım**

- Dizinin sonlu sayıdaki terimleri hariç diğer bütün terimleri bir $L$ sayısının her $\varepsilon$-komşuluğunda toplanıyorsa dizi $L$'ye yakınsar.
- Gösterim: $\lim_{n\to\infty} a_n = L$.
- Limit tektir.
- Limit $+\infty$ ya da $-\infty$ ise ya da limit yoksa dizi ıraksaktır.

**Örnekler**

- $\dfrac1n \to 0$
- $\dfrac{n}{n+1} \to 1$
- $(-1)^n$: çift $n$ için $1$, tek $n$ için $-1$. Limit yok, dizi ıraksak.
- $1, 2, 3, \dots$ dizisi $+\infty$'a ıraksar.

**Limit kuralları:** $\lim a_n = A$ ve $\lim b_n = B$ ise

- $\lim(a_n \pm b_n) = A \pm B$
- $\lim (k\,a_n) = kA$
- $\lim (a_n b_n) = AB$
- $B\ne0$ ise $\lim \dfrac{a_n}{b_n} = \dfrac{A}{B}$

**Sandviç (sıkıştırma) teoremi**

- $a_n \le b_n \le c_n$ ve $\lim a_n = \lim c_n = L$ ise $\lim b_n = L$.

**Örnek 7:** $\lim\limits_{n\to\infty} \dfrac{\sin n}{n}$

- Derste öğrenciler $1$, $0$ ve "limit yok" cevaplarını verdi. Doğru cevap $0$.
- $-1\le \sin n\le 1$ olduğundan her tarafı $n$'ye bölünce $-\dfrac1n \le \dfrac{\sin n}{n} \le \dfrac1n$ olur.
- İki uç $0$'a gider. Sandviç teoreminden limit $0$.

**Örnek 8:** $\dfrac{\cos n}{n}$ dizisi aynı yolla $0$'a yakınsar.

**Örnek 9 (eşlenikle çarpma):** $a_n = \sqrt{n^2+2n} - n$

- Doğrudan yerine koyunca $\infty - \infty$ belirsizliği çıkar.
- Eşlenikle çarpılır: $a_n = \dfrac{2n}{\sqrt{n^2+2n}+n}$.
- $n\to\infty$ için limit $\dfrac{2}{1+1} = 1$.

**Örnek 10 (L'Hôpital):** $a_n=\dfrac{\ln n}{n}$

- $\dfrac{\infty}{\infty}$ belirsizliği var. $n$ yerine $x$ düşünülüp türev alınır: $\dfrac{1/x}{1}\to 0$.
- Dizi $0$'a yakınsar.

**Örnek 11 (sınav sorusu tarzı):** $\sin(n\pi)$

- Her doğal sayı $n$ için $\sin(n\pi)=0$. Dizi sabit $0$, yani $0$'a yakınsar.
- Bir öğrenci "$-1$ ile $1$ arasında değişir, limit yok" dedi. Bu cevap $\sin(\pi x)$ fonksiyonu için doğru, $\sin(n\pi)$ dizisi için yanlış.

**Örnek 12:** $\tfrac12, -\tfrac13, \tfrac1{20}, 200, \tfrac19, \tfrac1{99}, \tfrac1{999}, \dots$

- İlk terimler düzensiz, ama sonraki bütün terimler $0$'a yaklaşıyor.
- Sonlu sayıdaki terim dizinin karakterini değiştirmez. Dizi $0$'a yakınsar.

### Monoton dizi teoremi

- Monoton ve sınırlı dizi yakınsaktır.
- **Örnek 13:** $\dfrac{n}{n+1}$ dizisi $\tfrac12$ ile $1$ arasında sınırlı ve monoton artan. Bu yüzden yakınsaktır; limiti $1$'dir. Artan dizi üst sınırına yaklaşır.

### $1^\infty$ belirsizliği

**Kural:** $a_n\to0$, $b_n\to\infty$ ve $a_nb_n\to\lambda$ ise $(1+a_n)^{b_n}\to e^\lambda$.

**Örnek 14:** $\left(1+\dfrac{2}{5n}\right)^{3n}$

- $a_n = \dfrac{2}{5n}\to 0$, $b_n=3n\to\infty$.
- $a_nb_n = \dfrac{6n}{5n} = \dfrac65 = \lambda$.
- Sonuç $e^{6/5}$. Bir öğrenci $e^{-6/5}$ dedi. Hoca işaretin artı olduğunu doğruladı.

**Örnek 15:** $\left(-\tfrac12\right)^n$

- $\left|-\tfrac12\right|<1$ olduğundan $0$'a gider.
- Mantığı: $\dfrac{1}{2^n}$'de pay $1$, payda sonsuza gider.

- İki dizinin çarpımı şeklindeki bir örnekte hoca limiti, limit kurallarıyla parça parça alarak $6$ buldu. Dizinin tam ifadesi altyazıda anlaşılmıyor.

### Serilere giriş

**Top örneği**

- 10 m yükseklikten bırakılan top her seferinde düştüğü yüksekliğin yarısı kadar sekiyor.
- Top durur mu? Teorik olarak durmaz, sonsuz kez seker.
- Aldığı toplam yol bir seriyle hesaplanır. Hoca hesabı derste yapmadı. Hesap "Ders sonrası notlar" kısmında.

**Seri ve kısmi toplam**

- Bir dizinin bütün terimlerinin toplamı $\sum_{n=1}^\infty a_n$ seridir.
- Kısmi toplamlar: $S_1=a_1$, $S_2=a_1+a_2$, $S_3=a_1+a_2+a_3$, ..., $S_n=\sum_{k=1}^{n}a_k$.
- $\lim S_n = S$ sonluysa seri yakınsaktır, toplamı $S$'dir. $\pm\infty$ ise ya da limit yoksa seri ıraksaktır.
- Örnekler:
  - $1+\tfrac12+\tfrac13+\dots$ (harmonik seri) ıraksaktır.
  - $\sum \dfrac1{n^p}$: $p>1$ ise yakınsak, $p\le1$ ise ıraksak.

**Geometrik seri**

- Seri: $a + ar + ar^2 + \dots = \sum_{n=1}^\infty a r^{n-1}$.
- Kısmi toplam:
  - $S_n = a + ar + \dots + ar^{n-1}$
  - Her terim $r$ ile çarpılıp taraf tarafa çıkarılır.
  - Sonuç: $S_n = \dfrac{a(1-r^n)}{1-r}$
- $|r|<1$ ise $r^n\to0$ ve toplam $\dfrac{a}{1-r}$ olur. $|r|\ge1$ ise seri ıraksaktır.

**Örnek 16:** $1+\tfrac12+\tfrac14+\dots=\sum_{n=1}^\infty\left(\tfrac12\right)^{n-1}$

- $a=1$, $r=\tfrac12$.
- Toplam $\dfrac{1}{1-\frac12}=2$.

**Örnek 17 (çıkmış sınav sorusu):** $\pi - e + \dfrac{e^2}{\pi} - \dfrac{e^3}{\pi^2} + \dots$

- $\pi$ parantezine alınır: $\pi\left(1 - \dfrac e\pi + \dfrac{e^2}{\pi^2} - \dots\right)$.
- Genel terim: $\sum_{n=1}^\infty (-1)^{n-1}\,\pi\left(\dfrac{e}{\pi}\right)^{n-1}$.
- $a=\pi$, $r=-\dfrac e\pi$. $e\approx2{,}71$ ve $\pi\approx3{,}14$ olduğundan $|r|<1$.
- Toplam: $\dfrac{\pi}{1+\frac e\pi} = \dfrac{\pi^2}{\pi+e}$.

**Örnek 18:** $1+\sqrt2+2+2\sqrt2+\dots$

- $r=\sqrt2>1$. Seri $+\infty$'a ıraksar.

### Teleskopik ve harmonik seriler

- Terimleri basit kesirlere ayrılıp fark şeklinde yazılabilen seriye teleskopik seri denir. Açılınca ara terimler birbirini götürür.

**Örnek 19:** $\sum_{k=1}^\infty \dfrac{1}{k(k+1)}$

- Terim fark şeklinde yazılır: $\dfrac1{k(k+1)} = \dfrac1k - \dfrac1{k+1}$.
- Kısmi toplam: $S_n = 1 - \dfrac{1}{n+1}$.
- $n\to\infty$ için $S_n\to1$. Toplam $1$.

**Örnek 20:** $\sum \dfrac{1}{k^2+3k+2}$

- Payda çarpanlara ayrılır: $\dfrac1{(k+1)(k+2)} = \dfrac1{k+1}-\dfrac1{k+2}$. Basit kesir katsayıları $A=1$, $B=-1$.
- Terimler açılınca baştan bir terim, sondan bir terim kalır.
- Hoca sonucu söylüyor ama serinin hangi $k$ değerinden başladığı altyazıda net değil. "Ders sonrası notlar" kısmına bakın.

**Örnek 21 (logaritmalı teleskopik seri, sınav sorusu):**

- Logaritmanın özellikleri kullanılarak terimler $\ln$ içinde çarpım şekline getirilir. Çarpımlar sadeleşir.
- Kısmi toplam $\ln\dfrac{n+1}{2n}$ biçiminde çıkar.
- Limit $\ln$ içine alınır: $\dfrac{n+1}{2n}\to\tfrac12$. Sonuç $\ln\tfrac12$.
- Serinin tam ifadesi altyazıda anlaşılmıyor.

**Seri işlemleri:** $\sum a_n = A$ ve $\sum b_n = B$ ise

- $\sum (a_n \pm b_n) = A\pm B$
- $\sum k a_n = kA$

### Duyurular

- Sınavlar test şeklinde olacak, yaklaşık 20 soru.
- Sınavların online mı yüz yüze mi olacağı belli değil. Nisan başında bir değerlendirme yapılacak. Hoca, derslerin online, sınavların yüz yüze olmasını beklediğini ama bunun kesin olmadığını söyledi.
- Gelecek ders: serilere devam, yakınsaklık testleri ve uygulama soruları. Ardından Taylor ve Maclaurin serileri. Diziler ve seriler 2-3 haftada bitecek.

### Ders sonrası notlar

- **Laurent serisi:** Hoca dönem konularını sayarken "Laurent ve Taylor serileri" diyor. Laurent serisi karmaşık analiz konusudur. Matematik 2'de Taylor ve Maclaurin serileri işlenir.
- **Aritmetik dizi:** Bir öğrenci monoton diziyi "artış miktarı sabit dizi" diye tanımladı ve hoca onayladı. Bu tanım aritmetik dizinin tanımıdır. Monoton artan dizide artış miktarının sabit olması gerekmez, yalnız her terimin bir öncekinden büyük olması yeter.
- **Sabit dizi:** Hoca sabit dizinin monoton olmadığını onayladı. Kesin anlamda (strictly) artan ya da azalan değildir, bu doğru. Ama geniş anlamda hem artmayan hem azalmayan olduğu için çoğu kitapta monoton sayılır. Ayrıca sabit dizi sınırlıdır ve yakınsaktır.
- **"Gerekli ve yeterli koşul":** Hoca monoton dizi teoremini "monotonluk ve sınırlılık yakınsaklık için gerekli ve yeterli koşul" diye okudu. Bu koşul yalnız yeterlidir, gerekli değildir. Örneğin $\dfrac{(-1)^n}{n}$ dizisi $0$'a yakınsar ama monoton değildir. Monoton bir dizi için ise "yakınsak ⇔ sınırlı" doğrudur.
- **$x^n$ limiti:** Hoca "$x$ bir ya da birden büyükse ıraksaktır" dedi. $x=1$ için $1^n=1$ olur ve dizi $1$'e yakınsar. Doğrusu:
  - $|x|<1$ ise $0$'a yakınsar.
  - $x=1$ ise $1$'e yakınsar.
  - $x>1$ ise $+\infty$'a ıraksar.
  - $x\le-1$ ise ıraksar.
- **Geometrik seri toplamı:** Hoca bir yerde toplamı "$r$ bölü $1-r$" diye söyledi, sonra örnekte ilk terim bölü $(1-r)$ kullandı. Doğru formül $\dfrac{a}{1-r}$, burada $a$ ilk terimdir.
- **Örnek 17'de işaret:** Hoca önce $1-r$ yazdı, bir öğrenci uyarınca $1+\frac e\pi$ olarak düzeltti. Doğru sonuç $\dfrac{\pi^2}{\pi+e}$.
- **Top örneğinin hesabı:**
  - İlk düşüş $10$ m.
  - Sonra her sekmede çıkış ve iniş var: $2(5+2{,}5+1{,}25+\dots) = 2\cdot\dfrac{5}{1-\frac12} = 20$ m.
  - Toplam yol $30$ m. Bir öğrencinin önerdiği $20$ m yalnız sekmelerin yoludur, ilk düşüşü içermez.
- **Örnek 20'nin sonucu:**
  - Seri $k=1$'den başlarsa $S_n = \tfrac12 - \dfrac1{n+2}$ olur, toplam $\tfrac12$.
  - $k=0$'dan başlarsa toplam $1$ olur. Hoca "1 kaldı" diyor; serinin $k=0$'dan başladığı düşünülebilir.
- **Örnek 21:** Kısmi toplamı $\ln\frac{n+1}{2n}$ olan bilinen seri $\sum_{n=2}^\infty \ln\left(1-\dfrac1{n^2}\right)$'dir. Toplamı $\ln\tfrac12=-\ln2$.
- **Ödev olarak kalan soru:** "$0{,}\overline{32}$ sayısını iki tam sayının oranı olarak yazınız" derste çözülmedi. Çözüm:
  - $0{,}\overline{32} = \dfrac{32}{100}+\dfrac{32}{100^2}+\dots$ bir geometrik seridir.
  - $a=\dfrac{32}{100}$, $r=\dfrac1{100}$.
  - Toplam $\dfrac{32/100}{1-1/100}=\dfrac{32}{99}$.

Gemini Notebook notu: İsterseniz bu özeti ve ders kaydını Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
