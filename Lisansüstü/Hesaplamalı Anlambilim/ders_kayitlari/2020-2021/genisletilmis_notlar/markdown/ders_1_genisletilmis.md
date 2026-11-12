# Ders 1 Genişletilmiş Notu: Anlambilim ve Hesaplamalı Anlambilime Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Konu Akışı
- 2. Anlambilim Nedir?
- 3. Çıkarım
- 4. Hesaplamalı Anlambilim ve İki Temel Okul
- 5. Açıklanabilirlik: Neden Formal Yaklaşıma Geri Dönülüyor?
- 6. Formal Anlambilim: Doğal Dili Mantıkla Yazmak
- 7. Kural Tabanlı Yaklaşımlar: Cümle ve Kelime Çözümleme
- 8. Prolog ile Bir Çıkarım Örneği
- 9. Uzman Sistemler ve Kural Tabanlı Yaklaşımın Sınırları
- 10. İstatistiksel Anlambilim
- Örnek Sorular

## 1. Dersin Konu Akışı

Bu ilk derste hoca, dersin içeriğini tanıttı ve anlambilime dair birkaç temel kavramı verdi. Asıl konulara bir sonraki dersten itibaren girilecek. Haftalık içerik belgesinde dersin konuları şu sırayla yer alıyor (ekrandan, 00:31:10):

- Ders tanıtımı, anlambilim ve hesaplamalı anlambilime giriş.
- Hayat bilgisi veri tabanları (iki hafta).
- Anlamsal uzaylar ve dil modelleri; kelime, deyiş, cümle ve metin temsilleri.
- Makine öğrenmesinde yeni yaklaşımlar-1: aktif öğrenme, yarı eğiticili öğrenme, transfer öğrenme, aktif örnekleme, zayıf denetim (weakly supervision).
- Makine öğrenmesinde yeni yaklaşımlar-2: planlı öğrenme, hayat boyu öğrenme, çekişmeli eğitim, çok görevli eğitim, zero/one/few shot learning, veri zenginleştirme.
- Bağlam temelli dil modelleri.
- Metin sınıflandırma ve duygu durum analizi.
- NER, paragraf anlama, soru cevaplama.
- Metinlerde çıkarım.
- Bağlam duyarlı hesaplama, diyalog ve üretim uygulamaları, görsel anlambilim.

Hoca, makine öğrenmesinin eskiden sınıflandırma, kümeleme, regresyon ve birliktelik (sepet analizi gibi örüntü bulma) problemleriyle sınırlı olduğunu söyledi. Son 5-10 yılda bu problemler çok çeşitlendi. Bu yüzden ilgili bölümün adını "makine öğrenmesi versiyon 2" diye koymuş. Bağlam temelli dil modelleri bölümünde RNN tipli ve transformer tipli nöral dil modelleri işlenecek. Uygulamalar kısmında NLP'nin temel alanları ele alınacak.

Görsel anlambilim, doğal dil işleme ile bilgisayarla görmenin ortak alanı gibi düşünülebilir. Son zamanlarda popüler olan çok kipli öğrenme (multimodal learning) burada yer alır. Bu yaklaşımda elinizdeki veri yalnız metin ya da yalnız resim değildir; hem resim hem metin vardır. Bunlar birbiriyle eşleşmiş ya da eşleşmemiş olabilir.

Dersin genel yapısı iki kısımdır: önce araçlar ve yöntemler, sonra uygulamalar. Hocanın belirttiği amaçlar, literatürdeki son gelişmeleri ve açık problemleri tanımak, güncel araçları ve veri kümelerini kullanmak, çeşitli uygulama alanlarında uygulama yapmak ve literatüre katkı sağlayabilecek fikirler üretmektir. Hoca alanın son 3-4 yılda o kadar hızlandığını söyledi ki bütün gün literatür okusanız yine yetişmek zor.

## 2. Anlambilim Nedir?

Anlambilim (semantik), kelimelerin, kelime öbeklerinin ve cümlelerin anlamını, aralarındaki ilişkileri ve bu ilişkilerin türlerini konu edinen dilbilim dalıdır.

### 2.1 Kelime öbekleri

Tanımda kelime ve cümlelerin yanında kelime öbekleri de geçer, çünkü bir kelime öbeği de bir kavramı ifade eder. "Fatih Sultan Mehmet" bir kelime öbeğidir: kelimelerin her birinin tek başına taşıdığı anlamdan farklı bir anlam oluşturmak üzere bir araya gelirler. Bu yapılar İngilizcede collocation ya da phrase diye geçer.

### 2.2 Kelimeler arası ilişkiler

Slaytta şu kelime ikilileri verildi (ekrandan, 00:49:20):

- büyük-küçük, büyük-iri, pembe-kırmızı, hayvan-canlı, sınıf-tahta, güldü-gülmedi, güldü-ağladı

Her ikilide kelimeler arasında bir ilişki vardır. Hoca bu ilişkilerin türlerinin aynı olup olmadığını sordu; cevap, farklı olduklarıydı. Zıt anlamlı olanlar, benzer anlamlı olanlar, bir şeyin bir yerde bulunmasıyla ilgili olanlar ve üst kavram-alt kavram ilişkisi olanlar vardır.

### 2.3 Cümleler arası ilişkiler

Kelimeler gibi cümleler arasında da ilişkiler vardır (ekrandan, 00:49:20):

