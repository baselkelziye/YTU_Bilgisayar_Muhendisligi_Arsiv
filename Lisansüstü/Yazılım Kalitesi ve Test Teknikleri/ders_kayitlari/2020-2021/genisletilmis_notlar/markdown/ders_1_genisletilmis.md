# Ders 1 Genişletilmiş Notu: Ders İçeriği ve Yazılım Mühendisliğinde Kalitenin Yeri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin çerçevesi ve ön bilgi
- 2. Ders içeriği: 12 başlık
- 3. Yazılım gereksinimlerinin hatırlatılması
- 4. Test süreci, test teknikleri ve hata giderme
- 5. Ölçüm, güvenilirlik ve test yönetimi
- 6. Teslim sonrası kalite ve kalite iyileştirme
- 7. Ders kapsamındaki çalışmaların akademik yönü
- 8. Yazılım mühendisliğinde kalitenin yeri
- 9. Yazılım geliştirme süreç adımları
- 10. Yazılım geliştirme süreç modelleri

## 1. Dersin çerçevesi ve ön bilgi

Ders, yazılım mühendisliği dersinin bilindiği varsayımıyla başlar. Hoca, alan içinden gelen öğrencilerin yazılım mühendisliği dersini lisansta ya da yüksek lisansa başlarken yeterlik dersi olarak almış olacağını belirtir. Bu yüzden süreç modelleri, gereksinimler gibi temel konular ayrıntılı anlatılmaz, yalnız hatırlatılır. Bu dersin lisanstaki seçimlik karşılığında da kalite ve test süreçleri işlenir; lisansüstü derste bu konular daha yeni yaklaşımlarla ve daha ağırlıklı olarak ele alınır.

Ders kaynakları olarak Pressman'ın ve Sommerville'in yazılım mühendisliği kitapları anılır. Hoca, yazılım mühendisliği derslerinde çok özet geçilen kalite ve test bölümlerinin bu kitaplardaki ayrıntılı hallerini kullandığını söyler.

## 2. Ders içeriği: 12 başlık

Dersin içeriği slaytta "Yazılım Kalite ve Test Teknikleri Dersi İçeriği" başlığıyla verilir (ekrandan, 00:05:00 - 00:40:00).

### 2.1 Yazılım geliştirme ve kalite yaklaşımı

Slayttaki ilk başlık şu alt başlıkları içerir (ekrandan, 00:05:00):

- Yazılım mühendisliğinde kalitenin yeri
- Yazılım geliştirme süreç modelleri
- Çevik yaklaşımlarda kalite bakış açısı
- Test güdümlü yazılım geliştirme

Süreç modelleri üzerinde durulmasının nedeni, formal bir model izlemenin kalite açısından önemli olmasıdır. Çevik yaklaşımlarla geleneksel yaklaşımlar arasındaki fark ve test güdümlü yaklaşım (Test Driven Development) da bu bölümde işlenir.

### 2.2 Kalite özellikleri ve kaliteyi sağlama aktiviteleri

İkinci başlık kalite özellikleridir. Yazılım mühendisliği dersinden bilinen McCall yazılım kalite özellikleri sınıflaması ve yazılım ölçütleriyle kalite özelliklerinin çapraz ilişkilendirilmesi burada ele alınır. Üçüncü başlık, yazılım kalitesini sağlamak için gereken aktivitelerdir: kalite standartlarının kullanılması, gözden geçirme (review) ve onaylama.

<!-- BELİRSİZ: 2. ve 3. başlıkların slayt metni karelerde görünmedi; bu bölüm hocanın anlatımından yazıldı. -->

### 2.3 Yazılım inceleme

Gözden geçirmenin (review) daha formal ve daha ayrıntılı yapılan hali inceleme (inspection) olarak adlandırılır. Slayttaki dördüncü başlık şöyledir (ekrandan, 00:10:00):

- Yazılım inceleme temel kavramları
- Yazılım incelemesinin önemi
- Genel yazılım inceleme süreci
- Fagan incelemesi
- İnceleme ekibi

### 2.4 Geçerleme ve doğrulama, yazılım testi

