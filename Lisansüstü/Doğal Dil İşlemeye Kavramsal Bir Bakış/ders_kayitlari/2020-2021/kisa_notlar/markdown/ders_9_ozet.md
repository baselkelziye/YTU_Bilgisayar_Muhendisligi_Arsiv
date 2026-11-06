# Ders 9 Çalışma Özeti

## Genel Konular

- Vize, seminer ve dönemin geri kalanı hakkında duyurular.
- Önceki dersin kısa tekrarı: Boole, genişletilmiş Boole ve bulanık modeller.
- Gizli anlamsal indeksleme (latent semantic indexing, LSI) / gizli anlamsal analiz (latent semantic analysis, LSA):
  - Amaç, ön işlem ve terim ağırlıklandırma: yerel ağırlık (local weighting), global ağırlık (global weighting).
  - Tekil değer ayrışımı (singular value decomposition, SVD): 2×2 örnek.
  - Rank (k) seçimi.
  - Üç belgelik LSI örneği ("gold silver truck" sorgusu).
- Arama motorları: web katalogları, Google mimarisi, PageRank, akıllı bir arama motorunda olması gerekenler.
- Performans ölçütleri: karışıklık matrisi (confusion matrix), duyarlılık (sensitivity), özgüllük (specificity), kesinlik (precision), anma (recall), F-ölçüsü (F-measure).
- Bilgi çıkarımı (information extraction, IE):
  - IR, IE ve soru cevaplama (question answering) ilişkisi.
  - Yapılandırılmış, yarı yapılandırılmış ve yapılandırılmamış belgeler.
  - Düzenli ifadeler (regular expression), NLP katkısı, adlandırılmış varlık tanıma (named entity recognition, NER).
  - Güvenilir sayfa belirleme, alışveriş robotları, şablon tabanlı ilişki çıkarımı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Vize 17 Aralık 2020'de, test usulü:
  - Bazı sorularda kağıtta çözüm yapıp sonucu şıklarda aramak gerekecek.
  - Önceki sorulara geri dönülebilecek. Hoca, geri dönüşü engelleyen sınav ayarını doğru bulmuyor.
  - Sorular Türkçe olacak. Hoca sınav boyunca sistemin başında olacak; anlaşılmayan yer chat'ten sorulabilir.
  - Vizeden sonra duruma göre yaklaşık bir saat ders yapılabilir.
- Vizeden sonra seminerler başlıyor. Seminerler arasında zaman kalırsa hoca 15-20 dakikalık konu anlatabilir.
- Kalan konular: metin sınıflandırma (text classification), bilgi çıkarımı ve kısaca soru cevaplama sistemleri. Hoca bazı konuları "acil ya da önemli değil" diye vermiyor.
- Hocanın sınav beklentisi: not değil, öğrencinin "ihtiyacım olduğunda bunu görmüştüm" diyebilmesi. "Herkes kendisinden sorumludur."
- LSI, terimlerin yalnızca geçip geçmediğine değil anlamsal ilişkilerine de bakar. Ortak kelime olmasa bile benzer belgeleri bulabilir.
- Tıpta en tehlikeli hata yanlış negatiftir (false negative). Hasta birine "hasta değilsin" demek ölümcül sonuç doğurabilir.
- Kesinlik ve anma tek başına yanıltıcıdır. İkisinin harmonik ortalaması olan F-ölçüsü kullanılır.
- Bilgi çıkarımında sıra:
  - Önce doğru (güvenilir) sayfalarda arama yapıldığından emin ol.
  - Yapılabiliyorsa düzenli ifade kullan.
  - Yetmezse NLP'den yardım al: sözcük türleri, NER, sözdizimsel çözümleme.
  - Şablonlar oluştur.
- IR, IE ve soru cevaplama iç içedir. IR iyi çalışırsa IE iyi çalışır, IE iyi çalışırsa soru cevaplama iyi çalışır.
- Türkçe NLP kaynakları için Starlang ve Loodos firmalarına bakın.
- Slaytlar hocanın AVESİS sayfasında "2020" olarak yüklü. Sayfaya AVESİS'te "Banu Diri" aratılarak ulaşılır.

## Kısa Tekrar Notları

- LSI/LSA adımları:
  - Ön işlem: noktalama ve büyük harfleri kaldır, durak kelimeleri (stop words) at, kök bul (stemming).
  - Terim-belge matrisi oluştur ve ağırlıklandır.
  - SVD uygula.
  - Rank $k$ ile boyut indirge.
  - Belge ve sorgu vektörlerinin kosinüs benzerliğini hesapla ve sırala.
