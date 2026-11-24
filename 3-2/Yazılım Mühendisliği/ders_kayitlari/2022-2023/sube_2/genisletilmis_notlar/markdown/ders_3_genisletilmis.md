# Ders 3 Genişletilmiş Notu: Bileşen Tabanlı Geliştirme, Artımsal Modeller ve Çevik Süreçler (XP, Scrum)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. UML Şemalarını Çizerken Araç Seçimi
- 2. Bileşen Tabanlı Uygulama Geliştirme
- 3. Artımsal ve Yinelemeli Modeller
- 4. Sarmal (Spiral) Model
- 5. Kazan-Kazan (WinWin) Modeli
- 6. Çevik Süreçler ve Çevik Manifesto
- 7. Çevik Süreci Yürütecek Ekibin Özellikleri
- 8. Çevik Süreçlerin Dezavantajları
- 9. Aşırı Programlama (XP)
- 10. Scrum
- 11. Çevik Modelleme ve Denge
- Örnek Sorular
- Dersin Toparlaması

## 1. UML Şemalarını Çizerken Araç Seçimi

Dersin ilk yarım saati dönem projesinin düzenine ayrıldı; bu kısım nota alınmadı. Bu konuşmanın içinde yazılım mühendisliği açısından kalıcı bir uyarı da vardı. Projede çok sayıda UML şeması çizilecektir ve bunun için UML'ye özel bir çizim aracı ya da genel amaçlı bir grafik programı kullanılabilir. Hoca, UML şemalarının her birinin kendine özgü kuralları olduğunu, her şeklin ve özellikle okların uçlarının farklı biçimlerinin farklı anlamlar taşıdığını hatırlattı. UML odaklı bir araç bu kuralları şemaya kendiliğinden yansıtır. Genel bir çizim programında ise programın varsayılan ok ucu UML'nin hiçbir şemasında kullanılmayan bir ok olabilir; bu durumda doğru gösterimi denetleme yükü tamamen çizen kişiye kalır. Bu yüzden hoca UML odaklı bir çizim aracı kullanmayı tavsiye etti.

Projeyle ilgili bir başka akademik not da "kabul ve kısıtlar" kavramıdır. Gereksinimler ne kadar ayrıntılı yazılırsa yazılsın açıklanmamış noktalar kalabilir. Gerçek bir projede bu noktalar müşteriyle görüşülerek netleştirilir. Görüşme yapılamıyorsa ekip kendi kararını verir ve bunu kabul ve kısıtlar bölümüne yazar. Örneğin bir kurs sisteminde kontenjan üst sınırı belirtilmemişse "üst sınır sistem yöneticisi tarafından belirlenir" diye bir kabul yazılabilir.

## 2. Bileşen Tabanlı Uygulama Geliştirme

Önceki derste kalınan yerden, bileşen tabanlı (component-based) uygulama geliştirme modelinden devam edildi (ekrandan, 00:35:00). Bu model, uygulamanın mümkün olduğunca hazır yazılım bileşenlerinden oluşturulmasını öngörür. Elde hazır bileşen yoksa o da hazırlanır. Odak noktası hazır bileşenlerden yazılım kurmak olduğu için iş adımlarının akışı diğer süreçlerden farklıdır.

### 2.1 Aşamalar

Slayttaki aşamalar şunlardır:

- Konu alanı mühendisliği (Domain Engineering)
- Aday bileşenlerin sınıflandırılması ve seçilmesi (Qualification)
- Seçilen bileşenlerin kendi yazılımımıza uyarlanması (Adaptation)
- Bileşenlerin bir araya getirilmesi (Composition)

**Konu alanı mühendisliği.** İlk iki aşama birlikte gereksinim mühendisliği ve analiz çalışması gibi düşünülebilir. Bu aşamada problem alanı olabildiğince iyi anlaşılmaya çalışılır: problem alanındaki varlıklar neler, bu varlıklarla hangi işler yapılacak, hangi eylemler gerçekleşecek?

**Sınıflandırma ve seçme.** Yapılması gerekenler anlaşıldıktan sonra bunları hangi bileşenlerle yapacağımıza karar veririz. Belirli bir işi yapabilecek birden fazla aday bileşen olabilir ve adayların karşıladığı işlevler farklı biçimlerde örtüşür. Hocanın örneğinde bir bileşen A, B, C işlevlerini, başka bir bileşen B, C, E işlevlerini karşılıyor. Hangisini seçersek seçelim açıkta kalan işlevi karşılayacak başka bir bileşen de gerekecektir. Bu yüzden bir bileşeni seçmek, başka bileşenleri de seçmeye zorlar ya da seçim kümesini daraltır; seçimler bir zincir gibi birbirini etkiler.

Hocaya göre bu aşamada değerlendirilmesi gereken en önemli soru şudur: Bu bileşen ihtiyaçları doğrudan karşılayabilir mi, karşılayamıyorsa ne kadar değişiklikle karşılar? Bileşen açık kaynaklıysa (hepsi öyle olmayabilir) kaynak kodunda değişiklik yapmak gerekebilir. Bu, en önemli maliyetlerden biridir; çünkü harcanan çaba ve zaman da nakittir. Bazen elimizdeki lisanslı bileşenler arasında olmayan yeni bileşenler almak da gerekir.

Sınıflandırmada şu ölçütler kullanılabilir:

- Gereken değişiklik (düzenleme) düzeyi ve bunun maliyeti
- Yeni bileşen ise baştan ödenecek maliyet (upfront cost)
- Bileşenin iç ve dış kalite özellikleri ile kalite puanları

Bu ölçütlere farklı ağırlıklar verilerek her bileşenin bir değeri bulunur. Ama tek tek bileşenlere değil, bütün ihtiyaçları karşılayan alternatif bileşen setlerine ve bunların toplam değerine bakılır. Sonuçta en az çaba, en düşük maliyet ya da ikisinin birlikte gözetildiği bir plan seçilir.

> **Hocanın vurgusu:** İlk iki aşama çok kritiktir. Bu aşamalarda verilen yanlış kararlar önemli teknik riskler oluşturur.

**Uyarlama ve bir araya getirme.** Bileşenler nadiren olduğu gibi kullanılabilir; çoğunlukla bazı değişiklikler gerekir ve bunlar uyarlama aşamasında yapılır. Son aşamada bileşenler birleştirilir (kompozisyon).

### 2.2 Artılar, Eksiler ve Sonuçlar

Modelin en önemli artısı yeniden kullanımın özendirilmesidir; hazır bileşenlerle daha verimli, daha hızlı ve daha az çabayla proje gerçeklenebileceği düşünülür. Slaytta bu artı "azalan giderler?" diye soru işaretiyle yazılmıştı. Hoca bunun nedenini şöyle açıkladı: Yazılımın yeniden kullanımı üzerine okuduğu araştırmalarda, yeniden kullanımın sağladığı tasarruf %50-60 gibi değil, en fazla %30 civarında çıkmıştı. Bunun sebebi, bir bileşeni yeniden kullanıma yönelik tasarlayıp kodlarken ona daha fazla çaba harcanmasıdır: daha esnek geliştirilir, daha ayrıntılı sınanır. Bu ek çabanın gelecekteki her senaryoda işe yarayacağının garantisi yoktur. Yine de hoca, %30'un üçte bir demek olduğunu ve önemli bir oran olduğunu da ekledi.

