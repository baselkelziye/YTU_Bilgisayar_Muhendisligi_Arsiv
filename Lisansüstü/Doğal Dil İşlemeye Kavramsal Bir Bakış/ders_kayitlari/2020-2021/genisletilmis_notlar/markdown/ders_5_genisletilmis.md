# Ders 5 Genişletilmiş Notu: Sentaktik Analiz, Ağaç Derlemleri ve Dil Modellerine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Morfolojik Analizden Sentaktik Analize
- 2. Sentaktik Analizin Tanımı ve Amaçları
- 3. Kelime Türleri ve Durak Kelimeler
- 4. Diller Arasında Söz Dizimi Farkı
- 5. Sözcük Türü Etiketleri
- 6. Türkçe ile İngilizcenin Söz Dizimi Farkları
- 7. Sentaktik Analizin Problemleri
- 8. Çözümleme Yaklaşımları ve Bağlamdan Bağımsız Dilbilgisi
- 9. Olasılık Tabanlı Çözümleme
- 10. Bağlılık Ayrıştırması
- 11. Türkçede Tümce Türleri ve Öğelere Ayırma
- 12. Ağaç Derlemi ve Sözlükler
- 13. Yukarıdan Aşağı Ayrıştırma
- 14. Aşağıdan Yukarı Ayrıştırma
- 15. Genişletilmiş Geçiş Ağları
- 16. Baştan Sona Bir Örnek ve Soru Cevaplama
- 17. Dil Modellerine Giriş
- 18. Lemma ve Kök
- 19. Dil Modellerinin Kullanım Alanları
- 20. Shannon Oyunu ve N-Gram Fikri
- 21. Harf Dizilerinde Yaklaşım Dereceleri
- 22. Romance Dillerinde Hece Örtüşmesi
- 23. Zipf Yasası
- 24. Cümle Olasılığı ve N-Gram Modeli

## 1. Morfolojik Analizden Sentaktik Analize

Hoca derse şimdiye kadar görülenlerin kısa bir tekrarıyla başladı. Morfolojik analiz (biçim bilimsel analiz) bu derste öğrencilerin yazacağı bir şey değildir. Dersin belirli bir noktasından sonraki konsepti, var olan araçları kullanmaktır.

Morfolojik analiz şunu yapar: bir metin verilir, metin token'lara, yani kelimelere ayrılır. Sonra kelimeler kök ve eklerine ayrılır. Eklerin hangi ekler olduğu da bildirilir. Bu çıktı sentaktik analizin girdisidir. Çünkü sentaktik analiz yapabilmek için kelimelerin etiketlenmiş olması gerekir.

Morfolojik analizin bir sınırı vardır. Bir kelime için birden fazla çözüm üretebilir ve hangisinin doğru olduğunu söyleyemez. Hoca her zamanki örneğini verdi: "gül" hem isim hem fiil olabilir. Bu karışık duruma belirsizlik (ambiguity) denir. Doğru çözüme bağlama (context) bakılarak karar verilir. Pratikte iki çözüm de bir ağaç derleminde yürütülür ve cümle hangisiyle ağaca oturuyorsa o çözüm doğru kabul edilir. Morfolojik analiz bunu tek başına veremez. Bu belirsizlik giderme işi söz dizimsel analizde yapılabilir.

Hoca terim konusunda da bir not düştü. Bu derste "tümce" ile "cümle", "sözcük" ile "kelime" aynı anlamdadır. Kendisi eski alışkanlıkla cümle ve kelime diyor, kaynaklarda tümce ve sözcük geçiyor.

## 2. Sentaktik Analizin Tanımı ve Amaçları

Söz dizimsel analiz (syntactic analysis), söz dizimini oluşturan morfolojik öğelerin hiyerarşik kurallara uyumunu çözümlemektir. Buradaki hiyerarşik kurallar, dil ve gramer konusunda görülen tür 0'dan tür 3'e kadar olan dil türlerinden gelir. O konuda bir başlangıç sembolü $S$ ve türetme kuralları $P$ vardı. Örneklerde hep $A$, $B$ gibi soyut semboller kullanılmıştı. Gerçek dünyada bu sembollerin yerine nesne, tümleç, ön ad, isim öbeği, fiil öbeği gibi dilbilgisi öğeleri gelir.

Çözümleme de aynı mantıkla yürür. Elde bir dizgi vardır, bu dizgi aslında tümcedir. Dizgi türetme kuralları üzerinden geçirilir ve bütün tümce oturtulmaya çalışılır. Çözümlemenin sonunda her şey uç değişkenlere ($V_T$) iner. Sentaktik analizde uç değişkenler, kelimelerin çözümlenmiş hâlleridir. Kelimeler ilerletilen ağacın yapraklarına oturur. Ağaç dışında başka gösterimler de vardır.

Sentaktik analize şu nedenlerle ihtiyaç duyulur:

- Anlamsal analize (semantic analysis) girdi sağlar.
- Kelimelerdeki belirsizlikleri çözer.
- Bir cümlenin o dile ait olup olmadığına karar verir.
- Cümleyi öğelerine ayırmaya yardımcı olur.

Üçüncü maddeyi hoca şöyle açtı. Morfolojik analizden geçmiş rastgele kelimeler yan yana getirilebilir. İnsan bunun anlamlı bir cümle olmadığını bilir. Bilgisayar ise bunu da tümce sanabilir. Bu yüzden bilgisayara dilin söz dizimi yapısı verilmelidir. Bu işte otomatlar, ağaç yapıları ya da başka modeller kullanılabilir.

<!-- BELİRSİZ: 00:12:07'de hocanın gösterdiği rastgele kelime dizisi slaytta kaldı, altyazıda okunmuyor. -->

## 3. Kelime Türleri ve Durak Kelimeler

Bir cümleyi oluşturan kelimelerin türleri vardır. Hoca bunları İngilizce karşılıklarıyla verdi, çünkü etiketler bu adlardan türer:

| Tür | İngilizce | Not |
|---|---|---|
| İsim | noun | |
| Belirleyici | determiner | İngilizcede "the", "a", "an". Türkçede yok. "Bir kitap" ifadesindeki "bir" belirleyici gibi düşünülebilir. |
| Sıfat | adjective | |
| Fiil | verb | |
| Zarf ya da belirteç | adverb | İki Türkçe ad da kullanılır. |
| Edat ya da ilgeç | preposition | |
| Bağlaç | conjunction | |

Hoca sonra metin üzerinde çalışırken ortaya çıkan bir soruna geçti. Metinler üzerinde sınıflandırma (classification) ya da kümeleme (clustering) yapmak ya da doküman ve cümlelerin vektörlerini çıkarmak isteyelim. Her kelimeyi kullanmak çok maliyetlidir. Üstelik bazı kelimelerin yapılan işe katkısı yoktur.

**Durak kelimeler (stop words).** Türkçede durak kelimeler ya da fonksiyonel kelimeler de denir. Tanımı şudur: tek başına kullanıldığında bir anlam ifade etmeyen, cümle içinde geçtiğinde cümlenin anlamına katkı sağlayan kelimeler. Bunların önemi uygulamaya göre değişir. Yazar tanıma (authorship) çalışmasında bir yazar bu kelimeleri belirli biçimde kullanıyorsa ayırt edici olabilirler. Konu ya da tür belirleme yapılıyorsa genelde bir anlamları yoktur.

Hoca İngilizce bir derlemden çıkarılmış sıklıkları gösterdi. "of" yaklaşık 540 bin, "in" yaklaşık 331 bin kez geçiyor.

> **Hocanın vurgusu:** Bir kelimenin çok sık geçmesi onun önemli olduğu anlamına gelmez. "of" ve "in" çok sık geçer ama bir anlam ifade etmez. Metin madenciliğinde (text mining) ön işleme (preprocessing) sırasında bu kelimeler çıkarılır.

Aynı durum diğer kelime gruplarında da görülür. Zamirlerden "it", "I", "he", "you" çok sık geçer. "it" ve "I" bütün dokümanlarda geçtiği için ayırt edici değildir. Bunları cümle vektörüne özellik olarak koymak boşuna bir özellik kullanmak demektir. Bağlaçlardan "and", "that", "but" da böyledir.

Yardımcı fiil listesi hocayı şaşırtmış. Hoca "have", "do", "am", "is" gibi yardımcı fiillerin daha sık kullanıldığını düşünüyordu. Tabloda ise "can", "may", "will", "should" gibi kip fiilleri (modal) daha sık çıkmış.

