# Ders 3 Genişletilmiş Notu: Arama Problemlerinin Gösterimi ve Kör Arama Stratejileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Arama Konusuna Giriş
- 2. Küp Planlama Problemi
- 3. Robot Yol Planlama
- 4. Çiftçi, Kurt, Keçi ve Kabak Problemi
- 5. Su Bidonları Problemi
- 6. Problemleri Ortak Bir Gösterime Getirmek
- 7. 8'li Yapboz (8-Puzzle)
- 8. Temel Tanımlar
- 9. Arama Neden Zor Olabilir?
- 10. Arama Stratejileri ve Karşılaştırma Kriterleri
- 11. Enlemesine Arama (Breadth-First Search)
- 12. Ekleme Yerini Değiştirmek: Derinlemesine Arama
- 13. Enlemesine Aramanın Analizi
- 14. Derinlemesine Aramanın Analizi
- 15. Düşük Maliyetli Arama (Uniform Cost Search)
- 16. Sınırlı Derinlikte Arama (Depth-Limited Search)
- 17. Artan Derinlikli Arama (Iterative Deepening Search)
- Örnek Sorular

## 1. Arama Konusuna Giriş

Bu dersle birlikte yapay zekanın teknik yöntemlerine geçildi. Hoca, arama konusunun birkaç hafta süreceğini ve dersin bu bölümünün tamamen arama üzerine kurulu olduğunu söyledi. Ona göre makine öğrenmesinde yapılan işler de temelde arama olarak düşünülebilir; fark, orada aramanın kesikli (diskret) bir uzay yerine sürekli bir uzayda yapılmasıdır.

Dersin planı şuydu: önce birbirinden farklı görünen birkaç problem ele alınacak, sonra bu problemlerin ortak yönleri bulunacak ve hepsi aynı yapıya getirilecek. En sonunda bu ortak yapı üzerinde çalışan arama algoritmaları görülecek.

## 2. Küp Planlama Problemi

İlk problemde bir masanın üzerinde A, B, C küpleri yan yana durur. İstenen durumda ise küpler üst üste dizilmiştir: altta A, ortada B, üstte C (ekrandan, 00:10:00). Slayttaki tanım şöyledir:

- **Problem:** Masadaki küpleri mevcut pozisyondan istenilen pozisyona getirmek.
- **Olası hareketler:** Küp tutma, küpü yere koyma, küpü başka bir küpün üzerine koyma.
- **Çözüm:** Hareketler sırası.

Bu örnekte çözüm, "B'yi tut, A'nın üzerine koy, C'yi tut, B'nin üzerine koy" gibi bir hareket dizisidir. Hareket, bir durumu başka bir duruma geçiren operatördür.

