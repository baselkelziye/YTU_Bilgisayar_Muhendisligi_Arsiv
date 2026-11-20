# Ders 6 Çalışma Özeti

## Genel Konular

- Dizi hizalama varyantlarının hatırlatılması
  - Global hizalama (Needleman-Wunsch): ilk satır ve ilk sütun boşluk cezasıyla başlatılır, $S_{i,0} = i \cdot w$, $S_{0,j} = j \cdot w$; hücre değeri çapraz, üst ve sol komşudan gelen üç değerin en büyüğüdür (ekrandan, 00:10:00).
  - Yerel hizalama (Smith-Waterman): ilk satır ve sütun 0 ile başlatılır; aynı yineleme bağıntısına 0 eklenir, yani hiçbir hücre negatif olamaz.
  - Örtüşme (overlap) hizalaması: yerel gibi başlar (ilk satır ve sütun 0), global gibi devam eder (yineleme global ile aynıdır).
  - En iyi hizalama büyük ölçüde seçilen skor şemasına (metriğe) bağlıdır.
- Skor matrisleri
  - Basit eşleşme/uyuşmazlık skoru benzer diziler için kötü değildir ama uzak akraba dizileri göstermez (ekrandan, 00:15:00).
  - Olabilirlik (likelihood) matrisi, bir yer değiştirmenin doğada görülme olasılığına göre skor verir; amino asit dizilerinde daha uygundur.
  - DNA için en basit şema: aynı harf 1, farklı harf 0 (birim matris).
  - Protein skor matrisinde her amino asit çiftinin ayrı değeri vardır (ör. C:C = 9, S:S = 4, T:T = 5, P:P = 7, T:G = −2) (ekrandan, 00:20:00).
- Amino asitlerin özellikleri
  - Amino asitler biyokimyasal ve fiziksel özellikleri yüzünden evrimde birbirinin yerine farklı kolaylıkla geçer: çok küçük (tiny), küçük, alifatik (I, V, L), aromatik (F, Y, W, H), hidrofobik, polar, yüklü, pozitif gruplar (ekrandan, 00:25:00).
  - Kimyasal olarak benzer amino asitlerin yer değiştirmesi daha olasıdır; skor matrisleri bu sıklıklardan log-odds değeri olarak türetilir.
- PAM matrisleri (Percent Accepted Mutations)
  - Dayhoff ve arkadaşları (1978); aileleri en az %85 özdeş olan protein ailelerinin global hizalamalarından türetilir (ekrandan, 00:30:00).
  - Her aile için filogenetik ağaç ve atasal diziler kurulur, her amino asit çifti için yer değiştirme sayısı hesaplanır.
  - PAM1, amino asit konumlarının ortalama %1'inin değişmesine karşılık gelir. Daha büyük evrimsel uzaklıklar için PAM1 çarpılarak (üs alınarak) türetilir; PAM250 yaklaşık 100 kalıntıda 250 değişim demektir.
  - Matristeki 0, hizalanma sıklığının rastgele ile aynı olduğunu gösterir. Değer, gözlenen sıklığın beklenen sıklığa oranının logaritmasıdır.
