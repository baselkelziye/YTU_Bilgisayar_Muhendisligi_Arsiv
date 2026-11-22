# Ders 10 Genişletilmiş Notu: Test, Yeni Sisteme Geçiş, Bakım ve Spor Salonu Sistemi Örneği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kodlama aşamasının tekrarı
- 2. Tasarımdaki kodlama kavramı (girdi kodlaması)
- 3. Yazılım kalitesi ve test basamakları
- 4. Yeni sistemin kullanıma geçişi ve kullanıcı eğitimi
- 5. Geçiş yöntemleri
- 6. Yazılım bakımı
- 7. Örnek uygulama: Spor salonu sistemi, problem ve veri toplama
- 8. Yapısal yaklaşımla analiz: veri akış diyagramları, veri sözlüğü, ER diyagramı
- 9. Nesneye yönelik yaklaşımla analiz: use case diyagramı ve senaryo dokümanı
- 10. Sistem tasarımı: yapı diyagramı, sınıf diyagramı, ardışıl diyagram
- 11. Hangi yaklaşımda hangi diyagramlar
- Örnek Sorular

## 1. Kodlama Aşamasının Tekrarı

Ders, bilgi sistemi geliştirme sürecinin son halkalarını tamamlıyor: önceki derste anlatılan kodlama ve test aşaması kısaca hatırlatılıyor, ardından bakım ve yeni sisteme geçiş yolları anlatılıyor. Dersin ikinci yarısında da analiz ve tasarım aşamalarının bir örnek proje üzerinde baştan sona nasıl yürütüldüğü gösteriliyor.

Analiz ve tasarım (yapısal ya da nesneye yönelik yaklaşımla) tamamlandıktan sonra sıra kodlamaya gelir. Kodlamanın ayrıntısına bu derste girilmez, çünkü programlama derslerinde işlenmektedir. Kodlamaya geçmeden önce programlama dili ve kullanılacak platform uygun şekilde seçilmelidir. <!-- BELİRSİZ: altyazıda "UML diyagramın niteliği düzenli bir kodlama tekniğine ve kodlama biçimine bağlıdır" geçiyor; büyük olasılıkla "yazılımın niteliği" kastedildi. -->

Hocanın gösterdiği akış şeması kodlamadan kullanıma kadarki adımları özetler (ekrandan, 00:10:00):

```text
Sistem Gereksinimleri
   | Kabul
   v
Kodlama  ------------------->  Programlar
   | Kabul                ^
   v                      |
Denetim  -- Revizyon -----+   (denetimden geçmezse kodlamaya dönülür)
   | Kabul
   v
Test (* Modüller  * Genel  * Onaylama)  ---->  Test Planı ve İşlemleri
   |
   v
Sistem Kullanıma Hazır
```

Test başlamadan önce bir test planı hazırlanır ve test işlemleri bu plana göre yürütülür. Testlerden ve kullanıcı onayından geçen sistem kullanıma alınır; kullanıma alındıktan sonra da belli aralıklarla bakım (maintenance) yapılır.

Programlama dili şu etkenlere göre seçilir:

- genel uygulama alanı,
- algoritmanın karmaşıklığı,
- yazılımın kullanılacağı ortam,
- yazılımı hazırlayacakların seçilen dildeki bilgi düzeyi.

Kodun anlaşılır olması gerekir. Açıklama satırları ne fazla ne az, gerektiği kadar olmalıdır. Yazım düzeni okunabilirliği sağlamalıdır. Veri tabanı tabloları, program modülleri, değişkenler ve tablo kolonları anlamlı adlarla adlandırılmalı; kurumun bir adlandırma standardı varsa ona uyulmalıdır.

## 2. Tasarımdaki Kodlama Kavramı (Girdi Kodlaması)

Hoca burada katılımcılara bir soru yöneltti: program kodu yazmanın dışında, tasarım aşamasında bir "kodlama" kavramı daha geçmişti; bu neydi?

Bir öğrenci, kayıtlara öğrenci numarası ya da kimlik numarası gibi tekil (unique) bir kod verip onlara kolay erişmek olarak hatırladığını söyledi. Hoca bunun veri tabanı tasarımındaki birincil anahtar (primary key) kavramıyla karıştırıldığını belirtti: birincil anahtar, tablodaki bir satıra erişmek için kullanılan tekil anahtar alandır. Tasarımdaki kodlama ise başka bir şeydir.

Girdi kodlamasında, üzerinde ileride sınıflama ya da raporlama yapılacak bir alan sayısal ya da karakter olarak daha kolay erişilebilir hale getirilir:

- Öğrenim durumu birçok kayıtta geçer. "İlkokul", "ortaokul" diye yazı yazılırsa ya da kısaltma kullanılırsa herkes başka türlü yazabilir. Her değer bir sayıya ya da tek harfe karşılık getirilirse bütün ilkokul mezunu çalışanlar tek bir sorguyla listelenebilir.
- Hastalık kodları: hastanede diyabet hastalarını listelemek istiyorsak, tanı alanına "diyabet" yazmak yerine tanının kodunu yazmışsak hastaları çok daha kolay sınıflayabiliriz.
- Cinsiyet gibi alanlar da kodla tutulur. Ad, soyad gibi bilgiler ise doğrudan kendisiyle girilir.

