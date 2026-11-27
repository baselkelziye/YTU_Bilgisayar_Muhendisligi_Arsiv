# Ders 5 Çalışma Özeti

## Genel Konular

- Algoritma analizinin amacı ve iki yaklaşım
  - Algoritma analizi, aynı problemi çözen farklı yöntemlerin başarımını (performansını) ölçmeye ve karşılaştırmaya yarayan araçları sunan bir bilgisayar bilimi alanıdır.
  - Üç amaç: tek bir algoritmanın performansını ölçmek, farklı algoritmaları karşılaştırmak, bulunan çözümden daha iyisinin mümkün olup olmadığını araştırmak.
  - Empirik analiz: algoritmalar aynı dilde kodlanır, aynı ortamda çalıştırılır ve işletim süreleri karşılaştırılır. Bu yöntem algoritmayı değil programı (gerçeklemeyi) ölçer.
  - Teorik analiz: başarımı gerçekleştirimden, bilgisayardan ve veriden bağımsız değerlendiren matematiksel yöntemlerdir (ekrandan, 00:20:00).
- Algoritmaların işletim süresi (maliyet hesabı)
  - Her işlemin (atama, aritmetik işlem, karşılaştırma) sabit bir maliyeti vardır: $c_1, c_2, \dots$ Toplam maliyet = her satırın maliyeti × tekrar sayısı.
  - Ardışık komutlarda maliyetler toplanır; `if-else` yapısında $c_1 + \max(c_2, c_3)$ alınır.
  - Basit döngü: toplam maliyet $c_1 + c_2 + (n+1)c_3 + n c_4 + n c_5$, yani süre $n$ ile doğru orantılıdır (ekrandan, 00:25:00).
  - İç içe döngü: toplam maliyet $c_1 + c_2 + (n+1)c_3 + n c_4 + n(n+1)c_5 + n^2 c_6 + n^2 c_7 + n c_8$, yani süre $n^2$ ile doğru orantılıdır (ekrandan, 00:30:00).
- Büyüme oranı (growth rate)
  - Çalışma süresinin girdi boyutu $n$'ye göre ne hızla arttığıdır. Ne kadar yavaş büyürse algoritma o kadar iyidir.
  - Örnek: A algoritması $n^2/5$, B algoritması $5n$ birim zaman ister; küçük $n$'de A daha hızlı görünse de büyük $n$'de B her zaman kârlıdır.
  - Yaygın büyüme oranları: sabit, logaritmik, logaritmik kare, doğrusal, doğrusal logaritmik, kare, kübik, üstel, faktöriyel (ekrandan, 00:55:00).
- Döngülerin büyüme oranları (ekrandan, 01:15:00 ve 01:20:00)
  - `i++` ile $n$ adım: doğrusal; `i+=2` ile $n/2$ adım: yine doğrusal; `i*=2` ile $\log n$ adım: logaritmik.
  - İki bağımsız iç içe döngü: $n^2$ (kuadratik); iç döngü dış sayaca bağlıysa yaklaşık $n^2/2$ (bağımlı kuadratik); iç döngü çarparak ilerliyorsa $n \log n$.
- Büyük O gösterimi ve algoritma seviyesi
  - Büyüme oranı $g(n)$ olan algoritmanın karmaşıklığı $O(g(n))$ diye yazılır.
  - Örnek: $n^2 - 3n + 10$ fonksiyonu için $k = 3$, $n_0 = 2$ seçilirse $n \ge 2$ olan her $n$ için $3n^2 \ge n^2 - 3n + 10$ olur. Bu yüzden algoritma $O(n^2)$'dir (ekrandan, 01:45:00).
  - $O$ üstten, $\Omega$ alttan, $\Theta$ hem alttan hem üstten sınırlar (ekrandan, 01:50:00).
  - Eşitsizlikteki $\ge$ yerine $>$ konursa küçük $o$ ve küçük $\omega$ gösterimleri elde edilir.
- Büyük O özellikleri (ekrandan, 01:55:00)
  - Düşük seviyeli terimler ve sabit çarpanlar atılır; $O(f(n)) + O(g(n)) = O(f(n) + g(n))$; çarpmada da aynı kural geçerlidir.
  - Derste daha önce hesaplanan basit döngü $an + b \Rightarrow O(n)$, iç içe döngü $an^2 + bn + c \Rightarrow O(n^2)$, üç bağımlı iç içe döngü $\Rightarrow O(n^3)$.
- Özyinelemeli algoritmalarda büyük O
  - Özyinelemeli fonksiyonun süresi $T(n)$ kendisi cinsinden yazılır. Buna yineleme denklemi (recurrence equation) denir.
  - Özyinelemeli Fibonacci: $T(n) = T(n-1) + T(n-2) + c$. $T(n-1) \approx T(n-2)$ kabulüyle $T(n) \approx 2^n$, yani $O(2^n)$ (ekrandan, 02:25:00).
  - Çağrı ağacı: `fib(6)` için aynı alt problemler tekrar tekrar hesaplanır (ekrandan, 02:30:00).
  - Önceki iki değeri tutarak ilerleyen yinelemeli (iteratif) çözüm $O(n)$'dir.
