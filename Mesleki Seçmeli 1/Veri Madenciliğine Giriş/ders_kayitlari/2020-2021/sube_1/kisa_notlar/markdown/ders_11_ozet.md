# Ders 11 Çalışma Özeti

<!-- Kaynak: ders kaydı altyazısı ve 5 dakikada bir alınmış ekran kareleri. Hoca dersin ilk yarısını İngilizce, ikinci yarısını Türkçe anlatmıştır; altyazıda çok sayıda Whisper tekrar halüsinasyonu vardır, bunlar nota alınmamıştır. -->

## Genel Konular

- Dersin yeri: birliktelik kuralları ve market sepeti analizi
  - Dönem başında gösterilen veri madenciliği stratejileri şemasında üç başlık vardı: denetimli öğrenme (sınıflama), denetimsiz kümeleme ve market sepeti analizi. Sınıflama ve kümeleme bitti; bu derste üçüncü başlığa, birliktelik kurallarına (association rules) geçildi.
  - Birliktelik kuralları denetimsiz öğrenme altında yer alır. Amaç verideki en sık görülen yerel örüntüleri (local patterns) bulmaktır.
  - E-ticarette ve marketlerde her gün çok sayıda satın alma işlemi (transaction) kaydedilir. Bu ham veri (müşteri kayıtları) madencilik yöntemleriyle işlenir ve şirket için yararlı bilgiye (knowledge) dönüştürülür.
  - Slayttaki benzetme: bu, veri madenciliğinin en çok "büyük bir veritabanında altın aramaya" benzeyen biçimidir. Buradaki "altın", veritabanı hakkında önceden bilinmeyen ve açıkça ifade edilmemiş ilginç bir kuraldır (ekrandan, 00:25:00).
- Market sepeti (market basket)
  - Bir müşterinin tek bir işlemde satın aldığı ürünlerin topluluğudur.
  - İşlem veritabanı üzerinde yapılan yaygın analiz, birçok işlemde birlikte görülen ürün kümelerini (itemset) bulmaktır. İşletme bu örüntüleri ürünlerin mağazadaki yerleşimini iyileştirmek ve satışları artırmak için kullanır.
- Temel kavramlar: sık örüntüler (frequent patterns) (ekrandan, 00:30:00)
  - $i$ tane ürün içeren ürün kümesine $i$-ürün kümesi ($i$-itemset) denir.
  - Bir ürün kümesini içeren işlemlerin yüzdesine o kümenin desteği (support) denir.
  - Bir ürün kümesinin ilginç sayılması için desteği kullanıcının belirlediği bir minimumun üstünde olmalıdır; böyle kümelere sık (frequent) ya da büyük (large) küme denir.
  - Mağazadaki ürünler $I$ kümesini, her işlem $T$ ise $I$'nın bir alt kümesini oluşturur. Bir $X$ ürün kümesi için $X \subseteq T$ ise $T$ işlemi $X$'i içerir.
  - Algoritmalarda ürünler kısaca A, B, C, ... harfleriyle gösterilir.
- Birliktelik kuralı, destek ve güven (ekrandan, 00:40:00)
  - Kural $X \Rightarrow Y$ biçimindedir: "$X$'i alan müşteriler $Y$'yi de alır". Burada $X \subset I$, $Y \subset I$ ve $X \cap Y = \emptyset$.
  - $\text{Support}(X \Rightarrow Y) = P(X \cup Y)$: tüm işlemler içinde $X \cup Y$'yi içeren işlemlerin oranı.
  - $\text{Confidence}(X \Rightarrow Y) = P(Y \mid X)$: $X$'i içeren işlemlerin kaçta kaçının $Y$'yi de içerdiği.
- İkili (binary) gösterim (ekrandan, 00:45:00)
  - İşlemler, sütunları mağazadaki ürünler olan 0-1 matrisiyle gösterilebilir. Bir üründen kaç tane alındığı önemli değildir; alındıysa 1, alınmadıysa 0 yazılır. Mağazadaki tüm ürünler sütun olduğu için matris çok büyüktür.
- Güçlü kurallar (strong rules) (ekrandan, 01:05:00)
  - Güven kuralın gücünü (strength of implication), destek örüntünün sıklığını gösterir.
  - Güveni yüksek ve desteği güçlü kurallara güçlü kural denir; güveni önceden belirlenen eşiğin (ör. %80) altında kalan kurallar zayıftır.
  - Birliktelik kuralı madenciliğinin görevi büyük veritabanlarında güçlü kuralları bulmaktır.
