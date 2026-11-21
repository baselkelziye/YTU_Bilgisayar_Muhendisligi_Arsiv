# Ders 8 Genişletilmiş Notu: Yarı Rastgele Altuzaylar, Uzman Karışımı, Stacking ve Karar Birleştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yarı rastgele altuzaylar (Semi-Random Subspace)
- 2. Karar benzerliği matrisi ve topluluk büyüklüğünün etkisi
- 3. Teorik çalışma, deney ve varsayımlar
- 4. Yerel modellerin birleşimi (Mixture of Experts)
- 5. İki aşamalı öğrenme (Stacking)
- 6. Yöntemler üzerine sorular: paralelleştirme ve Rotasyon Ormanı
- 7. Model kararlarını birleştirme kuralları
- 8. Bir deney: budama ve ağırlıklandırma
- 9. Algoritmaların karşılaştırılması
- 10. Algoritmaların ve veri kümelerinin benzerliği
- 11. Kolektif regresyon ağaçları
- 12. Kolektif kümeleme
- Örnek Sorular

## 1. Yarı rastgele altuzaylar (Semi-Random Subspace)

Ders, önceki haftadan kalan bir konuyla, yarı rastgele altuzay (semi-random subspace) adlı bir bildirinin fikriyle başladı. Hoca anlatımı boş bir Word belgesine yazarak yaptı.

### 1.1 Rastgele altuzayları hatırlama

Elimizde $N$ örnek ve $d$ özellik olsun; orijinal eğitim kümesi $N \times d$ boyutundadır. Rastgele altuzay (Random Subspace) yönteminde her tekil öğrenici için özelliklerin bir kısmı, örneğin $d/2$ tanesi, rastgele seçilir. Böylece her tekil öğrenicinin eğitim kümesi $N \times d/2$ boyutunda olur (ekrandan, 00:10:00). Örnek sayısı değişmez; bütün örnekler alınır, yalnız özellikler seçilir.

Örnek olarak 4 özellik (1, 2, 3, 4) ve $d/2 = 2$ alınsın. Rastgele ikililer üretilir: bir öğrenici 1 ve 3 ile, bir başkası 3 ve 4 ile, bir başkası 1 ve 2 ile, bir diğeri 3 ve 2 ile çalışır (ekrandan, 00:10:00). Her ikiliyle bir sınıflandırıcı ya da regresör eğitilir, sonra sonuçlar birleştirilir.

Hoca $d/2$ seçiminin deneysel olarak iyi çalıştığının ifade edildiğini, kendi gözlemlerinin de bu yönde olduğunu söyledi. Ama $d/2$ şart değildir; $d/4$ ya da $d/5$ de seçilebilir.

### 1.2 $x$'in tekil başarıya ve çeşitliliğe etkisi

Hoca şu soruyu sordu: $d/x$ ifadesindeki $x$'in değişimi tekil öğrenici başarısını ve çeşitliliği (diversity) nasıl etkiler? Çeşitlilik, tekil öğrenicilerin kararlarının birbirinden ayrıklığıdır.

**Soru:** $x$ büyüyünce ne olur? **Cevap:** Bir öğrenci önce örnek sayısının azalacağını söyledi; hoca düzeltti: örnek sayısı aynı kalır, azalan özellik sayısıdır. Özellik sayısı azalınca tekil öğrencinin başarısı düşer, çeşitlilik artar.

Örneğin 100 özellikten yalnız 10'u seçilirse her tekil öğrenici az bilgiyle çalışır ve başarısı düşer. Öte yandan her biri farklı 10 özellikle eğitildiği için kararları birbirinden farklılaşır. Benzer özellikler kullanan öğrenicilerin kararları birbirine yaklaşır ve çeşitlilik düşük olur. $x$ küçükse tam tersi olur: tekil başarı artar, çeşitlilik azalır (ekrandan, 00:15:00).

### 1.3 Fikir: tekil başarıyı değiştirmeden çeşitliliği artırmak

Topluluğun başarısı iki şeye bağlıdır: tekil öğrenici başarısı ve çeşitlilik. $x$'i artırarak ya da azaltarak genel olarak daha başarılı bir topluluk elde edilemez, çünkü birinden kazanırken ötekinden kaybedilir. Soru şudur: $x$'i değiştirmeden, yani seçilen özellik sayısını (dolayısıyla tekil başarıyı) sabit tutarak çeşitlilik artırılabilir mi?

İki öğrenicinin kararlarının benzer olma ihtimali, özellik altkümelerindeki ortak özellik sayısıyla ilişkilidir. Rastgele seçimde altkümeler genellikle bazı özellikleri paylaşır: "1 3" ile "3 4" yarı yarıya aynı özellikleri kullanır, "1 3" ile "1 2" yine bir ortak özelliğe sahiptir. Tüm sistemin çeşitliliği, her özellik altkümesinin diğer bütün altkümelerle benzerliklerinin ortalaması gibi düşünülebilir.

Yarı rastgele altuzay yöntemi öğrenicileri çiftler hâlinde üretir (ekrandan, 00:15:00):

```text
SRS, 4 özellik: 1 2 3 4, d/2 = 2
1 3   (4 özellik içinden 2 tanesini rastgele seç)
2 4   (geri kalanları al)
1 2   (4 özellik içinden 2 tanesini rastgele seç)
3 4   (geri kalanları al)
```

Her öğrenici yine iki özellik kullandığı için tekil başarı kabaca yukarıdaki klasik yöntemle aynıdır. Ama birinci ile ikinci öğrenici, üçüncü ile dördüncü öğrenici bilerek birbirinden tamamen bağımsız yapılmıştır: ortak eleman içermezler. Ortak eleman içermeyen öğrenicilerin kararları farklılaşır, çeşitlilik artar. Tekil başarı aynı kalıp çeşitlilik arttığında topluluğun başarısı da artar.

### 1.4 Üçlü seçim ve tam bölünmeyen durum

**Soru:** $d/3$ olsaydı da aynı şekilde mi yapılırdı? **Cevap:** Evet. Örneğin 9 özellik ve üçlü seçimde önce 9 özellik içinden 3'ü rastgele seçilir (ör. 1 4 6). Sonra bunların dışındaki 6 özellikten 3'ü rastgele seçilir (ör. 2 7 8). Son öğreniciye kalan 3 özellik verilir (3 5 9) (ekrandan, 00:20:00). Bu üçlünün kendi arasındaki çeşitlilik artar; başka gruplardaki öğrenicilerle olan çeşitlilikte değişiklik olmaz.

**Soru:** 5 özellik olsaydı ve 3'er özellik seçilseydi nasıl yapılırdı? **Cevap:** 5 özellikten 3'ü rastgele seçilir; eşine geri kalan 2 özellik konur, eksik kalan üçüncü özellik rastgele seçilir. En azından iki özellik önceki öğrenicide olmayan özellikler olduğu için rastgele seçime göre çeşitlilik yine artar.

## 2. Karar benzerliği matrisi ve topluluk büyüklüğünün etkisi

Yöntemin başarılı olacağı açık görünüyor. Hoca bu başarının neyle azalabileceğini düşünmek için bir tablo çizdi.

### 2.1 Dört öğrenici

4 tekil öğrenici için 4x4'lük bir karar benzerliği matrisi çizildi. Her hücre iki tekil öğrenicinin kararlarının benzerliğini gösterir. Köşegen 1'dir, çünkü herkesin kararı kendisiyle birebir aynıdır. Matris simetrik olduğu için yalnız üst üçgene bakmak yeterlidir: 1-2, 1-3, 1-4, 2-3, 2-4, 3-4 çiftleri. Topluluğun çeşitliliği bu değerlerin ortalamasıyla ifade edilir (ekrandan, 00:25:00).

