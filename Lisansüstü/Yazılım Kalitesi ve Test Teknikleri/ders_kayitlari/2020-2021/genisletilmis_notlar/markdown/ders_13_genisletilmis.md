# Ders 13 Genişletilmiş Notu: Regresyon Testinde Önceliklendirme ve Uygulama Test Projeleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Makale Sunumu: Regresyon Testi ve Test Stratejileri
- 2. Karınca Kolonisi Optimizasyonu ile Test Senaryosu Önceliklendirme
- 3. Uygulama Sunumu 1: Seyahat Acentesi Masaüstü Uygulamasının Testi
- 4. Uygulama Sunumu 2: Envanter Yönetim Sisteminde PHPUnit ile Birim Testi
- 5. Uygulama Sunumu 3: PHP Web Uygulamalarında Birim ve Sistem Testi
- 6. Test Raporlarında Farklı Yaklaşımlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Makale Sunumu: Regresyon Testi ve Test Stratejileri

Bu ders, dönem sonu öğrenci sunumlarına ayrılmıştır. Önce son makale sunumu yapılır, sonra öğrencilerin bir yazılım üzerinde yürüttükleri test uygulama projeleri sunulur. Makalenin konusu, test senaryolarının önceliklendirilmesiyle optimize edilen regresyon testidir. Hoca, aynı konunun bir hafta önce başka bir sunumda da işlendiğini, bu makalenin ise önceliklendirme içindeki bir optimizasyon katkısına odaklandığını belirtir. Hocaya göre test önceliklendirme üzerine yapılan çalışmalar son yıllarda artmıştır.

### 1.1 Regresyon testi nedir, ne zaman yapılır?

Regresyon testi, uygulamada yapılan değişikliklerin sistemin geneline ya da modüllerine bir etkisi olup olmadığını tespit etmek için yapılır. Uygulamaya yeni bir özellik eklendiğinde, mevcut bir özellik geliştirildiğinde ya da konfigürasyonda değişiklik yapıldığında uygulama ya baştan sona ya da değişiklikten etkilenen bölümleri üzerinden yeniden test edilir. İki şey kontrol edilir: uygulama eski özelliklerini hâlâ koruyor mu, yeni özellikler düzgün çalışıyor mu?

Burada iki temel yol vardır. Ya önceden yazılmış ve yeni yazılmış bütün test senaryoları baştan sona koşturulur ya da aralarından seçim yapılır. Seçim yapmanın artıları ve eksileri vardır. Test kümesinden hangi senaryoların çıkarıldığı kod kapsamını etkileyebilir; senaryoların koşturulma sırasının değiştirilmesi de regresyon testinin etkinliğini değiştirir.

### 1.2 Regresyon test stratejileri

Sunumdaki şema (ekrandan, 00:05:00) stratejileri şu hiyerarşiyle gösterir:

```text
Strategy
├── Retest All
└── Selective Retest
    ├── Test Case Selection
    ├── Test Suite Minimization
    └── Test Case Prioritization
```

Bütün test senaryolarını yeniden koşturmanın (Retest All) neden her zaman mantıklı olmadığı şöyle açıklanır: uygulamada çok sayıda özellik ve çok sayıda test senaryosu varsa hepsini yeniden çalıştırmak çok zaman alır. Eski senaryolar için yazılmış testler geçerliliğini yitirmiş olabilir. Değişmeyen modüller için çalışan testler de zaman kaybına yol açar. Bu yüzden seçerek yeniden test (Selective Retest) yapmak mantıklıdır. Makalenin konusu bu dalın üçüncü kolu olan test senaryosu önceliklendirmedir.

### 1.3 Test senaryosu seçme teknikleri

Eldeki araçlarla değişiklikleri otomatik tespit edip buna göre senaryo seçmek isteniyorsa şu yaklaşımlar kullanılır:

- **Kontrol akışı tabanlı (control-flow based):** uygulamanın kontrol akışı üzerinde değişen yollar bulunur.
- **Metinsel fark tabanlı (textual difference based):** kodda statik olarak, metin düzeyinde neyin değiştiği tespit edilir ve bu değişikliklere karşılık gelen test senaryoları seçilir.
- **Kod varlığı tabanlı (code entity based):** benzer şekilde değişikliğin hangi sınıf ve fonksiyonlarda olduğuna bakılır.
- **Dilimleme tabanlı (slicing based):** dilimleme algoritmalarıyla kodun belirli bölümleri alınır, bu bölümlere yine kontrol akışı, metinsel ya da kod varlığı tabanlı seçim uygulanır.
- **Önceliklendirme tabanlı seçim.**

Böyle bir araç yoksa seçim sezgisel olarak yapılır:

- En çok hata (defect) yakalayan senaryoları seçmek.
- Son kullanıcının göreceği ekranları seçmek; örneğin müşteriye yapılacak bir gösterimde müşterinin deneyeceği ve hata çıkabilecek ekranlar.
- Entegrasyon testinde kullanılan bütün senaryoları seçmek. Sistemin bütünleşmesi önemli olduğu için burada kısıtlamaya gidilmez.
- Kritik ve etkisi yüksek modülleri seçmek.

### 1.4 Test senaryosu önceliklendirmenin faydaları

Sunuma göre önceliklendirme:

- hata tespit oranının artmasını sağlar,
- yüksek riskli hataların test döngüsünün erken bir aşamasında yakalanmasını sağlar,
- teste dahil edilmesi gereken test kapsamının daha hızlı belirlenmesine katkı verir.

