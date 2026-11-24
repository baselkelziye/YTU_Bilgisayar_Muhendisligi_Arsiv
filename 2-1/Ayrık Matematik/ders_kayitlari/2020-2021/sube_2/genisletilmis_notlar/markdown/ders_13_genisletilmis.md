# Ders 13 Genişletilmiş Notu: Sonlu Durum Makineleri: Tanım, Mealy ve Moore Makineleri ve Tasarım Örnekleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sonlu Durum Makineleri ve Hesaplama Kuramı
- 2. RAM Modeli
- 3. Günlük Hayattan Örnek: Turnike
- 4. Mealy ve Moore Makineleri
- 5. Sonlu Durum Makinesinin Biçimsel Tanımı ve Kabul Durumu
- 6. Durum Tablosu ve Deterministik Makine
- 7. Bir Girdi İçin Çıkış Dizisini Bulma
- 8. Sağa Bir Kez Öteleme Yapan Makine
- 9. Seri Toplama Makinesi
- 10. Giriş (Login) Makinesi
- 11. Dört Karakterli Değişken Adı Denetleyicisi
- 12. Art Arda Üç 1 Gelince Hata Veren Makine
- 13. Dersin Diğer Derslerle Bağlantısı
- Örnek Sorular

## 1. Sonlu Durum Makineleri ve Hesaplama Kuramı

Dersin son konusu sonlu durum makineleridir (SDM, ingilizcesi finite state machines, FSM) (ekrandan, 00:05:00). Hoca konuya, öğrencilerin lojik devreler dersinde flip-floplardan sonra Mealy ve Moore makinelerini görüp görmediklerini sorarak başladı; öğrenciler gördüklerini söyledi.

Hoca bu konunun bu ders için kısa bir giriş olduğunu belirtti. Ayrıntısı sonraki dönemde alınacak hesaplama kuramı dersinde işlenir; buradaki anlatım o dersin başlıklarını tanıtmak gibidir. Hesaplama kuramı şu soruyla ilgilenir: Bir program yazarken ya da algoritma geliştirirken, işi en sonunda yapacak makineyi bir modele göre belirleriz; program gerçek bir makine üzerinde çalışacaktır. Örneğin yazdığımız bir programdaki `for` döngüsünün belli bir kuralı vardır. Derleyicinin bu kuralı nasıl tanıyacağı, nasıl derleyeceği ve arkada hangi optimizasyonların yapılacağı bu alanın konusudur. Hesaplama kuramında en basit makinelerden başlanır ve daha karmaşık makinelere doğru ilerlenir. Bu dersin üzerine de biçimsel diller ya da derleyici tasarımı dersleri gelir; gerçek bir derleyicinin nasıl yapılacağı orada işlenir.

## 2. RAM Modeli

Bugün C gibi dillerde kodunu yazıp derlediğimiz programların dayandığı makine modeli RAM modelidir. Program kodu bir hafıza birimine kopyalanır ve bu hafıza biriminin özelliği rastgele erişilebilir olmasıdır.

Hoca bunu sıralı erişimli hafıza birimleriyle karşılaştırdı. Teyp ve kaset gibi birimlerde erişim sıralıdır. Böyle bir ortamda yazdığınız bir `for` döngüsünün ikilik karşılığını tanımak için makinenin şeridi karakter karakter ileri geri sararak kontrol etmesi gerekirdi. Bu, performansı düşüren olumsuz bir durumdur. RAM modeli sayesinde rastgele erişim yapılarak bu işler çok daha rahat yapılır. Hoca bu konuların en temellerinin hesaplama kuramı kapsamında anlatıldığını söyledi.

## 3. Günlük Hayattan Örnek: Turnike

### 3.1 İki durumlu turnike

Sonlu durum makinelerinin günlük hayattaki karşılığı birçok yerde görülür. Basit bir cihaz olan turnikenin içinde aslında bir sonlu durum makinesi vardır. Turnikenin genel olarak iki durumu vardır: **kapalı** ve **açık**.

- Kapalıyken jeton atılabilir. Atılan jeton durumun değişmesine yol açar: turnike açılır.
- Açıkken turnikeden geçilirse turnike yeniden kapalı duruma döner.
- Açıkken jeton atılırsa ne olacağı da tanımlanmalıdır. Örneğin bir tahliye kısmı vardır ve jeton dışarı geri verilir.

Hoca, açık durumda jeton atılması için bir tanım yapılmazsa böyle bir makineye deterministik olmayan makine dendiğini söyledi. Kapalı durum için tanım yapıldığından orada bir sorun yoktur. Burada bir eylem gerçekleştiğinde durumun değiştiğini görürüz.