- BLOSUM matrisleri (Blocks Substitution Matrix)
  - Uzak akraba proteinlerin korunmuş bloklarının (domain) hizalamalarından türetilir; blok içindeki diziler özdeşlik düzeyine göre kümelenir, her küme tek dizi sayılır (ekrandan, 00:35:00).
  - Addaki sayı (BLOSUM62'de 62) kümelemede kullanılan özdeşlik yüzdesidir; büyük sayı küçük evrimsel uzaklık demektir.
  - BLOSUM62'de kimyasal olarak benzer yer değiştirmeler pozitif, yaygın amino asitler düşük, nadir amino asitler yüksek ağırlıklıdır (ör. W:W = 11) (ekrandan, 00:45:00).
- Nükleik asit skor şeması
  - Geçiş (transition) mutasyonu daha yaygındır: pürin ↔ pürin (A ↔ G), pirimidin ↔ pirimidin (T ↔ C).
  - Çaprazlama (transversion) mutasyonu daha az olasıdır: pürin ↔ pirimidin.
  - Daha iyi DNA şeması: eşleşme 20, geçiş 10, çaprazlama 5 (ekrandan, 00:40:00).
  - Kimura modelinde $\alpha$ geçiş hızı, $\beta$ çaprazlama hızıdır.
  - 1 PAM uzaklığında nükleotit matrisleri: düzgün mutasyon modelinde köşegen 0,99, diğerleri 0,00333; geçişlerin 3 kat olduğu modelde köşegen 0,99, geçiş 0,006, çaprazlama 0,002 (ekrandan, 00:55:00).
- Log-odds matrisleri
  - PAM matrisi log-odds matrisine çevrilir: her yer değiştirme skoru amino asit sıklığına bölünür, oranın $\log_{10}$'u alınıp 10 ile çarpılır, A→B ve B→A değerlerinin ortalaması alınır; sonuç simetrik matristir (ekrandan, 00:50:00).
  - Dinamik programlamada hücreler bu tablodaki eşleşme/uyuşmazlık değerleriyle hesaplanır (PAM250'de C:C = 12, S:C = 0).
- Doğrusal ve afin boşluk cezası
  - Şimdiye kadar her boşluğa aynı ceza veren doğrusal ceza kullanıldı.
  - Evrimde bitişik bir kalıntı bloğunun birlikte eklenmesi/silinmesi daha olasıdır: uzunluğu k olan 1 boşluk, uzunluğu 1 olan k boşluktan daha olasıdır (ekrandan, 01:15:00).
  - Afin cezada boşluk açma cezası ($g$) ile uzatma cezası ($r$) ayrıdır; tipik değerler $g = -12$, $r = -4$.
  - Afin cezalı DP'de eşleşme (M), silme (D) ve ekleme (I) olmak üzere üç matris hesaplanır (ekrandan, 01:20:00).
- DP yaklaşımlarının üstünlüğü ve sakıncaları
  - Verilen bir skor şeması için iki dizi arasındaki en iyi hizalamayı garanti eder.
  - Hesap ve bellek yoğundur: en az $O(n^2)$ bellek, $O(n^2)$ ile $O(n^3)$ arası zaman (ekrandan, 01:25:00).
  - Alternatifler: Myers-Miller doğrusal bellek algoritmaları, sınırlı (bounded) DP, Ewan Birney'nin Dynamite paketi (DP kodunu otomatik üretir) (ekrandan, 01:30:00).
- Hizalamanın anlamlılığı (istatistiksel önem)
  - Bariz biçimde benzer olmayan, uzunlukları m ve n olan iki dizi bir hizalama gösteriyorsa bu hizalamanın rastgele oluşma olasılığı değerlendirilir (ekrandan, 01:35:00).
  - Rastgele dizilerin hizalama skorları Gumbel uç değer dağılımına uyar (Gauss gibi simetrik değildir).
  - Beklenen değer: $E = K m n e^{-\lambda S}$; K ve $\lambda$ skor sistemine ve arka plan kalıntı sıklıklarına bağlıdır.
  - Bit skoru: $S' = \dfrac{\lambda S - \ln K}{\ln 2}$, buradan $E = m n 2^{-S'}$; olasılık $P = 1 - e^{-E}$.
  - Matris bit biriminde ise anlamlılık eşiği yaklaşık $\log_2(mn)$ bittir.
- Boşluklu hizalamaların anlamlılığı
  - Aynı istatistik kullanılır, ama $\lambda$ ve K kolay kestirilemez; rastgele dizilerin hizalamalarına bakılarak deneysel kestirimler yapılmıştır (ekrandan, 01:55:00).
- Bayesçi istatistiğe kısa giriş
  - Koşullu olasılık $P(B \mid A)$, marjinal olasılık $P(B)$, ortak olasılık $P(A,B)$.
  - Bayes kuralı: $P(A1,B1) = P(B1)P(A1 \mid B1) = P(A1)P(B1 \mid A1)$ (ekrandan, 02:00:00).
  - Önsel (prior) olasılıklar bilinir; ortak olasılıklar hesaplanarak sonsal (posterior) olasılıklar bulunur.
- İkili hizalama programları
  - needle (global), water (yerel, Smith-Waterman), iki dizinin BLAST ile karşılaştırılması, NCBI'nin web tabanlı araçları ve genomik diziyi protein/mRNA/EST ile hizalayan araçlar. <!-- BELİRSİZ: genomik hizalama araçlarının adları (02:05:50-02:06:08) altyazıda bozuk, kare boş -->
- Çoklu dizi hizalamaya (MSA) giriş
  - Gerçekte çoğu zaman ikiden çok dizi hizalanır; benzer genler türler arasında korunur.
  - Çok sayıda dizinin aynı anda hizalanması, hangi bölgelerin evrimde mutasyona uğradığını, hangi bölge ve domainlerin işlev için kritik olduğunu gösterir; proteinlerin yapı ve işlevi, motifler ve genler arası evrimsel ilişkiler hakkında bilgi verir (ekrandan, 02:15:00).
  - Amaç, üç veya daha çok diziyi en çok benzer karakter aynı sütuna gelecek şekilde hizalamaktır. Eşleşme, ekleme ve silme kombinasyonlarının sayısı büyük olduğu için en iyi (optimal) algoritma pratik değildir; kullanılan yöntemler yaklaşık (ad hoc) yöntemlerdir.
  - Örnek: 8 immünoglobulin dizisinin çoklu hizalaması (ekrandan, 02:20:00).
  - MSA ile filogenetik analiz yakından ilişkilidir; hayat ağacında Bacteria, Archaea ve Eucarya (ekrandan, 02:25:00).
  - Yöntem sınıfları: kesin (DP tabanlı), ilerlemeli (progressive), yinelemeli (iterative) ve istatistiksel model yaklaşımları.

## Hocanın Özellikle Vurguladığı Kısımlar

- En iyi hizalama skor şemasına bağlıdır
  - Basit eşleşme/uyuşmazlık skoru yerine amino asitlerin ve nükleotitlerin biyofiziksel özelliklerini yansıtan şemalar daha anlamlı hizalamalar verir.
- Hangi matris ne zaman?
  - Uzak akraba proteinlerde yüksek PAM, düşük BLOSUM; yakın akraba proteinlerde düşük PAM, yüksek BLOSUM kullanılır.
- DP en iyiyi garanti eder ama pahalıdır
  - Geri izleme (traceback) için en azından sonraki hücreleri belirleyen değerlerin saklanması gerekir. Hızlandırıcı yaklaşımlar kullanılırsa "garanti eder" ifadesi "verebilir" olarak değiştirilmelidir.
- Hizalamanın anlamlı olup olmadığı istatistikle sınanır
  - Bulunan hizalama skoru bit cinsinden anlamlılık eşiğinin üstündeyse hizalama anlamlıdır, altındaysa değildir.
- Çoklu dizi hizalama yöntemleri en iyiyi garanti etmez
  - Tüm MSA yöntemleri ad hoc yöntemlerdir, bulunan hizalama en iyi olmayabilir.

## Kısa Tekrar Notları

- Global: ilk satır/sütun $i \cdot w$, $j \cdot w$; yerel: 0 ile başlat, max içine 0 ekle; örtüşme: 0 ile başlat, global yineleme.
- Geçiş: A ↔ G, T ↔ C (daha yaygın). Çaprazlama: pürin ↔ pirimidin.
- DNA şeması: eşleşme 20, geçiş 10, çaprazlama 5.
- PAM: Dayhoff 1978, %85 özdeş aileler, global hizalama, filogenetik ağaç; PAM1 = %1 değişim; PAM250 = PAM1'in 250. kuvveti.
- BLOSUM: korunmuş bloklar, yerel; BLOSUM62 = %62 özdeşlikle kümeleme; büyük sayı = yakın akrabalık.
- Log-odds: $10 \log_{10}(\text{gözlenen}/\text{beklenen})$, A→B ve B→A ortalaması, simetrik.
- Afin boşluk: açma $g$, uzatma $r$; tipik $g=-12$, $r=-4$; üç matris M, D, I.
- DP: $O(n^2)$ bellek, $O(n^2)$–$O(n^3)$ zaman. Alternatif: Myers-Miller, sınırlı DP, Dynamite.
- $E = K m n e^{-\lambda S}$, $S' = (\lambda S - \ln K)/\ln 2$, $E = mn2^{-S'}$, $P = 1 - e^{-E}$.
- PAM250 skoru bit'e yaklaşık $S/3$ ile çevrilir; eşik $\log_2(mn)$.
- Örnek: skor 73 → 24,33 bit > $\log_2(250 \cdot 250) \approx 16$ bit → anlamlı yerel hizalama.
- Bayes: $P(A,B) = P(B)P(A \mid B)$.
- MSA: kesin, ilerlemeli, yinelemeli, istatistiksel model yöntemleri; pratikte ad hoc.

