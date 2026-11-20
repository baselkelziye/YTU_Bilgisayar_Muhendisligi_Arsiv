# Ders 8 Genişletilmiş Notu: Bilgi Gösterimi ve Çıkarım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bilgi Nedir? Bilmenin Seviyeleri
- 2. Veriden Bilgiye
- 3. Bilginin Özellikleri (Meta Bilgi)
- 4. Bilgi Gösterim Türleri ve Kurallar
- 5. Kurallarla Çıkarım: İleriye ve Geriye Doğru Zincirleme
- 6. İki Doktor: Mekanizmalar Birlikte
- 7. Anlaşmazlık Kümesi ve Anlaşmazlığın Çözümü
- 8. Anlamsal Ağlar ve Hiyerarşik Bilgi
- 9. Yüklem Mantığı ve Çerçeveler
- 10. Sahneler
- 11. Kapalı Dünya ve Açık Dünya
- 12. Yapay Sinir Ağlarında Bilgi Temsili
- 13. Doğal Dil İşlemede Bilgi Gösterimi
- 14. Görüntü İşlemede Bilgi Gösterimi
- 15. Çıkarım Türleri: Tümdengelim, Abduction, Tümevarım
- 16. Çıkarım Örnekleri ve Belirsizlik Kaynakları
- Örnek Sorular
- Dersin Toparlaması

## 1. Bilgi Nedir? Bilmenin Seviyeleri

Bu derste önce bilgi gösterimi, sonra çıkarım konusu işlendi (slayt dosyaları `bilgi_gosterimi.ppt` ve `cikarim.pptx`, ekrandan, 00:10:00 ve 02:05:00). Bilginin içinde de bir çıkarım kısmı vardır; dersin sonundaki çıkarım slaydı ise çıkarımın türleriyle ilgilidir.

Slayttaki ilk cevap denemesi "bilgi, bilinen her şeydir" der. Hoca bunun iyi bir tanım olmadığını, kendine referans veren özyinelemeli (rekürsif) bir tanım olduğu için pek bir şey söylemediğini belirtti. Bilginin ne olduğuna dair herkesin uzlaşacağı bir tanım bulmak zordur. Buna karşılık "bilmenin" farklı seviyeleri tanımlanabilir ve bunları hepimiz hayatımızda görürüz.

Slayttaki "bilmenin farklı seviyedeki göstergeleri" şunlardır (ekrandan, 00:10:00):

- Farkında olma
- Anımsama / çağrıştırma / hatırlama
- Tanıma
- Yorumlama
- Açıklayabilir olma
- Kanıtlayabilir olma
- Hakkında konuşabilme
- Yerine getirebilir / yapabilir olma

Hoca bu listenin yukarıdan aşağı artan ya da azalan bir sıra olmadığını vurguladı. Örneğin bir arkadaşınızın yüzünü tanırsınız, bir şey size başka bir şeyi çağrıştırır; bunların hepsi ayrı mekanizmalardır.

Seviyeleri bir örnekle somutlaştırmak için slayta $E = mc^2$ resmi kondu. Bir öğrenci bunun maddenin enerjiye dönüşümü denklemi olduğunu söyledi. Hoca şunu sordu: Bu denklemi ne olduğunu bilmeden de tanımak mümkün mü? Bir öğrencinin dediği gibi, denklem tişörtlerde bile vardır; bazı insanlar ne anlama geldiğini bilmeden onu tanır. Bu, düşük seviyede bir bilmedir. Biraz daha üst seviye parçaları söylemektir: E enerjiyi, m kütleyi, c ışık hızını gösterir. Bir üst seviye yorumlamaktır: enerji ile kütle birbirine dönüştürülebilir. Daha da üstte kanıtlayabilmek vardır; hoca bunun ayrı bir seviye bilmeyi gerektirdiğini, kendisinin bunu yapamayacağını söyledi. Böylece tek bir denklem üzerinde tanımak, hakkında konuşmak, yorumlamak, açıklamak ve kanıtlamak gibi farklı bilme seviyeleri görülmüş oldu.

## 2. Veriden Bilgiye

### 2.1 Veri-bilgi üçgeni

Bu ders kapsamında veri ve bilgi kavramlarının ne ifade ettiği bir üçgenle gösterildi (ekrandan, 00:15:00). Üçgenin alt kısmında veri, üst kısmında bilgi vardır. Dikey eksen soyutluk derecesidir (alt düşük, üst yüksek); yatay eksen miktardır. Alt kısım hacimce büyüktür: veri çoktur, bilgi azdır. Yukarı çıktıkça "işleme / yorumlama miktarı" ve "kişiye özel oluş" artar.

Herkesin bir şeye baktığında ortak gördüğü kısma veri denir. Herkes aynı şeye bakar ama herkes aynı şeyi görmez. Bunu sağlayan, insanların veriyi alıp işlemesi, yorumlaması ve kendilerine has hale getirmesidir. Bu işlem yapıldıkça soyutluk derecesi artar.

### 2.2 Pikseller, bölgesel etiketler, tek bir etiket

Bir resmin pikselleri veridir. İnsanlar renkleri birbirinden çok farklı görmez; küçük farklar olabilir ama büyük farklar olmaz. Bir üst seviyede bölgesel etiketler gelir: resmin küçük parçaları için yapılan yorumlar, etiketlemeler. Örneğin bir harfi pikselleri yerine "şöyle bir çizgi, böyle bir çizgi" diye tarif etmek bölgesel etikete karşılık gelir. Tanıdığımız bir alfabede bu tarifler pek değişmez, ama hiç bilmediğimiz bir dildeki harfi tarif etmeye kalksak iki kişinin tarifi birbirinden farklı olabilir.

Slayttaki ilk örnek resim için bölgesel etiketler "yaşlı bir kadın, fakir bir kadın, bir çorba tenceresi tutuyor, gülümsüyor", tek bir etiket ise "mutluluk, şükran, ?" şeklindedir (ekrandan, 00:20:00). Hoca, resimdeki teyzeyi herkesin farklı birine benzetebileceğini, aklına farklı şeyler gelebileceğini; tek etiket olarak kimisinin huzur, kimisinin yaşlılık diyebileceğini söyledi. Veriden koptuğumuz anda kişiye özel olma başlar ve devam eder.

İkinci örnekte bölgesel etiketler "iki kilit, bir anahtar, bir eğik çizgi", tek etiket ise "gülen bir yüz"dür (ekrandan, 00:20:00). Hoca iki örnek arasındaki temel farkı şöyle gösterdi: İlk resimde parçalara (bölgesel etiketlere) bakarak bütünü tahmin edebiliriz. İkincisinde "iki kilit, bir anahtar, bir çizgi" bilgisinden gülen bir yüz çıkacağını tahmin etmek pek mümkün değildir. Burada bütün, parçaların toplamından daha fazla bir şeydir.

Bu durum makineler için de zordur. Mevcut görüntü işleme sistemleri çoğunlukla parçaları tanıyıp parçaların toplamı üzerinden ilerler. Parçaların toplamının bambaşka bir çıkış üretmesi gereken durumlar bu sistemleri zorlar.

## 3. Bilginin Özellikleri (Meta Bilgi)

Bilginin özellikleri, bilgi hakkındaki bilgilerdir, yani meta bilgidir. Örneğin "deniz seviyesinde su 100 derecede kaynar" bir bilgidir ve onun hakkında çeşitli sıfatlar söylenebilir. Slayttaki liste şöyledir (ekrandan, 00:25:00):

- Alan (özel - genel)
- Doğruluk (doğru - yanlış)
- Kesinlik (kesin - belirsiz)
- Doğrulanabilirlik / yanlışlanabilirlik (bilimsel bilgi - metafizik)
- Güncellik (güncel - eski)
- Tamlık (tam - eksik)
- Ekonomiklik (elde edilmesi, ondan beklenenden pahalı - değersiz)
- Yaygınlık (çokça bilinen - hiç bilinmeyen)

### 3.1 Kesinlik

Bir bilginin kesinliği temelde kaynağına bağlıdır. İnsanlardan gelen bilgileri düşünürsek, durmadan palavra atan birinden gelen bilgiye pek güvenmeyiz; çok güvendiğimiz birinden gelen bilgi ise kesin olabilir. Çok sayıda kişiden duyulan bilgi de daha güvenilir hale gelebilir.

Robot örneğinde sensörler bilgi kaynağıdır ve her birinin bir kesinlik kriteri vardır. Kameradan gelen görüntüler ortam şartlarına göre farklı kesinliktedir: düşük ışıkta değişimler daha rastgele, görüntü daha belirsizdir; yüksek ışıkta görüntü daha net ve güvenilirdir. Lazer sensörü ortamda yoğun nem ya da toz varsa sorun çıkarabilir. Ses sensörü ise lazere göre daha düşük kesinlikli bir sensördür.

