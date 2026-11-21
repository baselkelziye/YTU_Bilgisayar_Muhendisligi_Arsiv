# Ders 3 Genişletilmiş Notu: Gözden Geçirme, Yazılım İncelemesi ve Birim Test

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dönem Başından Bu Yana: Kaliteyi Sağlama Aktiviteleri
- 2. Gözden Geçirme ve Onaylama
- 3. Gözden Geçirme Toplantısı ve Gözden Geçirme Tipleri
- 4. Gözden Geçirme ve Onaylama Basamakları
- 5. Gözden Geçirme Standartları
- 6. Yazılım İncelemesi (Inspection)
- 7. Yazılım Sınama (Test) ve V Model
- 8. Birim Test
- 9. Genişletilmiş V Model ve Alt Test Adımları
- 10. Ders Kaynakları ve Makale Araştırması
- Örnek Sorular
- Dersin Toparlaması

## 1. Dönem Başından Bu Yana: Kaliteyi Sağlama Aktiviteleri

Hoca derse önceki haftaların kısa bir toparlamasıyla başladı. Önce yazılım mühendisliği içinde kalitenin yerinden söz edilmiş, yazılım mühendisliğiyle ilgili hatırlatmalar yapılmıştı. Ardından kalite yaklaşımı için yazılım kalite özellikleri bir kalite modeli üzerinden sınıflandırılmış, bu model üç bakış açısına göre açılmıştı: kullanıcı bakış açısı, çalıştıran bakış açısı ve bakım yapan bakış açısı. Her bakış açısında bulunması gereken kalite özellikleri tek tek açıklanmış, sonra bu özelliklerin metriklerle ilişkisi üzerinde durulmuştu. Bir önceki derste ise kaliteyi sağlamak için neler yapılacağına geçilmiş ve standartlar anlatılmıştı. Kalite özelliklerinin kendisine (yazılım mühendisliği dersinde de görüldüğü için) tekrar dönülmeyeceği söylendi.

Kaliteyi sağlamak için yapılan aktiviteler bütün olarak şöyle hatırlatıldı:

- **Uygun bir süreç modeli seçmek:** Yazılım geliştirmeye başlamadan önce, önlem olarak iyi bir yazılım geliştirme süreç modeli seçilir; yani hata yapmamak için süreç formal bir disiplin altına alınır. Burada "iyi" sözü, her uygulama için yüzde yüz iyi olan bir model olduğu anlamına gelmez. Hangi tür ekipte, hangi tür uygulamada hangi süreç modelinin uygun olduğu bilinerek seçim yapılır.
- **Standartları belirlemek:** Hangi standartların kabul edildiği kararlaştırılır. Kurum, ulusal ya da uluslararası kalite yönetim sistemlerinden yararlanarak seçilmiş ya da karma biçimde hazırlanmış bir standartlar grubu oluşturur; bunlar kurumun yazılım standartlarıdır ve bir el kitabında toplanır. Her projede bu kurum standartlarına başka standartlar da eklenebilir.
- **Geliştirme sırasında gözden geçirme, inceleme ve test:** Geliştirme süreci başladığında gözden geçirme (review) ve daha formal, daha ayrıntılı olan inceleme (inspection) yapılır; ardından test gelir. Bunlar geliştirme sırasında kaliteyi sağlamak için yapılan üç temel aktivitedir.
- **Diğer aktiviteler:** Konfigürasyon yönetimi, risk yönetimi ve ürün teslim aşamasındaki sürüm (release) yönetimi de kaliteyi sağlamaya hizmet eder. Hata yapmamak ve doğru tahmin yapabilmek için ayrıca ölçüm gerçekleştirilir.

Hoca gözden geçirmenin neden bu kadar önemli olduğunu daha önce görülen bir grafikle hatırlattı: Yazılım geliştirme süreci ilerledikçe hatayı bulmak zorlaşır ve hatayı bulmak için harcanacak miktar artar. Waterfall modelde test sona kalır; çevik (agile) yaklaşımlarda test daha öne çekilmiştir. Yine de "ben yazılımı geliştireyim, sonra test ederim" yaklaşımında hatalar teste kalmasın diye, yapılanlar gözden geçirmeyle ara ara kontrol edilir.

## 2. Gözden Geçirme ve Onaylama

### 2.1 Tanım ve "eleme" niteliği

Slayttaki tanıma göre, yazılım geliştirme sürecini oluşturan her basamak tamamlanınca durak noktalarında yapılan işler gözden geçirilmekte ve gerekli düzeltmeler yapılmaktadır (ekrandan, 00:10:00).

Gözden geçirme bir "eleme" niteliğindedir. Her basamakta yapılabilen hata ve eksiklerin zamanında bulunup giderilmesini sağlar. Böylece hata bulma gideri düşük, hatanın bulunma olasılığı yüksek olur.

Bunu gösteren şekil (Şekil 2.3, "Yazılım geliştirme süreci ile hata bulma gideri ve hata bulma olasılığı ilişkisi") iki eğriden oluşur (ekrandan, 00:15:00):

- (a) Yatay eksen süreç, dikey eksen hata bulma gideri (TL): süreç ilerledikçe gider giderek hızlanan biçimde artar.
- (b) Yatay eksen süreç, dikey eksen hata bulma olasılığı (P): başta yüksek olan olasılık, süreç ilerledikçe hızla düşer.

### 2.2 Hata oranları ve maliyet katları