- Ali okula gitti. – Ali öğrencidir.
- Sınava çok çalıştım. – Dersi geçtim.
- Bugün ıslanmadım. – Şemsiyem yanımdaydı.
- Bugün okula gitmeyeceğim. – Hastayım.

Bu ikililerdeki ilişkiler de aynı türden değildir. Demek ki elimizde hem ilişkiler hem de ilişkilerin türleri vardır. Anlambilim bunlarla birlikte bir temel konuyu daha kapsar: çıkarım.

## 3. Çıkarım

### 3.1 Doğru mu, yanlış mı?

Slayttaki ilk örnek (ekrandan, 00:52:15):

- Verilenler: "Ali'nin kedisi yok. Sarman bir kedi."
- Soru: "Sarman'ın sahibi Ali'dir." (doğru mu?)

Bunu mantık açısından düşünmek gerekir. Mantıkta bize doğru olduğu söylenen önermeler verilir; bunlara bakarak bir ifadenin doğru olup olmadığına karar veririz. Burada "Sarman'ın sahibi Ali'dir" çıkarılamaz. Tersine, "Sarman'ın sahibi Ali değildir" ifadesi verilenlerden kesin olarak çıkar.

### 3.2 Neler üretilebilir?

İkinci türde bize bir şey verilir ve doğru olduğu söylenir; buna göre neler üretilebileceği sorulur (ekrandan, 00:52:15):

- Verilen: "Ali bugün okula gitmedi." (Neler üretilebilir?)
- Ali öğrencidir.
- Ali hastadır.
- Ali yaz tatilindedir.
- Ali mutludur.

"Ali öğrencidir" üretilebilir ama kesin değildir: okula gitmeyen kişi bir öğretmen de olabilir, okula mal getiren bir manav da. "Ali hastadır" ve "Ali yaz tatilindedir" de birer ihtimaldir. "Ali mutludur" da olabilir; okula gitmediği için mutlu olabilir, ama okulunu çok seviyorsa doğru olmayabilir.

Hoca birinci türü geriye doğru zincirleme (backward reasoning), ikinci türü ileriye doğru zincirleme (forward reasoning) diye adlandırdı. Birincisinde bir ifade verilip doğruluğu sorulur; ikincisinde siz üretebildiğiniz kadar sonuç üretirsiniz.

Slaytta bir örnek daha vardı: "Ali Hoca bugün öğrencilerinin dersteki performansından çok memnun oldu." Bu cümleden de birçok şey üretilebilir; slaytta "Ali Hoca öğretmendir", "Ali Hoca bugün mutludur", "Ali Hoca'nın öğrencileri çalışkandır" gibi sonuçlar yer alıyordu (ekrandan, 00:52:15, slayt küçük görünümü).

### 3.3 Kesin ve yaklaşık çıkarım

Bu örnekler bir kavramı daha ortaya çıkarır: çıkarımla elde edilen her şey için "kesin doğrudur" ya da "kesin yanlıştır" denemez. Sarman örneğinde, verilenler doğru kabul edilirse "Sarman'ın sahibi Ali değildir" kesinlikle doğrudur. Buna kesin akıl yürütme (exact reasoning) denebilir. "Ali okula gitmedi" örneğinde üretilenler ise olası durumlardır; ne kesin doğru ne kesin yanlıştır. Bu da yaklaşık ya da olasılıksal akıl yürütmedir (approximate reasoning).

## 4. Hesaplamalı Anlambilim ve İki Temel Okul

Hesaplamalı anlambilim (computational semantics), anlambilimin bütün ilgi alanlarını çeşitli yöntemlerle otomatikleştirme uğraşıdır (ekrandan, 00:54:25). Yani anlambilimde yapılabilen şeyleri bilgisayara yaptırma çabasıdır.

Tarihçesine bakıldığında iki temel okul vardır:

- **Formal anlambilim**
- **İstatistiksel anlambilim**

Bu iki okul birbirinden tamamen ayrık değildir, birbirinden çok şey öğrenirler. Tarihsel olarak önce formal kısım ortaya çıkmış, sonra istatistiksel kısım gelmiştir. Bugünkü gelişmelerin en yoğun yaşandığı alan istatistiksel kısımdır. Ancak son zamanlarda formal anlambilimden yeniden yararlanmak gerektiği düşüncesi ortaya çıkmaya başladı: doğrudan formal yöntemleri kullanmak değil, onlarınki gibi çıktılar üretmek. Bunun sebebi bir sonraki bölümün konusudur.

## 5. Açıklanabilirlik: Neden Formal Yaklaşıma Geri Dönülüyor?

### 5.1 Açıklama mı, başarı mı?

Yapay sinir ağlarının temel bir problemi, verdikleri kararların sebebini pek açıklayamamalarıdır. Bu konuda epey çalışma yapılmaya başlandı. Kararın sebebini söylemesi neden önemli olsun? Hoca bu noktada Hinton'a atfettiği bir soruyu aktardı.

Bir tıbbi uzman sistem size bir tanı koyuyor ya da bir tedavi öneriyor. İki sistem olsun:

- Birinci sistem kanıtlara bakarak tanı koyuyor ve tanıya nasıl vardığını açıklıyor: "Şurada şunu gördüm, şu değer yükselirse bu buna delalettir, bu yüzden bu çıkarımı yaptım." İnsanlar üzerindeki testlerde başarısı %60.
- İkinci sistem de kendi içinde çıkarım yapıyor ama bunu size anlatamıyor. Başarısı %70.

