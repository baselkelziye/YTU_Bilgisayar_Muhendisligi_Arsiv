# Ders 14 Genişletilmiş Notu: Açık Adreslemede Arama ve Silme, Double Hashing, Yük Faktörü ve Separate Chaining

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Açık Adreslemede Arama
- 2. Açık Adreslemede Silme ve Durum Bayrağı
- 3. Doğrusal Sınamada Kümelenme
- 4. Double Hashing
- 5. Tablo Uzunluğu ve Doğum Günü Paradoksu
- 6. Yük Faktörü
- 7. Kapalı Hash: Separate Chaining
- 8. Hash Sorularında Sık Yapılan Hatalar ve Kavramların Önemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Açık Adreslemede Arama

Bu kayıt, aynı günün ikinci ders saatidir ve önceki saatte anlatılan açık adresleme (open addressing) ile doğrusal sınamanın (linear probing) devamıdır. Ders, bir öğrencinin sorusuyla başladı: dolu bir adres bulunca bir sonraki göze geçip ilk boş göze yerleştiriyorsak, sonra bu elemanı nasıl bulacağız?

Hoca cevabı bir örnekle verdi (ekrandan, 00:05:00). Tablo 5 gözlüdür (0'dan 4'e), adres fonksiyonu $h(x) = x \bmod 5$'tir.

- $x = 4$: 4. göze yerleşir.
- $x = 3$: 3. göze yerleşir.
- $x = 13$: $13 \bmod 5 = 3$; 3. göz dolu, 4. göz dolu, tablonun sonundan başa dönülür ve 13 0. göze yerleşir.

Ekleme bitti, sıra aramaya gelir. Arama da eklemeyle **aynı mantıkla** yapılır. 13 aranırken önce adresi hesaplanır: $13 \bmod 5 = 3$. 3. göze bakılır. Göz boşsa eleman tabloda yok demektir. Boş değilse içindeki 13 mü diye bakılır; değil (3). Bir sonraki göze geçilir: 4. göz, 4 var, 13 değil. Başa dönülür: 0. göz, 13 bulundu.

Olmayan bir eleman için hoca bilerek yine çakışan bir sayı seçti: $x = 8$. $8 \bmod 5 = 3$ olduğu için 3. göze bakılır; dolu ve 8 değil. 4. göz dolu ve 8 değil. Başa dönülür, 0. göz dolu ve 8 değil. 1. göz boştur; arama burada biter ve "8 bulunamadı" denir (ekrandan, 00:10:00).

## 2. Açık Adreslemede Silme ve Durum Bayrağı

Hoca daha önemli bir soru sordu: silme (delete) nasıl yapılacak? Aynı tabloda 3 silinsin ve ardından 13 aransın.

**Soru:** 3 silindikten sonra 13'ü ararsak başımıza ne gelir?
**Cevap (öğrenci):** 3. göze bakarız; orası boş olduğu için doğrudan "yok" sonucunu alırız. Hoca bunu doğruladı. 13 tabloda olduğu halde arama yanlış sonuç verir.

Öğrencilerden çeşitli öneriler geldi.

- **Geri kaydırma:** 4'ü 3. göze, 13'ü de alttaki göze kaydırmak. Hoca bunun doğru olmadığını söyledi: 4 zaten kendi doğru yerindedir; onu yukarı kaydırmak hash düzenini bozar ve yeniden hash (rehash) gerektirir.
- **Sırayla aramaya devam etmek:** Bu durumda hash'in amacından uzaklaşılır. Hoca, hash tablosuna asla normal bir tablo muamelesi yapılmaması gerektiğini vurguladı.
- **Yeniden yerleştirme (rehash):** Silmeden sonra tablodaki her elemanın mod 5 kuralına uyup uymadığına bakıp yerlerini buna göre düzenlemek. Hoca bunun gerçekten yapılan yöntemlerden biri olduğunu, bütün elemanlar için silme sonrasında yeniden hash yapılabileceğini söyledi. Ama bir milyon eleman varken tek bir silme için her şeyi oynatmak doğru değildir.