## 2. Karınca Kolonisi Optimizasyonu ile Test Senaryosu Önceliklendirme

### 2.1 Benzetme

Makalede önerilen yaklaşım karınca kolonisi optimizasyonudur (Ant Colony Optimization, ACO). Benzetme şöyledir: karıncalar yuvadan yiyeceğe giderken rastgele yollar izler. Hangi yol daha çok kullanılıyorsa o yolda karıncaların salgıladığı feromon miktarı daha yüksek olur. Dönüş yolunda da kısa yolda daha çok feromon biriktiği için karıncalar dönüşte kısa yolu daha çok kullanır.

Test tarafındaki karşılığı şudur: test senaryoları hata kapsamına göre kombinasyonlar halinde denenir. Hangi senaryo kombinasyonlarda daha sık birlikte kullanılıyorsa onun feromon değeri yükselir ve seçimde öne çıkar.

### 2.2 Önceliklendirme kriterleri

Seçimde yalnız feromon benzetmesi kullanılmaz. Sunumda belirtilen kriterler şunlardır:

- Test senaryosunun kapsadığı hata (bug) sayısı.
- Test senaryosunun çalışma süresi (execution time).
- Senaryonun diğer senaryolarla birlikte kullanılma oranı.
- Bütün koşullar ve farklı senaryo kombinasyonları arasında en çok kullanılan senaryoların belirlenmesi, yani feromon değeri. Sunucuya göre makalenin asıl ek katkısı bu son kriterdir.

### 2.3 Algoritmanın döngüsü

Test senaryoları algoritmaya girdi olarak verilir. Ekrandaki döngü (ekrandan, 00:10:00) şu adımlardan oluşur:

```text
1. Select a test case covers maximum faults.
   (En çok hatayı kapsayan test senaryosunu seç.)
2. Check if all faults are covered.
   (Bütün hatalar kapsandı mı kontrol et.)
3. If not covered, then select other test case to cover remaining.
   (Kapsanmadıysa kalan hataları kapsayacak başka senaryo seç.)
4. Calculate total covered faults.
   (Toplam kapsanan hata sayısını hesapla.)
   -> Bütün hatalar kapsandıysa: Terminate Algorithm
5. Explore all the paths in each iteration.
   (Her iterasyonda bütün yolları keşfet.)
6. Calculate average execution time of test case.
   (Senaryonun ortalama çalışma süresini hesapla.)
7. Calculate average probability of usage of test case.
   (Senaryonun ortalama kullanılma olasılığını hesapla.)
8. Compare paths based on calculated values.
   (Yolları hesaplanan değerlere göre karşılaştır.)
9. Select the best path and update pheromone value for each path chosen.
   (En iyi yolu seç, seçilen her yol için feromon değerini güncelle.)
   -> 1. adıma dön
```

Seçilen farklı senaryo gruplarının her birine bir feromon değeri atanır; değerler güncellenerek diğer senaryolar eklenir. Seçilen senaryolar bütün hata gruplarını kapsadığında algoritma sonlanır ve elde edilen verilere bakılarak sıralamaya karar verilir. Feromonun formülü makalede ayrıntılı verilmiştir ama sunuma eklenmemiştir.

> **Ek bilgi (derste anlatılmadı):** ACO, 1990'larda Marco Dorigo tarafından önerilen, karıncaların feromon izi bırakarak kısa yolu bulmasından esinlenen bir meta-sezgisel arama yöntemidir. Klasik sürümde her yolun feromonu bir buharlaşma katsayısıyla azaltılır ve iyi çözümlerde kullanılan yollara feromon eklenir; böylece arama zamanla iyi çözümlere yoğunlaşır. Gezgin satıcı problemi gibi kombinatoryal problemlerde sıkça kullanılır.

### 2.4 Makaledeki deneysel örnek

Makalede 5 test senaryosu (TC01-TC05) ve yapay olarak oluşturulmuş 6 hata (fault 1-6) kullanılmıştır. Birinci tabloda hangi senaryonun hangi hatayı yakaladığı yıldızla işaretlenmiştir. İkinci tabloda her senaryonun çalışma süresi verilmiştir. Algoritma çalıştıktan sonraki tablolarda her senaryonun kaç kez kullanıldığı ve feromon değeri, en sonda da bunlara göre çıkan sıralama gösterilmiştir. <!-- BELİRSİZ: tablolar sunumda bulanıktı ve kare aralığında okunmadı; aşağıdaki değerler sunucunun sözlü aktarımıdır -->

Sunucunun aktarımına göre sıralama şöyle oluşmuştur:

- **TC03 ilk sıraya** yerleşmiştir. Kombinasyonlarda 4 kez kullanılmış, yani en sık kullanılan senaryodur. 0 ile 1 arasında hesaplanan feromon değeri 1'dir. 1, 5 ve 6 numaralı hataları kapsar.
- **TC01 ikinci sıraya** yerleşmiştir. 2, 4 ve 5 numaralı hataları kapsar. Çalışma süresi yüksek, feromon değeri düşüktür (yaklaşık 0,42 olarak okunmuştur). Buna rağmen TC03 ile birlikte kalan hataları kapsadığı için baskın gelmiş ve seçilmiştir.
- **TC05 üçüncü sıraya** yerleşmiştir. Daha az hata kapsar ama feromon değeri yüksektir (yaklaşık 0,6) ve 3 kez kullanılmıştır.