Hoca bir çalışmaya dayanan sayıları aktardı. Slayttaki metne göre yazılım geliştirmedeki hataların %50-65'i tasarım aşamasında yapılmaktadır; gözden geçirme sırasında bu hataların %75'i bulunup düzeltilebilmektedir. Bulunamayan hatalara sınama öncesinde rastlanması halinde 5-6 kat, sınama sırasında rastlanması halinde 15 kat, kullanım aşamasında rastlanması halinde ise 67 kat gider gerekmektedir (ekrandan, 00:20:00, slayt listesindeki küçük görüntüden). Hoca bu oranların çalışmadan çalışmaya değişebileceğini, ama hata bulma giderinin hep katlanarak arttığını vurguladı. Kullanım aşamasında bulunan hatada, kullanıcının güveni de sarsıldığı için bu maliyet de eklenir.

> **Hocanın vurgusu:** Oranlar değişebilir, ama hata ne kadar geç bulunursa gider o kadar katlanır. Bu yüzden gözden geçirme her basamakta yapılmalı, hatalar teste ve kullanıma kalmamalıdır.

### 2.3 Amaçlar ve yararlar

Gözden geçirmenin amaçları üç başlıkta toplandı:

- Yazılımda yapılabilen işlevsel, mantıksal ve gerçekleştirme (kodlama) hatalarının bulunup giderilmesi.
- Yazılımın gereksinimlere uygun olarak düzenlendiğinin onaylanması.
- Yazılımın önceden belirlenen standartlara uygunluğunun sağlanması.

Son madde bir önceki dersle bağlantılıdır: Standartlar yazılıma başlamadan belirlenir; gözden geçirme sırasında, durak noktalarında, raporlarda ve kodlamada kurum standartlarına uymayan bir şey olup olmadığına bakılır.

Yararlar ise şunlardır: yazılımın belli bir düzen içinde geliştirilmesi, proje yönetiminin kolaylaşması ve müşteriye dağıtılacak ürünlerin kalitesinin artması. (Hoca, slaytta son üç maddenin "yararlar" olduğunu, başlığı ayırmayı unuttuğunu belirtti.)

### 2.4 Gözden geçirme nedir, ne değildir

Gözden geçirme (review); teknik uzmanların çalışmalarının teknik uzmanlar tarafından değerlendirildiği bir toplantıdır. Yazılım mühendisliği sürecinde yaratılan ürünlerin teknik bir değerlendirmesidir, kaliteyi sağlamak için yapılan bir aktivitedir ve aynı zamanda bir eğitim ortamıdır.

Gözden geçirme şunlar değildir (ekrandan, 00:20:00):

- Bir proje özeti veya proje ilerlemelerinin ifadesi değildir; "proje ne durumda" toplantısı değildir.
- Yazılım geliştirme ekibinin politik veya kişisel değerlendirmesi değildir.
- Sadece bilgi verme toplantısı değildir.

> **Hocanın vurgusu:** En çok yakınma, gözden geçirmenin kalite ya da test grubunun politik veya kişisel bir değerlendirmesine dönüşmesinden gelir. Hedef tamamen standartlara ve gereksinimlere uygunluğa bakmak, o ana kadar yapılan işlerde mantıksal ya da kodlama hatası ya da işin yanlış anlaşılmasından doğan hatalar varsa bunları ortaya çıkarmaktır.

## 3. Gözden Geçirme Toplantısı ve Gözden Geçirme Tipleri

### 3.1 Toplantıdaki roller

Gözden geçirme, gözden geçirme toplantılarıyla yapılır. Bu toplantılarda şu roller bulunur:

- **Gözden geçirme lideri:** Olabilir; her türde zorunlu değildir.
- **Kullanıcı temsilcisi:** Mutlaka bulunmalıdır.
- **Standartlara uygunluğu kontrol eden kişi:** Kalite güvence ekibinden biridir. Böyle bir ekip yoksa, yazılım ekibinin önceden oluşturduğu standartlara ya da küçük bir el kitabına uygunluk kontrol edilir.
- **Üretici:** Yazılım geliştirme ekibinden biri.
- **Kayıtçı:** Toplantı sırasında kayıtları tutan kişi.

### 3.2 Gözden geçirme tipleri

Gözden geçirme ve inceleme tipleri şöyle sayıldı:

- Formal olmayan gözden geçirme (informal review): Genelde "review" denince anlaşılan budur; daha hızlı, daha sık aralıklarla yapılanların değerlendirilmesidir.
- Yapısal denetim (walkthrough).
- İnceleme (inspection).
- Round robin peer review: incelemenin bir başka çeşidi olarak anıldı.

### 3.3 Gözden geçirme seçenek matrisi

Bu üç türün farkları Tablo 3.1 "Gözden Geçirme (Review) Seçenek Matrisi" ile gösterildi (ekrandan, 00:25:00). GG formal olmayan gözden geçirme, WT walkthrough, İnc. inspection anlamındadır:

| Ölçüt | GG | WT | İnc. |
|---|---|---|---|
| Gözden geçirme lideri | yok | var | var |
| Toplantı takvimi | belki | var | var |
| Gözden geçirenlerin hazırlığı | belki | var | var |
| Yazılımcı sunum yapıyor mu | belki | var | yok |
| Hataları bulmak için checklist | yok | yok | var |
| Bulunan hatalar sınıflanıyor mu | yok | yok | var |
| Kayıtçı not alıyor mu | belki | var | var |

Hoca tabloyu satır satır yorumladı:

- **Lider:** Formal olmayan gözden geçirmede önceden belirlenmiş bir lider olmayabilir; katılımcılardan biri o anda, toplantı sırasında bu iş için seçilebilir. Walkthrough ve inspection'da lider mutlaka vardır.
- **Hazırlık:** Walkthrough ve inspection'da gözden geçirenler mutlaka önceden hazırlık yapar.
- **Yazılımcı sunumu:** Formal olmayan gözden geçirmede belki, walkthrough'da mutlaka yapılır. Inspection'da yazılımcıdan ayrıca sunum alınmaz. İnceleme ekibi yapılanları aralarında paylaşır, önceden çalışır ve değerlendirmeyi kendisi yapar; yalnız soruları olursa yazılım geliştiricilere sorar.
- **Checklist:** Inspection'da hataları bulmak için önceden bir checklist hazırlanır; paylaştırılmış bölümleri farklı bakış açılarıyla değerlendirmek içindir. Diğer ikisinde checklist yoktur.
- **Hata sınıflaması:** Bulunan hataların sınıflandırılması inspection'da zorunludur, diğer ikisinde yoktur.
- **Kayıtçı:** Inspection'da kayıtçı mutlaka vardır ve not alır. Formal olmayan gözden geçirmede ise bu görev ekipten herhangi birine verilebilir.

### 3.4 Kim yapmalı?

Küçük projelerde gözden geçirme ve düzeltme işlemi tamamen yazılım geliştirenler tarafından yapılabilir. Ancak hata ve eksikleri üçüncü bir kişi daha kolay ve duyarlı biçimde görebileceği için büyük projelerde bu işi ayrı bir ekibin yapması daha doğrudur.

## 4. Gözden Geçirme ve Onaylama Basamakları

Gözden geçirme genellikle yazılım proje yönetiminde milestone denen durak noktalarında yapılır. Önemli durak noktaları şunlardır: sistem analizinin bitmesi, yazılım geliştirme planının bitmesi, gereksinim analizinin (SRS) tamamlanması, tasarım, kodlama, sınama, bakım ve onarım. Bunların her birinin sonunda gözden geçirme yapılır.

Bu noktaların mutlaka bu adlarla tanımlanması gerekmez. Kaliteyi sağlamak için önceden bir süreç modeli seçilmiştir ve gözden geçirme o modelin adımlarına göre yapılır. Örneğin spiral model seçilmişse, spiral modelin 6 adımı prototip geliştirme, ürün geliştirme ve ürün zenginleştirme turlarında tekrar eder; adlar farklı olsa da bu adımların her biri için gözden geçirme yapılır. Slaytlardaki basamaklar waterfall'a göre yazılmıştır, ama her süreç modelinde adı farklı da olsa izlenecek adımlar vardır.

### 4.1 Sistem analizi

Slayttaki metne göre (ekrandan, 00:30:00), sistem analizi basamağında sistem düzeyindeki spesifikasyonların yazılıma ilişkin işlev ve görevler olarak dağıtımının doğruluğu, kalite güvencesini onaylama gereksinimlerinin tutarlılığı ve görevlendirmenin yeterliliği denetlenir. Özellikle şunlar üzerinde durulur:

- Ana işlevlerin, ara birimlerin, performansların ve tasarım kısıtlarının tanımları.
- Alternatifler arasından yapılan seçimin tutarlılığı (fizibilite analizi tutarlı mı?).
- Teknolojik bakımdan yapılabilirlik.
- Sistemin sınanma esasları (sistem nasıl test edilebilir?).
- Sistem öğeleri arasındaki uyumluluk.

Yani sistem analizi denince fizibilite (yapılabilirlik) analizi, sistemin gerçekleştireceği temel işler ve sistem kuruluşuyla ilgili alternatiflerin hepsi bu basamakta gözden geçirilir.

### 4.2 Yazılım geliştirme planı

Alternatif çözümlerden seçilen en iyi çözüme göre bir plan oluşturulur. Bu basamakta projenin gerçekleştirilmesinde risk olup olmadığı ortaya çıkarılmaya çalışılır. Yazılım sorununun tanımı ve terimlerin doğruluğu, kaynakların yeterliliği ve sağlanma olasılığı, görevlerin uygunluğu, verimlilik, kalite, gider ve zamanlama tahminlerinin tutarlılığı incelenir. Kısacası "bu plan doğru çalışır mı?" diye bir gözden geçirme yapılır.

### 4.3 Gereksinim analizi

Gereksinim analizinde sistem düzeyindeki gereksinimlere uygunluk, bağlılık ve doğruluk gözden geçirilir. Bilgi alanı analizi doğru ve tutarlı tanımlanmış mı, sorun bölümlere doğru ayrılmış mı, iç ve dış ara birimlerin tanımları uygun mu kontrol edilir. Bütün gereksinimlerin sistem düzeyinde tutarlı olup olmadığına ve istenen performansın sağlanabilir olup olmadığına bakılır.

Hoca basamakların sırasını da bağladı: önce sistem analizinde kullanıcıdan bilgi alınır ve alternatifler arasından seçim yapılır; seçilen çözüm üzerinde plan yapılır ve planın doğruluğu gözden geçirilir; ardından gereksinim analizinde sistem çok ayrıntılı incelenerek sistemin bütün elemanlarının ve aralarındaki ilişkilerin anlaşılıp anlaşılmadığına, fonksiyonel olmayan gereksinimlerin doğru tanımlanıp tanımlanmadığına bakılır.

