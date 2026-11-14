# Ders 11 Genişletilmiş Notu: Kruskal Algoritması, Karar Ağaçları, Entropi ve Bilgi Kazancı, Ağaçlarda İzomorfizm ve Graf Türleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kruskal Algoritması
- 2. Karar Ağaçları ve Sınıflandırma
- 3. Sahte Para Problemi
- 4. "Tenis Oynanır mı?" Veri Seti ve Rastgele Kurulan Ağaç
- 5. Entropi
- 6. Bilgi Kazancı ile Karar Ağacı Kurma
- 7. Ağaçlarda İzomorfizm
- 8. Graflara Giriş: Tanım ve Terimler
- 9. Graf Türleri
- 10. Benzerlik Grafı
- 11. Özel Graflar: $K_n$, $C_n$, $W_n$, $Q_n$
- 12. İki Parçalı Graflar
- 13. Özel Grafların Düğüm ve Kenar Sayıları

## 1. Kruskal Algoritması

Ders, ağaçlar bölümünde kalınan yerden, Kruskal algoritmasından başladı. Bu derste ağaçların bitirilmesi ve graflara başlanması planlandı.

### 1.1 Hatırlatma: Kapsayan Ağaç ve Prim

Hoca önce önceki dersi hatırlattı. Ağaçlar (trees) grafların özel bir halidir: Bir graf döngü içermiyorsa (ve bağlıysa) otomatik olarak bir ağaçtır. Bu yüzden ağaçları anlatırken sürekli graflardan söz ediliyor.

Kapsayan ağaçta (spanning tree) amaç, graftaki bütün düğümleri gezmektir. Aynı düğümleri farklı yollardan gezebiliriz; herkes farklı bir yol seçebilir. Prim algoritması bir en küçük kapsayan ağaç (minimum spanning tree) algoritmasıydı. Başındaki "minimum" şunu söyler: Bütün düğümleri gezeceğim, ama gezerken toplam yolu en kısa tutacağım. Hoca bunu bir yerden kampüse giden onlarca farklı yolla anlattı: Gidilebilecek pek çok yol vardır, ama algoritmanın amacı en kısa olanıdır.

### 1.2 Algoritmanın Üç Adımı

Kruskal algoritması üç adımdan oluşur. Hoca bunu "görebileceğiniz en kolay algoritmalardan biri" diye tanıttı.

1. Graftaki kenarları ağırlıklarına göre en küçükten en büyüğe sırala. Aynı ağırlıkta birden fazla kenar varsa zaten arka arkaya gelirler; hangisinin önce alındığının önemi yoktur.
2. Sıradaki kenarı seç. Tek şart: Seçilen kenar kapalı bir döngü oluşturmamalıdır. Döngü oluşturuyorsa o kenarı alma, sıradaki kenara geç.
3. Bütün düğümler bağlanana kadar 2. adıma dön.

Durma noktasını algoritmik olarak şöyle anlarız: $n$ düğümlü bir grafta $n-1$ kenar seçilmişse iş bitmiştir. $n$ düğüm için $n$ kenar seçilirse mutlaka döngü oluşur.

> **Hocanın vurgusu:** Yazılı sınavda graflar küçük verildiği için sonucu gözle bakıp doğrudan yazanlar oluyor. Öyle olmaz. Algoritmanın adımlarını tek tek göstermek gerekir. Gerçek dünya problemleri 5-6 düğümlü olmaz.

### 1.3 Birinci Örnek (7 Düğüm)

<!-- BELİRSİZ: Graf ekranda çizili; kenarların hangi düğümler arasında olduğu altyazıdan okunmuyor. Yalnız seçilen kenarların ağırlıkları sözlü veriliyor. -->

- En küçük kenar 1'dir; önce o seçilir.
- Sırada dört tane 2'lik kenar vardır. Hoca bunları sırayla seçti; hiçbiri döngü oluşturmadı.
- Bu noktada gözle bakınca bütün düğümler seçilmiş görünür. Ama düğüm sayısı 7'dir, yani $7-1 = 6$ kenar gerekir. Seçilen kenar sayısı yalnızca 5'tir.

Hoca burada durup şunu gösterdi: Seçilen kenarlar birbirinden bağımsız **iki ayrı ağaç** oluşturuyor. Amaç bütün düğümleri gezmek ve aynı zamanda birbirine bağlamaktır. Bu yüzden bir kenar daha seçilmelidir. 2'likler bittiği için sıradaki 3'lük kenarlardan, iki ağacı birbirine bağlayan bir tanesi seçilir. Kenar sayısı $n-1 = 6$ olur ve iş biter.

Toplam ağırlık (ara adım eklendi): $1 + 2 + 2 + 2 + 2 + 3 = 12$.

> **Hocanın vurgusu:** Bütün düğümlerin seçilmiş olması işin bittiğini göstermez. Bu işlemi yaparken büyük ihtimalle bir matris kullanacaksınız. Matriste bütün düğümler işlenmiş görünür ve "işim bitti" dersiniz. Ama birbirinden ayrı iki ağaç olabilir; onları da bağlamanız gerekir.

### 1.4 İkinci Örnek (9 Düğüm)

<!-- BELİRSİZ: Graf ekranda; hangi 3'lük ve 4'lük kenarların seçildiği altyazıdan okunmuyor. -->

- Önce 1'lik kenar, sonra iki tane 2'lik kenar seçilir. Bütün düğümler henüz seçilmemiştir.
- Sırada 3'lükler vardır. Üç tane 3'lük kenar seçilir; her biri yeni bir düğümü ağaca katar.
- 3'lükler bittiğinde hâlâ alınmamış düğüm vardır. Sıra 4'lüklere gelir.
- Bazı 4'lük kenarlar kapalı çevrim oluşturduğu için alınmaz. Açıkta kalan bir düğümü bağlayan 4'lük kenar mecburen alınır.
- Bu noktada bütün düğümler gezilmiştir, ama yine iki ayrı ağaç vardır. 9 düğüm için 8 kenar gerekirken 7 kenar seçilmiştir.
- Döngü oluşturmayan ve iki ağacı birbirine bağlayan bir 4'lük kenar daha seçilir. Bütün düğümler gezilmiş ve en küçük toplam bulunmuştur.

Seçilen kenarlar 1, 2, 2, 3, 3, 3, 4, 4'tür. Toplam ağırlık (ara adım eklendi): $1+2+2+3+3+3+4+4 = 22$.

### 1.5 İnternetteki Demo Örneği

Hoca slayttaki bağlantılarda her örnek için hazırlanmış demolar olduğunu söyledi ve birini gösterdi. Düğümler $u_0, \dots, u_5$'tir. Demo da kenarları küçükten büyüğe sıralar: önce 5'likler ($u_0u_1$, $u_3u_4$), sonra 10'luklar ($u_1u_3$, $u_2u_3$), sonra 15'likler ($u_2u_4$, $u_4u_5$), sonra 20'likler ve 30'luklar.

<!-- BELİRSİZ: Altyazıda 5'lik kenarlar "U0, U1, orası 5, U3, U4, 5" diye okunuyor; demonun tam kenar listesi ve 20'lik/30'luk kenarların uçları altyazıdan çıkmıyor. -->

Çalışma sırası:

- $u_3u_4$ çizilir, sonra $u_0u_1$.
- $u_1u_3$ çizilir, sonra $u_2u_3$. Hâlâ açıkta düğüm var ve döngü yok.
- $u_2u_4$ sıradadır. Çizilirse $u_2, u_3, u_4$ arasında kapalı döngü oluşur. Bu yüzden alınmaz.
- $u_4u_5$ alınır. Bütün düğümler bağlanmıştır.

6 düğüm için 5 kenar seçilmiştir ve algoritma biter.

Hoca bağlantılarda Ford-Fulkerson diye başka bir yöntemin de geçtiğini, Dijkstra algoritmasını ise graflar bölümünde göstereceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Prim tek bir ağacı her adımda bir düğüm ekleyerek büyütür. Kruskal ise ara adımlarda birden fazla ayrı ağaç (orman) tutar ve en sonda bunları birleştirir. Derste görülen "bütün düğümler seçildi ama iki ağaç var" durumu bu yüzden Kruskal'a özgüdür. Döngü kontrolü pratikte büyük olasılıkla birleşim-bul (union-find) veri yapısıyla yapılır: Bir kenarın iki ucu aynı ağaçtaysa kenar döngü oluşturur.

## 2. Karar Ağaçları ve Sınıflandırma

Hoca karar ağaçlarını (decision trees) ağaçların en önemli konularından biri olarak tanıttı. Karar ağaçları yalnız veri yapıları dersinde değil, ileride lisans ve yüksek lisans seçimlik derslerinde de karşınıza çıkacak: bir sınıflandırma (classification) algoritması olarak, ya da rastgele orman (random forest) gibi algoritmaların parçası olarak. Veri madenciliği, yapay zekâ ve doğal dil işleme derslerinde bunları göreceksiniz.

### 2.1 Sınıflandırma Nedir?

Hocanın örneği: Masanın üzerinde silgiler ve kalemler var. Sizden bunları "kalemler" ve "silgiler" diye ayırmanız isteniyor. Kalemler dolma kalem, tükenmez kalem, boya kalemi olabilir; önemli olan kalem olmalarıdır, hepsi bir sınıfa atılır. Silgiler de (kurşun kalem silgisi, tükenmez silgisi, kokulu, kokusuz) ayrı bir sınıfa ayrılır. Bu ayırma, elemanların özelliklerine göre yapılır.

