# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin tarihi 24 Aralık 2020 Perşembe. Ders Zoom üzerinden yapıldı. Kayıt yaklaşık 2 saat sürüyor.
  - İlk 10 dakikada proje soruları cevaplandı. Ders yaklaşık 00:21'de başlıyor.
  - Hoca konuyu İngilizce anlattı. Tahtadaki çizimleri ve PageRank'in matris gösterimini Türkçe açıkladı.
- Önceki dersin özeti: merkezilik (centrality) ve prestij (prestige) metrikleri, sıra prestijinin (rank prestige) matris gösterimi.
- Ortak atıf (co-citation) ve bibliyografik eşleşme (bibliographic coupling) metrikleri.
- Popülerliğe dayalı sıralama (popularity-based ranking): PageRank ve HITS.
- PageRank:
  - Akış denklemi (flow equation) ve basit örnek üzerinde çözüm.
  - Stokastik komşuluk matrisi (stochastic adjacency matrix) ve özvektör sistemi (eigen system).
  - Kuvvet yinelemesi (power iteration) yöntemi.
  - Rastgele yürüyüş (random walk) yorumu ve durağan dağılım (stationary distribution).
  - Çıkmaz sokak (dead end) ve örümcek tuzağı (spider trap) sorunları.
  - Rastgele ışınlanma (random teleport) ile çözüm ve Google matrisi.
- PageRank'in avantajları ve sorgudan bağımsız (query independent) olmasının eleştirisi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Prestij metrikleri giriş bağlantılarıyla (in-link) ilgilenir.
  - Her bağlantının önemi aynı değildir. Bir şirketin genel müdüründen gelen bağlantı, iş arkadaşından gelen bağlantıdan daha değerlidir.
- Web'de arama yaparken iki sorun vardır:
  - Hangi sayfalar güvenilirdir (trustworthy)? Varsayım: güvenilir sayfalar birbirine bağlantı verir. Örneğin Wikipedia'nın spam sayfalara bağlantı vermesi beklenmez.
  - Güvenilir sayfalar arasında sorguya en iyi cevap hangisidir?
- Çok bağlantı alan sayfa popülerdir ve güvenilir kabul edilir. Örnek: stanford.edu çok sayıda bağlantı alır, adı bilinmeyen bir site tek bağlantı alır.
- **Tek bağlantı alan sayfanın PageRank'i yüksek olabilir.** Örnekteki C düğümü yalnız bir bağlantı alıyor. Ama bu bağlantı ağın en önemli düğümünden geliyor. Bu yüzden C'nin skoru 4 bağlantı alan E'ninkinden yüksek.
- Bir düğüm PageRank değerini çıkış bağlantılarına eşit olarak paylaştırır. 3 çıkış bağlantısı olan düğüm her birine değerinin $1/3$'ünü aktarır.
- PageRank denklemi bir özvektör sistemidir. Özdeğer (eigenvalue) 1'dir.
- PageRank'in iki avantajı:
  - Spam'e karşı dayanıklıdır. Yüksek popülerlikteki sayfalar spam değildir.
  - Sorgudan bağımsızdır. Skor yalnız bağlantı yapısından önceden hesaplanır.
- Sorgudan bağımsızlık aynı zamanda bir eleştiridir. Bir sorgu için en otoriter sayfa yeterince bağlantı almadıysa ilk sıralarda çıkmayabilir.
  - HITS bu soruna sorguya bağımlı (query dependent) bir çözüm getirir. Gelecek hafta işlenecek.