Yarı rastgele yöntem yalnız 1-2 ve 3-4 çiftlerinin benzerliğini azaltır (ekranda Y ile işaretli hücreler). Diğer çiftlerde değişiklik olmaz: örneğin 1 ile 3'ün her ikisi de rastgele seçimdir, onlardan kalanlar da rastgeledir. Dolayısıyla 4 öğrenicide 6 değerin 2'si azaltılmıştır (ekrandan, 00:25:00).

### 2.2 Altı öğrenici ve genelleme

6 öğrenicide üst üçgende $6 \cdot 5 / 2 = 15$ değer vardır. Yarı rastgele yöntem 1-2, 3-4 ve 5-6 çiftlerini azaltır; yani 15 değerin 3'ü azalır (ekrandan, 00:30:00). Hoca bunu şöyle özetledi: 4 öğrenicide değerlerin yaklaşık %33'ü, 6 öğrenicide %20'si azaltılabildi.

**Soru:** Öğrenici sayısı 100 olsa değerlerin ne kadarı azalır? **Cevap:** Çok çok küçük bir kısmı. Bu yüzden yöntem topluluk büyüklüğü (ensemble size) küçükken çok etkilidir; topluluk büyüdükçe etkisini büyük ölçüde yitirir. Çeşitlilik yine artar, ama başarıdaki artış azalır.

> **Ek bilgi (derste anlatılmadı):** Derste verilen iki duruma bakılırsa, çift sayıda $L$ öğrenicide azaltılan çift sayısı $L/2$, toplam çift sayısı $L(L-1)/2$ olduğundan azaltılan oran $1/(L-1)$ olur. Bu oran 4 öğrenicide 1/3, 6 öğrenicide 1/5'tir; 100 öğrenicide yaklaşık %1'e düşer.

Hocanın vardığı sonuçlar:

- Yöntem başarıyı artırır, çünkü tekil öğrenici başarısına dokunmadan çeşitliliği artırır.
- Kazanç topluluk büyüklüğüyle ters orantılıdır: öğrenici sayısı arttıkça çeşitlilikteki artışın oranı azalır ve topluluğun doğruluğu çok fazla yükseltilemez.

## 3. Teorik çalışma, deney ve varsayımlar

### 3.1 Deney yapmadan varılan sonuç

Hoca, yukarıdaki sonuçların hiçbir deney yapılmadan, tamamen mantıkla elde edildiğine dikkat çekti. Bir veri kümesi alınıp rastgele altuzay ile yarı rastgele altuzay karşılaştırılmadı; yani empirik (deneysel) bir şey yapılmadı, teorik bir iş yapıldı. Böyle düz bir mantıkla ve çok az varsayımla varılan bir sonucun deneyde de gözlenmesi beklenir. Hocanın kendi deneylerinde de beklenen bulgular çıkmıştı: daha başarılı topluluklar, ama topluluk büyüdükçe azalan başarı farkı.

> **Hocanın vurgusu:** Deneysel çalışmalar mühendislik anlamında çok önemlidir, ama işin seyrini değiştiren çalışmalar teorik çalışmalardır. Bütün dünyada teorik çalışan insan sayısı deneysel çalışanlardan çok daha azdır, çünkü deney yapmak teorik bir şey geliştirmekten daha kolaydır. Bu yönü geliştirmek büyük bir avantajdır.

### 3.2 Teori deneyle uyuşmazsa

Hoca, bir teoriye göre beklenen şeyin deneylerde görülmemesinin ne anlama gelebileceğini sordu. Öğrencilerle birlikte şu ihtimaller sıralandı:

- Deney yanlış yapılmış olabilir. Bu durumda deney tekrarlanır.
- Deney tekrar tekrar yapılıp beklenen yine görülmüyorsa teori yanlış kurulmuş olabilir.
- Teorinin varsayımları deneyde kullanılan veri kümelerine uymuyor olabilir.

**Soru:** Bir öğrenci, AdaBoost ile Bagging karşılaştırmasında başarının veri kümesine göre değişmesiyle bunun ilgili olup olmadığını sordu. **Cevap:** Hoca yaklaştığını ama tam olmadığını söyledi: bütün algoritmalar birer varsayımdır. Varsayım, gerçekte olmayan ama bizim varsaydığımız ek şeylerdir; varsayımsız bir şey yapmak pek mümkün değildir. Teorinin varsayımlarıyla deneydeki veri kümelerinin yapısı birbirini tutmuyor olabilir.

### 3.3 Varsayımları genelleştirmek ya da daraltmak

Varsayımlar aslında kısıttır: "şöyledir, başka türlü değildir" denir. Teoriler genellikle "şu varsayım altında şu şöyledir" biçimindedir. Varsayımlar elinizdeki verilere uymuyorsa bu teorinin yanlışlığı değil, çok kısıtlı olmasıdır. Bazen varsayımlar yazılmadan, örtük olarak yapılmış olabilir; bilim tarihinde bunun çok örneği vardır. Bu örtük varsayımları ortaya çıkarıp onlardan kurtulmak da bir iştir.

Bir teoriyi geliştirmenin iki yolu vardır:

- Varsayımları genelleştirmek: bazı kısıtlar kaldırılırsa teori daha fazla duruma uygulanabilir. Hocaya göre daha iyisi budur.
- Varsayımları daraltmak: algoritmanın hangi durumlarda daha iyi çalıştığını açıkça tarif etmek. Bu, algoritmayı kullanacak kişilere bir kullanım kılavuzu gibi hizmet eder.

Hoca bir sonraki dersin teorik bir ders olacağını ve orada bu tür varsayım örneklerinin görülebileceğini söyledi.

## 4. Yerel modellerin birleşimi (Mixture of Experts)

### 4.1 Hatırlatma ve konum

Hoca slaytlara döndükten sonra, iki sınıflı problemleri çözebilen sınıflandırıcıları (ör. SVM) çok sınıflı problemlere uygulamak için kullanılan hata düzelten kod tabanlı toplulukların (Error-Correcting Output Codes) daha önce işlendiği öğrencilerle teyit edildi (ekrandan, 00:40:00). Ders, farklı eğitim kümeleri üretme yöntemlerinden sonuncusu olan yerel modellerin birleşimiyle devam etti. Daha önce farklı özellikler, farklı örnekler ve farklı sınıflar kullanan yöntemler görülmüştü.

### 4.2 Fikir

Yerel modellerde veri uzayı belli parçalara ayrılır ve her parçaya bir tekil öğrenici atanır. Hoca bulunduğunuz odayı örnek verdi: odanın içindeki noktalar üç boyutlu bir uzaydır; şu köşeyi bir öğrenici, öbür köşeyi başka bir öğrenici öğrenir. Her öğreniciye "senin uzmanlığın şurası" denir.

**Soru:** Böyle eğitilmiş öğreniciler varken bir test örneği gelince ne yapılır? **Cevap:** Bir öğrenci kararların ortalamasının alınacağını söyledi. Hoca, kimin kararına daha çok önem verileceğinin farklı olabileceğini hatırlattı. Ekranı iki boyutlu bir uzay gibi düşünürsek, bir sınıflandırıcı sol bölgeyi, biri orta kısmı, biri sağ tarafı çok iyi yapıyor olsun. Sol bölgeden gelen bir örnek için o bölgenin uzmanının kararı daha etkili olmalıdır. Demokrasi usulü burada anlamlı değildir; başka bir bölgeyi öğrenmiş bir öğrenicinin bu örnek için kararının pek anlamı yoktur.

**Soru:** Örneğin hangi bölgeden geldiğini biliyorsak neden diğer modellere de veriyoruz? Yalnız o bölgenin uzmanına vermek daha iyi olmaz mı? **Cevap:** Olur; burada anlatılan şey de odur.

### 4.3 Gating fonksiyonu

Slayttaki model (Jacobs ve ark., 1991) şöyledir (ekrandan, 00:45:00):

$$y = \sum_{j=1}^{L} w_j d_j$$

