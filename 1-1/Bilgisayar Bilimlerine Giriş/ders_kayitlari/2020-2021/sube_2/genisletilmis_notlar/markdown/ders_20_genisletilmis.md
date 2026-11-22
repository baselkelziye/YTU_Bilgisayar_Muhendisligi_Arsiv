# Ders 20 Genişletilmiş Notu: Art Arda En Çok Tekrar Eden Eleman, Histogram (Sayma Dizisi) ve Matris Çarpımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Art Arda En Çok Tekrar Eden Eleman Problemi
- 2. Akışın Öğrencilerle Birlikte Çizilmesi
- 3. Akıştaki Hatalar ve Düzeltmeleri
- 4. Sınır Durumu: En Uzun Tekrar Dizinin Sonunda
- 5. Ek Dizi Kullanmak ve Yer Karmaşıklığı
- 6. Gri Seviye Resim ve Histogram Problemi
- 7. Değeri İndis Olarak Kullanmak: Sayma Dizisi
- 8. Matris Çarpımı
- 9. Matris Çarpımı Akışı
- 10. Akışı Analizle Doğrulamak

## 1. Art Arda En Çok Tekrar Eden Eleman Problemi

Ders yine bir problemle başladı. Hoca ekrana şu diziyi yazdı ve aynı değerlerin art arda devam ettiği bölümleri altını çizerek gösterdi (ekrandan, 00:15:00):

```text
konum :  1  2  3  4  5  6  7  8  9 10 11 12 13
dizi  :  3  5  5  5  4  4  7  6  6  6  6  3  3
           \_____/  \__/     \________/ \__/
              3       2           4       2
```

Dizide peş peşe devam eden elemanlar vardır: 5 üç kez, 4 iki kez, 6 dört kez art arda tekrar eder. Problemin tanımı ekrana şöyle yazıldı (ekrandan, 00:35:00):

> Bir dizi içerisinde **"art arda"** en çok tekrar eden eleman ve tekrar sayısı.

### 1.1 "Art arda" ne demek?

Bir öğrenci, tekrar eden sayıların yan yana mı olması gerektiğini yoksa dizinin farklı yerlerinde de olabileceğini sordu. Hoca "art arda" kelimesinin özellikle vurgulandığını hatırlattı: birbirini takip eden şekilde en çok tekrar eden eleman soruluyor. Örneğin dizide 3 değeri bir kez başta, iki kez sonda geçer; bunlar toplanıp "üç tane 3 var" denmez. Yalnız art arda gelen tekrarlara bakılır. Bu örnekte en çok art arda tekrar eden eleman 8. elemandır, yani 6 değeri; tekrar sayısı 4'tür.

### 1.2 Cevap nasıl verilir?

Hoca elemanı bildirmenin iki yolu olduğunu söyledi. Birincisi yalnız değeri söylemektir: "6". İkincisi, daha makul ve mantıklı olanı, konumu söylemektir: "8. eleman" (ekrandan, 00:35:00). Konum bilgisine sahipseniz tekrarın nereden başladığını, hangi sayı olduğunu ve tekrar sayısıyla birlikte ne kadar devam ettiğini rahatça çıkarabilirsiniz. Çözüm bu yüzden konumu saklayacak şekilde kurulur.

## 2. Akışın Öğrencilerle Birlikte Çizilmesi

Bir öğrenci çözüm fikrini söyledi, hoca da onun tarifine göre akışı çizdi. Fikir şuydu: bir sayaç (`CNT`, "count"un kısaltması) 1'den başlatılır; dizide ilerlerken eleman bir öncekiyle (ya da bir sonrakiyle) aynıysa sayaç bir artırılır; ayrıca bir de en büyük tekrar uzunluğunu tutan `MAX` değişkeni olur. Öğrenci `MAX`'ın da 1 ile başlaması gerektiğini söyledi, çünkü eleman komşusuyla aynı olmasa bile kendisi 1 uzunluğunda bir tekrardır.

İlk çizilen akış şöyledir (ekrandan, 00:25:00):

```text
START
  |
[ N, A(N) ]                    (girdi)
  |
[ CNT = 1 ; MAX = 1 ]          (sonradan yanına PL = 1 eklendi)
  |
[ I <- 1 || 1 ; bitiş N ] <---------------------------+
  |                                                   |
< A(I) = A(I+1) >                                     |
  F |                         | T                     |
< CNT > MAX >           [ CNT = CNT + 1 ]             |
  F |          | T              |                     |
[ CNT = 1 ]  [ MAX = CNT ]      |                     |
  |            |                |                     |
  +------------+----------------+---------------------+
```

