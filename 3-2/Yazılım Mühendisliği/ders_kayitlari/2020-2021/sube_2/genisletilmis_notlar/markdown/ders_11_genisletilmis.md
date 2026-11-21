# Ders 11 Genişletilmiş Notu: Yazılım Proje Yönetimi, Maliyet Tahmin Yöntemleri (Delphi, Analiz, Walston-Felix, COCOMO, PNR) ve İleri Yazılım Sınama Teknikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yazılım Proje Yönetimine Giriş, Zorluklar ve Planlama İlkeleri
- 2. Proje Yönetiminde Kişi Etkenleri, Takım Yapıları ve Haberleşme
- 3. Proje Yönetiminde Ölçüm, Kalite Etkenleri ve Süreç Ölçütleri (HGE ve GQM)
- 4. Yazılım Proje Yönetiminde Maliyet Tahmin Yöntemleri
- 5. İleri Yazılım Sınama Teknikleri ve Resmi Gözden Geçirme (IEEE 1028)
- Örnek Sorular
- Dersin Toparlaması

## 1. Yazılım Proje Yönetimine Giriş, Zorluklar ve Planlama İlkeleri

### 1.1 Yazılım Projelerinin Başarısızlık Nedenleri ve Proje Yönetiminin 4 Odak Alanı

Klasik (geleneksel) yazılım geliştirme süreçleriyle yürütülen projelerde başarı oranı yaklaşık `%50` düzeyindeyken, çevik (*agile*) süreçlerin kullanılmasıyla bu oran `%75–80` bandına yükselebilmektedir. Yazılım projelerinin önemli oranda başarısızlığa uğramasının başlıca nedenleri şunlardır (ekrandan, 00:06:30):
- **Yazılım geliştirmedeki zorluklar:** Yoğun zihinsel emek gerektirmesi ve bir problem çözüldükçe beklenti çıtasının sürekli yükselmesi.
- **Ölçek büyüklüğünden kaynaklanan zorluklar:** Hem yazılım ölçeğinin (kod hacmi ve modüller arası bağımlılıkların) hem de kişi ölçeğinin (çalışan sayısının) büyümesi.
- **Kestirimdeki (*estimation*) zorluklar:** Süre, çaba ve maliyet tahminlerinin güçlüğü.
- **İnsanlarla çalışmadaki zorluklar.**
- **Teknolojideki değişimler ve gereksinimlerdeki değişimler.**
- **Politik değişimler ve mali değişimler:** Buradaki *"politik değişimler"* ifadesiyle ülke veya uluslararası siyaset değil, **şirket içi / kurum içi politikalar** (üst yönetimin öncelik değiştirmesi, kârlılığa mı yoksa pazar payına mı odaklanılacağı, kaynakların hangi projelere kanalize edileceği yönündeki kurumsal kararlar) kastedilmektedir (ekrandan, 00:06:30).

Yazılım proje yönetimi, yukarıda sayılan zorlukların çözümüne ve etkilerinin azaltılmasına odaklanan en iyi uygulamalar bütünüdür.

> **Hocanın vurgusu (Önem Sırasına Göre Proje Yönetiminin 4 İlgi Alanı):**
> Yazılım proje yönetiminin ilgi alanları önem sırasına göre dizildiğinde, üzerinde çalışılan projenin kendisi en son sırada, **insan faktörü ise birinci sırada** yer alır (ekrandan, 00:06:30):
> 1. **Kişiler (*People*):** Ne kadar iyi teknolojiye, kaynağa veya sürece sahip olursanız olun; doğru kişileri bir araya getirip motive edemiyor ve işbirliği içinde çalıştıramıyorsanız proje `%100` başarısızlığa uğrar. Bu yüzden birinci odak noktası insan dinamikleri ve kişiler arası etkileşimdir.
> 2. **Ürün (*Product*):** Ortaya çıkacak fiziksel yazılım ürününün zamanında, bütçe dâhilinde, istenen gereksinimleri karşılayacak ve kaliteli biçimde üretilmesi.
> 3. **Süreç (*Process*):** Seçilen yazılım geliştirme sürecinin kurallarına ve önerilerine uygun biçimde yürütülmesi.
> 4. **Proje (*Project*):** Proje yönetim sürecinin kendisinin nasıl daha verimli hâle getirilebileceği (proje yönetimi kendisiyle ilgilenmeyi en son sıraya koyar) (ekrandan, 00:06:30).

### 1.2 Disiplinler Arası Yapı ve Proje Ölçekleri

Yazılım proje yönetimi tek bir disiplinden ibaret değildir; **1) Yazılım mühendisliği teknikleri**, **2) İdari yönetim bilimi** ve **3) Genel mühendislik projeleri yönetimi** olmak üzere üç disiplinin kesişim kümesinde yer alır.

Projeler insan kaynakları ve iş hacmine (süreye) göre dört ölçekte değerlendirilir:
1. **Çok Küçük Ölçekli Projeler:** `1–2` çalışan içeren ve `1–2 ay` içinde tamamlanan projeler.
2. **Küçük Ölçekli Projeler:** `2–3` çalışan içeren ve `2–3 ay` süren projeler (örneğin mobil uygulama geliştirme projeleri genellikle küçük veya çok küçük ölçekli çevrimlerle tamamlanır).
3. **Orta Ölçekli Projeler:** `4 ila 6 ay` sürebilen projeler.
4. **Büyük Ölçekli Projeler:** En az `5` çalışan (çoğunlukla `20` ve daha fazla kişi) içeren ve `1,5 – 2` hatta `3 yıl` süren projeler.
   - Küçük ölçekli projelerde basit yönetim teknikleri yeterli olurken, büyük ölçekli projelerde çok sayıda kişinin farklı modüller üzerinde çalışması modüller arası bağımlılığı (*coupling*) artırır; bir modülde yapılan değişiklik başka bir modülde daha önce geçen birim testlerinin bozulmasına yol açabilir ve sorunun değişiklik yapılan yerde mi yoksa tasarımı yanlış yorumlayan karşı modülde mi olduğunu çözmek iyi tanımlanmış bir yönetim süreci gerektirir.

### 1.3 Planlama Yaklaşımları ve Temel Planlama İlkeleri

Proje yönetiminin vazgeçilmez etkinliği olan **planlama** için üç ana yaklaşım vardır:
1. **Geleneksel Yaklaşım:** Planlamayı projenin ayrıntılı bir **yol haritası** olarak görür; bir noktadan diğerine giderken ne kadar ayrıntılı harita kullanılırsa hedefe en az harcamayla ulaşma şansı o kadar artacağından ayrıntılı planlamayı vazgeçilmez kabul eder.
2. **Basitlik Yaklaşımı:** Özellikle 12–18 aylık orta ve büyük ölçekli projelerde geleceğin kaçınılmaz olarak değişiklikler getireceğini, bu yüzden baştan çok ayrıntılı plan yapmanın boşa gideceğini savunarak planların basit tutulmasını önerir.
3. **Çevik (*Agile*) Yaklaşım:** İlk iki yaklaşım arasında denge kurar; bir ön hazırlık gereklidir ancak asıl ayrıntılı yol haritası proje ilerledikçe ortaya çıkar.