> **Ders sonrası not:** Sunucunun aktardığı kapsama bilgisiyle TC03 (1, 5, 6) ve TC01 (2, 4, 5) birleşimi $\{1, 2, 4, 5, 6\}$ eder; 3 numaralı hata bu iki listede geçmez. Sunucu iki senaryonun bütün hataları kapsadığını söylediği için tablo büyük olasılıkla Whisper'ın ya da sözlü aktarımın atladığı bir hücre içerir; asıl tablo karede okunamadığından kesin değer belirsizdir.

Sonuçta 5 senaryodan yalnız 2'siyle, önceliklendirme yapılarak bütün hatalar kapsanmıştır. Önceliklendirme yapılmasaydı test 19 saniye sürecekti; önceliklendirmeyle iki senaryo 11 saniyede tamamlanmıştır, yani süre yaklaşık %42 kısalmıştır. Ayrıca bir değerlendirme ölçütünün önceliklendirmesiz durumda 0,63, önceliklendirmeli durumda 0,55 olduğu söylenmiştir. <!-- BELİRSİZ: 0,63 ve 0,55'in hangi ölçüte ait olduğu altyazıda bozuk; hangi durumun hangi değere karşılık geldiği de net değil -->

### 2.5 Sunum sonrası soru

Sunumdan sonra bir öğrenci, feromonun regresyon testine nasıl bağlandığını anlamadığını söyler ve sunucu açıklamayı tekrarlar. Bu soru-cevap "Örnek Sorular" bölümünde verilmiştir. Hoca, öğrencilerin bu dönem seçtiği makale konularının çoğunun güzel olduğunu ve son yıllarda yazılmış makalelerden başlandığını belirtir.

## 3. Uygulama Sunumu 1: Seyahat Acentesi Masaüstü Uygulamasının Testi

### 3.1 Test edilen sistem

İlk uygulama sunumunda bir grup, bir seyahat acentesinin tatil ve ulaşım hizmetlerini yönettiği bir bilgi sistemini test etmiştir. Sistem dört modülden oluşur:

- **Giriş-çıkış modülü:** yetkili sistem personeli ve acente görevlisinin sisteme giriş ve çıkış yapmasını sağlar.
- **Kullanıcı modülü:** yetkili sistem personelinin kullanıcı eklemesine ve silmesine olanak verir.
- **Ulaşım modülü:** acente görevlisi, müşterinin gitmek istediği yere istediği tarihte farklı firmaların farklı saatlerdeki seferlerini listeler. Müşteri isterse seferlerden birinin ücretini görevliye öder ve bileti alır. Yetkili personel bu modülde firma ekleyip silebilir.
- **Bilgilendirme modülü:** satın alınan hizmete göre müşteriye bilgi verir.

Üç kullanıcı sınıfı vardır: yetkili sistem personeli (firma ve kullanıcı ekler/siler, firma puanlarını düzenler), acente görevlisi (müşterinin seçimlerini sisteme girer) ve müşteri. Müşterinin sisteme doğrudan erişimi yoktur; işlemlerini görevliye bildirerek yaptırır.

Yazılım arayüzü açısından sistem C# ile .NET Framework 4.6 üzerinde geliştirilmiştir, Windows 7, 8 veya 10 gerektirir ve veritabanı sunucusu olarak MySQL kullanır. Geliştiriciler için Visual Studio 2015, 2017 veya 2019 yeterlidir.

### 3.2 Test süreci ve test planı

Test süreci önce birim testleriyle başlamış, sistemi oluşturan her modül test edilmiş, en son kullanıcı testleriyle sistemin kullanıcı gereksinimlerini karşılayıp karşılamadığı sınanmıştır. Her adımda bulunan hatalar test sonuç belgesinde raporlanmıştır.

Test planı dört aşamalıdır ve bir Gantt şemasıyla gösterilmiştir (ekrandan, 00:25:00):

- **Planning (planlama):** test planının oluşturulması ve bir kilometre taşı.
- **Code Inspection and Execution:** kodun incelenmesi, kodun yerel makinede çalıştırılması (veritabanı sunucusunun kurulup uygulamaya bağlanması dahil) ve bir kilometre taşı.
- **Testing:** birim testi (Unit Testing), arayüz testi (User Interface Testing), sonuçların birleştirilmesi ve bir kilometre taşı.
- **Document Creation and Completion:** plan belgesinin düzenlenmesi, test tanımlama belgesinin tamamlanması ve sonuç belgesinin sonlandırılması.

Testlere başlamadan önce test plan raporu oluşturulmuş, dokümantasyon aşamasında son sürümüne getirilmiştir. Gerçekleştirilen testler ve tanımları test tanımlama raporunda, sonuçları test sonuç raporunda verilmiştir. Her aşamanın sonundaki kilometre taşı, ekibin neyin yapıldığını ve nerede olunduğunu konuştuğu toplantılara karşılık gelir.

### 3.3 Test ortamı ve birim testi

Birim testi Visual Studio'nun test aracıyla yapılmış, ReSharper, dotCover ve TestCop eklenti olarak kurulmuştur. Gerekçe şudur: kullanılan ücretsiz Community sürümü kod kapsamını göstermez; kapsam ölçümü ücretli Enterprise sürümünde vardır. Bu yüzden JetBrains altyapısını kullanan bir kapsam eklentisi tercih edilmiştir. Yazılım nesneye dayalı olduğu için birden çok sınıftan oluşur ve birim testinde her sınıf ayrı ayrı test edilmiştir.

