# Ders 8 Genişletilmiş Notu: Sık Öğe Kümeleri: A-Priori, PCY, Çok Aşamalı ve Çok Karmalı Algoritmalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konusu ve Kaynağı
- 2. Pazar Sepeti Modeli
- 3. Destek ve Sık Öğe Kümeleri
- 4. Uygulamalar
- 5. Problemin Ölçeği
- 6. Birliktelik Kuralları ve Güven
- 7. Birliktelik Kurallarını Bulma Adımları
- 8. Verinin Diskte Saklanması ve Maliyet Modeli
- 9. Asıl Sorun: Çiftleri Saymak
- 10. Saf Algoritma
- 11. Çiftleri Bellekte Saymanın İki Yolu
- 12. A-Priori Algoritması
- 13. PCY Algoritması
- 14. Çok Aşamalı (Multistage) Algoritma
- 15. Çok Karmalı (Multihash) Algoritma
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Konusu ve Kaynağı

Derste MMDS (Mining of Massive Datasets, Leskovec, Rajaraman ve Ullman) kitabından devam edildi. Önceki derslerde ilk beş bölüm işlenmişti; bu derste 6. bölüm olan sık öğe kümeleri (frequent itemsets) konusu ele alındı (ekrandan, 00:05:00). Açılış slaytındaki üç başlık dersin akışını özetler: pazar sepeti modeli (market-basket model), birliktelik kuralları (association rules) ve A-Priori algoritması.

Hoca, A-Priori algoritmasını veri madenciliği ya da bilgi erişimi gibi derslerde görmüş olanlar olabileceğini, ama bu derste algoritmanın büyük veri sürümünün, yani çok büyük veri kümelerine nasıl uygulanacağının konuşulacağını söyledi. Dersin büyük kısmı bu nedenle bellek ve disk erişimi kısıtları altında sık çiftlerin nasıl bulunacağına ayrıldı.

## 2. Pazar Sepeti Modeli

Model fiziksel bir süpermarketle anlatıldı. Slayttaki tanıma göre (ekrandan, 00:10:00):

- Büyük bir **öğe (item)** kümesi vardır; örneğin süpermarkette satılan ürünler.
- Büyük bir **sepet (basket)** kümesi vardır; her sepet öğelerin küçük bir alt kümesidir, örneğin bir müşterinin bir günde aldıkları.

Kasaya gittiğimizde sepetteki bütün ürünler aynı fişe girer ve hepsini birlikte öderiz. Bu satın alma bir **işlem (transaction)** oluşturur. Mağazadan alışveriş yapan herkes bir işlem yaratır.

İlgilendiğimiz problem, **birlikte sık satılan öğe kümelerini** bulmaktır. Hoca örnek olarak 100.000 müşterisi olan bir süpermarketi verdi: müşterilerin %90'ı ekmek ve sütü birlikte alıyorsa bu bilgiyi öğrenmek isteriz. Pazar sepeti analizi, bir mağazada birlikte sık satılan ürünleri bulma problemidir.

## 3. Destek ve Sık Öğe Kümeleri

### 3.1 Destek eşiği

"Sık" kavramını tanımlamak için **destek (support)** ölçüsü kullanılır. Bir öğe kümesinin desteği, o kümedeki öğeleri birlikte içeren işlem (sepet) sayısıdır. Destek belirli bir **destek eşiğinin (support threshold)** üzerindeyse küme sık sayılır.

Küme tek öğeli ya da çok öğeli olabilir. Ekmek destek eşiğinin üzerinde satılıyorsa ekmek sık bir öğedir; ekmek ve süt birlikte eşiğin üzerinde satılıyorsa {ekmek, süt} sık bir ikili öğe kümesidir.

Destek eşiği iki biçimde verilebilir:

- **Sayı olarak:** Örneğin eşik 100 ise bir öğe kümesi en az 100 sepette geçmelidir.
- **Yüzde olarak:** Örneğin %90, %70 ya da %50; bütün işlemlerin bu kadarı kümeyi içeriyorsa küme sıktır.

### 3.2 Örnek: sık öğe kümeleri

Slayttaki örnekte öğeler {milk, coke, pepsi, beer, juice} (kısaca $m, c, p, b, j$), destek eşiği 3 sepettir ve 8 sepet vardır (ekrandan, 00:15:00):

| Sepet | İçerik | Sepet | İçerik |
|---|---|---|---|
| $B_1$ | $\{m, c, b\}$ | $B_2$ | $\{m, p, j\}$ |
| $B_3$ | $\{m, b\}$ | $B_4$ | $\{c, j\}$ |
| $B_5$ | $\{m, p, b\}$ | $B_6$ | $\{m, c, b, j\}$ |
| $B_7$ | $\{c, b, j\}$ | $B_8$ | $\{b, c\}$ |

Önce tek öğeler sayılır. $m$; $B_1, B_2, B_3, B_5, B_6$ sepetlerinde geçer, yani 5 kez; eşiğin üzerinde olduğu için sıktır. Benzer biçimde $c$, $b$ ve $j$ de sık bulunur. Sonra ikili kümelere bakılır: $\{m, b\}$; $B_1, B_3, B_5, B_6$ sepetlerinde geçer, 4 kez, yani sıktır. Diğer ikililer de aynı yolla sayılır. Slayttaki sonuç:

$$\text{Sık öğe kümeleri: } \{m\}, \{c\}, \{b\}, \{j\}, \{m,b\}, \{b,c\}, \{c,j\}$$

Tam sayımlar (python ile doğrulandı): tek öğeler için $b$: 6, $m$: 5, $c$: 5, $j$: 4, $p$: 2; çiftler için $\{m,b\}$: 4, $\{b,c\}$: 4, $\{c,j\}$: 3, diğer bütün çiftler en fazla 2.

> **Ders sonrası not:** Hoca $c$ için $B_1, B_4, B_6, B_8$ sepetlerini sayıp 4 dedi; $B_7 = \{c, b, j\}$ de $c$'yi içerdiği için doğrusu 5'tir. Sonuç (c sıktır) değişmez. Hoca ayrıca eşiği "üçten fazla sepette geçerse" diye okudu; slayttaki sonuçta $\{c,j\}$ tam 3 sepette geçip sık sayıldığına göre ölçüt "en az 3 sepet"tir.

Bu sayma, eşiğin üzerinde kalan tek öğeli, iki öğeli, üç öğeli kümeleri bulmak için aynı biçimde sürdürülür.

## 4. Uygulamalar

Sık öğe kümelerini bulmanın bir yolu varsa bu farklı problemlerde kullanılabilir. Hoca üç uygulama anlattı.

### 4.1 Pazarlama: bebek bezi ve bira

Öğeler ürünler, sepetler ürün kümeleridir. Bir fiziksel mağazada birçok kişi bira ve bebek bezini birlikte alıyorsa bu bilgi pazarlamada kullanılabilir: bebeği olan ve bez almaya gelen kişiler bira da alıyor demektir. Hocanın anlattığı fiyatlama stratejisi şöyledir: bezde indirim yapılarak bebeği olan müşteriler mağazaya çekilir, biranın fiyatı yükseltilir. Bez almaya gelen kişi sırf bira için başka mağazaya gitmekte zorlanacağı için birayı da buradan alır. Bu uygulama pazarlama bölümü için bir karar destek sistemi işlevi görür.

### 4.2 İntihal tespiti

Bu kez öğeler belgeler, sepetler cümlelerdir: her sepet, o cümleyi içeren belgelerden oluşur (ekrandan, 00:20:00). İki ya da üç belge birçok sepette birlikte geçiyorsa, bu belgeler birçok cümleyi ortak içeriyor demektir. Bu belgeler birbirinin kopyası (replica) sayılabilir ya da aralarında intihal (plagiarism) olabilir.

Slayt bu örnek için iki noktayı vurgular: öğelerin sepetin "içinde" olması gerekmez (burada belge cümlenin içinde değildir, ilişki tersinedir); yine de sepetlerin az sayıda öğe içermesi, öğelerin ise çok sayıda sepette bulunabilmesi tercih edilir.

### 4.3 Tweet'lerde önemli haberler

Öğeler kelimeler, sepetler belgelerdir; ama burada yalnız tweet gibi kısa belgeler düşünülür. İki ya da üç kelime birçok tweet'te birlikte geçiyorsa bu kelimeler arasındaki ilişki ilginçtir ve önemli bir haberi gösterebilir.

Hoca üç uygulamayı şöyle özetledi: birincisi pazarlama için karar destek sistemi, ikincisi intihal tespiti, üçüncüsü tweet'lerden önemli haberleri bulma.

## 5. Problemin Ölçeği

Slayta göre WalMart 100.000 ürün satar ve milyarlarca sepet saklayabilir; web'de milyarlarca kelime ve milyarlarca sayfa vardır (ekrandan, 00:25:00). Fiziksel bir mağazada ürün sayısı çok fazla değildir, ama altı aylık ya da bir yıllık sürede milyarlarca işlem olabilir. E-ticarette ise satılan ürün sayısı (hocanın Amazon örneğiyle) milyarlar mertebesindedir; işlem sayısı bundan da büyüktür. Tweet uygulamasında da kelime sayısı yüz binler, tweet sayısı milyarlar mertebesindedir. Kısacası problem web ortamına geçince çok büyür. <!-- BELİRSİZ: 00:25:49 ile 00:26:19 arasında altyazıda boşluk var; bu aralıktaki anlatım alınamadı. -->

## 6. Birliktelik Kuralları ve Güven

Sık öğe kümelerini bulmamızın amacı bunlardan **kurallar** çıkarmaktır. $k+1$ öğeden oluşan bir kural şu biçimdedir:

$$\{i_1, i_2, \ldots, i_k\} \to j$$

Sol tarafta $i_1$'den $i_k$'ye kadar öğeler, sağ tarafta tek bir öğe $j$ vardır. Kural şunu söyler: $i_1, \ldots, i_k$ öğelerini alan kişi büyük olasılıkla $j$'yi de alır.