Eksiler şunlardır:

- Uygun bileşenlerin bulunması gerekir ve her zaman bulunamaz. Bulunamazsa eksik özellikler için bileşenleri kendimiz yazarız. Bu ileriye yönelik bir yatırımdır ama projeyi planlanandan yavaşlatır, geliştirme sırasındaki aksaklıklar projenin başarısını doğrudan tehdit eder.
- Bileşenlerin uyarlanması gerekir ve bu göründüğü kadar kolay olmayabilir; özellikle kaynak kodu bizim tarafımızdan yazılmamışsa.

Hoca, sınıflandırma ve seçme aşaması çok karmaşık ve riske açık olduğu için kendisinin bu çalışma biçimini çok tercih etmediğini söyledi. Sonuç olarak bu modelin ana fikirleri, özellikle önceki hafta görülen hızlı uygulama geliştirme (RAD) olmak üzere başka süreçlere uygulanabilir. RAD ile çalışılabilecek bir problemde hazır bileşen kullanmak çok rahatlatıcı olabilir.

## 3. Artımsal ve Yinelemeli Modeller

Artımsal "incremental", yinelemeli "iterative" demektir (ekrandan, 00:45:00). Bu modellerin ortak yönü, geleneksel sürecin adımlarının çevrimsel olarak yürütülmesidir. Slayttaki gösterim şöyledir:

```text
Adımlar:  [ Analiz -> Tasarım -> Kodlama -> Sınama ] --> Bakım
               ^                                |
               |________________________________|
```

Bir miktar analiz yapılır, sonucuna göre tasarım yapılır, tasarlanan kısım koda dökülür, kod sınanır ve tekrar bir miktar analiz yapılır. Bu çevrim bütün gereksinimler gerçeklenene kadar sürer; sonra yazılım kullanıma alınır ve bakım aşamasına geçilir.

### 3.1 Artım ile Yineleme Arasındaki Fark

- Bir çevrimde yeni bir işlev gerçekleniyorsa bu bir **artım**dır.
- Bir çevrim hata düzeltmek ya da değişen bir gereksinimi karşılamak için yapılıyorsa bu bir **yinelemedir**.

Proje yalnız yinelemeyle ilerlemez; ne kadar çok artım yapılırsa proje o kadar tamamlanmaya yaklaşır. Ama gereksinim değişiklikleri ve yanlış anlaşılan noktalar yüzünden yineleme çevrimleri de mutlaka olur.

Hangi işin ne zaman yapılacağına gereksinimler sınıflandırılarak karar verilir: gereksinimler önemlerine ve birbirine bağımlılıklarına göre sıralanır ve her çevrimde bunların bir kısmı tamamlanır.

### 3.2 Artılar ve Eksiler

Slayta göre bu modeller ön ürün (prototipleme) modeli ile ardışıl (şelale) modelin güçlü yönlerini bir araya getirip zayıf yönlerini geride bırakmıştır. Ayrıca en yaygın programlama yaklaşımı olan nesneye yönelik programlama ile uyumludurlar.

Hoca sınıfa bu modellerin dezavantajının ne olabileceğini sordu ve cevabı kendisi verdi: miyopi. Yakını görüp uzağı görememek, ya da deyimle ağaçlara bakarken ormanı kaçırmak. Yazılımın küçük artımlarına fazla yoğunlaşırsak, sisteme bütüncül baktığımızda kolayca görebileceğimiz sorunları gözden kaçırabiliriz. Bunu önleyecek ek adımlar tanımlanmış ve uygulanıyorsa, bu modeller vaat ettiklerini yerine getirir. Slayttaki sonuç da budur: sistemin genelini göz ardı etmemek şartıyla güçlü bir modeldir. Örnek olarak sarmal model ve kazan-kazan modeli incelendi. Hoca bunların eski, klasik modeller olduğunu, bugün genelde kullanılmasalar da getirdikleri yeniliklerin güncel süreçlere uyarlandığını belirtti.

## 4. Sarmal (Spiral) Model

Sarmal modelde süreç merkezden başlayıp dışa doğru genişleyen bir spiral biçiminde ilerler (ekrandan, 00:50:00). Hoca aşamaları slayt üzerinde 1'den 6'ya numaralayıp ilk turu boyayarak gösterdi (ekrandan, 00:55:00). Aşamalar şunlardır:

1. **Müşteri ile iletişim: gereksinimlerin belirlenmesi.** Müşteri dinlenir, ihtiyacı anlaşılmaya ve açığa çıkarılmaya çalışılır; bir miktar gereksinim belirlenir.
2. **Planlama: kaynaklar, zamanlama, yapılacaklar vb.** Bu gereksinimleri karşılamak için neler yapılacağı, hangi kaynakların (insan kaynakları, kod bileşenleri, araçlar, alt yapılar) kullanılacağı ve hangi işin kaç hafta süreceği planlanır. Bu planlama çok teknik değildir.
3. **Risk analizi: teknik, mali ve politik riskler.** Projenin başarısını tehdit edebilecek riskler belirlenir ve yönetilir. Hoca bu çalışmanın olabildiğince geniş ve farklı alanlardan katılımcılarla yapılmasının en yararlı olduğunu söyledi.
4. **Mühendislik: çözümleme ve tasarım.** Asıl teknik planlama, yani tasarım bu aşamada yapılır.
5. **Gerçekleme ve kurulum: kullanıcı eğitimi, dokümantasyon vb. dahil.** Tasarım koda dökülür, kullanıcı eğitimi ve dokümantasyon eklenir, gerçeklenen kısım kullanıcı ortamına kurulur.
6. **Müşteri tarafından ürünün değerlendirilmesi.** Beşinci aşamada gerçeklenen kısım müşteri tarafından değerlendirilir ve birinci çevrim tamamlanır.

Hoca beşinci aşamayla ilgili önemli bir noktayı vurguladı: Her çevrimin sonunda kullanıcının en azından denemeye başlayabileceği bir parça ortaya çıktıysa bunu bekletmeden kullanıcıya vermek yararlıdır. Böylece gereksinimleri yanlış anladığımız için yanlış bir şey ürettiysek bunu çok daha erken öğreniriz. Şelale modelinin en önemli sorunlarından biri, müşterinin deneyebileceği kodun ortaya çıkmasının çok uzun sürmesiydi; yinelemeli modeller bu dezavantajı ortadan kaldırır.

### 4.1 Sonraki Çevrimler

Müşterinin değerlendirmesinden sonra ikinci çevrime geçilir. Müşteriden değişiklik istekleri alınır; değişiklik yoksa ilk aşama daha hızlı geçilebilir. Değişiklikler varsa ikinci aşamada ana plan revize edilir. Bu revizyonlar risk analizini değiştirebilir. Değişiklik olmasa bile iki çevrim arasında zaman geçmiştir; bu sürede problem alanında, mevzuatta ya da pazarda değişiklik olmuş olabilir. Bu yüzden risk izleme her çevrimde yapılır.

