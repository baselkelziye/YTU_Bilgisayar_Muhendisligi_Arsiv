# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı
  - Ders iki ana bölümden oluşur: önce araçlar ve yöntemler, sonra uygulamalar (ekrandan, 00:56:55).
  - Araçlar ve yöntemler: hayat bilgisi veritabanları, dil modelleri, anlamsal uzaylar, makine öğrenmesinde yeni yaklaşımlar.
  - Makine öğrenmesindeki yeni yaklaşımlar: aktif öğrenme, yarı eğiticili öğrenme, transfer öğrenme, aktif örnekleme, zayıf yönlendirme (weak supervision), planlı öğrenme, hayat boyu öğrenme, çekişmeli eğitim, çok görevli eğitim, az sayıda örnekle eğitim (zero/one/few-shot learning), veri zenginleştirme.
  - Bağlam temelli dil modelleri de işlenecektir. Hoca, günümüzdeki birçok başarılı doğal dil işleme uygulamasının bu modellere dayandığını söyledi.
  - Uygulamalar: metin sınıflandırma, duygudurum analizi, varlık ismi tanıma, paragraf anlama, soru cevaplama, metinlerde çıkarım, sohbet ve sanal asistan uygulamaları, metin/hikâye/şiir üretimi, görsel anlambilim (metin ve görüntü birlikte).
  - Hoca, ChatGPT gibi güncel sistemlerin nasıl çalıştığına da değinmeyi planladığını söyledi.
- Anlambilim (semantik)
  - Tanım: kelimelerin, kelime öbeklerinin, cümlelerin anlamını, aralarındaki ilişkileri ve bu ilişkilerin türlerini konu edinen, dilbiliminin bir alt dalı (ekrandan, 00:30:45).
  - Derste metin tarafı ele alınır; görsel anlambilim gibi başka alanlar da vardır.
- Kelimeler ve cümleler arası ilişkiler
  - Kelime çiftleri arasında farklı türde ilişkiler vardır: büyük-küçük (zıtlık), büyük-iri (belli bağlamlarda eş anlam), pembe-kırmızı (yakın anlam), hayvan-canlı (alt sınıf / üst sınıf), sınıf-tahta (bir şeyin nerede bulunduğu), güldü-gülmedi, güldü-ağladı (ekrandan, 00:31:30).
  - Cümleler arasında da ilişki vardır: "Ali okula gitti. – Ali öğrencidir.", "Sınava çok çalıştım. – Dersi geçtim.", "Bugün ıslanmadım. – Şemsiyem yanımdaydı.", "Bugün okula gitmeyeceğim. – Hastayım." (ekrandan, 00:32:50).
  - Bu ilişkiler, iletişimde ve düşünmede yaptığımız çıkarımların ham maddesidir.
- Çıkarım
  - Elimizdeki verilerden elimizde olmayan bir bilgi üretmektir. Öncüller doğru kabul edilerek hareket edilir.
  - Çıkarım doğru da yanlış da olabilir; çoğu zaman belli bir olasılıkla doğrudur.
  - Zorunlu çıkarım (tümdengelim): öncüller doğruysa sonuç kesin doğrudur. Örnek: "Bütün insanlar ölümlüdür. Sokrat bir insandır. O hâlde Sokrat ölümlüdür."
  - Günlük hayatta en çok kullanılan çıkarımlar zorunlu değildir; daha az kesindirler ama daha çok işe yararlar.
- Hesaplamalı anlambilim (computational semantics)
  - Anlambilimin tüm ilgi alanlarını çeşitli yöntemlerle otomatikleştirme uğraşıdır, yani anlambilimi makinelere yaptırmaktır (ekrandan, 00:37:45).
  - İki temel okul (ekol) vardır: formal anlambilim ve istatistiksel anlambilim.
- Formal anlambilim
  - İnsan dilini mantık cümleleriyle (birinci dereceden mantık) ifade etmeye çalışır.
  - Güçlü yanı: bu yapılabilirse çıkarımlar kolayca, geriye doğru izi sürülebilir ve açıklanabilir biçimde yapılır.
  - Kural tabanlı yaklaşımlar: formal gramerlerle cümle çözümleme, sonlu durum makineleriyle morfolojik çözümleme, Prolog ile çıkarım.
  - Zayıf yanı: dildeki belirsizlik ve kuralların elle yazılması gereği.
- İstatistiksel anlambilim
  - Kuralları insan yazmaz; makineye yeterince veri verilir, kuralları makine öğrenir.
  - Dayandığı ilkeler: bir kelime etrafındaki kelimelerle anlam bulur; sıklıkla birlikte geçen kelimelerin anlamları benzerdir; büyük derlemlere gereksinim duyar (ekrandan, 00:53:20).