### 4.4 Yazılım tasarımı

Slayta göre yazılım tasarımı basamağında veri yapıları, program yapısı ve işlemler ele alınır; önce ön tasarım, sonra ayrıntılı tasarım gözden geçirilir (ekrandan, 00:35:00).

**Ön tasarım (genel tasarım):** Ana fikir, gereksinim analizinin tasarıma doğru dönüştürülüp dönüştürülmediği, yani yazılım mimarisinin doğru oluşturulup oluşturulmadığıdır. Gereksinimler uygun modüller içinde tasarlanmış mı, modül hiyerarşisi gereksinim yapısına göre doğru belirlenmiş mi diye bakılır. Slayttaki ayrıntıyla: gereksinimlerin yazılım mimarisine doğru yansıtılmış olması, modüllerin etkinliği ve işlevsel bağımsızlığı, program yapısının uygunluğu, dış sistem öğeleri ve modüllere ait ara birimlerin tanımlanması, veri yapısının bilgi alanı ile tutarlılığı, bakım ve onarım sorunları incelenir.

"Modüller etkin mi?" sorusu, modül bağımsızlığının yeterince sağlanıp sağlanmadığı, işlevsel bağımsızlığın olup olmadığı ve ara birimlerin ileride bakımda sorun çıkaracak biçimde tasarlanıp tasarlanmadığı anlamına gelir. Nesneye yönelik yaklaşımda aynı soru sınıfların yapısı ve sınıflar arasındaki bağımsızlık için sorulur; hoca bunun kalite metrikleri konusunda tekrar ele alınacağını söyledi. Modül içi kuvvet (iç veri yapılarının uygunluğu ve birbiriyle tutarlılığı) yüksek olmalı, modüller arası ilişkilendirme (coupling) ise çok kuvvetli olmamalıdır; modüller arasında yalnız gerektiği kadar iletişim bulunmalıdır. "Birinde hesapla, öbüründe yazdır" gibi iç içe geçmiş yapılar bakım ve onarımı zorlaştırır.

> **Ek bilgi (derste anlatılmadı):** Hocanın "iç kuvvet" dediği kavram yazılım tasarımında genellikle bağlılık (cohesion) olarak adlandırılır. İyi tasarımda modül içi bağlılığın yüksek, modüller arası bağlantının (coupling) düşük olması hedeflenir.

**Ayrıntılı tasarım:** Ön tasarımda mimarisi oluşturulan yapının birimleri tek tek ayrıntısıyla incelenir. Her modülün algoritması doğru mu, modül bağımsızlığı iç yapıda gerçekten sağlanmış mı, lokal (yerel) veri yapıları uygun mu diye bakılır. Veri tabanı tasarımı, ara birimlerin ayrıntılı tasarımı ve girdilerle çıktıların uygun tanımlanması da bu aşamada gözden geçirilir.

### 4.5 Kodlama

Kodlama (gerçekleştirme) basamağında ayrıntılı tasarımın programlama diline doğru dönüştürülüp dönüştürülmediğine, bu sırada hata yapılıp yapılmadığına bakılır (ekrandan, 01:15:00, slayt listesinden). Kodlamanın izlenmesinde şunlar araştırılır:

- Tasarımın kaynak programa dönüştürülmesinin doğruluğu: yazılım algoritmayı ve ayrıntılı tasarımı doğru yansıtmış mı?
- Yazım hataları: programlama diline aykırı yazım hataları var mı?
- Kodlama standartlarına ve programlama dili standartlarına uygunluk.
- Program içindeki açıklamaların tutarlılığı ve uygunluğu.
- Tasarımda bulunan hataların kodlamada düzeltilmiş olup olmadığı.

Test ve bakım-onarım basamaklarındaki gözden geçirmenin ilerleyen konularda görüleceği belirtildi.

## 5. Gözden Geçirme Standartları

Gözden geçirmede kullanılacak standartlar da yazılım mühendisliği standartları içinde tanımlanmıştır. Slayttaki örnekler (ekrandan, 01:15:00):

- **SDR – System Design Review (Sistem Tasarım Değerlendirme):** Sistem tasarımı gerçekleştirildiğinde bu tasarımın nasıl değerlendirileceğini, dikkat edilecek kuralları ve bakılacak şeyler için checklist'leri verir.
- **SSR – Software Specification Review:** Yazılım tanımlamanın (spesifikasyonun) gözden geçirilmesi.
- **PDR – Preliminary Design Review (Ön Tasarım):** Ön tasarım gözden geçirme belgesinde hangi başlıkların bulunması gerektiği.
- **TRR – Test Readiness Review (Sınama İşlerine Hazır Olmanın Değerlendirilmesi):** Teste başlamadan önce nelerin tamamlanmış olması gerektiğini, "şunlar yapıldı mı?" sorularıyla yanıtlanan bir checklist gibi tanımlar.

Hoca bir ayrıma dikkat çekti: SRS standardı, gereksinim analizinden sonra yazılan raporun standardıdır; belgede hangi başlıkların bulunacağını ve her başlıkta neler olması gerektiğini bir içindekiler listesi gibi anlatır. SSR ise gereksinim belgesi yazıldıktan sonra onu değerlendirirken nelere bakılacağını, neyin kontrol edileceğini tanımlar. Yani gözden geçirme standartları, her adımdaki gözden geçirme işini yapmanın kurallarıdır.

