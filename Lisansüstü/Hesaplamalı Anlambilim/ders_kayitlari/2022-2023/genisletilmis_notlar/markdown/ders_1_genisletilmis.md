# Ders 1 Genişletilmiş Notu: Anlambilim ve Hesaplamalı Anlambilime Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı
- 2. Anlambilim Nedir?
- 3. Kelimeler ve Cümleler Arasındaki İlişkiler
- 4. Çıkarım
- 5. Hesaplamalı Anlambilim ve İki Temel Okul
- 6. Formal Anlambilim: Dili Mantıkla Yazmak
- 7. Kural Tabanlı Yaklaşımlar: Cümle ve Kelime Çözümleme
- 8. Prolog ile Bir Çıkarım Örneği
- 9. İstatistiksel Anlambilim
- 10. Dersin Amacı ve Kazanımları
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kapsamı

Bu, dönemin ilk dersidir. Hoca önce dersin hangi konuları kapsayacağını özetledi. Ders iki ana gövdeden oluşur: önce **araçlar ve yöntemler**, ardından bu araçların kullanıldığı **uygulamalar** (ekrandan, 00:56:55).

Araçlar ve yöntemler kısmında şu konular ele alınacak:

- **Hayat bilgisi veritabanları:** metinde yazmayan ama metni anlamak için gereken genel dünya bilgisi.
- **Dil modelleri** ve **anlamsal uzaylar:** kelime, deyiş, cümle ve metin düzeyinde anlam temsili.
- **Makine öğrenmesinde yeni yaklaşımlar:** aktif öğrenme, yarı eğiticili öğrenme, transfer öğrenme, aktif örnekleme, zayıf yönlendirme (weak supervision), planlı öğrenme, hayat boyu öğrenme, çekişmeli eğitim, çok görevli eğitim, az sayıda örnekle eğitim (zero/one/few-shot learning) ve veri zenginleştirme. Hoca bunları "genellikle son dönemde ortaya çıkan yaklaşımlar" diye tanıttı.
- **Bağlam temelli dil modelleri:** hocaya göre günümüzdeki birçok başarılı doğal dil işleme uygulamasının temelinde bu modeller yatıyor.

Uygulamalar kısmında metin sınıflandırma, duygudurum analizi, varlık ismi tanıma, paragraf anlama, soru cevaplama, metinlerde çıkarım, sohbet ve sanal asistan uygulamaları, metin/hikâye/şiir üretimi ele alınacak. Her uygulama için o konuda yapılmış iyi çalışmalar birlikte incelenecek. En sonda **görsel anlambilim** gelir: yalnız metinle değil, metin ve görüntüyle birlikte neler yapıldığı ve yapılabileceği konuşulacak.

Hoca ayrıca, önümüzdeki birkaç yıl da sürecek gibi görünen hızlı gelişim sürecine değinerek ChatGPT gibi sistemlerin ne yaptığından ve nasıl yaptığından da bahsetmeye çalışacağını söyledi. Bu sistemlerde kullanılan tekniklerin bazılarının temelleri ders notlarında zaten bulunuyor; yeni parçalar zamanla eklenecek.

## 2. Anlambilim Nedir?

"Anlambilim" ve "semantik" Türkçede eş anlamlı iki kelimedir. Hesaplamalı anlambilime geçmeden önce anlambilimin kendisi tanımlandı (ekrandan, 00:30:45):

> Anlambilim, kelimelerin, kelime öbeklerinin, cümlelerin anlamını, aralarındaki ilişkileri ve bu ilişkilerin türlerini konu edinen, dilbiliminin bir alt dalıdır.

Hoca bu tanımı "farklı büyüklüklerdeki metin parçaları" diye genelleştirdi: bir kelime, bir öbek, bir cümle ya da daha uzun bir parça. Anlambilim bunların anlamıyla ve anlamı tam bilinmese bile aralarındaki ilişkilerle ve bu ilişkilerin türleriyle uğraşır. Görsel anlambilim gibi başka alanlar da vardır; ancak bu derste genelde metinlerle çalışılacağı için tanımın metin tarafı alındı.

## 3. Kelimeler ve Cümleler Arasındaki İlişkiler

### 3.1 Kelimeler arası ilişki

Slaytta şu kelime çiftleri verildi (ekrandan, 00:31:30): büyük-küçük, büyük-iri, pembe-kırmızı, hayvan-canlı, sınıf-tahta, güldü-gülmedi, güldü-ağladı.