Her bir öğrenici veri uzayının farklı bir bölgesine uzmanlaşır. Bir geçit (gating) fonksiyonu, gelen her test örneği $x$ için ağırlıkları ($w_1, \dots, w_L$) üretir; bu ağırlıklar her uzmanın kararına o $x$ için ne kadar önem verileceğini gösterir. Test örneğinin gating'e de verilmesinin sebebi, o örneğin uzayın hangi bölgesinde olduğunun bulunmasıdır. Öğreniciler ve gating fonksiyonu doğrusal ya da doğrusal olmayan olabilir.

- Bütün $w_j = 1/L$ olursa bu demokrasidir.
- Bölgeler kesin sınırlarla ayrılmak yerine örtüşebilir; bir örnek bir uzmanın alanına girerken yakındaki uzmanların da etkisi olsun istenebilir. Bu durumda daha yumuşak geçişler kullanmak mantıklıdır.
- Herhangi bir anda yalnız bir $w$ 1, diğerleri 0 ise yalnız yerel uzmanın dediğine uyulur. O zaman önce hangi uzmanın kullanılacağı bulunur, sonra yalnız onun kararı kullanılır; örneği $L$ öğrenicinin hepsine vermenin anlamı kalmaz.

**Soru:** Bölgelerde kesişme olmasaydı gating'e gerek olur muydu? **Cevap:** Yine olabilir. Bir test örneği için yalnız kendi bölgesinin öğrenicisinin değil, o bölgeye yakın diğer öğrenicilerin kararlarının da etkili olması istenebilir; çok uzaktakilerin değil, yakındakilerin. Hoca bunu en yakın komşu algoritmasına benzetti. 1-NN'in Voronoi bölgeleri çizdirilirse tam bir uzman karışımı gibi davranır: örnek hangi Voronoi bölgesine düşerse oradaki eğitim örneğinin kararı döner (tek bir $w$ 1, diğerleri 0). 3-NN ise o noktaya en yakın üç "uzmanın" kararlarını kullanmak gibidir. Yani bölgeler kesişsin ya da kesişmesin, bir ya da birkaç uzman kullanmak için bir şart yoktur.

### 4.4 Doğrusal birleştirmeden genellemeye

Bu yöntem kararların doğrusal birleştirildiğini gösterir: ağırlıklar toplamı 1 olan bir olasılık dağılımı gibidir; her uzmanın dediğine bakılır, onun ağırlığıyla çarpılır ve toplanır (ağırlıklı oylama, weighted voting). Öğrenicilerin çıkışları $d_1, \dots, d_L$ tek bir sınıf etiketi ya da her sınıfa ait olma olasılıkları olabilir. Her durumda yapılan şey $L$ boyutlu bir uzaydan $y$'ye bir eşleme (mapping) tahmin etmektir. Bir sonraki yöntem bunu genelleştirir.

## 5. İki aşamalı öğrenme (Stacking)

### 5.1 Fikir

Stacking'de öğrenicilerin çıkışları yeni bir veri kümesi olarak görülür. Birinci aşamada örnekleri sınıflandırmayı öğreniriz; ikinci aşamada tekil öğrenicilerin kararlarını nasıl birleştireceğimizi öğreniriz. Bu ikinci problem de yapısal olarak birinci problemle aynıdır: satırlarında örnekler, sütunlarında özellikler olan bir matris vardır. Bu yüzden örneğin birinci aşamada Random Forest kullanılabilir, onun sonuçlarını birleştirmek için de başka bir Random Forest kullanılabilir. Girdileri ve çıktıları farklıdır ama yapı aynıdır.

### 5.2 Meta eğitim kümesi

Orijinal eğitim kümesinde her satır bir örnektir: özellikler ve sınıf. Büyük $N$ tane sınıflandırıcı eğitildiğini düşünelim (küçük $n$ örnek sayısıdır). Her sınıflandırıcı, gelen bir örneğin her sınıfa ait olma olasılıklarını verir. Bu olasılıklar yan yana konunca üst düzey eğitim kümesi (meta training set) oluşur (ekrandan, 00:55:00):

```text
            Classifier_1            Classifier_2           ...   Classifier_N           class
            a      b      c         a      b      c              a      b      c         = a?
örnek 1    P1,a1  P1,b1  P1,c1     P2,a1  P2,b1  P2,c1     ...  PN,a1  PN,b1  PN,c1      1
örnek 2    P1,a2  P1,b2  P1,c2     P2,a2  P2,b2  P2,c2     ...  PN,a2  PN,b2  PN,c2      0
...
örnek n    P1,an  P1,bn  P1,cn     P2,an  P2,bn  P2,cn     ...  PN,an  PN,bn  PN,cn      1
```

Bir sınıflandırıcının bir örnek için verdiği üç olasılığın toplamı 1'dir.

- Yeni kümenin örnek sayısı orijinal eğitim kümesiyle aynıdır.
- Orijinal özellik sayısı ne olursa olsun (100, 10, 2...), yeni kümenin özellik sayısı (sınıflandırıcı sayısı) $\times$ (sınıf sayısı) kadardır, çünkü her sınıflandırıcı her sınıf için bir olasılık verir.
- Çıkış orijinal sınıf olabilir; ya da her sınıf için "a sınıfı mı, değil mi?" biçiminde ayrı ikili problemler tanımlanabilir. Slayttaki ikinci tabloda yalnız her sınıflandırıcının a sınıfına ait olma olasılıkları alınıp "a sınıfı mı?" sorusu için bir sınıflandırıcı kurulur; b ve c için de benzeri yapılıp sonuçlar birleştirilir. Hocaya göre hangisinin seçildiği çok önemli değildir.

Önemli olan, orijinal veri kümesinden yeni bir eğitim kümesi üretildiğini görmektir. Bu kümenin amacı yeni bir $x$'i sınıflandırmak değil, temel öğrenicilerin kararlarını nasıl birleştireceğimizi öğrenmektir. Bu kümede de bir topluluk yöntemi kullanılabilir, onun sonuçlarını birleştirmek için yine başka bir topluluk; böyle sonsuza kadar özyinelemeli giden bir yapı kurulabilir, ama hocaya göre bunun bir anlamı olmaz.

## 6. Yöntemler üzerine sorular: paralelleştirme ve Rotasyon Ormanı

Hoca metotlar sunumunun sonundaki soruları sınıfla birlikte cevapladı (ekrandan, 01:00:00).

### 6.1 Bölgesel öğrenmede demokrasi

Eğitim verisi bölgelere bölünüp kolektif öğrenme uygulanırsa temel öğrenicilerin kararlarını demokrasiyle birleştirmek mantıklı değildir; bu soru uzman karışımında cevaplanmıştı.

### 6.2 Hangi yöntemler paralelleştirilebilir?

Boosting, Bagging, rastgele altuzay (RS), Random Forest (RF) ve Rotation Forest (RotF) için:

- Bagging'de her tekil öğrenici birbirinden bağımsızdır; aynı anda farklı makinelerde ya da aynı makinenin farklı iş parçacıklarında (thread) eğitilebilir. Aynı durum RS, RF ve RotF için de geçerlidir.
- Boosting paralel eğitilemez: bir model eğitilir, sonraki model öncekinin yanlışlarını düzeltmek için ona bakar; öncekini eğitmeden sonrakini eğitemezsiniz.

Hoca bir de "Boosting algoritmasının neresi paralelleştirilebilir?" sorusunu bıraktı: tekil öğreniciler farklı makinelerde çalıştırılamıyor, ama kendi içindeki bir adımı paralelleştirmek mümkün olabilir mi? Bu soru sonraya bırakıldı.

### 6.3 Rotasyon Ormanında KNN