Beşinci başlık geçerleme ve doğrulama teknikleridir (verification & validation). Altıncı başlık yazılım testidir ve test süreci adımlarını içerir: birim test, bütünleme testi, regresyon testi, sistem testi, onaylama testi (ekrandan, 00:15:00). Dersin adında da geçtiği gibi test, yazılım geliştirme sürecindeki adımlardan biridir; derste kaliteyi sağlamak için testin nasıl, hangi modelde ne zaman yapıldığı incelenir.

### 2.5 Test teknikleri ve hata giderme

Yedinci başlık test teknikleri (saydam kutu testi, kara kutu testi), sekizinci başlık hata giderme (debugging) ve hata düzeyleridir (ekrandan, 00:25:00). Hoca slayta yazılmamış olsa da gri kutu testinin de bulunduğunu ekler.

### 2.6 Ölçüm ve güvenilirlik

Dokuzuncu başlıkta kalite ölçütleri, McCabe ve Halstead metrikleri ve yazılım güvenilirliği ele alınır (ayrıntısı 5. bölümde).

<!-- BELİRSİZ: 9. başlığın slayt metni karelerde görünmedi; başlık adı ve alt başlıklar anlatımdan alındı. -->

### 2.7 Test planlama ve yönetim, teslim sonrası kalite

Slayttaki onuncu ve on birinci başlıklar şöyledir (ekrandan, 00:30:00):

- 10. Yazılım test planlama ve yönetim: test yönetimi, test planı, test senaryoları, test çalışma ekibi yapısı
- 11. Yazılım teslim sonrası kalite sağlama: yazılım bakımı, yazılım konfigürasyonu

### 2.8 Kalite iyileştirme

On ikinci başlık kalite iyileştirmedir (ekrandan, 00:40:00):

- CMMI
- CMMI yeterlilik düzeyleri
- CMMI anahtar süreç alanları
- CMMI süreç alanları sınıflaması
- People CMM

## 3. Yazılım gereksinimlerinin hatırlatılması

Test teknikleri konuşulurken hoca, kullanıcı testinde kara kutu testinin neden uygun olduğunu açıklamak için gereksinim türlerini hatırlatır ve öğrencilere sorar.

**Soru (hocadan):** İşlevsel (functional) ve işlevsel olmayan (non-functional) gereksinim ne demektir? **Cevap (bir öğrenci):** Basitleştirirsek işlevsel gereksinimler programın çalışmasını etkileyen işlemlerdir. İşlevsel olmayanlar çoğunlukla görsel, akışı ve programın yapısını etkilemeyen, "olsa iyi olur" (nice to have) türünden gereksinimlerdir.

Hoca cevabı şöyle tamamlar. İşlevsel gereksinimler yapılacak işin tanımıyla ilgili gereksinimlerdir. Her gereksinim maddesinde net, kısa cümlelerle işle ilgili tanımlar yer alır. Gereksinimler liste halinde sunulur; genellikle modül modül ayrılarak alt başlıklar halinde verilir, böylece daha kolay izlenir. Sınıflama yapmadan baştan sona numaralandırmak da mümkündür.

İşlevsel olmayan gereksinimler ise kalite özelliklerine benzeyen gereksinimlerdir. Uygulamaya özgü değildir, doğrudan yazılımın teknik özellikleriyle ilgilidir. Örneğin bütün yazılımların güvenilir olmasını (reliability), doğru sonuç vermesini, güvenliğinin (security) yüksek olmasını, hız açısından performansının iyi olmasını, uzaktan bağlantının kesilmemesini isteriz. Ancak her yazılımda bunların hepsi aynı oranda istenmez; bazı yazılımlarda bazı kalite özellikleri öne çıkar. İşlevsel olmayan gereksinimler bunu anlatır.

> **Ek bilgi (derste anlatılmadı):** Öğrencinin cevabındaki "görsel, olsa iyi olur" nitelemesi dar bir tanımdır. Hocanın tamamladığı gibi işlevsel olmayan gereksinimler performans, güvenilirlik, güvenlik gibi zorunlu kısıtları da kapsar ve çoğu zaman sistemin kabulü için en az işlevsel gereksinimler kadar belirleyicidir.

## 4. Test süreci, test teknikleri ve hata giderme

### 4.1 Testin süreç modelleri içindeki yeri

