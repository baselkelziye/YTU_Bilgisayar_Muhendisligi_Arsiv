# Ders 5 Genişletilmiş Notu: Kavramsal Ağaç Benzerlikleri, Birlikte Geçme ile Anlamsal Uzaylar, word2vec ve FastText

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Geçen Dersin Tekrarı: LSI ve LDA
- 2. Kavramsal Ağaç (Taksonomi) ile Anlamsal Benzerlik
- 3. Birbiri Yerine Kullanılan Kelimeler
- 4. Kelime Kümeleme ve Matris Türleri
- 5. Anlamsal Uzay: Neden Koordinat?
- 6. Birlikte Geçme Matrisleri ve Çok Boyutlu Ölçekleme (MDS)
- 7. Anlamsal Uzayların Metin Sınıflandırmada Kullanımı
- 8. Kelime Yörüngeleri
- 9. Sinirsel Dil Modelleri: word2vec
- 10. FastText
- 11. Kelime Vektörlerinin Değerlendirilmesi ve Metin Vektörleri
- 12. Kelime Öbekleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Geçen Dersin Tekrarı: LSI ve LDA

Ders, anlamsal uzaylar bölümünün kısa bir tekrarıyla başladı. Geçen hafta istatistiksel dil modelleri, Markov varsayımı ve $K=1$, $K=2$ ile metin üretimi denemeleri görülmüştü; hangi birlikteliklerin anlamlı, hangilerinin anlamsız çıktığı konuşulmuştu.

### 1.1 Saklı Anlam İndeksleme (LSI) hatırlatması

Kedi ve köpek örneğinde 8 doküman ve 9 kelimelik bir doküman-kelime matrisi vardı. Dokümanların sınıf bilgisi sisteme verilmiyordu; numaralar yalnız okuyucuya kolaylık olsun diye yazılmıştı. Matris olduğu gibi hiyerarşik kümelemeye verildiğinde dokümanlar sınıflarına göre iyi ayrılmıyordu. <!-- BELİRSİZ: Hocanın ham matrisin dendrogramındaki birleşme sırasını anlattığı yer (00:06:36) altyazıda bozuk; "6 ile 8, sonra 3, 7, 4 ... 7 ile 5" gibi geçiyor. -->

Sonra SVD ile matris çarpanlarına ayrıldı ve 9 boyutlu dokümanlar, son bileşenler atılarak 5 boyuta indirildi. Bu yeni dokümanlar hiyerarşik kümelemeye verildiğinde ilk dört doküman (kedi) ve son dört doküman (köpek) kendi aralarında birleşti. Bu, sisteme verilmeyen sınıf bilgisinin yalnız kelimelerden çıkarılabildiğini gösterir.

Büyük ölçekli LSI için bir kod (`lsi_modeli.m`) gösterildi (slayt "Büyük ölçekte LSI", ekrandan, 00:10:00 karesindeki küçük resim). Kodda kelimelerin koordinatları üretilir; şekildeki kırmızı ve mavi kareler yakınlaştırılmış bölgelerdir. Mavi karede "gaz, metreküp, enerji, bakanlık, İran" gibi gazla ilgili kelimeler, yanında "metrekare, anlaşma" gibi kelimeler bir aradaydı. Yakın anlamlı kelimeler yakın koordinatlara düşmüştü.

### 1.2 Latent Dirichlet Allocation (LDA)

LDA bir konu modelleme (topic modeling) yöntemidir. Varsayımı şudur: kelimeler belli olasılıklarla konuları oluşturur, konular da belli oranlarla dokümanları oluşturur. Bir doküman birden fazla konudan bahsedebilir; LDA, farklı konular içeren dokümanlarda konu bütünlüğü sağlayan parçaları bulmak için de kullanılır.

Haber metinleriyle 4 konu çıkarılan örnekte (`lda_modeli.m`, ekrandan, 00:10:00) her konu bir kelime bulutuyla gösterildi. Bir konu için kelimeler, geçtiklerinde o konunun olasılığını yükselten kelimelerdir:

- Topic 1: dizi, film, aşk, şarkıcı, müzik, akşam, sanatçı gibi magazinle ilgili kelimeler.
- Topic 2: banka, faiz, aylık, sermaye, bankacılık gibi ekonomiyle ilgili kelimeler.
- Topic 3: almanya, ırak, çin, endeksi, küresel gibi dünya ile ilgili kelimeler.
- Topic 4: otomobil, yerli, su, eğitim, turizm, şirket gibi daha karışık bir konu.

Aynı konunun içindeki kelimeler, öteki konulardaki kelimelere göre birbirine biraz daha benzerdir. Bu da LDA'yı kelime benzerliği için bir yol yapar.

## 2. Kavramsal Ağaç (Taksonomi) ile Anlamsal Benzerlik

### 2.1 Kavramsal ağaç nedir?

Hayat bilgisi veri tabanlarında görülen "is-a" (bir türüdür) ilişkileri bir hiyerarşi kurar: X is-a Y, Y is-a T, T is-a A gibi. Bu ağaca kavramsal ağaç ya da taksonomi denir. Elimizde böyle bir ağaç varsa iki temel yaklaşımla benzerlik bulunabilir (slayt 27):

- Bağ sayma: yalnız taksonomi gerekir. Kabaca, ağaç üzerinde bir düğümden ötekine gitmek için ne kadar uzun yol gerekiyorsa iki kavram birbirine o kadar uzaktır.
- Ortak (müşterek) bilgi (mutual information): taksonomi ve derlem (korpus) birlikte gerekir.

### 2.2 WordNet ve synset

Bu yöntemlerde WordNet kullanılır. Türkçe için küçük bir WordNet vardır; yöntemlerin kullandığı ise büyük İngilizce WordNet'tir. WordNet'in düğümleri synset'lerdir. Synset'ler arasında ilişkiler (ilişki türleri) vardır; yani yine üçlüler vardır. Farkı şudur: hayat bilgisi veri tabanında "şu kavramla şu kavram arasında şu ilişki var" denirken WordNet'te "şu synset ile şu synset arasında şu ilişki var" denir.

Synset, aynı anlama gelen kelimeler kümesidir; içindeki kelimeler birbirinin eş anlamlısıdır. Bir kelimenin birden fazla anlamı varsa, örneğin beş anlamı varsa, o kelime beş farklı synset'in içinde bulunur. WordNet uzun emekler sonucunda elle oluşturulmuştur. Ağacın tek bir kökü vardır, her şey ona bağlıdır; ondan somut şeyler ve soyut şeyler diye iki kavram çıkar, altları bölüne bölüne gider. Hocanın aktardığına göre içinde 200 bine yakın synset vardır.

> **Ek bilgi (derste anlatılmadı):** Hocanın "tink" diye andığı kök, İngilizce WordNet'te büyük olasılıkla isimler hiyerarşisinin en üstündeki "entity" synset'idir. WordNet 3.0'da büyük olasılıkla yaklaşık 117 bin synset bulunur; hocanın verdiği sayı büyük olasılıkla kaba bir hatırlamadır.

### 2.3 Leacock & Chodorow (1998)

Slayttaki formül (ekrandan, 00:13:30):

$$sim_{LC}(c_1, c_2) = -\log \frac{len(c_1, c_2)}{2L}$$

- $len(c_1, c_2)$: iki synset arasındaki en kısa yolun uzunluğu. Ağaç WordNet'in yalnız is-a ilişkileriyle kurulmuş ağaçtır. Uzunluk benzerlik değeriyle ters orantılıdır.
- $L$: tüm taksonominin derinliği, yani ağacın maksimum derinliği.

Logaritma ölçeklemeyi sağlar; baştaki eksi işareti uzaklığı (benzemezliği) benzerliğe çevirir. Hoca sezgiyi şöyle verdi: maksimum derinliği 10 olan bir ağaçta iki kavram arasında 1 birimlik mesafe varsa birbirlerine çok yakındırlar, 8 birimlik mesafe varsa çok uzaktırlar.

Örnek (Wu & Palmer slaytındaki ağaç üzerinde, ekrandan, 00:20:00): $c_1$'den $c_2$'ye en kısa yol $c_1 \to$ üst düğüm $\to lcs \to c_2$ olmak üzere 3 bağdır. Hoca ağacın maksimum derinliğini 7 saydı ve sonucu "3 bölü 7 gibisinden bir şey" diye anlattı.

> **Ders sonrası not:** Formülün paydası $2L$ olduğu için oran $3/(2 \cdot 7) = 3/14$ olur. Doğal logaritmayla $sim_{LC} = -\ln(3/14) \approx 1.54$, 10 tabanında $\approx 0.67$ çıkar (python ile hesaplandı). Hoca derinliği düğüm seviyesi sayarak 7 buldu; derinliği bağ sayısıyla ölçen bir tanımda değer 6 olur.

### 2.4 Wu & Palmer (1994)

Slayttaki formül (ekrandan, 00:20:00):

$$sim_{WP}(c_1, c_2) = \frac{2 \times N_3}{N_1 + N_2 + 2 \times N_3}$$

Wu & Palmer yeni bir kavram kullanır: en yakın ortak üst synset, $lcs(c_1, c_2)$. Bu, iki kavramın ikisini de altında barındıran en yakın synset'tir.

- $N_1$ ve $N_2$: $c_1$ ve $c_2$'nin $lcs(c_1,c_2)$'ye is-a bağlarıyla uzaklıkları. Benzerlik değeriyle ters orantılıdır: kavramlar ortak üst synset'lerinden ne kadar uzaksa birbirlerinden de o kadar uzaktırlar.
- $N_3$: en yakın ortak üst synset'in kök synset'e is-a bağlarıyla uzaklığı. Büyüklüğü ortak üst synset'in spesifikliğini gösterir; benzerlikle doğru orantılıdır.