Hangisini tercih edersiniz?

Derste farklı görüşler çıktı. Bir öğrenci, açıklamaya gerek olmadığını, %10 daha başarılı olanı seçeceğini söyledi. Başka bir öğrenci, sistemin sonuca nasıl vardığını görmek istediğini, bir yanlış varsa kendisinin de fark etmek isteyeceğini söyledi. Bir başka öğrenci, model geliştirme sürecinde yorumlanabilirliğin önemli olduğunu, çünkü performansı artırmak için modelin neden hata yaptığını görmek gerektiğini belirtti. Hoca bu noktanın çok doğru olduğunu, ama sorunun son kullanıcı açısından sorulduğunu hatırlattı; son kullanıcı olarak o öğrenci de yüksek performanslı olanı seçeceğini söyledi.

Hoca insan ilişkilerinden bir benzetme yaptı. Bir ilişkide taraflardan biri ayrılmak istiyor; ayrılması da gerçekten mantıklı. Ama karşı taraf "neden?" diye sorduğunda yalnızca "çünkü bu daha iyi" cevabını alıyor. Bu cevap tatmin etmez. İnsanın düşünce dünyasında süreçler de önemlidir; süreci atlayıp yalnızca sonucu gösteren bir şey hoşumuza gitmeyebilir. Hastalık teşhisinde ise performansa güvenmek mantıklı olabilir.

### 5.2 Tank anekdotu

Hoca, sistemlerin nasıl çalıştığını bilmenin neden gerektiğini bir anekdotla anlattı. Soğuk savaş döneminde olduğunu tahmin ettiği bir projede tanklara bilgisayarlı görü sistemi kuruluyor. Tankların önündeki kameralar dışarıdaki tankları görüyor ve sistemin bunların dost mu düşman mı olduğunu otomatik olarak ayırt etmesi isteniyor.

- Arazide, tankların içinden dost ve düşman tank resimleri çekiliyor.
- Veriler yazılım birimine gönderiliyor, rastgele eğitim ve test kümelerine ayrılıyor.
- Test kümesindeki başarı %95 civarında. Birçok test kümesiyle çapraz doğrulama yapılıyor, doğrulama kümesi de kullanılıyor; sorun yok.
- Model tanklara yükleniyor. Gerçek arazide başarı %50 civarına düşüyor. İki sınıflı bir problemde bu, aşağı yukarı yazı tura atmak demektir (sınıf olasılıklarına da bağlı olarak).

Eğitim ve test bölmesinde hata yok, etiketler doğru, veri de arazide toplandığı için çözünürlük, gürültü ya da ortam farkı yok. Öğrencilerin önerileri (görüntülerin temiz olması, kılık değiştirme, ortam farkı, doğrulama kümesi eksikliği, aşırı öğrenme) tek tek elendi. Hoca, aşırı öğrenmede eğitim başarısı yüksek, test başarısı düşük olacağını; burada test başarısının da yüksek olduğunu hatırlattı.

Cevap: Düşman resimleri hava açıkken, dost resimleri hava kapalıyken çekilmiş. Modele "bu resimleri iki sınıfa ayır" denmiş, model de ayırmış; ama tanklara bakarak değil, ışığa bakarak. "Işık fazlaysa düşman, azsa dost" kuralını öğrenmiş. Sahada hava açıkken herkese düşman, kapalıyken herkese dost diyecektir.

Bir öğrenci, modelin ana nesneye odaklanacak şekilde eğitilmesi gerektiğini söyledi. Hoca, modelin arka plana mı ön plana mı bakacağını önceden bilemeyeceğimizi belirtti. Aynı resimler hava durumuna göre sınıflandırılmak istenseydi, modelin yaptığı şey doğru olacaktı. Başka bir öğrenci, veriyi temizleyip yalnız tankları kesip vermeyi önerdi. Hoca, o zaman da modelin nereye bakması gerektiğini sizin söylemeniz gerektiğini belirtti.

Modelin neye bakarak karar verdiğini bilmenin anlamı buradadır. Yapay sinir ağı kullanıldıysa modelin ne öğrendiğini anlamak zordur (mümkün, ama güç). Karar ağacı gibi bir algoritma kullanılsaydı, modeli inceleyip "şu değer şundan büyükse" gibi kurallara bakarak resmin üst kısmının rengine odaklandığı, tanklara hiç odaklanmadığı görülebilirdi.

> **Ek bilgi (derste anlatılmadı):** Bu tank hikâyesi yapay zekâ literatüründe çok anlatılır, ama gerçekten yaşandığına dair güvenilir bir kaynak büyük olasılıkla yoktur; genellikle bir şehir efsanesi olarak kabul edilir. Hikâyenin anlattığı sorun ise gerçektir: model, sınıf etiketiyle tesadüfen ilişkili olan bir özelliği (burada ışık) öğrenebilir. Bu tür hatalar literatürde "kısayol öğrenme" (shortcut learning) ya da sahte korelasyon (spurious correlation) diye anılır.

### 5.3 Ne yapmasını söyleyebiliriz, nasıl yapacağını söyleyemeyiz