Listede "have" soru işaretiyle verilmiş. Nedeni, "have" kelimesinin hem yardımcı fiil hem asıl fiil olabilmesidir. Listeyi hazırlayanlar hangisi olduğunu bilemedikleri için sayıyı kesin vermemişler. Bir çözüm önerisi şudur: "have" bir zamirden ya da özneden sonra geliyorsa yardımcı fiil olarak alınabilir. Yalnızca terim frekansı (term frequency, TF) sayılır ve böyle bir kontrol yapılmazsa önemli bir bilgi kaçabilir.

## 4. Diller Arasında Söz Dizimi Farkı

Slaytta "O kalemini tek silahı olarak görür" anlamında bir cümle Türkçe, Japonca, Korece, Fince, Çince ve İngilizce olarak verildi. Soldaki üç dilde (Türkçe, Japonca, Korece) fiil sondadır. Aralarda küçük farklar olsa da yapı benzerdir. Sağdaki üç dilde (Fince, Çince, İngilizce) fiil ortada yer alır. Hoca bu gruba Almanca ve Fransızcanın da eklenebileceğini söyledi.

Hoca bu benzerliği dil aileleriyle açıkladı. Soldakileri sondan eklemeli ve aynı aileden diller olarak anlattı. Aynı aileden olmanın iki pratik yararı vardır:

- Bir dilin sentaktik analiz kodu alınıp küçük değişikliklerle diğerine uyarlanabilir.
- Aralarındaki makine çevirisi daha başarılı olur. Hoca bunun derin öğrenme öncesi için geçerli olduğunu belirtti. İngilizceden Almancaya çevirinin İngilizceden Türkçeye çeviriden başarılı olmasının nedeni budur.

Cümleler özne, nesne, tümleç ve yüklemden oluşur, ama sıralamaları dile göre değişir. Türkçedeki kural özne, nesne, tümleç, yüklemdir. Yüklem başa gelirse buna devrik cümle denir. Finceye gelince sıra özne, yüklem, nesne, tümleç olarak verildi.

<!-- BELİRSİZ: İngilizce ve Çince için slaytta yazan öğe sıraları altyazıda söylenmiyor. -->

Bir dilin sentaktik yapısı çıkarılırken o dildeki cümle yapıları belirlenir. Bu yapılara uygun ağaçlar oluşturulur ve bir ağaç derlemi kurulur. Bir cümle geldiğinde derlemdeki ağaçlardan biri üzerinde ayrıştırılır. Hangi ağacın kullanılacağı konusunda çeşitli yöntemler vardır. En çok kullanılanı kural tabanlı olan bağlamdan bağımsız dilbilgisidir. Bunun dışında istatistik tabanlı yöntemler de vardır.

## 5. Sözcük Türü Etiketleri

Morfolojik analiz kelimenin kökünü ve ekini verirken bunlara etiket de koymalıdır. Sentaktik analiz bu etiketler üzerinden yapılır. Bu etiketlere sözcük türü etiketleri (part of speech, POS) denir. Hoca POS kavramını, bir dokümanda anlamı olan en küçük birim olarak gördüğü kelimeyle ilişkilendirdi: her kelimeye bir etiket atanır.

Etiketleri kimse kafasına göre atamaz. İngilizce için geliştirilmiş etiket kümeleri vardır: Penn Treebank ve Brown. Türkçe çalışmalarda da bu kümeler kullanılır. Ancak İngilizcede olup Türkçede olmayan, Türkçede olup İngilizcede olmayan türler bulunduğu için bazı eksiklikler oluşur. Hangi morfolojik aracı kullanırsanız kullanın (örneğin Porter stemmer), etiketler bu kümelere benzer biçimde verilir. Küçük farklar çoğunlukla Penn Treebank'tan gelir.

> **Hocanın vurgusu:** Bu etiketlerin hepsini ezberlemek gerekmez. Baktıkça göz alışır. Takılınca tabloya bakılır.

Hoca tabloyu etiketlerin nasıl türetildiğini göstererek anlattı:

| Etiket | Anlamı | Türetilme mantığı |
|---|---|---|
| CC | Sıralama bağlacı | coordinating conjunction |
| JJ | Sıfat | adjective |
| JJR | Karşılaştırma hâlindeki sıfat | sona R (comparative) |
| JJS | Üstünlük hâlindeki sıfat | sona S (superlative) |
| MD | Kip fiili | modal |
| NN | Tekil isim | noun, yalın hâl |
| NNS | Çoğul isim | sona S |
| NNP | Tekil özel isim | sona P (proper) |
| NNPS | Çoğul özel isim | P'nin sonuna S |
| POS | Kesme işaretiyle ayrılan 's | possessive |
| VB | Fiil, yalın hâl | verb |
| VBD | Geçmiş zaman | sona D |
| VBG | -ing hâli | sona G |
| VBN | Üçüncü hâl | sona N |
| VBZ | Üçüncü tekil şahıs | sona Z |

Zamirlerin etiketi hoca tarafından PP olarak gösterildi. "Benimki", "seninki" gibi sahiplik bildirenlere bir S eklenir. Noktalama gibi özel işaretler için bile etiketler çıkarılmıştır.

Bu etiketler önceki derslerdeki gramerlerle şöyle bağlanır. Önceden "S, büyük A ve küçük a'dan oluşur" gibi kurallar yazılıyordu. Artık sembollerin yerine etiketler gelir. Hoca rastgele iki örnek verdi: bir cümle NN ve onu izleyen bir RP'den oluşabilir ya da VP ve onu izleyen JJ'den oluşabilir. Bir dilin cümle yapılarından çıkarılan bu kurallar o dilin ağaç derlemini oluşturur. Her dilin kendine özgü bir ağaç derlemi vardır.

**Türk dilleri için etiket kümesi.** Türkçe ve aynı aileden diller için ayrı bir etiket kümesi de geliştirilmiştir. Slaytta birinci sütun Türkçe, sonraki sütunlar Tatarca, Mişerce, Başkurtça, Kazakça gibi dillerdir. Örneğin yönelme eki (dative) için etiket vardır. İngilizcede bu tür ekler yoktur, aynı işi başka yapılar görür. Sayılar, kişiler, zamanlar ve soru ekleri için de etiketler vardır.

Hocanın gözlemi şudur: Türkçe çalışmalarda bile bu etiketler pek kullanılmıyor, İngilizce etiketler tercih ediliyor. Brown kümesinde eksik bir etiket varsa araştırmacı kendi etiketini ekliyor.

## 6. Türkçe ile İngilizcenin Söz Dizimi Farkları

Hoca iki dil arasındaki farkları sıraladı:

- İngilizcede "the", "a", "an" vardır. Türkçede yoktur, "bir" bu işi görebilir.
- İngilizcede ön edatlar ("of", "in", "by") vardır. Türkçede böyle bir yapı yoktur.
- İngilizcede karşılaştırma ve üstünlük "-er", "-est" gibi eklerle yapılır. Türkçede sıfatın önüne ayrı kelime konur: "büyük top", "çok büyük top", "daha büyük top", "kocaman top". Zarflarda da böyledir: "hızlı", "daha hızlı", "çok hızlı".
- İngilizcede "up", "off" gibi fiil parçacıkları vardır. Türkçede yoktur.
- Türkçe fiiller kurallıdır ama içinde hem kişi hem zaman bilgisi taşır. "Okuyor" kelimesinde hem "o" kişisi hem zaman bilgisi vardır. İngilizcede "play" ya da "read" denince iş biter. Bu yüzden Türkçe fiili çözümlemek çok daha zor ve karmaşıktır.
- Türkçe eklemeli bir dildir. Yapım eki çoktur, İngilizcede azdır. Bir kökten yapım ekleriyle çok farklı kelimeler türetilebilir.

**Serbest sıralı söz dizimi (free word order).** Türkçeyi İngilizceden ayıran en önemli özellik budur. Kelimelerin yerleri değiştirilebilir ve anlam bozulmaz:

- "Ben kıza çiçek verdim."
- "Kıza çiçeği ben verdim."
- "Ben çiçeği kıza verdim."
- "Çiçeği kıza ben verdim."
- "Kıza ben verdim çiçeği."

Ortada bir kız ve bir çiçek vardır, veren de "ben"dir. Yüklem sonda ya da ortada olabilir, özne ve nesne yer değiştirebilir, ama anlam aynı kalır. Bu yüzden Türkçenin sentaktik yapısı daha zordur. Yalnız bu cümle için bile beş farklı ağaç gerekir.

İngilizcede ise sıra çok kısıtlıdır. Hoca "She saw him" cümlesini büyüttü: "she" yerine "the woman", sonra "the tall woman" geldi, "him" yerine "the man", "the fat man", "the fat man with red beard" geldi. Öbekler büyüyebilir ama yerleri değiştirilemez. "She the man saw" gibi bir dizilim yapılamaz.