Birim testiyle yaklaşık %93 kod kapsamına ulaşılmıştır. Test edilemeyen bölümler, stub yazılamayan panel (arayüz) kısımlarıdır. Sunucuya göre arayüz kısımlarının birim testi için Java'da ayrı araçlar vardır; C# için bu araçlar ücretli olduğundan kullanılmamıştır.

### 3.4 Fonksiyonel kullanıcı testi

Kullanıcı testine geçmeden önce SRS belgesindeki gereksinimler hatırlatılır. Yetkili sistem personeli kullanıcı adı, şifre ve kullanıcı türü girerek kullanıcı ekler ve siler; firma adı ve puanı girerek firma ekler ve siler; firmaları ve kullanıcıları listeler. Acente görevlisi masa başında bilet satan görevli gibidir: arayüzde nereden nereye, hangi araçla ve hangi saatte gidileceğine göre filtreleme yapar, müşteri bilet almaya karar verirse bilet bilgilerini PDF olarak çıkarır. İki kullanıcı türü de kullanıcı adı ve şifreyle giriş-çıkış yapar; giriş sırasında tür seçmeye gerek yoktur, hesap hangi türde tanımlıysa o türle girilir.

Bütün gereksinimler test edilmiş, iki hata örnek olarak anlatılmıştır:

- **Ondalık puan hatası:** firma eklerken puan alanına yalnız rakam ve nokta girilebilir. 3.5 puanı girilip firmalar yeniden listelendiğinde puan 35 olarak görünür. Bu, yanıltıcı olabileceği için hata sayılmıştır.
- **Alan uzunluğu tutarsızlığı:** kullanıcı eklerken her uzunlukta kullanıcı adı ve şifre girilebilir, ekleme "başarılı" mesajıyla biter. Ancak giriş ekranında kullanıcı adı alanına 10 karakterden fazla yazılamaz; tuşa basılsa da ilerleme olmaz. Şifre için de benzer bir üst sınır vardır. Dolayısıyla uzun adla eklenen kullanıcı işlevsiz kalır. Ekrandaki örnekte uzun bir kullanıcı adıyla ekleme başarılı görünür, giriş ekranında ise ad kesik kalır (ekrandan, 00:30:00). Ayrıca çok kısa şifrelerin, hatta tek karakterin kabul edilmesi de bir zayıflık olarak değerlendirilmiştir.

### 3.5 Test sonuçları ve test riskleri

Birim testinde 2 hata bulunmuştur: biri orta, biri yüksek önemde. Kullanıcı testinde 3 hata bulunmuştur: ikisi yüksek, biri düşük önemde.

Grup ayrıca test sürecine ait riskleri bir tabloyla vermiştir:

| Risk | Etki | Olasılık | Olası neden | Önlem | İlgili taraf |
|---|---|---|---|---|---|
| Test planında ve takvimde gecikme | Yüksek | Orta | Gereksinim belgesinin geç hazırlanması, test ekibinde yeterli kişi olmaması | Testlerin daha yoğun yürütülmesi, yazılım geliştirmenin plana uygun yürütülmesi | Test ve yazılım ekibi |
| Test ortamının hazırlanamaması | Orta | Düşük | Ekibin kurulacak araçlar hakkında tecrübesizliği | Test ekibine eğitim verilmesi | Test ekibi |
| Test ekibinden birinin ayrılması | Yüksek | Düşük | Çalışma koşullarının yetersizliği, daha iyi bir teklif | Çalışan memnuniyetinin artırılması, görüş ve sıkıntılarıyla ilgilenilmesi | Test ekibi ve insan kaynakları |

Takvim gecikmesi riski, önceden planlanmış test takvimine göre bitmesi gereken testlerin zamanında bitmemesi ve ürünün müşteriye teslimatının gecikmesi olarak tanımlanmıştır.

## 4. Uygulama Sunumu 2: Envanter Yönetim Sisteminde PHPUnit ile Birim Testi

### 4.1 Test edilen sistem ve kapsam

İkinci grup, küçük ve orta büyüklükteki işletmeler için yazılmış web tabanlı bir envanter yönetim sistemini test etmiştir. Sistem envanter ve stok işlemlerini, satışları ve diğer işlemleri yönetir; ürün, kategori, makbuz ve kullanıcı kaydeder; gelir ve stokla ilgili rapor ve istatistik üretir; müşterilerin ödeme geçmişini gösterir. Grubun hazırladığı belgenin kapsam bölümünde, önceden sunulmuş SRS raporundaki gereksinimlerin doğrulanması için bir yazılım test dokümanı kullanılacağı belirtilir (ekrandan, 00:35:00).

Test planı 12 modülü kapsar: kullanıcı girişi, kullanıcı kaydı, kullanıcı (pano), işlemler istatistiği, işlemler, envanter istatistiği, müşteriler, tedarikçiler, banka hesapları ve ödeme yöntemleri, ürün ekleme, kategoriler ve ürünler. 12 modülün hepsi için kullanıcı/fonksiyon testi, ekleme işlemlerini içeren 9 modülü için ayrıca birim testi yazılmıştır.

### 4.2 Gereksinimden türetilen test senaryoları

Senaryolar doğrudan SRS'teki gereksinimlerden türetilmiştir. Örnekler:

- **Kullanıcı girişi:** kullanıcı e-posta ve şifreyle giriş yapar; e-posta alanının dolu ve geçerli bir adres olduğu, şifrenin girildiği kontrol edilir; hatalı girişte kullanıcı görsel olarak bilgilendirilir; 5 hatalı girişte kullanıcı 15 dakika boyunca engellenir.
- **Kullanıcı kaydı:** ad-soyad alanı dolu olmalı ve en az 3, en fazla 255 karakter içermelidir; e-posta geçerli olmalıdır; şifre ve şifre doğrulama alanları aynı olmalı ve en az 8 karakter içermelidir; kullanım şartlarının kabul edildiği kontrol edilir. Ekranda 6 karakterlik şifre girildiğinde "en az 8 karakter girin" uyarısı çıktığı ve geçersiz e-postada uyarı verildiği gösterilmiştir (ekrandan, 00:40:00).
- **Kullanıcı (pano) ve istatistik modülleri:** modüle erişimde kullanıcının yetkili olup olmadığı, her kullanıcının yalnız kendi kayıtlarına erişip erişmediği, günlük/haftalık/aylık/yıllık kayıtların görüntülenmesi; envanter istatistiğinde miktara, gelire ve ortalama fiyata göre en yüksek 15 kaydın görüntülenmesi.
- **Müşteriler ve tedarikçiler:** yalnız kendi kayıtlarına erişim, yeni kayıt ekleme, silme ve düzenleme. Bu iki modülün her biri için 14 birim testi yazılmış ve hepsi geçmiştir.

Hoca bu noktada sistem testinin olup olmadığını sorar. Grup, kullanıcı testinin gereksinimlere göre sistemin çalışabilirliğini sınadığını ve ayrıca bir araçla performans ölçümü yaptığını söyler. Hoca, sistem testi için de bir araç bulunmasını önerdiğini hatırlatır.

> **Hocanın vurgusu:** Birbirine benzeyen sonuç ekran görüntülerini tek tek göstermek yerine bir birim testi seçilip, aracın nasıl kullanıldığı ve testin nasıl çalıştırıldığı sınıfa ayrıntılı olarak gösterilmelidir.

### 4.3 PHPUnit ile kullanıcı oluşturma testi

Uygulama PHP ile yazıldığı için birim testleri PHPUnit ile yapılmıştır. 9 modül için toplam 9 test sınıfı yazılmış, hepsi birlikte çalıştırıldığında sonuç "OK (9 tests, 96 assertions)" olmuştur (ekrandan, 00:50:00). Grubun kullandığı uygulamada birim testi yoktu; testler `tests/Unit` klasörüne eklenmiştir.

Kullanıcı testinde önce bir alan dizisi tanımlanır, bu alanlarla bir `User` nesnesi doldurulup kaydedilir, sonra her alan doğrulanır. Ekrandaki testin yapısı şöyledir (ekrandan, 00:50:00 ve 00:55:00; test verisindeki şifre değeri bu notta yer tutucuyla gösterilmiştir):

```php
$fields = [
    'id'       => 1,
    'name'     => 'test',
    'name2'    => 'test',
    'email'    => 'test@example.com',
    'password' => '<test şifresi>',
];

$this->user = new User();
$item = $this->user->fill($fields);
$item->save();

$this->assertArrayHasKey('id', $item);
$this->assertArrayHasKey('name', $item);
$this->assertEquals($item->name, 'test');
$this->assertArrayHasKey('email', $item);
$this->assertEquals($item->email, 'test@example.com');
$this->assertArrayHasKey('password', $item);
$this->assertEquals($item->password, '<test şifresi>');
$this->assertArrayNotHasKey('name2', $item);
$this->assertNotEquals($item->name2, 'name2');

$this->user = $item;
```

Testin mantığı şudur:

- `assertArrayHasKey` ile verilen alanın kayıtta bulunduğu, `assertEquals` ile değerinin doğru olduğu kontrol edilir. Örneğin ad alanına "test" yazıldığı için oluşan kullanıcının adının gerçekten "test" olduğu doğrulanır.
- Testin bir kısmı ters yönden yazılmıştır. Kullanıcı modelinde tanımlı olmayan `name2` adlı fazladan bir alan gönderilir. Kayıt sırasında biri fazladan alan göndererek bir güvenlik açığını kullanmaya çalışabilir; bu yüzden bu alanın kayda girmemesi gerekir. `assertArrayNotHasKey` ve `assertNotEquals` bunu doğrular ve test başarılı geçer.

Canlı gösterimde test çalıştırıldığında bir doğrulama başarısız olmuştur: test verisindeki şifre ile beklenen değer farklı yazılmıştı (biri 8, diğeri 6 karakterlik bir diziydi). İkisi aynı yapılıp test yeniden çalıştırılınca "OK (1 test, 9 assertions)" sonucu alınmıştır (ekrandan, 00:55:00). Bu durum, testin gerçekten bir şeyi kontrol ettiğini de göstermiş olur.

### 4.4 Test yazarken fark edilen tasarım sorunu

Birim testi yazmak koddaki bir sorunu da ortaya çıkarmıştır. Müşteri oluşturulurken "belge türü" ve "belge numarası" diye iki alan vardır (ekrandan, 00:45:00). Belge türü sayısal bir değerdir ve tek başına bir anlam taşımaz; normalde ilişkili bir belge türleri tablosundan gelmesi beklenir. Böyle bir tablo ve ilişki yoktur, bu alanın kontrolü de yapılmamıştır. Öte yandan uygulamanın genelinde veritabanı bütünlüğü kontrolleri yapılmıştır; örneğin ürün eklenirken seçilen kategorinin gerçekten var olup olmadığı kontrol edilir. Grup bu gözlemleri test yazarken edinmiştir.