Hoca anekdotun asıl dersini şöyle bağladı: Bu süreçteki hatayı bulmak için, sistemin yalnız cevabı değil o cevaba nasıl eriştiğini de söylemesi çok işe yarardı. Böyle bir hata her zaman yapılabilir, çünkü makinelere ne yapmalarını istediğimizi söyleyebiliriz, ama nasıl yapmalarını istediğimizi pek söyleyemeyiz.

Bir problemin nasıl çözüleceğini "şöyleyse böyle" diye kodlayabiliyorsak makine öğrenmesine gerek yoktur. Makine öğrenmesini, problemin nasıl çözüleceğini açıkça bilmediğimiz durumlarda kullanırız: "Ben bunun nasıl yapılacağını bilmiyorum, sen örneklerden öğren." Bu durumda modelin neye bakacağına ve neye ne kadar önem vereceğine çok fazla müdahale edemeyiz.

Buradan açıklanabilir yapay zekâ (explainable AI) kavramı doğar. Çok başarılı ama sonuçlarını açıklayamayan modellerin sonuçlarını açıklayabilmesi üzerine çalışmalar yapılıyor. Bu çalışmalar da günün sonunda sonuçları bizim anlayabileceğimiz, formal olarak ifade edilebilen bir hale getirmeye çalışıyor. Özetle: önce formal anlambilim vardı, belli başarılardan sonra tıkandı; istatistiksel kısma geçildi ve o süreç hâlâ sürüyor; bugün açıklanabilir yapay zekâ ile formal alandan yeniden yararlanma çabası var.

### 5.4 Çekişmeli örnekler

İstatistiksel yöntemlerin "arka kapıları" da vardır. Hoca çekişmeli (adversarial) örnekleri hatırlattı: bir maymun resminde 3-5 pikseli özel olarak değiştirdiğinizde model artık "ağaç" ya da istediğiniz başka bir şey demeye başlıyor. Bu da modelin neye göre çıkarım yaptığının sorunlu olduğunu gösterir. Bunu düzeltmek için de çalışmalar sürüyor.

## 6. Formal Anlambilim: Doğal Dili Mantıkla Yazmak

Formal anlambilimin sorusu şudur: İnsan dili formal bir dil olarak, yani mantıkla ifade edilebilir mi?

Hoca önce niceleyicileri hatırlattı: $\exists$ "en az bir tane", yani "vardır" demektir; $\forall$ "her" demektir.

### 6.1 Yatakhane örneği

Cümle: "Yatakhanede herkesin sevmediği bir oda arkadaşı vardır." (ekrandan, 01:15:15)

$$\forall x\,[D(x) \rightarrow \exists y\,(R(x,y) \land \neg L(x,y))]$$

- $D(x)$: x yatakhanede yaşar.
- $R(x,y)$: x ve y oda arkadaşıdır.
- $L(x,y)$: x, y'yi sever.

Okunuşu: Her x için, eğer x yatakhanede yaşıyorsa, öyle bir y vardır ki x ile y oda arkadaşıdır ve x, y'yi sevmez. Yani yatakhanede yaşayan herkesin odasında sevmediği biri vardır.

### 6.2 Diğer örnekler

Slaytta şu örnekler de vardı (ekrandan, 01:15:15 ve 01:16:20):

- "Hiç kimse yalancıları sevmez": $\forall x\,[S(x) \rightarrow \neg \exists y\,(L(x,y))]$ (slayttaki hâliyle).
- "Herkes en az 2 kişiyi sever": $\forall x\,\exists y\,\exists z\,(L(x,y) \land L(x,z) \land (y \neq z))$. Burada $y \neq z$ koşulu, sevilen iki kişinin farklı olmasını sağlar.
- "Tüm evli çiftler kavga eder": $\forall x\,\forall y\,(M(x,y) \rightarrow F(x,y))$. $M(x,y)$: x ve y birbiriyle evlidir. $F(x,y)$: x ve y birbiriyle kavga eder. Yani bütün x ve y'ler için, eğer evlilerse kesinlikle kavga ederler.
- "Ali sadece 1 kişiyi sever." <!-- BELİRSİZ: Bu cümlenin formülü karede kesik kaldı; hoca da üzerinde durmadı. -->

> **Ders sonrası not:** Slaytta $S(x)$ tanımlanmamış. $S(x)$ "x yalancıdır" anlamındaysa, "hiç kimse x'i sevmez" demek için formül büyük olasılıkla $\forall x\,[S(x) \rightarrow \neg \exists y\,L(y,x)]$ olmalıdır. Slayttaki $L(x,y)$ sırası, $L(x,y)$ "x, y'yi sever" tanımına göre "yalancılar kimseyi sevmez" anlamına gelir.

## 7. Kural Tabanlı Yaklaşımlar: Cümle ve Kelime Çözümleme

Formal anlambilimde cümleleri mantıkla ifade etmenin yanında kural tabanlı yaklaşımlar vardır. Bunların yaptığı en temel işler:

- Formal gramerlerle cümle çözümleme.
- Sonlu durum makineleriyle kelimelerin morfolojik çözümlemesi.
- Çıkarım yapma.

### 7.1 Formal gramerle cümle çözümleme