**Planlama İlkeleri (Slayt 130) (ekrandan, 00:20:00):**
- **Projenin sınırlarını belirleyin (*Nereye gideceğinizi bilmezseniz kaybolursunuz*):** Ortaya çıkarılacak ürünün amaçları, hedefleri ve kapsam sınırları önceden çizilmezse proje asla bitmez (ekrandan, 00:20:00).
  - *Tarihsel Örnek — Charles Babbage:* 1800'lü yıllarda ilk modern programlanabilir sayısal bilgisayarın (*Fark Makinesi / Analitik Makine*) temelini atan Charles Babbage, tasarıma sürekli *"şunu da yapabilir, bu özellik de eklenebilir"* diyerek yeni yetenekler eklemiş; projenin sınırlarını belirleyip *"artık bu noktada durup inşa edeyim"* diyemediği için makinesi yalnızca kağıt üzerinde tasarım olarak kalmış ve fiziksel olarak çalışan bir donanıma dönüşememiştir.
- **Müşteriyi planlama eylemlerine katın:** **Öncelikleri, sınırları ve zamanlamayı müşteri belirler (bu sırada); ancak gerçekçiliği korumak amacıyla yazılım ekibi pazarlık yapar (aksi sırada)** (ekrandan, 00:20:00). Müşteri kendi ihtiyacını (gereksinim sınırlarını), neyin kendisi için öncelikli olduğunu ve ürüne ne zaman ihtiyaç duyduğunu bilir; ancak teknik bilgi birikimi olmadığı için gerçekçi olmayan süre/kapsam taleplerinde bulunabilir. Teknik ekip ise gereken çabayı hesaplayarak müşteriyle karşılıklı pazarlık (*negotiation*) yapar ve denge noktasını bulur.
- **Planlamanın doğası yinelemelidir (*Plan asla taşa yazılmaz*):** Değişim kaçınılmaz olduğundan planlar süreç içinde güncellenir; değişikliklerin projeye nasıl yansıtılacağının kuralları müşteriyle önceden sözleşmeyle belirlenmelidir (ekrandan, 00:20:00).
- **Planın ölçeği ile planın vadesi ters orantılı olmalıdır:** Vade ne kadar yakınsa (kısa vadeli plan) o kadar **ince ayrıntılı**, vade ne kadar uzaksa (uzun vadeli plan) o kadar **genel hatlarıyla** planlama yapılmalıdır.
- **Bildiklerinizi kullanarak kestirimlerde bulunun:** Geçmiş proje deneyimlerine dayalı eğitimli tahminler (*educated guesses*) yapın; bilginin kapsamı, doğruluğu ve belirginliği kestirimin doğruluğunu doğrudan etkiler (ekrandan, 00:20:00).
- **Planın her aşamasına risk değerlendirmesini (*teknik, mali, kişisel, politik riskler*) ve kalite güvence eylemlerini ekleyin** (ekrandan, 00:20:00).
- **Gerçekçi olun (*Yazılımcı süpermen veya robot değildir*):** İnsanın çalışma kapasitesi sınırlıdır; sıkışık dönemlerde çalışma temposu en fazla **`%10–15`** artırılabilir, ancak `%30–40–50` oranında bir ek yükün altından kalkılması beklenemez (ekrandan, 00:20:00).

## 2. Proje Yönetiminde Kişi Etkenleri, Takım Yapıları ve Haberleşme

### 2.1 Takım Yöneticisi (Teknik Yönetici) ve Proje Yöneticisi Modelleri

Yazılım proje yönetimi üç disiplinin (yazılım mühendisliği, yönetim bilimi, mühendislik proje yönetimi) kesişiminde yer aldığından, takım yöneticisinin de hem teknik yeteneklerinin hem de sosyal ve yönetimsel yeteneklerinin yüksek olması gerekir. Uygulamada (teknopark firmalarında, Ar-Ge ve KOSGEB/TÜBİTAK projelerinde) iki farklı yönetim modeli görülür:
1. **Tek Yönetici Modeli (Takım Yöneticisi = Proje Yöneticisi):** Teknik ekibin başındaki yönetici hem teknik kararları verir hem de projenin idari/takvim yönetimini yürütür. Bu modelde yöneticinin en çok zorlandığı nokta; bir yanda **müşteri**, bir yanda **yazılım evinin üst yönetimi**, diğer yanda **teknik ekip** arasındaki üçlü dengeyi kurmaktır.
2. **Ayrık Yönetici Modeli (Takım Yöneticisi $\neq$ Proje Yöneticisi):** Teknik ekibin başında ayrı bir takım lideri bulunur; **proje yöneticisi** ise yüksek teknik bilgiye sahip olması beklenmeyen ancak idari/yönetim bilgisi güçlü ayrı bir kişidir. Proje yöneticisi yalnızca projenin plana uygun ilerleyip ilerlemediğini ve **risk bilgi sayfalarındaki erken uyarı sinyallerini** izler; sapma olduğunda takım yöneticisiyle kafa kafaya verip düzeltici eylemleri belirler. Bu izleme işi bir kişinin zamanının `%100`'ünü almadığı için tek bir proje yöneticisi aynı anda `2, 3` hatta `4` ayrı projeyi izleyip yönetebilir.

**İyi Bir Teknik Yöneticinin Sahip Olması Gereken Özellikler:**
- Teknik ekibi **motive edebilmeli** ve ortak amaç etrafında kenetleyebilmelidir.
- Hem ekibini hem de yazılım geliştirme sürecini ürünün ve ekibin özelliklerine göre (küçük, orta veya büyük ölçekte) **düzenleyebilmelidir**.
- Ürün ve süreç sınırlarını korurken ortaya çıkan fırsatları algılayabilmeli ve **ekibini yaratıcı fikirler üretmeye teşvik edebilmelidir** (üretilen bir fikir takvim kısıtı yüzünden o projede kullanılamasa bile baskılanmamalı, sonraki fazlar veya gelecek projeler için not edilmelidir).
- **İyi bir sorun çözücü** olmalıdır: Teknik ve yönetimsel sorunlara doğru tanı/teşhis koyabilmeli, ilk uygulanan çözümün işe yaramadığı görüldüğünde bunda ısrarcı olmayıp alternatif planları gecikmeden devreye sokabilmeli ve **sorumluluk alabilmelidir**.

### 2.2 Takım Üyelerinin Özellikleri ve Takım Ruhunu Bozan Etkenler

Takım üyeleri birbirine saygı ve güven duymalı, yetenekleri birbirini tamamlar nitelikte olmalı ve her üye kendi güçlü/zayıf yönlerinin farkında olarak takım liderinin görev dağılımına uyum sağlayabilmelidir.

**Takım Ruhunu Bozan Olumsuz Etkenler ve Çözüm Yolları:**
1. **Telaşlı İş Ortamı:** Belli bir plana uymadan sürekli gelen anlık değişiklikler, yeni görevler ve kesintiler odaklanmayı bozar; işe yeterli özen gösterilememesine ve kalitenin düşmesine yol açar. *Çözümü:* Değişiklik ve görev taleplerinin kurallı bir biçimde (**resmi iletişim** düzeniyle) alınmasıdır.
2. **Sık Ortaya Çıkan Hayal Kırıklıkları ve Başarısızlıklar (Suçlama Psikolojisi):** Başarısızlık yaşandığında ekip üyeleri arasında sürtüşme çıkar; çünkü insan doğası gereği kendi hatalarına karşı perdelidir ve suçu hep karşı tarafta arar (hoca burada insanın başkasında gördüğü bir kusuru aslında kendisinde de az çok bulunduğu veya geçmişte deneyimlediği için tanıyabildiğini hatırlatmıştır). *Çözümü:* Başarısızlığa uğrayan ve sürtüşme yaşayan bir ekibi olduğu gibi tutmak yerine **yeniden yapılandırmak**, üyeleri bireysel yeteneklerinin başka takımlardaki eksikleri tamamlayacağı farklı ekiplere dağıtmak en doğru karardır.
3. **En Başarılı Ekibe Sürekli En Zor İşlerin Verilmesi:** Madalyonun diğer yüzünde, çok uyumlu ve başarılı bir ekibe *"nasılsa altından en iyi onlar kalkar"* diyerek sürekli en zor projeleri yüklemek de yanlıştır. Sürekli aşırı zorlanan ekipte zamanla yorgunluk, sürtüşme ve başarısızlık riski baş gösterir.
4. **Sürece Uygun Yönlendirme Eksikliği ve Belirsiz Rol/Yetkiler:** Hangi işin kim tarafından yapılacağı ve hangi konuda karar verme yetkisinin kimde olduğu net tanımlanmazsa; ya iş ortada kalır (*"sen yapacaktın, ben yapacaktım"*) ya da yetki karmaşası ve tartışma çıkar.

