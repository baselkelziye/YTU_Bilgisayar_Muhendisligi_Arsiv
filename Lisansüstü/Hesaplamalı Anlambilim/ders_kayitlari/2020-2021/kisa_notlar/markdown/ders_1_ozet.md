# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin konu akışı
  - Anlambilime ve hesaplamalı anlambilime giriş, hayat bilgisi (dünya bilgisi) veri tabanları, anlamsal uzaylar ve dil modelleri, kelime, deyiş, cümle ve metin temsilleri.
  - Makine öğrenmesinde yeni yaklaşımlar: aktif öğrenme, yarı eğiticili öğrenme, transfer öğrenme, aktif örnekleme, zayıf denetim (weakly supervision), planlı öğrenme, hayat boyu öğrenme, çekişmeli eğitim, çok görevli eğitim, zero/one/few shot learning, veri zenginleştirme (ekrandan, 00:31:10).
  - Bağlam temelli dil modelleri (RNN tabanlı ve transformer tabanlı nöral dil modelleri).
  - Uygulamalar: metin sınıflandırma, duygu durum analizi, NER, paragraf anlama, soru cevaplama, metinlerde çıkarım, bağlam duyarlı hesaplama, diyalog ve üretim uygulamaları.
  - Görsel anlambilim: metin ile görüntünün birlikte kullanıldığı çok kipli öğrenme (multimodal learning).
- Anlambilim (semantik)
  - Kelimelerin, kelime öbeklerinin ve cümlelerin anlamını, aralarındaki ilişkileri ve bu ilişkilerin türlerini inceleyen dilbilim dalı.
  - Kelime öbeği (collocation, phrase): bir araya gelerek parçalarından farklı tek bir anlam kuran kelimeler. Örnek: "Fatih Sultan Mehmet".
  - Kelimeler arası ilişki örnekleri: büyük-küçük, büyük-iri, pembe-kırmızı, hayvan-canlı, sınıf-tahta, güldü-gülmedi, güldü-ağladı (ekrandan, 00:49:20).
  - Cümleler arası ilişki örnekleri: "Ali okula gitti. – Ali öğrencidir.", "Sınava çok çalıştım. – Dersi geçtim.", "Bugün ıslanmadım. – Şemsiyem yanımdaydı.", "Bugün okula gitmeyeceğim. – Hastayım." (ekrandan, 00:49:20).
  - Çıkarım da anlambilimin konusudur.
- Çıkarım türleri
  - Verilen bir ifadenin doğru olup olmadığını sorma: "Ali'nin kedisi yok. Sarman bir kedi." bilgisinden "Sarman'ın sahibi Ali'dir" çıkmaz; tersine "Sarman'ın sahibi Ali değildir" kesin olarak çıkar (ekrandan, 00:52:15).
  - Verilenden yeni bilgi üretme: "Ali bugün okula gitmedi." cümlesinden "Ali öğrencidir", "Ali hastadır", "Ali yaz tatilindedir", "Ali mutludur" gibi olası sonuçlar üretilebilir (ekrandan, 00:52:15).
  - Hoca birincisini geriye doğru (backward), ikincisini ileriye doğru (forward) akıl yürütme diye adlandırdı.
  - Kesin (exact) çıkarım ile yaklaşık ya da olasılıksal (approximate) çıkarım ayrımı.
- Hesaplamalı anlambilim (computational semantics)
  - Anlambilimin bütün ilgi alanlarını çeşitli yöntemlerle otomatikleştirme uğraşı (ekrandan, 00:54:25).
  - İki temel okul: formal anlambilim ve istatistiksel anlambilim. Tarihsel olarak önce formal, sonra istatistiksel yaklaşım gelmiştir; bugünkü gelişmeler en çok istatistiksel tarafta.
- Açıklanabilirlik ve formal yaklaşıma dönüş
  - Yapay sinir ağları kararlarının sebebini açıklayamaz.
  - Tank anekdotu: test başarısı yüksek olan model sahada başarısız oldu, çünkü sınıfları tanklardan değil havanın aydınlığından ayırt etmeyi öğrenmişti.
  - Açıklanabilir yapay zekâ (explainable AI) ve çekişmeli (adversarial) örnekler.