> **Hocanın vurgusu:** Hash tablosu "delik deşik" bir tablodur. Veri yapıları dersinde stack ve queue'nun kendi erişim biçimleri olduğu gibi hash tablosunun da kendi erişim kuralı vardır; normal bir tabloymuş gibi sırayla aranmaz.

Genel yöntem her göze bir **bayrak (flag)** eklemektir. Bayrak üç değer alır (ekrandan, 00:10:00):

- **Normal:** göz dolu, içinde geçerli bir eleman var.
- **Empty:** göz gerçekten boş, hiç kullanılmamış.
- **Deleted:** gözde önceden bir eleman vardı, silindi.

**Soru:** 3. gözdeki 3 silinmiş ve göz Deleted olarak işaretlenmiş. 13'ü ararken aramaya devam eder misiniz?
**Cevap:** Bir öğrenci "hayır" dedi; hoca devam edileceğini açıkladı. Göz boş görünse de Deleted yazdığına göre orada önceden bir eleman vardı ve çıkarıldı; 13 ileriki adreslerden birinde olabilir. Arama yalnız Empty gözde durur.

> **Hocanın vurgusu:** Açık adreslemede silme gerçekten ciddi bir problemdir.

Bir öğrenci, hocanın tahtada boş göz için bir yerde NULL, bir yerde Empty yazdığını fark edip Empty'nin görevini sordu. Hoca haklı olduğunu söyleyip düzeltti: Empty gerçekten boş göz demektir; tahtadaki NULL'lar da Empty olarak okunmalıdır.

## 3. Doğrusal Sınamada Kümelenme

Linear probing'in asıl sıkıntısı **kümelenmedir (clustering)**. Hoca yine 5 gözlü tabloyla anlattı. 3 3. göze yerleşir. Sonra 5 fazlası olan bir sayı, 8 gelir: $8 \bmod 5 = 3$, 3. göz dolu olduğu için 8 4. göze yerleşir. Ardından 4 gelir; kendi gözü olan 4. göz doludur, başa dönülür, 0. göz de doludur ve 4 1. göze yerleşir. <!-- BELİRSİZ: Hoca örneğe 3, 4 ve 12 ile başlayıp sonra 4 yerine 8 koydu; 0. gözdeki elemanın hangisi olduğu altyazıdan net değil ve bu ana ait kare yok. -->

Yani birisi yerine yerleşemeyince başkasının yerine yerleşir, o yerleşemeyince bir sonraki de yerleşemez. Sonuçta arka arkaya dolu gruplar oluşur. Bunu önlemek için en çok kullanılan yöntemlerden biri **double hashing**'dir.

## 4. Double Hashing

### 4.1 Formül

Linear probing'de adım büyüklüğü 1'dir: dolu gözden sonra bir sonraki göze bakılır. Double hashing'de bir sonrakine değil, belli bir adım büyüklüğü kadar sonrasına (örneğin 4 ya da 5 sonrasına) bakılır. Formül şudur (ekrandan, 00:25:00):

$$hash(key, i) = [hash_1(key) + i \cdot hash_2(key)] \bmod m$$

Burada $i$, kaçıncı deneme (i-th step) olduğunu gösterir. $hash_2(key)$, linear probing'in adım büyüklüğünü (step size) verir. İlk denemede $i = 0$ olduğu için ikinci terim sıfırdır ve adres $hash_1(key)$ olur; anahtar ilk denemede yerleşirse iş biter. İlk denemede yerleşemeyen anahtar için ne kadar ileri gidileceğini $hash_2(key)$ belirler.

### 4.2 Örnek

Tablo uzunluğu $m = 13$'tür (gözler 0'dan 12'ye). Fonksiyonlar (ekrandan, 00:25:00):