Hoca sonra aynı problemin beş küplü bir halini gösterdi. Yukarıda sarkan bir kol vardır; bir küpü tutabilir, onu başka bir küpün üzerine ya da yere bırakabilir. Başlangıçta kol boş olduğu için yapılabilecek tek şey bir küp tutmaktır; üstü açık üç küp (B, C, E) olduğundan başlangıç durumundan üç farklı duruma gidilebilir. Örneğin B tutulduysa, B'yi C'nin ya da E'nin üzerine ya da yere bırakmak mümkündür. B'yi geldiği yere (A'nın üstüne) geri koymak da yapılabilir bir harekettir, ama bir döngü oluşmasın diye çizimde gösterilmemiştir.

Her durumdan yeni durumlar, onlardan da yeni durumlar çıktığı için bu yapı bir ağaç halini alır. Hedef durum bu ağacın bir yerindedir. Arama sırasında hedef durum bulunduğu anda, onu ağacın köküne bağlayan yol çözümdür: önce şu hareket, sonra şu hareket, ... diye okunan hareketler sırası.

## 3. Robot Yol Planlama

İkinci problemde bir labirent vardır (ekrandan, 00:15:00). Kırmızı hücrelere gidilemez, beyaz hücrelere gidilebilir. Robot başlangıç noktasından (B) hedef noktasına (H) gitmek ister. Slayttaki tanım:

- Başlangıç noktasından (B) hedef noktasına (H) gitmek.
- Olası hareketler: sola, sağa, aşağıya, yukarıya.
- Olası hareketlerin maliyetleri birbirinden farklı olabilir.
- En az maliyetli hareketler dizisini bulmak.

Hoca, amacın bu problemleri kendimiz çözmek değil, makineye çözdürmek olduğunu hatırlattı. Maliyet farkı için şu örneği verdi: sağa ve sola gitmek aynı maliyetli olabilir, ama yukarı gitmek yer çekimine karşı daha fazla güç gerektirdiği için daha pahalı, aşağı gitmek ise daha ucuz olabilir. Yani her hareketin maliyeti aynı olmak zorunda değildir.

Robotun bulunduğu konum ve hedefin konumu birlikte bir durumdur. Hoca bu durumdan oluşan ağacı slaytta çizdi (ekrandan, 00:20:00): başlangıç durumunda robot iki yöne gidebilir; geri dönme hareketleri yazılmadığında sonraki durumların bazılarından bir, bazılarından iki yeni durum çıkar. Ağaç böyle aşağı doğru büyür ve epey derinlerde bir yerde robotun H'de olduğu durum bulunur. Bu durumu köke bağlayan yol yine çözümdür.

**Soru:** Bu problemdeki kısıtlar nelerdir? **Cevap:** Bir öğrenci yalnız sağa, sola, yukarı, aşağı gidilebildiğini, bir başkası engelleri söyledi. Hoca bunları doğruladı: kırmızı hücrelere gidilemediği için dört hareket her durumda uygulanamaz, belli durumlarda yalnız bir kısmı uygulanabilir.

## 4. Çiftçi, Kurt, Keçi ve Kabak Problemi

Üçüncü problemde çiftçi Ali, sandalla kurt, keçi ve kabağı nehrin karşı kıyısına geçirmek ister. Başlangıçta hepsi nehrin güneyindedir, sonunda hepsinin kuzeyde olması istenir. Kısıtlar şunlardır:

- Sandal tek başına gidemez; Ali her zaman sandaldadır ve yanına en fazla bir nesne (kurt, keçi ya da kabak) alabilir.
- Ali yanlarında değilken keçi ile kabak ya da kurt ile keçi aynı tarafta kalmamalıdır. Örneğin Ali ilk seferde kurdu götürürse keçi kabağı yer; kabağı götürürse kurt keçiyi yer.

### 4.1 Durumların gösterimi

Bu problemi de bir arama problemi gibi düşünmek için durumlar, durumları birbirine geçiren hareketler, başlangıç ve bitiş durumları ve kısıtlar tanımlanmalıdır. Ali ve sandal hep aynı yerde olduğundan sandal için ayrı bir değişken tutmaya gerek yoktur. Ali, kurt, keçi ve kabak için birer yer tutulur. Her nesnenin iki olası pozisyonu vardır: nehrin kuzeyi (N) ya da güneyi (S). Böylece durum dört harften oluşan bir dörtlüdür: (farmer, wolf, goat, cabbage) (ekrandan, 00:25:00).

Slayttaki gösterim:

- **İlk durum:** (S, S, S, S)
- **Yasak durumlar:**
  - Kurt keçiyi yer (Ali olay yerinde değilse): (N, S, S, \_) ve (S, N, N, \_)
  - Keçi kabağı yer (Ali olay yerinde değilse): (N, \_, S, S) ve (S, \_, N, N)
- **Hedef durum:** (N, N, N, N)

Alt çizgi, o konumdaki değerin önemli olmadığını gösterir. Örneğin (N, S, S, \_) kalıbı kabağın yeri ne olursa olsun geçerlidir; yani iki durumu birden ifade eder.

**Soru:** Bu problemde kaç durum vardır? **Cevap:** Öğrenciler 16, yani $2^4$ dedi. Dört değişkenin her biri iki değer alabildiği için durum sayısı $2^4 = 16$'dır.

> **Ders sonrası not:** Hoca, dört kalıbın her biri iki durumu gösterdiği için geçilmemesi gereken 8 durum olduğunu söyledi. Kalıplar kesiştiği için farklı yasak durum sayısı 6'dır: (N, S, S, S) hem "kurt keçiyi yer" hem "keçi kabağı yer" kalıbına, (S, N, N, N) de iki kalıba birden uyar. Bu sayım python ile kontrol edildi.

### 4.2 Operatörler

Aksiyon, hareket ve operatör aynı anlamda kullanılır: durumları birbirine dönüştürürler. Slayttaki örnek keçiyi kuzeye taşıma operatörüdür (ekrandan, 00:30:00):

- **Başlangıç koşulu:** Keçi güneyde. Ali'nin de güneyde olması gerekir, çünkü sandalı yalnız Ali kullanabilir.
- **Bitiş:** Keçi ve Ali kuzeyde.
- Diğer nesnelerin yerinin önemi yoktur.

Gösterim:

$$\text{Move(Goat, North)}: (S,\ ?wolf,\ S,\ ?cabbage) \Rightarrow (N,\ ?wolf,\ N,\ ?cabbage)$$

Burada `?wolf` kurtun yerini gösteren bir değişkendir. Bu hareket kurdu ve kabağı etkilemez; ne iseler öyle kalırlar. Slayta göre değişken kullanımı bizi çok sayıda kural yazmaktan kurtarır; burada 4 kural yerine 1 kural yeter. Her nesne iki yerde olabildiği için toplam $2^4 = 16$ durum vardır.

### 4.3 Bir çözüm

Slaytta $S_1, S_2, \dots$ diye numaralanmış durumlarla bir çözüm gösterildi. **Soru:** $S_1, S_2, S_3$ neyi ifade ediyor? **Cevap:** Bir öğrencinin dediği gibi, o anki durumları. $S_1$ = (S, S, S, S) başlangıç durumudur; slayttaki mavi çizgi nehri gösterir. Çözüm şu hamlelerden oluşur:

1. Keçiyi kuzeye taşı (Move Goat North).
2. Ali tek başına güneye döner (Move Farmer South). Keçinin tek başına kalmasında sorun yoktur.
3. Kurdu kuzeye taşı. Şimdi kuzeyde Ali, keçi ve kurt birliktedir; Ali tek başına dönerse kurt keçiyi yer.
4. Bu yüzden keçiyi geri, güneye taşı.
5. Kabağı kuzeye taşı.
6. Ali tek başına döner; kurt ve kabak birlikte kalabilir.
7. Son olarak keçiyi kuzeye taşı.

Toplam 7 hamle vardır; yani bu çözüm arama ağacında 7 derinliktedir. Python ile yapılan enlemesine arama da bu problemin en kısa çözümünün 7 hamle olduğunu doğruladı.

## 5. Su Bidonları Problemi

Hoca bu problemi Die Hard filmindeki bir sahneyle tanıttı. Filmde iki kahramandan, 3 ve 5 galonluk iki bidonla 5'liğin içinde tam 4 galon su elde etmeleri istenir; miktar tam tutmazsa bomba patlayacaktır. Ders slaytındaki versiyon biraz farklıdır (ekrandan, 00:35:00):

- Elde 3 ve 4 galon hacimli 2 bidon vardır.
- Limitsiz bir su kaynağı (pompa) vardır.
- İstenen: 4 galonluk bidona tam 2 galon su koymak.

"Göz kararı yarısını doldurayım" gibi tahmini hareketlere izin yoktur. Bir bidon ağzına kadar doluysa içinde tam kapasitesi kadar su olduğu bilinir; ölçüm yalnız böyle yapılabilir.

### 5.1 Durumlar

Önce durumları temsil etmek gerekir. Durum iki sayıyla gösterilir: $(x, y)$. $x$ 4 galonluk bidondaki, $y$ 3 galonluk bidondaki su miktarıdır. Başlangıç durumu $(0, 0)$, hedef durumu $(2, \text{herhangi})$'dir.

**Soru:** Hedef neden $y$'de değil de yalnız $x$'te 2? **Cevap:** Problem öyle verildiği için; 2 galonun 4 galonluk bidonda olması isteniyor, başka özel bir sebebi yok.

**Soru:** Başlangıç ve bitiş tanımlandıktan sonra neye ihtiyaç var? **Cevap:** Sohbetten bir öğrenci aksiyonlara (operatörlere) ihtiyaç olduğunu yazdı.

### 5.2 Operatörler

Sekiz operatör tanımlandı. Altyazıdaki anlatıma göre:

| No | Anlamı | Dönüşüm | Koşul |
|---|---|---|---|
| 1 | 4 galonluk bidonu pompayla doldur | $(x,y) \to (4,y)$ | $x < 4$ |
| 2 | 3 galonluk bidonu pompayla doldur | $(x,y) \to (x,3)$ | $y < 3$ |
| 3 | 4 galonluk bidonu yere boşalt | $(x,y) \to (0,y)$ | $x > 0$ |
| 4 | 3 galonluk bidonu yere boşalt | $(x,y) \to (x,0)$ | $y > 0$ |
| 5 | 4 galonluk bidon dolana kadar 3 galonluktan aktar | $(x,y) \to (4,\ y-(4-x))$ | $x+y \ge 4$, $y > 0$ |
| 6 | 3 galonluk bidon dolana kadar 4 galonluktan aktar | $(x,y) \to (x-(3-y),\ 3)$ | $x+y \ge 3$, $x > 0$ |
| 7 | 3 galonluktaki suyun tamamını 4 galonluğa boşalt | $(x,y) \to (x+y,\ 0)$ | $x+y \le 4$, $y > 0$ |
| 8 | 4 galonluktaki suyun tamamını 3 galonluğa boşalt | $(x,y) \to (0,\ x+y)$ | $x+y \le 3$, $x > 0$ |

<!-- BELİRSİZ: Operatör slaytının karesi yok. 4 numaralı operatör (3 galonluğu boşaltmak) altyazıda açıkça okunmadı; sekiz operatör sayısından ve 3 numaranın simetriğinden yazıldı. 7 ve 8'deki koşulu hoca "küçükse" diye söyledi; tabloya taşma olmaması için gereken eşitlikli hali yazıldı. -->

5 numaralı operatörde 4 galonluk bidon sonunda mutlaka dolar, yani $x$ 4 olur. $y$'den $4-x$ kadar su eksilir. Bu hareketin yapılabilmesi için başlangıçta $x+y \ge 4$ olmalıdır, ayrıca $y$ boş olmamalıdır. 7 numarada ise bütün su aktarıldığı için taşma olmaması gerekir; bunun için $x+y$ 4'ü aşmamalıdır.

### 5.3 Bir çözüm

Slayttaki çözümde operatörler 2, 7, 2, 5, 3, 7 sırasıyla uygulanır:

| Adım | Uygulanan operatör | Durum |
|---|---|---|
| 0 | başlangıç | (0, 0) |
| 1 | 2: 3'lüyü doldur | (0, 3) |
| 2 | 7: 3'lüyü tamamen 4'lüye boşalt | (3, 0) |
| 3 | 2: 3'lüyü doldur | (3, 3) |
| 4 | 5: 4'lü dolana kadar 3'lüden aktar | (4, 2) |
| 5 | 3: 4'lüyü yere boşalt | (0, 2) |
| 6 | 7: 3'lüyü tamamen 4'lüye boşalt | (2, 0) |

4. adımda 3'lüden 1 galon aktarılır ve 4'lü dolar; 3'lüde 2 galon kalır. Sonuçta 4 galonluk bidonda tam 2 galon vardır. Bu adımlar python ile kontrol edildi; enlemesine arama da bu problemin en kısa çözümünün 6 adım olduğunu gösterdi (6 adımlık başka bir çözüm de vardır: 1, 6, 4, 8, 1, 6).

## 6. Problemleri Ortak Bir Gösterime Getirmek

Hoca, şimdiye kadar konuşulan bütün problemlerin aynı hale getirildiğini vurguladı: durumlar, başlangıç durumu, hedef durumu ve durumlar arası geçişi sağlayan operatörler tanımlandı. Bir çözüm bulunduğunda, o çözümden ağacın köküne giden yol bir hareket sırasıdır ve bu sıra çözümü verir.

Aynı hale getirmenin avantajı şudur: problemler ne kadar farklı görünürse görünsün, hepsi aynı tür algoritmalarla çözülebilir. Her problem için ayrı bir çözüm yöntemi keşfetmeye gerek kalmaz.

## 7. 8'li Yapboz (8-Puzzle)

Eskiden 16 parçaya bölünmüş bir resimden oluşan, bir karesi boş, parçaları kaydırılabilen oyuncaklar vardı. Karışık verilen resmi orijinal haline getirmek gerekir; hoca bunu Rubik küpün iki boyutlu hali gibi düşünebileceğimizi söyledi. 8'li yapbozda $3 \times 3$ bir tabloda 8 taş ve bir boş kare vardır. Bir başlangıç ve bir hedef dizilişi verilir.

### 7.1 Operatörlerin seçimi

Slayttaki başlangıç durumunda üç hareket vardır: 1 numaralı taşı aşağı, 7 numaralı taşı sağa ya da 5 numaralı taşı sola kaydırmak. Her taş için aşağı, yukarı, sağa, sola hareket düşünülürse 8 taş için $8 \times 4 = 32$ operatör gerekir. Operatör sayısı çok olursa arama uzayının karmaşıklığı büyür.

Bunu azaltmak için bütün hareketler boş kareyi hareket ettirmek olarak düşünülebilir. 1 numaralı taşı aşağı kaydırmak, boş kareyi yukarı kaydırmakla aynıdır; 7 numaralı taşı sağa kaydırmak, boş kareyi sola kaydırmakla aynıdır. Böylece $1 \times 4 = 4$ operatör yeterli olur: boş kareyi sağa, sola, yukarı, aşağı hareket ettir. Operatör sayısını azaltmak zamandan ve bellekten kazandırır.

### 7.2 Arama ağacı ve büyüklüğü

8-puzzle'ın arama ağacında başlangıç durumundan boş kare dört yöne hareket edebilir. Sonraki durumlarda geri dönme hareketi çizilmediğinden genelde iki ya da üç hamle kalır. Hedef durum ağacın derinlerinde bir yerdedir. Hoca, bu problemde ortalama zorluktaki bir örneğin çözüm derinliğinin ortalama 22 olduğunu söyledi.

**Soru:** Ortalama dallanma sayısı 2,67 ne demektir? **Cevap:** Bir öğrencinin dediği gibi, bir durumdan çıkan ortalama dal sayısıdır. Başlangıç durumundan 4 dal çıkar, sonrakilerden ikişer ya da üçer çıkar; bütün ağaç için ortalama 2,67'dir. Bu durumda ağaçta milyarlarca durum oluşur ve hepsine bakmak gerekebilir.

<!-- BELİRSİZ: Hocanın söylediği durum sayısı altyazıda bozuk ("7 milyar ... 2.7 milyar"). Hesapla $2{,}67^{22} \approx 2{,}4 \times 10^9$ çıkar. -->

**Soru:** 8'li yerine $4 \times 4$ tabloda bir boş kareyle 15'li yapboz olsaydı ne değişirdi, ortalama dallanma sayısı mı, ortalama adım sayısı mı? **Cevap:** Adım sayısı. Çözüm çok daha derinlerde olurdu; ortalama dallanma sayısı ise o kadar artmazdı.

## 8. Temel Tanımlar

Görülen kavramlar toplu olarak şöyle verildi:

- **Durum uzayı, arama uzayı, arama ağacı:** Durumları ve aralarındaki geçişleri gösteren graf ya da ağaç. Bazı durumlarda elimizdeki yapı ağaç değil graf olur.
- **Operatörler:** Durumlar arası geçişi sağlar.
- **Başlangıç durumu ve hedef durum(lar).**
- **Maliyet:** Operatör uygulama maliyeti.
- **Çözüm yolu:** Başlangıç durumunu hedef duruma götüren yol.
- **Optimum yol:** En düşük maliyetli çözüm yolu. Bir problemin birçok çözümü ve bunların farklı maliyetleri olabilir.

**Soru:** En düşük maliyetli çözüm yolu birden fazla olabilir mi? **Cevap:** Evet. Maliyetleri birbirine eşit ve en düşük olan birden fazla optimum yol olabilir.

## 9. Arama Neden Zor Olabilir?

Aramanın büyüklüğü çözümün derinliğiyle ve dallanma sayısıyla artar. Slayttaki varsayımlar (ekrandan, 01:05:00):

- Bir durumdan gidilebilecek durum sayısı (dallanma sayısı): $b = 10$
- Saniyede işlenen durum sayısı: 1000
- Bir durum için tutulan bellek: 100 bayt

| Çözümün derinliği | İşlenen durum sayısı | Zaman | Bellek |
|---|---|---|---|
| 0 | 1 | 1 milisaniye | 100 bayt |
| 2 | 111 | 0,1 saniye | 11 kilobayt |
| 4 | 11.111 | 11 saniye | 1 megabayt |
| 8 | $10^8$ | 31 saat | 11 gigabayt |
| 12 | $10^{12}$ | 35 yıl | 111 terabayt |

Derinlik 2 olduğunda kökten 10 durum, her birinden 10'ar durum çıkar: $1 + 10 + 100 = 111$. Python ile yapılan kontrolde tablodaki değerler tutarlıdır: derinlik 8 için $111.111.111$ durum yaklaşık $30{,}9$ saat ve $11$ GB, derinlik 12 için yaklaşık $35{,}2$ yıl ve $111$ TB eder.

Hoca, bilgisayarların hızlanmasının bunu çözmediğini anlattı. Saniyede işlenen durum sayısı bin değil bir milyar olsa bile, derinliği biraz artırınca yine yıllar mertebesine çıkılır; çünkü derinliği bir artırmak işi on kat artırır. Bilgisayarların her yıl yaklaşık iki kat hızlandığı düşünülürse bu büyümeyle başa çıkılamaz. Böylece iki temel problem ortaya çıkar: zaman ve bellek.

## 10. Arama Stratejileri ve Karşılaştırma Kriterleri

Şimdiye kadar çözümün nasıl bulunacağından söz edilmedi. Bunun için arama algoritmaları (arama stratejileri) vardır. Slayttaki tanıma göre arama stratejileri, bir durumdan diğerine giderken gidilecek durumun olası gidilebilecek durumlar arasından nasıl seçildiğini belirler (ekrandan, 01:10:00).

Stratejiler dört boyutta değerlendirilir:

- **Tamlık (completeness):** Bir çözüm varsa, derinliği ne olursa olsun mutlaka bulması. Bunu yapabilen algoritmaya tam algoritma denir.
- **Zaman karmaşıklığı (time complexity):** Aramanın alacağı süre.
- **Hafıza karmaşıklığı (space complexity):** Arama için gereken hafıza miktarı. Arama yaparken bir dizi (kuyruk ya da yığın) tutulur; hafıza karmaşıklığı bu dizinin büyüklüğüyle ilgilidir.
- **Optimumluk (optimality):** İlk bulunan çözümün en düşük maliyetli çözüm (ya da en düşük maliyetli çözümlerden biri) olması.

> **Hocanın vurgusu:** Optimumluk tanımındaki "ilk bulunan çözüm" ifadesi önemlidir. Algoritmanın bulduğu ilk çözüm bu özelliğe sahipse algoritma optimumdur.

Hoca, kör arama algoritmalarının zaman karmaşıklıklarının birbirine yakın, hafıza karmaşıklıklarının ise çok farklı olduğunu söyledi. Sonraki derste görülecek sezgisel arama algoritmalarında zaman karmaşıklıkları da farklılaşır.

Karmaşıklık ifadelerinde kullanılan büyüklükler:

- $b$: maksimum dallanma sayısı (branching factor), yani bir düğümden çıkan maksimum düğüm sayısı.
- $d$: en az maliyetli çözümün derinliği.
- $m$: arama uzayının maksimum derinliği; bazen $\infty$ olabilir.

En az maliyetli çözümün derinliği sonsuz olamaz; öyleyse zaten çözüm yoktur. Ama arama uzayının maksimum derinliği sonsuz olabilir.

Arama algoritmaları iki büyük aileye ayrılır: kör (bilgisiz, mekanik, uninformed) arama ve sezgisel arama. Slayttaki kör arama stratejileri şunlardır (ekrandan, 01:10:00):

- Enlemesine arama (breadth-first search)
- Düşük maliyetli arama (uniform cost search)
- Derinlemesine arama (depth-first search)
- Sınırlı derinlikte arama (depth-limited search)
- Artan derinlikli arama (iterative deepening search)
- Çift yönlü arama (bidirectional search)

Çift yönlü arama sonraki derse kaldı.

## 11. Enlemesine Arama (Breadth-First Search)

### 11.1 Ağaç baştan kurulmaz

Arama ağacı en başta oluşturulmaz. Sonsuz büyüklükte bir ağaç kurulamaz; belli bir derinliğe kadar kurmak gerekir, ama hangi derinliğin yeteceği bilinmez. Büyük bir derinlik varsayılırsa gereksiz yere dev bir ağaç kurulmuş olur. Bu yüzden ağacı baştan belleğe kurup üzerinde arama yapmak verimli değildir.

Bunun yerine ağaç zaman içinde adım adım oluşuyormuş gibi davranılır. Gerçekte bir ağaç veri yapısı kurulmaz; ağaçta görünen durumlar üretilir, bir dizide tutulur ve sırayla bunlara erişilir. Enlemesine aramada erişim sırası satır satırdır: önce birinci seviye, sonra ikinci, sonra üçüncü seviye (ekrandan, 01:15:00).

### 11.2 Çözüm sırası ile durum açma sırası

Slayttaki ağaçta düğümler 1'den başlayarak numaralanmıştır: 1'in çocukları 2 ve 3, 2'nin çocukları 4 ve 5'tir. Başlangıç durumu 1, hedef durumu 5 olsun. Çözüm 1, 2, 5 durum sırasıdır; yani 1'den 2'ye ve 2'den 5'e geçiren hareketler. Fakat arama sırasında algoritma durumlara 1, 2, 3, 4, 5 sırasıyla bakar.

> **Hocanın vurgusu:** Çözüm bir durum sırasıdır, durum açma sırası da bir durum sırasıdır, ama bunlar birbirinden farklı şeylerdir. Örneğin 10 derinlikli bir ağaçta hedef bulunana kadar binlerce düğüme bakılır, ama çözüm yolu yalnız 10 uzunluktadır.

### 11.3 Algoritma

Enlemesine arama için ilk giren ilk çıkar (FIFO) mantığıyla çalışan bir kuyruk kullanılır. Bunun illa kuyruk ya da yığın olması gerekmez, bir diziyle de yapılabilir. Slayttaki algoritma (ekrandan, 01:20:00):

```text
kuyruk = [kök durum]
bulundu = FALSE
While (kuyruk <> boş) and (bulundu = FALSE)
    Kuyruktan ilk durumu (N) çek
    Eğer N hedef durumsa, bulundu = TRUE
    N'den gidilebilecek tüm durumları kuyruğun sonuna ekle
```

### 11.4 Adım adım örnek

Hedefin 5 olduğu ağaçta kuyruk $K$ ile gösterilsin. Slayttaki ve anlatımdaki adımlar şöyledir (ekrandan, 01:20:00):

| Kuyruk (çekmeden önce) | Çekilen | Eklenen (sona) |
|---|---|---|
| (1) | 1 | 2, 3 |
| (2 3) | 2 | 4, 5 |
| (3 4 5) | 3 | 6, 7 |
| (4 5 6 7) | 4 | 8, 9 |
| (5 6 7 8 9) | 5 | hedef bulundu |

1 hedef değildir; 1'den gidilebilecek 2 ve 3 kuyruğun sonuna eklenir. Sonra 2 çekilir; kuyrukta 3 kalır, 2'nin çocukları 4 ve 5 sona eklenir. Sonra 3 çekilir; çocukları (6 ve 7 diye adlandırıldı) sona eklenir. Böylece çekilen sıra 1, 2, 3, 4, 5, ... olur. Enlemesine aramayı sağlayan şey yeni üretilen durumları dizinin sonuna eklemek ve hep baştan çekmektir.

## 12. Ekleme Yerini Değiştirmek: Derinlemesine Arama

Hoca aynı algoritmada tek bir değişiklik yaptı: yeni durumları kuyruğun sonuna değil başına ekledi.

| Dizi (çekmeden önce) | Çekilen | Başa eklenen |
|---|---|---|
| (1) | 1 | 2, 3 |
| (2 3) | 2 | 4, 5 |
| (4 5 3) | 4 | 8, 9 |
| (8 9 5 3) | 8 | yok |
| (9 5 3) | 9 | yok |
| (5 3) | 5 | 10, 11 |
| (10 11 3) | 10 | ... |

Burada 4'ün çocuklarına 8 ve 9, 5'in çocuklarına 10 ve 11 denmiştir; 8 ve 9'un çocuğu olmadığı varsayılmıştır. Çekilen sıra 1, 2, 4, 8, 9, 5, 10, 11 olur; 11'den sonra 3'e, sonra 3'ün altındakilere geçilir. Bu derinlemesine aramadır (depth-first search). Slayttaki algoritmada bu yüzden kuyruk yerine yığın (stack) kullanılır.

> **Hocanın vurgusu:** İki algoritma arasındaki tek fark, yeni durumların dizinin başına mı sonuna mı eklendiğidir. Bu kadar basit bir değişiklik arama sürecini ve kriterlere göre özellikleri büyük ölçüde değiştirir.

## 13. Enlemesine Aramanın Analizi

- **Tam mı?** Evet, $b$ sonlu ise. Satır satır ilerlediği için ağaçta bir çözüm varsa mutlaka bulunur. Bir durum sonsuz olasılığa dallanıyorsa zaten bilgisayarla simüle edilemez; bilgisayarla çalışılan problemlerde $b$ sonludur.
- **Zaman:** Erişilen durum sayısı $1 + b + b^2 + b^3 + \dots + b^d$ olur, yani $O(b^d)$. Burada $d$ optimum çözümün derinliğidir.
- **Hafıza:** $O(b^d)$ mertebesinde. Bir satırın sonuna gelindiğinde, o satırdan gidilebilecek bütün durumlar dizide durur. Örneğin 3 çekildiğinde dizide 4, 5, 6, 7'nin hepsi vardır. Yani herhangi bir derinliğe gelindiğinde bir alt seviyedeki her şey bellekte tutulur. Hoca bunu $b^d$ ya da $b^{d+1}$ mertebesi diye ifade etti.
- **Optimal mi?** Farklı derinliklerde birden fazla çözüm varsa köke en yakın olanı, yani en az adımla gidileni önce bulur. Bu yüzden her adımın (her operatörün) maliyeti eşitse optimumdur. Maliyetler farklıysa garanti yoktur: iki adımlık bir çözümün maliyeti, operatörleri daha ucuz olan dört adımlık bir çözümden yüksek olabilir.

Labirent probleminde bütün hareket maliyetleri eşitse, enlemesine arama en az adımlı çözümü, dolayısıyla optimum çözümü bulur.

## 14. Derinlemesine Aramanın Analizi

- **Tam mı?** Arama uzayının derinliği sonsuzsa hayır. Bu, döngülerin oluştuğu durumlarda gayet mümkündür: 1'den 2'ye, 2'den 3'e, 3'ten tekrar 1'e geçilebiliyorsa algoritma sonsuza kadar inebilir. Bir dal sonsuza gidiyorsa, hemen yandaki daldaki sığ bir çözüme bile hiç ulaşılamaz.
- **Zaman:** $O(b^m)$. Burada $d$ değil $m$ (arama uzayının maksimum derinliği) vardır. $m$, $d$'den çok büyükse kötü bir durumdur, çok büyük değilse o kadar sorun olmaz.
- **Hafıza:** $O(bm)$. Bu en önemli farktır: hafıza gereksinimi üstel değil doğrusaldır. Durumlar başa eklendiği için dizi sürekli tüketilerek ilerler; hiçbir zaman $b^m$ gibi boyutlara çıkmaz.
- **Optimal mi?** Hayır. Sol tarafta derinde kötü bir çözüm, sağda daha iyi bir çözüm varsa algoritma önce soldan aşağı inip kötü olanı bulur.

Hoca, çözümler arama uzayında yoğunsa derinlemesine aramanın enlemesine aramadan daha hızlı sonuç bulabileceğini bir çizimle gösterdi. Bir çözüm sol dalın derinlerinde, bir çözüm sağda daha sığ bir yerde olsun.

**Soru:** Enlemesine arama hangi çözüme erişir? **Cevap:** Sağdaki, daha sığ olana; ama bunun için önce o seviyeye kadarki bütün düğümlere (çizimde yedi düğüm) bakması gerekir. Derinlemesine arama ise birkaç adımda soldaki çözüme iner. Yani derinlemesine aramanın daha hızlı sonuç üretme olasılığı vardır, ama bu kesin değildir ve problem tipine göre değişir.

> **Hocanın vurgusu:** Derinlemesine aramanın birçok kötü özelliği vardır (tam değil, optimal değil), ama çok güzel bir özelliği vardır: hafıza gereksinimi çok azdır.

## 15. Düşük Maliyetli Arama (Uniform Cost Search)

Önceki iki algoritmada diziden mekanik olarak hep baştaki eleman çekiliyordu; yalnız ekleme yeri farklıydı. Düşük maliyetli arama, diziden bir elemanı bir analiz yaparak çeker: kökten itibaren toplam maliyeti en düşük olan düğümü seçip genişletir. Slayttaki özet (ekrandan, 01:50:00):

- Enlemesine aramaya benzer.
- Kökten itibaren toplam maliyeti en az düğümü seçer ve genişletir.
- Tüm maliyetler birbirine eşitse enlemesine aramanın aynısıdır.

Bu algoritmada yeni durumların başa mı sona mı eklendiğinin önemi yoktur; seçim maliyete göre yapılır.

### 15.1 Şehirler örneği

Slayttaki arama uzayında A, B, C, D, E, F şehirleri ve aralarındaki yollar vardır; yolların üzerindeki sayılar uzaklıktır. Hoca, her şehirden her şehre yol olmadığını, nasıl ki buradan her şehre doğrudan yol yoksa burada da öyle olduğunu söyledi. Amaç A'dan F'ye gitmektir. Slayttaki kenarlar (ekrandan, 01:50:00):

| Kenar | Maliyet |
|---|---|
| A - B | 1 |
| A - C | 5 |
| A - D | 15 |
| B - F | 10 |
| C - E | 4 |
| E - F | 1 |
| D - F | 1 |

Arama adımları:

| Adım | Kuyruktaki düğümler (kökten maliyet) | Seçilen |
|---|---|---|
| 1 | A(0) | A |
| 2 | B(1), C(5), D(15) | B |
| 3 | F(1+10=11), C(5), D(15) | C |
| 4 | F(11), E(5+4=9), D(15) | E |
| 5 | F(11), F(9+1=10), D(15) | F (maliyet 10) |

3. adımda hedef F kuyrukta olduğu halde çekilmez, çünkü maliyeti (11) C'nin maliyetinden yüksektir. 5. adımda kuyrukta iki farklı F vardır: biri A-B-F yolunun F'si (11), diğeri A-C-E-F yolunun F'si (10). Bunlar aynı düğüm değildir. Maliyeti en düşük olan ikinci F seçilir; hedef olduğu için arama durur. Bulunan yol A-C-E-F, maliyeti 10'dur. Bu sonuç python ile doğrulandı.

> **Ders sonrası not:** Hoca anlatırken A-C maliyetini 4, C-E maliyetini 5 diye okudu. Bir öğrenci slayttaki iki çizimde 5 ile 4'ün yer değiştirdiğini belirtti; üstteki grafikte A-C = 5, C-E = 4'tür. E'nin kökten maliyeti iki durumda da 9 olduğu için sonuç değişmez. Yalnız C'nin kökten maliyeti grafiğe göre 5'tir.

### 15.2 Analiz

Slayttaki analiz (ekrandan, 01:55:00):

- **Complete?** Eğer $b$ sonlu ve maliyet $> 0$ ise evet.
- **Time?** $O(b^d)$
- **Space?** $O(b^d)$
- **Optimal?** Tüm maliyetler pozitif ise evet.
- Hafıza zamandan daha büyük problemdir.

Hoca, zaman ve hafıza açısından enlemesine aramadan farkı olmadığını söyledi. Asıl önemli özellik optimumluktur: burada "maliyetler eşitse" diye bir koşul yoktur; maliyetler farklı olsa da algoritma optimaldir. Optimumluk açısından şimdiye kadarki en iyi algoritmadır, ama temelde enlemesine arama yaptığı için hafıza yine sorundur. Bütün maliyetler eşit olan bir problemde her zaman köke en yakın olanı seçeceği için enlemesine aramanın aynısını yapar.

> **Ek bilgi (derste anlatılmadı):** Kaynaklarda düşük maliyetli aramanın karmaşıklığı genellikle $O(b^{1+\lfloor C^*/\varepsilon \rfloor})$ diye verilir. Burada $C^*$ optimum çözümün maliyeti, $\varepsilon$ en küçük adım maliyetidir. Bütün adım maliyetleri eşitse bu ifade $b^d$ mertebesine iner.

## 16. Sınırlı Derinlikte Arama (Depth-Limited Search)

Derinlemesine aramanın güzel tarafı belleğin az olmasıydı. Sınırlı derinlikte arama, derinlemesine aramadan tek bir farkla ayrılır: derinliğe bir sınır ($L$) koyar. Örneğin $L=5$ ise algoritma 5'ten daha aşağıdaki düğümlere inmez.

**Soru:** Algoritma bir seferde mi 5'ten aşağı inemiyor, sonraki adımda devam edecek mi? **Cevap:** Hayır; en fazla 5 adım derine inebilir. Önceki örnekte 8 ve 9'un çocukları yokmuş gibi davranılması, sınırı 2 olan bir sınırlı derinlikte arama gibi düşünülebilir.

Hoca kriterleri öğrencilerle birlikte doldurdu (ekrandan, 02:00:00):

- **Complete?** $L > d$ ise evet. Bir öğrencinin dediği gibi, $L$'den daha aşağıda çözüm varsa algoritma oraya bakmaz. Seçilen $L$ iyiyse çözüm bulunur, değilse bulunmaz.
- **Time?** $b^L$
- **Space?** $b \cdot L$
- **Optimal?** Hayır.

**Soru:** $L$'ye kadar gidip bulamazsa, $L$'nin ilerisine bakmaya devam etmiyor mu? **Cevap:** Hayır, etmiyor.

> **Ders sonrası not:** Slayt ve hoca "$L > d$ ise evet" dedi. Derinliği $d$ olan çözüme $L = d$ sınırında da ulaşılır; bu yüzden tamlık koşulu büyük olasılıkla $L \ge d$ diye yazılmalıdır.

## 17. Artan Derinlikli Arama (Iterative Deepening Search)

Artan derinlikli arama, sınırlı derinlikte aramayı kullanır. Sınır parametresi 0'dan (ya da 1'den) başlatılır ve birer birer artırılır. Önce sınır 1 ile derinlemesine arama yapılır: kök, sonra birinci seviyedeki düğümler. Sonra sınır 2 yapılır: yine kökten başlanır, ikinci seviyeye kadar derinlemesine gidilir. Sonra sınır 3, ve böyle devam edilir.