### 2.3 Dört Temel Takım Yapılanması ve Haberleşme Yolları (Slayt 134–135)

Takımların iç örgütlenmesinde dört temel yaklaşım kullanılır (ekrandan, 01:00:00; ekrandan, 01:06:00):

1. **Kapalı Yaklaşım (ekrandan, 01:00:00):**
   - Geleneksel bir yetki hiyerarşisi ve kontrol mekanizmaları bulunur (proje yöneticisi $\rightarrow$ teknik yönetici $\rightarrow$ kıdemli tasarımcı/programcı $\rightarrow$ programcılar, test sorumlusu; kimin kime iş verdiği ve raporladığı kesin çizgilerle bellidir).
   - Geçmiş deneyimlere benzer projelerde ve şelale (*waterfall*) modelinde başarılı bir yapıdır; disiplin sorunu yoktur.
   - Ancak **yaratıcı fikirler ortaya çıkarmak ve ilk kez girilen yeni problem alanları için uygun değildir** (ekrandan, 01:00:00).
2. **Rastgele (*Random* / Serbest) Yaklaşım (ekrandan, 01:00:00):**
   - Kapalı yaklaşımın tam zıt ucudur; takım üyeleri bireysel ve teknik yeteneklerine göre kendi aralarında doğal bir yapı kurarlar (örneğin ayrıntılara dikkat edenlerin sınamayı, sınırları iyi görenlerin artım planındaki belirsizlikleri üstlenmesi).
   - **Yaratıcı fikirler ortaya çıkarmak ve Ar-Ge projeleri için en uygun yaklaşımdır.**
   - Dezavantajı ise **disiplin elde etmenin zor olmasıdır** (ekrandan, 01:00:00).
3. **Açık Yaklaşım (ekrandan, 01:00:00):**
   - Kapalı ve rastgele yaklaşım arasında denge kuran **demokratik yapıdır**; kontrol mekanizmaları bulunur ancak yapılanma serbesttir ve kararlar ortaklaşa alınır.
   - **Karmaşık sorunların çözümü için uygundur.**
   - Dezavantajı, farklı çözüm önerilerini savunan gruplar arasındaki ikna tartışmalarının uzaması nedeniyle **etkinliği (*efficiency*) ve verimliliği sağlamanın zor olabilmesidir** (takım liderinin belirleyici oy yetkisi olsa bile karşı görüştekilerde kırgınlık birikebilir) (ekrandan, 01:00:00).
4. **Eşzamanlı (*Synchronous*) Yaklaşım (ekrandan, 01:06:00):**
   - Problemin takımın üzerine düşen bölümünün de bağımsız alt parçalara ayrılabildiği durumlarda (*Rapid Application Development — RAD* sürecinde olduğu gibi) kullanılır.
   - Takım kendi içerisinde problemin alt parçalarını paylaşarak alt takımlara bölünür; aynı alt takım içinde etkileşim yoğun iken **alt takımlar arasında etkileşim azdır**. Dezavantajı her problemin bu şekilde bağımsız parçalara bölünmeye uygun olmamasıdır (ekrandan, 01:06:00).

**Takım İçi ve Takımlar Arası Haberleşme Yolları (Slayt 135) (ekrandan, 01:06:00):**
- **Resmi (*Formal*) Yollar:** Yazı ile (e-posta, standart elektronik formlar), zamanlı mesajlaşma kuralları ile (ör. *"yeni gereksinim değişiklikleri her pazartesi öğlene kadar bildirilir"*, *"hata bildirimleri günün ilk iki saatinde yapılır"*) ve yeri, zamanı, gündemi önceden belirlenmiş kurallı toplantılar ile yürütülür. Geleneksel/şelale süreçlerde tercih edilir ve telaşlı iş ortamını önler (ekrandan, 01:06:00).
- **Gayri Resmi (*Informal*) Yollar:** Sözlü iletişim, kişisel etkileşimler (ör. açık ofiste veya kahve makinesi başında) ile gün içerisinde gerektikçe anlık yapılır. Çevik süreçlerde ve anlık sorun çözmede tercih edilir; ancak aşırıya kaçarsa iş yerindeki telaşı artırabilir (ekrandan, 01:06:00).

## 3. Proje Yönetiminde Ölçüm, Kalite Etkenleri ve Süreç Ölçütleri (HGE ve GQM)

### 3.1 Proje Ölçümü vs. Süreç Ölçümü ve Kaliteyi Etkileyen 4 Etken Grubu

Projenin plana uygun ilerleyip ilerlemediğini izlemek için yapılan ölçümler ikiye ayrılır:
1. **Proje Ölçümü:** Odağı **teknik düzeydir**; geliştirilen yazılım ürününün ilerlemesini ve **iç kalite özelliklerini** ölçerek yazılım geliştirme ekibini yönlendirmeyi amaçlar (veri toplama *Jira* gibi görev atama araçlarıyla mümkün olduğunca otomatik yapılmalıdır).
2. **Süreç Ölçümü:** Odağı **yönetimsel düzeydir**; yazılımın **dış kalite ölçütlerini** ve kullanılan yazılım geliştirme sürecinin tüm aşamalarındaki istatistikleri ölçerek hem mevcut projede hem de gelecekteki projelerde **sürecin kendisini iyileştirmeyi** amaçlar.

**Ortaya Çıkacak Ürünün Kalitesini Etkileyen Çevresel ve İçsel Etkenler:**
1. **Kişi Etkenleri (En Önemli Etken):** Çalışanların yeteneği, istekliliği ve uyumlu çalışabilmesi.
2. **Ürün Etkenleri:** Çözülmeye çalışılan problemin ve ürünün karmaşıklığı/ölçeği (artan zorluk takım maneviyatını da etkiler).
3. **Teknolojik Etkenler:** Kullanılan yazılım geliştirme araçlarının ve donanım bileşenlerinin kalitesi ve **olgunluk düzeyi** (birkaç revizyon geçirmiş olması, eğitimsel belgelerinin/kitaplarının/videolarının ve nitelikli bir topluluk [*community*] desteğinin bulunması; açık kaynaklı araçlarda karşılaşılan eksikler proje sonunda geliştirilerek topluluğa geri kazandırılabilir).
4. **Çevresel Koşullar:** Müşterinin iletişim ve işbirliği yetenekleri (müşteri işbirliğine kapalıysa gereksinim belirsizlikleri ve tasarım uyuşmazlıkları doğar) ile geliştirici firmanın **iş akış kuralları ve şirket kültürü** (ör. katı hiyerarşik ve bürokratik bir kurumda açık veya serbest takım yapılanması yürütülemez).

