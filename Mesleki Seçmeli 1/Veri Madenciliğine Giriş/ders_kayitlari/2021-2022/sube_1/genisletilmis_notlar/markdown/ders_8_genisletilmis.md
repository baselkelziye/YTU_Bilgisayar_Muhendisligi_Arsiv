# Ders 8 Genişletilmiş Notu: Kural Tabanlı Sınıflandırma, Naive Bayes ve Weka

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.


## İçindekiler

- 1. Giriş: Önceki Dersten Bugüne
- 2. Kural Tabanlı Sınıflandırma ve Kuralın Yapısı
- 3. Kuralın Kapsaması (Coverage) ve Doğruluğu (Accuracy)
- 4. Kural Tabanlı Sınıflandırıcı Nasıl Çalışır?
- 5. Kural Kümelerinin Özellikleri ve Çatışma Çözümü
- 6. Kural Sıralama Şemaları
- 7. Kural Oluşturma: Doğrudan Yöntemler ve Ardışık Kapsama
- 8. Learn-One-Rule ve Kural Büyütme Stratejileri
- 9. Kural Değerlendirme: FOIL Bilgi Kazancı
- 10. Dolaylı Yöntem: Karar Ağacından Kural Çıkarma
- 11. Olasılık ve Bayes Teoremi
- 12. Olayların Bağımsızlığı
- 13. Naive Bayes Sınıflandırıcı
- 14. Weka ile Uygulama
- Örnek Sorular

## 1. Giriş: Önceki Dersten Bugüne

Ders, önceki haftanın kısa bir tekrarıyla başladı. Geçen derste karar ağaçları görülmüştü: ağacın nasıl kurulduğu, bölmenin daha iyi olması için bilgi kazancının (information gain) nasıl kullanıldığı, bilgi kazancının entropi ile ve Gini indeksi ile nasıl formüle edildiği. Bu derste sınıflandırmaya devam edildi. Hoca, bugünkü yöntemlerin karar ağacına göre daha basit olduğunu, kafa karıştırmayacağını söyledi ve dersin sonunda Weka aracının gösterileceğini belirtti (00:01:45).

## 2. Kural Tabanlı Sınıflandırma ve Kuralın Yapısı

Kural (rule), "eğer şöyle şöyle ise, şudur" biçiminde ifade edilen bir yapıdır; İngilizce "IF ... THEN ..." diye yazılır. IF'ten sonra bir koşul (condition) gelir. Bu koşulda öznitelikler yer alır: "bu öznitelik şundan küçükse", "şundan büyükse", "şuna eşitse" gibi. Koşul içindeki testler AND ile bağlanır; OR kullanılmaz. THEN'den sonraki kısma sonuç (consequent) denir ve burada yalnız sınıf bulunur (00:03:30).

Derste iki örnek verildi: yaş ve öğrencilik koşullarına göre "buys_computer = yes" diyen bir kural ile "sıcak kanlıysa ve yumurtluyorsa sınıfı kuştur" kuralı. Her ikisinde de THEN'den sonra yalnız sınıf etiketi vardır. Hoca, kuralın anlaşılmasının oldukça basit olduğunu vurguladı.

<!-- BELİRSİZ: buys_computer kuralındaki yaş koşulunun değeri altyazıda anlaşılmıyor (00:04:12); bu slayt karelerde yok. -->

## 3. Kuralın Kapsaması (Coverage) ve Doğruluğu (Accuracy)

Kural tabanlı sınıflandırıcılarda her kural için iki sayısal ölçü tanımlanır: kapsama (coverage) ve doğruluk (accuracy). Hoca, ders kitabının "coverage" terimini kullandığını, başka kaynaklarda bunun yerine "support" görülebileceğini söyledi (00:04:58).

Slayttaki tanımlar şöyledir (ekrandan, 00:07:06). Bir r kuralı, bir x örneğinin öznitelikleri kuralın koşulunu sağlıyorsa o örneği "kapsar" (covers).

- $n_{covers}$: R kuralının kapsadığı kayıt (tuple) sayısı.
- $n_{correct}$: R kuralının doğru sınıfladığı kayıt sayısı.
- $D$: eğitim veri kümesi.

$$\text{coverage}(R) = \frac{n_{covers}}{|D|}, \qquad \text{accuracy}(R) = \frac{n_{correct}}{n_{covers}}$$

Coverage, verideki satırların yüzde kaçının kuralın yalnız koşul kısmına uyduğunu gösterir; THEN'den sonraki sınıfa bakılmaz. Accuracy'de ise sonuç kısmı da işe girer: koşulu sağlayanlardan kaçının sınıfı kuralın söylediği gibidir, yani kural yüzde kaç doğrulukla çalışıyor (00:05:52).

### 3.1 "status = single" örneği

Hoca 10 satırlık bir veri üzerinde "IF status = single THEN class = no" kuralını inceledi (00:07:24). Veride status değeri single olan 4 satır vardır; bu yüzden coverage $4/10 = 0.4$, yani $\%40$'tır. Bu 4 satırın sınıflarına bakıldığında ikisi gerçekten "no", ikisi "yes"tir. Kural 4 satırdan 2'sini doğru sınıfladığı için accuracy $2/4 = \%50$'dir.

<!-- BELİRSİZ: Bu 10 satırlık tablo karelerde yok; sayılar altyazıdan alındı. Altyazıda yanlış sınıflanan satırlardan yalnız biri açıkça sayılıyor, sonuç 2/4 olarak veriliyor. -->

### 3.2 Hayvan veri kümesi örneği

İkinci örnek 20 satırlık bir hayvan tablosudur (00:08:42). Sütunlarda kan tipi (sıcak/soğuk kanlı), doğurma (give birth), uçabilme (can fly), suda yaşama (live in water) ve sınıf (memeli, sürüngen, balık, kuş, amfibi) vardır.

- R1: IF Give Birth = no AND Can Fly = yes THEN Birds. Bu koşula tabloda 3 satır uyar ve üçü de kuştur. Coverage $3/20$, accuracy $3/3 = \%100$.
- R2: IF Give Birth = no AND Live in Water = yes THEN Fishes. Hoca uyan satırları saydı; bunların hepsi balıktır, bu kural da $\%100$ accuracy ile çalışır.
- R3: IF Give Birth = yes AND Blood Type = warm THEN Mammals.
- R5: IF Live in Water = sometimes THEN Amphibians.

Hoca, en azından baktığı iki kuralın $\%100$ doğrulukla çalıştığını belirtti ve bu kuralların eğitim kümesinden çıkarılmış "model" olduğunu söyledi.

## 4. Kural Tabanlı Sınıflandırıcı Nasıl Çalışır?

Kural tabanlı sınıflandırıcı bir kaydı, o kaydın tetiklediği (trigger) kurala göre sınıflar. Slayttaki test kayıtları ve kurallar şöyledir (ekrandan, 00:12:06):

| Name | Blood Type | Give Birth | Can Fly | Live in Water | Class |
|---|---|---|---|---|---|
| lemur | warm | yes | no | no | ? |
| turtle | cold | no | no | sometimes | ? |
| dogfish shark | cold | yes | no | yes | ? |

```text
R1: IF (Give Birth = no) AND (Can Fly = yes) THEN Class = Birds
R2: IF (Give Birth = no) AND (Live in Water = yes) THEN Class = Fishes
R3: IF (Give Birth = yes) AND (Blood Type = warm) THEN Class = Mammals
R4: IF (Give Birth = no) AND (Can Fly = no) THEN Class = Reptiles
R5: IF (Live in Water = sometimes) THEN Class = Amphibians
```

Hoca kayıtları kurallara sırayla sordu:

- Lemur: R1'de Give Birth = no değil, geç. R2'de de değil, geç. R3'te Give Birth = yes ve Blood Type = warm; uyar. Lemur memelidir.
- Kaplumbağa (turtle): R1 ve R2'ye uymaz, R3'te kan tipi soğuk olduğu için uymaz. R4'te Give Birth = no ve Can Fly = no; uyar, sürüngen. Ama R5'e de bakılırsa Live in Water = sometimes olduğu için o da tetiklenir ve amfibi der. Kaplumbağa iki kuralı birden tetikler; sürüngen mi amfibi mi olduğu çözülmelidir.
- Köpek balığı (dogfish shark): Give Birth = yes olduğu için R1, R2, R4'e uymaz; R3'te kan tipi soğuk olduğu için uymaz; R5'te Live in Water = yes olduğu için uymaz. Hiçbir kural tetiklenmez.

Bu örnekten iki soru çıkar: bir kayıt birden fazla kuralı tetiklerse ne yapılacak, hiçbir kuralı tetiklemezse ne yapılacak? Hoca, birinci soru için iki strateji olduğunu baştan söyledi: sırayla bakmak ya da oylama yapmak (00:14:51).

## 5. Kural Kümelerinin Özellikleri ve Çatışma Çözümü