### 3.2 Doğrulanabilirlik ve metafizik

Bilimsel bilgi laboratuvar ortamında doğru ya da yanlış olduğu test edilebilen bilgidir. Bugünkü teknoloji yetmiyorsa bile günün birinde o teknolojiye sahip olunacağı ve bilginin test edilebileceği düşünülür; laboratuvarda kontrollü deney yapılabilir. Hoca öğrencilere laboratuvarda test edilemeyecek bilgilere örnek sordu, cevap gelmeyince kendisi verdi: inanç ve din konusundaki bilgiler metafizik (fizik ötesi, doğa ötesi) bilgi türüne girer. Bunlar için kontrollü bir deney tasarlamak düşünülemez bile.

Hoca bir noktayı özellikle ayırdı: Bir bilgiye metafizik demek, onun doğru ya da yanlış olduğuna dair bir yargı değildir; yalnızca doğrulanabilir ya da yanlışlanabilir olmadığını söyler. Suyun deniz seviyesinde 100 derecede kaynaması test edilebilir bir bilimsel bilgidir.

### 3.3 Güncellik, tamlık ve ekonomiklik

Bir bilgi güncel ya da eski, tam ya da eksik olabilir. Ekonomiklik için hoca şu soruyu sordu: Bugün Türkiye'de kaç Fenerbahçeli var? Diyelim ki cevap 12.748.365. Bu bilgiyi bulmak düşünülebilir; örneğin herkesin aynı anda girdiği bir web uygulaması yapılabilir, ama bunu bütün Türkiye'ye yaymak birkaç milyon dolar gerektirebilir. Bu bilgi futbol kulüpleri gibi birçok kurum için değerli olabilir, ama sayıyı küsuratına kadar bilmenin ek bir faydası azdır. "Yaklaşık 12 milyon" ya da "yaklaşık 13 milyon" bilgisi çoğu amaç için yeterlidir ve çok daha ucuza elde edilir. Bir bilginin ekonomik olup olmaması, elde edilmesinin ondan beklenene göre pahalı ya da değersiz olmasına bağlıdır.

Bu soruyu ekonomik çözmenin yolu herkese sormak yerine daha küçük bir örneklem (ör. 100 kişi) üzerinde çalışmak ve sonucu 80 milyonluk nüfusa ölçeklemektir. Örneklem büyüdükçe gerçeğe daha iyi bir tahmin yapılır, ama maliyet de artar. Ayrıca örneklemin nerede seçildiği önemlidir: anket bir takımın stadının çevresinde yapılırsa o takımın taraftar oranı gerçeğinden yüksek, rakip takımın semtinde yapılırsa gerçeğinden düşük bulunabilir. Bilgiyi ekonomik hale getirirken bu da göz önünde bulundurulmalıdır.

### 3.4 Yaygınlık

Herkesin (ya da milyonda 999.999 kişinin) bildiği bilgiler vardır: insanların uykuya ihtiyacı vardır, gökyüzü mavidir, insanlar uçamaz, kuşlar uçar. Bunlara hayat bilgisi de denebilir ve bunları bilmek bütün insanların ortak özelliğidir. Öte yandan yalnız bir kişinin bildiği bilgiler de vardır: dün gece gördüğünüz rüyayı kimseye anlatmadıysanız onu yalnız siz bilirsiniz. Bilimsel tarafta da $E = mc^2$ bir zamanlar yalnızca onu bulan kişinin bildiği bir bilgiydi. Az bilinen ama önemli bir bilgiyi ilk ortaya çıkaran kişi olmak, bilim insanlarının en temel motivasyonlarından biridir.

## 4. Bilgi Gösterim Türleri ve Kurallar