Yani daha analizden başlayarak hangi bilginin doğrudan, hangisinin kodla girileceğine karar verilir. Kod kullanılmazsa yazılar uzun ya da kısa, farklı biçimlerde girilir ve eşleşme sağlanamaz.

Bir öğrenci, öğrenci numaralarının başındaki iki hanenin giriş yılını göstermesini örnek verdi; hoca bunu onayladı ve bölüm kodunu da ekledi. Bölüm kodu aynı zamanda veri tabanı tasarımında yabancı anahtar (foreign key) olur: bölümlerin açıklandığı tabloyla öğrencilerin tutulduğu tablo arasında ilişki (relation) kurar.

## 3. Yazılım Kalitesi ve Test Basamakları

### 3.1 Kaliteli yazılım

Slayttaki tanım (ekrandan, 00:15:00): kaliteli yazılım; önceden belirlenmiş olan işlevsel gereksinimlere, yazılım geliştirme standartlarına ve bir yazılımdan beklenen bütün özelliklere tamamen uygun bir yazılımdır.

Hocanın saydığı kalite faktörleri:

- Kullanıcı açısından: doğruluk (doğru çalışma), güvenilirlik (reliability), verimlilik, kullanışlılık, güvenlik.
- Geliştirme ve işletme açısından: hata bulma kolaylığı, kolay değişiklik yapılabilmesi, test edilebilirlik, taşınabilirlik (bir işletim sisteminden başka bir işletim sistemine), yeniden kullanılabilirlik (bir parçasının ya da bütününün başka yazılımlarda kullanılabilmesi).
- Bağlanabilirlik: hocaya göre burada "birlikte çalışabilirlik" (interoperability, başka sistemlerle çalışabilme) demek daha doğrudur.

### 3.2 Test basamakları

Slayt "Yazılım Sınama Basamakları" (ekrandan, 00:20:00): yazılımın sınanması ünite testi, bütünlük testi, sistem testi ve onaylama testi basamakları halinde gerçekleştirilir. Böylece sınama işlemi, yazılım geliştirmenin son basamağı olan kodlamadan geriye doğru yürütülür.

- **Birim (ünite) testi:** Programlama dilinde doğru kodlandı mı, algoritma doğru mu? Bu testi yapmak için modülün kodunun bulunması gerekir.
- **Bütünlük testi:** Modüller tek tek doğru çalışıyor; birleştirildiklerinde de doğru çalışıyorlar mı?
- **Sistem testi:** Sistemle ilişkiler nasıl, işletim sistemiyle uyumlu mu? Aynı anda kaç kullanıcı çalışabilir, gerçekten çalışıyor mu, veri tabanından nasıl okuma yapıyor?
- **Onaylama testi (kullanıcı testi):** Kullanıcı, sistem analizi sırasında sistemin ne yapmasını istediğini söylemişti. Bu testte "sistem gerçekten benim istediklerimi yapıyor mu?" sorusuna cevap verilir.

## 4. Yeni Sistemin Kullanıma Geçişi ve Kullanıcı Eğitimi

Bu haftanın asıl konusu yeni sistemin kullanıma geçişidir. Günümüzde bilgisayar hiç kullanılmayan bir yerde sıfırdan sistem kurmak nadirdir, çünkü hemen her alanda bilgisayar kullanılıyor. Genellikle var olan bir sistemde iyi gitmeyen şeyler vardır ve sistem yenilenir. Yeni sistemin başarısında iki şey rol oynar: sistemin nasıl hazırlandığı ve nasıl kullanıma geçirildiği.

Yeni sistem hazırlandığında önce kullanıcılara eğitim verilir. Eğitim farklı kategorilere ayrılır:

- **Sistemle ilgilenecekler (işleten ve düzenleyen):** İşletim sistemi ve program modüllerinin yapısı hakkında daha ayrıntılı bilgi verilir.
- **Uç kullanıcılar:** Sistemde gerçekleştirebilecekleri işlemler, hangi modülle ne yaptıkları ve menüler arasında nasıl geçiş yapacakları anlatılır.
- **Üst yönetim:** Sistem aracılığıyla hangi bilgileri alabilecekleri, hangi kısıtlamaların bulunduğu ve alttaki çalışanlardan bu sistemle neler isteyebilecekleri anlatılır.

Eğitimden sonra kurumda çalışanlar sistemi nasıl kullanacaklarını, ondan ne isteyebileceklerini ve nasıl çalıştıracaklarını öğrenmiş olur. Sonraki soru şudur: var olan sistemden veri kaybı ve iş kaybı olmadan yeni sisteme nasıl geçilir?

## 5. Geçiş Yöntemleri

Slaytlarda her yöntemin yanında, eski sistemden yeni sisteme geçişi zaman ekseninde gösteren küçük bir çizim vardır. Bu çizimler aşağıda metin olarak verilmiştir.

### 5.1 Doğrudan geçiş

Slayttaki tanım (ekrandan, 00:25:00): belirlenen bir tarihten itibaren eski sistem tamamen bırakılarak yeni sistem kullanılmaya başlanır. Oldukça riskli olan bu yöntemde ön hazırlıkların çok iyi yapılması gerekir; özellikle eğitimin ve veri tabanı dönüşümünün çok iyi hazırlanmış olması gerekir.

