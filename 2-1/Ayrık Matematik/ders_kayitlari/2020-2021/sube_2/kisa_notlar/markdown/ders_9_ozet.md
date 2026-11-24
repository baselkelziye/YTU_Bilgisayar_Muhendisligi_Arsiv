# Ders 9 Çalışma Özeti

## Genel Konular

- Birinci ara sınav sorularının çözümü
  - Lojik devre tasarımı sorusu: dört ulaşım türünden (demiryolu $D$, karayolu $K$, denizyolu $D_z$, havayolu $H$) izin verilen birleşimlerde 1 veren dört girişli, tek çıkışlı devre (ekrandan, 00:15:00).
    - Doğruluk tablosunda 1 olan mintermler: $m_4, m_8, m_9, m_{10}, m_{12}, m_{14}$.
    - Bool cebri ile sadeleştirme ve 4x4 Karnaugh haritası ile doğrulama; iki yöntem aynı sonucu verir: $F = DH' + DK'D_z' + KH'D_z'$ (ekrandan, 00:25:00).
  - Çalışma zamanı sorusu: üç iç içe döngülü bir fonksiyon için $T(n)$ fonksiyonunun kurulması ve Big-O ile ifadesi (ekrandan, 00:45:00).
    - Sonuç: $T(n) = n^2\log n + \frac{n^2}{4} + 4n + 3 \in O(n^2 \log n)$.
  - Önermeleri Türkçe cümleye çevirme sorusu: $p \rightarrow \neg r$ ve $\neg q \leftrightarrow r$ (ekrandan, 00:10:00).
    - Bir önermenin değilini almak, koşullu önermeyi değiştirir; soruda olmayan bir değil eklenmez.
- Asimptotik gösterim örnekleri
  - $4^n \in O(8^n)$: $4^n \le c\cdot 8^n$ eşitsizliği $n \ge 2$ için $c = 1/4$ ile sağlanır.
  - $x^3 + 5x \notin O(x^2)$: hiçbir sabit $c$ için $x^3 + 5x \le c x^2$ büyük $x$ değerlerinde sağlanmaz (ekrandan, 00:55:00).
  - Limit yöntemi: $\lim_{n\to\infty} f(n)/g(n)$ değeri $0$, sabit ya da $\infty$ çıkmasına göre $f$, $g$'den küçük, onunla aynı mertebede ya da büyüktür. Belirsizlikte L'Hôpital kuralı kullanılır.
- Öz yinelemeli (recursive) algoritmaların analizi
  - Öz yinelemeli fonksiyon kendini daha küçük bir girdiyle çağırır; sonsuz çağrıyı bir temel durum (if koşulu ve return) durdurur.
  - Böl ve yönet (divide and conquer) ile azalt ve yönet (decrease and conquer) yaklaşımlarında sık görülür.
  - Analiz adımları: girdi boyutu, temel işlem, durum analizi (en kötü, en iyi, ortalama), temel işlem sayısı için rekürans bağıntısının kurulması ve çözülmesi, sonucun asimptotik gösterimle yazılması.
  - Örnekler: $1$'den $n$'e toplam ($f(n) = n + f(n-1)$), faktöriyel ($T(n) = T(n-1) + 3$), Fibonacci.
- Rekürans bağıntısı çözüm yöntemleri
  - İleri yerine koyma (forward substitution): ilk terimlerden örüntü tahmin edilir, sonra denetlenir (ekrandan, 01:40:00).
  - Geri yerine koyma (backward substitution): $T(n)$ geriye doğru açılıp $k$ adım sonraki genel biçim bulunur; $k$ temel duruma ulaşacak şekilde seçilir.
  - Öz yineleme ağacı (recursion tree) yöntemi: her seviyenin maliyeti toplanır, ağacın derinliği bulunur (ekrandan, 01:55:00).
  - Ana teorem (master theorem): $T(n) = aT(n/b) + f(n)$, $f(n) \in \Theta(n^d)$ biçimli bağıntılar için.
  - Karakteristik denklem yöntemi: ikinci ve daha yüksek dereceli, sabit katsayılı doğrusal bağıntılar için.
- Rekürans bağıntılarının sınıflandırılması (ekrandan, 02:25:00)
  - Mertebe (derece): en geriye giden terime göre belirlenir.
  - Homojenlik: yalnız $a_n$'li terimler varsa homojendir; sabit, $n$'li ya da üstel ek terim homojenliği bozar.
  - Doğrusallık: $a_n$'li terimler birbiriyle çarpılıyor ya da kuvveti alınıyorsa doğrusal değildir.
  - Sabit ya da değişken katsayı: $a_n$'li terimlerin katsayısı $n$'e bağlıysa değişken katsayılıdır.