## Hocanın Özellikle Vurguladığı Kısımlar

- Metni anlamak için metinde olmayan bilgiyi kullanırız
  - Ali'nin öğle yemeğini nerede yediği sorusu, metinde yazmayan "sınıf okulun içindedir", "birisi bir yerde bulunmuşsa oraya gitmiştir" gibi bilgilerle cevaplanır.
  - Bu bilgiler olmadan, cümleleri formal olarak yazsak bile çıkarım yapılamaz. Hoca bunu bir sonraki dersin konusu olan hayat bilgisi veritabanlarına bağladı.
- Dilde belirsizlik
  - "John saw a man with a telescope" cümlesi iki anlama gelir: John adamı teleskopla mı gördü, yoksa elinde teleskop olan adamı mı gördü?
  - Dil birimleri tek başına ele alındığında anlamları her zaman tekilleştirilemez. Bu belirsizlik kural tabanlı yapıların işini çok zorlaştırır.
- Kural tabanlı sistemlerde asıl zorluk
  - Çıkarım sürecinin kendisi karmaşık değildir. Asıl iş, çıkarımda kullanılacak kuralların oluşturulmasıdır ve bu kısım çok emek ister.
- Kelimenin anlamı bağlama bağlıdır
  - Hoca "bir kelime etrafındaki kelimelerle anlam bulur" ilkesini bir varsayım değil, bir gerçek olarak sundu.
  - "Sıklıkla birlikte geçen kelimelerin anlamları benzerdir" ilkesi ise benzerliğin türünü söylemez; yalnız aralarında bir ilişki olduğunu ifade eder.

## Kısa Tekrar Notları

- Anlambilim = semantik: kelime, kelime öbeği ve cümle anlamlarını ve aralarındaki ilişki türlerini inceleyen dilbilim dalı.
- Kelimeler arası ilişki türleri farklıdır: zıtlık, eş/yakın anlam, alt sınıf-üst sınıf, bulunma yeri vb.
- Çıkarım: eldeki bilgiden olmayan bilgiyi üretmek. Tümdengelim kesin ama az kullanılır; günlük çıkarımlar olasılıklıdır.
- Hesaplamalı anlambilim: anlambilimi makinelere yaptırma uğraşı. İki okul: formal ve istatistiksel.
- Formal: dil mantık formülleriyle yazılır; çıkarım açıklanabilir ve izlenebilir.
  - "Yatakhanede herkesin sevmediği bir oda arkadaşı vardır": $\forall x[D(x) \rightarrow \exists y(R(x,y) \land \neg L(x,y))]$.
- Gramer: bir dilin cümlelerinin nasıl oluşturulduğunu tanımlayan kurallar kümesi. Gramerle cümle çözümleme ağaçları çıkarılır.
- Morfolojik çözümleme: `kalem+ler+im+den` → isim, çoğul eki, şahıs eki, hâl eki.
- Prolog: kural tabanlı çıkarım için kullanılan dillerden biri.
- İstatistiksel: veriden öğrenme; dağılımsal varsayımlar; büyük derlem (metin koleksiyonu) ihtiyacı.
- Derlem örnekleri: Wikipedia sayfalarının metinleri, 100 bin haber metni, forum sitelerinden toplanan soru-cevap ikilileri.

## Detaylı Açıklamalar

- Anlambilim ve ilişkiler
  - Anlambilim yalnız tek tek kelimelerin anlamıyla değil, farklı büyüklükteki metin parçaları (kelime, öbek, cümle, paragraf) arasındaki ilişkilerle de uğraşır.
  - Slayttaki kelime çiftlerinin hepsi birbiriyle ilişkilidir ama ilişkilerin türü aynı değildir. "Büyük-küçük" zıtlığa, "büyük-iri" belli bağlamlarda eş anlama, "pembe-kırmızı" yakın anlama, "hayvan-canlı" alt sınıf-üst sınıf ilişkisine örnektir. "Güldü-gülmedi" ile "güldü-ağladı" da aynı ilişki türünde değildir; hoca, gülmeyen birinin illa ağlamış olmayacağını belirtti. İlişki türleri ilerideki derslerde ayrıntılı ele alınacaktır.
  - Cümleler arasında "öyleyse", "bu sayede", "çünkü" gibi bağlarla kurulabilecek ilişkiler vardır. Örneğin "Ali okula gitti, öyleyse Ali öğrencidir" kurulabilir ama "Ali öğretmendir" de olabilir.