- $hash_1(key) = key \bmod 13$
- $hash_2(key) = key \bmod 11$

Girdiler sırasıyla:

- 96: $96 \bmod 13 = 5$ ($13 \cdot 7 = 91$, kalan 5). 96 5. göze yerleşir.
- 79: $79 \bmod 13 = 1$ ($13 \cdot 6 = 78$, kalan 1). 79 1. göze yerleşir.
- 14: $14 \bmod 13 = 1$. $i = 0$ için 1. göze bakılır, dolu.

$i = 1$ için $hash_2(14) = 14 \bmod 11 = 3$ hesaplanır. Bu, adım büyüklüğüdür. 1. gözün 3 sonrası olan 4. göze bakılır. 4. göz boşsa 14 oraya yerleşir.

Hoca adımları görmek için gözlerin dolu olduğunu varsayarak örneği sürdürdü (ekrandan, 00:30:00): 1. gözde 1, 4. gözde 4, 7. gözde 7, 10. gözde 10, 12. gözde 12 olsun. 14 için deneme sırası:

| $i$ | Hesap | Bakılan göz | Durum |
|---|---|---|---|
| 0 | $14 \bmod 13$ | 1 | dolu |
| 1 | $(1 + 1 \cdot 3) \bmod 13$ | 4 | dolu |
| 2 | $(1 + 2 \cdot 3) \bmod 13$ | 7 | dolu |
| 3 | $(1 + 3 \cdot 3) \bmod 13$ | 10 | dolu |
| 4 | $(1 + 4 \cdot 3) \bmod 13 = 13 \bmod 13$ | 0 | boş, 14 buraya yerleşir |

(Tablo python ile doğrulandı.)

> **Ders sonrası not:** Hoca $i = 3$ için önce 12. göze bakıldığını söyledi ve ekranda $(12 + 3) \bmod 13$ hesabına geçti (bu 2 verir). Sonra hatasını fark edip $i = 3$ için doğru gözün 10 olduğunu, 10 da doluysa $i = 4$ için 0. göze bakılacağını belirtti. Doğru sıra yukarıdaki tablodaki gibidir: 1, 4, 7, 10, 0.

Böylece elemanlar alt alta değil, atlaya atlaya yerleşir.

**Soru:** İkinci anahtar (key) neye göre seçiliyor?
**Cevap:** Anahtar aynıdır; yerleştirilmek istenen sayı, yani 14'tür.

**Soru:** $\bmod 11$'deki 11 neye göre seçiliyor?
**Cevap:** Rastgele belirlenir; tablo uzunluğu 13 olduğu için 13'ten küçük herhangi bir sayı olabilir. $hash_2$'nin görevi adım büyüklüğünü belirlemektir.