> **Ders sonrası not:** Altyazıda bu standart "STR" diye geçiyor; slaytta "SDR – System Design Review" yazıyor (ekrandan, 01:15:00).

## 6. Yazılım İncelemesi (Inspection)

### 6.1 Statik ve dinamik geçerleme

Yazılım incelemesi, test yöntemiyle birlikte yazılım kalitesini sağlamada en çok kullanılan yöntemlerden biridir; "code inspection" kavramı daha sık duyulur. İncelemede hatalar kodu çalıştırmadan tespit edilmeye çalışılır. Bu yüzden inspection bir **statik geçerleme** yöntemidir.

Sistem testinde ya da birim testinde ise kod mutlaka çalıştırılır ve hatalar öyle bulunur; bu **dinamik** değerlendirmedir. Hoca bu farkı slayttaki şekille (Şekil 4.1, statik ve dinamik geçerleme) anlattı: Yazılımın bütün ara ürünleri incelenebilir: gereksinim spesifikasyonu, yüksek seviye tasarım, formal spesifikasyon, ayrıntılı tasarım ve program. Bu basamakların sonunda hazırlanan raporlar inceleme aşamasına alınabilir; bu statik geçerlemedir. Test ise yalnız çalıştırılabilen şeylere uygulanır: programa ve prototipe. <!-- BELİRSİZ: Şekil 4.1'in ayrıntısı karede yalnız küçük slayt görüntüsü olarak görünüyor; kutuların listesi altyazıdan alındı. -->

### 6.2 Genel yazılım inceleme süreci

Yazılım inceleme süreci genel olarak üç aşamadan oluşur (Şekil 4.2, ekrandan, 01:20:00):

1. **Planlama ve hazırlık aşaması:** İncelemeyle ilgili genel soruları cevaplamayı amaçlar. Bu sorular slaytta şöyledir:
   - İncelemenin amaç ve hedefleri nelerdir?
   - İncelenecek yazılım parçaları hangileri olacaktır?
   - Bu incelemeyi kim yapacak?
   - İncelemeyi yapacak kişiler hangi özellikleri taşımalılar?
   - Bütün süreç boyunca hangi inceleme teknikleri ve takip eylemleri uygulanacak?
2. **İnceleme ve toparlama aşaması:** Belirlenen kriterlere uygun olarak, görev dağılımından sonra inceleme işlemi yapılır; hatalar tespit edilir ve kayıt altına alınır.
3. **Düzeltme ve tamamlama aşaması:** Bulunan hatalar, yazılımı incelemekle sorumlu kişiler tarafından düzelttirilir ve takip edilir. İstenen sonuçlar elde edilemezse yeniden inceleme için sürecin başına dönülür.

"Kim yapacak?" sorusu, yazılımın bütününün parçalara bölünmesiyle ilgilidir: planı, gereksinim analizini, tasarımı ve kodu kim inceleyecek; kod incelemesi yapılıyorsa hangi modülleri kim inceleyecek? Gereksinim spesifikasyonunu inceleyecek kişiyle kod incelemesi yapacak kişinin taşıması gereken özellikler de farklıdır. Hoca "düzeltme" sözünün, incelemeyi yapanların hataları kendisinin düzelttiği anlamına gelmediğini, hataların geliştiricilere düzelttirildiği anlamına geldiğini açıkladı.

### 6.3 Fagan inceleme süreci

Farklı bakış açılarıyla farklı inceleme modelleri geliştirilmiştir. Slayt başlığında "İnceleme (inspection) Süreci, Fagan (1986)" yazar (ekrandan, 01:25:00) ve hoca Fagan incelemesinin hâlâ yerleşik bir model olduğunu belirtti. Fagan sürecinde aşamalar genel sürece göre daha ayrıntılıdır. Hocanın anlatımına göre önce planlama yapılır, sonra genel bir gözden geçirme ile iş kişilere paylaştırılır; ardından kişisel inceleme, inceleme toplantısı, düzeltme için geri bırakma, tamamlama ve raporlama gelir. <!-- BELİRSİZ: Şekil 4.3'teki aşama kutularının adları karede okunamadı; aşamalar altyazıdan alındı. -->

> **Ders sonrası not:** Slayt ve hoca Fagan sürecini 1986 ile tarihlendiriyor. Fagan'ın inceleme sürecini ilk tanıttığı makale büyük olasılıkla 1976 tarihlidir; 1986 tarihi büyük olasılıkla aynı yazarın incelemelerdeki gelişmeleri anlatan sonraki makalesine aittir.

**Kod okuma.** Slayta göre etkili bir kod okuma tekniği hem yukarıdan aşağıya hem de aşağıdan yukarıya incelemenin bir birleşimi olmalıdır. Yukarıdan aşağıya incelemede kodun ve bütün modüllerin tamamı göz önünde tutulur; aşağıdan yukarıya incelemede modüllerin iç yapıları incelenir. Yani kod incelenirken genel tasarım gözden kaybedilmez ve modüllerin birbiriyle ilişkileri de dikkate alınır. Program mümkün olan en küçük parçalara (örneğin fonksiyon, prosedür, alt program) ayrılarak önce bu parçaların kendi içindeki bütünlüğü ve doğruluğu, sonra da programın bütünüyle olan uyumları incelenmelidir.

**İnceleme ekibi.** İnceleme ekibi; inceleme sorumlusu, inceleyiciler, yazar (kodu yazan), kod okuyucu (toplantıda kodun açıklamasını yapan) ve kayıtçıdan oluşur.