Döngü değişkeni `I`, `A(I)` ile `A(I+1)` karşılaştırılır. Öğrenci önce karşılaştırmayı "N'inci eleman ile N+1'inci eleman" diye tarif etti; hoca bunun döngü değişkeniyle, yani `A(I)` ve `A(I+1)` olarak yazılması gerektiğini gösterdi.

- Eşitse (`T`): `CNT = CNT + 1`.
- Eşit değilse (`F`): içinde bulunulan tekrar bitmiştir. `CNT > MAX` sorulur. Doğruysa `MAX = CNT` yapılır. Öğrenci yanlış kolda da sayacın yeniden 1 yapılması gerektiğini ekledi (`CNT = 1`).

Ardından öğrenci akışın yalnız tekrar sayısını bulduğunu, hangi eleman olduğunu bulmadığını fark etti. Bunun için bir konum değişkeni `PL` eklendi ve başta `PL = 1` yapıldı. Öğrenci, `PL`'nin `CNT > MAX` kararının doğru kolunda güncellenmesi gerektiğini söyledi (ilk hali `PL = I`). Döngüden çıkınca eleman ve `MAX` yazdırılacaktı.

## 3. Akıştaki Hatalar ve Düzeltmeleri

Akış bittikten sonra diğer öğrenciler sırayla hataları gösterdi. Hocanın düzeltmeleri işaretlediği hal (ekrandan, 00:30:00):

### 3.1 Döngü sınırı: N değil N-1

Bir öğrenci for döngüsünün bitişinin `N` değil `N-1` olması gerektiğini söyledi. Hoca açıkladı: `I`, `N` değerini aldığında `A(N)` ile `A(N+1)` yani olmayan bir eleman karşılaştırılmaya çalışılır. Dizinin sınırlarının dışına çıkılır ve "iş patlar". Bu yüzden bitiş `N-1` olmalıdır. Hoca öğrencinin söylediğini doğru buldu.

### 3.2 Yazdırılan eleman: A(I) değil A(PL)

Başka bir öğrenci, sonda `A(I)` yerine `A(PL)` yazdırılması gerektiğini söyledi. Döngü bittiğinde `I` dizinin sonunu gösterir; aranan elemanın konumu `PL`'dedir. Çıkış kutusu `A(PL), MAX` olarak düzeltildi.

### 3.3 Başlangıç konumu: PL = I - MAX + 1

Bir öğrenci, `CNT > MAX` kararının doğru kolunda `PL = I` yerine `PL = I - MAX + 1` yazılması gerektiğini söyledi (ekrandan, 00:30:00). Akışı tarif eden öğrenci bunu ilk anda anlamadı; hoca örnek üzerinden gösterdi:

- `I = 1`: 3 ile 5 karşılaştırılır, aynı değil, devam edilir.
- `I = 2`: 5 ile 5 aynı, `CNT = 2`.
- `I = 3`: 5 ile 5 aynı, `CNT = 3`.
- `I = 4`: 5 ile 4 aynı değil. `CNT > MAX` mı? `3 > 1`, evet. `MAX = 3`. `PL = I` yazılırsa `PL = 4` olur.

Oysa 4. eleman tekrarın başlangıç noktası değil, son elemanıdır. Tekrar 2. elemanda başlar. `I = 4`'ten `MAX = 3` çıkarılırsa 1 bulunur, bu tekrarın bir öncesini gösterir; 1 eklenince başlangıç noktası (2) elde edilir: `PL = 4 - 3 + 1 = 2`. Akışı tarif eden öğrenci de `PL = I` yazarken değerin aynı olduğunu (5) düşündüğünü, ama başlangıç noktası olmadığını kabul etti.

### 3.4 Karar kutusunda "=" mi "==" mi?

Bir öğrenci ilk karar kutusunda `=` yerine `==` yazılmasının daha doğru olacağını söyledi. Hoca buna şakayla karşılık verip öğrenciden beş dakika düşünmesini istedi. Öğrenci sonra programlama dili mantığıyla düşündüğünü, akış diyagramı olduğunu unuttuğunu söyledi; hoca da bunu doğru cevap kabul etti. Akış diyagramında karar kutusundaki `=` bir karşılaştırmadır; `==` C dilinin yazımıdır ve akışa taşınmaz.

### 3.5 Sayacın sıfırlanması iki kolda da yapılmalı

Bir öğrenci, `CNT = 1` sıfırlamasının `CNT > MAX` kararının yalnız yanlış kolunda değil, doğru kolunda da yapılması gerektiğini söyledi; çünkü `CNT` artık `MAX`'a atanmıştır. Hoca bunu "hem false hem true'da olmalı" diye not etti ve sıfırlamanın iki kolun birleştiği yere konmasının daha iyi olacağını söyledi.