### 5.1 Karşılıklı dışlayan ve kapsayıcı kurallar

Slayttaki tanımlar şöyledir (ekrandan, 00:17:06):

- Karşılıklı dışlayan kurallar (mutually exclusive rules): R kümesindeki hiçbir iki kural aynı kayıt tarafından tetiklenmiyorsa kurallar karşılıklı dışlayandır. Her kayıt R'deki en fazla bir kural tarafından kapsanır.
- Kapsayıcı kurallar (exhaustive rules): öznitelik değerlerinin her birleşimi için bir kural varsa R kapsayıcıdır. Her kayıt R'deki en az bir kural tarafından kapsanır.

Önceki örnek karşılıklı dışlayan değildir, çünkü kaplumbağa birden fazla kuralı tetiklemiştir. Kapsayıcı da değildir, çünkü köpek balığı için bir kural yoktur.

### 5.2 Kurallar karşılıklı dışlayan değilse

Bir kayıt birden fazla kuralı tetikleyebiliyorsa iki çözüm vardır (ekrandan, 00:22:06).

**Çözüm 1: Sıralı kural kümesi.** Kurallar rastgele değil, önceliğe göre azalan sırada dizilir (örneğin accuracy, coverage ya da kuralların üretilme sırasına göre). Sıralı kural kümesine karar listesi (decision list) de denir. Bir kayıt geldiğinde kurallara sırayla bakılır; kaydı kapsayan ilk kuralda "break" yapılır, kalan kurallara bakılmaz. Kayıt, onu kapsayan en üst sıradaki kuralın sınıfını alır.

Hoca burada kuralların neye göre sıralanabileceğini sordu. Konuşmada şu fikirler geçti:

**Soru:** Köpek balığı için "Blood Type = cold AND Give Birth = yes AND Can Fly = no THEN dogfish shark" gibi daha fazla koşullu bir kural yazıp en başa koysak olmaz mı? **Cevap:** Köpek balığı sorunu çözülür, ama Give Birth = yes ve Can Fly = no olan benzer kayıtlar da ilk bakılan bu kurala takılabilir; yanlış sınıflandırma ihtimali yükselir (00:19:40).

**Soru:** Kurallar sınıfın kendine özgü özelliklerine göre, yalnız tek bir sınıfa özgü olan kural başa konacak şekilde sıralanamaz mı? **Cevap:** Olabilir; ama elimizde zaten iki ölçü var: accuracy ve coverage. Accuracy'si ve coverage'i yüksek kuralları yukarı koymak gerekir. Bu hem algoritmayı hızlandırır (üstte uyan kuralda çıkılır) hem de çok özel kuralların, örneğin eğitim kümesinde yalnız iki örneğe uyan nadir bir kuralın, aşağıda kalmasını sağlar; böylece o kuralın neden olacağı yanlış sınıflandırmalardan kurtulunur (00:20:49). Sohbet penceresinden de bir öğrenci kuralların accuracy'ye göre sıralanması gerektiğini yazdı (00:25:36).

**Çözüm 2: Sırasız kural kümesi ve oylama.** Kayıt bütün kurallara tek tek sorulur ve birden fazla kuralı tetikleyebilir. Tetiklenen her kuralın sonucu bir sınıf için bir oy sayılır; kayıt genellikle en çok oyu alan sınıfa atanır. Hocanın örneği: üç kural tetiklenmiş, ikisi sürüngen, biri balık demişse oylamayı sürüngen kazanır. Bazı durumlarda oylar kuralın accuracy değeriyle çarpılarak ağırlıklandırılır; böylece doğruluğu yüksek kuralların oyu daha fazla sayılır (00:22:27).

### 5.3 Kurallar kapsayıcı değilse

Hiçbir kural tetiklenmezse, köpek balığında olduğu gibi, bir varsayılan sınıf (default class) kullanılır. Sıralı kurallarda en sona bir varsayılan kural konur. Hoca burada şunu sordu: kullanıcı bir hayvanın türünü sorduğunda ona "türü: default" diye cevap verilebilir mi? Verilemez; anlamlı bir sınıf döndürülmelidir. Bu yüzden varsayılan sınıf genellikle eğitim kümesinde en çok bulunan sınıf (majority class) olarak atanır. Örneğin 20 hayvanın 7'si memeliyse varsayılan sınıf memeli olur (00:24:28).

Hoca bu kısmı şöyle özetledi: önce coverage ve accuracy tanımlandı; kuralın koşul ve sonuç kısımları görüldü; sonra bir kayıt birden fazla kuralı tetiklerse (karşılıklı dışlayan değilse) ve hiçbir kuralı tetiklemezse (kapsayıcı değilse) uygulanan stratejiler konuşuldu.

## 6. Kural Sıralama Şemaları

Kural sıralaması kural kural ya da sınıf sınıf yapılabilir (ekrandan, 00:27:06).

**Kural tabanlı sıralama (rule-based ordering).** Her kural kendi kalitesine, yani accuracy ve coverage değerine göre sıralanır. Her kayıt, onu kapsayan "en iyi" kural ile sınıflanır. Slayta göre aşağıdaki kuralları yorumlamak daha zordur, çünkü her biri kendinden önceki kuralların sağlanmadığını varsayar. Hoca, accuracy ve coverage'i yüksek kuralların genellikle en çok görülen sınıfa ait olduğunu, test kümesinde de benzer kayıtların gelmesi beklendiği için bu kuralların önde olmasının hem hızlı hem doğru cevap verdiğini söyledi (00:26:26).

**Sınıf tabanlı sıralama (class-based ordering).** Aynı sınıfa ait kurallar kural kümesinde bir arada durur; önce bir sınıfın kuralları, sonra diğer sınıfın kuralları gelir. Kurallar sınıf bilgisine göre topluca sıralanır. Aynı sınıfın kuralları arasındaki sıra önemli değildir, çünkü hangisi tetiklenirse tetiklensin sonuç aynı sınıftır. Slayta göre bu şemanın bir sakıncası, yüksek kaliteli bir kuralın, daha üst sıradaki bir sınıfı tahmin eden daha zayıf bir kural yüzünden göz ardı edilebilmesidir.

Hoca sınıfların kendi aralarındaki sıranın neden önemli olduğunu bir örnekle anlattı (00:30:05). Kuş kurallarından biri "Skin Cover = feathers AND Aerial Creature = yes AND A = X THEN Bird" olsun. Daha aşağıda, amfibi sınıfında yalnız ilk iki koşulu içeren "Skin Cover = feathers AND Aerial Creature = yes THEN Amphibian" kuralı bulunsun. Bu sırada A = X olan kayıt kuş olur, A ≠ X olan kayıt aşağıya inip amfibi olur. Ama amfibi kuralları kuş kurallarının üstüne alınırsa ilk iki koşula uyan bütün kayıtlar amfibi diye sınıflanır ve üç koşullu kuş kuralı boşa çıkar. Yani sınıfların kendi içindeki sıra önemli değil, birbirlerine göre sırası sonucu değiştirir.

## 7. Kural Oluşturma: Doğrudan Yöntemler ve Ardışık Kapsama

Kural tabanlı bir sınıflandırıcı kurmak için, veri kümesindeki öznitelikler ile sınıf etiketi arasındaki temel ilişkileri ortaya koyan bir kural kümesi çıkarmak gerekir. Bunun iki yolu vardır (ekrandan, 00:32:06):

- Doğrudan yöntemler (direct methods): sınıflandırma kuralları doğrudan veriden çıkarılır. Örnekler: RIPPER, CN2.
- Dolaylı yöntemler (indirect methods): kurallar başka bir sınıflandırma modelinden (örneğin karar ağacından) çıkarılır. Örnek: C4.5rules.

Hoca doğrudan yöntemlerden en çok kullanılanın RIPPER algoritması olduğunu söyledi (00:32:16).

### 7.1 Notasyon

Eğitim verisi E ile gösterilir. Her satırda $A_i$ öznitelikleri ve $v_i$ bunların değerleri bulunur; örneğin öznitelik "kan tipi" iken değeri "warm" ya da "cold"dur. Y sınıflar kümesidir; sınıflar $c_1, c_2, \dots$ diye gösterilir. İkili sınıflandırmada iki, çok sınıflı sınıflandırmada daha fazla sınıf vardır (00:33:03).

<!-- BELİRSİZ: Algoritmanın sözde kodu karelerde yok; aşağıdaki adımlar altyazıdan kuruldu. -->

### 7.2 Ardışık kapsama algoritması

Algoritma her sınıf için şu döngüyü kurar (00:34:20):

```text
R = boş kural listesi
her sınıf c için:
    durma koşulu sağlanmadıkça:
        kural = Learn-One-Rule(E, öznitelikler, c)
        kuralın kapsadığı kayıtları E'den çıkar
        kuralı R listesine ekle
```