**Veri tabanı dönüşümü** nedir? Yeni sistem için yeni bir veri tabanı tasarlanmıştır. Ama eski, çalışmakta olan sistemde saklanmış ve güncel uygulamalarda kullanılan veriler vardır. Bu verileri kaybetmeden, yeni sistemin kullanacağı biçime dönüştürerek yeni veri tabanına aktarmaya veri tabanı dönüşümü denir.

Çizimde eski sistem ve yeni sistem dikey bir çizgiyle ayrılır: T anına kadar eski sistem, T anından sonra yeni sistem kullanılır.

```text
| Eski Sistem | Yeni Sistem |
              ^
              T anı
```

Bu geçiş bir anda, hazırlıksız yapılmaz. Yeni sistemin veri tabanı eski sistemin verileri dönüştürülerek önceden hazır hale getirilir, bütün kullanıcılar eğitimi almış olur. Kullanıcılar yeni sistemin nasıl kullanılacağını ve eski sistemden farklarını biliyorsa daha kolay uyum sağlar; veri tabanı ve uygulamalar hazırsa geçiş kolaylaşır. Hazırlık iyiyse doğrudan geçiş en temiz geçiştir: iki tarafta ayrı veri kullanılmaz, eskisinden beslenip hazırlanmış tek bir veri tabanı vardır. Hoca, hazırlıklar iyi yapılmış ve uygulamaya uygunsa doğrudan geçişin daha doğru olduğunu, ama geri dönüş gerektiğinde çok sıkıntılı olacağını söyledi.

### 5.2 Paralel geçiş

Slayttaki tanım (ekrandan, 00:30:00, slayt küçük resmi): eski sistemle yeni sistem belirlenen süre boyunca birlikte çalışır. Ancak her iki sistemde de verilerin birbirini tutmasını sağlamak için kullanıcıların gerçekleştirdikleri işlemi hem yeni hem de eski sistemde yapmaları gerekir. Eğitim, geçiş süreci sırasında da verilebilir.

Çizimde eski sistem kutusu ile yeni sistem kutusu zaman ekseninde üst üste biner: eski sistem kullanılırken yeni sistem de devreye alınır ve bir süre ikisi birlikte kullanılır.

```text
| Eski Sistem      |
          | Yeni Sistem      |
          <-- ortak süre -->
```

Zorlukları: bir süre her iki tarafa da bilgi işlenmesi zahmetlidir, veri tutarsızlığına dikkat etmek gerekir ve erişim açısından güçlükler çıkabilir. Teoride güzel görünse de uygulamada zorlukları vardır. Hocaya göre paralel geçiş son yıllarda daha fazla kullanılmaya başlanmıştır.

### 5.3 Dereceli geçiş

Slayttaki tanım (ekrandan, 00:30:00): yeni sistem belli işlevleriyle kullanılmaya başlanır. Zaman içinde yeni sistemin diğer işlevleri de aşamalı olarak aktarılarak sistem bütünleştirilir. Yeni sistem tüm fonksiyonlarıyla beraber kullanılmaya başlandığı andan itibaren ise eski sistem kullanımdan kaldırılır.

Yani yeni sistem bütün modülleri ve işlevleriyle değil, parça parça devreye sokulur; yeni sistem tamamen hazır olana kadar eski sistem de kullanımda tutulur. Kademelerin iyi seçilmesi ve birbirleriyle uyumunun sağlanması gerekir.

Çizimde eski sistemden yeni sisteme geçiş eğik bir çizgiyle gösterilir (ekrandan, 00:35:00): eski sistem yavaş yavaş bırakılır, yeni sistem onun yerini alır. Hoca, aslında bu çizginin üzerinde eski sistemin işlev işlev kaldırıldığını gösteren küçük kademeler (tırtıklar) olması gerektiğini, çizimde bunu gösteremediğini söyledi.

```text
 ________________________
 Eski Sistem  /  Yeni Sistem
 ____________/___________
```

> **Ders sonrası not:** Hoca dereceli geçişi anlatırken bir süre iki sistemin birlikte kullanılmasına "buna da paralel geçiş diyoruz" dedi. Dereceli geçişte de geçiş süresince iki sistem yan yana bulunur, ama her işlev yalnız bir sistemde yürür. Paralel geçişte ise aynı işlem iki sistemde birden yapılır. İki yöntem bu yüzden ayrı tutulur.

**Soru:** Eski sistemin bazı işlevleri yeni sisteme geçtiğinde, bu işlevler eski sistemden kaldırılıyor mu, yoksa orada çalışmaya devam ediyor mu? **Cevap:** Dereceli geçişte kaldırılıyor.

### 5.4 Prototip geçiş

Slayttaki tanım (ekrandan, 00:35:00, slayt küçük resmi): prototip geçişin dereceli geçişe göre daha organize bir yapısı vardır. Sistemin bir prototipi oluşturulup küçük bir bölüm için kullanıma geçirilir. Prototipin çalışmasından elde edilen sonuçlara göre sistem üzerinde gerekli düzenlemeler yapıldıktan sonra tamamen yeni sisteme geçilir.