## Detaylı Açıklamalar

- **Hizalama varyantları.** Ders, önceki derste görülen üç DP varyantının hatırlatılmasıyla başladı. Needleman-Wunsch global hizalamasında ilk satır ve ilk sütun boşluk cezasının katlarıyla doldurulur, her hücre $S_{i,j} = \max[S_{i-1,j-1} + s(a_i,b_j),\ S_{i,j-1} + w,\ S_{i-1,j} + w]$ ile hesaplanır. Smith-Waterman yerel hizalamasında başlangıç 0'dır ve max içine 0 eklenir; böylece hücre en az 0 olur. Örtüşme hizalaması iki yaklaşımın birleşimidir: başlatma yereldeki gibi, yineleme globaldeki gibidir (ekrandan, 00:10:00).
- **Protein skor matrisi örneği.** Slaytta iki protein dizisi (PTHPLASKTQILPEDLASEDLTI ve PTHPLAGERAIGLARLAEEDFGM) ve bir skor matrisinin parçası gösterildi. T:T için 5, T:G için −2 okunur, toplam skor 48 olarak verildi (ekrandan, 00:20:00). Matristeki değerler BLOSUM62 ile aynıdır.
  - Ders sonrası not: Slayttaki matris parçası BLOSUM62 ile aynıdır, ama standart BLOSUM62 ile bu boşluksuz hizalamanın toplamı python ile 46 çıkıyor. Slayttaki 48 büyük olasılıkla farklı bir matris sürümüyle ya da başka bir hesapla bulunmuştur.
