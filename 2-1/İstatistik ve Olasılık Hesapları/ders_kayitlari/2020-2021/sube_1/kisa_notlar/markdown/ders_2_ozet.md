# Ders 2 Çalışma Özeti

## Genel Konular

- Topluca kapsayıcı (collectively exhaustive) ve karşılıklı ayrık (mutually exclusive) kümeler, bölüntü (partition)
  - $A_1, A_2, \dots, A_n$ kümeleri, ancak ve ancak (iff) $\bigcup_{i=1}^{n} A_i = \Omega$ ise topluca kapsayıcıdır.
  - Kümelerin hiçbir ikisinin ortak elemanı yoksa karşılıklı ayrıktır: her $i \neq j$ için $A_i \cap A_j = \emptyset$.
  - Hem topluca kapsayıcı hem karşılıklı ayrık olan küme ailesi örnek uzayın bir bölüntüsüdür.
  - Derste Venn şemasıyla örnek verildi: $A$ ve $B$ kesişiyor, $A \cup B \neq \Omega$; $C = \overline{A \cup B}$ alınınca $A, B, C$ topluca kapsayıcı olur ama $A \cap B \neq \emptyset$ olduğu için karşılıklı ayrık değildir. $D = A \cup B$ alınınca $C$ ve $D$ hem kapsayıcı hem ayrıktır, yani bir bölüntüdür (ekrandan, 00:20:00).
- Kümeler cebiri (ekrandan, 00:25:00)
  - Birleşme özelliği: $A \cup (B \cup C) = (A \cup B) \cup C$, $A \cap (B \cap C) = (A \cap B) \cap C$.
  - Dağılma özelliği: $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$, $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$.
  - De Morgan kuralları: $\overline{A \cup B} = \bar{A} \cap \bar{B}$, $\overline{A \cap B} = \bar{A} \cup \bar{B}$.
- Deneyden olasılık modeline geçiş
  - Deney izlenen bir prosedürdür; deneyin gözlemlenen sonuçlarına çıktı (outcome) denir.
  - Olasılık modeli, fiziksel dünyadaki durumu incelemek için kurulan basitleştirilmiş matematiksel modeldir.
  - Modelin bileşenleri: çıktı (deneyin olası gözlemlerinden biri), örnek uzay $\Omega$ (bütün olası çıktıların kümesi) ve olay (çıktılardan oluşan küme, $A \subset \Omega$).
- Küme kuramı ile olasılık kuramı terimleri (ekrandan, 00:35:00 ve 00:40:00)
  - Evrensel küme ↔ örnek uzay ($\Omega$ ya da $S$); küme elemanı ↔ çıktı; alt küme ↔ olay; ayrık kümeler ↔ karşılıklı ayrık olaylar; boş küme ↔ imkânsız olay ($\emptyset$); evrensel küme ↔ kesin olay ($\Omega$).
  - İmkânsız olayın tümleyeni kesin olaydır: $\bar{\emptyset} = \Omega$.
- Mutlak ve göreli frekans
  - Deney $N$ kez tekrarlanır; $A$ olayının kaç kez gerçekleştiği $\alpha$ ile gösterilir ve buna mutlak frekans denir. $\alpha \in \{0, 1, \dots, N\}$.
  - $\bar{A}$ olayı $N - \alpha$ kez gerçekleşir.
  - Göreli (normalize) frekans: $f_A(N) = \dfrac{\alpha}{N}$; $A$'nın $N$ tekrardaki gerçekleşme oranıdır.
  - Özellikler: $0 \le f_A(N) \le 1$; $f_\Omega(N) = 1$; $A \cap B = \emptyset$ ise $f_{A\cup B}(N) = f_A(N) + f_B(N)$; buradan $f_{\bar A}(N) = 1 - f_A(N)$.
  - Olasılığın frekans tanımı: $\Pr(A) = \lim_{N \to \infty} f_A(N)$.
- Olasılık aksiyomları (ekrandan, 01:25:00)
  - Aksiyom 1 (negatif olmama): $\Pr(A) \ge 0$.
  - Aksiyom 2 (normalleştirme): $\Pr(\Omega) = 1$.
  - Aksiyom 3 (toplanabilirlik): $A_1, \dots, A_n$ karşılıklı ayrıksa $\Pr\left(\bigcup_{i=1}^{n} A_i\right) = \sum_{i=1}^{n} \Pr(A_i)$.
- Olasılık yasasının özellikleri
  - Özellik 1: $0 \le \Pr(A) \le 1$.
  - Özellik 2: $\Pr(\bar A) = 1 - \Pr(A)$.
  - Özellik 3: $\Pr(\emptyset) = 0$.
  - Özellik 4: $\Pr(A \cup B) = \Pr(A) + \Pr(B) - \Pr(A \cap B)$.
  - Özellik 5 (bölüntü özelliği): $B_1, \dots, B_n$ bir bölüntüyse $\Pr(A) = \sum_{i=1}^{n} \Pr(A \cap B_i)$.
  - Özellik 6 (monotonluk): $A \subseteq B$ ise $\Pr(A) \le \Pr(B)$.