### 3.2 Ölçütlerin Gizlilik Düzeyleri ve Psikolojik Etkileri

Toplanan ölçütlerin görünürlük (gizlilik) sınırları ve kullanım amacı çok hassas bir konudur:
- **Gizlilik Düzeyleri:**
  - **Bireysel düzeydeki ölçütler** (ör. bir programcının `Hata/KLOC` oranı) **kişiye özel** olmalı; yalnızca ilgili çalışan ve bir üst sorumlusu olan **takım yöneticisi** tarafından bilinmeli, diğer ekip arkadaşlarına ($A$ kişisinin verisi $B$ kişisine) kesinlikle açık olmamalıdır.
  - **Takım düzeyindeki ölçütler** ilgili takıma ve üst yönetime açık olmalıdır.
  - **Proje düzeyindeki ölçütler** kurum içindeki tüm çalışanlara açık, kurum dışına kapalı olmalıdır.
- **Tehdit veya Tek Başına Ödül Aracı Yapmama İlkesi:**
  - Takım lideri, `Hata/KLOC` değeri yüksek çıkan (ör. diğerlerinde `3–4` iken onda `10` çıkan) bir çalışanı *"Sen ne biçim yazılımcısın, izninden keserim"* diyerek **utandırmamalı veya tehdit etmemelidir**. Kök neden incelendiğinde belki de en deneyimli kişi olduğu için en zor modüller ona verilmektedir ya da geçici bir ailevi/taşınma sorunu yaşıyordur; iyi bir yönetici tehdit etmek yerine bu kök nedeni çözmeye yardımcı olur.
  - Madalyonun diğer yüzünde, ölçütleri doğrudan **"6 ay sonunda ölçütü en iyi çıkana 5 gün ek izin veya `%10` maaş ikramiyesi"** şeklinde ödül/prim mekanizmasına bağlamak da tehlikelidir; bu durumda çalışanlar müşterinin istediği ürünü zamanında çıkarmayı ikinci plana atıp yalnızca o spesifik metriği yüksek çıkartacak davranışlara yönelirler (*Goodhart Yasası*). Ölçütler amaç değil, araç olarak kullanılmalıdır.

### 3.3 Süreç Ölçütleri: Hata Giderme Etkinliği (HGE) ve GQM Yaklaşımı (Slayt 138)

Yazılım yaşam döngüsünde ilerledikçe (özellikle ürün müşteriye teslim edilip bakım aşamasına geçildikten sonra) hata düzeltme ve dağıtım maliyeti üstel olarak arttığı için, hataların ne kadarının teslimden önce yakalandığını ölçen **Hata Giderme Etkinliği ($\text{HGE}$ — *Defect Removal Efficiency*)** tanımlanır (ekrandan, 01:30:00):

$$\text{HGE} = \frac{\text{TÖ}}{\text{TÖ} + \text{TS}}$$

- **$\text{TÖ}$:** Ürünün müşteriye tesliminden **önce** bulunan hata sayısı.
- **$\text{TS}$:** Teslimden **sonra** (bakım aşamasında) bulunan hata sayısı (ekrandan, 01:30:00).
- Bu oran $1$'e (`%100`'e) ne kadar yakınsa sınama ve kalite güvence süreci o kadar başarılıdır.

**Fazlar Arası (Ardışıl Adımlar Arası) Hata Giderme Etkinliği:**
$\text{TÖ}$ ve $\text{TS}$ yerine yazılım geliştirme sürecinin ardışıl adımları olan $A(i)$ ve $A(i+1)$ de kullanılabilir (ekrandan, 01:30:00):

$$\text{HGE}_i = \frac{A(i)}{A(i) + A(i+1)}$$

- Örneğin 1. adım **Çözümleme (Analiz)** ve 2. adım **Tasarım** ise; $A(i)$ çözümleme aşamasında bulunan çözümleme hatası sayısı, $A(i+1)$ ise tasarım aşamasında fark edilen çözümleme kaynaklı hata sayısıdır (ekrandan, 01:30:00).
- Diğer süreç ölçütleri: **Doğruluk** (bulunan hata sayısının proje boyutuna [`LOC`/`FP`] oranı), **Bakım kolaylığı** (bir hatanın bulunması ile giderilmesi arasında geçen zaman) ve **Güvenlik** (bulunan güvenlik açıkları ve ciddilik düzeyleri) (ekrandan, 01:30:00).
- **Ölçek Orantılılığı ve GQM (*Goal–Question–Metric*) Yaklaşımı:** 3–4 kişilik küçük bir KOBİ'de veya 4–5 haftalık minik bir projede ağır süreç ölçümleri yapmak projeyi 7–8 haftaya uzatacağı için uygulanmaz. Hangi ölçütlerin seçileceğine karar vermek için **GQM (*Goal–Question–Metric*)** yaklaşımı kullanılır:
  1. **Goal (Hedef):** Projenin kalite öncelik ve hedeflerini belirle.
  2. **Question (Soru):** Bu hedefe doğru gidip gitmediğimizi anlamak için hangi soruları sormalıyız?
  3. **Metric (Ölçüt):** Bu sorulara yanıt verecek uygun metrikleri seç ve uygula.

## 4. Yazılım Proje Yönetiminde Maliyet Tahmin Yöntemleri

Gereksinim mühendisliği çalışmaları biter bitmez (daha analize yeni başlarken), projenin kaç adam-ay çaba ve kaç ay süre gerektireceğini tahmin etmek hayati önem taşır. Örneğin bir proje `240 adam-ay` çaba gerektiriyorsa ve elimizde yalnızca `3` yazılımcı varsa proje $240 / 3 = 80\text{ ay}$ (6,5 yıldan fazla) sürecektir; eğer pazar hedefimiz veya bir kamu ihalesinin şartnamesi çok daha kısa bir süre öngörüyorsa ve yeterli insan kaynağı ayıramıyorsak o projeye/ihaleye hiç girmeme kararı verebilmek için maliyet tahmini şarttır.

> **Ders sonrası not:** Hoca bu sayısal örneği sözlü anlatırken `240 adam-ay`lık işin 3 kişiyle $240 / 3 = 80\text{ ay}$ süreceğini doğru söyledikten sonra, *"hedefimiz 3 ay olacaksa 240'ı kaça böldüğümüzde 3 çıkar, ancak 8'e böldüğümüzde 3 çıkar, 8 kişi ayıramayacaksak..."* demiştir (01:39:25). $240 / 8 = 30\text{ ay}$ (veya 3 ayda bitirmek için $240 / 3 = 80\text{ kişi}$, ya da `24 adam-ay`lık bir işte $24 / 8\text{ kişi} = 3\text{ ay}$) olduğundan burada sözlü anlatımda bir basamak/bölme sürçmesi olmuştur.

Derste dört ana maliyet tahmin yöntemi incelenmiştir:

### 4.1 Bilirkişi Takdiri (Expert Judgment) ve Delphi Yöntemi (Slayt 142)