## 5. Uygulama Sunumu 3: PHP Web Uygulamalarında Birim ve Sistem Testi

Üçüncü grubun iki üyesi başlangıçta farklı projeler için SRS hazırladığından iki ayrı PHP web uygulaması üzerinde ama aynı test yaklaşımıyla çalışmıştır: biri bir kitap satış sitesi, diğeri bir envanter (stok takip) uygulamasıdır.

### 5.1 Kitap satış sitesi ve test ortamı

Birinci uygulama, daha çok hata bulunabileceği düşüncesiyle seçilmiş bir öğrenci projesidir. İki bölümü vardır. Kullanıcı sayfası bir alışveriş sitesinin bütün işlevlerine sahiptir: kitaplar kategorilere ayrılır, sisteme eklenme tarihine göre "en yeniler", en çok satılan ilk 10 kitaba göre "çok satanlar" sayfaları vardır, sepete ekleme ve satın alma yapılır. Admin sayfası ise kitap ekleme, üyeleri listeleme ve kullanıcıların kitaplara yaptığı yorumları listeleyip silme gibi yönetim işlevleri sunar.

Test ortamı şöyle kurulmuştur (ekrandan, 01:00:00):

- PHPUnit, Composer ile kurulur; bu işlem `composer.json` dosyasını ve `vendor` klasörünü oluşturur. PHPUnit'in çalıştırılabilir dosyası `vendor/bin` altındadır.
- Bir `tests` klasörü açılır ve test fonksiyonlarını içeren PHP dosyaları buraya konur (ekranda `TestFunction.php` ve `TestSession.php`).
- `./vendor/bin/phpunit` çalıştırılınca `tests` altındaki bütün testler koşar. Ekrandaki çıktıda PHPUnit 9.5.0, PHP 7.3.11 çalışma zamanı ve `phpunit.xml` yapılandırma dosyası görülür.
- Uygulamada bütün sayfaların fonksiyonları tek bir `function.php` dosyasında toplanmıştır ve sayfalar bu dosyayı çağırır. Bu yüzden testler bu fonksiyon dosyası üzerinde yazılmıştır.
- Web sunucusu olarak Apache, sistem testi için Apache'nin ApacheBench aracı kullanılmıştır.

### 5.2 Kitap sitesinde birim testleri

Testler üç tür fonksiyonu sınar:

- **Listeleme fonksiyonları:** kategorileri ve yayınevlerini veritabanından çekip HTML listesi olarak üreten fonksiyonlar birçok sayfada kullanılır. Örnek olarak yayınevi ve kategori fonksiyonları alınmıştır. Fonksiyonun çıktısında liste etiketleri (`li`) bulunup bulunmadığı, beklenen çıktıyla üretilen çıktı karşılaştırılarak kontrol edilir.
- **Kitap görüntüleme fonksiyonları:** farklı kategorilerdeki kitapları gösteren fonksiyonlar birbirine benzediği için "çok satanlar" sayfası örnek alınmıştır. Görsellerin çıkması gerektiğinden çıktıda `img` etiketleri aranır. Karşılaştırma PHPUnit'in beklenen çıktı fonksiyonuyla yapılmıştır. <!-- BELİRSİZ: altyazıda "expect output fonksiyonu" diye geçiyor; büyük olasılıkla expectOutputString ya da expectOutputRegex -->
- **Oturuma bağlı fonksiyonlar:** yorum yapmak ya da alışveriş yapmak için kullanıcının giriş yapmış olması gerekir. Fonksiyon oturumdan bir kullanıcı kimliği gelmezse "lütfen üye olun" mesajı verir. Bu fonksiyon giriş yapılmış ve yapılmamış iki durumda test edilmiştir; oturum değeri beklenen değerle karşılaştırılır. <!-- BELİRSİZ: altyazıda "S4 de kuz fonksiyonu" diye bozuk geçiyor; büyük olasılıkla assertEquals -->

Bütün testler başarılı geçmiştir. Kullanıcı giriş yapmadan oturum testi çalıştırıldığında beklendiği gibi "failure" alınmıştır. Sunucuya göre bu, yazılan testin gerçekten doğru şeyi test ettiğini görmeyi sağlamıştır.

### 5.3 ApacheBench ile sistem (yük) testi

Sistem testinde farklı senaryolarla sisteme yük bindirilmiştir: 10 kullanıcı 1000 istek, 10 kullanıcı 10.000 istek ve 100 kullanıcı 1000 istek. Birinci senaryonun çıktısı ekranda görülür (ekrandan, 01:05:00):

```text
ab -k -n 1000 -c 10 http://localhost/index.php

Server Software:        Apache/2.4.41
Document Length:        13214 bytes
Concurrency Level:      10
Time taken for tests:   1.623 seconds
Complete requests:      1000
Failed requests:        0
Total transferred:      13396000 bytes
HTML transferred:       13214000 bytes
Requests per second:    615.99 [#/sec] (mean)
Time per request:       16.234 [ms] (mean)
Time per request:       1.623 [ms] (mean, across all concurrent requests)
Transfer rate:          8058.44 [Kbytes/sec] received

Percentage of the requests served within a certain time (ms)
  50%  14
  66%  16
  75%  18
  80%  19
  90%  24
  95%  29
  98%  41
  99%  53
 100%  100 (longest request)
```