> **Ders sonrası not:** Hoca, bir durumda bir girdinin geçişi tanımlanmazsa makinenin deterministik olmadığını söyledi. Büyük olasılıkla daha doğru ifade şudur: tanımlanmamış geçişi olan makine eksik tanımlı (kısmi) bir makinedir. Deterministik olmama ise aynı durumda aynı girdi için birden fazla sonraki durumun mümkün olmasıdır (bkz. Bölüm 6'daki deterministik tanımı).

### 3.2 Üç durumlu turnike

Hoca bazı metrolarda gördüğü daha gelişmiş bir turnike modelini bir videoyla gösterdi. Bu turnikede yolcu kağıt bileti turnikenin giriş kısmına bırakır. Bileti bıraktıktan sonra turnike hemen açılmaz; yolcu bileti geri almayı bekler ve bileti alır almaz turnike açılır. Yani bilet verilmiş olsa bile geri alınmadan durum değişmez. Yolcu geçer geçmez farklı bir mekanizmayla bir durum değişimi daha olur; bu da aynı anda iki kişinin geçmesini engeller.

Böylece bu turnike üç durumludur: bileti vermek, bileti almak ve turnikeden geçmek. Ancak üçüncü adımdan sonra başlangıç durumuna geri dönülür.

### 3.3 Durumlar ve geçişler graf olarak

Turnikenin açıktan kapalıya ya da kapalıdan açığa geçmesi için bir eylem tanımlanır: jeton ekleyerek kapalı durumdan açık duruma, turnikeden geçerek açık durumdan kapalı duruma geçilir. Her durumda yapılacak eylemlerin belli bir anlamı vardır. Hoca bunu lojikteki flip-flopa benzetti: flip-flop bir durumdayken 0 ya da 1 gelmesi gibi. Flip-flop ikili düzeyde düşünür, ama burada çok sayıda düzey (durum) olabilir.

Açık durumu grafın bir düğümü, kapalı durumu başka bir düğümü olarak alırsak, bu düğümlerden çıkan ve bunlara gelen kenarlar çok farklı olabilir. Geçişlerdeki etiketler genellikle iki parçalıdır:

- İlk parça gerçekleşen olayın kendisidir (girdi).
- İkinci parça olayın sonunda oluşan sonuçtur (çıkış).

Örneğin "kapalı durumdayken jeton bırakıldığında açık duruma geç ve çıkışta şu olsun" denir. Etiket hem durum geçişini hem de çıkışta olacak şeyi söyler.

## 4. Mealy ve Moore Makineleri

Hoca, çıkış üreten makinelerin iki türlü olduğunu ve bu yüzden Mealy ve Moore makinelerini sorduğunu söyledi. Ekranda açtığı kaynakta şu tanım yer alıyordu (ekrandan, 00:10:00): Sonlu otomatlar her geçişe karşılık gelen çıkışlara sahip olabilir. Çıkış üreten iki tür sonlu durum makinesi vardır: Mealy makinesi ve Moore makinesi.

**Mealy makinesi:** Çıkışı hem o anki duruma hem de o anki girdiye bağlı olan sonlu durum makinesidir. Kaynakta 6'lı $(Q,\Sigma,O,\delta,X,q_0)$ ile tanımlanır:

- $Q$: durumların sonlu kümesi,
- $\Sigma$: girdi alfabesi denen sonlu sembol kümesi,
- $O$: çıkış alfabesi denen sonlu sembol kümesi,
- $\delta: Q\times\Sigma\to Q$: girdi geçiş fonksiyonu,
- $X: Q\times\Sigma\to O$: çıkış geçiş fonksiyonu,
- $q_0\in Q$: girdinin işlenmeye başladığı başlangıç durumu.

Ekrandaki Mealy durum tablosu şöyledir (ekrandan, 00:10:00):

| Bulunulan durum | girdi 0: durum | girdi 0: çıkış | girdi 1: durum | girdi 1: çıkış |
| :---: | :---: | :---: | :---: | :---: |
| $\to a$ | $b$ | $x_1$ | $c$ | $x_1$ |
| $b$ | $b$ | $x_2$ | $d$ | $x_3$ |
| $c$ | $d$ | $x_3$ | $c$ | $x_1$ |
| $d$ | $d$ | $x_3$ | $d$ | $x_2$ |

**Moore makinesi:** Hoca, Moore makinesinde de durumlar arası geçişlerin (0 mı geldi, 1 mi geldi) Mealy'deki gibi olduğunu, ama durumun içinde ek bir bilgi tanımlandığını söyledi. Derste çizilen örneklerin bir anlamda bu türlerden birine benzediğini belirtti. Ayrıntıların hem lojikte hem hesaplama kuramında anlatıldığını, burada çok fazla ayrıntıya girmeye gerek olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Moore makinesinde çıkış yalnız bulunulan duruma bağlıdır ve diyagramda durumun içine yazılır; Mealy makinesinde çıkış durum ile girdinin birlikte belirlediği geçişe bağlıdır ve kenar üzerine yazılır. Bu derste kullanılan $g: S\times I\to O$ çıkış fonksiyonu Mealy türüne karşılık gelir.

Bütün bu makinelerin ortak özelliği sonlu sayıda duruma sahip olmalarıdır. Dil tanıma ve konuşma tanıma da bunların uygulama örnekleri arasında sayılır.

## 5. Sonlu Durum Makinesinin Biçimsel Tanımı ve Kabul Durumu

### 5.1 6'lı tanım

Slayttaki tanım şöyledir (ekrandan, 00:15:00): Bir sonlu durum makinesi

$$M=(I,O,S,f,g,\sigma)$$

6'lısından oluşur:

- a) $I$: giriş sembollerinin sonlu kümesi (makineye girdi olarak neler verilebileceği),
- b) $O$: çıkış sembollerinin sonlu kümesi,
- c) $S$: sonlu durumlar kümesi (turnikedeki açık ve kapalı gibi iki, üç ya da daha fazla ama sonlu sayıda durum),
- d) $f: S\times I\to S$: gelecek durumun fonksiyonu; durumlar ile girdilerin kartezyen çarpımından durumlara giden fonksiyon,
- e) $g: S\times I\to O$: çıkış fonksiyonu; girdilere karşı gelecek çıkışları verir,
- f) $\sigma$: başlangıç durumu; $t=0$ anında hangi durumdan başlanacağı.

