# Ders 10 Genişletilmiş Notu: Makine Öğrenmesine Giriş: Problem Türleri ve Uygulamalar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Makine Öğrenmesi Nedir?
- 2. Sınıflandırma ve Model Ailesi
- 3. Kümeleme
- 4. Regresyon ve Model Esnekliği
- 5. Pekiştirmeli Öğrenme
- 6. Birliktelik Kurallarının Keşfi
- 7. Uygulama: Dolar Kuru Tahmini ve Zaman Serilerinde Test Kümesi
- 8. Uygulama: El Yazısı ve Kitap Yazısı Tanıma
- 9. Uygulama: Gen Mikrodizilimleri ve Hata Türlerinin Maliyeti
- 10. Tank Hikayesi: Makineye "Nasıl"ı Söyleyemeyiz
- 11. Biyometri ve Adversarial Örnekler
- 12. Diğer Uygulamalar ve Etik Sorular
- 13. Basit Bir OCR Uygulaması ve Eğitim/Test Ayrımı
- Örnek Sorular

## 1. Makine Öğrenmesi Nedir?

Bu ders makine öğrenmesi konusunun üç bölümünden ilkidir. Bu bölümde kavramlar ve uygulamalar ele alındı; sınıflandırma algoritmaları sonraki derse, pekiştirmeli öğrenme ise ayrı bir bölüme bırakıldı.

Slayttaki tanıma göre çok büyük miktardaki verilerin elle işlenmesi ve analizinin yapılması mümkün değildir. Bu tür problemlere çözüm bulmak amacıyla makine öğrenmesi metotları geliştirilmiştir. Bu metotlar **geçmişteki verileri kullanarak** veriye en uygun **modeli** bulmaya çalışır; yeni gelen verileri de bu modele göre analiz edip sonuç üretir (ekrandan, 00:10:00).

Hoca, sürecin temelini şöyle anlattı:

- Elimizde bir miktar veri vardır; bu veri farklı türlerde olabilir.
- Veri ve görev için bir algoritma seçilir. Algoritma seçmek aslında bir **model ailesi** seçmektir. Bu bir varsayımdır: "Bu veriyi bu algoritmayla iyi modellerim."
- Seçilen algoritmanın parametreleri vardır. Bu parametrelerin eldeki veriye uyumlu hale getirilmesine **eğitim süreci** denir. Bu süreç aslında ailenin veriye en uygun üyesini arama sürecidir.
- Eğitimden sonra, eğitim kümesinde olmayan bir örnek geldiğinde o örnek için tahmin üretilebilir.

> **Hocanın vurgusu:** Bir modelin başarılı olması, eğitim sürecinde kullanılmayan örnekler üzerindeki performansının iyi olması demektir.

Uygulamaların beklediği çıktı türleri farklıdır. Makine öğrenmesi problemleri bu çıktı türlerine göre sınıflandırılırsa birkaç tür ortaya çıkar.

## 2. Sınıflandırma ve Model Ailesi

### 2.1 Tanım ve örnek veri

Sınıflandırmada çıkış **kategorik** bir değişkendir: bir örnek geldiğinde üretilen çıktı bir sınıf etiketidir.

Slayttaki şekilde iki boyutlu uzayda mor (mavi) ve siyah noktalar vardır. Her nokta bir örnektir; iki boyutta olması her örneğin iki özelliğinin ($x_1, x_2$) bilindiği anlamına gelir. Renkler sınıfları gösterir. Kırmızı nokta ise sınıfı bilinmeyen yeni örnektir. Slayttaki tablo beş özellikli bir veri kümesini gösterir (ekrandan, 00:15:00):

| x1 | x2 | x3 | x4 | x5 | Sınıf |
|---|---|---|---|---|---|
| 1.2 | 3.4 | 2.3 | 6.7 | 7.8 | A |
| 1 | 2 | 2 | 4 | 5 | A |
| 9 | 8 | 6 | 5 | 3 | B |
| 6 | 7 | 8 | 9 | 1 | B |
| 8 | 8 | 9 | 9 | 9 | B |

**Soru:** Bu tablodaki her satır neyi temsil eder? **Cevap:** Bir örneği, yani şekildeki bir noktayı.

### 2.2 Doğrusal model ailesi

Örnek olarak doğrusal bir model seçildiğini düşünelim. Doğrusal model, sınıfları ayıran karar sınırının doğrusal olması demektir. Bu veri için bu varsayım fena değildir, çünkü iki sınıf düz bir çizgiyle ayrılabiliyor. İki boyutta bunu gözle görmek kolaydır; ama 500 boyutlu bir veride doğrusal ayrılabilirliği gözle anlamak kolay değildir.

Doğrusal model ailesinin sonsuz üyesi vardır. Hoca şeklin üzerine birçok doğru çizdi (ekrandan, 00:20:00). Bu doğruların her biri parametrik olarak şöyle yazılabilir:

$$w_1 x_1 + w_2 x_2 + w_3 = 0$$

$w_1, w_2, w_3$ parametrelerinin farklı değerleri farklı doğrular üretir. Bu parametreler eldeki veriye uyuma göre seçilir. Çizilen doğruların her birinin eğitim verisine uyumu farklıdır; bazıları diğerlerinden daha başarılıdır. Aynı uyuma sahip birden fazla üye de olabilir: eğitim kümesini hatasız ayıran tek bir doğru olması şart değildir.

### 2.3 Test örneği ve tahmin farklılığı

Eğitim bittikten sonra yeni bir test örneği (kırmızı nokta) geldiğinde yalnız model kullanılarak karar verilir: nokta doğrunun üstündeyse mor, altındaysa siyah sınıftandır.

Hoca, tek bir doğrunun olmadığını göstermek için iki pembe doğru ve bir mavi doğru çizdi. Üçünün de eğitim kümesindeki hatası sıfırdır; mor ve siyahları mükemmel ayırırlar. Ancak pembe doğrulara göre kırmızı nokta mor sınıfa, mavi doğruya göre siyah sınıfa düşer. Yani eğitim verisine %100 uyan modellerin test örneklerindeki tahminleri aynı olmak zorunda değildir. Hoca bunun bir varyans oluşturduğunu söyledi ama ayrıntısına girmedi.