- Terim-belge matrisi çok seyrektir (sparse).
- Ağırlık: $a_{ij} = L_{ij} \cdot G_i \cdot N_j$. $L$ yerel ağırlık, $G$ global ağırlık, $N$ normalizasyon faktörü.
- Yerel ağırlık: belgede çok geçen kelime daha anlamlıdır.
- Global ağırlık: derlemde seyrek geçen kelime daha ayırt edicidir. IDF'ye karşılık gelir.
- SVD: $A = U S V^T$. Tekil değerler, $A^T A$'nın özdeğerlerinin (eigenvalue) karekökleridir.
- Rank seçimi: ilk $r$ tekil değerin toplamı / tüm tekil değerlerin toplamı istenen eşiği geçince dur.
- Sorgu vektörü: $q_k = q^T U_k S_k^{-1}$.
- LSA'da negatif değer: kelime ile belge anlamca birbirinden çok uzaktır. 0 nötrdür.
- LSA kullanım alanları: bilgi erişimi, eş anlamlılık (synonymy), çok anlamlılık (polysemy), arşivleme, belge sınıflandırma, özetleme, filtreleme.
- Duyarlılık = anma = $\frac{TP}{TP+FN}$. Özgüllük = $\frac{TN}{TN+FP}$.
- Kesinlik = $\frac{|\text{ilgili} \cap \text{getirilen}|}{|\text{getirilen}|}$. Anma = $\frac{|\text{ilgili} \cap \text{getirilen}|}{|\text{ilgili}|}$.
- $F = \frac{2PR}{P+R}$. 1'e ne kadar yakınsa sistem o kadar başarılı.
- Çok sınıflı problemde her sınıf için kesinlik ve anma hesaplanıp ortalaması alınır.
- IE'de kesinlik $= C/E$, anma $= C/N$.
- NER'de temel varlıklar: kişi (person), yer (location), kurum (organization). Ek olarak para birimi, tarih, zaman.
- NER yöntemleri: kural tabanlı, şablon tabanlı, koşullu rastgele alanlar (conditional random fields, CRF), derin öğrenme.

## Detaylı Açıklamalar

### Duyurular ve sınav soruları

- Hoca proje ve seminer durumunu sordu. Bir öğrenci makaleyi okuduğunu ama raporu henüz yazmadığını söyledi.
- Bir öğrenci, başka bir dersin sınavında önceki sorulara geri dönülemediğini, talimatı sınav açılınca telaşla okumadıklarını anlattı. Hoca böyle bir ayar kullanmayacağını söyledi. Ayrıca talimatların boşuna yazılmadığını, mühendislerin yazılanı okuması gerektiğini ekledi.

### Önceki dersin tekrarı

- Boole modeli belgeleri sıralamadan getiriyordu.
- Genişletilmiş Boole modeli benzerlik formülüyle sıralama yapıyordu. OR'da ağırlıkların p. kuvvetlerinin ortalamasının kökü, AND'de $1-w$ değerleriyle aynı işlem ve sonucun 1'den farkı.
- Bulanık modelde üyelik dereceleri vardı. MMM modeli min ve max değerlerini deneysel katsayılarla çarpıyordu.
- Bu modeller yalnızca kelimenin belgede geçip geçmediğine bakıyordu. Anlamsal bilgi katmak için cebirsel modeller geliştirildi. En önemlisi LSI.

### LSI'nin amacı

- Her belge ve sorgu için bir vektör oluşturulur. Benzerlik skaler bir değer olarak ölçülür ve belgeler en benzerden en az benzere sıralanır.
- Önceki yöntemler kelime-belge arasındaki anlamsal ilişkiyi kullanmıyordu. LSI bunu kullanmaya çalışır.
- Örnekler:
  - Bir belgede "Atatürk" geçiyor ama "Türkiye" geçmiyor. Diğerinde tersi. LSI ikisi arasındaki ilişkiyi bulur. "Türkiye" aranınca Atatürk ile ilgili sayfalar da gelebilir.
  - Associated Press haber veritabanında "Saddam Hüseyin" araması: Körfez Savaşı, BM yaptırımları ve petrol ambargosu makalelerinin yanında Saddam Hüseyin adı geçmeyen ama Irak hakkında olan makaleler de döner.
  - "Tiger Woods" araması: adının geçmediği ama büyük golf turnuvaları hakkında olan makaleler de döner. Sistem "bu kişi golfle ilgileniyor" çıkarımını yapar.
- Sonuç kümesi, aranan terimle ilişkili başka terimler de düşünülerek genişler.

### LSI ön işlemi ve ağırlıklandırma

- Ön işlem:
  - Başlıklar ve noktalama işaretleri atılır. Tüm harfler küçültülür.
  - Durak kelimeler atılır. Yalnızca içerik kelimeleri (content words) kalır.
  - Türkçe gibi sondan eklemeli dillerde ekler atılır. Türkçe için Snowball, Zemberek veya Porter stemmer kullanılabilir.
