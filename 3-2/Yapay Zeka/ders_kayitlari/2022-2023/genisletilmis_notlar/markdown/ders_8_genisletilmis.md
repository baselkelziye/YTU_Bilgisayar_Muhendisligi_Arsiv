# Ders 8 Genişletilmiş Notu: Bilgi Gösterimi: Kurallar, Anlamsal Ağlar, Çerçeveler, Sahneler ve Yapay Sinir Ağları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bilgi Nedir ve Bilmenin Seviyeleri
- 2. Veriden Bilgiye
- 3. Bilginin Özellikleri (Meta Bilgi)
- 4. Bilgi Gösterim Türleri ve Kurallar
- 5. Kurallarla Çıkarım: İleri ve Geri Zincirleme
- 6. Anlaşmazlık (Çatışma) Çözümü
- 7. Anlamsal Ağlar ve Bilgi Ekonomisi
- 8. Çerçeveler (Frames)
- 9. Sahneler (Scripts)
- 10. Closed World ve Open World Sistemler
- 11. Yapay Sinir Ağlarında Bilgi Gösterimi
- Örnek Sorular

## 1. Bilgi Nedir ve Bilmenin Seviyeleri

Dersin konusu bilgi gösterimidir. Hoca, bilginin ne olduğunu tanımlamanın kolay olmadığını söyleyerek başlar. Slayttaki tanım bilerek biraz komiktir: bilgi "bilinen her şey"dir. Hemen ardından iki soru gelir: "Bilmek nedir? Bir şeyi bildiğimizi nasıl biliriz?"

Bilmenin farklı seviyeleri vardır ve herkes bir şeyi hangi seviyede bildiğinin az çok farkındadır. Slaytta bu seviyelerin göstergeleri sıralanır (ekrandan, 00:10:00):

- Anımsama / çağrıştırma / hatırlama / tanıma
- Yorumlama
- Açıklayabilir olma
- Kanıtlayabilir olma
- Hakkında konuşabilme
- Yerine getirebilir / yapabilir olma

Hoca bu maddelerin kesin bir sıralama olmadığını vurgular. En alttaki "yapabilir olma" ötekilerden biraz farklıdır: bisiklet sürmeyi ya da yüzmeyi bilmek gibi bedensel bir bilmedir. Üstteki maddeler daha soyut bir bilmeyi anlatır.

Seviyeler $E = mc^2$ formülüyle örneklenir. Formülün ne anlama geldiğini bilmeyen biri bile onu görünce "bunu bir yerde görmüştüm" diyebilir; bu tanıma seviyesidir. Bir adım ötesi $E$'nin enerji, $m$'nin kütle, $c$'nin ışık hızı olduğunu bilmektir. Sonra yorum gelir: böyle bir eşitlik varsa enerji ve kütle birbirine dönüştürülebilen şeylerdir. Formülün neden böyle olduğunu kanıtlamak ise bambaşka, çok daha yüksek bir bilme seviyesi ister.

## 2. Veriden Bilgiye

### 2.1 Veri ve bilgi ayrımı

Günlük Türkçede "veri" ve "bilgi" birbirinin yerine kullanılabilir, ama bu derste ikisi farklı kavramlardır. Veri çok miktarda bulunan şeydir. Veri işlendikçe bilgiye dönüşür. Slayttaki piramitte veri altta, bilgi üstte durur; yatay ve dikey eksenler işleme / yorumlama miktarını, soyutluk derecesini ve kişiye özel oluşu gösterir (ekrandan, 00:15:00 karesinin kenar çubuğundaki slayt). İşleme miktarı arttıkça bilginin soyutluk derecesi artar. İşlem kişinin kendi bilgileriyle yapıldığı için kişiye özel oluşu da artar. Veri herkes için aynıdır; işlenmiş bilgi ise size göre işlenmiştir.

### 2.2 Pikseller, bölgesel etiketler, tek etiket

Slaytlarda veriden bilgiye geçiş soldan sağa üç sütunla gösterilir: pikseller, bölgesel etiketler, tek bir etiket (ekrandan, 00:15:00).

- İlk örnekte bir "2" şeklinin pikselleri vardır. Pikseller herkes için aynıdır. Bunu yorumlamaya başlayınca "şurada bir çizgi, şurada bir eğri var" deriz (bölgesel etiketler). Sonra şekli "iki" kavramına ya da "A" gibi bir sese eşleriz (tek etiket). Bu geçiş her zaman mümkün değildir: şekil Latin alfabesinde olduğu için kolayca tanınır, ama başka bir alfabeden ya da hiçbir alfabede olmayan bir şekli kolayca etiketleyemeyiz.
- İkinci örnekte iki yaşlı insanın sarıldığı bir resim vardır. Pikseller aynıdır, ama "bunlar nedir?" diye sorulunca herkes farklı şeyler söyleyebilir: biri kendi büyükannesine benzetir, biri tanıdığı bir ünlüye. Herkes kendi bilgisine göre yorumlar; üzerinde düşündükçe kişiye özel oluş artar.
- Üçüncü örnekte çorba tenceresi tutan yaşlı bir kadın vardır. Bölgesel etiketler "yaşlı bir kadın, fakir bir kadın, bir çorba tenceresi tutuyor, gülümsüyor"; tek etiket "mutluluk, şükran, ?" olarak verilir.
- Dördüncü örnekte iki kilit, bir anahtar ve bir eğik çizgi vardır; tek etiket "gülen bir yüz"dür.

### 2.3 Bütün, parçaların toplamından büyük olabilir