### 2.4 Model eğitim verisini sıkıştırır

Model elde edildikten sonra eğitim kümesine ihtiyaç kalmaz. Modellemek, eğitim örneklerini bir model içine sıkıştırmak demektir: iki sınıfı ayırdığı düşünülen karar mekanizmasını, yani karar sınırını ifade eden bir formül bulunur. Bundan sonra yeni bir örneğin sınıfı ya da çıkışı yalnız modelle tahmin edilir.

## 3. Kümeleme

### 3.1 Tanım

Kümeleme Türkçede öbekleme ya da demetleme, İngilizcede clustering olarak geçer. Veri kümesinde örnekler ve özellikleri vardır, ama **çıkış yoktur**. Amaç örnekleri A, B gibi sınıflara atamak değil, genellikle önceden belirlenmiş sayıda kümeye ayırmaktır. Örneğin tablodaki ilk iki örnek bir kümeye, son üçü başka bir kümeye konabilir; ya da başka bir gruplama yapılabilir.

Çıkışın ne olması gerektiği söylenmiyorsa buna **gözetimsiz öğrenme** (unsupervised learning), çıkış bilgisi varsa **gözetimli öğrenme** (supervised learning) denir.

Kümeleme, örneklerin çeşitliliğini azaltır. Beş örnek iki kümeye ayrıldığında beş farklılık ikiye indirgenmiş olur.

### 3.2 256 rengi 16 renge indirmek

Slaytta iki biber resmi vardır: soldaki resimde pikseller 256 farklı değer alır (256 piksel değil, 256 farklı değer). Sağdakinde bu değerler 16'ya indirilmiştir (ekrandan, 00:25:00). Bu bir kümeleme problemidir: pikseller renklerine göre kümelenir ve her piksel kendi kümesinin değeriyle temsil edilir. Sonuçta birçok farklı kırmızı tonu tek bir kırmızıyla, birçok yeşil tonu tek bir yeşille gösterilir. Bunun nasıl yapılacağı sonraki derslerde görülecek.

Estetik açıdan sonuç kötüdür; resmin kalitesi bir miktar bozulur. İyi tarafı ise resmin daha az yer kaplamasıdır.

**Soru:** Resim ne kadar daha az yer kaplar? 256/16 kadar mı? **Cevap:** Hayır. Slayttaki ipucuna göre $n$ bit ile $2^n$ farklı değer tutulur (ekrandan, 00:25:00). 256 farklı değer için $\log_2 256 = 8$ bit, 16 farklı değer için $\log_2 16 = 4$ bit gerekir. Piksel sayısı değişmez, yalnız piksel başına gereken alan 8 bitten 4 bite iner. Boyut 16'da birine değil, **yarıya** iner.

Farklı değer sayısının azaltılmasına **kuantizasyon** da denir. Hoca kuantum fiziğindeki "kuantum" sözcüğünün de aynı fikre, parçacıkların her yerde değil belli seviyelerde bulunabilmesine dayandığını belirtti.

### 3.3 GSM operatörü örneği

Kümeleme yalnız resimlerde kullanılmaz. 16 milyon müşterisi olan bir GSM operatörü her müşteriye ayrı kampanya düzenleyemez; müşterilerini segmentlere ayırır. Müşterileri 5 segmente ayırmak, 16 milyon farklılığı 5 farklılığa indirmek demektir.