Bir kuralın gücünü gösteren ölçü **güvendir (confidence)**. Güven, $i_1, \ldots, i_k$ öğelerini içeren işlemlerden kaçının $j$'yi de içerdiğini, yani bir olasılığı verir:

$$\text{conf}(I \to j) = \frac{\text{support}(I \cup \{j\})}{\text{support}(I)}, \qquad I = \{i_1, \ldots, i_k\}$$

### 6.1 Örnek: güven hesabı

Aynı sekiz sepet üzerinde $\{m, b\} \to c$ kuralı ele alındı (ekrandan, 00:30:00). Kural, $m$ ve $b$'yi alan kişinin $c$'yi de alma eğiliminde olduğunu söyler.

- Önce $\{m, b\}$'yi içeren sepetler bulunur: $B_1, B_3, B_5, B_6$. Bu 4 sepet paydadır.
- Bunlardan $c$'yi de içerenler bulunur: $B_1$ ve $B_6$. Bu 2 sepet paydır (slaytta $+$ ile işaretli).
- Güven: $2/4 = \%50$.

## 7. Birliktelik Kurallarını Bulma Adımları

Problem şöyle konur: desteği $s$'den büyük, güveni $c$'den büyük bütün birliktelik kurallarını bul. Bir kuralın desteği, sol taraftaki öğe kümesinin desteğidir. Kural yüksek destek ve güvene sahipse hem $\{i_1, \ldots, i_k\}$ hem de $\{i_1, \ldots, i_k, j\}$ kümeleri sık olur. Bu yüzden önce sık öğe kümeleri bulunur, kurallar sonra çıkarılır.

Slayttaki adımlar (ekrandan, 00:35:00):

1. Desteği en az $cs$ olan bütün kümeleri bul.
2. Desteği en az $s$ olan bütün kümeleri bul.
3. $\{i_1, \ldots, i_k, j\}$ kümesinin desteği en az $cs$ ise, bir öğesi eksik olan hangi alt kümelerin desteğinin en az $s$ olduğuna bak. Eksik öğeyi $j$ olarak al.
4. $\{i_1, \ldots, i_k\}$ kümesinin desteği $s_1 \ge s$, $\{i_1, \ldots, i_k, j\}$ kümesinin desteği $s_2 \ge cs$ ve kuralın güveni olan $s_2/s_1$ en az $c$ ise, $\{i_1, \ldots, i_k\} \to j$ kabul edilebilir bir birliktelik kuralıdır.

Hoca bu adımları Türkçe olarak da tekrar etti. Önce bütün öğeleri içeren kümenin $cs$ eşiğinin üzerinde olması istenir. Sonra bu kümeden her seferinde bir öğe sağ tarafa alınarak kurallar oluşturulur; $k+1$ öğeli bir kümeden $k+1$ farklı kural çıkar. Her kural için sol taraftaki kümenin desteği (en az $s$) ve bütün kümenin desteği bilindiğinden, ikisinin oranı güveni verir. Bu oran girdi olarak verilen güven eşiğinden büyükse kural kabul edilir.

> **Hocanın vurgusu:** Üçüncü ve dördüncü adım zor değildir. Zor olan sık öğe kümelerini bulmaktır, özellikle veri ölçeği büyüdüğünde. İşlem ya da sepet sayısı o kadar fazladır ki sayaçlar belleğe sığmaz ve öğelerin destek eşiğini geçip geçmediği bellekte denetlenemez. Bu yüzden sık öğe kümelerini hesaplamak için bir yöntem bulmak gerekir.

## 8. Verinin Diskte Saklanması ve Maliyet Modeli

### 8.1 Dosya düzeni

Veri dosyalarda, işlem biçiminde ve sepet sepet saklanır: önce birinci sepetin bütün öğeleri, sonra ikinci sepetin öğeleri, ve böyle sürer. Slayttaki örnekte öğeler pozitif tam sayılardır ve sepetler arasındaki sınır $-1$ ile gösterilir (ekrandan, 00:45:00).

Amaç önce sık tek öğeleri, yani destek eşiğinden fazla sepette geçen öğeleri bulmak; sonra sık çiftleri, sonra sık üçlüleri bulmaktır.

### 8.2 Maliyet: disk G/Ç sayısı

Bu algoritmaların maliyeti **disk G/Ç (disk I/O) erişimi** sayısıyla ölçülür. Algoritma birçok disk erişimi yapıyorsa maliyeti yüksektir; bir ya da iki erişimle işini görüyorsa daha iyidir. Disk erişimi dışındaki hesaplamanın süresi, disk erişim süresine göre çok küçüktür. Bu yüzden analizde algoritmanın kaç disk erişimi yaptığına bakılır.

Bir öğenin sık olup olmadığını bulmak için algoritma her seferinde bütün veri üzerinden bir **geçiş (pass)** yapar, yani dosyadaki bütün veriyi okur.

### 8.3 Asıl darboğaz: ana bellek

