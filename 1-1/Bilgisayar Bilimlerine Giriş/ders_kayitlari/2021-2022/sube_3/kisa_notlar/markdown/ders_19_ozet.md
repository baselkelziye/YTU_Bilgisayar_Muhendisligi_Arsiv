# Ders 19 Çalışma Özeti

## Genel Konular

- Akış diyagramı elemanlarının tekrarı (ekrandan, 00:15:00 ve 00:20:00)
  - Başla/Dur: elips ya da üstü ve altı düz, yanları yuvarlak şekil (START, STOP).
  - Girdi: sol üst köşesi çentikli dikdörtgen (delikli kartı temsil eder).
  - İşlem: düz dikdörtgen; atamalar ve hesaplar burada yazılır.
  - Karar: içine uzun mantıksal ifadeler sığsın diye uzatılmış altıgen. En az iki çıkışı vardır; False kolu boş olsa bile çizilir, T/F etiketleri yazılır.
  - Adım sayısı belli döngü (for): üç bölmeli kutu. Sol üstte ilk değer ($i=1$), sağ üstte artım miktarı ($1$), altta son değer ($N$) yazılır.
  - Çıktı: altı dalgalı kesilmiş kağıt şekli (yazıcı çıktısı).
  - Akış okları yönlüdür; mümkün olduğunca düz, köşeli çizgilerle çizilir.