**Soru:** Böyle bir kümelemede girdiler ($x$'ler) neler olabilir? **Cevap (öğrencilerin önerileri):** aylık internet kullanımı (GB), konuşma süresi, SMS sayısı, geçmiş faturalar, konum, yaş, cinsiyet. Hoca yaşa göre (öğrenci paketleri) ve mesleklere göre paketler gördüğünü, cinsiyete göre paket görmediğini söyledi; kullanım alışkanlıkları farklı olsa da bunun bilinçli olarak yapılmadığını tahmin etti.

Kümeleme bu tür durumlarda verileri daha iyi yönetmek ve analiz etmek için kullanılır.

## 4. Regresyon ve Model Esnekliği

### 4.1 Regresyon

Regresyon da gözetimli öğrenmedir; girdiye karşılık olması gereken çıkış verilir. Ancak çıkış **sayısaldır**. Slayttaki örnekte her nokta bir arabadır; motor gücüne karşılık maksimum hız verilmiştir (ekrandan, 00:35:00). Grafikte yaklaşık 20 nokta, tabloda bunlardan 5'i vardır:

| Motor gücü | Max hız |
|---|---|
| 1500 | 230 |
| 2500 | 280 |
| 1600 | 210 |
| 3500 | 290 |
| 1200 | 210 |

Amaç, motor gücü verildiğinde maksimum hızı veren bir model kurmaktır. Grafikteki mavi doğru, doğrusal model ailesinin veriye en iyi uyan üyelerinden biridir. Ailenin başka üyeleri (başka doğrular) da çizilebilir; aralarındaki tek fark parametreleridir. Burada da eğitim, ailenin veriye en uyumlu üyesini bulmaktır.

### 4.2 Doğrusal model her veriye tam uyamaz

**Soru:** Sınıflandırma örneğinde doğrusal ailenin içinden eğitim kümesine tamamen uyan bir üye bulunabiliyordu. Bu regresyon örneğinde de bu geçerli mi? **Cevap:** Geçerli değil; bunun için bütün örneklerin dümdüz dizilmiş olması gerekirdi.

Herhangi bir doğru oturtulduğunda her örnek için hata vardır: model bir örnek için bir değer tahmin eder, gerçek değer farklıdır ve aradaki fark o örnekteki hatadır. Hoca bu hataları doğruyla noktalar arasındaki dikey kırmızı çizgilerle gösterdi; bazıları küçük, bazıları büyüktür.

**Soru:** Hatası olmayan bir model kurmak için ne yapmak gerekir? **Cevap:** Doğrusal model varsayımından çıkıp başka bir model ailesi seçmek gerekir.

Hoca grafiğe bütün noktalardan geçmeye çalışan yeşil bir eğri çizdi (ekrandan, 00:40:00). Bu eğri eğitim kümesine uyum açısından doğrudan daha başarılıdır, ama doğrusal ailenin üyesi değildir; onu bulabilmek için daha karmaşık bir model ailesi gerekir.

### 4.3 Esneklik ve parametre sayısı

Eğitim kümesine tam uyum sağlamak bütün model ailelerinin özelliği değildir. Hangi eğitim kümesi olursa olsun ona tam uyabilen aileler de vardır, bunu başaramayanlar da. Model ailesinin esnekliği arttıkça uyum sağlayabildiği eğitim kümesi sayısı artar. Esneklik temelde **parametre sayısıyla** artar: bir modelin parametresi ne kadar çoksa o kadar esnektir ve eğitim kümesine uyma ihtimali o kadar yüksektir.

**Soru:** O zaman neden basit modeller var, hep karmaşık modeller kullanılmıyor? **Cevap:** Eğitim kümesine uyum, test performansı hakkında temelde bir şey söylemez. Modelin parametreleri belirlenirken kullanılan örneklerdeki performans, daha önce görülmemiş örneklerdeki performans hakkında çok bilgi vermez. Basit bir model eğitim kümesinde karmaşık bir model kadar başarılı olmasa bile test kümesinde daha başarılı olabilir. Bu yüzden hem basit hem karmaşık modeller vardır.

Eldeki veriye en uygun model ailesinin seçimi kolay değildir; bu konu sonraki derste örneklerle ele alınacak.

## 5. Pekiştirmeli Öğrenme

### 5.1 Tanım

Slayttaki tanıma göre pekiştirmeli öğrenmede (reinforcement learning) modele çıkışın ne olması gerektiği söylenmez, sadece doğru ya da yanlış yaptığı söylenir (ekrandan, 00:45:00). Yani belli bir durumda yapılması gereken hareket verilmez; model bir hareket yaptığında bunun iyi ya da kötü, ne kadar iyi ya da ne kadar kötü olduğu söylenir.

### 5.2 Geri bildirim türleri

Hoca, modelin 3 ürettiği bir durum üzerinden farklı geri bildirim türlerini karşılaştırdı:

- "Sen 3 ürettin, ama üretmen gereken 5'ti." Bu doğrudan bir geri bildirimdir ve gözetimli öğrenmeye karşılık gelir. Model kendini buna göre düzeltir.
- "Doğru yaptın." Model parametrelerini düzeltmek için bir şey yapmaz.
- "Yanlış yaptın." Daha az bilgi verir. Model 3'ten uzaklaşması gerektiğini bilir, ama yukarı mı aşağı mı gideceğini bilmez.
- "Doğruya 2 uzaksın." Doğru cevap 1 de olabilir 5 de; hangisi olduğu bilinmez.

### 5.3 Neden doğrudan doğru cevap verilmiyor?

Hoca birkaç sebep saydı:

- O durumda ne yapılması gerektiğini biz de bilmiyor olabiliriz ve modelin bunu keşfetmesini isteyebiliriz.
- Biliyor olsak bile etiketlemek için zamanımız ve bütçemiz olmayabilir.
- O durumda yapılabilecek birden fazla doğru hamle olabilir. Örneğin 5 de 7 de iyi cevaplarsa "5 yapmalıydın" demek, 7'nin kötü olduğunu da söylemek olur. "Yanlış yaptın" demek ise işi modele bırakır.

Pekiştirmeli öğrenmede probleme dair bilgiler kullanılarak bir ödül ya da ceza fonksiyonu tanımlanır. Genelde tek bir kararın değil, ardışık ve birbirini etkileyen kararların olduğu problemlerde kullanılır; bunların en bariz örneği oyunlardır.

Hoca güncel bir örnek olarak ChatGPT gibi sistemlerin eğitim sürecinde pekiştirmeli öğrenme bulunduğunu söyledi. Geniş, açık alanlı (open domain) bir sistemde "kullanıcı şunu derse sen şunu de" biçiminde yeterli etiket toplamak pek mümkün değildir. Bunun yerine toplanan belli etiketlerle bir ödül (reward) fonksiyonu oluşturulur ve sistem onunla eğitilir.

Özetle buradaki geri bildirim, çıkışın ne olması gerektiği değil, çıkışa yönlendiren bir bilgidir: doğru/yanlış ya da "şu kadar doğru, şu kadar yanlış" gibi.

## 6. Birliktelik Kurallarının Keşfi

Birliktelik kurallarının keşfi aslında bir uygulamadır, ama birçok alana yayıldığı için ayrı bir problem türü olarak ele alınır. Ortaya çıktığı yer **sepet analizidir**: sanal ya da gerçek marketlerdeki sepetlerde hangi ürünler birlikte yer alıyor? Slayttaki kullanım alanları (ekrandan, 00:50:00):

- Sepet analizi: hangi ürünler birlikte satılıyor?
- Raf düzenlemesi: hangi ürünler yan yana konmalı? (Sanal markette sayfa düzenlemesi.)
- Promosyonlar: neyin yanında ne verilmeli? ("Bunu alırsan şunu da al", "ikisini birlikte alırsan indirim.")

Apriori gibi klasik ve oldukça başarılı algoritmalar vardır, ancak bu dersin kapsamında bunlara girilmeyecek.

## 7. Uygulama: Dolar Kuru Tahmini ve Zaman Serilerinde Test Kümesi

### 7.1 Veri kümesinin oluşturulması

Aradan sonra uygulamalara geçildi. Elimizde geçmiş tarihlere ait bir dolar kuru zaman serisi olsun. Varsayım şudur: doların bugünkü değeri yalnız önceki günlerdeki değerlerine bağlıdır. Hoca bunun doğru bir varsayım olmadığını, doların değerinin siyasi ve ekonomik birçok etkene bağlı olduğunu belirtti; ama örnek için kabul edildi.

Veri kümesinde örneklerin eşit sayıda ve aynı anlamda özellikleri olmalıdır. Bu yüzden ne kadar geçmişe bakılacağı sınırlanır. Buradaki varsayım, bugünkü değerin önceki 3 günün değerlerine bağlı olmasıdır. Seri kayan bir pencereyle tabloya çevrilir (ekrandan, 01:05:00):

Seri: 6.1, 6.2, 6.3, 6.3, 6.3, 6.2, 6.4, 6.1, ...

| D-3 | D-2 | D-1 | D |
|---|---|---|---|
| 6.1 | 6.2 | 6.3 | 6.3 |
| 6.2 | 6.3 | 6.3 | 6.3 |
| 6.3 | 6.3 | 6.3 | 6.2 |
| 6.3 | 6.3 | 6.2 | 6.4 |
| 6.3 | 6.2 | 6.4 | 6.1 |

Her satırda D-3, D-2, D-1 girdiler, D ise çıkıştır. Pencere birer adım kaydırılarak her satır elde edilir (tablo seriden python ile yeniden üretilerek doğrulandı).

**Soru:** Bu bir sınıflandırma problemi mi, regresyon problemi mi? **Cevap:** Regresyon; çünkü çıkış sayısaldır.

### 7.2 Zaman serilerinde eğitim ve test ayrımı

Hoca burada önemli bir parantez açtı. Zaman serisi içeren problemlerde eğitim ve test kümesi seçilirken **zamansal ayrım** korunmalıdır. Bu, modelin kopya çekmediğinden, ezberlemediğinden ve modelin kabiliyetinin abartılmadığından emin olmak içindir.

Örneğin bir yıllık veride ilk 8 ayın verileri eğitim, son 4 ayın verileri test kümesi olabilir. Bir yıllık veri karıştırılıp rastgele %80'i eğitim, %20'si test olarak ayrılırsa modelin kopya çekme ihtimali artar ve ölçülen performans gerçeği yansıtmaz. Çünkü gerçek hayatta geçmiş verilerle gelecek tahmin edilecektir; performans ölçülürken de eğitim ile test arasındaki bu ayrım aynı şekilde korunmalıdır.

> **Hocanın vurgusu:** Bu çok yapılan bir hatadır.

## 8. Uygulama: El Yazısı ve Kitap Yazısı Tanıma

Slaytta solda el yazısı bir mektup, sağda basılı bir metin vardır; ikisinde de işlem, şekillerin hangi harf olduğunu tahmin etmektir (HCR/OCR) (ekrandan, 01:10:00).

**Soru:** Hangisi daha kolaydır? **Cevap:** Sağdaki, yani kitap yazısı. Öğrenciler basılı metinde satırların ve harf boyutlarının belli olduğunu, el yazısında aynı harfin farklı yazılabildiğini söyledi.

Hoca bunu **sınıf içi benzerlik** kavramıyla açıkladı. Küçük "a" sınıfının örneklerini düşünelim: kitap yazısında bu örnekler birbirine çok benzer. El yazısında boyut bir şekilde normalize edilebilir, ama farklı kişilerin yazdıkları birbirinden farklıdır; aynı kişinin yazdıkları bile yazma hızına ve harfin kelimenin başında, ortasında ya da sonunda olmasına göre değişir.

- Sınıf içi benzerlik ne kadar fazlaysa problem o kadar **kolaydır**.
- Sınıflar arası benzerlik (bir sınıftaki örneğin başka bir sınıftaki örneğe benzemesi) ne kadar fazlaysa problem o kadar **zordur**.

Sınıflandırmada sınıf içi benzerliğin olabildiğince yüksek, sınıflar arası benzerliğin olabildiğince düşük olması istenir. "O" harfi ile "0" rakamı ya da "9" ile küçük "g" sınıflar arası benzerliğin yüksek olduğu, ayırt etmesi zor durumlardır; "1" ile "8" ise kolayca ayrılır. Bir sınıflandırma probleminin zorluğu bu iki benzerlik açısından değerlendirilebilir.

## 9. Uygulama: Gen Mikrodizilimleri ve Hata Türlerinin Maliyeti

### 9.1 Gen mikrodizilimleri

Slaytta ALL ve AML lösemi hücreleri ile bir mikrodizi çipi görülür. Metin şöyledir: 100 kişinin (hasta/sağlam) elimizde gen dizilimleri var. Bu dizilimleri analiz ederek hasta olup olmadığı bilinmeyen birinin hasta olup olmadığını ya da hastalığının türünü öğrenebilir miyiz? En iyi tedaviyi önerebilir miyiz? Nasıl? Elimizde hangi bilgiler olmalı? (ekrandan, 01:15:00)

Hoca, genetik hastalıkların asıl teşhisinin gen dizilimlerine bakılarak yapıldığını söyledi. Girdi gen dizilimleri, çıkış hasta olup olmamaktır.

**Soru:** Bu sınıflandırma mı, regresyon mu? **Cevap:** Sınıflandırma.

**Soru:** Hastalara verilecek ilacın dozu (kaç miligram) modellenirse? **Cevap:** Regresyon.

**Soru:** Farklı tedavi türlerinden hangisinin önerileceği modellenirse? **Cevap:** Sınıflandırma.

### 9.2 Hata türlerinin farklı maliyeti

İki sınıflı bir problemde A olana B demek ile B olana A demek, dışarıdan bakan biri için benzer hatalar gibi görünebilir; ama uygulamada etkileri farklıdır. Hasta birine "hasta değilsin" demek ile hasta olmayan birine "hastasın" demek aynı maliyete sahip değildir.

Otonom bir araç örneğinde, karşıdan karşıya geçen biri varken "yok" demek çok kötü sonuç doğurur; kimse yokken "var" demenin sonucu ise en fazla gereksiz bir fren olur. Bu hata tiplerine **tip 1** ve **tip 2** hata denir ve maliyetleri farklı olabilir.

Bu farkı eğitim sürecine katmak mümkündür: hatanın türüne göre modele ek ceza verilebilir, yani kayıp (loss) değeri hata türüne göre büyütülüp küçültülebilir. Böylece algoritmaya belli tür hatalardan daha çok kaçınması, bazılarına ise daha çok tahammül etmesi söylenebilir. Teknik ayrıntılarına girilmedi.

## 10. Tank Hikayesi: Makineye "Nasıl"ı Söyleyemeyiz

Hoca, gerçek olup olmadığından emin olmadığı bir hikaye anlattı. Tankların dış dünyayı görmesi zayıf olduğu için dışarıyı gösteren kameralar ve görüntüdeki nesneleri sınıflandıran algoritmalar yerleştirilmek istenir. İlk hedef, görüntüye düşman tankı girince uyarı veren bir sistemdir. Resim ve videolar çekilir, etiketlenir (düşman tankı, dost tankı, hiçbir şey yok), eğitim ve test kümeleri oluşturulur, bir yapay sinir ağı eğitilir. Testlerde yüzde yüze yakın başarı elde edilir. Model tanka monte edilip gerçek ortamda çalıştırıldığında ise başarı şans düzeyinin (yaklaşık %50) üstüne çıkmaz.

Sorun uzun süre bulunamaz; bunun bir sebebi, modelin kararlarını neye göre verdiğinin kolay anlaşılamadığı bir "kara kutu" olarak yapay sinir ağının kullanılmasıdır. Sonunda anlaşılır ki dost tanklarının görüntüleri güneşli havada, düşman tanklarınınki bulutlu havada çekilmiştir. Model tankları değil, havanın güzel mi kötü mü olduğunu sınıflandırmayı öğrenmiştir.

Hoca bu hikayenin ne anlattığını sordu. Öğrencilerin yorumları:

- Bağımlı ve bağımsız değişkenler kontrol altında tutulmalı; öğrenilmek istenen konu dışındaki değişkenler sabit kalmalı. Hoca, bunların ne olduğunu makinenin kendisinin bulmasının kolay olmadığını ekledi.
- A'ya B ve B'ye A deme maliyetinin farklı olması gibi, modele havayla ilgili kararlarının yanlış olduğu söylenerek model yönlendirilebilirdi. Hoca, modelin yönlendirilebileceğini ama orada kullanılan algoritmaların bunu yapamadığını söyledi.
- Sonuçlar veri kümesine çok bağlıdır; veri kümesi çok doğru seçilmelidir.

Hocanın çıkardığı sonuç şudur: popüler makine öğrenmesi algoritmalarının çoğu **çıkışı** optimize eder. Bir veri kümesi vererek makinelere **ne** yapmaları gerektiğini söyleyebiliriz, ama **nasıl** yapmaları gerektiğini söyleyemeyiz. Bu aslında makine öğrenmesini kullanmamızın da sebebidir: bir problemin nasıl çözüleceğini bilseydik algoritmasını doğrudan yazardık. Örneğin bir diziyi sıralamak için makine öğrenmesi kullanmanın pratik bir anlamı yoktur. Nasıl çözüleceğini bilmediğimiz için makineler girdi-çıktı ilişkisini kendileri kurar; ama bunu bizim hayal ettiğimiz yoldan yapmayabilirler. Hoca bunu bilerek abarttığı bir örnekle anlattı: bir robota bir insanı mutlu etme görevi verilirse, robot amaca beklenmedik ve istenmeyen bir yoldan ulaşmaya kalkabilir.

Bu her zaman kötü değildir: model, önemli olduğunu hiç düşünmediğimiz bir değişkeni kullanarak problemi iyi çözebilir ve bu da bilgimize katkı sağlar.

## 11. Biyometri ve Adversarial Örnekler

### 11.1 İris

Slayttaki soru: "Bu adam kim? İçeri girsin mi?" (ekrandan, 01:20:00). İris, gözdeki renkli halkadır ve göz kaslarından oluşur; kas deseni kişiye oldukça özeldir. Hocanın hatırladığına göre iki kişinin irisinin birebir aynı olma olasılığı milyarda birdir. Bu yüzden kişi tanıma için kullanışlı bir biyometrik özelliktir.

Sıkıntılı tarafları da vardır: kişiyi tanımak için iris bilgisine önceden erişilmiş olmalıdır ve en gelişmiş iris kameraları bile en fazla yaklaşık 3 metreden çekim yapabilir. Doğruluğu yüksek, ama erişimi ve donanım maliyeti yüksek bir yöntemdir.

**Soru:** Burada nasıl bir makine öğrenmesi var? İris veritabanına kaydedilip yalnız eşleştirme yapılmıyor mu? **Cevap:** Sadece o kadar değil. Kaydedilen görüntüyle yeni görüntü birebir örtüşmez: ışık ve benzeri koşullarda çok sayıda değişim olur. Bir kodu birebir eşleştirmek gibi değildir; aynı kişinin iris resimlerinde bile sınıf içi benzerlik yüksektir ama sonsuz değildir.

### 11.2 Yüz ve adversarial örnekler

İnsan yüzünün doğruluğu daha düşüktür (farklı açılar, farklı ışıklar), ama elde edilmesi çok daha kolaydır; örneğin aranan birini havalimanında yakalamak için kamera görüntüleri kullanılabilir.

Yüz tanıma algoritmalarından kaçmak için de yöntemler vardır. Hoca, bir ülkede protestocuların tespit algoritmalarını yanıltmak için belli desenler içeren tişörtler giydiğini hatırladı; bu desenler algoritmanın yüzü ya da insanı bulmasını engelliyordu. Bunlara **adversarial örnekler** denir. Makine öğrenmesi algoritmalarını kandırmak sağlam bir araştırma konusudur: kararlar makinelere bırakıldıkça, insanları kandırmaya çalışanlar gibi makineleri kandırmaya çalışanlar da olur. Görüntüde belli şeyler değiştirildiğinde model bir papağana çok yüksek olasılıkla "masa" ya da "sandalye" diyebilir. Hoca bunun, tank hikayesindeki durumdan farklı olduğunu belirtti: orada sorun modelin nasıl öğrendiğiydi, burada ise modeli yanıltan yapıların bilerek bulunmasıdır.

### 11.3 Parmak izi, ses ve imza

Parmak izinde iki kişinin aynı olma oranı hocanın hatırladığına göre milyonda birdir. Parmak izi bilgisayarlardan önce de kullanılıyordu: olay yerinden toplanan izler, defterlerdeki izlerle uzmanlar tarafından tek tek karşılaştırılırdı. Hoca, bu işi yapanların artık uzmanlığa daha az ihtiyaç duyduğunu ve bunun ölmekte olan bir meslek gibi görülebileceğini, ama uzmanlığın tamamen kaybolmasının iyi olmadığını söyledi; el dokuması halıların makine halılarına rağmen değerini korumasını örnek verdi. Önümüzdeki dönemde standart, çok kişinin yaptığı ve kayıt altına alınabilen işlerin makineleştirilebileceğini, yazılım ve eğitim sektörünün de bundan etkileneceğini tahmin etti.

Slaytta "Bu ses kimin? Bu ses ne diyor?" sorusu ve bir ses dalgası ile spektrogram vardır (ekrandan, 01:40:00). İmza taklidinde, imzanın nasıl atıldığını (zaman bilgisini de) gören profesyonel taklitçiler çok iyi taklit yapabilir; hoca bunun günümüzdeki çözümünün elektronik imza olduğunu ve analog imzanın öneminin azalacağını söyledi.

## 12. Diğer Uygulamalar ve Etik Sorular

### 12.1 Spam, güvenlik kamerası ve işaret dili

Bir mailin spam olup olmadığı çok yaygın bir problemdir ve reklam tarafı olduğu için hep var olacaktır. Spam filtreleri bazen iyi, bazen kötü çalışır; yine de çok zaman kazandırırlar. Güvenlik kamerası kayıtlarında olağan dışı bir durum olup olmadığını bulmak, videodaki durumları sınıf olarak tanımlayıp sınıflandırmakla mümkün olabilir. Videodan işaret dilini metne çevirmek de bir uygulamadır.

### 12.2 Otonom sürüş: ALVINN

Slayttaki örnek 1988 tarihli bir çalışmadır (slaytta "ALVIN*" yazar): otobanda saatte 70 mil hızla sürücüsüz gidebilen bir otomobil. Bütün denemeler trafiğe kapalı alanlarda yapılmıştır. Sistem bir yapay sinir ağıdır: 30x32 sensör girdi retinası, 4 gizli birim ve sola keskin dönüş, düz, sağa keskin dönüş arasında dağılan 30 çıkış birimi (ekrandan, 01:45:00). Hoca bu örneği, otonom sürüş üzerinde çok uzun zamandır çalışıldığını ve o zaman da yapay sinir ağlarının kullanıldığını göstermek için koyduğunu söyledi.

**Soru:** Sistemin çıktısı direksiyon açısı ile gaz ve fren pedallarının konumuysa bu sınıflandırma mı, regresyon mu? **Cevap:** Regresyon; bunların hepsi sayısaldır.

Slayttaki diğer sorular: Neden şehir içi değil? Neden otoban? Neden diğer arabalar yok? Araba birine çarparsa suçlu kim? Hoca, kararlar makinelere aktarıldıkça bu tür etik sorunlarla çok karşılaşılacağını söyledi: makineler belki insanlardan az, ama mutlaka hata yapacaktır ve bunun sorumlusunun kim olacağı, adalet duygumuzun buna nasıl uyum sağlayacağı açık bir sorudur.

### 12.3 Adalet

Slayt: Çin'de pilot uygulama: bir şehrin mahkeme hakimleri bir bilgisayar programı. Amaç daha adil bir dünya, yani aynı özelliklere sahip davalarda aynı kararların alınması. Sistemin eğitimi için milyonlarca, milyarlarca davaya ait verilerin kategorilenmesi gerekir (ekrandan, 01:50:00).

Hoca, iyi karar veren bir sistemin rüşvet almaması, morali bozulmaması ve karar verdikçe yorulmaması gibi avantajları olacağını söyledi. Belli kurallara bağlı milyonlarca dava bir kural sistemine oturtulup çok hızlı yürütülebilir; ama kurala uymayan durumlar da vardır. Adaletin tanımı ve insan yargıcın inisiyatif kullanabilmesi makineler için soru işaretidir; makineyi tasarlayanların seçtiği kayıp fonksiyonları ve kriterler çok etkili olacaktır. Bir öğrenci, makinelerin karşısındakinin insan olduğunu anlamadığını, insanın insanı yargılamasıyla makinenin insanı yargılamasının farklı olacağını söyledi. Hoca, bunların yeni yeni karşımıza çıkacağını, karar verilmesi gereken durumların artık insanların yetişemeyeceği kadar çok olduğunu, çok geciken bir kararın da anlamını yitirdiğini belirtti. Bu sistemler tek seferde mükemmel olmayacak; denenip vazgeçilen süreçler eğitimde ve hukukta görülecek.

### 12.4 Beyin aktiviteleri

Slayt: insanların değişik şeyler düşünürken, değişik duygulara sahipken, problem çözerken beyin aktiviteleri kaydedilir. Görev? (ekrandan, 01:55:00) Hoca olası görevler olarak insanların aklından geçeni okumayı, rüyaları kaydetmeyi, iki insanın yalnız düşünerek iletişim kurmasını saydı. Şu anki teknolojiyle bunlar mümkün değildir; yalnız düşünerek sağa, sola, yukarı, aşağı gibi hareketler ya da biraz daha yüksek çözünürlüklü hareketler yaptırılabiliyor. Bu alandaki gelişmeler insanın her şeyle etkileşimini değiştirebilir; en uç hali, beyin dışındaki her şeyin beyne eklenti gibi düşünülmesidir.

Bir öğrenci, beyin aktivitesine bakılarak suçlulardaki empati bölgelerinin çalışmadığının gözlemlendiği bir belgeseli hatırlattı. Hoca, bir insanın beyin aktivitelerine bakarak psikopat olup olmadığını tespit etmenin günümüz teknolojisiyle bile kabaca mümkün olduğunu, ama bunu sokaktaki insanlara uygulamanın ve suç işlenmeden önlem almanın ayrı bir hak sorunu olduğunu söyledi. Bir öğrenci, suçu ispatlanana kadar kimsenin suçlu sayılmadığını hatırlattı. Hocanın vardığı nokta şudur: teknolojik olarak yapılabilir olmak, yapılması gerektiği anlamına gelmez.

### 12.5 Veri büyüklükleri ve öğrenmenin geleceği

Bir tabloda çeşitli uygulama alanlarında örnek sayılarının ve özellik sayılarının çok büyük değerlere (milyonlara) ulaşabildiği gösterildi. Hoca, tablonun eski olduğunu ve günümüzde iki yönde de çok daha büyük sayılara ulaşıldığını söyledi.

"Öğrenmenin geleceği" slaytı (ekrandan, 02:00:00):

- Öğrenme modülleri birçok uygulamaya girmiş durumda.
- Ticari olarak satılan (gerçek dünya için tasarlanmış) birçok ürün var.
- Bu tür ürün ve modüllerin sayısı giderek artmakta.
- Çözüm bekleyen ve büyük potansiyelleri olan birçok problem (?) var.

Hoca insan öğrenmesinin de değişebileceğini ekledi. En iyi eğitimin birebir eğitim olduğu yaygın kabul gören bir yaklaşımdır: eğitmen kişiye göre anlatır, soruları ona göre seçer ve gelişimini takip eder. Bu ölçeklenebilir değildir, ama kişiye özel eğitim asistanlarıyla makinelere aktarılabilirse büyük avantaj sağlanabilir. Hoca bunun da bir soru doğurduğunu söyledi: bir insanı eğitebilen makine o işi zaten insan kadar yapabiliyorsa, insanı eğitmeye neden ihtiyaç olsun?

## 13. Basit Bir OCR Uygulaması ve Eğitim/Test Ayrımı

Dersin son konusu, bir kitap sayfasındaki yazıyı metne dönüştüren basit bir uygulamaydı:

```text
1. Resimdeki satırları bul.
2. Satırların içindeki harfleri bul.
3. Bütün harfleri eşit boyuta getir (10x6'lık bir yapı).
4. Her harf 10x6 = 60 boyutlu uzayda bir nokta olur.
5. Satırları örnekler, sütunları 60 piksel değeri olan bir matris kur;
   her örneğe hangi harf/rakam olduğunu gösteren sınıf bilgisini ekle.
6. Veriyi eğitim ve test kümesine ayır.
7. Eğitim kümesini bir sınıflandırıcıya ver ve modeli eğit.
8. Test örneklerini modele ver; tahmini gerçek sınıfla karşılaştırarak başarıyı ölç.
```

<!-- BELİRSİZ: Bu slaytın karesi yok. Altyazıda rakamlar için "her birinden 16 tane örnek" ve "100 tane örnek, 100 satır, 60 sütun" birlikte geçiyor; 10 rakam x 10 örnek = 100 olmalı. Rakam başına örnek sayısı doğrulanamadı. -->

Veri kümesini ikiye ayırmanın temel amacı, modelin gerçek dünyadaki performansını doğru tahmin etmektir. Bir OCR paketi yazıp insanlara verdiğinizde, kullanıcıların kendi örneklerindeki performansını bilmek istersiniz. Bunun için müşterinin verisi gerekir, ama o veri elinizde yoktur. Bu yüzden eldeki verinin bir kısmı "müşteri verisi" gibi kullanılır. Müşteri verisinin özelliği, makinenin eğitimde görmediği veri olmasıdır.

Hoca bunu sık verdiği bir örnekle açıkladı: bir öğretmen sınıfta çözdüğü soruların aynılarını sınavda sorarsa ve öğrenciler yüksek not alırsa, öğretmen öğrencilerin konuyu öğrendiğinden mi yoksa ezberlediğinden mi emin olamaz. Sınavda, sınıfta çözülen sorulara benzeyen ama onların aynısı olmayan sorular sorulmalıdır. Eğitim ve test kümesinin birbirinden ayrı olması bu yüzden gereklidir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00; derste sözlü, 00:12:23): Sınıflandırma slaytındaki tabloda ($x_1 \dots x_5$ ve Sınıf sütunları) her satır neyi temsil eder?