Türkçede de yer değiştirmenin anlamı bozduğu durumlar vardır:

- "Sınavı zor yetiştirdim": süre yetmemiştir, sınav zorlukla yetiştirilmiştir. "zor" fiili niteler, zarftır.
- "Zor sınavı yetiştirdim": soruların içeriği zordur. "zor" ismi niteler, sıfattır.

Her cümle yapısını çözecek ağaç derlemde bulunmalıdır. Yapılar ikili, üçlü, dörtlü olabilir. Özne ile yüklem arasına birçok şey girebilir. Kurallı cümlede yüklem sondayken devrik cümlede başa gelebilir. Özne gizli olabilir ya da cümlenin başında olmayabilir.

## 7. Sentaktik Analizin Problemleri

**Bir kelime birden fazla sınıfa girebilir.** İngilizcede "this" kelimesi buna örnektir:

- "This is a nice day.": zamir.
- "This day is nice.": belirleyici.
- "You can go this far.": zarf.

Türkçede de "zor" örneğindeki gibi aynı kelime yerine göre sıfat ya da zarf olur. Basit bir kural vardır: kelime ismin önündeyse sıfat, fiilin önündeyse zarftır. Çünkü fiilin önündeyken fiili vurgular.

**Sözcük öbekleri farklı kalıplarda olabilir.** Ad (isim) tamlamaları, ön ad (sıfat) tamlamaları olabilir. Yüklemin türüne göre eylem tümceleri ya da ad tümceleri olabilir. Hoca "ad" teriminin kaynaktan geldiğini, kendi kuşağının "isim" dediğini ekledi.

**Öğelerin dizilişi.** Slayttaki istatistiğe göre belli başlı dillerde özne-nesne-yüklem dizilişi yaklaşık %46'dır.

<!-- BELİRSİZ: Hocanın "%7, %20, %10" diye okuduğu diğer dizilişlerin hangileri olduğu slaytta kaldı. Hoca bunları "Türkçede" diye okudu; kaynağın dünya dilleri mi Türkçe mi olduğu altyazıdan anlaşılmıyor. -->

**Tümcenin anlamı.** Tümceler anlamlarına göre olumlu, olumsuz, bildirme, soru, emir, istek ve ünlem tümceleri olabilir. Bunun bilinmesi önemlidir. Hoca olumsuzluk ekiyle bir örnek verdi:

- Cümle: "Öğretmen bana şunu yapmamamı söyledi."
- "yapmamamı" kelimesinin kökü "yap" kelimesidir. Köke inilince olumsuzluk eki gider ve cümledeki olumsuzluk kaybolur.
- Duygu analizi (sentiment analysis) yapan çalışmalarda bu sık yaşanır. Durak kelimeler ve ekler atılır, sözlük (lexicon) tabanlı analiz yapılır. Genelde anlamı sıfatların ve isimlerin taşıdığı düşünülür. Oysa cümleyi negatif yapan şey o olumsuzluk ekidir.

> **Hocanın vurgusu:** Morfolojik analizde "-ma", "-me" gibi bir olumsuzluk eki görülüyorsa kelimenin kökü doğrudan "yap" diye alınmamalıdır.

## 8. Çözümleme Yaklaşımları ve Bağlamdan Bağımsız Dilbilgisi

Bir tümceyi çözümlemenin en klasik yolu bağlamdan bağımsız dilbilgisidir (context-free grammar, CFG). Kurallı bir yapıdır: $S$ şunlardan, $NP$ bunlardan oluşabilir diye bütün kurallar verilir. Slaytta başka modeller de geçti: sözcüksel işlevsel dilbilgisi (Lexical Functional Grammar), ulamsal dilbilgisi (Categorial Grammar), başsözcüğe dayalı öbek yapısal dilbilgisi (Head-driven Phrase Structure Grammar) ve bağlılık dilbilgisi (Dependency Grammar). Hoca bunların üzerinde durmadı ve CFG'yi referans alarak ilerledi.

Chomsky hiyerarşisinin kısa tekrarı şöyledir:

- **Tür 0:** serbesttir. $X \to Y$ kuralının iki tarafında istenen sayıda uç ya da söz dizimsel değişken olabilir. Turing makineleri üzerinde gerçekleştirilenler buradadır.
- **Tür 1:** bir kısıt gelir. Sol taraftaki sembol sayısı sağ taraftakine eşit ya da ondan küçük olur.
- **Tür 2:** bağlamdan bağımsız dilbilgisidir.
- **Tür 3:** düzenli dillerdir.

Slayttaki tanım, CFG'nin bir kelime dizisi ile cümlenin söz dizimini betimleyen ağaç yapısı arasındaki bağıntıyı belirlediğini söylüyor. Hoca bu çeviri cümlesini beğenmedi ve şöyle açıkladı: elinde bir cümle varsa ona karşılık gelen mutlaka bir ağaç olmalıdır. Her cümlenin üzerinde ilerleyebileceği bir ağaç gerekir. Bu ağaçların toplandığı yapı ağaç derlemidir (treebank).

Çözümler iki gruba ayrılır. Kural tabanlı çözümde ağaçta yukarıdan aşağı ya da aşağıdan yukarı ilerlenir. Olasılık tabanlı çözümde ise ağaçların olasılıkları kullanılır.

## 9. Olasılık Tabanlı Çözümleme

Özne-nesne-yüklem yapısında bir cümle olsun. Derlemde bu yapıyı çözen birden fazla ağaç vardır. Örneğin $T_1$ ağacı bu yapıyı %40, $T_{15}$ ağacı %60 olasılıkla çözüyor. Cümle geldiğinde önce olasılığı en yüksek ağaç denenir. Cümle bu ağaca oturursa hem çözümleme bitmiştir hem de cümlenin o dile ait olduğu anlaşılmıştır. Oturmazsa olasılığı daha düşük olan diğer ağaca geçilir.

Hoca bunu "zor" örneğine bağladı. "zor" sıfat olarak kullanıldıysa cümleyi bir ağaç, zarf olarak kullanıldıysa başka bir ağaç çözer. Hangisi olduğu çözümlemeden önce bilinmez. Önce olasılığı yüksek olan denenir, olmazsa diğerine bakılır.

Hiçbir ağaç çözemezse kelimelerde bir hata olabilir, çünkü dokümanlarda yanlış yazılmış kelimeler bulunabilir. İki seçenek vardır:

- Ön işlemede hatalı olduğundan şüphelenilen kelimeleri düzeltmek. Bunun bir maliyeti vardır.
- Cümleyi "çözümlenemedi" diye kenara ayırmak, sonra bakıp hatayı düzeltmek ve yeniden ağaca vermek.

## 10. Bağlılık Ayrıştırması

Bağlılık ayrıştırması (dependency parsing), sentaktik analizin olmazsa olmaz parçalarından biridir. İngilizce için açık kaynak araçlar vardır ve Python kütüphanelerinde bulunur. Türkçe için akademik çalışmalar yapılmıştır, ama derste kullanılan Zemberek'te bu özellik yoktur. Bu araçlar genelde açık kaynak sunulmuyor. Akademik kullanım için ticari üründe kullanmayacağını belirten imzalı bir form doldurmak gerekiyor. Ayrıca Teknik Üniversite'de doktora tezini Türkçe çözümleme üzerine yapan Gülşen Hoca, buna başka adımlar da ekleyerek bir boru hattı (pipeline) oluşturup web üzerinden öğrencilere açmıştı. Cümle gönderilir, işlenip geri gelir. Bu zaman kaybı olduğu için pek tercih edilmez. Diğer seçenek kodu yeniden yazmaktır.

Hoca aynı hocanın makalesinden alınan bir örneği gösterdi: "Bu okuldaki öğrencilerin en akıllısı şurada duran küçük kızdır."

İşlem üç aşamalıdır:

1. **Morfolojik analiz:** her kelimenin kökü, eki ve etiketi çıkar. Örneğin "okul-da-ki" kelimesinde "-da" bulunma hâlidir (locative). "-ki" eklenince kelime sıfat olur.
2. **Sentaktik analiz:** cümle derlemdeki bir ağaca oturur. Bütün kelimeler yapraklara gelir. Bu da cümlenin Türkçe olduğunu gösterir.
3. **Bağlılık ayrıştırması:** dile ait kurallarla kelimeler birbirine bağlanır. Her eksik durumda kurallara yenisi eklenir.

Örnekte kullanılan kurallar şunlardır:

- Bir belirleyicinin arkasından isim geliyorsa belirleyici o ismi belirler.
- "-ki" eki önündeki ismi niteler.
- "küçük" sıfatı "kız" kelimesini niteler. Bu bir sıfat tamlamasıdır.
- "duran" kelimesindeki "-an" eki "kız" kelimesini niteler. Duran kişi kızdır.
- "kızdır" kelimesi "kızmak" fiili de olabilir, "kız" ismi de. Önünde sıfat bulunduğu için isim kabul edilir. Sonuna gelen "-dır" ile yüklem olur.

<!-- BELİRSİZ: Makaledeki bağlılık okları ve morfolojik çıktının bütün etiketleri ekranda kaldı. Burada yalnız hocanın sözlü anlattığı bağlar var. -->

Bu ilişkiler bilinirse anlamsal analiz çok daha doğru yapılır. 5N1K türü sorular cevaplanabilir:

- "Öğrencilerin en akıllısı kimdir?" Cevap: küçük kız.
- "Kız nerede duruyor?" Cevap: şurada.
- "Neredeki öğrencilerin en akıllısı?" Cevap: okuldaki.

Hoca "Küçük kız nerede?" sorusunun yanlış olduğunu söyleyip kendini düzeltti. Cümle kızın şu anda okulda olduğunu söylemiyor, okuldaki öğrencilerden biri olduğunu söylüyor.

> **Hocanın vurgusu:** Cümlenin öğeleri (özne, nesne, tümleç, yüklem, zarf tümleci) bağlılık ayrıştırmasından elde edilir. Bu çok önemlidir.

## 11. Türkçede Tümce Türleri ve Öğelere Ayırma

Aradan sonra hoca Türkçe cümlenin öğelerine geçti. Gösterimde $TT$ temel tümce, $YT$ yan tümcedir. Bir cümle yalnız temel tümceden ya da bir veya birkaç yan tümce ile bir temel tümceden oluşabilir.

**Basit tümce.** "Çocuk duvarı boyadı." Yalnız temel tümce vardır. Özne "çocuk", nesne "duvarı", yüklem "boyadı" kelimesidir. Ağaca yerleştirildiğinde öğeler bellidir.

**Ortak öğesiz birleşik tümce.** "Çocuk duvarı boyarken adam geldi." İki tümce birbirine bağlanmıştır ama öğeleri ortak değildir. Boyayan çocuk, gelen adamdır. "Çocuk duvarı boyarken" kısmı "geldi" yükleminin zarf tümleci olur, adamın geliş anını belirtir.

**Ortak öğeli birleşik tümce.** "Çocuk duvarı boyarken elini boyadı." Boyanan "el" nesnedir. "Duvarı boyarken" zarf tümlecidir. Duvarı boyayan da eli boyayan da çocuktur. Yani "çocuk" hem içteki hem dıştaki tümcenin ortak öznesidir.

**Ortak özneli bağımlı sıralı tümce.** "Çocuk duvarı boyadı ve gitti." İki ayrı cümle "ve" ile bağlanır. "Gitti" yükleminin öznesi de "boyadı" yükleminin öznesi de çocuktur. İkinci cümlede özne yazılmaz, gizlidir.

**Ortak nesneli bağımlı sıralı tümce.** "Parayı ben kazanıyorum, eşim harcıyor." Kazanan "ben", harcayan "eşim"dir. Özneler farklı, nesne "para" ortaktır.

**Birden fazla ortak öğeli tümce.** "Çocuk evde oyun oynarken televizyon izliyor." Birinci cümlede oynayan çocuktur, ikinci cümlede izleyen de çocuktur. İki tümcenin öznesi aynıdır.

**Sıralı (bağımsız) tümceler.** "Bahar geldi, çiçekler açtı." İki cümle birbirinden tamamen bağımsızdır.

**Girişik tümce.** "Atatürk 'Çalışmayan insan yükselemez.' diyor." Diyen Atatürk öznedir. Tırnak içindeki tümce nesnedir. Çözümlemesi en zor yapı budur. Hoca bunun kendisine de karışık geldiğini söyledi, ama problem olmadığını ekledi: ağaç derleminde bu yapıyı çözen bir ağaç varsa öğeler kolayca etiketlenir.

**Öğeler.** Tümcede özne, yüklem, nesne, dolaylı tümleç ve belirteç tümleci olabilir. Yüklemsiz cümle olamaz. Özne gizli olabilir. "Geldim" kelimesinde yüklem vardır, ama kelime kişiyi ve zamanı içinde taşıdığı için özne gizlidir.

Öğeleri bulmak için hangi soruların sorulacağı ve hangi sırayla bakılacağı slaytta verildi. Kaynak, hocanın "Eşref Hoca'nın kitabı" dediği bir kitaptır. Sıra şöyledir:

1. Ad öbekleri aranır: tek isimden mi oluşuyor, önünde ön ad var mı? "Büyük kırmızı ev" kalıbında "ev" isim, önündekiler ön addır.
2. Çoğul eki, iyelik eki alıp almadığına, yalın hâlde olup olmadığına bakılır.
3. Yüklem bulunur: tümcedeki çekimli eylem mi, ek eylem mi, birleşik eylem mi?

Bu kurallar teker teker işletilerek öğeler bulunur. Hoca bu sürecin blok diyagramını da gösterdi:

```text
Metin
  -> cümlelere ve kelimelere ayırma
  -> biçim bilimsel çözümleme
  -> belirsizlik giderme ve ön işleme
  -> ad tamlamaları, ön ad tamlamaları, ilgeç öbekleri, belirteç öbekleri
  -> yüklemin belirlenmesi
  -> öğelerine ayrılmış (etiketlenmiş) metin
```

Ön işleme adımına örnek olarak "ıspanak" kelimesinin Türkçe karakter kullanılmadan "ispanak" yazılması verildi. Bu hâliyle morfolojik analiz yapılamaz, önce Türkçe karakter sorunu giderilir. Belirsizlik gidermede ise biçim bilimsel çözümleme birden fazla sonuç verdiyse hangisinin alınacağına karar verilir.

## 12. Ağaç Derlemi ve Sözlükler

Hoca artık gerçekçi örneklere geçti. Morfolojik analizden geçen kelimeler Brown etiketleriyle etiketlenmiştir. Kurallar örneğin şöyledir:

```text
S  -> NP VP
S  -> Aux NP VP
S  -> VP
NP -> Det Nominal
NP -> ProperNoun
VP -> Verb NP
VP -> Verb
Nominal -> Noun
```

Bu kurallardan ağaçlar türetilir. Birinci ağaç $S \to NP\ VP$ yapısındadır, $NP$ altına belirleyici ve nominal konur. İkinci ağaç aynı yapıdadır ama $NP$ altına özel isim gelir. Bir başkasında $VP$ açılır. Böylece bir dile ait çok sayıda ağaç oluşur ve bunların bulunduğu yere ağaç derlemi denir.

Ağaçların yapraklarına ise sözlüklerdeki (lexicon) kelimeler gelir. Elde isim sözlüğü, fiil sözlüğü, belirleyici sözlüğü, özel isim sözlüğü, yardımcı fiil sözlüğü gibi birçok sözlük bulunur. İngilizcede düzenli ve düzensiz fiiller için iki ayrı sözlük gerekir.

Bir cümle geldiğinde morfolojik analizden geçip etiketlenir, sonra derlemde ilerletilir. Bu ilerleyiş yukarıdan aşağı ya da aşağıdan yukarı olabilir. Ağaç seçimi ya kural tabanlı sırayla ya da olasılık tabanlı yapılır. Hocanın örneğinde bir ağacın olasılığı 0,8, ötekilerin 0,7 ve 0,3 ise önce 0,8 denenir, çözülmezse sırayla diğerlerine geçilir.

## 13. Yukarıdan Aşağı Ayrıştırma

Cümle: "Does this flight include a meal?"

1. $S \to NP\ VP$ ağacı alınır. $NP$ açılır: $Det\ Nominal$. Belirleyici sözlüğünde "the", "a", "an" gibi kelimeler vardır. "does" orada yoktur. Bu yol tıkanır.
2. Başka ağaca geçilir: $NP \to ProperNoun$. Özel isimler sözlüğünde de "does" yoktur. Bu ağaç da olmaz.
3. $S \to Aux\ NP\ VP$ ağacına geçilir. Yardımcı fiil sözlüğünde "does" vardır. Yerleşir.
4. $NP$ açılır: $Det\ Nominal$. "this" belirleyici sözlüğündedir, yerleşir.
5. $Nominal \to Noun$. "flight" isim sözlüğündedir, yerleşir.
6. $VP \to Verb\ NP$. "include" fiil sözlüğündedir, yerleşir.
7. $NP$ açılır. "a" belirleyici sözlüğündedir, "meal" isim sözlüğündedir. İkisi de yerleşir.