**Soru:** Sınır her artırıldığında derinlemesine arama ağacın kökünden mi başlar? **Cevap:** Evet, her seferinde kökten başlar.

### 17.1 Tekrarlanan iş

Bu yöntemde fazladan iş yapılır. Kök durum her turda yeniden kontrol edilir; ikinci seviyedeki düğümlere de her turda tekrar bakılır. Sınırlı derinlikte arama ($L=d$) $b^d$ mertebesinde zaman harcar. Artan derinlikli aramada birinci seviyedeki düğüm $d+1$ kez, ikinci seviyedekiler $d$ kez, üçüncü seviyedekiler $d-1$ kez işlenir; ama en son seviye yalnız bir kez işlenir.

Hocanın sayısal örneği $b = 10$, $d = 5$ içindir:

- Sınırlı derinlikte arama: $1 + 10 + 100 + 1000 + 10.000 + 100.000 = 111.111$ düğüm.
- Artan derinlikli arama: $6 \cdot 1 + 5 \cdot 10 + 4 \cdot 100 + 3 \cdot 1000 + 2 \cdot 10.000 + 1 \cdot 100.000 = 123.456$ düğüm (ara adım eklendi).
- Fazladan iş: $(123.456 - 111.111) / 111.111 \approx \%11$.

En büyük terim olan son seviye iki yöntemde aynıdır; fazlalık bu yüzden küçük kalır. Sonuçlar python ile doğrulandı.