- Formal anlambilim
  - Doğal dil cümlelerinin birinci derece mantıkla yazılması.
  - Kural tabanlı yaklaşımlar: formal gramerlerle cümle çözümleme, sonlu durum makineleriyle morfolojik çözümleme, kurallarla çıkarım.
  - Prolog ile cümle çözümleme, morfolojik çözümleme ve çıkarım örnekleri.
- Uzman sistemler ve kural tabanlı yaklaşımın sınırları
  - Her cümle formal yapıya çevrilemez, kuralları uzmanların elle yazması gerekir ve dünya bilgisi (world knowledge) sisteme aktarılamaz.
- İstatistiksel anlambilim
  - Bir kelime, çevresindeki kelimelerle anlam bulur. Sıklıkla birlikte geçen kelimelerin anlamları benzerdir. Büyük derlemlere gereksinim duyar (ekrandan, 01:35:40).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kelime ve cümle ikilileri arasındaki ilişkilerin türleri aynı değildir
  - Zıt anlam, benzer anlam, bir şeyin bir yerde bulunması, üst kavram-alt kavram gibi farklı ilişki türleri vardır. Anlambilim hem ilişkiyi hem de türünü inceler.
- Çıkarımla elde edilen her şey kesin değildir
  - "Ali okula gitmedi" cümlesinden "Ali öğrencidir" çıkarılabilir ama kesin değildir; okula gitmeyen kişi öğretmen ya da başka biri de olabilir.
- Modelin neye bakarak karar verdiğini bilmek önemlidir
  - Tank örneğinde eğitim/test bölmesinde, etiketlerde ya da çapraz doğrulamada hata yoktu. Sorun, sınıfların veri toplama koşullarıyla (hava açık/kapalı) karışmasıydı.
  - Karar ağacı gibi yorumlanabilir bir model kullanılsaydı modelin resmin üst kısmının rengine baktığı fark edilebilirdi.
  - "Makineye ne yapmasını istediğimizi söyleyebiliriz, nasıl yapacağını söyleyemeyiz." Nasıl yapılacağını bilseydik kuralı kodlardık, makine öğrenmesine gerek kalmazdı.
- Son kullanıcı ile geliştirici bakışı farklıdır
  - Geliştirici için yorumlanabilirlik hatayı bulmayı sağlar. Son kullanıcı için soru, açıklama yapan ama daha düşük başarılı bir sistem ile açıklamayan ama daha başarılı bir sistem arasında seçimdir.
- Eklemeli dillerde alt kelime (subword) parçalaması
  - "geldim" ile "geldik" bütün olarak verilirse ortak bir şeyleri yokmuş gibi görünür. Parçalara ayrılırsa ortak kök görülür. Türkçe gibi eklemeli dillerde bu çok faydalıdır; İngilizcede daha çok nadir kelimeler için kullanılır.
- Dünya bilgisi sorunu hâlâ sürüyor
  - Böbreklerdeki bakteriye "böbrekleri 150 dereceye ısıtın" diyen tedavi sistemi hikâyesi, makinenin dünyanın nasıl işlediğini bilmediğini gösterir.
- General AI hâlâ ufukta değil
  - Belirli bir problemi çözen sistemlerde (satranç, görüntü tanıma) büyük ilerleme var. Her problemi çözen genel sistemler eskiden de ütopyaydı, bugün de öyle.

## Kısa Tekrar Notları