Cümle çözümlemede kodu yazan kişi şunu bilmelidir: bir cümle hangi öğelerden oluşur, o öğelerin her biri hangi alt öğelerden oluşur ve en altta her öğe hangi kelimeler olabilir. Her cümle için ayrı kural yazılmaz. Dilin dilbilgisi kullanılarak cümlelerin hangi parçalardan, birleşe birleşe hiyerarşik bir yapıda oluşabileceği genel kurallarla söylenir; olasılıklar ifade edilir. Sistem bu olasılıklar içinden cümleye uygun yapıyı bulur. Basit gramerlerle basit cümleler çözümlenebilir; karmaşık cümleler daha karmaşık yapılar ister.

Derste SWISH (swish.swi-prolog.org) üzerindeki örnek bir İngilizce DCG grameri gösterildi (ekrandan, 01:17:40):

```prolog
% A simple English DCG grammar
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

<!-- BELİRSİZ: `v(v(sees), sg)` satırının sağ tarafı karede imlecin altında kaldı; `[sees]` olarak tamamlandı. -->

Sorgu `?- phrase(s(Tree), [john, saw, a, man, with, a, telescope]).` ekranda iki ağaç verdi:

```text
Ağaç 1:  s(np(pn(john)),
           vp(v(saw),
              np(det(a), n(man),
                 pp(p(with), np(det(a), n(telescope))))))

Ağaç 2:  s(np(pn(john)),
           vp(v(saw),
              np(det(a), n(man)),
              pp(p(with), np(det(a), n(telescope)))))
```

Birinci ağaçta "with a telescope" öbeği "a man"e bağlıdır, ikincisinde doğrudan fiile ("saw") bağlıdır.

> **Ek bilgi (derste anlatılmadı):** Bu iki ağaç, edat öbeği bağlanma belirsizliği (PP-attachment ambiguity) denen klasik bir durumu gösterir. Birinci okumada adamın elinde teleskop vardır ("teleskoplu bir adam gördü"), ikincisinde John adamı teleskopla görmüştür. Gramer iki yapıya da izin verdiği için çözümleyici ikisini de üretir; hangisinin kastedildiği ancak anlam ya da bağlamla belirlenebilir.

### 7.2 Sonlu durum makineleriyle morfolojik çözümleme

Morfolojik çözümleme, cümle çözümlemenin kelimeye uyarlanmış hâli gibi düşünülebilir: kelimenin morfemlerini bulmaya çalışır. Bu da kural tabanlı bir yapıdır; bir kelimenin hangi parçalardan oluşabileceği tanımlanır. Derste `turkce_morfoloji.pl` adlı Prolog kodunun çıktısı gösterildi (ekrandan, 01:19:10):

```prolog
?- morp([kalem,ler,im,den], A).
A = [isim, çoğul_eki, şahıs_eki, hal_eki]

?- morp([gel,di,m], A).
A = [fiil, zaman_eki, şahıs_eki]
```

(Slayttaki Türkçe karakterler kodlama hatasıyla "çoðul", "þahýs" görünüyordu; burada düzeltildi.)

### 7.3 Kelimeyi parçalara kim ayıracak?

Bu kodda kelime, parçalarına önceden ayrılmış olarak verilir. Bir öğrenci, daha gelişmiş bir sistemin kelimeyi doğrudan alıp kendisinin parçalaması gerektiğini söyledi. Hoca bunun daha iyi olacağını ve bunun yolları olduğunu belirtti: "geldim" kelimesini "gel, di, m" hâline çevirmek. Bunun için BPE (Byte Pair Encoding), WordPiece ve SentencePiece gibi algoritmalar vardır. Bunlar bir kelimenin o dile göre en olası nasıl parçalanabileceğini bulur. Bugün nöral dil modellerine kelimeler bütün olarak değil, bu şekilde parçalara (token) ayrılarak verilir.

**Soru:** Kelimeleri bütün olarak mı vermek iyidir, parçalara ayırarak mı?

**Cevap:** "geldim" ve "geldik" kelimelerini birbirinden tamamen farklı iki kelime olarak verirsek aralarında ortak bir şey yokmuş gibi görünür. Parçalara ayırarak verirsek sistem ortak parçaları görüp tanıyabilir. Bu özellikle eklemeli dillerde önemlidir. İngilizcede bu yöntem daha çok nadir (rare) kelimeleri, yani frekansı düşük kelimeleri kodlamak için kullanılır. Türkçe gibi, kelimeye önden ya da arkadan ek alan dillerde ise çok fayda sağlar.

> **Ek bilgi (derste anlatılmadı):** BPE, başlangıçta kelimeleri karakterlerine ayırır ve derlemde en sık yan yana gelen sembol çiftini tekrar tekrar birleştirerek bir alt kelime sözlüğü oluşturur. Böylece sık kelimeler tek parça kalırken nadir kelimeler sık görülen parçalarına bölünür. WordPiece benzer şekilde çalışır ama birleştirilecek çifti derlemin olasılığını en çok artıran çifte göre seçer. SentencePiece ise metni boşluklara göre önceden bölmeden doğrudan ham metin üzerinde çalışabilir.

## 8. Prolog ile Bir Çıkarım Örneği

### 8.1 Problem

Prolog dili anlatılmadı, ama onunla yapılabilen çok basit, tamamen kural tabanlı bir çıkarım örneği gösterildi. Verilen paragraf:

- Ali okula gittiğinde öğle yemeğini kantinde yer.
- Ali eve gittiğinde öğle yemeğini mutfakta yer.
- Ali (bugün) sınıfta kitap okudu.

Soru: Ali öğle yemeğini nerede yedi?

Hoca, bilgisayarların istediğimizi değil söylediğimizi anladığını hatırlattı. Soruya cevap vermek için neye ihtiyaç var? Ali öğle yemeğini iki yerde yiyebilir: mutfakta ya da kantinde. Mutfakta yemesi için eve gitmiş olması, kantinde yemesi için okula gitmiş olması gerekir. Elimizde ise "Ali eve gitti" ya da "Ali okula gitti" diye bir bilgi yok; yalnız "Ali sınıfta kitap okudu" var. Buradan "Ali okula gitti"ye erişebilmek için şu bilgilere ihtiyaç var:

- Birisi bir yerde bulunmuşsa oraya gitmiştir.
- Birisi bir yere gitmişse o yeri içine alan yere de gitmiştir.
- Sınıf okulun içindedir.
- Oda evin içindedir.

Çıkarım zinciri şöyledir:

```text
Ali sınıfta kitap okudu
  -> Ali sınıfta bulundu
  -> Ali sınıfa gitti
  -> (sınıf okulun içinde) Ali okula gitti
  -> (okula gittiğinde kantinde yer) Ali öğle yemeğini kantinde yedi