> **Cevap (derste verildi):** Bir örneği; iki boyutlu çizimde bu bir noktaya karşılık gelir.

**Soru 2** (ekrandan, 00:25:00; derste sözlü, 00:27:27): 256 farklı renk değerine sahip bir resim 16 renge indirilirse, piksel sayısı değişmediğine göre resim ne kadar daha az yer kaplar? İpucu: $n$ bit = $2^n$ farklı değer.

> **Cevap (derste verildi):** 256 değer için 8 bit, 16 değer için 4 bit gerekir. Piksel başına alan 8 bitten 4 bite iner; boyut 16'da birine değil yarıya iner.

**Soru 3** (derste sözlü, 00:30:54): Bir GSM operatörü müşterilerini segmentlere ayırmak isterse hangi girdileri kullanmak mantıklı olur?

> **Cevap (derste verildi, öğrenci önerileri):** Aylık internet kullanımı, konuşma süresi, SMS sayısı, geçmiş faturalar, konum, yaş, cinsiyet.

**Soru 4** (ekrandan, 00:35:00; derste sözlü, 00:36:34): Motor gücü ile maksimum hız verisinde doğrusal bir model eğitim kümesine tam uyabilir mi? Uyamıyorsa hatasız bir model için ne gerekir?

> **Cevap (derste verildi):** Uyamaz; bunun için bütün noktaların bir doğru üzerinde olması gerekirdi. Hatasız bir model için doğrusal varsayımdan çıkıp daha karmaşık (daha çok parametreli) bir model ailesi seçmek gerekir.