Bu düzeltmenin neden gerekli olduğu örnek dizide görülebilir: sıfırlama yalnız yanlış kolda olursa 5'lerin tekrarı bitince `MAX = 3` olur ama `CNT = 3` olarak kalır. Ardından gelen iki 4, sayacı 4'e çıkarır ve akış yanlış sonuç verir (bu hatalı akışla örnek dizide 5 değeri ve 4 tekrar çıkıyor; python ile denendi).

### 3.6 Düzeltilmiş akış

Derste söylenen düzeltmelerin hepsi uygulanınca akış şöyledir (ekrandan, 00:30:00 ve altyazıdan):

```text
START
  |
[ N, A(N) ]
  |
[ CNT = 1 ; MAX = 1 ; PL = 1 ]
  |
[ I <- 1 || 1 ; bitiş N-1 ] --(bitince)--> [ A(PL), MAX ] --> STOP
  |  (gövde)                       ^
< A(I) = A(I+1) >                  |
  F |                     | T      |
< CNT > MAX >     [ CNT = CNT + 1 ]|
  F |      | T            |        |
    |   [ MAX = CNT        ]       |
    |   [ PL = I - MAX + 1 ]       |
    +------+                       |
           |                       |
     [ CNT = 1 ]                   |
           |                       |
           +-----------+-----------+  (döngü başına)
```

Örnek dizide bu akış `PL = 8`, `A(8) = 6`, `MAX = 4` verir (python ile doğrulandı). 6'ların tekrarı biterken `I = 11`, `CNT = 4` olur ve `PL = 11 - 4 + 1 = 8` bulunur.

## 4. Sınır Durumu: En Uzun Tekrar Dizinin Sonunda

Bir öğrenci analiz için dizinin sayılarına geri dönülmesini istedi. Hoca bunun üzerine diziyi biraz değiştirerek yeniden yazdı; bu kez 3'leri 6'lardan önce, 6'ları en sona koydu (ekrandan, 00:40:00):

```text
3  5  5  5  4  4  7  3  3  6  6  6  6
                              \________/
                                  4
```

En uzun tekrar yine 6'ların tekrarıdır ve uzunluğu 4'tür. Hoca akışı tarif eden öğrenciye algoritmasının bunu yakalayıp yakalamadığını sordu: son 6'larda sayaç artırılır, sonra döngüden çıkılır. `MAX` yalnız eşitsizlik görüldüğünde güncellendiği için sondaki tekrar hiç değerlendirilmez. Öğrenci de akışın bunu yakalamadığını kabul etti. Bu akışla ikinci dizide sonuç 5 değeri ve 3 tekrar çıkar (python ile denendi).

Hoca bu duruma göre akışın yeniden çizilmesi, toparlanması gerektiğini söyledi ve not düştü: en uzun tekrar sonda olabilir. Düzeltilmiş hali derste çizilmedi (bkz. Örnek Sorular).

> **Hocanın vurgusu:** Akışınızı çizdiğiniz zaman test etmek için analiz yapmanız lazım. Her seferinde "arkadaşlar bir el atın" diyerek bu iş olmaz. Çizeceksiniz, deneyeceksiniz, olmadığı yerde bir daha kontrol edeceksiniz. Tek bir örnekle kontrol etmeyeceksiniz; özellikle uç nokta ve sınır değer kontrollerini (en başta, en sonda olan durumlar) da yapacaksınız.

## 5. Ek Dizi Kullanmak ve Yer Karmaşıklığı

**Soru:** Aynı olan elemanları ayrı bir diziye aktarıp o dizinin içinde seçim yapamaz mıyız?

**Cevap:** Hoca, öyle bir bolluk içindeyseniz yapabileceğinizi ama derste hep büyük problemlerin küçültülmüş hallerinin konuşulduğunu hatırlattı. Milyonlarca elemanlı bir dizide dizinin bir kopyasını alıp kenara çıkarmak efektif ya da makul değildir. Daha önce zaman karmaşıklığı (time complexity) konuşulmuştu; karmaşıklık yalnız zamanla sınırlı değildir, yer karmaşıklığı (space complexity) da vardır. Bir problemi çözmek için bir birim mi yer harcıyorsunuz, yoksa problemin boyutu kadar (`n` elemanlı problem için `n` birim) yer mi? İkincisi çözümü tercih edilebilir olmaktan çıkarır.