```

> **Ders sonrası not:** Hoca bu zinciri anlatırken bir yerde "sınıf okulun içindedir, o da evin içindedir" dedi. Slayttaki ve koddaki bilgi "oda evin içindedir"dir; sınıfın evle bir ilişkisi yoktur.

### 8.2 Prolog kodu

Kodda cümleler `vardir(yüklem, özne, belirtilinesne, dolaylıtümleç, cümleno)` yapısında tutulmuştur. Cümle numarası takip için eklenmiştir, çok kritik değildir (ekrandan, 01:27:15):

```prolog
kapsar(oda,ev).
kapsar(sinif,okul).
vardir(oku,ali,kitap,sinif,12).

vardir2(git,M,_,Yer,_) :- vardir(_,M,_,Yer,_).
    % M Yer'de bulunmussa -> M Yer'e gitmistir

vardir2(F,M,B,Yer1,I) :- kapsar(Yer2,Yer1), vardir2(F,M,B,Yer2,I).
    % M Yer2'de birsey yapmissa ve Yer2 yer1'i kapsiyorsa
    % -> M Yer1'de de ayni seyi yapmistir

vardir2(yer,ali,oglenyemegi,mutfak,_) :- vardir2(git,ali,_,ev,_).
    % ali eve gitmisse -> oglenyemegini mutfakta yer

vardir2(yer,ali,oglenyemegi,kantin,_) :- vardir2(git,ali,_,okul,_).
    % ali okula gitmisse -> oglenyemegini kantinde yer