Test bir süreç adımıdır, ama ne zaman başlayacağı izlenen modele bağlıdır. Waterfall izleniyorsa test yazılım geliştirme sürecinin sonunda yapılır ve yapılanların doğru olup olmadığı adım adım denetlenir. Spiral modelde her çevrimde test yapıldığı için daha fazla test gerçekleştirilir. Unified Process yaklaşımında test yine daha farklı bir noktada yer alır.

### 4.2 Test süreci adımları

- **Birim test:** Test verisinin nasıl hazırlanacağı ve bir fonksiyonun henüz test edilmemiş alt fonksiyonlarının yerine ne konacağı gibi konular üzerinde durulur.
- **Bütünleme testi:** Bütünleme işleminin ne zaman yapılacağı ve hangi stratejinin, yukarıdan aşağıya mı aşağıdan yukarıya mı, uygulanacağı ele alınır.
- **Regresyon testi:** Bütünleme testinden sonra yapılır. Birimlerden birinde bütünleme testinden sonra değişiklik yapılmışsa uygulanır.
- **Sistem testi:** Bütünlük ve regresyon testleri yapılmış, yazılım doğru çalışıyor olsa bile içinde bulunduğu sistemle uyumlu çalışıp çalışmadığı burada görülür.
- **Onaylama testi:** Kabul testi (acceptance test), yani kullanıcının onayıdır. Ölçüt gereksinim spesifikasyonudur (gereksinim listesi, requirement specification): kullanıcı başta ne istemişti, istediklerinin hepsi yapıldı mı? Kullanıcı istediklerinin olduğunu kabul ederse onaylama testi tamamlanır.

> **Ek bilgi (derste anlatılmadı):** Birim testte henüz yazılmamış ya da test edilmemiş alt fonksiyonların yerine konan basit yer tutuculara genellikle "stub", test edilen birimi çağıran geçici sürücü koda "driver" denir. Yukarıdan aşağıya bütünlemede stub, aşağıdan yukarıya bütünlemede driver kullanımı öne çıkar.

### 4.3 Test teknikleri

Test teknikleri saydam kutu, kara kutu ve gri kutu testleridir. Saydam kutu testi iç testtir, yani iç yapının test edilmesidir. Kara kutu testi dış yapının, dışarıdan görünüşün test edilmesidir. Bu teknikler test süreci adımlarına uygulanır; hangi aşamada hangi tür testin yapılacağı ayrıca ele alınacaktır.

> **Hocanın vurgusu:** Kullanıcı testinde kara kutu testi yapmak daha uygundur. Kullanıcı iç yapının ne olduğuyla, algoritmanın ne kadar iyi olduğuyla pek ilgilenmez; önemli olan yazılımın onun istediği gereksinimlere uygun olup olmadığıdır.

### 4.4 Hata giderme

Hata giderme (debugging) konusunda test ile debug arasındaki fark, hatanın yerinin belirlenmesi ve sorunun giderilmesi ile hata düzeyleri işlenecektir.

> **Ek bilgi (derste anlatılmadı):** Genel kabul gören ayrımda test, hatanın varlığını ortaya çıkarmaya yönelik etkinliktir; debugging ise testte ortaya çıkan bir hatanın kaynağını bulup düzeltme işidir.

## 5. Ölçüm, güvenilirlik ve test yönetimi

### 5.1 Ölçümün önemi

Yazılım mühendisliğinde sık tekrarlanan bir söz vardır: Tom DeMarco'nun "Ölçemediğinizi yönetemezsiniz" sözü. Hocaya göre mühendislik kavramını yazılım mühendisliğine taşıyan şey ölçüm ve tasarım aşamalarıdır; bu derste tasarım değil ölçüm tarafına bakılır. Kalite ölçütlerine, kalite özellikleriyle ölçütleri ilişkilendiren McCall matrisi üzerinden girilir.

### 5.2 McCabe ve Halstead metrikleri

McCabe metriği yazılım kalitesiyle birlikte test aşamasında, özellikle birim test aşamasında test verisi hazırlanırken de kullanılır. Halstead metriği ise algoritmadaki işlemci ve işlenenleri sayarak ilerleyen bir ölçüttür; yazılımdaki işlem miktarını, oranını ölçer.