Dereceli geçişten farkı: dereceli geçişte işlevler tek tek devreye alınır; prototip geçişte sistemin bütününün bir prototipi oluşturulur ve bir prototip alanı seçilir. Eski sistem bir süre prototiple birlikte çalışır. Prototipin yerini ve kullanıcılarını doğru seçmek önemlidir. Prototip üzerinde denemeler yapıldıktan sonra yeni sisteme geçilir.

Hocanın örneği: bir bankanın yeni uygulaması, önce bankanın yurt dışındaki küçük bir şubesinde ya da biriminde prototip olarak denenir, sonra asıl sisteme yüklenir.

Çizimde eski sistem ile yeni sistem arasındaki geçişte, eski sistemin son bölümünün altında bir "Prototip" kutusu bulunur:

```text
| Eski Sistem | Yeni Sistem |
|  Prototip  |
```

### 5.5 Dağıtılmış geçiş

Slayttaki tanım (ekrandan, 00:40:00, slayt küçük resmi): dağıtılmış geçişte kurumun her bölümünde aşamalı olarak tek tek geçiş söz konusudur. Sistemin belirli periyotlarla genel olarak değerlendirilmesi ve bakımının yapılması gerekir.

Kurumdaki bölümler ya da departmanlar tek tek yeni sisteme dahil edilir. Çizimde geçiş merdiven biçiminde kademelerle gösterilir (ekrandan, 00:40:00): her basamak bir bölümün yeni sisteme geçişidir.

```text
 ______________________________
 Eski Sistem    _|  Yeni Sistem
              _|
 ____________|_________________
```

## 6. Yazılım Bakımı

Geçiş tamamlandıktan, eğitim verildikten ve uygulama kullanıma alındıktan sonra, belli aralıklarla bakım (maintenance) yapılır. Donanımda bir arıza olduğunda bakım yapıldığı gibi yazılımda da çeşitli durumlarda bakım gerekir:

- Yazılımın geliştirildiği platformda, veri tabanında ya da geliştirme ortamında bir iyileştirme olmuş, yeni sürümler çıkmışsa, yazılım bunlarla iyileştirilebilir; yeni olanaklardan yararlanmak ve performansı artırmak için bakım yapılır.
- Hata çıkmışsa hatayı düzeltmek için bakım yapılır.
- Kullanıcıların işleyiş şekillerinde ya da sistemlerinde değişiklik olmuşsa, yazılımın bu değişikliğe uyarlanması istenebilir.

Bu bakım işleri kullanıma alındıktan bir süre sonra ortaya çıkar: örneğin altı ay sonra bir hata çıkabilir, bir yıl sonra iyileştirme yapılabilir ya da kurumdaki değişikliklere uyarlama istenebilir.

> **Ek bilgi (derste anlatılmadı):** Yazılım mühendisliği kaynaklarında bakım genellikle dört türe ayrılır: düzeltici (hata giderme), uyarlayıcı (ortam ya da iş değişikliğine uyum), mükemmelleştirici (performans ve yeni özellik) ve önleyici bakım. Hocanın saydığı üç durum ilk üç türe karşılık gelir.

## 7. Örnek Uygulama: Spor Salonu Sistemi, Problem ve Veri Toplama

Aradan sonra hoca, öğrencilerin dönem projelerine benzer bir örnek çalışma gösterdi. Örnekteki fizibilite çalışmasını iyi bir örnek olarak görmediği için onu atlayıp analiz ve tasarımdan devam etti. Örnek, aynı problemi hem yapısal hem nesneye yönelik yaklaşımla modelliyor.

### 7.1 Problemin tanımı

Hizmet vermekte olan bir spor salonu bir bilgi yönetim sistemi kurulmasını istiyor. Var olan sistemde müşteriler salona giderek bilgi alıyor ve kayıt oluyor, kayıtlar yönetim tarafından saklanıyor. Yeni sistemde kişiler online üye olabilecek, eğitmenleri ve dersleri görüntüleyebilecek, farklı spor çeşitlerindeki istedikleri sınıflara kaydolabilecek. Eğitmenler de bilgilerini güncelleyebilecek ve eğitmeni oldukları sınıfların durumunu görebilecek.

Slayttaki ücret kuralı (ekrandan, 00:55:00): her ay sabit bir üyelik ücreti alınmakta, bu ücret dahilinde süresiz olarak fitness salonundan faydalanılabilmektedir. Pilates, dans vb. derslerin olduğu sınıflara katılmak isteniyorsa ekstra ücret ödenmektedir. Grup derslerine katılabileceği gibi özel ders talebinde de bulunulabilir. Bu durumda ücretler grup ücretlerinden farklı olarak hesaplanmakta ve müşteriye belirtilmelidir.

Ayrıntılı incelemede kişilere göre işlemler:

- **Yönetim:** kişilerin üyelik başvurusunu onaylar, derslere ait sınıfları oluşturur, tarih-saat bilgileriyle eğitmenleri belirler, gerekirse bu bilgileri günceller.
- **Üyeler:** bilgilerini girerek üyelik işlemlerini yapar, sınıfların takvim ve eğitmen bilgilerini görüntüler, kontenjanı olan sınıflara kaydolur, isterse eğitmenlerden özel ders talep eder.
- **Eğitmenler:** sistemdeki bilgilerini günceller, ders verdikleri sınıfların katılımcı listelerini görüntüler.