- Karakteristik denklemle çözüm (ekrandan, 02:30:00)
  - Farklı kökler: $a_n = c_1 r_1^n + c_2 r_2^n$; eşit kökler: $a_n = c_1 r^n + c_2 n r^n$.
  - Üçüncü derece için de benzer kurallar vardır; tekrar eden köke $n$, $n^2$ çarpanı eklenir.
  - Homojen olmayan bağıntılarda homojen çözüme bir özel çözüm eklenir (ekrandan, 02:35:00).
  - Fibonacci: $r^2 = r + 1$, kökler $\frac{1\pm\sqrt5}{2}$, $F_n = \frac{1}{\sqrt5}\left(\frac{1+\sqrt5}{2}\right)^n - \frac{1}{\sqrt5}\left(\frac{1-\sqrt5}{2}\right)^n$.
- Sayı dizilerini rekürans bağıntısına dönüştürme (ekrandan, 02:40:00)
  - $4, 7, 13, 25, 49, 97, \dots$: $a_0 = 4$, $a_n = 2a_{n-1} - 1$.
  - $1, 3, 7, 17, 41, 99, 239, \dots$: $a_0 = 1$, $a_1 = 3$, $a_n = 2a_{n-1} + a_{n-2}$.
- Böl ve yönet algoritmaları: ikili arama, birleştirerek sıralama (merge sort), en yakın nokta çifti (closest pair); hepsi ana teoremle çözülür.
- Problemlerin zorluğu: çözülebilir (tractable), şu an çözülemeyen (intractable) ve hiç çözülemeyen problemler; P, NP, NP-tam ve NP-zor sınıfları (ekrandan, 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- $2^k = n \Rightarrow k = \log_2 n$ kuralı
  - Döngü sayacı ya da problem boyutu her adımda ikiye katlanıyor ya da yarıya iniyorsa adım sayısı $\log_2 n$ olur. Hoca bu kuralı çok iyi bilmek gerektiğini, karşınıza çıkacağını söyledi.
- İç içe döngülerde çağrı sayısı
  - İçteki döngünün başlatma işlemi, dıştaki döngünün dönme sayısı kadar yapılır. En içteki döngü, dıştaki döngülerin dönme sayılarının çarpımı kadar çağrılır.
- Karnaugh haritasında gruplama
  - Önce mümkün olan en büyük grup ($2^4$, $2^3$, $2^2$) aranır; tek kalan 1'ler mutlaka bir ikili gruba dahil edilmeye çalışılır. Satır ve sütun etiketleri $00, 01, 11, 10$ (Gray kodu) sırasıyla yazılır.
- Ana teoremde $f(n)$ polinom olmalı
  - $n^0, n^1, n^2, n^3$ olabilir; $2^n$ gibi üstel bir fonksiyon olamaz. Derece $d$ bulunurken katsayıya bakılmaz ($4n$ için $d = 1$).
- Rekürans soruları
  - Hoca, bu konudan gelecek soruların genelde hazır verilmiş bir rekürans bağıntısını çözmek olacağını, homojen olmayan bağıntıların özel çözüm kısmına odaklanmak gerekmediğini söyledi; asıl çalışılması gereken homojen çözümdür.
- Merge sort ve bellek
  - Merge sort sıralamayı $n^2$'den $n\log n$'e indirir, ama ek diziler gerektirdiği için daha çok bellek kullanır.

## Kısa Tekrar Notları

- `for (i = 0; i < n; i++)` $n$ kez, `for (i = 1; i < n; i *= 2)` yaklaşık $\log_2 n$ kez döner.
- Sınavdaki fonksiyonda dıştaki iki döngü $n/2$'şer, en içteki döngü $\log n$ kez döner; `sayac++` yaklaşık $\frac{n^2}{4}\log n$ kez çalışır; sonuç $O(n^2\log n)$.
- $T(n) = T(n-1) + 1$, $T(1) = 1$ ise $T(n) = n$; $T(n) = T(n-1) + 3$, $T(0) = 1$ ise $T(n) = 3n + 1$.
- $T(n) = T(n/2) + 1$, $T(1) = 1$ ise $T(n) = \log_2 n + 1 \in \Theta(\log n)$ (ikili arama).
- $T(n) = 2T(n/2) + 4n$ ise üç yöntem de $\Theta(n\log n)$ verir.
- Ana teorem: $a < b^d \Rightarrow \Theta(n^d)$; $a = b^d \Rightarrow \Theta(n^d\log n)$; $a > b^d \Rightarrow \Theta(n^{\log_b a})$.
- Karakteristik denklem: $a_n$ yerine $r^k$, $a_{n-1}$ yerine $r^{k-1}$ ... yazılır; kökler bulunur; başlangıç koşullarından $c_1, c_2$ hesaplanır.
- Homojen olmayan bağıntı: $a_n = a_n^{(h)} + a_n^{(\text{ö})}$; sabit ek terim için özel çözüm $A$, $n$'e bağlı doğrusal terim için $An + B$ diye tahmin edilir.
- P: polinom zamanda çözülebilen problemler. NP: çözümü polinom zamanda denetlenebilen problemler. Durma problemi (halting problem) hiçbir algoritmayla çözülemez.

## Detaylı Açıklamalar

- **Lojik devre sorusu.** Dört giriş ($D, K, D_z, H$) ve bir çıkış ($F$) vardır. Doğruluk tablosunda izin verilen durumlar (yalnız karayolu, yalnız demiryolu, hava ve demir, kara ve demir, deniz ve demir, deniz-kara-demir) $m_4 = D'KD_z'H'$, $m_8 = DK'D_z'H'$, $m_9 = DK'D_z'H$, $m_{10} = DK'D_zH'$, $m_{12} = DKD_z'H'$, $m_{14} = DKD_zH'$ mintermlerine karşılık gelir (ekrandan, 00:20:00). Bool cebrinde önce $m_8, m_{10}, m_{12}, m_{14}$'ten $DH'$ ortak çarpanı alınır; parantez içindeki $K'D_z' + K'D_z + KD_z' + KD_z$ ifadesi $K$ ve $D_z$'nin bütün birleşimlerini içerdiği için 1'dir. Kalan $DH' + D'KD_z'H' + DK'D_z'H$ ifadesinde $H'$ parantezine alınıp $x + x'y = x + y$ kuralı iki kez uygulanır ve $F = DH' + DK'D_z' + KH'D_z'$ elde edilir (ekrandan, 00:25:00). Karnaugh haritasında satırlar $DK$, sütunlar $D_zH$ ile etiketlenir. $D = 1$ satırlarında $H = 0$ olan dört köşe hücresi bir dörtlü grup oluşturur ($DH'$). $m_4$ ile $m_{12}$ ikili grubu $KD_z'H'$, $m_8$ ile $m_9$ ikili grubu $DK'D_z'$ verir.
- **Çalışma zamanı sorusu.** Ekrandaki fonksiyon (ekrandan, 00:10:00):

  ```c
  void function(int n)
  {
      int sayac = 0;
      for (int i = n/2; i <= n; i++)
          for (int j = 1; j + n/2 <= n; j = j++)
              for (int k = 1; k <= n; k = k * 2)
                  sayac++;
  }
  ```

  Dış döngü $n/2$'den $n$'e gider, yaklaşık $n/2$ kez döner. Ortadaki döngüde $j + n/2 \le n$ koşulu $j \le n/2$ demektir; o da $n/2$ kez döner. En içteki döngü $k = 1, 2, 4, \dots, 2^k \le n$ olduğu için $\log_2 n$ kez döner. Her işlem (atama, toplama, bölme, karşılaştırma, artırma) ayrı sayılır: dış döngüde $1 + 1 + n/2 + n/2$, ortadaki döngü $n/2$ kez başlatıldığı için $n/2$'li terimler, en içteki döngü $n^2/4$ kez başlatıldığı için $\frac{n^2}{4}$ atama ve $\frac{n^2}{4}\log n$'li karşılaştırma, çarpma-atama ve `sayac++` terimleri çıkar. Toplam $T(n) = 4\cdot\frac{n^2}{4}\log n + \frac{n^2}{4} + 8\cdot\frac{n}{2} + 3 = n^2\log n + \frac{n^2}{4} + 4n + 3$ olur ve en büyük terim nedeniyle $T(n) \in O(n^2\log n)$ yazılır (ekrandan, 00:45:00). Kaba analizle $\frac{n}{2}\cdot\frac{n}{2}\cdot\log n$ hesaplayıp aynı sonuca varmak da doğrudur.
- **Ders sonrası not (çalışma zamanı sorusu):** Ekrandaki kodda ortadaki döngünün artırma kısmı `j = j++` yazılıdır. Derste bu `j++` gibi ele alındı. C dilinde `j = j++` tanımsız davranıştır ve büyük olasılıkla `j++` kastedilmiştir. Ayrıca döngü sayıları derste yaklaşık alındı: $n$ çift olduğunda dış döngü tam olarak $n/2 + 1$, en içteki döngü $\lfloor\log_2 n\rfloor + 1$ kez döner (python ile sayıldı). Bu fark asimptotik sonucu değiştirmez.
- **Asimptotik gösterim.** Big-O için $f(n) \le c\,g(n)$ eşitsizliğini sağlayan bir $c$ ve bir başlangıç değeri bulunması yeterlidir. $4^n \le c\cdot 8^n$ eşitsizliği iki taraf $8^n$'e bölününce $(1/2)^n \le c$ olur; $n \ge 2$ için $c = 1/4$ seçilebilir. Tersine, $x^3 + 5x \le c x^2$ eşitsizliğinde $x > c$ alındığında sol taraf hep büyük kalır; bu yüzden $x^3 + 5x \notin O(x^2)$. Limit yönteminde $\lim f/g = 0$ ise $f \in O(g)$, sabit bir sayı ise iki fonksiyon aynı mertebededir ($\Theta$), $\infty$ ise $f \in \Omega(g)$.
- **Geri yerine koyma.** $T(n) = T(n-1) + 1$ bağıntısı $T(n) = T(n-k) + k$ biçimine açılır. Temel duruma ulaşmak için $n - k = 1$, yani $k = n - 1$ seçilir; $T(1) = 1$ ile $T(n) = n$ bulunur. Böl ve yönet bağıntısı $T(n) = T(n/2) + 1$ için $T(n) = T(n/2^k) + k$ olur; $2^k = n$'den $k = \log_2 n$ ve $T(n) = \log_2 n + 1$ çıkar.
- **$T(n) = 2T(n/2) + 4n$ örneği.** Öz yineleme ağacında $i$. seviyede $2^i$ düğüm vardır ve her birinin maliyeti $4n/2^i$'dir; her seviyenin toplamı $4n$'dir (ekrandan, 02:00:00). Derinlik $\log n$ olduğundan $0$'dan $\log n$'e $\log n + 1$ seviye vardır ve toplam $4n\log n + 4n$ olur. Geri yerine koymada $T(n) = 2^i T(n/2^i) + i\cdot 4n$ bulunur; $i = \log_2 n$ için $nT(1) + 4n\log n$ çıkar (ekrandan, 02:10:00). Ana teoremde $a = 2$, $b = 2$, $d = 1$ ve $a = b^d$ olduğundan $\Theta(n\log n)$ doğrudan yazılır.
- **Karakteristik denklem.** $a_n = 3a_{n-1} + 4a_{n-2}$ için $r^2 - 3r - 4 = 0$, kökler $4$ ve $-1$, çözüm $a_n = c_1 4^n + c_2(-1)^n$ (ekrandan, 02:30:00). $a_n = 3a_{n-1} + 10a_{n-2}$, $a_0 = 5$, $a_1 = 8$ için kökler $5$ ve $-2$; $c_1 + c_2 = 5$, $5c_1 - 2c_2 = 8$ denklemlerinden $c_1 = 18/7$, $c_2 = 17/7$ bulunur. Homojen olmayan $a_n = 2a_{n-1} + 3a_{n-2} + 5$, $a_0 = 4$, $a_1 = 10$ bağıntısında homojen kısım $c_1 3^n + c_2(-1)^n$'dir; özel çözüm $A$ diye tahmin edilip $A = 2A + 3A + 5$'ten $A = -5/4$ bulunur; başlangıç koşullarıyla $a_n = \frac{33}{8}3^n + \frac{9}{8}(-1)^n - \frac{5}{4}$ elde edilir (ekrandan, 02:35:00).
- **Merge sort ve en yakın çift.** Merge sort diziyi iki yarıya böler, her yarıyı öz yinelemeli sıralar ve sıralı iki diziyi birleştirir: $M(n) = 2M(n/2) + n$, ana teoremle $\Theta(n\log n)$. En yakın nokta çifti probleminde her noktanın her noktaya uzaklığını hesaplayan basit algoritma $n^2$ mertebesindedir; noktaları $x$ ve $y$ eksenine göre sıralayıp böl ve yönet uygulayan algoritmanın bağıntısında da $a = 2$, $b = 2$, $d = 1$ olduğundan karmaşıklık $n\log n$'dir.
- **Problemlerin zorluğu.** Polinom zamanda ($n^2$, $n^3$, $n^4$) çözülebilen problemler çözülebilir (tractable) sayılır. $2^n$, $3^n$ ya da $n!$ zaman gerektirenler şu an için çözülemeyen (intractable) problemlerdir; örneğin 256 karakterli bir alfabeden 10 karakterlik bir parolanın bütün olasılıklarını denemek $256^{10}$ durum demektir. Durma problemi (bir programın sonlanıp sonlanmayacağını söyleyen genel bir program yazmak) hiçbir algoritmayla çözülemez. NP-tam problemlerden biri polinom zamanda çözülürse NP sınıfının tamamı polinom zamanda çözülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