> **Ek bilgi (derste anlatılmadı):** McCabe'in çevrimsel karmaşıklığı (cyclomatic complexity) kontrol akış grafından $V(G) = E - N + 2$ ile hesaplanır ($E$ kenar, $N$ düğüm sayısı) ve birbirinden bağımsız yol sayısını verir; birim testte en az bu kadar test durumu tasarlanması önerilir. Halstead ölçütleri ise farklı işlemci ve işlenen sayıları ile toplam işlemci ve işlenen sayılarından türetilir.

### 5.3 Yazılım güvenilirliği

Güvenilirliğin (reliability) önemli bir kavram olduğu daha önce söylenmişti. Hoca bunu kabaca şöyle tarif eder: Yazılımı test ettiğimizde beklediğimiz sonucu alabiliyor muyuz, sonuçlar beklediğimiz sonuçlar mı ve yazılımın doğruluğuna ne kadar güvenebiliyoruz? Bunun çok daha istatistiksel bir altyapısı vardır: hata oranları, hata sayıları ve belirli bir süre içindeki davranışa dayanan yaklaşımlar. Bunlara yazılım güvenilirliği modelleri denir; pek çok model kullanılır ve yazılım mühendisliğinde oldukça çalışılan bir konudur.

### 5.4 Test planlama ve yönetim

Bir kurumu ya da kurum içindeki yazılım birimini düşündüğümüzde, geliştirilen yazılım test aşamasına geldiğinde ekibin nasıl oluşacağı sorusu ortaya çıkar. Ayrı bir test grubu var mı, yoksa testleri kodu yazanlar mı yapacak? Hangi testi kodu yazanlar, hangisini test grubu yapacak ve test grubu nasıl oluşturulacak? Test yönetimi bunu kasteder. Hoca, birçok kurumda artık ayrı kalite ve test ekipleri bulunduğunu belirtir.

Test planı, nasıl ki proje planı yapılıyor ve yazılım geliştirme süreci planlanıyorsa, test sürecinin de önceden planlanmasıdır. Sıra şöyledir:

- Test yapılacak yazılım seçilir.
- Yazılımın gereksinim raporu (spesifikasyonu) hazırlanır. Gereksinim belgesi olmayan bitmiş bir yazılımda bu, geriye dönerek, bir tür tersine mühendislikle (reverse engineering) yeniden çıkarılır.
- Test planı yapılır: hangi testler, hangi sırada yapılacak.
- Test takvimi oluşturulur ve planda hedefler yazılır: planlanan testin hedefi nedir?
- Test senaryoları ve test raporları hazırlanır.

Örneğin kodu elde olan bir yazılımda birim test, ayrıca bir kullanıcı testi ya da araçları (tool) elde edilerek sistem testi yapılabilir.

## 6. Teslim sonrası kalite ve kalite iyileştirme

On birinci bölümde yazılım teslim edildikten sonra kalitenin nasıl sağlandığı, bakım planı ve gerçekleştirilen iş adımları görülecektir. Yazılım konfigürasyonu da yazılım mühendisliğinden en azından kavram olarak bilinen bir konudur. Son bölüm olan kalite iyileştirmede, yazılım mühendisliği derslerinin başında ya da sonunda değinilen CMMI yeterlilik düzeyleri ve People CMM ele alınacaktır.

## 7. Ders kapsamındaki çalışmaların akademik yönü

Dönem içindeki çalışmalardan biri, yukarıdaki test planlama ve yönetim bölümünü bir projede örneklemektir: bir yazılım seçilir, gereksinim analizi yapılır ya da tersine mühendislikle çıkarılır, bir kullanıcı testi ile bir birim ya da sistem testi gerçekleştirilir ve süreç test planı, test senaryoları ve test yönetimini gösterecek biçimde raporlanır. Gerçek bir ekip kurmak zor olduğunda ekip çalışması tek kişiyle, daha küçük bir yazılım üzerinden benzetilir.

Diğer çalışma bir derleme makalesidir. Dersin konularıyla ilgili güncel (2015 ve sonrası) dergi makaleleri ve ciddi konferans bildirileri taranır. Örnek olarak IEEE Transactions on Software Engineering, yazılım kalitesi ve doğrulama/geçerleme dergileri, ACM'in yazılım testi ve otomasyon dergileri ile Springer dergileri anılır. Hoca, derleme makalesini şöyle tanımlar: seçilen bir konuda çıkmış önemli kaynaklar taranır, temel kavramlar gerekirse kitaplardan da alınır, önce anlaşılır, sonra anlaşılanlar kaynak gösterilerek birleştirilip yazılır. Bir başlangıç makalesinden yola çıkıp altyapıyı başka kitap ve bildirilerle destekleyerek makaledeki uygulamanın benzeri de yapılabilir; deneme ortamı varsa çalışma bir araştırma makalesine dönüşebilir. Metin IEEE makale biçiminde yazılır.

