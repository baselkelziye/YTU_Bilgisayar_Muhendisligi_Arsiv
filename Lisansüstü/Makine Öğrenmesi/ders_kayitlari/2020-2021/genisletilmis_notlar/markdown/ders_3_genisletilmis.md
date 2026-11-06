# Ders 3 Genişletilmiş Notu: Karar Ağaçlarında Budama, Bayes Teoremi ve Naive Bayes Sınıflandırıcısı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Aşırı Öğrenmeye Kısa Bir Dönüş
- 2. Veriyi Üçe Bölmek: Eğitim, Doğrulama, Test
- 3. Azaltılmış Hata Budaması (Reduced Error Pruning)
- 4. Erken Durdurma (Early Stopping)
- 5. Kural Sonrası Budama (Rule Post-Pruning)
- 6. Karar Ağaçlarının Değerlendirmesi
- 7. Ayırt Edici ve Üretici Sınıflandırıcılar
- 8. Olasılık Hatırlatması
- 9. Bayes Teoremi ve En Büyük Sonsal Olasılık
- 10. Örnek: COVID Testi
- 11. Örnek: Monty Hall Problemi
- 12. Naive Bayes Sınıflandırıcısı
- 13. Örnek: Naive Bayes ile PlayTennis
- 14. Naive Bayes ile Belge Sınıflandırma

## 1. Aşırı Öğrenmeye Kısa Bir Dönüş

Ders, geçen haftanın son konusu olan karar ağaçlarında aşırı öğrenme (overfitting) ile başladı. Hoca önce kavramı bir kez daha toparladı.

Bir öğrenme sisteminin eğitimini tamamladığınızı ve eğitim başarısının %90 çıktığını düşünün. Bu iyi bir sonuçtur. Fakat modeli yeni örneklerle test ettiğinizde başarının %60-70'lere düştüğünü görüyorsunuz. Böyle bir durumda akla gelmesi gereken ilk şey aşırı öğrenmedir.

Aşırı öğrenme, gereğinden fazla öğrenmektir. Öğrenmeden kastedilen, öğrenilmesi istenen bilginin karakteristiklerinin anlaşılmasıdır. Karakteristikler anlaşılırsa, bilinmeyen bir örnek geldiğinde onun ne olduğu doğru tahmin edilir. Gereğinden fazla öğrenildiğinde ise sistem ezberlemeye kayar. Örneğin A sınıfına ait bir örnek, fazla ayrıntıyla öğrenildiği için karakteristiğini kaybeder ve B sınıfından sanılabilir.

Hoca bunu bir örnekle açıkladı. Kız ve erkek öğrencileri boy ve kilolarına göre ayıran bir sistem kurduğunuzu düşünün. Genel olarak kız öğrencilerin boyu 1,55 ile 1,75 m, kilosu 45 ile 100 kg arasında değişsin. Ama aykırı örnekler de vardır: 1,85 m boyunda 80 kg ya da 1,90 m boyunda 120 kg bir kız öğrenci. Bu örnekler aslında erkek öğrencilerin bilgilerine daha yakındır. "Modelim bunları da mutlaka doğru bilsin" derseniz, model yavaş yavaş sınıfın karakteristiğinden uzaklaşır. Bunu çok yaparsanız eğitimdeki bütün örnekleri %100'e yakın doğrulukla bilen, ama testte başarısı düşen bir model elde edersiniz.

Karar ağaçlarında aşırı öğrenmenin görünümü düğüm sayısının artmasıdır. Her şeyi doğru yapmaya çalışan ağaç, bütün şartları sağlamak için gittikçe büyür. Slayttaki grafikte yatay eksende ağaçtaki düğüm sayısı, dikey eksende başarı vardı. Koyu çizgi eğitim örneklerinin, kesikli çizgi test örneklerinin başarısını gösteriyordu. Düğüm sayısı 10'a, sonra 20'ye çıktıkça her iki başarı da artıyor. Düğüm sayısı artmaya devam ettikçe eğitim başarısı da yükselmeye devam ediyor. Test başarısı ise bir noktadan sonra önce sabit kalıyor, sonra düşmeye başlıyor. Düşmenin başladığı yer, aşırı öğrenmenin başladığı yerdir: Model bütün eğitim örneklerini öğrenmiştir, ama artık sınıfın karakteristiğini temsil etmemektedir.

<!-- BELİRSİZ: Grafikteki eksen değerleri ve eğrilerin tam biçimi slaytta; altyazıda yalnız 10 ve 20 düğüm değerleri sözlü geçiyor. -->

Aşırı öğrenmenin olası sebepleri:

- **Gürültülü (noisy) veri.** Hoca burada "gürültü" kelimesinin sinyal işlemedeki parazit gibi düşünülmemesini istedi. Kastedilen, örnek kümesindeki diğer örneklere benzemeyen veridir. 1,90 m boyunda, 90 kg bir kız öğrenci, o sınıf için böyle bir örnektir.
- **Küçük eğitim kümesi.** Örnek sayısı azsa karakteristikler yakalanamayabilir. Şanslıysanız az sayıda örnek bile karakteristiği gösterir, ama genellikle bu kadar şanslı olunmaz.

Karar ağacının kendine özgü bir sorunu da vardır: Öğrenme, bütün yapraklarda yalnızca tek bir sınıf kalana kadar sürer. Model ancak böyle tamamlanır. Bu yüzden ağaç aşırı öğrenmeye yatkındır. Peki eğitimde aşırı öğrenme olmaması için ne yapılmalı? Hoca bunun için genellikle kullanılan üç yolu saydı: azaltılmış hata budaması (reduced error pruning), erken durdurma (early stopping) ve kural sonrası budama (rule post-pruning).

## 2. Veriyi Üçe Bölmek: Eğitim, Doğrulama, Test

Budamanın neye göre yapılacağını anlatmadan önce hoca, örneklerin eğitim ve test için nasıl kullanıldığını basitçe anlattı. Bu konu ileriki haftalarda (çapraz doğrulama, cross-validation gibi yöntemlerle) ayrıntılı işlenecek.

Elinizde 100 örnek olsun. Bu örnekler hem eğitim hem test için kullanılacaktır. Azaltılmış hata budamasında örnekler üç parçaya ayrılır: eğitim (training), doğrulama (validation) ve test. Genelde örneklerin %70'i eğitim tarafına, %30'u test için ayrılır. Eğitim tarafındaki %70'lik kısım da kendi içinde bölünür: Örneğin bunun %60'ı eğitim, %40'ı doğrulama için kullanılır.

Üç parçanın görevleri birbirine karışmaz:

- **Eğitim örnekleri** modeli eğitmek için kullanılır.
- **Doğrulama örnekleri** eğitilmiş modeli iyileştirmek için kullanılır.
- **Test örnekleri** iş bittikten sonra başarıyı bağımsız olarak ölçmek ve modelin başarısını raporlamak için kullanılır.

> **Ek bilgi (derste anlatılmadı):** Hocanın oranlarıyla 100 örnekten yaklaşık 42'si eğitim ($70 \times 0{,}6$), 28'i doğrulama ($70 \times 0{,}4$), 30'u test için ayrılmış olur.

## 3. Azaltılmış Hata Budaması (Reduced Error Pruning)

### 3.1 Yöntemin mantığı

Bu yöntemde önce ağaç eğitim örnekleriyle tam olarak kurulur, sonra budanır. Budamaya yapraklardan başlanır ve yukarı doğru ilerlenir. Her budamadan sonra doğrulama örnekleriyle başarı ölçülür. Başarı iyileştiği sürece budamaya devam edilir. Artık bir şey değişmediğinde ya da başarı düşmeye başladığında, bu karakteristiklerin bozulmaya başladığını gösterir. O noktada budama kesilir.