**Soru:** Rotasyon Ormanlarında temel öğrenici olarak KNN kullanımı işe yarar mı, neden karar ağacı kullanılmış? **Cevap:** Rotasyon Ormanı koordinat düzlemini döndürür. Döndürme noktaların birbirine uzaklığını ve birbirine göre konumunu değiştirmez, bu yüzden KNN'in cevapları değişmez; cevaplar değişmeyince topluluğun bir anlamı kalmaz. Karar ağaçları ise (tek değişkenli olanlar) yapısal olarak eksenlere dik karar sınırları çizmek zorundadır. Bu yüzden döndürmeye karşı oldukça hassastırlar; uzay döndürülünce oluşan ağaçlar doğrudan değişir.

## 7. Model kararlarını birleştirme kuralları

Aradan sonra hoca kararların birleştirilmesine geçti. Şimdiye kadar demokrasi usulü, ağırlıklandırma usulü ve birleştirmeyi öğrenme (stacking) görülmüştü. Cevap aranan sorular şunlardır: $L$ modelin kararı nasıl birleştirilmeli? Hepsini mi yoksa bir kısmını mı kullanmak mantıklı? Herkesin kararı eşit mi olmalı?

### 7.1 Örnek ve kurallar

Slayttaki örnekte (Polikar, "Ensemble Based Systems in Decision Making") 5 sınıflandırıcı ve 3 sınıf vardır (ekrandan, 01:25:00). Her sınıflandırıcının bir başarı ağırlığı vardır (toplamları 1 olacak şekilde normalize edilmiş) ve test örneği için her sınıfa ait olma olasılıklarını verir:

| | Classifier 1 | Classifier 2 | Classifier 3 | Classifier 4 | Classifier 5 |
|---|---|---|---|---|---|
| Ağırlık | 0.30 | 0.25 | 0.20 | 0.10 | 0.15 |
| $C_1$ | 0.85 | 0.3 | 0.2 | 0.1 | 0.1 |
| $C_2$ | 0.01 | 0.5 | 0.6 | 0.7 | 0.1 |
| $C_3$ | 0.14 | 0.2 | 0.2 | 0.2 | 0.8 |

Örneğin Classifier 2, örneğin %30 olasılıkla $C_1$'den, %50 olasılıkla $C_2$'den, %20 olasılıkla $C_3$'ten olduğunu söyler.

- **Product Rule:** bir sınıfın olasılığı, bütün sınıflandırıcıların o sınıf için verdiği olasılıkların çarpımıdır. $C_1$ için $0.85 \times 0.3 \times 0.2 \times 0.1 \times 0.1$.
- **Sum Rule ve Mean Rule:** olasılıkların toplamı ve ortalaması.
- **Max Rule:** bir sınıfın olasılığı, o sınıf için verilen olasılıkların en büyüğüdür. $C_1$ için 0.85, 0.3, 0.2, 0.1, 0.1 içinden 0.85; $C_2$ için 0.01, 0.5, 0.6, 0.7, 0.1 içinden 0.7; $C_3$ için 0.8.
- **Median ve Minimum Rule:** ortanca ve en küçük değer.
- **Weighted Average:** her sınıflandırıcının olasılığı ağırlığıyla çarpılıp toplanır: $C_1$ için $0.85 \times 0.30 + 0.3 \times 0.25 + 0.2 \times 0.20 + 0.1 \times 0.10 + 0.1 \times 0.15$.
- **Majority Voting:** her sınıflandırıcı en yüksek olasılık verdiği sınıfa oy verir. Classifier 1 $C_1$, Classifier 2, 3 ve 4 $C_2$, Classifier 5 $C_3$ der; $C_2$ üç oyla kazanır.
- **Weighted Majority Voting:** oylar sınıflandırıcı ağırlıklarıyla çarpılır (Classifier 1'in oyu 0.30, Classifier 2'ninki 0.25 ...).
- **Borda Count:** slaytta yer aldı, derste ayrıca anlatılmadı.

Slayttaki sonuçlar (ekrandan, 01:25:00), kalın olanlar kazanan sınıf:

| Kural | $C_1$ | $C_2$ | $C_3$ |
|---|---|---|---|
| Product | **0.0179** | 0.00021 | 0.0009 |
| Sum | 1.55 | **1.91** | 1.54 |
| Mean | 0.310 | **0.382** | 0.308 |
| Max | **0.85** | 0.7 | 0.8 |
| Median | 0.2 | **0.5** | 0.2 |
| Minimum | 0.1 | 0.01 | **0.14** |
| Weighted Average | **0.395** | 0.333 | 0.272 |
| Majority Voting | 1 | **3** | 1 oy |
| Weighted Majority Voting | 0.3 | **0.55** | 0.15 oy |
| Borda Count | 5 | **6** | 4 oy |

Sum, Mean, Max, Median, Minimum, Weighted Average, Majority Voting ve Weighted Majority Voting değerleri python ile doğrulandı.

> **Ders sonrası not:** Slayt Product kuralında $C_1$ için 0.0179 verir ve hoca bunu $0.85 \times 0.3 \times 0.2 \times 0.1 \times 0.1$ diye açıkladı. Bu çarpım 0.00051'dir (python ile doğrulandı); 0.0179 yanlıştır. $C_2$ (0.00021) ve $C_3$ (0.000896 ≈ 0.0009) doğrudur. Doğru değerlerle Product kuralının kazananı $C_1$ değil $C_3$'tür.

> **Ders sonrası not:** Borda Count değerleri derste anlatılmadı. Standart puanlamayla (her sınıflandırıcıda 1. sıraya 2, 2. sıraya 1, 3. sıraya 0 puan, eşitlikte puanlar paylaştırılarak) $C_1$: 4, $C_2$: 6.5, $C_3$: 4.5 çıkar (python ile hesaplandı). Slayttaki 5, 6, 4 büyük olasılıkla eşitliklerin farklı bir kuralla çözülmesinden kaynaklanır; iki hesapta da kazanan $C_2$'dir.

Aynı veriyle kurala göre farklı sınıflar kazanabilir. Hocaya göre bu kurallardan birinin diğerlerinden çok daha iyi olduğunu genel olarak söylemek kolay değildir.

### 7.2 Hangi sınıflandırıcılar sınıf olasılığı verir?

Olasılık tabanlı kuralları uygulamak için sınıflandırıcının bir test örneğinin her sınıfa ait olma olasılığını verebilmesi gerekir. Hoca bunu birkaç algoritma için sordu:

- **1-NN:** vermez. Yalnız en yakın örneğin sınıfını döndürür.
- **10-NN:** verir. En yakın 10 örneğin sınıf dağılımına bakılarak her sınıfa ait olma olasılığı bulunur.
- **Karar ağacı:** önce örneğin düştüğü yaprak bulunur. Yaprak eğitim örnekleri açısından safsa (hep aynı sınıf) olasılık hakkında bir şey söylenemez; o zaman yeterince yukarı çıkılır. Yukarı çıkmak, örneğe yakın örnekleri içeren daha geniş bir bölgenin eğitim örneklerinin sınıf dağılımına bakmak demektir.

**Soru:** Bir üst düğüme çıkınca diğer sınıfların olasılığı nasıl üretilir? **Cevap:** Örneğin üst düğüm "5. özellik 2.73'ten büyük mü?" diye soruyor olsun; büyükse bir tarafa, değilse öbür tarafa aktarır. Bu düğüme gelmiş olan bütün eğitim örnekleri onun altına dağılır. O düğüme gelen bütün eğitim örneklerinin sınıf dağılımına bakılır.

- **Yapay sinir ağı:** Bir öğrenci çıkışta sigmoid kullanmayı önerdi; hoca sigmoidin tek bir değer verdiğini, her sınıfa ait olasılığı söylemediğini belirtti. Mimari olarak sınıf sayısı kadar çıkış nöronu olmalı, her çıkış bir sınıfı temsil etmelidir. Bu çıkışlar toplamlarına bölünerek normalize edilip toplamı 1 yapılabilir. Öğrencinin hatırlamaya çalıştığı yöntemin adı softmax'tır.