Bilgisayarlarda bilginin gösterim türleri şunlardır (ekrandan, 00:35:00 sol panel): kurallar (rules), anlamsal ağlar (semantic net), yüklem mantığı (predicate logic), çerçeveler (frames), sahneler (scripts) ve yapay sinir ağları (YSA'lar).

İlk gösterim türü kurallardır. Bunlar herkesin bildiği `if-then` yapısıdır. Kurallarla ilişkiler, tavsiyeler ve direktifler ifade edilebilir. Slayttaki küçük örneklerden biri bir ilişki kuralıdır: "IF the 'fuel tank' is empty THEN the car is dead" (ekrandan, 00:35:00 sol panel). <!-- BELİRSİZ: Tavsiye ve direktif örneklerinin tam metni küçük önizlemede seçilemiyor; derste sözlü anlatılmadı. -->

Bu kısımda asıl kritik olan, kurallarla çıkarım yapmaktır. Hoca çıkarımı iki kez tekrarlayarak tanımladı:

> **Hocanın vurgusu:** Elinizdeki bilgileri kullanarak elinizde olmayan bir bilgiyi üretme sürecine çıkarım denir.

## 5. Kurallarla Çıkarım: İleriye ve Geriye Doğru Zincirleme

### 5.1 Kurallar ve gerçekler

"Kurallarla Çıkarım" slaydındaki bilgi tabanı şudur (ekrandan, 00:35:00):

```text
if A and C then E.
if D and C then F.
if B and E then F.
if B then C.
if F then G.
A.
B.
```

Slaytta dördüncü kural "if B than C" diye yazılmıştır; doğrusu "then"dir. İlk kural "A doğruysa ve C doğruysa E de doğrudur" diye okunur. Son iki satır ise doğrudan doğru olan gerçeklerdir (fact): A doğrudur, B doğrudur. Böylece elimizde kurallar ve gerçekler vardır; hoca bu yapının Prolog'dan hatırlanacağını söyledi.

Çıkarım için temel iki mekanizma kullanılır: geriye doğru zincirleme ve ileriye doğru zincirleme. Geriye doğru zincirlemede bir şeyin doğru olup olmadığı merak edilir, soru tek odaklıdır: "G doğru mudur?" İleriye doğru zincirlemede ise odak yoktur, "doğru olan her şeyi bana üret" denir: "Ne doğrudur?"

### 5.2 İleriye doğru zincirleme örneği

İleriye doğru zincirleme örneğinde iki kısım vardır. Üstteki database, şu an doğru olduğu bilinen şeylerdir: A, B, C, D, E. Alttaki knowledge base ise beş kuraldan oluşur:

```text
Y & D     -> Z
X & B & E -> Y
A         -> X
C         -> L
L & M     -> N
```

İleriye doğru zincirlemede herhangi bir anda birden fazla kural kullanılabilir olabilir, yani sol tarafı doğru olan birden fazla kural bulunabilir. Başlangıçta kurallar tek tek kontrol edilir:

- $Y \land D \to Z$: D doğru ama Y hakkında bilgi yok, uygulanamaz.
- $X \land B \land E \to Y$: B ve E var ama X yok, uygulanamaz.
- $A \to X$: A doğru, uygulanabilir.
- $C \to L$: C doğru, uygulanabilir.
- $L \land M \to N$: L ve M yok, uygulanamaz.

Bir kuralın kullanılmasına "ateşlenme" (fired) de denir. Diyelim ki $A \to X$ seçilip ateşlendi; bu anda database'e yeni bir doğru eklenir: X. Artık A, B, C, D, E'ye ek olarak X'in de doğru olduğu bilinir ve bu, uygulanabilecek kural sayısını artırır: $X \land B \land E \to Y$ artık kullanılabilir. Süreç böyle sürer; L, X, Y eklenir, Y ve D doğru olduğu için en son $Y \land D \to Z$ uygulanır ve Z eklenir. Bu noktada uygulanabilecek kural kalmaz: $L \land M \to N$ için L vardır ama M olmadığı için yapılacak bir şey yoktur. Süreç biter.

Sürecin bitmesi, ileriye doğru çıkarım mekanizmasının üretebileceği her şeyi ürettiği anlamına gelir. Başlangıçta A, B, C, D, E biliniyordu; şimdi bunlara ek olarak X, L, Y, Z bilgileri üretilmiştir. Slayttaki gösterimde bu adımlar döngüler halindedir (ekrandan, 00:40:00 sol panel):

```text
Döngü 1: A -> X ve C -> L ateşlenir      => X, L eklenir
Döngü 2: X & B & E -> Y ateşlenir        => Y eklenir
Döngü 3: Y & D -> Z ateşlenir            => Z eklenir
Sonuç database: A B C D E X L Y Z
```

Bu döngü sırası python ile simüle edilerek doğrulandı.

### 5.3 Geriye doğru zincirleme örneği

Geriye doğru zincirlemenin slayttaki tanımı şöyledir (ekrandan, 00:45:00):

- Hedef güdümlü akıl yürütmedir (goal-driven reasoning).
- Sistemin doğruluğunu aradığı bir hedefi vardır.
- Hedefler, alt hedeflere bölünerek kanıtlanmaya çalışılır.
- Tüm alt hedefler kanıtlandığında hedef de kanıtlanmış olur.

Aynı database ve knowledge base ile soru "Z doğru mudur?" olsun (ekrandan, 00:40:00):

- Pass 1, hedef Z: Z'yi veren kural $Y \land D \to Z$'dir. D doğrudur ama Y doğru değildir. Y doğrulanabilirse birinci kuraldan Z de doğrulanır. Hedef Z, alt hedef Y'ye çevrilir.
- Pass 2, alt hedef Y: Y için X, B, E doğru olmalıdır. B ve E bilinir, X bilinmez. Yeni alt hedef X olur.
- Pass 3, alt hedef X: $A \to X$ kuralı vardır ve A zaten doğrudur.
- Pass 4-6: Önce X eklenir, sonra Y, en sonunda Z eklenir.

Adın neden "geriye doğru" olduğu buradan görülür: önce hedeften geriye doğru alt hedeflere gidilir, sonra gerçeklere ulaşınca zincir ileri doğru sarılır.

### 5.4 "G doğru mu?" örneği

Hoca ardından 5.1'deki kural kümesinde "G doğru mudur?" sorusunu çözdü:

1. G'nin doğru olması için F'nin doğru olması gerekir ($F \to G$).
2. F'nin doğru olmasının iki şartı vardır: ya D ve C doğru olacak ya da B ve E doğru olacak.
3. D ve C doğru mu? Değil; ikisini birden doğrulamak daha zor görünür. B ve E yolundan gitmek daha kolay olabilir. B doğrudur, E değildir. E doğrulanırsa F doğrulanır; yeni alt hedef E'dir.
4. E için A ve C doğru olmalıdır. A zaten doğrudur; C bilinmez. Yeni alt hedef C'dir.
5. C doğru mu? $B \to C$ kuralı ve B'nin doğru olması nedeniyle evet.
6. Zincir geri sarılır: C doğru; C ve A doğru olduğundan E doğru; E ve B doğru olduğundan F doğru; F doğru olduğundan G doğrudur.

Sonuç: Bu bilgilere göre G doğrudur. "Ne doğrudur?" sorusunda ise aynı kurallar adım adım uygulanarak doğru olanların hepsi üretilir. Bu iki sorgu da python ile simüle edildi; ileriye doğru zincirleme A ve B gerçeklerinden sırayla C, E, F, G'yi üretir, geriye doğru zincirleme de D bulunamadığı için F'ye B ve E yolundan ulaşır.

## 6. İki Doktor: Mekanizmalar Birlikte

Hoca iki mekanizmayı bir senaryoyla karşılaştırdı. Üç gündür sabahları başınız ağrıyor ve doktora gidiyorsunuz.

**Doktor A:** Şikayetinizi soruyor, siz anlatıyorsunuz. Size bazı tahliller veriyor, yaptırıp getiriyorsunuz. Sonra bir iki tahlil daha veriyor, onları da yaptırıyorsunuz. Sonunda "sizin A hastalığınız var, tedavisi bu" diyor.

**Doktor B:** İçeri giriyorsunuz; size hiçbir şey sormadan, siz şikayetinizi anlatmadan tahlil listesindeki bütün tahlilleri işaretleyip veriyor. Hepsini yaptırıp getiriyorsunuz (muhtemelen uzun sürüyor). Sonra "sizin A hastalığınız var, tedavisi bu" diyor.

İkisi de bir çıkarım süreci gerçekleştirir. Birinci doktor söylediklerinize göre bir hipotez üretir: "Bu kişinin büyük ihtimalle şöyle bir hastalığı olabilir." Bunu doğrulamak için tahlil ister. Tahlil sonucuna bakıp "bu hastalık yok, galiba şu hastalık var" diyerek yeni bir hipotez üretir ve onu doğrulamak için yeni tahliller ister. Sonunda tahmini doğrulanır. Şikayetleri kullanarak hipotez üretme süreci ileriye doğru zincirlemenin, hipotezin doğru olup olmadığını kontrol etme süreci ise geriye doğru zincirlemenin bir örneği olarak düşünülebilir. Yani birinci doktor hem ileriye hem geriye doğru çıkarım yapar. İkinci doktor sizden hiçbir şey dinlemeden bütün sonuçları alır ve doğrudan ileriye doğru çıkarımla "neler doğrudur" diye ilerleyip sonucu söyler; geriye doğru çıkarım yapmaz.

**Soru:** Hangi doktoru tercih edersiniz, birincisinin avantajı nedir? **Cevap (bir öğrenci):** Birinci doktoru; arama uzayını küçülttüğü için daha kısa sürede cevap alınır. Hoca buna ek olarak birinci doktorun daha ucuz olduğunu söyledi; muayene ücreti anlamında değil, var olan bütün tahlilleri yaptırmanın toplam maliyeti anlamında.

**Soru:** İkinci doktorun, birincinin yapamayacağı neyi yapabilir? **Cevap (bir öğrenci):** Başka bir hastalık varsa onu da bulabilir. Hoca şöyle açtı: Henüz semptomları ortaya çıkmamış, rahatsızlığını hissetmediğiniz bir hastalığınız varsa birinci doktorun bunu yakalaması mümkün değildir, çünkü o sizin söylediklerinize göre ilerler. İkinci doktor ise bir nevi check-up yapar ve bir hastalığın ilk evrelerini de yakalayabilir.

Slayttaki genel kural (ekrandan, 00:45:00 sol panel, "Ne zaman hangisi kullanılmalı?"): Alan uzmanı önce bilgi toplayıp sonra olası sonuçları arıyorsa ileriye doğru zincirleme, önce hipotez üretip sonra bu hipotezin doğruluğunu araştırıyorsa geriye doğru zincirleme kullanılmalıdır.

## 7. Anlaşmazlık Kümesi ve Anlaşmazlığın Çözümü

İleriye doğru zincirlemede aynı anda birden fazla kuralın uygulanabildiği görüldü: 5.2'deki örnekte A ve C doğru olduğundan üçüncü ve dördüncü kuralın ikisi de uygulanabilirdi. Hoca orada bir sıra seçip önce yukarıdakini uyguladı. Peki bu seçim nasıl yapılmalıdır?

Slayttaki örnekte üç kural vardır; ikinci ve üçüncü kuralın sol kısımları aynı, sağ kısımları farklıdır: trafik ışığı kırmızıysa biri "dur", diğeri "geç" der (ekrandan, 01:05:00 sol panel). Böyle bir seçim bazı durumlarda hayati olabilir. Sol kısımların aynı olması, o anda bu kuralların hepsinin uygulanabilir olduğu anlamına gelir.

Database'deki bilgilere göre ateşlenebilecek kuralların oluşturduğu kümeye **çatışma / anlaşmazlık kümesi**, bu kümeden hangi kuralın ateşleneceğinin seçimine **anlaşmazlığın çözümü** denir. Slayttaki çözüm metotları şunlardır (ekrandan, 01:05:00):

- **Sıralama:** Kurallar önemliliklerine göre sıralanır; kümedekilerden en yukarıda yer alan ateşlenir.
- **Durumla eşleşme:** Duruma en çok uyan kural ateşlenir. Slayttaki örnek: A ve B doğru; kurallar `if A or B or C then X` ve `if A then Y`. Yukarıdaki durumda X gerçekleştirilir.
- **Güncellik:** Kurallardan en güncel olanı (bilgi tabanına en son ekleneni) ateşlenir.
- **Meta kurallar (kurallar hakkında kurallar):** Kuralın kaynağı (uzmanlık dereceleri) kuralın önceliğini belirler; insan hayatı ile ilgili kurallar diğer kurallardan yüksek önceliklidir.

Hoca durumla eşleşme ölçütünün iki türlü yorumlanabileceğini gösterdi. Birinci kural için elimizde birden fazla kanıt vardır (hem A hem B), ikinci kural için tek kanıt vardır; kanıt sayısına bakılırsa birinci kural seçilir (slayttaki seçim budur). Ama oran olarak bakılırsa birinci kuralın şartlarından üçte ikisi, ikinci kuralın ise birde biri (tamamı) elimizdedir; o zaman "olması gerekenin tamamı aşağıdakinde var" denip ikinci kural seçilebilir. Hangisinin seçileceği tamamen kullanılan stratejiye bağlıdır.

Güncellik de iki yönlü düşünülebilir. Semptomlara göre hastalık bulan, sürekli yeni kurallar eklenen tıbbi bir bilgi sistemi düşünelim. Bir açıdan en son eklenen kuralı kullanmak mantıklıdır. Öte yandan eski kurallar bugüne kadar defalarca kullanılmış, sorun çıkarmamış ve hâlâ tabanda duruyor demektir; bu da onların oldukça güvenilir olduğunu gösterir. Bu yüzden güncellik yerine eskilik ya da kuralın farklı vakalarda ne kadar çok kullanıldığı da ölçüt olabilir. Meta kurallarda ise kuralın kaynağı insan olabilir: bir yıllık bir doktorun yazdığı kural ile on yıllık bir doktorun yazdığı kural çatışırsa on yıllık doktora daha fazla güvenilebilir.

Sonuçta anlaşmazlığın çözümü, tasarımcının seçimlerine ve tercihlerine göre şekillenen, ama mutlaka yapılması gereken bir süreçtir.

## 8. Anlamsal Ağlar ve Hiyerarşik Bilgi

### 8.1 Anlamsal ağ nedir

Anlamsal ağ (semantic net), birbirine değişik tipte bağlarla bağlanmış bir küme düğümden oluşan yönlü bir graftır. Slayttaki örnekte Mary, St. Joe's, Person, Mammal, Head, Stanford gibi kavramlar vardır ve farklı ilişkilerle bağlanmışlardır: Mary, St. Joe's'a "hometown" ilişkisiyle, Person, Mary'ye "instance" ilişkisiyle, Person, Mammal'a "is-a" ilişkisiyle, Person, Head'e "has-part" ilişkisiyle bağlıdır. Anlamsal ağların popülerliğinin en büyük nedeni grafik gösterime çok uygun olmalarıdır. Örneğin "Sue ve Max'in 5 yaşında bir oğulları var; Sue ve Max'in ikisinin de yaşı 34" gibi bir bilgi böyle bir ağ içinde tutulabilir. <!-- BELİRSİZ: Altyazıda "Su ve Max" geçiyor; slayttaki adların yazımı kareden doğrulanamadı. -->

### 8.2 Hiyerarşik yapı ve çıkarım

Hiyerarşik yapılar bilgi çıkarımına oldukça uygundur. Slayttaki ağ şöyledir (ekrandan, 01:10:00):

```text
ANIMAL  : can Breathe, has Skin, can Move
  BIRD (is a ANIMAL) : can Fly, has Wings, has Feathers
    CANARY (is a BIRD)  : can Sing, is Yellow
    OSTRICH (is a BIRD) : cannot Fly, is Tall
  FISH (ANIMAL'a bağlı)
```

Slaydın altındaki not: "Bazı tür ilişkiler çıkarıma uygundur. Ör: is-a yollarında has ilişkileri."

Kanaryalar nefes alır mı, derileri var mı, hareket ederler mi, uçarlar mı, kanatları ve tüyleri var mı? Hepsine evet deriz; ama bu bilgilerin hiçbiri kanaryanın altına yazılmamıştır. Bazıları BIRD'ün, bazıları ANIMAL'ın altındadır. Hoca bu tasarımın ne sağladığını sordu. Bir öğrenci bunu sınıf mantığına benzetti: üstteki özellikler otomatik olarak alttakilere atanır, böylece daha fazla bilgi girişi yapmak gerekmez.

Hocanın açıklaması şöyleydi: Gerektiğinde çıkarılabilecek bilgileri veri tabanında tutmaya gerek yoktur. "Kanaryalar nefes alabilir", "papağanlar nefes alabilir", "serçeler hareket edebilir" gibi bilgiler veri tabanında hiç tutulmaz, çünkü istendiği anda çıkarım yoluyla erişilebilirler. Kuşlardan ve hayvanlardan gelen bütün özellikleri kanarya ve deve kuşu için ayrı ayrı tutmaya kalksaydık bilgi tabanı korkunç derecede hantal hale gelirdi. Çıkarım yapmadan her şeye erişebilirdik, ama bu çok etkin bir yapı olmazdı.

### 8.3 Ezberlemek mi, çıkarmak mı?

Bunun bir dengesi vardır. Çarpım tablosunu hepimiz ezbere biliriz. Aslında 7 kere 8'i, 7 tane 8'i ya da 8 tane 7'yi toplayarak çıkarımla da bulabiliriz. Neden ezberliyoruz? Bir öğrencinin dediği gibi, hızlı bulmamız gerektiği için. Çok sık yaptığımız bu kadar basit bir işi ezberlemek, refleks haline getirmek oldukça kazançlıdır. Nadiren yaptığımız şeyleri ise çıkarımla yapmak daha anlamlıdır; onları ezberlemek makul olmaz.

İnsanlarda da bilginin, çok kabaca, bu hiyerarşik yapıdaki gibi tutulduğu varsayılır. Hoca şu soruyu sordu: Bir kaplumbağanın sol ön bacağındaki hücrenin ribozomu var mıdır? Hepimiz evet deriz, oysa bugüne kadar böyle bir şey muhtemelen hiç duymadık. Bu bilgiyi gerektiğinde üretiriz: kaplumbağalar hayvandır, sol ön bacaklarındaki hücreler hayvan hücresidir, hayvan hücreleri de ribozoma sahiptir. Bu hiyerarşik düzen olmasaydı böyle bir soruya cevap vermemiz mümkün olmazdı.

## 9. Yüklem Mantığı ve Çerçeveler

### 9.1 Yüklem mantığı

Yüklem mantığı (predicate logic) ve oradaki çıkarım mekanizmaları, önceki dönem uzman sistemler dersini alanların Prolog yapısından hatırlayacağı konulardır. Hoca bu derste ayrıntısına girmedi.

### 9.2 Çerçeveler

Çerçeveler (frames), nesneye yönelik programlamanın yapay zekaya uyarlaması olarak düşünülebilir. Anlamsal ağlara benzerler: kavramlar vardır ve kavramlar çeşitli türde ilişkilerle birbirine bağlanır. Farkı, kavramların anlamsal ağlarda olmayan slotlara sahip olmasıdır. Slayttaki örnekte memeli, kuş, hayvan birer çerçevedir; altlarına "legs" (ayak sayısı), "flies" (uçabiliyor mu) gibi bilgiler konmuştur. Çerçeveleri kavramlar olarak düşünmek gerekir.

Slaytta temel yapı şöyle özetlenir (ekrandan, 01:15:00):

- Bir çerçevenin çeşitli öznitelikleri (slot) vardır.
- Bir özniteliğin çeşitli yuvaları (facets) olabilir.

Hocanın saydığı yuva türleri: değer, varsayılan değer, değer aralığı, değerin türü, o özniteliğe bir şey eklenince çalışacak prosedür (kontrol mekanizması), silinince çalışacak prosedür, önem katsayısı. Bir yuvanın değeri başka bir çerçeveye referans vermek için o çerçevenin ID'si de olabilir.

Bu yapı bir yandan nesneye yönelik programlamaya, bir yandan anlamsal ağlardaki mekanizmaya benzer. Anlamsal ağlardan en temel farkı, çerçeve olarak adlandırılan her kavramın içinde özniteliklerinin bulunmasıdır.

## 10. Sahneler

### 10.1 Basmakalıp olay dizileri

Bir diğer bilgi gösterim türü sahnelerdir (scripts): belli bir durumdaki basmakalıp bir olay dizisinin ifadesi. Lokantada yemek yemek, otobüse binmek, sinemaya gitmek, sınava girmek insanların bildiği sahnelerdir.

Hoca şu cümleyi verdi: "Ali bugün lokantaya gitti. Çıkışta da garsona yüklüce bir bahşiş verdi." Ardından sordu: Ali bugün lokantada yemek yemiş midir?

**Soru:** Ali yemek yemiş midir, bunu nereden biliyorsunuz? **Cevap (bir öğrenci):** Yemiştir; lokantada bir şey yemeden bahşiş vermeyeceğine göre yemiştir.

Hoca önemli noktanın şu olduğunu söyledi: Metnin içinde Ali'nin yemek yediğiyle ilgili hiçbir şey yazmaz, ama büyük ihtimalle yediğini tahmin edebiliriz. Roger Schank'ın açıklamasına göre insanların bu tür olaylar için kafalarında belli senaryolar, belli sahneler vardır. Bu sahnelerde belli olaylar belli sıralarda gerçekleşir. İnsanlar bu senaryoları zamanla öğrenir ve bir hikayenin duymadıkları parçasını bu senaryoları kullanarak doldururlar.

### 10.2 Sahnenin bileşenleri ve lokanta sahnesi

Bir sahnenin bileşenleri şunlardır: sahne ismi, başlama şartları (sahnenin ne zaman aktif olacağı), roller, nesneler, alt sahneler ve sonuçlar (sahneden çıktıktan sonraki durum). Lokanta sahnesinin alt sahneleri sırayla ilerler (ekrandan, 01:20:00):

- **Alt sahne 1, lokantaya giriş:** Müşteri lokantaya girer, boş yer arar, boş yeri görür, boş masaya gider, masaya oturur.
- **Alt sahne 2, sipariş:** Müşteri menüyü alır, menüyü okur, yiyecek kararını verir, garsonu çağırır, yiyeceği garsona söyler.
- **Alt sahne 3, yiyeceğin hazırlanması:** Garson siparişi aşçıya söyler, aşçı yemeği hazırlar, aşçı garsona haber verir.
- **Alt sahne 4, yemeğin yenmesi:** Garson yemeği müşteriye getirir, müşteri yemeği yer.
- **Alt sahne 5, lokantadan ayrılma:** Müşteri garsonu çağırır, garsondan hesabı ister, garson hesabı getirir, müşteri parayı verir, garson parayı kasiyere verir, müşteri lokantadan ayrılır.

### 10.3 Neden başarılı olamadı?

Hocanın hatırladığı kadarıyla bine yakın böyle sahne oluşturulmuş, ama gözlenmeyen olayları sahnelerle tahmin etme işi çok başarılı olamamıştır. Hoca nedenini sordu.

**Soru:** Bu yaklaşım neden başarılı olamamış olabilir? **Cevap (bir öğrenci):** Her insan farklı davranabilir, bu bilgiler çok genel kalır. Hoca bunu "insandan insana ve olaydan olaya varyasyonlar fazladır" diye özetledi ve doğru buldu.

Alt sahneler slayttaki sırayla gidebilir, ama çok farklı varyasyonlar da olabilir. Bütün olası varyasyonları yazmaya kalkınca belli bir noktadan sonra işin içinden çıkılamaz hale gelinmiştir; en genel olanı söylemek her zaman yetmez. Bu çalışmalar hayatın o kadar basmakalıp olmadığını, tahmin ettiğimizden çok daha fazla değişkenlik içerdiğini ortaya çıkarmıştır.

## 11. Kapalı Dünya ve Açık Dünya

**Kapalı dünya (closed world)** sistemlerinde sistemde olmayan bilgilerin yanlış olduğu kabul edilir. Örneğin bir sistemde "Alex'in Bob ve ... adlı çocukları vardır" bilgisi varsa, Alex'in sisteme girilmemiş çocukları yok sayılır ve sistem "Alex'in iki çocuğu vardır" sonucuna varabilir. <!-- BELİRSİZ: Örnekteki ikinci çocuğun adı altyazıda bozuk ("Becey"), slayt küçük önizlemede okunamıyor. -->

**Açık dünya (open world)** sistemlerinde sistemde olmayan bilgilerin eksik ya da yanlış olabileceği varsayılır; kesinlikle yanlıştır denmez. Aynı örnekte açık dünya varsayımıyla "Alex'in yalnızca iki çocuğu vardır" sonucuna ulaşılamaz; en fazla "en az iki çocuğu vardır" denebilir.

Hoca bilgisayarı çıkarım yapmak üzere programlamak için hangisinin daha kolay olduğunu sordu: Kapalı dünya çok daha basittir; açık dünyada çıkarım yapmak çok daha zordur. Ama hepimiz açık dünya sistemlerinde yaşıyoruz; kapalı dünya sistemlerine örnek olarak belki oyunlar düşünülebilir.

## 12. Yapay Sinir Ağlarında Bilgi Temsili

### 12.1 Bilgi ağırlıklarda saklanır

Slayt "Yapay Sinir Ağlarında Bilgi Temsili - Vektörler" başlığını taşır (ekrandan, 01:25:00):

- Tüm bilgi ağda saklanır.
- Ağın yapısı ve ağın ağırlıkları bilgiyi depolar.
- Tek / çok katmanlı ağlar.
- Özyinelemeli ağlar (önceki girişlere göre de işlem yapar).

Hoca konuşmayı metne çeviren bir program örneği verdi (Google'ın Speech API'si gibi). Bu program ses sinyallerini bir metne eşleyen (map eden) bir fonksiyondur. Bu fonksiyonun içinde "şöyle bir sinyal seviyesi varsa a harfini yaz" gibi bizim anlayabileceğimiz açık kurallar yoktur. Eşleme bilgisi ağın yapısında ve ağırlıklarında saklıdır. İnsan beyninde de bilginin temelde böyle, beynin ağ yapısında ve ağırlıklarında saklandığı düşünülür; hoca bunun çok basitleştirilmiş bir ifade olduğunu, ama kabaca doğru sayılabileceğini söyledi.

### 12.2 TensorFlow Playground gösterimi

Hoca tarayıcıda TensorFlow Playground'u açtı. Ekrandaki problem iki sınıflı bir sınıflandırma problemidir: veriler sarılar ve maviler diye ayrılmak istenir. Giriş iki boyutludur (yatay ve dikey eksen). Girişler bir yapay sinir ağına verilir; ağın çıkışı, hangi bölgenin hangi sınıfa ait olma olasılığının daha yüksek olduğunu renklerle gösterir. Ağdaki bağlantılar ağırlıklardır.

Yapay sinir ağının eğitimi, bir veri kümesinde "şöyle bir giriş gelirse şöyle bir çıkış olsun" bilgisine göre, bu eşlemeyi doğru yapacak ağırlıkları bulma, yani ağırlıkları güncelleme sürecidir. Hoca eğitimi başlatıp durdurarak gösterdi: başlangıçta kararlar belirsizdir; eğittikçe ağırlıklar değişir ve kararlar oluşur. Ağın yapısı aynı kalmıştır, değişen yalnızca ağırlıklardır. Sarıları mavilerden ayırmaya yarayan bütün bilgi bu ağırlıklarda ve ağın mimarisinde depolanmıştır.

Daire şeklindeki veri kümesinde ekrandaki ayarlar şunlardır: öğrenme oranı 0.03, aktivasyon tanh, regülarizasyon yok, girişler $X_1, X_2$, 2 gizli katman (4 ve 2 nöron). 53. epokta eğitim kaybı 0.032, test kaybı 0.044'tür ve mavi daire turuncu halkadan ayrılmıştır (ekrandan, 01:30:00).

Hoca aynı mekanizmanın nesne tanımada da geçerli olduğunu anlattı. Giriş bu kez resmin kendisidir; resim $n \times m$'lik bir matristir. Örneğin $100 \times 100$'lük bir resim on bin boyutlu uzayda bir noktaya karşılık gelir; yani iki giriş yerine on bin giriş vardır. Çıkışta da tanınmak istenen nesne sınıfı sayısı kadar (ör. bin) çıkış olur. Mekanizma tamamen aynıdır: belli girişlere belli çıkışları üretecek şekilde aradaki katmanların ağırlıkları öğrenilir.

Ardından hoca daha zor bir problem, spiral veri kümesini denedi. Başlangıçtaki yapıyla ağ öğrenemedi. Aktivasyonu ReLU yapmak işe yaramadı; katman sayısını artırmak da yavaş ilerledi. Hoca buradan şu sonucu çıkardı: Her problemin zorluğu aynı değildir. Bu problemi çözmek için ek girişler eklemenin makul olacağını düşündü ve girişin çeşitli varyasyonlarını ekledi. Bir ara iyi bir sonuç yakalanıp kaçırıldı, sonunda istenen ayrım oluşunca eğitim durduruldu. Ekrandaki son ayarlar: aktivasyon ReLU, girişler $X_1, X_2, X_1^2, X_2^2, X_1X_2, \sin(X_1), \sin(X_2)$, 4 gizli katman (4, 2, 2, 2 nöron); 854. epokta test kaybı 0.042, eğitim kaybı 0.046 (ekrandan, 01:35:00). Hoca sonuçta hâlâ hatalı bölgeler bulunduğunu, ama bunun zor bir problem olduğunu söyledi.

Başlangıçta ağın içinde hiçbir şey yoktur; saçma sapan tahminler yapan bir sistem vardır. Eğitildiğinde doğru tahminler yapabilen bir hale gelir. Bu her zaman kolay, hatta her zaman mümkün değildir; yeterince büyük bir ağla her fonksiyona yaklaşılabilir, ama test başarısı o kadar iyi olmayabilir.

> **Ek bilgi (derste anlatılmadı):** Hocanın değindiği "yeterince büyük bir ağ her fonksiyona yaklaşabilir" fikri, literatürde evrensel yaklaşım teoremi (universal approximation theorem) olarak bilinir: tek gizli katmanlı, yeterli sayıda nörona sahip bir ağ, kapalı ve sınırlı bir bölgede tanımlı sürekli bir fonksiyona istenen doğrulukta yaklaşabilir. Teorem eğitim verisine uymayı garanti eder; test verisinde iyi genelleme yapacağını söylemez.

## 13. Doğal Dil İşlemede Bilgi Gösterimi

### 13.1 Kelimeler string değil, vektör

Klasik yaklaşımlarda, programlama dillerinde kelimeler string (karakter dizisi) olarak kullanılır. İki kelimenin karşılaştırılması ancak sentaktik, yani şekilsel seviyede yapılabilir; stringler üzerinden anlamsal karşılaştırma yapılamaz. Örneğin "Galatasaray yendi" ile "Cimbom kazandı" karakter bazında hiçbir ortak yönü olmayan, ama anlamca aynı şeyi söyleyen iki ifadedir.

Bunların benzer olduğunu yakalamak için kelimeler bir anlamsal uzayda vektörlerle temsil edilir. Bu uzayda anlamca birbirine yakın kelimelerin vektörleri de birbirine yakındır. Böylece "Cimbom" ile "Galatasaray"ın, "kazanmak" ile "yenmek"in vektörleri benzer olur ve iki metnin benzer olduğu çıkarılabilir.

### 13.2 Word2vec: skip-gram ve CBOW

Kelime vektörlerini bulmak için 2013'te Word2vec yaklaşımı çıktı; fastText onun küçük bir modifikasyonudur. Slayttaki bilgiler (ekrandan, 01:40:00):

- Word2vec (2013, T. Mikolov ve ark., "Distributed representations of words and phrases and their compositionality"), fastText (2017, P. Bojanowski ve ark., "Enriching word vectors with subword information").
- Tek gizli katmana sahip bir yapay sinir ağıdır.
- $C=2$ için bağlam $= (w_{t-2}, w_{t-1}, w_t, w_{t+1}, w_{t+2})$.
- Skip-gram: giriş $w_t$; çıkış $(w_{t-2}, w_{t-1}, w_{t+1}, w_{t+2})$'nin her biri.
- CBOW: giriş $(w_{t-2}, w_{t-1}, w_{t+1}, w_{t+2})$'nin her biri; çıkış $w_t$.

$C=2$, pencerenin yarı büyüklüğüdür: ortadaki kelimenin iki solundaki ve iki sağındaki kelimeler bir pencere oluşturur. Skip-gram ortadaki kelimeyi verip çevresindekileri, CBOW çevresindekileri verip ortadakini tahmin etmeye çalışır. Böylece "şu kelime geldiğinde şu kelime çıksın" biçiminde bir eğitim kümesi kurulur ve ağın bunu öğrenmesi sağlanır.

Bu ağdaki sınıf sayısı, sözlükteki kelime sayısı kadardır. $V$ sözlüktür (vocabulary): elimizdeki derlemdeki bütün kelimelerin tekil hale getirilmiş listesi. Çıkışta bir kelime tahmin edildiği için sınıf sayısı sözlük büyüklüğüne denk gelir ve rahatlıkla on binler, yirmi binler civarında olabilir. Bu algoritmalar kelimeler arasındaki anlamsal ilişkileri iyi öğrenebilsin diye genelde büyük hacimli metinler üzerinde çalıştırılır; 100 MB'lık Türkçe bir veride en az 50-60 bin farklı kelime çıkar. Bunların hepsini almak zorunlu değildir; örneğin frekansı belli bir eşiğin (ör. 5) üstünde olanlar alınarak sözlük küçültülebilir, ama sonuçta yine 10-20 bin civarında bir sözlükten söz edilir.

Slayttaki skip-gram modeli şöyledir (ekrandan, 01:40:00):

```text
Input layer          Projection layer        Output layer
1-hot input vector   embedding for w_t       probabilities of context words
     1 x |V|   --W(|V| x d)-->   1 x d   --C(d x |V|)-->   1 x |V|
```

Giriş sözlük boyutunda bir vektördür, çıkış da aynı boyuttadır. Aradaki matrisler nöronlar arasındaki ağırlıklardır. Temel fikir, kelime vektörlerinin ağın içindeki ağırlıklardan oluşmasıdır. $W$ matrisi $|V| \times d$ boyutludur; $d$ her kelimenin kaç boyutlu uzayda temsil edileceğini gösterir. Hoca pratikte $d$'nin genelde 300 civarında kullanıldığını, 50'nin altına pek rastlanmadığını, çünkü varyansı içerebilmek için yetmediğini söyledi. Eğitim sonunda her kelime için $d$ boyutlu bir vektör elde edilir ve istenildiği gibi kullanılabilir.

### 13.3 Metin temsili

Kelimeler temsil edildi; metinler nasıl temsil edilecek? Slayttaki iki yol (ekrandan, 01:45:00):

- **İçerdiği kelimelerin ortalaması:** Metindeki kelimelerin vektörlerinin ortalaması alınarak metnin vektörü bulunur. Üç kelimelik bir metinde üç kelime vektörünün ortalaması metnin vektörüdür.
- **Encoder-decoder mimarileri (seq2seq türü problemler için):** Girişin de çıkışın da dizi (sekans) olduğu problemlerde kullanılır: A dilinden B diline çeviri, chatbot, müşteriye cevap veren asistan. Müşterinin söylediği bir dizidir, karşılık olarak sizin de bir dizi üretmeniz gerekir; İngilizce bir ifadeyi Türkçeye çevirmek de böyledir.

Encoder-decoder yapılarında temelde özyinelemeli (rekürsif) yapay sinir ağları, yani LSTM'ler ve GRU'lar kullanılır. Slayttaki örnekte LSTM encoder "How are you <EOL>" dizisini okur ve metnin temsili bir $W$ vektöründe toplanır. LSTM decoder yalnızca bu vektörü alarak "I am fine <EOL>" dizisini üretir (ekrandan, 01:45:00). Burada da ne söylendiğinde ne söyleneceği, ya da bir cümlenin İngilizcesinin nasıl üretileceği bilgisinin tamamı ağın ağırlıklarında ve mimarisinde saklıdır. Bu temsillerde anlamsal ağlar gibi açık yapılar yoktur.

## 14. Görüntü İşlemede Bilgi Gösterimi

Görüntü işlemedeki slayt, dersin başındaki veriden bilgiye geçişe benzer. CNN'lerde en alt katmanda (Layer 1) her türlü resim için geçerli olabilecek çok basit özellikler vardır: siyahlık, beyazlık ve çizgilerin açıları. Bunlar çeşitli kombinasyonlarla birleşerek daha büyük parçaları oluşturur: kaş, göz, burun gibi. Daha üst katmanlarda bu parçalar birleşerek yüzleri oluşturur. Yani hiyerarşik bir yapı vardır.

Hoca bunu yüz tanıma uygulamasıyla açtı: kameraya yüzünüzü gösterirsiniz ve sistem "hoş geldiniz Ahmet Bey" der ya da kapıdan geçip geçemeyeceğinizi söyler. Ahmet'i, Mehmet'i, Ayşe'yi tanımak için en alt seviyedeki değerlerde kişiye özel bir şey yoktur. Onun üstünde kişiye özel şeyler yavaş yavaş oluşmaya başlar ("şu kişinin gözü" gibi), en sonunda yüzlerin tamamı daha yüksek seviyedeki katmanlarda oluşur ve kişi kontrolü bu şekilde yapılır.

Hoca yapay sinir ağlarını burada birkaç slaytta yalnızca genel kültür olarak anlattığını, bunun bölümde ayrı bir ders, hatta alt kırılımlarıyla birkaç ders olabilecek bir konu olduğunu ve 2012'den beri yükselişinin sürdüğünü belirtti. Gösterdiği web sitesinde dinamikleri daha iyi görmek için denemeler yapılabilir.

## 15. Çıkarım Türleri: Tümdengelim, Abduction, Tümevarım

### 15.1 Çıkarım neyi yapar

Çıkarım, eldeki verilerle elde olmayan veriyi üretme sürecidir. Çıkarım mekanizması iki şey yapabilir: kendi bilgi tabanını kullanarak yeni bilgiler üretebilir (ileriye doğru zincirleme) ve verilen bir bilginin kendi bilgi tabanına göre doğru olup olmadığını söyleyebilir (geriye doğru zincirleme). Çıkarım mekanizmaları farklı ölçütlere göre sınıflandırılabilir; ileri / geri bunlardan biridir. Bu bölümde başka bir sınıflandırma görüldü.

### 15.2 Üç tür

Slayttaki "Çıkarım Türleri" (ekrandan, 02:05:00):

| Tür | Tanım | Örnek | Biçim |
|---|---|---|---|
| Tümdengelim (Deduction) | Sebeplerden sonuca | Bu kutudaki tüm toplar siyahtır. Bu toplar bu kutudandır. → Bu toplar siyahtır. | $A \Rightarrow B$, $A$; sonuç $B$ |
| Abduction | Sonuçtan olası sebebe | Bu kutudaki tüm toplar siyahtır. Bu toplar siyah. → Bu toplar bu kutudandır. | $A \Rightarrow B$, $B$; sonuç possibly $A$ |
| Tümevarım (Induction) | Örneklerden olası kurala | Bu toplar bu kutudandır. Bu toplar siyah. → Bu kutudaki tüm toplar siyahtır. | Whenever $A$ then $B$; sonuç possibly $A \Rightarrow B$ |

Abduction için slayttaki kaynak: Charles Peirce, "Reasoning and the Logic of Things", Harvard University Press.

**Tümdengelim:** Kutudaki bütün topların siyah olduğunu biliyoruz. Elimizi kutuya sokup bir top çıkarıyoruz; bu top bu kutudandır. Bu iki bilgi doğruysa "bu top siyahtır" kesinlikle doğrudur.

**Tümevarım:** İçini görmediğimiz bir kutudan bir top çekiyoruz, siyah; bir daha, yine siyah. Bunu yüz kere tekrarlıyoruz ve "bu kutudaki tüm toplar siyahtır" diyoruz. Hoca bunun kesin olup olmadığını sordu.

**Soru:** Bu kesin midir? **Cevap (bir öğrenci):** Kutudan bütün topları çıkarmışsak kesinlikle doğrudur. Hoca: Bütün topları çıkarmadınız; kutuda bir milyon top var, siz yüz tanesini seçtiniz. O zaman kesinlikle diyemeyiz, bu bir ihtimaldir. Tümdengelimde ise kesinlik vardır.

Tümevarım örneklerden olası bir kurala geçiştir; adında da "olası" vardır. Bugüne kadar gördüğünüz bütün inekler pembe olsaydı "inekler pembedir" derdiniz. Dünyadaki bütün inekleri görmeden de inekler hakkında bir fikir edinebilirsiniz, ama bu kesin değil, olasılıklıdır. Kesinlikle bilebileceğimiz şeyler çok azdır.

**Abduction:** Kutudaki bütün topların siyah olduğunu biliyoruz. Kutunun içinde değil, yanında da birkaç siyah top görüyoruz ve "bu toplar bu kutudan düşmüş" diyoruz. Bir öğrencinin dediği gibi bu da kesin değildir. "A doğruysa B doğrudur" kesin olarak biliniyor, B'nin doğru olduğu görülüyor ve "büyük ihtimalle A da doğrudur" deniyor. Üç tür içinde yalnızca tümdengelim kesinlik içerir.

> **Hocanın vurgusu:** İleriye ve geriye doğru zincirlemede yaptığımız şeylerin hepsi tümdengelim tarzındaki, kesinlik içeren çıkarımlardı. Olasılık içeren çıkarımlar işin içine girince farklı mekanizmalar gerekir.

### 15.3 Abduction ile tümevarımın farkı

Ders sonunda bir öğrenci abduction ile tümevarım (induction) arasındaki farkı yeniden sordu.

**Soru:** Abduction ile induction'ın farkı nedir? **Cevap:** Tümevarımda kutudan içine bakmadan top çekersiniz, hep siyah çıkar ve "büyük ihtimalle bu kutudaki bütün toplar siyahtır" dersiniz; yani bir **kural** tahmin edersiniz. Abduction'da ise doğru olduğunu bildiğiniz bir kural vardır ($A \Rightarrow B$) ve B'nin doğru olduğunu görürsünüz; kutunun yanındaki siyah toplar için "bu toplar bu kutudan gelmiş" dersiniz. Burada kural üretilmez; olasılıkla bir **olgu** (fact) üretilir. İkisi de olasılık içerir, ama biri kural, öteki olgu üretir. Abduction biçimce tümdengelime daha çok benzer: tümdengelimde $A \Rightarrow B$ ve A'dan B kesin çıkar; abduction'da $A \Rightarrow B$ ve B'den A büyük ihtimalle çıkar.

Hoca bunu yağmur örneğiyle somutlaştırdı: Yağmur yağınca yerler (toprak) ıslanır. Dışarı çıktınız, yağmurun yağdığını görmediniz ama yerler ıslak; "büyük ihtimalle yağmur yağdı" diyorsunuz. Bu abduction'dır. Öte yandan yağmurun yağdığını ve yerlerin ıslandığını defalarca görüp "ne zaman yağmur yağsa yerler ıslanıyor" diyorsanız, bu tümevarımdır.

## 16. Çıkarım Örnekleri ve Belirsizlik Kaynakları

### 16.1 Slayttaki örnekler

"Çıkarım Örnekleri" slaydındaki örnekler (ekrandan, 02:10:00 ve 02:15:00) derste tek tek tartışıldı; her birinde "bu sonuç kesin mi?" diye soruldu.

1. Kediler memelidir. Memeliler hayvandır. → Kediler hayvandır. Kesindir.
2. Yaşamak için havaya ihtiyacın var. Uzayda hava yok. → Uzayda yaşayamazsın. Bir öğrenci "koşullar oluşturulursa uzayda da yaşanabilir" diyerek kesin olmadığını söyledi. Hoca: İki öncülün de kesinlikle doğru olduğu durumdan söz ediyoruz. Yanınızda hava götürürseniz "uzayda hava yok" öncülü doğru olmaz; öncülleri değiştirirseniz her şey değişir. İkisi doğru olduğunda sonuç kesinlikle doğrudur.
3. Kapıyı itmek kapıyı açar. Ali kapıyı itti. → Ali kapıyı açtı. Kesindir. Gerçek hayatta kapı kilitli olabilir, açılmayabilir; ama "kapıyı itmek kapıyı açar" doğru kabul edilirse sonuç da doğrudur.
4. Ali şu an araba kullanıyor. → Ali'nin ehliyeti var. → Ali'nin arabası var. İkisi de kesinlikle söylenemez; yalnızca olasılıkla ("büyük ihtimal", "umarız") söylenebilir.
5. X'in A, B, C'sinin olduğunu biliyorum. Y'nin B, C'sinin olduğunu biliyorum. → Y'nin A'sı olabilir. Bir öğrenci örnek verdi: arabanın tekeri, kapısı ve direksiyonu var; başka bir aracın direksiyonu ve kapısı varsa tekeri de olabilir.
6. Gördüğüm A'ların B'si var. → Tüm A'ların B'si var. Örneğin gördüğüm inekler morsa bütün inekler mordur demek. Bu tümevarımdır.
7. Ali 1971'de attan düştü. → Ali 1972'de attan düşmedi, diyebilir miyiz? Diyemeyiz; 71'de düştüyse 72'de neden düşmesin?
8. Ali 1971'de öldü. → Ali 1972'de attan düşmedi, diyebilir miyiz? Bir öğrenci "diyebiliriz" dedi, hoca da katıldı.

Hoca 7 ve 8 arasında sentaktik olarak büyük bir fark olmadığını, farkı anlamın yarattığını belirtti. Yine de insan aklı istisna üretmekte sınırsızdır: önceki yıllarda bir öğrenci şöyle bir senaryo uydurmuştu. Ali 31 Aralık 1971'de saat 23.55'te atın üzerindeyken kalp krizi geçirip ölür; at acıkıp yürümeye başlar, bu arada 1972'ye girilir ve Ali attan düşer. Genel olarak düşünüldüğünde yine de Ali'nin 1972'de attan düşmediği söylenebilir.

Slaytta 9. madde olarak Peirce'ün abduction tanımı da yer alır: "The surprising fact, C, is observed. But if A were true, C would be a matter of course. Hence, there is reason to suspect that A is true." Bu madde derste ayrıca tartışılmadı.

### 16.2 Kopya örneği

Sonraki slaytta "X bugün kopya çekerken yakalandı" bilgisinden hangi sonuçların kesinlikle, hangilerinin büyük ihtimalle doğru olduğu soruldu. Derste örnek kişinin adı da Ali olarak kullanıldı:

- Ali öğrencidir: Kesin diyemeyiz; bir sınava girmek için illa öğrenci olmak gerekmez.
- Ali bugün en az bir sınava girmiştir: Kopya çekmek mutlaka sınavla ilişkilendirilirse evet; başka bir faaliyette kopya çekilebiliyorsa belki.
- Ali bugün okula gitmiştir: Şart değil. (Hoca bu slaytların pandemi öncesinden kaldığını belirtti.)
- Ali dün çok ders çalışmamıştır: Kopya çektiğine göre çalışmamış olabilir, ama belli olmaz.
- Ali bugün bir sırada oturmuştur: Olabilir.
- Ali dersten kalacak mı: <!-- BELİRSİZ: Hocanın bu maddeye cevabı altyazıda "Kesinlikle." diye geçiyor; kesin mi, kesin değil mi dediği net değil. -->
- Ali bugün üzülmüş müdür: Bir ihtimal; yakalanmaya çok alışkınsa belki üzülmeyebilir.
- Ali'nin midesi vardır, annesi vardır: Kesinlikle.

Hoca bazı sonuçların olasılıklı, bazılarının kesin olmasının arkada kullanılan çıkarım mekanizmasının türünden kaynaklandığını söyledi: tümevarım ya da abduction kullanılıyorsa olasılıkla bir şey söylenir; tümdengelim tarzında çıkarım yapılıyorsa kesinlik içeren sonuçlara varılır.

### 16.3 Tweety örneği

Bir sonraki slayttaki örnek: "Tüm serçeler kuştur. Tüm kuşlar uçabilir. Tweety uçamaz." Bunlar doğru kabul edildiğinde "Tweety serçe midir?" ve "Tweety uçabilseydi ona serçe diyebilir miydik?" soruları düşünülecek sorular olarak bırakıldı; derste çözülmedi (bkz. Örnek Sorular).

### 16.4 Belirsizlik kaynakları

Belirsizlik, olası olma durumudur. Slayttaki kaynaklar şunlardır:

- Girişlerin eksik olması
- Bir sebebin çok sayıda sonucunun olması
- Bir sonucun çok sayıda sebebinin olması
- Olasılıkla ortaya çıkmak
- Tümevarım ve abduction kullanmak
- Rasyonel davranış (bu oyunlar konusunda görülmüştü)

Slaydın sonunda tümevarımla ilgili bir alıntı bulunur; hoca bunun akılda tutulmasını önerdi. <!-- BELİRSİZ: Alıntının metni ve kime ait olduğu (altyazıda "Mahatma Gandhi" geçiyor) kareden doğrulanamadı. -->

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): Kurallar `if A and C then E`, `if D and C then F`, `if B and E then F`, `if B then C`, `if F then G` ve gerçekler `A`, `B` veriliyor. Geriye doğru zincirlemeyle G doğru mudur? İleriye doğru zincirlemeyle neler doğrudur?

