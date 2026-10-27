# Ders 8 Çalışma Özeti

## Genel Konular

- Vize ve dönem projesi teklifi duyuruları.
- Büyük veri türleri: yüksek boyutlu veri, graf verisi, sonsuz (akış) veri.
- Graf verisi örnekleri: sosyal ağlar, atıf ağları, internet ve web (World Wide Web).
- Web grafı: düğümler web sayfaları, kenarlar köprüler (hyperlink). Yönlü graf.
- Web'de bilgiye erişim: dizin (directory) gezme ve web araması (web search).
- Web aramasının iki zorluğu: kime güvenilecek (spam sayfalar) ve sorguya en iyi cevap hangisi.
- Bağlantı analizi (link analysis) ve popülerlik tabanlı sıralama. PageRank ve HITS.
- PageRank akış formülasyonu (flow formulation) ve denklem sistemi.
- Matris gösterimi: stokastik komşuluk matrisi (stochastic adjacency matrix).
- Kuvvet yinelemesi yöntemi (power iteration method), özvektör (eigenvector).
- Rastgele gezgin (random surfer) yorumu, durağan dağılım (stationary distribution), Markov zinciri teoremi.
- İki sorun: örümcek tuzağı (spider trap) ve çıkmaz uç (dead end).
- Çözüm: ışınlanma (teleport), $\beta$ olasılığı ve Google matrisi.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Vize:** 28 Nisan Cuma öğleden sonra. Ders sonunda kesin tarihin bölüm sitesinde ilan edildiği söylendi.
- **Vize biçimi:** Online. Büyük olasılıkla çoktan seçmeli. Doğru/yanlış, kutucuk işaretleme ve boşluk doldurma soruları da olabilir. Açık uçlu soru yok.
- **Vize konuları:** 1, 2, 3 ve 4. bölümler, bağlantı analizi bölümü ve kümeleme bölümü (7. bölüm).
- **Proje teklifi son tarihi:** 2 Mayıs Salı, gün sonuna kadar. Uzatma yok.
- **Teklif, proje belgesinde yazan e-posta adresine gönderilecek.** Hocanın okul e-postasına gönderilmeyecek. Belge ders sitesinde.
- **Bağlantı = oy.** Bir sayfa ne kadar çok gelen bağlantı (inlink) alıyorsa o kadar önemlidir.
- **Bütün gelen bağlantılar eşit değildir.** Önemli bir sayfadan gelen tek bağlantı, önemsiz sayfalardan gelen çok bağlantıdan daha değerli olabilir. Örnek: şirket CEO'sundan alınan referans mektubu.
- Küçük graflarda denklemler Gauss eliminasyonuyla çözülebilir. Web ölçeğinde bu imkânsızdır, bu yüzden matris gösterimi ve kuvvet yinelemesi kullanılır.
- Kuvvet yinelemesi, Markov zinciri teoremi sağlanırsa başlangıç vektöründen bağımsız olarak tek bir çözüme yakınsar.
- Örümcek tuzağı **denklem güncellenerek** (teleport terimi eklenerek) çözülür. Çıkmaz uç **web grafı (matris) güncellenerek** çözülür.

## Kısa Tekrar Notları

- **Proje teklifinde olması gerekenler:**
  - Tek başına mı, ortakla mı yapılacağı.
  - Kullanılacak veri kümesi, bağlantısı ve açıklaması.
  - MapReduce programlama modeliyle gerçeklenecek istatistik fonksiyonlarının listesi.
  - Çatı: Spark mı, Hadoop mu.
  - Programlama dili: Python mı, Java mı.
  - Mayıs ayının dört haftası için haftalık iş planı.