Hoca farklı kaynaklarda farklı semboller kullanıldığını, örneklerin farklı türlerde görülebileceğini belirtti.

### 5.2 Kabul durumu

Hoca bu 6'lıya ek olarak bir de **kabul durumu** olduğunu söyledi; bu özellikle hesaplama kuramında görülür. Makine bir durumdan bir duruma gider; işlenen ifadenin sonunda ulaşılan durum kabul durumuysa ifade kabul edilir, yani istenen duruma ulaşılmış olur. İstenirse kabul durumuna gelindikten sonra makine yeniden başlangıç durumuna döndürülebilir. Kabul durumu, graf gösteriminde iç içe iki daireyle çizilir; bir düğüm çift daireyse kabul durumuna ulaşılmış demektir. Hoca bunun zor bir şey olmadığını, ezberlenecek bir tarafı olmadığını, kullanıla kullanıla öğrenileceğini söyledi.

### 5.3 Düzenli ifade örnekleri

Kabul durumu düzenli ifadelerde (regular expressions) sıkça görülür. Hoca şu ifadeyi verdi:

$$a^*\,b^*\,c^*$$

Bu ifade istenen sayıda $a$, ardından istenen sayıda $b$, ardından istenen sayıda $c$ içeren dizgileri tanımlar. Örneğin $abc$, $abbc$, $abcc$ ve $aabcc$ kabul edilir.

İkinci örnek olarak $a^k\,b^l\,c^m$ biçiminde dizgiler ve $k<l<m$ kuralı verildi. Sayılar sıfırdan büyük alınırsa en kısa örnek $k=1$, $l=2$, $m=3$ ile $abbccc$ olur. Buna karşılık $aabbccc$ kabul edilmez, çünkü $k=l=2$ olduğundan $k<l$ şartı sağlanmaz.

> **Ders sonrası not:** Hoca bu kuralı "tanımlayan otomatı yazın" diye sorulabilecek bir örnek olarak verdi. Büyük olasılıkla $a^k b^l c^m$, $0<k<l<m$ dili bir sonlu durum makinesiyle tanınamaz, çünkü $a$, $b$ ve $c$ sayılarını karşılaştırmak sınırsız bellek ister. $a^*b^*c^*$ ise düzenli bir dildir ve sonlu durum makinesiyle tanınır. Bu ayrım hesaplama kuramında ele alınır.

## 6. Durum Tablosu ve Deterministik Makine

### 6.1 Tablo gösterimi

Hoca bir örnek verdi. Girdi kümesi $I=\{a,b\}$, çıkış kümesi $O=\{0,1\}$, durumlar $\sigma_0$ ve $\sigma_1$'dir. Geçiş fonksiyonu graf ile gösterilebildiği gibi tablo ile de gösterilebilir. Hoca, lojikte bu tablonun daha çok kullanıldığını, flip-flopların Karnaugh haritasıyla denklemlerinin bu tablodan üretildiğini, burada da benzer bir mantık olduğunu söyledi.

Tabloda $f$ bir sonraki duruma geçiş fonksiyonunu, $g$ çıkış fonksiyonunu belirtir. Örnekteki satırlar:

- $\sigma_0$ durumunda $a$ gelirse yine $\sigma_0$'a gidilir: $f(\sigma_0,a)=\sigma_0$, çıkış $g(\sigma_0,a)=0$.
- $\sigma_0$ durumunda $b$ gelirse $\sigma_1$'e gidilir: $f(\sigma_0,b)=\sigma_1$, çıkış $g(\sigma_0,b)=1$.
- Aynı şey $\sigma_1$ için de tabloda yazılıdır.

<!-- BELİRSİZ: σ1 satırının değerleri altyazıda okunmadı; 00:20:00 karesinde slaytın çoğu başka bir pencereyle örtülü, yalnız b/1 ve b/0 etiketli kenarlar seçiliyor. -->

### 6.2 Deterministik makine

Hoca öğrencilere bu makineye deterministik denip denemeyeceğini sordu. Cevap: Makinede bütün durumlar bellidir. Girdi olarak bir hamle yapıldığında, bu hamleye karşılık hangi duruma geçileceği ve çıkışta ne görüleceği bellidir; belirsiz hiçbir şey yoktur. Böyle makinelere deterministik otomat denir. Ekrandaki el yazısı notta da "Deterministic Machine" yazmaktadır (ekrandan, 00:20:00). Sonraki dönem deterministik olmayan sonlu otomat (non-deterministic finite automata) ve deterministik sonlu otomat (deterministic finite automata) ayrı ayrı incelenecektir.

## 7. Bir Girdi İçin Çıkış Dizisini Bulma

Hoca slayttaki bir soruyu çözdü: Verilen sonlu durum makinesine girdi değeri $101011$ verilirse makine çıkış olarak ne üretir?

<!-- BELİRSİZ: Bu makinenin diyagramının karesi yok. Girdi ve geçişler altyazıdan alındı; altyazıdaki "1.0, 1.0, 1.1" ifadesi 101011 olarak okundu ve anlatılan altı geçişle tutarlı. -->

$s_0$ durumunda başlanır. Altyazıdaki anlatıma göre izleme şöyledir:

| Adım | Bulunulan durum | Girdi | Sonraki durum | Çıkış |
| :---: | :---: | :---: | :---: | :---: |
| 1 | $s_0$ | 1 | $s_3$ | 0 |
| 2 | $s_3$ | 0 | $s_1$ | 0 |
| 3 | $s_1$ | 1 | $s_2$ | 1 |
| 4 | $s_2$ | 0 | $s_3$ | 0 |
| 5 | $s_3$ | 1 | $s_0$ | 0 |
| 6 | $s_0$ | 1 | $s_3$ | 0 |

Çıkış dizisi $001000$ olur. Hoca durum geçişlerinin de istenebileceğini söyledi; o zaman $s_0\to s_3\to s_1\to s_2\to s_3\to s_0\to s_3$ yazılır. Çıkış dizisi Python ile tablodaki geçişlerden yeniden üretildi.

## 8. Sağa Bir Kez Öteleme Yapan Makine

### 8.1 Soru ve diyagram

Slayttaki soru (ekrandan, 00:25:00): "State diyagramı aşağıda verilmiş olan işlem neyi gerçekleştirmektedir?"

Diyagramda üç durum vardır; $S_0$ başlangıç durumudur. Kenar etiketleri "girdi, çıkış" biçimindedir:

- $S_0\xrightarrow{1,0}S_1$ ve $S_0\xrightarrow{0,0}S_2$,
- $S_1\xrightarrow{1,1}S_1$ (kendi üzerine dönen kenar) ve $S_1\xrightarrow{0,1}S_2$,
- $S_2\xrightarrow{1,0}S_1$ ve $S_2\xrightarrow{0,0}S_2$ (kendi üzerine dönen kenar).

### 8.2 Tablo ile analiz

Hoca, bunun biraz tahmin gerektiren bir soru olduğunu ve bunun için tablo yapmanın gerekebileceğini söyledi. Her durum için $f$ ve $g$ tarafı ayrı ayrı, 1 ve 0 girdileri için yazılır. Ekrandaki el yazısı tablo (ekrandan, 00:25:00):

| Durum | $f$, girdi 1 | $f$, girdi 0 | $g$, girdi 1 | $g$, girdi 0 |
| :---: | :---: | :---: | :---: | :---: |
| $S_0$ | $S_1$ | $S_2$ | 0 | 0 |
| $S_1$ | $S_1$ | $S_2$ | 1 | 1 |
| $S_2$ | $S_1$ | $S_2$ | 0 | 0 |

### 8.3 Makine ne yapıyor?