- β genellikle 0,8 ile 0,9 arasında seçilir.
- **Proje duyuruları:**
  - Proje konusu değiştirilebilir. Ama başka bir grubun seçtiği ürünle çakışmamalı. Bütün projeler yayınlandı.
  - Sınıflandırma projelerinde en az 3 farklı sınıflandırıcı (classifier) kullanılmalı ve karşılaştırılmalı. Random Forest bir öneri, zorunlu değil.
    - Örnek akış: verinin %70–80'i eğitim (training), kalanı test. Üç sınıflandırıcı eğitilir, test verisi etiketlenir ve doğruluk karşılaştırılır.
  - Konu sürekli değişirse proje yetişmez. Hoca, gönderilen öneri (proposal) belgesini bitmiş projeyle karşılaştıracağını söyledi.
  - Sunumda slayt gerekmiyor. Çalışan bir kullanıcı arayüzü üzerinden demo isteniyor. Editörde ya da Jupyter'de kod çalıştırarak yapılan demo kabul edilmiyor.
  - Model eğitimi uzun sürüyorsa: küçük bir veri örneği üzerinde arayüzden eğitim gösterilir. Etiketleme ise daha önce büyük veriyle eğitilmiş modelle yapılır. Eğitim bulut (ör. Colab) üzerinde de gösterilebilir.
  - Ayrı rapor gerekmiyor. Hoca kodlara, demoya, demonun öneriyle uyumuna ve harcanan emeğe bakacak.
  - Bütün proje ziplenip Google Drive ya da Dropbox'a yüklenecek, indirilebilir bağlantı gönderilecek. E-posta eki istenmiyor.
  - Asistan projeyi kimseye danışmadan kendi bilgisayarında çalıştırabilmeli. Bunu temiz bir bilgisayarda deneyin.
  - Projeye adım adım çalıştırma talimatı içeren bir readme dosyası eklenecek.
  - Sunumlar dönemin son haftasında, ders günü olan Perşembe saat 9–12 arasında. Yetmezse öğleden sonra devam edilecek.
- Bağlantı analizi bölümü (7. bölüm) neredeyse bitti. Yalnız HITS kaldı. Sonraki haftalarda web kullanım madenciliği (web usage mining) ve fikir madenciliği (opinion mining) işlenecek.

## Kısa Tekrar Notları

- Sıra prestiji: $i$'nin prestiji, ona bağlantı veren düğümlerin prestijlerinin toplamıdır.

$$P_R(i)=\sum_{j=1}^{n}A_{ji}\,P_R(j)\qquad\Longrightarrow\qquad P=A^{T}P$$

- Ortak atıf: $i$ ve $j$'ye aynı anda atıf yapan makale sayısı. Atıf matrisinde $i$ ve $j$ sütunları satır satır çarpılıp toplanır.

$$C_{ij}=\sum_{k=1}^{n}L_{ki}\,L_{kj}$$

- Bibliyografik eşleşme: $i$ ve $j$'nin ortak atıf yaptığı makale sayısı. Atıf matrisinde $i$ ve $j$ satırları eleman eleman çarpılıp toplanır.

$$B_{ij}=\sum_{k=1}^{n}L_{ik}\,L_{jk}$$

  - Atıf matrisinde (citation matrix) satır atıf yapan, sütun atıf alan makaledir. $L_{ij}=1$ ise $i$, $j$'ye atıf yapmıştır.