1. **Bilirkişi Takdiri:** Daha önce tamamlanmış ve gerçek maliyeti/süresi bilinen projelerle yeni projenin benzerliklerini, zorluk ve ölçek farklarını yüzde olarak karşılaştırarak deneyimli bir uzmanın tahminde bulunmasıdır. Tek bir uzmana dayandığında öznel (*subjektif*) kalma riski vardır.
2. **Delphi Yöntemi (Slayt 142) (ekrandan, 01:45:30):**
   - Birden fazla bilirkişinin farklı tahminlerini ortak bir noktada uzlaştırmak (*konsolide etmek*) için sosyal bilimlerdeki bir anket tekniğinin yazılım proje takdirine uyarlanmış hâlidir. Adımları şunlardır (ekrandan, 01:45:30):
     1. **Belgelerin Dağıtılması:** Koordinatör, bilirkişilere *"sistemi tanımlama"* belgelerini (tercihen gereksinim mühendisliği süzgecinden geçmiş gereksinim belgesini) ve birer *"tahmin formu"* verir.
     2. **Bağımsız Yazılı Tahmin:** Bilirkişiler birbirinden habersiz ve bağımsız olarak, nedenleri ile birlikte tahminlerini yazılı olarak koordinatöre bildirir (örneğin 4 bilirkişi sırasıyla `30`, `50`, `60` ve `90` adam-ay tahmin etmiş olsun; burada `50–60` ortanca değerler, `30` ve `90` ise iki uçtaki aykırı [*outlier*] tahminlerdir).
     3. **Geri Bildirim ve Yineleme:** Koordinatör ortanca ve aykırı tahmin sonuçlarını bilirkişilere vererek değerlendirmelerini gözden geçirip yeni tahminde bulunmalarını ister.
     4. **Yakınsama:** Ortak bir değere yaklaşıncaya kadar bu işlem yinelenir (ekrandan, 01:45:30).

### 4.2 Analiz Yöntemi (Aşağıdan Yukarıya / Bottom-Up ve Üç Noktalı Tahmin) (Slayt 144)

Analiz yönteminde, ortaya çıkması planlanan ürün veya işlem **Ürün Analiz Kartı** ve **Üretim Analiz Kartı** (proje yönetimi, geliştirme, sınama, servisler, garantiler vb.) kullanılarak hiyerarşik bir ağaç yapısında alt bileşenlerine ayrılır (ekrandan, 01:50:00):
- Ağacın en alt basamağındaki yaprak öğelerin giderleri, `LOC` / `FP` ve $(\text{kişi} \times \text{ay})$ ölçülerine dayanarak ilgili alanın uzmanları tarafından takdir edilir ve **aşağıdan yukarıya doğru toplamları** alınır (ekrandan, 01:50:00).
- Her yaprak düğüm için tekrarlı Delphi turları yapmak çok maliyetli olacağından, birden fazla tahmin tek adımda şu **ağırlıklı ortalama (PERT / üç noktalı tahmin)** formülüyle birleştirilir (ekrandan, 01:50:00):

$$E = \frac{a + 4m + b}{6}$$

- **$E$:** İlgili gider kalemi için beklenen çaba.
- **$a$:** En kötü (kötümser) tahmin.
- **$m$:** En olası (ortalama) tahmin *(4 katsayısıyla ağırlıklandırılır)*.
- **$b$:** En iyimser tahmin (ekrandan, 01:50:00).

### 4.3 İstatistiksel Modeller: Walston-Felix, COCOMO ve PNR Modelleri (Slayt 146, 148, 150)

İstatistiksel modeller, doğrudan ölçülemeyen maliyet/çaba/süre ($y$) değerini, tahmin edilen kod satırı sayısı ($\text{KLOC}$) veya işlev noktası ($\text{FP}$) gibi bağımsız değişkenlerin ($x$) üstel bir fonksiyonu olarak hesaplar:

$$y = f(x) = a \cdot x^b$$

Buradaki $a$ ve $b$ katsayıları, geçmişte tamamlanmış projelerin verileri üzerinde **en küçük kareler yöntemi (*least squares*)** gibi istatistiksel regresyon analizleri uygulanarak elde edilir.

#### 1. Walston-Felix Modeli (Slayt 146) (ekrandan, 02:10:00)

Walston ve Felix, büyüklükleri `4.000` ile `467.000` satır kod (`4–467 KLOC`) arasında değişen **`60` yazılım projesinin** sonuçlarına dayanarak şu dört istatistik fonksiyonunu kurmuştur (ekrandan, 02:10:00):
- **İş hacmi (ayda-kişi / adam-ay, $H$):**
  $$H = 5{,}2 \cdot \text{KLOC}^{0{,}91}$$
- **Proje süresi (ay, $T$):**
  $$T = 4{,}1 \cdot \text{KLOC}^{0{,}36} \qquad \text{veya iş hacmi üzerinden:} \qquad T = 2{,}47 \cdot H^{0{,}35}$$
- **İşgücü talebi (atanacak kişi sayısı, $I$ — en yakın tam sayıya yuvarlanır):**
  $$I = 0{,}54 \cdot H^{0{,}06}$$
- **Belge hacmi (sayfa sayısı, $B$):**
  $$B = 49 \cdot \text{KLOC}^{1{,}01}$$

#### 2. COCOMO (*Constructive Cost Model*) Modeli (Slayt 148) (ekrandan, 02:15:00)

Barry Boehm tarafından **`63` yazılım projesinin** sonuç değerlerine dayanarak ve Delphi yöntemi uygulanarak geliştirilen **COCOMO (*Constructive Cost Model*)**, ayrıntı düzeyine göre üç alt modele ayrılır: **1) Temel COCOMO**, **2) Orta COCOMO** ve **3) İleri COCOMO** (ekrandan, 02:15:00).

- **Temel COCOMO:** Bin kod satırına ($\text{KLOC}$) dayanarak iş hacmi ($H$, adam-ay) kestirilir ve $H$ serbest değişkeninden de proje süresi ($T$, ay) hesaplanır (ekrandan, 02:15:00):
  $$H = a \cdot \text{KLOC}^b, \qquad T = c \cdot H^d$$
  Boehm, ilk haftalarda işlenen **yazılım türlerine** göre değişen $a, b, c, d$ katsayılarını şu şekilde saptamıştır (ekrandan, 02:15:00):

| Yazılım Türü | İş Hacmi (Adam-Ay, $H$) Formülü | Proje Süresi (Ay, $T$) Formülü | Katsayıların Yorumu |
| :--- | :--- | :--- | :--- |
| **Uygulama Programı** (*Application / Organic*) | $H = 2{,}4 \cdot \text{KLOC}^{1{,}05}$ | $T = 2{,}5 \cdot H^{0{,}38}$ | $a$ ve $b$ en düşüktür; ancak gereksinimler daha sık değiştiği için süre üssü ($d = 0{,}38$) daha büyüktür. |
| **Yardımcı Programlar** (*Utility / Semi-detached*) | $H = 3{,}0 \cdot \text{KLOC}^{1{,}12}$ | $T = 2{,}5 \cdot H^{0{,}35}$ | Orta düzeyde karmaşıklık ve çaba katsayılarına sahiptir. |
| **Sistem Yazılımları** (*System / Embedded*) | $H = 3{,}6 \cdot \text{KLOC}^{1{,}20}$ | $T = 2{,}5 \cdot H^{0{,}32}$ | Donanım/sistem kısıtları nedeniyle kodlaması en zor gruptur ($a=3{,}6, b=1{,}20$ en yüksek); ancak gereksinimleri daha sabit olduğundan $d = 0{,}32$ daha küçüktür. |

- **Orta COCOMO:** Temel COCOMO formülüne, mevcut projenin geçmiş projelere göre zorluk/kolaylık durumunu yansıtan ve $0{,}90$ (`%10` azalış) ile $1{,}40$ (`%40` artış) arasında değer alan bir **Çaba Düzeltme Çarpanı (*EAF — Effort Adjustment Factor*)** ekler.
- **İleri COCOMO:** Yazılım geliştirme sürecinin her ayrı alt aşaması (analiz, tasarım, kodlama, sınama) için ayrı fonksiyonlar ve çarpanlar kullanır.