- Birliktelik kuralı madenciliğinin iki fazı (ekrandan, 01:10:00)
  - 1. faz: desteği önceden belirlenen minimum eşiğin üstünde olan büyük (sık) ürün kümelerini bulmak. Bunun için Apriori algoritması kullanılır.
  - 2. faz: büyük ürün kümelerinden kurallar üretmek, güven değerlerini hesaplamak ve güveni eşiğin üstünde olanları güçlü kural olarak seçmek.
- Apriori algoritması
  - Yinelemeli (iterative) bir algoritmadır. $k$. yinelemenin sonunda büyük $k$-ürün kümeleri ($L_k$) bulunur.
  - Her yinelemede iki adım vardır: aday üretme ($C_k$) ve adayları sayıp sık olanları seçme.
  - Aday üretme ($\ast$ işlemi): $L_k \ast L_k = \{X \cup Y \mid X, Y \in L_k,\ |X \cap Y| = k-1\}$ (ekrandan, 01:30:00).
  - Budama (pruning): $(k+1)$ elemanlı bir adayın $k$ elemanlı alt kümelerinden biri bile $L_k$'da yoksa aday sayılmadan elenir; çünkü desteği zaten minimumun altında kalacaktır (ekrandan, 01:40:00).
- Apriori'nin kazancı: ürün kümesi kafesi (itemset lattice) (ekrandan, 02:35:00)
  - 5 ürünlü örnekte Apriori olmadan bütün kombinasyonlar sayılır: $5 + 10 + 10 + 5 + 1 = 31$ sayma.
  - Apriori ile: $5 + 6 + 1 = 12$ sayma. Budama olmasaydı 3. düzeyde 3 aday sayılacağı için 14 sayma gerekirdi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Destek ve güvenin formülleri
  - Hoca destek $P(X \cup Y)$ ve güven $P(Y \mid X)$ formüllerini "en açık hali bu, lütfen yazın" diyerek not ettirdi.
- Sayma (tarama) işlemi algoritmanın en pahalı kısmıdır
  - Gerçek hayatta işlem tablosunda milyonlarca satır olabilir ve her sepette 20-30 çeşit ürün bulunabilir. Her aday için bütün işlemler baştan sona taranır. Bu yüzden sayılan aday sayısını azaltmak çok önemlidir; Apriori'nin ve budamanın amacı budur.
- Budama adımının etkisi
  - Örnekte 3 aday budamayla 1'e indi; böylece iki aday için tüm işlemleri satır satır sayma maliyetinden kurtulundu.
- Kurallarda simetri yoktur
  - $A \Rightarrow C$ kuralının güveni %100 iken tersi $C \Rightarrow A$ kuralının güveni 2/3'tür. Bir kuralın güveni tersine aktarılamaz.
- Kafes diyagramı üzerinden sayma karşılaştırması
  - Hoca bu bölümün çok önemli olduğunu, Apriori ile ve Apriori olmadan yapılan sayma adetlerinin karşılaştırılmasının üzerinde durduğunu belirtti.
- Kural üretirken yeniden sayma yapılmaz
  - Güven değerleri Apriori'nin ürettiği $L_1$, $L_2$, $L_3$ tablolarındaki sayılardan okunur.

## Kısa Tekrar Notları

- Birliktelik kuralları denetimsiz öğrenmedir; market sepeti analizinin temelidir.
- $i$-itemset: $i$ ürünlü küme. Destek: kümeyi içeren işlemlerin yüzdesi.
- Kural $X \Rightarrow Y$, $X \cap Y = \emptyset$.
- $\text{Support} = P(X \cup Y)$, $\text{Confidence} = P(Y \mid X) = \dfrac{\text{count}(X \cup Y)}{\text{count}(X)}$.
- Güçlü kural: yüksek destek + güven eşiğin üstünde.
- İki faz: (1) Apriori ile sık kümeler, (2) sık kümelerden kural üretip güven eşiğiyle süzme.
- Apriori yinelemesi: aday üret ($C_k$) → say → minimum desteğe göre seç ($L_k$).
- $C_2$, $L_1$'in ikili kombinasyonlarıdır; sonraki adaylar $L_k \ast L_k$ ile, ortak eleman sayısı $k-1$ olan kümeler birleştirilerek üretilir.
- Budama: adayın bir alt kümesi önceki $L$ listesinde yoksa aday sayılmadan elenir.
- Örnekte (min. destek %50): $L_1 = \{A, B, C, E\}$, $L_2 = \{AC, BC, BE, CE\}$, $L_3 = \{BCE\}$.
- $BC \Rightarrow E$ ve $CE \Rightarrow B$ güçlü (güven %100); $B \Rightarrow CE$ güveni 2/3.
- $L_1$'den kural üretilmez; kurallar $L_2$ ve $L_3$'ten üretilir.
- Kafes: Apriori olmadan 31, Apriori ile 12, budamasız Apriori ile 14 sayma.