Tablodan şu görülür: Hangi durumda olunursa olunsun 1 gelince $S_1$'e, 0 gelince $S_2$'ye gidilir. Çıkış ise yalnız bulunulan duruma bağlıdır: $S_1$'de 1, $S_0$ ve $S_2$'de 0. Yani $S_1$ "son gelen bit 1", $S_2$ "son gelen bit 0" anlamına gelir ve her adımın çıkışı bir önceki girdidir. Başlangıçta önceki bit olmadığından ilk çıkış 0'dır.

Sonuç olarak makine diziyi **sağa bir kez öteler** (shift), başa 0 koyar; slaytta da cevap "Sağa bir kez shift (öteleme)" diye yazılıdır. Hoca bunu $01$ girdisiyle gösterdi: $S_0$'da 0 gelir, çıkış 0, $S_2$'ye geçilir; sonra 1 gelir, çıkış 0, $S_1$'e geçilir. Çıkış $00$ olur. Başta 1 varsa önüne bir 0 gelir ve dizi yine bir bit kaymış olur. Python ile kontrol edildi: $01\to 00$, $10\to 01$, $1101\to 0110$.

## 9. Seri Toplama Makinesi

Hoca, çıkış üreten sonlu durum makinelerine verilen en genel örneğin iki tabanında toplama yapan makine olduğunu söyledi. Slayttaki tanıma göre:

- Toplama için kabul edilen girdi çiftleri $00$, $01$, $10$, $11$'dir; girdi artık iki bitliktir.
- Çıkış 0 ya da 1'dir.
- $x$ ve $y$ girdi değerlerine göre iki durumdan biri oluşur: $x$ ile $y$'nin toplanması ya da eldeli olarak $x$, $y$ ve 1'in toplanması.
- Bu yüzden iki durum vardır: $s_0$ eldesiz, $s_1$ eldeli durum.
- Başlangıç durumu $s_0$ ise seri toplama yapan sonlu durum makinesinin nasıl olacağı sorulur.

Hoca $00$ geldiğinde ve $11$ geldiğinde neler olacağını anlatmaya başladı, ama örneği tamamlamadan başka bir örneğe geçti.

<!-- BELİRSİZ: Seri toplayıcının diyagramı derste tamamlanmadı ve bu ana ait kare yok. -->

> **Ek bilgi (derste anlatılmadı):** Seri toplayıcıda bitler en düşük basamaktan başlanarak çiftler hâlinde verilir. $s_0$'da toplam bit $x\oplus y$ çıkar ve $x=y=1$ ise $s_1$'e geçilir; $s_1$'de çıkış $x\oplus y\oplus 1$ olur ve $x=y=0$ ise $s_0$'a dönülür. Elde, durum olarak bir sonraki basamağa taşınır.

## 10. Giriş (Login) Makinesi

### 10.1 Problem

Hoca kendi örneğini tahtada çözdü: Bir bilgisayar sistemine giriş (login, logon) yapabilmek için şart şöyledir:

- İlk durumda kullanıcı ID'si kontrol edilir. Girilen ID geçersizse yeniden ID girişi yapılır; geçerliyse şifre istenir.
- İkinci durumda girilen şifre kontrol edilir. Şifre geçersizse ID girişi tekrarlanır; geçerliyse komut işleme ortamına geçilir.
- Son durumda her komut yürütüldükten sonra yeniden komut istemine (prompt) dönülür. Hoca bunu C kodlarını çalıştırdığımız komut satırı ekranına benzetti.

### 10.2 Semboller

Tahtadaki semboller şöyledir (ekrandan, 00:30:00):

| Girdi | Anlamı | Çıkış | Anlamı |
| :---: | :--- | :---: | :--- |
| $v$ | geçerli ID | $a$ | Enter User ID |
| $i$ | geçersiz ID | $b$ | Enter Password |
| $p$ | geçerli parola | $c$ | prompt |
| $q$ | geçersiz parola | | |
| $x$ | herhangi bir girdi (any input) | | |

Hoca geçersiz parolayı önce başka bir harfle gösterdi, karışmasın diye $q$ dedi.

### 10.3 Durumlar ve geçişler

- $s_0$: başlangıç durumu, kullanıcı ID'si beklenir. Geçersiz ID ($i$) girilirse yeniden ID istenir: $s_0\xrightarrow{i,\,a}s_0$. Geçerli ID ($v$) girilirse parola istenir ve yeni bir duruma geçilir: $s_0\xrightarrow{v,\,b}s_1$.
- $s_1$: parola beklenir. Geçersiz parola ($q$) girilirse ID'nin yeniden girilmesi istenir: $s_1\xrightarrow{q,\,a}s_0$. Geçerli parola ($p$) girilirse komut istemi açılır: $s_1\xrightarrow{p,\,c}s_2$.
- $s_2$: sisteme giriş yapılmıştır. Her türlü işlemden sonra yeniden prompt'a dönülür: $s_2\xrightarrow{x,\,c}s_2$.