- PageRank akış denklemi ($d_i$: $i$'nin çıkış derecesi):

$$r_j=\sum_{i\to j}\frac{r_i}{d_i}$$

- Matris gösterimi: $r=M\cdot r$.
  - $M_{ji}=1/d_i$, eğer $i\to j$ bağlantısı varsa. Yoksa 0.
  - $M$'de sütun bağlantıyı vereni, satır alanı gösterir. Her sütunun toplamı 1'dir (sütun stokastik).
  - $r$, özdeğeri 1 olan özvektördür.
- Kuvvet yinelemesi:
  - Başlangıç: $r^{(0)}=[1/N,\dots,1/N]^T$.
  - Yineleme: $r^{(t+1)}=M\,r^{(t)}$.
  - Durma: $\lVert r^{(t+1)}-r^{(t)}\rVert<\varepsilon$.
- Rastgele yürüyüş: $r_j$, rastgele bir kullanıcının (random surfer) herhangi bir anda $j$ sayfasında bulunma olasılığıdır. Yakınsayan vektör durağan dağılımdır.
- Google matrisi:

$$A=\beta M+(1-\beta)\frac{1}{N}\mathbf{1}\mathbf{1}^{T},\qquad r=A\,r$$

## Detaylı Açıklamalar

### Ortak atıf ve bibliyografik eşleşme neden önemli?

- İki belgenin benzerliği yalnız içerikten (TF-IDF) ölçülmez. Kaynakçalar üzerinden bağlantı analizi de yapılabilir.
- İki makale aynı makalelere atıf yapıyorsa bibliyografik eşleşme değeri yüksektir.
- İki makale sürekli birlikte atıf alıyorsa ortak atıf değeri yüksektir.
- Hoca, intihal (plagiarism) kontrol yazılımlarının yalnız içeriğe değil, kaynaklara da baktığını söyledi.

### Basit PageRank örneği (y, a, m)

- Bağlantılar: y→y, y→a, a→y, a→m, m→a.
- Denklemler:

$$r_y=\frac{r_y}{2}+\frac{r_a}{2},\qquad r_a=\frac{r_y}{2}+r_m,\qquad r_m=\frac{r_a}{2}$$

- Bu üç denklemin tek bir çözümü yoktur. Dördüncü koşul eklenir: $r_y+r_a+r_m=1$.
- Çözüm: $r_y=\frac{2}{5}$, $r_a=\frac{2}{5}$, $r_m=\frac{1}{5}$. Python'da kuvvet yinelemesiyle de aynı değerler (0,4; 0,4; 0,2) bulundu.
- Matris gösterimi:

$$M=\begin{pmatrix}1/2&1/2&0\\1/2&0&1\\0&1/2&0\end{pmatrix}$$

- Büyük web grafında denklemleri tek tek yazmak mümkün değildir. Bu yüzden matris gösterimi ve kuvvet yinelemesi kullanılır.

### Matrisle tek düğümün skoru (tahtadaki açıklama)

- $M$'nin $j$. satırı alınır, $r$ sütun vektörüyle eleman eleman çarpılıp toplanır.
- Satırdaki sıfır olmayan elemanlar $j$'ye bağlantı veren düğümlerdir. Değerleri $1/d_i$'dir.
- Sonuç, $j$'ye bağlantı veren düğümlerin oransal PageRank'lerinin toplamıdır. Bu, akış denkleminin aynısıdır.

### Rastgele yürüyüş yorumu

- Rastgele kullanıcının tarayıcısında geri tuşu yoktur. Yalnız sayfadaki bağlantılara tıklayarak ilerler.
- $t$ anında $i$ sayfasındaysa ve $i$'nin $d_i$ çıkış bağlantısı varsa, $t+1$ anında $j$'de olma olasılığı $1/d_i$'dir.
- $j$'de olma olasılığı, $j$'ye bağlantı veren her $i$ için ($i$'de bulunma olasılığı × $1/d_i$) toplamıdır. Bu, PageRank formülünün aynısıdır.
- $p^{(t+1)}=M\,p^{(t)}$ yinelendiğinde $p^{(t+1)}=p^{(t)}$ olursa bu vektöre durağan dağılım denir.
- Markov zinciri (Markov chain) kuramına göre graf bazı koşulları sağlıyorsa durağan dağılım tektir (unique).

### Web grafındaki iki sorun

- **İki düğümlü döngü (a→b, b→a):** Başlangıç $(1,0)$ ise yineleme $(0,1)$, $(1,0)$, $(0,1)$ diye gider. Hiç yakınsamaz.
- **Çıkmaz sokak (a→b, b'nin çıkışı yok):** $(1,0)$, $(0,1)$, $(0,0)$. Yakınsar ama bütün skorlar 0 olur. Sıralama yapılamaz.
  - Matriste çıkmaz sokak düğümünün sütunu tamamen 0'dır.
- **Örümcek tuzağı (spider trap):** Örnekte m yalnız kendine bağlantı veriyor. m'ye gelen kullanıcı bir daha çıkamaz.
  - Yineleme yakınsar ama bütün skor m'de toplanır. İstenen bir sıralama değildir.

### Çözüm: rastgele ışınlanma

- Kullanıcı her adımda $\beta$ olasılıkla bir bağlantıyı izler. $1-\beta$ olasılıkla rastgele bir sayfaya atlar.
- Çıkmaz sokak için: sıfır sütundaki her elemanın yerine $1/N$ yazılır. Bu, o düğümden kendisi dahil bütün düğümlere sanal bağlantı koymak demektir.
  - Matrisle: $M+\frac{1}{N}\mathbf{1}\,a^{T}$. Burada $a_i=1$, eğer $i$'nin çıkış bağlantısı yoksa. Yoksa $a_i=0$.
- Örümcek tuzağı için: akış denklemi şöyle olur.

$$r_j=\sum_{i\to j}\beta\frac{r_i}{d_i}+(1-\beta)\frac{1}{N}$$

- Elde edilen $A$ matrisi stokastik, indirgenemez (irreducible) ve periyodik olmayan (aperiodic) bir matristir. Bu yüzden kuvvet yinelemesi tek bir durağan dağılıma yakınsar.
- Bu formül Brin ve Page'in 1998'de yayımlanan PageRank makalesindeki formüldür.

### Işınlanmalı örnek (β = 0,8)

- Slayt: Leskovec, Rajaraman, Ullman, *Mining of Massive Datasets* (Stanford). Bağlantılar: y→y, y→a, a→y, a→m, m→m.

$$A=0{,}8\begin{pmatrix}1/2&1/2&0\\1/2&0&0\\0&1/2&1\end{pmatrix}+0{,}2\begin{pmatrix}1/3&1/3&1/3\\1/3&1/3&1/3\\1/3&1/3&1/3\end{pmatrix}=\begin{pmatrix}7/15&7/15&1/15\\7/15&1/15&1/15\\1/15&7/15&13/15\end{pmatrix}$$

| Yineleme | $r_y$ | $r_a$ | $r_m$ |
|---|---|---|---|
| 0 | 1/3 | 1/3 | 1/3 |
| 1 | 0,33 | 0,20 | 0,47 |
| 2 | 0,28 | 0,20 | 0,52 |
| 3 | 0,26 | 0,18 | 0,56 |
| ∞ | 7/33 | 5/33 | 21/33 |

- Python ile 300 yinelemeyle sonuç doğrulandı: $(0{,}212;\ 0{,}152;\ 0{,}636)$. Bu $7/33$, $5/33$, $21/33$ ile aynıdır.
- Slaytta 1. yinelemedeki $r_m$ 0,46 yazıyor. Kesin değer $7/15\approx0{,}467$'dir. Slayt aşağı yuvarlamış.

### Ders sonrası notlar

- **Stokastik matris tanımı:** Hoca önce "her satırı topladığınızda 1 çıkacak" dedi, sonra sütun dedi. PageRank'in $M$ matrisinde sütunlar bağlantıyı veren düğümlerdir. Her sütunun toplamı 1'dir (sütun stokastik, column stochastic).
- **İki düğümlü döngü örümcek tuzağı değildir:** Hoca a↔b örneğini örümcek tuzağı olarak anlattı. Kaynak slaytta bu örnek "Yakınsıyor mu?" sorusu için verilir. Asıl sorun periyodikliktir (periodicity). Örümcek tuzağı, çıkış bağlantılarının hepsi grubun içinde kalan düğüm grubudur (m→m örneği).
- **Koşulların eşleştirilmesi:** Hoca "periyodik olmayan = örümcek tuzağı yok, indirgenemez = çıkmaz sokak yok" dedi. Daha doğru eşleştirme:
  - Çıkmaz sokaklar matrisin stokastik olmasını bozar. Çözüm: sıfır sütunları $1/N$ ile doldurmak.
  - Örümcek tuzakları matrisi indirgenebilir (reducible) yapar. Çözüm: ışınlanma.
  - a↔b gibi döngüler periyodikliğe yol açar. Işınlanma bunu da giderir.
- **Kaynak adı:** Altyazıda "Samford" ve "Stanford.edu" geçiyor. Doğrusu Stanford Üniversitesi'dir.
- **Bozuk altyazı:** Bibliyografik eşleşmenin tahtada anlatıldığı yaklaşık 00:36–00:38 arası anlamsız İngilizce cümlelere dönüşmüş. Bu kısım özette yalnız standart formülle verildi.
- **Eksik kayıt:** Hoca prestij metriklerini (derece prestiji, yakınlık prestiji, sıra prestiji) ve ortak atıfın başlangıcını "geçen hafta" anlattığını söylüyor. Ders 10'un kaydı merkezilik metrikleriyle bitiyor. Prestij metriklerinin anlatıldığı ders bu şubenin kayıtlarında yok.
  - Kitaptaki tanımlar: derece prestiji $P_D(i)=\frac{d_I(i)}{n-1}$ (giriş derecesi). Yakınlık prestiji, $i$'ye ulaşabilen düğümlerin oranının, bu düğümlerin $i$'ye ortalama uzaklığına bölümüdür.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