Slayttaki ağaçta hoca $N_1 = 2$, $N_2 = 1$ değerlerini gösterdi.

Hoca $N_3$'ün yönünü sınıfa sordu (bkz. Örnek Sorular). Ağacın üstündeki kavramlar çok genel, altındakiler çok spesifiktir. $lcs$ köke yakınsa iki kavramın ortak noktası çok genel bir kavramdır; $lcs$ ağacın dibine yaklaştıkça iki kavram daha spesifik bir kavramın altında toplanır ve birbirine daha benzer olur. Wu & Palmer da yalnız ağacı kullanır, başka ek bilgiye ihtiyaç duymaz.

### 2.5 Jiang-Conrath (1997) ve Lin (1998)

Bu iki yöntem taksonominin yanında bir derlem de kullanır. Önce bir kavramın derlemdeki olasılığı tanımlanır (ekrandan, 00:23:00):

$$P(concept) = \frac{freq(concept)}{freq(root)}$$

$freq(x)$, derlemde $x$ synset'inin tepesinde bulunduğu bütün synset'lerin frekanslarının toplamıdır. Slayttaki ağaçta $x$'in altında $x1$, $x2$, $x2$'nin altında $x21$ ve $x22$ vardır:

$$freq(x) = f(x) + f(x1) + f(x2) + f(x21) + f(x22)$$

Yani bir kavramın frekansı, kendisinin derlemde kaç kez geçtiği artı altındaki her şeyin frekansıdır. Bu tanımdan kökün frekansı da çıkar: kökün altında her şey vardır, dolayısıyla $freq(root)$ derlemdeki toplam kelime sayısına eşittir.

Slayttaki benzerlik formülleri (ekrandan, 00:25:00):

$$sim_{JC}(c_1, c_2) = 2\log\big(p(lcs(c_1,c_2))\big) - \big(\log p(c_1) + \log p(c_2)\big)$$

$$sim_{L}(c_1, c_2) = \frac{2 \log\big(p(lcs(c_1,c_2))\big)}{\log p(c_1) + \log p(c_2)}$$

Hoca iki formülü iki parçaya ayırdı: A, ortak üst synset'e ait terim ($2\log p(lcs)$); B, iki kavramın terimlerinin toplamı. Jiang-Conrath A'dan B'yi çıkarır, Lin A'yı B'ye böler. İkisi de aynı yöne gider: A büyüdükçe benzerlik büyür, B büyüdükçe küçülür. Slayttaki yorum:

- A, her iki kavramı da içeren en spesifik kavramı kullanır; kabaca iki kavramın beraber geçtiği doküman sayısına benzer.
- B, kabaca iki kavramdan herhangi birini içeren doküman sayısına benzer.

> **Ders sonrası not:** Olasılıklar 1'den küçük olduğu için bütün logaritmalar negatiftir; bu yüzden "büyür/küçülür" yorumunda işarete dikkat etmek gerekir. Büyük olasılıkla Jiang-Conrath'ın özgün çalışmasında slayttaki ifade ($2\log p(lcs) - \log p(c_1) - \log p(c_2)$) bir uzaklık olarak tanımlanır ve benzerlik genelde bu uzaklığın tersi alınarak elde edilir. Lin benzerliği ise 0 ile 1 arasında değer alır.

> **Ek bilgi (derste anlatılmadı):** $-\log p(c)$ niceliğine bilgi kuramında büyük olasılıkla bir kavramın "bilgi içeriği" (information content) denir. Nadir (spesifik) kavramların bilgi içeriği yüksek, genel kavramlarınki düşüktür; kökün olasılığı 1 olduğu için bilgi içeriği 0'dır. Resnik, Jiang-Conrath ve Lin ölçüleri büyük olasılıkla bu nicelik üzerine kuruludur.

### 2.6 Karşılaştırma ve taksonomi yöntemlerinin sorunu

Yöntemler küçük bir veri kümesinde karşılaştırılmış (slayt "Karşılaştırma"). 38 kelime çifti insanlara verilmiş, her çift için örneğin 0 ile 1 arasında bir benzerlik puanı istenmiş ve insanların puanlarının ortalaması alınmış. Sonra her yöntemin bulduğu benzerliklerle bu ortalamalar arasındaki korelasyona bakılmış: korelasyon ne kadar yüksekse yöntem o kadar başarılı sayılmış. Sonuçlar fena değil.

Hoca bu yöntemlerin küçük ve spesifik işler için uygun, büyük işler için kolay uygulanabilir olmadığını söyledi. Nedeni sınıfla birlikte bulundu:

- Derlem toplamak sorun değildir; derlem etiketsiz veridir, içindeki kelimelerin frekansları sayılır.
- Asıl sorun ağaçtır. Herhangi bir dil için kavramsal ağacı otomatik oluşturmak kolay değildir.
- Ağaç kurulsa bile dil yaşayan bir şeydir: her gün yeni kavramlar ve ifadeler girer, kelimelerin kullanım frekansları zamanla değişir. 50 yıl önce yazılmış kitaplarla bugünküler arasında ciddi kelime frekansı farkları vardır; eskiden kullanılıp artık kullanılmayan ya da yeni çıkmış birçok kelime vardır. Ağacın sürekli güncellenmesi gerekir, bilinmeyen kelimeler büyük sorun olur.

Bu sorunları yavaş yavaş çözmek için sonraki yöntemlere geçildi.

## 3. Birbiri Yerine Kullanılan Kelimeler

Slayttaki fikir (Deniz Yüret, 2009; ekrandan, 00:30:00):

```text
W1 W2 X1 W3 W4
W1 W2 X2 W3 W4
```

İki dizenin ilk iki ve son iki kelimesi aynıdır. Buna göre X1 ve X2 birbirinin yerine, aynı bağlamda kullanılmıştır; demek ki aralarında bir ilişki vardır. "W1 W2 _ W3 W4" bir bağlamdır. X1 ve X2 kaç farklı bağlamda birbiri yerine kullanıldıysa aralarındaki bağ o kadar güçlüdür.

Bir bitirme projesinde bulunan örnekler slaytta "kelime1 kelime2 kaç farklı bağlamda birbirinin yerine kullanıldığı" biçiminde verildi (ekrandan, 00:31:30):

| Çift | Bağlam sayısı | Çift | Bağlam sayısı |
|---|---|---|---|
| dolar - ytl | 939 | meclis - tbmm | 219 |
| bulun - olmak | 619 | belir - kaydet | 194 |
| avro - euro | 459 | futbol - oyun | 189 |
| kanun - yasa | 350 | art - azal | 187 |
| avro - dolar | 344 | avro - ytl | 182 |
| oyna - yap | 309 | alan - saha | 177 |
| dolar - lira | 251 | gerek - iste | 176 |
| dolar - euro | 249 | lira - ytl | 173 |
| milyar - milyon | 241 | haziran - nisan | 161 |

Örneğin dolar ile YTL 939 farklı bağlamda birbirinin yerine kullanılmıştır; eş anlamlı değillerdir ama gerçekten birbirinin yerine kullanılabilirler. Bu yöntemle bulunan ilişkiler farklı türlerdendir:

- Eş anlamlı: kanun-yasa, avro-euro, alan-saha.
- Zıt anlamlı: art-azal (artmak-azalmak).
- Kardeş kavram: haziran-nisan, dolar-euro. Kardeş kavramlar, is-a ağacında aynı üst kavrama bağlı kavramlardır. Örneğin "para birimi"nin altında dolar, euro, sterlin, lira, frank gibi kavramlar vardır; hepsi bir üstte tek bir kavrama bağlıdır. (Euro ile avro ayrıca eş anlamlıdır, o ayrı bir mesele.)

## 4. Kelime Kümeleme ve Matris Türleri

Slayttaki fikir (ekrandan, 00:40:00): kelimeleri

- terim × doküman matrisine göre,
- birlikte geçme matrisine göre,
- sınıflarda yer alma olasılıklarına göre

kümelersek aynı kümede yer alan kelimeler birbirine benzerdir diyebiliriz. Üç matrisin satır ve sütunları:

- Satırlarda terim, sütunlarda dokümanlar.
- Satırlarda terim, sütunlarda terim.
- Satırlarda terim, sütunlarda sınıf olasılıkları.

### 4.1 Terim-doküman ve doküman-terim matrisi

Hoca geçen haftanın kedi-köpek matrisini açıp bunun nasıl bir matris olduğunu sordu. Bir öğrenci doğru olarak bunun doküman-terim matrisi olduğunu söyledi (satırlarda dokümanlar, sütunlarda kelimeler); transpozu terim-doküman matrisidir.

- Doküman-terim matrisinde her doküman, içinde geçebilecek terim sayısı kadar boyutlu bir uzayda bir noktadır. Kedi-köpek örneğinde 9 kelime olduğu için dokümanlar 9 boyutlu uzayda noktalardır.
- Terim-doküman matrisinde her terim, doküman sayısı kadar boyutlu bir uzayda bir noktadır. "Kedi" terimi 8 boyutlu bir noktadır. 50 bin doküman olsaydı her terim 50 bin boyutlu bir nokta olurdu; her doküman bir özellik gibi düşünülür.

Bu matrisle terimler kümelenebilir.

### 4.2 Birlikte geçme matrisi

Birlikte geçme matrisinin satırlarında da sütunlarında da terimler vardır. $(i,j)$ hücresi $i$'inci kelimenin $j$'inci kelimeyle kaç kez birlikte geçtiğidir. Birlikte geçme farklı biçimlerde sayılabilir: aynı cümlede, aynı metinde ya da örneğin 5 kelimelik bir pencerenin içinde. Matris terim sayısı × terim sayısı boyutludur; satırlara da sütunlara da baksanız her terim, terim sayısı uzunluğunda bir vektördür ve kümeleme algoritmaları yine çalıştırılabilir.

