# Ders 6 Çalışma Özeti

## Genel Konular

- Dersin tarihi 21 Ekim 2020 Çarşamba. Bu kayıt, ders 5'ten sonraki uygulama (problem çözme) saatidir. Zoom üzerinden yapıldı.
- Ders 5'teki bir soruya cevap: sonuçlarda neden $\Theta$ yazıldı.
- Alıştırma 1: $x(n) = x(n-1) + n$ rekürans bağıntısını geriye doğru yerine koyma (backward substitution) ile çözme.
- Alıştırma 2: $x(n) = x(n/3) + 1$ bağıntısını $n = 3^k$ kabulüyle çözme. İki öğrencinin çözümü ekranda değerlendirildi.
- Alıştırma 3: $\sum_{i=2}^{n-1} \log_2 i^2$ toplamının büyüme derecesini bulma.
- Gelecek haftanın planı: azalt ve yönet (decrease and conquer), böl ve yönet (divide and conquer) ve ödev duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sonuçlar $\Theta$ ile yazıldı. Çünkü incelenen algoritmalarda üst sınır (upper bound) ile alt sınır (lower bound) aynı noktaya denk geliyor. Bu durumda sıkı sınır (tight bound) $\Theta$ kullanılır.
- Rekürans bağıntısı tek başına geriye doğru yerine koymayla çözülemez. Başlangıç koşulu (initial condition) da gerekir.
  - Alıştırmalarda başlangıç koşulu verilir. Algoritma analizinde ise başlangıç koşulunu algoritmanın durma noktasından sizin bulmanız gerekir.
- Çözüm adım adım yazılmalı. Yalnız sonucu yazmak yetmez.
- Not tutun. Ekran görüntüsü alabilirsiniz, ama elle yazarak bir defter oluşturmanız öğrenmek için daha faydalı.
  - Hoca ileride öğrencilerden defter isteyebileceğini söyledi.
- Toplamın büyüme derecesini bulurken sabitler atılır. Daha düşük dereceli terimler de atılır.
  - $\Theta(n \log n)$ ile $\Theta(\log n)$ toplanınca sonuç $\Theta(n \log n)$ olur.
- Konuşurken adınızı söyleyin. Ekran paylaşımı sırasında hoca kimin konuştuğunu göremiyor.

## Kısa Tekrar Notları

- Alıştırma 1: $x(n) = x(n-1) + n$, $x(0) = 0$. Sonuç $x(n) = \frac{n(n+1)}{2} \in \Theta(n^2)$.
- Alıştırma 2: $x(n) = x(n/3) + 1$, $x(1) = 1$. $n = 3^k$ için sonuç $x(n) = \log_3 n + 1 \in \Theta(\log n)$.
- Alıştırma 3: $\sum_{i=2}^{n-1} \log_2 i^2 = 2\sum_{i=2}^{n-1} \log_2 i \in \Theta(n \log n)$.
- $\sum_{i=1}^{n} \log i \approx n \log n$ ($\log n! \in \Theta(n \log n)$).
- Ödev süresi bir ya da iki hafta olacak.

## Detaylı Açıklamalar

### Neden $\Theta$?

- $O$ üst sınırdır, $\Omega$ alt sınırdır.
- MaxElement ve faktöriyel gibi örneklerde iki sınır aynı fonksiyona denk geliyor. Bu yüzden $\Theta$ yazılabiliyor.
- İki sınır farklıysa her biri ayrıca değerlendirilmelidir.

### Alıştırma 1: $x(n) = x(n-1) + n$, $x(0) = 0$

$$
\begin{aligned}
x(n) &= x(n-1) + n \\
&= [x(n-2) + (n-1)] + n = x(n-2) + (n-1) + n \\
&= [x(n-3) + (n-2)] + (n-1) + n = x(n-3) + (n-2) + (n-1) + n \\
&\;\;\vdots \\
&= x(n-i) + (n-i+1) + (n-i+2) + \dots + n
\end{aligned}
$$