> **Ek bilgi (derste anlatılmadı):** $hash_2(key)$ sıfır çıkarsa adım büyüklüğü 0 olur ve aynı göze tekrar tekrar bakılır; örneğin $key \bmod 11$ fonksiyonunda 22 için bu olur. Bu yüzden ders kitaplarında $hash_2$ genellikle hiç sıfır vermeyecek biçimde, örneğin $1 + (key \bmod m')$ olarak seçilir. Ayrıca adım büyüklüğü ile $m$ aralarında asal olursa (örneğin $m$ asal seçilirse) bütün gözler denenebilir.

### 4.3 Neden adım anahtara bağlı?

Hoca linear probing'deki sorunu yeniden özetledi: 13 3. göze yerleşmek ister, orası dolu, bir sonrakine gider, o da dolu, bir sonrakine yerleşir. "Doluysa bir sonrakine git" kuralı kümelenme oluşturur; sonra gelen 4 de kendi yeri dolu olduğu için başkasının yerine yerleşir. Adım büyüklüğü 1 yerine örneğin 3 alınırsa kümelenme azalır. Ama 3'ü de sabit yapmak yerine anahtara bağlı yapmak daha iyidir.

**Soru:** Yerleştirmek istediğimiz sayı 9 ise adım büyüklüğü kaç olur?
**Cevap:** $9 \bmod 11 = 9$, yani 9. Sayı 5 ise adım 5, sayı 14 ise $14 \bmod 11 = 3$ olur. Gelen anahtara göre adım büyüklüğü değiştiği için kümelenme oluşma ihtimali azalır.

> **Ders sonrası not:** Hoca bir örnekte "1'i yerleştiremediğimde 2-2 ilerleyerek bakıyor" dedi; $hash_2(key) = key \bmod 11$ ile 1 için adım büyüklüğü $1 \bmod 11 = 1$'dir. Hoca büyük olasılıkla yalnız anahtara göre adımın değiştiğini anlatmak için rastgele bir sayı söyledi.

> **Hocanın vurgusu:** Çakışmadan (collision) kurtulmanın imkânı yoktur; bunun için sonsuz boş yer gerekirdi. Hem zamanı hem yeri verimli kullanmaya çalıştığımız için çakışma olacaktır. Yapılmaya çalışılan şey çakışma olasılığını olabildiğince düşürmektir. Linear probing yerine double hashing kullanmak bunu bir nebze daha azaltır.

## 5. Tablo Uzunluğu ve Doğum Günü Paradoksu

Asıl soru şudur: açık adreslemede $N$ elemana göre tablo uzunluğu $M$ ne olmalı ki eleman yerleştirirken çakışma azalsın (ekrandan, 00:35:00, "$N \to M$?")? Bu matematiksel olarak belirlenmiştir. Hoca konuya doğum günü problemiyle girdi.

Bir topluluktaki iki kişinin doğum gününün aynı olma olasılığı nedir? Birinin doğum günü $N$ günden biriyse, diğerinin farklı olma olasılığı $(N-1)/N$'dir. Yılda 365 seçenek vardır: birinci kişi için $365/365$, ikinci kişinin farklı bir gün bulabilmesi için $364/365$, üçüncü kişi için $363/365$ seçenek kalır (ekrandan, 00:35:00):

$$\frac{365}{365} \cdot \frac{364}{365} \cdot \frac{363}{365} \cdots \frac{365-(k-1)}{365}$$

$k$ kişinin doğum günlerinin hepsinin farklı olma olasılığı bu olasılıkların çarpımıdır. Bu hesaba göre 23 kişilik bir toplulukta iki kişinin doğum gününün aynı olma olasılığı yaklaşık %50'dir (python ile $1 - \prod_{j=0}^{22} \frac{365-j}{365} \approx 0{,}507$).

> **Ders sonrası not:** Hoca 23 kişi için "iki kişinin doğum günü aynı oluyor" dedi; doğrusu bunun bir olasılık olduğu ve 23 kişide yaklaşık %50,7'ye ulaştığıdır. Daha sonra "22 kişi varsa çakışma olasılığı var" dedi; 22 kişide olasılık yaklaşık %47,6'dır (python ile hesaplandı).

Aynı mantık hash'e uygulanınca, 32 bitlik hash değerleri kullanıldığında yaklaşık 77.163 eklemeden sonra çakışma olasılığı %50'ye çıkar. Tablo uzunluğu $M$ ise ikinci gelen sayının birinciyle çakışmama olasılığı $(M-1)/M$, üçüncününki $(M-2)/M$'dir. Bu çarpım sürdürülünce $k$ sayı içinde iki sayının çakışma olasılığı yaklaşık

$$1 - e^{-\frac{k(k-1)}{2M}}$$

olarak bulunur. <!-- BELİRSİZ: Hoca bu kısmı (00:36:40-00:38:30) büyük olasılıkla ekranda yazarak ya da göstererek anlattı; bu aralığa ait kare yok, 77.163 ve 250.000 değerleri ile formül altyazıdan alındı ve python ile kontrol edildi. -->

> **Ders sonrası not:** Hoca 250.000 eklemeden sonra çakışma olasılığının %100 olduğunu söyledi. Formülle $M = 2^{32}$, $k = 250.000$ için olasılık büyük olasılıkla yaklaşık %99,93'tür; "neredeyse kesin" demek daha doğrudur. 77.163 için formül %50 verir (python ile hesaplandı).

Hocanın göstermek istediği şey, çakışma olasılığının aslında çok da yüksek olmadığıdır: bir sınıfta ancak 22-23 kişi olunca doğum günlerinin çakışma olasılığı belirginleşir. Bu analizden çıkan pratik kural: $N$ eleman için tablo uzunluğu yaklaşık $M = 2N$ seçilirse (ekrandan, 00:40:00) çakışmaların az olduğu, yeterli uzunlukta bir tablo elde edilir.

## 6. Yük Faktörü

**Yük faktörü (load factor)** tablonun ne kadar dolu olduğunu gösterir (ekrandan, 00:40:00):

$$\alpha = \frac{N}{M}$$

$N$ eleman $M$ uzunluklu tabloya yerleştirildiğinde $\alpha$ doluluk oranıdır. $M$ çok büyük seçilirse çok fazla boş yer olur; bu yer kaybıdır. $M$ küçük seçilirse çakışmalar çok olacağından aramada boşuna zaman kaybedilir. İdeali $\alpha = 1/2$, yani $M \approx 2N$'dir.

Uygulamada 10 elemanınız varsa, 2 katı olan 20'ye yakın bir asal sayı tablo uzunluğu olarak alınır; örneğin 23.

## 7. Kapalı Hash: Separate Chaining

### 7.1 Mantık

İkinci yaklaşım **kapalı hash (closed hashing)**'tir; diğer adı **separate chaining**'dir (ekrandan, 00:45:00). Burada $M$, $N$'den küçük alınır ($M < N$). Çünkü elemanlar tabloya doğrudan değil, her gözden başlayan bir bağlı liste (linked list) yapısıyla yerleştirilir.

Örnek: $M = 5$ uzunluklu tablo, bölme (division) yöntemi (ekrandan, 00:45:00):

- 8 gelir: $8 \bmod 5 = 3$. 3. gözden başlayan listeye 8 yerleştirilir.
- 13 gelir: $13 \bmod 5 = 3$. 3. gözün listesine, 8'in arkasına eklenir. Liste: $8 \to 13 \to NULL$.

Açık adreslemede boş yer bulunamayınca aşağıya doğru gidiliyordu; burada yana doğru gidilir. Aradaki fark budur. Yana doğru gidildiği için tablo $N$'den küçük alınabilir. İstatistiksel çalışmalarla tablo uzunluğunun eleman sayısının yaklaşık beşte biri olmasının yeterince verimli olduğuna karar verilmiştir:

$$M = \frac{N}{5}$$

Hoca 10 eleman için 2-3 almanın uygun olduğunu söyledi. Çok küçük alınırsa zincirler sağa doğru çok uzar; çok büyük alınırsa boş göz sayısı çok artar.

### 7.2 Listenin başına ekleme

**Soru:** 23 geldi. Bu bağlı listeye nasıl yerleştirirsek en verimli olur?
**Cevap (öğrenci):** Listenin başına ekleriz. Hoca doğruladı: $23 \bmod 5 = 3$; yeni eleman sona değil listenin başına eklenirse sona kadar ilerlemek için harcanacak zamandan kurtulunur (ekrandan, 00:45:00). Liste: $23 \to 8 \to 13 \to NULL$.

Hoca aynı fikri bir örnekle daha gösterdi (ekrandan, 00:50:00): 1 gelir, $1 \bmod 5 = 1$, 1. göze yerleşir. 6 gelir, $6 \bmod 5 = 1$; 6 listenin başına eklenir: $6 \to 1$. Böylece listenin sonunu bulmakla vakit kaybedilmez. Yeni eleman geldiğinde adres hesabı açık adreslemedekinden farklı değildir; bölme ya da çarpma (multiplication) yöntemiyle yapılır. Tablo gözleri liste başının (head) adresini tutar.

### 7.3 Veri yapısı

Hoca yapının nasıl oluşturulacağını anlatmaya başladı:

- **Düğüm (node):** bağlı listeye yerleştirilecek her düğümde anahtar (key), anahtara bağlı bilgi (örneğin name) ve bir sonraki düğümün adresi (next) bulunur.
- **Hash yapısı:** her göz için listenin baş düğümünün yeri (head) ve o listede kaç düğüm olduğu (count) saklanır. Hash tablosu bu yapı tipinde bir dizidir.

Hoca ardından anahtarı ve ismi okuyup tablo için yer ayırma adımlarına geçti, ancak kalem ve tabletin şarjı yüzünden yazamadığı için kodu tamamlamadı ve bu bölümü daha sonra anlatacağını söyledi. Bu yüzden kod bu notta yer almıyor. <!-- BELİRSİZ: Düğüm ve hash yapısının tahtaya yazılan hali (00:46:00-00:48:00) karelerde yok; yapı yalnız altyazıdan aktarıldı. -->

## 8. Hash Sorularında Sık Yapılan Hatalar ve Kavramların Önemi

Hoca, hash algoritmalarında öğrencilerin en sık yanıldığı yerleri ekranda daha önceki bir soruyu göstererek anlattı. <!-- BELİRSİZ: Hocanın 00:55:00 civarında ekranda gösterdiği soru metni karede görünmüyor (kamera kapalı görüntüsü); soru aktarılamadı. -->

- Adres artırılırken mod alınmaması: pek çok kişi $adres = adres + 1$ yazıp geçer; mod alınmadığı için tablonun sonundan başa dönülemez. Doğrusu $adres = (adres + 1) \bmod M$ biçimindedir.
- Gerekli kontrollerin unutulması: yalnız boş göz olup olmadığına bakılır; oysa yerleştirilmek istenen anahtar tabloda zaten varsa onu tekrar yerleştirmemek için bu da kontrol edilmelidir.

> **Hocanın vurgusu:** Hash gibi bir soru çok kolay olmasına rağmen çok sık hatalı çözülür. Bu noktalara dikkat edin.

Hoca, Big-O, Big-Theta ve Big-Omega gibi kavramların ezberlenmemesini, öğrenilmesini istedi. Bu kavramlar ileride, özellikle Ar-Ge yapılan yerlerde algoritma geliştirirken karşınıza çıkar. Hazır araçlar ve dil kütüphaneleri çok faydalıdır, ama büyük şirketlerin ürünleri sağlam Ar-Ge çalışmaları ve iyi algoritmalar sonucu geliştirilir. Mesajlaşma uygulamasının yanlış yazılan kelimeyi düzeltmesi, tamamlaması, önermesi ya da yol tarifinde giderken daha kısa bir yol bulunup önerilmesi iyi algoritmaların örnekleridir. Karmaşıklık, asimptotik analiz, böl ve yönet gibi konuların yanında, anlatılan konularla ilgili (örneğin böl ve yönet ya da hash için) algoritma tasarlayabilecek durumda olmak gerekir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00; derste sözlü, 00:04:58): 5 gözlü tabloya $h(x) = x \bmod 5$ ve linear probing ile sırasıyla 4, 3, 13 yerleştirilmiştir. 13 ve 8 nasıl aranır?