Learn-One-Rule her seferinde eğitim verisindeki özniteliklere ve sınıfa bakarak bir kural öğrenir. Kurala uyan kayıtlar eğitim verisinden çıkarılır, çünkü artık onlara bakmaya gerek yoktur; kural da kural listesine eklenir. Eğitim verisi küçülür ve yeni bir kural aranır. Algoritma satır satır ilerler; öznitelikler Learn-One-Rule'un içinde kullanılır.

Durma koşulu ne olabilir? Verinin bitmesi olabilir, ama veri her zaman bitmeyebilir. Bir başka seçenek, accuracy belirli bir yüzdenin altına düşüyorsa, yani daha iyi bir kural bulunamıyorsa durmaktır (00:35:42).

Slayttaki görsel örnek şöyledir (ekrandan, 00:37:06). Orijinal veri kümesinde + ve − örnekler karışık durur. Algoritma önce + sınıfı için kural arar; ilk kural R1 bir dikdörtgen bölgedeki + örnekleri kapsar ("X şu ile şu arasındaysa, Y de şu ile şu arasındaysa" gibi). R1'in kapsadığı kayıtlar veriden çıkarılır ve R1 kural listesine eklenir. Sonraki adımda R2 başka bir bölgeyi kapsar. Hoca, bir kuralın arada bir iki negatif örneği de kapsayabileceğini, accuracy örneğin $\%90$'ın üzerindeyse bunun göz ardı edildiğini söyledi. R3 ile devam edilir; sonunda yalnız negatifler kaldığında onlar için de kural yazılıp çıkılır. En sonda, gerçek hayatta bu kadar keskin ayrımlar olmadığı için, bulunamayan kayıtlar için bir varsayılan sınıf tanımlanır; bu da en çok bulunan sınıftır (örnekte −).

## 8. Learn-One-Rule ve Kural Büyütme Stratejileri

Algoritmada bilinmeyen tek parça Learn-One-Rule'dur. Hoca öğrencilere kuralı nasıl öğreneceklerini sordu. Bir öğrenci sezgisel (heuristic) bir yöntem kullanılabileceğini söyledi. Hoca kendi yaklaşımını şöyle anlattı: her öznitelik için sınıfa bakılır, hangisinin coverage'i daha fazlaysa o koşul eklenir, sonra öznitelik ekleye ekleye gidilir. Bu açgözlü (greedy) bir algoritmadır ve çalışır (00:37:57).

Learn-One-Rule'un amacı, bakılan sınıftan olabildiğince çok örneği kapsayan bir kural bulmaktır. Accuracy çoğu zaman $\%100$ olmayacağı için kural arada az sayıda başka sınıftan örnek de içerebilir.

### 8.1 Neden optimum kural bulunamaz?

Hoca sordu: bir sınıf için $n$ öznitelik varsa kaç farklı kural yazılabilir? Koşul olarak tek bir öznitelik, iki öznitelik, ..., $n$ öznitelik seçilebileceği için (00:39:24):

$$\binom{n}{1} + \binom{n}{2} + \dots + \binom{n}{n}$$

Bu üstel bir arama problemidir; büyük $n$ değerlerinde normal bilgisayarlarla çalışmaz ve global optimumu bulmak pratikte mümkün değildir. Bulunan kurallar optimal olmayacaktır. Bunun yerine açgözlü bir arama yapılır: önce bir kural bulunur, sonra iyileştirilmeye çalışılır. Örneğin bir öznitelikle başlanır, accuracy'yi en iyi yapan öznitelik bulunur; ona ikinci bir öznitelik eklemenin daha iyi olup olmadığına bakılır; iyiyse üçüncüsü denenir.

> **Ek bilgi (derste anlatılmadı):** Bu toplam $2^n - 1$'e eşittir. Ayrıca her öznitelik birden fazla değer alabildiği için gerçek arama uzayı bundan da büyüktür.

### 8.2 Genelden özele (general-to-specific)

Boş bir kuralla başlanır: `{} => Mammals` (ekrandan, 00:42:06). Boş kural hiçbir şey ifade etmez, çünkü her şeyi kapsar. Sonra koşul kısmına teker teker öznitelik eklenir. Slayttaki ağaçta birinci seviyede "Skin Cover = hair => Mammals", "Body Temperature = warm-blooded => Mammals", ..., "Has Legs = No => Mammals" adayları vardır. En iyi aday (Body Temperature = warm-blooded) seçilir; ikinci seviyede ona "Has Legs = yes" ya da "Gives Birth = yes" eklenir ve en iyisi ("Body Temperature = warm-blooded, Gives Birth = yes => Mammals") seçilir.

İyileşme sürdükçe öznitelik eklemeye devam edilir; bir noktadan sonra daha iyi sınıflandırma yapılamıyorsa durulur. Hoca, algoritmanın her adımda yalnız en iyiyi ya da en iyi üç adayı tutacak şekilde ayarlanabileceğini söyledi (00:43:12).

Bu yöntemde çok fazla tekrar oluşur: koşulunda dört öznitelik olan bir kuralın iki öznitelikli bir alt kümesi başka bir kural olarak durabilir. Bu yüzden ağaçlardaki budamaya (pruning) benzer şekilde kuralların sonradan elenmesi gerekir (00:42:11).

### 8.3 Özelden genele (specific-to-general)

Bunun tersidir. İlk kuralda bütün öznitelikler vardır; böyle bir kurala çok az kayıt uyar. Sonra öznitelikler teker teker çıkarılarak kural genelleştirilir. Slayttaki örnekte "hibernates" gibi koşulların bulunduğu bir kuraldan "Body Temperature" çıkarılmış; bu çıkarılınca kuralın coverage'i artmış, kural genelleşmiştir. Bu daha iyi sınıflandırıyorsa oradan devam edilir; her adımda hangi özniteliğin çıkarılmasının daha iyi olacağına bakılır (00:44:30).

<!-- BELİRSİZ: Özelden genele örneğinin slaytı karelerde yok; koşul adları altyazıdan alındı. -->

Bu kısımda bir öğrencinin sorusu üzerine şu konuşuldu (00:45:16):

**Soru:** Öznitelikleri çıkarma sırası önemli mi? Hep en iyiyi çıkarmak yanlış bir yöne götürmez mi? **Cevap:** Önemli. Her özniteliğin etkisi farklıdır; bazı sınıflar tek bir öznitelikle bile ayrılabilir. Açgözlü algoritmada bir öznitelik çıkarıldıktan sonra geri dönüş yoktur; o yüzden sonra daha iyisi hiç bulunamayabilir. Bu tür durumlarda genellikle algoritma örneğin 10 farklı rastgele başlangıçla çalıştırılır ve hangisi daha iyi buluyorsa oradan devam edilir; hoca bunun optimizasyon dersinde görüleceğini söyledi. Genelde her adımda o an en iyi olan seçilir.

## 9. Kural Değerlendirme: FOIL Bilgi Kazancı

Kural büyütülürken hangi koşulun ekleneceğine (ya da çıkarılacağına) karar vermek için bir değerlendirme ölçüsü gerekir. Akla ilk gelen accuracy'dir: bir koşulu çıkarınca accuracy düşüyorsa onu çıkarmanın anlamı yoktur. Ama yalnız accuracy yeterli değildir (00:46:52). Binlik bir eğitim kümesinde yalnız iki satıra uyan bir kural o iki satırı doğru buluyorsa accuracy'si zaten $\%100$'dür. Yalnız accuracy'ye bakılırsa neredeyse her satır için ayrı bir kural yazmaya doğru gidilir. Bu yüzden kuralın koşul kısmının tüm verinin ne kadarını kapsadığına, yani coverage'e de bakılmalıdır.

### 9.1 Yalnız accuracy'nin yetersizliği: örnek