Bu çiftlerin hepsinde iki kelime birbiriyle ilişkilidir; en azından bu kadarı söylenebilir. Ama ilişkilerin türü aynı değildir. Hoca çiftleri tek tek yorumladı:

- **Büyük-küçük:** zıtlık gibi bir ilişki.
- **Büyük-iri:** benzer anlamlar; belli bağlamlarda eş anlamlı da olabilirler.
- **Pembe-kırmızı:** eş anlamlı değiller ama anlamca yakınlar.
- **Hayvan-canlı:** alt sınıf-üst sınıf ilişkisi.
- **Sınıf-tahta:** "bir şey nerede bulunur" türünden bir ilişki.
- **Güldü-gülmedi, güldü-ağladı:** bunlar da birbirleriyle tam aynı türde ilişkide değil. Hoca, gülmeyen birinin illa ağlamış olmayacağını belirtti.

Bu örneklerle anlatılmak istenen iki şeydir: kelimeler arasında ilişki vardır ve bu ilişkiler farklı türlerdendir. İlişki türlerinin neler olduğu ilerideki derslerde ele alınacak.

### 3.2 Cümleler arası ilişki

İlişki yalnız kelimeler arasında değil, cümleler arasında da kurulabilir (ekrandan, 00:32:50):

- "Ali okula gitti. – Ali öğrencidir." Burada "öyleyse" türünden bir bağ kurulabilir: Ali okula gitti, öyleyse Ali öğrencidir. Ama "öyleyse Ali öğretmendir" de olabilir.
- "Sınava çok çalıştım. – Dersi geçtim." Bu sayede dersi geçtim, şeklinde bağlanabilir.
- "Bugün ıslanmadım. – Şemsiyem yanımdaydı." Bugün ıslanmadım, çünkü şemsiyem yanımdaydı.
- "Bugün okula gitmeyeceğim. – Hastayım." Bugün okula gitmeyeceğim, çünkü hastayım.

Daha uzun parçalar arasında da bunun gibi pek çok ilişki kurulabilir.

## 4. Çıkarım

Hoca, bu ilişkileri kullanarak yaptığımız en temel işin **çıkarım** olduğunu söyledi. İletişim kurarken ya da kendi kendimize düşünürken aklımızdan birbirine bağlı pek çok şey geçer; bu süreçte ilişkiler önemlidir. Hoca ilişkileri kabaca çıkarımın "ham maddesi" diye niteledi.

Çıkarım, **elimizde olan verilerle elimizde olmayan bir bilgiyi çıkarmak** demektir. Çıkarım yaparken genelde elimizdeki verileri doğru kabul ederek hareket ederiz.

### 4.1 Sarman örneği

Slayttaki ilk örnek (ekrandan, 00:34:45): "Ali'nin kedisi yok. Sarman bir kedi." Bu iki bilgiyi doğru kabul edelim. Bu durumda "Sarman'ın sahibi Ali'dir" demek doğru olur mu? Olmaz; bu sonuç öncüllerle çelişir. Demek ki yaptığımız bir çıkarım doğru da olabilir, yanlış da.

### 4.2 Zorunlu çıkarım ve günlük çıkarımlar

Bir çıkarım belli bir olasılıkla doğru olabilir. Hocaya göre bizim kullandığımız çıkarım türlerinin büyük kısmı **zorunlu çıkarım** değildir. Zorunlu çıkarım, öncülleri doğruysa sonucu da kesinlikle doğru olan çıkarımdır. Klasik örnek tümdengelimdir: "Bütün insanlar ölümlüdür. Sokrat bir insandır. Dolayısıyla Sokrat ölümlüdür."

Tümdengelimin güzel tarafı, yapılan çıkarımın yüzde yüz doğru olmasıdır. Tabii ki kullanılır, ama günlük hayatta çok fazla işe yaramaz. Asıl çok kullandığımız çıkarım türleri daha az kesindir, ama daha çok işe yarar.

> **Ek bilgi (derste anlatılmadı):** Mantıkta zorunlu olmayan çıkarımlar genelde tümevarım (gözlemlerden genelleme) ve abdüksiyon (gözleme en iyi açıklamayı seçme) diye adlandırılır. "Ali bugün okula gitmedi, Ali hastadır" türü çıkarımlar en iyi açıklamayı arayan abdüktif çıkarıma örnektir.

### 4.3 "Ali bugün okula gitmedi" örneği

Elinizde yalnız "Ali bugün okula gitmedi" bilgisi var. Bundan neler üretilebilir? (ekrandan, 00:35:30) Üretilenlerin hiçbiri yüzde yüz doğru olmayacak, belki bazıları doğru olacak:

- **Ali öğrencidir:** bir ihtimal olabilir. Cümlede Ali her gün okula gidiyormuş gibi bir hava var; her gün okula giden biri öğrenci de olabilir, öğretmen de.
- **Ali hastadır:** mümkün.
- **Ali yaz tatilindedir:** o da olabilir.
- **Ali mutludur:** biraz soru işareti. Yaz tatilindeyse ya da kar yağdığı için kar tatilindeyse belki mutludur; kesin değil.

### 4.4 "Ali Hoca" örneği

İkinci bilgi (ekrandan, 00:37:10): "Ali Hoca bugün öğrencilerinin dersteki performansından çok memnun oldu." Bundan şunlar çıkarılabilir:

- **Ali Hoca öğretmendir:** "öğrencileri" dendiğine göre öğrencileri olan biri öğretmen diye düşünülebilir.
- **Ali Hoca bugün mutludur:** öğrencilerin performansı iyiyse hoca da mutludur.
- **Ali Hoca'nın öğrencileri çalışkandır:** bu da olabilir.

Bunların hepsi yapılabilecek çıkarım türleridir. Derste farklı büyüklükteki birimler arasındaki ilişkiler ve çıkarımlar ele alınacak; amaç bunları makinelere yaptırmaktır.

## 5. Hesaplamalı Anlambilim ve İki Temel Okul

Hesaplamalı anlambilim (computational semantics), kabaca **anlambilimin tüm ilgi alanlarını çeşitli yöntemlerle otomatikleştirme uğraşıdır** (ekrandan, 00:37:45). Daha kısa söylersek: anlambilimi makinelere yaptırmaya çalışmak.

Bu işi makinelere nasıl yaptıracağımız konusunda iki temel okul (ekol) vardır:

- **Formal anlambilim**
- **İstatistiksel anlambilim**

## 6. Formal Anlambilim: Dili Mantıkla Yazmak

### 6.1 Temel fikir

Formal anlambilim, insanların birbiriyle iletişim kurduğu dili mantık cümleleriyle yazmaya çalışır. Sorular şunlardır: İnsanların kurduğu cümleler mantıksal sembollere dönüştürülebilir mi? Ne ölçüde dönüştürülebilir?

Bunun güçlü yanı şudur: Eğer bu yapılabilirse, az önce bahsedilen çıkarımlar çok rahatlıkla yapılabilecektir. Üstelik bu çıkarımlar **geriye doğru izi sürülebilir** ve **açıklanabilir** biçimde yapılabilecektir. Çünkü mantık yaptığı her işi nasıl yaptığını gösterir; biz de bunu adım adım takip edebiliriz. Hoca bunu son zamanlarda çok duyulan bir kavrama, makinenin vardığı sonuçları bize açıklamasına bağladı: İnsan dili formal bir dille yeterince iyi ifade edilebilirse, makinelerin ne yaptığını ve verdikleri kararların sebeplerini çok rahat gözlemleyebiliriz.

### 6.2 Mantık sembolleri

Hoca, mantık dersinden hatırlayanlar olabileceğini söyleyerek sembolleri hatırlattı:

- $\forall$ (ters A): "her". $\forall x$, "her x" diye okunur.
- $\exists$ (ters E): "vardır", yani en az bir tane vardır.
- $\rightarrow$: "ise".
- $\land$: "ve".
- $\neg$: "değil".

Bağıntılar (relation) tanımlanırken bazıları tek parametreli, bazıları iki parametrelidir.

### 6.3 "Yatakhanede herkesin sevmediği bir oda arkadaşı vardır"

Slayttaki ilk cümle ve karşılığı (ekrandan, 00:38:15):

$$\forall x\,[D(x) \rightarrow \exists y\,(R(x,y) \land \neg L(x,y))]$$

- $D(x)$: x yatakhanede yaşar.
- $R(x,y)$: x ve y oda arkadaşıdır.
- $L(x,y)$: x, y'yi sever.

Hocanın okuyuşu: Her x için (yani herkes için), eğer x yatakhanede yaşıyorsa, şu doğrudur: en az bir y vardır; y de bir kişidir; x ile y oda arkadaşıdır ve x, y'yi sevmez. Yani yatakhanede yaşayan herkesin illaki sevmediği bir oda arkadaşı vardır. Böylece Türkçe cümle sembollerle yazılmış olur.

### 6.4 Diğer örnekler