#### 3. PNR (*Putnam-Norden-Rayleigh*) Modeli (Slayt 150) (ekrandan, 02:20:00)

Putnam, Norden ve Rayleigh tarafından önerilen **PNR modelinde** yıllık iş hacmi ($H$, yılda işgücü / adam-yıl); bin kod satırı sayısı ($\text{KLOC}$), **teknoloji katsayısı ($C_k$)** ve **yıl olarak geliştirme süresine ($t$)** bağlı olarak şu formülle hesaplanır (ekrandan, 02:20:00):

$$H = \frac{\text{KLOC}^3}{C_k^3 \cdot t^4}$$

- **$C_k$ Teknoloji Katsayısı Değerleri (ekrandan, 02:20:00):**
  - Düşük teknoloji ortamında: **`2000`**
  - İyi (yüksek) teknoloji araçlarının kullanıldığı ortamda: **`8000`**
  - Uçtan uca otomatik ve tümleşik yazılım araçlarının kullanıldığı ortamda: **`12000`** (veya kurumun eski verilerine dayanarak en küçük kareler yöntemiyle kestirilen değer).
  - *Formülün Yorumu:* $C_k$ katsayısı paydada ($C_k^3$ olarak) yer aldığından, kullanılan yazılım geliştirme ortamı ne kadar gelişmiş ve tümleşikse (örneğin UML şemalarından koda ve koddan şemaya çift yönlü [*round-trip*] dönüşüm yapan, başarısız birim testlerini izlenebilirlik matrisi ve *Jira* üzerinden otomatik olarak ilgili yazılımcının iş listesine atayan *IBM Rational Application Developer* veya *Microsoft Team System / Team Foundation Server / Azure DevOps* gibi ekosistemler kullanıldığında) payda o kadar büyür ve gereken **iş hacmi ($H$) ciddi oranda azalır** (ekrandan, 02:20:00).
- **Zaman İçinde İşgücü Dağılımı (Rayleigh Eğrisi) (ekrandan, 02:20:00):** PNR modeli, işgücü ihtiyacının proje süreci basamaklarına ve sürecin başından bu yana geçen zamana ($t$) bağlı olduğunu kabul eder. Toplam işgücü yüzdesinin zamana göre grafiği çizildiğinde; proje başında sıfırdan hızla yükselen, ürünün müşteriye teslim edildiği (bakım aşamasına geçildiği) dikey çizgi civarında tepe noktasına ulaşıp toplam alanın yaklaşık `%50`'sini dolduran, bakım aşamasında ise yazılım emekli edilene kadar sağa doğru uzun bir kuyrukla azalan **Rayleigh dağılımı** elde edilir (ekrandan, 02:20:00).

## 5. İleri Yazılım Sınama Teknikleri ve Resmi Gözden Geçirme (IEEE 1028)

Dersin son bölümünde, 10. derste birim sınamaları (*unit testing*) için atlanan genel sınama süreci, sınama psikolojisi, tümleştirme/geçerleme/sistem sınamaları ve koda dayalı olmayan resmi gözden geçirme (*IEEE 1028*) konuları tamamlanmıştır.

### 5.1 Sınama Süreci Adımları ve Sınama Amaçlı Yapılanma (Slayt 162)