- **PageRank akış denklemi:** $r_j = \sum_{i \to j} \frac{r_i}{d_i}$. Burada $d_i$, $i$ düğümünün giden bağlantı (outlink) sayısıdır.
- **Stokastik komşuluk matrisi $M$:** $i \to j$ bağlantısı varsa $M_{ji} = 1/d_i$, yoksa 0. Her sütunun toplamı 1'dir.
- **Matris biçimi:** $r = M \cdot r$. Bu bir özdeğer sistemidir (eigensystem). $r$ özvektördür.
- **Kuvvet yinelemesi:**
  - Başlangıç: her düğüme $1/N$.
  - Her adımda $r^{(t+1)} = M \cdot r^{(t)}$.
  - $\lVert r^{(t+1)} - r^{(t)} \rVert < \varepsilon$ olunca dur.
- **Rastgele gezgin:** $p(t+1) = M \cdot p(t)$. Yakınsadığında $p = M p$, yani durağan dağılım.
- **Markov zinciri teoremi koşulları:** matris stokastik, indirgenemez (irreducible) ve periyodik olmayan (aperiodic) olmalı.
- **Google formülü:** $r_j = \sum_{i \to j} \beta \frac{r_i}{d_i} + (1-\beta)\frac{1}{N}$.
- **$\beta$ tipik değeri:** 0,8 veya 0,9. Işınlanma olasılığı $1-\beta$ = 0,2 veya 0,1.
- **Google matrisi:** $A = \beta M + (1-\beta)\left[\frac{1}{N}\right]_{N \times N}$, sonra $r = A \cdot r$.

## Detaylı Açıklamalar

### Büyük veri türleri ve graf verisi

- Önceki derslerde yüksek boyutlu veri (yerelliğe duyarlı karma (LSH), kümeleme) ve sonsuz veri (veri akışları) işlendi.
- Bu derste graf verisi işleniyor: düğümler (node, vertex) ve aralarındaki kenarlar (edge).
- Örnekler:
  - Facebook sosyal ağ grafı.
  - Blog verisinin görselleştirmesi.
  - Atıf ağı: her makale veya kitap bir düğüm, kaynakçadaki her atıf bir kenar. Renkler konuları gösterir.
  - İnternet: sunucular ve aralarındaki ağ bağlantıları.
- **Web ile internet farkı:** İnternet bilgisayar ağı altyapısıdır. Web ise bunun bir üst katmanıdır: web sayfaları ve aralarındaki köprüler.

### Web grafı

- Her web sayfası bir düğümdür.
- Köprü (hyperlink): metne iliştirilmiş, URL'si görünmeyen bağlantı. Tıklanınca tarayıcı başka sayfaya geçer.
- Köprüler kenarlardır. Bir sayfadan diğerine işaret ettikleri için graf **yönlüdür**.

### Web'de bilgiye erişim

- **Dizin gezme:** Telefon rehberi gibi kategorilere ayrılmış dizinler. Örnek: Yahoo directory, Google directory, Open directory.
- **Web araması:** Anahtar kelime girilir, arama motoru eşleşen belgeleri bulur.
- Kullanıcı genelde yalnız ilk 10 sonuca bakar. Bu yüzden en ilgili sonuçlar ilk 10'da olmalı.
- **Zorluk 1, güven:** Bazı sayfalar ilk 10'a girmek için ilgisiz anahtar kelimeler ekler. Bazıları yanlış bilgi içerir. Bunlar spam sayfalardır ve elenmelidir.
- **Zorluk 2, en iyi cevap:** Anahtar kelime milyonlarca sayfada geçebilir. Hangisinin en ilgili olduğu bulunmalıdır.
- Google'ın popülerlik sıralaması iki sorunu birlikte çözer.

### Bağlantı analizi yaklaşımları

- Sıralama algoritmaları: PageRank ve HITS. Konuya özgü PageRank (topic-specific PageRank). Spam tespiti.
- Bu derste yalnız PageRank işleniyor.

### PageRank fikri

- **Bağlantılar oy gibidir.** Birbirini tanımayan pek çok sayfa aynı sayfaya bağlantı veriyorsa o sayfa güvenilirdir. İnsan yalnız doğru bilgi içerdiğini düşündüğü sayfaya bağlantı verir.
- Örnek: stanford.edu sayfası çok sayıda gelen bağlantı alır. İsimsiz bir sayfa tek bağlantı alır. İlki daha önemlidir.
- **Gelen bağlantıların ağırlığı farklıdır.** Slayttaki örnekte düğüm boyutu PageRank puanıyla orantılı çizilmiş:
  - Çok gelen bağlantı alan mavi düğüm en büyük puana sahip.
  - Sarı düğüm yalnız bir bağlantı alıyor. Ama bu bağlantı en prestijli düğümden geliyor, bu yüzden puanı yüksek.