**Soru 5** (ekrandan, 01:05:00; derste sözlü, 01:06:37): Dolar kurunun önceki 3 günden tahmin edildiği problem sınıflandırma mı, regresyon mu?

> **Cevap (derste verildi):** Regresyon; çıkış sayısaldır.

**Soru 6** (ekrandan, 01:10:00; derste sözlü, 01:09:20): El yazısı tanıma mı yoksa kitap yazısı tanıma mı daha kolaydır? Neden?

> **Cevap (derste verildi):** Kitap yazısı. Aynı harfin örnekleri kitap yazısında birbirine çok benzer (sınıf içi benzerlik yüksektir). Sınıf içi benzerlik yüksek, sınıflar arası benzerlik düşük olduğunda problem kolaylaşır.

**Soru 7** (ekrandan, 01:15:00; derste sözlü, 01:13:37): Gen dizilimlerinden (a) kişinin hasta olup olmadığını, (b) verilecek ilaç dozunu, (c) önerilecek tedavi türünü tahmin etmek hangi problem türleridir?

> **Cevap (derste verildi):** (a) sınıflandırma, (b) regresyon, (c) sınıflandırma.

**Soru 8** (derste sözlü, 01:24:24): Testte %100'e yakın başarı gösteren, ama sahada şans düzeyinde kalan tank tanıma sistemi hikayesi bize ne anlatıyor?