- Çıkarım örnekleri (ekrandan, 00:34:45 ve 00:37:10)
  - "Ali'nin kedisi yok. Sarman bir kedi." öncülleri doğru kabul edildiğinde "Sarman'ın sahibi Ali'dir" sonucu yanlıştır; öncüllerle çelişir.
  - "Ali bugün okula gitmedi." bilgisinden üretilebilecekler: "Ali öğrencidir" (okula her gün giden biri gibi, öğrenci ya da öğretmen olabilir), "Ali hastadır" (mümkün), "Ali yaz tatilindedir" (mümkün), "Ali mutludur" (soru işaretli; örneğin tatildeyse belki). Hiçbiri kesin değildir.
  - "Ali Hoca bugün öğrencilerinin dersteki performansından çok memnun oldu." bilgisinden: "Ali Hoca öğretmendir" (öğrencileri olduğuna göre), "Ali Hoca bugün mutludur", "Ali Hoca'nın öğrencileri çalışkandır".
- Formal anlambilim ve birinci dereceden mantık (ekrandan, 00:38:15 ve 00:41:55)
  - Semboller: $\forall$ "her", $\exists$ "en az bir tane vardır", $\rightarrow$ "ise", $\land$ "ve", $\neg$ "değil".
  - "Yatakhanede herkesin sevmediği bir oda arkadaşı vardır": $\forall x[D(x) \rightarrow \exists y(R(x,y) \land \neg L(x,y))]$. Burada $D(x)$: x yatakhanede yaşar; $R(x,y)$: x ve y oda arkadaşıdır; $L(x,y)$: x, y'yi sever. Okunuşu: yatakhanede yaşayan her x için, x'in oda arkadaşı olan ve x'in sevmediği en az bir y vardır.
  - "Hiç kimse yalancıları sevmez": slaytta $\forall x[S(x) \rightarrow \neg\exists y(L(x,y))]$.
  - Ders sonrası not: Slayttaki formül, $L(x,y)$ "x, y'yi sever" tanımıyla "yalancılar kimseyi sevmez" anlamına gelir. "Hiç kimse yalancıları sevmez" için argümanların yer değiştirmesi gerekir: $\forall x[S(x) \rightarrow \neg\exists y\, L(y,x)]$ ($S(x)$: x yalancıdır; slaytta $S$ tanımlanmamış, anlamı büyük olasılıkla budur). Derste bu fark konuşulmadı.
  - "Herkes en az 2 kişiyi sever": $\forall x \exists y \exists z(L(x,y) \land L(x,z) \land (y \neq z))$. $y \neq z$ koşulu iki kişinin farklı olmasını sağlar.
  - "Tüm evli çiftler kavga eder": $\forall x \forall y(M(x,y) \rightarrow F(x,y))$. $M(x,y)$: x ve y birbiriyle evlidir; $F(x,y)$: x ve y birbiriyle kavga eder.
  - Slaytta "Ali sadece 1 kişiyi sever" cümlesi de vardı; formülü karede okunmuyor ve derste anlatılmadı. <!-- BELİRSİZ: "Ali sadece 1 kişiyi sever" formülü karede kesik (00:41:55). -->
- Cümle çözümleme (ekrandan, 00:42:45)
  - Gramer, bir cümlenin hangi parçalardan, o parçaların da hangi alt parçalardan oluştuğunu tanımlayan kural tabanlı bir yapıdır. Gramere uygun cümleler parçalarına ayrılabilir; Türkçe açısından bu, cümleyi öğelerine (özne, nesne, dolaylı tümleç vb.) ayırmaya benzer.
  - Örnekte SWI-Prolog üzerinde basit bir İngilizce DCG grameri kullanıldı (kaynak: swish.swi-prolog.org/example/grammar.pl). Kuralların bir kısmı:

```prolog
s(s(NP,VP)) --> np(NP, Num), vp(VP, Num).
np(NP, Num) --> pn(NP, Num).
np(np(Det,N), Num) --> det(Det, Num), n(N, Num).
np(np(Det,N,PP), Num) --> det(Det, Num), n(N, Num), pp(PP).
vp(vp(V,NP), Num) --> v(V, Num), np(NP, _).
vp(vp(V,NP,PP), Num) --> v(V, Num), np(NP, _), pp(PP).
pp(pp(P,NP)) --> p(P), np(NP, _).
```

  - Sorgu: `phrase(s(Tree), [john, saw, a, man, with, a, telescope]).` Sistem iki ayrı ağaç üretti: birinde "with a telescope" "a man" isim öbeğine bağlı (adamın teleskobu var), ötekinde fiil öbeğine bağlı (John teleskopla gördü).
  - Bağımlılık çözümleme (dependency parsing) gibi başka çözümleme türleri de vardır.