### Akış formülasyonu

- Her düğüm puanını giden bağlantılarına eşit böler.
- Örnek: $i$ düğümünün 3, $k$ düğümünün 4 giden bağlantısı var. İkisi de $j$'ye bağlanıyor.
  - $r_j = \frac{r_i}{3} + \frac{r_k}{4}$.
  - $j$'nin 3 giden bağlantısı varsa her biri $r_j/3$ taşır.
- Genel formül: $r_j = \sum_{i \to j} \frac{r_i}{d_i}$.
- **Üç düğümlü örnek (y, a, m):**
  - y kendine ve a'ya bağlanır. a, y'ye ve m'ye bağlanır. m yalnız a'ya bağlanır.
  - $r_y = \frac{r_y}{2} + \frac{r_a}{2}$
  - $r_a = \frac{r_y}{2} + r_m$
  - $r_m = \frac{r_a}{2}$
  - Üç bilinmeyen, üç denklem var ama tek çözüm yok. Dördüncü denklem eklenir: $r_y + r_a + r_m = 1$.
  - Çözüm: $r_y = r_a = \frac{2}{5}$, $r_m = \frac{1}{5}$. y ve a eşit ve en yüksek, m en düşük.

### Matris gösterimi

- $M$, $N \times N$ boyutlu bir matristir. $N$ graftaki düğüm sayısıdır.
- Sütunlar bağlantı veren sayfalar, satırlar bağlantı alan sayfalardır.
- Bağlantı varsa 1 yerine $1/d_i$ yazılır. Böylece her sütunun toplamı 1 olur. Bu yüzden matrise **stokastik** denir.
- $r$, $N \times 1$ sütun vektörüdür. $r_j$, $M$'nin $j$. satırı ile $r$'nin çarpımıdır.
- y, a, m örneği için:

```
        y    a    m
  y  [ 1/2  1/2   0 ]
  a  [ 1/2   0    1 ]
  m  [  0   1/2   0 ]
```

### Kuvvet yinelemesi

- Başlangıçta her düğüme $1/N$ verilir. Örnekte her düğüm $1/3$ ile başlar.
- $M$ ile çarpılır, sonuç yeniden $M$ ile çarpılır. Bu döngü sürer.
- Ardışık iki vektör arasındaki fark ihmal edilebilir ($\varepsilon$) olduğunda durulur.
- Sonuçta y ve a en yüksek, m en düşük puanı alır.
- $r = M r$ denklemine özdeğer sistemi, çözüm vektörüne özvektör denir.

### Rastgele gezgin yorumu

- Tarayıcıda URL kutusu ve geri tuşu yoksa gezgin yalnız bağlantılara tıklayarak ilerleyebilir.
- Ana sayfada 4 bağlantı varsa, örneğin müfredat (syllabus) sayfasına gitme olasılığı $1/4$'tür.
- $t$ anında $i_1, i_2, i_3$ sayfalarından birinde olan gezginin $t+1$ anında $j$'de olma olasılığı: $p_j(t+1) = \sum_{i \to j} \frac{p_i(t)}{d_i}$.
- Bu, PageRank akış denkleminin aynısıdır. Sıralama vektörü artık olasılık dağılımı vektörü olarak görülür.
- Yakınsamada $p(t+1) = p(t)$, yani $p = M p$. Buna **durağan dağılım** denir.
- **Rastgele yürüyüş (Markov zinciri) teoremi:** Graf belirli koşulları sağlarsa durağan dağılım tektir. Başlangıç dağılımı ne olursa olsun bu dağılıma ulaşılır.

### Örümcek tuzağı ve çıkmaz uç