- Anlambilim: kelime, kelime öbeği ve cümle anlamları, aralarındaki ilişkiler ve ilişki türleri; ayrıca çıkarım.
- Hesaplamalı anlambilim: anlambilimde yapılabilenleri bilgisayara yaptırma uğraşı.
- İki okul: formal (önce gelen, mantık ve kural tabanlı) ve istatistiksel (vektörler, büyük derlemler, bugünkü gelişmelerin merkezi).
- Çıkarım: doğruluğu sorulan ifade (backward) ya da yeni bilgi üretme (forward); kesin (exact) ya da yaklaşık (approximate).
- Formal gösterim örneği: $\forall x\,[D(x) \rightarrow \exists y\,(R(x,y) \land \neg L(x,y))]$ "Yatakhanede herkesin sevmediği bir oda arkadaşı vardır."
- Kural tabanlı araçlar: formal gramer (Prolog DCG), sonlu durum makinesiyle morfoloji (`morp([kalem,ler,im,den],A)`), Prolog kurallarıyla çıkarım.
- Alt kelime algoritmaları: BPE (Byte Pair Encoding), WordPiece, SentencePiece.
- Kural tabanlı sistemlerin sınırları: uzman emeği, her durumu kapsayamama, dünya bilgisinin eksikliği.
- İstatistiksel anlambilimin dayanağı: kelime, çevresindeki kelimelerle anlam bulur; birlikte geçen kelimeler benzer anlamlıdır.
- Derlem: etiketlenmemiş, toplanmış büyük metin (haber, köşe yazısı, film altyazısı derlemi).
- Açıklanabilir yapay zekâ, formal anlambilimin bugün yeniden önem kazanmasının bir sebebidir.

## Detaylı Açıklamalar

### Anlambilim ve ilişki türleri

Anlambilim (semantik), kelimelerin, kelime öbeklerinin ve cümlelerin anlamını, aralarındaki ilişkileri ve bu ilişkilerin türlerini konu edinen dilbilim dalıdır. Kelime öbeği, tek tek kelimelerin anlamından farklı bir kavramı ifade etmek için bir araya gelen kelimelerdir; İngilizcede collocation ya da phrase diye geçer. "Fatih Sultan Mehmet" buna örnektir.

Slayttaki kelime ikililerinin her birinde bir ilişki vardır ama ilişkilerin türleri farklıdır: zıt anlamlılar, benzer anlamlılar, bir şeyin bir yerde bulunmasıyla ilgili olanlar, üst kavram-alt kavram ilişkisi gibi. Cümle ikililerinde de aynı durum vardır. Örneğin "Sınava çok çalıştım. – Dersi geçtim." ile "Bugün okula gitmeyeceğim. – Hastayım." ikililerindeki ilişkiler aynı türden değildir. Bu ilişkileri ve türlerini bulmak, ayrıca çıkarım yapmak anlambilimin temel konularıdır.

### Çıkarım

Mantıkta bize doğru olduğu söylenen önermeler verilir. Bunlardan iki tür iş yapılabilir:

- Sorulan bir ifadenin doğru olup olmadığına karar vermek. "Ali'nin kedisi yok. Sarman bir kedi." verildiğinde "Sarman'ın sahibi Ali'dir" çıkarılamaz. Tersi, yani "Sarman'ın sahibi Ali değildir", kesin olarak doğrudur. Bu kesin (exact) akıl yürütmeye örnektir.
- Verilenden yeni bilgiler üretmek. "Ali bugün okula gitmedi." cümlesinden "Ali öğrencidir", "Ali hastadır", "Ali yaz tatilindedir", "Ali mutludur" gibi sonuçlar üretilebilir. Bunların hiçbiri kesin doğru ya da kesin yanlış değildir, yalnızca olasıdır. Bu, yaklaşık ya da olasılıksal (approximate) akıl yürütmedir.

Hoca birinci türü geriye doğru zincirleme (backward reasoning), ikinci türü ileriye doğru zincirleme (forward reasoning) diye adlandırdı. Slaytta benzer bir örnek daha vardı: "Ali Hoca bugün öğrencilerinin dersteki performansından çok memnun oldu." cümlesinden de birçok olası sonuç üretilebilir (ekrandan, 00:52:15).

### Hesaplamalı anlambilim ve iki okul