- Kesikli modeller ve eşit olasılıklı çıktılar
  - Model kurmak için önce örnek uzay tanımlanır, sonra üç aksiyomla tutarlı bir olasılık yasası belirlenir.
  - Örnekler: hilesiz bir para atışı ($\Pr(H) = \Pr(T) = 1/2$) ve üç para atışı (8 çıktı, her biri $1/8$).
  - $\Omega = \{\omega_1, \dots, \omega_n\}$ eşit olasılıklı çıktılardan oluşuyorsa $\Pr(\omega_i) = 1/|\Omega| = 1/n$; $k$ çıktılı bir $E$ olayı için $\Pr(E) = \dfrac{k}{n} = \dfrac{\#\text{(E'deki çıktılar)}}{\#\text{(}\Omega\text{'daki çıktılar)}}$.
- Sayma teknikleri
  - Çarpma kuralı: $k$ bileşenli bir deneyde bileşenlerin çıktı sayıları $n_1, \dots, n_k$ ise örnek uzayın büyüklüğü $n_1 \times n_2 \times \dots \times n_k$; hepsi $n$ ise $n^k$.
  - Permütasyon (sıra önemli): yerine koyarak $P_r(n,k) = n^k$; yerine koymadan $P(n,k) = n(n-1)\cdots(n-k+1) = \dfrac{n!}{(n-k)!}$.
  - Kombinasyon (sıra önemsiz): yerine koymadan $C(n,k) = \dfrac{P(n,k)}{P(k,k)} = \dfrac{n!}{k!\,(n-k)!} = \binom{n}{k}$; yerine koyarak $C_r(n,k) = \binom{k+n-1}{k} = \dfrac{(k+n-1)!}{k!\,(n-1)!}$ (ekrandan, 02:45:00).
- Koşullu olasılığa giriş
  - Bir koşul bilindiğinde olasılıklar değişir: zar çift geldiği biliniyorsa sonucun 1 olma olasılığı 0, 6 olma olasılığı $1/3$ olur (ekrandan, 02:55:00).
  - Tanım: $\Pr(B) \neq 0$ (B imkânsız olay değil) iken $\Pr(A \mid B) = \dfrac{\Pr(A \cap B)}{\Pr(B)}$ (ekrandan, 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Terminoloji
  - Hoca küme kuramı ile olasılık kuramı arasındaki terim eşleşmesini "çok önemli" diye tanıttı; aynı nesneye iki alanda farklı adlar verildiği için tablo halinde öğrenilmeli.
- Bölüntü için iki şart birlikte gerekir
  - Bir öğrencinin sorusu üzerine hoca, bölüntüde kümelerin hem birleşiminin örnek uzay olması hem de birbirleriyle kesişmemesi gerektiğini, biri eksikse bölüntü olmayacağını Türkçe olarak tekrar açıkladı.
- De Morgan kurallarının kullanışlılığı
  - Zor görünen bir problemi birleşimi kesişime (ya da tersini) çevirerek daha basit hale getirmek mümkündür.
- Monotonluk
  - $A$, $B$'nin alt kümesiyse $A$'nın olasılığı $B$'ninkinden büyük olamaz; hoca bunu ayrıca dikkate alınması gereken bir özellik olarak vurguladı.
- İspatlar
  - Özelliklerin ispatları aksiyomlardan adım adım yapıldı.
- Gösterim uyarısı
  - $\Pr(A \setminus B)$ ("A fark B") ile $\Pr(A \mid B)$ ("B verildiğinde A") aynı şey değildir; çizgi yönüne dikkat edilmeli.
- Kaynak kitap
  - Permütasyon ve kombinasyon bölümlerinin derste önerilen kitaptan (Michael Baron) okunması önemle tavsiye edildi.

## Kısa Tekrar Notları

- Topluca kapsayıcı: birleşim $= \Omega$. Karşılıklı ayrık: ikili kesişimler boş. İkisi birden: bölüntü.
- De Morgan: $\overline{A \cup B} = \bar A \cap \bar B$, $\overline{A \cap B} = \bar A \cup \bar B$.
- Olasılık modeli: çıktı, örnek uzay $\Omega$, olay $A \subset \Omega$.
- Göreli frekans $f_A(N) = \alpha/N$; $N \to \infty$ iken olasılığa yaklaşır.
- Üç aksiyom: $\Pr(A) \ge 0$, $\Pr(\Omega) = 1$, ayrık olaylarda toplanabilirlik.
- $\Pr(\bar A) = 1 - \Pr(A)$, $\Pr(\emptyset) = 0$, $\Pr(A \cup B) = \Pr(A) + \Pr(B) - \Pr(A \cap B)$.
- Bölüntü özelliği: $\Pr(A) = \sum_i \Pr(A \cap B_i)$. Monotonluk: $A \subseteq B \Rightarrow \Pr(A) \le \Pr(B)$.
- Eşit olasılıklı çıktılarda $\Pr(E) = |E| / |\Omega|$.
- Çarpma kuralı $n_1 n_2 \cdots n_k$; permütasyon yerine koyarak $n^k$, koymadan $n!/(n-k)!$.
- Kombinasyon yerine koymadan $\binom{n}{k}$, yerine koyarak $\binom{n+k-1}{k}$.
- Koşullu olasılık: $\Pr(A \mid B) = \Pr(A \cap B) / \Pr(B)$, $\Pr(B) \neq 0$.

## Detaylı Açıklamalar

- Kapsayıcılık ve ayrıklık örneği
  - Derste bir örnek uzay içinde kesişen iki olay $A$ ve $B$ çizildi. $A \cup B$ örnek uzayı doldurmadığı için bu iki olay topluca kapsayıcı değildir. Dışarıda kalan bölge $C = \overline{A \cup B}$ olarak adlandırılınca $A \cup B \cup C = \Omega$ olur, yani üçü birlikte kapsayıcıdır. Ancak $A \cap C = \emptyset$ ve $B \cap C = \emptyset$ olsa da $A \cap B \neq \emptyset$ olduğundan $A, B, C$ karşılıklı ayrık değildir. Buna karşılık $D = A \cup B$ ve $C$ çifti için hem $C \cup D = \Omega$ hem $C \cap D = \emptyset$ sağlanır; bu yüzden $\{C, D\}$ bir bölüntüdür (ekrandan, 00:15:00 ve 00:20:00).
- Göreli frekans örneği
  - Hoca MATLAB'de hilesiz bir zarın 60 kez atılmasını simüle etti (`randi(6,1,60)`, ekrandan, 01:00:00). $A = \{1\}$ için 1'leri sayarak $f_A(60) = 11/60 \approx 1/6$ buldu. $B = \{1, 3, 5\}$ (tek sayılar) için 11 + 9 + 13 = 33 sayıldı ve $f_B(60) = 33/60 \approx 1/2$ elde edildi. $C = \{2, 3, 5\}$ (asal sayılar) için yaklaşık $31/60 \approx 1/2$ bulundu. Bu oranlar atış sayısı arttıkça gerçek olasılıklara ($1/6$, $1/2$, $1/2$) yaklaşır. <!-- BELİRSİZ: 60 çıktılık dizi karede okunamayacak kadar küçük; sayımlar hocanın sözlü sayımından alındı. -->
  - Ders sonrası not: Hoca önce "zarı altı kez atarsanız en az bir kez 1 görürsünüz" dedi, sonra Türkçe olarak bunun garantili olmadığını, ancak çok sayıda tekrarda 1'in oranının $1/6$'ya yaklaşacağını söyledi. Doğrusu ikincisidir: altı atışta en az bir 1 görme olasılığı $1 - (5/6)^6 \approx 0{,}665$'tir.
- $\Pr(A \cup B)$ formülünün ispatı
  - $A = (A \setminus B) \cup (A \cap B)$ ve bu iki parça ayrık olduğundan $\Pr(A) = \Pr(A \setminus B) + \Pr(A \cap B)$ (1). Ayrıca $A \cup B = (A \setminus B) \cup B$ ve bu parçalar da ayrık olduğundan $\Pr(A \cup B) = \Pr(A \setminus B) + \Pr(B)$ (2). (1)'den (2) çıkarılınca $\Pr(A \setminus B)$ terimleri sadeleşir ve $\Pr(A) + \Pr(B) - \Pr(A \cap B) = \Pr(A \cup B)$ elde edilir.
- Bölüntü özelliği ve monotonluk
  - Örnek uzay $B_1, \dots, B_{10}$ parçalarına bölünmüş, $A$ olayı bunların bir kısmıyla kesişiyor. $A$, $A \cap B_i$ parçalarının ayrık birleşimi olduğundan Aksiyom 3 ile $\Pr(A) = \sum_i \Pr(A \cap B_i)$ olur; $A$ ile kesişmeyen parçaların katkısı sıfırdır (ekrandan, 01:40:00 ve 01:45:00).
  - $A \subseteq B$ ise $B = A \cup (B \setminus A)$ ve iki parça ayrıktır. $\Pr(B) = \Pr(A) + \Pr(B \setminus A)$ ve ikinci terim Aksiyom 1 gereği negatif olmadığından $\Pr(A) \le \Pr(B)$.
- Üç para atışı
  - $\Omega = \{HHH, HHT, HTH, HTT, THH, THT, TTH, TTT\}$, her çıktının olasılığı $1/8$. "Tam olarak iki tura (head)" olayı $A = \{HTH, THH, HHT\}$ olduğundan $\Pr(A) = 3/8$ (ekrandan, 02:10:00).
- Kombinasyon ile permütasyon ilişkisi
  - Yerine koymadan seçimde sıra önemsizse, aynı $k$ nesnenin $k!$ farklı sıralaması tek seçim sayılır. Bu yüzden $C(n,k) = P(n,k) / P(k,k) = n!/(k!(n-k)!)$ olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