## 8. Bir deney: budama ve ağırlıklandırma

### 8.1 Deney tasarımı

Hoca, rastgele altuzayı anlatan bir sunumda ağaçların başarılarına göre sıralanıp bir kısmının alındığının gösterildiğini hatırlattı. Bunu kendi deneyimiyle sınadı (ekrandan, 01:30:00):

- Validasyon kümesindeki en başarısızları budamak.
- Kararları validasyon kümesindeki başarıya göre ağırlıklandırmak.

> **Hocanın vurgusu:** Birinin bir sunumda bir şeyi söylemiş olması onu doğru kabul etmek için her zaman yeterli değildir. Birinci elden gözlem yapmak, kendiniz deneyimlemek, öğrenmenin en iyi yollarından biridir.

Çalışma UCI'deki 26 veri kümesi üzerinde, 5x2 çapraz doğrulamayla ve her yöntemde 100 ağaç üretilerek yapıldı. Yöntem adındaki $(100, k)$, 100 ağaç üretilip en başarılı $k$ tanesinin demokrasiyle birleştirildiğini gösterir; "ağırlıklandırılmış" 100 ağacın hepsinin tekil başarılarına göre ağırlıklandırıldığını gösterir.

### 8.2 Ortalama başarı sırası

16 algoritma her veri kümesinde başarıya göre sıralanır; en başarılı 1., ikinci 2. olur. Bu 26 veri kümesi için tekrarlanır ve her algoritmanın sıralarının ortalaması alınır. Değer ne kadar küçükse algoritma o kadar başarılıdır. Tabloda 1'e yakın bir değer yoktur, yani hiçbir algoritma bütün veri kümelerinde en iyi değildir; en iyiler 5-6 civarındadır.

Sonuçlar (ekrandan, 01:35:00):

| Algoritma | Ortalama başarı sırası |
|---|---|
| Tek ağaç (CART) | 14.9231 |
| Random forest (100, 25) | 8.3077 |
| Random forest (100, 50) | 6.8846 |
| Random forest (100, 75) | 6.7692 |
| Random forest (100, 100) orijinal algoritma | 5.6154 |
| Random forest (100, 100) ağırlıklandırılmış | 6.6154 |
| Bagging (100, 25) | 12.2308 |
| Bagging (100, 50) | 10.9231 |
| Bagging (100, 75) | 10.4231 |
| Bagging (100, 100) orijinal algoritma | 9.1538 |
| Bagging (100, 100) ağırlıklandırılmış | 9.2692 |
| Rastgele altuzay (100, 25) | 9.5769 |
| Rastgele altuzay (100, 50) | 7.1923 |
| Rastgele altuzay (100, 75) | 6.5769 |
| Rastgele altuzay (100, 100) orijinal algoritma | 6.0000 |
| Rastgele altuzay (100, 100) ağırlıklandırılmış | 5.5385 |

### 8.3 İstatistiksel anlamlılık: Nemenyi testi

Öğrencilerin ödevde kullandığı t-testi iki algoritmayı doğrudan karşılaştırmak içindir. Çok sayıda algoritmayı tek seferde sıralamak için Nemenyi testi kullanılır. Anlamlı fark, veri kümesi ve algoritma sayısına bağlıdır. Slaytta (ekrandan, 01:35:00):

$$\text{Anlamlı fark} = 3.426 \sqrt{\frac{16 \cdot 17}{6 \cdot 26}} = 4.522$$

Python ile hesaplanınca 4.5239 çıkar. Yani iki algoritmanın ortalama sıraları arasında yaklaşık 4.5'lik fark varsa aralarında anlamlı bir fark vardır. Testin ayrıntısına derste girilmedi.

> **Ek bilgi (derste anlatılmadı):** Nemenyi testinde kritik fark $CD = q_\alpha \sqrt{k(k+1)/(6N)}$ biçimindedir; $k$ algoritma sayısı, $N$ veri kümesi sayısıdır. Buradaki formülde $k=16$, $N=26$ ve $q_\alpha = 3.426$'dır.

### 8.4 Yorumlar

- Kabaca bütün topluluk algoritmaları tek bir ağaçtan daha başarılıdır.
- Orijinal algoritmalarda iyiden kötüye sıra: Random Forest (5.6154), rastgele altuzay (6.0000), Bagging (9.1538).

Hoca temel öğrenicilerin eriştiği bilgi üzerine de yorum yaptı. Bagging'deki karar ağaçlarının her düğümü örneklerin bir kısmına (hoca "%66.6'sı diyelim" dedi) ama bütün özelliklere erişir ve bütün özellikler içinden seçim yapar; en fazla bilgiye onlar sahiptir. Random Forest'ta her düğüm rastgele küçük bir özellik altkümesine bakar, ama her düğümde farklı seçim yapıldığı için ağacın tamamında bütün özelliklerin yer alması mümkündür. Rastgele altuzayda ise her ağaç baştan seçilen $d/2$ özellikle kurulur; bütün özelliklere erişemez. Sonuç olarak en çok özelliğe Bagging, orta düzeyde Random Forest, en az rastgele altuzay erişir. Buna göre üyelerinin kararları arasında en çok farklılık olan (çeşitliliği en yüksek) algoritma rastgele altuzaydır.

> **Ders sonrası not:** Hoca Bagging'deki ağaçların örneklerin yaklaşık %66.6'sına eriştiğini "diyelim" diyerek yuvarlak söyledi. Yerine koyarak $n$ içinden $n$ örnek seçildiğinde farklı örneklerin beklenen oranı yaklaşık $1 - e^{-1} \approx \%63.2$'dir (ders 6'da görüldü).