- Morfolojik çözümleme (ekrandan, 00:45:50)
  - Şekilsel olarak zengin dillerde (Türkçe gibi) kelimelerin morfolojik analizi gerekir. Sonlu durum makineleriyle yapılır; kod dersin sayfasında `turkce_morfoloji.pl` olarak verilmiştir.
  - `morp([kalem,ler,im,den],A).` → `A = [isim, çoğul_eki, şahıs_eki, hal_eki]`.
  - `morp([gel,di,m],A).` → `A = [fiil, zaman_eki, şahıs_eki]`.
  - Kod Türkçenin kelime oluşturma kurallarını (isimden ya da fiilden sonra hangi eklerin gelebileceğini) içerir.
- Prolog ile çıkarım (ekrandan, 00:50:00, 00:50:30, 00:51:40)
  - Bilgiler: "Ali okula gittiğinde öğlen yemeğini kantinde yer. Ali eve gittiğinde öğlen yemeğini mutfakta yer. Ali sınıfta kitap okudu." Soru: "Ali öğlen yemeğini nerede yedi?"
  - Bilinmesi gerekenler: birisi bir yerde bulunmuşsa oraya gitmiştir; birisi bir yere gitmişse o yeri içine alan yere de gitmiştir; sınıf okulun içindedir; oda evin içindedir.
  - Kodda cümleler `vardir(yüklem, özne, belirtili_nesne, dolaylı_tümleç, cümle_no)` yapısında tutulur. `vardir` gerçek bilgileri, `vardir2` türetilen bilgileri ifade eder.

```prolog
kapsar(oda,ev).
kapsar(sinif,okul).
vardir(oku,ali,kitap,sinif,12).
vardir2(git,M,_,Yer,_) :- vardir(_,M,_,Yer,_).
% M Yer'de bulunmuşsa -> M Yer'e gitmiştir
vardir2(F,M,B,Yer1,I) :- kapsar(Yer2,Yer1), vardir2(F,M,B,Yer2,I).
% M Yer2'de birşey yapmışsa ve Yer2 Yer1'i kapsıyorsa -> M Yer1'de de aynı şeyi yapmıştır
vardir2(yer,ali,oglenyemegi,mutfak,_) :- vardir2(git,ali,_,ev,_).
% ali eve gitmişse -> öğlen yemeğini mutfakta yer
vardir2(yer,ali,oglenyemegi,kantin,_) :- vardir2(git,ali,_,okul,_).
% ali okula gitmişse -> öğlen yemeğini kantinde yer
```

  - Sorgu `?- vardir2(yer,ali,oglenyemegi,Nerede,_).` sonucu `Nerede = kantin`. Sistem Ali'nin sınıfta bulunduğunu görüp okulda bulunduğunu, okulda bulunduğuna göre okula gittiğini, okula gittiğine göre yemeğini kantinde yediğini çıkarır.
  - `vardir(oku,ali,kitap,sinif,12).` yerine `vardir(oku,ali,kitap,oda,12).` verilseydi cevap `mutfak` olurdu.
  - Ders sonrası not: Slayttaki ikinci kural "Yer2 Yer1'i kapsıyorsa" diye açıklanır, ama kodda `kapsar(Yer2,Yer1)` "Yer2, Yer1'in içindedir" anlamında kullanılır (`kapsar(sinif,okul)`: sınıf okulun içindedir). Kod doğru çalışır; yorumdaki ifade ters okunmamalıdır.
- İstatistiksel anlambilim
  - Kuralları elle yazmak ya da klasik makine öğrenmesiyle buldurmak yerine, makine yeterli veriyle bu ilişkileri kendisi öğrenir.
  - Birlikte geçme farklı biçimlerde tanımlanabilir: aynı cümlede, aynı paragrafta ya da aynı web sayfasında geçmek gibi.
  - Derlem, metin koleksiyonudur. Kurallar elle konmadığı için büyük ölçekli derlemler gerekir. Bu yöntemlerin nasıl çalıştığı sonraki derslerde ele alınacaktır.
- Dersin amacı ve kazanımları (ekrandan, 00:56:10)
  - Hesaplamalı anlambilimin bilgisayarlı doğal dil işlemedeki önemini bilmek; literatürdeki son gelişmeleri ve açık problemleri bilmek; geliştirilmiş en güncel araçları ve veri kümelerini kullanabilmek; çeşitli uygulama alanlarında uygulama yapabilmek; bilimsel literatüre katkı yapabilecek fikirler üretebilmek.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