Bütün kelimeler ağaca oturduğu için cümle çözümlenmiştir. Elde artık hangi kelimenin ne olduğu bilgisi vardır. Sonraki adım bağlılık ayrıştırmasıyla kimin kime bağlı olduğunu işaretlemek ve anlamsal bilgi çıkarmaktır.

## 14. Aşağıdan Yukarı Ayrıştırma

Cümle: "Book that flight."

Bu kez yapraklardan başlanır. "book" hem isim hem fiil sözlüğünde vardır. Bu bir belirsizliktir. Belirsizlik ya önceden çözülür ya da ağaçta ilerlerken doğru olan bulunur.

**Birinci deneme: "book" isim.**

1. "book" $Noun$, "that" $Det$, "flight" $Noun$ olur.
2. $Noun$ kelimeleri $Nominal$ olur.
3. $Det\ Nominal$ birleşip $NP$ olur: "that flight".
4. Geriye $Nominal$ ve $NP$ kalır. Bu ikisini birleştirip $S$ yapan bir kural yoktur.

Buradan iki sonuç çıkabilir: ya cümle İngilizce değildir ya da bir belirsizlik vardır. Belirsizlik "book" kelimesindedir.

**İkinci deneme: "book" fiil.**

1. "that flight" yine $NP$ olur.
2. $Verb\ NP$ birleşip $VP$ olur.
3. $S \to VP$ kuralı vardır. $S$ düğümüne ulaşılır.

Yapraklardan yukarı çıkarak $S$ düğümüne varıldığı için bu bir İngilizce cümledir. Belirsizlik de ağaçta ilerlerken çözülmüş olur.

## 15. Genişletilmiş Geçiş Ağları

Ağaç derlemindeki yapılar illa ağaç olarak gösterilmez. Bazı kaynaklar genişletilmiş geçiş ağlarını (Augmented Transition Network, ATN) kullanır. Sonuna "G" (grammar) eklenerek ATNG de denir. Hoca bunun daha havalı değil, daha derli toplu olduğunu söyledi. Ağaç dallandıkça uzar ve çalışması zorlaşır. ATN blok şemaya benzer.

Ağda durumlar (state) ve geçişler vardır. Bir durum, bir şeyin özne ya da yüklem olup olmadığını kontrol edebilir. Sağdaki duruma geçmek için soldaki durumun onaylanması gerekir. Son durum (final state), etrafına çizilen halka ile gösterilir.

**Örnek ağ.** Slayttaki dört durumlu ağ şöyledir:

```text
q1 --abb--> q2 --ε--> q3 --a--> q4 (final)
q3 --aa--> q1
q1 --b---> q4 (final)
```

Elde şu dizgilerin tümce olduğunu varsayalım: "abba", "abbaaabba", "abbaab", "b" tanınır. "abbab" ve "baab" tanınmaz.

**"abbaaabba" dizgisi.**

1. "abb" ile $q_1 \to q_2$ geçilir.
2. $q_2$ boş bir geçiş verir (ε). Girdi harcanmadan $q_3$ durumuna geçilir.
3. $q_3$ durumundan tek "a" ile $q_4$ durumuna gidilebilir. Final durumuna gelinir, ama girdi bitmemiştir. Bu yol yanlıştır.
4. Öteki seçenek "aa" ile $q_1$ durumuna dönmektir.
5. Yeniden "abb" ile $q_2$, ε ile $q_3$ durumuna gidilir.
6. Kalan "a" ile $q_4$ durumuna gelinir. Hem final durumundayız hem girdi bitmiştir. Dizgi tanınır.

**"baab" dizgisi.** Girdi "b" ile başladığı için $q_1 \to q_4$ gidilir. $q_4$ durumundan çıkış yoktur, başka seçenek de yoktur. Girdi bitmediği için dizgi tanınmaz.

Hoca ağacın gösterimden başka bir farkı olmadığını vurguladı.

**"Ali camı kırdı" örneği.** Cümle token'lara ayrılır ve morfolojik analize gönderilir. "Ali" isim, "cam" isim ve "-ı" nesne eki, "kır" fiil ve "-dı" zaman ekidir. "kır" kelimesi çimlik alan anlamında isim de olabilir. Ağda ilerlerken hangisinin doğru olduğu ortaya çıkar. Hoca, genel kalsın diye bütün isimleri, özel isimler dâhil, tek isim sözlüğünde varsaydı.

1. Cümle başında özne beklenir. Özne alt ağına gidilir. "Ali" isim sözlüğünde vardır. Alt ağın final durumuna gelinir. Özne tamamdır ve $q_1$ durumundan çıkılır.
2. "camı" için iki yol vardır: yüklem ya da nesne.
3. Yüklem yolu denenir. "cam" fiil sözlüğünde yoktur. Yol tıkanır.
4. Nesne yolu denenir. "cam" isim sözlüğünde, "-ı" nesne ekleri sözlüğünde vardır. Nesne tamamdır.
5. "kırdı" için yükleme bakılır. "kır" fiil sözlüğünde, "-dı" zaman ekleri sözlüğünde vardır. Yüklem tamamdır.
6. Final durumuna gelinir, cümle de bitmiştir. Çözümleme tamamlanır.

Burada olasılık da kullanılabilir. Hoca varsayımsal bir örnek verdi: Türkçede özneden sonra nesne gelme olasılığı %80, yüklem gelme olasılığı %15, başka bir öğe gelme olasılığı %5 ise önce nesne yolu denenir. Böylece çözüm daha hızlı bulunur.

**Döngü.** ATN gösteriminin bir kolaylığı da döngüdür. Türkçede bir ismin önüne çok sayıda sıfat gelebilir: "yırtık kırmızı büyük ağır top". Kaç sıfat geleceği bilinmez. Ağa aynı duruma dönen bir döngü konur. Her sıfatta başa dönülür, "top" gelince isim olduğu anlaşılır ve durulur.

## 16. Baştan Sona Bir Örnek ve Soru Cevaplama

Hoca şimdiye kadar anlatılan her şeyi şu cümleyle özetledi: "Ahmet'in babası beyaz şirin koyunu araba ile köye getirdi."

**Ön işleme.** Yanlış yazılmış kelimeler düzeltilir. "şirin" kelimesi "sirin", "köy" kelimesi "koy" yazılmış olabilir. Türkçe karakter sorunları giderilir. Noktalama işaretleri atılır.

**Morfolojik analiz.** Kökler, ekler ve etiketler çıkar. Etiketlerin açılımları şöyledir: `<İ>` isim, `<TE>` tamlayan eki, `<TNE>` tamlanan eki, `<S>` sıfat, `<NE>` nesne eki, `<DE>` dolaylı tümleç eki, `<F>` fiil, `<ZE>` zaman eki. "ile" için `<DZ>` etiketi verilmiş. Hoca bu kısaltmanın ne olduğunu o an hatırlamadı.

**Sentaktik analiz.** Dilin tümce kuralları elde olmalıdır. Kurallardan hiyerarşi kurulur:

```text
Ahmet<İ> in<TE>        -> <T>
baba<İ> sı<TNE>        -> <TN>
<T> <TN>               -> <İG>  -> Özne:           Ahmet'in babası
beyaz<S> şirin<S>      -> <S>
<S> koyun<İ>           -> <SG>
<SG> u<NE>             -> <SN>  -> Nesne:          beyaz şirin koyunu
araba<İ> ile<DZ>       -> <ZT>  -> Zarf tümleci:   araba ile
köy<İG> e<DE>          -> <DT>  -> Dolaylı tümleç: köye
getir<F> di<ZE>        -> <Y>   -> Yüklem:         getirdi
```

Ağaç derleminde cümleye oturan bir ağaç bulunur. Böylece cümle öğelerine ayrılmış olur. Bu çıktı anlamsal analizin girdisidir.

**Soru cevaplama.** Hoca bu çıktının nerede kullanılabileceğini şöyle gösterdi. Cümle "Türkiye'nin başkenti Ankara'dır", soru "Türkiye'nin başkenti neresidir?" olsun. İki yol vardır:

- **Bağlılık ayrıştırması üzerinden gitmek.** Daha zahmetli ve zaman alıcıdır.
- **Örüntü (pattern) tabanlı yöntem.** Daha kurallıdır. "Nere" sorusu bir yer, yani özel isim arar. Soruda "başkent" geçtiği için aranan özel isim bu kelimenin yakınında olmalıdır. "Türkiye'nin başkenti Ankara'dır", "Ankara Türkiye'nin başkentidir", "Başkent olan Ankara" gibi cümleler toplanır. Ankara ile başkentin birlikte geçtiği örüntüler çıkarılır. Soru gelince bu örüntülere uyan dokümanlardan cevap çekilir.

Hangisinin kullanılacağı, üzerinde çalışılan işe bağlıdır.

## 17. Dil Modellerine Giriş

İkinci aradan sonra hoca, içinde daha çok matematik olan yeni konuya geçti. Bilgisayar okuduğunu insan gibi anlayamaz. İnsan bir kelimenin hangi nesneye karşılık geldiğini bilir. Kelimenin birden fazla anlamı varsa bile cümlenin bağlamından doğru anlamı çıkarır. Deneyimleriyle ve benzetmeleriyle kafasında bir model kurar. Bilgisayarda bu yeti yoktur. Ona bir şey verilmedikçe model kuramaz. Verilecek bilgilerden biri kullanılan dilin modelidir.

**Tanım.** Bir dildeki kelimelerin sıralanışının olasılık dağılımı, o dilin istatistiksel dil modeli olarak tanımlanır.

Yani karakterlerin ve kelimelerin kullanım sıklıkları ile iki, üç, ..., $n$ kelimenin art arda gelme sıklıkları belirlenir. Bunların hepsi dil modelini oluşturur.

## 18. Lemma ve Kök

Hoca önceki slaytta geçen "başsözcük" kavramını burada açtı. İngilizcedeki lemma, Türkçede başsözcük olarak çevrilir. Tanım olarak sözlükteki madde başı kelimedir. Bundan türetilenlere sözcükbirim denir.

Örnek: "göz", "gözlük", "gözlükçü". Üç kelimenin de kökü "göz" kelimesidir. Ama köke inilirse anlam kaybolur. Gözleri saymak isteyen biri "gözlük" kelimesini de "göz" diye sayarsa hata yapar. Gözlük bambaşka bir şeydir, bu bilgi kaçırılmış olur.

> **Hocanın vurgusu:** Kelimenin kökü ile lemması ayrı şeylerdir. Bir kelime aldığı ekle sözlükte bulunuyorsa daha fazla köküne inilmez. Sözlükteki hâli alınır. Bu işleme lemmatization denir.

İngilizcede durum kolaydır: "read", "reads", "reading" için kök "read" kelimesidir. "-s" ve "-ing" hiçbir şeyi değiştirmez.

Türkçede durum böyle değildir. İsim soylu bir kelimeye 24 farklı çekim eki, fiil soylu bir kelimeye 46 çekim eki gelebilir. Çekim ekleri kelimenin anlamını değiştirmez. Günlük hayatta hepsi aynı anda kullanılmaz, ama kullanılamayacağı anlamına da gelmez. Bu hâller TDK sözlüğünde yer almaz. Bütün kombinasyonları bir yerde tutmak da akıl kârı değildir. Bu yüzden ekler ayrılır. Türkçede lemma olarak kullanılabilecek yaklaşık 70 bin kelime vardır.

## 19. Dil Modellerinin Kullanım Alanları

**Konuşma tanıma (speech to text).** Şiveli konuşan biri "celiyorum" derse metne "celiyorum" diye geçer. Morfolojik analiz bunu çözemez. Dil modeli bunun "geliyorum" olduğunu bulup düzeltmeye çalışır.

**El yazısı tanıma (handwriting recognition).** Burada imza değil, kalemle yazılmış normal yazı kastediliyor. Bazı harfler anlaşılmaz: S mi, Z mi? Hoca kendi hızlı yazdığı S harfini örnek gösterdi. Cümleyi okuyan insan harfi anlar, bilgisayar anlamaz. Dil modeli o harfin ne olması gerektiğini söyleyebilir.

**Yazım düzeltme (spelling correction).** Klavyede sağdaki tuş yerine soldakine basılarak yazılan kelimeler düzeltilebilir. Hoca, İngilizceye yeni başlayanların bazı kelimeleri sık yanlış yazdığını da ekledi.

<!-- BELİRSİZ: 02:03:40'ta gösterilen sık yanlış yazılan kelimeler slaytta kaldı. Altyazıda yalnız "weave" benzeri bir sözcük geçiyor. -->

**Makine çevirisi (machine translation).**

**Optik karakter tanıma (OCR).** Metin tarayıcıdan geçince resim olur. OCR resmi metne çevirir. Hoca "m" harfinin "in", "u" harfinin çift "i" okunduğuna, "t" ile "l" harflerinin karıştığına çok şahit olduğunu söyledi. Günümüz OCR araçları ise çok başarılıdır.

**Banka örneği.** Kitaplarda hep geçen bu örnek bir Woody Allen filminden gelir. Adam bankaya sıradan biri gibi girer, kasaya gider ve veznedara bir kâğıt gösterir. Kâğıtta "I have a gub" yazar. "gub" İngilizcede bir kelime değildir. Veznedar bunun silah ("gun") olduğunu anlar. Adamın vücut dilinden, o güne kadar kimsenin böyle bir kâğıt göstermemiş olmasından anlar.

Bilgisayar ise dil modeliyle anlar. Bu kelime "gun", "gum", "gas", "gull" gibi bir şey olabilir. Bunlardan hangisi "I have a" kalıbıyla birlikte kullanılır? Önündeki "a" kelimesi bunun isim olduğunu gösterir. Hangisinin sıfat ya da özel isim olduğu da dikkate alınır. Arkadaki kod bu şekilde "gun" olabileceğini söyler.

## 20. Shannon Oyunu ve N-Gram Fikri

Hoca sınıfla bir oyun oynadı. Buna Shannon oyunu (Shannon game) denir. Bir karakter açılır ve sonrakinin ne olacağı sorulur.

**Soru:** İlk karakter "W". Sonraki karakter ne olabilir?

**Cevap:** Öğrenciler "A" ve "E" dedi.

İngilizcede 26 harf vardır. Hiç kimse "J" ya da "K" demez. Çünkü herkes İngilizce bildiği için akla en olası harfler gelir. Hoca ek bir bilgi verdi: cümlenin başında "W" varsa genelde soru kelimesi gelir: "who", "which", "what", "when". Bu yüzden "H" de güçlü bir adaydır.

Sonra "H" açıldı. Artık iki karakterin olasılığı birlikte kullanılır. "WH" sonrası "A" (what), "E" (when), "O" (who), "Y" (why) olabilir. Yirmi altı harf dört harfe inmiş olur. İnsan bu olasılıkları kesin bilmez, ama bilgisayara verilirse insandan daha hızlı bulur.

"A" açılınca herkes "T" der. Ardından boşluk karakteri gelir. Sonra büyük olasılıkla bir yardımcı fiil gelir.

Bu oyunun iki biçimi vardır:

- **Karakter n-gram modeli (character n-gram):** karakter, kendinden önceki karakterlere göre tahmin edilir.
- **Kelime n-gram modeli (word n-gram):** kelime, kendinden önceki kelimelere göre tahmin edilir. "what" kelimesinden sonra "do" gelmesi gibi.

## 21. Harf Dizilerinde Yaklaşım Dereceleri

Hoca ekranda anlamsız bir karakter dizisi gösterdi ve ne anlaşıldığını sordu. Hiçbir şey. Bilgisayarın anlamlı bir metne bakışı da aslında böyledir. Sonra bu dizinin nasıl üretildiğini ve dereceler arttıkça neyin değiştiğini anlattı.

<!-- BELİRSİZ: Her derecede üretilen örnek metinler ekranda kaldı. Altyazıda yalnız hocanın içinden seçip okuduğu kelimeler var. -->

**Sıfırıncı derece (zero-order approximation).** Bir torbada karakterler vardır. Sayıları rastgeledir, sıraları birbirinden bağımsızdır. Torbadan harfler çekilir. Çıkan dizi tamamen anlamsızdır.

**Birinci derece (first-order approximation).** Harfler yine birbirinden bağımsızdır, ama torbada dildeki sıklıklarına göre bulunur. Scrabble ya da Kelimelik oyunundaki gibi çok kullanılan harflerden çok, az kullanılanlardan az vardır. Çıkan dizi yine anlamsızdır, ama bir öncekinden iyidir. Sesli harfler torbada daha çok olduğu için sessiz harften sonra sesli gelme olasılığı artar.