Bu ayırma bir ağaç üzerinde olur. Ağacın bir düğümünde bir soru sorulur ve cevaba göre dallara ayrılınır. Sonraki düğümde başka bir soru sorulur. Bu, yapraklara gelindiğinde yapraktaki elemanların hepsi aynı olana kadar sürer. Kalem örneğinde bir yaprakta yalnız boya kalemleri, birinde yalnız tükenmez kalemler kalır.

### 2.2 İkili Olmak Zorunda Değil

Bazı kaynaklar karar ağacını "bir olayın sonuçlandırılmasında bir sorunun cevabına göre hareket eden ikili ağaç" diye tanımlar. Hoca, karar ağacının ikili (binary) olmak zorunda olmadığını vurguladı. Bir sorunun ikiden fazla cevabı olabilir; ağacın yapısı duruma göre değişir. Geçen hafta görülen ikili arama ağaçları (binary search trees) da aslında bir karar ağacıdır: Her düğümde "bu sayıdan büyük mü, küçük mü?" diye sorulur.

### 2.3 Karar Ağacıyla Yeni Örneği Sınıflandırma

Elimizde örnekler vardır ve bu örnekler karar ağacına yerleştirilir. Dışarıdan yeni bir örnek geldiğinde ağaçta onun yerine bakılır ve yeni örneğin sınıfına karar verilir.

## 3. Sahte Para Problemi

Hoca "her ayrık matematik kitabında olan" bir örnekten başladı.

**Problem:** Görünüşleri birbirinin aynısı olan 5 madeni para (coin) var: $C_1, \dots, C_5$. Bunlardan biri sahtedir. Sahteyi dışarıdan bakarak göremezsiniz; yalnızca ağırlığına bakarak karar verebilirsiniz. Sahte para diğerlerinden ya ağırdır ya hafiftir. Hangi paranın sahte olduğunu ve ağır mı hafif mi olduğunu bulmak istiyoruz.

Bir terazinin üç sonucu vardır: sol taraf ağır, denge, sağ taraf ağır. Bu yüzden ağaçta her soru düğümünden üç dal çıkar.

### 3.1 Ağacın Kurulması

**Birinci tartım:** $C_1$ ile $C_2$ tartılır.

**Dal 1: $C_1 > C_2$ ($C_1$ ağır basıyor).** Sahte para bu ikisinden biridir, ama hangisi olduğu henüz bilinmiyor. $C_3, C_4, C_5$ kesinlikle gerçektir. Gerçek olduğundan emin olunan bir para, $C_5$, alınır ve $C_1$ ile $C_5$ tartılır.

- Denge varsa $C_1$ gerçektir. Teraziyi bozan $C_2$'dir. Bu dala $C_2$ hafif tarafta kaldığı için gelinmişti; yani sahte para $C_2$'dir ve **hafiftir**.
- Denge yoksa sahte para $C_1$'dir. Bu dala $C_1$ ağır olduğu için gelinmişti; yani $C_1$ sahte ve **ağırdır**.

**Dal 2: $C_1 < C_2$ ($C_2$ ağır basıyor).** Yine $C_1$ ile $C_5$ tartılır.

- Denge varsa sahte $C_2$'dir ve ağırdır.
- Denge yoksa sahte $C_1$'dir ve hafiftir.

**Dal 3: $C_1 = C_2$ (denge).** $C_1$ ve $C_2$ gerçektir. Sahte para $C_3, C_4, C_5$'ten biridir. $C_3$ ile $C_4$ tartılır.

- $C_3 > C_4$ ise bunlardan biri sahtedir. $C_3$ gerçek $C_5$ ile tartılır. Denge varsa sahte $C_4$'tür ve hafiftir. Denge yoksa sahte $C_3$'tür ve ağırdır.
- $C_3 < C_4$ ise $C_3$ ile $C_5$ tartılır. Denge varsa sahte $C_4$'tür ve ağırdır. Denge yoksa sahte $C_3$'tür ve hafiftir.
- $C_3 = C_4$ ise sahte para $C_5$'tir. Ağır mı hafif mi olduğunu anlamak için $C_1$ ile $C_5$ tartılır. $C_1$ ağır basarsa $C_5$ hafiftir; $C_5$ ağır basarsa $C_5$ ağırdır.

Ağaçta 10 yaprak vardır (5 para × ağır/hafif) ve her yolda en fazla 3 tartım yapılır (ara adım eklendi).

> **Ders sonrası not:** Hoca anlatım sırasında birkaç kez dalları karıştırdı ve düzeltti. Örneğin bir yerde "$C_1$ ile $C_5$ dengedeyse sahte $C_2$, çünkü $C_2$ ağır olduğu için buraya girdim" dedi. $C_1 > C_2$ dalında denge varsa sahte para $C_2$'dir ve hafiftir. Yukarıdaki dallar bu düzeltmeyle yazıldı.

### 3.2 Neden "Karar" Ağacı?

Bu bir ağaçtır. Adının "karar" olmasının sebebi, her düğümde bir "if" olmasıdır: Bir soru sorulur ve cevabın durumuna göre bir sonuca gidilir. Ağacın derinliği elimizdeki sınıf sayısına ve örnek sayısına göre değişir. Tek amaç şudur: Yapraklardaki her şey tek bir sınıfa ait olmalı. Bu problemde $C_1, \dots, C_5$ sınıfın hangi para olduğunu, ağır/hafif ise sınıfın etiketini gösterir.

Hoca çok sayıda karar ağacı algoritması (ID3, C4.5 vb.) görülmesinin sebebini de açıkladı. Ana fikir aynıdır; verinin türüne göre ufak değişiklikler yapılır. Veri tamamen sayısal (numerik) ise aynı mantıkta sayılarla daha hızlı çalışan bir değişiklik yapılır. Veri kategorik ise (buradaki $C_1$, $C_2$ gibi sayısal olmayan değerler) özelliklerle ilgili başka bir değişiklik yapılır. Karışık veri setleri (numerik, kategorik, reel değerler) için de daha iyi çalışması için ufak değişiklikler yapılmış algoritmalar vardır.

## 4. "Tenis Oynanır mı?" Veri Seti ve Rastgele Kurulan Ağaç

Ardından gerçek dünyayla ilgili bir örneğe geçildi. Veri setinde 14 örnek (gün) ve 4 özellik vardır. Bu özelliklere bakarak dışarıda tenis oynanıp oynanamayacağına karar verilecektir.

- **Hava durumu (outlook):** güneşli (sunny), parçalı bulutlu (overcast), yağmurlu (rain).
- **Sıcaklık (temperature):** sıcak (hot), ılık (mild), serin (cool).
- **Nem (humidity):** yüksek (high), normal.
- **Rüzgâr (wind):** zayıf (weak), kuvvetli (strong).

Sınıf etiketi: tenis oynanır (yes) veya oynanmaz (no). Hocanın satır örnekleri: "Hava güneşli, sıcak, nem yüksek, rüzgâr zayıfsa tenis oynayamazsın", çünkü sıcak ve nemli havada tenis yorucudur. "Hava yağmurlu, serin, nem normal, rüzgâr zayıfsa tenis oynayabilirsin."

Tablonun her satırı bir örnektir, sütunlar özelliklerdir, son sütun sınıf etiketidir. Dört değişkenin farklı değerleri pek çok kombinasyon oluşturur. Tabloda olmayan bir kombinasyon geldiğinde örnek ağaca sokulur ve tenis oynanıp oynanmayacağına karar verilir. İşte bu bir sınıflandırma problemidir.

Hoca gerçek dünyadan bir benzetme de yaptı: Bir hastanede her hasta veri setindeki bir örnektir. Alınan test sonuçları (sedimantasyon, karaciğer enzimleri, kolesterol gibi) özelliklerdir. Sınıf etiketi "hasta" ya da "hasta değil"dir. Test sonuçları karar ağacına verilir ve ağaç kişinin hasta olup olmadığını söyler.

Hoca öğrencilerden bu tabloyu ekran görüntüsü olarak kaydetmelerini istedi. Tablo aşağıdadır.

<!-- BELİRSİZ: Tablo ekranda gösterildi; altyazıda bütünüyle okunmuyor. Aşağıdaki değerler, derste sözlü geçen bütün bilgilerle (nem yüksek günler 1, 2, 3, 4, 8, 12, 14; 1 no, 2 no, 3 yes, 4 yes, 8 no; 9 yes / 5 no; dal üyeleri ve sayımlar) tutarlı olan klasik "PlayTennis" veri setidir. -->

| Gün | Hava durumu | Sıcaklık | Nem | Rüzgâr | Tenis |
| :---: | :--- | :--- | :--- | :--- | :---: |
| 1 | güneşli | sıcak | yüksek | zayıf | no |
| 2 | güneşli | sıcak | yüksek | kuvvetli | no |
| 3 | bulutlu | sıcak | yüksek | zayıf | yes |
| 4 | yağmurlu | ılık | yüksek | zayıf | yes |
| 5 | yağmurlu | serin | normal | zayıf | yes |
| 6 | yağmurlu | serin | normal | kuvvetli | no |
| 7 | bulutlu | serin | normal | kuvvetli | yes |
| 8 | güneşli | ılık | yüksek | zayıf | no |
| 9 | güneşli | serin | normal | zayıf | yes |
| 10 | yağmurlu | ılık | normal | zayıf | yes |
| 11 | güneşli | ılık | normal | kuvvetli | yes |
| 12 | bulutlu | ılık | yüksek | kuvvetli | yes |
| 13 | bulutlu | sıcak | normal | zayıf | yes |
| 14 | yağmurlu | ılık | yüksek | kuvvetli | no |

### 4.1 Rastgele Seçilen Özelliklerle Bir Ağaç

Hoca önce özellikleri hiçbir ölçüte bakmadan, "canım istedi" diyerek yerleştirdi.