Hoca "Hiç kimse yalancıları sevmez" cümlesinin de böyle yazılabileceğini söyledi. Slayttaki formül (ekrandan, 00:41:30):

$$\forall x\,[S(x) \rightarrow \neg\exists y\,(L(x,y))]$$

> **Ders sonrası not:** Slaytta $S(x)$ tanımlanmamış; anlamı büyük olasılıkla "x yalancıdır"dır. Bu durumda slayttaki formül, $L(x,y)$ "x, y'yi sever" tanımıyla "her yalancı x için, x'in sevdiği hiç kimse yoktur", yani "yalancılar kimseyi sevmez" anlamına gelir. "Hiç kimse yalancıları sevmez" için sevenle sevilenin yeri değişmelidir: $\forall x\,[S(x) \rightarrow \neg\exists y\,L(y,x)]$. Derste bu fark konuşulmadı.

Sonraki slayttaki örnekler (ekrandan, 00:41:55):

- **"Herkes en az 2 kişiyi sever":**

$$\forall x\,\exists y\,\exists z\,(L(x,y) \land L(x,z) \land (y \neq z))$$

  Burada herkes ($\forall x$) ve en az iki kişi ($y$ ve $z$) vardır. $y \neq z$ koşulu bu ikisinin birbirine eşit olmadığını, yani iki farklı kişi olduğunu söyler. Böylece x hem y'yi hem z'yi sever: herkes en az iki kişiyi sever.

- **"Tüm evli çiftler kavga eder":**

$$\forall x\,\forall y\,(M(x,y) \rightarrow F(x,y))$$

  $M(x,y)$: x ve y birbiriyle evlidir; $F(x,y)$: x ve y birbiriyle kavga eder. Her x ve y için, evlilerse kavga ederler.

- **"Ali sadece 1 kişiyi sever":** slaytta yer aldı, ama hoca formülüne girmeden geçti. <!-- BELİRSİZ: Bu cümlenin formülü karede kesik (00:41:55) ve derste anlatılmadı. -->

## 7. Kural Tabanlı Yaklaşımlar: Cümle ve Kelime Çözümleme

Formal anlambilimde ifade edilen kısım kural tabanlı yaklaşımlardır. Mantık ya da doğal dil işleme dersi almış olanlar, gramerleri ve sonlu durum makinelerini hatırlayacaktır. Bunlar dili formal olarak işlemek için kullanılabilecek mekanizmalardır. Dili işlemede ne kadar başarılı oldukları tartışmalıdır, ama kullanılabilen yapılardır.

### 7.1 Formal gramerlerle cümle çözümleme

Slayttaki örnek SWI-Prolog'un çevrimiçi ortamındaki basit bir İngilizce gramerdir (ekrandan, 00:42:45; kaynak: swish.swi-prolog.org/example/grammar.pl). Türkçe açısından düşünürsek yapılan iş, cümleyi **öğelerine ayırmaya** benzer: öznesi şudur, nesnesi şudur, dolaylı tümleci şudur gibi. Çözümleme sonunda bir **gramer ağacı** oluşur.

**Gramer**, bir dilin cümlelerinin nasıl oluşturulduğunun kurallarıdır. Bir cümle şu parçalardan oluşur, o parçaların her biri şu parçalardan oluşur, diye giden kural tabanlı bir yapıdır. Grameri kullanarak, gramere uygun cümleler çözümlenebilir. Ekrandaki gramerin kuralları (ekrandan, 00:42:45):

```prolog
s(s(NP,VP)) --> np(NP, Num), vp(VP, Num).

np(NP, Num) --> pn(NP, Num).
np(np(Det,N), Num) --> det(Det, Num), n(N, Num).
np(np(Det,N,PP), Num) --> det(Det, Num), n(N, Num), pp(PP).

vp(vp(V,NP), Num) --> v(V, Num), np(NP, _).
vp(vp(V,NP,PP), Num) --> v(V, Num), np(NP, _), pp(PP).

pp(pp(P,NP)) --> p(P), np(NP, _).

det(det(a), sg) --> [a].
det(det(the), _) --> [the].
pn(pn(john), sg) --> [john].
n(n(man), sg) --> [man].
n(n(men), pl) --> [men].
n(n(telescope), sg) --> [telescope].
v(v(sees), sg) --> [sees].
v(v(see), pl) --> [see].
v(v(saw), _) --> [saw].
p(p(with)) --> [with].
```

Sorgu: `phrase(s(Tree), [john, saw, a, man, with, a, telescope]).`

### 7.2 Belirsizlik problemi