### 4.3 Sınıflarda yer alma olasılıkları

İlk iki matrisle kelime kümelemek için dokümanların sınıflarına gerek yoktur. Sınıflarda yer alma olasılıklarını kullanmak içinse dokümanların hangi sınıfta olduğunu bilmek gerekir; Naive Bayes'teki gibi her kelimenin her sınıfta ne kadar yer aldığına bakılır. Her sınıfta yer alan bir kelime pek anlamlı değildir; bazı sınıflara özgü kelimeler daha değerlidir. Bu matriste her terim, sınıf sayısı kadar boyutlu bir uzayda bir noktadır ve yine kümelenebilir.

## 5. Anlamsal Uzay: Neden Koordinat?

Anlamsal uzay, kelimelerin anlamsal benzerliklerinin bir temsilidir: kavramların anlamsal yakınlıklarına göre yer aldıkları bir uzay. Anlamsal yakınlığa bağlı koordinatların nasıl oluşturulabileceğine dair yollar (slayt "Anlamsal Uzay", ekrandan, 00:40:00 karesindeki küçük resim):

- Terim-doküman matrislerini ayrıştırma (LSI, SVD ile). Görüldü.
- Konu modelleri (LDA). Görüldü.
- Birlikte geçme matrisleri (MDS; slaytta GloVe da anılıyor). Bu derste.
- Sinirsel dil modelleri (word2vec, FastText). Bu derste.

Koordinat atamak kümelemenin ötesinde bir şey sağlar: çok daha yüksek çözünürlüklü benzerlik. Kümeleme yaptığınızda örneğin 10 küme ve her kümede 100 kelime bulursunuz; bir kümenin içindeki kelimelerin birbirine ne kadar benzediği konusunda elinizde bir bilgi yoktur. "Şu kelimeye en yakın kelimeler hangileri?" diye sorduğunuzda kümeleme yetmez. Kavramların koordinatları bulunabilirse bu soruya çok güzel cevaplar verilebilir.

## 6. Birlikte Geçme Matrisleri ve Çok Boyutlu Ölçekleme (MDS)

### 6.1 Harris'in fikri ve arama motoru denemesi

Birlikte geçme matrisleri terim × terim matrislerdir. Harris'e göre birlikte kullanılan kavramlar anlamca birbirine benzer. Birlikte kullanım aynı cümlede, aynı metinde ya da sabit bir kelime penceresinde olabilir.

Hocanın yıllar önce yaptığı bir denemede (slayt "Örnek çalışma-1: Kelimelerin Anlamsal Benzerlik Ölçümü, Amasyalı, 2006") iki kavramın birlikte geçmesi arama motoruyla ölçüldü. Arama motoruna "kelime1 kelime2" sorgusu gönderildiğinde aslında "bu iki kavramın ikisini birden içeren sayfaları getir" denir. Arama motoru sonuçları sıralayıp sayfa sayfa gösterir, ama ayrıca toplam kaç sonuç bulduğunu da söyler. Varsayım şudur: iki kavram arasındaki ilişki güçlüyse ikisinin birlikte yer aldığı web sayfası sayısı da yüksektir. Burada birlikte geçme, internette aynı web sayfasında geçme olarak yorumlanır.

Veri kümesi 1'de 10 yer adı (berber, bakkal, kuaför, ...), 10 hayvan adı ve 10 taşıt adı vardı. Her kelime her kelimeyle ikili olarak sorgulandı (berber-bakkal, berber-kuaför, berber-akbaba, berber-baykuş, berber-otobüs, berber-cip, ...). "Yer, hayvan, taşıt" grupları yalnız okuyucuya bilgi olsun diye verilmişti; sistemde kullanılmadı. Sonuçta $30 \times 30$'luk bir matris elde edildi: $(i,j)$ hücresinde $i$'inci ve $j$'inci kelimenin kaç web sayfasında birlikte geçtiği (örneğin berber ile bizon) yazar. Bu matris yalnız "ilişkili mi?" bilgisini değil, "ne kadar ilişkili?" bilgisini de verir.

### 6.2 Çok boyutlu ölçekleme (MDS)

Multidimensional Scaling (çok boyutlu ölçekleme, ÇBÖ), aralarındaki mesafeler bilinen nesneleri alır ve bu nesnelerin koordinatlarını üretir. Üretilen koordinatlar, verilen mesafe matrisindeki değerlerle en uyumlu koordinatlardır.

Hocanın benzetmesi: eskiden her şehrin her şehre karayolu mesafesini veren üçgen tablolar yayımlanırdı. Bu matris simetriktir (alt üçgen üst üçgenle aynıdır). Bu matris MDS'ye verilirse şehirlerin koordinatları, yani ülkenin haritası noktalar hâlinde elde edilir.

MDS aslında nesne sayısı kadar boyut üretir. PCA'de olduğu gibi baştaki boyutlar en önemlileridir; ilk bir iki boyut genel yapıyı oldukça iyi gösterir.

Bir fark vardır: birlikte geçme sayısı bir yakınlık ölçüsüdür, değeri büyüdükçe iki kavram birbirine daha yakındır. MDS ise uzaklıklarla çalışır. Bu yüzden benzerlik matrisinden uzaklık matrisine geçmek gerekir. Bir öğrenci büyük bir sayıyı bu değerlere bölmeyi önerdi; hoca bunun da olabileceğini söyledi. Çalışmada uzaklık = 1/yakınlık kullanıldı.

### 6.3 Sonuçlar

Veri kümesi 1 için Google ile bulunan benzerlik matrisinden hesaplanmış iki boyutlu koordinatlar (ekrandan, 00:50:00):

- Hayvanlar bir bölgede: balina, akbaba, aslan, akrep, arı, bit, baykuş; at ve bizon biraz ayrı.
- Taşıtlar bir bölgede: cip, ambulans, sedan, traktör, limuzin, tren, otomobil, araba, taksi, otobüs.
- Yerler bir bölgede: dershane, park, okul, hastane, kuaför, otel, bakkal, büfe, berber.

Sisteme hangi kelimenin hangi gruba ait olduğu söylenmedi; yalnız aynı web sayfasında birlikte geçme sayıları kullanıldı. Buna rağmen benzer terimler yakın koordinatlara düştü. "Ahır" ile "at", "bizon" yakın çıktı; "limuzin" ile "tren" çok yakın çıktı.

Veri kümesi 2'de ev eşyaları, hayvanlar ve giyecekler vardı. Hoca "Birinci kümede şanslı mıydık?" diye sordu; ikinci kümede de sonuç fena değildi. İlginç bir sonuç "bit" ile "divan"ın yakın çıkmasıydı (bkz. Örnek Sorular).

Veri kümesi 3 daha karmaşıktı: 6 kategori, her birinden 6 örnek, toplam 36 terim. Benzer şeyler ilk ikisi kadar olmasa da yine yakın çıktı. Hoca şuna dikkat çekti: şekillerde yalnız birinci ve ikinci boyut gösteriliyor. MDS yalnız iki boyut üretmez; 36 terim için 36 boyut üretir. Daha fazla boyut kullanılırsa daha iyi sonuçlar elde edilebilir.

Bu koordinatlarla kelimeler sınıflandırıldı: veri kümelerinde 2 ve 10 boyutlu (ve 4 boyutlu) temsillerle SVM, C4.5, Random Forest gibi eğiticili yöntemler ve EM gibi eğiticisiz bir yöntem denendi; sonuçlar fena değildi. V1 ve V2 için en fazla 30, V3 için en fazla 36 boyut çıkabilir.

### 6.4 Teknik terim sınıflandırma

Daha büyük bir denemede (slayt "Örnek çalışma-2: Teknik Terim sınıflandırma") 967 teknik terimin koordinatları elde edildi. Bunun için Google değil, rastgele indirilmiş 15.000 web sitesinden oluşan bir külliyat kullanıldı. Nedeni hesapla bulundu: birlikte geçme matrisi $967 \times 967$ olur, yani $935.089$ sorgu gerekir; bu kadar sorgu bedava yapılamaz. 20.000 terim olsa $400$ milyon sorgu gerekirdi (python ile doğrulandı).

İki boyutlu koordinatlarda terimlerin üzerindeki işaretler sınıflarını (tıp, edebiyat, zooloji, ekonomi) gösteriyordu; sınıf bilgisi koordinatların elde edilmesinde kullanılmadı. Sınıflar birbirinden oldukça iyi ayrıldı; örneğin tıbbi terimler uzunlamasına bir bölgede toplandı. Bu kadar iyi sonucun nedeni teknik terimlerin doğasıdır: teknik terimler spesifiktir ve kendi alanlarındaki terimlerle birlikte geçmeye yatkındır, başka alanların terimleriyle pek birlikte geçmez. Bu yüzden bu yöntemle sınıflandırılmaları kolaydır.

## 7. Anlamsal Uzayların Metin Sınıflandırmada Kullanımı

### 7.1 Deney düzeni

Slayt "Örnek çalışma-3: Metin sınıflandırma (Amasyalı, Beken, 2009)":

- 5 farklı haber sınıfı (ekonomi, magazin, sağlık, siyasi, spor), her sınıfa ait 230'ar metin.
- Her sınıftan 150'şer metin eğitim, 80'er metin test.
- Kelime kökleri (gövdeleri) bulundu; farklı gövde sayısı yaklaşık 4500. Yani 4500 terim.

Slayt "Anlamsal Uzayların Metin Sınıflandırmada Kullanımı" (ekrandan, 01:00:00):