- Başlangıç koşulunu kullanmak için $i = n$ alınır:

$$x(n) = x(0) + 1 + 2 + \dots + n = \frac{n(n+1)}{2}$$

- Ders 5'teki faktöriyel bağıntısında her adımda sabit $+1$ ekleniyordu. Burada her adımda $+n$, $+(n-1)$ gibi değişen terimler ekleniyor. Bu yüzden sonuç bir toplam formülüne dönüşüyor.

### Alıştırma 2: $x(n) = x(n/3) + 1$, $x(1) = 1$

- $n = 3^k$ kabul edilir:

$$
\begin{aligned}
x(3^k) &= x(3^{k-1}) + 1 \\
&= x(3^{k-2}) + 2 \\
&\;\;\vdots \\
&= x(3^{k-i}) + i
\end{aligned}
$$

- $i = k$ alınır: $x(3^k) = x(1) + k = k + 1$.
- $k = \log_3 n$ olduğu için $x(n) = \log_3 n + 1$.
- Derste iki öğrencinin çözümü gösterildi. Biri doğrudan $n/3^i$ ile ilerledi, diğeri $3^k$ yazarak ilerledi. İkisi de aynı sonuca ulaştı.
  - Hoca ikinci çözümde genel adım olan $x(3^{k-i}) + i$ satırının eksik olduğunu söyledi. Bu satır mutlaka yazılmalı.

### Alıştırma 3: $\sum_{i=2}^{n-1} \log_2 i^2$

$$
\sum_{i=2}^{n-1} \log_2 i^2 = 2\sum_{i=2}^{n-1} \log_2 i = 2\left(\sum_{i=1}^{n} \log_2 i - \log_2 1 - \log_2 n\right) = 2\sum_{i=1}^{n} \log_2 i - 2\log_2 n
$$

- $\sum_{i=1}^{n} \log_2 i = \log_2 n! \in \Theta(n \log n)$.
- Sonuç: $\Theta(n \log n) - \Theta(\log n) = \Theta(n \log n)$.
- Bu alıştırmada geriye doğru yerine koyma kullanılmaz. Çünkü bir rekürans bağıntısı yok. Yalnız toplam formülleri ve sınır kaydırma kullanılır.
  - Toplamın sınırlarını $2..n-1$'den $1..n$'ye genişletmek için eklenen terimler ($\log_2 1 = 0$ ve $\log_2 n$) çıkarılır.

### Ders sonrası notlar

- **Alıştırma 1 sonucu:** Hoca sonucu söylerken bir yerde "$n+1$ bölü 2" dedi. Doğrusu $\frac{n(n+1)}{2}$. Python ile $n = 10$ için 55 elde edildi.
- **Alıştırma 3 sonucu:** Hoca özetin sonunda bir an "Theta log n" dedi. Doğru sonuç $\Theta(n \log n)$. Python ile $n = 1000$ için toplam $\approx 17039$, $2n\log_2 n \approx 19932$. Oran $n$ büyüdükçe 1'e yaklaşır.
- **Bir öğrencinin cevabı:** Bir öğrenci sonucu $\log_2(n-1)\cdot(\log_2(n-1)+1)$ olarak söyledi. Bu doğru değil. Toplamda $n$ tane logaritmik terim var. Bu yüzden sonuç $n \log n$ mertebesindedir, $\log^2 n$ değil.
- **$\log n!$ yaklaşımı:** Bir öğrencinin önerdiği $\log n! - \log n$ yolu da doğrudur. $\log n! \in \Theta(n \log n)$ olduğu için sonuç aynıdır.
- **Alıştırma 2 doğrulama:** $n = 1, 3, 9, 27, 81$ için $x(n) = 1, 2, 3, 4, 5$ çıkar. Bu, $\log_3 n + 1$ ile aynıdır (Python ile kontrol edildi).

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