Hoca bu örnekle dilin ilk problemini gösterdi. "John saw a man with a telescope" cümlesi tek başına anlamı tekilleştirilebilir bir cümle değildir:

- John adamı teleskop yardımıyla mı gördü, yani teleskopla bakıp adamı mı gördü?
- Yoksa adamın elinde bir teleskop vardı ve John o adamı mı gördü?

İkisi de mümkündür; Türkçede de bunun birçok örneği bulunabilir. Ekrandaki sistem aynı cümle için bu iki anlama karşılık gelen iki ayrı ağaç üretti (ekrandan, 00:42:45):

```text
Ağaç 1 (adamın teleskobu var):
s
├── pn: john
└── vp
    ├── v: saw
    └── np
        ├── det: a
        ├── n: man
        └── pp
            ├── p: with
            └── np: det a, n telescope

Ağaç 2 (John teleskopla gördü):
s
├── pn: john
└── vp
    ├── v: saw
    ├── np: det a, n man
    └── pp
        ├── p: with
        └── np: det a, n telescope
```

Buradan çıkan sonuç: dil birimleri anlam bakımından tek başına ele alındığında her zaman tam anlaşılamayabilir; bir belirsizlik alanı bırakırlar. Bu bariz belirsizlik alanı, kural tabanlı yapıların işini oldukça güçleştirir.

Cümleleri öğelerine, birbirleriyle ilişkili birimlere ayırmanın başka türleri de vardır; hoca bağımlılık çözümlemeyi (dependency parsing) örnek verdi.

### 7.3 Sonlu durum makineleriyle morfolojik çözümleme

Cümleler parçalara ayrılabildiği gibi, özellikle morfolojik (şekilsel) açıdan zengin diller için kelimelerin de morfolojik analizi gerekebilir. Slaytta bunun için yazılmış `turkce_morfoloji.pl` kodu gösterildi; kod dersin sayfasında yer alıyor (ekrandan, 00:45:50):

```prolog
?- morp([kalem,ler,im,den],A).
A = [isim, çoğul_eki, şahıs_eki, hal_eki]

?- morp([gel,di,m],A).
A = [fiil, zaman_eki, şahıs_eki]
```

Kod "kalemlerimden" kelimesinin parçalarını isim, çoğul eki, şahıs eki ve hâl eki dizisine dönüştürüyor. Kodun içinde Türkçenin kabaca kelime oluşturma kuralları bulunur: bir isimden sonra hangi ekler gelebilir, bir fiilden sonra hangi ekler gelebilir, bir kelime ne tür parçalardan oluşur.

> **Hocanın vurgusu:** Buradaki çıkarım sürecinin kendisi karmaşık değildir. Asıl iş, çıkarımı yaparken kullanılacak kuralların oluşturulmasıdır. Asıl sıkıntı ve çok emek isteyen kısım orasıdır.

## 8. Prolog ile Bir Çıkarım Örneği

### 8.1 Problem

Kural tabanlı yapılarla çıkarım yapılabilir mi? Hoca bunu bir örnekle gösterdi (ekrandan, 00:50:00):

- Ali okula gittiğinde öğlen yemeğini kantinde yer.
- Ali eve gittiğinde öğlen yemeğini mutfakta yer.
- Ali sınıfta kitap okudu.

Soru: **Ali öğlen yemeğini nerede yedi?** Bu soruyu cevaplamak için yukarıdaki parçada yeterli bilgi var mı?

**Soru:** (Hoca sınıfa sordu.) **Cevap:** Bir öğrenci, okula gittiğinde öğlen yemeğini kantinde yediğini söyledi. Hoca bunu açtı: sınıfta kitap okuduysa Ali okula gitmiştir; okula gittiğine göre öğlen yemeğini kantinde yemiştir. Biz bu çıkarımı zaten yapabiliyoruz. Asıl soru, bu çıkarımı bir makineye nasıl yaptıracağımızdır.

### 8.2 Metinde olmayan bilgi

Hoca burada önemli bir noktaya dikkat çekti: Bu metni anlamak için metinde olmayan dünya kadar bilgi kullanıyoruz. Slayttaki "Burada bilinmesi gerekenler" (ekrandan, 00:50:00):

- Birisi bir yerde bulunmuşsa oraya gitmiştir.
- Birisi bir yere gitmişse o yeri içine alan yere de gitmiştir.
- Sınıf okulun içindedir.
- Oda evin içindedir.