> **Çözüm (derste verildi):** 13: $13 \bmod 5 = 3$; 3. göz (3) ve 4. göz (4) eşleşmez, başa dönülür, 0. gözde 13 bulunur. 8: $8 \bmod 5 = 3$; 3, 4 ve 0. gözler dolu ve 8 değil, 1. göz boş, 8 tabloda yoktur.

**Soru 2** (derste sözlü, 00:06:06): Aynı tablodan 3 silinip göz boşaltılırsa 13 aranınca ne olur? Ne önerirsiniz?

> **Çözüm (derste verildi):** Arama 3. gözün boş olduğunu görüp yanlışlıkla "yok" der. Çözüm gözlere Normal/Empty/Deleted bayrağı koymaktır; silinen göz Deleted olarak işaretlenir ve aramada Deleted gözde durulmaz.

**Soru 3** (derste sözlü, 00:09:12): Bir göz boş ama Deleted işaretliyse 13'ü aramaya devam eder misiniz?

> **Çözüm (derste verildi):** Evet. Deleted, orada önceden bir eleman olduğunu gösterir; aranan eleman ileriki gözlerde olabilir. Arama yalnız Empty gözde durur.

**Soru 4** (ekrandan, 00:25:00 ve 00:30:00): $m = 13$, $hash_1(key) = key \bmod 13$, $hash_2(key) = key \bmod 11$ ile double hashing yapılmaktadır. 96, 79 ve 14 nereye yerleşir? 1, 4, 7, 10 ve 12. gözler doluysa 14 için deneme sırası nedir?