### 6.4 Teknik inceleme raporu

İnceleme sonunda bir rapor hazırlanır. Teknik inceleme özet raporunda şunlar bulunur (ekrandan, 02:20:00, slayt listesinden):

- Neyin gözden geçirildiği.
- Kimin gözden geçirdiği.
- Hangi hata ve eksikliklerin bulunduğu ve ne yapılması gerektiği.

Seçenek matrisinde inspection'ı diğerlerinden ayıran en önemli özellikler hataların sınıflandırılması ve checklist kullanılmasıydı; bu yüzden raporda değerlendirmeler checklist ile gösterilir ve bulunan hatalar sınıflandırılarak açıklanır. Raporun sonunda bir karar belirtilir. Slayttaki seçenekler:

- a) Değişiklik yapılmaksızın kabul edilmesi.
- b) Belirtilen önemsiz hataların düzeltilmesi koşulu ile kabul edilmesi.
- c) Reddedilerek düzeltme sonunda yeniden incelenmesi.

Hoca anlatımında ilk iki kararı örnek verdi; bu kararlarla iş yazılım geliştirme ekibine geri gönderilebilir.

## 7. Yazılım Sınama (Test) ve V Model

### 7.1 Sınamanın tanımı

Slayttaki tanıma göre sınama (testing), bir programdaki hataları bulmak amacıyla yapılan işlemlerdir. Sınama, yazılımın (a) fonksiyonel, (b) performans, (c) dayanıklılık ve (d) yapısal bakımlardan yeterliliğini denetler (ekrandan, 01:30:00). Hoca bunu şöyle açtı: yazılım fonksiyonel gereksinimleri karşılıyor mu, performans ve dayanıklılık gibi fonksiyonel olmayan özellikleri karşılıyor mu, iç yapısıyla ve algoritma yapısıyla ilgili özellikleri karşılıyor mu?

Bölümün hedefleri slayt listesinde şöyle görünüyor: dinamik geçerlemeyi ve yazılım test sürecini tanımlamak, birim test ve bütünlük test işlemlerini özetlemek, regresyon testini tanımak, saydam kutu ve kara kutu test tiplerini incelemek, performans, dayanıklılık ve güvenlik testi olarak sistem testini tanımlamak (ekrandan, 02:20:00, slayt listesinden).

### 7.2 Verification ve validation: terim düzeltmesi

Hoca eski slaytlarında verification için "geçerleme" yazdığını, bunu düzelttiğini belirtti. Türkçe sözlükte iki kavram da hem "geçerleme" hem "doğrulama" diye karşılanabilir. Ancak test üzerinde çalışanlar ortak bir anlaşma yaparak **validation'a geçerleme, verification'a doğrulama** adını vermiştir.

> **Hocanın vurgusu:** Validation = geçerleme, verification = doğrulama. Eski slaytlarda ters yazılmış yerler olabilir.

> **Ders sonrası not:** Hocanın kendi düzeltmesine göre, bu derste "statik geçerleme" diye geçen "static verification" kavramı aslında "statik doğrulama" olarak okunmalıdır. Slaytlardaki bazı başlıklarda (ör. "Dinamik Geçerleme (verification)") eski çeviri kalmıştır.

### 7.3 V model yaklaşımı

V model, verification ve validation adlarından ve şeklin yapısından dolayı bu adı alır; waterfall modelinin bir yorumudur. Şekil 3.2 "Yazılım geliştirme ve test sürecindeki geçerleme ve doğrulama aktiviteleri (V model yaklaşımı)" şöyledir (ekrandan, 01:40:00):

```text
Müşteri Gereksinimleri  ------- Geçerleme ----------->  İşlemsel kullanım
   Ürün Spesifikasyon   --- Geçerleme/Doğrulama --->    Sistem Test
     Yüksek düzey tasarım  ---- Doğrulama ---->       Bütünlük Test
        Alçak düzey Tasarım  -- Doğrulama -->     Bileşen Test
                      Kodlama & Birim Test
```

V'nin sol kolu yazılım geliştirme süreci aktiviteleri (müşteri gereksinimlerinin alınması, yazılım/ürün spesifikasyonunun oluşturulması, yüksek düzey yani genel tasarım, alçak düzey yani alt düzey tasarım ve kodlama), sağ kolu test süreci aktiviteleridir. Alt düzeylerde "doğru yolla mı gidiyoruz?" sorusuyla doğrulama (verification) yapılır; ürün spesifikasyonu ile sistem testi düzeyinde ikisi birden yapılır; en üst düzeyde tümüyle geçerleme (validation) yapılır. Çünkü kullanıcı programa dışarıdan bakar ve "benim isteklerim bunlar, program bunları yapıyor mu?" diye sorar; iç yapıda ne olduğu onu ilgilendirmez.

Sağdaki her test, karşısındaki geliştirme adımının ürettiği belgeyi kullanır. Kodlama sonucunda elde edilen kod birim testte test edilir. Bütünlük testi, yüksek düzey tasarım raporunda hazırlanan yapı diyagramlarına ya da UML diyagramlarına göre yapılır. Sistem testi ürün spesifikasyonuna göre yapılır. İşlemsel kullanımda ise müşteri gereksinimlerinin sağlanıp sağlanmadığına bakılır.

## 8. Birim Test

### 8.1 Tanım ve kapsam