> **Çözüm (derste verildi):** G ← F. F için (D ve C) ya da (B ve E) gerekir. D bilinmediği için B ve E yolu seçilir; B doğru, E alt hedef olur. E ← A ve C; A doğru, C alt hedef olur. C ← B ve B doğru. Zincir geri sarılınca C, E, F, G doğru bulunur: G doğrudur. İleriye doğru zincirlemede A ve B'den sırayla C, E, F, G üretilir (python ile doğrulandı).

**Soru 2** (ekrandan, 00:40:00): Database A, B, C, D, E; knowledge base $Y \land D \to Z$, $X \land B \land E \to Y$, $A \to X$, $C \to L$, $L \land M \to N$. İleriye doğru zincirlemeyle hangi yeni bilgiler üretilir? Geriye doğru zincirlemeyle Z doğru mudur?

> **Çözüm (derste verildi):** İleriye doğru: döngü 1'de X ve L, döngü 2'de Y, döngü 3'te Z eklenir; N eklenemez çünkü M yoktur. Yeni bilgiler X, L, Y, Z. Geriye doğru: hedef Z → alt hedef Y → alt hedef X; X, A'dan doğrulanır, ardından Y ve Z eklenir. Z doğrudur (python ile doğrulandı).

**Soru 3** (ekrandan, 01:05:00): A ve B doğruyken `if A or B or C then X` ve `if A then Y` kuralları anlaşmazlık kümesindedir. "Durumla eşleşme" stratejisinde hangisi ateşlenir?