- En kötü, en iyi ve ortalama durum analizi (ekrandan, 02:40:00)
  - En kötü durum azami süredir ve üst sınır verir. En iyi durum asgari süredir ve çok kullanışlı değildir. Ortalama durumu belirlemek çoğunlukla zordur.
  - Algoritmalar karşılaştırılırken en çok en kötü durum kullanılır. Bu derste de en kötü durum analizi yapılacaktır.
- Sıralı arama ve ikili arama
  - Sıralı arama: bulunamazsa $O(n)$; en iyi durum $O(1)$; en kötü ve ortalama durum $O(n)$ (ekrandan, 02:45:00).
  - İkili arama (dizi sıralıysa): eleman yoksa $\lfloor \log_2 n \rfloor + 1$ yineleme, yani $O(\log n)$; en iyi durum $O(1)$ (ekrandan, 02:50:00).
- Zaman ve bellek (uzay) karmaşıklığı
  - Bu derste yalnız zaman karmaşıklığı hesaplandı. Bellek ihtiyacı da büyük O ile ifade edilebilir. İkisi arasındaki ödünleşime space-time trade-off denir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Empirik ölçüm algoritmayı değil, gerçeklemeyi ölçer.
  - Kodlama biçimi, programcının stili, bilgisayar ve o an arka planda çalışan işlemler (kesmeler, ağ trafiği, güncelleme) sonucu etkiler. Analiz bunlardan bağımsız olmalıdır.
- Önemli olan küçük $n$ değil, büyük $n$ bölgesidir.
  - Küçük girdilerdeki milisaniyelik kazanç önemsizdir. $n$'nin ne kadar büyüyeceği bilinemediği için büyüme oranı küçük olan algoritma tercih edilir.
- Logaritmaların tabanı 2'dir.
  - Derste ve kaynaklarda $\log n$ ya da $\lg n$ yazılınca $\log_2 n$ kastedilir.
- $2^n$ ve $n!$ kabul edilemez büyüme oranlarıdır.
  - Hoca $2^n$ görünce "korkun, kaçın" dedi; faktöriyel karmaşıklık pratikte çözümsüzlük demektir.
- Bu derste en kötü durum (büyük O) kullanılacaktır.
  - Büyük O, "bu mertebenin üzerine çıkamam" garantisini verir.
- Yazması kolay özyinelemeli çözüm her zaman iyi değildir.
  - İki satırlık özyinelemeli Fibonacci $O(2^n)$ iken önceki iki değeri tutan yinelemeli çözüm $O(n)$'dir.
- İkili aramanın tek şartı dizinin sıralı olmasıdır.
  - Sıralı yaklaşık 80 milyon kayıt içinde bile yaklaşık 27 karşılaştırma yeter.

## Kısa Tekrar Notları

- Teorik analiz: önemli işlemleri say, sonra büyüme fonksiyonuyla ifade et.
- Döngüde maliyet = tekrar sayısı × döngü gövdesinin maliyeti; `while (i <= n)` koşulu $n+1$ kez denetlenir.
- `if-else`: koşul maliyeti + iki koldan maliyetli olanı.
- `i++` ve `i+=2`: $O(n)$; `i*=2`: $O(\log n)$.
- İki iç içe döngü $O(n^2)$, üç iç içe döngü $O(n^3)$; içte çarparak ilerleyen döngü $O(n \log n)$.
- $f(n) = O(g(n))$: $n \ge n_0$ için $f(n) \le k\,g(n)$ olacak şekilde $k$ ve $n_0$ vardır.
- $\Omega$ alt sınır, $\Theta$ hem alt hem üst sınır.
- Büyük O'da düşük terimler ve sabit çarpanlar atılır: $O(n^3 + 4n^2 + 3n) = O(5n^3) = O(n^3)$.
- Özyinelemeli Fibonacci $O(2^n)$, yinelemeli Fibonacci $O(n)$.
- Sıralı arama $O(n)$, ikili arama $O(\log n)$ (sıralı dizi şart).
- $n = 1.048.576$ için $\log_2 n = 20$; $n \approx 10^9$ için 30.

## Detaylı Açıklamalar