**Kök: nem.** Nemin veri setinde iki değeri vardır. Nemin yüksek olduğu örnekler 1, 2, 3, 4, 8, 12 ve 14'tür; geri kalanlarda nem normaldir. Yalnız nemin yüksek olduğuna bakarak karar verebilir miyiz? Hayır: 1 no, 2 no, 3 yes, 4 yes, 8 no. Bu dalda hem yes hem no var. Amaç, yaprağa gelindiğinde rahatça karar verebilmektir. Demek ki bu dalda başka bir soru sorulmalıdır.

**Nem yüksek dalında: rüzgâr.** Bu örneklerden rüzgârın zayıf olduğu günler 1, 3, 4 ve 8'dir; diğerlerinde (2, 12, 14) rüzgâr kuvvetlidir. Bunlar da tek bir etikete sahip değildir.

Hoca, nem normal dalına da rüzgârı koyduğunu, ama bunun zorunlu olmadığını söyledi: Aynı seviyedeki düğümlere aynı özelliği koymak gerekmez.

**Rüzgâr zayıf dalında: hava durumu.** Hava durumunun üç değeri vardır. Nem yüksek, rüzgâr zayıf ve hava güneşli olan 1 ve 8 numaralı örneklerde tenis oynanmaz. Nem yüksek, rüzgâr zayıf ve hava bulutlu olan 3 numaralı örnekte tenis oynanır. Yağmurlu olan 4 numaralı örnekte de oynanır (ara adım eklendi; veri setinden). Artık yapraklarda tek sınıf vardır.

**Rüzgâr kuvvetli dalında: hava durumu.** 2, 12 ve 14 numaralı örnekler hava durumuna göre ayrılır: 2 (güneşli) no, 12 (bulutlu) yes, 14 (yağmurlu) no.

> **Ders sonrası not:** Hoca bu dal için "2, 12, 14; yes, yes, no" dedi. Veri setinde 2 numaralı örneğin etiketi no'dur. Doğrusu: 2 no, 12 yes, 14 no.

Nem normal dalındaki ayrıntılar altyazıda verilmedi.

<!-- BELİRSİZ: Rastgele ağacın nem normal kolundaki düğümler ve yapraklar ekranda; altyazıda yalnız "5, 6, 7 ... normal olan örneklerden rüzgârı zayıf olan örnekler" diye geçiyor. -->

> **Hocanın vurgusu:** Kökten bir yaprağa giden yol üzerinde bir özellik yalnız bir kez kullanılır. Bir yolda nem ve rüzgâr kullanıldıysa aynı yolda tekrar nem sormanın hiçbir anlamı yoktur.

### 4.2 Ağacın Yüksekliği Neden Önemli?

Bu rastgele ağacın seviyesi 3'tür: nem, rüzgâr, hava durumu. Hoca burada bir kural koydu: Ağacın yüksekliği mümkünse en küçük olmalıdır. Ağaç ne kadar yüksekse o kadar çok soru soruluyor demektir. Az soru sorarak sonuca ulaşmak isteriz.

Özellikler rastgele yerleştirildiğinde biri seviyesi 4 olan bir ağaç kurar, biri 3'te, biri 2'de bütün yaprakları tek sınıfa indirir. En iyi ağacı bulmak tesadüfe kalır. O halde köke ve alt düğümlere hangi özelliğin konacağına dair bir dayanak gerekir. Bu dayanak entropi kavramı ve bilgi kazancı (information gain) yöntemidir: Hangi özellikten en büyük kazanç elde ediliyorsa o özellik kullanılır.

## 5. Entropi

### 5.1 Olasılık ve Bilgi

Entropinin sözlük anlamı karmaşıklıktır. Fizikte, kimyada, mühendislikte, hatta işletme ve sosyal alanlarda farklı anlamlarda kullanılır. Burada kullanılan entropi, bilgi teorisinin (information theory) önemli bir kavramıdır.

Hoca bunu bir örnekle anlattı. "Kampüste köpek beni ısırdı." Bu olayın olasılığı yüksektir; o kadar köpeğin olduğu bir yerde ısırılma olasılığı yüksektir. Peki taşıdığı bilgi önemli midir? Hayır; gayet normal bir olaydır. Olasılık yüksek, taşıdığı bilgi azdır.

Tersini düşünelim: "Hoca gitti köpeği ısırdı." Bunun olasılığı çok düşüktür. Ama gerçekten olursa bütün üniversite bunu konuşur. Taşıdığı bilgi yüksektir.

Bir başka örnek: 30 derece sıcaklıkta kar yağması olasılığı düşüktür; yağarsa taşıdığı bilgi çok yüksektir. Sıfır derecede kar yağması ise hiç şaşırtmaz; olasılığı yüksek, bilgisi önemsizdir.

> **Hocanın vurgusu:** Bir olayın olasılığı ile taşıdığı bilgi arasında her zaman ters bir orantı vardır.

### 5.2 Bilginin Ölçülmesi

Hoca, bir olayın entropisinin o olayın olasılığı ile taşıdığı bilginin çarpımı olduğunu söyledi. Kitaplarda entropi çoğunlukla $H$ ile gösterilir; burada $E$ kullanılıyor.

Olasılık 0 ile 1 arasında sayısal bir değerdir. Bilgi ise soyut bir kavramdır. Hocanın benzetmesi: Bir öğrenci "bu derste çok şey öğrendim" dese de bu soyuttur; somut hale getirmek için ödev ve sınavla ölçmeye çalışırız. Bilgiyi de somutlaştırmak gerekir. Bir olayın bilgisi, olasılığın tersinin 2 tabanında logaritmasıdır:

$$I = \log_2 \frac{1}{p} = -\log_2 p$$

Neden 2 tabanı? "Biz bilgisayarcıyız; her şey bizim için 1 ve 0'dır." Bilgi bit ile ölçülür.

Bir olayın entropi katkısı olasılık ile bilginin çarpımıdır:

$$p \cdot \log_2 \frac{1}{p} = -p \log_2 p$$

### 5.3 Genel Formül

Tenis örneğinde iki olay (sınıf) vardır: tenis oynamak (yes, $+$) ve oynamamak (no, $-$). Entropi, her olayın olasılığı ile bilgisinin çarpımlarının toplamıdır:

$$E(S) = -p_{+} \log_2 p_{+} - p_{-} \log_2 p_{-}$$

$c$ tane sınıf olabilir. Hastane örneğinde 6 farklı hastalık için test yapılmışsa 6 sınıf vardır ve 6 terim toplanır. Genel formül:

$$E(S) = -\sum_{i=1}^{c} p_i \log_2 p_i$$

$p_i$ sıfır ile bir arasında olduğu için $\log_2 p_i$ negatiftir; her terim negatif gelir. Bu negatifliği ortadan kaldırmak için başa eksi konur.

### 5.4 Entropinin Yorumu

Hoca entropiyi bir sayı doğrusu üzerinde anlattı.

**Bütün örnekler aynı sınıftaysa entropi 0'dır.** 10 örneğin 10'u da yes olsun:

$$E = -\frac{10}{10}\log_2\frac{10}{10} = -1 \cdot \log_2 1 = -1 \cdot 0 = 0$$

Veri homojendir. Hepsi no olsa da sonuç aynıdır.

**Örnekler eşit dağılmışsa entropi 1'dir.** 10 örneğin 5'i yes, 5'i no olsun:

$$E = -\frac{5}{10}\log_2\frac{5}{10} - \frac{5}{10}\log_2\frac{5}{10} = -\frac{1}{2}(-1) - \frac{1}{2}(-1) = 1$$

Entropi 0 ile 1 arasındaysa sınıflardan biri daha yoğundur. Slayttaki örnek: 9 yes, 5 no ise entropi 0.940; 7 yes, 7 no ise entropi 1.

> **Ders sonrası not:** Hoca bir an "sadece yes'ler varsa entropi 1" dedi, hemen ardından 0 olarak düzeltti. Tek sınıflı veride entropi her zaman 0'dır. Ayrıca "entropi 0 ile 1 arasındadır" ifadesi iki sınıf için doğrudur; derste anılan 6 hastalıklı örnek gibi $c$ sınıflı durumda en büyük entropi $\log_2 c$'dir (6 sınıf için yaklaşık 2.585).

## 6. Bilgi Kazancı ile Karar Ağacı Kurma

### 6.1 Formül

Bilgi kazancı (information gain) şöyle hesaplanır:

$$\text{Gain}(S, A) = E(S) - \sum_{v \in \text{Değerler}(A)} \frac{|S_v|}{|S|}\, E(S_v)$$

- $S$: veri seti (setin S'si).
- $A$: özellik (attribute). Bu örnekte nem, rüzgâr, sıcaklık ve hava durumu.
- $S_v$: $A$ özelliğinin $v$ değerini aldığı örnekler.

Önce bütün veri setinin (sistemin) entropisi hesaplanır. Sonra o özelliğin her değeri için "o değerin olasılığı × o değerin entropisi" hesaplanıp toplanır ve sistemin entropisinden çıkarılır. Olasılık $\frac{|S_v|}{|S|}$, veri setinde o değere sahip örnek sayısının bütün örnek sayısına oranıdır. Örneğin nem için "yüksek nemin oranı × yüksek nemin entropisi + normal nemin oranı × normal nemin entropisi" hesaplanır.

Dört özelliğin her biri için kazanç hesaplanır. En büyük kazancı veren özellik köke yerleştirilir.

### 6.2 Sistemin Entropisi

Sistemde 9 yes ve 5 no vardır:

$$E(S) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} \approx 0.940$$

Bu değer bütün kazanç hesaplarında kullanılır; çünkü hepsinin başında sistemin entropisi vardır. Bir kez hesaplanması yeter.

