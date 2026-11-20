# Ders 14 Çalışma Özeti

## Genel Konular

- Sık örüntüler (frequent patterns)
  - Birliktelik kuralı madenciliği (association rule mining), veri madenciliğinin ilk ve klasik uygulamalarından biridir. En bilinen kullanımı market sepeti analizidir (market basket analysis): alışveriş sepetinde birlikte alınan ürünleri bulmak.
  - Sık örüntü, bir veri kümesinde sık görülen örüntüdür; bir öğe kümesi, bir alt dizi ya da bir alt yapı olabilir (ekrandan, 00:05:00).
  - Sık öğe kümesi (frequent itemset): süt ve ekmek gibi bir işlem (transaction) veri kümesinde sık sık birlikte görünen öğeler.
  - Sık sıralı örüntü (frequent sequential pattern): önce bilgisayar, sonra dijital kamera, sonra hafıza kartı almak gibi, belli bir sırayla sık tekrarlanan alt dizi.
  - Sık yapısal örüntü (frequent structured pattern): alt graf, alt ağaç ya da alt kafes (sublattice) biçiminde sık görülen yapı.
  - Bu örüntüler pazarlama, reklam kampanyası ve raf düzeni gibi kararlarda kullanılır.
- Veri gösterimi
  - İşlemler liste olarak tutulabilir, ama büyük listede arama yavaştır.
  - Bu yüzden genellikle Boolean matris kullanılır: sütunlar ürünler, satırlar işlemlerdir; alınan ürün 1, alınmayan ürün 0 olarak yazılır.
- Temel tanımlar (ekrandan, 00:15:00)
  - Öğe kümesi (itemset): bir ya da daha fazla öğeden oluşan küme; $k$ öğeli olana $k$-öğe kümesi denir, $X = \{x_1, \ldots, x_k\}$.
  - Mutlak destek (absolute support): $X$ öğe kümesinin geçtiği işlem sayısı. Örnekte $\{Beer\}$ için 3.
  - Göreli destek (relative support): $X$'i içeren işlemlerin oranı, yani bir işlemin $X$'i içerme olasılığı. Örnekte $\{Beer\}$ için $3/5$.
  - $X$'in desteği, kullanıcının elle belirlediği minimum destek eşiğinden (minsup) küçük değilse $X$ sıktır. Algoritma eşiği kendisi seçmez.
- Birliktelik kuralı, destek ve güven (ekrandan, 00:20:00)
  - Birliktelik kuralı $X \rightarrow Y$ biçiminde bir çıkarımdır; $X$ ve $Y$ öğe kümeleridir.
  - Amaç, minimum destek ve minimum güveni (minconf) sağlayan bütün kuralları bulmaktır.
  - Destek: bir işlemin $X \cup Y$'yi içerme olasılığı, $P(X \cup Y)$; yani hem $X$'i hem $Y$'yi içeren işlemlerin oranı.
  - Güven: $X$'i içeren bir işlemin $Y$'yi de içerme koşullu olasılığı, $P(Y|X) = \text{support}(X \cup Y) / \text{support}(X)$. $X$'i alanların ne kadarının $Y$'yi de aldığını ölçer; en fazla 1 olur.
- Bira ve bebek bezi örneği (ekrandan, 00:25:00)
  - İşlemler: 10: Beer, Nuts, Diaper; 20: Beer, Coffee, Diaper; 30: Beer, Diaper, Eggs; 40: Nuts, Eggs, Milk; 50: Nuts, Coffee, Diaper, Eggs, Milk. minsup = %50, minconf = %50.
  - Sık örüntüler: $\{Beer\}:3$, $\{Nuts\}:3$, $\{Diaper\}:4$, $\{Eggs\}:3$, $\{Beer, Diaper\}:3$.
  - $Beer \rightarrow Diaper$ (%60, %100): bira alan 3 işlemin üçünde de bebek bezi var.
  - $Diaper \rightarrow Beer$ (%60, %75): bebek bezi alan 4 işlemin 3'ünde bira var, $3/4 = 0{,}75$. Destek ise $3/5 = 0{,}6$.