> **Çözüm (derste verildi):** Slayttaki seçime göre X gerçekleştirilir, çünkü birinci kural için iki kanıt (A ve B), ikinci kural için bir kanıt vardır. Hoca eşleşme oranına bakılırsa (birincide 2/3, ikincide 1/1) ikinci kuralın da seçilebileceğini, kararın stratejiye bağlı olduğunu söyledi.

**Soru 4** (derste sözlü, 00:46:00): Şikayeti dinleyip adım adım tahlil isteyen doktor ile hiçbir şey sormadan bütün tahlilleri isteyen doktor hangi çıkarım mekanizmalarını kullanır? Her birinin avantajı nedir?

> **Çözüm (derste verildi):** Birinci doktor şikayetlerden hipotez üretir (ileriye doğru) ve hipotezi tahlille doğrular (geriye doğru); daha hızlı ve toplamda daha ucuzdur. İkinci doktor yalnız ileriye doğru çıkarım yapar; henüz belirtisi olmayan hastalıkları da yakalayabilir.

**Soru 5** (derste sözlü, 01:17:16): "Ali bugün lokantaya gitti. Çıkışta garsona yüklüce bir bahşiş verdi." Ali lokantada yemek yemiş midir, bu sonuca nasıl varılır? Sahne yaklaşımı neden çok başarılı olamamıştır?