### 6.3 Rüzgâr İçin Kazanç

Rüzgârın iki değeri vardır:

- **Zayıf:** 8 örnek; 6'sı yes, 2'si no.
- **Kuvvetli:** 6 örnek; 3'ü yes, 3'ü no.

Toplam $6+2+3+3 = 14$ eder; bütün örnekler sayılmıştır.

Zayıf rüzgârın entropisi:

$$E(S_{\text{zayıf}}) = -\frac{6}{8}\log_2\frac{6}{8} - \frac{2}{8}\log_2\frac{2}{8} \approx 0.811$$

Kuvvetli rüzgârın entropisi:

$$E(S_{\text{kuvvetli}}) = -\frac{3}{6}\log_2\frac{3}{6} - \frac{3}{6}\log_2\frac{3}{6} = 1$$

Kazanç:

$$\text{Gain}(S, \text{rüzgâr}) = 0.940 - \frac{8}{14}\cdot 0.811 - \frac{6}{14}\cdot 1 \approx 0.048$$

Hoca işaretlere dikkat çekti: İçteki eksiler logaritmanın negatifliğini gidermek içindir. Dıştaki büyük parantez açıldığında eksi işaretleri içeri dağılır. Parantez yazılırsa içerideki terimler artıyla yazılır; parantez yazılmazsa eksiler terimlerin önüne gelir.

### 6.4 Bütün Özelliklerin Kazançları

Aynı hesap diğer özellikler için de yapılır:

| Özellik | Kazanç |
| :--- | :---: |
| Hava durumu | 0.246 |
| Nem | 0.151 |
| Rüzgâr | 0.048 |
| Sıcaklık | 0.029 |

En büyük kazanç hava durumundadır. Hava durumu köke yerleştirilir.

> **Ders sonrası not:** Hoca sıcaklık için "0.29" dedi; doğru değer 0.029'dur. Nem için "0.15" dedi; slayttaki değer 0.151'dir. Hoca bir an "en büyük rüzgâr" dedi, sonra hava durumu olarak düzeltti. Python ile hesapta hava durumunun kazancı 0.2467 çıkar; slayttaki 0.246 bu değerin kesilmiş halidir.

### 6.5 Hava Durumu Kökte: Dallar

Hava durumunun üç değeri vardır:

- **Bulutlu (3, 7, 12, 13):** 4 yes, 0 no. Hepsi aynı sınıftır; dal biter. Hava bulutluysa başka soru sormaya gerek yoktur: Tenis oynanır.
- **Güneşli (1, 2, 8, 9, 11):** 2 yes, 3 no. Karışıktır; yeni bir soru gerekir.
- **Yağmurlu (4, 5, 6, 10, 14):** 3 yes, 2 no. Karışıktır; yeni bir soru gerekir.

> **Ders sonrası not:** Hoca güneşli günleri "1, 8, 9, 11", bulutlu günleri "7, 12" diye saydı. Veri setinde güneşli günler 1, 2, 8, 9, 11 (5 örnek), bulutlu günler 3, 7, 12, 13'tür (4 örnek). Hocanın verdiği dağılımlar (2 yes / 3 no ve 4 yes / 0 no) bu tam listelerle tutarlıdır.

### 6.6 Alt Düğümler: Sistem Yerine Dalın Entropisi

Alt düğümlere özellik seçerken aynı formül kullanılır, tek bir farkla: Artık bütün sistemin değil, o dalın entropisi kullanılır. Güneşli kolundaysak sistem sanki yalnız o 5 örnekten oluşuyormuş gibi davranılır.

**Güneşli dalı.** 5 örneğin 2'si yes, 3'ü no:

$$E(S_{\text{güneşli}}) = -\frac{2}{5}\log_2\frac{2}{5} - \frac{3}{5}\log_2\frac{3}{5} \approx 0.971$$

Bu dalda nemin kazancı hesaplanır. Güneşli günlerden nemi normal olan 2 örnek vardır ve ikisi de yes'tir; entropi $-\frac{2}{2}\log_2\frac{2}{2} - 0 = 0$. Nemi yüksek olan 3 örnek vardır ve üçü de no'dur; entropi 0. Bu yüzden:

$$\text{Gain}(S_{\text{güneşli}}, \text{nem}) = 0.971 - \frac{3}{5}\cdot 0 - \frac{2}{5}\cdot 0 = 0.971$$

Sıcaklık ve rüzgâr için de hesap yapılır; en büyük kazanç (0.971) nemindir. Güneşli dalının altına nem gelir: Nem yüksekse tenis oynanmaz (3 örnek), nem normalse oynanır (2 örnek). İki yaprak da tek sınıftır.

**Yağmurlu dalı.** 5 örneğin 3'ü yes, 2'si no; entropi yine yaklaşık 0.971'dir. Hoca nem, sıcaklık ve rüzgâr için kazançların aynı şekilde hesaplandığını söyledi. Slayttaki sonuçta bu dala rüzgâr yerleşir (kazanç 0.971): Rüzgâr kuvvetliyse oynanmaz, zayıfsa oynanır.

Python ile kontrol (ders sonrası): Güneşli dalında kazançlar nem 0.971, sıcaklık 0.571, rüzgâr 0.020; yağmurlu dalında rüzgâr 0.971, nem 0.020, sıcaklık 0.020.

### 6.7 Sonuç: Yükseklik 3'ten 2'ye

Rastgele kurulan ağacın yüksekliği 3'tü. Bilgi kazancıyla kurulan ağacın yüksekliği 2'dir. Yani 3 soru yerine en fazla 2 soru sorarak cevaba ulaşılır. Hava bulutluysa tek soru yeter.

### 6.8 Derste Birlikte Yapılan Uygulama

Aradan önce hoca hesabı öğrencilerle birlikte baştan yaptı.

Sistemin entropisi: Kaç sınıf var? İki: yes ve no. 14 örneğin 9'u yes, 5'i no:

$$E(S) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14}$$

Sonra köke hava durumu konursa ne olacağı hesaplandı. Hava durumunun her değeri sayıldı:

- Güneşli: 5 örnek; 3 no, 2 yes.
- Bulutlu: 4 örnek; 4 yes, 0 no.
- Yağmurlu: 5 örnek; 3 yes, 2 no.

Formüle yerleştirme:

$$\text{Gain}(S, \text{hava}) = E(S) - \Big[\tfrac{5}{14}\big(-\tfrac{3}{5}\log_2\tfrac{3}{5} - \tfrac{2}{5}\log_2\tfrac{2}{5}\big) + \tfrac{4}{14}\big(-\tfrac{4}{4}\log_2\tfrac{4}{4} - \tfrac{0}{4}\log_2\tfrac{0}{4}\big) + \tfrac{5}{14}\big(-\tfrac{3}{5}\log_2\tfrac{3}{5} - \tfrac{2}{5}\log_2\tfrac{2}{5}\big)\Big]$$

Hesap (ara adım eklendi): $0.940 - \left(\frac{5}{14}\cdot 0.971 + \frac{4}{14}\cdot 0 + \frac{5}{14}\cdot 0.971\right) \approx 0.940 - 0.694 = 0.246$. Burada $0 \cdot \log_2 0$ terimi 0 kabul edilir (ara adım eklendi).

> **Ders sonrası not:** Uygulama sırasında hoca sistemin entropisini "0.97 idi galiba" diye hatırladı. 9 yes, 5 no için doğru değer 0.940'tır. 0.971, güneşli ve yağmurlu dallarının entropisidir.

> **Hocanın vurgusu:** Önemli olan entropi ve bilgidir: Bilginin nasıl entropiye dönüştüğü ve bir sistemin entropisinin nasıl hesaplandığı. Diğer özelliklerin kazançlarını kendiniz hesaplayıp aynı sonuçları elde edebildiğinizi görün.

## 7. Ağaçlarda İzomorfizm

Aradan sonra ağaçların son konusuna geçildi. İzomorfizm (isomorphism) benzerlik demektir. İki ağaç görsel olarak birbirine benzemeyebilir. Acaba yapıca benzer midir? Ağaçlar birbirine benziyorsa üzerlerinde ortak işlemler yapılabilir.

### 7.1 Birebir ve Örten Eşleme

Slayttaki $T_1$ ve $T_2$ ağaçları görsel olarak hiç benzemiyor, ama izomorfiktir. İki ağacın izomorfik olması için aralarında birebir ve örten (bijective) bir fonksiyon bulunmalıdır. Hatırlatma: Tanım kümesindeki (domain) her eleman değer kümesindeki (range) bir elemana karşılık gelir ve değer kümesinde açıkta eleman kalmaz. Ağaçlarda da aynısı düşünülür. Bakılacak şeyler: düğüm sayılarının aynı olması, kenar sayılarının aynı olması ve düğümlerin derecelerinin aynı olması. Bir düğümün derecesi, o düğüme giren ve çıkan kenarların toplamıdır.

### 7.2 Köklü Ağaçlar

Ağaçlar köklü de olabilir köksüz de. Köklüyse bu bilginin verilmesi gerekir. Slayttaki örnekte $T_1$'in kökü $r_1$, $T_2$'nin kökü $r_2$'dir. İkisinde de 5 düğüm vardır; birebir eşleme kurulabilir ve kökler birbirine karşılık gelir. Bu ağaçlar köklü ağaç olarak izomorfiktir.

### 7.3 İkili Ağaçlar