Biz bu bilgileri farkında olsak da olmasak da kullandık. Bu çıkarımda "oda evin içindedir" bilgisi kullanılmadı, ama diğer üçü kullanıldı. Ali sınıfta kitap okuduysa okula gitmiştir, çünkü sınıf okulun içindedir; sınıfta kitap okuduysa okulda kitap okumuştur; birisi bir yerde bir şey yaptıysa oraya gitmiştir. Bunlar sürekli yaptığımız şeyler olduğu için farkına bile varmayız.

> **Hocanın vurgusu:** Bu bilgilerin hiçbiri metnin içinde yok. Metni formal olarak yazıp yapıya gömsek ve çıkarım sürecini işletmeye kalksak, alttaki bilgiler olmadan hiçbir sonuç çıkmaz. Bu, bir sonraki dersin konusu olan hayat bilgisi veritabanlarının neden gerektiğini gösterir.

### 8.3 Prolog kodu

Prolog, kural tabanlı çıkarım yapmak için kullanılan dillerden biridir. Kodda cümleler `vardir(yüklem, özne, belirtili_nesne, dolaylı_tümleç, cümle_no)` yapısında tutulur; cümle numarası burada çok önemli değildir. `vardir` bağıntısı gerçek cümleleri (bilgileri), `vardir2` bağıntısı türetilen cümleleri (bilgileri) ifade eder (ekrandan, 00:50:30):

```prolog
kapsar(oda,ev).
kapsar(sinif,okul).
vardir(oku,ali,kitap,sinif,12).

vardir2(git,M,_,Yer,_) :- vardir(_,M,_,Yer,_).
% M Yer'de bulunmuşsa -> M Yer'e gitmiştir

vardir2(F,M,B,Yer1,I) :- kapsar(Yer2,Yer1), vardir2(F,M,B,Yer2,I).
% M Yer2'de birşey yapmışsa ve Yer2 Yer1'i kapsıyorsa
% -> M Yer1'de de aynı şeyi yapmıştır

vardir2(yer,ali,oglenyemegi,mutfak,_) :- vardir2(git,ali,_,ev,_).
% ali eve gitmişse -> öğlen yemeğini mutfakta yer

vardir2(yer,ali,oglenyemegi,kantin,_) :- vardir2(git,ali,_,okul,_).
% ali okula gitmişse -> öğlen yemeğini kantinde yer
```

Burada "Ali sınıfta kitap okudu" cümlesi `vardir(oku,ali,kitap,sinif,12)` biçimine getirilmiştir. Bize verilen yalnız bu cümle ve iki yemek kuralıdır; "kapsar" bilgileri ile ilk iki genel kural ise metinde olmayan, bizim eklediğimiz bilgilerdir.

> **Ders sonrası not:** İkinci kuralın yorumunda "Yer2 Yer1'i kapsıyorsa" yazıyor, ama kodda `kapsar(Yer2,Yer1)` "Yer2, Yer1'in içindedir" anlamında kullanılıyor: `kapsar(sinif,okul)` "sınıf okulun içindedir" demektir. Kod bu anlamla doğru çalışır; yorumu okurken kapsama yönü ters okunmamalıdır.

### 8.4 Sorgu ve sonuç

Sorgu ve sistemin cevabı (ekrandan, 00:51:40):

```prolog
?- vardir2(yer,ali,oglenyemegi,Nerede,_).
Nerede = kantin ;
No
```

Sistemin yaptığı:

- Ali'nin sınıfta bulunduğunu görüp okulda bulunduğu bilgisini edindi.
- Okulda bulunduğuna göre okula gitmiştir çıkarımını yaptı.
- Okula gittiğine göre yemeğini de kantinde yemiştir sonucuna ulaştı.

Eğer `vardir(oku,ali,kitap,sinif,12).` yerine `vardir(oku,ali,kitap,oda,12).` cümlesi verilseydi, yani Ali kitabı odada okusaydı, sistemin cevabı `mutfak` olacaktı.

Sonuç: Kural tabanlı yapılarla bu tarz çıkarımlar yapmak mümkündür, yeter ki sisteme yeterli bilgi verilebilsin.

### 8.5 Formal yaklaşımın özeti

Buraya kadar anlatılan kısım kabaca formal sistemlerdir: Cümleleri ve birimlerini belli formatlara sokalım, aralarındaki ilişkileri açıkça tanımlayalım; "şöyle olursa şöyle olur", "şu şöyle parçalara ayrılır", "çıkarım şöyle yapılır" gibi kuralları biz yazalım.

## 9. İstatistiksel Anlambilim