Hoca bunu başka bir problemle örnekledi: elinizde `N` elemanlı bir dizi var ve değerlerin 0 ile 9 arasında olduğunu biliyorsunuz. Hangi elemandan kaç tane olduğu soruluyor. Bunun için 10 elemanlı bir dizi açılır ve sayıların değerleri bu yeni dizinin indisi olarak kullanılarak ilgili göz artırılır: 1 görünce 1'e karşılık gelen göz, 2 görünce 2'ye karşılık gelen göz artırılır. Sonunda her değerin kaç kez geçtiği ortaya çıkar. Ama değer aralığı 0'dan 4 milyara kadarsa ve dizi yüz ya da bin elemanlıysa, o kadar gözlü bir dizi açıp saymak mantıklı olmaz.

## 6. Gri Seviye Resim ve Histogram Problemi

Hoca, 0-9 örneğinin kafalarda tam oturmadığını düşünerek aynı fikri bir senaryo üzerinden formüle etti.

### 6.1 Renk derinliği

Resim dosyaları farklı renk seviyelerinde olabilir (ekrandan, 00:45:00):

- **24 bit:** RGB formatıdır; Red, Green, Blue için 8'er bit ayrılır.
- **32 bit** ve **16 bit** biçimler de vardır; 16 bitlik RGB de mümkündür.
- **8 bit gri seviye (gray level / gray scale):** 8 bitle 0 ile 255 arasındaki değerler ifade edilir, toplam 256 değer vardır.

### 6.2 Resim bir matristir

Gri seviye bir resim büyütülerek bakıldığında her karesi bir piksel olan bir ızgaradır; her pikselde 0 ile 255 arasında bir değer (örneğin 17, 37) bulunur. Bu resim bir matris olarak düşünülebilir; en küçüğünden 640 × 480, yani 640 çarpı 480 göz (ekrandan, 00:45:00).

Resimde iyileştirme yapmak, örneğin bir eşik (threshold) değeri hesaplamak için önce bu renk değerlerinden hangisinden kaç tane olduğu bulunmalıdır: kaç tane 0, kaç tane 1, kaç tane 2, ..., kaç tane 253, 254, 255. Bu sayılar histogramı oluşturur; eşikleme bu histograma göre yapılır.

### 6.3 Bir öğrencinin denemesi ve hocanın müdahalesi

Bir öğrenci akışı çizmeyi denedi: `N, M` ve `A(N)(M)` okundu, `I ← 1 || 1` (bitiş `N`) ve içinde `J ← 1 || 1` (bitiş `M`) döngüleri kuruldu (ekrandan, 00:50:00). Öğrenci sonra `A(I)(J) = A(I+1)(J+2)` gibi bir karşılaştırma önerdi. Hoca burada müdahale etti: öğrenci problemi kafasında henüz oturtmadığı için her şey havada kalıyordu ve bir yere varılabilecek gibi durmuyordu.

> **Hocanın vurgusu:** Problemi öncelikle iyi anladığınızdan emin olun. Gerekiyorsa bir daha, bir daha okuyun; kafanıza yatmayan yer varsa sorun. "Nasıl yapacağız?" dendiğinde hemen atlamanız gerekmiyor. Önemli olan hızlı yapmanız değil, mümkünse doğru yapmanız. Problemden çok bağımsız şeyler söylediğinizde problem hiç anlaşılmamış demektir; bir şeyi anlayıp anlamadığınızın farkına varma iç güdüsünü kazanmanız lazım.

Hoca problemi sadeleştirdi (ekrandan, 00:55:00): renkleri ve resmi boş verin; elinizde bir matris var ve içinde 0-255 arası değerler var. Sizden istenen, sonunda şöyle bir sonuç söylemenizdir:

```text
sayı   değer
10  ->  0      (10 tane 0)
11  ->  1      (11 tane 1)
70  ->  2      (70 tane 2)
 0  ->  3      (3'ten hiç yok)
...            (0 ile 255 arasındaki her değer için)
```

## 7. Değeri İndis Olarak Kullanmak: Sayma Dizisi

### 7.1 Tek değer sayılacak olsaydı

Hoca öğrencilere bir dakika düşünme süresi verdikten sonra sordu: soru "bu matris içerisinde 71 değerinin kaç kere geçtiğini bulun" olsaydı ne yapardınız? Matrisin bütün elemanlarını tek tek kontrol eder, 71 olan varsa bir sayacı artırırdınız.

Şimdi sayılması gereken tek bir eleman yoktur; 256 değer vardır ve her biri bağımsız istenmektedir. Dolayısıyla 256 sayaca ihtiyaç vardır. Değerleri tek tek "bu 1 mi, 2 mi, 3 mü..." diye kontrol eden 256 tane `if` yazılmaz.

### 7.2 Değer başka bir dizinin indisi olabilir

Bir dizinin elemanına erişmek için `A(I)` yazılır: `A` dizinin adı, `I` indistir. İndis için genelde değişken kullanılır, ama bir sabit de kullanılabilir: `A(1)` birinci elemandır. Matriste de `A(1)(2)` birinci satır ikinci sütundaki göze erişir.