- **Örümcek tuzağı:** Gezgin bir düğüm grubuna girer ve dışarı çıkamaz. Örnekte m yalnız kendine bağlanıyor. a'dan m'ye gelen gezgin m'de takılır.
  - Kuvvet yinelemesinde tüm puan tuzaktaki düğümlerde toplanır. Diğer düğümlerin puanı sıfıra gider. Sonuç anlamsız olur.
  - Slayttaki bir örnekte iki adımda aynı düğüme dönülüyor. Vektör her adımda değişip salınıyor, yakınsamıyor.
- **Çıkmaz uç:** Hiç giden bağlantısı olmayan düğüm. Gezgin oradan hiçbir yere gidemez.
  - Matriste o düğümün sütunu tamamen 0 olur. Matris artık stokastik değildir.
  - Yinelemede puan "sızar" ve tüm değerler sıfıra gider.

### Çözüm: ışınlanma

- Tarayıcıya URL kutusu eklenir. Gezgin her an istediği sayfanın adresini yazıp oraya geçebilir.
- Her adımda:
  - $\beta$ olasılıkla rastgele bir bağlantı izlenir.
  - $1-\beta$ olasılıkla rastgele bir sayfaya ışınlanılır.
- **Örümcek tuzağı için:** Denklem güncellenir: $r_j = \sum_{i \to j} \beta \frac{r_i}{d_i} + (1-\beta)\frac{1}{N}$.
- **Çıkmaz uç için:** Matris güncellenir. Çıkmaz uç düğümünün sütununa her satırda $1/N$ yazılır. Gezgin oradan her sayfaya, kendisi dahil, eşit olasılıkla ışınlanır.
  - Bu, $M + \frac{1}{N} e\, a^T$ toplamıyla yapılır. $e$ tüm elemanları 1 olan vektördür. $a_i = 1$ yalnız $i$ çıkmaz uç ise.
  - Bu çarpım, yalnız çıkmaz uç sütunu $1/N$ olan, diğer sütunları 0 olan bir $N \times N$ matris verir.
- **Soru: Neden 1/2 değil de 1/3?** Gezgin kendi sayfasına da ışınlanabilir. URL kutusuna aynı adresi yeniden yazmak buna örnektir. Bu yüzden payda tüm düğüm sayısıdır (örnekte 3).
- **Google matrisi:** $A = \beta M + (1-\beta)\frac{1}{N}$. Bu matris stokastik, indirgenemez ve periyodik olmayan bir matristir. Kuvvet yinelemesi tek ve anlamlı bir çözüme yakınsar.
- Slayttaki örnekte $\beta = 0{,}8$ alınıyor. Altyazının bu kısmı bozuk olduğu için sayısal ara adımlar okunamıyor.

### Ders sonrası notlar

- Hoca "HITS algoritmasını Yahoo arama motoru kullanıyor" dedi. HITS, Jon Kleinberg'in algoritmasıdır. Daha çok Ask.com'un öncülü Teoma ile ilişkilendirilir. Sınavda bu eşleştirmeye güvenmeyin.
- Hoca örümcek tuzağını "iki adım sonra hep aynı düğüme dönmek" diye tanımladı. Kitaptaki tanım daha geneldir: dışarıya giden bağlantısı olmayan düğüm grubu. Tek düğümlü öz-döngü de bir örümcek tuzağıdır.
- Hoca bir yerde "indirgenemez = çıkmaz uç yok, periyodik olmayan = örümcek tuzağı yok" eşleştirmesini yaptı. Kitapta teleport iki sorunu birlikte çözer. Bu eşleştirmeyi yaklaşık bir sezgi olarak görün.
- Hoca "3 denklem, 3 bilinmeyen var, tek çözüm yok" dedi. Bunun nedeni denklemlerin bağımlı ve homojen olmasıdır. $r = 0$ ve onun her katı da çözümdür. Toplamın 1 olması koşulu çözümü tekleştirir.
- Altyazıda "Patriot", "patron", "Payt-Rank" diye geçen terimler PageRank'tir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