- **Maliyet hesabının mantığı.** Bir komutun makine düzeyindeki karşılığı belirli bir mimaride sabit sayıda saat çevrimi sürer. Bu yüzden her satıra bir sabit maliyet ($c_i$) verilir ve satırın kaç kez çalıştığı sayılır. Basit döngü örneğinde `i = 1` ve `sum = 0` birer kez, `while (i <= n)` koşulu $n+1$ kez (çıkış için son bir denetim gerekir), döngü gövdesindeki iki satır $n$ kez çalışır. Sabitler bir büyük $C$ altında toplanınca maliyet $C_1 n + C_2$ biçimine gelir; bu da doğrusal büyüme demektir. İç içe döngüde iç bloğun her satırı dış döngünün $n$ çarpanını da taşır. Bu yüzden $n^2$ terimleri ortaya çıkar. $n = 1000$ girdi için yaklaşık 1 milyon işlem gerekir.
- **Döngü artım biçiminin etkisi.** `for (i=0; i<1000; i+=2)` döngüsü $0, 2, 4, \dots, 998$ değerleriyle 500 kez döner. Bu $n/2$ demektir; katsayı küçülse de büyüme doğrusaldır. `for (i=1; i<=1000; i*=2)` döngüsü $1, 2, 4, \dots, 512$ değerleriyle yalnız 10 kez döner (1024, sınırı aştığı için çalışmaz). Başlangıç değeri 1'dir; 0 olsaydı çarpma hep 0 verir ve döngü sonsuz olurdu. İç döngü `j < i` koşuluyla dış sayaca bağlanınca iç döngü 0, 1, 2, ... kez döner ve toplam işlem kabaca $n^2/2$ olur. Bu hâlâ $n^2$ mertebesidir ama daha yavaş büyür.
- **Büyüme oranlarının sayısal karşılaştırması.** Slayttaki tabloda (ekrandan, 01:40:00) $\log_2 n$ değeri $n = 10, 100, \dots, 10^6$ için 3, 6, 9, 13, 16, 19'dur. $n \log_2 n$ 30, 664, 9.965, $10^5$, $10^6$, $10^7$; $n^2$ $10^2$'den $10^{12}$'ye; $n^3$ $10^3$'ten $10^{18}$'e çıkar. $2^n$ ise $n = 10^6$ için $10^{301.030}$ mertebesine ulaşır. Hoca $n = 10.000$ için şu kaba süreleri verdi: $\log n$ yaklaşık 13 yineleme (mikrosaniyeler), $n$ saniyeler, $n \log n$ yaklaşık 140 bin işlem (saniyeler), $n^2$ $10^8$ işlem (dakikalar), $n^k$ saatler, $2^n$ "felaket", $n!$ "ölümcül".
- **Büyük O'nun tanımı ve grafikle yorumu.** $f(n) = n^2 - 3n + 10$ için $k = 3$ ve $n_0 = 2$ alınırsa, $n \ge 2$ olan her değerde $3n^2$ eğrisi $f(n)$'nin üstünde kalır (ekrandan, 01:45:00). $n_0$'dan önce fonksiyonlar istediği gibi davranabilir; önemli olan $n_0$'dan sonrasıdır. Büyük O fonksiyona bir tavan koyar. Büyük $\Omega$ bir taban koyar: $f(n) \ge k\,g(n)$. Büyük $\Theta$ ise iki sabitle iki taraftan sıkıştırır: $k_1 g(n) \le f(n) \le k_2 g(n)$.
- **Özyinelemeli Fibonacci'nin çözümü.** Slayttaki kod (ekrandan, 02:15:00):

  ```c
  int fib(int n)
  {
     if (n <= 1)
        return n;
     return fib(n - 1) + fib(n - 2);
  }
  ```

  Yineleme denklemi $T(n) = T(n-1) + T(n-2) + c$'dir. $T(n-1) \ge T(n-2)$ olduğundan $T(n-2)$ yerine $T(n-1)$ yazmak üstten sınırlamadır: $T(n) \le 2T(n-1) + c$. Açılınca $4T(n-2) + 3c$, $8T(n-3) + 7c$ ve genel olarak $2^k T(n-k) + (2^k - 1)c$ bulunur. $k = n$ alınırsa $T(n) = 2^n T(0) + (2^n - 1)c = 2^n(1 + c) - c$ olur, yani $O(2^n)$ (ekrandan, 02:25:00). Çağrı ağacında `fib(6)` için toplam 15 çağrı yapılır; `fib(2)` 5 kez, `fib(3)` ve `fib(1)` 3'er kez, `fib(4)` 2 kez hesaplanır (ekrandan, 02:30:00).
- **Arama algoritmaları.** Sıralı aramada `1 1 2 3 5 8 13 21 34` dizisinde 25 aranırsa 9 elemanın hepsine bakılır ve $-1$ döner; 1 aranırsa ilk adımda bulunur (ekrandan, 02:45:00). İkili aramada önce ortadaki 5'e bakılır, 25 daha büyük olduğu için sol yarı atılır; sonra 13, 21 ve 34'e bakılır ve 4 karşılaştırmada "yok" denir. 7 elemanlı bir dizide her konum için yineleme sayıları `3 2 3 1 3 2 3`, ortalaması $17/7 \approx 2{,}43 < \log_2 7$'dir (ekrandan, 02:50:00).

<!-- BELİRSİZ: 00:47 civarında anlatılan iki algoritmanın n = 10 ... 10^6 için süre tablosunun karesi okunmadı; değerler yalnız altyazıdan izlendi. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