- 4500 kelimenin sayısal karşılıklarını elde etmek için 15.000 web sitesinden oluşan bir külliyat kullanılmış.
- Kelimelerin birbirine anlamsal yakınlık matrisi: bu külliyatta birlikte geçtikleri doküman sayıları.
- uzaklık = 1/yakınlık.
- MDS (ÇBÖ).
- MDS'de ilk 100 ve ilk 10 boyut alınmış.

Hoca külliyat, derlem ve korpusun aynı anlamda kullanıldığını, "aynı synset'teki kelimeler" olduğunu esprili biçimde belirtti.

### 7.2 Metinlerin koordinatı

Şekildeki her nokta bir kelimeyi değil bir metni gösteriyordu. Hoca, MDS'nin çıktısının ne olduğunu sordu: koordinatlar, ama kelimelerin koordinatları. Metinlerin koordinatı doğrudan yoktur.

Kelimelerden metne geçmenin en klasik yolu, metnin içindeki kelimelerin koordinatlarının ortalamasını almaktır. Bir metinde 5 kelime varsa ve her kelimenin 50 boyutlu bir karşılığı varsa, 5 kelimenin birinci boyutlarının ortalaması metnin birinci boyutu, ikinci boyutlarının ortalaması ikinci boyutu, ..., ellinci boyutlarının ortalaması ellinci boyutu olur. Böylece kelimeler kaç boyutluysa metinler de o kadar boyutlu olur. Şekildeki tek bir üçgen, arka planda bir sürü kelime noktasının ortasıdır.

Şekilde farklı sınıflardan haberler farklı bölgelerde toplanmıştı. Sınıflandırıcıların iyi çalışması için aynı sınıfın örnekleri birbirine yakın, farklı sınıfların örnekleri birbirinden uzak olmalıdır; her şey üst üste binerse sınıflandırma imkânı kalmaz.

**Soru:** Bütün sınıflar değil de belli iki sınıf birbirine geçiyorsa, o iki sınıfın birbirine benzer olduğu yorumu yapılabilir mi?
**Cevap:** Yapılabilir. Bu karışıklık matrisinden de çıkar, ama buradan da söylenebilir. Örneğin spor ile magazin biraz iç içe girmişti; belki futbolcuların sosyal hayatlarına dair magazin haberleri vardı. Ekonomi ile politikanın da kesişimleri vardı. Yalnız birinci ve ikinci boyut bu yorum için yetmez; ikinci-üçüncü ya da birinci-ikinci-üçüncü boyutlara birlikte bakmak iyi olur.

### 7.3 Sonuçlar

Slayttaki tablolar (ekrandan, 01:04:50):

| Sınıflandırma algoritması | 100 boyutlu metinler | 10 boyutlu metinler |
|---|---|---|
| Lineer Regresyonla Sınıflandırma | 93.25 | 89 |
| Pace Regresyonla Sınıflandırma | 92.75 | 88.5 |
| En Yakın Komşu | 70 | 79 |
| Destek Vektör Makineleri | 90 | 89.75 |
| Rastgele Ormanlar (100 ağaçlı) | 90.75 | 87.75 |

Karşılaştırma için 4500 boyutlu klasik temsilde Klasik Naive Bayes %87.25 (tf), Diskrit Naive Bayes %85.75 (tf) ve %89.25 (tfidf) başarı vermişti; aynı tabloda 100 boyutlu (tf/tfidf) temsillerle Lineer Regresyonla Sınıflandırma 81.75/84.5, Destek Vektör Makineleri 80.25/87.75 gibi değerler vardı. Hoca, 4500 boyutta yaklaşık %89'a çıkılabilirken metinleri 100 boyuta indirince yine %90 civarında başarı elde edildiğini söyledi. Sonuç: daha yüksek başarı, metin temsilinde daha az bellek.

### 7.4 Yöntemin özellikleri

- Dilden bağımsızdır: hiçbir dile özgü bilgi kullanılmaz, yalnız "bu kelimeyle bu kelime kaç kez birlikte geçti" sayılır.
- Sondan eklemeli dillerde terim sayısı çok yüksek değerlere çıkar; bu kötüdür.
- Çok anlamlı (eş sesli) kelimeler sorun olur. Örneğin İngilizce "apple" kelimesinin bir firma, bir de meyve anlamı vardır. Koordinatı iki farklı konunun tam ortasına düşer, ikisine de yakın olmaz; ya da birbiriyle ilgisiz şeyleri birbirine yaklaştırır, örneğin armutla cep telefonunu yakın hâle getirir.

> **Hocanın vurgusu:** Burada bir kelime için sabit bir koordinat belirliyoruz. Kelimenin birden fazla anlamı varsa anlamına göre bir şey yapma şansımız kalmıyor. İleride göreceğimiz sinirsel dil modellerinde kelimenin koordinatı etrafındaki kelimelere göre değişecek, sabit olmayacak.

## 8. Kelime Yörüngeleri

Aradan sonra hoca, metinleri temsil etmeye farklı bir bakış açısı sunan bir çalışmayı anlattı (slayt "Örnek çalışma-4: Kelime yörüngeleri (Amasyalı, Yener, Kaplan, 2012)").

### 8.1 Fikir

Bir metnin kelimeleri sırayla yazılır. Her kelimenin anlamsal uzayda bir koordinatı varsa, kelimelerin koordinatları yazıdaki sırayla birleştirilerek metin X boyutlu bir uzayda bir yörünge (path) olarak ifade edilebilir. Metin, kelimelerin ortalamasıyla değil bu yörüngeyle temsil edilir.

Slayttaki örnekte iki metin çizildi (slayt "Kelime Yörüngeleri", 01:27:00 civarı):

- "Bugün yolda kedi gördüm. Arkasından gittim. Hızlı koşuyordu. Yakalayamadım."
- "Hızlı araba kullanmak tehlikelidir. Kediler arabaların altında ..."

Bir öğrenci "kedi"nin iki metinde de ortak olduğu için iki yörüngenin ortasında bulunduğunu fark etti; "hızlı" da iki metinde ortaktır. Ama önemli olan kelimelerin kendileri değil yörüngenin özellikleridir: örneğin bir noktadan ötekine büyük bir zıplama ("arabadan kediye atlamış") ya da küçük adımlar.

### 8.2 Özellikler

Farklı metinler farklı sayıda kelime içerdiği için yörüngelerin uzunlukları eşit olmaz; ama metinleri karşılaştırmak için hepsinin aynı boyutta temsil edilmesi gerekir. Bunun için histogramlar kullanılır. Slayttaki tanım (ekrandan, 01:30:00):

- 2 özellik: kavramlar arası mesafeler ve kavramlar arası açılar.
- $(n, n+1, n+2, n+3)$ arka arkaya gelen 4 koordinat olmak üzere $(n,n+1)$, $(n,n+2)$, $(n,n+3)$ arası mesafelerin 10'luk histogram değerleri ve frekansları, ve $(n,n+1,n+2)$, $(n,n+2,n+3)$ arası açıların (PI cinsinden) 10'luk histogram değerleri ve frekansları.

Böylece her yörünge 100 boyutlu bir vektör olur. Burada kelimelerin koordinatları yoktur; yalnız ardışık adımların uzunlukları ve aralarındaki açılar vardır. Örneğin "hızlı → araba → kullanmak" gibi bir dizide açı küçük olabilir; "hızlı → araba → altın" gibi ilgisiz bir sıçramada açı büyük olur.

### 8.3 Neden işe yarar? Yazar tanıma

Bir metnin yazarını bulmak istediğimizi düşünelim. Kelimeleri kullanırsak aynı kelimeler birçok yazar tarafından ortak kullanılabilir; bir yazar da birden fazla konuda (ekonomi, spor, magazin) yazabilir. Bu yüzden kelimelerin kendileri değil, kelimelerin birbirlerine göre kullanımları, yani yörüngeler daha belirleyici olabilir.

Deneysel sonuçlar (ekrandan, 01:33:30):

İki yazara ait 35'er yazı, "bir yazı kime ait?", 10'lu çapraz geçerleme:

| Algoritma | Sınıflandırma başarısı (%) |
|---|---|
| C4.5 | 97.15 |
| Naive Bayes | 97.15 |
| En yakın komşu | 95.71 |
| Destek Vektör Makineleri | 98.57 |

Her yazara ait 35'er yazı, 10'lu çapraz geçerleme:

| Algoritma | 3 yazar | 4 yazar | 8 yazar |
|---|---|---|---|
| C4.5 | 91.43 | 90.71 | 53.21 |
| Naive Bayes | 95.24 | 92.14 | 62.5 |
| En yakın komşu | 80.95 | 62.14 | 50 |
| Destek Vektör Makineleri | 94.29 | 85.71 | 68.57 |
| Zero Rule | 33.33 | 25 | 12.5 |

Yazar sayısı arttıkça başarı düşer, ama her durumda Zero Rule'un çok üstündedir. Zero Rule'u bir öğrenci açıkladı: eğitim verisinde en sık geçen sınıfı bütün test örneklerine vermek. Hoca bunu "mantıkla atmak" diye özetledi: içeriğe hiç bakmadan tutturma ihtimalimiz budur. Buradaki veri kümeleri dengeli olduğu için (her sınıftan eşit sayıda örnek) Zero Rule 3 yazar için %33.33, 4 yazar için %25, 8 yazar için %12.5 verir. Bunun üzerinde bir sonuç elde ediliyorsa anlamlı bir şey yapılmıştır.

Kadın ve erkek yazarları ayırmak da denendi, ama iyi çalışmadı. Hoca, örneğin bir grubun konudan konuya çok uçması ya da öteki grubun aynı konunun etrafında dönüp durması gibi bir fark olsaydı mesafelerde ortaya çıkabileceğini, ama böyle bir fark çıkmadığını söyledi. Yaklaşım farklı yazarları ayırmada başarılıdır. Slayttaki olası kullanım alanları arasında psikolojik hastalıkların tespiti ve psikolojik hastalıkların düşünce süreçleri üzerindeki etkilerinin araştırılması da vardır.