Son iki resim arasında önemli bir fark vardır. Resimler kapatılıp yalnız bölgesel etiketlere bakılsa, yaşlı kadın örneğinde tek etiketi tahmin etmek az çok mümkündür. Kilit örneğinde ise neredeyse imkânsızdır: kilit ve anahtarın yüzle ne alakası vardır? Burada ortaya çıkan anlam parçaların toplamından daha büyüktür; parçalar özel bir şekilde düzenlendiği için bütün bir yüz oluşturur. Bu tarz bir resmi yorumlamak hem insanlar hem makineler için daha zordur. Parçaları bulmak bir iştir, parçaların nasıl bir bütün oluşturduğunu ifade etmek çok daha zor bir iştir.

## 3. Bilginin Özellikleri (Meta Bilgi)

Slaytta bilgiyi niteleyen sıfatlar sıralanır (ekrandan, 00:20:00).

- **Alan (özel - genel):** Bilgi fizik literatürü gibi belli bir alana ait olabilir ya da genel hayata dair olabilir.
- **Doğruluk (doğru - yanlış).**
- **Kesinlik (kesin - belirsiz):** Bir bilgi illa doğru ya da yanlış olmak zorunda değildir, içinde belirsizlik de olabilir.
- **Doğrulanabilirlik / yanlışlanabilirlik (bilimsel bilgi - metafizik).**
- **Güncellik (güncel - eski).**
- **Tamlık (tam - eksik).**
- **Ekonomiklik (elde edilmesi, ondan beklenenden pahalı - değersiz).**
- **Yaygınlık (çokça bilinen - hiç bilinmeyen).**

### 3.1 Doğrulanabilirlik ve bilimsel bilgi

Bir bilginin doğru olup olmadığını test edebiliyorsanız, yani üzerinde deney yapabiliyorsanız, o bilgi bilimsel bilgidir. Örneğin "dünya yüzeyinde belli bir yükseklikten bırakılan top yere şu kadar saniyede düşer" bilgisi için deney tasarlanabilir; deney yapılır, sonuç ya doğrular ya yanlışlar.

Ne doğrulanabilen ne de yanlışlanabilen bilgiler de vardır. Bir öğrencinin cevabıyla örneklenen büyü, inanç gibi konular bu türdendir. Bunlar hakkında deney yapılamaz; deney tasarlansa ve sonuç çıksa bile konu deneysel bir konu değildir, deneyle doğrulanabilecek kavramlar içermez. Bu yüzden metafiziğe girerler, bilimsel bilgi değildirler.

> **Hocanın vurgusu:** Bilimsel bir teori "şu durumda bu teori yanlıştır" diyebilmelidir. Her duruma, birbirine zıt durumlara bile açıklaması olan bir teori bilimsel bir teori olamaz. Yanlışlanabilirliğini gösterebilmelidir.

### 3.2 Ekonomiklik

Ekonomiklik, bilgiyi kullanarak elde edeceğimiz şeyin, bilgiyi elde etmenin maliyetinden pahalı mı ucuz mu olduğudur. Hoca örnek olarak Türkiye'de belli bir futbol takımının tam olarak kaç taraftarı olduğunu sorar. Bu bilgiye tam olarak erişmek çok zordur; erişilse de son hanesine kadar bilmek çoğu zaman bir anlam taşımaz, "aşağı yukarı şu kadar milyon" yeterlidir. Bilgi ne kadar kesin istenirse o kadar çok para, zaman ve emek harcanır.

Seçim anketleri de yaklaşık sonuç verir: herkese sorulmaz, bir örneklem üzerinde çalışılır. Bu yüzden örneklemin topluluğu temsil etme kabiliyeti yüksek olmalıdır. Taraftar sayısını yalnız belli bir caddede ya da belli bir stadyumun önünde sorarak bulmaya çalışmak yanlış olur.

### 3.3 Yaygınlık

Dünyada yalnız sizin bildiğiniz bilgiler vardır: dün gece gördüğünüz ve kimseye anlatmadığınız rüya gibi. Şu anda kimsenin bilmediği ama ileride bilinecek bilgiler vardır; hiç bilinmeyecek bilgiler de vardır. Bilim insanlarının temelde yaptığı şey, şu an bilinmeyen ama bilindiğinde bir işe yarayacak bilgileri ortaya çıkarmaktır. Rüya kişi için anlamlı olabilir ama toplum için değildir. $E = mc^2$ ise ilk bulunduğu anda dünyada yalnız bulanın bildiği ve insanların işine yarayacak bir bilgiydi.

## 4. Bilgi Gösterim Türleri ve Kurallar

### 4.1 Gösterim türleri

Derste bilginin bilgisayarda gösterimi için şu türler sıralanır (ekrandan, 00:25:00 karesinin kenar çubuğundaki slayt): kurallar (rules), anlamsal ağlar (semantic nets), yüklem mantığı (predicate logic), çerçeveler (frames), sahneler (scripts) ve yapay sinir ağları. Hoca bunların en sonunda en popüler olanın yapay sinir ağları olduğunu söyler.

### 4.2 Kurallar

Kurallar bilgi gösteriminde en sık kullanılan yaklaşımdır. Nedeni şudur: bilgi kurallarla ifade edildiğinde, onu kullanarak yapılan şey çok rahat açıklanabilir; elimizde açıklanabilir bir süreç olur. Slayttaki genel format (ekrandan, 00:25:00):