### 17.2 Analiz

**Tamlık:** Derinlemesine arama sonsuz döngülere takıldığı için tam değildi; sınırlı derinlikte arama da çözüm sınırın altında kalırsa bulamıyordu. Artan derinlikli arama sınırı sürekli artırdığı için ikisine de takılmaz ve bir çözüm varsa bulur.

**Soru:** Bu algoritmanın enlemesine aramaya göre avantajı hafıza karmaşıklığı, dezavantajı zaman karmaşıklığı mı? **Cevap:** Hoca önce tamlık konusunun bitirilmesini istedi, sonra karşılaştırmayı adım adım yaptı.

Slayttaki analiz (ekrandan, 02:10:00):

- **Complete?** Evet.
- **Time?** $(d+1)b^0 + d\,b^1 + (d-1)b^2 + \dots + b^d = O(b^d)$
- **Space?** $O(bd)$
- **Optimal?** Eğer tüm maliyetler eşitse evet.

Zaman açısından $b^d$'ye bir şeyler eklenir, ama eklenen kısım $b^d$'den daha üst bir mertebede değildir. Optimumluk için hoca şunu sordu: biri sol tarafta daha derinde, biri yukarıda olan iki çözümden hangisi önce bulunur? Sınır sıfırdan başlayıp birer birer arttığı için köke daha yakın olan çözüm her zaman önce bulunur. Bu yüzden optimumluk koşulu enlemesine aramayla aynıdır: tüm maliyetler eşitse optimumdur.