**Soru:** Yazılacak makale bir derleme (survey) mi olacak, yoksa belirli bir uygulamaya mı odaklanacak? **Cevap:** Hedef derleme makalesidir; seçilen makale başlangıç noktasıdır ve o konudaki başka yazılardan ve kitaplardan derleme yapılır. İstenirse makaledeki uygulamanın benzeri yapılarak araştırma makalesine de genişletilebilir.

## 8. Yazılım mühendisliğinde kalitenin yeri

### 8.1 Tanım

Slayttaki ifade şöyledir (ekrandan, 00:55:00): Yazılım mühendisliği bilgisayar bilimi, yönetim bilimi, ekonomi ve bilişim bilim dallarından yararlanmakta ve sorun çözümünde mühendislik yöntemlerini kullanmaktadır. Yazılım mühendisliğinin, temelinde kalite bakış açısı olan, mühendislik yöntemleri, süreçler, metodolojiler ve yazılım araçları (CASE tool) olan katmanlı bir yapısı vardır.

Hoca, temel kitaplarda yazılım mühendisliğinin genellikle dört kısımda incelendiğini, bazen yeni yaklaşımlar için beşinci bir kısım eklendiğini anlatır:

- **Yazılım mühendisliği kavramları:** Yazılım geliştirme süreci, süreçteki temel adımlar ve destek aktiviteleri, süreç modelleri.
- **Analiz ve tasarım:** Gereksinim analizi ve tasarım, hem geleneksel hem özellikle nesneye yönelik yaklaşımla; kullanım durumu (use case) ve ardışıl (sequence) diyagramları gibi diyagramların çizimi ve amacı, analizden tasarıma geçiş ve CASE araçlarının kullanımı. Gerçekleştirme kodlamayla ilgili derslerde işlenir.
- **Yazılım proje yönetimi.**
- **Kalite yönetimi ve test teknikleri.**

Bütün bu içeriği kapsayan kısa tanım şudur:

> **Hocanın vurgusu:** Yazılım mühendisliği, kaliteli yazılımı en ekonomik olarak elde etmek üzere mühendislik yöntem ve tekniklerinin kullanılmasıdır.

Tanımdaki "kaliteli yazılımın elde edilmesi", yazılımı ne olursa olsun elde etmek değil, kaliteli olmasını sağlamaktır; bu kısım kalite yönetimi ve test tekniklerine karşılık gelir. "En ekonomik olarak elde etmek", en ucuzu değil, daha etkin kaynaklarla en faydalıyı en iyi maliyetle elde etmektir; bu da proje yönetimini gerektirir.

Mühendislik kavramının altında iki şey yatar. Birincisi iyi tasarımdır: yazılımı hemen geliştirmek yerine iyi tasarım modelleri oluşturarak geliştirmek. İkincisi ölçümdür. Hoca, "mühendis" kelimesinin "hendese yapan", yani ölçen, biçen kişi anlamına geldiğini hatırlatır. Ölçme (software metrics) de yazılım mühendisliğinin konularından biridir. Böylece bu kısa tanımda yazılım mühendisliğinin bütün alt başlıkları görülebilir.

### 8.2 Katmanlı yapı

Slayttaki Şekil 1.1 "Yazılım Mühendisliği Katmanlı Yapısı"nı gösterir (ekrandan, 01:00:00). Katmanlar alttan üste şöyledir:

```text
YAZILIM ARAÇLARI        (en üst)
YÖNTEMLER
SÜREÇLER
KALİTE BAKIŞ AÇISI      (temel)
```

En altta kalite bakış açısı vardır. Onun üstünde süreçler (analiz aşaması, tasarım aşaması gibi), onun üstünde bu süreçler boyunca kullanılacak yöntemler, en üstte de bunlara uygun yazılım araçları yer alır. Yazılım araçları, CASE araçları gibi yazılım geliştiricilere destek olan yazılımlar ya da geliştirme ortamlarıdır. Bir yazılım aracı seçilirken kalite bakış açısıyla, yazılım geliştirme süreçlerine ve tekniklerine uygun araçların seçilmesi gerekir.