- **Neden PAM ve BLOSUM?** Amino asitler küçük, alifatik, aromatik, hidrofobik, hidrofilik, polar, yüklü gibi alt gruplara ayrılır. Aynı gruptaki amino asitler birbirinin yerine daha kolay geçer. Gerçek protein ailelerinde yer değiştirme sıklıkları sayılır, beklenen sıklığa oranlanır ve logaritması alınır. Değer 0 ise çiftin hizalanma sıklığı rastgeleyle aynıdır.
- **PAM'ın kuruluşu.** Margaret Dayhoff'un çalışmasında 71 protein grubunda yaklaşık 1572 kabul edilmiş yer değiştirme sayılmıştır. "Kabul edilmiş" mutasyon, proteinin işlevini (uygunluğunu) olumsuz etkilemeyen mutasyondur. Benzer diziler filogenetik ağaçlara yerleştirilir, değişimler sayılır, amino asitlerin göreli değişebilirliği bulunur ve 20 × 20'lik yer değiştirme matrisi hesaplanır. PAM1'de normalleştirilmiş olasılıklar 10.000 ile çarpılır.
- **Daha iyi DNA şeması.** Birim matriste her uyuşmazlık aynı sayılır. Geçiş mutasyonu çaprazlamadan daha olası olduğu için eşleşmeye 20, geçişe (A:G, T:C) 10, çaprazlamaya 5 verilen bir şema daha anlamlıdır (ekrandan, 00:40:00).
- **Afin boşluk ve DP.** Afin cezada her boşluk bloğu bir kez açma cezası alır, her ek konum için daha küçük uzatma cezası eklenir. DP'de eşleşme matrisi $M_{i,j} = \max\{D_{i-1,j-1}, M_{i-1,j-1}, I_{i-1,j-1}\} + subst(A_i,B_j)$, silme matrisi $D_{i,j} = \max\{D_{i,j-1} - extend,\ M_{i,j-1} - open\}$ ile hesaplanır; ekleme matrisi I de benzer bir formülle bulunur (ekrandan, 01:20:00). Hesaplanacak matris sayısı arttığı için DP karmaşıklaşır.
- **Anlamlılık örneği.** PAM250 ile FWLEVEGNSMTAPTG / FWLDVQGDSMTAPAG hizalaması bulunmuş, skor 73'tür (ekrandan, 01:45:00; python ile PAM250 üzerinden 73 doğrulandı). PAM250 değerleri $10\log_{10}$ biriminde olduğu için bit'e çevirmek için yaklaşık 3'e bölünür: $S' = 73/3 = 24{,}333$ bit. Dizi uzunlukları 250 alınırsa eşik $\log_2(250 \cdot 250) = 16$ bittir. Skor eşiğin üstünde olduğu için hizalama anlamlı bir yerel hizalamadır (ekrandan, 01:50:00). PAM250 için $K = 0{,}09$ ve $\lambda \approx 0{,}229$ ile hesaplanan beklenen değer $E \approx 3{,}1 \times 10^{-4}$ olur. <!-- BELİRSİZ: λ altyazıda "0.29" duyuluyor, 3,1×10⁻⁴ sonucu 0,229 ile tutuyor; slayt karesi yok -->
- **MSA'ya giriş.** Dersin sonunda yeni konu açıldı. Birden çok türde korunmuş genlerin aynı anda hizalanması, evrim sürecinde hangi bölgelerin değiştiğini ve hangilerinin işlev için kritik olduğunu gösterir. Kesin DP çözümü dizi sayısı arttıkça pratik olmaktan çıktığı için yaklaşık yöntemler kullanılır. Yöntemlerin ayrıntısı bir sonraki derse bırakıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