> **Cevap (derste verildi):** Model tankları değil havayı (güneşli/bulutlu) ayırt etmeyi öğrenmişti. Makine öğrenmesi algoritmaları çıkışı optimize eder; makineye ne yapacağını söyleyebiliriz ama nasıl yapacağını söyleyemeyiz. Veri kümesinin dikkatle hazırlanması ve öğrenilmek istenen konu dışındaki değişkenlerin kontrol edilmesi gerekir.

**Soru 9** (ekrandan, 01:45:00; derste sözlü, 01:45:23): ALVINN sisteminin çıktısı direksiyon açısı ve pedal konumlarıysa problem sınıflandırma mı, regresyon mu? Slayttaki diğer sorular: Neden şehir içi değil? Neden otoban? Neden diğer arabalar yok? Araba birine çarparsa suçlu kim?

> **Cevap (derste verildi, ilk kısım):** Regresyon; çıktıların hepsi sayısaldır. Slayttaki diğer sorular derste tartışmaya açıldı, ayrı ayrı cevaplanmadı.

**Soru 10** (ekrandan, 01:50:00): Davaları bir bilgisayar programının karara bağladığı bir sistemin eğitimi için neler gereklidir?

> **Cevap (ekrandan):** Milyonlarca/milyarlarca davaya ait verilerin kategorilenmesi.