> **Çözüm (derste verildi):** Metinde yazmasa da Ali büyük ihtimalle yemek yemiştir; bu sonuç, kafadaki lokanta sahnesinin (giriş, sipariş, hazırlama, yeme, ayrılma) eksik parçayı doldurmasıyla elde edilir. Yaklaşım, olayların insandan insana ve olaydan olaya çok fazla varyasyon göstermesi nedeniyle başarılı olamamıştır.

**Soru 6** (ekrandan, 02:10:00): Aşağıdaki çıkarımlardan hangileri kesindir?
(1) Kediler memelidir, memeliler hayvandır → kediler hayvandır. (2) Yaşamak için havaya ihtiyacın var, uzayda hava yok → uzayda yaşayamazsın. (3) Kapıyı itmek kapıyı açar, Ali kapıyı itti → Ali kapıyı açtı. (4) Ali şu an araba kullanıyor → Ali'nin ehliyeti var / arabası var. (5) X'in A, B, C'si, Y'nin B, C'si var → Y'nin A'sı olabilir. (6) Gördüğüm A'ların B'si var → tüm A'ların B'si var. (7) Ali 1971'de attan düştü → 1972'de attan düşmedi. (8) Ali 1971'de öldü → 1972'de attan düşmedi.

> **Çözüm (derste verildi):** 1, 2 ve 3 öncüller doğru kabul edildiğinde kesindir (tümdengelim). 4, 5, 6 ve 7 kesin değildir. 8'de anlam devreye girer ve büyük ihtimalle "düşmedi" denebilir; yine de hoca uç bir istisna senaryosunun kurulabildiğini gösterdi.