Komuttaki `-n` toplam istek sayısını, `-c` eşzamanlı istek (kullanıcı) sayısını, `-k` bağlantının açık tutulmasını (keep-alive) belirtir. Değerler birbiriyle tutarlıdır (python ile kontrol edildi):

- Saniyedeki istek: $1000 / 1{,}623 \approx 616$; ekrandaki 615,99 değeri sürenin yuvarlanmamış hâlinden gelir.
- Eşzamanlı istekler üzerinden istek başına süre: $1{,}623\ \text{s} / 1000 = 1{,}623\ \text{ms}$.
- Tek bir isteğin ortalama süresi: $1{,}623 \times 10 \approx 16{,}23\ \text{ms}$ (ekranda 16,234 ms). 10 istek aynı anda işlendiği için iki ortalama arasında 10 kat fark vardır.
- HTML aktarımı: $13214\ \text{bayt} \times 1000 = 13\,214\,000$ bayt.

Sunucunun yorumları şöyledir: istek sayısı 10 katına (10.000) çıkarıldığında, kullanıcı sayısı yine 10 olduğu için toplam süre doğrusal artmamış, yaklaşık 50 saniyeye çıkmıştır. Kullanıcı sayısı 100'e çıkarılıp istek sayısı 1000'de tutulduğunda süre çok değişmemiş (yaklaşık 2 saniye), ama kullanıcı fazla olduğu için saniyede karşılanan istek sayısı artmıştır.

> **Ek bilgi (derste anlatılmadı):** ApacheBench'teki yüzdelik satırları (50%, 90%, 99%) yanıt süresi dağılımını gösterir; örneğin "90% 24" isteklerin %90'ının 24 ms içinde yanıtlandığı anlamına gelir. Yük testlerinde ortalamadan çok bu yüzdelikler ve en uzun istek süresi izlenir, çünkü kullanıcı deneyimini kuyruktaki yavaş istekler belirler.

### 5.4 Envanter uygulaması: veritabanı ve yardımcı fonksiyon testleri

Grubun ikinci üyesi, hazır bir uygulama üreticisiyle oluşturulmuş bir stok takip web uygulamasını test etmiştir. Uygulamada kategoriler, ürünler (item), depolama bölümleri, işlemler (transaction) ve partiler (batch) vardır; ürünlerin takvime bağlı olarak bir depodan diğerine aktarılması ve giriş-çıkışların izlenmesi sağlanır. Uygulama Apache üzerinde çalışır, MySQL kullanır. Çok sayıda modül olduğu için en temel ve en çok kullanılan fonksiyonlar seçilmiştir.

Her sınıf ya da betik için ayrı bir test betiği yazılmıştır. Betikler tek tek çalıştırılabildiği gibi `phpunit.xml` yapılandırmasıyla hepsi arka arkaya da çalıştırılabilir. Test ortamı PHPUnit 9.5 ve PHP 7.3'tür.

İlk test sınıfı (`DBTest`) veritabanı fonksiyonlarını sınar (ekrandan, 01:10:00 ve 01:15:00; bağlantı bilgileri bu notta yer tutucuyla gösterilmiştir):

```php
use PHPUnit\Framework\TestCase;

class DBTest extends TestCase
{
    public function test_dbconnect(){
        require 'app/db.php';
        require 'app/settings-manager.php';
        $host = "<sunucu>";
        $username = "<kullanıcı>";
        $passwd = "<şifre>";
        $dbname = "<veritabanı>";
        $port = "<port>";
        $connected = db_connect($host,$username,$passwd,$dbname,$port);
        $this->assertFalse(!$connected);
    }

    public function test_db_num_rows(){
        if(function_exists('mysqli_connect')) {
            $result = @mysqli_query("SELECT * FROM categories", $link);
        } else {
            $result = @mysql_query("SELECT * FROM categories", $link);
        }
        $expected = @mysqli_num_rows($results);
        $num_rows = db_num_rows($result);
        $this->assertEquals($expected,$num_rows);
    }
}
```

- `test_dbconnect`, MySQL bağlantısını kuran `db_connect` fonksiyonunun bağlantıyı gerçekten kurduğunu doğrular.
- `test_db_num_rows`, `categories` tablosundaki satır sayısını döndüren yardımcı fonksiyonun doğru değer döndürdüğünü kontrol eder.

> **Ders sonrası not:** Ekrandaki ikinci testte sorgu sonucu `$result` değişkenine atanırken beklenen değer `$results` değişkeninden okunuyor ve `$link` bağlantısı bu fonksiyonda tanımlanmıyor. Ayrıca `mysqli_query` bağlantıyı ilk parametre olarak alır. Bu haliyle test büyük olasılıkla beklenen değeri doğru hesaplamaz; sunumda bu konuya değinilmemiştir.

İkinci test sınıfı (`CommonTest`) ortak kullanılan iki yardımcı fonksiyonu sınar: HTML `<br>` etiketini yeni satır karakterine dönüştüren `br2nl` fonksiyonu (basit bir düzenli ifade değiştirmesidir) ve web arayüzünden gelen tarih biçimini MySQL tarih biçimine çeviren bir fonksiyon. Testte girdi metni ve beklenen sonuç önceden belirlenir, fonksiyon `require` ile içe aktarılan kaynak dosyadan çağrılır ve sonucun beklenen değere eşit olduğu kontrol edilir.