## 9. Sinirsel Dil Modelleri: word2vec

### 9.1 Neden word2vec?

Sinirsel dil modellerinden iki yönteme bakıldı: word2vec ve FastText. FastText, word2vec'in bir varyantıdır.

word2vec 2013'te çıkmıştır. MDS'de birlikte geçme matrisinden kelime vektörleri elde ediliyordu; word2vec aslında aynı şeyi yapar, kelimelere koordinat bulur, ama çok daha ölçeklenebilir ve hızlı bir biçimde. 50 bin terimin koordinatlarını birlikte geçme ile bulmak için $50.000 \times 50.000$'lik bir matris oluşturup üzerinde MDS uygulamak gerekir; bu oldukça güç bir iştir.

Slayttaki tanım (ekrandan, 01:40:00):

- Word2vec (2013, T. Mikolov ve ark., "Distributed representations of words and phrases and their compositionality"), FastText (2017, P. Bojanowski ve ark., "Enriching word vectors with subword information").
- Tek gizli katmana sahip bir yapay sinir ağı.
- $C=2$ için bağlam $= (w_{t-2}, w_{t-1}, w_t, w_{t+1}, w_{t+2})$. $w_{t-1}$, $w_t$'den bir önceki; $w_{t+1}$ bir sonraki kelimedir. $C$ pencere uzunluğudur.
- Skip-gram: giriş $w_t$, çıkış $(w_{t-2}, w_{t-1}, w_{t+1}, w_{t+2})$'nin her biri.
- CBOW: giriş $(w_{t-2}, w_{t-1}, w_{t+1}, w_{t+2})$'nin her biri, çıkış $w_t$.

Skip-gram'da ağa $w_t$ verilir ve ondan örneğin $w_{t+1}$, $w_{t+2}$ ya da $w_{t-2}$'yi vermesi istenir; bunlar eğitim kümesini oluşturur. CBOW'da ağa örneğin $w_{t-2}$ verilir ve çıkış olarak $w_t$ istenir.

### 9.2 Ağın yapısı

Slayttaki şema (ekrandan, 01:40:00):

```text
Input layer            Projection layer        Output layer
1-hot input vector     embedding for w_t       probabilities of context words
     1 x |V|    --W (|V| x d)-->   1 x d   --C (d x |V|)-->   1 x |V|
     w_t                                                      w_{t+1}
```

- Giriş katmanı one-hot kodlamadır: bir tane 1, geri kalan hepsi 0. Her kelimenin sözlükte (vocabulary) bir indisi vardır; sözlük tekil kelimelerin hepsini içerir ve $1 \times |V|$ boyutlu bir vektördür. Örneğin $w_t$ 248'inci indisteyse 248'inci eleman 1, geri kalan (örneğin 20 bin kelimelik sözlükte 19.999 eleman) 0'dır. Çıkış da öyledir: $w_{t+1}$ örneğin 948'inci indisse 948'inci eleman 1, kalanı 0'dır.
- $W$ matrisi $|V| \times d$ boyutludur. $d$, kelime koordinatlarının kaç boyutlu olacağıdır.
- One-hot vektör $W$ ile çarpılınca $1 \times d$ boyutlu bir vektör çıkar.
- Bu vektör $d \times |V|$ boyutlu $C$ matrisiyle çarpılınca $1 \times |V|$ boyutlu çıkış elde edilir.

Ağ $W$ ve $C$ matrislerini öğrenmeye çalışır. Başarılı sonuçlar elde edilince eğitim durdurulur. Bir öğrencinin cevabıyla birlikte hoca şunu vurguladı: eğitim bitince $W$ matrisi her kelimenin $d$ boyutlu uzaydaki vektörünü, yani koordinatını tutar. Bu koordinatlar alınıp istenen yerde kullanılır.

### 9.3 Amaç fonksiyonu ve negatif örnekleme

Slayttaki ifadeler (ekrandan, 01:47:40):

- $W$ matrisi kelime vektörleridir.
- Başlangıçta rastgele atanırlar, eğitim bitince kullanıma hazırdırlar. (Yapay sinir ağlarında ağırlıklar başta rastgele atanır, zamanla eğitim kümesine uygun hâle getirilir.)
- Amaç: bir kelimenin ($w$) genelde etrafında bulunan kelimelerle ($c$) benzer vektörlere, diğerleriyle ($w_i$) farklı vektörlere sahip olması.
- İki vektör benzer ise iç çarpımları yüksektir.
- Negatif örneklemeli skip-gram için hata fonksiyonu:

$$\log \sigma(c \cdot w) + \sum_{i=1}^{K} \mathbb{E}_{w_i \sim p(w)} \big[\log \sigma(-w_i \cdot w)\big]$$

Hoca iç çarpımın neyi ölçtüğünü sordu; iki vektör arasındaki açı darsa vektörler birbirine benzer.

Sonra kritik soruyu sordu: amaç yalnız "her kelime etrafındaki kelimelere benzesin" olsaydı çözüm nereye çökerdi? Bütün kelimelerin koordinatları aynı olsa bu amaç mükemmel sağlanır: herkes etrafındaki kelimelerle sıfır açıya sahip olur. Model sonunda bütün kelimeleri aynı koordinata getirir; bu da işe yaramaz (bkz. Örnek Sorular). Bu yüzden ikinci bir amaç gerekir: kelime, bağlamında olmayan kelimelerle farklı vektörlere sahip olmalıdır. Loss fonksiyonu modelin performansını ölçer ve model eğitim sürecinde ona göre güncellenir; bu ikinci amaç loss'a negatif örneklemeyle girer.

- Pozitif örnekler: bu iki kelimenin koordinatları birbirine yakın olsun.
- Negatif örnekler: bu iki kelimenin koordinatları birbirinden uzak olsun. Formüldeki $-w_i \cdot w$ içindeki eksi, bu kelimelerin uzak olması istendiği içindir.
- Her pozitif örnek için $K$ negatif örnek seçilir. Hocanın hatırladığına göre Mikolov'un uygulamasında bu oran 5 civarındadır.

Negatif örnekler nasıl seçilir? Bir kelimenin etrafındaki kelimeler pencere kaydırılırken zaten bilinir. Ama bağlamda olmayan kelimeleri tek tek belirlemek zordur. Bunun yerine kelimeler $p(w)$'ye göre, yani derlemdeki olasılıklarına göre rastgele seçilir. Bağlamda olmayan kelimeleri bulmakla hiç uğraşılmaz; rastgele seçilirken frekansa dikkat edilir. Nadir kelimeleri seçmek pek bir şey kazandırmaz; derlemde frekansı yüksek olanlardan seçilir. Bütün kayıplar hesaplanıp ağırlıklar güncellenir.

> **Ders sonrası not:** Slayttaki sigmoid tanımı $\sigma(x) = \frac{1}{1+e^{x}}$ biçiminde yazılmış. Doğrusu $\sigma(x) = \frac{1}{1+e^{-x}}$'tir; aksi hâlde fonksiyon azalan olur ve iç çarpım büyüdükçe $\sigma$ küçülür.

> **Ek bilgi (derste anlatılmadı):** Mikolov ve arkadaşlarının çalışmasında büyük olasılıkla negatif örnekler $p(w)$'nin kendisinden değil, unigram frekansının 3/4'üncü kuvvetiyle orantılı bir dağılımdan çekilir; bu, çok sık kelimelerin ağırlığını biraz azaltıp nadir kelimelere biraz şans tanır. Önerilen $K$ değerleri büyük olasılıkla küçük veri kümeleri için 5-20, büyükler için 2-5 civarındadır.

### 9.4 Eğitim kümesi oluşturmak

Slayttaki örnek (ekrandan, 01:50:00):

```text
Text: w1 w2 w3 w4 w5 w6 w7 ...

Skip-gram için eğitim örnekleri (giriş, çıkış), C=2, w3 için:
  benzer olmasını istediğimiz ikililer (pozitif):
    (w3,w1), (w3,w2), (w3,w4), (w3,w5)
  farklı olmasını istediğimiz ikililer (negatif):
    (w3,t1), (w3,t2), (w3,t3) ... (w3,tK)
    burada t1...tK, p(wi)'ye göre rastgele seçilen kelimeler
Sonra w4 ile devam ...
C-bow için ikilileri tersine çevir.
```

$w_3$ için iş bitince pencere kayar ve aynı iş $w_4$ için yapılır. CBOW için yapılacak tek şey ikilileri tersine çevirmektir: girişte $w_1$ çıkışta $w_3$, girişte $w_2$ çıkışta $w_3$, girişte $w_4$ çıkışta $w_3$. Yani etraftaki kelimeler verilir, kelimenin kendisi tahmin edilir. İki yöntem arasındaki tek fark budur.

**Soru:** Bu yöntem dilden bağımsız mı, yoksa dile göre değişiyor mu?
**Cevap:** Dilden bağımsızdır. $w_1, w_2, w_3, w_4$ birer token'dır; dile özgü hiçbir şey kullanılmaz.

## 10. FastText

### 10.1 Fikir

Slayt "Fasttext" (ekrandan, 01:50:00 karesindeki küçük resim): FastText word2vec'e bir ektir. Aynı bağlamda bulunmaya ek olarak kelime içi n-gram benzerliklerini (subword similarity) de dikkate alır. Kelimeleri n-gramlarına ayırır ve her n-gram için vektör bulur.