Veri üzerinden geçiş yapmak tek başına sorun değildir; sorun bellektir. Bir öğenin sık olup olmadığını saymak için mağazadaki bütün öğelerin sayacını tutmak gerekir. Örneğin mağazada 1 milyar öğe varsa 1 milyar sayaç bellekte tutulmalıdır: birinci sepet okunur, içindeki öğelerin sayaçları artırılır; ikinci sepete geçilir, tablodaki ilgili sayaçlar güncellenir; böyle sürer. Fiziksel bellek bütün bu sayaçları tutacak kadar büyük olmalıdır.

Sayaçları diske koymak da çözüm değildir: her sayaç artırımı bir disk erişimi gerektireceği için erişim sayısı çok artar.

## 9. Asıl Sorun: Çiftleri Saymak

Yalnız tek öğeleri değil, öğe çiftlerini de saymak isteriz. Mağazada 100.000 öğe varsa bunları saymak sorun değildir. Ama çiftlere geçince $\binom{100.000}{2}$ çift sayılmalıdır ve bu ana belleğe sığmayacak kadar büyüktür.

> **Ders sonrası not:** Hoca $\binom{100.000}{2}$ için "1 milyar çift" dedi; doğrusu $\frac{100.000 \cdot 99.999}{2} = 4.999.950.000$, yani yaklaşık 5 milyar çifttir (python ile doğrulandı). Sonuç (belleğe sığmaz) değişmez.

Bu yüzden sık öğe kümesi problemi denince genellikle **sık çiftleri bulma** problemi kastedilir. Hoca nedenini şöyle açıkladı: bu tür problemlerin çalışıldığı alanlarda destek eşiği çok yüksek seçilir; %80 ya da %90 sepette birlikte satılmış ürünler aranır. Bu kadar yüksek bir destekte çok sayıda sepette birlikte geçen üçlü ya da dörtlü ürün bulmak çok zordur, ama ikili ürünler yaygın olarak bulunabilir.

Hocanın sayısal örneği: 1 milyon sepet ve 100.000 öğe olsun. Her öğe için 4 baytlık bir sayaç tutularak 100.000 öğe bellekte kolayca izlenebilir. Ama bu öğelerin ikilileri oluşturulunca sayılması gereken ikili sayısı milyarlara çıkar ve buna uygun bir çözüm gerekir.

## 10. Saf Algoritma

Önce en basit yöntem düşünüldü: karşılaşılabilecek bütün ikilileri sayacak kadar bellek olduğunu varsayalım. $n$ öğe için tek öğe sayaçları bellekte tutulabilir; ancak bütün veri bir kez okunduktan sonra hangi tek öğelerin sık olduğu anlaşılır. Sonra çiftler için veri yeniden okunur. En kötü durumda bütün öğeler sıksa $n$ öğenin bütün ikililerine bakmak gerekir; olası çift sayısı $\frac{n(n-1)}{2}$'dir. Bellek ihtiyacı $n^2$ mertebesindedir. Her sayaç 4 baytlık tamsayıysa toplam bellek

$$4 \cdot \frac{n(n-1)}{2} \approx 2n^2 \text{ bayt}$$

olur. $n = 100.000$ için bu yaklaşık $2 \cdot 10^{10}$ bayt, yani 20 GB eder (ara adım eklendi).

Slayttaki saf algoritma (ekrandan, 00:50:00):