Slayttaki örnek şöyledir (ekrandan, 00:47:06; hoca 00:55:20'de tekrar anlattı):

- Eğitim kümesinde 60 pozitif, 100 negatif örnek var.
- R1: 50 pozitif ve 5 negatif örneği kapsıyor.
- R2: 2 pozitif örneği kapsıyor, hiç negatif örnek kapsamıyor.

R2'nin accuracy'si $\%100$'dür ve R1'inkinden ($50/55 \approx \%90.9$) yüksektir. Ama R2 60 pozitiften yalnız ikisini ayırabilir, etkisi çok azdır. R1 ise 60 pozitifin 50'sini kapsar; coverage'i çok daha yüksek olduğu için daha iyi bir kuraldır. Demek ki coverage'i hesaba katan bir ölçüye ihtiyaç vardır: FOIL bilgi kazancı ve benzeri ölçüler.

### 9.2 FOIL bilgi kazancının tanımı

FOIL bilgi kazancı (FOIL's Information Gain), hem coverage'i hem accuracy'yi dikkate alan bir kural kalitesi ölçüsüdür (ekrandan, 00:54:00). İki kural karşılaştırılır:

```text
R0: {A} => class          (başlangıç kuralı)
R1: {A and B} => class    (B koşulu eklendikten sonraki kural)
```

$$\text{FOIL\_Gain}(R_0, R_1) = p_1 \times \left( \log_2 \frac{p_1}{p_1 + n_1} - \log_2 \frac{p_0}{p_0 + n_0} \right)$$

- $p_0$: R0'ın kapsadığı pozitif örnek sayısı; $n_0$: R0'ın kapsadığı negatif örnek sayısı.
- $p_1$: R1'in kapsadığı pozitif örnek sayısı; $n_1$: R1'in kapsadığı negatif örnek sayısı.

Soru şudur: R0 mı daha iyi, yoksa B eklenerek genişletilen R1 mi? (00:50:43)

### 9.3 Formülün sezgisi

$\frac{p_1}{p_1+n_1}$, kuralın doğru sınıfladıklarının, kuralın kapsadığı bütün örneklere (doğru ve yanlış) oranıdır; yani tek başına bakılınca accuracy gibidir. R1 için örnekteki değerlerle bu oran $50/55$ olur. Sınıflandırıcı çok iyiyse bu oran 1'e yakın, kötüyse örneğin $1/2$ civarında çıkar (00:57:19).

$\log_2$ içindeki oran 1'den küçük olduğu için logaritma negatif çıkar. Koşul eklenince kural iyileşmişse R1'in oranı R0'ınkinden büyüktür, yani $\log_2$ değeri sıfıra daha yakındır; R0'ın daha negatif logaritması çıkarıldığında ("eksi negatif") parantezin içi pozitif olur (00:53:19).

Sonra bu fark $p_1$ ile, yani son kuralın doğru kapsadığı pozitif örnek sayısıyla çarpılır. Hoca bunu bir katsayı gibi yorumladı: R1'e C eklenmesi, D eklenmesi gibi adaylar karşılaştırılırken hangisi daha çok veriyi doğru kapsıyorsa onunla çarpılmış olur; böylece çok örnek kapsayan aday öne çıkar (00:57:54). Hoca, bunun kafa karıştıracak bir şey olmadığını, formülün hem accuracy'yi hem coverage'i içerdiğini vurguladı.

> **Hocanın vurgusu:** Yalnız accuracy'ye bakmak mantıklı değildir; tek bir örneği kapsayan kural bile $\%100$ accuracy alır. Bu yüzden ölçünün içinde coverage de olmalıdır.

Hoca ayrıca FOIL'in kendi başına, RIPPER gibi bir kural öğrenme yöntemi olduğunu da belirtti (00:47:44).

## 10. Dolaylı Yöntem: Karar Ağacından Kural Çıkarma

Doğrudan yöntemin karşısında dolaylı yöntem vardır (00:58:43). Önce C4.5 gibi bir yöntemle karar ağacı kurulur, sonra kurallar ağaçtan çıkarılır. Slayttaki noktalar şunlardır (ekrandan, 00:59:00):

- Kuralları anlamak büyük ağaçları anlamaktan kolaydır.
- Kökten bir yaprağa giden her yol için bir kural oluşturulur.
- Yol boyunca her öznitelik-değer çifti bir bağlaç (AND) oluşturur; yaprak sınıf tahminini taşır.
- Kurallar karşılıklı dışlayan ve kapsayıcıdır.

buys_computer ağacında kök "age?" düğümüdür. age ≤ 30 dalında "student?" düğümü vardır (no → no, yes → yes); 31..40 dalı doğrudan yes yaprağıdır; > 40 dalında "credit rating?" düğümü vardır (excellent → no, fair → yes). Bu ağaçtan beş kural çıkar:

```text
IF age = young AND student = no             THEN buys_computer = no
IF age = young AND student = yes            THEN buys_computer = yes
IF age = mid-age                            THEN buys_computer = yes
IF age = old AND credit_rating = excellent  THEN buys_computer = no
IF age = old AND credit_rating = fair       THEN buys_computer = yes
```

Hoca kuralların neden karşılıklı dışlayan ve kapsayıcı olduğunu sordu. Ağaçta bir öznitelik bir yolda bir kez kullanılır ve her kayıt yapraklara kadar inip tam bir yola düşer; bu yüzden bir kayıt iki kurala birden uymaz. Ağaç eğitim kümesinin tamamından kurulduğu için açıkta kalan kayıt da yoktur (00:59:15). Hoca bunun budanmamış (unpruned) ağaç için geçerli olduğunu belirtti; bir özniteliğin bir yolda birden fazla geçtiği durumların slaytta anlatıldığını söyleyip geçti.

> **Ders sonrası not:** Altyazıda hocanın "mutually exclusive midir?" sorusuna verdiği cevap "Değildir, değil mi?" diye yazılmış, ama gerekçe ("her şey bir kural içine girer", bir öznitelik bir yolda bir kez kullanılır) ve slayt, ağaçtan çıkan kuralların karşılıklı dışlayan olduğunu söyler. Doğrusu: budanmamış bir karar ağacından çıkarılan kurallar hem karşılıklı dışlayan hem kapsayıcıdır.

Hoca kural tabanlı sınıflandırmayı burada kapattı ve istatistiksel bir yöntem olan Naive Bayes sınıflandırmaya geçti.

## 11. Olasılık ve Bayes Teoremi

Bayes sınıflandırıcıları tamamen istatistikten veri madenciliğine geçmiş yöntemlerdir; kullandıkları araç Bayes teoreminin kendisidir. En basiti Naive Bayes sınıflandırıcıdır; Bayes inanç ağları (belief networks) gibi ondan türemiş çeşitleri de vardır. Hoca, optimal Bayes yönteminin bütün çıkarımlarını yapmanın çok büyük veri kümelerinde mümkün olmadığını, ama çıkarılabildiği kadarıyla güzel sonuç veren bir yöntem olduğunu söyledi (01:01:14).

### 11.1 Notasyon

- $P(A)$: A olayının (event) olma olasılığı.
- $P(A|B)$: B olduğunda A'nın olma olasılığı (koşullu olasılık).
- $P(A,B)$: A ve B'nin birlikte olma olasılığı (ortak olasılık, joint probability). Bazı kitaplarda virgülle yazılır; kesişim olarak $P(A \cap B)$ diye düşünülebilir. Kesişim olduğu için $P(A,B) = P(B,A)$'dır.

### 11.2 Teoremin türetilmesi

Hoca iki olayı iki kesişen daire olarak çizdi (ekrandan, 01:04:00). B'nin olduğu biliniyorsa, A'nın da olma olasılığı kesişimin B içindeki payıdır. Slayttaki türetme şöyledir:

$$P(A|B) = \frac{P(A,B)}{P(B)} \;\Rightarrow\; P(A,B) = P(A|B)\,P(B)$$

$$P(B|A) = \frac{P(B,A)}{P(A)} \;\Rightarrow\; P(B,A) = P(B|A)\,P(A)$$

$P(A,B) = P(B,A)$ olduğundan $P(A|B)\,P(B) = P(B|A)\,P(A)$ olur. Buradan Bayes teoremi elde edilir:

$$P(A|B) = \frac{P(B|A)\,P(A)}{P(B)}, \qquad P(B|A) = \frac{P(A|B)\,P(B)}{P(A)}$$

Hoca, yapılan tek şeyin iki ifadedeki kesişimleri çekip birbirine eşitlemek olduğunu söyledi.

### 11.3 Tablo üzerinde örnek

A ve B olaylarının 7 durumda doğru (T) ya da yanlış (F) olduğu bir tablo verildi (ekrandan, 01:09:00). Hoca bunu 7 zaman dilimi gibi düşünmeyi önerdi: birinci dilimde A da B de olmuş, ikincide A olmuş B olmamış, üçüncüde A olmamış B olmuş, vb.

| | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| A holds | T | T | F | F | T | F | T |
| B holds | T | F | T | F | T | F | F |

- $P(A) = 4/7$ (A'nın dört T'si var), $P(B) = 3/7$.
- $P(B|A)$: A'nın doğru olduğu 4 durumdan (1, 2, 5, 7) B yalnız ikisinde (1, 5) doğru; $P(B|A) = 2/4$.
- $P(A|B)$: B'nin doğru olduğu 3 durumdan (1, 3, 5) A ikisinde (1, 5) doğru; $P(A|B) = 2/3$.
- $P(A,B) = P(B,A) = 2/7$: ikisinin birlikte doğru olduğu 2 durum (1 ve 5), toplam 7 durum.

Slayt teoremi bu değerlerle doğrular:

$$P(B|A) = \frac{P(A|B)\,P(B)}{P(A)} = \frac{(2/3)(3/7)}{4/7} = \frac{2}{4}, \qquad P(A|B) = \frac{P(B|A)\,P(A)}{P(B)} = \frac{(2/4)(4/7)}{3/7} = \frac{2}{3}$$

Hoca burada koşullu olasılık ile kesişimin farkını vurguladı: kesişim ikisinin de doğru olduğu durumları (T, T) içerir ve paydası tüm durumlardır. $P(B|A)$ ise yalnız A'nın olduğu durumlara bakar; A olup B'nin yanlış olduğu durumlar da paydaya dahildir (01:09:45).

### 11.4 Menenjit örneği

Slayttaki soru (01:10:26): menenjit, vakaların $\%50$'sinde boyun tutulmasına (stiff neck) neden olur, yani $P(S|M) = 0.5$. Boyun tutulması olasılığı $P(S) = 1/20$'dir. Boynu tutulmuş bir hastanın menenjit olma olasılığı nedir?

Doğrudan Bayes teoremi uygulanır:

$$P(M|S) = \frac{P(S|M)\,P(M)}{P(S)}$$

Hoca değerler yerine konduğunda sonucun 10.000'de 2 gibi çok düşük bir oran çıktığını söyledi.

<!-- BELİRSİZ: Bu slayt karelerde yok; menenjitin önsel olasılığı P(M) altyazıda okunmadı. -->

> **Ders sonrası not:** Sonucun $2/10000 = 0.0002$ çıkması için $P(M) = 1/50000$ olmalıdır: $0.5 \times (1/50000) / (1/20) = 0.0002$. Slaytta büyük olasılıkla bu değer yazıyordu.

## 12. Olayların Bağımsızlığı

İki olay ancak ve ancak $P(A,B) = P(A)\,P(B)$ ise bağımsızdır (independent); yani kesişimlerinin olasılığı, olasılıklarının çarpımına eşitse (01:11:47).

Slayttaki örnek 3 uzunluğundaki bit dizileridir (ekrandan, 01:14:00): $\{000, 001, 010, 011, 100, 101, 110, 111\}$, toplam $2^3 = 8$ dizi.

- Olay A: rastgele üretilen 3 bitlik dizi 1 ile başlar. $P(A) = 4/8$ (100, 101, 110, 111).
- Olay B: dizi 1 ile biter. $P(B) = 4/8$ (001, 011, 101, 111).
- $P(A,B) = 2/8$ (101, 111).
- $P(A)\,P(B) = (4/8)(4/8) = 16/64 = 2/8 = P(A,B)$. A ve B bağımsızdır.

- Olay C: dizi tam iki tane 1 içerir. $P(C) = 3/8$ (011, 101, 110).
- $P(A,C) = 2/8$ (101, 110).
- $P(A)\,P(C) = (4/8)(3/8) = 12/64 = 3/16 \neq 2/8$. A ve C bağımsız değildir.

Yani "1 ile başlama" ile "iki tane 1 içerme" olayları birbirinden bağımsız değildir.

## 13. Naive Bayes Sınıflandırıcı

### 13.1 Bayes teoremini veriye uygulamak

Hoca öğrencilere Bayes teoreminin bir eğitim kümesine nasıl uygulanacağını sordu (01:15:25). A, B, C olayları özniteliklere karşılık gelir. $P(A|B)$ ifadesinde koşul tarafındaki B öznitelikler olursa, A sınıf olur. Yani "öznitelikleri bunlar ve bunlar ise (given) sınıfın şu olma olasılığı nedir?" sorusu cevaplanır.

X verinin bir örneğidir, yani öznitelik değerleri kümesidir. H ise "X, C sınıfına aittir" hipotezidir. Hayvan örneğinden gidilirse, kan tipi sıcak ve uçma yeteneği evet olan bir kayıt X'tir; hipotez bu kaydın belli bir sınıfa ait olup olmadığıdır. Bayes teoremiyle:

$$P(H|X) = \frac{P(X|H)\,P(H)}{P(X)}$$

Burada $P(H)$ önsel olasılıktır (prior probability), yani kaydın bu sınıfa ait olma olasılığı. $P(X|H)$ hipotez verildiğinde bu verinin görülme olasılığıdır, $P(X)$ verinin kendisinin olasılığıdır. Bu olasılıklar her sınıf için hesaplanır; hangi sınıfınki daha yüksekse kayıt o sınıfa atanır (01:17:41).

> **Ek bilgi (derste anlatılmadı):** $P(X)$ bütün sınıflar için aynı olduğundan karşılaştırmada atlanabilir; bu yüzden pratikte yalnız $P(X|C)\,P(C)$ değerleri karşılaştırılır.

### 13.2 buys_computer örneği

Veri kümesinde 14 kayıt ve iki sınıf vardır: buys_computer = yes ve buys_computer = no (ekrandan, 01:19:00).

| age | income | student | credit_rating | buys_computer |
|---|---|---|---|---|
| <=30 | high | no | fair | no |
| <=30 | high | no | excellent | no |
| 31...40 | high | no | fair | yes |
| >40 | medium | no | fair | yes |
| >40 | low | yes | fair | yes |
| >40 | low | yes | excellent | no |
| 31...40 | low | yes | excellent | yes |
| <=30 | medium | no | fair | no |
| <=30 | low | yes | fair | yes |
| >40 | medium | yes | fair | yes |
| <=30 | medium | yes | excellent | yes |
| 31...40 | medium | no | excellent | yes |
| 31...40 | high | yes | fair | yes |
| >40 | medium | no | excellent | no |

**Önsel olasılıklar.** 9 kayıt yes, 5 kayıt no'dur: $P(bc = yes) = 9/14$, $P(bc = no) = 5/14$.

**Koşullu olasılıklar.** Her öznitelik değeri için, sınıf verildiğinde o değerin görülme olasılığı doğrudan sayılarak bulunur. Örneğin sınıfı yes olan 9 kaydın 3'ünde yaş 40'tan büyüktür; sınıfı no olan 5 kaydın 3'ünde yaş 30'dan küçüktür, bu yüzden $3/5$ gelir. 31..40 yaşında olup no olan hiç kayıt yoktur; bu olasılık 0'dır (01:19:37). Aynı sayım income, student ve credit_rating için de yapılır. Slayttaki tablo şöyledir (ekrandan, 01:24:00; b31: 30 ve altı, i31: 31..40, g40: 40'tan büyük):

| Öznitelik değeri | $P(\cdot \mid yes)$ | $P(\cdot \mid no)$ |
|---|---|---|
| age = b31 | 2/9 | 3/5 |
| age = i31 | 4/9 | 0 |
| age = g40 | 3/9 | 2/5 |
| income = high | 2/9 | 2/5 |
| income = medium | 4/9 | 2/5 |
| income = low | 3/9 | 1/5 |
| student = yes | 6/9 | 1/5 |
| student = no | 3/9 | 4/5 |
| credit = excellent | 3/9 | 3/5 |
| credit = fair | 6/9 | 2/5 |

Bu olasılıklar eğitim kümesinden hesaplanıp bir yerde saklanır.

**Test zamanı.** Tabloda olmayan yeni bir test kaydı gelir: yaşı 30'dan küçük, income = medium, student = yes, credit_rating = fair (01:22:57). Bu kişi bilgisayar alır mı? Öznitelikler bağımsız varsayıldığı için her sınıf için kaydın öznitelik olasılıkları çarpılır, sonra sınıfın önsel olasılığıyla çarpılır (ara adımlar eklendi):

$$P(X|yes) = \frac{2}{9} \cdot \frac{4}{9} \cdot \frac{6}{9} \cdot \frac{6}{9} = \frac{32}{729} \approx 0.044$$

$$P(X|no) = \frac{3}{5} \cdot \frac{2}{5} \cdot \frac{1}{5} \cdot \frac{2}{5} = \frac{12}{625} = 0.0192$$

$$P(X|yes)\,P(yes) \approx 0.044 \times \frac{9}{14} \approx 0.028, \qquad P(X|no)\,P(no) = 0.0192 \times \frac{5}{14} \approx 0.007$$

$0.028 > 0.007$ olduğu için kaydın sınıfı yes'tir; bu kişi bilgisayar alır. Hoca, çarpımları tek başına karşılaştırmanın yetmediğini, önsel olasılıklarla (9 yes, 5 no) çarparak "normalize etmek" gerektiğini vurguladı (01:21:39).

> **Ders sonrası not:** Hoca önce "bunlardan en yüksek olanları alıyoruz, burada en yüksek olan 4/9" dedi (01:20:38). Doğrusu: çarpıma en yüksek olasılıklar değil, test kaydının kendi öznitelik değerlerinin olasılıkları girer. Örneğin yes için yaş terimi $4/9$ değil, $P(age \le 30 \mid yes) = 2/9$'dur. Hoca daha sonra (01:25:00) test kaydının değerlerini kullandığını açıkça söyledi. Ayrıca altyazıda yes için ara sonuç "0.0044" diye geçiyor; doğru değer $32/729 \approx 0.044$'tür.

Bir öğrencinin isteği üzerine hoca hesabı bir daha anlattı (01:25:00): test kısmında kaydın sınıfı soruluyor; yes için de no için de aynı öznitelikler kullanılıyor. Örneğin no sınıfı için yaşın 30'dan küçük olma olasılığı $3/5$, student = yes olma olasılığı $1/5$ alınıyor. Bu olasılıklar çarpılıyor, sonra sınıfın önsel olasılığıyla çarpılıyor ve en yüksek olasılığı veren sınıf seçiliyor.

### 13.3 Zorluklar ve sıfır olasılık sorunu

Hoca yöntemin zor tarafını sordu (01:26:05). Birincisi, her şeyi sayıp bir yerde tutmak ve test zamanında çok işlem yapmak gerekir. İkincisi, tabloda bir sıfır vardır: no sınıfında 31..40 yaşında hiç kayıt yoktur. Bu sıfır formüle konursa bütün çarpım sıfırlanır. Eğitim kümesinde az örnek varsa sıfırlar çıkar ve tek bir sıfır o sınıfın seçilme ihtimalini tamamen ortadan kaldırır. Bu örnekte sistem yaşı 31..40 arasında olan hiç kimseye "no" diyemez; no olasılığı sıfır çıkacağı için hep "alır" der.

Bunu önlemek için düzleştirme (smoothing) kullanılır; ya da slayttaki örnekte olduğu gibi her sayıma bir eklenir (01:27:38). Hoca slaytta bu konuda bir örnek daha olduğunu, ama üzerinden geçmeyeceklerini söyledi.

> **Ek bilgi (derste anlatılmadı):** Her sayıma bir ekleme yöntemine Laplace düzeltmesi (Laplace smoothing) denir. Bir özniteliğin $k$ farklı değeri varsa, $C$ sınıfında $n_C$ kayıt bulunuyorsa olasılık $(\text{sayım}+1)/(n_C + k)$ olarak hesaplanır; böylece hiçbir olasılık sıfır olmaz ve olasılıklar yine toplamı 1 olacak şekilde kalır.

### 13.4 Artılar, eksiler ve bağımsızlık varsayımı

Slayttaki değerlendirme şöyledir (ekrandan, 01:29:00):

- Artılar: uygulanması kolaydır; çoğu durumda iyi sonuç verir.
- Eksiler: sınıf koşullu bağımsızlık (class conditional independence) varsayımı doğruluk kaybına yol açar. Pratikte değişkenler arasında bağımlılıklar vardır. Örneğin hastanelerde hastaların profili (yaş, aile geçmişi), belirtileri (ateş, öksürük) ve hastalıkları (akciğer kanseri, diyabet) birbirine bağlıdır. Bu bağımlılıklar Naive Bayes sınıflandırıcıyla modellenemez.

Hoca bütün özniteliklerin bağımsız varsayıldığını, gerçek dünyada öznitelikler bağımsız değilse yöntemin iyi çalışmayacağını vurguladı (01:27:54). Bağımlılık olduğu biliniyorsa Bayes inanç ağları (belief networks) kullanılabilir; bunlar biraz farklı çalışır (01:29:11).

> **Ders sonrası not:** Hoca bağımsızlık varsayımını Bayes teoreminin kesişimden çıkarılmasına bağladı ve teorem türetilirken olayların bağımsız olması gerektiğini ima etti (00:13:00, 01:28:13). Doğrusu: Bayes teoremi bağımsızlık gerektirmez, her iki olay için geçerlidir. Bağımsızlık varsayımı Naive Bayes'e özgüdür ve $P(X|C)$'yi öznitelik olasılıklarının çarpımı olarak yazabilmek için yapılır.

> **Ders sonrası not:** Hoca Naive Bayes'in "çok yavaş çalıştığını" söyledi (01:27:54). Naive Bayes genellikle hızlı bir yöntem olarak bilinir: eğitim yalnız sayımdan oluşur, test zamanında da her sınıf için öznitelik sayısı kadar çarpma yapılır. Hocanın kastı büyük olasılıkla sayımları saklama ve test zamanındaki hesap yüküydü.

## 14. Weka ile Uygulama

### 14.1 Weka nedir?

Weka, Yeni Zelanda'da Waikato Üniversitesi'nde geliştirilmiş, tamamen Java ile yazılmış bir veri madenciliği aracıdır (01:43:16). Açık kaynaklıdır: istenirse yöntemlerin kodları indirilip çalıştırılabilir ve değiştirilebilir, istenirse arayüz kullanılır. Büyük bir program değildir; güzelliği, işlerin hızlıca yapılabilmesidir. Logosundaki kuş da o bölgeye ait weka kuşudur.

Tools menüsündeki Package Manager ile başkalarının yazdığı özel paketler yüklenebilir; örneğin sınıflandırma için geliştirilmiş yeni algoritmalar ya da gizli Markov modelleri. Bunlar seçilip "install" edilerek standart yöntemlerin yanında kullanılabilir (01:47:07).

### 14.2 Veri kaynakları

Hoca veri bulmak için iki kaynak gösterdi. Kaggle'da çok sayıda veri kümesi vardır; şirketler, üniversiteler ve kişiler veri ekler, yarışmalar (competition) düzenlenir. Bazı veri kümelerinin hazır çözüm kodu ve eğitimleri de vardır; hoca bunların doğrudan alınıp kullanılmaması, üzerine yeni yöntem geliştirilmesi ya da değiştirilerek kullanılması gerektiğini söyledi (01:45:15). UCI Machine Learning Repository de bir veri deposudur; Kaggle'dan daha eskidir ve yalnız veri içerir, Kaggle'da ise videolar ve eğitimler de bulunur (01:50:11). Hoca çok küçük bir veri kümesi seçilmemesini, çünkü yöntemlerin sağlıklı çalışmayacağını söyledi.

### 14.3 Iris veri kümesi

Uygulamada Iris veri kümesi kullanıldı (01:50:41). Bu, çiçeklerle ilgili bir veri kümesidir. Üç çiçek türü (sınıf) vardır: Setosa, Versicolor ve Virginica. Dört öznitelik vardır: çanak yaprak (sepal) ve taç yaprağın (petal) uzunluğu ve genişliği (sepal.length, sepal.width, petal.length, petal.width). Her türden 50 örnek, toplam 150 örnek vardır. Sınıf sütununun adı "variety"dir (ekrandan, 02:14:00).

### 14.4 CSV biçimi ve Türkçe Excel sorunu

CSV (comma separated values), sütunların virgülle ayrıldığı bir metin dosyasıdır. Iris CSV'si bir metin düzenleyiciyle açıldığında başlıkların tırnak içinde olduğu, sütunların virgülle ayrıldığı görülür (01:53:58).

> **Hocanın vurgusu:** En sık yapılan hata Excel ayarlarından kaynaklanır.

İngilizcede ondalık ayırıcı nokta (5.1), Türkçede virgüldür (5,1); Türkçede nokta binlik ayırıcı olarak kullanılır. Bu yüzden Türkçe ayarlı Excel, CSV kaydederken sütunları virgül yerine noktalı virgülle ayırır. 5,1 ve 4,6 gibi değerler virgülle ayrılsaydı CSV okuyucu her değeri iki sütun sanardı. CSV açarken sorun yaşanıyorsa büyük ihtimalle sebep virgül, noktalı virgül ve nokta karışıklığıdır; Excel'in ayarı düzeltilip dosya yeniden "farklı kaydet" ile kaydedilerek sorun giderilir (01:54:49).

### 14.5 Explorer ve Preprocess sekmesi

Explorer, en çok kullanılan arayüzdür. Sekmeleri Preprocess, Classify, Cluster, Associate, Select attributes ve Visualize'dır (ekrandan, 01:59:00). Preprocess'te veri açılır ve üzerinde filtreleme gibi işlemler yapılır. Veri birkaç yoldan açılabilir: dosyadan (Open file), URL'den (Open URL) ya da bir veri tabanı bağlantısıyla (Open DB). Weka JSON, LibSVM, CSV ve kendi biçimi olan ARFF dosyalarını açabilir (01:57:49). Weka kurulunca bazı varsayılan veri kümeleri de gelir.

Iris CSV'si açıldığında (ekrandan, 01:59:00) ilişki (relation) adı iris, örnek sayısı 150, öznitelik sayısı 5 görünür. Bir öznitelik seçilince istatistikleri gösterilir; sepal.length için: Minimum 4.3, Maximum 7.9, Mean 5.843, StdDev 0.828; eksik değer yok, 35 farklı değer var. Sınıf olarak nominal "variety" seçildiğinde histogramlar üç sınıfa göre üç renkle boyanır. Sınıf olarak sayısal bir öznitelik (örneğin sepal.length) seçilirse değerler sürekli olduğu için boyama yapılmaz (01:58:51).

**Filtreler.** Filtreler hem öznitelik (attribute, tüm sütunu etkileyen) hem örnek (instance, satır) bazında, ayrıca denetimli (supervised: etiket varsa) ve denetimsiz (unsupervised: etiket yoksa, kümeleme gibi) olarak ayrılmıştır (01:59:25). Örnekler:

- NominalToBinary: nominal değerleri ikili (binary) değerlere çevirir. Filtre adına tıklanınca parametreleri açılır; fare üzerine gelince parametrenin açıklaması görünür. Apply ile uygulanır; hoca veriyi bozmamak için uygulamadı.
- Discretize: sürekli değeri bin'lere ayırır. Bin sayısı ve hangi özniteliklerin ayrıklaştırılacağı (first-last tümü, ya da yalnız 3 gibi bir numara) seçilir. Öznitelik numaraları Python'daki gibi 0'dan değil, 1'den başlar (02:01:26).
- RemoveRange: belirli bir aralıktaki örnekleri siler (örneğin 18 yaş altını almamak).
- RemoveDuplicates: aynı satırdan birden fazla varsa tekrarları siler.
- RemoveWithValues: belli bir değere sahip örnekleri siler.

### 14.6 Classify sekmesi ve test seçenekleri

Classifier listesinde derste öğrenilen yöntemler bulunur: trees altında karar ağaçları, rules altında kural tabanlı sınıflandırıcılar, bayes altında NaiveBayes (ekrandan, 02:09:00). Test seçenekleri şunlardır (ekrandan, 02:04:00):

- Use training set: 150 örneğin hepsi eğitim için kullanılır, ayrı test yoktur.
- Supplied test set: test için ayrı bir dosya verilir.
- Cross-validation (Folds): çapraz doğrulama.
- Percentage split: veri rastgele ayrılır; örneğin $\%80$ eğitim, $\%20$ test.

**Çapraz doğrulama.** Hoca bunun önemli olduğunu söyledi ve 3 katlı (fold) örnekle anlattı (02:03:33). Veri rastgele A, B, C diye üç parçaya ayrılır ve üç tur yapılır:

```text
Tur 1: eğitim = A, B   test = C
Tur 2: eğitim = A, C   test = B
Tur 3: eğitim = B, C   test = A
```

Böylece her örnek bir kez test edilir; her turda veri farklı olduğu için farklı bir model öğrenilir ve sonuçta ortalama hata verilir. Çapraz doğrulama genellikle veri az olduğunda kullanılır: test için ayrılan $\%10$'a yalnız 20-30 örnek düşüyorsa, bunun yerine model birkaç kez kurulup tüm veri üzerinde doğrulanır (02:04:27).

"More options" altında her sınıf için istatistikler, "Output predictions" ile tahminlerin düz metin (plain text) olarak gösterilmesi ve "Preserve order for % split" seçenekleri vardır. Preserve order seçilirse veri karıştırılmadan (shuffle yapılmadan) ilk $\%80$ eğitime, son $\%20$ teste ayrılır; hoca bunu işaretlemedi (02:05:29).

### 14.7 Iris üzerinde sonuçlar

**Naive Bayes, $\%80$ eğitim.** Çıktıda kullanılan sınıflandırıcı, ilişki adı (iris.csv; ARFF'te tanımlanmadığı için dosya adı yazılmış), 150 örnek, 5 öznitelik ve test modu görünür. Modelde sınıfların önsel dağılımı (her biri yaklaşık $\%33$, her sınıftan 50 örnek) ve her öznitelik için sınıf bazında ortalama ve standart sapma gibi istatistikler yer alır (02:07:12). Tahminler listesinde her test örneğinin gerçek ve tahmin edilen sınıfı ile güven değeri görülür; 18. örnekte bir Virginica, Versicolor olarak tahmin edilmiştir. 150 örneğin $\%20$'si olan 30 test örneğinden 29'u doğru sınıflanmıştır: $29/30 = \%96.6667$ (ekrandan, 02:09:00). Hoca, gerçek projelerde sonuçların bu kadar iyi çıkmayacağını, çıktıdaki diğer ölçülerin ve karışıklık matrisinin (confusion matrix) ileride öğrenileceğini söyledi.

**Kural tabanlı sınıflandırıcı.** Rules altındaki bir sınıflandırıcı çalıştırıldı ve $\%80$ ayrımda $\%100$ doğruluk elde edildi (02:09:07). Hoca bulunan kuralları okudu: birinci kural petal ölçülerine dayalı üç koşulla Versicolor diyor, ikinci kural Virginica diyor, en sondaki varsayılan kuralın önünde hiçbir koşul yok ve geri kalan her şeye Setosa diyor.

<!-- BELİRSİZ: Hangi kural sınıflandırıcının seçildiği ve kurallardaki öznitelik adları ile eşik değerleri (altyazıda "büyük eşit 3", "küçük eşit 4.8", "küçüktür 1.6", "4.5'tan büyük") karelerde yok; altyazıda length/width ayrımı okunamıyor. -->

**Eğitim oranını $\%50$'ye düşürmek.** Hoca doğruluğun düşmesini beklediklerini söyledi. Kural sınıflandırıcıda doğruluk $\%100$'den $\%94$'e düştü; veri karıştırıldığı için sonuç her çalıştırmada değişebilir. Naive Bayes olasılık hesapladığı için daha çok etkilenmesi beklenir; ama $\%50$ ayrımda yine yaklaşık $\%96$ doğrulukla çalıştı (02:10:36).

### 14.8 Visualize sekmesi

Visualize sekmesi öznitelik çiftleri arasındaki ilişkiyi, sınıflara göre renklendirilmiş saçılım grafikleriyle gösterir (02:10:52). Bir özniteliğin kendisiyle grafiği düz bir çizgi verir, çünkü korelasyon 1'dir. petal.width ile petal.length arasında pozitif bir korelasyon görülür. petal.length ile sepal.width grafiğinde sınıfların oldukça ayrılabilir olduğu görülür.

### 14.9 ARFF biçimi

ARFF, Weka'nın kendi veri biçimidir (uzantı .arff); ama CSV de verilebilir (02:11:44). Dosyada % ile başlayan satırlar yorumdur. Yapı şöyledir:

```text
% yorum satırları
@relation <veri kümesinin adı>
@attribute <sayısal öznitelik adı> real
...
@attribute class {<sınıf 1>, <sınıf 2>, <sınıf 3>}
@data
<değer>,<değer>,...,<sınıf>
...
```

`@relation` ile veri kümesine istenen ad verilir. Her öznitelik `@attribute` ile tanımlanır; sayısal öznitelikler `real` olarak, nominal sınıf ise süslü parantez içinde olası değerleri virgülle yazılarak tanımlanır (cinsiyet olsaydı "kadın, erkek" yazılırdı). `@data` satırından sonra veri, virgülle ayrılmış satırlar halinde yazılır.

<!-- BELİRSİZ: Derste gösterilen iris ARFF dosyası karelerde görünmüyor; yapı altyazıdaki anlatımdan kuruldu, öznitelik adları yazılmadı. -->

### 14.10 Weka ne zaman kullanılır?

Weka JVM üzerinde çalıştığı için, veri çok büyükse ve özellikle yapay sinir ağları gibi bazı yöntemlerde bellek hatası verebilir. Ayarlarından JVM'e ayrılan bellek artırılabilir, ama yine de çok büyük verilerle iyi çalışmaz (02:12:44).

Hoca, veri temizlemenin kendi yazılan kodla, kurallara göre daha kolay olduğunu düşündüğünü söyledi; Preprocess filtreleri işi arka planda yaptığı için ne olduğu pek görülmez. Elde çok temizlenmeyecek bir veri varsa ve hızlıca sınıflandırma yapılıp yapılamayacağına bakılacaksa, ya da küçük bir veri kümesi varsa Weka hızlı bir araçtır. Ama örneğin bir sunucuda arka planda kural tabanlı sınıflandırma çalıştırılacaksa, Weka'nın sitesinden ilgili Java kodu indirilip programdan çağrılmalıdır; arayüzden bu yapılamaz (02:13:26).

Bir başka sınır, yöntemlerin parametrelerinin arayüzde sınırlı ölçüde değiştirilebilmesidir. Örneğin trees altında J48 seçildiğinde şu parametreler görülür: batch size (her seferde kaç örnek üzerinden işlem yapılacağı), binary splits (ikili bölme mi yapılsın, yoksa üçlü dörtlü bölmelere izin verilsin mi), unpruned (budama yapılsın mı) vb. Yalnız arayüzün verdiği parametreler değiştirilebilir; kodla çalışınca daha fazla parametreyle oynanabilir (02:15:01).

> **Ek bilgi (derste anlatılmadı):** J48, C4.5 karar ağacı algoritmasının Weka'daki Java gerçeklemesidir. Weka'nın rules altındaki JRip sınıflandırıcısı da derste anlatılan RIPPER algoritmasının gerçeklemesidir.

## Örnek Sorular

### Soru 1 (ekrandan, 01:09:00)

7 durumda A ve B olaylarının doğruluk değerleri aşağıdadır. $P(A)$, $P(B)$, $P(A,B)$, $P(B|A)$ ve $P(A|B)$ değerlerini bulun ve Bayes teoreminin doğru olduğunu gösterin.

| A holds | T | T | F | F | T | F | T |
|---|---|---|---|---|---|---|---|
| B holds | T | F | T | F | T | F | F |

**Çözüm (derste verildi):** $P(A) = 4/7$, $P(B) = 3/7$, $P(A,B) = 2/7$, $P(B|A) = 2/4$, $P(A|B) = 2/3$.

$$P(B|A) = \frac{(2/3)(3/7)}{4/7} = \frac{2}{4}, \qquad P(A|B) = \frac{(2/4)(4/7)}{3/7} = \frac{2}{3}$$

İki eşitlik de sağlanır; teorem doğrudur.

### Soru 2 (ekrandan, 01:14:00)

3 bitlik diziler kümesinde A: "dizi 1 ile başlar", B: "dizi 1 ile biter", C: "dizi tam iki tane 1 içerir" olayları tanımlanıyor. A ve B bağımsız mı? A ve C bağımsız mı?

**Çözüm (derste verildi):** $P(A) = P(B) = 4/8$, $P(A,B) = 2/8$ (101, 111). $P(A)P(B) = 16/64 = 2/8$; A ve B bağımsızdır. $P(C) = 3/8$, $P(A,C) = 2/8$ (101, 110). $P(A)P(C) = 12/64 = 3/16 \ne 2/8$; A ve C bağımsız değildir.

### Soru 3 (derste sözlü, 01:10:26)

Menenjit vakaların $\%50$'sinde boyun tutulmasına yol açar. Boyun tutulması olasılığı $1/20$'dir. Boynu tutulmuş bir hastanın menenjit olma olasılığı nedir?

**Çözüm (derste verildi):** $P(M|S) = P(S|M)\,P(M)/P(S)$. Hoca sonucun 10.000'de 2 olduğunu söyledi.

<!-- BELİRSİZ: Menenjitin önsel olasılığı P(M) altyazıda geçmiyor ve kare yok. Sonucun 0.0002 çıkması için P(M) = 1/50000 olmalıdır (python ile kontrol edildi: 0.5 × (1/50000) / (1/20) = 0.0002). -->

### Soru 4 (ekrandan, 01:19:00 ve 01:24:00)

14 kayıtlı buys_computer veri kümesi (13.2 bölümündeki tablo) ile eğitilmiş bir Naive Bayes sınıflandırıcı, X = (age ≤ 30, income = medium, student = yes, credit_rating = fair) kaydını hangi sınıfa atar?

**Çözüm (derste verildi, ara adımlar eklendi ve python ile kontrol edildi):**

- $P(yes) = 9/14$, $P(no) = 5/14$.
- $P(X|yes) = (2/9)(4/9)(6/9)(6/9) = 32/729 \approx 0.044$.
- $P(X|no) = (3/5)(2/5)(1/5)(2/5) = 12/625 = 0.0192$.
- $P(X|yes)P(yes) \approx 0.028$; $P(X|no)P(no) \approx 0.007$.

$0.028 > 0.007$ olduğu için X "buys_computer = yes" sınıfına atanır.

### Soru 5 (ekrandan, 00:12:06)

Bölüm 4'teki beş kural (R1-R5) verildiğinde lemur, turtle ve dogfish shark kayıtları nasıl sınıflanır? Kural kümesi karşılıklı dışlayan ve kapsayıcı mıdır?

**Çözüm (derste verildi):** Lemur yalnız R3'ü tetikler, memelidir. Turtle hem R4'ü (Reptiles) hem R5'i (Amphibians) tetikler; çatışma vardır, bu yüzden kümeler karşılıklı dışlayan değildir. Dogfish shark hiçbir kuralı tetiklemez; küme kapsayıcı değildir. Çatışma sıralı kurallarla ya da oylamayla, kapsanmayan kayıt varsayılan sınıfla çözülür.

### Soru 6 (derste sözlü, 00:07:24)

10 satırlık veride "IF status = single THEN class = no" kuralına 4 satır uyuyor ve bunlardan 2'sinin sınıfı no. Kuralın coverage ve accuracy değerleri nedir?

**Çözüm (derste verildi):** Coverage $= 4/10 = \%40$, accuracy $= 2/4 = \%50$.

### Soru 7 (derste sözlü, 00:09:07)

20 satırlık hayvan tablosunda "IF Give Birth = no AND Can Fly = yes THEN Birds" kuralının koşuluna 3 satır uyuyor ve üçü de kuş. Kuralın coverage ve accuracy değerleri nedir?

**Çözüm (derste verildi):** Coverage $= 3/20 = \%15$, accuracy $= 3/3 = \%100$.

### Soru 8 (derste sözlü, 00:39:05)

Bir sınıf için $n$ öznitelik varsa koşul kısmı için kaç farklı öznitelik birleşimi yazılabilir? Optimum kural bulunabilir mi?

**Çözüm (derste verildi):** $\binom{n}{1} + \binom{n}{2} + \dots + \binom{n}{n}$ birleşim vardır. Bu üstel bir arama problemidir; büyük $n$ için global optimum bulunamaz, açgözlü arama kullanılır.

> **Çözüm (derste verilmedi):** Toplam $2^n - 1$'e eşittir (boş küme hariç bütün alt kümeler).

### Soru 9 (ekrandan, 00:47:06)

Eğitim kümesinde 60 pozitif ve 100 negatif örnek var. R1 50 pozitif ve 5 negatif, R2 2 pozitif ve 0 negatif örnek kapsıyor. Hangi kuralın accuracy'si yüksektir, hangisi daha iyi kuraldır?

**Çözüm (derste verildi):** R2'nin accuracy'si $\%100$, R1'inki $50/55 \approx \%90.9$'dur. Ama R1, coverage'i çok daha yüksek olduğu için daha iyi bir kuraldır. Bu, coverage'i hesaba katan FOIL bilgi kazancı gibi ölçülere ihtiyaç olduğunu gösterir.

> **Çözüm (derste verilmedi):** Başlangıç kuralı R0 olarak bütün veriyi kapsayan boş kural ($p_0 = 60$, $n_0 = 100$) alınırsa FOIL bilgi kazançları (python ile hesaplandı):
> $\text{FOIL}(R_0, R_1) = 50\left(\log_2\frac{50}{55} - \log_2\frac{60}{160}\right) \approx 63.88$,
> $\text{FOIL}(R_0, R_2) = 2\left(\log_2\frac{2}{2} - \log_2\frac{60}{160}\right) \approx 2.83$.
> FOIL ölçüsüne göre R1 açıkça daha iyidir.

### Soru 10 (ekrandan, 00:59:00)

buys_computer karar ağacından kuralları çıkarın. Bu kurallar karşılıklı dışlayan ve kapsayıcı mıdır?

**Çözüm (derste verildi):** Kökten her yaprağa giden yol bir kuraldır; Bölüm 10'daki beş kural elde edilir. Ağaçta her kayıt tek bir yola düştüğü ve ağaç eğitim verisinin tamamından kurulduğu için kurallar hem karşılıklı dışlayan hem kapsayıcıdır.

## Dersin Toparlaması

Bu derste sınıflandırmanın iki yeni yaklaşımı görüldü. Kural tabanlı sınıflandırmada önce kuralın yapısı (koşul ve sonuç) ve kalitesini ölçen coverage ile accuracy tanımlandı. Bir kaydın birden fazla kuralı tetiklemesi (karşılıklı dışlayan olmama) sıralı kurallar ya da oylama ile, hiçbir kuralı tetiklememesi (kapsayıcı olmama) varsayılan sınıf ile çözüldü; kural tabanlı ve sınıf tabanlı sıralama şemaları karşılaştırıldı. Kurallar ya doğrudan veriden (RIPPER gibi ardışık kapsama algoritmalarıyla, Learn-One-Rule'un açgözlü genelden özele ya da özelden genele büyütmesiyle) ya da dolaylı olarak karar ağacından çıkarılır. Kuralları değerlendirirken accuracy tek başına yanıltıcı olduğu için coverage'i de içeren FOIL bilgi kazancı kullanılır.

İkinci yaklaşım istatistiksel Naive Bayes sınıflandırıcıdır. Bayes teoremi koşullu olasılık tanımından türetildi, bağımsızlık kavramı bit dizisi örneğiyle gösterildi ve buys_computer verisinde bir test kaydının sınıfı adım adım hesaplandı. Sıfır olasılık sorunu ve smoothing, ayrıca özniteliklerin bağımsız olduğu varsayımının sınırları konuşuldu. Ders, Weka aracıyla Iris verisi üzerinde ön işleme filtreleri, test seçenekleri (özellikle çapraz doğrulama), Naive Bayes ve kural tabanlı sınıflandırıcıların çalıştırılması ve ARFF biçimiyle tamamlandı. Hoca, çıktıdaki karışıklık matrisi ve diğer başarı ölçülerinin sonraki derslerde öğrenileceğini belirtti; sınıflandırma yöntemleri önümüzdeki birkaç hafta daha devam edecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
