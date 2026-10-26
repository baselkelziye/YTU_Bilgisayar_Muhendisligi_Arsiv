# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 5 Kasım 2020 Perşembe. Ders Zoom üzerinden, İngilizce yapıldı.
  - Asıl ders yaklaşık 00:04:50'de başlar.
  - Hoca notlarını tablette yazıyor. Türkçe açıklamalar araya giriyor.
- Toplam olasılık kuralı (law of total probability) tekrarı ve torba-madeni para örneği
  - Torbada 3 hileli madeni para var. Yazı (heads) gelme olasılıkları 0.9, 0.6 ve 0.3.
  - Rastgele seçilen paranın yazı gelme olasılığı toplam olasılık kuralıyla bulunur.
- Bayes kuralı (Bayes' rule)
  - Şartlı olasılığın tanımından türetildi.
  - Payda çoğu zaman toplam olasılık kuralıyla hesaplanır.
  - Örnek: Yazı geldiğine göre seçilen paranın 1. para olma olasılığı.
- Şartlı bağımsızlık (conditional independence)
- Zincir kuralı (chain rule)
  - İki ve üç olay için yazıldı. Şartlı hâli de gösterildi.
  - Virgül gösterimi: $P(A \mid B, C) = P(A \mid B \cap C)$.
- Quiz duyurusu ve yeni çevrim içi sınav sistemi denemesi
  - Öğrenciler online.yildiz.edu.tr'de 2 soruluk deneme sınavına girdi. Not verilmedi.
  - Bu bölümde altyazı büyük ölçüde bozuk. Konuşma Türkçe olduğu için İngilizce çıktı anlamsız.
- Güvenilirlik (reliability) problemleri
  - Yedekli sabit disk örneği.
  - Seri (serial) ve paralel (parallel) bağlı bileşenler.
  - 5 bileşenli sistem örneği. Böl ve fethet (divide and conquer) yaklaşımı.
- Sayma (counting)
  - Eşit olasılıklı çıktılarda $P(A) = \frac{|A|}{|S|}$. Bu yüzden kümenin elemanlarını saymak gerekir.
  - Çarpma ilkesi (multiplication principle). Alt komite örneği.
  - Örnekleme (sampling): yerine koymalı (with replacement) / yerine koymasız (without replacement), sıralı (ordered) / sırasız (unordered). Dört durum incelendi.
  - Türkiye plaka sayısı, 52 kartlık desteden 5 kartlık el, donut seçme örnekleri.
  - Yıldızlar ve çubuklar (stars and bars) fikrine kısaca değinildi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bayes kuralı çok önemli. Sınavda neredeyse kesin çıkacak.
  - Yapay zekâ ve makine öğrenmesinde (ör. naive Bayes) sürekli karşınıza çıkacak.
- Olasılık sorusu çözmeden önce olaylara harf verin. Verilenleri ve isteneni bu harflerle denklem olarak yazın.
- Güvenilirlik sorularında birleşimi doğrudan hesaplamak zordur. Tümleyenden gidin.
  - "En az biri çalışır" $= 1 - P(\text{hepsi bozulur})$.
  - Bileşenler bağımsızsa kesişim, olasılıkların çarpımıdır. Bağımsız değilse zincir kuralı gerekir.
- Formülleri ezberlemek yerine mantığı hatırlayın.
  - Hoca $n^k$ gibi formülleri hatırlamadığını, mantıktan (çarpma ilkesi) yeniden kurduğunu söyledi.
- Quiz duyurusu:
  - Bir hafta sonra, üçüncü ders saatinde (15:00) yapılacak. En fazla 50 dakika.
  - Bu dersin konuları dahil, şimdiye kadar işlenen her şey kapsamda.
  - Hoca ağırlığın 10 puan olduğunu tahmin ediyor. Kesin bilgi için Bologna sistemine bakın.
  - Çoktan seçmeli test olarak online.yildiz.edu.tr'de yapılması planlanıyor.
- Çalışma kaynağı: Baron'un kitabında Bölüm 2 bitti. Bölümün sonundaki problemleri çözün. Pishro-Nik'te Bölüm 1 ve 2. Quiz sorularının bu kaynaklardan geleceğini söyledi.
- Sayma konusu liseden bilindiği için hızlı geçildi. Quiz'den sonra kesikli rastgele değişkenlere (discrete random variables) geçilecek.

## Kısa Tekrar Notları

- Toplam olasılık: $B_i$'ler örnek uzayın bir bölüntüsü ise $P(A) = \sum_i P(A \mid B_i)\,P(B_i)$.
- Bayes: $P(B \mid A) = \dfrac{P(A \mid B)\,P(B)}{P(A)}$, $P(A) \neq 0$.
  - Bölüntü ile: $P(B_j \mid A) = \dfrac{P(A \mid B_j)\,P(B_j)}{\sum_i P(A \mid B_i)\,P(B_i)}$.
- Şartlı bağımsızlık: $P(A \cap B \mid C) = P(A \mid C)\,P(B \mid C)$.
- Zincir kuralı:
  - $P(A \cap B) = P(A \mid B)\,P(B)$.
  - $P(A \cap B \cap C) = P(A \mid B, C)\,P(B \mid C)\,P(C)$. Sıra istenildiği gibi seçilebilir.
- Gösterim: $P(A \mid B, C)$, $P(A \mid B \cap C)$ ve $P(A \mid BC)$ aynı şeydir.
- Seri sistem: $P(S) = P(A \cap B)$. Paralel sistem: $P(S) = P(A \cup B) = 1 - P(\bar{A} \cap \bar{B})$.
- Çarpma ilkesi: $r$ ardışık deneyin çıktı sayısı $n_1 \cdot n_2 \cdots n_r$.
- Dört örnekleme durumu ($n$ elemandan $k$ tane):

| Durum | Sayı |
| :--- | :---: |
| Sıralı, yerine koymalı | $n^k$ |
| Sıralı, yerine koymasız (permütasyon) | $P(n,k) = \dfrac{n!}{(n-k)!}$ |
| Sırasız, yerine koymasız (kombinasyon) | $\binom{n}{k} = \dfrac{n!}{k!\,(n-k)!}$ |
| Sırasız, yerine koymalı | $\binom{n+k-1}{k}$ |

## Detaylı Açıklamalar

### Torba ve madeni para örneği

- Olaylar: $H$ = yazı gelmesi, $C_i$ = $i$. paranın seçilmesi.
- Verilenler: $P(H \mid C_1) = 0.9$, $P(H \mid C_2) = 0.6$, $P(H \mid C_3) = 0.3$, $P(C_i) = 1/3$.
- Toplam olasılık:
  - $P(H) = \sum_{i=1}^{3} P(H \mid C_i)\,P(C_i) = \frac{1}{3}(0.9 + 0.6 + 0.3) = 0.6$.
- Bayes ile ters soru: Yazı geldi. Para 1. para mı?
  - $P(C_1 \mid H) = \dfrac{P(H \mid C_1)\,P(C_1)}{P(H)} = \dfrac{0.9 \cdot \frac{1}{3}}{0.6} = 0.5$.
  - Önsel olasılık $1/3$ idi. Yazı gelmesi bu olasılığı $0.5$'e çıkardı. Çünkü 1. para yazıya en yatkın para.

### Bayes kuralının türetilmesi

- Şartlı olasılık tanımı iki yönde yazılır:
  - $P(B \mid A) = \dfrac{P(A \cap B)}{P(A)}$, $P(A \mid B) = \dfrac{P(A \cap B)}{P(B)}$.
- İkinciden $P(A \cap B) = P(A \mid B)\,P(B)$ çekilir ve birincide yerine konur.

### Zincir kuralı

- İki olay için tanımdan gelir: $P(A \cap B) = P(A \mid B)\,P(B)$.
  - Okunuşu: Önce $B$ olur. $B$ olduktan sonra $A$ olur.
- Üç olay için bir sıra seçilir:
  - $P(A \cap B \cap C) = P(C)\,P(B \mid C)\,P(A \mid B, C)$.
  - Aynı şey $P(A)\,P(B \mid A)\,P(C \mid A, B)$ olarak da yazılabilir.
- Şartlı hâli: Her terime "$\mid C$" eklenir.
  - $P(A \cap B \mid C) = P(A \mid B, C)\,P(B \mid C)$.
- Üçlü hâlin ispatı ev ödevi olarak bırakıldı. İkili kural iki kez uygulanarak elde edilir.

### Yedekli sabit disk örneği

- Ana diskin bozulma olasılığı %1. İki yedek diskin her birinin bozulma olasılığı %2. Üçü bağımsız.
- Bilgi yalnızca üç disk birden bozulursa kaybolur.
- Olaylar: $H$ = ana disk bozulur, $B_1$, $B_2$ = yedekler bozulur.
- Doğrudan yol: $P(\bar{H} \cup \bar{B_1} \cup \bar{B_2})$. Üçlü birleşim formülü 7 terim ister.
- Tümleyen yolu:
  - $P(\text{bilgi korunur}) = 1 - P(H \cap B_1 \cap B_2) = 1 - 0.01 \cdot 0.02 \cdot 0.02 = 0.999996$.
- Öğrenci sorusu: Olaylar bağımsızsa kesişimler sıfır mı olur?
  - Hayır. Bağımsızlık kesişimi sıfır yapmaz. Kesişim olasılıkların çarpımıdır. Kesişimi sıfır olan olaylar ayrık (disjoint) olaylardır.

### Beş bileşenli sistemin güvenilirliği

- Devre: Üst kolda $A$ ve $B$ seri. Alt kolda $C$, ardından paralel bağlı $D$ ve $E$. İki kol birbirine paralel.
- Her bileşen bağımsız olarak $0.92$ olasılıkla çalışıyor.
- Adım adım indirgeme:
  - $F = A \cap B$: $P(F) = 0.92^2 = 0.8464$.
  - $G = D \cup E$: $P(G) = 1 - 0.08^2 = 0.9936$.
  - $H = C \cap G$: $P(H) = 0.92 \cdot 0.9936 = 0.914112$.
  - $S = F \cup H$: $P(S) = 1 - (1 - 0.8464)(1 - 0.914112) \approx 0.9868$.
- Benzer sorular Baron'un kitabında var.

### Sayma ve örnekleme

- Alt komite örneği: 3 birinci sınıf, 4 ikinci sınıf, 5 üçüncü sınıf, 2 dördüncü sınıf öğrencisi var. Her sınıftan bir kişi seçilir.
  - $3 \cdot 4 \cdot 5 \cdot 2 = 120$ farklı alt komite.
- $A = \{1, 2, 3\}$ kümesinden $k = 2$ eleman seçimi:
  - Sıralı, yerine koymalı: 11, 12, 13, 21, 22, 23, 31, 32, 33. Toplam $3^2 = 9$.
  - Sıralı, yerine koymasız: 11, 22, 33 çıkar. Toplam $3 \cdot 2 = 6$.
  - Sırasız, yerine koymasız: 12, 13, 23. Toplam $\binom{3}{2} = 3$.
  - Sırasız, yerine koymalı: 11, 22, 33, 12, 13, 23. Toplam $\binom{4}{2} = 6$.
- Permütasyon formülünde $0 \le k \le n$ olmalı.
- Ayırt edilebilir (distinguishable) nesne = sıra önemli. Ayırt edilemez (indistinguishable) nesne = sıra önemsiz. Ayırt edilebilirlik problemin bakış açısına göredir.
- Kombinasyon, permütasyonun $k!$'e bölünmesidir. Çünkü seçilen $k$ elemanın $k!$ farklı sıralaması aynı seçimi verir.
- Plaka örneği: "34 BA 1482" kalıbı. 2 rakam, 2 harf, 4 rakam.
  - Hoca her rakam için 10, her harf için 28 seçenek aldı: $10^2 \cdot 28^2 \cdot 10^4 = 784\,000\,000$.
  - Hoca bunu kaba bir model olarak kurdu. Bir öğrencinin uyarısıyla her hanenin tüm değerleri alamayabileceğini kabul etti.
- Poker eli: 52 kartlık desteden 5 kart. Sırasız ve yerine koymasız. $\binom{52}{5} = 2\,598\,960$.
- Donut örneği: 4 çeşitten 3 donut. Aynı çeşit birden fazla alınabilir. Sıra önemsiz.
  - $\binom{4+3-1}{3} = \binom{6}{3} = 20$.
  - Yıldızlar ve çubuklar: 3 yıldız (donut) ve çeşitleri ayıran 3 çubuk vardır. 6 konumdan çubukların (veya yıldızların) yeri seçilir.
  - $x_1 + x_2 + x_3 + x_4 = 3$ denkleminin negatif olmayan tam sayı çözümlerinin sayısı da aynıdır.
  - Öğrenci sorusu: Neden $4 \cdot 4 \cdot 4$ değil? Çünkü $4^3 = 64$ sıralı seçimleri sayar. Burada (çikolata, muz, çikolata) ile (çikolata, çikolata, muz) aynı seçimdir.

### Ders sonrası notlar

- Hoca zincir kuralını önce $P(A \cap B) = P(A \mid B)\,P(A)$ diye yazdı, sonra düzeltti. Doğrusu $P(A \cap B) = P(A \mid B)\,P(B)$.
- Hoca bir yerde "sıralı, yerine koymalı örnekleme permütasyondur" dedi. Doğrusu: Permütasyon sıralı ve yerine koymasız örneklemedir. Sıralı ve yerine koymalı durumun sayısı $n^k$'dır.
- Sırasız ve yerine koymalı formül derste önce yanlış yazıldı ($\binom{n-k+1}{k}$). Bir öğrenci düzeltti. Doğrusu $\binom{n+k-1}{k} = \binom{n+k-1}{n-1}$.
  - Kontrol: $n = 3$, $k = 2$ için $\binom{4}{2} = 6$. Liste ile uyumlu.
- Donut örneğinde hoca "6 konumdan 3 tane seçiyoruz" fikrini derste toparlayamadı. Açıklama: $k$ yıldız ve $n-1$ çubuk toplam $n+k-1$ konum oluşturur. Bunlardan $k$ tanesi yıldızdır.
- Hoca bir yerde $P(C_1 \mid H)$ için sayısal sonucu vermedi. Hesap: $0.5$. $P(H) = 0.6$.
- Plaka örneği gerçek kuralları yansıtmıyor. Türkiye'de ilk iki hane 01-81 arası il kodudur. Plakalarda Ç, Ğ, İ, Ö, Ş, Ü kullanılmaz. Harf sayısı 1-3, rakam sayısı 2-4 arasında değişir. Örnek yalnızca çarpma ilkesini göstermek içindir.
- Hoca 7 terimli birleşim açılımını "toplam, çiftli kesişimleri çıkar, üçlü kesişimi ekle" diye anlattı:
  - $P(A \cup B \cup C) = P(A) + P(B) + P(C) - P(A \cap B) - P(A \cap C) - P(B \cap C) + P(A \cap B \cap C)$.
- Yaklaşık 00:43:00 ile 00:50:30 arası deneme sınavı bölümünde konuşma Türkçe. Altyazı bu bölümde anlamsız ve döngülü. Bu kısımdan konu içeriği çıkmaz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilirsiniz. Bu ders İngilizce anlatılmıştır; altyazı da İngilizcedir.