Slayttaki tanıma göre ünite (birim) testi, yazılım tasarımının en küçük birimi olan modül üzerinde uygulanmaktadır. Ayrıntılı tasarım tanımlarına dayanılarak, modül içerisindeki hataları bulmak üzere önemli kontrol yolları sınanmaktadır. Saydam kutu testi olarak uygulanan bu işlem, çok sayıdaki modül üzerinde paralel olarak yürütülmektedir (ekrandan, 01:55:00).

Birim testinde modülün şu kısımları sınanır:

- Ara birim.
- Lokal veri yapısı.
- Kontrol yapıları arasındaki ana yollar.
- Hata arama yolları.
- Modül sınırları.

### 8.2 Test sürücü ve koçan

Birim testinde test edilen birimin yanında bir test sürücü (driver) ve koçan (stub) kullanılır. Hoca "koçan" Türkçesinin slaytta geçtiğini ama pek kullanılmadığını söyledi. Bir test programı oluşturulur: hangi test verisinin kullanılacağı ve beklenen sonuçlar belirtilir. Bu iş için araçlar kullanılabilir; örneğin Java ile yazılmış bir program için JUnit kullanılabilir.

- **Test sürücü (driver):** Test edilen modülü çağıran bir modül varsa onun yerine geçer, test verisini modüle aktarır ve sonuçları dışarıya aktarır.
- **Koçan (stub):** Test edilen modülün içinden çağrılan modüller henüz test edilmemişse, bunların yerine yerleştirilen yapay modüldür.

Slayta göre modülün bağımsız olmaması halinde sınamada diğer modüller de dikkate alınmalıdır; bu amaçla her ünite testi için bir test sürücü ve/veya koçan yazılımı geliştirilir (ekrandan, 02:00:00). Test programlarının geliştirilmesi de diğer yazılımlar gibidir; geliştirmeye test planı uyarınca ve yazılım tasarımı ile birlikte başlanmalıdır.

> **Ek bilgi (derste anlatılmadı):** Driver ve stub, birbirine bağımlı modüllerin tek tek test edilebilmesini sağlar. Örneğin bir hesaplama modülü bir veri tabanı modülünü çağırıyorsa ve o modül henüz hazır değilse, sabit değer döndüren basit bir stub yazılarak hesaplama modülü yalıtılmış biçimde test edilebilir.

### 8.3 Test senaryosu (test case)

Slayttaki tanıma göre test senaryosu (test case), belirli bir program yolunu işlemek ya da özel bir gereksinime uygunluğu onaylamak amacı ile düzenlenen bir dizi sınama verisinden ve buna ilişkin işlemlerden oluşturulmaktadır (ekrandan, 02:00:00).

Hoca bunu bir örnekle açıkladı: Bir programda izlenen birden fazla kontrol akışı olabilir. İkinci dereceden bir denklemin köklerini bulan programda deltanın durumuna göre üç farklı yol izlenir ve hangi yolun izleneceği giriş verisine bağlıdır. Birim testte her yolu deneyebilmek için bizi bu üç farklı akışa yönlendirecek test verisi grupları oluşturmak gerekir. Rastgele veri girilip sonuçlara bakılırsa, girilen veriler hep aynı program akışından geçebilir. Bu yüzden kontrol akışı izlenmeli ve test verisi buna göre hazırlanmalıdır. Bu, yol odaklı birim testtir.

Test senaryosu bir de fonksiyonel gereksinim açısından düşünülebilir: programın gerçekleştirdiği bir iş, ona uygun veri gönderilerek denenir. Böylece test senaryosu ya bir program kontrol akışını işletmek üzere hazırlanan test veri grubu ya da bir senaryoya (gereksinime) uygunluğu onaylamak için hazırlanan test verisi olarak görülebilir; her iki durumda da bir program akışı çerçevesinde kontrol yapılır.

> **Ek bilgi (derste anlatılmadı):** Denklem $ax^2+bx+c=0$ için $\Delta=b^2-4ac$ olmak üzere üç yol $\Delta>0$ (iki farklı reel kök), $\Delta=0$ (çift kök) ve $\Delta<0$ (reel kök yok) durumlarıdır. Her yolu en az bir kez işletmek için her duruma düşen birer test verisi gerekir.

## 9. Genişletilmiş V Model ve Alt Test Adımları

Bütünlük testi, sistem testi ve kullanıcı testlerinin ayrıntısı sonraki derse bırakıldı; bu derste V modelin genişletilmiş hali gösterildi. Şekil 5.6 "Test sürecindeki alt test adımları (V model yaklaşımına göre)" temel V modele kesikli kutularla şu testleri ekler (ekrandan, 02:05:00):

- Bütünlük testinin yanında **regresyon testi**.
- Sistem testinin üstünde **kabul testi**.
- İşlemsel kullanımın yanında **beta testi** ve **teşhis testi**.

**Regresyon testi** bir tamamlama testidir. Birimlerde değişiklik olmuşsa, düzeltme yapıldıktan sonra bütünlük testinin tekrarlanması gerekir; bu teste regresyon testi denir. Bütünlük testini tamamlayıcı olarak yapılır.

Sistem testinden sonra **onay (kabul) testi** gelir. Onay testinden önce **alfa testi** yapılır: sistem testi tamamlandıktan sonra yazılım ekibi içinde kullanıcıları temsil eden bir grup oluşturulur ve yazılım bu kullanıcıya benzer grup tarafından çalıştırılarak test edilir. **Beta testi** ise yazılımın potansiyel, gerçek kullanıcılara verilerek test edilmesi aşamasıdır.