Hoca çıtayı yükseltti. İki köklü ağaçta da 5 düğüm ve 4 kenar varsa köklü ağaç olarak izomorfik denebilir. Fakat bu ağaçların ikili ağaç (binary tree) olduğu söylenirse durum değişir. İkili ağaçta bir düğümden en fazla iki kenar çıkar ve çocukların sol/sağ konumu anlam taşır. Slayttaki ağaçlardan biri sağa doğru, diğeri sola doğru genişliyor. Düğüm ve kenar sayıları aynı olsa da ikili ağaç olarak izomorfik değildir. İkili ağaçta derinleşme yönlerinin de aynı olması gerekir.

Bir başka örnek: Kökü olan, 4 düğümlü ve 3 kenarlı iki ağaç köklü ağaç olarak izomorfiktir, ama ikili ağaç bilgisi verildiğinde değildir.

### 7.4 Derece Dizisi

Hoca dereceleri bir örnekle gösterdi. Bir ağaçta düğüm dereceleri 1, 3, 1, 1'dir (bir düğümden üç kenar çıkıyor, diğerlerinden birer). Öbür ağaçta da 1, 3, 1, 1'dir. Dereceler de aynıdır.

### 7.5 Olmadığını Göstermek Daha Kolay

> **Hocanın vurgusu:** Bir şeyin olduğunu ispatlamaktansa olmadığını ispatlamak daha kolaydır.

Bir şeyin var olduğunu ispatlamak için belki yüz soruya cevap vermek gerekir; ancak yüzü de tamamsa o şey vardır. Olmadığını göstermek için tek bir sağlanmayan şart bulmak yeter. Hoca bunu önermeler mantığındaki "her" (for every) ve "bazı" (for some) niceleyicilerine benzetti: "Her" için kümedeki bütün elemanlar sağlamalıdır; tek bir sağlamayan eleman bulunursa "her" denemez. İzomorfizmde de, ister ağaç ister graf olsun, izomorfik olmadığını göstermek çok daha kolaydır.

### 7.6 İzomorfizm İçin Şartlar

İki ağaç arasında izomorfizm aramak için şu şartlar sağlanmalıdır:

- Düğüm sayıları aynı olmalı. Aynı değilse diğer şartlara bakmaya gerek yoktur.
- Kenar sayıları aynı olmalı.
- Karşılıklı düğümlerin dereceleri aynı olmalı.
- Köklü ağaçta kök köke eşlenmeli.
- İkili ağaçta çocukların (child) pozisyonları da aynı olmalı.

Hoca köklü ağaç eşlemesini şöyle anlattı: Ağaçları köklerinden tutup üzüm salkımı gibi salladığınızda aynı düğümler ve aynı kenarlar aynı şekilde sallanmalıdır. Dalların boyunun uzun ya da kısa çizilmiş olmasının önemi yoktur.

> **Ders sonrası not:** Hoca üç tür izomorfizmi özetlerken "Kök bilgisi yoksa düğüm sayısına, kenar sayısına bakıp izomorfizm var dersiniz" dedi. Bu şartlar gereklidir ama yeterli değildir. Aynı düğüm sayısına sahip her ağacın kenar sayısı zaten $n-1$'dir. Örneğin 4 düğümlü yıldız (dereceler 1, 1, 1, 3) ile 4 düğümlü yol (dereceler 1, 1, 2, 2) aynı düğüm ve kenar sayısına sahiptir ama izomorfik değildir. Derece dizisi de yalnız gerekli bir şarttır. Hoca da az sonraki örnekte "sadece kenarlara baksaydım yanılırdım" diyerek derecelere bakmayı ekledi.

### 7.7 Dört Ağaç Örneği

Slaytta 4 ağaç verildi. En tepedeki düğümler kök kabul ediliyor; ikili ağaç denmemiş, köklü ağaç denmiş. Bu ağaçlarda izomorfizm var mı?

- Hepsinde 4 düğüm ve 3 kenar vardır.
- Düğüm dereceleri: birinci ağaçta 1, 1, 1, 3; ikincide 1, 1, 1, 3; üçüncüde 1, 2, 1, 2; dördüncüde 1, 2, 2, 1.

Hoca derecelere bakarak birinci ile ikincinin, üçüncü ile dördüncünün kendi aralarında izomorfik olduğunu söyledi. Yalnız düğüm sayısına ya da yalnız kenar sayısına bakılsaydı yanılınırdı.

<!-- BELİRSİZ: Dört ağacın şekli ekranda. Kısa notta şekiller "1: kökten üç yaprak, 2: kök - orta düğüm - iki yaprak, 3: kökten iki dal (biri iki uzunlukta), 4: dört düğümlü yol" olarak verilmiş; bu, altyazıdaki derece dizileriyle tutarlıdır ama altyazıdan doğrulanamıyor. -->

> **Ders sonrası not:** Hocanın sonucu kök bilgisi yokken (köksüz ağaç olarak) doğrudur: 1 ile 2 yıldız, 3 ile 4 yoldur. Ağaçlar köklü kabul edilirse kök köke eşlenmelidir. Kısa nottaki şekillere göre birinci ağaçta kökün derecesi 3, ikincide 1'dir; üçüncüde kökün derecesi 2, dördüncüde 1'dir. Bu durumda köklü ağaç olarak dördü de birbirinden farklıdır. Şekiller altyazıdan doğrulanamadığı için bu sonuç büyük olasılıkla doğrudur.

### 7.8 İzomorfik Olmayan İkili Ağaç Sayısı

Son slaytta şu soruldu: $n$ düğümle kaç tane izomorfik olmayan ikili ağaç çizilebilir? 3 düğüm ve 2 kenarla en bilinen ikili ağaç, kökün iki çocuğu olduğu ağaçtır. Diğerleri, bir yöne ya da zikzak ilerleyen ağaçlardır. İkili ağaçlarda çocukların pozisyonu önemli olduğu için bunların hiçbiri birbiriyle izomorfik değildir.

Formül:

$$\frac{1}{n+1}\binom{2n}{n}$$

$n = 3$ için:

$$\frac{1}{4}\binom{6}{3} = \frac{1}{4}\cdot\frac{6!}{3!\,3!} = \frac{1}{4}\cdot\frac{6\cdot 5\cdot 4}{3\cdot 2\cdot 1} = \frac{20}{4} = 5$$

3 düğümle 5 farklı ikili ağaç çizilebilir.

> **Ders sonrası not:** Hoca hesabı tahtada yaparken $(6-3)!$ yerine birkaç kez $4!$ yazdı ve sonucu bulamadı; sonra $\binom{6}{3} = \frac{6!}{3!\,3!}$ olarak düzeltip 5'e ulaştı. Doğru hesap yukarıdadır.

> **Ek bilgi (derste anlatılmadı):** $\frac{1}{n+1}\binom{2n}{n}$ sayılarına Catalan sayıları denir: $n = 1, 2, 3, 4, 5$ için 1, 2, 5, 14, 42. Bu sayılar ikili ağaç sayısının yanı sıra büyük olasılıkla dengeli parantez dizilerinin sayısı gibi başka sayma problemlerinde de karşınıza çıkar.

## 8. Graflara Giriş: Tanım ve Terimler

Ağaçlar bitti ve graf teorisine geçildi. Hoca, ağaçlardan sonra grafların biraz daha hafif geleceğini söyledi. Ağaçlar da bir tür graftır, ama graflar ağaç değildir. Pek çok şeyin benzerini göreceğiz. Fark şudur: Ağaçlar kapalı döngü oluşturmaz; graflar oluşturmak zorunda değildir ama oluşturabilir.

### 8.1 Tanım

Hoca bir anekdot anlattı: Bir akademik sınavda adaya "grafı tarif et" diye sorulmuş. Aday bildiği her şeyi anlatmış, ama jürinin beklediği tek şey şuymuş:

**Graf, düğümler ve kenarlardan oluşan bir yapıdır:** $G = (V, E)$.

- $V$: düğüm (vertex) kümesi. Süslü parantez içinde bütün düğümler yazılır.
- $E$: kenar (edge) kümesi. Süslü parantez içinde ikili düğüm çiftleri yazılır: $E = \{\{v, w\}, \{w, y\}, \{y, z\}, \dots\}$.

<!-- BELİRSİZ: Slayttaki örnek grafın kenar listesi altyazıda "V, W, W, Y, Y, Z, U, Z, U, Y, S, U, S, Y, S, V, S, W, S, X, X, V, ..." diye bozuk okunuyor; tam liste çıkarılamadı. -->

Ağaçtan farkı: Ağaçta bir düğümden diğerine gitmek için tek bir yol vardır. Grafta $v$'den $w$'ye birçok farklı yoldan gidilebilir. Döngülü bir yapı varsa alternatif sayısı çok artar.

### 8.2 Terimler

- **Yalıtılmış düğüm (isolated vertex):** Hiçbir kenarı olmayan, kimseyle bağlantısı olmayan düğüm. Tek bir düğümden oluşan graf da bir graftır; hoca buna "noktasal graf" dedi.
- **Paralel kenar:** Aynı iki düğüm arasında birden fazla kenar. Örnekte $A$ ile $B$ arasında paralel kenar vardır. Paralel kenarlar yönlü de olabilir yönsüz de: Biri $A$'dan $B$'ye, biri $B$'den $A$'ya gidebilir ya da hiç yön olmayabilir. Yön verilmediği sürece graf yönsüzdür. Yönlü graf deniyorsa yön mutlaka belirtilmelidir.
- **Döngü (loop):** Bir düğümden çıkıp başka hiçbir düğüme uğramadan aynı düğüme dönen kenar. Hoca bunun kapalı çevrimle (cycle) karıştırılmamasını söyledi.

## 9. Graf Türleri

### 9.1 Basit Graf, Çoklu Graf, Sözde Graf