Hesaplamalı anlambilim (computational semantics), anlambilimin bütün ilgi alanlarını çeşitli yöntemlerle otomatikleştirme uğraşıdır. Tarihçede iki temel okul vardır: formal anlambilim ve istatistiksel anlambilim. Bu okullar birbirinden tamamen ayrık değildir, birbirinden çok şey öğrenir. Önce formal yaklaşım çıkmış, belli başarılardan sonra tıkanmış, ardından istatistiksel yaklaşıma geçilmiştir. Bugün en yoğun gelişme istatistiksel taraftadır. Ancak son zamanlarda, açıklanabilirlik ihtiyacı nedeniyle formal yaklaşımın ürettiği türden çıktılara yeniden ilgi doğmuştur.

### Açıklanabilirlik tartışması

Yapay sinir ağlarının temel sorunlarından biri, verdikleri kararların sebebini açıklayamamalarıdır. Hoca, Hinton'a atfettiği bir soruyu sordu: Tanı koyan iki tıbbi sistem olsun. Birincisi kararının gerekçesini açıklıyor ve başarısı %60. İkincisi açıklamıyor ama başarısı %70. Hangisini tercih edersiniz? Derste bazı öğrenciler başarılı olanı seçti, bazıları açıklama yapanı. Bir öğrenci de geliştirme sürecinde yorumlanabilirliğin hatayı bulmak için önemli olduğunu söyledi. Hoca bunun doğru olduğunu, ama sorunun son kullanıcı bakışıyla sorulduğunu belirtti. İnsan ilişkilerinde gerekçesiz bir kararın tatmin etmediği örneğini verdi: süreçler insan için önemlidir. Hastalık teşhisinde ise performansa güvenmek mantıklı olabilir.

Tank anekdotu: Tankların önündeki kameralardan gelen görüntülerle dost ve düşman tanklarını ayıran bir sistem geliştirilir. Veri arazide toplanır, rastgele eğitim ve test kümelerine bölünür. Test başarısı %95 civarındadır, çapraz doğrulama ve doğrulama kümesi de sorunsuzdur. Sahada ise başarı %50'ye iner. Sebep: düşman resimleri hava açıkken, dost resimleri hava kapalıyken çekilmiştir. Model tankları değil ışık miktarını ayırt etmeyi öğrenmiştir. Hava açıkken herkese "düşman", kapalıyken herkese "dost" der. Karar ağacı gibi kararının nedeni okunabilen bir model kullanılsaydı, modelin resmin üst kısmının rengine baktığı görülebilirdi.

Bu anekdotun dersi şudur: Makine öğrenmesini, problemi nasıl çözeceğimizi açıkça kodlayamadığımız durumlarda kullanırız. Bu yüzden modelin neye bakacağına ve neye önem vereceğine çok az müdahale edebiliriz. Kararın nasıl verildiğini açıklayan bir şey olsaydı, süreçteki hata fark edilebilirdi. Açıklanabilir yapay zekâ (explainable AI) bu ihtiyaçtan doğmuştur. Çekişmeli (adversarial) örnekler de istatistiksel yöntemlerin bir zayıflığıdır: bir maymun resminde özel seçilmiş 3-5 piksel değiştirildiğinde model resme "ağaç" ya da istenen herhangi bir etiketi verebilir.

### Formal anlambilim: mantıkla gösterim

Formal anlambilimin sorusu, insan dilinin formal bir dil olarak ifade edilip edilemeyeceğidir. Slayttaki örnekler (ekrandan, 01:15:15 ve 01:16:20):

- "Yatakhanede herkesin sevmediği bir oda arkadaşı vardır": $\forall x\,[D(x) \rightarrow \exists y\,(R(x,y) \land \neg L(x,y))]$. Burada $D(x)$: x yatakhanede yaşar, $R(x,y)$: x ve y oda arkadaşıdır, $L(x,y)$: x, y'yi sever.
- "Hiç kimse yalancıları sevmez": $\forall x\,[S(x) \rightarrow \neg \exists y\,(L(x,y))]$ (slayttaki hâliyle).
- "Herkes en az 2 kişiyi sever": $\forall x\,\exists y\,\exists z\,(L(x,y) \land L(x,z) \land (y \neq z))$.
- "Tüm evli çiftler kavga eder": $\forall x\,\forall y\,(M(x,y) \rightarrow F(x,y))$. $M(x,y)$: x ve y birbiriyle evlidir, $F(x,y)$: x ve y birbiriyle kavga eder.
- "Ali sadece 1 kişiyi sever." <!-- BELİRSİZ: Bu cümlenin formülü karede kesik kaldı, hoca da üzerinde durmadı. -->