### 7.2 Sistem analizi ve tasarımı adımları

Hoca adımları hatırlattı:

- **Olabilirlik (fizibilite) araştırması:** Böyle bir sistem teknik, ekonomik ve zaman açısından geliştirilebilir mi?
- **Gereksinim analizi (sistem analizi):** Müşteriyle yapılan görüşmeler sonucunda modelleme yapılır; tasarım aşamasının temelini oluşturur.
- **Sistem tasarımı:** Belirlenen gereksinimler doğrultusunda problem yapısal olarak netleştirilir ve gerçekleştirme aşamasına hazır hale getirilir; örneğin modüller ve iş akışı belirlenir.

Gereksinim analizinde ön inceleme ve fizibilite adımından elde edilen raporlar incelenir, sistemdeki kaynaklar gözden geçirilir, ayrıntılı görüşmeler sonucunda sistem ihtiyaçları belirlenip modelleme yapılır.

### 7.3 Veri toplama: anket

Bu aşamada veri toplama yöntemi olarak açık uçlu ve kapalı uçlu sorulardan oluşan anketler uygulanabilir. Örnek anketteki sorular (hocanın okuduğu biçimiyle):

- Soru 1: Var olan sistemde sorun yaşıyor musunuz? (Evet / Hayır)
- Soru 2: Online sisteme geçmek sorunları çözecek mi? (Evet / Hayır)
- Soru 3: Online sistemde ihtiyaç duyduğunuz modülleri işaretleyin. (seçenekli)
- Soru 4: Rakipleriniz tarafından kullanıldığını gördüğünüz sistemlerde hangi özellikler var?

<!-- BELİRSİZ: anket slaydının karesi alınmadı; Soru 3'ün seçenekleri okunamadı. -->

Hoca hangi soruların açık, hangilerinin kapalı uçlu olduğunu sordu (bkz. Örnek Sorular).

## 8. Yapısal Yaklaşımla Analiz

### 8.1 Veri akış diyagramları

Gereksinim analizindeki bir sonraki adım, elde edilen bilgiler doğrultusunda sistemdeki verilerin nasıl taşındığının modellenmesidir. Spor salonu sistemi için veri akış diyagramları Gane-Sarson notasyonuyla hazırlanmıştır (ekrandan, 01:00:00).

**Taslak (context, Level-0) diyagram:** Tek bir süreç olarak "Spor Salonu Sistemi" ve onunla ilişkide olan dış varlıklar gösterilir: üye, eğitmen, yönetim.

- Üye: spor salonuna üye olur, sınıf bilgilerini alır, istediği sınıfa kaydolur, ödeme yapar.
- Eğitmen: katılımcıları görür, bilgilerini günceller.
- Yönetim: üyelik taleplerini toplar ve onaylar, sınıf oluşturur, raporlama yapar.

**1. seviye diyagram:** Taslak diyagramdaki tek süreç alt işlemlerine açılır. Yedi işlem, dört veri deposu vardır (ekrandan, 01:05:00):

| İşlem | Gelen akış (kaynak → işlem) | Giden akış (işlem → hedef) |
|---|---|---|
| 1.0 Üye Olma | Kişisel Bilgiler (Üye); Üyelik Onayı (Yönetim) | Üye Bilgileri (D1 Üyeler) |
| 2.0 Sınıf Oluşturma | Sınıf Bilgileri (Yönetim) | Sınıf Bilgileri (D2 Sınıf Bilgileri) |
| 3.0 Ödeme Yapma | Ücret (Üye); Ödenecek Tutar (D3 Ücretler) | Ödenen Tutar (D3 Ücretler) |
| 4.0 Sınıf Bilgileri Görüntüleme | Sınıf Seçimi (Üye); Sınıf Bilgisi (D2) | |
| 5.0 Sınıfa Kaydolma | Sınıf Seçimi (Üye) | Üye Bilgisi (D2 Sınıf Bilgileri) |
| 6.0 Katılımcıları Görüntüleme | Katılımcılar (D2) | Katılımcı Listesi (Eğitmen) |
| 7.0 Bilgilerini Güncelleme | Bilgiler (Eğitmen) | Eğitmen Bilgisi (D4 Eğitmenler) |

Semboller: dış varlıklar (üye, eğitmen, yönetim) dikdörtgenle; işlemler 1.0, 2.0, 3.0 gibi numaralı kutularla; veri saklama ortamları D1, D2, D3, D4 diye numaralı açık uçlu kutularla gösterilir. Varlıklarla işlemler arasındaki oklar geçen veriyi gösterir.

> **Hocanın vurgusu:** Veri akış diyagramı kurallarına uyulmalıdır:
> - Varlıktan varlığa doğrudan akış olmaz, arada bir işlem olmalıdır.
> - İşlemden işleme akış olabilir.
> - Varlıktan veri saklama ortamına (dosyaya) doğrudan akış olmaz, arada bir işlem olmalıdır.

**2. seviye diyagram:** 1. seviyedeki bir işlemin alt işlemlerini ve ilişkili varlıkları gösterir. Örnekte 3.0 Ödeme Yapma açılmıştır: önce üyenin ücreti hesaplanır, sonra ödeme alınır, ardından kalan borç hesaplanır. Bu alt işlemler Üye varlığıyla ve Ücretler veri deposuyla ilişkilidir. <!-- BELİRSİZ: 2. seviye diyagramın karesi alınmadı; alt işlem numaraları ve akış adları okunamadı. -->