**Soru:** Zaman karmaşıklığı $b^{d+1}$'e yakın olmaz mı, eklenen kısım büyük değil mi? **Cevap:** Hoca, $b^d$'lik son terimde tekrar olmadığını gösterdi: $b^{d-1}$ iki kez, $b^{d-2}$ üç kez sayılır, ama $b^d$ bir kez sayılır. Bu yüzden toplam hiçbir zaman bir üst mertebeye çıkmaz. Öğrenci $b = 2$ durumunu düşündüğünü söyleyince hoca, fazladan işin en fazla ne olabileceğini incelemesini önerdi.

Sonuç olarak artan derinlikli arama oldukça iyi bir algoritmadır: bellek gereksinimi doğrusal kalır, derinlik artsa da bellek üstel büyümez; tüm maliyetler eşitse optimumdur ve birçok problem türüne uygundur.

### 17.3 Derinlemesine yerine enlemesine arama kullanılırsa

Slayttaki soru: artan derinlikli aramada derinlemesine arama yerine enlemesine arama yapılırsa ne olur? (ekrandan, 02:10:00)

Bir öğrenci hiçbir şeyin değişmeyeceğini söyledi; hoca bir şeyin değişeceğini belirtti. Bir başka öğrenci sınırın altındaki durumların kuyruğa alınmayacağı için belleğin biraz azalacağını söyledi. Hocanın cevabı: $d$ derinlikteki bir çözüm aranırken bellek gereksinimi yine $b^d$ mertebesinde kalır, hiçbir zaman $b \cdot d$'ye dönüşmez; en fazla bir seviye farkı olur. Zaman açısından da düz enlemesine aramadan biraz daha kötü olur. Yani bu değişiklikle bir şey kazanılmaz, yalnız bir şeyler kaybedilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:25:18): Çiftçi, kurt, keçi ve kabak probleminde kaç durum vardır?