- Koşullu döngüler: while, do-while, repeat-until (ekrandan, 00:20:00 ve 00:25:00)
  - While: önce koşul kontrol edilir ($J<N$), doğru olduğu sürece gövde çalışır. Koşul baştan yanlışsa gövde hiç çalışmaz.
  - Gövde içinde döngü değişkeni mutlaka güncellenmelidir ($J = J + 1$ gibi); güncellenmezse sonsuz döngü oluşur ve bu, algoritma tanımına (sonlu adımda durma) aykırıdır.
  - Do-while: önce gövde (işlem 1, işlem 2) en az bir kez çalışır, sonra koşul kontrol edilir; koşul doğru olduğu sürece gövdeye geri dönülür.
  - Repeat-until: "koşul doğru olana kadar" tekrarlar (Pascal gibi dillerde var, C'de yok). Koşulun değili alınarak do-while ile aynı iş yapılır; ayrı bir yapıya gerek yoktur.
  - Roadrunner ve çakal benzetmesi: Roadrunner while gibi davranır ("kenar değilse koş"), uçurum kenarında durur. Çakal do-while gibi davranır ("koş, sonra kenar mı diye bak"), bir adım fazla koştuğu için uçurumdan düşer.
- Diziler (ekrandan, 00:30:00 ve 00:35:00)
  - Dizi: aynı türden verilerin tek bir isim altında tutulduğu veri topluluğu. Beş sayı için $a, b, c, d, e$ gibi beş ayrı değişken yerine tek bir $A$ dizisi kullanılır.
  - Elemanlara indisle erişilir; akış diyagramında notasyon köşeli parantezdir: $A[i]$, dizinin $i$'inci gözündeki değer.
  - Bellekte genellikle ardışık adreslerde durduğu düşünülebilir; ama algoritmada dizi tek bir bütün olarak görülür.
  - Akış diyagramlarında indisler $1 \ldots N$ alınır (okunması kolay). C dilinde indisler $0$'dan başlar, $0 \ldots N-1$ arasıdır. Hangisi seçilirse seçilsin başlangıç ve bitiş değerlerine dikkat edilmelidir.
  - Ek bilgi olarak: bazı dillerde indisler sayı olmak zorunda değildir; metin ya da enumerasyon değerleri (elma, armut, muz) indis olabilir.
- Dizi ile toplam ve ortalama (ekrandan, 00:40:00 ve 00:45:00)
  - Okuma kutusunda önce uzunluk, sonra dizi okunur: "$N, A[N]$". Bu, $i=1 \ldots N$ döngüsü içinde $A[i]$'yi tek tek okumanın kısa gösterimidir.
  - $top = 0$, $ort = 0$; döngüde $top = top + A[i]$; döngüden sonra $ort = top / N$; $top$ ve $ort$ yazdırılır.
  - Değişiklik: tek ve çift toplamları ayrı tutmak için $tt = 0$, $tc = 0$ alınır; döngüde mod 2 kontrolü yapılır. İndislerin tekliğine bakılacaksa $i \bmod 2$, değerlerin tekliğine bakılacaksa $A[i] \bmod 2$ kontrol edilir; çiftse $tc = tc + A[i]$, tekse $tt = tt + A[i]$.
- Dizi sınırlarının dışına taşma (ekrandan, 00:50:00)
  - Ardışık iki elemanın toplamını yazdıran döngü: $i = 1 \ldots N$ için $A[i] + A[i+1]$ yazdırılır.
  - $N = 3$, $A = [2, 4, 6]$ için $i=1$'de $6$, $i=2$'de $10$ yazılır; $i=3$'te tanımsız $A[4]$'e erişilmeye çalışılır.
  - C gibi dillerde taşma kontrolü programcının sorumluluğundadır: hata alınmadan bellekteki ilgisiz bir değer (örneğin $-312$) kullanılır ve ekranda saçma bir sonuç ($-306$) görülebilir.
  - Doğrusu döngünün $N-1$'e kadar dönmesidir. $A[i-1]$ gibi erişimlerde de soldan taşma olabilir.
- Üç sayının ortancası: iç içe kararlarla (ekrandan, 00:55:00, 01:00:00 ve 01:05:00)
  - Problem: $a, b, c$ okunur, ortanca değer yazdırılır. Dizi ya da sıralama kullanılmaz, yalnız karşılaştırma yapılır. Eşit değerlerde herhangi birini vermek doğrudur.
  - Örnekler (ekrandan): $3, 5, 8 \to 5$; $8, 3, 5 \to 5$; $5, 8, 3 \to 5$; $-2, 0, 2 \to 0$; $3, 3, 8 \to 3$.
  - Akış iç içe if'lerden oluşur (aşağıda Detaylı Açıklamalar).
- Üç sayının ortancası: farklarla (ekrandan, 01:10:00 ve 01:15:00)
  - $x = a-b$, $y = b-c$, $z = c-a$ hesaplanır; farkın işareti hangisinin büyük olduğunu gösterir. İki farkın çarpımı pozitifse işaretleri aynıdır.
  - $x \cdot y > 0$ ise $b$ ortancadır; değilse ikinci kontrolle $a$ ile $c$ arasında seçim yapılır.
  - Ders sonrası not: ekrandaki akışta ikinci kararın çıkışları ters yazılmıştır (aşağıda Detaylı Açıklamalar).
- Fazla değişken mi, fazla karar mı?
  - Kesin cevabı yoktur, "iyi" kavramı hedefe göre değişir. Hız önemliyse kararlar (dallanmalar) azaltılır, fazladan değişken kullanılabilir. Bellek kısıtlı ise (gömülü sistem) değişken sayısı azaltılır.
  - Bu derste öncelik okunabilir, sade akış diyagramlarıdır.
- Fibonacci sayıları (ekrandan, 01:35:00, 01:40:00 ve 01:45:00)
  - Tanım: $f_1 = 1$, $f_2 = 1$, $f_n = f_{n-2} + f_{n-1}$, $n > 2$. Kısıt girdi uzayında verildiği için akışta ayrıca kontrol edilmez.
  - Değişkenlerle ($N$'e kadar olanlar): $a = 1$, $b = 1$; $a, b$ yazdır; $c = a + b$; $c \le N$ olduğu sürece $c$ yazdır, sonra kaydır: $a = b$, $b = c$, $c = a + b$. $N = 20$ için çıktı: 1, 1, 2, 3, 5, 8, 13.
  - Diziyle ($N$ tane): $A[1] = 1$, $A[2] = 1$; $i = 3 \ldots N$ için $A[i] = A[i-2] + A[i-1]$ ve $A[i]$ yazdır. $N = 6$ için dizi: 1, 1, 2, 3, 5, 8.
- Tam bölenler (ekrandan, 01:50:00 ve 01:55:00)
  - $N$ oku, $x = 1$; $x \le N$ olduğu sürece: $N \bmod x = 0$ ise $x$ yazdır; $x = x + 1$.
  - Hoca artımı bilerek unuttu: $x$ güncellenmezse $x = 1$'de sonsuz döngü olur.
  - İyileştirme (öğrenci önerisi): $N/2$'den büyük bir sayı (kendisi hariç) $N$'i tam bölemez; $N/2$'ye kadar gidip sonra $N$'in kendisi yazdırılabilir.
- Toplamayla çarpma, çıkarmayla bölme (ekrandan, 02:00:00)
  - Çarpma: $c = 0$; $i = 1 \ldots y$ için $c = c + x$; $c$ yazdır. ($3 \times 2 = 3 + 3$.)
  - Bölme: $b = 0$; $x \ge y$ olduğu sürece $x = x - y$, $b = b + 1$; $b$ (bölüm) ve $x$ (kalan) yazdırılır. $10/3$: bölüm 3, kalan 1.
- Saat kolları arasındaki açı (ekrandan, 02:05:00, 02:10:00 ve 02:15:00)
  - 12'lik analog saat: $H \in [1, 12]$, $M \in [0, 59]$.
  - Akrep saatte $360/12 = 30°$, dakikada $30/60 = 0.5°$ ilerler: $Ha = (H \cdot 60 + M) \cdot 0.5$.
  - Yelkovan dakikada $360/60 = 6°$ ilerler. Aradaki açı: $a = M \cdot 6 - Ha$.
  - $a < 0$ ise $a = -1 \cdot a$. Sonra $a < 360 - a$ ise $a$, değilse $360 - a$ yazdırılır (dar taraf).

## Hocanın Özellikle Vurguladığı Kısımlar

- Döngü değişkeni gövdede mutlaka değişmeli
  - While ve do-while döngülerinde koşuldaki değişken gövdede güncellenmezse döngüden çıkılamaz. Tam bölenler örneğinde bu hata bilerek yapıldı ve bir öğrenci yakaladı.
- True/False etiketleri ve oklar
  - Her karar kutusunda T ve F kolları yazılmalı, oklar konmalı; hoca bunun alışkanlık haline getirilmesini istedi.
- Karar kollarından geri dönülerek döngü kurulmaz
  - Akış yönlüdür; bir if'in kolundan yukarıya geri ok çekip döngü kurmak yanlıştır. Yapılar blok halinde, iç içe (nested) kurulur.
  - Tam bölenler örneğinde False kolunu döngü dışına bağlamak da yanlıştır; iki kol birleşip döngü bloğuna dönmelidir.
- Dizi sınırları ve uç değerler
  - Başlangıç ve son değerleri (1…N ya da 0…N−1) dikkatle seçin; taşma hem sağdan hem soldan olabilir. Algoritmayı uç değerlerle mutlaka test edin.
- "Analiz" kelimesinin bu dersteki anlamı
  - Akışı çizdikten sonra değişkenlerin aldığı değerleri adım adım izleyip akışın doğru sonuç verdiğini ve durduğunu göstermek. Ortanca örneğinde 3, 5, 8'in bütün sıralamaları, negatifli girdiler, sıfırlı girdiler ve hepsi eşit girdiler denenmeli.
- Tek bir doğru çözüm yoktur
  - Aynı problem farklı bakış açılarıyla çözülebilir; hedef hız, az bellek ya da kolay gerçekleştirme olabilir. Sürekli sorgulayın, alternatifleri düşünün.

## Kısa Tekrar Notları

- While: önce kontrol, sonra gövde (gövde hiç çalışmayabilir). Do-while: önce gövde, sonra kontrol (en az bir kez çalışır).
- Repeat-until, koşulun değiliyle kurulan do-while'dır.
- For kutusu: sol üst ilk değer, sağ üst artım, alt son değer.
- Dizi: aynı türden veriler, $A[i]$ notasyonu; akışta $1 \ldots N$, C'de $0 \ldots N-1$.
- Okumada önce uzunluk ($N$), sonra dizi ($A[N]$).
- $A[i] + A[i+1]$ için döngü $N-1$'e kadar döner.
- Ortanca: iç içe if ile ya da fark çarpımlarının işaretiyle bulunur.
- Fibonacci: kaydırma ($a = b$, $b = c$, $c = a + b$) ya da dizi ($A[i] = A[i-2] + A[i-1]$).
- Bölme: $x \ge y$ olduğu sürece çıkar ve say; kalan $x$'te kalır.
- Saat açısı: $Ha = (60H + M) \cdot 0.5$, $a = 6M - Ha$, mutlak değer, sonra $\min(a, 360-a)$.

## Detaylı Açıklamalar

- **İç içe kararlarla ortanca (ekrandan, 01:05:00).** İlk karar $a < b$'dir.
  - True kolunda $a \ge c$ kontrol edilir; doğruysa $c \le a < b$ olduğundan $ort = a$. Eşitlik bu kontrole konarak $a = c$ durumu da karşılanır. Yanlışsa $a$ en küçüktür; $b < c$ ise $ort = b$, değilse $ort = c$. Burada eşitlik ayrıca kontrol edilmez, çünkü $b = c$ iken ikisinden hangisi seçilse değer aynıdır.
  - False kolunda ($b \le a$) $a < c$ kontrol edilir; doğruysa $b \le a < c$ olduğundan $ort = a$. Yanlışsa $a$ en büyüktür; $b > c$ ise $ort = b$, değilse $ort = c$.
  - Bütün kollar birleşir, $ort$ yazdırılır ve durulur. Python ile $-3 \ldots 3$ aralığındaki bütün üçlülerde (eşitlikler dahil) doğru sonuç verdiği denendi.
  - Bir öğrenci kararları "ve" ile birleştirmeyi önerdi ($a < b$ ve $a > c$ gibi); bu da doğru bir yoldur ama karar sayısını pek azaltmaz.
- **Farklarla ortanca (ekrandan, 01:15:00).** $x = a-b$, $y = b-c$, $z = c-a$.
  - $x \cdot y > 0$ ise ya $a > b > c$ ya da $a < b < c$'dir; ortanca $b$'dir.
  - Ekrandaki akışta ikinci karar $x \cdot z > 0$'dır; True kolunda $ort = c$, False kolunda $ort = a$ yazılmıştır. Hoca $-2, 2, -2$ girdisiyle izledi: $x = -4$, $y = 4$, $z = 0$; $x \cdot y < 0$, $x \cdot z = 0$ olduğundan $ort = a = -2$ çıktı.
  - Ders sonrası not: $x \cdot z > 0$ ise $a - b$ ile $c - a$ aynı işaretlidir, yani $b < a < c$ ya da $c < a < b$; bu durumda ortanca $c$ değil $a$'dır. Ekrandaki dallar ters yazılmıştır; örneğin $5, 3, 8$ girdisinde akış $8$ verir (doğrusu $5$). Python ile denendiğinde şu sıra bütün durumlarda (eşitlikler dahil) doğru çalıştı: $x \cdot y \ge 0$ ise $ort = b$; değilse $x \cdot z \ge 0$ ise $ort = a$; değilse $ort = c$. Eşitlik ($\ge$) gerekir, yoksa $3, 3, 8$ gibi girdilerde $c$ seçilir.
  - Bu çözümde 3 fazladan değişken kullanılır ama yalnız iki karar vardır.
- **Ortalamaya en yakın olan.** Öğrencilerden biri üç sayının ortalamasını alıp ortalamaya en yakın sayıyı seçmeyi önerdi. Hoca, bir sayı çok büyükse ortalamanın o tarafa kayacağını, bu yüzden yaklaşımın yanlış olacağını söyledi ve konuyu kapattı.
  - Ders sonrası not: hoca yaklaşımın yanlış olduğunu söyledi; oysa $a \le b \le c$ ve $m = (a+b+c)/3$ için $b$ her zaman ortalamaya en yakın (ya da eşit yakın) sayıdır. Örneğin $b \ge m$ ise $c$ zaten $b$'den uzaktır ve $(b-m) - (m-a) = (a+b-2c)/3 \le 0$ olur; $b < m$ durumu simetriktir. Python ile $-20 \ldots 20$ aralığındaki bütün üçlülerde denendi, karşı örnek çıkmadı. Ancak bu yol bölme, mutlak değer ve yine karşılaştırmalar gerektirir.
- **Fibonacci, değişkenlerle izleme (ekrandan, 01:40:00).** $N = 20$: $a = 1$, $b = 1$ yazdırılır; $c = 2$. $2 \le 20$, 2 yazdırılır; kaydırma: $a = 1$, $b = 2$, $c = 3$. Sonra 3, 5, 8, 13 yazdırılır; $c = 21$ olunca $21 \le 20$ yanlış olur ve durulur. Çıktı: 1, 1, 2, 3, 5, 8, 13. $a = b$ ataması "b'nin bellek gözündeki değeri a'nın gözüne kopyala" demektir.
- **Bölme, öğrenci sorusu.** $10/9$ için: $10 \ge 9$, $x = 1$, $b = 1$; $1 \ge 9$ yanlış; bölüm 1, kalan 1. Akış doğru çalışır.
- **Saat açısı.** Örneğin 3:55 için $Ha = (3 \cdot 60 + 55) \cdot 0.5 = 117.5$, $a = 55 \cdot 6 - 117.5 = 212.5$; $212.5 < 147.5$ yanlış olduğundan $360 - 212.5 = 147.5°$ yazdırılır (hesap derste yapılmadı, python ile kontrol edildi). Hoca kontrolü önce "360'tan küçükse" diye söyledi, sonra "180'den küçük" diye düzeltti; ekrandaki $a < 360 - a$ kontrolü $a < 180$ ile aynıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
