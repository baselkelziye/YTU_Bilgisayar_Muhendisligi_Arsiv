# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 8 Ekim 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl ders yaklaşık 05:00'te başlar. İlk dakikalar selamlaşma ve bekleme kısmıdır.
  - Hoca kendini Oğuz Altun olarak tanıttı. Derste yaklaşık 56 öğrenci vardı.
  - Hoca, İngilizce anlamadığınız bir kelimeyi sorabileceğinizi, soruları Türkçe de sorabileceğinizi söyledi.
- Dersin işleyişi
  - Ofis saati: Çarşamba 15:00-17:00. Bu saatler uymazsa e-posta ile ya da Calendly üzerinden görüşme talebi gönderilebilir.
  - Ders izlencesi (syllabus) Bologna Bilgi Sistemi'nde (BLM2011) bulunur.
  - Dersin amacı: belirsizlik (uncertainty) içeren problemleri olasılık ve istatistik modelleriyle modellemek ve çözmek.
  - Dosyalar (örnekler, eski sınavlar) Dropbox linkiyle paylaşılacak. Dosyaları görmek için Dropbox hesabı gerekmez.
  - Duyurular USİS e-posta sistemiyle yapılacak. USİS e-postası almıyorsanız üniversitenin bilgi işlem birimiyle görüşün.
- Kaynak kitaplar
  - Michael Baron, *Probability and Statistics for Computer Scientists*, 2. baskı.
  - Hossein Pishro-Nik, *Introduction to Probability, Statistics and Random Processes*. Bu kitap internette ücretsizdir.
  - İki kitabın içeriği çok yakındır. Baron'un kitabında alıştırma çok daha fazladır.
- Dönem planı (taslak)
  - Giriş ve olasılığa giriş.
  - Rastgele değişkenler (random variables) ve dağılımları (2 hafta).
  - Beklenen değer (expectation), varyans (variance), kovaryans (covariance), korelasyon (correlation).
  - Kesikli dağılımlar (discrete distributions, 1 hafta), sürekli dağılımlar (continuous distributions, 2 hafta).
  - Vize.
  - İstatistik: parametre tahmini (parameter estimation), güven aralıkları (confidence intervals), hipotez testi (hypothesis testing), p-değerleri, varyanslar hakkında çıkarım.
  - Final.
- Olasılığa giriş ve olasılığın iki yorumu
- Küme teorisi tekrarı (sets)
- Fonksiyonlar (functions), kardinalite (cardinality), sonlu ve sonsuz kümeler

## Hocanın Özellikle Vurguladığı Kısımlar

- Hoca slayt, PPT veya ders notu paylaşmayacak.
  - Kâğıt kalem alın ve kendi notunuzu tutun. Hoca bunu dersin sonunda Türkçe olarak da tekrarladı.
- Not dağılımı: 2 quiz toplam 20 puan, vize 40 puan, final 40 puan.
  - Quiz tarihleri önceden belli değil. Quizden önce duyurulacak.
- İngilizce okuyup anlayabilmelisiniz.
  - Öğrenilecek şeylerin çoğu önce İngilizce çıkıyor. Matematik kitabını okuyamıyorsanız İngilizceye ayrıca zaman ayırın.
- Olasılık problemlerinde ilk iş örneklem uzayını (sample space) yazmaktır.
- Olasılıklar kümeler üzerinden hesaplanır.
  - "1'in olasılığı" dediğimizde aslında tek elemanlı $\{1\}$ kümesinin olasılığından bahsediyoruz.
- Yapay zekâ olasılık üzerine kuruludur. Bu yüzden olasılık bugün iş bulmak için çok önemlidir.
- İki kitabın notasyonları farklıdır, ikisini de bilin.
  - Örneklem uzayı: Baron'da $\Omega$, Pishro-Nik'te $S$.
  - Tümleyen: Baron'da $\bar{A}$, Pishro-Nik'te $A^c$.
  - Fark: Baron'da $A \setminus B$, Pishro-Nik'te $A - B$.
- Baron'un fark işaretindeki çizgi sola yatıktır ($\setminus$). Dik çizgi veya bölü işareti gibi yazmayın.
  - Dik çizgi ($|$) şartlı olasılıkta kullanılacak. $/$ bölme işaretidir.