- Terim-belge matrisi: satırlar terimler, sütunlar belgeler. Değerler terimin belgede geçme sayısı (ya da 1/0).
- Gerçek bir derlemde bu matris çok seyrektir. Her kelime her belgede geçmez.
- Seyreklikten kurtulmak için ilk akla gelen yumuşatma (smoothing) teknikleri. Ama burada önce ham sayımlar yerine ağırlıklar kullanılır.
- Yerel ağırlık (tek belge içinde):
  - Belgede çok geçen kelime, bir kez geçen kelimeden daha anlamlıdır.
  - Örnek: 11 kelimelik bir belgede "Türkiye" 10, "yer" 1 kez geçiyor. Yerel ağırlıklar $10/11$ ve $1/11$. Değerler normalize de edilmiş olur.
- Global ağırlık (derlem genelinde):
  - Seyrek kullanılan kelime, yaygın kelimeden daha ilginçtir, çünkü daha ayırt edicidir.
  - Örnek: 5 belgenin hepsinde A geçiyor, yalnızca 2'sinde B ("onkoloji") geçiyor. B, o iki belgenin onkolojiyle ilgili olduğunu gösterir.
  - IDF ile hesaplanır. Hoca B için örneği $2 \cdot \log(5/2)$ olarak, yani TF-IDF biçiminde yazdı.
- Ağırlıklı matris: $a_{ij} = L_{ij} \cdot G_i \cdot N_j$. Eski modellerde yalnızca frekans kullanılıyordu.

#### Negatif değerler

- SVD sonrasında matriste negatif değerler görülür.
- Bir kelime bir belgede ya hiç geçmez ya da birkaç kez geçer; negatif sayım olmaz. Buradaki negatiflik anlamsal uzaklıktır.
- Pozitif: ilişkili. 0: nötr. Negatif: içerik olarak çok uzak.
- Örnek: yaz tatilinden bahseden bir belge ile "onkoloji" kelimesi arasındaki değer negatif olabilir.

#### Kullanım alanları

- Bilgi erişimi.
- Eş anlamlıları yakalama: "okul" ve "mektep".
- Çok anlamlılık: yazılışı aynı, anlamı farklı kelimeler.
- Arşivleme, belge sınıflandırma, özetleme, filtreleme.

### SVD örneği (2×2)

- Amaç, matristeki anlamsal bilgiyi çekmek. Bunun için özdeğerler, özvektörler (eigenvector) ve tekil değerler (singular values) bulunur.

$$
A = \begin{bmatrix} 4 & 0 \\ 3 & -5 \end{bmatrix}
\qquad
A^T A = \begin{bmatrix} 4 & 3 \\ 0 & -5 \end{bmatrix}\begin{bmatrix} 4 & 0 \\ 3 & -5 \end{bmatrix} = \begin{bmatrix} 25 & -15 \\ -15 & 25 \end{bmatrix}
$$

- Adım 1, özdeğerler: $\det(A^T A - cI) = 0$.
  - $(25-c)^2 - 225 = 0 \Rightarrow c^2 - 50c + 400 = 0$.
  - $c_1 = 40$, $c_2 = 10$. Azalan sırada sıralanır.
- Adım 2, tekil değerler: özdeğerlerin karekökü.
  - $s_1 = \sqrt{40} \approx 6{,}32$, $s_2 = \sqrt{10} \approx 3{,}16$.
  - Köşegeninde büyükten küçüğe tekil değerler olan $S$ matrisi kurulur. $S^{-1}$ de sonradan gerekecek.

$$
S = \begin{bmatrix} \sqrt{40} & 0 \\ 0 & \sqrt{10} \end{bmatrix}
\qquad
S^{-1} = \begin{bmatrix} 1/\sqrt{40} & 0 \\ 0 & 1/\sqrt{10} \end{bmatrix}
$$

- Adım 3, özvektörler: her özdeğer $(A^T A - cI)x = 0$ denkleminde yerine konur.
  - $c = 40$: $-15x_1 - 15x_2 = 0 \Rightarrow x_2 = -x_1$. Vektör $(x_1, -x_1)$.
  - Uzunluk $\sqrt{x_1^2 + x_1^2} = x_1\sqrt{2}$. Her eleman uzunluğa bölünür: $(1/\sqrt{2},\ -1/\sqrt{2})$.
  - $c = 10$: $15x_1 - 15x_2 = 0 \Rightarrow x_2 = x_1$. Birim vektör $(1/\sqrt{2},\ 1/\sqrt{2})$.
  - Bu iki vektör $V$ matrisinin sütunlarıdır. $V^T$ de alınır.
- Adım 4, $U$ matrisi: $U = A V S^{-1}$.