Sınama etkinlikleri yazılım yaşam döngüsünün her aşamasında yürütülür ve kendi içinde beş adımlı bir süreçtir: **1) Planlama** (toplam proje çabasının ne kadarının, ör. `%10`'unun sınamaya ayrılacağının ve hedef kod kapsama oranının, ör. yüksek riskli projede `%70` yerine `%80` *code coverage* hedefinin belirlenmesi), **2) Tasarım**, **3) Çalıştırma** (mümkün olduğunca otomatik araçlarla), **4) Bilgi toplama** ve **5) Değerlendirme** (*MTBF — Mean Time Between Failures* vb. ölçütlerle).

**Bir Kodu Kim Sınar? — Sınama Amaçlı Yapılanma (Slayt 162) (ekrandan, 02:35:00):**
1. **İlk Olarak Bileşeni Hazırlayan Programcı Sınar:** Bir programı ve iç çalışma ayrıntılarını (*white-box*) en iyi bilen kişi onu yazan programcıdır (ekrandan, 02:35:00).
2. **Her Bileşen Aynı Zamanda Yazarı Dışındaki Kişilerce Sınanır:**
   - Programcıların çıkarları, kendi yazdıkları programın hatasız, zamanında ve bütçe dâhilinde tamamlanmasını gerektirir; ayrıca insan ürettiği kodu bir sanat eseri gibi sahiplenir (*"kuzguna yavrusu şahin görünür"*).
   - **Psikolojik açıdan bakıldığında sınama "yıkıcı" (*destructive*) bir eylemdir** (*"bu kodda mutlaka bir hata var ve onu bulacağım"* bakış açısı gerektirir). Geliştiriciler kendi kodlarına yıkıcı yaklaşamazlar; hataları bulmaya değil, **kodun doğru çalıştığını ispatlamaya** yönelik sınamalara eğilim gösterirler (ekrandan, 02:35:00).
   - Bu nedenle yazılım evinin **bağımsız bir sınama ekibi (*ITG: Independent Test Group*)** bulunabilir; kaynaklar buna yetmiyorsa aynı projenin üyeleri karşılıklı *"al gülüm ver gülüm"* ($A \leftrightarrow B$) yapmadan, **dairesel rotasyonla** ($A$'nın kodunu $B$, $B$'ninkini $C$, $C$'ninkini $D$, $D$'ninkini $A$) birbirlerinin çalışmalarını sınar (ekrandan, 02:35:00).
3. **Teknik Olmayan Kişiler (Müşteriler / Son Kullanıcılar) Sınar:** *"Müşteriler hataları önünde sonunda bulacaklardır. İyisi mi siz onlardan önce davranın! Aksi hâlde prestijiniz sarsılacaktır"* (ekrandan, 02:35:00).

### 5.2 Tümleştirme, Geçerleme (Alfa / Beta) ve Sistem Sınamaları

1. **Tümleştirme Sınamaları (*Integration Testing*):** Bireysel olarak doğru çalışan sınıflar bir araya getirildiğinde, farklı programcıların tasarımdaki belirsiz noktaları farklı yorumlaması nedeniyle uyumsuzluklar çıkabilir. İki önemli alt türü vurgulanmıştır:
   - **Tahribat Sınaması (*Smoke Testing*):** Eski mühendislik disiplinlerinden gelen bu terim yazılımı veya donanımı kırmak/yakmak anlamına gelmez; tüm yazılım ve donanım bileşenleri ilk kez birleştirildiğinde tüm sistemin çalışmasını kilitleyen **kritik (*showstopper*) hataları** yakalamak için diğer tümleştirme sınamalarından önce yapılan temel bütüncül sınamadır. *(Örnek: Windows 95 lansmanında klavye ve farenin PS/2 portlarına ters takılması yüzünden sürücü hatasıyla projeksiyonda mavi ekran [BSOD] çıkması bir showstopper hatadır).*
   - **Gerileme Sınaması (*Regression Testing*):** Yazılıma yeni bir işlev eklendiğinde veya mevcut bir hata düzeltildiğinde, bu değişikliğin sistemin diğer kısımlarında beklenmedik yan etkiler doğurup doğurmadığını görmek için sınamaların (ör. birim testlerinin her akşam, tümleştirme testlerinin her cuma akşamı) tekrarlanmasıdır.
2. **Geçerleme Sınamaları (*Validation Tests* — Alfa ve Beta Sınamaları):** Doğrulama (*verification*) ve geçerleme (*validation*) birlikte kısaca **V&V sınamaları** olarak anılır. Geçerleme sınamaları kullanım senaryosu metinleri üzerinden **son kullanıcılar** tarafından yürütülür ve Yunan alfabesinin ilk iki harfiyle iki aşamaya ayrılır:

| Özellik | Alfa ($\alpha$) Sınaması | Beta ($\beta$) Sınaması |
| :--- | :--- | :--- |
| **Yürütüldüğü Mekân / Ortam** | **Yazılım evinde**, doğal kullanım ortamı yapay olarak **simüle edilerek** (ör. yazılım evinin bir odasına 3–4 raflı kitaplık, barkodlu kitaplar ve masa kurulup müşteri temsilcisi kütüphanecinin oturtulması). | **Müşterinin kendi mekânında ve gerçek kullanım ortamında** (mevcut sistem çalışırken sınırlı sayıda kullanıcı tarafından paralel/eşzamanlı yürütülerek). |
| **Hata Bildirimi ve İletişim Türü** | **Gayri resmi (*Informal*) iletişim:** Kullanıcı hatayla karşılaşır karşılaşmaz aynı ortamdaki geliştiricilere **anında ve sözlü** olarak bildirir; ekip hemen üzerinde çalışmaya başlar. | **Resmi (*Formal*) iletişim:** Geliştirici ekip ortamda yoktur; müşteri hataları **standart hata bildirim formu** (hatanın kısa tanımı, adım adım tekrarlama sırası, ekran görüntüleri, tarih/saat) doldurup e-posta ile belirli periyotlarda (ör. her pazartesi öğlene kadar) iletir. |

3. **Sistem Sınamaları (*System Testing*):** Yazılımın donanım ve diğer harici sistemlerle birlikte tüm yönleriyle incelendiği dört temel sınama türü:
   - **Kurtarma Sınaması (*Recovery Testing*):** Sistemin çalışmasını durduran bir hata oluştuğunda sistemin tekrar çalışır hâle getirilmesi için gereken ortalama süreyi (**$\text{MTTR}$ — *Mean Time to Repair***) ölçer.
   - **Güvenlik Sınaması (*Security Testing*):** Her şifreleme (*encryption*) önünde sonunda kırılabilir; önemli olan şifrelemenin kırılma süresinin işlemin geçerlilik süresinden uzun olmasıdır. *(Örnek: Banka EFT emrinin eliptik eğri [ECC] asimetrik şifrelemesiyle gönderilmesi durumunda, saldırganın şifreyi çözmesi 3–5 saat sürüyorsa ve EFT işlemi 30 dakika içinde tamamlanıp kapanıyorsa güvenlik sınaması başarılı kabul edilir).*
   - **Zorlama Sınaması (*Stress Testing*):** Kısa aralıklarla gelen aşırı yoğun kullanım talepleri altında sistemin nereye kadar dayandığını ve sınırlarını belirler.
   - **Başarım Sınaması (*Performance Testing*):** Özellikle gerçek zamanlı (*real-time*) uygulamalarda (ör. otomatik borsa alım-satım emrinin uçtan uca `0,5 saniye` içinde işlenmesi gereksinimi) işlemin öngörülen süre sınırları içinde tamamlanıp tamamlanmadığını sınar.

### 5.3 Resmi Yazılım Gözden Geçirme Çalışmaları (Formal Software Review — IEEE 1028) (Slayt 174)

Gereksinim belirleme, çözümleme ve tasarım aşamalarında henüz çalıştırılacak kaynak kod bulunmadığından uygulanabilecek tek sınama yöntemi **Yazılım Gözden Geçirme (*Software Review*)** tekniğidir. Koda dayalı sınamalara kıyasla çok daha az çabayla hata bulmayı sağlar. Gayri resmi gözden geçirmeye örnek olarak Çevik/XP süreçlerdeki **Eşli Programlama (*Pair Programming*)** verilebilir. **IEEE 1028 standardına göre Resmi Yazılım Gözden Geçirme (*Formal Technical/Software Review*)** ise 7 adımdan oluşur (ekrandan, 03:05:00):

1. **Değerlendirme başlangıcı:** Değerlendirme yöneticisi standart bir kontrol listesi (*checklist*) kullanarak verimli bir toplantı için gerekli ön koşulları sağlar (ekrandan, 03:05:00).
2. **Yönetimin hazırlanması:** Sorumlu yönetim gözden geçirme için gerekli kaynakları (ör. incelenecek *SRS* / analiz / tasarım belgesinin erişime açılması, toplantı salonunun ayarlanması) hazırlar ve toplantının standartlara uygun yürütülmesini sağlar (ekrandan, 03:05:00).
3. **Gözden geçirme prosedürlerine genel bakış:** Değerlendirme yöneticisi tüm değerlendiricilerin gözden geçirmenin amaçlarını ve IEEE 1028 prosedürlerini anladığından (hizmet içi eğitim aldığından) emin olur (ekrandan, 03:05:00).
4. **Bireysel hazırlık:** Değerlendiriciler birbirlerinden habersiz ve bağımsız olarak inceleme toplantısına hazırlanır; gözden geçirilecek malzemede (ör. *use case* metinleri, *use case* şemaları ve alan modeli arasında) hataya yol açabilecek olası bozuklukları (*anomaly*) arar ve not alır (ekrandan, 03:05:00).
5. **Grup incelemesi:** Bireysel hazırlıkların sonuçları önceden belirlenen yer ve zamandaki toplantıda bir araya getirilir; her bulgu tartışılır (gerçekten hata olup olmadığı netleştirilir) ve **sonuç raporu** üzerinde uzlaşıya varılır (ekrandan, 03:05:00).
6. **Düzenleme:** İncelenen çalışmanın yazar(lar)ı veya atanacak bir başka kişi/ekip, sonuç raporunda belirlenen hatalı noktaları düzeltir (ekrandan, 03:05:00).
7. **Sonlandırma:** Değerlendirme yöneticisi (gerekirse hatayı bulan değerlendiricinin de görüşünü alarak) yapılan düzeltmelerin yeterliliğini inceler; yeterli bulursa süreci sonlandırır, eksik bulursa tekrar düzenleme talep eder (ekrandan, 03:05:00).

## Örnek Sorular

### Soru 1: Süreç Ölçütleri — Hata Giderme Etkinliği ($\text{HGE}$) Hesabı (ekrandan, 01:30:00)

**Soru:** Bir yazılım projesinde ürün müşteriye teslim edilmeden önce yürütülen inceleme ve sınama etkinliklerinde toplam $\text{TÖ}$ adet hata, ürün müşteriye teslim edildikten sonra (bakım aşamasında) ise $\text{TS}$ adet hata bulunmuştur.
a) Projenin genel **Hata Giderme Etkinliği ($\text{HGE}$)** nasıl formüle edilir ve bu oranın yüksek çıkması ne anlama gelir?
b) Aynı ölçüt yazılım geliştirme sürecinin ardışıl iki adımı olan **Çözümleme ($A_1$)** ve **Tasarım ($A_2$)** aşamaları arasında nasıl tanımlanır?