- Kural madenciliğinin maliyeti
  - Kaba kuvvet (brute force) yaklaşımda kafesteki (lattice) her öğe kümesi bir aday sık öğe kümesidir; her adayın desteği veritabanı taranarak sayılır (ekrandan, 01:55:00).
  - $d$ öğe için $M = 2^d$ aday vardır. $N$ işlem sayısı, $w$ işlem genişliği olmak üzere karmaşıklık yaklaşık $O(NMw)$'dir; $d$'ye göre üstel büyür. Yalnız 6 ürün için bile 602 olası kural vardır.
  - Aynı öğe kümesinden çıkan kuralların desteği aynı, güveni farklıdır (ekrandan, 00:30:00). Örnek: $\{Milk, Diaper, Beer\}$'den çıkan altı kuralın hepsinde $s = 0{,}4$, güvenler 0,67, 1,0, 0,67, 0,67, 0,5, 0,5. Bu yüzden destek ve güven koşulları ayrılabilir.
  - İki adımlı yaklaşım: önce desteği minsup'tan büyük olan sık öğe kümelerini bul, sonra bunlardan güveni yüksek kuralları üret.
- Altı işlemli örnek (ekrandan, 00:35:00)
  - İşlemler: ABD, ABCD, A, ABC, BC, B; minsup = 0,5, minconf = 0,7.
  - Tekliler: $A = 4/6$, $B = 5/6$, $C = 3/6$. $D = 2/6$ eşiğin altında kaldığı için elenir; D içeren hiçbir küme sık olamaz.
  - İkililer: $\{A,B\} = 3/6$, $\{B,C\} = 3/6$; $\{A,C\} = 2/6$ elenir.
  - Kurallar: $conf(A \rightarrow B) = 3/4$, $conf(C \rightarrow B) = 3/3$; ikisi de 0,7'nin üstündedir.
- Sık öğe kümesi üretme stratejileri (ekrandan, 00:40:00)
  - Aday sayısını ($M$) azaltmak: budama (pruning). Apriori ilkesi, bazı adayları desteğini saymadan eler.
  - Karşılaştırma sayısını ($NM$) azaltmak: adayları ya da işlemleri hash ağacı gibi verimli bir veri yapısında tutmak; her adayı her işlemle eşleştirmeye gerek kalmaz.
  - İşlem sayısını ($N$) azaltmak.