> **Hocanın vurgusu:** Risk yönetimi bir şemsiye süreçtir; sürekli tekrarlanması gereken, bütün süreci kapsayan bir alt etkinliktir. "Değişiklik yoksa bu aşamayı atlıyoruz" denmez.

Sonra yeni plana göre çözümleme ve tasarım, ardından gerçekleme ve kurulum yapılır, müşteri yeniden değerlendirir. Spiral böyle genişledikçe ortaya çıkan yazılımın hacmi de büyür. Sarmal modelin literatüre kazandırdığı en önemli özellik risk yönetiminin sürekli yapılmasıdır.

## 5. Kazan-Kazan (WinWin) Modeli

Kazan-kazan modeli de benzer bir spiral çalışma biçimine sahiptir, ama aşamalar farklıdır (ekrandan, 01:00:00). Adı "sen de kazan, ben de kazanayım" anlamındaki win-win'den gelir ve kazananlar paydaşlardır. Bu modelin getirdiği yenilik, çalışmanın paydaşlar üzerinden yürütülmesidir. Aşamalar şunlardır:

1. İlgililerin (paydaşların) belirlenmesi
2. Kazanma durumlarının belirlenmesi
3. Uzlaşma ve seçeneklerin belirlenmesi
4. Seçeneklerin değerlendirilmesi ve risklerin çözülmesi
5. Gerçekleme ve kurulum
6. İlgililer tarafından değerlendirmeler

### 5.1 Paydaş Kavramı

Slayttaki tanıma göre paydaş, yazılımın başarısı ve başarısızlığının etkileyeceği kişi ve kurumlardır. İngilizcesi "stakeholder"dır; hoca bunun boşluksuz tek kelime olarak yazıldığını belirtti. Türkçede "ilgililer" de denebilir, ama "paydaş" daha yaygındır.

Paydaş denince genellikle müşteri akla gelir, ama müşterinin içinde de alt paydaş grupları vardır. Ayrıca problem alanıyla ilgili kanun ve kural koyucu kurumlar varsa, özellikle proje çıktısının bir dış denetime tabi olduğu finansal uygulamalarda, onlar da paydaştır. Yazılım evi de bir paydaştır ve kendi içinde alt paydaşlara sahiptir: üst yönetim, yazılımcılar, ayrıysa sınama ekibi.

### 5.2 Çatışan Çıkarlar