> **Çözüm:** Dört nesnenin her biri N ya da S olabilir: $2^4 = 16$ durum. Başlangıç (S,S,S,S), hedef (N,N,N,N). Farklı yasak durum sayısı 6'dır (bkz. Bölüm 4.1'deki ders sonrası not).

**Soru 2** (ekrandan, 00:35:00): 3 ve 4 galonluk iki bidon ve sınırsız pompa ile 4 galonluk bidona tam 2 galon su nasıl konur?

> **Çözüm:** Derste verilen çözüm: (0,0) → (0,3) → (3,0) → (3,3) → (4,2) → (0,2) → (2,0). Operatör sırası 2, 7, 2, 5, 3, 7 (6 adım).

**Soru 3** (derste sözlü, 01:01:03): 8'li yerine 15'li yapboz ($4 \times 4$) olsaydı ortalama dallanma sayısı mı, ortalama adım sayısı mı çok değişirdi?

> **Çözüm:** Ortalama adım sayısı (çözüm derinliği) çok artar; ortalama dallanma sayısı o kadar artmaz.

**Soru 4** (derste sözlü, 01:20:37): Enlemesine arama algoritmasında yeni durumlar kuyruğun sonu yerine başına eklenirse ne olur?

> **Çözüm:** Algoritma derinlemesine aramaya dönüşür. Örnek ağaçta çekilme sırası 1, 2, 4, 8, 9, 5, 10, 11, 3, ... olur.