## 9. Yazılım geliştirme süreç adımları

### 9.1 Esas süreç adımları

Esas süreç adımları gereksinim analizi, tasarım, kodlama, test ve bakımdır. Bunlar yazılımın hazırlanması için gerekli temel işlemlerdir. Hoca slaytta tasarımın eksik kaldığını belirterek listeye ekler.

### 9.2 Destek süreç adımları

Destek süreç adımları, yazılımı daha iyi hale getirmek için yapılan işlemlerdir: proje yönetimi, kalite yönetimi, geçerleme ve doğrulama (validation, verification), formal ve teknik gözden geçirme, yazılım konfigürasyon yönetimi, yeniden kullanılabilirlik yönetimi, yazılım ölçümü ve risk yönetimi. Bunların bir kısmı doğrudan kalite yönetiminin, yani kalitenin sağlanmasının altındadır.

<!-- BELİRSİZ: destek adımları slaytı karelerde yalnız küçük önizleme olarak görüldü; liste önizleme ve anlatım birleştirilerek yazıldı. -->

Yeniden kullanılabilirlik, yapılan işleri, hazırlanan algoritmaları, çözüm yollarını ya da yazılım parçalarını saklayıp tekrar kullanabilmektir. Bu, projelerde aynı eforun gereksiz yere tekrar tekrar harcanmasını önler.

## 10. Yazılım geliştirme süreç modelleri

### 10.1 Süreç modeli kavramı

Slayttaki tanıma göre süreç modeli, yazılım geliştirme süreci adımlarının hangi sırada ve düzende uygulanacağını tanımlar (ekrandan, 01:05:00). Başlıca yazılım geliştirme süreç modelleri:

- Klasik doğrusal akış (Waterfall)
- Prototip model
- Artımlı (incremental) model
- Helezon (spiral) model
- Hızlı uygulama geliştirme (Rapid Application Development)
- Birleştirilmiş süreç (Unified Process) modeli

Temel adımlar tek tip düzenlenmez. Analiz, tasarım, gerçekleştirme ve test Waterfall'da da, prototip, artımlı ve spiral modelde de vardır. Modeller, bu temel işlemlerin dizilişine ve destek aktivitelerinin araya nasıl, hangilerinin eklendiğine göre farklı tanımlanır.

Hocanın kısa açıklamaları şöyledir. Waterfall doğrusal akış (linear) modelidir. Prototip modelde belli bir yere kadar model oluşturulup üzerinde denemeler yapılarak uygulanır. Artımlı modelde yazılımın bütünü değil, belli artımlarla ilerlenerek tamamı oluşturulur. Spiral model yazılımı sürekli evrim geçirerek, sarmal biçimde oluşturur. RAD hızlı yazılım geliştirme için kullanılır. Unified Process ise UML'e göre geliştirilmiş bir yaklaşımdır.

### 10.2 Spiral model

Şekil 1.2, spiral modelin evrimsel yazılım geliştirme süreç yapısını gösterir (ekrandan, 01:10:00). Şekildeki dilimler müşteri iletişimi, planlama, risk analizi, mühendislik, yapım ve değişim, müşteri değerlendirmedir. Halkalar ise içten dışa kavram geliştirme projesi, yeni ürün geliştirme projesi, ürün zenginleştirme projesi ve ürün bakım projesidir.

Sonraki slayt altı aşamayı şöyle tanımlar (ekrandan, 01:15:00):

- **Müşteri iletişimi:** Geliştirici ve müşteri arasındaki etkin iletişimi sağlama.
- **Planlama:** Proje için zaman ve kaynak yöntem tanımı yapma.
- **Risk analizi:** Teknik ve yönetim risklerini belirleme.
- **Mühendislik:** Uygulamanın tanımının yapılması (tasarım). Hoca bunu gereksinim analizinin bir bölümü ve tasarım aşaması olarak açıklar.
- **Yapım ve değişim (construction & release):** Gerçekleştirme, test, kuruluş ve kullanıcı desteği (belgeleme ve eğitim). Hoca bunu ayrıntılı tasarım ve kodlama aşaması olarak da anar.
- **Müşteri değerlendirme:** Kullanıcı testi.