- Apriori ilkesi ve algoritması
  - Bir öğe kümesi sıksa bütün alt kümeleri de sıktır. Tersinden: bir öğe kümesi sık değilse onu içeren hiçbir üst küme (superset) sık olamaz.
  - Örnek (ekrandan, 00:45:00): minimum destek 3. Teklilerde Coke (2) ve Eggs (1) elenir. İkililerde {Beer, Bread} (2) ve {Beer, Milk} (2) elenir; {Bread, Milk}, {Bread, Diaper}, {Diaper, Milk}, {Beer, Diaper} (3'er) kalır. Üçlülerin sayıları 2, 2, 2, 1 çıkar; hepsi eşiğin altında olduğu için algoritma durur.
  - Bütün alt kümeler düşünülseydi $\binom{6}{1} + \binom{6}{2} + \binom{6}{3} = 6 + 15 + 20 = 41$ aday sayılacaktı; destek tabanlı budamayla $6 + 6 + 4 = 16$ aday sayılır.
  - Algoritma: $k = 1$ ile başla, sık 1-öğe kümelerini bul. Sık $k$-öğe kümeleri boş kalana kadar: aday üret, sık olmayan alt kümesi olan adayları buda, destekleri say, seyrek olanları ele.
  - Bu aşamada yalnız sık öğe kümeleri bulunur; henüz kural çıkarılmaz ve güven kullanılmaz.
- Aday üretme: $F_{k-1} \times F_{k-1}$ yöntemi (ekrandan, 00:50:00)
  - İki sık $(k-1)$-öğe kümesi, ilk $(k-2)$ öğeleri aynıysa birleştirilir.
  - $F_3 = \{ABC, ABD, ABE, ACD, BCD, BDE, CDE\}$ için: ABC+ABD = ABCD, ABC+ABE = ABCE, ABD+ABE = ABDE. ABD ile ACD birleştirilmez, çünkü yalnız 1 uzunluğunda ön ek paylaşırlar. Aday 4-öğe kümeleri $\{ABCD, ABCE, ABDE\}$ olur.
- Hash ağacı
  - Yapraklarda öğe kümeleri ve sayaçları, iç düğümlerde hash tablosu bulunur. Bir işlemin (örneğin 1, 2, 3, 5, 6) içerdiği adaylar, ağaçta doğru dala inilerek her adaya tek tek bakmadan bulunur.
- Apriori'nin karmaşıklığını etkileyen etkenler (ekrandan, 00:55:00)
  - Minimum destek eşiği: eşik düşerse daha çok sık öğe kümesi ve aday çıkar, sık öğe kümelerinin en büyük boyu artar.
  - Öğe sayısı (boyut): her öğenin destek sayacı için daha çok yer gerekir; hesaplama ve G/Ç maliyeti artabilir.
  - Veritabanı büyüklüğü: Apriori veriyi birçok kez taradığı için çalışma süresi işlem sayısıyla artar.
  - Ortalama işlem genişliği: yoğun veride işlemler geniştir; sık öğe kümelerinin boyu ve bir işlemin alt küme sayısı artar.
  - Sonuçlar parametreye çok bağlıdır; farklı eşikler için grafik çizip bakmadan tek bir parametreyle sonuç yorumlanmamalıdır.
- Çoklu minimum destek (ekrandan, 01:00:00)
  - Tek eşik çok yüksekse önemli öğeler kaçar, çok düşükse ilgisiz birçok öğe kümesi çıkar. Bu yüzden öğelere farklı minimum destek (MS) verilebilir.
  - Örnek: MS(Milk) = %5, MS(Coke) = %3, MS(Broccoli) = %0,1, MS(Salmon) = %0,5. Öğeler MS'e göre artan sırada dizilir: Broccoli, Salmon, Coke, Milk.
  - Apriori şöyle değiştirilir: $L_1$ sık öğeler; $F_1$ desteği $MS(1) = \min_i MS(i)$ değerinden büyük ya da eşit olan öğeler; boyutu 2 olan adaylar $L_1$ yerine $F_1$'den üretilir.
  - Bu parametreleri ayarlamak da kolay değildir; deneyerek bulunur.
- Kural üretme (ekrandan, 01:05:00)
  - Sık bir $L$ öğe kümesi için boş olmayan her $f \subset L$ alt kümesiyle $f \rightarrow L - f$ aday kuralı kurulur ve minimum güveni sağlayıp sağlamadığına bakılır.
  - $\{A,B,C,D\}$ için aday kurallar: ABC→D, ABD→C, ACD→B, BCD→A, D→ABC, C→ABD, B→ACD, A→BCD, AB→CD, AC→BD, AD→BC, CD→AB, BD→AC, BC→AD.
  - $|L| = k$ ise $2^k - 2$ aday kural vardır ($L \rightarrow \emptyset$ ve $\emptyset \rightarrow L$ sayılmaz).
- Güvenin anti-monoton özelliği (ekrandan, 01:20:00)
  - Genelde güven anti-monoton değildir: $c(ABC \rightarrow D)$, $c(AB \rightarrow D)$'den büyük de küçük de olabilir.
  - Aynı öğe kümesinden üretilen kurallarda ise anti-monotondur: $c(ABC \rightarrow D) \ge c(AB \rightarrow CD) \ge c(A \rightarrow BCD)$. Güven, kuralın sağ tarafındaki öğe sayısı arttıkça azalır.
  - Bu yüzden bir kural eşiği geçmezse, sağ tarafı onun sağ tarafını kapsayan bütün kurallar (alt çocukları) budanır.
- Sık öğe kümelerinin kompakt gösterimi
  - Sık öğe kümeleri çok sayıda ve birbirini tekrarlayan biçimde çıkar; bir üst küme sıksa bütün alt kümeleri de sıktır.
  - Maksimal sık öğe kümesi: hiçbir doğrudan üst kümesi (immediate superset) sık olmayan sık öğe kümesi (ekrandan, 01:25:00). Bütün sık öğe kümelerinin türetilebildiği en küçük kümeler topluluğudur.
  - Hocanın örneği: ABCDEFG eşiği aşmadı; ABCDE, BCDE ve DE sık. DE ve BCDE maksimal değildir, çünkü sık üst kümeleri vardır; maksimal olan ABCDE'dir.
  - Maksimal kümeler alt kümelerinin destek bilgisini taşımaz; örneğin $\{a,c,e\}$, $\{a,d\}$, $\{b,c,d,e\}$'nin destekleri alt kümelerinin desteği hakkında ipucu vermez (ekrandan, 01:30:00).
  - Kapalı sık öğe kümesi (closed frequent itemset): hiçbir doğrudan üst kümesi kendisiyle aynı destek sayısına sahip olmayan sık öğe kümesi. Destek bilgisini koruyan bir gösterimdir.
  - Bir üst kümenin desteği alt kümeyle aynıysa, eklenen öğe alt kümenin geçtiği her işlemde vardır.
  - Slayttaki örnekte 4 maksimal ve 9 kapalı sık öğe kümesi vardır. Kurallar yalnız bunlardan üretilir; yüzlerce kural yerine daha az ve daha kapsamlı kural elde edilir.
- FP-Growth algoritması (ekrandan, 01:35:00 ve 01:40:00)
  - Apriori'den tamamen farklı bir yaklaşımdır. FP-ağacı (Frequent Pattern tree) adlı sıkıştırılmış bir veri yapısı kullanır.
  - Ağaç, kökü null olan bir ağaçtır. İşlemler tek tek okunur; ortak ön eki olan işlemler aynı yolu paylaşır, düğümlerde sayaçlar tutulur. Aynı öğenin farklı dallardaki düğümleri işaretçilerle (pointer) bağlanır ve bir başlık tablosu (header table) bu bağlantılara erişim sağlar.
  - Sık öğe kümeleri aşağıdan yukarı, son eklere (suffix) göre bulunur: örneğin E ile bitenler için E düğümlerinden köke doğru çıkılır.
  - Örnekte (10 işlem, minsup = 2) E son ekli sık öğe kümeleri: {E}, {D,E}, {A,D,E}, {C,E}, {A,E}.
  - Sonrasında kurallar yine maksimal ve kapalı sık öğe kümeleri kullanılarak yazılır.
- Birliktelik örüntülerinin değerlendirilmesi
  - Algoritmalar çok sayıda, çoğu ilgisiz ya da tekrarlayan kural üretir. Kuralları elemek için ilginçlik ölçüleri (interestingness measures) kullanılır.
  - Güvenin zayıflığı, çay ve kahve örneği (ekrandan, 01:45:00): 100 kişiden çay ve kahve alan 15, çay alıp kahve almayan 5, çay almayıp kahve alan 75, ikisini de almayan 5. $Tea \rightarrow Coffee$ için güven $15/20 = 0{,}75$ yüksek görünür; ama $P(Coffee) = 0{,}9$ ve $P(Coffee|\overline{Tea}) = 75/80 = 0{,}9375$'tir. Kural yanıltıcıdır.
  - İstenen: $conf(X \rightarrow Y)$, $Y$'nin desteğinden büyük olmalı.
  - Lift: $lift = \dfrac{conf(A \rightarrow B)}{support(B)}$. Interest: $\dfrac{P(X,Y)}{P(X)P(Y)}$. Değer 1 ise bağımsız, 1'den büyükse pozitif ilişkili, 1'den küçükse negatif ilişkilidir.
  - Çay-kahve: $0{,}75 / 0{,}9 \approx 0{,}83 < 1$, yani çay ile kahve arasında negatif ilişki vardır.
  - Basketbol ve mısır gevreği örneği (ekrandan, 01:50:00): 5000 öğrenci. "Basketbol oynuyor ⇒ mısır gevreği yiyor" [%40, %66,7] yanıltıcıdır, çünkü öğrencilerin genelinde gevrek yeme oranı %75'tir. $lift(B,C) = 0{,}89$; "basketbol oynuyor ⇒ gevrek yemiyor" [%20, %33,3] ise $lift(B, \neg C) = 1{,}33$ ile daha doğrudur.
  - Başka ölçüler de vardır: kappa istatistiği ve büyük olasılıkla Jaccard gibi <!-- BELİRSİZ: ölçü adları altyazıda bozuk, slayt karesi yok -->; en çok lift ve interest kullanılır.
- Genel değerlendirme
  - Birliktelik kuralları, kümelemeden farklı olarak "bu alındıysa şu da ne kadar alınmış" sorusuna cevap veren betimleyici (descriptive) bir yöntemdir.
  - Market sepeti analizi dışında, birlikte geçen kelimeler gibi metin madenciliği uygulamalarında da kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Destek ve güvenin farkı
  - Destek, $X$ ile $Y$'nin birlikte geçtiği işlem oranıdır (bölen bütün işlemler). Güven, birlikte geçme sayısının yalnız $X$'in geçtiği işlem sayısına bölümüdür. Bundan sonraki her şey bu iki tanıma dayanır.
- Eşiklerin seçimi
  - Destek ve güven eşikleri kullanıcı tarafından elle belirlenir ve sonuçları çok etkiler. Düşük destekli kurallar genelde anlamsızdır, çünkü pazarlama çoğunluğa göre yapılır. Çıkan kuralların tesadüf olup olmadığı ayrıca incelenmelidir.
  - Farklı parametreler için sonuçları çizip bakmak gerekir; tek bir parametreyle "kurallarım bunlar" demek yanlış yerlere götürür.
- Apriori ilkesi
  - Seyrek bir kümenin hiçbir üst kümesi sık olamaz. Algoritma bu yüzden seyrek kümeleri hiç genişletmez; hoca bunu algoritmanın temeli olarak gösterdi.
- Kaba kuvvetin imkansızlığı
  - $n$ öğeli bir kümenin $2^n$ alt kümesi vardır; gerçek bir markette binlerce ürün olduğundan bütün alt kümeleri denemek mümkün değildir.
- Lift ve interest
  - Kurallarda yalnız destek ve güvene bakılmamalı; mutlaka lift ve interest de incelenmelidir. Hoca projelerde bunlara bakılmasını önerdi.
- FP-Growth
  - Ayrıntısı önemli değildir; bir ağaç yapısı tuttuğunu ve sık öğe kümelerini bu ağaçtan aşağıdan yukarı çıkardığını bilmek yeterlidir. Hash ağacı da yalnız ana fikriyle bilinmelidir.

## Kısa Tekrar Notları

- Destek: $s(X \rightarrow Y) = P(X \cup Y)$; güven: $c(X \rightarrow Y) = s(X \cup Y)/s(X)$.
- Mutlak destek = sayı, göreli destek = sayı / işlem sayısı.
- Sık öğe kümesi: desteği minsup'tan küçük değil.
- Kaba kuvvet: $M = 2^d$ aday, karmaşıklık $O(NMw)$; 6 öğede 602 kural.
- Apriori ilkesi: sık kümenin alt kümeleri sıktır; seyrek kümenin üst kümeleri seyrektir.
- Apriori: birlikler → buda → ikililer → buda → ... sık küme kalmayınca dur.
- Aday üretme: ilk $k-2$ öğesi aynı olan iki $(k-1)$-kümeyi birleştir.
- Karmaşıklığı etkileyenler: minsup, öğe sayısı, işlem sayısı, ortalama işlem genişliği.
- Çoklu minimum destek: her öğeye ayrı MS; $F_1$ en küçük MS ile seçilir.
- $k$ öğeli sık kümeden $2^k - 2$ aday kural çıkar.
- Aynı kümeden çıkan kurallarda güven, sağ taraf büyüdükçe azalır: $c(ABC \rightarrow D) \ge c(AB \rightarrow CD) \ge c(A \rightarrow BCD)$.
- Maksimal: hiçbir doğrudan üst kümesi sık değil. Kapalı: hiçbir doğrudan üst kümesi aynı desteğe sahip değil.
- FP-Growth: FP-ağacı + başlık tablosu + işaretçiler; son eke göre aşağıdan yukarı arama.
- Lift = interest = $P(X,Y)/(P(X)P(Y))$: 1 bağımsız, >1 pozitif, <1 negatif ilişki.
- Çay → kahve: güven 0,75 ama lift ≈ 0,83 (negatif ilişki).

## Detaylı Açıklamalar

Birliktelik kuralı madenciliği, bir işlem veritabanında hangi öğelerin birlikte göründüğünü bulmaya çalışır. Her işlem (transaction) bir müşterinin bir alışverişidir ve bir öğe kümesidir. Bir öğe kümesinin desteği onu içeren işlemlerin sayısı ya da oranıdır. Kullanıcı bir minimum destek eşiği belirler; desteği bu eşiğin altında olmayan kümelere sık öğe kümesi denir. Bir $X \rightarrow Y$ kuralının desteği $X \cup Y$'nin desteğidir, güveni ise $X$'i içeren işlemlerin ne kadarının $Y$'yi de içerdiğidir.

Bira ve bebek bezi örneğinde beş işlem vardır. Bira 3 işlemde, bebek bezi 4 işlemde, ikisi birlikte 3 işlemde geçer. Bu yüzden iki kuralın desteği de $3/5 = \%60$'tır. $Beer \rightarrow Diaper$ kuralının güveni $3/3 = \%100$, $Diaper \rightarrow Beer$ kuralının güveni $3/4 = \%75$'tir. Aynı kümeden çıkan kuralların desteği aynı, güveni farklıdır; bu gözlem, kural madenciliğini iki adıma ayırmayı mümkün kılar: önce sık öğe kümeleri bulunur, sonra bunlardan güvenli kurallar çıkarılır.

Kaba kuvvetle bütün $2^d$ aday kümeyi saymak, $N$ işlem ve $w$ genişliğinde $O(NMw)$ iş ister ve öğe sayısıyla üstel büyür. Apriori algoritması bu maliyeti Apriori ilkesiyle azaltır: bir küme seyrekse onu içeren bütün kümeler de seyrektir. Algoritma tekli kümelerden başlar, seyrek olanları atar, kalanlardan bir büyük boyutta aday üretir ve hiç sık küme kalmayana kadar devam eder. Ekmek-süt örneğinde minimum destek 3 iken Coke ve Eggs ilk adımda, {Beer, Bread} ve {Beer, Milk} ikinci adımda elenir; üçlülerin hiçbiri 3'e ulaşmadığı için algoritma durur. Bütün alt kümeler sayılsaydı 41 aday gerekecekti, budamayla 16 aday sayılır.

Adaylar $F_{k-1} \times F_{k-1}$ yöntemiyle, ilk $k-2$ öğesi aynı olan sık kümeler birleştirilerek üretilir. Adayların işlemlerde aranması için hash ağacı kullanılabilir; böylece her işlem her adayla karşılaştırılmaz. Algoritmanın maliyetini minimum destek eşiği, öğe sayısı, veritabanı büyüklüğü ve ortalama işlem genişliği belirler. Tek bir eşik yetersiz kalırsa öğelere farklı minimum destek değerleri verilebilir.

Kural üretmede, $k$ öğeli bir sık kümeden $2^k - 2$ aday kural çıkar. Güven genelde anti-monoton değildir, ama aynı kümeden çıkan kurallar için sağ taraf büyüdükçe güven azalır. Bu yüzden eşiği geçemeyen bir kuralın, sağ tarafı daha büyük olan bütün türevleri denenmeden atılır.

Sık öğe kümelerinin sayısını azaltmak için iki kompakt gösterim tanımlanır. Maksimal sık öğe kümelerinin hiçbir doğrudan üst kümesi sık değildir; bütün sık kümeler bunlardan türetilebilir, ama alt kümelerin destek bilgisi kaybolur. Kapalı sık öğe kümelerinin hiçbir doğrudan üst kümesi aynı desteğe sahip değildir; bu gösterim destek bilgisini korur.

FP-Growth, Apriori'den tamamen farklı bir yaklaşımdır. İşlemler bir FP-ağacına yerleştirilir; ortak ön ekler aynı yolu paylaşır, aynı öğenin düğümleri işaretçilerle bağlanır. Sık öğe kümeleri, başlık tablosundan bir öğenin bütün düğümlerine gidilip köke doğru çıkılarak son eklere göre bulunur.

Son olarak, yüksek güven tek başına iyi bir kural anlamına gelmez. Çay-kahve örneğinde $Tea \rightarrow Coffee$ kuralının güveni 0,75'tir, ama zaten herkesin %90'ı kahve alır; çay almayanlarda bu oran %93,75'tir. Lift (interest), güveni sağ tarafın genel oranına bölerek bu durumu ortaya çıkarır: $0{,}75/0{,}9 \approx 0{,}83 < 1$, yani çay alanların kahve alma olasılığı genel ortalamadan düşüktür. Basketbol örneğinde de destek ve güveni daha düşük olan "gevrek yemiyor" kuralı, lift'i 1,33 olduğu için daha doğru çıkar.

> **Ders sonrası not:** Hoca çay-kahve örneğinde lift için "yüksek çıktı" dedi; doğrusu lift $0{,}75 / 0{,}9 \approx 0{,}83$'tür ve 1'den küçüktür. Hocanın hemen ardından vardığı "negatif korelasyon var" sonucu bu değerle uyumludur.

> **Ders sonrası not:** Hoca lift için "bağımsızlık yorumu yapılamaz, interest normalize eder" anlamında konuştu. İkisi aynı değerdir: $conf(X \rightarrow Y)/s(Y) = \dfrac{P(X,Y)/P(X)}{P(Y)} = \dfrac{P(X,Y)}{P(X)P(Y)}$. Bu yüzden 1'e göre yorum ikisi için de geçerlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