Hoca $s_2$ durumunun tam deterministik görünmeyebileceğini, ama bu durumda başka bir olasılık olmadığını söyledi. Bu diyagramların bize işin algoritmasını çözümleme ve analiz etme imkânı verdiğini, lojikte de bu yüzden kullanıldığını vurguladı.

## 11. Dört Karakterli Değişken Adı Denetleyicisi

### 11.1 Kurallar

Sonraki örnekte değişken adı verme kuralları şöyledir (ekrandan, 00:40:00):

- Değişken adı 4 karakterlidir.
- İlk karakter hariç diğer karakterler rakam olabilir.
- $(0$-$9)$, $(A$-$Z)$, $(a$-$z)$ dışındaki karakterler geçersizdir.
- $\Sigma$ geçersiz karakterleri göstersin.

Hoca önce $\Sigma$'yı karakter sayısını saklayan bir değişken olarak düşündü (bu sırada ekranda "Σ karakter sayısını saklayan değişken" yazıyordu, ekrandan, 00:35:00). Sonra slayttaki soruda bunun yanlış yazıldığını, $\Sigma$'nın geçersiz karakterler için olduğunu söyleyerek tanımı düzeltti (ekrandan, 00:40:00).

### 11.2 Diyagram

Tahtadaki diyagram (ekrandan, 00:40:00 ve 00:45:00):

- $S_0$ (başlangıç): $\Sigma$ ya da $0$-$9$ gelirse $S_0$'da kalınır (ilk karakter rakam olamaz, yeniden giriş beklenir). $A$-$Z$ ya da $a$-$z$ gelirse $S_1$'e geçilir.
- $S_1$: $\Sigma$ gelirse $S_1$'de kalınır. $A$-$Z$, $a$-$z$ ya da $0$-$9$ gelirse $S_2$'ye geçilir.
- $S_2$: $\Sigma$ gelirse $S_2$'de kalınır. $A$-$Z$, $a$-$z$ ya da $0$-$9$ gelirse $S_3$'e geçilir.
- $S_3$: $\Sigma$ gelirse $S_3$'te kalınır. $A$-$Z$, $a$-$z$ ya da $0$-$9$ gelirse $S_4$'e geçilir.
- $S_4$: kabul durumu (çift daire).

**Neden harf geçişi tek durum üzerinde kendine döndürülmüyor?** Hoca bu soruyu kendisi sordu ve şöyle açıkladı: Harf ve rakam geçişleri tek bir durum üzerinde kendine döndürülseydi sonsuz sayıda karakter girilebilirdi ve dört karakter şartı sağlanamazdı. Dört karakter ancak $S_1$, $S_2$, $S_3$, $S_4$ zinciriyle sayılır.

### 11.3 Denemeler

Ekrandaki denemeler (ekrandan, 00:45:00):

- `0Abc`: $0$ gelince $S_0$'da kalınır. $A$ ile $S_1$'e, $b$ ile $S_2$'ye, $c$ ile $S_3$'e gelinir. İfadenin sonunda kabul durumuna gelinmedi; geçersizdir.
- `Ab#c`: $A$ ile $S_1$'e, $b$ ile $S_2$'ye geçilir. `#` geçerli karakterlerden biri değildir, $S_2$'de kalınır. $c$ ile $S_3$'e geçilir. Kabul durumuna gelinmedi; geçersizdir.
- `A1ad`: $A$ ile $S_1$'e, $1$ ile $S_2$'ye, $a$ ile $S_3$'e, $d$ ile $S_4$'e geçilir. Sonunda kabul durumundayız; geçerlidir.

Üç sonuç Python ile kontrol edildi.

### 11.4 Sayaç gerekli mi, baştan başlamak gerekli mi?

Hoca karakter sayısını tutmanın mantıksal olarak "kaçıncı karakterdeyiz" diyen bir değişken gibi düşünülebileceğini, ama aslında buna gerek olmadığını söyledi: Diyagram her şeyi deterministik olarak zaten belirtir. Önemli olan işin sonunda kabul durumuna gelmektir.

**Soru:** Yanlış girişte makine baştan başlatılmalı mı?
**Cevap:** Soru "yanlış karakterde girişe sıfırdan başlansın" deseydi bütün $\Sigma$ geçişleri $S_0$'a gönderilirdi; bu da yanlış değildir. Ama girilen ifadenin doğru olup olmadığını anlamak için başa döndürmek gerekmez, çünkü sonunda $S_4$'e gelinip gelinmediğine bakılır. Başa döndürme daha çok, parolanın yeniden girilmesini istemek için kullanılan bir yöntemdir.