**Soru 7** (derste sözlü, 02:19:01): Abduction ile tümevarım (induction) arasındaki fark nedir? Yağmur ve ıslak yer üzerinden açıklayın.

> **Çözüm (derste verildi):** İkisi de olasılıklıdır. Tümevarım örneklerden bir kural üretir (yağmur her yağdığında yer ıslanıyor → yağmur yağınca yerler ıslanır). Abduction bilinen bir kurala ($A \Rightarrow B$) ve gözlenen sonuca (B) dayanarak olası sebebi, yani bir olguyu üretir (yerler ıslak → büyük ihtimalle yağmur yağdı).

**Soru 8** (derste sözlü, 02:17:41): Tüm serçeler kuştur. Tüm kuşlar uçabilir. Tweety uçamaz. Bunlar doğruysa Tweety serçe midir? Tweety uçabilseydi ona serçe diyebilir miydik?

> **Çözüm (derste verilmedi):** Tweety serçe olsaydı, birinci öncülden kuş, ikinci öncülden uçabilir olurdu; bu, "Tweety uçamaz" öncülüyle çelişir. Dolayısıyla Tweety serçe değildir ve bu sonuç kesindir (tümdengelim türünde bir çıkarım). Tweety uçabilseydi ise "serçeler uçar" kuralından ve gözlenen sonuçtan sebebe gitmek gerekirdi; bu abduction olur ve en fazla "Tweety serçe olabilir" denebilir, kesinlikle denemez.