Bu matrisin elemanları sayısal değerlerdir ve 0 ile 255 arasında değişir. `A(1)(2)` ya da `A(I)(J)` değerlendirildiğinde 17, 87, 102 gibi bir sayıya denk gelir. Bu yüzden `A(I)(J)` başka bir dizinin indisi olarak kullanılabilir.

`CNT` adlı 256 gözlü bir sayaç dizisi açılır (ekrandan, 01:00:00). Bu derste dizi indisleri 1'den başladığı için gözler 1'den 256'ya numaralanır. `A(I)(J)` 0 ile 255 arasında olduğu için `A(I)(J) + 1` değeri 1 ile 256 arasındadır: değer 0 ise 1. göze, 255 ise 256. göze denk gelir. Böylece aradaki bütün değerler bir göze eşlenir (map edilir).

Akışın kalbi şu işlemdir (ekrandan, 01:55:00):

```text
CNT(A(I)(J)+1) = CNT(A(I)(J)+1) + 1
```

Matris dolaşılırken her eleman için ilgili göze bir eklenir. Böylece değerleri tek tek kontrol etmek yerine, değerlerin kendisi kullanılarak ilgili gözler doğrudan artırılır.

### 7.3 Önemli kural: ilklendirme

> **Hocanın vurgusu (ekranda "önemli" diye işaretlendi):** `CNT` eşitliğin hem solunda hem sağında geçer, ama önce sağda kullanılır. Bu yüzden `CNT` dizisi ilklendirilmelidir; sıfırla.

Hoca bundan sonra öğrencilerden bu problemin akışını kendilerinin çizmesini istedi.

**Soru:** Matrisin içinde 0-255 arası değerler var, ama kullanıcı 256 girerse ne olur?

**Cevap:** Hoca hikâyeyi hatırlattı: akışta okuma kutusuna `N, M, A(N)(M)` yazılır ama değerler illa kullanıcıdan alınmak zorunda değildir; bu bir resimdir ve bilgi belki bir dosyadan okunur. Alan zaten 8 bit tanımlandıysa girilen 256 taşar (overflow). Dosyadan okunuyorsa ve dosya gerçek bir gri seviye resimse sorun yoktur; dosya uygun formatta değilse zaten o resim dosyası işlenemez. Yan problemlere değil, çözülmeye çalışılan ana probleme odaklanılmalıdır.

> **Ders sonrası not:** Hoca 8 bitlik alana girilen 256'nın taşıp 1'e döndüğünü söyledi. İşaretsiz 8 bitlik bir alanda 256 değeri $256 \bmod 256 = 0$ olur, yani büyük olasılıkla 0'a döner.

## 8. Matris Çarpımı

Aradan sonra hoca yeni bir problem verdi: A matrisi ile B matrisi çarpılıp C matrisi oluşturulacak. Ekrandaki boyutlar: A 7 × 8, B 8 × 5 (ekrandan, 01:25:00).

### 8.1 Çarpımın tarifi

Bir öğrenci çarpımı tarif etti: A'nın birinci satırı ile B'nin birinci sütununun karşılıklı elemanları çarpılır. Hoca tarifte kimin satırı, kimin sütunu olduğunun belirtilmesi gerektiğini hatırlattı. A'nın satırı ile B'nin sütunu karşılıklı eleman eleman çarpılır, bu çarpımlar toplana toplana gider ve sonuç C'de tek bir yere yazılır: birinci satırın ilk elemanı olarak. Sonra aynı satır B'nin bir sonraki sütunuyla çarpılıp yanına yazılır. A'nın ikinci satırı B'nin bütün sütunlarıyla tek tek çarpılıp C'nin ikinci satırına yerleştirilir; bu yedi satır için tekrarlanır (ekrandan, 01:30:00).

### 8.2 Sonucun boyutu

**Soru:** 7 × 8 ile 8 × 5 matris çarpılınca çıkan matrisin boyutu ne olur?

**Cevap:** Öğrenci önce 8 × 5 dedi, sonra düzeltti: 7 × 5. Hoca C'nin satır sayısını 7, sütun sayısını 5 olarak işaretledi.

$$A_{7\times 8}\cdot B_{8\times 5} = C_{7\times 5}$$

### 8.3 Boyut uyumu

**Soru:** Birinci matrisin sütun sayısı 8 ve ikincinin satır sayısı da 8 olmak zorunda; bunu akışta belirtmemiz gerekiyor mu?