**İkinci derece (second-order approximation).** Bir harfin görülme olasılığı önceki harfe bağlıdır. Bir sonraki konuma, önceki harften sonra en yüksek olasılıkla gelen harf konur. Metin yine anlamsızdır ama İngilizce kelimeler oluşmaya başlar. Hoca çıkan metinde "and", "to be", "best", "dream" gibi kelimeleri gösterdi.

**Üçüncü derece (third-order approximation).** Harf, önceki iki harfe bağlıdır. "W" ve "H" geçmişinden sonra en olası harf "E" ise "E" konur. Sonra "H" ve "E" geçmişine bakılır, en olası harf "Y" ise "Y" konur. Sonuç çok daha anlamlıdır. Hoca "when", "last", "no", "demonstration", "recognition" gibi kelimeleri gösterdi.

Derece 40, 50, 60 yapılırsa çıkan kelimelerin hepsinin İngilizce olduğu görülür. Burada kelimelerden söz ediliyor. Cümle anlamsız olabilir, konu cümlenin anlamı değil dilin yapısıdır.

**$n$ kaç olmalı?** n-gram adındaki $n$ yerine 1, 2, 3, 5, 10 gelebilir. Teorik olarak sonsuz da olabilir, ama mantıklı değildir. Pratikte en fazla 20'ye kadar kullanılabileceği gösterilmiştir. Yine de 20 kullanan bir çalışma bulunmaz. Çünkü bir kelimenin geçmişindeki 20 kelimeyle birlikte geçme olasılığı sıfıra çok yakındır. Naive Bayes gibi olasılıkları çarpan bir yöntemde sonuç neredeyse sıfır olur.

> **Hocanın vurgusu:** Akademik çalışmalarda en fazla 4 ve 5 görülür. Genelde çalışmalar 2 ve 3 ile sınırlıdır.

> **Ek bilgi (derste anlatılmadı):** Çok küçük olasılıkların çarpımı bilgisayarda taşma (underflow) sorunu da yaratır. Bu yüzden uygulamalarda olasılıklar genellikle çarpılmaz, logaritmaları toplanır. Bu, hocanın anlattığı "çarpım sıfıra iniyor" sorununu sayısal olarak çözer. Ama çok uzun geçmişlerin seyrek görülmesi sorununu çözmez.

## 22. Romance Dillerinde Hece Örtüşmesi

Hoca, üst derecelerde anlamlı kelimelerin çıktığı görülünce yapılan çalışmalara değindi. Aynı aileden olan Hint-Avrupa dilleri alınmış, trigram'lara bölünmüş ve en sık üçlü karakterler çıkarılmış. İlk sıralarda hepsinde ortak olan "ion" gibi trigram'lar görülmüş. İlk 10'a bakılınca ortak olanlar artıyor, biraz daha artırılınca çok daha fazla örtüşme çıkıyor. Hocaya göre Türkçe bu listeye katılsa "ion" ilk 100'e bile girmez.

<!-- BELİRSİZ: Slayttaki ilk dört ve ilk on trigram listesi ekranda kaldı. -->

Sonra aynı aile içindeki Romance dilleri için hece tabanlı benzerlik çıkarılmış. Her dilin derlemi hecelerine ayrılmış ve sıklıkları hesaplanmış. Aşağıdaki tablo, her dilin en sık ilk $k$ hecesinin diğer dillerde de bulunma yüzdesini ve çalışılan hece sayılarını gösterir:

| Dil | 100 | 200 | 300 | 400 | 500 | 561 | Hece türü (type) | Hece sayısı (token) |
|---|---|---|---|---|---|---|---|---|
| Latince | %72 | %86 | %92 | %95 | %98 | %100 | 561 | 3922 |
| Rumence | %63 | %74 | %80 | %84 | %87 | %90 | 1243 | 6591 |
| İtalyanca | %75 | %85 | %91 | %94 | %96 | %97 | 803 | 7937 |
| Portekizce | %69 | %84 | %91 | %95 | %97 | %98 | 693 | 6152 |
| İspanyolca | %73 | %87 | %93 | %96 | %98 | %99 | 672 | 7477 |
| Katalanca | %62 | %77 | %84 | %88 | %92 | %93 | 967 | 5624 |
| Fransızca | %48 | %61 | %67 | %72 | %76 | %78 | 1738 | 5691 |

Hoca tabloyu şöyle yorumladı. İlk 100 hecede Latincenin %72'si, İtalyancanın %75'i diğer dillerde de vardır. Hece sayısı arttıkça çakışma yüzdesi artar. Latincenin 561 hecesinin tamamı diğer dillerde bulunur, çünkü hepsi Latinceden türemiştir. İtalyanca, Portekizce ve İspanyolca çok yakındır. Bu dillerden birini bilen, kelimelerin kökeni aynı olduğu için diğerini kolay anlar, gazetesini okur ve rahat öğrenir. Fransızca diğerlerinden biraz farklıdır.

Aynı veriler her dil için grafik olarak da çizilmiş. Kullanım sırası en sıktan en seyreğe sıralanmış, her sıra için örtüşme yüzdesi gösterilmiş. Hepsinin eğrisi benzer şekildedir. Bu eğri, sonraki konunun girişidir.

## 23. Zipf Yasası

Hoca bunu çok önemli ve ilginç bir yasa olarak tanıttı. George Zipf ortaya atmıştır. Bir dildeki kelimelerin kullanım sırası ile sıklığı arasında bir ilişki vardır. Kelimeler sıklığa göre sıralandığında bütün dillerde aynı karakterde bir eğri çıkar.

Bu yalnızca dillerde değil, doğadaki olaylarda da görülür. Dünyadaki bütün göller derinliklerine, bütün dağlar yüksekliklerine göre sıralanırsa aynı yasaya uyar.

**Sayısal örnek.** Sıralanmış kelimelerde en sık kelime 100 kez geçsin. Yasa, sıradaki kelimelerin yaklaşık şu sıklıklarda geçeceğini söyler:

| Sıra | Hesap | Sıklık |
|---|---|---|
| 1 | $100/1$ | 100 |
| 2 | $100/2$ | 50 |
| 3 | $100/3$ | yaklaşık 33 |
| 4 | $100/4$ | 25 |
| 5 | $100/5$ | 20 |
| 10 | $100/10$ | 10 |

Değerler yaklaşıktır. 50 yerine 47, 49, 52 gibi değerler çıkabilir.

**Formül.** $r$. sıradaki kelimenin sıklığı $n(r)$ ile gösterilir:

$$n(r) \propto \frac{1}{r^\alpha}$$

$\alpha$ düzgün bir eğri elde etmek için deneyerek bulunan bir değerdir. Her dil için çıkarılmıştır, tekrar hesaplamak gerekmez. Hoca fonksiyon biçiminde yazılan $f(n) \propto 1/n^\gamma$ ifadesinden ve $\gamma$ değerinin $\alpha$ değerine bağlı olarak oluşturulduğundan da söz etti.

<!-- BELİRSİZ: Slaytta γ ile α arasındaki bağıntı ve eğrinin sayısal noktaları altyazıda okunmuyor. Bkz. Ders Sonrası Notlar. -->

**Eğrinin bölgeleri.** Grafikte iki noktalı çizgi vardır:

- **Baştaki bölge:** işlevsel sözcüklerdir. Bunlar durak kelimelerdir: "ve", "veya", "that", "which", "and", "or", "the". Çok sık geçerler.
- **Orta bölge:** ana sözcüklerdir.
- **Sondaki kuyruk:** dilde en az kullanılan, sıklığı çok düşük kelimelerdir.

Türkçe sıklık tablosunun grafiği de aynı eğriyi verir. Hoca, işlevsel sözcükler atılmazsa eğrinin başının biraz kaydığını söyledi. Başka bir dilde eğri biraz daha farklı olabilir, ama hepsi Zipf yasasına uyar. Bir dilin derleminde yalnız karakter sıklıkları sıralansa bile aynı dağılım görülür.

## 24. Cümle Olasılığı ve N-Gram Modeli

Dil modelinde karakter ve kelime olasılıklarının önemli olduğu görüldü. Peki bir cümlenin olasılığı nasıl hesaplanır?

**Sıfır-gram (zero-gram).** Hiçbir kelime kendinden önceki kelimeye bağlı değildir. Hepsi serbest ve bağımsızdır. Sözlüğün boyutu $V$ olsun. Türkçe için bu sayı yaklaşık 70 bindir. Bu durumda her kelimenin olasılığı $1/V$ olur. "aba" kelimesi sözlükte bir kez geçer, olasılığı $1/70000$ olur. "abla" da öyle. Cümlenin olasılığı kelime olasılıklarının çarpımıdır.