- **Basit graf (simple graph):** Yönsüzdür, paralel kenar içermez, döngü içermez.
- **Çoklu graf (multigraph):** Basit grafın yetmediği durumlarda kullanılır. Yönsüzdür, paralel kenar içerebilir, döngü içermez.
- **Sözde graf (pseudograph):** Çoklu grafın yetmediği durumlarda kullanılır. Yine yönsüzdür; paralel kenar ve döngü içerebilir. Çoklu grafın üstüne döngü eklenmiş halidir.

Hoca bir not ekledi: Her basit graf bir çoklu graftır, ama çoklu graflar basit graf değildir. Bir graf için "çoklu graf" denmişse üzerinde paralel kenar olabilir de olmayabilir de; basit grafta ise hiçbir zaman paralel kenar olmaz.

### 9.2 Ağırlıklı Graf

Kenarların üzerinde sayısal bir ağırlık değeri verilmişse graf ağırlıklı graftır (weighted graph). Prim algoritmasında kenarlara verilen ağırlıklar buna örnektir.

### 9.3 Yönlü Graflar

Yönlü graflarda (directed graph, digraph) her kenar sıralı bir düğüm çiftiyle ilişkilendirilmiştir ve her kenarın yönü vardır. Artık hangi düğümden hangi düğüme gidilebileceği bellidir. Slayttaki örnekte $B$'den $C$'ye doğrudan gidilemez; önce $B$'den $D$'ye, sonra $D$'den $C$'ye gidilir.

Hoca bunu tek yönlü sokaklara benzetti: Ana caddeye çıkmak için tek yönlü yolları izlemek gerekir; bu yollar tamamen yönlü graf gibi tasarlanmıştır. Bazen iki yönlü ok olur; bu, hem gidiş hem geliş olduğunu gösterir. Bunu tek bir iki yönlü okla ya da iki ayrı yönlü kenarla gösterebilirsiniz.

### 9.4 Özet Tablo

| Tür | Kenar | Çoklu (paralel) kenar | Döngü |
| :--- | :---: | :---: | :---: |
| Basit graf | yönsüz | yok | yok |
| Çoklu graf | yönsüz | var | yok |
| Sözde graf | yönsüz | var | var |
| Yönlü graf | yönlü | yok | var |
| Yönlü çoklu graf | yönlü | var | var |

Yönlü grafta çoklu kenara izin yoktur; çoklu kenara izin verilmek isteniyorsa graf yönlü çoklu graf adını alır. İkisinde de döngüye izin vardır.

## 10. Benzerlik Grafı

Hoca burada "benzerlik" kelimesinin izomorfizm anlamında değil, benzerlik (similarity) anlamında kullanıldığını belirtti.

### 10.1 Problem

Nesneleri değişik özelliklerine göre sınıflandırmak istiyoruz. Elimizde çok sayıda program kodu var ve bunları belirlediğimiz özelliklere göre gruplamak istiyoruz. Üç özellik kullanılır:

- Programdaki satır sayısı (lines of code, LOC),
- Kullanılan return sayısı,
- Çağrılan fonksiyon sayısı.

Her program parçası bir düğümdür. Her düğüm üç özellik taşıdığı için bir üçlüyle (tuple) gösterilir. Programlar birbirine benziyorsa düğümleri bir kenarla bağlanır; bağlanan iki program aynı küme içinde olabilir.

| Kod | Satır | Return | Fonksiyon çağrısı |
| :---: | :---: | :---: | :---: |
| $v_1$ | 66 | 20 | 1 |
| $v_2$ | 41 | 10 | 2 |
| $v_3$ | 68 | 5 | 8 |
| $v_4$ | 90 | 34 | 5 |
| $v_5$ | 75 | 12 | 14 |

### 10.2 Benzer Olmama Fonksiyonu

Pek çok benzerlik ölçütü vardır; her kitapta farklısını görebilirsiniz. Burada benzerlik değil, benzer olmama (dissimilarity) ölçülüyor. Hoca bunu izomorfizmdeki fikre bağladı: Benzer olduğunu göstermek, benzer olmadığını göstermekten daha zordur.

$v = (p_1, p_2, p_3)$ ve $w = (q_1, q_2, q_3)$ iki kod olsun. Karşılıklı elemanların mutlak farkları toplanır:

$$s(v, w) = \sum_{k=1}^{3} |p_k - q_k|$$

Bir de eşik (threshold) değeri $N$ gerekir. $s(v, w) < N$ ise $v$ ile $w$ arasına bir kenar eklenir; değilse bu iki kod birbirine benzemiyordur ve bağlanmaz.

### 10.3 Hesap

Düğümler bir matris gibi düşünülür. Köşegen 0'dır; bir düğüm kendisiyle aynıdır. $v_1$, $v_2$'ye ne kadar benziyorsa $v_2$ de $v_1$'e o kadar benzer; matris simetriktir. Bu yüzden yalnız üst üçgen hesaplanır: $v_1v_2$, $v_1v_3$, $v_1v_4$, $v_1v_5$, $v_2v_3$, $v_2v_4$, $v_2v_5$, $v_3v_4$, $v_3v_5$, $v_4v_5$.

Derste yapılan iki hesap:

$$s(v_1, v_2) = |66-41| + |20-10| + |1-2| = 25 + 10 + 1 = 36$$

$$s(v_4, v_5) = |90-75| + |34-12| + |5-14| = 15 + 22 + 9 = 46$$

> **Ders sonrası not:** Hoca $v_1$'in satır sayısını önce "60" diye okudu ve $60-41 = 19$ buldu; bir öğrencinin uyarısıyla 66'ya düzeltti. Doğru fark 25'tir.

Bütün değerler:

| | $v_2$ | $v_3$ | $v_4$ | $v_5$ |
| :---: | :---: | :---: | :---: | :---: |
| $v_1$ | 36 | 24 | 42 | 30 |
| $v_2$ | | 38 | 76 | 48 |
| $v_3$ | | | 54 | 20 |
| $v_4$ | | | | 46 |

### 10.4 Eşik ve Sonuç

Eşik $N = 25$ alındı. Hoca bu değerin rastgele seçilmediğini, gerçekten bu alanda çalışılıyorsa denemelerle en iyi değerin belirlenmesi gerektiğini söyledi; sonra o alanda çalışanlar bu değeri kullanır.

25'ten küçük değerler: $s(v_1, v_3) = 24$ ve $s(v_3, v_5) = 20$. Grafa iki kenar eklenir: $v_1v_3$ ve $v_3v_5$.

Sonuç: $v_1$, $v_3$, $v_5$ özellikleri bakımından birbirine benzeyen üç koddur. $v_2$ diğer dördüne hiç benzemiyor, $v_4$ de benzemiyor; bunlar ayrı sınıflar olarak kabul edilebilir. Bu grafa benzerlik grafı (similarity graph) denir. Size bir benzerlik grafı verildiğinde bağlı düğümlerin benzer, bağsız düğümlerin farklı olduğunu anlarsınız.

## 11. Özel Graflar: $K_n$, $C_n$, $W_n$, $Q_n$

Hoca bu graflarla haftaya kromatik polinomlarda tekrar karşılaşılacağını söyledi.

### 11.1 Tam Graf $K_n$

Bir graf tamsa (complete) $K$ grafı diye adlandırılır. Graftaki her düğüm, kendisi dışındaki bütün düğümlere bağlıdır. Slayttaki örnekte $A$, $B$, $C$, $D$'nin her biri diğer bütün düğümlere bağlı. Alt indis $n$ düğüm sayısını gösterir; 5 düğümlü tam graf $K_5$'tir.

- $K_3$: 3 düğüm, her biri diğer ikisine bağlı (üçgen).
- $K_4$: 4 düğüm, her biri diğer üçüne bağlı.
- $K_6$: 6 düğüm, hepsi birbirine bağlı.

> **Ders sonrası not:** Hoca önce "$n$ düğüm derecesini gösterir" dedi, sonra "alt indis düğüm sayısını gösterir" diye düzeltti. $n$ düğüm sayısıdır; $K_n$'de her düğümün derecesi $n-1$'dir. Hoca ayrıca "$n \ge 3$ olmalı, 2 ya da 1 düğümlü graf $K$ grafı olamaz" dedi; az sonra da tek düğümlü noktasal grafı ve tek kenarlı çizgisel grafı andı. $K_1$ (tek düğüm) ve $K_2$ (tek kenar) da tam graftır. $n \ge 3$ şartı $C_n$ ve $W_n$ için gereklidir.

### 11.2 Çember Graf $C_n$

Çember graf (cycle graph) $C$ ile gösterilir; alt indis yine düğüm sayısıdır ve $n \ge 3$'tür. $n$ düğüm için kenarlar:

$$v_1v_2,\; v_2v_3,\; \dots,\; v_{n-1}v_n,\; v_nv_1$$

Kapalı bir döngü oluşur. $C_3$'te 1 ile 2, 2 ile 3 ve 3 ile 1 bağlıdır. $C_4$ için 4 düğüm konur ve çevrilir; $C_5$, $C_6$ de aynı şekilde çizilir.

Hoca iki küçük durumdan da söz etti: Tek düğümlü, hiç kenarı olmayan graf noktasal graftır. İki düğüm ve bir kenardan oluşan graf da çizgisel graftır. Bunlar graf çizerken pek dikkate alınmaz.

### 11.3 Tekerlek Graf $W_n$

Hoca tekerlek grafı (wheel graph) at arabası tekerleğine benzetti: Ortada bir göbek vardır, oradan dış çembere tahtalar uzanır ve dış çemberdeki bağlantı noktalarına kenetlenir. Gerçek dünyadaki at arabası tekerleği aslında bir tekerlek graftır.