> **Çözüm (derste verildi):** $96 \bmod 13 = 5$, $79 \bmod 13 = 1$, $14 \bmod 13 = 1$. 14 için $hash_2 = 3$; deneme sırası 1, 4, 7, 10, 0 olur ve 14 0. göze yerleşir (python ile doğrulandı).

**Soru 5** (derste sözlü, 00:31:14): $hash_2(key) = key \bmod 11$ iken yerleştirilecek sayı 9 ise adım büyüklüğü kaç olur?

> **Çözüm (derste verildi):** $9 \bmod 11 = 9$.

**Soru 6** (derste sözlü, 00:33:32; ekrandan, 00:35:00): Bir toplulukta iki kişinin doğum gününün aynı olma olasılığı nedir?

> **Çözüm (derste verildi):** Hepsinin farklı olma olasılığı $\frac{365}{365} \cdot \frac{364}{365} \cdots \frac{365-(k-1)}{365}$'tir; aynı olma olasılığı 1'den bunun çıkarılmasıyla bulunur. 23 kişide yaklaşık %50'dir (python ile 0,507).

**Soru 7** (derste sözlü, 00:43:45; ekrandan, 00:45:00): Separate chaining ile $M = 5$ tabloda 3. gözün listesi $8 \to 13 \to NULL$ iken 23 gelirse en verimli nasıl yerleştirilir?