**Soru 11** (ekrandan, 02:10:00): Dilediğiniz konuda kendiniz bir veri kümesi oluşturun (hazır veri kümesi kabul edilmez; anket, gözlem ya da web sayfalarından veri çekilebilir). Veri kümesinin örnek sayısı en az 200, özellik sayısı en az 10 olsun; çıkış sınıflandırma ya da regresyon olabilir. En az 5 farklı tahminleyici ile 10 katlı çapraz geçerleme sonuçlarını elde edin. Özellik seçimi, özellik dönüşümü (PCA vb.) ve normalizasyonun tahminleyici başarılarına etkisini ölçün. Tahminleyicilerin performansları arasında istatistiksel anlamlı fark olup olmadığını t-testi ile kontrol edin.

Derste bu ödevle ilgili sorulan iki soru:

- **Soru:** "En az 10" sınıf sayısı mı? **Cevap:** Hayır; sınıf sayısı serbesttir (iki sınıf, yirmi sınıf ya da regresyon olabilir). 10, özellik sayısıdır: matrisin satır sayısı en az 200, sütun sayısı en az 10 olmalıdır.
- **Soru:** Metin verisinde cümlelerin kelime sayısı mı özellik sayısıdır? **Cevap:** Hayır. Metin sınıflandırmada en temel yaklaşım, veri kümesindeki bütün tekil kelimelerin sayısını özellik sayısı olarak almaktır; metinler TF ya da TF-IDF gibi yaklaşımlarla bu matrise kodlanır. Bu durumda özellik sayısı binleri geçer.