Formal yaklaşımın karşısında istatistiksel anlambilim durur. Burada kuralları bizim tanımlamamız yaklaşımı yoktur. Makinelere bir şekilde yeterince veri verilir; elle yazdığımız ya da klasik makine öğrenmesi teknikleriyle buldurduğumuz kuralları makine kendisi öğrenir. Bunun için bazı ilkeler kabul edilir (ekrandan, 00:53:20):

- **Bir kelime etrafındaki kelimelerle anlam bulur.** Hoca bunu bir varsayım değil, bir gerçek olarak sundu. Bir kelimenin anlamı tek başına anlaşılmaz; tam olarak görmek için kullanıldığı cümleye bakmak gerekir. Anlam bağlama bağlıdır.
- **Sıklıkla birlikte geçen kelimelerin anlamları benzerdir.** "Birlikte geçmek" farklı biçimlerde tanımlanabilir: aynı cümlede, aynı paragrafta ya da aynı web sayfasında geçmek gibi. Bu ilke benzerliğin hangi anlamda olduğunu söylemez; yalnız aralarında bir ilişki olduğunu ifade eder.
- **Büyük derlemlere gereksinim duyar.** İstatistiksel anlambilim bu iki ilkenin üzerine kuruludur ve bunları kullanabilmek için büyük miktarda derleme ihtiyaç duyar.

**Derlem**, metin koleksiyonudur, yani metinler kümesidir. Hocanın örnekleri:

- Wikipedia sayfalarının metinlerini alıp birleştirirseniz bir Wikipedia derlemi elde edersiniz.
- 100 bin haberi alıp birleştirirseniz bir haber derlemi elde edersiniz.
- Forum sitelerinde gezip soru-cevap ikililerini toplarsanız bir forum derlemi elde edersiniz.

Kurallar çok fazla elle konmadığı için büyük ölçekli derlemler gerekir. Bunların nasıl yapıldığı önümüzdeki derslerde anlatılacak.

> **Ek bilgi (derste anlatılmadı):** "Bir kelime etrafındaki kelimelerle anlam bulur" ilkesi literatürde dağılımsal hipotez (distributional hypothesis) olarak bilinir ve büyük olasılıkla Harris (1954) ile Firth'in (1957) "You shall know a word by the company it keeps" sözüne dayandırılır. word2vec gibi kelime gömme yöntemleri bu ilke üzerine kuruludur.

## 10. Dersin Amacı ve Kazanımları

Hoca dersin amacını slayttan okudu (ekrandan, 00:56:10). Bu dersi alan öğrenci:

- Hesaplamalı anlambilimin (HA) bilgisayarlı doğal dil işlemedeki önemini bilecektir.
- HA literatüründeki son gelişmeleri ve açık problemleri bilecektir.
- HA için geliştirilmiş en güncel araçları ve veri kümelerini kullanabilecektir.
- HA'nın çeşitli uygulama alanlarında uygulama yapabilecektir.
- HA bilimsel literatürüne katkı yapabilecek fikirler üretebilecektir.

Hoca son maddenin kendisi için önemli olduğunu söyledi: Derste yapılan çalışmaların öğrencilere gerçekten katkı sağlayacak seviyeye gelmesini istiyor; bu yüzden başkalarının doğrudan yaptığı işler yerine biraz farklı konular vermeye çalışıyor.

## Örnek Sorular

**Soru 1** (ekrandan, 00:34:45): "Ali'nin kedisi yok. Sarman bir kedi." öncülleri doğru kabul edilirse, "Sarman'ın sahibi Ali'dir" sonucu doğru mudur?

> **Çözüm (derste verilen):** Hayır. Ali'nin hiç kedisi olmadığı doğru kabul edildiğine göre, bir kedi olan Sarman'ın sahibi Ali olamaz; sonuç öncülle çelişir. Örnek, çıkarımın doğru da yanlış da olabileceğini göstermek için verildi.

**Soru 2** (ekrandan, 00:35:30): "Ali bugün okula gitmedi." bilgisinden neler üretilebilir?

> **Çözüm (derste verilen):** "Ali öğrencidir" (her gün okula giden biri gibi; öğretmen de olabilir), "Ali hastadır" (mümkün), "Ali yaz tatilindedir" (mümkün), "Ali mutludur" (soru işaretli; tatildeyse belki). Hiçbiri kesin değildir; hepsi belli bir olasılıkla doğru olan, zorunlu olmayan çıkarımlardır.