## 12. Art Arda Üç 1 Gelince Hata Veren Makine

### 12.1 Problem

Slayttaki soru (ekrandan, 00:40:00): "Öyle bir FSM/SDM tasarlayınız ki, gönderilen mesaj içerisinde arka arkaya tekrar eden 3 tane 1 varsa 'hata mesajı' olarak dışarıya 1 değerini versin."

### 12.2 Tasarım

Art arda üç 1 olması, üç farklı durumun analiz edileceği anlamına gelir. Mesajın öncesinde ne olduğu önemli değildir.

<!-- BELİRSİZ: Bu diyagramın çizildiği ana ait kare yok; tasarım altyazıdaki anlatımdan kuruldu. -->

- $s_0$'da bir 1 gelirse arkasından iki 1 daha gelebilir, bu kontrol edilmelidir. Yeni bir duruma geçilir ama çıkış hâlâ 0'dır, çünkü şu ana kadar yalnız bir tane 1 gelmiştir: $s_0\xrightarrow{1/0}s_1$.
- Bir 1 daha gelirse yine yeni bir duruma geçilir, çıkış hâlâ 0'dır: $s_1\xrightarrow{1/0}s_2$.
- Üçüncü 1 gelince çıkış 1 yapılır ve makine kendi üzerine döner: $s_2\xrightarrow{1/1}s_2$.
- Her 0 geldiğinde, üç durumun yeniden kontrol edilmesi için makine $s_0$'a döndürülür ve çıkış 0'dır. İki tane 1 gelip ardından 0 gelirse sorun yoktur; her şey baştan kontrol edilir.

| Durum | 0 gelirse | 1 gelirse |
| :---: | :---: | :---: |
| $s_0$ | $s_0$ / 0 | $s_1$ / 0 |
| $s_1$ | $s_0$ / 0 | $s_2$ / 0 |
| $s_2$ | $s_0$ / 0 | $s_2$ / 1 |

Hoca üç tane 1'den sonra 1'ler gelmeye devam ederse çıkışta her seferinde 1 görüleceğini söyledi. Lojik dersinde örtüşen (overlap) dizilere de bakıldığını, orada önceki üç bitin kontrol edildiğini hatırlattı.

<!-- BELİRSİZ: Hoca örtüşme açıklamasında "bir defa 1 olduktan sonra kendisini sıfırlar, yeni bir üçlü duruma geçmek ister" de dedi; bu, örtüşmesiz bir tasarımı anlatıyor olabilir. Yukarıdaki tablo hocanın çizdiği kendine dönen kenarla uyumlu olan örtüşmeli sürümdür. -->

Bu tür makinelerin lojikte flip-floplarla devresi kurulur ve analizi biraz farklıdır; flip-floplar bir bitlik kaydediciler olduğundan farklı durum bilgisi taşırlar. Burada işin genel mantığına bakılmaktadır.

## 13. Dersin Diğer Derslerle Bağlantısı

Hoca dersin kapanışında bu dersin daha çok veri yapıları, algoritma analizi ve hesaplama kuramı gibi derslerin temelini oluşturduğunu söyledi. Dönem boyunca görülen graflar, ağaçlar, yığın (stack), kuyruk (queue), bağlı listeler ve özyineleme (recursion) konularının meslek hayatında her yerde karşıya çıkacağını belirtti. Dersin amacının kod yazmak değil, işin mantığını ve arkadaki mekanizmayı anlamak olduğunu, ama bu algoritmaları öğrencilerin kendilerinin kodlamasını önerdiğini söyledi: Şimdiden oluşturulan kod şablonları ileride her türlü probleme uyarlanabilecek bir kütüphane olur. Bu kodlar C'de ya da Java'da yazılabilir; aynı yapılar ileride hem yapısal hem nesneye dayalı programlamada görülecektir. Özyinelemeli algoritmalara örnek olarak merge sort ve quick sort'u verdi; merge sort'un arkasında güzel bir mantık olan iyi bir özyineleme uygulaması olduğunu söyledi.

## Örnek Sorular

### Soru 1 (ekrandan, 00:25:00)

State diyagramı aşağıda verilmiş olan işlem neyi gerçekleştirmektedir? Durumlar $S_0$ (başlangıç), $S_1$, $S_2$; geçişler (girdi, çıkış): $S_0\xrightarrow{1,0}S_1$, $S_0\xrightarrow{0,0}S_2$, $S_1\xrightarrow{1,1}S_1$, $S_1\xrightarrow{0,1}S_2$, $S_2\xrightarrow{1,0}S_1$, $S_2\xrightarrow{0,0}S_2$.