- Ders sonrası not: Slaytta $S(x)$ tanımlanmamış. $S(x)$ "x yalancıdır" ise, "hiç kimse x'i sevmez" demek için büyük olasılıkla $\neg \exists y\,L(y,x)$ yazılmalıdır. Slayttaki $L(x,y)$ sırası "yalancılar kimseyi sevmez" anlamına gelir.

### Kural tabanlı yaklaşımlar

Formal anlambilimdeki kural tabanlı yaklaşımların temel işleri formal gramerlerle cümle çözümleme, sonlu durum makineleriyle kelimelerin morfolojik çözümlemesi ve çıkarımdır.

Cümle çözümlemede, kodu yazan kişi dilin dilbilgisini kurallarla verir: bir cümle hangi öğelerden oluşur, o öğeler hangi alt öğelerden oluşur, en altta hangi kelimeler gelebilir. Her cümle için ayrı kural yazılmaz; genel kurallardan cümleye uygun hiyerarşik yapı bulunur. Derste SWISH (çevrimiçi Prolog) üzerindeki basit bir İngilizce DCG grameri gösterildi. `phrase(s(Tree), [john, saw, a, man, with, a, telescope])` sorgusu ekranda iki farklı ağaç verdi: "with a telescope" öbeği bir ağaçta "man"e, diğerinde "saw" fiiline bağlanıyordu (ekrandan, 01:17:40).

Morfolojik çözümleme, cümle çözümlemenin kelimeye uyarlanmış hâlidir; kelimenin morfemlerini bulur (ekrandan, 01:19:10):

```prolog
?- morp([kalem,ler,im,den], A).
A = [isim, çoğul_eki, şahıs_eki, hal_eki]

?- morp([gel,di,m], A).
A = [fiil, zaman_eki, şahıs_eki]
```

Bu kodda kelimenin parçaları önceden ayrılmış olarak verilir. Daha gelişmiş bir yöntem "geldim" kelimesini kendisi "gel, di, m" diye bölmelidir. Bunun için BPE (Byte Pair Encoding), WordPiece ve SentencePiece gibi algoritmalar vardır. Bu algoritmalar bir kelimenin o dile göre en olası nasıl parçalanacağını bulur ve bugün nöral dil modellerinde kelimeler bu tür parçalara (token) ayrılarak verilir.

### Prolog ile çıkarım örneği

Bilgiler: "Ali okula gittiğinde öğle yemeğini kantinde yer. Ali eve gittiğinde öğle yemeğini mutfakta yer. Ali sınıfta kitap okudu." Soru: "Ali öğle yemeğini nerede yedi?" Cevap için şu bilgiler de gerekir: birisi bir yerde bulunmuşsa oraya gitmiştir; birisi bir yere gitmişse o yeri içine alan yere de gitmiştir; sınıf okulun içindedir; oda evin içindedir. Çıkarım zinciri: Ali sınıfta bulundu → sınıfa gitti → sınıf okulun içinde olduğu için okula gitti → okula gittiğinde kantinde yer → öğle yemeğini kantinde yedi.

Kodda cümleler `vardir(yüklem, özne, belirtilinesne, dolaylıtümleç, cümleno)` yapısında tutulur (ekrandan, 01:27:15):