**Cevap:** Hoca, bu koşul sağlanmazsa zaten çarpılamayacağını ve örneğin bu yüzden öyle verildiğini söyledi. Ayrıca akıllı bir tasarımda kullanıcıdan dört boyut istenmez; topu topu üç bilgi istenir: birinci matrisin satır sayısı, ortak boyut ve ikinci matrisin sütun sayısı. B'nin satır sayısı A'nın sütun sayısına eşit olmak zorunda olduğu için ayrıca sorulmaz. Böylece kullanıcının yanlış girmesi engellenir ("kullanıcıdan daha akıllı olursun").

### 8.4 Tek bir elemanın hesabı ve örüntü

Hoca birinci elemanın hesabını açık yazdıktan sonra C'nin ikinci elemanı için gerekenleri gösterdi: A'nın aynı satırı ($A_{11}, A_{12}, \dots, A_{18}$) bu kez B'nin ikinci sütunuyla çarpılır:

$$C_{12} = A_{11}B_{12} + A_{12}B_{22} + \dots + A_{18}B_{82}$$

Hoca, bu matematiği yazıp tek tek denediğinizde bir örüntü (pattern) çıktığını görmeniz gerektiğini söyledi. Probleme bakar bakmaz göremiyorsanız açık açık yazıp örüntüyü bulmalı, akışı bu örüntüye göre kurmalısınız.

### 8.5 Geçici değişkenle toplamak

**Soru:** `C = C + A * B` biçiminde, döngü içinde doğrudan C matrisine toplayarak yazabilir miyiz? (Soru sohbete yazılarak soruldu.)

**Cevap:** Hoca formül olarak yazılabileceğini, indis harflerinden birinin büyük birinin küçük yazılması dışında bir sorun görmediğini söyledi. Ama döngü içinde toplaya toplaya gidilecekse kendisinin böyle yapmayacağını, toplamı geçici bir değişkende (örneğin `TMP`) biriktirip en son matrise atayacağını belirtti. Gerekçe: matrisin indislenmesi teknik olarak daha maliyetli bir süreçtir; `C(I)(J)` gözüne erişmek için matris boyutu üzerinden adres hesabı yapılır ve bu bellek erişimi bakımından daha uzun sürebilir. Bunun etkisi platforma ve mimariye göre değişir; örneğin o göz önbelleğe alınıp hızlı erişilebilir. Bunlar ihtimaldir, ama optimum noktada mümkün olan yerde matris indisi yerine geçici değişken tercih edilir; özellikle büyük matrislerde adres çözümlemeye daha fazla vakit harcanır.

> **Ek bilgi (derste anlatılmadı):** C'de `C[i][j]` gibi iki boyutlu bir dizi elemanının adresi, satır uzunluğu kullanılarak `taban + (i * sütun_sayısı + j) * eleman_boyutu` biçiminde hesaplanır. Derleyiciler çoğu durumda bu hesabı döngü dışına taşıyarak iyileştirebilir; bu yüzden fark büyük olasılıkla derleyiciye ve optimizasyon ayarına bağlıdır.

## 9. Matris Çarpımı Akışı

Bir öğrenci akışı tarif etti. Önce boyut uyumu koşulunu hatırlattı: A'nın sütun sayısı ile B'nin satır sayısı aynı olmalıdır. Bu yüzden üç değişken (`L`, `M`, `N`) ve iki matris (`A(L)(M)`, `B(M)(N)`) okunur. Sonra üç iç içe for döngüsü kurulur:

- Birinci döngü A'nın satırları üzerindedir: `I`, 1'den `L`'ye.
- İkinci döngü B'nin sütunları üzerindedir: `K`, 1'den `N`'ye.
- Toplam için `SUM = 0` atanır.
- Üçüncü döngü ortak boyut üzerindedir (A'nın sütun sayısı = B'nin satır sayısı): `J`, 1'den `M`'ye. İçinde `SUM = SUM + A(I)(J) * B(J)(K)` yapılır.

Hoca, `SUM = 0` kutusundaki karakterin harf O mu sıfır mı olduğunu sordu. Kendi sıfırlarını içine çizgi koyarak (`Ø`) yazdığını açıkladı: eski nokta vuruşlu (dot matrix) ekranlarda sıfırın O harfinden ayrılması için ortasına bir nokta ya da çizgi konurdu. Akış çizerken sıfırın sıfır olduğunun net anlaşılmasını tavsiye etti.

Öğrenci çarpım toplamının C'de nereye yerleşeceğini kuramamıştı. Hoca yönlendirdi: `J` döngüsü bittiğinde A'nın `I`. satırı B'nin `K`. sütunuyla tamamen çarpılmıştır; sonuç C'nin `I`. satırı, `K`. sütununa yerleşir. Bu atama üçüncü döngünün çıkışında yapılır: `C(I)(K) = SUM`. Sonra döngüler kapanır ve matris yazdırılır.