### 3.2 Aşırı öğrenmeye yol açan bir örnek

Hoca, geçen haftaki PlayTennis (tenis oynansın mı, oynanmasın mı) ağacını kullandı. Eğitimi tamamlanmış ağaç şöyleydi:

```text
Outlook
+-- Sunny    -> Humidity
|                +-- High   -> No
|                +-- Normal -> Yes
+-- Overcast -> Yes
+-- Rain     -> Wind
                 +-- Weak   -> Yes
                 +-- Strong -> No
```

Ağaç bu haldeyken şöyle bir eğitim örneği daha geldiğini düşünün: Outlook = Sunny, Temperature = Hot, Humidity = Normal, Wind = Strong, PlayTennis = No. Ağaçta "Outlook Sunny ve Humidity Normal ise Yes" yazıyor. Yeni örnek ise aynı koşulda "No" diyor. Artık bu yaprakta hem Yes hem No olduğu için ağaç bu daldan aşağı doğru uzamak zorunda kalır. Sorun budur: Tek bir aykırı örnek ağacı büyütür.

### 3.3 Adım adım budama

Başlangıçta eğitimi tamamlanmış ağacın doğrulama örnekleriyle ölçülen başarısı **%75**'tir.

**Adım 1: Sunny dalını buda.** Sunny dalının altındaki Humidity düğümü kaldırılır ve Sunny dalı doğrudan bir yaprak olur. Yaprağa hangi sınıfın yazılacağına çoğunluğa bakılarak karar verilir. Hocanın örneğinde, nem yüksekken 3 gün tenis oynanmamış, 1 gün oynanmış. Çoğunluk "oynamadı" olduğu için yaprak **Don't Play (No)** olarak etiketlenir. Yani "Outlook Sunny iken oynamadı" denir. Budanmış ağaç doğrulama örnekleriyle yeniden ölçülür ve başarı **%80** çıkar. Başarı arttığına göre bu dalı budamanın faydası görülmüştür; budama korunur.

**Adım 2: Overcast dalı.** Bu dal zaten tek bir yapraktır (Overcast ise oynanmış). Altında uzayan bir ağaç olmadığı için yapılacak bir şey yoktur.

**Adım 3: Rain dalını buda.** Rain dalının altındaki Wind düğümü kaldırılır. Yine çoğunluğa bakılır: Hocanın örneğinde rüzgar Strong iken 2 gün oynanmamış, Weak iken 6 gün oynanmış. Çoğunluk "oynadı" olduğu için yaprak **Play (Yes)** olur: "Outlook Rain iken oynadı." Burada önemli bir ayrıntı var: Bu deneme, sol taraf (Sunny dalı) budanmadan, orijinal ağaç üzerinden yapılır. Doğrulama başarısı **%70** çıkar. Orijinal ağacın başarısı %75'ti. Başarı düştüğüne göre bu dalı budamak iyi gelmemiştir; Rain dalı budanmaz.

Hoca ayrıca şunu belirtti: Sol taraf budanmış haldeyken sağ tarafı budamayı da deneyebilirsiniz, ama bir faydası olmadığını görürsünüz. Çünkü iki dal birbirinden tamamen farklı kuralları değerlendirir; biri Outlook Sunny durumunu, öbürü Outlook Rain durumunu. Bu yüzden birbirlerini etkilemezler.

Sonuçta Sunny dalı budanmış ağaç, %80 doğrulama başarısıyla modelin yeni hali olarak kabul edilir. Son adım, olaya hiç karışmamış test örnekleriyle başarıyı ölçmek ve "bu karar ağacının doğruluğu (accuracy) şu kadardır" demektir.

> **Hocanın vurgusu:** Eğitim örnekleriyle eğittiniz, doğrulama örnekleriyle budayıp son halini verdiniz. Modelin eğitiminde ve düzeltilmesinde hiçbir şekilde kullanılmamış bağımsız bir veriyle de test ettiniz.

**Soru:** Budama yaparken eğitim örneklerine bakarak mı karar veriyoruz, doğrulama verisine bakarak mı?

**Cevap:** Doğrulama verisine. Eğitim bittikten sonra eğitim örnekleriyle hiç işiniz yoktur; onları kullanmak durumu karıştırır. Model eğitimde %90 başarı vermiş olabilir. Doğrulama örnekleriyle ölçtüğünüzde %75 çıkması, modelin eğitim örneklerini çok iyi öğrendiğini ama yeni örneklerde aynı başarıyı göstermediğini anlatır. Doğrulama kümesi de aslında bir tür test kümesidir; onunla yalnızca ölçüm yaparsınız. Budamanın faydasını da yine onunla görürsünüz.

> **Hocanın vurgusu:** Doğrulama her zaman böyledir: Eğitimle oluşturduğunuz modelin ince ayarının yapılmasıdır. Model karar ağacı da olabilir, k-en yakın komşu da; hangi yöntemi kullanıyorsanız, doğrulamada onun sonuçlarını iyileştirirsiniz (ağaçsa budarsınız, farklı parametreler denersiniz).

### 3.4 Budamanın grafikteki görünümü

Slayttaki ikinci grafikte budama sırasında doğrulama başarısı ve test başarısı gösteriliyordu. Budamaya devam ettikçe başarı yükseliyor. Bir noktadan sonra budamak başarıyı değiştirmiyor; budama orada kesilebilir. Hoca, fazla budanırsa başarının yine düşebileceğini, örnekteki ağacın yaklaşık 20 düğüm varken iyi olduğunu ve 20'nin altına inmenin bir şey kazandırmadığını söyledi.

<!-- BELİRSİZ: Budama grafiğindeki eğrilerin renkleri ve tam değerleri slaytta; altyazıdan yalnız "yaklaşık 20 düğüm" anlaşılıyor. -->

## 4. Erken Durdurma (Early Stopping)

Erken durdurmada ağaç büyütülürken başarı ölçülerek ilerlenir. Her yeni alt düğüm eklendiğinde başarı hesaplanır ve kaydedilir. Ağaç yine eğitim verisiyle sonuna kadar kurulur. Ağaç bittikten sonra başarının düşmeye başladığı noktadaki ağaca geri dönülür ve "sınıflandırıcım budur" denir.

Slayttaki grafikte siyah çizgi eğitim verisini, kırmızı çizgi test verisini, yeşil çizgi doğrulama verisini gösteriyordu. Eğitim başarısı yüksek kalmaya devam ederken belli bir noktadan sonra hem doğrulama hem test başarısı düşüyordu. Ağaç o noktada kesilmişti.

İki yöntemin farkı şudur:

- **Azaltılmış hata budamasında** ağaç önce kurulur, sonra budaya budaya geri dönülür.
- **Erken durdurmada** ağaç kurulurken başarı hesaplana hesaplana kurulur; ağaç bitince başarının en uygun olduğu yerde kesilir.

Hocaya göre erken durdurma çok pratik değildir, çünkü her aşamada bir sürü bilgi tutmak gerekir. Budamak daha etkilidir.

## 5. Kural Sonrası Budama (Rule Post-Pruning)

Üçüncü yöntemde de veri eğitim, doğrulama ve test olarak üçe ayrılır. Hoca, slaytta yalnızca "train" ve "validation" yazsa da başarı ölçmek için üç parçaya ayırmanın doğrusu olduğunu belirtti.

Yöntemin adımları:

1. Ağaç eğitim verisiyle kurulur.
2. Eğitimi tamamlanmış ağaç kurallara çevrilir. Örneğin: "Outlook Sunny ve Humidity High ise Don't Play", "Outlook Sunny ve Humidity Normal ise Play", "Outlook Overcast ise Play".
3. Her kural için doğrulama başarısı hesaplanır. Kurallar birbirinden bağımsız olarak değerlendirilir.
4. Başarıyı artıran kurallar korunur, başarıyı düşüren kurallar elenir. Örneğin slayttaki örnekte "Humidity High ise Don't Play" kuralı doğrulama başarısını %75'e çıkarıyormuş; bu kural mutlaka kullanılmalıdır.
5. Kurallar başarılarına göre büyükten küçüğe sıralanır. Belli bir başarı seviyesinin altındaki kurallar atılabilir. Kalan kurallarla model oluşturulur.