### 8.2 Veri sözlüğü

Veri sözlüğü, veri akış diyagramında geçen her elemanın (veri akışı, veri saklama ortamı vb.) adının, tanımının, miktarının (buraya ne kadar giriş yapıldığının) açıklandığı yapıdır. Böylece diyagramdaki her eleman ayrıca tanımlanmış olur. Örnekte bir veri akışı ve bir veri deposu için tablolar vardır (ekrandan, 01:10:00, slayt küçük resimleri). <!-- BELİRSİZ: veri sözlüğü tablolarının içeriği karede okunamadı. -->

### 8.3 Varlık-ilişki (ER) diyagramı

Analiz sırasında veri nesneleri arasındaki ilişkiler de gösterilir; bu, veri tabanı analizidir. Chen notasyonunda varlıklar dikdörtgen, varlıkların nitelikleri elips, varlıklar arası ilişkiler eşkenar dörtgenle gösterilir. Hoca, derste kullanılan diğer kitapta eşkenar dörtgen çizmeden, ilişkinin zorunlu ya da seçimlik oluşuna göre gösterimin de anlatıldığını hatırlattı.

Spor salonu ER diyagramı (ekrandan, 01:10:00):

| Varlık | Nitelikler |
|---|---|
| Üye | Yaş, Ad Soyad, Boy-Kilo, İletişim Bilgisi |
| Sınıf | İsim, Kapasite, Yer, Tarih-Saat |
| Eğitmen | Ad Soyad, Yaş, Branş |
| Muhasebe | Ödenen Tutar, Borç |
| Yönetim | (nitelik gösterilmemiş) |

| İlişki | Bağladığı varlıklar |
|---|---|
| Kaydol | Üye – Sınıf |
| Ders Ver | Eğitmen – Sınıf |
| Sınıf Oluştur | Yönetim – Sınıf |
| Ödeme Yap | Üye – Muhasebe |
| Raporla | Muhasebe – Yönetim |

Okunuşu: üyeler sınıflara kaydolur, eğitmenler sınıflara ders verir, yönetim sınıfları oluşturur, muhasebe yönetime raporlar, üyeler muhasebeye ödeme yapar. Hoca ilişki adlarının "kaydolur, ders verir, oluşturur, ödeme yapar" gibi zaman ekiyle yazılmasının daha doğru olabileceğini söyledi.

Veri tabanı analizi (ER) ve iş analizi (veri akış diyagramları) birlikte, bu uygulama için yapısal yaklaşımla yapılmış sistem analizidir. Yapısal yaklaşımı seçen bir projede analiz sırasında bunların yapılması gerekir.

## 9. Nesneye Yönelik Yaklaşımla Analiz

### 9.1 Use case diyagramı

Nesneye yönelik yaklaşımda analizde use case (kullanım senaryosu) diyagramı çizilir. Sistemin aktörleri üye, eğitmen ve yönetimdir; senaryolar elips şeklinde gösterilir. <!-- BELİRSİZ: use case diyagramının karesi alınmadı; aşağıdaki liste anlatımdan kuruldu. -->

- Üye: üye olur; sınıfa kaydolur; ödeme yapar.
  - Sınıfa kaydolma, sınıf bilgisini görüntülemeyi de içerdiği için aralarında `include` ilişkisi vardır.
  - Sınıfa kaydolurken isteyen üye özel ders talebinde de bulunabilir; bu senaryo `extend` ile genişletilir.
- Yönetim: sınıf oluşturur.
- Eğitmen: katılımcıları görür, kendi bilgilerini günceller.

Hoca, kullanım senaryolarıyla işlerin kademe kademe belirlendiğine dikkat çekti.

### 9.2 Kullanım senaryosu dokümanı

Diyagram çizildikten sonra her senaryo için bir dokümantasyon yazılır. Örnekte ödeme senaryosu anlatıldı:

| Alan | İçerik |
|---|---|
| Senaryo | Ödeme |
| Birincil aktör | Üye |
| İlgililer ve beklentileri | Üyeler: sisteme doğru parayı ödemek istiyor |
| Ön koşul | Kişi üye olmalı ve sisteme online erişebilmiş olmalı |
| Son koşul | Ödeme bilgileri doğrulanmış olmalı |
| Ana akış | 1. Üye ödenecek toplam tutarı görüntüler. 2. Ödenecek tutar için kredi kartı ve fatura bilgilerini girer. 3. Üyenin onayıyla ödeme gerçekleşir. |
| Alternatif akış | Üyenin verdiği bilgilerde yanlışlık varsa sistem hata mesajı verir ve bilgilerin yeniden girilmesini ister. |

## 10. Sistem Tasarımı

### 10.1 Yapısal yaklaşım: yapı diyagramı

Yapısal yaklaşımda sistem mimarisini ortaya koymak için programdaki yapısal öğeler arasındaki ilişkiler yapı diyagramlarıyla hiyerarşik olarak gösterilir; ana modüle bağlı alt modüller belirlenir.

Spor salonu yapı diyagramı (ekrandan, 01:15:00):