```text
IF condition THEN conclusion (action)

Genelde sonlu sayıda birçok kuralımız olur:
IF condition is Ai THEN conclusion is Bi

Genelde kurallarımız çok değişkenlidir:
IF condition1 and condition2 or .... and conditionn THEN conclusion
```

Veri tabanındaki gerçekler bize verilen doğrulardır; kurallar ise şartlı doğrulardır.

## 5. Kurallarla Çıkarım: İleri ve Geri Zincirleme

Çıkarım, elimizdeki verilerden elimizde olmayan verileri üretme sürecidir. Derste iki mekanizma görülür: ileri doğru zincirleme ve geri doğru zincirleme. İkisi de kesin mekanizmalardır, yani vardıkları sonuçlar kesindir. Kesin olmayan sonuçlara varan çıkarım türleri sonraki derslere bırakılır.

İki mekanizmanın sisteme sorduğu soru farklıdır:

- **Geri doğru zincirleme:** "G doğru mudur?" Tek bir şeyin doğru olup olmadığı merak edilir (hedef güdümlü).
- **İleri doğru zincirleme:** "Neler doğrudur?" Doğru olan ne varsa söylenmesi istenir (veri güdümlü).

### 5.1 Örnek bilgi tabanı

Slayttaki örnekte (Negnevitsky'nin *Artificial Intelligence* kitabından; ekrandan, 00:30:00) kuralların bulunduğu kısma bilgi tabanı (knowledge base), bilinen gerçeklerin bulunduğu kısma veri tabanı (database) denir.

```text
Veri tabanı:  A  B  C  D  E

Bilgi tabanı:
  Y & D      -> Z
  X & B & E  -> Y
  A          -> X
  C          -> L
  L & M      -> N
```

### 5.2 İleri doğru zincirleme

Her adımda, şu an bildiklerimizle koşulu sağlanan, yani uygulanabilecek kurallar belirlenir ve uygulanır. Bir kural uygulandığında sonucu veri tabanına eklenir. Sonra başa dönülür.

- 1. tur: `Y & D -> Z` uygulanamaz, Y bilinmiyor. `X & B & E -> Y` uygulanamaz, X bilinmiyor. `A -> X` uygulanır, X eklenir. `C -> L` uygulanır, L eklenir. `L & M -> N` uygulanamaz, M bilinmiyor.
- 2. tur: Artık X bilindiği için `X & B & E -> Y` uygulanır, Y eklenir.
- 3. tur: Y ve D bilindiği için `Y & D -> Z` uygulanır, Z eklenir.
- Uygulanabilecek yeni kural kalmadığı için süreç biter. M de veri tabanında olsaydı `L & M -> N` ile N de üretilirdi.

Sistemin cevabı: verilen A, B, C, D, E'ye ek olarak X, L, Y, Z de doğrudur. Bu sonuç python ile kurallar turlar halinde uygulanarak kontrol edildi (1. turda X ve L, 2. turda Y, 3. turda Z; N üretilmez).

<!-- BELİRSİZ: Altyazıda 1. tur anlatımı bozuk ("şu anda uygulayabileceğimiz bir tane kural var"); hoca önce A -> X'i, sonra C -> L'yi kullandığını söylüyor. Turların ayrımı yukarıda slayttaki kitap örneğine göre yazıldı. -->

### 5.3 Geri doğru zincirleme

Aynı bilgi tabanında soru "Z doğru mudur?" olsun (ekrandan, 00:30:00; slayttaki altı geçiş: Goal Z, Sub-Goal Y, Sub-Goal X, sonra X, Y ve Z sırayla kanıtlanır).

- Z'nin doğru olması için `Y & D -> Z` kuralına göre Y ve D doğru olmalıdır. D bilinir, Y bilinmez. Amaç Z'den Y'ye aktarılır: Y bir alt hedeftir (sub-goal).
- Y'nin doğru olması için `X & B & E -> Y` kuralına göre X, B ve E doğru olmalıdır. B ve E bilinir, X bilinmez. Yeni alt hedef X'tir.
- X'in doğru olması için `A -> X` kuralına göre A doğru olmalıdır. A doğrudur; X doğrulanır ve veri tabanına eklenir.
- X'e Y'yi doğrulamak için gelinmişti. X, B, E doğru olduğu için Y doğrulanır.
- Y ve D doğru olduğu için Z doğrulanır. Sorulan sorunun cevabı: evet, Z doğrudur.

### 5.4 İki doktor benzetmesi

Hoca farkı bir hikâyeyle anlatır. Birkaç gündür başınız ağrıyor ve doktora gidiyorsunuz.

- **Doktor A** size şikâyetlerinizi sorar, birkaç tahlil ister. Sonuçlara bakar, iki tahlil daha ister. Sonra hastalığınızı ve tedavisini söyler.
- **Doktor B** size hiçbir şey sormaz. Bütün tahlilleri içeren kâğıttaki her şeyi işaretler, hepsini yaptırmanızı ister. Sonuçlar gelince hastalığınızı ve tedavisini söyler.

**Soru:** Bu iki doktor hangi zincirlemeye karşılık gelir? **Cevap:** Bir öğrencinin cevabıyla, Doktor A geri doğru, Doktor B ileri doğru zincirlemedir. Doktor A söylediklerinizden bir tahminde bulunur ("acaba hastalık şu olabilir mi?") ve onu doğrulamaya çalışır, bu "G doğru mudur?" sorusudur. Doktor B ise "neler doğrudur?" diye bakar.

**Soru:** Hangisi size daha pahalıya mal olur? **Cevap:** Doktor B. Bütün tahlilleri istediği için daha çok zaman ve para gerekir.

**Soru:** Doktor B'nin iyi bir tarafı olabilir mi? **Cevap:** Bütün hastalıkları bulabilir; şüphelenilmeyen, belirti göstermeyen bir hastalığı da ortaya çıkarabilir. Doktor A'nın böyle bir şansı yoktur. Doktor B bir check-up'a benzer: toplumda ya da sizin için görülme olasılığı yüksek hastalıkların bir paketine karşı kontrolden geçersiniz.

> **Ek bilgi (derste anlatılmadı):** Slayt kenar çubuğundaki "Ne zaman hangisi kullanılmalı?" başlıklı slaytta (ekrandan, 00:30:00 karesinin kenar çubuğu, küçük yazı) büyük olasılıkla şu ölçüt yer alır: alanın uzmanı önce bilgi toplayıp sonra olası sonuçları arıyorsa ileri doğru, önce hipotez üretip sonra bunun doğruluğunu araştırıyorsa geri doğru zincirleme kullanılır.

## 6. Anlaşmazlık (Çatışma) Çözümü

İleri zincirlemede bazen aynı anda uygulanabilecek birden fazla kural çıkar. Hoca bunu uç bir örnekle gösterir. Bilgi tabanında üç kural olsun:

```text
Kural 1: IF trafik ışığı yeşil  THEN git
Kural 2: IF trafik ışığı kırmızı THEN dur
Kural 3: IF trafik ışığı kırmızı THEN git
```

Işık kırmızıysa iki kural uygulanabilir ve sonuçları çelişir. Veri tabanındaki bilgilere göre ateşlenebilecek kuralların oluşturduğu kümeye **çatışma kümesi** ya da **anlaşmazlık kümesi**, bu kümeden hangi kuralın uygulanacağının seçilmesine **çatışma çözümü** (conflict resolution) denir.

Çatışma çözümü yöntemleri:

- **Sıralama:** Kurallar bir ölçüte göre sıralanır, üstteki önce uygulanır.
- **Durumla eşleşme:** Duruma en çok uyan kural seçilir. Örneğin A ve B biliniyor; bir kural yalnız A'ya, başka bir kural "A ve B ve C"ye bakıyor ve ikisi de uygulanabilir sayılıyor. İkinci kuralla iki gerçek eşleştiği için onu uygulamak daha iyi denebilir. Ya da tersine, ikincisinde koşulların üçte ikisi tutarken birincisinde yüzde yüzü tuttuğu için birincisi seçilebilir.
- **Güncellik:** Kurallar bir kere yazılıp sonsuza kadar kalmaz; güncellenir, değiştirilir, yenileri eklenir. En güncel kural seçilebilir. Tam tersine en eski kural da seçilebilir: o güne kadar silinmeden, güncellenmeden veri tabanında durmuş ve çalışmıştır, yeni gelenin ne yaptığı ise belli değildir.
- **Meta kurallar (kurallar hakkında kurallar):** Kuralın kaynağına bakılabilir. Tıbbi bir sistemde iki yıllık bir doktordan ve yirmi yıllık bir doktordan gelen iki kural aynı anda uygunsa deneyimli olanınki tercih edilebilir. İnsan güvenliğiyle ilgili kurallar da olabilir: trafik örneğinde gitmek durmaktan daha risklidir, etrafa zarar vermemek için durmayı seçmek daha mantıklıdır.

Veri tabanında neden böyle çatışan kurallar olsun? Hatayla olabilir. Kurallar farklı insanlardan toplandığında farklı insanlar farklı şeyler söyleyebilir. Bu yüzden böyle durumlar gerçekten oluşur ve bunlara mutlaka bir çözüm bulunmalıdır.

## 7. Anlamsal Ağlar ve Bilgi Ekonomisi

### 7.1 Tanım

Anlamsal ağ (semantic net), bilgiyi birbirine değişik tipte bağlarla bağlanmış bir düğüm kümesi şeklinde gösterir (ekrandan, 00:40:00). Düğümler kavramları, bağlar kavramlar arasındaki ilişkileri gösterir. Bağların türleri vardır: "instance of", "is a", "has a", "part of". Oklar bağlantının yönünü gösterir ve bağlantılar çoğunlukla yönlüdür; yapı bir graf gibi düşünülebilir. Bütün hikâye "şununla şunun arasında şu tür bir ilişki vardır" demektir. Slayta göre anlamsal ağların popülerliğinin en büyük sebebi grafiksel gösterime çok uygun olmalarıdır.

Slayttaki örnek (ekrandan, 00:40:00):

```text
Person  --Is-A-->      Mammal
Person  --Has-Part-->  Head
Mary    --Instance-->  Person
Mary    --Home-Town--> San Jose
Mary    --School-->    Stanford
```

### 7.2 Hiyerarşik anlamsal ağ

İkinci örnek hiyerarşik bir ağdır (Collins ve Quillian, 1969; ekrandan, 00:45:00):

```text
ANIMAL  : can Breathe, has Skin, can Move
BIRD    : is a ANIMAL; can Fly, has Wings, has Feathers
FISH    : is a ANIMAL
CANARY  : is a BIRD; can Sing, is Yellow
OSTRICH : is a BIRD; cannot Fly, is Tall
```

Hayvanlar nefes alır, derileri vardır, hareket ederler. Kuşlar ve balıklar birer hayvandır. Kanarya bir kuştur. Deve kuşu da bir kuştur ama uçamaz ve uzundur. Slaytın alt yazısı: "Bazı tür ilişkiler çıkarıma uygundur. Ör: isa yollarında has ilişkileri."

### 7.3 Bilgi ekonomisi

Bilgi bu formda tutulduğunda "kanaryalar nefes alır, derileri vardır, hareket ederler, uçabilirler, kanatları ve tüyleri vardır" bilgilerini ayrıca yazmaya gerek yoktur. Bu bilgiler ağın içinde zaten vardır; istendiğinde "is a" bağları izlenerek erişilir. Buna bilgi ekonomisi denir: istediğimiz zaman erişebildiğimiz bir bilgiyi bir daha üretip tutmanın anlamı yoktur.

Aynı durum ileri zincirleme örneğinde de vardır. X, L, Y, Z'ye istediğimiz zaman erişebiliyoruz; veri tabanında A, B, C, D, E'yi ve bilgi tabanındaki kuralları tutmak yeterlidir. X, L, Y, Z'yi ayrıca eklemek gerekmez, veri tabanı çok daha küçük kalır.

**Soru:** Sokakta bir kedi gördüğünüzü düşünün. O kedinin arka ayağındaki bir hücrenin mitokondrisi var mıdır? **Cevap:** Evet, vardır. Böyle bir soruyu daha önce hiç düşünmemiş olsanız da çok yüksek bir kesinlikle doğru cevap verebilirsiniz. Bunun sebebi insanların da bilgiyi slayttaki gibi hiyerarşik bir yapıda tutmasıdır: kedi bir hayvandır, hayvanın bacağındaki hücreler hayvan hücresidir, hayvan hücrelerinin hepsinde mitokondri vardır. Bu bilgiler yeterlidir. "Kedilerin sol arka bacaklarındaki hücrelerin mitokondrisi vardır", "kedilerin sol ön bacaklarındaki hücrelerin mitokondrisi vardır" gibi bilgileri tek tek tutmanıza gerek yoktur; veri tabanınızı şişirmezsiniz.

### 7.4 Ezber: çıkarım yerine önbellek

Çıkarım yapılabilecek bazı sonuçların çıkarım yapılmış halini de tutarız, yani ezberleriz. $7 \times 8$ sorulduğunda kimse yedi tane sekizi toplamaz. Toplayarak da bulunabilir, bu bir çıkarım süreci olurdu; ama cevap doğrudan bir önbellekten (cache) çekilir. Çıkarım uzun bir süreçtir. Buna karşılık $249 \times 165$'in sonucu ezberde tutulmaz, gerektiğinde hesaplanır. Fark kullanım sıklığıdır: $7 \times 8$ günlük hayatta çok daha sık karşımıza çıkar. Sık karşılaşılan sonuçlar önbelleğe alınır.

## 8. Çerçeveler (Frames)

Çerçeveler aslında nesneye yönelik programlamanın yapay zekâdaki kullanımıdır. Çok farklı bir yanı yoktur ama birkaç jargonu vardır: çerçeve (frame), öznitelik (slot) ve yuva (facet). Sınıf bir sınıf çerçevesine, nesne bir nesne çerçevesine karşılık gelir; bir çerçevenin çeşitli öznitelikleri, bir özniteliğin de çeşitli yuvaları olabilir (ekrandan, 01:00:00 karesinin kenar çubuğundaki slaytlar).

Slayttaki çerçeve tabanlı bilgi tabanı ve onun birinci derece mantığa çevirisi (Russell ve Norvig'in kitabının şekillerinden; ekrandan, 01:00:00):

```text
Animals  : Alive = T, Flies = F
Birds    (Subset of Animals) : Legs = 2, Flies = T
Mammals  (Subset of Animals) : Legs = 4
Penguins (Subset of Birds)   : Flies = F
Cats     (Subset of Mammals)
Bats     (Subset of Mammals) : Legs = 2, Flies = T
Opus     (Member of Penguins): Name = Opus, Friend = Bill
Bill     (Member of Cats)    : Name = Bill, Friend = Opus
Pat      (Member of Bats)    : Name = Pat
```

```text
Rel(Alive, Animals, T)     Rel(Flies, Animals, F)
Birds ⊂ Animals            Mammals ⊂ Animals
Rel(Flies, Birds, T)       Rel(Legs, Birds, 2)      Rel(Legs, Mammals, 4)
Penguins ⊂ Birds           Cats ⊂ Mammals           Bats ⊂ Mammals
Rel(Flies, Penguins, F)    Rel(Legs, Bats, 2)       Rel(Flies, Bats, T)
Opus ∈ Penguins            Bill ∈ Cats              Pat ∈ Bats
Name(Opus, "Opus")  Name(Bill, "Bill")  Friend(Opus, Bill)  Friend(Bill, Opus)  Name(Pat, "Pat")
```

Animals çerçevesinin altında Alive ve Flies adlı iki slot vardır; değerleri True ve False'tur. Çerçevelerin alt kümeleri vardır ve her alt kümenin kendi slotları olabilir. Bir slotun değeri başka bir çerçeve de olabilir: biri penguen, biri kedi olan Opus ve Bill birbirinin arkadaşıdır.

Nesneye yönelik programlamada nesnelerin özellikleri yanında fonksiyonları da olabildiği gibi, çerçeveler de prosedürler içerebilir: bir değer silinirken ya da eklenirken çalışan, değerin belli aralıklarda kalmasını sağlayan fonksiyonlar gibi. Nesneye yönelik programlamadan temel farkı yoktur; bilgiler nesnenin içinde tutulur. Bu anlamda yapay zekâya özgü bir gösterim türü değildir.

## 9. Sahneler (Scripts)

### 9.1 Fikir

Hoca sahneleri bir hikâyeyle anlatır: "Ali bugün çok acıktı, bir lokantaya gitti, çıkarken garsona yüklü bir bahşiş verdi." Ardından sorular sorar:

- Ali yemek yedi mi? Muhtemelen.
- Ali yemeği beğendi mi? Muhtemelen.
- Ali bugün bir menü okumuş mudur? Muhtemelen.

Yemek yedi, beğendi, menüyü okudu, masaya oturdu, garsonla konuştu gibi şeylerin hiçbiri metinde yazmaz, ama bu sorulara doğru cevap veririz. Sahne yaklaşımına göre bunun sebebi, kafamızda bu tür olayları senaryolar, yani sahneler halinde tutmamızdır. Günlük hayatta sık yaptığımız birçok şeyin (yemek yemek, otobüse binmek, ders çalışmak) bir senaryosu vardır; her biri birbirini izleyen basmakalıp dizilerden oluşur. Bunlar tanımlanabilirse, bir sahnede olan şeylerin hepsi söylenmese bile bilgisayar onların olduğunu ya da belli bir olasılıkla olduğunu anlayabilir. Sahneler, söylenmeden anlaşılan, sağduyu (common sense) diyebileceğimiz bilgiyi tutar ve gözlenmeyen olayları tahmin etmeye yarar.

### 9.2 Bir sahnenin bileşenleri

Bir sahnenin başlama şartı, rolleri, alt sahneleri ve sonucu vardır. Slayttaki bileşenler (ekrandan, 01:05:00 karesinin kenar çubuğu): sahne ismi; başlama şartları (sahnenin ne zaman aktif olacağı, sahne başlamadan önceki durum); roller; nesneler; alt sahneler; sonuç (sahne bittikten sonraki durum).

Lokanta sahnesinin ana kısmı (ekrandan, 01:05:00 karesinin kenar çubuğu, küçük yazı):

```text
Sahne ismi      : Lokanta
Nesneler        : Masalar, Menü, Yiyecek, Para
Roller          : Müşteri, Garson, Ahçı, Kasiyer, Lokanta sahibi
Giriş koşulları : Müşteri aç; Müşterinin parası var
Sonuçlar        : Müşteri tok; Müşterinin daha az parası var;
                  Lokanta sahibinin daha çok parası var; Müşteri memnun
```

<!-- BELİRSİZ: Ana kısım tablosu küçük bir kenar çubuğu küçük resminden okundu; ayrıntılar tam okunamamış olabilir. -->

Alt sahneler (ekrandan, 01:05:00):

```text
Alt sahne 1: lokantaya giriş
  Müşteri lokantaya girer. Boş yer arar. Boş yeri görür.
  Boş masaya gider. Masaya oturur.
Alt sahne 2: sipariş
  Müşteri menüyü alır. Menüyü okur. Yiyecek kararını verir.
  Garsonu çağırır. Yiyeceği garsona söyler.
Alt sahne 3: yiyeceğin hazırlanması
  Garson siparişi ahçıya söyler. Ahçı yemeği hazırlar.
  Ahçı garsona haber verir.
Alt sahne 4: yemeğin yenmesi
  Garson yemeği müşteriye getirir. Müşteri yemeği yer.
Alt sahne 5: lokantadan ayrılma
  Müşteri garsonu çağırır. Garsondan hesabı ister.
  Garson hesabı getirir. Müşteri parayı verir.
  Garson parayı kasiyere verir. Müşteri lokantadan ayrılır.
```

Hoca bunun 1980'lerin fikri olduğunu, örneğin o zamanın eski usul lokantasını anlattığını, bugün birçok şeyin değiştiğini belirtir.

### 9.3 Neden yaygınlaşmadı?

Fikrin sahipleri (Roger Schank ve arkadaşları) bine yakın sahne yazmışlar, ama sahnelerin kendi içindeki varyasyonları bir türlü bitirememişler. Çok basmakalıp görünen olayların bile çok sayıda varyasyonu olduğunu görmüşler. Arama algoritmaları diliyle, buradaki dallanma faktörü (branching factor) çok yüksektir: lokantada yemek yemek gibi basit bir olayda bile neler olabileceğinin sayısı çok büyüktür. Sahneleri elle yazıp bilgisayara vermek ölçeklenebilir bir çözüm değildir; "elle bu iş olmaz" sonucuna varılmıştır.

## 10. Closed World ve Open World Sistemler

Bu noktada iki kavram çıkar (ekrandan, 01:10:00 karesinin kenar çubuğundaki slaytlar):

- **Closed world (kapalı dünya) sistem:** Sistemde var olmayan bilgilerin yanlış olduğu kabul edilir. Örneğin sistemde "Alex'in Bob ve Jane adlı çocukları vardır" bilgisi varsa, Alex'in sisteme girilmemiş çocukları yok sayılır ve "Alex'in iki çocuğu vardır" sonucuna varılır.
- **Open world (açık dünya) sistem:** Sisteme girilmemiş bilgilerin yanlış olduğu sonucuna varılmaz; bu bilgiler eksik veya yanlış olabilir. Aynı örnekte, sistemde Alex'in çocuklarıyla ilgili bir sayı kısıtı yoksa "Alex'in iki çocuğu vardır" sonucuna varılamaz.

**Soru:** Bilgisayarda hangisini gerçekleştirmek daha zordur? **Cevap:** Bir öğrencinin cevabını hoca onaylar: open world daha zordur. Closed world'de olmayan bilgi doğrudan yanlış sayılır ve üzerine düşünülmez; open world'de ise olmayan bilginin de olabileceği hesaba katılmalıdır.

<!-- BELİRSİZ: Öğrencinin cevabı ve hocanın gerekçesi altyazıda bozuk (01:07:34); "open world daha zordur" sonucu bağlamdan çıkarıldı. -->

## 11. Yapay Sinir Ağlarında Bilgi Gösterimi

### 11.1 Bilgi ağırlıklarda saklanır

Son gösterim türünde bilgi nesnelerde, düz metinlerde, kurallarda ya da "şununla şunun arasında şu ilişki var" yapılarında tutulmaz; yapay sinir ağında tutulur. Bir eğitim kümesi oluşturulur ve ağ bu kümeyle eğitilir. Eğitim bitince eğitim kümesiyle işiniz kalmaz: kümedeki bütün bilgi ağın ağırlıklarına dönüşmüştür. Ağ, öğrendiği haliyle bu bilgiyle iş yapar.

Ağın yapısı bilginin tutulma tarzını bir miktar etkiler: tek ya da çok katmanlı yapılar, önceki girdileri de kullanarak sekans türünden işlem yapan özyinelemeli yapılar vardır. Bunların ayrıntıları dersin kapsamı dışında bırakılır.

### 11.2 Doğal dilde: kelime vektörleri

Kelimelerin ağın ağırlıklarında saklanması, kelimeler için sayısal bir uzayda bir karşılık (eşleme) bulunması demektir. Bir kelime örneğin on ya da yüz boyutlu bir uzayda bir nokta olarak temsil edilir.

"Beşiktaş kazandı" ve "Kara Kartal yendi" cümlelerinin hiçbir ortak kelimesi yoktur, ama aynı anlama gelirler. Bunu anlayabilmek için "Beşiktaş" ile "Kara Kartal"ın anlamca yakın olduğunu ve "kazandı" ile "yendi"nin anlamca yakın olduğunu bilmek gerekir. İkisi birden bilinirse cümlelerin benzer anlamda olduğu bulunur. Kelimelerin ya da daha karmaşık cümlelerin temsil edildiği bu uzaylar sinir ağının ağırlıklarında gizlidir. Eğitimden sonra ağdan "şu kelimeye en yakın kelimeler nelerdir?" diye sorulabilir.

Slayttaki ayrıntılar (ekrandan, 01:10:00):

- Word2vec (Mikolov ve ark., 2013) ve fastText (Bojanowski ve ark., 2017).
- Tek gizli katmana sahip bir yapay sinir ağıdır.
- $C = 2$ için bağlam: $(w_{t-2}, w_{t-1}, w_t, w_{t+1}, w_{t+2})$.
- Skip-gram: giriş $w_t$, çıkış $(w_{t-2}, w_{t-1}, w_{t+1}, w_{t+2})$'nin her biri.
- CBOW: giriş $(w_{t-2}, w_{t-1}, w_{t+1}, w_{t+2})$'nin her biri, çıkış $w_t$.
- Skip-gram modelinin şeması: giriş katmanı $1 \times |V|$ boyutlu 1-hot vektör; $W$ ağırlık matrisi $|V| \times d$; projeksiyon katmanı $1 \times d$ boyutlu, $w_t$'nin gömmesi (embedding); $C$ matrisi $d \times |V|$; çıkış katmanı $1 \times |V|$ boyutlu, bağlam kelimelerinin olasılıkları.

### 11.3 Cümle temsili ve çeviri

Bir adım daha farklı bir yapı: "Şu Türkçe cümlenin İngilizce karşılığı nedir?" Burada kelimelerin yanında cümlelerin kendisi de vektörlere dönüştürülür. Kenar çubuğundaki slayta göre metin, içerdiği kelimelerin ortalamasıyla ya da seq2seq türü problemler için encode-decode mimarileriyle temsil edilebilir (ekrandan, 01:10:00 karesinin kenar çubuğu). Slaytta özyinelemeli ağların (RNN) bir türü olan LSTM yapısı görünür. Hoca bugün bunların yerine daha çok öz-dikkat (self-attention) kullanan transformer bloklarının kullanıldığını, ama temel hikâyenin aynı kaldığını söyler: bilgi sinir ağının ağırlıklarında saklanır ve işlenir. Eğitim kümesi harici bir yerde durur, ama eğitimden sonra içindeki gerekli bilgiler ağa eklenmiş olur.

### 11.4 Görüntüde: katmanlı örüntüler

Görüntüde de çok benzer bir durum vardır (ekrandan, 01:15:00). Slaytın başlığı "Görüntü işlemede YSA'larda bilgi gösterimi", maddesi "Önce basit, sonra kompleks örüntüleri temsil"dir. Şekilde Layer 1'de kenar benzeri basit parçalar, Layer 2'de göz, burun gibi yüz parçaları, Layer 3'te bütün yüzler görülür (konvolüsyonel derin inanç ağları üzerine bir çalışmadan).

Kedilerin bıyıkları, kuyrukları, dört ayakları, gözleri olduğu gibi bilgiler günümüzde harici olarak yazılıp verilmez. Bunun yerine örnekler verilir: "bu bir kedi". Bu tür bilgiler o formda olmasa da ağın ağırlıklarında saklanır. Kuyruk, belki alt seviyedeki belli şekillerin üst seviyelerde birleşmesiyle oluşan bir şablon olarak ağın içinde ortaya çıkar; kedi gözü de öyle. Bunlar şablonlar gibi hayal edilebilir: en altta en basitleri, üstte onların birleşimlerinden oluşan daha karmaşıkları, daha üstte onların da birleşimlerinden oluşan daha karmaşıkları.

## Örnek Sorular

**1. (derste sözlü, 00:17:31)** Ne doğrulanabilen ne de yanlışlanabilen bilgi türleri var mıdır? Bunlar ne tür bilgilerdir?

> **Cevap (derste verildi):** Vardır; bunlar metafiziğe girer (bir öğrencinin örneğiyle büyü; inanç gibi konular). Hakkında deney yapılamadığı için bilimsel bilgi değildir.

**2. (ekrandan, 00:30:00)** Veri tabanı A, B, C, D, E ve bilgi tabanı `Y & D -> Z`, `X & B & E -> Y`, `A -> X`, `C -> L`, `L & M -> N` olsun. (a) İleri doğru zincirleme hangi gerçekleri üretir? (b) Geri doğru zincirleme ile "Z doğru mu?" sorusu nasıl cevaplanır?

> **Cevap (derste verildi):** (a) Sırasıyla X ve L, sonra Y, sonra Z üretilir; M bilinmediği için N üretilmez. (b) Hedef Z → alt hedef Y → alt hedef X; X, A'dan doğrulanır, ardından Y ve Z doğrulanır: Z doğrudur.

**3. (derste sözlü, 00:33:32)** Şikâyetleri dinleyip yalnız gereken tahlilleri isteyen Doktor A ile hiçbir şey sormadan bütün tahlilleri isteyen Doktor B hangi zincirleme türlerine karşılık gelir? Hangisi daha pahalıdır, pahalı olanın avantajı nedir?

> **Cevap (derste verildi):** Doktor A geri doğru, Doktor B ileri doğru zincirlemedir. Doktor B daha pahalıdır (zaman ve para), ama belirti vermeyen, şüphelenilmeyen hastalıkları da bulabilir (check-up gibi).

**4. (derste sözlü, 00:43:44)** Sokaktaki bir kedinin arka ayağındaki bir hücrenin mitokondrisi var mıdır? Daha önce hiç düşünmediğimiz bu soruya nasıl kesin cevap verebiliyoruz?

> **Cevap (derste verildi):** Evet, vardır. Bilgiyi hiyerarşik tuttuğumuz için: kedi bir hayvandır, hayvan hücrelerinin hepsinde mitokondri vardır. Bu genel bilgiler yeterlidir, her özel durumu ayrıca tutmayız (bilgi ekonomisi).

**5. (derste sözlü, 00:45:38)** $7 \times 8$'in sonucunu ezberde tutarken $249 \times 165$'in sonucunu neden tutmayız?

> **Cevap (derste verildi):** $7 \times 8$ günlük hayatta çok daha sık karşımıza çıkar; sık gereken sonuçlar çıkarım yapılmadan önbellekten çekilir. Ötekisi gerektiğinde hesaplanabilir.

**6. (derste sözlü, 01:01:27)** "Ali bugün çok acıktı, bir lokantaya gitti, çıkarken garsona yüklü bir bahşiş verdi." Ali yemek yedi mi, yemeği beğendi mi, menü okudu mu? Metinde yazmayan bu sorulara nasıl cevap verebiliyoruz?

> **Cevap (derste verildi):** Muhtemelen evet. Kafamızda lokanta gibi olayları basmakalıp senaryolar (sahneler) halinde tuttuğumuz için söylenmeyen olayları da tahmin edebiliriz.

**7. (derste sözlü, 01:07:20)** Closed world ve open world sistemlerden hangisini bilgisayarda gerçekleştirmek daha zordur?

> **Cevap (derste verildi):** Open world. Closed world'de sistemde olmayan bilgi doğrudan yanlış sayılır; open world'de olmayan bilginin de doğru olabileceği hesaba katılmalıdır.

## Dersin Toparlaması

Bu derste bilginin ne olduğu, bilmenin seviyeleri ve verinin işlenerek nasıl soyut ve kişiye özel bilgiye dönüştüğü tartışıldı; bilginin alan, doğruluk, kesinlik, doğrulanabilirlik, güncellik, tamlık, ekonomiklik ve yaygınlık gibi özellikleri incelendi. Ardından bilginin bilgisayarda gösterim türleri ele alındı. Kurallar en yaygın ve en açıklanabilir gösterimdir; kurallarla kesin sonuçlu çıkarım ileri doğru zincirlemeyle ("neler doğru?") ya da geri doğru zincirlemeyle ("şu doğru mu?") yapılır ve aynı anda ateşlenebilen kurallar için çatışma çözümü gerekir. Anlamsal ağlar "is a" hiyerarşisiyle bilgi ekonomisi sağlar; çerçeveler nesneye yönelik yapının yapay zekâdaki karşılığıdır; sahneler sağduyu bilgisini basmakalıp senaryolarla tutmaya çalışır ama elle yazılması ölçeklenmemiştir. Closed world ve open world varsayımları eksik bilginin nasıl yorumlanacağını belirler.

Dersin sonunda günümüzde en yaygın yaklaşım olan yapay sinir ağlarına geçildi: bilgi elle yazılmaz, örneklerden öğrenilip ağın ağırlıklarında saklanır; kelime vektörleri, cümle temsilleri ve görüntüde katman katman karmaşıklaşan örüntüler bunun örnekleridir. Kurallarla çıkarım ve kesin olmayan çıkarım türleri sonraki derslere bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