Tekerlek graf, bir çember grafa ($C_n$) yeni bir düğüm eklenerek oluşturulur. Eklenen yeni düğüm diğer bütün düğümlere bağlanır. Bu düğümün ortaya çizilmesi zorunlu değildir; başka bir yere çizilip bütün düğümlere bağlanırsa da tekerlek graftır.

Adlandırma: Tekerlek graf, toplam düğüm sayısının bir eksiğiyle adlandırılır. Örneğin $W_3$'te 4 düğüm vardır. $W_3$ verilmişse önce bir $C_3$ çizilir, sonra ekstra bir düğüm eklenip diğerlerine bağlanır. $W_6$ isteniyorsa bir $C_6$ çizilir ve bir merkez düğüm eklenip altı düğümün hepsine bağlanır.

### 11.4 Küp Graf $Q_n$

Küpe benzediği için küp graf denir ve $Q$ ile gösterilir. Buradaki $n$ çok önemlidir. Slayttaki küp grafta 8 düğüm vardır: $2^n = 8$ ise $n = 3$, yani bu $Q_3$'tür. $Q_n$'de $2^n$ düğüm vardır.

Düğümler $n$ bitlik dizgilerle etiketlenir. Etiketleme öyle yapılır ki bir düğümden komşusuna geçerken yalnızca bir bitin yeri değişir. Hoca küp üzerinde bir tur atarak bunu gösterdi: Hangi köşeden hangi komşu köşeye gidilirse gidilsin, yalnız bir bit değişir. Bunun önemi ileride görülecek.

- **$Q_1$:** $2^1 = 2$ düğüm, tek kenar. Çizgisel graf aynı zamanda bir $Q_1$'dir. Etiketler 0 ve 1.
- **$Q_2$:** $2^2 = 4$ düğüm, kare. Hoca Gray kodlamayla etiketledi: 00, 01, 11, 10. Her geçişte tek bit değişir.
- **$Q_3$:** 8 düğüm, küp, 3 bitlik etiketler.
- **$Q_4$ (hiperküp):** 16 düğüm. İç içe iki küp gibidir: içte 8, dışta 8 düğüm, karşılıklı köşeler birbirine bağlıdır. Etiketler 4 bitliktir.

Etiketlerin bit sayısı $n$'dir: $Q_3$ 3 bitlik, $Q_2$ 2 bitlik, $Q_1$ 1 bitlik. $Q_5$, $Q_6$ de yapılabilir ama iş çok karmaşıklaşır; bu derste görülmeyecek.

Hoca slayttaki $Q_3$ çiziminde koyu yazılmış kenarların ve okların henüz anlatılmadığını, dikkate alınmamasını söyledi.

## 12. İki Parçalı Graflar

### 12.1 Tanım

İki parçalı (bipartite) grafta graf iki parçaya ayrılır, ama bu ayırma keyfi değildir. $G$ grafının düğümleri, $m$ düğümlü $V_1$ ve $n$ düğümlü $V_2$ olmak üzere iki kümeye bölünsün. Graf iki parçalıysa bu iki kümenin kesişimi boş kümedir: $V_1 \cap V_2 = \emptyset$. Kural şudur: Bir kenarla birbirine bağlı düğümler aynı kümeye konmaz. Her kenar bir kümeden diğerine gider.

Slayttaki örnekte $\{A, B, C\}$ ve $\{D, E\}$ kümeleri vardır. $A$ ile $B$ arasında, $A$ ile $C$ arasında, $B$ ile $C$ arasında kenar yoktur. $D$ ile $E$ arasında da kenar yoktur. Bu graf iki parçalıdır.

### 12.2 $K_3$ İki Parçalı mı?

$K_3$'ü çizelim: 1, 2, 3 düğümleri birbirine bağlı. İki kümeye bölmeyi deneyelim:

- $\{1\}$ ve $\{2, 3\}$: 2 ile 3 bağlı, olmaz.
- $\{1, 3\}$ ve $\{2\}$: 1 ile 3 bağlı, olmaz.
- $\{1, 2\}$ ve $\{3\}$: 1 ile 2 bağlı, olmaz.
- Üçünü ayrı ayrı koymak üç küme demektir; iki parçalılık iki küme ister.

$K_3$ iki parçalı değildir.

### 12.3 $C_6$ İki Parçalı mı?

$C_6$'nın düğümleri 1'den 6'ya numaralansın ve çember şeklinde bağlansın. Hoca düğümleri tek tek yerleştirdi:

- 1 birinci kümeye konur. 2 ve 6, 1'e bağlı olduğu için ikinci kümeye konur; 2 ile 6 arasında doğrudan kenar yoktur.
- 3, 2'ye bağlı olduğu için ikinci kümeye konamaz; 1 ile bağı olmadığı için birinci kümeye konur.
- 4, 3'e bağlı olduğu için birinci kümeye konamaz; 2 ve 6 ile bağı yoktur, ikinci kümeye konur.
- 5, 4 ve 6'ya bağlıdır; ikinci kümeye konamaz. 1 ve 3 ile bağı yoktur, birinci kümeye konur.

Sonuç: $\{1, 3, 5\}$ ve $\{2, 4, 6\}$. $C_6$ iki parçalıdır.

### 12.4 Test Sorusu Tipi Örnekler

Hoca bir graf verip "bu nasıl bir graftır" diye sordu; şıklarda iki parçalı graf da var. Ayrıntılar aşağıdaki Örnek Sorular bölümündedir. Bu tür sorularda düğümleri tek tek iki kümeye yerleştirmeyi denemek gerekir.

Hoca, çok düğümlü graflarda gözle bakmanın zorlaştığını, bu işler için algoritma yazmanın en iyisi olduğunu söyledi. Grafı bir komşuluk matrisi gibi düşünün: Kenarı olan düğüm çiftine 1, olmayana 0 yazın. Örneğin 7 düğümlü bir graf için $7 \times 7$'lik bir matris kurulur ve iki parçalılığı bulan algoritma bunun üzerinde çalışır.

> **Hocanın vurgusu:** Boş vaktinizde ya da sömestr arasında iki parçalı grafı bulan algoritmayı kendiniz kurmaya çalışın. İnternette mutlaka vardır, ama önce kendinizin kurmaya çalışması kendinizi geliştirmek için çok daha önemlidir.

> **Ek bilgi (derste anlatılmadı):** Bir graf ancak ve ancak tek uzunlukta bir çember içermiyorsa iki parçalıdır. Bu yüzden $C_n$, $n$ çift ise iki parçalıdır, tek ise değildir. Hocanın istediği algoritma büyük olasılıkla genişlik öncelikli arama (BFS) ile "2-boyama" biçiminde kurulabilir: Bir düğüme 0 rengi verilir, komşularına 1, onların komşularına 0 verilir; iki komşu düğüm aynı rengi alırsa graf iki parçalı değildir. Derste $C_6$ için yapılan tek tek yerleştirme bu fikrin elle uygulanmasıdır.

### 12.5 Tam İki Parçalı Graf $K_{m,n}$

Tam iki parçalı graf (complete bipartite graph), iki parçalı grafın gelişmiş halidir. "Tam" (complete), $K_n$'deki gibi bütün bağlantıların bulunması demektir. Graf iki parçaya ayrılır ve bir parçadaki her düğüm karşı parçadaki bütün düğümlere bağlıdır. Bir parçada $m$, diğerinde $n$ düğüm varsa tam $m \cdot n$ kenar olmalıdır.

Slayttaki önceki iki parçalı graf örneği ($\{A, B, C\}$ ve $\{D, E\}$) tam değildir. Örneğin $A$'nın $D$'ye ve $C$'nin $E$'ye de bağlı olması gerekirdi. Bu bağlantılar eksik olduğu için tam iki parçalı graf değildir.

<!-- BELİRSİZ: Bu örnekte hangi kenarların bulunduğu ekranda; altyazıda yalnız "A'nın D'ye, C'nin E'ye komşuluğu eksik" diye geçiyor. -->

Örnekler:

- **$K_{2,3}$:** Üstte 2, altta 3 düğüm; kümelerin içinde bağlantı yok. $2 \cdot 3 = 6$ kenar olmalı; 6 kenar var. Tam iki parçalıdır.
- **$K_{3,3}$:** $3 \cdot 3 = 9$ kenar olmalı; her üst düğümden 3 kenar çıkıyor, toplam 9. Tam iki parçalıdır.
- **$K_{2,6}$:** $2 \cdot 6 = 12$ kenar olmalı; 12 kenar var. Tam iki parçalıdır.

Özet: İki parçalı grafta kümelerin içinde bağlantı olmayacak şekilde graf iki parçaya ayrılır. Tam iki parçalı grafta ayrıca iki parçanın eleman sayılarının çarpımı kadar kenar vardır.

## 13. Özel Grafların Düğüm ve Kenar Sayıları

Dersin sonunda hoca şu soruyu sordu: $K_n$, $C_n$, $W_n$, $K_{m,n}$ ve $Q_n$ graflarında $m$ ve $n$ verildiğinde düğüm ve kenar sayısını veren formüller nedir? Hesaplar öğrencilerle birlikte yapıldı.

- **$K_n$:** $n$ düğüm. Kenar sayısı $\frac{n(n-1)}{2}$. Kontrol: $K_4$'te $\frac{4 \cdot 3}{2} = 6$ kenar vardır; çizimde de 6 kenar sayılır.
- **$C_n$:** $n$ düğüm, $n$ kenar. Kontrol: $C_3$'te 3 düğüm, 3 kenar.
- **$W_n$:** $C_n$'ye bir düğüm eklendiği için $n+1$ düğüm. Kenar sayısı $2n$: Çemberin $n$ kenarına, merkez düğüm diğer bütün düğümlere bağlandığı için $n$ kenar daha eklenir.
- **$K_{m,n}$:** $m+n$ düğüm, $m \cdot n$ kenar.
- **$Q_n$:** $2^n$ düğüm. Kenar sayısı $n \cdot 2^{n-1}$. Hoca bu formülün çıkarılmasının uzun olduğunu söyleyip çıkarmadı.