```text
Spor Salonu (ana modül)
|-- Üye Olma            veri: Üyelik Bilgileri   kontrol: Üyelik Onayı
|-- Üye Girişi Yapma    veri: Kullanıcı Bilgileri kontrol: Doğrulama
|   `-- Sınıf Bilgileri Görüntüleme   veri: Sınıf Seçimi
|        `--> Sınıfa Kaydol            veri: Sınıf Seçimi
|              <seçim>
|              |-- Grup Dersine Katıl
|              `-- Özel Ders Al
`-- Sınıf Oluşturma     veri: Sınıf Bilgileri
```

Gösterim kuralları:

- Ucu içi dolu daire olan oklar kontrol akışını (bayrak) gösterir: örnekte üyelik onayı ve doğrulama.
- Ucu içi boş daire olan oklar veri akışını gösterir: üyelik bilgileri, kullanıcı bilgileri, sınıf seçimi, sınıf bilgileri.
- Eşkenar dörtgen koşulu (IF) gösterir: "Sınıfa Kaydol" modülünde üye isterse grup dersine katılır, ek olarak özel ders isterse özel derse katılır.
- Örnekte döngü yoktur. Bir işlem birçok kişi için tekrarlanacak olsaydı yarım daire biçiminde döngü oku çizilirdi.

### 10.2 Nesneye yönelik yaklaşım: sınıf diyagramı

Slayttaki açıklama (ekrandan, 01:25:00): nesne tabanlı yaklaşımın benimsendiği proje için sistem tasarımı adımında çizilen sınıf diyagramları ile sistemdeki sınıflar ve sahip oldukları özellikler ile metotlar ayrıntılı olarak belirtilir. Ardışıl diyagram adı verilen sequence diyagramlar ile de nesneler arası iletişim modellenir; metot çağrılarının ve içerisinde gerçekleşen işlemlerin ayrıntılandırılması amaçlanır.

Sınıf diyagramında bütün sınıflar ve aralarındaki ilişkiler gösterilir: üye için hangi bilgilerin tutulacağı, üyelik işlemleri için hangi metotların çalışacağı; üyenin bir sınıfa kaydolması; sınıf için hangi ders ve hangi eğitmen bilgisinin alınacağı; spor salonu yönetimi ve eğitmenin bu sınıfları değerlendirmesi. Aerobik, dans, pilates gibi dersler "Ders" sınıfı altında genellenir: Ders üst sınıfında ad ve saat ücreti gibi özellikler ile saat ücretini getiren metot bulunur; aerobik, dans, pilates bunun alt sınıflarıdır. <!-- BELİRSİZ: sınıf diyagramının karesi alınmadı; sınıf adları, nitelikler ve metotlar ayrıntılı okunamadı. -->

### 10.3 Ardışıl (sequence) diyagram

Slayttaki açıklama ve diyagram (ekrandan, 01:20:00): sistemdeki bir üyenin üye olma, sınıfa kaydolma ve ücret görüntüleme işlemlerinde hangi metot çağrılarının ne şekilde gerçekleştirildiğine dair bir ardışıl diyagram örneği.

Nesneler (soldan sağa): `üye:Üye`, `:SporSalonu`, `sınıf:Sınıf`, `ders:Ders`.

| Sıra | Gönderen → Alıcı | Mesaj | Tür |
|---|---|---|---|
| 1 | üye → SporSalonu | `üyeOl(üye)` | çağrı |
| 2 | SporSalonu → üye | `onay` | dönüş |
| 3 | üye → sınıf | `getSınıfBilgisi()` | çağrı |
| 4 | sınıf → üye | `sınıfBilgileri` | dönüş |
| 5 | üye → sınıf | `Kaydol(üye)` | çağrı |
| 6 | üye → SporSalonu | `borcOgren` | çağrı |
| 7 | SporSalonu → sınıf | `getOdenecekTutar` | çağrı |
| 8 | sınıf → ders | `getSaatUcreti` | çağrı |
| 9 | ders → sınıf | `saatUcreti` | dönüş |
| 10 | sınıf → sınıf | `getKatılımSüresi` | kendine çağrı |
| 11 | sınıf → SporSalonu | `saatUcreti*katılımSüresi` | dönüş |
| 12 | SporSalonu → üye | `borc` | dönüş |

Borç, dersin saat ücreti ile üyenin katılım süresinin çarpımı olarak hesaplanır ve çağrı zinciri boyunca üyeye geri döner.

Hoca ardışıl diyagramın özelliğini sordu. Etkileşim diyagramıdır, sistemin elemanları (sınıfların nesneleri) arasındaki etkileşimi gösterir. Asıl özelliği, nesnelerin uygulama çalıştığında devreye girme ve birbirini çağırma sırasına göre soldan sağa dizilmesi ve mesajların iş sırasına göre yukarıdan aşağı akmasıdır; bu yüzden "ardışıl" (sequence) diyagram denir (bkz. Örnek Sorular).

## 11. Hangi Yaklaşımda Hangi Diyagramlar

Örnekte aynı problem iki yaklaşımla birden modellendi. Amaç, hangi yaklaşımda hangi diyagramların kullanıldığını ve bunların karmaşık düşünmeden, basit tutularak nasıl doğru geliştirileceğini göstermekti.