> **Çözüm (derste verilmedi):** Açık uçlu bir uygulama sorusudur, tek bir doğru cevabı yoktur. Genel akış şöyle kurulabilir: veri kümesi bir özellik matrisine ve bir çıkış sütununa dönüştürülür; scikit-learn ile en az 5 tahminleyici (örneğin karar ağacı, k-en yakın komşu, naive Bayes, lojistik regresyon, destek vektör makinesi) 10 katlı çapraz geçerlemeyle değerlendirilir; aynı deney normalizasyonlu, özellik seçimli ve PCA ile dönüştürülmüş veriyle tekrarlanır; iki tahminleyicinin 10 kat başarıları eşleştirilmiş t-testiyle karşılaştırılır. Çapraz geçerleme ve sınıflandırıcıların ayrıntısı sonraki derste anlatılacaktı.

## Dersin Toparlaması

Bu derste makine öğrenmesinin temel fikri kuruldu: bir model ailesi seçmek bir varsayımdır, eğitim bu ailenin veriye en uygun üyesini bulmaktır ve asıl başarı ölçüsü görülmemiş örneklerdeki performanstır. Çıktı türüne göre problemler sınıflandırma (kategorik çıkış), regresyon (sayısal çıkış), kümeleme (çıkış yok), pekiştirmeli öğrenme (yalnız doğru/yanlış ya da ödül/ceza geri bildirimi) ve birliktelik kurallarının keşfi olarak ayrıldı. Model esnekliğinin parametre sayısıyla arttığı, ama eğitimdeki tam uyumun test başarısını garanti etmediği görüldü.

Uygulamalar üzerinden zaman serilerinde eğitim/test kümesinin zamansal ayrılması, sınıf içi ve sınıflar arası benzerliğin problem zorluğuna etkisi, tip 1 ve tip 2 hataların farklı maliyetleri, makinelere "ne"yi söyleyip "nasıl"ı söyleyemememiz ve adversarial örnekler tartışıldı. Otonom sürüş, yargı ve beyin aktiviteleri örnekleri etik soruları gündeme getirdi. Sonraki derste sınıflandırma algoritmaları, çapraz geçerleme ve model ailesi seçimi örneklerle ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
