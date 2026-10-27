# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 14 Ekim 2020 Çarşamba. Bu kayıt aynı günün laboratuvar (uygulama) oturumudur. Zoom üzerinden yapıldı.
  - Kayıt yaklaşık 37 dakikadır. Teori kısmı ders 3'tür.
- Asimptotik gösterimde sadeleştirme hatırlatması
  - Sabitler ve katsayılar atılır, düşük dereceli terimler atılır. Örnek bir karesel ifadenin sonucu $O(n^2)$.
- Insertion sort'un ortalama durum (average case) analizi
  - İç döngüde ortalama karşılaştırma sayısı ve dış döngüyle toplam.
- Doğru-yanlış soruları
  - $n \in O(n^2)$, $100n+5 \in O(n^2)$, $\frac{1}{2}n(n-1) \in O(n^2)$, $n^3 \in O(n^2)$, $0.0001n^3 \in O(n^2)$.
- Büyüme derecelerini limitle karşılaştırma
  - $\lim_{n\to\infty} t(n)/g(n)$ değerinin $0$, sabit $c$ veya $\infty$ olmasına göre karar.
  - Örnek: $\frac{1}{2}n(n-1)$ ile $n^2$.
- Gelecek haftanın konuları: toplam (summation) formülleri, iteratif ve özyinelemeli algoritmaların matematiksel analizi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Derse aktif katılın.
  - Hoca öğrencileri tek tek adıyla çağırdı, birçoğu cevap vermedi. "Bu şekilde dersi yürütmemiz mümkün değil" dedi.
  - Cevap gelmezse uygulama saatinde örnek çözmeyi bırakıp doğrudan yeni konuya geçeceğini söyledi.
- Kolay görünen sorularda hata yapılıyor.
  - Önceki yıllarda "zaten belli" deyip bu soruları sınavda yanlış yapan çok öğrenci olmuş.
- Bir ifadeyi doğru yapmanın bir yolu da "elemanıdır" yerine "elemanı değildir" ($\notin$) yazmaktır.
  - $n^3 \notin O(n^2)$ doğrudur. $n^3 \in \Omega(n^2)$ de doğrudur.
- Ortalama durum her algoritmada bu kadar kolay hesaplanamaz. Insertion sort bunun için güzel bir örnektir.
- Anlamadığınız noktaları gelecek dersin ilk 10 dakikasında sorabilirsiniz.
- Gelecek haftanın konusuna önceden göz atın.

## Kısa Tekrar Notları

- Sadeleştirme: sabitleri at, katsayıları at, düşük dereceli terimleri at, en yüksek dereceli terimi bırak.
- Insertion sort ortalama durumu: $\Theta(n^2)$. Yaklaşık $\frac{n^2}{4}$ karşılaştırma.
- Limit kuralı:
  - $\lim t(n)/g(n)=0$ ise $t$, $g$'den daha düşük derecede büyür.
  - $\lim t(n)/g(n)=c>0$ ise $t$ ile $g$ aynı derecede büyür ($t\in\Theta(g)$).
  - $\lim t(n)/g(n)=\infty$ ise $t$, $g$'den daha yüksek derecede büyür.
- Doğru-yanlış cevapları:
  - $n \in O(n^2)$: doğru.
  - $100n+5 \in O(n^2)$: doğru.
  - $\frac{1}{2}n(n-1) \in O(n^2)$: doğru.
  - $n^3 \in O(n^2)$: yanlış. Doğru biçimleri: $n^3 \notin O(n^2)$ veya $n^3 \in \Omega(n^2)$.
  - $0.0001n^3 \in O(n^2)$: yanlış. Katsayı ne kadar küçük olursa olsun $n^3$ terimi $n^2$'yi geçer.

## Detaylı Açıklamalar

### Insertion sort'un ortalama durumu

Hoca şu modeli kullandı:

- $k$. eleman eklenirken ilk $k-1$ eleman zaten sıralıdır.
- Eleman $j$. konuma ($1\le j\le k$) yerleşecekse $k-j+1$ karşılaştırma yapılır.
- Her konum eşit olasılıklıdır, yani her birinin olasılığı $\frac{1}{k}$'dır.

İç döngünün ortalama karşılaştırma sayısı:

$$\frac{1}{k}\sum_{j=1}^{k}(k-j+1) = \frac{1}{k}\cdot\frac{k(k+1)}{2} = \frac{k+1}{2}$$

Dış döngü $k=2$'den $n$'ye kadar döner:

$$A(n)=\sum_{k=2}^{n}\frac{k+1}{2}$$

Hoca sonucu $\frac{1}{2}\cdot\frac{(n+1)(n+2)}{2} = \frac{1}{4}(n^2+3n+2)$ olarak yazdı. Bu yaklaşık $\frac{n^2}{4}$'tür. En kötü durum gibi ortalama durum da karesel büyür: $A(n)\in\Theta(n^2)$.

- Bir öğrenci, sıralı kısmın sonrasındaki elemanların da hesaba katılıp katılmadığını sordu.
- Hoca, $k$'nın 2'den $n$'ye kadar bütün değerleri aldığını ve her adımda yalnız $k$. elemanın sıralı kısma yerleştirildiğini açıkladı.

### Limitle karşılaştırma örneği

$t(n)=\frac{1}{2}n(n-1)$, $g(n)=n^2$:

$$\lim_{n\to\infty}\frac{\frac{1}{2}n(n-1)}{n^2} = \frac{1}{2}\lim_{n\to\infty}\frac{n^2-n}{n^2} = \frac{1}{2}\lim_{n\to\infty}\left(1-\frac{1}{n}\right)=\frac{1}{2}$$

Sonuç sabit olduğu için iki fonksiyon aynı derecede büyür: $\frac{1}{2}n(n-1)\in\Theta(n^2)$.

### Ders sonrası notlar

- **Toplamın kapalı biçimi:** $\sum_{k=2}^{n}\frac{k+1}{2}$ toplamının tam değeri $\frac{n^2+3n-4}{4}$'tür. Hocanın yazdığı $\frac{(n+1)(n+2)}{4}=\frac{n^2+3n+2}{4}$ ifadesi $\frac{6}{4}$ kadar büyüktür; toplamı $k=0$'dan başlatmaya karşılık gelir. Asimptotik sonuç ($\Theta(n^2)$) değişmez. Python ile $n=2,3,5,10$ için kontrol edildi.
- **Modelin kesin değeri:** Gerçek insertion sort'ta eleman en başa ($j=1$) yerleşince $k$ değil $k-1$ karşılaştırma yapılır, çünkü dizinin başına gelince döngü karşılaştırmasız biter. Bütün permütasyonlar üzerinden kesin ortalama $\frac{n^2+3n}{4}-H_n$'dir ($H_n$: harmonik sayı). Örnek: $n=4$ için $\frac{59}{12}\approx 4.92$. Bu da $\Theta(n^2)$'dir. Python ile bütün permütasyonlar sayılarak doğrulandı.
- **Hafıza değil zaman:** Bir öğrenci insertion sort'taki $O(n^2)$'nin bellek karmaşıklığı olup olmadığını sordu. Burada konuşulan zaman (işlem sayısı) karmaşıklığıdır. Insertion sort ek bellek olarak yalnız $O(1)$ kullanır (yerinde, in-place sıralama).
- **Altyazı hataları:** "InSocial Sort", "Insurgent Sort", "Insolution sort" insertion sort demektir. "Eurich K" average case'tir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