**Teşhis testi**, işlemsel kullanımda genel olarak bir hata olup olmadığına bakılıp, hata görülürse ayrıntılara (alt test adımlarına) tekrar dönülebildiğini gösterir.

<!-- BELİRSİZ: 02:07:31-02:07:54 arasında bütünlük testinde kullanılan bir araç ya da yöntemden söz ediliyor, ancak altyazı bozuk ("M-Bütünlük testinde kullanıyoruz"); ne olduğu anlaşılamadı. -->

## 10. Ders Kaynakları ve Makale Araştırması

Bir öğrencinin sorusu üzerine hoca dersin kaynaklarını sıraladı:

- Roger Pressman'ın *Software Engineering* kitabının kaliteyle, testle ve yazılım metrikleriyle ilgili bölümleri; yazılım mühendisliği kitabı olmasına rağmen bu konuları çok ayrıntılı anlatır.
- Test ve kaliteyle ilgili bütün kavramları içeren bir *Software Quality* kitabı.
- Ian Sommerville'in *Software Engineering* kitabı.
- Süreli ve indeksli dergiler: IEEE Software, IEEE Transactions on Software Engineering, Software Quality dergileri; ACM, IEEE, Springer ve Elsevier'in kalite ve testle ilgili dergileri. IEEE Software'de daha kısa ve anlaşılır makaleler bulunabileceği, başlangıç noktası olarak uygun olduğu belirtildi.
- Yazılım testi, yazılım kalitesi, test otomasyonu, yazılım mühendisliğinde yapay zeka yaklaşımları gibi konulardaki uluslararası sempozyumların bildirileri.

Derleme makalesi için uluslararası indekslerde taranan dergilerden bir başlangıç makalesi seçilmesi ve konunun dersin içindekiler başlıklarından birine dayanması istendi. Dergilere üniversite kütüphanesinin sayfası üzerinden, kurumsal (öğrenci) e-posta ile kimlik doğrulanarak ücretsiz erişilebileceği; üniversite bu aboneliklerin bedelini ödediği için para ödenmemesi gerektiği söylendi.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:29:00): Statik geçerleme (static verification) nedir? Statik ve dinamik arasındaki fark nedir, "sabitlik" neyin sabitliğidir?

**Cevap (derste verildi):** Verification, yazılımın doğru yolla üretilip üretilmediğinin kontrolüdür. Statik geçerleme kodu çalıştırmadan yapılan incelemedir; yazılım gereksinim spesifikasyonu raporu, tasarım spesifikasyonu raporu ve kod gibi bütün ara ürünlere uygulanabilir. Dinamik geçerleme ise test aşamasında yazılımı mutlaka çalıştırarak hata bulmaktır. Bir öğrencinin verdiği "statik olan, yazılımı hiç çalıştırmadan yapılandır" cevabı hoca tarafından doğru kabul edildi.

**Soru 2** (derste sözlü, 01:32:12): Fortify, SonarQube, CAST gibi statik kod analizi yapan araçlar kodu (araç vasıtasıyla) işliyor; bunlar statik mi, dinamik mi sayılır?

**Cevap (derste verildi):** Statik. Çalışan şey analiz aracıdır; incelenen yazılım çalıştırılmaz, kod araç tarafından incelenir.

> **Ders sonrası not:** Altyazıda araç adları "Fortify, Sonar, Küp, Cast" diye geçiyor; bunlar büyük olasılıkla Fortify, SonarQube ve CAST araçlarıdır.

**Soru 3** (derste sözlü, 01:32:48): O halde dinamik geçerleme, ürüne (production) geçtikten, deployment'tan sonra yapılan doğrulama mı oluyor?

**Cevap (derste verildi):** Kısmen evet; ancak ürüne çıkmak şart değildir. Bir prototip üretilmişse o da çalıştırılarak test edilebilir. Dinamik geçerleme için çalıştırılabilir bir ürün (end product), prototip bile olsa, gerekir.

## Dersin Toparlaması

Bu derste kaliteyi sağlama aktivitelerinden gözden geçirme ve inceleme ayrıntılı olarak işlendi, ardından teste giriş yapıldı. Gözden geçirmenin, hataların erken ve ucuz bulunması için her durak noktasında yapılan bir "eleme" olduğu; amaçlarının işlevsel/mantıksal/kodlama hatalarını bulmak, gereksinimlere ve standartlara uygunluğu onaylamak olduğu görüldü. Formal olmayan gözden geçirme, walkthrough ve inspection seçenek matrisiyle karşılaştırıldı; sistem analizinden kodlamaya kadar her basamakta nelerin gözden geçirildiği ve SDR, SSR, PDR, TRR gibi gözden geçirme standartları anlatıldı. Inspection'ın kodu çalıştırmadan yapılan statik bir yöntem olduğu, genel inceleme sürecinin üç aşaması, Fagan süreci, kod okuma tekniği, inceleme ekibi ve teknik inceleme raporu ele alındı.

Test kısmında sınamanın tanımı, verification = doğrulama ve validation = geçerleme terim düzeltmesi, V model yaklaşımı, birim testin kapsamı, test sürücü ve koçan, test senaryosu ve yol odaklı test verisi hazırlama işlendi; genişletilmiş V model üzerinde regresyon, kabul, alfa, beta ve teşhis testleri tanıtıldı. Bir sonraki derste bütünlük testi, sistem testi ve kullanıcı testlerinin ayrıntılarına geçileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