## Detaylı Açıklamalar

- Destek ve güven örneği (ikili tablo)
  - Slayttaki dört işlem: 1 = {Shoes, Trousers, Shirt, Belt}, 2 = {Shoes, Trousers, Shirt, Hat, Belt, Scarf}, 3 = {Shoes, Shirt}, 4 = {Shoes, Trousers, Belt} (ekrandan, 00:45:00).
  - Trousers $\Rightarrow$ Shirt: Trousers 3 işlemde (1, 2, 4), bunların 2'sinde Shirt de var. Güven $= 2/3$. Destek $= 2/4 = \%50$. <!-- BELİRSİZ: destek değerinin derste söylendiği kısım altyazıda halüsinasyon nedeniyle kayıp; değer tablodan hesaplandı. -->
  - {Trousers, Shoes} $\Rightarrow$ Belt: üç ürün birlikte 3 işlemde var, destek $= 3/4$; Trousers ve Shoes birlikte 3 işlemde var ve üçünde de Belt var, güven $= 3/3 = \%100$. <!-- BELİRSİZ: hoca önce "shirt" deyip sonra "belt" dedi; söylenen 3/4 ve 3/3 değerleri yalnız Belt ile tutuyor. -->
- Apriori örneği (minimum destek %50, ekrandan 01:15:00 ve 01:20:00)
  - İşlemler: 10 = {A, C, D}, 20 = {B, C, E}, 30 = {A, B, C, E}, 40 = {B, E}.
  - 1. yineleme: $C_1$ sayımları A = 2, B = 3, C = 3, D = 1, E = 3; destekler %50, %75, %75, %25, %75. D elenir, $L_1 = \{A, B, C, E\}$.
  - 2. yineleme: $C_2 = \{AB, AC, AE, BC, BE, CE\}$, sayımlar 1, 2, 1, 2, 3, 2; destekler %25, %50, %25, %50, %75, %50. AB ve AE elenir, $L_2 = \{AC\ (50), BC\ (50), BE\ (75), CE\ (50)\}$ (ekrandan, 01:30:00).
  - 3. yineleme adayları ($k = 2$, ortak eleman sayısı 1): AC ve BC'den ABC, AC ve CE'den ACE, BC ve BE'den (ya da BC ve CE'den) BCE. AC ile BE'nin ortak elemanı olmadığı için birleştirilemez; ABE gibi bir aday bu işlemle elde edilemez.
  - Budama (ekrandan, 02:05:00): ABC'nin alt kümesi AB, ACE'nin alt kümesi AE $L_2$'de yok, ikisi de elenir. BCE'nin alt kümeleri BC, BE, CE $L_2$'de var, aday kalır.
  - 3. tarama: BCE sayımı 2, destek %50; $L_3 = \{BCE\}$. Tek üçlü küme olduğu için 4. yinelemeye geçilemez ve algoritma durur.
- Kural üretme (ekrandan, 02:20:00)
  - $L_3$'teki BCE'den: $BC \Rightarrow E$: count(BCE)/count(BC) $= 2/2 = \%100$, güçlü kural. $CE \Rightarrow B$: $2/2 = \%100$, güçlü kural. $B \Rightarrow CE$: count(BCE)/count(B) $= 2/3 \approx \%67$; eşik %80 olsaydı zayıf kural.
  - $L_2$'den: $A \Rightarrow C$: count(AC)/count(A) $= 2/2 = \%100$. Tersi $C \Rightarrow A$: count(AC)/count(C) $= 2/3$.
- Kafes diyagramıyla sayma karşılaştırması (ekrandan, 02:30:00 ve 02:35:00)
  - 5 ürünün $k$'lı kombinasyon sayıları $\binom{5}{1}=5$, $\binom{5}{2}=\frac{5!}{2!\,3!}=10$, $\binom{5}{3}=10$, $\binom{5}{4}=5$, $\binom{5}{5}=1$; toplam 31 sayma.
  - Apriori: $C_1$'de 5, $C_2$'de 6 (D elendiği için 4 ürünün ikilileri), $C_3$'te budamadan sonra 1 aday; toplam 12 sayma. Kazanç oranı olarak 12/31 hesaplanabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