**Ağırlıklandırma:** Bagging'de orijinal (9.1538) ile ağırlıklandırılmış (9.2692) arasında çok küçük bir fark vardır. Random Forest'ta yaklaşık 1'lik bir fark vardır, orijinal daha iyidir (5.6154'e karşı 6.6154). Rastgele altuzayda ise ağırlıklandırılmış daha iyidir (5.5385'e karşı 6.0000, yaklaşık yarımlık fark). Ağırlıklandırmanın iyileştirdiği tek yer rastgele altuzaydır. Kararlar birbirine yakınsa ağırlıklandırmanın pek anlamı yoktur: bütün ağırlıklar birbirine eşitse ağırlıklandırma demokrasiyle aynıdır. Bagging'de kararlar birbirine çok yakın olduğu için fark çıkmaz; kararların en farklı olduğu rastgele altuzayda ağırlıklandırma fark yaratır.

**Budama:** Üç yöntemde de 100 ağacın hepsini kullanmaktan 75, 50 ve 25 ağaca inildikçe ortalama sıra hep kötüleşir: Random Forest'ta 5.6154 → 6.7692 → 6.8846 → 8.3077, Bagging'de 9.1538 → 10.4231 → 10.9231 → 12.2308, rastgele altuzayda 6.0000 → 6.5769 → 7.1923 → 9.5769. Budama topluluktaki tekil öğrenicilerin ortalama başarısını artırır, ama çeşitliliği azaltır.

> **Hocanın vurgusu:** Herkesin aynı şeyi söylediği bir ortamda aslında tek bir kişi vardır. Herkes aynı şeyi söyleyince işe yarar bir sonuç elde edilemez.

## 9. Algoritmaların karşılaştırılması

Hoca karşılaştırma sunumunun Weka'da istatistiksel anlamlılık analizinin nasıl yapılacağını gösterdiğini, istenirse oradan bakılabileceğini söyledi. Weka'da yalnız başarıya göre değil, eğitim ve test süreleri gibi herhangi bir ölçüte göre de karşılaştırma yapılabilir. Asıl gösterdiği sonuçlardır.

### 9.1 Ortalama sıra ve sıralama testi sayısı

36 UCI veri kümesinde 11 tekil ve 12 topluluk algoritması çalıştırıldı; topluluklarda hep 100 temel öğrenici kullanıldı. Tekil algoritmalar arasında SVM, C4.5 (J48), Best-First Tree, CART, Random Tree, 1-NN ve Naive Bayes gibi algoritmalar vardır.

İki ölçüt kullanıldı:

- **Average Rank:** önceki deneydeki gibi ortalama sıra; küçük olması iyidir.
- **Ranking Test Count:** her algoritma diğer her algoritmayla istatistiksel olarak karşılaştırılır; yenme sayısından yenilme sayısı çıkarılır. Büyük olması iyidir.

Sonuçlar (ekrandan, 01:45:00):

| Tekil | Average Rank | Ranking Test Count | | Topluluk | Average Rank | Ranking Test Count |
|---|---|---|---|---|---|---|
| ZR | 21.9130 | -719 | | ADB | 13.5652 | -246 |
| NB | 12.7391 | -148 | | BG | 8.5217 | 141 |
| SMO | 10.2174 | -14 | | RNDF | 5.3913 | 227 |
| KNN | 16.4348 | -133 | | ROTF | 4.1304 | 289 |
| J48 | 14.2174 | 24 | | DG | 12.5652 | -127 |
| FT | 12.4348 | 50 | | DEC | 7.8261 | 176 |
| RT | 18.5217 | -135 | | END | 11.5652 | 126 |
| REPT | 15.3478 | -4 | | LB | 8.3043 | 179 |
| CART | 13.1304 | 40 | | MB | 13.3913 | -294 |
| BFT | 13.6957 | 36 | | RC | 6.9130 | 228 |
| LADT | 10.8696 | 123 | | RS | 10.2609 | 120 |
| NBT | 14.0435 | 61 | | | | |

- En düşük ortalama sıra Rotation Forest (4.1304) ve Random Forest (5.3913). En yüksek yenme-yenilme sayısı Rotation Forest (289), sonra Random Committee (228) ve Random Forest (227).
- Tekil algoritmalar içinde SVM (SMO) ve LADT (alternatif karar ağacı) iyidir; hoca model ağaçlarının ayrıntısına girmedi.
- Genel olarak topluluklar tekil algoritmalardan daha başarılıdır.
- Nemenyi testine göre bu deneyde anlamlı fark yaklaşık 5.8'dir.

> **Ders sonrası not:** Hoca Random Forest'ın ortalama sırasını sözlü olarak 5.33 diye okudu; tablodaki değer 5.3913'tür.

### 9.2 Hız

Hız da önemli bir ölçüttür. 36 veri kümesinin en büyük üçünde (letter, mushroom, splice) eğitim ve test süreleri saniye cinsinden ölçüldü. Seçilmiş değerler (eğitim/test, ekrandan, 01:50:00):

| Algoritma | letter | mushroom | splice |
|---|---|---|---|
| ZR | 0.01/0.09 | 0.00/0.03 | 0.00/0.01 |
| NB | 0.09/3.46 | 0.20/1.02 | 0.16/1.25 |
| J48 | 1.84/0.17 | 0.65/0.03 | 0.96/0.01 |
| RT | 0.29/0.06 | 0.07/0.04 | 0.11/0.02 |
| BG | 36.98/1.13 | 30.86/0.06 | 55.49/0.04 |
| RNDF | 25.94/2.62 | 6.66/0.20 | 7.90/0.27 |
| ROTF | 28?.57/69.86 | 250.6/348.7 | 324.2/442.7 |

<!-- BELİRSİZ: ROTF'nin letter eğitim süresinin bir hanesi karede imleçle örtülü; 28?.57 okunuyor. -->

- Rotation Forest hem eğitimde hem testte Random Forest'tan çok daha uzun sürer.
- Naive Bayes daha hızlıdır. Zero Rule hiçbir şey öğrenmez, doğrudan tahmin basar.
- Random Forest'ın verimi: letter verisinde tek bir J48 1.84 s'de eğitilirken 100 ağaçlı Random Forest 25.94 s sürer. İlişki doğrusal olsaydı 184 s sürmesi gerekirdi. Bagging ise (J48'lerle) 36.98 s sürer.

**Soru:** Random Forest 100 ağacı neden 100 J48'den çok daha kısa sürede üretiyor? **Cevap:** Bir öğrenci her düğümde özelliklerin logaritması kadarının seçildiğini söyledi. Hoca onayladı: her düğümde çok az sayıda kontrol yapılır; ağaç çok büyük olsa da az kontrol nedeniyle çok hızlı çalışır. Random Forest'ın ağacı gibi ağaç üreten Random Tree (RT) zaten çok daha hızlıdır, ama tekil olduğu için başarısı düşüktür; 100'ü birleştirilince başarı yükselir.

Hoca, buradaki Rotation Forest'ın Weka gerçeklemesi olduğunu ve iyi yazılmadığını belirtti. Kendisi MATLAB'de gerçeklediğinde Rotation Forest, Random Forest'tan yalnız iki-üç kat yavaş çalışmıştı; buradaki on, yirmi, kırk kat yavaşlık algoritmadan değil gerçeklemeden kaynaklanır.

### 9.3 Seçim

Bu tür (UCI benzeri) veri kümelerinde, birinci ölçüt doğruluksa Rotation Forest seçmek iyidir; istatistiksel olarak Random Forest'tan çok büyük farkı yoktur. Doğruluk ve hız birlikte önemliyse Random Forest daha mantıklıdır.

## 10. Algoritmaların ve veri kümelerinin benzerliği

### 10.1 Algoritmaların benzerliği

Satırlarında algoritmalar, sütunlarında veri kümeleri olan bir matris düşünülür; $(i, j)$ elemanı $i$. algoritmanın $j$. veri kümesindeki performansıdır. Böylece her algoritma 36 boyutlu uzayda bir noktadır. Bu matris hiyerarşik kümelemeyle kümelenir ve algoritmaların performans açısından birbirine benzerliği bulunur. Dendrogramda ne kadar yakında birleşen iki algoritma o kadar benzerdir.

Sonuçta topluluk algoritmaları bir grupta, tekil ağaç algoritmaları başka bir grupta toplandı. MultiBoost ile AdaBoost birbirine yakın çıktı; bunlar zaten aynı algoritmanın sürümleridir. Bazı eşleşmeler (Random Tree ile KNN gibi) ancak dendrogramın üst seviyelerinde birleşir ve anlamlı bir yakınlık göstermez. Farklı topluluk algoritmalarının ve farklı ağaç algoritmalarının kendi aralarında yakın çıkması, benzer fikirlerin benzer sonuçlara yol açabileceğini destekler.

### 10.2 Veri kümelerinin benzerliği

**Soru:** Matris çevrilip satırlara veri kümeleri, sütunlara algoritmalar konursa ne kümelenir? **Cevap:** Bir öğrenci veri kümelerinin benzerliğinin bulunacağını söyledi; hoca onayladı.

Slayttaki dendrogramda her veri kümesinin adından sonra sırasıyla özellik sayısı, sınıf sayısı ve örnek sayısı yazar (ör. primary-tumor-24-11-302, abalone-11-19-4153) (ekrandan, 01:55:00). Gözlemler:

- Veri kümeleri genel olarak sınıf sayılarına göre gruplanır: iki sınıflı veri kümeleri bir grup, daha fazla sınıflı olanlar başka bir grup oluşturur (slaytta mavi dikdörtgen).
- primary-tumor ve abalone tek başlarına kalır. Bunlar diğerlerine göre oldukça zor problemlerdir; başarı oranları düşüktür.
- En benzer veri kümesi çiftleri benzer örnek, özellik ve sınıf sayılarına sahiptir (slaytta kırmızı dikdörtgenler; ör. sick-32-2-3772 ile hypothyroid-32-3-3770, kr-vs-kp-40-2-3196 ile d159-33-2-7182).
- Özellik ve örnek sayısına göre genel bir şey söylemek kolay değildir.

**Soru:** Benzerlik hesabı için hangi metrik kullanıldı? **Cevap:** Algoritmaların performansları: her veri kümesinin 23 algoritmadaki performansı boyutları oluşturur; uzaklık olarak Öklid uzaklığı kullanıldı.

## 11. Kolektif regresyon ağaçları

Regresyon dönemin başında görülmüştü; burada yeni olan kısım regresyon ağaçlarıdır. Karar ağaçları anlatılırken biraz değinilmişti, ama görsel olarak pek görülmemişti.

Tek girdi ve tek sayısal çıkışlı bir regresyon ağacında eğitim örnekleri ve ağacın tahminleri birlikte çizildiğinde, ağaç derinleştikçe tahminlerin eğitim örneklerine daha çok uyduğu görülür. Ağaç yeterince büyütülürse bütün örneklerin üzerinden geçen bir hâle getirilebilir. Sınıflandırma ağacında yapraklarda sınıflar yazarken, regresyon ağacında yapraklarda sayılar yazar. En basit hâliyle bir yaprağın değeri, o yaprağa düşen eğitim örneklerinin çıkışlarının ortalamasıdır; bunun karesel hatayı en küçük yaptığından daha önce bahsedilmişti.

Slayttaki "Boosted Decision Tree Regression" grafiğinde (ekrandan, 02:00:00) tek bir ağaç (n_estimators=1, yeşil) basamaklı bir çıkış verir; 300 ağaçlı topluluk (n_estimators=300, kırmızı) eğitim örneklerini daha yumuşak ve başarılı bir eğriyle izler. Sınıflandırmadaki yapı regresyonda da aynen geçerlidir.

Regresyon için topluluk kurmak sınıflandırmadan bile kolaydır: tekil öğrenicilerin çıkışları toplanıp ortalaması alınabilir, sınıf olasılıklarına bakmaya gerek yoktur. Mimari açıdan bir sınıflandırma ve bir regresyon topluluğu arasında fark yoktur: tekil öğreniciler karar verir, kararlar birleştirilir. Kümelemede ise işler değişir.

## 12. Kolektif kümeleme

### 12.1 K-means ve DBSCAN

Hoca kümeleme algoritmalarından en temsil edici iki tanesinin K-means ve DBSCAN olduğunu söyledi. Sınıftan DBSCAN'i duyan çıkmadı. DBSCAN yoğunluk tabanlı bir algoritmadır.

- K-means'e iki küme bulması söylenirse küme merkezleri etrafında iki küme bulur.
- Bazen içteki halkanın bir küme, dıştaki halkanın başka bir küme olması istenebilir; veride manifoldlar olabilir. DBSCAN yoğun bölgeleri birleştirerek bu tür yapıları ayırabilir.
- DBSCAN'e küme sayısı doğrudan verilemez; "bana 5 küme üret" denemez. Birbirine yeterince yakın olan noktalar aynı kümeye girer; bu yakınlık toleransı bir hiperparametre olarak verilir. Tolerans çok büyükse her şey tek küme olur, çok küçükse bir küme kendi içinde parçalara ayrılır. Küme sayısı bu parametre üzerinden dolaylı olarak artırılıp azaltılabilir.

### 12.2 Temel kümeleyiciler

Kolektif kümelemede her temel kümeleyici (ekrandan, 02:05:00):

- farklı bir kümeleme algoritması olabilir,
- aynı kümeleme algoritması ile farklı bir özellik altkümesi olabilir.

Örnek altkümesi kullanılamaz, çünkü her örneğin hangi kümeye düşeceği bulunacaktır; örnekler sabit kalmak zorundadır.

### 12.3 Sorun: kararların birleştirilmesi

Sınıflandırmada bütün tekil öğreniciler için "birinci sınıf" aynı şeydir. Kümelemede ise:

- Küme sayıları farklı olabilir (ör. farklı parametreli DBSCAN'ler farklı sayıda küme bulur).
- Küme etiketleri tutarlı değildir. Bir DBSCAN dıştan başlayıp dış halkaya "birinci küme" der; başka bir çalıştırma içteki bir noktadan başlayıp iç halkaya "birinci küme" der. İkisi aynı kümelemeyi yapmıştır ama etiketler birbirine karşılık gelmez; "A" ya da "1" demenin bir anlamı yoktur.

### 12.4 Çözüm: birlikte bulunma sayısı

Çözüm, örneklerin aynı kümede birlikte bulundukları sonuç sayısını kullanmaktır. Hocanın örneğinde 7 örnek ve 3 kümeleme algoritması sonucu (a, b, c) vardır (derste sözlü, 02:06:39):

```text
a: {1, 2, 3}  {4, 5}     {6, 7}
b: {1, 2}     {3, 4}     {5, 6, 7}
c: {1, 2}     {3, 4, 5}  {6, 7}
```

$d$, her örnek çiftinin kaç kez aynı kümede yer aldığıdır. 1 ile 2 üç sonuçta da aynı kümededir. 3 ile 4, a'da farklı, b'de ve c'de aynı kümededir: iki kez. 6 ile 7 üç kez aynı kümededir. Bütün çiftler için (ara adım eklendi, python ile hesaplandı):

```text
     1  2  3  4  5  6  7
1    3  3  1  0  0  0  0
2    3  3  1  0  0  0  0
3    1  1  3  2  1  0  0
4    0  0  2  3  2  0  0
5    0  0  1  2  3  1  1
6    0  0  0  0  1  3  3
7    0  0  0  0  1  3  3
```

İki örnek ne kadar çok kez birlikte bulunduysa o kadar benzerdir; bu sayılar örnekler arası bir benzerlik matrisi oluşturur (ekrandan, 02:10:00). Bu matris üzerinde hiyerarşik kümeleme yapılarak sonuç kümeleme bulunur ve istenen sayıda kümeye inilebilir.

Hiyerarşik kümeleme için örneklerin gerçek koordinatları gerekmez; her örneğin diğer örneklere uzaklıkları (ya da benzerlikleri) yeterlidir, çünkü algoritma en yakınları birleştirerek ilerler. Böylece farklı kümeleme algoritmalarının sonuçlarını birleştirmek mümkün hâle gelir. Bütün bunların sebebi, sınıflandırmadan farklı olarak, aynı kümelemeyi yapmış iki kümeleyicinin kümelere tamamen farklı etiketler vermiş olabilmesidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): Rastgele altuzay yönteminde $d/x$ ifadesindeki $x$'in değişimi tekil öğrenici başarısını ve çeşitliliği nasıl etkiler?

> **Çözüm:** $x$ büyükse (az özellik seçilirse) tekil öğrenici başarısı düşer, çeşitlilik artar. $x$ küçükse tekil başarı artar, çeşitlilik azalır (ekrandan, 00:15:00). Örnek sayısı değişmez; değişen seçilen özellik sayısıdır.

**Soru 2** (derste sözlü, 00:10:36): Tekil öğrenicilerin başarısını değiştirmeden çeşitlilik artırılabilir mi? Yarı rastgele altuzay bunu nasıl yapar?

> **Çözüm:** Evet. Öğreniciler çiftler hâlinde üretilir: birincisi $d/x$ özelliği rastgele seçer, ikincisi geri kalanları alır (4 özellikte "1 3" ve "2 4"). Her öğrenici aynı sayıda özellik kullandığı için tekil başarı sabit kalır; eşler ortak özellik içermediği için kararları farklılaşır ve çeşitlilik artar.

**Soru 3** (derste sözlü, 00:25:18): Yarı rastgele altuzayda 4 öğrenicide karar benzerliği matrisinin 6 değerinden 2'si, 6 öğrenicide 15 değerinden 3'ü azalıyor. Öğrenici sayısı 100 olursa ne olur?

> **Çözüm:** Değerlerin çok küçük bir kısmı azalır; yöntemin etkisi topluluk büyüdükçe azalır. Çift sayıda $L$ öğrenicide oran $(L/2) / (L(L-1)/2) = 1/(L-1)$'dir; $L = 100$ için yaklaşık %1 (derste verilmedi, ara adım eklendi).

**Soru 4** (derste sözlü, 00:30:03): Bir teoriye göre beklenen sonuç deneylerde görülmüyorsa bunun olası sebepleri nelerdir?

> **Çözüm:** Deney yanlış yapılmış olabilir (önce deney tekrarlanır); teori yanlış kurulmuş olabilir; ya da teorinin varsayımları deneydeki veri kümelerine uymuyor olabilir. Sonuncusu teorinin yanlışlığı değil kısıtlılığıdır; varsayımlar genelleştirilerek teori daha çok duruma uygulanabilir.

**Soru 5** (ekrandan, 01:00:00): Eğitim datasını bölgelere bölüp kolektif öğrenme uygularsak, temel öğrenicilerin kararlarını demokrasi ile birleştirmek mantıklı olur mu?

> **Çözüm:** Olmaz. Bir bölgede uzmanlaşmış öğrenicinin başka bir bölgeden gelen örnek için kararının pek anlamı yoktur. Kararlar, örneğin bölgesine göre gating fonksiyonunun ürettiği ağırlıklarla birleştirilmelidir.

**Soru 6** (ekrandan, 01:00:00): Boosting, Bagging, RS, RF, RotF hangileri paralelleştirilebilir?

> **Çözüm:** Bagging, RS, RF ve RotF'de tekil öğreniciler birbirinden bağımsız olduğu için farklı makinelerde ya da iş parçacıklarında paralel eğitilebilir. Boosting'de her öğrenici bir öncekinin hatalarına göre eğitildiği için öncekini eğitmeden sonraki eğitilemez.

**Soru 7** (ekrandan, 01:00:00): Rotasyon Ormanlarında temel öğrenici olarak KNN kullanımı işe yarar mı? Neden karar ağacı kullanılmış?

> **Çözüm:** İşe yaramaz. Döndürme noktalar arası uzaklıkları değiştirmez, KNN'in kararları aynı kalır ve topluluk anlamsızlaşır. Tek değişkenli karar ağaçları eksenlere dik sınırlar çizdiği için döndürmeye duyarlıdır; her döndürme farklı bir ağaç üretir.

**Soru 8** (ekrandan, 01:00:00): Boosting algoritmasının neresi paralelleştirilebilir?

> **Çözüm (derste verilmedi):** Turlar sıralı kalmak zorundadır, ama her turun kendi içindeki işler paralelleştirilebilir. Örneklerin ağırlıklı hatasının hesaplanması ve ağırlıkların güncellenmesi örnekler üzerinde birbirinden bağımsız işlemlerdir. Temel öğrenici karar ağacıysa, bir düğümde farklı özellikler için en iyi bölmenin aranması da paralel yapılabilir.

**Soru 9** (ekrandan, 01:25:00): Ağırlıkları 0.30, 0.25, 0.20, 0.10, 0.15 olan 5 sınıflandırıcının sınıf olasılıkları (0.85, 0.01, 0.14), (0.3, 0.5, 0.2), (0.2, 0.6, 0.2), (0.1, 0.7, 0.2), (0.1, 0.1, 0.8) olsun. Max, Weighted Average ve Majority Voting kurallarına göre hangi sınıf seçilir?

> **Çözüm:** Max: $C_1$ 0.85, $C_2$ 0.7, $C_3$ 0.8 → $C_1$. Weighted Average: $C_1 = 0.85 \cdot 0.30 + 0.3 \cdot 0.25 + 0.2 \cdot 0.20 + 0.1 \cdot 0.10 + 0.1 \cdot 0.15 = 0.395$, $C_2 = 0.333$, $C_3 = 0.272$ → $C_1$. Majority Voting: sınıflandırıcılar sırasıyla $C_1, C_2, C_2, C_2, C_3$ der → $C_2$ (3 oy). Aynı veriyle kurala göre farklı sınıflar seçilir (python ile doğrulandı).

**Soru 10** (derste sözlü, 01:25:03): 1-NN, 10-NN, karar ağacı ve yapay sinir ağı bir test örneğinin her sınıfa ait olma olasılıklarını verebilir mi?

> **Çözüm:** 1-NN vermez. 10-NN, en yakın 10 örneğin sınıf dağılımıyla verir. Karar ağacı, örneğin düştüğü yaprağın (yaprak safsa yeterince yukarıdaki bir düğümün) eğitim örneklerinin sınıf dağılımıyla verir. YSA, sınıf sayısı kadar çıkış nöronu ve çıkışların normalize edilmesiyle (softmax) verir; tek bir sigmoid çıkış yetmez.

**Soru 11** (derste sözlü, 01:48:46): letter verisinde tek bir J48 1.84 s'de eğitiliyor. 100 ağaçlı Random Forest'ın 184 s yerine 25.94 s sürmesinin sebebi nedir?

> **Çözüm:** Random Forest her düğümde özelliklerin yalnız küçük bir rastgele altkümesine bakar; ağaç büyük olsa da düğüm başına çok az kontrol yapıldığı için eğitim çok hızlıdır.

**Soru 12** (derste sözlü, 02:06:39): Üç kümeleme sonucu a = {1,2,3}{4,5}{6,7}, b = {1,2}{3,4}{5,6,7}, c = {1,2}{3,4,5}{6,7} olsun. Kümeleme sonuçları neden doğrudan oylamayla birleştirilemez ve nasıl birleştirilir?

> **Çözüm:** Küme sayıları ve etiketleri kümeleyiciden kümeleyiciye farklıdır; aynı kümelemeyi yapan iki kümeleyici farklı etiketler verebilir. Bu yüzden her örnek çiftinin kaç sonuçta aynı kümede bulunduğu sayılır: 1-2 ve 6-7 için 3, 3-4 ve 4-5 için 2, 3-5 için 1 (tam matris 12.4'te). Bu benzerlik matrisi üzerinde hiyerarşik kümeleme yapılarak istenen sayıda küme elde edilir.

## Dersin Toparlaması

Ders, rastgele altuzay yönteminin bir iyileştirmesi olan yarı rastgele altuzaylarla başladı. Öğrenicileri "rastgele seç, eşine kalanları ver" biçiminde çiftler hâlinde üretmek tekil öğrenici başarısını değiştirmeden çeşitliliği artırır. Karar benzerliği matrisi üzerinden bu kazancın topluluk büyüdükçe azaldığı, hiç deney yapılmadan gösterildi; bu, teorik çalışmanın değeri ve varsayımların rolü üzerine bir tartışmaya bağlandı. Ardından farklı eğitim kümeleri üretmenin son yöntemi olan uzman karışımı (gating ile örneğe bağlı ağırlıklar) ve öğrenici çıkışlarını yeni bir veri kümesi olarak gören stacking anlatıldı. Paralelleştirme ve Rotasyon Ormanında temel öğrenici seçimi soruları cevaplandı.

İkinci bölümde kararları birleştirme kuralları (Product, Sum, Max, oylama vb.) bir örnek üzerinde gösterildi ve bu kuralların sınıf olasılığı gerektirdiği vurgulandı. Hocanın deneyinde budama hep kötüleştirdi; ağırlıklandırma yalnız kararları en farklı olan rastgele altuzayda işe yaradı. 36 veri kümesindeki karşılaştırmada Rotation Forest en doğru, Random Forest doğruluk ve hız birlikte düşünüldüğünde en mantıklı seçim çıktı. Son olarak kolektif regresyon ağaçları ve etiket tutarsızlığını birlikte bulunma matrisiyle aşan kolektif kümeleme işlendi. Bir sonraki derste boosting ile devam edilecek, ardından yapay sinir ağlarında kolektif öğrenmeye geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