| Graf | Düğüm sayısı | Kenar sayısı |
| :---: | :---: | :---: |
| $K_n$ | $n$ | $\frac{n(n-1)}{2}$ |
| $C_n$ | $n$ | $n$ |
| $W_n$ | $n+1$ | $2n$ |
| $K_{m,n}$ | $m+n$ | $m \cdot n$ |
| $Q_n$ | $2^n$ | $n \cdot 2^{n-1}$ |

> **Ek bilgi (derste anlatılmadı):** $Q_n$'nin kenar sayısı kısa bir sayımla bulunabilir. Her düğümün $n$ bitlik etiketinde değiştirilebilecek $n$ bit vardır; yani her düğümün derecesi $n$'dir. Derecelerin toplamı $n \cdot 2^n$'dir ve her kenar iki kez sayıldığı için kenar sayısı $\frac{n \cdot 2^n}{2} = n \cdot 2^{n-1}$ olur. Aynı mantıkla $K_n$'de her düğümün derecesi $n-1$ olduğu için kenar sayısı $\frac{n(n-1)}{2}$'dir.

Haftaya kalınan yerden devam edilecek: grafların dereceleri, graflarda izomorfizm, Dijkstra algoritması ve graf modellerinden sonra kromatik polinomlara geçilecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:44:22): Rastgele özelliklerle kurulan karar ağacının (kök nem, sonra rüzgâr, sonra hava durumu) seviyesi nedir?

Çözüm: Nem, rüzgâr ve hava durumu olmak üzere üç soru düzeyi vardır; seviye 3'tür. Bilgi kazancıyla kurulan ağaçta yükseklik 2'ye düşer.

**Soru 2** (derste sözlü, 00:43:49): Nem normal, rüzgâr zayıf ve hava yağmurluysa tenis oynanabilir mi?

Çözüm: Derste ağaç üzerinden bakılıp "evet, oynayabilirsin" denildi. Veri setinde bu koşulları taşıyan 5 ve 10 numaralı günlerin ikisi de yes'tir. Bilgi kazancıyla kurulan ağaçta da hava yağmurlu ve rüzgâr zayıf olduğu için sonuç yes'tir.

**Soru 3** (derste sözlü, 01:14:21): Veri setinin (sistemin) entropisini hesaplayın. Kaç sınıf var?

Çözüm: İki sınıf var (yes, no). 14 örneğin 9'u yes, 5'i no:

$$E(S) = -\frac{9}{14}\log_2\frac{9}{14} - \frac{5}{14}\log_2\frac{5}{14} \approx 0.940$$

Derste değer "0.97" diye hatırlandı; doğrusu 0.940'tır (bkz. Bölüm 6.8).

**Soru 4** (derste sözlü, 01:47:41): En tepedeki düğümleri kök kabul edilen, 4 düğümlü dört ağaçtan hangileri izomorfiktir?

Çözüm: Dördünde de 4 düğüm ve 3 kenar vardır. Derece dizileri 1-1-1-3, 1-1-1-3, 1-2-1-2, 1-2-2-1'dir. Derste birinci ile ikincinin, üçüncü ile dördüncünün kendi aralarında izomorfik olduğu söylendi. Köklü ağaç olarak kök köke de eşlenmelidir; bu açıdan bkz. Bölüm 7.7'deki not.

**Soru 5** (derste sözlü, 01:49:42): 3 düğümle kaç tane izomorfik olmayan ikili ağaç çizilebilir?

Çözüm: $\frac{1}{3+1}\binom{6}{3} = \frac{20}{4} = 5$.

**Soru 6** (derste sözlü, 02:09:35): $v_4 = (90, 34, 5)$ ile $v_5 = (75, 12, 14)$ arasındaki benzer olmama değerini hesaplayın.

Çözüm: $|90-75| + |34-12| + |5-14| = 15 + 22 + 9 = 46$.

**Soru 7** (derste sözlü, 02:27:32): $K_3$ iki parçalı bir graf mıdır?

Çözüm: Hayır. Üç düğümün her ikisi birbirine bağlı olduğu için, hangi ikiye bölme denenirse denensin aynı kümede bağlı iki düğüm kalır (bkz. Bölüm 12.2).

**Soru 8** (derste sözlü, 02:28:39): $C_6$ iki parçalı bir graf mıdır?

Çözüm: Evet. Kümeler $\{1, 3, 5\}$ ve $\{2, 4, 6\}$'dır (bkz. Bölüm 12.3).

**Soru 9** (derste sözlü, test sorusu tipi, 02:30:34): Ekranda verilen grafta $F$ düğümü $A, B, C, D, E$'nin hepsine bağlıdır; ayrıca $A$ ve $C$'nin de diğer düğümlerle bağlantısı vardır. Graf iki parçalı mıdır?

<!-- BELİRSİZ: Grafın tam kenar listesi ekranda; altyazıdan yalnız F'nin diğer beş düğüme bağlı olduğu ve A ile C'nin de diğerleriyle bağlantısı olduğu çıkıyor. -->

Çözüm: Bir öğrenci "F hepsiyle bağlantılı olduğu için olmayabilir" dedi. Hoca "olmayabilir diye bir cevap olmaz; bir şey ya oluyordur ya olmuyordur" dedi. $F$ diğer beş düğümün hiçbiriyle aynı kümeye konamaz; o halde $F$ bir tarafta, $A, B, C, D, E$ öbür tarafta olmalıdır. Ama $A$ ve $C$'nin de bu kümedeki düğümlerle bağlantısı vardır. Bu yüzden graf iki parçalı olamaz.

**Soru 10** (derste sözlü, 02:31:42): Ekranda verilen 7 düğümlü ($A, \dots, G$) graf iki parçalı mıdır?

<!-- BELİRSİZ: Grafın kenarları ekranda; altyazıdan yalnız G, F, E'nin birbirine bağlı olmadığı, A'nın B ile aynı kümeye konabileceği ama C ile konamayacağı çıkıyor. -->

Çözüm: Hoca önce $\{G, F, E\}$'yi bir kümeye koymayı denedi; $A$ ile $C$ bağlı olduğu için $\{A, B, C\}$ bir kümede olamadı. Bir öğrenci $\{A, B, D\}$ ve $\{C, E, F, G\}$ ayırımını önerdi. Hoca kontrol etti: $A$, $B$, $D$ arasında kenar yok; $C$, $E$, $F$, $G$ arasında da kenar yok. Graf iki parçalıdır.

**Soru 11** (derste sözlü, öğrenci sorusu, 02:35:17): İki komşu düğümün ortak bir komşusu varsa graf iki parçalı olamaz mı?

Çözüm: Evet. $A$ ile $B$ komşu ve ikisinin ortak komşusu $C$ ise $A$, $B$, $C$ bir $C_3$ (üçgen) oluşturur. Üçgen iki parçalı olamaz; bu yüzden onu içeren graf da iki parçalı olamaz. Aynı sebeple ($n \ge 3$ için) $K_n$ grafının iki parçalı olma imkânı yoktur.

**Soru 12** (derste sözlü, 02:40:15): $K_n$, $C_n$, $W_n$, $K_{m,n}$ ve $Q_n$ graflarının düğüm ve kenar sayılarını $m$ ve $n$ cinsinden verin.

Çözüm: Bölüm 13'teki tablo. Derste $W_n$ için bir öğrenci önce "$2(n-1)$ mi?" diye sordu, sonra "$2n$" dedi. Doğrusu $2n$'dir: $C_n$'nin $n$ kenarına merkezden $n$ kenar eklenir. $Q_n$ için $n \cdot 2^{n-1}$ derste çıkarılmadan verildi; Python ile $n = 1, \dots, 4$ için kontrol edildi (1, 4, 12, 32).

## Dersin Toparlaması

Bu derste ağaçlar bölümü tamamlandı ve graflara başlandı. Kruskal algoritmasında kenarlar küçükten büyüğe sıralanıp döngü oluşturmayan kenarlar seçildi; bütün düğümlerin seçilmiş görünmesinin yetmediği, $n$ düğüm için $n-1$ kenar seçilip bütün parçaların tek ağaçta birleşmesi gerektiği iki örnekle gösterildi. Karar ağaçlarında sahte para problemi ve "tenis oynanır mı" veri seti üzerinden sınıflandırma anlatıldı. Özelliklerin rastgele yerleştirilmesinin gereksiz yüksek ağaçlar ürettiği, olasılıkla ters orantılı bilgi kavramından entropinin, entropiden de bilgi kazancının kurulduğu ve bu yolla ağacın yüksekliğinin 3'ten 2'ye indiği görüldü. Ardından köksüz, köklü ve ikili ağaçlarda izomorfizm şartları, olmadığını göstermenin olduğunu göstermekten kolay olduğu fikri ve $n$ düğümlü ikili ağaç sayısı ele alındı.

Graflar bölümünde graf tanımı, yalıtılmış düğüm, paralel kenar ve döngü kavramlarıyla basit, çoklu, sözde, ağırlıklı ve yönlü graflar verildi. Benzerlik grafıyla program kodları özelliklerine göre gruplandı. $K_n$, $C_n$, $W_n$, $Q_n$ özel grafları, iki parçalı ve tam iki parçalı graflar ve bunların düğüm/kenar sayısı formülleri işlendi. Gelecek derste grafların dereceleri, graflarda izomorfizm, Dijkstra algoritması ve ardından kromatik polinomlar anlatılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