**Soru 3** (ekrandan, 00:37:10): "Ali Hoca bugün öğrencilerinin dersteki performansından çok memnun oldu." bilgisinden neler üretilebilir?

> **Çözüm (derste verilen):** "Ali Hoca öğretmendir" (öğrencileri var), "Ali Hoca bugün mutludur" (öğrenciler iyiyse hoca mutludur), "Ali Hoca'nın öğrencileri çalışkandır".

**Soru 4** (derste sözlü, 00:41:21): "Hiç kimse yalancıları sevmez" cümlesini birinci dereceden mantıkla yazabilir misiniz?

> **Çözüm (derste verilmedi):** Slaytta $\forall x\,[S(x) \rightarrow \neg\exists y\,(L(x,y))]$ verildi. $S(x)$ "x yalancıdır", $L(x,y)$ "x, y'yi sever" ise doğru yazım $\forall x\,[S(x) \rightarrow \neg\exists y\,L(y,x)]$ olur: her yalancı x için, x'i seven hiçbir y yoktur. Slayttaki biçim "yalancılar kimseyi sevmez" anlamına gelir (bkz. Bölüm 6.4'teki ders sonrası not).

**Soru 5** (ekrandan, 00:42:45): "John saw a man with a telescope" cümlesi neden kural tabanlı çözümleme için sorun çıkarır?

> **Çözüm (derste verilen):** Cümle iki anlama gelir: John adamı teleskopla gördü, ya da John elinde teleskop olan adamı gördü. Gramer bu cümle için iki ayrı ağaç üretir: "with a telescope" ya "a man" isim öbeğine ya da fiil öbeğine bağlanır. Cümle tek başına hangi anlamın kastedildiğini belirlemez; bu belirsizlik kural tabanlı yapıların işini zorlaştırır.

**Soru 6** (ekrandan, 00:50:00): "Ali okula gittiğinde öğlen yemeğini kantinde yer. Ali eve gittiğinde öğlen yemeğini mutfakta yer. Ali sınıfta kitap okudu." bilgileri verildiğinde "Ali öğlen yemeğini nerede yedi?" sorusunun cevabı nedir ve bu cevaba ulaşmak için metinde olmayan hangi bilgiler gerekir?

> **Çözüm (derste verilen):** Cevap: kantinde. Gerekli bilgiler: birisi bir yerde bulunmuşsa oraya gitmiştir; birisi bir yere gitmişse o yeri içine alan yere de gitmiştir; sınıf okulun içindedir. Ali sınıfta bulunduğu için okulda bulunmuştur, dolayısıyla okula gitmiştir, dolayısıyla yemeğini kantinde yemiştir. Prolog sorgusu `?- vardir2(yer,ali,oglenyemegi,Nerede,_).` cevabı `Nerede = kantin` verir. Ali kitabı odada okusaydı cevap `mutfak` olurdu.

## Dersin Toparlaması

Bu ilk derste önce dersin kapsamı çizildi: hayat bilgisi veritabanları, dil modelleri, anlamsal uzaylar ve makine öğrenmesindeki yeni yaklaşımlar gibi araç ve yöntemler; ardından metin sınıflandırmadan soru cevaplamaya ve görsel anlambilime uzanan uygulamalar. Sonra anlambilim, kelimelerin, öbeklerin ve cümlelerin anlamını ve aralarındaki ilişki türlerini inceleyen dilbilim dalı olarak tanımlandı. Bu ilişkilerin, eldeki bilgiden olmayan bilgiyi üretme işi olan çıkarımın ham maddesi olduğu; günlük çıkarımlarımızın çoğunun zorunlu değil olasılıklı olduğu örneklerle gösterildi.

Hesaplamalı anlambilim, anlambilimi makinelere yaptırma uğraşı olarak tanımlandı ve iki okulu tanıtıldı. Formal anlambilim dili mantık formülleriyle, gramerlerle ve kurallarla ifade eder; çıkarımları açıklanabilir ve izlenebilir yapar, ama dildeki belirsizlik ve kuralların elle yazılma yükü onu zorlar. Prolog örneği, metinde yazmayan genel bilgiler eklenmeden çıkarım yapılamayacağını gösterdi. İstatistiksel anlambilim ise kuralları veriden öğrenir; "kelime etrafındaki kelimelerle anlam bulur" ve "birlikte geçen kelimeler benzer anlamlıdır" ilkelerine dayanır ve büyük derlemler ister. Bir sonraki derste, Prolog örneğinde ihtiyaç duyulan bu türden genel bilginin kaynağı olan hayat bilgisi veritabanlarına geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