- Sözlükte olmayan kelimelerin vektörlerini de bulabilir: elinde alt kelime (subword) vektörleri olduğu için bunları birleştirerek hiç görmediği bir kelimenin koordinatını üretebilir. En uçta tek harfler için bile vektör vardır.
- Türkçe gibi eklemeli diller için avantajlıdır: aynı kelimenin farklı ek almış hâlleri ya da yanlış yazılmış hâlleri birbirine yakın koordinatlara sahip olur. Birisi bir kelimeyi yanlış yazdıysa FastText'te bu, doğru yazılmışına yakın bir koordinata düşer.
- Aynı kelimenin farklı ekli hâllerinin yakın olması bazı durumlarda iyi, bazı durumlarda kötüdür.
- Daha yavaş çalışır; hocanın hatırladığına göre en az 2-3 katlık bir fark vardır.

Derste kullanılan kodlar slaytta listelendi: `word2vec_modeli_hazir.m` (kullanım), `word2vec_modeli_egitim.m` (eğitim), `emb42_ngramsiz.mat` (kelime vektörleri), `fast_emb.mat` (kelime vektörleri), `haber42bin.mat` (derlem). Bunlarla hazır bir word2vec kullanılabilir, kendi derlemiyle eğitilebilir ve sonuçlar çizdirilebilir.

### 10.2 Hazır vektörler ve ölçeklenebilirlik

Hocanın aktardığına göre 2012 civarında insanlar büyük derlemler üzerinde oluşturdukları kelime koordinatlarını her dil için yayımlamaya başladı: X dilinde bir derlem verilir, X dilindeki kelimelerin koordinatları bulunur. Bugün FastText vektörleri birçok dil için Facebook tarafından hazır dağıtılmaktadır.

Derste indirilen hazır FastText vektörlerinde 416.000 kelime vardı. Bu sayı ölçeklenebilirliği gösterir: aynı işi benzerlik matrisiyle yapmak $416.000 \times 416.000$'lik bir matris gerektirirdi ve bunun üzerinde kimse bir şey yapamazdı. word2vec/FastText'te ise $d = 100$ için matris $416.000 \times 100$'dür; $|V| \times d$ ve $d \times |V|$ boyutlu iki matrisle iş görülür, $|V| \times |V|$'lik bir matris hiç yoktur.

### 10.3 Hazır FastText ile en yakın kelimeler

Slayt "Hazır fasttext vektörleri ile ilk satırdaki kelimelere en yakın 19 kelime" (ekrandan, 01:54:30; dipnot: "Fasttext vektörleri 416 bin kelime içermektedir. Ngram benzerliği de kullanır."):

| cimbom | terlik | virüs | elma | aslan | koş | bırak |
|---|---|---|---|---|---|---|
| cimbombom | terliksi | virüsün | elma,armut | aslaner | koşo | bıraktın |
| lik– | terlikler | virüslü | armut | aslana | koşoy | bırakın |
| penaltılarla | terlikleri | virüsle | ,armut | aslani | koşaç | bırakamam |
| #beşiktaş | noterlik | virüse | şeftali | aslankeser | koşa | bırakmam |
| rövanşta | kasiyerlik | virüstür | meyveş | aslanı | koşağaç | bıraz |
| lik/ | önlük | virüsü | meyva | aslanın | koşovi | bıraksın |
| penaltısonuç | yeterlik | virüsler | elmaağacı | aslanyürek | koşun | bıraktım |
| beşiktaşlı | dülgerlik | virüsün | kayısı | aslanbaş | koşamaz | bırakayım |
| cimbilli | dizlik | virüsten | meyvelik | aslanhan | koşalı | bırakırsan |
| gülesin | göynek | virüsteki | ayva | özaslan | koşacı | bıra |
| galatasaray | yerlik | virüsleri | üzüm | aslanbay | koşaca | bırakırsam |

(Tablo slayttaki listenin ilk 11 satırıdır; slaytta her kelime için 19 kelime var.)

Hoca sonuçları şöyle yorumladı:

- "cimbom"a cimbombom, penaltılarla, beşiktaş, rövanşta, galatasaray gibi kelimeler gelmiş; fena değil.
- "terlik"e terliksi, terlikler gibi ekli hâllerin gelmesi tamamdır. Ama "noterlik", "yeterlik", "dülgerlik" gibi kelimeler de gelmiş; bunların terlikle ilgisi yoktur, yalnız sonları "terlik"/"erlik" ile biter. "Terli" de "terlik"e benzer çıkmış.
- "virüs" için virüsün, virüsü, virüsle gibi farklı ekli hâller gelmiş; bu bir açıdan iyidir.
- "elma"ya armut, şeftali, meyve, kayısı, ayva, üzüm gibi kelimeler gelmiş; bunlar güzel.
- "aslan" için aslanyürek, aslana, aslanı; "koş" için koşa, koşun, koşamaz gibi ekli hâller gelmiş. Aynı kelimenin farklı ekli hâllerini birleştirmek için iyidir.
- Ama "terlik-yeterlik", "terlik-noterlik" gibi farklı kelimelerin aynı yere konmasını istemeyiz; bunlar kötü taraflardır.

"Terlik" ile "noterlik"in neden yakın çıktığı sorusunu bir öğrenci doğru cevapladı (bkz. Örnek Sorular): FastText alt kelimelere bakar, "noterlik"in içinde "terlik" vardır.

### 10.4 42 bin haber metniyle eğitilen vektörler (n-gramsız)

Slayt "42 bin haber metniyle eğitilen vektörler, ngram benzerliği yok, ilk satırdaki kelimelere en yakın 19 kelime": burada alt kelime benzerliği yoktur. "virüs"e virüsü gibi bir iki ekli hâl dışında bulaşan, HIV, hastalık, grip, aşı ve zararlı, yazılım, bilgisayar, kullanıcı, saldırgan gibi anlamca yakın kelimeler gelmiştir. Kelimeler arasında n-gram bazında bir benzerlik yoktur; anlamca yakın olanlar çıkmıştır.

Hoca, metinlerin 2012 civarına ait olduğunu, bugün "virüs" denince büyük olasılıkla korona ile ilgili kelimeler çıkacağını söyledi. Ayrıca "virüs"ün iki anlamı (biyolojik virüs ve yazılım virüsü) için de yakın kelimeler gelmiştir; bu da çok anlamlı kelimeler sorunudur. Yalnız en yakın 19 kelimeye bakıldığı için listenin devamında başka kelimeler de çıkabilir.

## 11. Kelime Vektörlerinin Değerlendirilmesi ve Metin Vektörleri

### 11.1 Başarı nasıl ölçülür?

Slayt "Kelime vektörlerinin başarısını nasıl ölçeriz?" (ekrandan, 02:00:00):

- Dahili / direkt yöntemler:
  - İnsanların verdikleri cevaplarla korelasyon: insanlara "şu kelimeye en yakın kelimeleri söyle" denir, modelin söyledikleriyle korelasyon ölçülür.
  - Analoji veri kümeleri: "şu kavramla şu kavram arasındaki ilişki, şu kavramla aşağıdakilerden hangisi arasında vardır?" tarzı sorular. Slaytta iki kaynak var: ACL wiki'deki "Google analogy test set (State of the art)" sayfası ve aclweb.org/anthology/C16-1332.
- Harici / dolaylı yöntemler: vektörlerin çeşitli NLP uygulamalarında kullanımları üzerinden; örneğin metin sınıflandırma, makine çevirisi, metin özetleme, varlık ismi tanıma (named entity recognition). Bu, vektörlerin kendileri üzerinden değil, onları kullanan uygulamalar üzerinden bir değerlendirmedir.

### 11.2 Cümle ve metin vektörleri

Slayt "Cümle ve metin vektörleri": dil modellerinin özelliklerinde de söylendiği gibi cümle ve metin vektörleri için en basit yol, içindeki kelimelerin vektörlerinin ortalamasını almaktır. Slaytta Universal Sentence Encoder'a (arxiv.org/abs/1803.11175) bağlantı verildi.

## 12. Kelime Öbekleri

### 12.1 Neden öbek?

Slayt "Kelime Öbekleri": 2, 3, 4 uzunluğunda genelde birlikte kullanılan kelime birlikleri, içerdikleri her bir kelimeden ayrı bir kavramı ifade edebilir. "Fatih Sultan Mehmet" ifadesi "Fatih", "Sultan" ve "Mehmet"in her birinden farklı bir kavramı ifade eder. Üç kelimenin vektörlerini ayrı ayrı alıp birleştirmek işleri karıştırabilir; ifade hep birlikte tek bir şey anlatır.

Şimdiye kadar kelimeler hep tek tek alındı. Hoca, "Fatih Sultan Mehmet"i tek bir token olarak düşünmenin daha iyi olup olmayacağını sordu; bir öğrenci evet dedi ve hoca onayladı. Asıl soru şuydu: bu öbekler nasıl bulunur? (Tartışma için bkz. Örnek Sorular.) Hoca öbeklerin yalnız özel isimler olmadığını vurguladı: "etekleri zil çalmak" gibi bir deyim için "etek", "zil" ve "çalmak" vektörleri birleştirilerek bu anlam büyük olasılıkla üretilemez.

### 12.2 Öbek bulma ölçüleri

Slayttaki yöntemler (ekrandan, 02:05:20):

- En basiti: frekansı en yüksek olanlar.
- Kelime öbeği olma olasılığı ($t_i$):
  - $t_i$'nin frekansı / $t_i$'nin içerdiği tekil kelimelerin frekanslarının minimumu.
  - $\log_2$($t_i$'nin frekansı / $t_i$'nin içerdiği tekil kelimelerin frekanslarının çarpımı).
- En basitini deneyelim.

Formül olarak:

$$P_1(t_i) = \frac{freq(t_i)}{\min_{w \in t_i} freq(w)}, \qquad P_2(t_i) = \log_2 \frac{freq(t_i)}{\prod_{w \in t_i} freq(w)}$$

Bu ölçüler öğrencinin önerisine hocanın eklediği noktayı yansıtır: yalnız ardışık geçme frekansı değil, kelimelerin tek başlarına geçme frekansları da hesaba katılır.

> **Ek bilgi (derste anlatılmadı):** İkinci ölçü büyük olasılıkla noktasal karşılıklı bilgiye (pointwise mutual information, PMI) benzer. PMI'da frekanslar yerine olasılıklar kullanılır: $\log_2 \frac{p(x,y)}{p(x)\,p(y)}$. Mikolov ve arkadaşları word2vec makalesinde öbekleri büyük olasılıkla benzer bir puanla, $\frac{count(w_i w_j) - \delta}{count(w_i) \times count(w_j)}$, bulmuştur.

### 12.3 Uygulama: 42 bin haber metni

Slayt "Kod kelime_obekleri.m" (ekrandan, 02:07:10):

- 42 bin haber metni içindeki 1, 2 ve 3 uzunluğunda kelime n-gramları bulunur.
- Nadir kelimeler silinmezse 11 milyon n-gram çıkar.
- 50'den az geçen kelimeler silinirse:
  - kelime silme öncesi tekil kelime sayısı = 356.680
  - kelime silme öncesi dokümanlardaki toplam kelime sayısı = 9.986.668
  - silinen tekil kelime sayısı = 336.019
  - kelime silme sonrası dokümanlardaki toplam kelime sayısı = 8.320.579
- Kod çıktısı: `Counts: [41992x8141753 double]`, `Vocabulary: [1x20661 string]`, `Ngrams: [8141753x3 string]`, `NgramLengths: [1 2 3]`, `NumNgrams: 8141753`, `NumDocuments: 41992`. N-gram sayısı yaklaşık 8 milyon.

Sayılar tutarlıdır: $356.680 - 336.019 = 20.661$, yani sözlükte kalan tekil kelime sayısı (python ile doğrulandı). Toplam kelimelerin yaklaşık %83'ü korunmuştur.

Kelime n-gramı, ardışık 1, 2 ya da 3 kelimeden oluşan dizedir. Hoca slayttaki "42bin haber metni içindeki 1, 2, ve 3 ..." cümlesi üzerinde 3-gramları gösterdi: "42bin haber metni", "haber metni içindeki", "metni içindeki 1", "içindeki 1 ," ... Pencere kayarak ilerler.

Hocanın aktardığına göre 8 milyon n-gramın yalnız yaklaşık 36 bini 50'den fazla geçmiştir ve yalnız onlar kullanılabilir. Frekansı en yüksek 1, 2, 3 n-gramlar slayttaki tabloda gösterildi: tek kelimeler arasında "ve" gibi kelimeler (hoca yaklaşık 180 bin kez geçtiğini söyledi); 2-gramlarda kesme işaretli ekler (" 'nin", " 'ın", " 'de" gibi); 3-gramlarda "Türkiye'nin", "Türkiye'de", "... diye konuştu", "şöyle devam etti", dönemin başbakanının adı, "yönetim kurulu başkanı" gibi ifadeler vardı. Metinler 2012 civarına aittir. <!-- BELİRSİZ: Hocanın frekans tablosunu okuduğu yer (02:07:30-02:08:20) altyazıda bozuk; tablodaki değerler karede okunmadı. -->

### 12.4 Öbekleri tek kelimeye çevirmek

Frekansı en yüksek 2-gram ve 3-gramların listesi elde edildikten sonra bunlar tekil kavramlar olarak ifade edilir: kelimeler arasındaki boşluklar silinip birleştirilir ("yer alırken" → "yeralırken", "700 milyon" → "700milyon"). Alt çizgiyle birleştirmek de olur. Sistem birleştirilmiş ifadeyi yeni bir kelime olarak görür ve onun için ayrı bir vektör üretir. İşin güzel tarafı budur: "dışişleri" ve "bakanı" için vektörler varken "dışişleribakanı" için de bir vektör olur.

Slayt "Haberlerin yeni hali" (ekrandan, 02:10:00), kırmızılar birleştirilen yerler:

```text
(1,1) 111 tokens: ortak vizyonumuz var dışişleribakanı davutoğlu yunanistan
iletürkiye arasındaki farklılıkların ortak vizyon ile çözülebileceğini söyledi
dışişleribakanıahmet davutoğluve yunan mevkidaşı dimitris avramopulos
başbaşa ve heyetler arası görüşmelerinardından ortakbasıntoplantısı
düzenledi davutoğlu yunanistanda kendisine gösterilen sıcak karşılama
içinteşekkür ederek ziyaretinin türkyunan dostluğunun bir nişanesi
olduğunudile getirdi ikiülke arasında görüş ayrılıkları vefarklı yaklaşımlar
olabileceğini amaaynı vizyonun paylaşılmasıyla aradaki sorunların
problemlerin daharahat çözülebileceğini ifadeeden bakan davutoğlu
samaras ve avramopulos ile görüşmelerinden eldeettiği sonucun dabu
yönde olduğunu söyledi davutoğlu ikiyılönce ydiki bu anlayışla kurdukları
yunanistanda istikrarlıbir hükümet kurulur kurulmaz da toplantının ikincisini
gerçekleştirmeyi planladıklarını vebugün ön hazırlıkları önemliölçüde
tamamladıklarını söyleyerek birçok alanda ortak mutabakatların ilk
tohumları atıldı ...
```

Hocanın vurguladığı nokta: birleştirilenler yalnız özel isimler değildir. "görüşmelerinardından", "ortakbasıntoplantısı", "eldeettiği", "ikiyılönce" gibi sıklıkla tekrar eden ifadeler de tek kelime hâline gelmiştir. Bu yeni derlemle word2vec yeniden eğitilebilir ve bu kavramlar için de vektörler elde edilir. Hoca sonuçlarda "İstanbul sanatseverler", "hastalığı nedeniyle ölmek", "demesi üzerine" gibi öbeklerin ortaya çıktığını gösterdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:26): Wu & Palmer formülünde $N_3$ değeri büyürse, yani iki kavramın ortak üst synset'i kökten çok uzaktaysa, iki kavram birbirine daha mı yakın olur, daha mı uzak?

> **Cevap (derste verildi):** Daha yakın olur. $N_3$ büyükse ortak üst synset ağacın dibine yakındır; ağacın altındaki kavramlar spesifik, üstündekiler geneldir. İki kavram çok daha spesifik bir kavramın altında toplanmış olur. Bu yüzden $N_3$ benzerlikle doğru, $N_1$ ve $N_2$ ters orantılıdır.

**Soru 2** (ekrandan, 00:20:00; derste kısmen çözüldü): Slayttaki ağaçta $c_1$ ile $c_2$ için Wu & Palmer benzerliğini hesaplayın. Ağaçta kök seviye 0'dadır; $lcs(c_1,c_2)$ seviye 2'de, $c_2$ doğrudan $lcs$'nin çocuğu (seviye 3), $c_1$ ise $lcs$'nin başka bir çocuğunun çocuğudur (seviye 4).

> **Çözüm (derste verilmedi):** Hoca $N_1 = 2$ ve $N_2 = 1$ değerlerini gösterdi. Kökten $lcs$'ye iki bağ olduğu için $N_3 = 2$'dir. $sim_{WP} = \frac{2 \times 2}{2 + 1 + 2 \times 2} = \frac{4}{7} \approx 0.571$ (python ile hesaplandı).

**Soru 3** (derste sözlü, 00:23:46): Jiang-Conrath ve Lin'deki $P(concept) = freq(concept)/freq(root)$ tanımında kökün frekansı neyi gösterir?

> **Cevap (derste verildi):** Bir kavramın frekansı kendisinin ve altındaki her şeyin frekanslarının toplamıdır. Kökün altında her şey vardır; dolayısıyla $freq(root)$ derlemdeki toplam kelime sayısına eşittir.

**Soru 4** (derste sözlü, 00:25:08): $sim_{JC}$ ve $sim_L$ formüllerinde A ($2\log p(lcs)$ terimi) büyüdükçe benzerlik büyür mü? B büyüdükçe?