| Aşama | Yapısal yaklaşım | Nesneye yönelik yaklaşım |
|---|---|---|
| Analiz | Veri akış diyagramları (taslak, 1. düzey, 2. düzey ayrıntılı), veri sözlüğü, ER diyagramı | Use case diyagramı ve kullanım senaryosu dokümanı |
| Tasarım | Yapı diyagramı, veri tabanı tasarımı için ER diyagramı | Sınıf diyagramı, ardışıl (sequence) diyagram |

**Soru:** Nesneye yönelik yaklaşımda yapılması gereken diyagramlar UML sınıf diyagramı, UML sequence diyagramı ve bir de ER diyagramı mı? **Cevap:** ER diyagramı, veri tabanına gerçeklerken dönüşümü göstermek amacıyla eklenebilir, iyi olur. Yapısal yaklaşımda ise ER diyagramı veri tabanı tasarımı için ayrıntılı gösterilir; analizde veri akış diyagramları bir paket halinde (taslak, birinci düzey, ikinci düzey) çizilir, tasarımda yapı diyagramı çizilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:11:46): Program kodunun yazılmasından başka, tasarım aşamasında bir "kodlama" kavramı daha geçti. Bu nedir?

> **Çözüm (derste verildi):** Girdi kodlamasıdır. Üzerinde sınıflama ya da raporlama yapılacak alanların değerleri (öğrenim durumu, cinsiyet, hastalık tanısı, bölüm) serbest metin yerine sayı ya da harf koduyla tutulur. Böylece herkesin farklı yazması önlenir, eşleşme ve listeleme kolaylaşır. Satıra erişim için kullanılan tekil anahtar (birincil anahtar) bundan farklı bir kavramdır.

**Soru 2** (ekranda gösterildi, derste sözlü, 00:58:46): Aşağıdaki anket sorularından hangileri açık uçlu, hangileri kapalı uçludur?

- 1. Var olan sistemde sorun yaşıyor musunuz? (Evet / Hayır)
- 2. Online sisteme geçmek sorunları çözecek mi? (Evet / Hayır)
- 3. Online sistemde ihtiyaç duyduğunuz modülleri işaretleyin.
- 4. Rakipleriniz tarafından kullanıldığını gördüğünüz sistemlerde hangi özellikler var?

> **Çözüm (derste verildi):** 4. soru açık uçludur; kişi kendi yorumunu yazabilir. 1, 2 ve 3. sorular kapalı uçludur; kişi verilen cevaplardan birini (ya da işaretlenecek seçenekleri) seçer.

**Soru 3** (derste sözlü, 01:18:13): Ardışıl (sequence) diyagramın özelliği nedir? Şekle bakarak, sınıflar (nesneler) nasıl dizilmiştir?

> **Çözüm (derste verildi):** Ardışıl diyagram bir etkileşim diyagramıdır; nesneler arası mesajları gösterir. Nesneler, uygulama çalışmaya başladığında devreye girme ve birbirini çağırma sırasına göre soldan sağa dizilir; mesajlar da iş sırasına göre yukarıdan aşağı zaman sırasıyla akar. Kimin kimi hangi sırayla çağırdığı ve dönüş değerleri görülür. Bu iş sırası temelli dizilim nedeniyle "ardışıl" diye adlandırılır.

**Soru 4** (derste sözlü, 00:32:21): Dereceli geçişte eski sistemin bazı işlevleri yeni sisteme geçtiğinde, bu işlevler eski sistemden kaldırılır mı?

> **Çözüm (derste verildi):** Evet, dereceli geçişte yeni sisteme aktarılan işlevler eski sistemden kaldırılır; yeni sistem tüm işlevleriyle çalışınca eski sistem tamamen kullanımdan kalkar.

## Dersin Toparlaması

Bu derste bilgi sistemi geliştirme sürecinin son aşamaları tamamlandı. Kodlamadan sonra test planına göre birim, bütünlük, sistem ve onaylama testleri yapılır; kalite, gereksinimlere ve standartlara uygunlukla ölçülür. Test edilen sistem kullanıcı gruplarına göre ayrı eğitim verildikten sonra doğrudan, paralel, dereceli, prototip ya da dağıtılmış geçiş yöntemlerinden biriyle kullanıma alınır. Doğrudan geçiş en temiz ama en riskli, paralel geçiş en güvenli ama en zahmetli yöntemdir; dereceli, prototip ve dağıtılmış geçiş işlev, prototip ya da bölüm bazında kademelendirme yapar. Kullanımdan sonra hata, yeni sürüm ve iş değişikliği nedeniyle bakım yapılır. Tasarım aşamasındaki girdi kodlaması da program kodlamasından ayrı bir kavram olarak hatırlatıldı.

Spor salonu örneği, dönem boyunca anlatılan analiz ve tasarım araçlarının tek bir problem üzerinde nasıl birleştiğini gösterdi: anketle veri toplama; yapısal yaklaşımda veri akış diyagramları, veri sözlüğü, ER diyagramı ve yapı diyagramı; nesneye yönelik yaklaşımda use case diyagramı ve senaryo dokümanı, sınıf diyagramı ve ardışıl diyagram. Bir projede yaklaşım seçildikten sonra o yaklaşımın diyagram takımı tutarlı ve sade biçimde kullanılmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