**Soru 5** (ekrandan, 01:50:00): Şehirler grafiğinde (A-B 1, A-C 5, A-D 15, B-F 10, C-E 4, E-F 1, D-F 1) düşük maliyetli arama ile A'dan F'ye giden yol nedir?

> **Çözüm:** Seçilme sırası A(0), B(1), C(5), E(9), F(10). Bulunan yol A-C-E-F, maliyeti 10. A-B-F yolu (11) kuyrukta olsa da daha pahalı olduğu için seçilmez.

**Soru 6** (derste sözlü, 02:03:46): Artan derinlikli aramanın sınırlı derinlikte aramaya göre yaptığı fazladan iş $b=10$, $d=5$ için %11'dir. $b$ ve $d$ değiştirilirse bu oran en fazla ne olabilir?

> **Çözüm (derste verilmedi):** Fazladan iş oranı $\dfrac{\sum_{i=0}^{d}(d+1-i)\,b^i}{\sum_{i=0}^{d} b^i} - 1$ ifadesidir. $d$ büyüdükçe bu oran $\dfrac{1}{b-1}$ değerine yaklaşır: $b=10$ için yaklaşık %11, $b=3$ için %50, $b=2$ için %100. Dolayısıyla en kötü durum $b=2$'dir ve artan derinlikli arama bu durumda en fazla yaklaşık iki kat iş yapar. Değerler python ile hesaplandı ($b=2$, $d=5$ için %90,5; $d=20$ için yaklaşık %100).

