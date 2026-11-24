# Ders 23 Çalışma Özeti

## Genel Konular

- N-vezir (N-Queens) problemi ve arama uzayının küçültülmesi
  - Amaç: $n$ veziri $n \times n$ satranç tahtasına birbirini görmeyecek biçimde yerleştirmek. Vezir satır, sütun ve çapraz boyunca hareket eder; bu yüzden aynı satır, sütun ya da çaprazda iki vezir olamaz.
  - 8 vezir için denenecek durum sayıları (ekrandan, 00:20:00):
    - Kaba kuvvet: $\binom{64}{8} = \frac{64!}{(64-8)!\,8!} = 4\,426\,165\,368$ durum.
    - Her satıra bir vezir: $n^n \Rightarrow 8^8 = 16\,777\,216$ durum.
    - Her satıra ve her sütuna bir vezir: $n! \Rightarrow 8! = 40\,320$ durum.
    - Geri izleme (backtracking): hocanın verdiği sayıya göre 2057 adım.
  - 4 vezir örneği adım adım çözülür ve çözüm $(2, 4, 1, 3)$ bulunur (satır $i$'deki vezirin sütunu).
- Geri izleme (backtracking) yaklaşımı
  - Çözüm adım adım kurulur. Bir noktada çözüme ulaşılamayacağı anlaşılınca o yoldan devam edilmez, bir önceki karar noktasına dönülüp sıradaki seçenek denenir.
  - Denenen seçenekler durum uzayı ağacı (state space tree) ile gösterilir.
  - Mantık derinlik öncelikli aramadır (DFS): en derine kadar gidilir, çıkmazda en son gelinen düğüme dönülür. Bu yüzden genelde özyinelemeli ya da yığıt (LIFO) ile yazılır.
  - Dinamik programlamadan farkı: dinamik programlama bütün alt çözümleri üretip saklar; geri izleme umutsuz dalları hiç açmaz.
- Hamilton çevrimi (Hamiltonian circuit) problemi
  - Bir düğümden çıkıp her düğüme tam bir kez uğrayarak başlangıç düğümüne dönülebiliyorsa bu yol bir Hamilton çevrimidir.
  - Örnek graf (ekrandan, 00:45:00): düğümler $a, b, c, d, e, f$; kenarlar $a\text{-}b$, $a\text{-}c$, $a\text{-}d$, $b\text{-}c$, $b\text{-}f$, $c\text{-}d$, $c\text{-}e$, $d\text{-}e$, $e\text{-}f$.
  - Geri izlemeyle bulunan çözüm: $a \to b \to f \to e \to c \to d \to a$.
- Dal ve sınır (branch and bound) yaklaşımı
  - Geri izlemenin optimizasyon problemlerine uyarlanmış biçimidir: seçimlerin bir bedeli (maliyet ya da kazanç) vardır ve en iyi çözüm (optimal solution) aranır.
  - Her düğüm için bir sınır hesaplanır: en küçükleme probleminde alt sınır (lower bound), en büyüklemede üst sınır (upper bound). Sınırı o ana kadar bulunan gerçek çözümden kötü olan dallar açılmaz.
- Atama problemi (assignment problem), en küçük maliyet
  - 4 kişi ($a, b, c, d$), 4 iş; maliyet matrisi (ekrandan, 01:10:00):

    | | İş 1 | İş 2 | İş 3 | İş 4 |
    |---|---|---|---|---|
    | a | 9 | 2 | 7 | 8 |
    | b | 6 | 4 | 3 | 7 |
    | c | 5 | 8 | 1 | 8 |
    | d | 7 | 6 | 9 | 4 |

  - Alt sınır: sabitlenmiş atamaların maliyeti ile kalan her kişinin boş işler arasındaki en küçük maliyetinin toplamı. Aynı işe iki kişinin düşmesi bu hesapta önemsenmez.
  - Başlangıç: $2 + 3 + 1 + 4 = 10$. $a \to 1$: 17, $a \to 2$: 10, $a \to 3$: 20, $a \to 4$: 18 (ekrandan, 01:15:00).
  - $a \to 2$ altında: $b \to 1$: 13, $b \to 3$: 14, $b \to 4$: 17 (ekrandan, 01:20:00).
  - $a \to 2, b \to 1$ altında: $c \to 3, d \to 4$ gerçek maliyet 13; $c \to 4, d \to 3$ gerçek maliyet 25. En iyi atama $a \to 2$, $b \to 1$, $c \to 3$, $d \to 4$, maliyet 13.
- 0-1 sırt çantası problemi, dal ve sınır ile (en büyük kazanç)
  - Kapasite $W = 10$; eşyalar (ekrandan, 01:35:00): 1: 4 kg, 40 TL; 2: 7 kg, 42 TL; 3: 5 kg, 25 TL; 4: 3 kg, 12 TL. Birim değerler $v_i/w_i$: 10, 6, 5, 4; eşyalar birim değere göre büyükten küçüğe sıralanır.
  - Üst sınır: $ub = v + (W - w)\,(v_{i+1}/w_{i+1})$.
  - Ağaç (ekrandan, 01:50:00): kök $ub = 100$; 1 alınır $ub = 76$, alınmaz $ub = 60$; 1 ile 2 alınırsa $w = 11$ (sığmaz); 1 var 2 yok $ub = 70$; 3 alınır $w = 9, v = 65, ub = 69$; 3 alınmaz $ub = 64$; 4 alınırsa $w = 12$ (sığmaz); 4 alınmaz $v = 65, ub = 65$.
  - En iyi çözüm: 1 ve 3 numaralı eşyalar, 9 kg, 65 TL.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çalışan ama verimsiz algoritma ile iyi tasarlanmış algoritma arasındaki fark çok büyüktür.
  - 8 vezirde kaba kuvvet yaklaşık 4,4 milyar durum dener; problemin yapısı kullanıldıkça sayı 16,7 milyona, 40 bine ve geri izlemeyle 2057'ye iner.
- Yerleştirme hiyerarşik yapılır.
  - Rastgele yer seçilmez; ilk vezir 1. satırın 1. sütunundan başlar, her satırda sütunlar soldan sağa denenir.
- Bir vezir yerleştirilemiyorsa bir önceki vezirin yeri değiştirilir.
  - Sonraki satırları denemenin anlamı yoktur; geri dönülür.
- Geri izleme DFS mantığıdır ve genelde özyinelemeli çözülür.
  - 8 vezir algoritmasını kaynaklara bakmadan kendiniz yazmayı deneyin (çalışma önerisi).
- Sınır gerçek çözüm değildir.
  - Alt ya da üst sınır, "kurallar hiçe sayılsaydı en iyi ne olurdu" sorusunun cevabıdır. Hangi dalın denenmeye değer olduğunu gösterir.
- Dal ve sınırda en umutlu düğümden devam edilir ve bütün açık düğümler karşılaştırılır.
  - Gerçek çözümün maliyeti, açık kalan düğümlerin sınırlarından iyiyse onları denemeye gerek yoktur. Başka bir katmanda daha iyi sınır varsa önce o denenir.

## Kısa Tekrar Notları

- N-vezir: aynı satır, sütun, çaprazda iki vezir olamaz.
- 8 vezir: $\binom{64}{8} = 4\,426\,165\,368$; $8^8 = 16\,777\,216$; $8! = 40\,320$; geri izleme 2057.
- 4 vezir çözümü: $(2, 4, 1, 3)$.
- Geri izleme = DFS + umutsuz daldan geri dönme; durum uzayı ağacıyla gösterilir.
- Hamilton çevrimi: her düğüme tam bir kez uğrayıp başlangıca dönmek. Örnek çözüm $a\,b\,f\,e\,c\,d\,a$.
- Dal ve sınır: optimizasyon için geri izleme; en küçüklemede alt sınır, en büyüklemede üst sınır.
- Atama örneği: başlangıç alt sınırı 10; en iyi çözüm $a \to 2, b \to 1, c \to 3, d \to 4$, maliyet 13.
- Sırt çantası üst sınırı: $ub = v + (W - w)(v_{i+1}/w_{i+1})$; örnekte en iyi çözüm {1, 3}, 65 TL.

## Detaylı Açıklamalar

- **N-vezir ve arama uzayı.** 8 vezir probleminde akla gelen ilk yol kaba kuvvettir: 64 kareden 8'ini seçen bütün kombinasyonlar denenir, bu $\binom{64}{8} = 4\,426\,165\,368$ durumdur. Bir satıra iki vezir gelemeyeceği görülünce her satıra bir vezir konur ve durum sayısı $8^8 = 16\,777\,216$'ya iner. Aynı sütuna da iki vezir gelemeyeceği eklenince her satır ve sütunda bir vezir kalır ve sayı $8! = 40\,320$ olur. Daha iyisi, umut kalmadığı anlaşılan noktada aramayı kesip geri dönmektir; hocanın verdiği sayıya göre geri izleme 8 vezirde 2057 adımda sonuca varır.
- **4 vezir izlemesi (ekrandan, 00:30:00).** 1. vezir (1,1)'e konur. 2. vezir için 1. ve 2. sütunlar yasaktır, (2,3)'e konur. 3. satırın dört sütunu da 1. ya da 2. vezir tarafından görülür, bu yüzden geri dönülür ve 2. vezir (2,4)'e kaydırılır. 3. vezir (3,2)'ye konur; bu kez 4. satırın her sütunu görülür. 2. vezirin gidecek başka yeri olmadığından 1. vezire kadar geri çıkılır ve 1. vezir (1,2)'ye konur. Ardından 2. vezir (2,4), 3. vezir (3,1), 4. vezir (4,3)'e yerleşir ve çözüm bulunur. Bu çizim durum uzayı ağacıdır.
- **Geri izleme ve DFS.** Geri izlemede yapılan, bir noktadan gidilebilecek en son yere kadar gidip çıkmazda en son ayrılınan düğüme dönmektir. Bu derinlik öncelikli aramadır; geri dönüş son giren ilk çıkar (LIFO) mantığıyla yürür, bu yüzden özyineleme ya da yığıt ile yazılır.
- **Hamilton çevrimi örneği (ekrandan, 00:45:00).** $a$'dan başlanır: $a \to b \to c \to d \to e \to f$ yolunda $f$'nin komşuları $b$ ve $e$ zaten ziyaret edilmiştir; çıkmazdır. Geri dönülerek $c \to e$ denenir: $e \to d$ çıkmaz ($d$'nin komşuları $a, c, e$), $e \to f$ çıkmaz. $c$'nin seçenekleri bitince $b$'ye dönülür ve $b \to f \to e \to c \to d$ yolu bulunur; $d$, $a$'ya bağlı olduğu için çevrim tamamlanır: $a\,b\,f\,e\,c\,d\,a$.
- **Atama problemi ve alt sınır.** Başlangıçta her kişi en ucuz işine konmuş varsayılır ($2 + 3 + 1 + 4 = 10$); $b$ ve $c$'nin ikisi de 3. işe düştüğü için bu gerçek bir atama değildir, yalnız bir alt sınırdır. $a$'nın her iş için sabitlenmesiyle 17, 10, 20, 18 bulunur. En küçük sınırlı düğüm ($a \to 2$) açılır: $b \to 1$ için 13, $b \to 3$ için 14, $b \to 4$ için 17. $a \to 2, b \to 1$ düğümünde kalan iki kişi için iki atama vardır ve gerçek maliyetler 13 ve 25'tir. Gerçek maliyet 13, açık kalan bütün sınırlardan (14, 17, 17, 20, 18) küçük olduğu için başka dal denenmez.
- **Sırt çantası ve üst sınır.** Eşyalar birim değere göre sıralanır. Kökte hiçbir şey yokken kalan 10 kg'ın tamamı en değerli birim fiyatla (10 TL/kg) doldurulsaydı kazanç en fazla 100 TL olurdu. 1. eşya alınınca $40 + 6 \cdot 6 = 76$, alınmayınca $10 \cdot 6 = 60$. 76 daha umutlu olduğu için o dal açılır: 2. eşya sığmaz ($4 + 7 = 11$), 2. eşya olmadan $40 + 6 \cdot 5 = 70$. 3. eşya alınınca $w = 9$, $v = 65$, $ub = 65 + 1 \cdot 4 = 69$; alınmayınca $40 + 6 \cdot 4 = 64$. 4. eşya sığmaz ($9 + 3 = 12$); alınmayınca gerçek değer 65 olur. 65, açık kalan 60 ve 64 sınırlarından büyük olduğu için çözüm {1, 3}, 65 TL'dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