$$
V = \begin{bmatrix} 0{,}7071 & 0{,}7071 \\ -0{,}7071 & 0{,}7071 \end{bmatrix}
\qquad
U = A V S^{-1} = \begin{bmatrix} 0{,}4472 & 0{,}8944 \\ 0{,}8944 & -0{,}4472 \end{bmatrix}
$$

- Hoca $U$'yu "kelimeler arasındaki anlamsal ilişkilerin de çıkarıldığı matris" diye tanımlıyor.
- Geri dönüş: $A \approx U S V^T$. Sonuç yaklaşık çıkar. Virgülden sonra kaç basamak alındığına göre gerçeğe yaklaşılır.
- Matris $n \times n$ olsaydı $n$ özdeğer ve $n$ özvektör çıkacaktı.
- Pratikte bu işlemler elle yapılmaz. Kütüphanelerdeki LSA fonksiyonuna matris verilir; arka planda bu adımlar çalışır.

### LSI örneği: "gold silver truck"

- Belgeler:
  - $d_1$: "Shipment of gold damaged in a fire"
  - $d_2$: "Delivery of silver arrived in a silver truck"
  - $d_3$: "Shipment of gold arrived in a truck"
- Sorgu: "gold silver truck".
- Örnek küçük olduğu için durak kelimeler atılmadı ve kök bulma yapılmadı. Yoksa geriye işlenecek kelime kalmazdı.
- Terimler alfabetik sıralandı. Matris yalnızca sayımlarla kuruldu; ağırlıklandırma yapılmadı.
- Hoca uyarısı: sorgu kelimelerinden kaçının geçtiğine bakıp "$d_2$ önce gelsin" demeyin. Anlamsal olarak en yakın olanın gelmesi beklenir.

| Terim | $d_1$ | $d_2$ | $d_3$ | $q$ |
|---|---|---|---|---|
| a | 1 | 1 | 1 | 0 |
| arrived | 0 | 1 | 1 | 0 |
| damaged | 1 | 0 | 0 | 0 |
| delivery | 0 | 1 | 0 | 0 |
| fire | 1 | 0 | 0 | 0 |
| gold | 1 | 0 | 1 | 1 |
| in | 1 | 1 | 1 | 0 |
| of | 1 | 1 | 1 | 0 |
| shipment | 1 | 0 | 1 | 0 |
| silver | 0 | 2 | 0 | 1 |
| truck | 0 | 1 | 1 | 1 |

- SVD sonucu tekil değerler: 4,0989; 2,3616; 1,2737. Belge sayısı 3 olduğu için 3 tekil değer var.

#### Rank seçimi

- $S_T$ = tekil değerlerin toplamı.
- Rank $r$ için oran: ilk $r$ tekil değerin toplamı / $S_T$.
- Bu örnekte: $r=1$ için %53, $r=2$ için %83,5, $r=3$ için %100.
- Kabul edilen eşik (örneğin %80) hangi $r$ ile aşılıyorsa o seçilir. Daha fazla kolon %100'e yaklaştırır ama işlem maliyeti artar ve kazanç çok küçük olur. Hoca: "Attığın taş ürküttüğün kurbağaya değmez."
- Bu örnekte $k = 2$ seçildi: $U$'nun ilk 2 sütunu, $S$'nin 2×2'lik kısmı, $V$'nin ilk 2 vektörü.

#### Belge ve sorgu vektörleri

- Belgeler artık $V_k$'nın satırlarıyla temsil edilir (2 boyutlu). Bu değerler yalnızca belgedeki kelimelerden değil, kelimelerin birlikte geçmelerinden de çıkar.
  - $d_1 \approx (-0{,}49;\ 0{,}65)$
  - $d_2 \approx (-0{,}65;\ -0{,}72)$
  - $d_3 \approx (-0{,}58;\ 0{,}25)$
- Sorgu aynı uzaya taşınır: $q_k = q^T U_k S_k^{-1} \approx (-0{,}21;\ -0{,}18)$.
- Kosinüs benzerlikleri:
  - $\mathrm{sim}(q, d_1) \approx -0{,}05$
  - $\mathrm{sim}(q, d_2) \approx 0{,}99$
  - $\mathrm{sim}(q, d_3) \approx 0{,}45$
- Sıralama: $d_2 > d_3 > d_1$. 2 boyutlu uzay grafiğinde de $q$'ya en yakın belge $d_2$.
- Hoca: burada "gold" o kadar etkili olmamış, "silver truck" öne çıkmış. Cümleler yalnızca örnek için yazılmış.

### Arama motorları