**Çözüm:** Her adımın çıkışı bir önceki girdidir, ilk çıkış 0'dır. Makine girdiyi sağa bir kez öteler (shift); örneğin $01\to 00$ (Bölüm 8).

### Soru 2 (derste sözlü, 00:20:48)

Verilen beş durumlu sonlu durum makinesine $101011$ girdisi verilirse çıkış ne olur?

**Çözüm:** İzleme $s_0\xrightarrow{1/0}s_3\xrightarrow{0/0}s_1\xrightarrow{1/1}s_2\xrightarrow{0/0}s_3\xrightarrow{1/0}s_0\xrightarrow{1/0}s_3$; çıkış $001000$ (Bölüm 7).

<!-- BELİRSİZ: Makinenin diyagramı karede yok; geçişler altyazıdan alındı. -->

### Soru 3 (derste sözlü, 00:19:27)

Durum tablosu verilen makineye deterministik denebilir mi? Deterministik ne demektir?

**Çözüm:** Evet. Her durumda her girdi için gidilecek durum ve üretilecek çıkış bellidir; belirsiz bir geçiş yoktur (Bölüm 6.2).

### Soru 4 (ekrandan, 00:30:00)

Bir sisteme girişte önce kullanıcı ID'si, sonra parola kontrol edilir; geçersiz ID'de ID yeniden istenir, geçersiz parolada ID girişi tekrarlanır, geçerli parolada komut istemine geçilir ve her komuttan sonra prompt'a dönülür. Bu süreci sonlu durum makinesiyle modelleyin.

**Çözüm:** $s_0\xrightarrow{i,a}s_0$, $s_0\xrightarrow{v,b}s_1$, $s_1\xrightarrow{q,a}s_0$, $s_1\xrightarrow{p,c}s_2$, $s_2\xrightarrow{x,c}s_2$ (Bölüm 10).

### Soru 5 (ekrandan, 00:40:00)

Değişken adı 4 karakterli olsun, ilk karakter dışındakiler rakam olabilsin, $(0$-$9)$, $(A$-$Z)$, $(a$-$z)$ dışındaki karakterler geçersiz olsun ve $\Sigma$ geçersiz karakterleri göstersin. Bu kuralı denetleyen makineyi çizin; `0Abc`, `Ab#c`, `A1ad` girdilerini deneyin.

**Çözüm:** $S_0\to S_1\to S_2\to S_3\to S_4$ zinciri, $\Sigma$ geçişleri kendi üzerine döner, $S_0$'da rakam da beklenir, $S_4$ kabul durumu. `0Abc` ve `Ab#c` $S_3$'te kalır (kabul değil), `A1ad` $S_4$'e ulaşır (kabul) (Bölüm 11).

### Soru 6 (ekrandan, 00:40:00)

Öyle bir FSM/SDM tasarlayınız ki, gönderilen mesaj içerisinde arka arkaya tekrar eden 3 tane 1 varsa "hata mesajı" olarak dışarıya 1 değerini versin.

**Çözüm:** Bölüm 12.2'deki üç durumlu makine.

### Soru 7 (derste sözlü, 00:42:27)

Bölüm 12'deki makineye $01001110000$ girdisi veriliyor. Çıkışta sırayla neler görülür? Durum geçişlerini yazın.

> **Çözüm (derste verilmedi):** Bölüm 12.2'deki tabloya göre, $s_0$'dan başlanırsa durumlar $s_0, s_0, s_1, s_0, s_0, s_1, s_2, s_2, s_0, s_0, s_0, s_0$ sırasıyla izlenir. Çıkış dizisi $00000010000$ olur; yalnız art arda üçüncü 1'in geldiği 7. bitte çıkış 1'dir. Sonuç Python ile kontrol edildi.

## Dersin Toparlaması

Bu derste sonlu durum makineleri hesaplama kuramına bir giriş olarak ele alındı. Turnike gibi günlük hayattan örneklerle durum, geçiş ve çıkış kavramları kuruldu. Ardından Mealy ve Moore makineleri tanıtıldı ve makine $M=(I,O,S,f,g,\sigma)$ 6'lısıyla biçimsel olarak tanımlandı. Kabul durumu ve düzenli ifadelerle bağlantısı gösterildi, tablo gösterimi ve deterministik makine kavramı açıklandı.

Örneklerde bir girdi dizisi için çıkışın izlenmesi, sağa öteleme yapan makinenin tablo ile çözümlenmesi, seri toplayıcının durumları, giriş (login) süreci, dört karakterli değişken adı denetleyicisi ve art arda üç 1'i yakalayan makine çalışıldı. Bu konular sonraki dönemde hesaplama kuramı dersinde deterministik ve deterministik olmayan sonlu otomatlarla ayrıntılı olarak sürdürülecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