```

Prolog'da `A :- B.` kuralı "B doğruysa A da doğrudur" demektir. Alt çizgi (`_`) "ne olursa olsun" anlamına gelir. Birinci kurala bakalım: en baştaki yüklem önemli değil; M özneyi, Yer dolaylı tümleci gösteriyor. M bir yerde dolaylı tümleç olarak bulunmuşsa, "M o yere gitmiştir" bilgisi türetilir. İkinci kural, bir yerde yapılan şeyin o yeri içine alan yerde de yapılmış sayılmasını sağlar. Son iki kural paragraftaki iki bilgidir. `vardir` ilişkisi gerçek cümleleri (bilgileri), `vardir2` ilişkisi türetilen cümleleri ifade eder.

> **Ders sonrası not:** `kapsar(sinif,okul)` gerçeği "sınıf okulun içindedir" anlamında kullanılıyor (hoca da "okul sınıfı kapsar" diye okudu). Buna göre ikinci kuraldaki `kapsar(Yer2,Yer1)`, "Yer2, Yer1'in içindedir" demektir. Slayttaki "Yer2 yer1'i kapsıyorsa" yorumu yönü ters söylüyor; kodun kendisi doğru çalışır.

### 8.3 Sorgu ve sonuç

Sorgu ve çıktı (ekrandan, 01:29:00):

```prolog
?- vardir2(yer,ali,oglenyemegi,Nerede,_).
Nerede = kantin ;
No
```

Sistem, Ali'nin sınıfta bulunduğunu görüp okulda bulunduğu bilgisini edinmiş; okulda bulunduğuna göre okula gittiği çıkarımını yapmış; okula gittiğine göre yemeğini de kantinde yediği sonucuna ulaşmıştır. Gerçek cümle `vardir(oku,ali,kitap,sinif,12)` yerine `vardir(oku,ali,kitap,oda,12)` olsaydı cevap `mutfak` olacaktı. Bu iki sonuç, kuralların Python ile yazılmış küçük bir ileri zincirleme benzetimiyle de doğrulandı (kod derste Prolog'da çalıştırıldı; ajan Prolog çalıştırmadı).

Formal yapının özü buradadır: cümleler kurallara uygun biçimde, her şey olması gereken yerde verilir; belirsizlik yoktur.

## 9. Uzman Sistemler ve Kural Tabanlı Yaklaşımın Sınırları

### 9.1 Yapay zekânın dalgalı tarihi

Bu formal yapılarla klasik uzman sistemler çağında çeşitli çalışmalar yapıldı. Yapay zekânın tarihi dalgalıdır. Bilgisayarlar ortaya çıkınca satranç programları gibi şeylerle çok büyük beklentiler doğdu. 1960'lara kadar süren bu beklentiler gerçekleşmeyince bir çöküş yaşandı. Yeni çıkışı sağlayan şey, kural tabanlı klasik uzman sistemler oldu. Hastalık teşhis sistemleri, planlama sistemleri gibi uygulamalar ortaya çıktı ve yapay zekâ çalışmaları yeniden ivme kazandı.

Uzman sistem, belirli ve özel bir problemi çözmek için tasarlanmış sistem demektir. Uzman olmayan sistem ise her türlü problemi çözebilen genel problem çözücüdür (general AI). Hocaya göre genel yapay zekâ eskiden de ütopyaydı, bugün de ütopyadır; gazetelerde ve abartılı yayınlarda iddialar olsa da henüz ufukta görünmüyor. Belirli bir problemi çözen sistemlerde ise çok büyük ilerleme vardır: 50 yıl önceki satranç programlarıyla bugünküler ya da görüntü tanıma sistemleri arasında büyük fark vardır.

### 9.2 Sınırlar

Kural tabanlı sistemlerin de bir sınırı olduğu görüldü:

- Her doğal dil cümlesi bu şekilde formal yapıya dönüştürülemiyor.
- Her yeni uzman sistem için uzman bilgisine çok ihtiyaç var; kuralları uzmanların oturup elle yazması gerekiyor. O dönemde bunları otomatik oluşturmanın yolu yoktu. Bu, zaman ve emek sorunudur.
- Bilgiyi kurallara dönüştürme işi her durumda etkili yapılamıyor; kuralların her durumu kapsaması pek mümkün değil.

Hoca, doğruluğundan emin olmadığını belirterek klasik bir hikâye anlattı: Tedavi öneren bir sistemde hastanın böbreklerini bir bakteri sarmış. Sistem "böbrekleri 150 dereceye ısıtın" öneriyor; çünkü bakteri 150 derecede ölüyor. Ama bir insanın böbreği 150 dereceye ısıtılırsa böbrek kalmaz. Bu hikâye, makinenin olaydan ne kadar kopuk olduğunu ve tamamen mekanik çalıştığını gösterir. Dünyanın nasıl işlediğine dair bilgiye dünya bilgisi (world knowledge) denir ve bunu sisteme vermemişizdir.

Dünya bilgisinin makinelere nasıl aktarılacağı problemi bugün de sürüyor. Dersin bir sonraki konusu olan hayat bilgisi veri tabanları tam olarak bu soruyla ilgilidir: dünya nasıl işliyor, bunu makinelere aktarabilir miyiz, bugün neleri yapabildik ve neleri hâlâ yapamıyoruz?

## 10. İstatistiksel Anlambilim

Kural tabanlı sistemler bir yere kadar geldi ve doyuma ulaştı. Bundan sonra istatistiksel yapılar ortaya çıkmaya başladı. Fikir şudur: kural yazmayalım; kelimeleri, ilişkileri, kavramları, cümleleri, her şeyi vektörlere dönüştürelim. Bu vektörlerin nasıl oluşturulacağı ilerideki derslerde görülecek.

İstatistiksel anlambilim iki hipoteze dayanır (ekrandan, 01:35:40):

- Bir kelime, etrafındaki kelimelerle anlam bulur.
- Sıklıkla birlikte geçen kelimelerin anlamları benzerdir.

Hoca bu iki ifadenin birbirine oldukça benzediğini belirtti. Bu yaklaşım büyük derlemlere gereksinim duyar. Derlemden kasıt, toplanmış ve etiketlenmemiş metinlerdir:

- Bir gazetede bir yıl boyunca çıkan bütün haberleri toplayıp bir metin dosyasına kaydederseniz bu bir haber derlemidir.
- Birçok köşe yazarının yazılarını toplarsanız bir köşe yazısı derlemi olur.
- Birçok filmin altyazısını bir ya da birden fazla metin dosyasında toplarsanız bir altyazı derlemi olur.

Bu tür derlemler üzerinde çalışarak istatistiksel anlambilimde ilerlemek mümkündür.

> **Ek bilgi (derste anlatılmadı):** Bu iki hipotez literatürde dağılımsal hipotez (distributional hypothesis) diye bilinir. Büyük olasılıkla en çok alıntılanan ifadeleri Zellig Harris'in (1954) benzer bağlamlarda geçen kelimelerin benzer anlamlı olduğu görüşü ve J. R. Firth'ün (1957) "Bir kelimeyi yanındaki kelimelerden tanırsınız" sözüdür. word2vec gibi kelime vektörü yöntemleri bu hipotezin doğrudan uygulamasıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:52:15): "Ali'nin kedisi yok. Sarman bir kedi." bilgileri doğru kabul edilirse "Sarman'ın sahibi Ali'dir." ifadesi doğru mudur?

Derste verilen çözüm: Hayır. Bu ifade verilenlerden çıkarılamaz; tersine, "Sarman'ın sahibi Ali değildir" ifadesi kesin olarak doğrudur. Bu bir kesin (exact) akıl yürütme örneğidir.

**Soru 2** (ekrandan, 00:52:15): "Ali bugün okula gitmedi." cümlesinden neler üretilebilir?

Derste verilen çözüm: "Ali öğrencidir", "Ali hastadır", "Ali yaz tatilindedir", "Ali mutludur" gibi sonuçlar üretilebilir. Hiçbiri kesin değildir; örneğin okula gitmeyen kişi öğretmen de olabilir. Bu, yaklaşık (approximate) akıl yürütmedir.

**Soru 3** (ekrandan, 00:49:20): Büyük-küçük, büyük-iri, pembe-kırmızı, hayvan-canlı, sınıf-tahta, güldü-gülmedi, güldü-ağladı ikililerindeki ilişkilerin türleri aynı mıdır?

Derste verilen çözüm: Aynı değildir. Zıt anlamlı, benzer anlamlı, bir şeyin bir yerde bulunmasıyla ilgili ve üst kavram-alt kavram ilişkisi olan ikililer vardır.

> **Çözüm (derste verilmedi):** İkililerin tek tek eşlemesi derste yapılmadı. Büyük olasılıkla şöyle eşlenir: büyük-küçük ve güldü-ağladı zıt anlam; büyük-iri benzer anlam; pembe-kırmızı aynı kavram alanında yakın renkler; hayvan-canlı alt kavram-üst kavram; sınıf-tahta bir şeyin bir yerde bulunması; güldü-gülmedi olumlu-olumsuz (çelişki).

**Soru 4** (derste sözlü, 00:57:00): Tanı koyan iki tıbbi sistem var. Birincisi kararını açıklıyor ve başarısı %60; ikincisi açıklamıyor ve başarısı %70. Son kullanıcı olarak hangisini tercih edersiniz?

Derste verilen çözüm: Tek doğru cevap verilmedi. Öğrencilerin bir kısmı daha başarılı sistemi, bir kısmı açıklama yapanı seçti. Hoca, geliştirici için yorumlanabilirliğin hatayı bulmada önemli olduğunu, insan ilişkilerinde gerekçesiz kararların tatmin etmediğini, hastalık teşhisinde ise performansa güvenmenin mantıklı olabileceğini söyledi.

**Soru 5** (derste sözlü, 01:03:13): Dost ve düşman tankları ayıran bir modelin test başarısı %95, sahadaki başarısı %50. Eğitim/test bölmesi rastgele, etiketler doğru, veri arazide toplanmış, çapraz doğrulama yapılmış. Ne olmuş olabilir?

Derste verilen çözüm: Düşman resimleri hava açıkken, dost resimleri hava kapalıyken çekilmiş. Model tankları değil ışık miktarını ayırt etmeyi öğrenmiş. Aşırı öğrenme değildir, çünkü test başarısı da yüksektir.

**Soru 6** (derste sözlü, 01:21:19): Nöral dil modellerine kelimeleri bütün olarak mı vermek iyidir, alt parçalara ayırarak mı?

Derste verilen çözüm: Parçalara ayırmak, "geldim" ve "geldik" gibi kelimelerin ortak parçalarının görülmesini sağlar. Bu, Türkçe gibi eklemeli dillerde çok faydalıdır; İngilizcede daha çok nadir kelimeler için kullanılır.

**Soru 7** (ekrandan, 01:29:00): 8.2'deki Prolog kodunda `?- vardir2(yer,ali,oglenyemegi,Nerede,_).` sorgusunun cevabı nedir? Gerçek cümle `vardir(oku,ali,kitap,oda,12)` olsaydı cevap ne olurdu?

Derste verilen çözüm: `Nerede = kantin`. Ali sınıfta bulunduğu için sınıfa gitmiş, sınıf okulun içinde olduğu için okula gitmiş, okula gittiğinde de kantinde yer. Cümle `oda` ile verilseydi, oda evin içinde olduğundan Ali eve gitmiş sayılır ve cevap `mutfak` olurdu.

## Dersin Toparlaması

Bu derste anlambilimin kelime, kelime öbeği ve cümle anlamlarını, aralarındaki ilişkileri ve bu ilişkilerin türlerini incelediği; çıkarımın da anlambilimin temel konularından olduğu görüldü. Çıkarım, bir ifadenin doğruluğunu sorgulama ya da verilenden yeni bilgi üretme biçiminde olabilir; sonuçlar kesin ya da yalnızca olası olabilir. Hesaplamalı anlambilim bu işleri otomatikleştirme uğraşıdır ve tarihsel olarak iki okula ayrılır. Formal anlambilim, dili birinci derece mantık, formal gramerler, sonlu durum makineleri ve Prolog kurallarıyla ifade eder. Belirsizlik içermez, ama kuralları elle yazmak zahmetlidir, her cümle formal yapıya çevrilemez ve dünya bilgisi eksik kalır. İstatistiksel anlambilim ise kelimeleri ve cümleleri büyük derlemlerden öğrenilen vektörlerle temsil eder ve bugün en hızlı gelişen taraftır.

Tank anekdotu ve çekişmeli örnekler, istatistiksel modellerin neye bakarak karar verdiğini bilmenin önemini gösterdi. Açıklanabilir yapay zekâ ihtiyacı, formal yaklaşımın ürettiği türden açıklanabilir çıktılara yeniden ilgi doğurdu. Bir sonraki ders, kural tabanlı sistemlerin tökezlediği dünya bilgisi sorununun devamı olan hayat bilgisi veri tabanlarıyla başlayacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