**Çözüm (derste verilen):**
- **a)** Genel Hata Giderme Etkinliği formülü (ekrandan, 01:30:00):
  $$\text{HGE} = \frac{\text{TÖ}}{\text{TÖ} + \text{TS}}$$
  Teslimden sonra (bakım aşamasında) hata düzeltmenin ve müşterilere dağıtmanın maliyeti çok yüksek olduğundan, $\text{HGE}$ oranının $1$'e (`%100`'e) yakın olması hataların büyük çoğunluğunun ürün müşteriye gitmeden önce yakalandığını ve kalite güvence sürecinin etkin çalıştığını gösterir.
- **b)** Ardışıl iki aşama için $\text{HGE}_i = \dfrac{A(i)}{A(i) + A(i+1)}$ formülü kullanılır. Çözümleme aşaması için $A(1)$ çözümleme aşamasında yakalanan çözümleme hatası sayısı, $A(2)$ ise tasarım aşamasına sızıp tasarım sırasında fark edilen çözümleme kaynaklı hata sayısıdır; dolayısıyla $\text{HGE}_{\text{çözümleme}} = \dfrac{A(1)}{A(1) + A(2)}$ olur (ekrandan, 01:30:00).

### Soru 2: Maliyet Tahmin Yöntemleri — Analiz Yöntemi, COCOMO ve PNR Karşılaştırması (ekrandan, 01:50:00; 02:15:00; 02:20:00)

**Soru:**
a) Analiz yönteminde bir alt bileşen için en kötü tahmin $a$, en olası tahmin $m$ ve en iyimser tahmin $b$ olarak verilmişse beklenen çaba ($E$) hangi formülle hesaplanır?
b) Temel COCOMO modelinde **Uygulama programları** ($H = 2{,}4 \cdot \text{KLOC}^{1{,}05}, \; T = 2{,}5 \cdot H^{0{,}38}$) ile **Sistem yazılımları** ($H = 3{,}6 \cdot \text{KLOC}^{1{,}20}, \; T = 2{,}5 \cdot H^{0{,}32}$) karşılaştırıldığında, neden sistem yazılımlarının $a$ ve $b$ katsayıları daha büyükken uygulama programlarının süre üssü ($d = 0{,}38 > 0{,}32$) daha büyüktür?
c) PNR modelindeki $H = \dfrac{\text{KLOC}^3}{C_k^3 \cdot t^4}$ formülünde otomatik ve tümleşik yazılım geliştirme araçları kullanmanın ($C_k$ katsayısını `2000`'den `12000`'e çıkarmanın) iş hacmi ($H$) üzerindeki etkisi nedir?

**Çözüm (derste verilen):**
- **a)** En olası tahmine `4`, en kötü ve en iyimser tahminlere `1` ağırlık verilerek altıya bölünür: $E = \dfrac{a + 4m + b}{6}$ (ekrandan, 01:50:00).
- **b)** Sistem yazılımlarını kodlamak ve gerçeklemek teknik olarak çok daha zor olduğundan birim kod başına gereken iş hacmi katsayıları ($a = 3{,}6, \; b = 1{,}20$) uygulama programlarından ($a = 2{,}4, \; b = 1{,}05$) daha büyüktür. Buna karşılık sistem yazılımlarında gereksinimler oldukça sabitken, uygulama programlarında müşteri gereksinimleri süreç boyunca çok daha sık değiştiği için süre formülündeki üstel katsayı ($d = 0{,}38$) sistem yazılımlarındakinden ($d = 0{,}32$) daha büyüktür (ekrandan, 02:15:00).
- **c)** Teknoloji katsayısı $C_k$ formülün paydasında küpü alınarak ($C_k^3$) yer aldığı için, gelişmiş ve tümleşik yazılım geliştirme araçları kullanıldığında $C_k$ büyür, payda büyüdüğü için de aynı kod hacmini ($\text{KLOC}$) aynı sürede ($t$) üretmek için gereken **yıllık iş hacmi ($H$) önemli ölçüde azalır** (ekrandan, 02:20:00).

### Soru 3: Alfa ve Beta Sınamaları ile IEEE 1028 Resmi Gözden Geçirme Farkları (derste sözlü ve ekrandan, 02:50:00; 03:05:00)

**Soru:**
a) Son kullanıcılar tarafından yapılan geçerleme (*validation*) sınamalarından **Alfa sınaması** ile **Beta sınaması** arasındaki iki temel fark (ortam ve iletişim biçimi açısından) nedir?
b) IEEE 1028 standardına göre yürütülen **Resmi Yazılım Gözden Geçirme** sürecinde değerlendiriciler önce doğrudan grup toplantısında mı inceleme yaparlar, yoksa öncesinde bireysel bir aşama var mıdır? Neden?

**Çözüm (derste verilen):**
- **a)** **Ortam farkı:** Alfa sınaması **yazılım evinin kendi mekânında** doğal kullanım ortamı simüle edilerek yapılırken, Beta sınaması **müşterinin kendi gerçek çalışma ortamında** yapılır. **İletişim farkı:** Alfa sınamasında kullanıcı aynı ortamdaki yazılım ekibine hataları **gayri resmi (*informal*), sözlü ve anlık** olarak bildirirken; Beta sınamasında kullanıcılar hataları **resmi (*formal*) hata bildirim formları** ile yazılı ve zamanlanmış kurallar çerçevesinde yazılım ekibine iletir.
- **b)** Grup incelemesi toplantısından önce mutlaka **4. adım olan Bireysel hazırlık** aşaması yürütülür; değerlendiriciler birbirlerine danışmadan ve birbirlerinden etkilenmeden malzemeyi tek başlarına inceleyerek olası bozuklukları (*anomaly*) raporlarlar. Ardından **5. adım olan Grup incelemesi** toplantısında bir araya gelerek bulgularını tartışır ve hangi bulguların gerçek hata olduğu konusunda uzlaşıp sonuç raporunu oluştururlar (ekrandan, 03:05:00).

## Dersin Toparlaması

Bu derste yazılım mühendisliği müfredatının son teorik konuları olan **Yazılım Proje Yönetimi**, **Maliyet Tahmin Yöntemleri** ve **İleri Yazılım Sınama Teknikleri** tamamlanmıştır. Proje yönetiminde önem sırasının **Kişiler $\rightarrow$ Ürün $\rightarrow$ Süreç $\rightarrow$ Proje** olduğu, plan ayrıntısının vade ile ters orantılı tutulması gerektiği, **Kapalı, Rastgele, Açık ve Eşzamanlı** takım yapıları ile **resmi ve gayri resmi** haberleşme kanalları incelenmiştir. Ardından süreç ölçütlerinden **Hata Giderme Etkinliği ($\text{HGE}$)** ve **GQM** yaklaşımı; maliyet tahmin yöntemlerinden ise **Bilirkişi Takdiri**, **Delphi Yöntemi**, **Analiz Yöntemi** ($E = \frac{a+4m+b}{6}$) ve istatistiksel modeller olan **Walston-Felix**, **COCOMO** (*Temel, Orta, İleri*) ile **PNR** ($H = \frac{\text{KLOC}^3}{C_k^3 t^4}$) modelleri ayrıntılı olarak ele alınmıştır. Son bölümde sınamanın yıkıcı psikolojisi ve bağımsız sınama (*ITG* / rotasyon), **Tahribat (*Smoke*)** ve **Gerileme (*Regression*)** sınamaları, **Alfa ve Beta** geçerleme sınamaları, **Kurtarma ($\text{MTTR}$), Güvenlik, Zorlama ve Başarım** sistem sınamaları ile **IEEE 1028 Resmi Yazılım Gözden Geçirme** adımları işlenmiştir. Dönemin son haftasında (Ders 12) öğrenci proje sunumları gerçekleştirilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