```prolog
kapsar(oda,ev).
kapsar(sinif,okul).
vardir(oku,ali,kitap,sinif,12).
vardir2(git,M,_,Yer,_) :- vardir(_,M,_,Yer,_).
    % M Yer'de bulunmussa -> M Yer'e gitmistir
vardir2(F,M,B,Yer1,I) :- kapsar(Yer2,Yer1), vardir2(F,M,B,Yer2,I).
    % M Yer2'de birsey yapmissa ve Yer2 yer1'i kapsiyorsa -> M Yer1'de de ayni seyi yapmistir
vardir2(yer,ali,oglenyemegi,mutfak,_) :- vardir2(git,ali,_,ev,_).
    % ali eve gitmisse -> oglenyemegini mutfakta yer
vardir2(yer,ali,oglenyemegi,kantin,_) :- vardir2(git,ali,_,okul,_).
    % ali okula gitmisse -> oglenyemegini kantinde yer
```

`vardir` gerçek cümleleri (bilgileri), `vardir2` türetilen cümleleri ifade eder. `?- vardir2(yer,ali,oglenyemegi,Nerede,_).` sorgusu `Nerede = kantin` döndürür. Gerçek cümle `vardir(oku,ali,kitap,oda,12)` olsaydı cevap `mutfak` olurdu (ekrandan, 01:29:00). Bu iki sonuç, kuralların Python ile yazılmış küçük bir ileri zincirleme benzetimiyle de doğrulandı (Prolog derste çalıştırıldı; ajan Prolog çalıştırmadı).

- Ders sonrası not: Hoca çıkarımı anlatırken "sınıf okulun içindedir, o da evin içindedir" dedi; slayttaki bilgi "oda evin içindedir"dir.
- Ders sonrası not: `kapsar(sinif,okul)` gerçeği "sınıf okulun içindedir" anlamında kullanılıyor; bu yüzden ikinci kuraldaki `kapsar(Yer2,Yer1)` "Yer2, Yer1'in içindedir" demektir. Slayttaki "Yer2 yer1'i kapsıyorsa" yorumu bu yönü ters söylüyor.

### Uzman sistemler ve kural tabanlı yaklaşımın sınırları

Yapay zekâ tarihi dalgalıdır. Bilgisayarların ortaya çıkışıyla büyük beklentiler doğmuş, 1960'lara kadar süren bu beklentiler gerçekleşmeyince bir çöküş yaşanmıştır. Yeni çıkışı, kural tabanlı klasik uzman sistemler sağlamıştır. Uzman sistem, belirli bir problemi çözmek için tasarlanmış sistemdir; hastalık teşhisi ve planlama sistemleri bunlara örnektir. Her türlü problemi çözen genel sistemler (general AI) ise eskiden de ütopyaydı, bugün de ütopyadır.

Kural tabanlı sistemlerin sınırları zamanla görüldü: her doğal dil cümlesi formal yapıya dönüştürülemiyor, her yeni uzman sistem için kuralların uzmanlarca elle yazılması gerekiyor ve kurallar her durumu kapsayamıyor. Böbreklerdeki bakteriyi öldürmek için "böbrekleri 150 dereceye ısıtın" öneren tedavi sistemi hikâyesi, sistemin dünyanın nasıl işlediğine dair bilgiden (world knowledge) yoksun olduğunu gösterir. Bu sorun bugün de sürmektedir ve sonraki konu olan hayat bilgisi veri tabanlarının çıkış noktasıdır.

### İstatistiksel anlambilim

Kural tabanlı sistemler doyuma ulaşınca istatistiksel yaklaşım öne çıktı. Bu yaklaşımda kural yazılmaz; kelimeler, ilişkiler, kavramlar ve cümleler vektörlere dönüştürülür. İki temel hipoteze dayanır: bir kelime çevresindeki kelimelerle anlam bulur ve sıklıkla birlikte geçen kelimelerin anlamları benzerdir. Bu yaklaşım büyük derlemlere ihtiyaç duyar. Derlem, toplanmış ve etiketlenmemiş metinlerdir: bir gazetenin bir yıllık bütün haberleri (haber derlemi), köşe yazarlarının yazıları (köşe yazısı derlemi) ya da film altyazıları (altyazı derlemi) gibi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