Hoca $V = 100000$ ve beş kelimeli bir cümle üzerinden gösterdi. Her kelimenin olasılığı $10^{-5}$ olduğuna göre (ara adım eklendi):

$$P(S) = \left(\frac{1}{100000}\right)^5 = 10^{-25}$$

Cümlenin olasılığı kelime sayısı arttıkça hızla küçülür. Hoca, böyle bir cümlenin tekrar karşılaşılmasının ancak birinin kopyala-yapıştır yapmasıyla olacağını söyledi. Bu yüzden sıfır-gram ile iş yapılmaz. Kelime önceki kelimelere bağlı olarak işlenir. Böylece hem daha anlamlı sonuçlar çıkar hem de olasılıklar bu kadar küçülmez.

**Kelimeleri bağımsız sayma.** Slayttaki bir sonraki yaklaşımda her kelimenin olasılığı sıklığına bağlıdır ve diğerlerinden bağımsızdır:

$$P(S) = P(w_1) \times P(w_2) \times \dots \times P(w_n)$$

**N-gram modeli.** Cümle $w_1 w_2 w_3 w_4$ olsun. İlk kelimenin geçmişi yoktur, $P(w_1)$ alınır. İkinci kelime geçmişine bağlı yazılır: $P(w_2|w_1)$. Bu ifade $w_2$ kelimesinin $w_1$ ile birlikte kullanılma olasılığıdır. $w_2$ başka kelimelerden sonra da gelebilir, onların olasılıkları farklıdır. Üçüncü kelimenin geçmişinde $w_1$ ve $w_2$ vardır. Dördüncünün geçmişinde $w_1$, $w_2$, $w_3$ vardır:

$$P(w_1 w_2 w_3 w_4) = P(w_1) \times P(w_2|w_1) \times P(w_3|w_1 w_2) \times P(w_4|w_1 w_2 w_3)$$

Hoca bunun en kesin çözüm olduğunu söyledi. Ama sorun vardır. Bazı edebî metinlerde cümle bir paragraf kadar uzundur. Virgüllerle bağlanır, 50 kelimeye çıkabilir. O zaman 50. kelimenin olasılığı geçmişindeki 49 kelimeyle birlikte hesaplanmalıdır. Bu mantıklı değildir.

**Çözüm: $n$ belirlenir.** Bütün geçmişe değil, yalnızca $n-1$ önceki kelimeye bakılır. $n=2$ (bigram) için aynı cümle şöyle yazılır:

$$P(w_1 w_2 w_3 w_4) \approx P(w_1) \times P(w_2|w_1) \times P(w_3|w_2) \times P(w_4|w_3)$$

Genel olarak bigram için:

$$P(S) = P(w_1) \times P(w_2|w_1) \times \dots \times P(w_n|w_{n-1})$$

> **Ek bilgi (derste anlatılmadı):** Bir kelimenin olasılığının yalnız son birkaç kelimeye bağlı olduğu varsayımına Markov varsayımı denir. Hocanın sonraki derste anlatacağını söylediği Markov modelleriyle bağlantı buradadır. Literatürde $P(S) = \prod P(w_i)$ biçimi unigram modeli olarak, her kelimeye $1/V$ veren biçim ise sıfır-gram ya da tekdüze model olarak anılır.

## Dersin Toparlaması

Bu dersin ilk kısmı sentaktik analizdi. Morfolojik analizden gelen etiketli kelimeler, dile ait kurallardan kurulmuş ağaç derlemi üzerinde ilerletilir. Cümle bir ağaca oturursa o dile aittir ve belirsizlikler de bu sırada çözülür. Bağlılık ayrıştırması kelimeler arası ilişkileri çıkarıp anlamsal analize zemin hazırlar. Türkçenin serbest sıralı yapısı ve zengin ek sistemi bu işleri İngilizceye göre zorlaştırır. Aynı yapı ağaç yerine geçiş ağlarıyla da gösterilebilir.

İkinci kısımda dil modellerine girildi. Bilgisayara dilin sıklık bilgileri verilir: karakterler ve kelimeler ile bunların art arda gelme olasılıkları. Shannon oyunu ve harf dizileri, geçmişe bakmanın ne kadar işe yaradığını gösterdi. Zipf yasası sıklıkların nasıl dağıldığını anlattı. Sonunda cümle olasılığı n-gram formülüyle yazıldı. Hoca konunun devamını sonraki derse bıraktı: Markov modelleri ve örnekler, yumuşatma (smoothing) ve belirsizlik giderme algoritması.

## Ders Sonrası Notlar

> **Ders sonrası not:** Hoca "okuyor" kelimesi için "geniş zaman" dedi. "Okuyor" şimdiki zamandır. Geniş zaman hâli "okur" olur.

> **Ders sonrası not:** Hoca POS kavramını "bir dokümanda anlamı olan en küçük birim" diye tanımladı. POS, kelimenin türü (sözcük türü) demektir. Anlamı olan en küçük dil birimi de biçimbirimdir. Bir dokümanı işlerken genelde kelimelerin birim alındığı doğrudur.

> **Ders sonrası not:** Hoca Fince, Çince ve İngilizceyi birlikte gösterip "Hint-Avrupa dilleri galiba" dedi. Bu üçünden yalnızca İngilizce Hint-Avrupa dilidir. Fince Ural ailesinden, Çince Çin-Tibet ailesindendir. Japonca ve Korecenin Altay ailesine bağlanması da dilbilimde tartışmalıdır, bu dillerin aynı aileden olduğu kesin değildir.

> **Ders sonrası not:** Hoca Türkçede bağlaç olmadığını söyler gibi bir ifade kullandı (00:31:55). Türkçede "ve", "veya", "ama" gibi bağlaçlar vardır. Bu kısım altyazıda da karışıktır.

> **Ders sonrası not:** "Çocuk evde oyun oynarken televizyon izliyor" örneğinde hoca "ortak nesnem çocuk" dedi. Doğrusu "çocuk" kelimesinin iki tümcenin ortak öznesi olmasıdır.

> **Ders sonrası not:** Hoca "belirteç" sözcüğünü iki anlamda kullandı. "This" örneğinde ve "Determiner sözlüğü belirteçti" derken determiner (belirleyici) kastediliyor. Kelime türleri tablosunda ise belirteç zarf (adverb) demektir. Bağlılık örneğinde "Bu bir bağlaçsa" denilen yerde de kastedilen belirleyicidir.

> **Ders sonrası not:** Örnek ağda hoca sondaki "a" için "Q3'e geldim, burası final state" dedi. Final durumu $q_4$ durumudur. Tanınan ve tanınmayan bütün dizgiler ve iki CFG örneği ayrıca kodla çözümlenip doğrulandı.

> **Ders sonrası not:** Hoca, Zipf yasasını anlatırken bir yerde "100 tane sözcük" dedi, örnekte ilk 10 sözcüğe baktı. Yasa bütün liste için geçerlidir, sayı örnek amaçlıdır. Slaytta $\gamma = 1 + \frac{1}{n^\alpha}$ yazdığı kısa notta belirtiliyor. Zipf yasasının literatürdeki biçiminde bu ilişki $\gamma = 1 + \frac{1}{\alpha}$ şeklindedir. Slayttaki ifade büyük olasılıkla yazım hatasıdır.

> **Ders sonrası not:** Altyazıda bozuk geçen kelimelerin doğru yazımları: "Pantry Bank" Penn Treebank; "Brom" Brown; "Porter Stamuli" Porter stemmer; "Şanon" Shannon; "Zif/Ziff" Zipf; "Wood Allen" Woody Allen; "gap" ve "gam/gal" slayttaki "gub", "gum", "gull" kelimeleri; "Lamentization" lemmatization; "Romanca" slayttaki Romanian, yani Rumence; "Mişarca" büyük olasılıkla Mişer Tatarcası.

> **Ders sonrası not:** Hoca zamir etiketini PP olarak gösterdi. Penn Treebank kümesinde kişi zamiri için yaygın etiket PRP, iyelik zamiri için PRP\$ etiketidir. Etiket adları araçtan araca değişebilir.

> **Ders sonrası not:** "Teknik Üniversite'deki Gülşen Hoca", İTÜ'den Gülşen Eryiğit'tir. Morfolojik çıktıda hocanın "kopu" diye okuyup ne olduğunu bilmediğini söylediği etiket büyük olasılıkla Cop (copula, ek eylem) etiketidir, kesin değildir. "Eşref Hoca'nın kitabı" da büyük olasılıkla Eşref Adalı'nın Türkçe doğal dil işleme kitabıdır, altyazıdan kesinleşmiyor.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