> **Çözüm (derste verildi):** $23 \bmod 5 = 3$; 23 listenin başına eklenir: $23 \to 8 \to 13 \to NULL$. Böylece listenin sonuna kadar ilerlemek gerekmez.

## Dersin Toparlaması

Bu derste açık adreslemenin işlemleri tamamlandı. Arama, eklemeyle aynı sırayı izler ve boş gözde biter. Silme ise aramayı bozabileceği için gözlere Normal, Empty ve Deleted bayrakları konur; aramada Deleted gözlerin üzerinden geçilir. Linear probing'in yarattığı kümelenme problemi, adım büyüklüğünü anahtara bağlayan double hashing ile azaltılır: $hash(key, i) = [hash_1(key) + i \cdot hash_2(key)] \bmod m$.

Tablo uzunluğunun seçimi doğum günü paradoksuyla gerekçelendirildi: çakışma, sanılandan erken ortaya çıkar ama yönetilebilir düzeydedir. Açık adreslemede $M \approx 2N$ (yakın bir asal) ve $\alpha = N/M \approx 1/2$ hedeflenir. İkinci yaklaşım olan separate chaining'de her göz bir bağlı listenin başını tutar, $M \approx N/5$ alınır ve yeni eleman listenin başına eklenir. Separate chaining'in kodlanması bu derste tamamlanmadı; hoca bu kısmı daha sonra anlatacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