`phpunit.xml` yapılandırmasıyla 4 birim testi birlikte çalıştırılmış ve hepsi geçmiştir. Başarısız durumu göstermek için test dosyasındaki veritabanı şifresi bilerek değiştirilmiş, bağlantı testinin MySQL'in "erişim reddedildi" hatasıyla başarısız olduğu gösterilmiştir.

### 5.5 Envanter uygulamasında stres testi

Bu üye de üç senaryolu bir stres testi yapmıştır; amaç farklı kullanıcı ve istek sayılarında sistemin yanıt davranışını ölçmektir. Diğer üyeden farklı olarak daha küçük istek sayıları (100 ve 1000) kullanılmıştır. Birinci senaryoda 10 kullanıcı 100 istek, ikincide 10 kullanıcı 1000 istek göndermiştir. Sunucuya göre bu iki senaryonun süreleri birbirine yakın çıkmıştır (en yüksek değerler 576 ve 502). Kullanıcı sayısı 10 katına çıkarıldığında 502 olan değerin 5200'lere, yani yaklaşık 10 katına çıktığı söylenmiştir. <!-- BELİRSİZ: 576, 502 ve 5200 değerlerinin hangi ölçüte (süre mi, istek sayısı mı) ve hangi birime ait olduğu altyazıdan net değil; ilgili kare yok -->

Sunucunun yorumu, ciddi bir tıkanıklık (congestion) sorunu olmadığı ve paralel çalışabilen Apache'nin iki çekirdekli bir makinede yeterli iş parçacığını oluşturup yükü karşılayabildiğidir.

Hocanın isteği üzerine sunucu, testi canlı olarak da gösterir: test klasörü, `phpunit.xml` dosyasının bu klasörü göstermesi, `br2nl` testinin girdisi ve beklenen çıktısı, terminalde PHPUnit'in çalıştırılması ve şifre bilerek değiştirildiğinde kırmızı başarısızlık çıktısı.

## 6. Test Raporlarında Farklı Yaklaşımlar

Sunumların sonunda bir öğrenci, test raporunu sektörde uygulanan biçimde hazırladığını söyler: önce geliştirici tarafında testler yapılıp sonra test ekibine devredilen bir akış. Hoca buna tek tip bir şey istemediğini, farklı bakış açılarının ve kullanımdaki farklı biçimlerin görülmesinin daha iyi olduğunu söyler. Test raporu için bu yüzden belirli bir format vermemiştir; bir sunumun bu derste yapılan sunumlarla aynı sırayı izlemesi şart değildir.

> **Hocanın vurgusu:** Test uygulamalarında tek bir prosedür izlenmesi gerekmez; farklı türde yapılan uygulamalar, uygulamadaki farklılıkları görmek açısından değerlidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:56): Makale sunumunda feromon kavramı regresyon testine nasıl bağlanıyor?

**Cevap (derste verildi):** Karınca benzetmesinde en sık kullanılan yolda en çok feromon birikir. Test tarafında test senaryoları hata kapsamına göre kombinasyonlar halinde (örneğin 1-2, 2-3, 2-3-5) denenir. Birlikte en sık kullanılan senaryo daha çok "feromon" biriktirir; örnekte TC03 4 kez kullanıldığı için feromon değeri 1 olmuştur. Algoritma her kombinasyonda feromon değerini günceller. Sıralamada yalnız feromon değil, kapsama da dikkate alınır: TC03 ilk sıraya, TC03'ün kapsamadığı hataları kapsadığı için TC01 ikinci sıraya, feromon değeri yaklaşık 0,6 olup 3 kez kullanılan TC05 üçüncü sıraya yerleşmiştir. Feromonun kesin formülü makalede verilmiş, sunuma eklenmemiştir.

**Soru 2** (derste sözlü, 00:37:34): Kullanıcı testi ve birim testi yapılan bir projede sistem testi ayrıca var mı?

**Cevap (derste verildi):** Grup, gereksinim belgesindeki maddelerin (örneğin geçerli e-posta adresi zorunluluğu) kullanıcı testiyle sistem üzerinde kontrol edildiğini ve ayrıca bir araçla performans ölçümü yapıldığını söyler. Hoca, sistem testi için de bir araç kullanılmasını önerdiğini hatırlatır. Diğer grup sistem testini ApacheBench ile yük testi biçiminde yapmıştır (bkz. 5.3).

## Dersin Toparlaması

Bu derste dönemin son makale sunumu ve ilk uygulama projesi sunumları yapıldı. Makale sunumunda regresyon testinde seçerek yeniden test stratejileri ve bunun bir kolu olan test senaryosu önceliklendirme ele alındı; karınca kolonisi optimizasyonunun, kombinasyonlarda birlikte sık kullanılan senaryolara yüksek feromon vererek ve hata kapsamını da gözeterek az sayıda senaryoyla bütün hataları daha kısa sürede kapsayabildiği bir örnekle gösterildi.

Uygulama sunumlarında dersin önceki konuları somut projelerde görüldü: SRS'ten türetilen test senaryoları, aşamalı ve kilometre taşlı test planı, test plan/tanımlama/sonuç belgeleri, birim testi ve kod kapsamı, fonksiyonel kullanıcı testi, hata önem dereceleri ve test riskleri. PHPUnit ile doğrulama fonksiyonlarının kullanımı, testin kendisini sınamak için beklenen değerin bilerek bozulması ve ApacheBench ile yük testi uygulamalı olarak gösterildi. Hoca, test uygulamalarında tek bir format yerine farklı yaklaşımların görülmesinin değerli olduğunu vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