- Dosyayı bir kez oku, her çiftin geçiş sayısını ana bellekte say.
- $n$ öğeli her sepetten iki iç içe döngüyle $n(n-1)/2$ çifti üret.
- $(\#\text{öğe})^2$ ana belleği aşarsa algoritma başarısız olur. Öğe sayısı 100K (Wal-Mart) ya da 100B (web sayfaları) olabilir.

Böyle bir bellek olsaydı karmaşık bir algoritmaya gerek kalmaz, hem tek öğelerin hem çiftlerin sayaçları bellekte tutularak sık olanlar bulunurdu. Derste bu saf algoritmaya alternatifler konuşuldu; ama önce sayma için bellekte nasıl bir veri temsili kullanılacağına bakıldı.

## 11. Çiftleri Bellekte Saymanın İki Yolu

Slayttaki karşılaştırma iki üçgenle gösterilir: soldaki üçgen matriste "çift başına 4 bayt", sağdaki tablo yönteminde "gerçekten görülen çift başına 12 bayt" yazar; sağdaki üçgende yalnız bazı noktalar (görülen çiftler) doludur (ekrandan, 00:55:00).

### 11.1 Üçgen matris yaklaşımı

Satırları ve sütunları 1'den $n$'e numaralı bir matris düşünülür, ama yalnız birinci indisin ikinciden küçük olduğu hücreler tutulur. Slayttaki kurallar (ekrandan, 01:00:00):

- Öğeleri 1, 2, ... diye numarala. Bunun için öğe adlarını ardışık tam sayılara çeviren $O(n)$ boyutlu bir tablo gerekir.
- $\{i, j\}$ çiftini yalnız $i < j$ ise say.
- Çiftleri şu sırada tut: $\{1,2\}, \{1,3\}, \ldots, \{1,n\}, \{2,3\}, \{2,4\}, \ldots, \{2,n\}, \{3,4\}, \ldots, \{3,n\}, \ldots, \{n-1,n\}$.

Her hücrede bir sayaç (4 baytlık bir tamsayı) tutulur. Olası bütün çiftler için yer ayrılır; bu çiftlerin bazıları sık olmayacak, hatta bazıları hiçbir sepette geçmeyecektir.

Hoca matrisin iki boyutlu tutulmak yerine bu sırayla tek boyutlu bir dizi olarak yazılabileceğini anlattı: birinci çifte 1, ikinciye 2, üçüncüye 3 diye numara verilir. Verilen $(i, j)$ çiftinin bu tek boyutlu dizide hangi konumda olduğunu veren bir formül vardır; bu formülle dizideki ilgili indise gidilip sayaç artırılır. <!-- BELİRSİZ: formülün bulunduğu slayt karelerde yok ve hoca formülü sesli okumadı. -->

> **Ek bilgi (derste anlatılmadı):** MMDS kitabında bu konum büyük olasılıkla $k = (i-1)\left(n - \frac{i}{2}\right) + j - i$ formülüyle verilir ($1 \le i < j \le n$). Bu formül, $n=5$ için yukarıdaki sıralamanın 1'den 10'a kadar ardışık numaralarını verir (python ile denendi).

### 11.2 Tablo (üçlü) yaklaşımı

Bu yöntemde her satır bir üçlüdür: birinci öğe, ikinci öğe ve sayaç, yani $[i, j, \text{sayı}]$. Birinci sepetten başlanır; sepetteki öğelerden oluşan bütün olası ikililer tabloya yazılır ve yanlarına sayaçları konur. Sonraki sepete geçilir; ikili tabloda zaten varsa sayacı artırılır, yoksa eklenir. Böylece yalnız veride gerçekten geçen ikililer sayılmış olur. Üçgen matriste hiç geçmeyecek çiftler için de yer ayrılırken, burada yalnız veride görülen çiftler için yer ayrılır.

Her alan 4 bayt olduğu için satır başına 12 bayt gerekir. Slayta göre (ekrandan, 01:05:00):

- Toplam kullanılan bellek yaklaşık $12p$ bayttır; $p$ gerçekten görülen çift sayısıdır.
- Olası çiftlerin en fazla 1/3'ü gerçekten görülüyorsa üçgen matristen iyidir.
- Erişim için ek bir yapı, örneğin bir hash tablosu gerekebilir.

### 11.3 Hangisi seçilir?

Olası çift sayısı $\frac{n(n-1)}{2}$'dir. Veride gerçekten geçen çift sayısı bunun 1/3'ünden küçükse tablo yöntemi daha az bellek kullanır: tabloda çift başına 12 bayt, üçgen matriste 4 bayt harcanır, ve $12p < 4 \cdot \frac{n(n-1)}{2}$ koşulu $p < \frac{1}{3}\cdot\frac{n(n-1)}{2}$ demektir (ara adım eklendi). Veri hakkında böyle bir ön bilgi yoksa ya da görülen çiftlerin 1/3'ten fazla olduğu biliniyorsa üçgen matris kullanılır; o zaman da iki boyutlu dizi yerine tek boyutlu dizi ve yukarıdaki konum formülü kullanılır.

## 12. A-Priori Algoritması

Aradan sonra sık öğe kümelerini bulmak için kullanılabilecek yöntemlere geçildi. Bölüm slaytında başlıklar monotonluk, aday çiftler ve daha büyük kümelere genişletmedir (ekrandan, 01:15:00).

### 12.1 Monotonluk

A-Priori algoritmasının dayanağı şudur: **bir öğe kümesi sıksa bütün alt kümeleri de sıktır.** Bu özelliğe monotonluk (monotonicity) denir. Bir kümenin öğeleri destek eşiğinin üzerinde sayıda sepette birlikte geçiyorsa, alt kümeleri de en az o kadar sepette geçer; dolayısıyla onlar da sıktır.

A-Priori bunun karşıt tersini kullanır: **bir öğe sık değilse, bu öğeyi içeren hiçbir çift sık değildir.** Bu yüzden sık olmayan öğeleri içeren çiftleri yeniden saymaya gerek yoktur.

### 12.2 İki geçiş

A-Priori diskteki veri üzerinden iki geçiş yapar (ekrandan, 01:20:00):

- **Geçiş 1:** Tek öğeler sayılır. $n$ öğenin her birinin hangi sepetlerde geçtiğine bakılarak sayaçları tutulur. Geçiş sonunda hangi öğelerin sık olduğu belirlenir.
- **Geçiş 2:** Yalnız sık öğelerden olası bütün çiftler oluşturulur. Örneğin $n$ öğenin yalnız üçte biri sık çıktıysa, yalnız bu üçte birin ikilileri oluşturulur. Veri yeniden okunur ve bu kez tek öğeler değil, bu çiftlerin her sepette geçip geçmediğine bakılarak sayaçları artırılır. Sonunda sık çiftler bulunur.

Slayttaki resimde geçiş 1'de bellekte "öğe sayaçları", geçiş 2'de "sık öğeler" ve "sık öğelerden oluşan çiftlerin sayaçları" yer alır.

### 12.3 A-Priori'nin sorunu

Sık öğe sayısı da çok yüksekse, bunlardan oluşan çiftlerin sayısı da çok yüksek olur, çünkü ikili kombinasyonlara bakılır. Bu durumda ikinci geçişin bellek ihtiyacı çok büyür. Üstelik bu çiftlerin birçoğu veride hiç birlikte geçmemiş olabilir, ama yine de onlar için yer ayrılır.

### 12.4 Bellekten kazanmak için yeniden numaralama

İkinci geçişte yalnız sık öğelerden oluşan çiftler sayılacağı için, bütün $n$ öğe için kurulan $\frac{n(n-1)}{2}$ hücreli üçgen matris yerine daha küçük bir üçgen matris yeterlidir. Hoca bunun için şöyle bir yöntem anlattı: bir tabloda bütün çiftlerin eski tek boyutlu dizideki konumları ile yalnız sık çiftler için kurulan yeni tek boyutlu dizideki konumları eşlenir. Örneğin eski dizide 1. konumdaki çift yeni dizide de 1. konumdadır; eski dizide 3. konumdaki çift yeni dizide 2. konuma karşılık gelir. Yeni dizide bir çiftin sayacına ulaşmak için önce eski üçgen matrisin konum formülüyle eski konum bulunur, tablodan yeni konum alınır ve sayaç orada artırılır. Böylece üçgen matris yaklaşımı yalnız sık öğelerden oluşan çiftler için kullanılmış olur.

> **Ek bilgi (derste anlatılmadı):** MMDS kitabında bu adım büyük olasılıkla öğe düzeyinde anlatılır: sık öğeler $1, \ldots, m$ diye yeniden numaralanır ve eski öğe numarasını yeni numaraya (sık değilse 0'a) eşleyen bir tablo tutulur. Üçgen matris sonra $m$ öğe için kurulur.

### 12.5 Genel akış ve daha büyük kümeler

Slayttaki akış şöyledir (ekrandan, 01:25:00):

```text
C1 (bütün öğeler)
  -> Filtre (birinci geçiş: öğeleri say)          -> L1 (sık öğeler)
  -> Oluştur (L1'den bütün çiftler)               -> C2 (aday çiftler)
  -> Filtre (ikinci geçiş: çiftleri say)          -> L2 (sık çiftler)
  -> Oluştur                                      -> C3 (aday üçlüler) -> ...
```

Bilinmeyen $n$ öğeden (tek öğeli kümeler) başlanır, bir geçiş yapılır ve destek eşiğinin üzerindekiler seçilir; bunlar sık öğelerdir. Sık öğelerden ikili adaylar (aday çiftler, $C_2$) oluşturulur; ikinci geçişte bunların sayaçlarına bakılır ve eşiğin üzerindekiler sık çiftler olur. Sonra aday üçlüler oluşturulur, sonraki geçişte onlar sayılır; filtreleme $C_3$'ten sonra da aynı biçimde sürer. Her aday küme için mutlaka bir geçiş, yani veri kümesinin bir kez okunması gerekir. Üçlüler ve dörtlüler için de çiftlerdeki gibi bellek ihtiyacı doğar. Ancak sahadaki problemlerde destek eşiği çok yüksek (%80-%90 üzeri) seçildiği için çok öğeli sık kümelerle karşılaşılmaz. Bu yüzden problem, A-Priori'nin büyük veri kümelerinde sık çiftleri bulmak için nasıl uygulanacağı problemine indirgenir.

A-Priori'nin özeti: birinci geçişte tek öğeleri sayar, sık olanları bırakıp diğerlerini siler; sık olanlardan bütün çiftleri oluşturur, ikinci geçişte bu çiftleri sayıp sık çiftleri bulur. Eksikliği: çift sayısı çok büyükse sınırlı bellekte algoritma çalıştırılamaz. Bu yüzden sık olmayacağı bilinen çiftleri saymamak gerekir; sıradaki algoritmalar A-Priori'nin bu yöndeki iyileştirmeleridir.

## 13. PCY Algoritması

### 13.1 Fikir

Park, Chen ve Yu tarafından önerilen PCY algoritması şunu önerir: birinci geçişte öğeler sayılırken belleğin geri kalanı boş bırakılmasın, orada bir **hash tablosu** kurulsun. Hash tablosunun büyüklüğü, algoritmanın kullanabileceği belleğin geri kalanı kadardır. Her sepette karşılaşılan bütün çiftler bu hash tablosunun **kovalarına (bucket)** eşlenir ve bir çift bir kovaya eşlendiğinde o kovanın sayacı bir artırılır.

Birinci geçiş bitince bir kovanın sayacı destek eşiğinden küçükse, o kovaya eşlenmiş çiftlerin hiçbirinin veride sık olmadığı bilinir. Bu çiftleri sonraki aşamada yeniden saymaya ve onlar için bellekte yer ayırmaya gerek yoktur.

### 13.2 Bitmap

Sayılmayacak çiftleri ayırmak için her kova bir **bit eşlemeyle (bitmap)** özetlenir: bitmap'in her hücresi bir kovaya karşılık gelir; kova sıksa 1, değilse 0 yazılır. Elde 0 ve 1'lerden oluşan bir bitmap kalır. Slayttaki resimde geçiş 1'de "öğe sayaçları" ve "hash tablosu", geçiş 2'de "sık öğeler", "bitmap" ve "aday çiftlerin sayaçları" vardır (ekrandan, 01:30:00).

### 13.3 İki geçiş

- **Geçiş 1:** Tek öğeler sayılır. Karşılaşılan her çift hash fonksiyonuyla bir kovaya eşlenir ve kovanın sayacı bir artırılır.
- **Geçiş 2:** Sık öğelerden bütün çiftler oluşturulur; bunlar aday çiftlerdir. Bir $\{i, j\}$ çifti ancak iki koşul sağlanırsa sayılır:
  - $i$ ve $j$ ikisi de sık öğedir (çiftler sık öğelerden oluşturulduğu için bu zaten sağlanır).
  - Çift aynı hash fonksiyonuyla eşlendiğinde düştüğü kovanın bitmap değeri 1'dir.

A-Priori'de sık öğelerden oluşan bütün çiftler sayılırdı; PCY'de önceki geçişten sık olmadığı bilinen çiftler sayım listesine konmaz, böylece sayılacak çift sayısı azalır. Algoritma sık çiftleri bulmaya indirgendiği için, ikinci geçişte bu adaylar sayılıp sık olanlar bulununca algoritma biter.

### 13.4 PCY'nin sorunları

Hash tablosunun büyüklüğü bellekle sınırlıdır, bu yüzden farklı çiftler aynı kovaya düşebilir:

- **Birinci durum:** Sık olmayan çok sayıda çift, hash fonksiyonu yüzünden tesadüfen aynı kovaya düşer. Her biri kovanın sayacını bir artırdığı için kova sayacı destek eşiğinin üstüne çıkar. Çiftlerin hiçbiri sık olmadığı halde PCY bunları sık adayı sayar ve onlar için gereksiz yere bellek ayrılır.
- **İkinci durum:** Sık bir çift bir kovaya eşlenir, ama aynı kovaya 4-5 sık olmayan çift de düşer. Sık çift yüzünden kovanın sayacı zaten eşiğin üstünde olacağından bitmap değeri 1 olur ve sık olmayan çiftler de ikinci geçişte sayılır.

Sonuç olarak PCY, A-Priori'ye göre bellek kazancı sağlar ama hâlâ sık olmayan çiftler için bellekte yer ayrılır; iyileştirmeye açıktır.

## 14. Çok Aşamalı (Multistage) Algoritma

Çok aşamalı algoritma da sonunda sık çiftleri bulur, ama iki yerine üç geçiş yaparak daha az bellekle çalışmayı hedefler (ekrandan, 01:40:00).

- **Geçiş 1:** PCY'deki gibidir. Öğeler sayılır, bütün çiftler birinci hash tablosunun kovalarına eşlenir ve kova sayaçları artırılır.
- **Geçiş 2:** Önce sık öğeler (sayacı destekten yüksek öğeler) bulunur. Sonra Bitmap 1 hesaplanır: bitmap'in eleman sayısı kova sayısı kadardır; sayacı destekten yüksek kovalara 1, diğerlerine 0 yazılır. Ardından ikinci bir hash tablosu kurulur ve çiftler bu tabloya, farklı bir hash fonksiyonuyla eşlenir. Ancak bir çift yalnız iki koşulu sağlarsa ikinci tabloya eşlenir: iki öğesi de sıktır ve çift birinci hash fonksiyonuyla Bitmap 1'de 1 olan bir kovaya düşer. Eşlenen çiftler için ilgili kovanın sayacı bir artırılır.
- **Geçiş 3:** Sık öğeler ve Bitmap 1 korunur; ikinci hash tablosundan Bitmap 2 oluşturulur (sayacı destekten yüksek kovalara 1, diğerlerine 0). Sayılacak çiftler sık öğelerden oluşturulur ve bir çift ancak üç koşulu sağlarsa sayılır:
  - İki öğesi de sıktır.
  - Birinci hash fonksiyonuyla düştüğü kovanın Bitmap 1 değeri 1'dir.
  - İkinci hash fonksiyonuyla düştüğü kovanın Bitmap 2 değeri 1'dir.

Bu koşullardan biri sağlanmazsa çift için sayaç ayrılmaz.

Böylece bellek ihtiyacı düşük bir ortamda üç geçişle sık çiftler bulunabilir. Ama bu algoritmanın da sorunu vardır: veriyi üç kez okur, yani diske üç kez erişip bütün veriyi üç kez tarar.

> **Hocanın vurgusu:** Bu tür algoritmaların maliyeti disk G/Ç erişim sayısıyla hesaplanır; ne kadar az disk erişimi o kadar iyi. Çok aşamalı algoritma daha az bellekle sık çiftleri bulur ama daha fazla zaman harcar.

## 15. Çok Karmalı (Multihash) Algoritma

Çok karmalı algoritma, çok aşamalı algoritmadaki "birden çok hash fonksiyonuyla aday çift sayısını azaltma" fikrini iki geçişle uygulamaya çalışır (ekrandan, 01:45:00).

- **Geçiş 1:** Veri okunurken tek öğelerin sayaçları artırılır. Aynı zamanda iki hash tablosu kurulur; ikisinde de PCY'deki gibi kovalar vardır ve birbirinden farklı (bağımsız) hash fonksiyonları kullanılır. Her sepetteki olası çiftler önce birinci, sonra ikinci hash tablosuna eşlenir ve ilgili kovaların sayaçları artırılır.
- **Geçiş 2 başı:** Birinci hash tablosunda sayacı destek değerinden büyük olan kovalar için Bitmap 1'de 1, diğerleri için 0 tutulur. Aynısı ikinci hash tablosu için Bitmap 2'de yapılır. Sık öğeler de belirlenir.
- **Geçiş 2:** Aday çiftler belirlenirken çok aşamalı algoritmanın son geçişindeki gibi üç koşula bakılır: çiftin iki öğesi de sıktır; çift birinci hash tablosuna eşlendiğinde düştüğü kovanın Bitmap 1 değeri 1'dir; ikinci tabloya eşlendiğinde düştüğü kovanın Bitmap 2 değeri 1'dir. Üç koşulu sağlayan aday çift için bellekte yer ayrılır ve sayılır.

Hash tablosu sayısı arttıkça gereksiz yere sayılan aday çift sayısı azalır; örneğin iki yerine beş hash tablosu kullanılırsa gereksiz sayılan aday çift sayısı daha da azalır.

> **Ek bilgi (derste anlatılmadı):** Çok karmalı algoritmada bütün hash tabloları birinci geçişte aynı belleği paylaştığı için her tablonun kova sayısı büyük olasılıkla azalır. Kova sayısı çok azalırsa kovaların çoğu sık hale gelir ve bitmap'ler eleme gücünü yitirir; bu yüzden hash tablosu sayısı sınırsız artırılamaz.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Öğeler {milk, coke, pepsi, beer, juice}, destek eşiği 3 sepettir. Sepetler $B_1=\{m,c,b\}$, $B_2=\{m,p,j\}$, $B_3=\{m,b\}$, $B_4=\{c,j\}$, $B_5=\{m,p,b\}$, $B_6=\{m,c,b,j\}$, $B_7=\{c,b,j\}$, $B_8=\{b,c\}$. Sık öğe kümelerini bulun.

> **Çözüm (derste verildi, sayımlar python ile doğrulandı):** Tek öğe sayıları $m$: 5, $c$: 5, $b$: 6, $j$: 4, $p$: 2; sık öğeler $\{m\}, \{c\}, \{b\}, \{j\}$. Çift sayıları $\{m,b\}$: 4, $\{b,c\}$: 4, $\{c,j\}$: 3; diğer çiftler en fazla 2. Sık öğe kümeleri: $\{m\}, \{c\}, \{b\}, \{j\}, \{m,b\}, \{b,c\}, \{c,j\}$. Üç öğeli kümelerin hiçbiri 3 sepete ulaşmaz.

**Soru 2** (ekrandan, 00:30:00): Aynı sepetlerde $\{m, b\} \to c$ birliktelik kuralının güveni nedir?

> **Çözüm (derste verildi):** $\{m,b\}$ içeren sepetler $B_1, B_3, B_5, B_6$ (4 sepet). Bunlardan $c$'yi de içerenler $B_1, B_6$ (2 sepet). Güven $= 2/4 = \%50$.

## Dersin Toparlaması

Ders, pazar sepeti modeliyle başladı: öğeler, sepetler, destek ve sık öğe kümeleri tanımlandı; pazarlama, intihal tespiti ve tweet'lerden haber bulma uygulamaları gösterildi. Sık kümelerden birliktelik kuralları çıkarıldı ve kuralların gücü güven ölçüsüyle değerlendirildi. Asıl zorluğun sık öğe kümelerini bulmak olduğu, bu işin maliyetinin disk geçişi sayısıyla ölçüldüğü ve darboğazın ana bellek olduğu vurgulandı. Uygulamada yüksek destek eşikleri nedeniyle problem sık çiftleri bulmaya indirgendi ve çiftlerin bellekte üçgen matrisle (çift başına 4 bayt) ya da üçlü tabloyla (görülen çift başına 12 bayt) sayılması karşılaştırıldı.

Ardından A-Priori algoritması monotonluk özelliğiyle iki geçişte sık çiftleri buldu; sık öğe sayısı büyük olduğunda bellek sorunu sürdüğü için iyileştirmelere geçildi. PCY, ilk geçişte belleğin boş kalan kısmını bir hash tablosuyla kullanıp bitmap ile aday çiftleri eledi; çok aşamalı algoritma ikinci bir hash tablosu ve üçüncü bir geçişle daha az bellek kullandı ama disk erişimini artırdı; çok karmalı algoritma ise birden çok bağımsız hash tablosunu ilk geçişte kullanarak iki geçişte kaldı. Bütün bu algoritmaların ortak amacı, sık olmayacağı bilinen çiftler için bellekte sayaç ayırmamaktır. Bir sonraki derste kümeleme (clustering) konusuna geçileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