## Dersin Toparlaması

Bu derste bilginin ne olduğu sorusundan başlayıp bilgisayarda nasıl gösterildiğine ve onunla nasıl çıkarım yapıldığına gelindi. Bilmenin seviyeleri, veriden bilgiye üçgeni ve bilginin meta özellikleri (kesinlik, doğrulanabilirlik, ekonomiklik, yaygınlık vb.) tanıtıldı. Ardından gösterim türleri sırayla görüldü: `if-then` kuralları ve onlarla ileriye / geriye doğru zincirleme, anlaşmazlık kümesinin çözüm stratejileri, kalıtıma dayalı çıkarıma uygun anlamsal ağlar, öznitelik ve yuvalara sahip çerçeveler, basmakalıp olay dizileri olan sahneler, kapalı ve açık dünya varsayımları. Son olarak bilginin açık sembollerde değil ağın yapısında ve ağırlıklarında saklandığı yapay sinir ağları; TensorFlow Playground, Word2vec, seq2seq ve CNN örnekleriyle anlatıldı.

Dersin ikinci kısmında çıkarım türleri karşılaştırıldı: yalnız tümdengelim kesinlik verir; abduction sonuçtan olası sebebe giderek bir olgu, tümevarım örneklerden olası bir kural üretir. Kurallarla yapılan zincirlemelerin hepsi tümdengelimdir; olasılık içeren çıkarımlar ve belirsizlik kaynakları başka mekanizmalar gerektirir. Hoca bir sonraki derste makine öğrenmesine giriş yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