> **Cevap (derste verildi):** Öğrenciler A büyüdükçe benzerliğin büyüdüğünü, B büyüdükçe küçüldüğünü söyledi; hoca bunun iki formül için de geçerli olduğunu, biri çıkarma, öteki bölme yapsa da ikisinin anlamca aynı şeyi yaptığını belirtti. (İşaret konusundaki çekince için 2.5'teki ders sonrası nota bakın.)

**Soru 5** (derste sözlü, 00:34:13 ve 00:35:04): Kedi-köpek örneğindeki (8 doküman satırda, 9 kelime sütunda) matris nasıl bir matristir? Bu matriste dokümanlar kaç boyutlu bir uzayda noktadır?

> **Cevap (derste verildi):** Bu bir doküman-terim matrisidir; transpozu terim-doküman matrisidir. Bir öğrenci önce "sekiz" dedi; doğrusu, dokümanlar terim sayısı kadar, yani 9 boyutlu bir uzayda noktadır. Terim-doküman matrisinde ise her terim doküman sayısı kadar (8) boyutlu bir noktadır.

**Soru 6** (derste sözlü, 00:39:06): Kelimeleri terim-doküman matrisine ve birlikte geçme matrisine göre kümelemek için dokümanların sınıf bilgisi gerekli mi?

> **Cevap (derste verildi):** Hayır. Yalnız sınıflarda yer alma olasılıklarına göre kümelemede sınıf bilgisi gerekir.

**Soru 7** (derste sözlü, 00:48:20): MDS uzaklıklarla çalışır, ama birlikte geçme sayısı bir yakınlık ölçüsüdür. Yakınlıktan uzaklığa nasıl geçilebilir?

> **Cevap (derste verildi):** Bir öğrenci büyük bir sayıyı bu değerlere bölmeyi önerdi; hoca bunun da olabileceğini söyledi. Çalışmada uzaklık = 1/yakınlık kullanıldı.

**Soru 8** (derste sözlü, 00:50:53): Veri kümesi 2'nin MDS koordinatlarında hayvan olan "bit" ile ev eşyası olan "divan" neden yakın çıkmıştır?

> **Cevap (derste verildi):** Bir öğrenci divanın eskiden kullanıldığını ve bitlendiğini hatırlattı. Hoca onayladı: divan ve bit web sayfalarında sık birlikte geçmiş, bu yüzden koordinatları da yakın çıkmıştır.

**Soru 9** (derste sözlü, 00:53:56 - 00:56:38): 967 teknik terimin koordinatlarını bulmak için neden Google yerine 15.000 web sitesi indirildi? Birlikte geçme matrisi kaça kaçtır ve kaç sorgu gerekir?

> **Cevap (derste verildi):** Matris $967 \times 967$'dir; $967 \times 967 = 935.089$ sorgu gerekir ve arama motoru bu kadar sorguya bedava izin vermez. Bir öğrenci önce "15.000 × 967" dedi, sonra doğru boyuta ulaşıldı. 20.000 terim için $20.000^2 = 400$ milyon sorgu gerekir.

**Soru 10** (derste sözlü, 01:00:28): Metin sınıflandırma deneyinde MDS'nin çıktısı neyin koordinatlarıdır? Metinlerin koordinatı nasıl bulunur?

> **Cevap (derste verildi):** MDS kelimelerin koordinatlarını verir; metinlerin koordinatı doğrudan yoktur. En klasik yol, metnin içindeki kelimelerin koordinatlarının boyut boyut ortalamasını almaktır; metin, kelimelerle aynı boyutta olur.

**Soru 11** (derste sözlü, 01:02:43): Farklı sınıflardan haberlerin uzayda farklı yerlerde toplanması iyi bir şey mi?

> **Cevap (derste verildi):** İyidir. Aynı sınıfın örnekleri birbirine yakın, farklı sınıfların örnekleri birbirinden uzak olmalıdır ki sınıflandırıcılar iyi çalışsın. Her şey üst üste binerse sınıflandırma imkânı kalmaz.

**Soru 12** (derste sözlü, 01:05:58): Birlikte geçme ile bulunan sabit koordinatlarda İngilizce "apple" kelimesinin koordinatı nasıl olur?

> **Cevap (derste verildi):** "apple"ın bir firma, bir de meyve anlamı vardır. Koordinatı iki konunun ortasına düşer ve ikisine de tam yakın olmaz; ya da ilgisiz şeyleri (armut ile cep telefonu gibi) birbirine yaklaştırır. Sabit koordinatla anlam ayrımı yapılamaz.

**Soru 13** (derste sözlü, 01:32:32): Yazar tanıma tablosundaki Zero Rule nedir? 3, 4 ve 8 yazar için başarısı neden 33.33, 25 ve 12.5'tir?

> **Cevap (derste verildi):** Zero Rule, eğitim verisinde en sık geçen sınıfı içeriğe bakmadan bütün test örneklerine vermektir. Veri kümeleri dengeli olduğu için (her yazara 35 yazı) en sık sınıfın oranı $1/k$'dır: $1/3 = \%33.33$, $1/4 = \%25$, $1/8 = \%12.5$.

**Soru 14** (derste sözlü, 01:42:57): word2vec'in amacı yalnız "bir kelime etrafındaki kelimelerle benzer vektörlere sahip olsun" olsaydı, çözüm nereye çökerdi?

> **Cevap (derste verildi):** Bütün kelimelerin koordinatları aynı olurdu. Bu durumda her kelime etrafındaki kelimelerle sıfır açıya sahip olur ve amaç mükemmel sağlanır, ama sonuç işe yaramaz. Bir öğrenci önce "sağlayamayız, bir manası olmaz" dedi; hoca işe yararlıktan değil amacın sağlanıp sağlanmadığından bahsettiğini, amacın sağlandığını belirtti. Bu yüzden bağlamda olmayan kelimelerle farklı olma amacı negatif örneklemeyle eklenir.

**Soru 15** (derste sözlü, 01:55:11): Hazır FastText vektörlerinde "terlik" ile "noterlik" neden birbirine yakın çıkmıştır? Aynı iş word2vec ile yapılsaydı yakın çıkarlar mıydı?

> **Cevap (derste verildi):** FastText alt kelimelere (subword) bakar; "noterlik"in içinde "terlik" vardır. word2vec ile yakın çıkmazlar, çünkü iki kelime aynı bağlamın içinde neredeyse hiç geçmez. Buradaki yakınlık birlikte geçmeden değil, alt kelime benzerliğinden kaynaklanır.

**Soru 16** (derste sözlü, 02:02:01 - 02:05:00): Elimizde yalnız bir derlem var (sözlük yok). "Fatih Sultan Mehmet" gibi kelime öbeklerini nasıl buluruz?

> **Cevap (derste verildi):** Öğrencilerden gelen öneriler: hazır bir sözlük (hoca: biz nasıl buluruz diye soruyorum), yan yana gelen özel isimler (hoca: yalnız özel isimler değil, "etekleri zil çalmak" gibi ifadeler de öbektir), ikili ve üçlü kelime gruplarının frekanslarına bakmak. Hoca sonuncuyu onayladı: arka arkaya sık geçen kelimelerin birliktelik ihtimali yüksektir. Ayrıca her kelimenin tek başına kaç kez geçtiğinin de hesaba katılması iyi olur; slayttaki iki ölçü bunu yapar (bkz. 12.2).

**Soru 17** (ekrandan, 02:12:00; ödevin akademik metni): Türkçe anlamsal uzayları derlem, yöntem ve hiperparametre açısından, konu sınıflandırma dışında seçilen bir uygulama üzerinden karşılaştırın. En az iki derlem ve en az üç yöntem kullanın; hazır vektör kullanmadan yöntemleri bu derlemlerle eğitin.

> **Hocanın açıklaması (derste verildi):** İki derlem ve üç yöntemle en az altı kelime koordinat sistemi elde edilir. Yöntem olarak FastText, word2vec, GloVe, ELMo, BERT gibi yöntemler kullanılabilir; yöntemler kodlanmaz, hazır kodları kullanılır. Hazır eğitilmiş vektörlerin kullanılmaması derlemin etkisini görmek içindir. Bazı yöntemlerin (ör. BERT) eğitimi uzun sürerse derlem küçültülür, ama adil karşılaştırma için bütün yöntemlere aynı küçültülmüş derlem verilir. Hiperparametrelerden yalnız bir iki tanesi (ör. word2vec için skip-gram/CBOW seçimi ve boyut sayısı) değiştirilir; 10 hiperparametrenin her birinin 3 değeri olsa çok sayıda olası durum çıkar, bu yüzden kapsamlı arama yapılmaz. Karşılaştırma elle ve gözle değil sayısal yapılmalıdır. Uygulama örneği olarak duygu analizi, sözcük türü etiketleme (POS tagging), boşluk doldurma (cloze test) ve varlık ismi tanıma anıldı. <!-- BELİRSİZ: Hocanın uygulama örneklerini yazarak saydığı yer (02:18:22-02:19:02) altyazıda bozuk ("Posting", "Close Test", "Aşka, aşka, atıma"); örnekler büyük olasılıkla bunlardır. -->

## Dersin Toparlaması

Bu derste kelimeler arası anlamsal benzerliği bulmanın üç kuşağı yan yana kondu. İlk kuşak, WordNet gibi elle kurulmuş bir kavramsal ağaca dayanır: Leacock & Chodorow ve Wu & Palmer yalnız ağaçtaki bağları sayar, Jiang-Conrath ve Lin buna derlemden kavram olasılıklarını ekler. Bu yöntemler küçük, spesifik işlerde iyi çalışır, ama ağacı her dil için kurmak ve yaşayan dille birlikte güncel tutmak çok zordur. İkinci kuşak yalnız derleme dayanır: birbiri yerine kullanılan kelimeler, terim-doküman ve birlikte geçme matrisleriyle kümeleme, ve birlikte geçme matrisinden MDS ile koordinat üretme. Bu koordinatlar kelime ve metin sınıflandırmada başarılı oldu; kelime yörüngeleri ise koordinatların sırasından yazar tanıma yapmayı sağladı. Ama terim × terim matrisi büyük sözlüklerde ölçeklenmez ve her kelimeye tek bir sabit koordinat verir.

Üçüncü kuşak sinirsel dil modelleridir. word2vec aynı amaca, kelimeye koordinat bulmaya, tek gizli katmanlı bir ağla ve negatif örneklemeyle ölçeklenebilir biçimde ulaşır; skip-gram ve CBOW yalnız giriş-çıkış yönünde ayrışır. FastText alt kelime n-gramlarını ekleyerek sözlük dışı kelimelere de vektör üretir ve eklemeli dillerde avantaj sağlar, ama yalnız yazımı benzeyen ilgisiz kelimeleri de yaklaştırabilir. Kelime vektörleri insan yargılarıyla, analoji kümeleriyle ya da NLP uygulamaları üzerinden değerlendirilir; kelime öbekleri ise sık n-gramları tek token yapıp bu modellere verilerek temsil edilebilir. Hoca, sabit koordinatların çok anlamlılık sorununu çözmek için kelimenin koordinatının bağlama göre değiştiği sinirsel modellerin ileride görüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