Yazılım bütün paydaşlarını memnun etmeye çalışır, ama paydaşların çıkarları birbiriyle çelişebilir. Hocanın örneği bir bankacılık uygulamasıdır. Bankanın kullanıcıları (iç paydaşlar) kullanım kolaylığı ve yüksek performans ister. Finansal kurumları denetleyen düzenleyici kurum (Türkiye'de BDDK) ise denetim ister. Denetim için ek kayıtların tutulması, günlük (log) dosyalarının oluşturulması ve bunların raporlanması sisteme ek yük getirir ve kullanım kolaylığını da azaltabilir. Bu iki istek arasında bir uzlaşma, bir optimum denge noktası bulunmalıdır.

> **Ders sonrası not:** Hoca kurumun açık adını hatırlayamadığını söyledi. BDDK'nın açılımı büyük olasılıkla Bankacılık Düzenleme ve Denetleme Kurumu'dur.

### 5.3 Aşamaların İşleyişi

Kazanma durumları belirlenip aradaki çatışmalar keşfedildikten sonra üçüncü aşamada çatışan çıkarlar uzlaştırılır. Uzlaştırmanın farklı seçenekleri olabilir. En optimum seçeneği gerçeklemek çok uzun sürebilir; belki daha az iyi ama daha çabuk kullanıma alınabilecek bir çözüm gerekebilir. Bu seçenekler dördüncü aşamada değerlendirilir ve karar verilir; WinWin modeli risk yönetiminin de bu adımda yapılmasını öngörür. Beşinci aşama, önceki modeldeki gerçekleme ve kurulum aşamasıyla aynıdır. Değerlendirmelerden sonra yeni paydaşlar ortaya çıkmışsa eklenir ve kazanma durumları güncellenir; süreç böylece artımsal olarak ilerler. Bu modelin literatüre katkısı, paydaş kavramı ve paydaşlar arasında denge kurma gerekliliğidir.

## 6. Çevik Süreçler ve Çevik Manifesto

Aradan sonra çevik (agile) süreçlere geçildi. Hocaya göre "agile" sözcüğünün Türkçe karşılığı olarak "çevik" çok iyi oturmuştur. Slayttaki tanım şudur: Çevik süreçler, değişen gereksinimler, teknik riskler gibi önceden belirlenemeyen durumlara ve yazılım ürününü etkileyebilecek her tür değişikliğe karşı esneklik sağlayan süreçlerdir (ekrandan, 01:25:00).

Tek bir çevik süreç yoktur; birçok çevik süreç önerisi vardır. İlk temeller Çevik Manifesto'yu yayınlayan yazılımcılar tarafından atılmış, yıllar içinde ayrıntılar belirlenerek farklı çevik süreç modelleri ortaya çıkmıştır. Derste önce bunların ortak yönleri, sonra en yaygın iki örnek (XP ve Scrum) incelendi.

### 6.1 Manifestonun Dört Karşıtlığı

Slaytta iki sütun halinde sekiz madde vardır:

| Sol sütun (öncelikli) | Sağ sütun |
|---|---|
| Bireyler ve etkileşimler | Süreçler ve gereçler |
| Çalışan yazılım | Ayrıntılı belgeler |
| Müşterinin sürece katılımı | Sözleşme pazarlığı |
| Değişikliklere uyum sağlamak | Bir planı izlemek |

Manifestoyu yayınlayanlar bu maddelerin hepsinin önemli olduğunu kabul eder, ama bir çelişki çıktığında sol sütundakileri tercih ettiklerini belirtir. Slayttaki ifadeyle: Çevik süreçler, sağ taraftaki maddelerin yararını kabul etmekle birlikte sol taraftaki maddelere daha çok önem vermektedir. Hoca her karşıtlığı çatışma örnekleriyle açıkladı.

**Bireyler ve etkileşimler / süreçler ve gereçler.** İyi tanımlanmış bir süreç ve iyi kullanılan gereçler başarıya götürür. Ama ister çevik ister geleneksel yaklaşılsın, yazılım proje yönetiminin birinci odak noktası bireylerdir. Yazılım bir "insan işi"dir (people job): Doğru kişilerle doğru biçimde çalışılmazsa diğer bileşenler ne kadar mükemmel olursa olsun proje başarısız olur. Kullanılan süreç modelinin kuralları bireyler arasındaki etkileşimi zayıflatıyorsa, bu kuralları kaldırmak ya da esnetmek daha başarılı kılar. Ekip sürecin gerektirdiği çalışma biçimine uygun değilse ya başka kişilerle çalışılır ya da süreç ekibe uyarlanır; çevik manifesto ağırlığı bireylere verir ve süreçlerin buna göre değiştirilebileceğini söyler.

**Çalışan yazılım / ayrıntılı belgeler.** Teknik belgelendirme ve son kullanıcı belgelendirmesi çok önemlidir ve bunun aksi söylenemez. Ama bu belgelerin bir maliyeti vardır ve en önemlisi müşteriye çalışan yazılım sunmaktır. Zaman sıkışıklığı varsa belgeler daha az ayrıntılı, daha genel hatlarıyla hazırlanabilir.

> **Hocanın vurgusu:** "Önce kodu tamamlayalım, belgelendirme sonra gelir" diye düşünmek teknik personelin en önemli yanılgılarından biridir. Çevik çalışmak belgelendirme yapmamak demek değildir; çevik süreçlerde özellikle teknik belgelendirme proje başarısı için daha da önemli olabilir.

**Müşterinin sürece katılımı / sözleşme pazarlığı.** Sözleşme, gereksinim belirleme ve analiz olgunlaştıktan sonra maliyet ve zaman açısından nihai hale getirilir. Yapılan işi kanuni bir temele oturtur, olası anlaşmazlıkların hangi kurallar çerçevesinde çözüleceğini belirler. Belirli bir müşteriye yönelik projede sözleşme şarttır; kurum içi projelerde bile ilgili paydaşlarla bir kurum içi sözleşme yapılabilir. Ama sözleşme asla değişmeyecek bir belge değildir; değişiklik yöntemleri sözleşmeye yazılmışsa değişiklik kolayca yapılabilir. Asıl çelişki, müşterinin "sözleşmeyi yaptık, artık gerisine karışmayız" diye düşünmesidir. Çevik süreçler ise müşterinin sürece olabildiğince geniş, sürekli ve sık katılımını ister; çünkü değişikliklerin kaynağı çoğunlukla müşteri ve onun çalışma koşullarıdır, yazılım da zaten müşterinin işini kolaylaştırmak için yapılır.

**Değişikliklere uyum sağlamak / bir planı izlemek.** Yazılım proje planı yapılmalı ve izlenmelidir; hocanın deyişiyle "haritasız yola çıkan kaybolur". Ama her şey en ince ayrıntısına kadar planlanamaz ve değişim kaçınılmazdır. Koşullara rağmen plana körü körüne bağlı kalmak başarısızlığa götürür; plan taşa yazılmaz, değişiklikler ortaya çıktıkça revize edilir.

### 6.2 Uyum Yetmez, İlerleme Gerekir

Slayttaki son madde, bir ilerleme olmaksızın yalnızca sürekli uyum sağlamanın başarı olmadığını söyler. Çevik süreçler:

- yazılımın artımsal gelişimini ister,
- müşteriye mümkün olduğunca erken ve sık ürün teslimini öngörür,
- başarının birincil ölçütü olarak doğru çalışan yazılımı görür.

Bu nedenle sınama çok önemlidir ve test güdümlü tasarım (TDD: Test Driven Design, Test Driven Development diye de geçer) tavsiye edilir, ama zorunlu tutulmaz.

### 6.3 Test Güdümlü Tasarım

Test güdümlü geliştirme, işleri kodlamaya başlamadan önce testlerinin kodlanmasını önerir. Test güdümlü tasarım ise, bir kısmı tasarlamadan önce o kısmın doğru çalışıp çalışmadığını nasıl sınayacağınızı tasarlamanızı ister. Gerekçe şudur: Düzgün ve verimli biçimde test edemediğiniz bir şeyi büyük olasılıkla doğru tasarlayamamışsınızdır.

Hoca önceki derslerde verilen iyi tasarım tanımını hatırlattı: Problem alanı hangi düzeyde parçalara ayrılabiliyorsa, o düzeyde alt bileşenlere ayrılabilen tasarım iyi tasarımdır. Modellediğimiz sistemde bir işi tek başına test edemiyor, ancak bir iki başka işle birlikte test edebiliyorsak, bu işler arasındaki veri, işlem ve sorumluluk ayrımını iyi yapamamışız demektir. Test tasarlarken bunu erkenden fark ederiz.

Hoca testlerin tasarımdan önce, bir alt birim tasarlandıktan hemen sonra ya da en kötü durumda bütün tasarımdan sonra tasarlanabileceğini, ama mutlaka tasarlanması gerektiğini söyledi. Yıllar geçtikçe sınamaya gitgide daha az önem verildiğini ve bunun ciddi sorunlara yol açtığını ekledi.

## 7. Çevik Süreci Yürütecek Ekibin Özellikleri

Çevik süreçler müşteriye çalışan kod teslimine ve bireylere çok önem verdiği için ekibin özellikleri ayrıca tartışılır (ekrandan, 01:40:00).

**Yüz yüze görüşme en etkili bilgi aktarım yoludur.** Hoca bu maddeye yürekten katıldığını söyledi. Konuşulanlar unutulmaya karşı yazıya geçirilebilir, ama işe yüz yüze görüşmeyle başlamak en iyisidir. Yine de yüz yüze görüşenler bile birbirini tam anlayamayabilir; herkes kendi geçmiş deneyimi ve algı perspektifinden, bazen ön yargıyla girdi alır. Çevik süreçler yüz yüze görüşmeyi teşvik eder ve süreç adımlarına yerleştirir.

**Takım üyeleri çevik yaklaşım hakkında eğitilmelidir.**

**Ekip üyelerinin ortak amacı, çalışan yazılım üreterek müşteriye zamanında teslim etmek olmalıdır.**

**Ekip üyeleri birbirleriyle ve müşteriyle işbirliği içinde olmalıdır.** Bu işbirliği sürekli, sık ve yakın olmalıdır. Belirli bir müşteri için kodlanmıyorsa bile yazılım evinden biri mutlaka müşteri rolünü üstlenir; bu kişiye "product owner" denir.

**Ekip üyeleri karşılıklı saygı ve güven içinde olmalıdır.** Birbirinin altını oymak ya da "bu belgeyi bu ayrıntıda yazarsam sonra beni kolayca devre dışı bırakırlar" gibi düşünceler olmamalıdır. Üst yönetim de şeffaf, samimi ve güvenilir olduğunu göstermelidir.

**Ekipler hem teknik hem de tüm proje hakkında kararlar verebilmelidir.** Ekip, üyelerinin yetenek ve deneyimine bakarak kullanılacak süreçler, yöntemler, araçlar ve planlama yaklaşımı hakkında karar verebilmeli ve uygulayabilmelidir. Ölçek büyüdükçe üst yönetime danışılabilir, ama üst yönetim projenin en içindeki çalışanlara güvenmelidir.

**Boşuna harcanan çaba yoktur.** Slayttaki ifadeyle: Çözülen bir sorun gereksizleşse bile, çözüm sürecinde edinilen deneyim ekibe ileri aşamalarda yararlı olabilir. Esneklik bazen yapılan bazı işlerin kullanılmamasına yol açar; bu durumda moral bozulmamalıdır. İnsan hatalarından da öğrenir; kullanılmayan bir artım bile deneyim kazandırır ve belki başka projelerde kullanılır.

**Kendi kendini düzenleme.** Slayta göre bu üç şey içerir: ekibin kendisini yapılacak işe göre uyarlaması, kullanacağı süreci yerel ortama uyarlaması ve üzerinde çalışılan artımsal yazılım parçasını teslim etmek için gereken çalışma zamanlamasını kendisinin belirlemesi. Hocanın örneği: Zor ve kritik bir çevrim fazla mesaiyle zamanında tamamlandıysa, daha kolay olan sonraki çevrimde ekip biraz daha rahat çalışabilmeli; geç gelmek, erken çıkmak, öğle arasını uzatmak gibi esneklikler tanınabilmelidir. İnsanlarla çalışıyoruz; her insanın gerçekçi bir yük kapasitesi vardır. Normal sınırın belirgin biçimde üstündeki tempo kişiyi yıpratır ve proje boyunca sürdürülemez. Bütün paydaşlar bu konuda da bilgilendirilmelidir.

## 8. Çevik Süreçlerin Dezavantajları

Hoca önceki derste gösterdiği proje başarı istatistiklerinde çevik süreçlerin gerçekten iyileşme sağladığını hatırlattı, ama bunların sihirli değnek olmadığını vurguladı (ekrandan, 01:50:00). Slayttaki dezavantajlar şunlardır:

**Uygun olmayan ekiple çevik çalışılamaz.** Hoca buna kurum kültürünü de ekledi: Kurum kültürü uygun olmayan yazılım evleriyle, hatta müşterilerle de çevik çalışılamaz. Çalışanların nitelikleri (deneyim, güçlü ve zayıf yönler, iş tutumu) çevik sürece uygun değilse en iyi alternatif çoğunlukla şelale modelidir. Hiyerarşi ve yetki yaklaşımı ağır basan kurumlara görev ve sorumlulukların en net tanımlandığı klasik model uyar.

**Kalabalık ekip veya büyük ölçekli projeler için uygun görülmemektedir.** Çevik süreçler ekip içinde ve müşteriyle sıkı, yüz yüze etkileşime dayanır. Ekip ve ilgili sayısı arttıkça bu etkileşim üstel olarak zorlaşır. Ekip üyeleri ve müşteriler farklı ofislerdeyse yüz yüze görüşmek zaten zorlaşır; telefon ya da video konferans aynı verimi vermez, farklı ülkelerdeki farklı saat dilimleri işi daha da zorlaştırır. Hoca, çevik süreçleri büyük ölçeğe uyarlamaya yönelik çalışmalar olduğunu ama bunların sahada yeterince doğrulanmadığını, sorunun ciddiyeti azalsa da hâlâ var olduğunu belirtti.

**Bir dış denetleyicinin dahil olduğu ve ayrıntılı kuralların gerektiği denetimlerin zorunlu olduğu projelerde yetersiz kalmaktadır.** Bu tür projelerde hiçbir şekilde esnetilemeyecek düzenlemeler vardır; katı düzen, kontrol, hiyerarşi ve yetki gereksinimleri çevik çalışma biçimine taban tabana zıttır. Çevik başlanan süreç zamanla kendiliğinden şelale modeline döner; bu yüzden en baştan o şekilde çalışmaya karar vermek daha doğrudur. Finans, sigortacılık ve bankacılık gibi alanlardaki projeler bu duruma tipik örneklerdir.

**Çevik çalışmak disiplinsizlik olarak yorumlanmamalıdır.** Ekip kendini düzenler, karar alır, esnektir; ama bu disiplinsizliğe dönüşmemeli ve ekibe duyulan güven kötüye kullanılmamalıdır.

Slayttaki çevik süreç örnekleri Aşırı Programlama (XP: Extreme Programming) ve Scrum'dır.

## 9. Aşırı Programlama (XP)

XP'nin adımları planlama, tasarım, kodlama ve sınamadır (ekrandan, 02:00:00). Slayttaki gösterim şöyledir:

```text
Adımlar:  Planlama -> Tasarım -> Kodlama -> Sınama ----> Artımsal Ürün
            ^                                  |
            |__________________________________|
```

Sınamadan sonra tekrar planlamaya dönülür ve yeni bir çevrim başlar. Yeni çevrim yeni bir işlevin gerçeklenmesi, mevcut sistemin düzenlenmesi ya da bir hatanın giderilmesiyle ilgili olabilir. Her çevrimin sonunda o ana kadar elde edilen artımsal ürün kullanıcıya verilir, kullanıcının denemesi sağlanır ve ağırlıklı olarak yüz yüze alınan geri bildirimler planlama aşamasında projeye dahil edilir. İlk çevrimlerde planlama adımları daha ağır basabilir.

### 9.1 Planlama

Slayttaki maddeler şunlardır:

- Müşteri, kullanıcı öykülerini (user story) oluşturur.
  - Müşteri öyküleri önemine göre derecelendirir.
  - Yaklaşık 3 haftada gerçeklenemeyecek öyküler varsa ekip müşteriden bunları alt öykülere bölmesini ister.
- Ekip ve kullanıcı, öykülerin sıradaki artımsal ürüne nasıl ekleneceğine karar verir:
  - Ya önce yüksek riskli öyküler gerçeklenir,
  - Ya da önce yüksek öncelikli öyküler gerçeklenir.
  - Her olasılıkta tüm öyküler kısa sürede (birkaç hafta) gerçeklenmelidir.

Hoca derste kullanıcı öyküsü yerine daha genel bir kavram olan "kullanım senaryosu" teriminin kullanılacağını, kullanım senaryolarının ayrıntılarının ve ilişkilerinin UML şemaları ve kullanım senaryosu metinleriyle ele alınacağını söyledi. Öyküleri ağırlıklı olarak müşteri yazar, ama yazılım ekibindeki uzmanlar onu yönlendirir. Öykülerin hepsi bir araya gelince bilgi sistemini oluşturur.

Müşteri öyküleri 3, 4 ya da 5 dereceli bir Likert ölçeğiyle derecelendirebilir; örneğin çok önemli, önemli, orta önemli, az önemli, çok az önemli. Teknik ekip de öykülerin yaklaşık 3 haftada gerçeklenebilecek büyüklükte olmasına dikkat eder. Buradan bir çevrimin, yani iki planlama arasında bir artımsal ürün çıkaran sürenin, yaklaşık 3 hafta olduğu anlaşılır. Bu 2 haftaya inebilir, 4 haftaya çıkabilir; daha uzunu istenmez (hocanın ifadesiyle "3 artı eksi 1"). Örneğin 5 haftalık bir öykü 3 + 2 hafta olacak biçimde ikiye bölünür ve iki çevrimde gerçeklenir.

Sıralamaya karar verirken müşteri öyküleri kendisi için önemine göre, teknik ekip de teknik risk, zorluk ve karmaşıklığa göre derecelendirir. İki seçenek müşteriye anlatılır ve son tercihi müşteri yapar:

- **Önce yüksek riskli öyküler.** Risk gerçekleşip başarısız olacaksak bunun olabildiğince erken olması istenir ("zararın neresinden dönülse kârdır"). İngilizcedeki karşılığı "fail fast, fail safe" gibidir: başarısız olacaksan çabuk başarısız ol ki güvende kal. Ama bu müşteri için her zaman en uygun çözüm olmayabilir.
- **Önce yüksek öncelikli öyküler.** İleride yüksek riskli bir öykünün gerçeklenemeyeceği ortaya çıksa bile müşterinin elinde o ana kadar işine yarayan bir ürün olur.

### 9.2 Planlama (Devam): Proje Hızı

İlk artımsal ürün projenin hızını ölçmek için de değerlendirilir (ekrandan, 02:05:00). Slayttaki maddeler:

- Eldeki artımın hızına göre sonraki artımların teslim tarihleri belirlenir.
- Aşırı sözler verildiği ortaya çıkarsa artımsal ürünlerin içeriği de yeniden kararlaştırılabilir.
- Süreç ilerledikçe müşteri yeni öyküler ekleyebilir, eski öykülerin önceliğini değiştirebilir, öyküleri farklı şekillerde bölüp birleştirebilir, bazı öykülerden vazgeçebilir. Bu durumda ekip kalan artımları ve iş planlarını uygun biçimde değiştirir.

Hocanın sayısal örneği şöyledir:

- **Verilen:** 10 öykü, her biri için 3 haftalık çevrim planlanmış.
- **Plan:** $10 \times 3 = 30$ hafta. Ayı kabaca 4 hafta alırsak $30 / 4 = 7{,}5$, yani "7 ay civarı".
- **Gerçekleşen:** Birkaç çevrimden sonra çevrimlerin 3 değil 4-5 hafta sürdüğü görülüyor. Çevrim 4 haftaya sabitlenirse $10 \times 4 = 40$ hafta, yani $40 / 4 = 10$ ay.
- **Sonuç:** Proje yaklaşık 7 aydan yaklaşık 10 aya sarkar.

Bu durumda ekip öyküleri belirlerken yeterince hassas davranamadığını kabul eder ve müşteriyle yeniden anlaşır. Müşteri ya uzamayı kabul eder, ya da "şu öyküler olmasın, yine 7 ayda istiyorum" der, ya da arada bir yol seçer (örneğin 7,5-8 ayda, bazı öyküler çıkarılarak). Benzer şekilde müşteri sürekli yeni öykü ekliyorsa her yeni öykü projeyi yaklaşık bir çevrim kadar uzatır; hem bütün öyküleri hem de aynı bitiş tarihini istemek gerçekçi değildir. Bu noktada "müşteri her zaman haklıdır" yaklaşımı uygulanır, ama plan buna göre değiştirilir.

> **Ders sonrası not:** Hoca hesapta ayı yuvarlak 4 hafta aldı. Bir ay ortalama yaklaşık 4,35 hafta olduğundan 30 hafta yaklaşık 6,9 ay, 40 hafta yaklaşık 9,2 aydır. Örneğin mesajı değişmez: çevrim süresindeki küçük bir artış toplam süreyi orantılı biçimde uzatır.

### 9.3 Tasarım

Slayttaki maddeler şunlardır (ekrandan, 02:10:00):

- Basit tasarım karmaşık gösterimden üstündür (KISS: Keep It Simple, Stupid!).
- CRC (Class-Responsibility-Collaboration) kartları ile yazılımın sınıf düzeyinde incelenmesi.
- Karmaşık bir tasarımdan kaçınılamazsa işlevsel bir ön gerçekleme yapılır (spike solution).
- Refactoring teşvik edilir.
- Bu aşamanın ürünleri CRC kartları ve ön gerçeklemelerdir (başka ürün yok).

**KISS ilkesi.** Mümkün olduğu kadar basit, sade ama amaca yönelik tasarım yapılır ve gereksiz karmaşıklıktan kaçınılır. Hoca kısaltmanın ilk bakışta sevimli göründüğünü, ama açılımının bir işi gerektiğinden karmaşık hale getirmenin yanlış olduğunu söylediğini belirtti.

**Spike solution.** Ne yapılırsa yapılsın bir öykünün tasarımı doğası gereği karmaşık kalıyorsa işlevsel bir ön gerçekleme yapılır. Bu bir prototip, demo ya da kavram kanıtı (proof of concept) gibi düşünülebilir; XP terminolojisindeki adı spike solution'dır. İşe yarıyorsa kullanılır; yetmediği noktalar varsa tasarım yetişirse bu çevrimde, yetişmezse sonraki çevrimde değiştirilir ya da o kısım baştan yapılır.

**Refactoring.** Yazılımın dışarıya verdiği hizmetleri ve etkileşim arayüzlerini değiştirmeden iç tasarımını değiştirmektir.

CRC kartı kullanılmıyorsa bu aşamanın çıktısı bir UML sınıf şeması olabilir. Hoca CRC kartlarını XP'nin önerdiğini ama zorunlu tutmadığını, projede de istemediğini söyledi.

### 9.4 CRC Kartı

Hoca bir CRC kartı örneği gösterdi. <!-- BELİRSİZ: Kartın gösterildiği slaytın karesi yok; aşağıdaki içerik altyazıdan kurulmuştur, kartın tam yazımı doğrulanamadı. --> CRC'nin ilk harfi "class"tır; her kart tek bir sınıf içindir ve nesneye yönelik programlama kullanıldığı varsayılır. Kartın yapısı şöyledir:

- **Başlık:** sınıfın adı.
- **Altında bir cümle:** sınıfın en temel görevi ya da problem alanında hangi varlığa karşılık geldiği.
- **Alt satırlar:** sınıf bir kalıtım hiyerarşisindeyse üst ve alt sınıfları. Bazı dillerde (örneğin C++) bir sınıfın birden fazla üst sınıfı olabilir.
- **Sol sütun:** sınıfın sorumlulukları.
- **Sağ sütun:** sınıf bir sorumluluğu tek başına yerine getiremiyorsa birlikte çalıştığı sınıflar (işbirlikçiler).

Hocanın örneğindeki kart, kasada yapılan ödemeyi simgeleyen bir "Satış" sınıfına aittir. Sorumluluklarından ikisi şunlardır:

| Sorumluluk | İşbirlikçi |
|---|---|
| Satışın yapıldığı tarih ve saati saklamak | (tek başına) |
| Yapılan ödeme tutarını saklamak | Ödeme |

Ödeme tutarını saklama sorumluluğu bir Ödeme nesnesiyle birlikte yerine getirilir; hocaya göre bu büyük olasılıkla bir sahiplik ilişkisidir. Bu ilişki türleri önceki yılın nesneye yönelik programlama dersinde görülen kavramlardır.

**CRC kartları ne sağlar?** Örneğin 5 kişilik bir ekip ve 100 sınıflık bir tasarım olsun. Her sınıf için bir kart hazırlanır ve herkese eşit sayıda, yani kişi başına 20 kart dağıtılır. Herkes önce kendi kartlarını inceler; mantığına yatmayan ya da yanlış gördüğü bir nokta varsa dile getirir. Ya diğer üyeler bu görüşün neden yanlış olduğunu açıklayıp onu ikna eder, ya da gerçekten bir hata bulunmuştur ve düzeltilir. Sonra desteler el değiştirir ve herkes başka bir 20 kartı inceler. Böylece:

- bütün tasarım bütün ekip tarafından gözden geçirilir,
- herkes kendisinin kodlamayacağı kısımlardan da haberdar olur; bu, sonraki çevrimlerde o kısımda çalışırken ya da başka bir üyenin işlevine ihtiyaç duyduğunda işe yarar.

Hoca CRC kartlarının ülkemizdeki yazılım evlerinde pek kullanıldığını görmediğini, bunun yerine çabanın daha ayrıntılı teknik dokümantasyona ya da sınamaya harcanabileceğini söyledi.

### 9.5 Kodlama

Slayttaki maddeler şunlardır (ekrandan, 02:20:00):

- Önce birim sınamaları hazırlanır.
  - Programcı tarafından yapılan, sınıfların (NYP'de; yapısalda fonksiyonlar vb.) temel işlevselliklerini sınama amaçlı kod.
  - Sadece sınavı geçmeye yarayan kod yazılır (KISS).
- Çift kişi ile kodlama:
  - Bir programcı eldeki sorunu çözerken diğeri çözümün genel tasarıma uygunluğunu gözetir ve kodlamanın takımın karar verdiği ölçütlere (kalite vb.) uygunluğunu denetler.

Test güdümlü çalışma önerilir ama şart değildir. XP'ye adını veren ve onu en çok ayırt eden özellik çift kişiyle kodlamadır (pair programming): Bir bilgisayarın başında iki kişi oturur. İkinci kişi yazılan kodun genel tasarıma uygun olup olmadığını, kalite ve sınanabilirlik ölçütlerine uyup uymadığını, kararlaştırılan kodlama standartlarına (girintileme, karmaşıklık vb.) uyup uymadığını, nesneye yönelik tasarım ilkelerine uygun olup olmadığını değerlendirir.

> **Hocanın vurgusu:** Çift kişiyle kodlama, artımsal ve yinelemeli süreçlerin en zayıf noktası olan bütüncül bakışın kaybolması sorununu engellemeye yönelik bir çalışma biçimidir. Bir programcı eldeki soruna, diğeri sistemin bütününe odaklanır.

Hoca bunu tüplü dalışla açıkladı. Tüplü dalışta tek başına dalınmaz; her biri ayrı tüp kullanan iki dalgıç birlikte dalar ve birbirini kollar (dalış arkadaşı, "buddy" sistemi). Su altı insan için çok uygunsuz bir ortamdır; nefes alma sistemindeki en ufak bir arıza ölümcül olabilir. Yazılım işi tehlikeli olmasa da çok riskli, karmaşık ve zordur, hatta ortaya çıkan sistem kritik görevlerde (mission critical) kullanılabilir. Bu yüzden XP çift kişiyle kodlamaya çok önem verir. Hoca, insan kaynakları ya da başka bir nedenle çift kişiyle kodlama yapılamayacaksa XP yerine Scrum kullanılabileceğini söyledi.

### 9.6 Sınama

Slayta göre sınama aşamasında birim sınamaları otomatik çalıştırılır ve müşteri artımsal ürünü dener. Birim sınamaları ve tümleştirme sınamaları baştan önerilir; öyle yapılmadıysa bile kodlamanın ardından sınamalar tasarlanıp mutlaka yürütülür. Her çevrimde sınama yapılmak zorundadır ve bu olabildiğince otomatikleştirilir. Önceki bileşenlerin ve onlarla ilişkili kısımların yeniden sınanmasına regresyon testi denir; ayrıntıları sınama konusunda işlenecektir. Bu sınamaların sonuçları ve müşterinin denemesi bir sonraki çevrime girdi olur.

## 10. Scrum

Scrum'ın adı Türkçeye pek çevrilememiştir (ekrandan, 02:25:00). Hoca kökenini ragbi oyunundan anlattı: Scrum, oyunda topu taşıyan oyuncunun rakip sahaya geçip sayı yapabilmesi için bütün ekibin bir araya gelip onu çevrelemesi ve birlikte ilerlemesi gibi bir taktiktir. Kod yazarken de ekibin benzer biçimde birlikte çalışması gerektiği düşünülerek süreç bu adı almıştır.

> **Ders sonrası not:** Hoca ragbiyi Avustralya'da oynanan bir oyun gibi anlattı; ragbi büyük olasılıkla İngiltere kökenlidir ve birçok ülkede oynanır. Hoca ayrıca ortadaki "koşu" adımının İngilizcesinin Scrum olduğunu söyledi; koşunun İngilizce karşılığı "sprint"tir, Scrum sürecin bütününün adıdır.

### 10.1 Adımlar

Slayttaki gösterim şöyledir:

```text
Adımlar:  Görev Listesi -> Koşu -> İşlev Gösterimi
                 ^                        |
                 |________________________|
```

Bu adımlar kabaca XP'nin adımlarıyla örtüşür. Slayttaki maddeler:

- Görev Listesi = Kullanıcı öyküleri.
  - Önceliklendirilmiştir.
- Koşu:
  - Görev listesinin maddelerinden biri seçilir ve önceden belirlenmiş kısa bir süre içerisinde (Ör. 1-4 hafta) gerçeklenir.
  - Koşu süresince ekibin her gün yaptığı kısa (Ör. 15 dk) toplantılar:
    - Proje lideri yönetir.
    - Cevaplanmaya çalışılan üç ana soru: Son toplantıdan bu yana ne yaptınız? Karşılaştığınız engeller nelerdir? Yarınki toplantıda neleri başarmayı hedefliyorsunuz?
- İşlev Gösterimi: Müşterinin en yeni işlevi veya o ana dek gerçeklenen tüm işlevleri sınaması.

**Görev listesi.** Scrum'ın görev listesi XP'nin kullanıcı öyküleriyle aynıdır; aynı şekilde planlanır, kategorilendirilir, eklenir ve silinir.

**Koşu.** Çevik süreçlerin özü gereği kısa sürelidir. Scrum'ın ayırt edici özelliği her gün toplantı yapılmasıdır. Bunlar saatler süren toplantılar değil, yaklaşık 15 dakikalık kısa toplantılardır; hoca en fazla 15-20 dakika dedi. Verimlilik için söz hakkını bir kişinin vermesi gerektiğinden toplantıyı proje lideri yönetir ve herkese üç soruyu sorar. Bu soruları net yanıtlayamayan kişi ya da takımlarla proje lideri toplantıdan sonra ayrıca ilgilenir ve birlikte çözüm yolu aranır. Bu toplantılar herkesin diğer üyelerin neyi nasıl yaptığından, özellikle kritik noktalardan haberdar olmasını sağlar; sonraki çevrimde başkasının işi üzerine iş koyacak kişi o kısma daha kolay hakim olur.

**İşlev gösterimi.** Müşteri yalnız en yeni artımı ya da o ana kadarki bütün işlevleri birlikte sınayabilir. Ekip kendi birim testlerini çalıştırır, müşteri de kendi sınamalarını yürütür.

### 10.2 Pre-scrum, Main Scrum ve Post-scrum

Hoca slayt üzerine çizerek (ekrandan, 02:30:00) üç adımlı ana çevrimi "main scrum" olarak çevreledi, öncesine bir "pre-scrum", sonrasına bir "post-scrum" aşaması ekledi.

- **Pre-scrum:** Görev listesinin ana hatlarıyla belirlenmesi, gerekli analiz çalışmaları, daha dikkatli bir risk analizi isteniyorsa ilk aşamaları, başarı ölçütlerinin belirlenmesi, süreçte hangi yazılım kalite ölçütlerinin kullanılacağı ve hangi aralıkla toplanacağı gibi, çevik koşu biçiminde sürekli uygulanmaya uygun olmayan ön etkinlikler. Manifestonun sağ sütunundaki işlerin önemli bir kısmı burada tanımlanabilir. Ama ana çevrime bir kez başlandıktan sonra çevik ilkelerden ödün vermeden devam edilmelidir.
- **Post-scrum:** Bütün öyküler gerçeklendikten sonra, yazılım canlıya alınmadan ve bakım başlamadan önce yapılması gerekenler. Örneğin kabataslak bırakılan belgelendirmenin ayrıntılarını tamamlamak. Hoca proje sonunda bir kutlama yapmayı da ekip dayanışmasını ve aidiyet duygusunu güçlendiren bir post-scrum etkinliği olarak önerdi.

Bu ek aşamalar XP'ye de uygulanabilir. Çevik süreçler adımların harfiyen uygulanmasını şart koşmaz; özünde esneklik vardır.

## 11. Çevik Modelleme ve Denge

Son slaytta çevik modelleme ilkeleri yer alır (ekrandan, 02:35:00):

- Bir amaç için modelleme yapın:
  - Neyi, kime, hangi düzeyde anlatmak istiyorsunuz?
  - Buna göre uygun modelin ve ayrıntılandırmanın seçimi.
- İçerik sunumdan daha önemlidir.
  - Gerekli bilgiyi içermeyen hatasız model işe yaramaz!
- Kullandığınız modelleme yolunun özünü ve modellerinizi oluşturmak için kullanacağınız araçları iyi öğrenin.
- DİKKAT: Önemli olan dengeyi korumaktır.
  - Çevik çalışacağız diye serseri programcı olmayın.
  - Disiplinli çalışacağız diye sırtınızda tuğla çuvalı taşımayın.

Hoca bu ilkeleri örneklerle açtı. Yazılımın karmaşık bir kısmını ilk kez belgeliyorsak, ekibin bütün üyelerine ve ileride bakım ya da yeni sürüm üzerinde çalışacak kişilere yönelik olabildiğince ayrıntılı ve teknik bir anlatım seçilir. Buna karşılık birimler arasındaki bilgi, veri ya da iş akışını anlatmak istiyorsak, örneğin bir etkinlik (activity) şeması en ince ayrıntılara girmeden orta düzeyde çizilir; gereksiz ayrıntı gereksiz çaba demektir ve zaten süre baskısı vardır. Gölgelendirme, yazı tipi, renk gibi süslemelerden çok, müşterinin ya da teknik personelin bilmesi gereken içeriğin modelde bulunup bulunmadığı önemlidir. Kullanılacak araçlar da verimli kullanılabilmeleri için iyi öğrenilmelidir. Son olarak çevik süreçlerde de denge korunmalıdır: ne çeviklik bahanesiyle disiplinsiz çalışılmalı ne de disiplin adına gereksiz yükler taşınmalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:48:09): Artımsal ve yinelemeli modellerin önemli bir dezavantajı ne olabilir?

> **Çözüm (derste verildi):** Miyopi, yani "ağaçlara bakarken ormanı kaçırmak". Yazılımın küçük artımlarına fazla yoğunlaşmak, sisteme bütüncül bakıldığında kolayca görülebilecek sorunların gözden kaçmasına yol açabilir. Bunu önleyecek ek adımlar (örneğin XP'deki çift kişiyle kodlama) uygulanırsa model güçlüdür.

**Soru 2** (derste sözlü, 02:14:51): CRC kartları ekibe ne sağlar?

> **Çözüm (derste verildi):** Kartlar ekip üyelerine eşit dağıtılır, herkes kendi destesini inceleyip itirazlarını tartışır, sonra desteler el değiştirir. Böylece bütün tasarım bütün ekip tarafından gözden geçirilir, hatalar erken bulunur ve herkes kendisinin kodlamayacağı kısımlardan da haberdar olur.

**Soru 3** (derste sözlü, 02:04:21): 10 kullanıcı öyküsü 3 haftalık çevrimlerle planlanmıştır, ama çevrimler fiilen 4 hafta sürmektedir. Proje süresi nasıl değişir ve ne yapılabilir?

> **Çözüm (derste verildi):** Plan $10 \times 3 = 30$ hafta (ayı 4 hafta alarak yaklaşık 7 ay) iken gerçekleşen $10 \times 4 = 40$ hafta (yaklaşık 10 ay) olur. Müşteriyle yeniden anlaşılır: ya uzama kabul edilir, ya bazı öyküler çıkarılarak süre korunur, ya da arada bir uzlaşma bulunur.

## Dersin Toparlaması

Bu derste klasik süreç modellerinden çevik süreçlere geçiş tamamlandı. Bileşen tabanlı geliştirme yeniden kullanımı öne çıkarırken bileşen seçiminin riskli ve maliyetli olabileceğini gösterdi. Artımsal ve yinelemeli modeller analiz-tasarım-kodlama-sınama döngüsünü çevrimsel hale getirerek müşterinin erken geri bildirim vermesini sağlar; sarmal model sürekli risk yönetimini, kazan-kazan modeli paydaş kavramını ve çıkar dengesini literatüre kazandırmıştır. Bu modellerin ortak riski, küçük artımlara odaklanırken sistemin bütününü gözden kaçırmaktır.

Çevik süreçler Çevik Manifesto'nun dört önceliğine (bireyler, çalışan yazılım, müşteri katılımı, değişime uyum) dayanır; uygun ekip ve kültür, makul ölçek ve dış denetimin olmaması gibi koşullarda başarılıdır. XP kullanıcı öyküleri, KISS, CRC kartları, spike solution, refactoring, önce birim testi ve çift kişiyle kodlama ile; Scrum ise görev listesi, kısa koşular ve günlük kısa toplantılarla çalışır. Derste, bir sonraki konunun sürece ilişkin diğer konular olacağı ve proje kapsamındaki uygulamalı etkinliklerin (kullanım senaryoları, UML şemaları) yakında işlenmeye başlanacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