- Hoca bu kısmı yüzeysel geçti, çünkü sürekli değişiyor.
- Web katalogları elle seçilmiş sitelerin tanımlarında arar ve hiyerarşik kategorilere ayırır. Arama motorları tüm sitelerin tüm sayfalarının içeriğinde arar ve sonuçları skora göre sıralar.
- Google mimarisi slaytta kabaca var. Merak eden ayrıntılı incelesin.
- PageRank: değer ne kadar yüksekse site o kadar popülerdir.
  - Puan; başlıklar, bağlantı metinleri (anchor text), sayfaya gelen ve sayfadan giden link sayıları gibi karışık hesaplarla çıkar.
  - Sürekli başka sayfalara link veren sayfa çok bilgi içermiyordur. Herkesin link verdiği sayfanın PageRank'i yüksektir.
- Akıllı bir arama motorunda olması gerekenler:
  - Eş anlamlılar: "restoran" aranınca lokanta, kafe, pub da gelmeli.
  - Kısaltmalar: "PRC" (People's Republic of China) için "China" da gelmeli.
  - Çok anlamlılık: "Apple" şirketi ile elma meyvesi ayrılmalı. "bat" hem beyzbol sopası hem yarasa.
  - Sorgudaki kelime sırası: insan önemli olanı öne yazar. Öndeki kelimeye öncelik verilmeli.
  - Kullanıcı davranışı: aynı sorguda herkes 3. sıradaki linke gidiyorsa o link üste çıkmalı.
  - Sorgu genişletme: "Yıldız Teknik Üniversitesi" aranınca eski adı "Yıldız Üniversitesi" geçen sayfalar da gelmeli.
  - İmla denetimi: "Bunu mu demek istediniz?"
  - Kaynak güvenilirliği: tamamen yanlış bilgilerle dolu bir sayfa da indekslenir. İndekslemede içeriğin doğruluğu kontrol edilmeli.

### Performans ölçütleri

#### Karışıklık matrisi

| | Test pozitif | Test negatif |
|---|---|---|
| Gerçekte hasta | doğru pozitif (TP) | yanlış negatif (FN) |
| Gerçekte sağlam | yanlış pozitif (FP) | doğru negatif (TN) |

- Hoca bu dört kavramın sık karıştırıldığını, kendisinin de bu tabloyu akılda tutarak hatırladığını söylüyor.
- Yazılım örneği: hatalı kod teste girer ve test hatayı bulursa TP. Bulamazsa FN.
- Amaç TP ve TN'yi büyütmek, FP ve FN'yi küçültmek. Her şeyin köşegene oturması teoride mümkün, pratikte zor.
- FP, Tip I hata (type I error). FN, Tip II hata (type II error).
- Hangi hata daha tehlikeli?
  - Sağlam birine "hastasın" demek (FP): morali bozulur, birkaç gün sonra bir şey olmadığını görür.
  - Hasta birine "hasta değilsin" demek (FN): durum eninde sonunda kötüleşir. Ölümcül sonuçlar FN'dedir.
  - Bu yüzden FN'yi en aza indirmek daha önemlidir.
- Karışıklık matrisi Türkçede hata matrisi ya da karmaşıklık matrisi diye de geçer. 2×2 olmak zorunda değil.

#### Duyarlılık ve özgüllük

- Hocanın benzetmesi:
  - Yalnızca kokain için eğitilmiş polis köpeği: dar alanda uzman, karıştırma şansı az. Özgüllüğe benzetiliyor.
  - Kokain, eroin, esrar gibi birçok madde için eğitilmiş köpek: yelpazesi geniş ama tek bir maddeyi bulmada karıştırabilir. Duyarlılığa benzetiliyor.
- Formüller:
  - Duyarlılık (sensitivity) = $\frac{TP}{TP + FN}$: gerçek pozitiflerin ne kadarı yakalandı.
  - Özgüllük (specificity) = $\frac{TN}{TN + FP}$: gerçek negatiflerin ne kadarı doğru ayrıldı.
  - Yanlış negatif oranı = $1 -$ duyarlılık.
  - Yanlış pozitif oranı = $1 -$ özgüllük.
- Pozitif ve negatif kestirim değerleri (positive/negative predictive value) de hesaplanabilir. Hoca bunların tıp çalışmalarında önemli olduğunu, bilgisayar alanındaki akademik çalışmalarda pek kullanılmadığını söylüyor.
- Bilgi erişiminde "sensitivity" yerine "recall" denir. İkisi aynı şeydir.

#### Bilgi erişiminde kesinlik ve anma

- Web içinde bir sorgu için ilgili (relevant) belgeler ve getirilen (retrieved) belgeler vardır. Arama motoru ne kadar iyiyse bu iki küme o kadar örtüşür.

| | İlgili | İlgisiz |
|---|---|---|
| Getirilen | ilgili ve getirilen | ilgisiz ama getirilen |
| Getirilmeyen | ilgili ama getirilmeyen | ilgisiz ve getirilmeyen |

$$
\text{Kesinlik (precision)} = \frac{|\text{ilgili} \cap \text{getirilen}|}{|\text{getirilen}|}
\qquad
\text{Anma (recall)} = \frac{|\text{ilgili} \cap \text{getirilen}|}{|\text{ilgili}|}
$$

- Kesinlik: getirilenlerin ne kadarı doğru.
- Anma: gelmesi gerekenlerin ne kadarı geldi.
- Anma, özgüllükle karıştırılmamalı.
- İkisini ayrı ayrı kullanmak yanıltır. Harmonik ortalamaları kullanılır:

$$
F = \frac{2 \cdot P \cdot R}{P + R}
$$

- F = 1, %100 başarı demektir.
- Çok sınıflı örnek: 100 belge ve 10 yazar (yazar tanıma). 10 sınıf için ayrı ayrı kesinlik ve anma hesaplanır, ortalamaları alınır.

### Bilgi çıkarımı (information extraction)

#### IR, IE ve soru cevaplama

- IR: sorgu gönderilir, belgeler gelir.
- IE: gelen belgelerden aranan bilginin bulunup çıkarılması. Örnek: "Uganda başkent" aranır; belgelere bakılıp başkentin Kampala olduğu bulunur.
- Soru cevaplama: "Uganda'nın başkenti neresi?" sorusuna doğrudan cevap.
- Üçü iç içedir. İyi bir IR, iyi bir IE'yi; iyi bir IE, başarılı soru cevaplamayı sağlar.
- Hoca bu konunun çok büyük olmadığını, birçok parçasının önceki slaytlarda geçtiğini söylüyor. Çoğu iş kendi yazılan kodlarla yapılır; hazır bir araç yok.

#### Tanım ve uygulamalar

- Bilgi çıkarımı: yapılandırılmış, yarı yapılandırılmış veya yapılandırılmamış verilerden şablonlar ya da yazılan kodlarla istenen bilginin çıkarılması.
- Message Understanding Conference (MUC): 1990'lardan beri düzenlenen yarışmalar. Verilen platformda sorulara en doğru cevabı getiren sistemler ödül alır.
- ABD için devlet politikası: webi izleyip ilgili bilgileri otomatik çıkarmak.
- Uygulama örnekleri:
  - Haberlerden ve tweetlerden terör olaylarını saptamak.
  - Şirket birleşmelerini ve ayrılmalarını haberlerden önceden çıkarıp borsada kullanmak.
  - İş ve işçi bulma: farklı ilan sitelerinden, örneğin LinkedIn'den, kriterlere uyan kişileri iletişim bilgileriyle getirmek.
  - Farklı sitelerde satılan ve kriterlere uyan ürünleri getirmek.
  - Farklı platformlardaki seminer duyurularını (örneğin fotoğrafçılık) toplamak.
  - Kiralık ve satılık daire ilanlarını taramak.
- Ortak özellik: birden çok yerden, istenen özelliklere sahip bilgiyi toplayıp getirmek.

#### Belge türleri

- Yarı yapılandırılmış: e-posta.
  - Konu, tarih, gönderen ve e-posta adresi gibi alanların yeri bellidir. Kolay çekilir.
  - Gövde yapılandırılmamıştır. Örnek: yazılım geliştirici ilanı. Deneyim, C bilgisi, 5 yıl deneyim, platform (DOS, OS/2, Unix) gibi anahtar kelimeler düzenli ifadeler ve dile özgü NLP özellikleriyle çekilir.
  - Çekilen bilgiler veritabanı alanlarına (dil, platform, deneyim, ilan numarası, ülke) yerleştirilir. Aramalar veritabanından yapılır.
- Yapılandırılmamış: düz paragraf. En zor çalışma alanıdır.
  - Örnek cümle: "21 yaşındaki inşaat işçisi A, evine dönerken para meselesi yüzünden tartıştığı arkadaşı B tarafından bıçaklanarak öldürüldü."
  - Sorular: kim öldürüldü, kim öldürdü, kaç yaşındaydı, işi neydi, neden, nerede, ne ile?
  - Yaşın kime ait olduğu belirsizdir. "tarafından" kalıbının önündeki adlandırılmış varlık öldüreni verir. "-lanarak" eki alan kelimenin kökü suç aletini gösterir.
  - 5N1K sorularını cevaplamak büyük problemdir. Cümleler karmaşık olabilir, içinde birçok kişi geçebilir. Sözdizimsel çözümleme ve sözcük türü etiketleri (POS tags) gerekir.
- Yapılandırılmış: ürün sayfası gibi web sayfaları. Örnek Amazon kitap sayfası.
  - Hangi HTML etiketleri arasında hangi bilginin olduğu bellidir: kitap adı, yazar, fiyat, ciltli/ciltsiz, baskı.
  - Fiyat karşılaştırma siteleri bunu kullanır. Özel NLP araçlarına gerek yoktur.

#### Düzenli ifadeler

- Birçok bilgi düzenli ifadelerle çıkarılabilir: adres, telefon.
- Doğum yeri ve tarihi örneği: "80 doğumluyum", "1980 doğumluyum", "1980 yılında İstanbul'da doğdum", "İstanbul'da 1980 yılında doğdum". Bu birkaç biçim tek bir regex ile yakalanabilir.
- Yukarıdaki cinayet cümlesi ise regex ile kolay çözülmez.
- Slaytta Amazon listesinden fiyat çıkaran bir regex şablonu var.
- Hoca, derin öğrenmeyle metin ve soru-cevap çiftleri verilerek bunun öğretilebileceğini düşünüyor. Ama milyonlarca belge ve etiket gerekir; etiketleme pahalıdır.

#### NLP katkısı

- Sözcük türleri: "Hava nasılmış?" sorusu için metindeki sıfatlar (güzel, yağmurlu) aranır.
- Sözdizimsel çözümleme: kim vurdu, neden vuruldu; özel isimler, isim öbekleri, fiil öbekleri.
- Anlamsal sınıflandırma: WordNet. "Öldürmek" eş anlamlı kümesinde (synset) kill, murder gibi ölümle ilişkili kelimeler.
- NER: metindeki kişi, yer, kurum, tarih ve zamanları bulmak.
- Örnek: "ye-" fiilinin nesnelerini arama motoruyla bulmak.
  - "yerken" aranınca: yarım döner, kraker, zeytin, mantar gibi yenilebilen şeyler gelir.
  - Hatalı sonuçlar da gelir. "Yerken" büyük harfle yazılmışsa soyadıdır; fiil büyük harfle yazılmaz. "Kiraz Yerken" bir kişinin adı ve soyadı olabilir. Bunlar büyük harf kuralı ve NER ile elenir.

#### Adlandırılmış varlık tanıma (NER)

- Temel varlıklar: kişi, yer, kurum. Ek olarak para birimi, tarih, zaman.
- Alt türlere ayrılabilir: yer için ülke, şehir, belde gibi hiyerarşik etiketler.
- Etiketleme örneği:

```
<PER>Jane Brown</PER> saw a cat in <LOC>London</LOC>
```

- Yöntemler:
  - Kural tabanlı: "New York → yer", "Mr. ile başlıyorsa kişi", "Corp./Co. geçiyorsa şirket". Hiçbir şey kaçmaz ama her şeyi tek tek vermek çok maliyetli. Artık geride kaldı.
  - Şablon tabanlı:
    - "unvan + kişi": unvan sözlüğünde "President" var, ardından gelen "George Bush" kişidir. Noktasız büyük harfle devam eden kelimeler aynı ismin parçasıdır.
    - "kişi, the unvan of kurum": "Fred Martin, the CEO of XYZ Corp." → CEO unvan, Fred Martin kişi, XYZ Corp. kurum.
    - Cümle üzerinde pencere kaydırılarak şablona uyan yerler bulunur. Asıl iş şablonları çıkarmaktır.
    - Yer, telefon numarası, tarih, URL ve e-posta için de şablonlar yazılabilir.
  - CRF (conditional random fields, koşullu rastgele alanlar): saklı Markov modellerine benzer. Bağlamdaki kelimelere göre olasılık hesaplar. Örneğin "Dr." ile başlayan bir kalıpta ortadaki kelimenin kişi olma olasılığı 0,98 gibi.
  - Derin öğrenme: olasılık tanımlanmaz; etiketli veri verilir, sistem etiketler arasında ne geldiğini öğrenir.
- Şablonla bulunan sonuçlara ağırlık verilir. Dilde daha sık kullanılan şablonun ağırlığı daha yüksektir. Sonuçlar bu ağırlıklara göre sunulur. Örnek çıktılar: Kodak, Apple Computer, Cupertino.
- Başarı %100 değil. NER birçok araçta İngilizce ve Türkçe için mevcut.
- Türkçe kaynaklar: Starlang (NLP araçları ve veri setleri paylaşıyor), Loodos (Türkçe için BERT tabanlı dil modelleri geliştirip kullanıma açtı).

#### Güvenilir sayfaları belirleme

- Her sayfada doğru bilgi yok. Yöntem:
  1. Doğruluğu bilinen çiftler seçilir: Ankara–Türkiye, Paris–Fransa, Türk lirası–Türkiye, dolar–ABD.
  2. Bu çiftler arama motoruna gönderilir, dönen sayfalardan şablonlar çıkarılır (başkent şablonu, para birimi şablonu).
  3. Şablonlar arama motoruna gönderilir, şablona uyan sayfalar bulunur.
  4. Gelen cevaplar veritabanıyla karşılaştırılır. Örneğin "Türkiye'nin başkenti İstanbul" diyen sayfa doğrulanmaz.
  5. Yanlış bilgi içeren sayfalar elenir. Arama motoru bu sayfaları indekslemeyi de keser.

#### Dinamik web sayfaları ve alışveriş robotları

- Web sayfalarından bilgi çıkarmak kolaydır, çünkü HTML kurallı bir dildir ve etiketler arasında tekrar eden kalıplar vardır. Örneğin tablo satırları aynı kalıpla tekrarlar.
- Alışveriş robotu örnekleri: Froogle, mySimon, BookFinder.
- Alışveriş robotunun çalışması:
  1. Her satıcı site için bilgi çıkarma mekanizması kurulur.
  2. Kullanıcının sorgusu alınır.
  3. Sorgu her siteye tek tek gönderilir, sonuç sayfaları alınır.
  4. Sonuç sayfalarından bilgi çıkarılıp veritabanına kaydedilir.
  5. Sonuçlar istenen ölçüte göre sıralanıp kullanıcıya döndürülür.

#### IE'de performans ölçümü

- $N$: belgelerdeki doğru cevap sayısı. $E$: sistemin çıkardığı toplam cevap sayısı. $C$: sistemin çıkardığı doğru cevap sayısı.
- Kesinlik $= C / E$. Anma $= C / N$. F-ölçüsü yine harmonik ortalamadır.

#### Şablon tabanlı ilişki çıkarımı

- "Tüm X'ler Y'dir" ilişkisi: örnek "bütün kuşlar kanatlıdır".
  1. "kuş" ve "kanat" birlikte aranır. Gelen kalıplar: "kuş ve diğer kanatlılar", "kuşlar ve diğer kanatlılar", "kuş ve benzeri kanatlılar", "kuş veya diğer kanatlılar", "kuş türü olan kanatlı".
  2. Bu kalıplar aranarak aynı ilişkiye sahip başka ikililer bulunur ve frekansları çıkarılır.
  3. Bulunan ikililer elle işaretlenir. Bazıları uyar (teçhizat–malzeme, protein–gıda, komünizm–ideoloji, delta–Gediz), bazıları uymaz (kız–sıfat gibi).
- "X'in yeri Y'dir" ilişkisi: "Beşiktaş" ve "İstanbul" aranır. "Beşiktaş İstanbul ili sınırları içerisinde bulunan..." gibi kalıplar çıkar. Bu kalıplarla başka ikililer bulunur.

### Ders sonu

- Bir öğrenci slaytları sordu. Hoca slaytların AVESİS sayfasında 2020 olarak yüklendiğini, ders ve konu adlarının dosyalarda yazdığını söyledi.

### Ders sonrası notlar

- LSI örneğinde altyazıda sorgu bir yerde "gold silver" diye geçiyor. Hoca hemen düzeltiyor: sorgu "gold silver truck".
- $d_1$ altyazıda "Shipment of gold to meet in a fire" diye geçiyor. Doğrusu "Shipment of gold damaged in a fire".
- Rank seçimini anlatırken hoca $r = 1, 2, 3$ için "%80, %85, 0,75" gibi rastgele oranlar verdi. Bu oranlar birikimli toplam olduğu için $r$ arttıkça büyür; $r = 3$ (tüm değerler) her zaman %100'dür. Bu örneğin gerçek değerleri %53, %83,5 ve %100.
- Hoca "global term weighting TF-IDF'e karşılık gelir" diyor. Tam olarak yerel ağırlık TF'e, global ağırlık IDF'e karşılık gelir. İkisinin çarpımı TF-IDF'dir.
- Hoca bir yerde "false negative rate bir eksi specificity" diyor. Doğrusu: yanlış pozitif oranı $= 1 -$ özgüllük. Yanlış negatif oranı $= 1 -$ duyarlılık.
- Hoca F-ölçüsündeki 2 çarpanının "denemeler sonucu bulunduğunu" söylüyor. Bu çarpan harmonik ortalamanın tanımından gelir: $F = \frac{2}{1/P + 1/R} = \frac{2PR}{P+R}$.
- Hoca precision için "duyarlılık" diyor. Türkçe kaynaklarda precision çoğunlukla "kesinlik", recall ise "duyarlılık" ya da "anma" diye geçer. Bu özette precision = kesinlik, recall = anma kullanıldı.
- Hocanın köpek benzetmesi formüllerle birebir örtüşmüyor. Sınavda formülleri esas alın: duyarlılık gerçek pozitiflere, özgüllük gerçek negatiflere bakar.
- Altyazıdaki "Namajigoro" Uganda'nın başkenti için söyleniyor. Uganda'nın başkenti Kampala'dır.
- Altyazıdaki "laten semantik indexing/LST" LSI, "portrait stammer" Porter stemmer, "Ludus" Loodos, "Frogle" Froogle, "but" (beyzbol/yarasa) "bat" demektir.

İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