**Soru 7** (ekrandan, 02:10:00): Artan derinlikli aramada derinlemesine arama yerine enlemesine arama yapılırsa ne olur?

> **Çözüm:** Bellek gereksinimi $O(b^d)$ mertebesinde kalır, $O(bd)$'ye inmez; zaman da düz enlemesine aramadan biraz kötü olur. Bir şey kazanılmaz, yalnız kaybedilir.

## Dersin Toparlaması

Bu derste küp planlama, robot yol planlama, nehir geçişi, su bidonları ve 8'li yapboz problemleri aynı yapıya getirildi: durumlar, başlangıç ve hedef durumları, operatörler ve kısıtlar. Çözüm, hedef durumu köke bağlayan operatör dizisidir. Arama uzayının dallanma sayısı ve çözüm derinliğiyle üstel büyüdüğü, bu yüzden zamanın ve özellikle belleğin temel sorun olduğu bir tabloyla gösterildi. Ardından kör arama algoritmaları tamlık, zaman, hafıza ve optimumluk kriterlerine göre incelendi: enlemesine arama, derinlemesine arama, düşük maliyetli arama, sınırlı derinlikte arama ve artan derinlikli arama.

Hoca, sonraki derste çift yönlü aramanın görüleceğini ve arama animasyonlarına bakılacağını söyledi. Ardından aramanın süresini azaltmaya çalışan sezgisel arama algoritmalarına geçilecektir. Kör arama algoritmalarında hafıza açısından kazanç sağlandı, ama zaman açısından pek bir iyileşme olmadı; sezgisel algoritmalarla süre açısından kazanç sağlanmaya çalışılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