Çizilen akış (ekrandan, 01:45:00; `C(I)(K) = SUM` ve yazdırma adımı altyazıdan):

```text
START
  |
[ L, M, N ; A(L)(M) ; B(M)(N) ]
  |
[ I <- 1 || 1 ; bitiş L ] <------------------------------+
  |                                                      |
[ K <- 1 || 1 ; bitiş N ] <---------------------+        |
  |                                             |        |
[ SUM = 0 ]                                     |        |
  |                                             |        |
[ J <- 1 || 1 ; bitiş M ] <--------+            |        |
  | (gövde)        | (bitince)     |            |        |
  |          [ C(I)(K) = SUM ] ----|------------+        |
[ SUM = SUM + A(I)(J) * B(J)(K) ]  |                     |
  |                                |                     |
  +--------------------------------+                     |
                                                         |
(K döngüsü bitince I döngüsüne, I döngüsü bitince:)      |
[ C matrisi yazdırılır ] --> STOP                        |
```

Bu akış 7 × 8 ve 8 × 5 boyutlu rastgele tamsayı matrislerle python'da denendi; sonuç kütüphane çarpımıyla aynı ve 7 × 5 boyutlu çıktı.

## 10. Akışı Analizle Doğrulamak

Bir öğrenci akışın üstünden bir kez daha geçilmesini istedi. Hoca bunun en iyi yolunun analiz olduğunu söyledi ve ekrana şunu yazdı (ekrandan, 01:50:00): "Çözüm / Çare: ANALİZ". Altına da izlenecek değişkenlerin tablo başlıklarını koydu:

```text
I    K    J    SUM    A(I)(J)    B(J)(K)
```

İki küçük matris alın, bu akışa göre çarpın; `I`, `K`, `J` değişkenlerinin her adımda ne olduğunu, hesaba hangi `A(I)(J)` ve `B(J)(K)` değerlerinin girdiğini ve `SUM`'ın nasıl değiştiğini tek tek not edin. Böylece akışın nasıl çalıştığını görürsünüz.

> **Hocanın vurgusu:** Bir çözümün doğru mu yanlış mı olduğunu bana sormak yerine analizini yaparak kendi kendinize çözümleyebilirsiniz. Her soru ya da sıkıntı anında yanınızda biri olmayacak. Optimumluk konusunda zaman zaman farklı bir yaklaşım ya da ek bilgi gerekebilir (matris indisleri konusundaki geçici değişken gibi), ama bir akışın çalışıp çalışmadığını analizle kendi başınıza kontrol edebiliyor olmanız gerekir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): Bir dizi içerisinde art arda en çok tekrar eden elemanı ve tekrar sayısını bulan akışı çizin. Örnek dizi: `3 5 5 5 4 4 7 6 6 6 6 3 3`.

> **Çözüm (derste verildi):** Bölüm 3.6'daki düzeltilmiş akış. `A(I) = A(I+1)` ise `CNT` artar; değilse `CNT > MAX` kontrol edilir, doğruysa `MAX = CNT` ve `PL = I - MAX + 1`; iki durumda da `CNT = 1`. Döngü `N-1`'e kadar döner, sonda `A(PL)` ve `MAX` yazdırılır. Örnek dizi için sonuç: 8. eleman, değeri 6, tekrar sayısı 4 (python ile doğrulandı).

**Soru 2** (ekrandan, 00:40:00): `3 5 5 5 4 4 7 3 3 6 6 6 6` dizisinde en uzun tekrar sondadır. Soru 1'deki akış bunu yakalar mı?

> **Çözüm (derste kısmen verildi):** Yakalamaz. `MAX` yalnız eşitsizlik görüldüğünde güncellendiği için sondaki dört 6 değerlendirilmez; akış 2. elemandan başlayan 5'leri (3 tekrar) bulur. Derste akışın yeniden çizilmesi gerektiği söylendi ama düzeltilmiş hali çizilmedi.

> **Çözüm (derste verilmedi):** En basit düzeltme, döngüden çıktıktan sonra son tekrarı da değerlendirmektir: döngü bitince bir kez daha `CNT > MAX` sorulur; doğruysa `MAX = CNT` ve `PL = N - MAX + 1` yapılır, sonra `A(PL), MAX` yazdırılır. Bu ekle ikinci dizide sonuç 10. eleman, değeri 6, tekrar sayısı 4 olur; birinci dizinin sonucu değişmez (python ile denendi).

**Soru 3** (derste sözlü, 00:39:21): `N` elemanlı bir dizide değerlerin 0 ile 9 arasında olduğu biliniyor. Hangi elemandan kaç tane olduğunu nasıl bulursunuz?