Hoca bu yöntemin de azaltılmış hata budamasına benzediğini söyledi: Burada da her parça için ayrı ayrı başarı hesaplanır. Slaytta da belirtildiği gibi kural sonrası budama çok kullanılan yöntemlerden biridir. Hoca ise kendisi azaltılmış hata budamasını tercih ettiğini, çünkü işlem açısından çok daha kolay olduğunu söyledi.

## 6. Karar Ağaçlarının Değerlendirmesi

Budamadan sonra hoca, karar ağaçlarıyla ilgili bilgileri toparladı.

### 6.1 Avantajlar

- **Doğrusal ayrılamayan sınıflar için etkili karar sınırları.** Dersin başında gösterilen, sınırı çok belli olmayan ve doğrusal olarak ayrılamayan sınıfları hatırlayın. Bunları doğrusal olmayan biçimde ayırmak için normalde bağıntılar kurmak gerekir. Karar ağacı ise bu ayrımı basit kontrollerle (eğer-ise) yapar. Hoca bunu karar ağacının başarısının önemli sebeplerinden biri olarak gösterdi.
- **Kategorik özelliklerle doğrudan çalışabilmek.** Kategorik özelliklerin sayısal özelliklere nasıl çevrildiği ve bunun getirdiği sorunlar ileriki haftalarda işlenecek. Karar ağacı bu çevirmeye gerek duymaz.
- **Sürekli özelliklerle eşik değerleri üzerinden çalışabilmek.** Örneğin sıcaklık 20 ile 50 derece arasında değişiyorsa, "sıcaklık 20'den büyükse oyna, değilse oynama" gibi eşiklerle karar verilebilir.
- **Kurallara çevrilebilmek.**
- **Budama ile gürültülü veriden kurtulabilmek.**
- **Hız.** Algoritma derslerinden hatırlanacağı gibi ağaçların en önemli avantajlarından biri, ağacın bir dalına girildiğinde öbür dalların hiç değerlendirilmeden elenmesidir. Örneğin Outlook Sunny ise diğer dallara hiç bakılmaz. Bir grup bilgiyi değerlendirmeden eleyebilmek, özellikle büyük ağaçlarda hız açısından önemli bir avantajdır.

### 6.2 Dezavantajlar

- **Büyük ağaçları anlamak zordur.** Çok büyük bir karar ağacını kurallara çevirmek ve anlamak zorlaşır.
- **Artımlı (incremental) değildir.** Ağaca yeni örnekler geldiğinde, ağacı yeni örneğe göre aşağı doğru büyütmeye çalışmak sorunludur; genellikle ağacın yeniden oluşturulması gerekir.
- **Özellik sayısı sabit ve baştan bilinmelidir.** Karar ağacında her düğüm bir özelliktir; bu yüzden özellik vektörünün uzunluğu sabit olmalıdır. Örneğin 8 özellik varsa ağaç 8 özellikle çalışır. Hoca bunu çok önemli bir dezavantaj olarak görmediğini söyledi.

Sonuç olarak karar ağaçları çok sık kullanılan ve çok başarılı yöntemlerden biridir.

## 7. Ayırt Edici ve Üretici Sınıflandırıcılar

Karar ağaçlarından sonra hoca Bayes teoremine geçti. Derste anlatmak için genellikle en başarılı ve en çok kullanılan modelleri seçtiğini, Bayes yönteminin de bunlardan biri olduğunu söyledi.

İki sınıfımız olsun: filler ve ayılar. Eğitmenli öğrenmede elimizde özellikler ve etiketler vardır. Amacımız, özellikleri verilen bilinmeyen bir örneğin hangi sınıfa ait olduğunu belirlemektir. Örneğin boyu şu kadar, ağırlığı bu kadar, rengi de böyle olan bir hayvan gördünüz; bu fil midir, ayı mıdır? Bunu yapan iki tür sınıflandırıcı vardır.

### 7.1 Ayırt edici (discriminative) sınıflandırıcılar

Ayırt edici sınıflandırıcılar, bilinmeyen örneğin özelliklerinden yola çıkıp doğrudan sınıfa gider. Eğitimde örneklerin özelliklerine karşılık gelen sınıf öğrenilir. Bilinmeyen bir örnek geldiğinde, onun özelliklerine bakılarak "bu fildir" denir ve iş biter. k-en yakın komşu (k-nearest neighbor), yapay sinir ağları, doğrusal regresyon ve bu derslerde görülen karar ağaçları bu türdendir. Bilinen yöntemlerin çoğu böyle çalışır.

### 7.2 Üretici (generative) sınıflandırıcılar

Üretici sınıflandırıcılar ters yönde çalışır. Sınıftan yola çıkarak geriye gidilir:

- "Hayvan fil ise, boyunun böyle, ağırlığının şöyle, renginin de böyle olma olasılığı nedir?"
- "Hayvan ayı ise, bu bilgilerin olasılığı nedir?"

Böylece eldeki örneğin hangi sınıfa daha çok benzediği bulunmaya çalışılır. Hangi sınıfa daha çok benziyorsa örnek o sınıfa atanır. Matematiksel olarak, verilen $y$ sınıfı için $x$ özelliklerinin olasılığı, yani $P(x \mid y)$ bulunarak ilerlenir. Bu türün en bilinen yöntemi Bayes yöntemidir. Naive Bayes ve Saklı Markov Modeli (Hidden Markov Model) de aynı şekilde çalışır.

Özetle: Ayırt edici yöntemlerde verilen özellikler için doğrudan "şu sınıfa aittir" denir. Üretici yöntemlerde ise her sınıftan yola çıkılarak örneğin o sınıfa ne kadar benzediği bulunur.

Hoca bu noktada slayt üzerinden anlatmayı bırakıp tablette yazarak anlatmaya geçti.

## 8. Olasılık Hatırlatması

Bayes teoremi olasılığa dayalı bir yaklaşım olduğu için hoca önce temel olasılık bilgilerini hatırlattı. (Kayıtta bu bölüm, bağlantı sorunu nedeniyle dosyanın sonunda yer alıyor; konu sırasına göre buraya alınmıştır.)

### 8.1 Örnek uzayı ve olasılık

$S$ örnek uzayımız (sample space) olsun. Örnek uzayı, problemde alınabilecek bütün değerleri gösterir. Örneğin bir oyun zarından bahsediyorsak $S = \{1, 2, 3, 4, 5, 6\}$ olur, çünkü zarın altı yüzü vardır. (Hoca önce "özellik uzayı" deyip sonra "örnek uzayı" diye düzeltti.)

$A$ rastgele değişkeni (random variable), bu uzayda alınabilecek değerlerden herhangi biridir. $P(A)$, mümkün bütün olaylar içinde $A$'nın olma olasılığıdır. Örneğin zarın 4 gelme olasılığı $P(A = 4) = 1/6$'dır.

Her zaman şu iki kural geçerlidir:

- Bir olasılık değeri 0 ile 1 arasındadır: $0 \le P(A) \le 1$.
- Örnek uzayındaki bütün olasılıkların toplamı 1'dir.

### 8.2 Bağımlı ve bağımsız olaylar

Değişkenler için iki durum söz konusudur: birbirleriyle bağlantılı (bağımlı) olabilirler ya da bağlantısız (bağımsız, independent) olabilirler.