Her evrimde, her sarmalda bu aşamaların hepsi tekrarlanır. Değişiklik gerekirse kavram geliştirmeden ürün bakımına kadar her halkada bütün çevrim yeniden işletilir; bu yüzden bir prototipte bile risk analizi yapmak gerekir.

> **Hocanın vurgusu:** Spiral model daha sağlam ilerler ama çok fazla emek ve süre ister. Rekabet koşulları ve piyasaya hızlı üretim baskısı nedeniyle her yazılım evinde kullanılamaz; ancak hata açısından kritik yazılımlarda kullanılır. Küçük projelerde ya da hızla ürüne dönüşmesi gereken sistemlerde spiral model uygun değildir.

### 10.3 Çevik modeller

Hoca buraya kadar geleneksel modelleri saydığını, bugün en çok kullanılanların ise çevik (agile) modeller olduğunu belirtir. Çevik sınıfına giren farklı modeller vardır.

**Soru (hocadan):** Çevik modellerden hangilerini hatırlıyorsunuz? **Cevap (bir öğrenci):** Yazılım mühendisliği dersinde üç temel model üzerinde durulmuştu; bunlardan biri Extreme Programming (XP).

Hoca XP'nin ilk kullanılan çevik model olduğunu, daha sonra Scrum'ın en çok kullanılan model haline geldiğini, Kanban'ın da birçok projede kullanıldığını söyler; hangi projede hangisinin daha uygun olduğu ayrıca değerlendirilebilir. Çevik modeller sonraki derste ele alınacaktır.

**Soru:** Çevik metotlara da giriş yapılacak mı? **Cevap:** Evet. İçerikteki test güdümlü geliştirme (Test Driven Development) zaten çevik yöntemlerin, özellikle XP'nin altında yatan yaklaşımdır; bundan da kısaca söz edilecektir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:17:21): İşlevsel (functional) ve işlevsel olmayan (non-functional) gereksinim nedir?

> **Cevap (derste verildi):** İşlevsel gereksinimler yapılacak işin tanımıyla ilgilidir ve net, kısa cümlelerle maddeler halinde yazılır. İşlevsel olmayan gereksinimler uygulamaya özgü olmayan, kalite özelliklerine benzeyen teknik gereksinimlerdir: güvenilirlik, doğruluk, güvenlik, performans, bağlantı sürekliliği gibi.

**Soru 2** (derste sözlü, 00:24:46): Test ile debug arasındaki fark nedir?

> **Çözüm (derste verilmedi):** Test, yazılımda hata olup olmadığını ortaya çıkarmaya yönelik etkinliktir. Debugging, testte görülen hatanın yerini belirleyip sorunu gidermektir. Derste bu ayrım yalnız "yerinin belirlenmesi ve sorun giderilmesi" ifadesiyle ileriki konu olarak anıldı.

**Soru 3** (derste sözlü, 01:10:53): Çevik yazılım geliştirme modellerinden hangilerini hatırlıyorsunuz?

> **Cevap (derste verildi):** Extreme Programming (XP), Scrum ve Kanban. XP ilk kullanılan çevik modellerdendir, Scrum bugün en çok kullanılanıdır.

## Dersin Toparlaması

Bu ilk derste dersin 12 başlıklık çerçevesi çizildi: kalitenin yazılım mühendisliğindeki yeri ve süreç modellerinden başlayıp kalite özellikleri, kaliteyi sağlama aktiviteleri, inceleme (Fagan), geçerleme ve doğrulama, test süreci ve teknikleri, hata giderme, ölçüm ve güvenilirlik, test yönetimi, teslim sonrası kalite ve CMMI ile kalite iyileştirmeye uzanan bir yol. Gereksinim türleri, test süreci adımları ve kara kutu testinin kullanıcı testindeki yeri kısaca hatırlatıldı.

Konu anlatımına yazılım mühendisliğinin "kaliteli yazılımı en ekonomik olarak elde etmek üzere mühendislik yöntem ve tekniklerinin kullanılması" tanımıyla başlandı. Katmanlı yapının temelinde kalite bakış açısının durduğu, esas ve destek süreç adımları ile geleneksel süreç modelleri, özellikle spiral model işlendi. Sonraki derste çevik modeller ve bunlarda kalite bakış açısı ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