## Kısa Tekrar Notları

- Olasılığın iki yorumu:
  - Frekans yorumu (frequentist): deney çok kez tekrarlanır. Olayın görülme oranı olasılığıdır.
  - İnanç yorumu (belief, Bayesçi yorum): deney tekrarlanamaz. Olasılık, olayın gerçekleşeceğine olan inançtır.
- Küme: sırasız eleman topluluğudur.
  - Elemanlar listelenerek ($B=\{1,2,3\}$) ya da tarif edilerek ($A=\{x^2 : x=1,2,3,\dots\}$) yazılır. ":" ve "|" "öyle ki" (such that) diye okunur.
- Bilinen kümeler: $\mathbb{N}$ (doğal sayılar, bu derste 1'den başlar), $\mathbb{Z}$ (tam sayılar), $\mathbb{Q}$ (rasyonel sayılar), $\mathbb{R}$ (reel sayılar).
- Alt küme: $A \subseteq B \iff (x \in A \Rightarrow x \in B)$.
- Eşitlik: $A = B \iff A \subseteq B$ ve $B \subseteq A$.
- Boş küme $\emptyset$ her kümenin alt kümesidir. Örneklem uzayı o problemdeki her kümenin üst kümesidir (superset).
- Birleşim: $x \in A \cup B \iff x \in A$ veya $x \in B$.
- Kesişim: $A \cap B$, hem $A$'da hem $B$'de olan elemanlar.
- Tümleyen: $A^c$, örneklem uzayında olup $A$'da olmayan elemanlar.
- Fark: $A \setminus B$, $A$'da olup $B$'de olmayan elemanlar.
- Ayrık (disjoint) ya da birbirini dışlayan (mutually exclusive) kümeler: $A \cap B = \emptyset$.
- Bölüntü (partition): kümeler ayrıktır ve birleşimleri örneklem uzayıdır.
- De Morgan: $(A \cup B)^c = A^c \cap B^c$, $(A \cap B)^c = A^c \cup B^c$.
- Dağılma: $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$, $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$.
- Fonksiyon $f: X \to Y$: $X$ tanım kümesi (domain), $Y$ değer kümesi (codomain). Görüntü kümesi (range), $f(x)$'in alabildiği değerlerdir. Range her zaman codomain'in alt kümesidir.
- Birebir (one-to-one) ya da tersinir (invertible) fonksiyon: farklı girdiler farklı çıktılara gider.
- Kardinalite $|A|$: kümedeki eleman sayısı. Sonlu küme: $|A| < \infty$.

## Detaylı Açıklamalar

- Belirsizlik ve karar verme
  - Hoca olasılığın, belirsizliği ölçmeye ve belirsizlik altında karar vermeye yaradığını anlattı.
  - Borsa örneği: hisse büyük olasılıkla düşecekse satmak, yükselecekse tutmak mantıklı olabilir.
  - Hava durumu örneği: bugün İstanbul'a dolu (hail) yağacak mı, dolu iri mi olacak? İri dolu bekleniyorsa araba kapalı otoparka konabilir.
- Frekans yorumu örneği
  - Bir para 1000 kez atılıyor. Yaklaşık 600 kez tura (heads), 400 kez yazı (tails) geliyor.
  - Bu durumda turanın olasılığı yaklaşık $600/1000 = 0.6$'dır. Bu para hilesiz (fair) değildir.
- İnanç yorumu örneği
  - "Kutuplardaki buzun kütlesi 50 yıl içinde yarıya inecek mi?" sorusu.
  - Bu deney 1000 kez tekrarlanamaz, tek bir kez olur. Bu yüzden olasılık bir inançtır.
  - Hocaya göre iki yorum bu derste aynı araçlarla çalışılır. Yorumlar daha ileri konularda ayrışır.
- Örneklem uzayı probleme göre değişir
  - Hava durumunda dolu ile ilgileniyorsanız: $\Omega = \{\text{yağmurlu}, \text{dolulu}, \text{güneşli}\}$.
  - Dolu sizin için önemsizse: $\Omega = \{\text{güneşli}, \text{yağmurlu}\}$.
- Venn diyagramları
  - Örneklem uzayı dikdörtgen, kümeler içinde kapalı bölgeler olarak çizilir.
  - Birleşim, kesişim, tümleyen ve fark bu diyagramlarla kolayca görülür.
- Ayrık kümeler (çok sayıda küme için)
  - $A_1, A_2, \dots, A_n$ kümeleri, her $i \neq j$ için $A_i \cap A_j = \emptyset$ ise ayrıktır.
- Bölüntü örneği
  - Örneklem uzayı $A_1, \dots, A_5$ gibi parçalara bölünür. Parçalar kesişmez, birleşimleri $\Omega$'yı verir.
- De Morgan çok sayıda küme için de geçerlidir: $(A_1 \cup A_2 \cup \dots \cup A_n)^c = A_1^c \cap A_2^c \cap \dots \cap A_n^c$.
- Derste çözülen örnek
  - $\Omega = \{1,2,3,4,5,6\}$, $A = \{1,2\}$, $B = \{2,4,6\}$. Soru: $A^c \cap B^c$ nedir?
  - Çözüm 1: $A^c = \{3,4,5,6\}$, $B^c = \{1,3,5\}$. Kesişim $\{3,5\}$'tir.
  - Çözüm 2 (De Morgan): $A^c \cap B^c = (A \cup B)^c$. $A \cup B = \{1,2,4,6\}$, tümleyeni $\{3,5\}$'tir.
  - Tümleyen içeren sorularda De Morgan kuralı işi kolaylaştırabilir.
- Fonksiyon örneği
  - $f: \mathbb{R} \to \mathbb{R}$, $f(x) = x^2$. Tanım kümesi ve değer kümesi $\mathbb{R}$'dir.
  - Görüntü kümesi $\{y \in \mathbb{R} : y \ge 0\}$'dır. Bu küme codomain'den küçüktür.
  - Büyük harf (ör. $X$) genelde küme adı, küçük harf (ör. $x$) genelde eleman için kullanılır.
- Rastgele değişkenler (random variables) de birer fonksiyondur. Fonksiyonların önemi buradan gelir.
- Tersinir fonksiyon
  - $f(x_1) = f(x_2)$ yalnızca $x_1 = x_2$ ise olur.
  - İki farklı $x$ aynı $y$'ye gidiyorsa ($g$ fonksiyonu), $g^{-1}(y)$'nin hangi $x$'e gideceği belli değildir. Bu yüzden $g^{-1}$ fonksiyon olamaz, $g$ tersinir değildir.
- Kardinalite örneği
  - $A = \{1, a, 2\}$ ise $|A| = 3$.
  - $\mathbb{N}$ sonsuz bir kümedir.
  - Sayılabilir (countable) ve sayılamaz (uncountable) kümeler sonraki derse bırakıldı.

### Ders sonrası notlar

- Derste rasyonel sayılara "3 veya 2 gibi" örneği verildiği duyuluyor. Rasyonel sayılar $a/b$ ($a \in \mathbb{Z}$, $b \in \mathbb{Z}$, $b \neq 0$) biçimindeki sayılardır. Örnek: $3/2$, $4/5$.
- Derste "boş küme her elemanın alt kümesidir" dendi. Doğrusu: boş küme her **kümenin** alt kümesidir.
- Derste $x^2$'nin görüntü kümesi için "pozitif sayılar" dendi. $0^2 = 0$ olduğu için doğrusu negatif olmayan sayılardır: $[0, \infty)$. Hoca tahtaya doğru olarak $\ge 0$ yazdı.
- Derste ayrık kümeler için "kesişimleri sıfır" dendi. Doğrusu: kesişim **boş kümedir** ($\emptyset$). Sıfır bir sayıdır, boş küme değildir.
- Kayıtta hocanın e-posta adresi net anlaşılmıyor. Adresi resmî kaynaklardan kontrol edin.
- Kayıtta 01:47-01:49 ve 02:29-02:31 arası anlaşılmıyor. Bu kısımlarda Türkçe konuşma var ve altyazı bozuk.
- Dersin sonunda bir öğrenci fonksiyon kısmını Türkçe istedi. Hoca kısaca Türkçe anlattı: tanım kümesi (domain), değer kümesi (codomain), görüntü kümesi (range). Kardinalitenin Türkçesi için "eleman sayısı" dendi.

**Not:** Bu ders İngilizce anlatılmıştır. İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