> **Çözüm (derste verildi):** 10 elemanlı bir sayaç dizisi açılır; her elemanın değeri bu dizinin indisi olarak kullanılıp ilgili göz bir artırılır. Sonunda her gözdeki sayı o değerin kaç kez geçtiğini verir. Değer aralığı çok büyükse (0-4 milyar) bu yöntem yer açısından mantıklı değildir.

**Soru 4** (derste sözlü, 00:53:29): Bir matris içerisinde 71 değerinin kaç kere geçtiğini nasıl bulursunuz?

> **Çözüm (derste verildi):** Matrisin bütün elemanları tek tek kontrol edilir; 71'e eşit olan her eleman için bir sayaç bir artırılır.

**Soru 5** (ekrandan, 00:55:00): Bir matris var, içinde 0-255 arası değerler var (8 bit gri seviye resim). Her değerden kaç tane olduğunu (histogramı) bulan akışı çizin.

> **Çözüm (derste verildi, ana adım):** 256 gözlü `CNT` dizisi sıfırla ilklendirilir. Matrisin her elemanı için `CNT(A(I)(J)+1) = CNT(A(I)(J)+1) + 1` yapılır (ekrandan, 01:55:00). İndislerin 1'den başlaması nedeniyle değere 1 eklenir.

> **Çözüm (derste verilmedi, akışın bütünü):** Derste verilen adımlarla kurulan akış (python ile denendi: rastgele 4 × 5 matriste sayımlar doğrudan sayımla aynı):
>
> ```text
> START
> [ N, M, A(N)(M) ]
> [ K <- 1 || 1 ; bitiş 256 ]  ->  [ CNT(K) = 0 ]
> [ I <- 1 || 1 ; bitiş N ]
>     [ J <- 1 || 1 ; bitiş M ]
>         [ CNT(A(I)(J)+1) = CNT(A(I)(J)+1) + 1 ]
> [ K <- 1 || 1 ; bitiş 256 ]  ->  [ K-1, CNT(K) ]   (değer, adet)
> STOP
> ```

**Soru 6** (ekrandan, 01:25:00): 7 × 8 boyutlu A matrisi ile 8 × 5 boyutlu B matrisi çarpılırsa C'nin boyutu ne olur?

> **Çözüm (derste verildi):** 7 × 5. A'nın sütun sayısı (8) B'nin satır sayısına (8) eşit olduğu için çarpım tanımlıdır; sonuç A'nın satır sayısı kadar satır, B'nin sütun sayısı kadar sütun içerir.

**Soru 7** (ekrandan, 01:45:00): A ve B matrislerini çarpıp C'yi bulan akışı çizin.

> **Çözüm (derste verildi):** Bölüm 9'daki akış: `I` (1..L), `K` (1..N), `SUM = 0`, `J` (1..M) ve `SUM = SUM + A(I)(J) * B(J)(K)`; J döngüsü bitince `C(I)(K) = SUM`; sonunda C yazdırılır. Doğrulamak için `I, K, J, SUM, A(I)(J), B(J)(K)` sütunlu bir analiz tablosu doldurulur.

## Dersin Toparlaması

Bu derste üç problem üzerinden akış diyagramı kurma ve akışı test etme pratiği yapıldı. İlk problemde bir dizide art arda en çok tekrar eden eleman arandı. Öğrencilerle birlikte çizilen akışta döngü sınırının `N-1` olması, sonucun konumla (`PL = I - MAX + 1`) saklanıp `A(PL)` ile yazdırılması ve sayacın her tekrar sonunda iki kolda da sıfırlanması gerektiği görüldü. En uzun tekrarın dizinin sonunda olduğu bir örnek akışın eksik kaldığını gösterdi ve sınır değer testinin önemi vurgulandı. Ek dizi önerisi üzerinden zaman karmaşıklığının yanında yer karmaşıklığı da konuşuldu.

İkinci problemde 8 bit gri seviye bir resmin histogramı, yani 0-255 arası her değerin bir matriste kaç kez geçtiği bulundu. Anahtar fikir, matris elemanının değerini 256 gözlü bir sayaç dizisinin indisi olarak kullanmak (`CNT(A(I)(J)+1)`) ve bu diziyi önce sıfırlamaktı. Üçüncü problemde matris çarpımı (7 × 8 ile 8 × 5, sonuç 7 × 5) üç iç içe döngüyle akışa döküldü; toplamın geçici bir değişkende tutulup en son matrise atanması tercih edildi. Ders, bir akışın doğruluğunu değişken tablosuyla analiz ederek kendi başına kontrol etme çağrısıyla kapandı; matris çarpımı akışı üzerinde sonraki derste çalışmaya devam edileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