- **Bağımlı olaylar:** Bir öğrencinin lisansüstü giriş sınavını kazanması ve yüksek mühendis olması birbiriyle bağlantılı iki olaydır.
- **Bağımsız olaylar:** Hoca burada paranın yazı gelmesi ile tura gelmesini örnek verdi (bu örnek için Ders Sonrası Notlar'a bakın).

### 8.3 Birleşik olasılık

Birleşik olasılık (joint probability), iki olayın birlikte doğru olma olasılığıdır. Örneğin grip belirtilerinden söz ederken başınızın ağrıması ve aynı anda burnunuzun akması. Bu, $A \cap B$ ile gösterilir. Örnek uzayı $S$ içinde $A$ ve $B$ kümelerini düşünürsek, bu kümeler kesişebilir ya da kesişimleri boş küme olabilir. Kesişim varsa:

$$P(A \cap B) = P(A \mid B)\,P(B)$$

### 8.4 Koşullu olasılık

Buradaki yeni kavram koşullu olasılıktır (conditional probability): $B$ gerçekleşmişken $A$'nın olma olasılığı, $P(A \mid B)$. $P(B) > 0$ iken:

$$P(A \mid B) = \frac{P(A \cap B)}{P(B)}$$

$B$ şartı sağlanırken $A$'nın olma olasılığı, $A$ ile $B$'nin birlikte olma olasılığının $B$'nin olasılığına bölümüdür. $P(B)$'ye bölmenin sebebi normalizasyonu sağlamaktır.

> **Hocanın vurgusu:** Bu tanımları genelde biliyorsunuzdur, ama mutlaka aklınızda tutmaya çalışın.

Hocanın örneği: Bir kişide baş ağrısı olma olasılığı $1/10$, nezle olma olasılığı $1/40$ olsun. Nezle olan birinde baş ağrısı olma olasılığı ise $1/2$ olsun. Son değer bir koşullu olasılıktır: $P(\text{baş ağrısı} \mid \text{nezle}) = 1/2$.

$A$ ve $B$ bağımsız iki olay ise, $B$'nin gerçekleşmesi $A$'nın olasılığını değiştirmez:

$$P(A \mid B) = P(A)$$

## 9. Bayes Teoremi ve En Büyük Sonsal Olasılık

### 9.1 Sezgi: Kiraz ve erik yaprağı

Bir bahçede 200 kiraz ağacı ve 120 erik ağacı olsun. Yerde bir yaprak buluyorsunuz. Ne kiraz ağacının yaprağını tanıyorsunuz ne de erik ağacının. Yaprak hangi ağaca aittir?

Derste öğrencilerin cevabı "kiraz" oldu. Neden kiraz? Çünkü yaprağın kiraza ait olma olasılığı $200/320$, eriğe ait olma olasılığı $120/320$'dir:

$$P(\text{kiraz}) = \frac{200}{320} = 0{,}625, \qquad P(\text{erik}) = \frac{120}{320} = 0{,}375$$

$200/320$ daha büyük olduğu için "kiraz" demek şansınızı artırır. Kiraz olmayabilir de, ama kiraz demek en iyi tahmindir.

Burada yalnızca kiraz ağaçlarının sayıca fazla olmasından yola çıkılıyor. Oysa yaprağı görüyorsunuz. Yaprak ince uzun olabilir; sonbaharda bazı yapraklar kırmızı, bazıları sarı olur, diyelim ki yaprak kırmızı. Gözlemlediğiniz özellikler de var. Hem ağaçların sayısından gelen bilgiyi hem de gözlemlediğiniz özellikleri kullanırsanız daha başarılı bir sınıflandırma yaparsınız. Bayes teoremi bu fikre dayanır.

### 9.2 Teorem

Bayes teoremi, $B$ şartı sağlanırken $A$ durumunun olma olasılığını şöyle verir: $A$ şartı sağlanırken $B$'nin olma olasılığı çarpı $A$'nın olasılığı, bölü $B$'nin olasılığı.

$$P(A \mid B) = \frac{P(B \mid A)\,P(A)}{P(B)}$$

Sınıflandırma diliyle yazarsak, $A$ merak ettiğimiz sınıf (kiraz mı, erik mi), $B$ ise gözlemlediğimiz veri, yani yaprağın özellikleridir:

$$P(\text{sınıf} \mid \text{veri}) = \frac{P(\text{veri} \mid \text{sınıf})\,P(\text{sınıf})}{P(\text{veri})}$$

Formüldeki her terimin anlamı:

- **Önceki olasılık (prior), $P(\text{sınıf})$:** Elimizde önceden olan bilgi. Sınıfların olasılıklarını biliyoruz: $P(\text{kiraz})$ ve $P(\text{erik})$.
- **Olabilirlik (likelihood), $P(\text{veri} \mid \text{sınıf})$:** Sınıf verilmişken gözlenen özelliklerin olasılığı. Örneğin kiraz ağacının yapraklarının kırmızı ve ince olma olasılığı, erik ağacının yapraklarının kırmızı ve ince olma olasılığı. Bu bilgileri önceden toplamışızdır; elimizde vardır.
- **Sonsal olasılık (posterior), $P(\text{sınıf} \mid \text{veri})$:** Bulmak istediğimiz şey. Özellikleri gözlenen yaprağın bu sınıfa ait olma olasılığı.

Yaprak için iki hesap yapılır. Kiraz ağacı için: bu özelliklerin kiraz ağacında görülme olasılığı ile kiraz ağacının olasılığı çarpılır, verinin olasılığına bölünür. Erik ağacı için de aynısı yapılır. Hangisinin olasılığı daha büyükse örnek o sınıfa aittir.

> **Hocanın vurgusu:** Burada yaptığımız şey, sınıftan geriye doğru giderek, elimizdeki özelliklere göre örneğin hangi sınıfa daha çok benzediğini bulmaktır. Bayes teoremiyle yapılan budur.

### 9.3 En büyük sonsal olasılık (MAP) kestirimi

Sınıflar $A_1$ (kiraz) ve $A_2$ (erik) olsun. Her iki sınıfın hesabında da payda $P(B)$, yani gözlenen verinin olasılığıdır. Payda her iki tarafta ortak olduğu için hangi tarafın daha büyük çıkacağını değiştirmez; zaten normalizasyon için kullanılır. Bu yüzden karşılaştırma yaparken atılabilir. Bilinmeyen sınıfı bulmak için bütün sınıflarda olasılıkları hesaplamak ve en büyüğünü almak yeterlidir.

$y_1, y_2, \dots, y_n$ sınıflar, $x$ gözlenen özellikler olmak üzere:

$$\hat{y}_{MAP} = \arg\max_{y_j} P(y_j \mid x) = \arg\max_{y_j} P(x \mid y_j)\,P(y_j)$$

Buna en büyük sonsal olasılık (maximum a posteriori, MAP) kestirimi denir.

## 10. Örnek: COVID Testi

Hoca Bayes teoremini dönemin gündemindeki COVID üzerinden bir örnekle uyguladı. (Bağlantı sorunu nedeniyle bu örnek derste baştan iki kez anlatıldı; burada tek ve tam haliyle verilmiştir.)

**Verilenler:**

- Toplumda bulunan kişilerin binde 8'inde COVID var: $P(C) = 0{,}008$. Dolayısıyla binde 992'si sağlam: $P(\neg C) = 0{,}992$.
- Gerçekten COVID olanların testinin pozitif çıkma olasılığı %98: $P(+ \mid C) = 0{,}98$. Hoca bunun gerçek pozitif (true positive) durumu olduğunu belirtti.
- Gerçekten COVID olmayanların testinin negatif çıkma olasılığı %97: $P(- \mid \neg C) = 0{,}97$.

**Soru:** Bir kişi test yaptırıyor ve test pozitif çıkıyor. Bu kişi COVID midir, değil midir?

**Çözüm.** İki sınıfımız var: COVID olanlar ve olmayanlar. Önce eldeki bilgilerden eksik olasılıkları çıkaralım. COVID olanların %98'inin testi pozitif çıkıyorsa, %2'sinin testi negatif çıkar: $P(- \mid C) = 0{,}02$. COVID olmayanların %97'sinin testi negatif çıkıyorsa, %3'ünün testi pozitif çıkar: $P(+ \mid \neg C) = 0{,}03$.

Bulmak istediğimiz, test pozitifken COVID olma ve COVID olmama olasılıklarından hangisinin büyük olduğudur:

$$\arg\max \left\{ P(C \mid +),\; P(\neg C \mid +) \right\}$$

Bayes teoremiyle her ikisinin paydasında $P(+)$ vardır; ortak olduğu için atılır. Geriye şu iki çarpım kalır:

$$P(+ \mid C)\,P(C) = 0{,}98 \times 0{,}008 = 0{,}00784$$

$$P(+ \mid \neg C)\,P(\neg C) = 0{,}03 \times 0{,}992 = 0{,}02976$$

$0{,}02976 > 0{,}00784$ olduğu için, test pozitif çıkmasına rağmen bu kişiye **"COVID değildir"** denir. Gözlem test sonucuydu; test sonucu verildiğinde örneğin hangi sınıfa daha çok benzediği Bayes teoremiyle ölçülmüş oldu.

> **Ek bilgi (derste anlatılmadı):** İki değer normalize edilirse $P(C \mid +) = 0{,}00784 / (0{,}00784 + 0{,}02976) \approx 0{,}21$ bulunur. Yani testi pozitif çıkan birinin gerçekten hasta olma olasılığı bu verilerle yaklaşık %21'dir.

**Soru:** Bu sonuca göre testi pozitif çıkan birine "COVID değilsin" demiş olduk. Bu bir sorun değil mi?

**Cevap:** Maalesef öyle; örnek tam da bunu göstermek için seçildi. Sorunun kaynağı toplumdaki oranlardır. COVID olmayanların olasılığı çok yüksektir: Bin kişiden 992'si sağlamdır. Yapılan hata, COVID olmayan insanlara pozitif denmesidir ve bunun olasılığı %3'tür. 992 kişinin %3'üne yanlışlıkla pozitif dendiğinde, bu yanlış pozitiflerin sayısı gerçek hastaların sayısından fazla olur. Bu yüzden pozitif çıkan biri için "hasta değil" olasılığı daha yüksek çıkar.

**Soru:** Toplumdaki bütün insanların sayısı yerine yalnızca vaka sayısını kullansak daha doğru sonuç elde etmez miyiz?

**Cevap:** %98 zaten yalnızca vakalara ilişkin bir değerdir: COVID olduğu bilinen kişilerde testin pozitif çıkma oranıdır. "COVID olduğunu biliyorsak testin pozitif çıkması zaten beklenir; bu bir çelişki değil mi?" diye düşünülebilir. Hoca, hastalığın testten bağımsız yollarla da doğrulandığını anlattı: akciğer görüntülemesindeki tipik bulgular, art arda yapılan testler, hastalık belirtilerinin tam olarak görülmesi gibi. Bir öğrencinin "binde 8 bilgisi de böyle mi elde ediliyor?" sorusuna da hoca, testin dışında başka bir yöntemle doğrulama yapılması gerektiğini, ayrıca bu yolla hiç ölçülemeyen vakaların da mutlaka olduğunu söyledi.

## 11. Örnek: Monty Hall Problemi

Bayes teoremiyle çözülen ikinci örnek, televizyondaki yarışma programlarından bilinen Monty Hall problemidir.

**Problem.** Üç kapı var. İki kapının arkasında keçi, bir kapının arkasında araba var. Yarışmacı A kapısını seçiyor. Sunucu Monty, arkasında araba olmayan kapılardan birini açıyor. Sonra yarışmacıya soruyor: "A'da mı kalacaksın, diğer kapıya mı geçeceksin?" Hangisi daha kârlıdır?

Derste önce tahminler alındı. Bazı öğrenciler A'da kalmayı, bazıları değiştirmeyi önerdi. Bir öğrenci "başta her kapı %33'tü, biri açılınca diğerinin olasılığı %66'ya çıkmadı mı?" diye düşündü. Hoca, soruyu Bayes teoremiyle birlikte çözmeyi önerdi.

Hoca soruyu ilk sorduğunda "Monty C kapısını açıyor" dedi. Çözüme geçerken karıştırmamak için açılan kapıyı B olarak aldı. Aşağıdaki çözüm bu ikinci haliyledir: Yarışmacı A'yı seçti, Monty B'yi açtı.

**Önceki olasılıklar.** İşe başladığımızda arabanın hangi kapının arkasında olduğuna dair hiçbir bilgimiz yoktur. Bütün kapıların olasılığı eşittir:

$$P(A) = P(B) = P(C) = \frac{1}{3}$$

Burada $A$, $B$, $C$ "araba A'nın / B'nin / C'nin arkasında" sınıflarıdır. Dışarıdan gelen veri ise "B kapısı açıldı" bilgisidir.

**Olabilirlikler.** Arabanın yerine göre Monty'nin B kapısını açma olasılığı:

- **Araba A'nın arkasındaysa:** Yarışmacı A'yı seçtiği için Monty A'yı açamaz. B ve C'nin ikisinde de keçi var; hangisini açacağı eşit olasılıklıdır. $P(B \text{ açılır} \mid A) = \dfrac{1}{2}$.
- **Araba B'nin arkasındaysa:** Monty arabanın olduğu kapıyı açmaz. $P(B \text{ açılır} \mid B) = 0$.
- **Araba C'nin arkasındaysa:** Monty A'yı açamaz (yarışmacı seçti), C'yi de açamaz (araba orada). Yapabileceği tek şey B'yi açmaktır. $P(B \text{ açılır} \mid C) = 1$.

**Karşılaştırma.** B açıldığına göre arabanın B'de olma olasılığı sıfırdır; karşılaştırılacak iki sınıf A ve C'dir. Payda olan $P(B \text{ açılır})$ ortak olduğu için atılır:

$$P(B \text{ açılır} \mid A)\,P(A) = \frac{1}{2} \cdot \frac{1}{3} = \frac{1}{6}$$

$$P(B \text{ açılır} \mid C)\,P(C) = 1 \cdot \frac{1}{3} = \frac{1}{3}$$

$\dfrac{1}{3} > \dfrac{1}{6}$ olduğu için **yarışmacı kapı değiştirmeli, C'ye geçmelidir.**

> **Ek bilgi (derste anlatılmadı):** İki değer normalize edilirse $P(A \mid B \text{ açıldı}) = 1/3$, $P(C \mid B \text{ açıldı}) = 2/3$ bulunur. Yani kapı değiştiren yarışmacı 2/3 olasılıkla kazanır.

Mantık COVID örneğindekiyle aynıdır: Dışarıdan verilen bilgi (B kapısının açılmış olması) ve her sınıf için bu bilginin olasılığı kullanılarak, hangi sınıfın daha olası olduğu bulunur.

## 12. Naive Bayes Sınıflandırıcısı

İkinci aradan sonra hoca Naive Bayes sınıflandırıcısına (Naive Bayes classifier) geçti.

### 12.1 Bağımsızlık varsayımı

Elimizdeki verideki özellikler çok fazla olsun ve bunların birbirlerine göre durumlarını bilmeyelim. Bu özellikler aslında birbirine bağlı olabilir. Örneğin soğuk algınlığında farklı belirtiler vardır. Ateşi varken burnunun akma olasılığı, kas ağrısı varken burnunun akma olasılığı gibi özelliklerin birbirlerine göre koşullu olasılıklarını bulmak gerçekten zor ve sorunlu bir iştir.

Bunun yerine şu varsayım yapılır: Bütün özellikler birbirinden bağımsız olsun. Eğer bunu dersek, $C$ sınıfında $x_1$'den $x_5$'e beş özellik varsa, $C$ sınıfında bu özelliklerin birlikte görülme olasılığı, her özelliğin $C$ sınıfında görülme olasılıklarının çarpımına eşit olur. Örneğin sınıf kiraz ağacıyken yaprağın kırmızı, ince vb. olma olasılığı:

$$P(x_1, x_2, \dots, x_5 \mid C) = P(x_1 \mid C)\,P(x_2 \mid C)\,P(x_3 \mid C)\,P(x_4 \mid C)\,P(x_5 \mid C)$$

Yani koşullu olasılık yine kullanılır, ama her özellik için ayrı ayrı: $C$ sınıfı için $x_1$'in olasılığı çarpı $C$ sınıfı için $x_2$'nin olasılığı, ve böyle devam eder. Özelliklerin birbirinden bağımsız olduğu varsayılarak yapılan bu sınıflandırmaya Naive Bayes sınıflandırıcısı denir. "Naive" (saf) adı, yaklaşımın basit ve karmaşık olmamasından gelir.

Bu varsayımın her zaman doğru olmayabileceği unutulmamalıdır. Hoca bir metin örneği verdi: "Donald Trump" ifadesinde "Donald" ve "Trump" kelimelerini ayrı ayrı değerlendirmenin etkisi ile ikisini birlikte değerlendirmenin etkisi farklıdır. Buna rağmen bu basitlikteki bir sınıflandırıcı yüksek başarı verir.

### 12.2 Nerelerde kullanılır?

> **Hocanın vurgusu:** Naive Bayes, belge sınıflandırmada başarısı çok yüksek olan bir sınıflandırıcıdır.

Kullanım örnekleri:

- **Spam filtresi.** Bir e-postanın spam olup olmadığı. İki sınıf var: spam ve spam olmayan. Özellik olarak kelimeler kullanılır ve kelimelerin birbirinden bağımsız olduğu varsayılır. Hoca, Naive Bayes'in asıl parlamasına sebep olan uygulamanın bu olduğunu söyledi. Yöntem daha önce de kullanılıyordu, ama spam filtrelerindeki yüksek başarısıyla belge sınıflandırmada dikkat çekmeye başladı.
- **Yazarın cinsiyeti.** Bir yazının yazarının kadın mı erkek mi olduğunu tahmin etmek. Kadın yazarların belgelerinden ve erkek yazarların belgelerinden oluşan iki sınıf vardır; bilinmeyen belgenin hangi sınıfa daha yakın olduğuna bakılır.
- **Duygu analizi.** Bir film yorumunun olumlu mu olumsuz mu olduğu; bir yorumun alaycı mı normal mi yazıldığı; bir ürünün altına yazılan yorumun hakaret içerip içermediği.
- **Haber kategorisi.** Bir haber belgesinin ekonomiyle mi, sanatla mı, politikayla mı ilgili olduğu.

Hoca bu konuların doğal dil işleme derslerinde daha ayrıntılı işlendiğini, derin öğrenmeyle de çok yüksek başarılar elde edildiğini belirtti. Klasik yöntemlerle, yani klasik karar ağacı, k-en yakın komşu, destek vektör makineleri ve derin öğrenme mimarisinde olmayan klasik yapay sinir ağlarıyla karşılaştırıldığında ise Naive Bayes, bu basitliğine rağmen genelde pek çok yöntemden daha yüksek başarıyla sınıflandırma yapar.

### 12.3 Sınıflandırma kuralı

$v_j$ $j$. sınıfı, $a_1, \dots, a_n$ de $n$ özelliği (attribute) göstersin. Naive Bayes'te, verilen sınıf için özelliklerin olasılığı her özelliğin o sınıftaki olasılığının çarpımına eşit varsayılır. Bilinmeyen örneğin sınıfı yine MAP yaklaşımıyla bulunur: Bütün sınıflar için olasılık hesaplanır, en yüksek olanı seçilir.

$$v_{NB} = \arg\max_{v_j} P(v_j) \prod_{i=1}^{n} P(a_i \mid v_j)$$

### 12.4 Eğitim ve test

Öğrenme için önce her sınıfa ait örneklerin olması gerekir. Eğitimde iki şey hesaplanır:

1. **Her sınıfın olasılığı, $P(v_j)$.** Monty Hall'da üç kapı için her birine $1/3$ dediğimiz gibi, burada da örneklerin sınıflarda bulunma olasılığına bakılır. A ve B sınıflarında eşit sayıda örnek varsa her sınıfın olasılığı $1/2$'dir. Ama örneğin bir hastalık teşhisi çalışmasında hasta kişilere ait örnek sayısı 1, sağlam kişilere ait örnek sayısı 4 ise, $P(\text{hasta}) = 1/5$, $P(\text{sağlam}) = 4/5$ olur. Sınıf olasılıkları örnek sayısına bağlı olarak farklı dağılır.
2. **Her sınıf için her özelliğin olasılığı, $P(a_i \mid v_j)$.**

> **Hocanın vurgusu:** Sınıflardaki örnek sayılarını yaklaşık eşit tutmaya çalışmanızda fayda var.

Testte, bilinmeyen örneğin özellik değerleri için her sınıfta bu olasılıklar çarpılır, sınıfın olasılığıyla da çarpılır ve en büyük değeri veren sınıf seçilir.

## 13. Örnek: Naive Bayes ile PlayTennis

Hoca, geçen haftaki karar ağacı örneğinde kullanılan PlayTennis verisini Naive Bayes ile çözdü. Slaytın sol tarafında 14 günün değerleri vardı; kırmızılar tenis oynanan günleri, siyahlar oynanmayan günleri gösteriyordu.

**Eğitim: sınıf olasılıkları.** 14 günün 9'unda oynanmış, 5'inde oynanmamış:

$$P(\text{Yes}) = \frac{9}{14}, \qquad P(\text{No}) = \frac{5}{14}$$

**Eğitim: özellik olasılıkları.** Her sınıf için her özelliğin aldığı değerlerin olasılıkları ayrı ayrı hesaplanır. Hoca sözlü olarak şunları okudu:

- Play = Yes iken Temperature: Hot $2/9$, Mild $4/9$, Cool $3/9$.
- Play = No iken Temperature: Hot $2/5$, Mild $2/5$, Cool $1/5$.
- Outlook = Sunny: Play = Yes iken $2/9$, Play = No iken $3/5$.

Diğer değerler slayttaki tablodadır. Aşağıdaki tablo, geçen haftaki 14 günlük PlayTennis verisinin tamamından hesaplanmış koşullu olasılıkları verir:

| Özellik = Değer | $P(\cdot \mid \text{Yes})$ | $P(\cdot \mid \text{No})$ |
| :--- | :---: | :---: |
| Outlook = Sunny | 2/9 | 3/5 |
| Outlook = Overcast | 4/9 | 0/5 |
| Outlook = Rain | 3/9 | 2/5 |
| Temperature = Hot | 2/9 | 2/5 |
| Temperature = Mild | 4/9 | 2/5 |
| Temperature = Cool | 3/9 | 1/5 |
| Humidity = High | 3/9 | 4/5 |
| Humidity = Normal | 6/9 | 1/5 |
| Wind = Weak | 6/9 | 2/5 |
| Wind = Strong | 3/9 | 3/5 |

<!-- BELİRSİZ: Outlook (Sunny dışı), Humidity ve Wind satırları altyazıda sözlü okunmuyor; değerler geçen dersin PlayTennis tablosundan hesaplandı. Hocanın verdiği sonuçlarla (10.000'de 53 ve 206) tutarlı. -->

Bu tablo eğitimin çıktısıdır. Bir kez hazırlanır ve önceki (prior) bilgiyi oluşturur.

**Test.** Bilinmeyen örnek: Outlook = Sunny, Temperature = Cool, Humidity = High, Wind = Strong. Bu şartlarda tenis oynanmış mıdır, oynanmamış mıdır?

Önce Yes sınıfı için hesap yapılır. Play = Yes iken Outlook'un Sunny olma olasılığı $2/9$, Temperature'ın Cool olma olasılığı $3/9$, Humidity'nin High olma olasılığı $3/9$, Wind'in Strong olma olasılığı $3/9$; sınıfın olasılığı $9/14$:

$$P(\text{Yes}) \prod_i P(a_i \mid \text{Yes}) = \frac{9}{14} \cdot \frac{2}{9} \cdot \frac{3}{9} \cdot \frac{3}{9} \cdot \frac{3}{9} \approx 0{,}0053$$

Aynı hesap No sınıfı için yapılır:

$$P(\text{No}) \prod_i P(a_i \mid \text{No}) = \frac{5}{14} \cdot \frac{3}{5} \cdot \frac{1}{5} \cdot \frac{4}{5} \cdot \frac{3}{5} \approx 0{,}0206$$

Hocanın ifadesiyle Yes için değer 10.000'de 53, No için 10.000'de 206 çıkıyor. MAP'e göre $0{,}0206 > 0{,}0053$ olduğu için cevap **No: Bu şartlarda tenis oynanmamalıdır.**

Genel olarak: $C$ sınıfı ve $n$ özellik için, her özelliğin bu sınıfta bulunma olasılıklarının çarpımı sınıf olasılığıyla çarpılır. Bu değer, Naive Bayes'e göre örneğin o sınıfa ne kadar benzediğini gösterir.

## 14. Naive Bayes ile Belge Sınıflandırma

### 14.1 Eğitim: sözlük ve kelime olasılıkları

Belge sınıflandırmada özelliklerin nasıl kullanılacağını hoca spam örneği üzerinden anlattı. İki sınıf olsun: spam ve spam olmayan. Verilen bir e-posta belgesinin spam olup olmadığı tespit edilmek isteniyor. Özellikler kelimelerdir ve bulunması gereken, $C$ sınıfı için $x$ kelimelerinin olasılığıdır.

1. **Örnekleri topla.** Örneğin 100 spam ve 100 spam olmayan e-posta alınır.
2. **Sınıf metnini oluştur.** Bir sınıfın bütün e-postaları alt alta eklenerek o sınıfın tek bir metni oluşturulur. Slayttaki "bir konu için bütün belgeleri birleştirerek tek bir belge oluştur" adımı budur.
3. **Durak kelimeleri ele.** Mutlaka yapılması gereken bir adımdır. Durak kelimeler (stop words), hem spam hem spam olmayan metinlerde geçme olasılığı yüksek olan kelimelerdir: Türkçede "de", "da", "ki" gibi. Her iki sınıfta benzer sıklıkta geçtikleri için sınıfları birbirine benzetirler ve sınıflandırma başarısını düşürürler.
4. **Sözlük oluştur.** Kalan kelimelerden, bütün sınıflarda var olan kelimeleri içeren bir sözlük (vocabulary) $V$ oluşturulur. Çalışmanıza göre kelime olmayan simgeler de (ünlem, soru işareti, sayı) sözlüğe alınabilir; bunlara genel olarak "token" denir.
5. **Sınıf olasılıklarını hesapla:** $P(v_j)$.
6. **Kelime olasılıklarını hesapla.** Sözlükteki her kelimenin her sınıfta bulunma olasılığı saklanır. Bir kelimenin A sınıfında geçme sayısının A sınıfındaki toplam kelime sayısına bölümü, o kelimenin A sınıfında bulunma olasılığını verir:

$$P(w_k \mid v_j) = \frac{n_{kj}}{n_j}$$

Burada $n_{kj}$, $w_k$ kelimesinin $j$. sınıfta geçme sayısı; $n_j$ ise $j$. sınıftaki toplam kelime sayısıdır.

Hoca, İngilizcede kelimelerin sözlüğe hazırlanmasının daha kolay olduğunu söyledi: "-ing" eki atılır ("raining" → "rain"), sondaki "-s" atılır ("cats" → "cat"); eklerle ilgili çok sorun yaşanmaz. Türkçede ise "geliyorum, geldin, gelir misin" gibi pek çok biçim vardır. Bu ayıklamanın yapılması Türkçe için ayrı bir ön işleme problemidir.

### 14.2 Sıfır olasılık sorunu ve Laplace düzeltmesi

Bir kelime bir sınıfta hiç geçmiyorsa ne olur? Slayttaki örnekte "fantastic" kelimesi pozitif sınıfta hiç geçmiyor, negatif sınıfta geçiyor. Sayısı sıfır olduğu için $P(\text{fantastic} \mid \text{pozitif}) = 0$ olur. Naive Bayes bütün kelimelerin olasılıklarını çarptığı için, çarpıma tek bir sıfır girince pozitif sınıfın olasılığı birdenbire sıfır çıkar; diğer kelimeler ne olursa olsun.

Bunu önlemek için formüle bir ekleme yapılır. Hocanın anlattığına göre bazı çalışmalarda paya ve paydaya 1 eklenir, bazı çalışmalarda ise paya 1, paydaya toplam farklı kelime sayısı $|V|$ eklenir. İki dikey çizgi arasındaki $|V|$, sözlükteki farklı kelime sayısını gösterir. Bu yaklaşıma Laplace düzeltmesi (Laplace estimator) denir. Genelde paydaya $|V|$ eklenen hali kullanılır:

$$P(w_k \mid v_j) = \frac{n_{kj} + 1}{n_j + |V|}$$

Amaç yalnızca payın sıfır olması durumundan, yani sıfırla çarpma sorunundan kurtulmaktır.

### 14.3 Test

Eğitimin sonunda elimizde bir sözlük, sözlükteki her kelimenin her sınıftaki olasılığı ve sınıfların olasılıkları hazır bekler. Bilinmeyen bir belge geldiğinde:

1. Belgedeki kelimelerden sözlükte bulunanlar çıkarılır. Belgedeki her kelimenin sözlükte olması gerekmez; sözlükte olmayan kelimeler için işlem yapılamaz, atlanır.
2. Her sınıf için $P(v_j) \prod_k P(w_k \mid v_j)$ hesaplanır.
3. Hangi sınıfın değeri daha büyükse belge o sınıfa atanır.

### 14.4 Örnek: Basit belge sınıflandırma

Hoca, tablette iki küçük sınıf ve bir bilinmeyen belge yazarak bir örnek çözdü. Bunun anlamlı bir metin değil, mekanizmayı göstermek için kurulmuş bir örnek olduğunu belirtti.

<!-- BELİRSİZ: A ve B sınıflarının kelime listeleri ve bilinmeyen belgenin tam metni tablette yazılı; altyazıda yalnız aşağıdaki kelimeler ve sayılar geçiyor. -->

Altyazıdan anlaşılan bilgiler:

- Sözlükte her iki sınıfta geçen, durak kelime olmayan 6 kelime var. Altyazıda "cat", "crab", "crawl", "rain" ve "dog" sayılıyor: $|V| = 6$.
- A sınıfında sözlükte geçen toplam kelime sayısı $n_A = 4$; "cat" bir kez geçiyor, "dog" hiç geçmiyor.
- B sınıfında $n_B = 3$; "cat" bir kez, "dog" bir kez geçiyor.
- Sınıflar yaklaşık eşit sayıda kelimeden oluştuğu için $P(A) = P(B) = 1/2$ alınıyor.
- Bilinmeyen belgede "it", "mice" gibi sözlükte olmayan kelimeler de var. Sözlükte bulunan yalnızca "cat" ve "dog"dur; işlem yalnız bu iki kelimeyle yapılır.

Laplace düzeltmesiyle, A sınıfı için:

$$P(A)\,P(\text{cat} \mid A)\,P(\text{dog} \mid A) = \frac{1}{2} \cdot \frac{1+1}{4+6} \cdot \frac{0+1}{4+6} = \frac{1}{2} \cdot \frac{2}{10} \cdot \frac{1}{10} = 0{,}01$$

B sınıfı için:

$$P(B)\,P(\text{cat} \mid B)\,P(\text{dog} \mid B) = \frac{1}{2} \cdot \frac{1+1}{3+6} \cdot \frac{1+1}{3+6} = \frac{1}{2} \cdot \frac{2}{9} \cdot \frac{2}{9} \approx 0{,}0247$$

$0{,}0247 > 0{,}01$ olduğu için (hocanın ifadesiyle "binde 24" daha büyük) **belge B sınıfına aittir.**

### 14.5 Genel akış ve bir uygulama

Hoca belge sınıflandırmadaki akışı bir kez daha toparladı. Örneğin politika, sanat ve spor haberlerinden oluşan dört beş sınıfınız olsun. Önce bütün sınıflardaki bütün kelimeler için bir sözlük oluşturulur. Ardından her sınıf için sözlükteki kelimelerin o sınıfta bulunma olasılıkları çıkarılır (A sınıfında "cat" geçme olasılığı, A sınıfında "dog" geçme olasılığı, A sınıfında "crab" geçme olasılığı gibi). Bu işlem bütün sınıflar ve bütün kelimeler için yapılınca eğitim tamamlanmış olur. Bilinmeyen bir belge geldiğinde, önce belgede sözlükte bulunan kelimeler çıkarılır, sonra bu kelimelerle her sınıf için olasılık hesaplanır ve en büyüğü seçilir.

Hoca Bayes'in farklı uygulamalarda da başarılı sonuçlar verdiğini söyledi. Kendi ekiplerinin BKM için yaklaşık 30 bankadan alınan verilerle yaptığı kredi kartı sahtekarlığı çalışmasında, klasik yöntemler arasında Naive Bayes oldukça yüksek başarı vermiş. Bazı durumlarda Naive Bayes, bazı durumlarda karar ağacı daha yüksek başarı vermiş.

## Dersin Toparlaması

Dersin ilk kısmında karar ağaçlarındaki aşırı öğrenmeye karşı kullanılan yöntemler tamamlandı. Veri eğitim, doğrulama ve test olarak üçe ayrılır. Azaltılmış hata budamasında tam kurulan ağaç yapraklardan yukarı doğru budanır; her budamanın faydası doğrulama verisiyle ölçülür, budanan düğüm çoğunluk sınıfıyla etiketlenir. Erken durdurma ağacı büyütürken başarıyı kaydeder ve en iyi noktaya döner; kural sonrası budama ağacı kurallara çevirip her kuralı ayrı değerlendirir. Modelin son başarısı, hiç kullanılmamış test verisiyle raporlanır. Karar ağaçlarının güçlü yanları (doğrusal olmayan sınırlar, kategorik ve sürekli özellikler, kurallara çevrilebilme, hız) ve zayıf yanları (büyük ağaçların anlaşılmazlığı, artımlı olmama, sabit özellik sayısı) özetlendi.

İkinci kısımda üretici sınıflandırıcılara geçildi. Bayes teoremi, önceki olasılıkla gözlenen verinin olabilirliğini birleştirerek bir örneğin her sınıfa ait olma olasılığını verir; ortak payda atılarak en büyük sonsal olasılıklı sınıf seçilir. COVID örneği, nadir bir durumda pozitif test sonucunun bile yanıltıcı olabileceğini; Monty Hall örneği ise kapı değiştirmenin neden daha kârlı olduğunu gösterdi. Son olarak özelliklerin sınıf verildiğinde bağımsız olduğunu varsayan Naive Bayes sınıflandırıcısı, PlayTennis verisi ve belge sınıflandırma (sözlük, kelime olasılıkları, Laplace düzeltmesi) üzerinden adım adım uygulandı.

## Ders Sonrası Notlar

> **Ders sonrası not:** Hoca ayırt edici sınıflandırıcıları sayarken bir an "bunlar hep generatif klasifierler" dedi, sonra "pardon, diskriminatif" diye düzeltti. Doğrusu: k-en yakın komşu, yapay sinir ağları, doğrusal regresyon ve karar ağaçları **ayırt edici** modellerdir.

> **Ders sonrası not:** Hoca bağımsız olaylara örnek olarak "paranın yazı gelmesi ve tura gelmesi"ni verdi. Tek bir atışta yazı gelmesi ile tura gelmesi **ayrık (mutually exclusive)** olaylardır, bağımsız değildir: Biri gerçekleşirse diğeri kesinlikle gerçekleşmez. Bağımsız olaylara doğru örnek, iki ayrı atışın sonuçlarıdır: İlk atışın yazı gelmesi, ikinci atışın sonucunu etkilemez.

> **Ders sonrası not:** Baş ağrısı ve nezle örneği derste Bayes teoremiyle tamamlanmadı. Tamamlanırsa: $P(\text{nezle} \mid \text{baş ağrısı}) = \dfrac{P(\text{baş ağrısı} \mid \text{nezle})\,P(\text{nezle})}{P(\text{baş ağrısı})} = \dfrac{(1/2)(1/40)}{1/10} = \dfrac{1}{8}$. Başı ağrıyan birinin nezle olma olasılığı 1/8'dir.

> **Ders sonrası not:** COVID örneğinde hoca ikinci çarpımı söylerken "0.03 çarpı 0.0992" dedi ve sonucu "0.029" olarak verdi. Doğru hesap $0{,}03 \times 0{,}992 = 0{,}02976$'dır. Hocanın vardığı sonuç ("COVID değil") değişmez.

> **Ders sonrası not:** Hoca COVID'in akciğerdeki bulgularının "MR" ile görüldüğünü söyledi. Bu bulgular genellikle bilgisayarlı tomografi (BT) ile incelenir. Hocanın "test sonuçları %40 oranla doğru" sözü, örnekte verilen %98 değeriyle çelişiyor; dönemin testlerinin yanlış negatif sorununa dair genel bir yorum olarak anlaşılmalıdır.

> **Ders sonrası not:** Laplace düzeltmesi için hoca "bazı çalışmalarda paya ve paydaya 1 eklenir" dedi. Olasılıkların toplamının 1 olması için paya 1 eklendiğinde paydaya sözlük boyutu $|V|$ eklenmelidir; hocanın da belirttiği gibi pratikte kullanılan hali budur.

> **Ders sonrası not:** Hoca bir yerde kelime olasılığının paydası için "B sınıfındaki farklı kelime sayısı" dedi. Doğrusu: Payda $n_j$, sınıftaki **toplam** kelime (geçiş) sayısıdır; farklı kelime sayısı $|V|$ yalnızca Laplace düzeltmesinde paydaya eklenir.

> **Ders sonrası not:** Hoca Naive Bayes'in belge sınıflandırmada "%100'lere yakın" başarı verebildiğini söyledi. Bu, veri kümesine ve göreve bağlıdır. Naive Bayes güçlü bir temel (baseline) yöntemdir, ama her belge sınıflandırma görevinde %100'e yakın başarı vermez.

> **Ders sonrası not:** Altyazıda "Nayibayez", "Mayıs sınıflandırıcısı" gibi geçen yöntem Naive Bayes'tir; "Hidden Markov model" Saklı Markov Modeli'dir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
