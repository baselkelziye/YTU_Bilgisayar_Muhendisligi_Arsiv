# Ders 11 Genişletilmiş Notu: Dönem Projesi Sunumları: Kütüphane, Poliklinik ve Medya Takip Bilgi Sistemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Amacı ve Proje Sunumlarının Ortak İskeleti
- 2. Birinci Kütüphane Bilgi Sistemi Projesi
- 3. İkinci Kütüphane Bilgi Sistemi Projesi
- 4. Üçüncü Kütüphane Bilgi Sistemi Projesi
- 5. Birinci Poliklinik Bilgi Sistemi Projesi
- 6. Medya Takip Bilgi Sistemi Projesi
- 7. İkinci Poliklinik Bilgi Sistemi Projesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Amacı ve Proje Sunumlarının Ortak İskeleti

Bu ders, öğrenci gruplarının dönem projelerini sunduğu bir oturumdur. Hoca, bu oturumda projelerin yalnız **modelleme** ve **proje yönetimi** ile ilgili kısımlarını incelediğini belirtti. Projelerin program tarafı, yani belirli bir modülün çalıştırılması ve kodun ayrıntılı gösterimi ayrı bir oturuma bırakıldı. Bu yüzden sunumlarda kod ekran görüntüleri ve arayüzler çoğunlukla hızlıca geçildi.

Sunulan projelerin hepsi derste işlenen yazılım mühendisliği etkinliklerini aynı sırayla izledi. Bu sıra, bir dönem projesi raporunun da iskeleti olarak okunabilir:

- **Proje planı:** proje alan tanımı, kapsam, fayda, kabuller ve kısıtlar, fizibilite (teknik, donanım, yasal, ekonomik).
- **Yazılım geliştirme süreç modeli** seçimi ve gerekçesi.
- **İş-zaman çizelgesi** (Gantt diyagramı) ve **maliyet** kalemleri.
- **Ekip organizasyon şeması** ve görev dağılımı.
- **Risk tablosu** (risk adı, türü, olasılık, etki, önlem) ve bazı gruplarda risk bilgi sayfaları.
- **İsteklerin modellenmesi:** kullanım senaryosu metinleri ve kullanım durumu (use case) diyagramı.
- **İzlenebilirlik tablosu.**
- **Nesneye dayalı modelleme ve tasarım:** kavramsal sınıf diyagramı, metotlarla zenginleştirilmiş tasarım sınıf diyagramı, etkinlik, durum ve sıralama diyagramları.
- **Birim testleri.**

Sunulan konular: üç grup kütüphane bilgi sistemi, iki grup poliklinik bilgi sistemi, bir grup medya takip bilgi sistemi.

## 2. Birinci Kütüphane Bilgi Sistemi Projesi

### 2.1 Proje Konusu ve Müşteri İhtiyaçları

Proje, kurgusal bir özel üniversitenin yeni kütüphane binasında kullanılacak yeni bir bilgi sistemidir. Grup önce müşteri ihtiyacını analiz ederek ürünün sahip olması gereken özellikleri şöyle sıraladı (ekrandan, 00:05:00):

1. İleride genişletilebilir envanter kategori yönetimi ile ürünler kategorize edilebilmelidir.
2. Kullanıcı yönetimi ile yönetici, öğrenci, memur ve öğretim üyesi kullanıcı sınıfları olmalıdır.
3. Her kullanıcı sınıfına göre özelleştirilmiş ve değiştirilebilir ödünç alma sistemi olmalıdır.
4. Ödünç alınan ürünler geri getirildiği zaman, eğer gecikme varsa gecikmeler için ceza hesaplanmalı ve bu ceza tanımlanmış olan kullanıcı bakiyelerinden düşülmelidir.
5. Kullanıcılar, başkasında olan bir ürüne rezervasyon koyabilmeli ve ürün geri iade edildiği zaman bildirim alabilmelidir.
6. E-posta ile rezervasyon, gecikme, ceza vb. gibi durumlar için bildirim verebilmelidir.

### 2.2 Kabuller, Kapsam ve Fayda

Bu ihtiyaçlara göre şu kabuller yapıldı:

- Kurumsal bir veri tabanı yerine açık kaynak ve dosya tabanlı bir veri tabanı kullanılacaktır.
- Sistemin yöneticisi kütüphane çalışanı olacaktır.
- Sistemde yapılacak işlemler 100 bin ürün ve 5 bin kullanıcıya kadar her bir işlem için 5 saniyenin altında olmalıdır. Bu, ölçülebilir bir başarım (performans) gereksinimidir.
- Ürün ve kullanıcı veri girişleri, kütüphane çalışanlarına sağlanacak arayüzle, ürün geliştirmeyle eş zamanlı olarak çalışanlar tarafından yapılacaktır.
- Sisteme giriş ve para yükleme için öğrenci ve personelin kimlik kartları kullanılacaktır.

**Kapsam:** Teslim edilecek yazılım, plandaki ve müşteriyle belirlenen ihtiyaçlardan çıkarılan kullanıcı hikayeleriyle sınırlıdır. **Fayda:** Yazılım kurulduğunda kütüphane personelinin ödünç verme, rezervasyon ve bakiye işlemleri gibi işleri yapmaması ve böylece çalışma saatlerinin yaklaşık %45'ine denk gelen iş yükünden kurtulması planlandı.

### 2.3 Süreç Modeli Seçimi

Grup, müşterinin istediği ürünün daha önce yapılan projelere benzemesi, karmaşıklık seviyesinin düşük olması ve proje süresinin kısa olması nedeniyle geleneksel bir süreç olan **şelale modelini** seçti.

### 2.4 Risk Tablosu ve Risklerin İzlenmesi

Grup, proje sırasında karşılaşılabilecek riskleri bir tabloda topladı. Tabloda her riskin tanımı, kategorisi, ortaya çıkma olasılığı ve ortaya çıktığında yaratacağı sorunun büyüklüğü (etkisi) yer aldı. Olasılık ile etki çarpılarak riskin toplam önemi bulundu; her risk için alınacak önlemler de listelendi.

> **Ek bilgi (derste anlatılmadı):** Olasılık ile etkinin çarpımı literatürde genellikle "risk maruziyeti" (risk exposure, $RE = P \times C$) olarak adlandırılır. Burada $P$ riskin gerçekleşme olasılığı, $C$ gerçekleşirse doğuracağı maliyettir. Riskler bu değere göre sıralanarak önce en yüksek maruziyetli olanlar için önlem planlanır.

Hoca risk tablosunu yeniden açtırarak önlemlerin yazıldığını, ama izlemenin nasıl yapılacağının görünmediğini belirtti ve bir takip planı sordu.

**Soru:** İlk başta böyle riskler çıktı. Bunları nasıl takip edersiniz? **Cevap:** Grup, risk kategorisinin riskin projenin hangi aşamasında öne çıkacağını gösterdiğini söyledi. Örneğin geç teslim riski projenin sonunda değil, zaman planına uyulup uyulmadığı izlendikçe ortaya çıkar; hata verme ya da veri kaybı ise müşteriye teslimden hemen önceki testlerde ortaya çıkar. Amaç, risk ortaya çıkmadan onu ortadan kaldıracak önlemleri almaktır.

> **Hocanın vurgusu:** Riskler sürekli kontrol edilmelidir; "sürekli" her gün demek değildir, her kilometre taşında (milestone) o döneme göre "gecikme var mı" diye bakılmalıdır.

### 2.5 Organizasyon, Zaman Planı ve Maliyet

Ekip beş kişiden oluştu: bir ürün sahibi, bir proje yöneticisi, iki geliştirici ve bir kalite güvence uzmanı (ekrandan, 00:10:00). Roller şöyle tanımlandı:

- **Ürün sahibi:** Müşterinin istekleriyle proje grubu arasında köprü görevi görür; kullanıcı senaryolarının önceliklendirilmesinden ve doğru işlendiğinin kontrolünden sorumludur.
- **Proje yöneticisi:** Görevlerin hangi sırayla yapılacağını, nelerin yapılacağını belirler ve genel koordinasyondan sorumludur.
- **Geliştiriciler:** Kiosk uygulamasının kodlanmasından ve uygun biçimde gösterilmesinden sorumludur.
- **Kalite güvence uzmanı:** Hangi birim testlerinin yapılacağını belirler ve kodun doğru çalıştığından emin olmak için gereken testleri koordine eder.

Zaman planı yaklaşık bir aylık süreye yayıldı: proje planı (organizasyon, zaman planı, kabuller ve kısıtlar), kullanıcı senaryolarının belirlenmesi, isteklerin modellenmesi (kullanım durumları, diyagram ve metin olarak), izlenebilirlik tablosu, nesneye dayalı modelleme, tasarım ve en sonda kurgulanan kullanım durumlarına göre test ve varsayımların kontrolü.

Maliyet hesabında işçilik kalemi, 26 günlük süre için herkesin günlük maliyetlerinin toplamı olarak 2600 dolar bulundu. Buna yazılım lisansları, tek bir kiosk donanımı, çalışan masrafları, risk ve genel gider payları eklendi ve üzerine %20 kâr konarak toplam 3900 dolarlık bir iş ortaya çıktı.

> **Ders sonrası not:** $3900 / 1{,}2 = 3250$ dolar olduğundan, kâr öncesi toplam büyük olasılıkla 3250 dolardır; bu durumda işçilik dışındaki kalemlerin toplamı büyük olasılıkla $3250 - 2600 = 650$ dolardır. Diğer kalemlerin tek tek değerleri altyazıda geçmedi.

### 2.6 Sınıf Diyagramı

Grubun ilk planlamada çıkardığı sınıf diyagramı şöyledir (ekrandan, 00:15:00):

| İlişki | Çokluk |
|---|---|
| SmartCard – User | 1 – 1 (User tarafında içi boş eşkenar dörtgen) |
| Relation – User | 1 – 1 |
| Relation – Item | 1 – 1 |
| User – Library | * – 1 |
| Item – Library | * – 1 |
| Library – DBOperations | 1 – 1 |

Ayrıca `Person` sınıfından `Officer`, `Student` ve `Teacher` sınıfları kalıtıldı; çünkü bu üç kullanıcı türünün bir parçayı elde tutma süresi ve aynı anda tutabileceği parça sayısı gibi farklı yetkinlikleri vardı. Sınıfların rolleri:

- **User:** Memur, öğretmen ya da öğrenci; her kullanıcının bir akıllı kartı ve bir kimliği vardır.
- **Relation:** Veri tabanıyla bağlantının nesnesidir. Bir kullanıcı bir parçayı ödünç aldığında bir kullanıcı, bir parça, alındığı tarih ve kullanıcı sınıfına göre hesaplanan son teslim tarihi (deadline) bu tabloya kaydedilir. Son teslim tarihinden sonraki her gün için kullanıcıya 1 lira ceza yazılır.
- **Library:** Ödünç verme, ödünç alma, bakiye yükleme, bakiye düşme, ceza ödeme gibi ana işlemlerin yapıldığı sınıftır; her kullanıcı sınıfı için parça limiti ve süre limiti öz niteliklerini tutar.
- **DBOperations:** MySQL bağlantısını sağlayan sınıftır.

Grup, uygulama ilerledikçe `Person` alt sınıflarına şimdilik gerek olmadığını fark etti; bu sınıflar genişletilebilirlik için diyagramda bırakıldı ama içleri boş kaldı. Kullanıcı türü akıllı kart içindeki bir "type" alanıyla tutuldu ve bütün işlemler bu alanla yürütüldü.

### 2.7 Kullanım Durumu Diyagramı ve Kullanım Senaryoları

Kullanım durumu diyagramında üç kullanıcı tipi (öğrenci, öğretim üyesi, memur) ve bir sistem yöneticisi yer aldı. Hepsi envanteri görüntüleyebilir; bu durum "parça ödünç alma" ve "parça rezerve etme" ile genişleyebilir. Kullanıcı parça iade ettiğinde borcu varsa borç ödemeye genişleyebilir ya da parçadan bağımsız olarak doğrudan borç ödeyebilir. Sistem yöneticisi ödünç alma süresini, ödünç alma sayısını değiştirmekten ve yeni gelen parçayı envantere eklemekten sorumludur.

Grup beş kullanım senaryosunu metin olarak yazdı: yeni gelen parçayı sisteme ekleme, parça ödünç alma, parça iade etme, ödünç alma süresini ve sayısını değiştirme, parça rezerve etme. Örnek olarak "parça ödünç alma" senaryosu:

- **Birincil aktör:** Kütüphane kullanıcısı (öğrenci, öğretim üyesi ya da memur).
- **İlgililer ve ilgi alanları:** Kullanıcı doğru ve hızlı bir giriş, en az çabayla en fazla hizmet ve parça için bilgilendirici bir fiş ister. Fiş isteği proje metninde yoktu; grup, olası bir anlaşmazlıkta kullanıcının elinde belge bulunması için ekledi.
- **Ön koşul:** Kiosk sistemi veri tabanına bağlıdır.
- **Son koşul:** Parça ödünç verilmiş, sisteme kaydedilmiş ve fiş yazdırılmıştır.
- **Ana senaryo (5 adım):** Kullanıcı kioska kartıyla giriş yapar; parçanın barkodunu taratır; ekranda bir onay isteği belirir; kullanıcı onaylar; ödünç alma bilgileri fişe yazdırılıp verilir.
- **Alternatif akışlar:** Kart sistem tarafından tanınmaz (uyarı); barkod geçersizdir (uyarı); kullanıcının borcu vardır (uyarı, borç ödemeye yönlendirme ya da iptal); ödünç alma limiti aşılır; kullanıcı öğretim üyesi değildir ve parça ders kitabı türündedir (kitap verilmez); kullanıcı işlemi onaylamaz (sistem başa döner).

### 2.8 Durum, Etkinlik ve Sıralama Diyagramları

**Kütüphane kullanıcısı durum diyagramı** (ekrandan, 00:20:00):

```text
[başlangıç] --Kullanıcı Kütüphane Sistemine Kayıt Olur--> Ödünç Alabilir

Ödünç Alabilir --Ödünç Alma [ödünç alma limiti aşılmadı AND ceza limiti aşılmadı]--> Ödünç Alabilir
Ödünç Alabilir --Ödünç Alma [ödünç alma limiti aşıldı OR ceza limiti aşıldı]--> Ödünç Alamaz

Ödünç Alamaz --İade [ceza limiti aşıldı]--> Ödünç Alamaz
Ödünç Alamaz --Ceza Ödendi [ödünç alma limiti aşıldı]--> Ödünç Alamaz
Ödünç Alamaz --İade [ödünç alma limiti altına düşüldü AND ceza limiti aşılmadı]--> Ödünç Alabilir
Ödünç Alamaz --Ceza Ödendi [ceza limiti altına düşüldü AND ödünç alma limiti aşılmadı]--> Ödünç Alabilir

Ödünç Alabilir --Kullanıcı Kütüphane Sisteminden Ayrılır--> [son]
```

Geçişlerdeki köşeli parantezler koruma koşullarıdır (guard); aynı olay (örneğin "Ödünç Alma"), koşula göre farklı durumlara götürür.

**Parça durum diyagramı:** Parça envanterde bulunuyorsa ya da yeni kopya eklenirse "ödünç alınabilir" durumunda kalır. Envanterde kalmazsa "ödünç alınamaz" durumuna geçer ve bu durumda rezervasyon koşulu açılır. Parça envantere geri döndüğünde tekrar "ödünç alınabilir" olur.

Etkinlik diyagramları ödünç alma, iade etme ve rezerve etme işlemleri için çizildi. Sıralama diyagramları ödünç alma ve iade için çizildi; ödünç alma sıralama diyagramında Relation sınıfının nerede kullanıldığı görülüyordu.

**Soru:** Sıralama diyagramında ya da metotlarda bir tasarım kalıbı (design pattern) düşündünüz mü? Metotlara hazır bir tasarım kalıbı eklenebilir mi diye baktınız mı? **Cevap:** Grup, tasarım kalıbı kullanmadığını, daha çok metotların içinin nasıl yazılacağını düşündüğünü söyledi.

### 2.9 İzlenebilirlik Tablosu

Bu noktada hoca, başka bir öğrencinin önceden sorduğu "izlenebilirlik tablosu nasıl hazırlanır" sorusunu bu grubun tablosu üzerinden açıklattı. Hoca derste bunu bir tablo olarak göstermediğini, tablonun hangi işlemde hangi veri tabanı ve uygulama parçalarının etkin olduğunu göstermesi gerektiğini söyledi.

Grup, tablosunda "ödünç alma" işleminin hangi koşul ve adımları gerektirdiğini işaretledi: kioskun veri tabanına bağlı olması, giriş yapılması, kullanıcı kartının tanınması, barkodun taratılması gibi. Ödünç alma işlemi bu adımların hepsini kullanır. Bazı işlemlerde bazı adımlar gereksizdir: örneğin rezerve etme işleminde parça bilgi girişi gerekmez, çünkü parça zaten kütüphanede yoktur; parça sisteme eklenirken de fiş bastırmaya gerek yoktur.

> **Ek bilgi (derste anlatılmadı):** İzlenebilirlik tablosu (traceability matrix), bir yazılım öğesini (gereksinim, kullanım senaryosu) onu gerçekleyen ya da sınayan öğelerle (sınıf, modül, test, tablo) satır-sütun eşlemesiyle ilişkilendirir. Bir gereksinim değiştiğinde hangi tasarım ve kod parçalarının etkileneceğini ya da bir sınıf değiştiğinde hangi senaryoların yeniden sınanacağını bulmayı kolaylaştırır; bu yüzden değişiklik yönetiminin temel aracıdır.

### 2.10 Test Stratejisi

Grup şu test durumlarını tanımladı (ekrandan, 00:25:00):

1. Sisteme yeni kullanıcı ekleme
2. Aynı TC kimlik numarası ile kullanıcı ekleme
3. Sisteme yeni parça ekleme
4. Rastgele bir kullanıcıya limit üzerinde parça verme
5. Parça iade etme (elde bulundurulan parça sayısı)
6. Parça iade etme (parça stok bilgisi)
7. Parça limiti güncelleme
8. Parça ödünç alma zaman limiti güncelleme
9. Bakiye yükleme
10. Öğretim üyesi dışında bir kullanıcıya ders kitabı verme

Testlerin açıklamaları: yeni kullanıcı eklenince veri tabanıyla ilişki kurulup kurulmadığı; aynı kimlik numarasıyla ikinci kez eklemede hata mesajı verilip verilmediği; limit aşımında hata verilip verilmediği; iadeden sonra veri tabanındaki stok bilgisinin artıp artmadığı ve kullanıcının elindeki parça sayısının düşüp düşmediği; yöneticinin limiti güncelleyebildiği ve güncellemeden sonra parça alınabildiği; bakiye yüklemede (kredi kartı bilgisi alınmadan) yalnız miktarın veri tabanına eklenip eklenmediği; öğretim üyesi dışındaki birine ders kitabı verilip verilmediği.

Grup testlerin boş bir veri tabanı üzerinde değil, internetten bulunan kişi ve kitap veri kümeleriyle doldurulmuş bir veri tabanı üzerinde yapıldığını belirtti.

**Soru:** Test gerçekleştirirken yazılımı hazırladığınız dille ilişkili bir birim test oluşturdunuz mu? **Cevap:** Evet; uygulama Java ile yazıldığı için JUnit kullanıldı. Kod testleri ayrı oturumda gösterileceği için sunuma konmadı.

## 3. İkinci Kütüphane Bilgi Sistemi Projesi

### 3.1 Alan Tanımı, Kabuller, Kısıtlar ve Fizibilite

Bu grup da aynı kütüphane problemini ele aldı. Sistemde kitap, dergi ve DVD türünde ürünler vardır; başlangıçta kitap ve dergiler eklidir, DVD'ler sonradan girilebilir. Kullanıcı ürün ödünç alabilir, geri bırakabilir ya da kısıtlara uymuyorsa ödünç alamaz. Ürün sistemde yoksa rezerve edilir ve ürün geri geldiğinde kullanıcıya e-posta gider.

- **Genel kabuller:** İnsan kaynağında azalma olmayacak; proje başladıktan sonra müşteriden yeni istek gelmeyecek; ayarlanan toplantılara herkes katılacak.
- **Kısıtlar:** Belirli bir zaman kısıtı (ay sonunda teslim), üniversite yönetiminin verdiği bütçe ve dört kişilik ekip.
- **Teknik fizibilite:** Arayüz için JavaFX, e-posta için JavaMail kütüphanesi, işletim sistemi olarak Windows 10, veri tabanı olarak PostgreSQL.
- **Donanım fizibilitesi:** Dört kişinin ayrı ayrı çalışması için ortalama bir donanım tanımlandı.
- **Yasal fizibilite:** Kullanıcıdan alınan bilgilerin güvenliği ve bu bilgilerin kötüye kullanılmaması.

Gantt diyagramında teslim tarihi baz alınarak bir plan yapıldı ve plana sadık kalınmaya çalışıldı. Kilometre taşları: problemin analizi, kavramsal tasarım, kodlama ve bütünleme, kapanış.

### 3.2 Risk Tablosu ve Risk Bilgi Sayfası

Grup yüksek riskli bir maddeyi örnek verdi: **projeyi yapan personel sayısının önerilenden düşük olması**. Proje beş kişilik ekip için tanımlanmıştı ama grup dört kişiyle başladı; bu risk yüksek olasılıklı ve etkisi büyük olarak değerlendirildi. Risk grafiği ve her risk için bir **risk bilgi sayfası** hazırlandı. Bu riskin bilgi sayfasında:

- **Risk:** Projenin ekibe atanması sonucunda önerilenden daha az personelle ekip oluşturulması.
- **İşaret:** Proje atandığında bu durumun belirtilmiş olması.
- **Önlemler:** Daha yetkin kişileri seçmek, düzgün bir iş planı uygulamak, hızlı ilerlemeye uygun bir yazılım geliştirme modeli seçmek, çalışanların yetkinliklerine göre iş dağılımı yapmak.

Raporda ayrıca proje ekibinin aynı anda farklı projelerde olması ve süre kısıtı içinde sınırlı personelle çalışılması gibi işaretlere karşı zaman planlamasının düzgün yapılması, toplantı sıklığının artırılması ve ekibin konuda deneyimli kişilerden oluşturulması önlemleri yazıldı (ekrandan, 00:35:00).

### 3.3 Sınıf Düzeyinde İzlenebilirlik Tablosu

Grup, izlenebilirlik tablosunu sınıf düzeyinde, "değişiklik yönetimi amacıyla" hazırladı: kullanım senaryolarının hangi sınıfları kullanarak çalıştığını işaretledi (ekrandan, 00:35:00).

| Sınıf | Kayıt Olmak | İçerik Eklemek | Kısıtlamaların Güncellenmesi | Ödünç Almak | İade Etmek | Bakiye Yüklemek | Borç Ödemek | Rezervasyon Yapmak |
|---|---|---|---|---|---|---|---|---|
| Admin |  | X | X |  |  |  |  |  |
| Book |  | X |  | X | X |  |  | X |
| Borrow |  |  |  | X | X |  |  |  |
| DVD |  |  |  | X | X |  |  | X |
| Magazine |  | X |  | X | X |  |  | X |
| Product |  | X |  | X | X |  |  | X |
| Rezervation |  |  |  |  |  |  |  | X |
| SmartCard | X |  |  |  |  | X | X |  |
| User | X |  |  |  |  | X | X |  |
| Database | X | X | X | X | X | X | X | X |

Tabloda X işareti, senaryonun o sınıfı kullandığını gösterir. Örneğin "içerik ekleme" senaryosu Admin, Book, Magazine, Product ve Database sınıflarını kullandığı için bu hücreler işaretlendi. Grup, müşterinin yazılımı görmese bile hangi senaryonun hangi sınıflarla bağlantılı olduğunu bu tablodan anlayabileceğini belirtti.

### 3.4 Kullanım Senaryoları ve Kullanım Durumu Diyagramı

Senaryolar: kütüphaneye kayıt olma, içerik ekleme, kısıtlamaların güncellenmesi, ödünç alma, iade etme, bakiye yükleme ve borç ödeme.

**Borç ödeme senaryosu:** Kullanıcının ödünç alabilmesi için sistemdeki borcunu ödemesi gerekir. Kullanıcı ilgili butona tıklayarak bakiye ve borç bilgisini görüntüler, ardından ödeme butonuna basarak cezasını öder ve tutar borcundan düşülür. Kullanıcının bakiyesi borcundan azsa bakiyesi kadar borç ödenir.

**Ödünç alma senaryosu:** Birincil aktör kullanıcıdır; ön koşul kullanıcının sisteme başarıyla girmiş olması, son koşul ürünü ödünç almış olmasıdır. Kullanıcı ödünç alma butonuna tıklar, açılan ekranda parçaları listeler, almak istediğini seçer ve ödünç alır. Alternatif akışlar: ürünün kütüphanede kopyası yoksa rezervasyon yapılır; kullanıcının borcu varsa ödünç alamaz; ödünç alma sınırı aşılıyorsa alamaz; kullanıcı tipi ile ürün türü uyuşmuyorsa alamaz; aynı kitabı daha önce almışsa ikinci kopyasını alamaz.

Kullanım durumu diyagramında üç kullanıcı tipi (öğrenci, öğretim üyesi, memur) kayıt, ödünç alma, iade etme, borç ödeme, bakiye ekleme işlemlerini yapar; bunların alternatif durumları include ve extend ilişkileriyle gösterildi. Sistem yöneticisi parça ekleme ve kısıtları güncelleme işlemlerini yapar.

> **Ek bilgi (derste anlatılmadı):** Kullanım durumu diyagramında `<<include>>`, temel kullanım durumunun her çalıştığında mutlaka yürütülen ortak bir alt davranışı ayırmak için kullanılır (ok, temel durumdan içerilen duruma). `<<extend>>` ise yalnız belirli bir koşul sağlandığında devreye giren isteğe bağlı davranışı gösterir (ok, genişleten durumdan temel duruma).

### 3.5 Sınıf Diyagramı

Grubun ayrıntılı sınıf diyagramı (ekrandan, 00:40:00):

- `<<abstract>> Product`: `id: Integer`, `copy_id: Integer`, `name: String`. Bu sınıfın nesnesi üretilmez; `Book` (`ISBN`, `authors_name`, `book_type`, `book_types[]`), `Magazine` (`ISSN`, `issue_date`) ve `DVD` bu sınıftan kalıtılır.
- `User` (`id`, `name`, `email`, `password`, `user_type`, `user_card: SmartCard`, `user_types[]`) ile `SmartCard` (`card_id`, `balance`, `debt`, `book_count`, `card_type`) arasında 1–1 **kompozisyon** vardır: her kullanıcının bir akıllı kartı olmak zorundadır, çünkü sistemdeki işlemler akıllı kart üzerinden yürür.
- `Borrow` (`user_id`, `product_identifier`, `copy_id`, `product_type`, `start_date`, `return_date`) ve `Reservation` (`user_id`, `product_identifier`, `product_type`, `reservation_date`) ödünç ve rezervasyon bilgisini tutar; ikisi benzerdir, yalnız tarih alanları farklıdır.
- `Database` (`connection`, `dburl`, `user`, `pass`) ve `<<abstract>> Mail`. Database dışındaki ve soyut sınıflar dışındaki sınıflar veri tabanı tablolarını temsil eder.

Sistemin çalışma mantığı: bir ürünle ya da kullanıcıyla ilgili işlem yapılacağında ilgili bilgi veri tabanından çekilir, işlem yapılabiliyorsa o ürünün ya da kişinin nesnesi oluşturulur, işlem bu nesne üzerinden yürütülür ve sonra nesne silinir. Böylece veri tabanının tamamı ya da büyük bir kısmı belleğe yüklenmez. Metotlu ayrıntılı diyagram hazır bir araçla koddan çıkarıldı.

### 3.6 Etkinlik, Durum ve Sıralama Diyagramları

- **Kısıtlama güncelleme etkinlik diyagramı:** Sistem yöneticisi giriş yapar, değiştirmek istediği kuralların yeni değerlerini seçer, "değiştir" butonuna basar ve etkinlik başarıyla biter.
- **Yeni içerik ekleme etkinlik diyagramı:** Yönetici giriş yapar, yeni ürün bilgilerini girer, "ekle" butonuna basar. Bir karar düğümü ürünün ilk kez mi eklendiğini kontrol eder: ürün sistemde varsa bir kopya eklenir, yoksa yeni ürün olarak eklenir.
- **Ödünç ürün alma durum diyagramı:** Kullanıcı kayıt olduktan sonra ürün ödünç alabilir; limitini aşmadıysa ve cezası yoksa aynı durumda kalır. Limit aşılır ya da ceza oluşursa ödünç alamaz duruma geçer; ceza ödenip limit altına inilince (iade ile) tekrar ödünç alabilir duruma döner ya da ilişiğini keser. Ödünç almak istediği ürünün kopyası yoksa rezervasyon durumuna gider.
- **Borç ödeme durum diyagramı:** Geç iade eden kullanıcı "cezası bulunur" durumundadır. Bakiyesi cezasından azsa tamamını ödeyemediği için bu durumda kalır; yeterliyse cezası bulunmaz durumuna geçer. Yeniden geç iade ederse tekrar cezalı duruma döner.
- **Sıralama diyagramları:** Ürün iade etme ve bakiye yükleme için çizildi. Nesnelerin yaşam çizgileri, kendine dönen (refleksif) mesajlar ve etkinliklerin üst üste binmeden sırayla yürümesi gösterildi.

Hoca bu grupta da tasarım kalıbı işaretlenmediğini belirtti.

### 3.7 Birim Testi Örneği

Grup dokuz birim testi yazdı. Hoca, sınıfın büyük kısmı kendi anlattığı örneği dinlemediği için derste bir tane örnek verilmesini istedi. Anlatılan "rezervasyon yapma" testi şöyle çalışır: önce `Database` sınıfı üzerinden bir rezervasyon yapılır; aynı `try` bloğunda bu rezervasyon veri tabanından geri çekilip bir rezervasyon nesnesine atanır. Böylece hem veri tabanında bir rezervasyon, hem de onun nesne kopyası olur. Sonra kullanıcı kimliği, ürün kimliği ve diğer bütün öz nitelikler karşılaştırılır; herhangi bir uyumsuzlukta test geçmez.

Raporda gösterilen başka iki JUnit testinin kodu (ekrandan, 00:45:00):

```java
assertTrue(Database.valid_email(valid_mail));
assertFalse(Database.valid_email(invalid_mail));
```

```java
@Test
void logIn() {
    System.out.println("Login Test Working");
    try {
        assertTrue(db.logIn(test_user_1, false) && db.logIn(test_user_1, true));
        assertFalse(db.logIn(test_user_2, false) || db.logIn(test_user_2, true));
    }
    catch (Exception e) {
        e.printStackTrace();
    }
}
```

Bu kodlar parça koddur, derlenmedi. İkinci testte geçerli kullanıcı her iki giriş türüyle de girebilmeli (`&&`), geçersiz kullanıcı hiçbiriyle girememelidir (`||` ifadesinin yanlış olması).

Modelleme varsayımları: kullanıcı giriş yaparken e-posta mı kart numarası mı kullandığını belirtir; rezerve edilen ürün iade edildiğinde bilgilendirme e-postası gider ve kullanıcının ürünü en kısa sürede alacağı kabul edilir; bakiye borçtan azsa bakiye kadar borç düşülür.

## 4. Üçüncü Kütüphane Bilgi Sistemi Projesi

### 4.1 Proje Alanı ve Kabul-Kısıtlar

Kütüphane iş akışlarını yöneten bilgi sistemini dijital, insan hatasını azaltan ve güvenilir bir sistemle yenilemek istemektedir; üniversitedeki memur, akademisyen ve öğrencilerin akıllı kartlarıyla entegre bir sistem hedeflenir. Kabul ve kısıtlar (ekrandan, 00:50:00):

- Hizmetlerden faydalanmak için akıllı kart sahibi olmak şarttır.
- Yayınlar kitaplar ve dergilerdir; DVD'lerin de eklenmesi düşünülmektedir.
- Kullanıcı statüleri öğrenci, öğretim üyesi ve memur ile sınırlıdır; kütüphaneden hizmet alanların yapabilecekleri statülerine göre belli limitasyonlara tabidir.
- Kütüphanedeki hizmetlerin kaydı ve yönetimi tamamıyla kütüphane binası içindeki kiosklar üzerinden yürütülmelidir (self-servis mantığı).
- Gecikme durumlarının maddi yaptırımı vardır; bu işlemler akıllı kart ve kiosk entegrasyonu ile çalışır.
- Sistemde yönetici yetkisi verilen çalışanlar kısıtlamaları değiştirebilir.
- Müsait olmayan yayınlar için rezervasyon oluşturma işlevi gerçeklenmelidir.

Grubun aktardığı limitler: aynı anda ödünç alınabilecek en fazla yayın sayısı öğrenci için 3, memur için 3, öğretim üyesi için 6 <!-- BELİRSİZ: altyazıda memur yerine bozuk bir kelime geçiyor -->; ders kitapları yalnız öğretim üyelerine verilir; ödünç süresi öğrenci ve memur için 1 ay, öğretim üyesi için 3 ay; gecikmenin her günü için 1 TL ceza akıllı karttan ödenir. Grubun gerçeklemesinde yöneticinin yaptığı limit değişikliği yalnız sonraki ödünç işlemlerini etkiler, aktif ödünç işlemlerini etkilemez; grup bunun sisteme güvenlik kattığını söyledi.

### 4.2 Zaman Çizelgesi, Görev Dağılımı, Risk ve Birim Testi

İş-zaman çizelgesinde açık renkler planlanan, koyu renkler gerçekleşen süreleri gösterdi; süreç yaklaşık bir aya yayıldı: proje alan, risk, kabul ve kısıt tanımları; zaman planlaması; fizibilite; isteklerin modellenmesi; nesneye dayalı modelleme ve tasarım; programlama, veri tabanı ve arayüzün bağlanması; birim testleri ve dokümantasyon.

Risk tablosundan bir örnek: **araçlar** riski, olasılığı çok düşük, etkisi büyük, türü teknik. Kütüphanede sınırlı sayıda kiosk vardır ve arızalanabilir; bu durumda kullanıcılar rezervasyon ve ödünç işlemlerini yapamaz. Önlemler: yedek kiosk bulundurmak ve personeli kiosk arızalarına karşı eğitmek.

Birim testi örneği: giriş yapma testi. Bir yönetici kullanıcı adı ve şifresi verilerek bağlantı sınıfındaki yönetici getirme fonksiyonu çağrılır ve girişin başarılı olup olmadığı kontrol edilir; test olumlu sonuçlandı.

### 4.3 İsteklerin Modellenmesi

Kullanım senaryosu (ödünç alma ve iade):

- **Birincil aktör:** Kütüphane üyesi (öğrenci, akademisyen ya da memur). **Diğer ilgili:** Kütüphane personeli.
- **İlgi alanları:** Üye, işlemlerinin kayıt altında tutulmasıyla hizmetlerden sorunsuz faydalanmak ister. Personel, işlemlerin kayıt altında tutulmasını, izlenmesini ve yönetilmesini, gerektiğinde maksimum ödünç süresi parametresini değiştirebilmeyi ister.
- **Ön koşul:** Üye ödünç almak istediği yayını seçmiştir. **Son koşul:** Üyenin işlemleri hatasız izlenmiş ve sınırlandırmalar uygulanmıştır.
- **Ana senaryo (9 adım):** Üye kioska yönelir; akıllı kartıyla giriş yapar; yayını kioska okutur; kiosk kaydı alır; üye yayını belli süre tutar; son tarihten önce kütüphaneye getirir; kartla giriş yapar; yayını okutur; sistem parçayı üyeden düşer.
- **Alternatif senaryolar:** Ödünç hakkı olmayan üyenin yeni yayın istemesi (gecikmiş ödünç işlemi ya da limit dolu, işlem yapılmaz ve üye bilgilendirilir); yayının başkasında olması (rezervasyon kaydı oluşturulur ve e-posta gönderilir); personelin maksimum ödünç süresini değiştirmesi (değişiklik yalnız o andan sonra başlayan ödünç dönemlerini etkiler); yayının geç getirilmesi (gün başına 1 TL ceza karttan düşülür); geç getirme ve kartta bakiye olmaması (üye personele yönlendirilir, bakiye yüklenir, adımlar tekrarlanır).

**İade etkinlik diyagramı** (ekrandan, 01:00:00):

```text
Kullanıcı akıllı kartı ile sisteme giriş yapar
-> Kullanıcı ödünç almak istediği yayının bilgilerini kioska iletir
-> <Sistem üyenin gecikme durumunu kontrol eder>
   [gecikme yok]
     -> Sistem iade işlemini kaydeder, parça kullanıcıdan düşülür
     -> <Yayın için yapılmış herhangi bir rezervasyonun varlığı kontrol edilir>
        [rezervasyon var] -> Rezervasyon yapan kullanıcı(lar)a e-posta gönderilir -> birleşme
        [rezervasyon yok] -> birleşme
   [gecikme var]
     -> Ceza tutarı hesaplanır
     -> <Kullanıcının akıllı kartında yeterince bakiye olup olmadığı kontrol edilir>
        [yeterli]   -> Tutar kartından düşülür, iade gerçekleşir -> birleşme
        [yetersiz]  -> İade gerçekleşmez, kullanıcı bilgilendirilir ve personele
                       yönlendirilir -> en başa dön
-> [son]
```

İzlenebilirlik tablosunda gereksinimlerin ait olduğu sınıflar gösterildi; örneğin kartla kullanıcı tanıma kullanıcı sınıfına, yayın ödünç alma yayın ve kullanıcı sınıflarına aittir.

### 4.4 Nesneye Dayalı Modelleme ve Tasarım

Sınıf diyagramında dört ana sınıf vardır: yayın, sistem, yönetici ve kullanıcı. Bir sistemin birden fazla yayını, kullanıcısı ve yöneticisi olur; kullanıcı ile yayın, rezervasyon ve ödünç sınıfları üzerinden bağlanır. Kitap, dergi ve DVD yayından; memur, öğretim üyesi ve öğrenci kullanıcıdan kalıtılır. Kullanıcıların belirli sayıda rezervasyon hakkı (0..6) gösterildi.

Ödünç alma sıralama diyagramında önce kullanıcının ihlali olup olmadığı kontrol edilir; ihlal varsa fonksiyon `false` döner ve ödünç verilmez. Sonra yayının müsait adedi alınır; adet yoksa yine `false` döner ve kullanıcıya rezervasyon imkanı sunulur, kullanıcı isterse rezervasyon veri tabanına eklenir. Adet varsa yayın adedi bir azaltılır ve veri tabanında güncellenir.

**Kiosk durum diyagramı:** Kütüphane açılınca kiosk "boşta bekleme" durumundadır. Kart okununca "kart kontrol"e geçer; kart onaylanmazsa tekrar boşta beklemeye, onaylanırsa "işlem bekleme"ye geçer. Kullanıcı ödünç alma ya da iade seçer, ardından parça bekleme durumuna geçilir. Ödünç almada parça mevcudiyeti kontrol edilir: müsaitse ödünç verilir, değilse rezervasyon yapma durumuna geçilir. İadede parça kullanıcıdan düşülür ve teslim süresi geçmişse ceza verme durumuna gidilir.

Birim testlerinde rezervasyon oluşturma ve kitap ekleme fonksiyonlarının `true` döndürüp döndürmediği kontrol edildi.

## 5. Birinci Poliklinik Bilgi Sistemi Projesi

### 5.1 Teknoloji, Organizasyon ve Süreç

Grup beş kişiydi; teknoloji olarak C# ve MySQL kullanıldı, geliştirme Visual Studio'da yapıldı. Görevler arayüz tasarımı ve proje yönetimi, veri tabanı ve SQL sorguları, sistem analizi ve dokümantasyon, uygulama kodu olarak dağıtıldı. Hedef, doktorların ve çalışanların sistemi modüler ve kolay biçimde kullanabilmesi, reçete gibi çıktıların alınması ve ödeme işlemlerinin yapılmasıydı.

**Soru:** Yazılım geliştirme süreç modeliniz neydi? **Cevap:** Grup biraz daha Scrum gibi çalışmaya çalıştığını söyledi; hoca planın şelaleye pek benzemediğini belirtti.

İş-zaman çizelgesi Microsoft Project'te hazırlandı (ekrandan, 01:10:00). Karede görev numaraları görünmüyor; aşağıdaki numaralar, öncüller sütunu ve çizelgedeki bağımlılık oklarıyla tutarlı olacak biçimde büyük olasılıkla 2'den başlar (1 numara görünmeyen bir özet satırı olabilir):

| No | Görev | Süre | Başlangıç | Bitiş | Öncüller |
|---|---|---|---|---|---|
| 2 | Menü ekranının tasarlanması | 4 gün | Paz 18.04.21 | Çar 21.04.21 | |
| 3 | Veri tabanı tablo tanımlamalarının yapılması | 6 gün | Cum 23.04.21 | Cum 30.04.21 | |
| 4 | Kullanım senaryoları ve sınıf diyagramının oluşturulması | 7 gün | Cmt 24.04.21 | Pzt 3.05.21 | |
| 5 | Doktor ekle/sil işlemlerinin kodlanması | 8 gün | Per 22.04.21 | Cmt 1.05.21 | 2 |
| 6 | Doktor güncelleme/görüntüleme işlemlerinin kodlanması | 8 gün | Per 22.04.21 | Cmt 1.05.21 | 2 |
| 7 | Doktor ve hasta işlemleri arayüzünün tasarlanması | 8 gün | Sal 4.05.21 | Per 13.05.21 | |
| 8 | Veri tabanı sorgularının tanımlanması ve veri tabanı diyagramının oluşturulması | 7 gün | Sal 4.05.21 | Çar 12.05.21 | 3 |
| 9 | Sıralama, etkinlik ve durum diyagramlarının tasarlanması | 8 gün | Sal 4.05.21 | Per 13.05.21 | 4 |
| 10 | Rapor ve reçete oluşturma işlemlerinin kodlanması | 8 gün | Pzt 3.05.21 | Çar 12.05.21 | 5 |
| 11 | Hasta güncelleme/görüntüleme ile rapor işlemlerinin kodlanması | 8 gün | Pzt 3.05.21 | Çar 12.05.21 | 6 |
| 12 | Arayüz ile diğer kodların entegre edilmesi | 7 gün | Paz 16.05.21 | Cmt 22.05.21 | 10;11 |

Hoca öncüllerin nasıl verildiğini sordu; grup öncüller kısmına görev numarası yazılınca aracın bağımlılığı çizelgede kendisinin gösterdiğini söyledi.

> **Ders sonrası not:** Tablodaki süreler takvim günüyle örtüşmüyor; örneğin 23.04 Cuma ile 30.04 Cuma arası 8 takvim günüdür ama süre 6 gün yazılmış. Süreler büyük olasılıkla iş günü olarak girilmiştir.

Süreç, menü tasarımıyla başladı; ardından kodlama ve veri tabanı tasarımı paralel ilerledi, belirli aralıklarla toplantılar yapıldı, arayüz parça parça tasarlandı ve en sonda arayüz ile kod entegre edildi.

### 5.2 Kullanım Durumu Diyagramı: include ve extend

Beş temel aktör vardır: kayıt görevlisi (hastayı kaydeder), randevu görevlisi, doktor, yönetici ve veznedar.

- **Yönetici:** Yeni poliklinik ya da klinik eklemekten ve kliniğe doktor eklemekten sorumludur.
- **Randevu görevlisi:** Randevu verir. Randevu vermeden önce sistemi sorguladığı için "randevu verme", "sistem sorgulama"yı **içerir** (include).
- Randevu verildikten sonra hasta kayıt görevlisi tarafından sisteme kaydedildiği için "randevu verme", "hasta kaydı"na include olarak bağlandı.
- **Doktor:** Önce hasta bilgisini sorgular, sonra muayene eder ve hasta bilgisini günceller (yeni tedavi kaydı ekler). Muayene sonunda rapor ya da reçete verilebildiği için bunlar **extend** olarak gösterildi.
- **Veznedar:** Ücret hesaplamadan önce hasta işlemleri sorgulanır (include); ücret kredi kartı ya da nakit olarak tahsil edilir (extend).

### 5.3 Sınıf, Etkinlik, Durum ve Sıralama Diyagramları

Sınıf diyagramı kullanım durumu diyagramlarındaki ve senaryo belgelerindeki kavramlardan çıkarıldı. Bütün doktorlar bir kliniğe bağlı olduğu için doktor ile klinik arasında **birleştirme** (aggregation) kullanıldı. Her hasta için bir hasta kaydı sınıfı vardır ve daha güçlü bir ilişki olduğu için **kompozisyon** ile gösterildi. Randevu sınıfı hasta ile doktoru ilişkilendirir; her randevuda bir doktor ve bir hasta vardır. Ödeme sınıfı ve muayene sonunda verilen muayene belgesi sınıfı da vardır; rapor ve reçete muayene belgesinden **kalıtılır**.

> **Ek bilgi (derste anlatılmadı):** UML'de birleştirme (aggregation, içi boş eşkenar dörtgen) parçanın bütünden bağımsız var olabildiği zayıf bir "sahiplik" ilişkisidir; kompozisyon (composition, içi dolu eşkenar dörtgen) ise parçanın yaşam süresinin bütüne bağlı olduğu güçlü ilişkidir: bütün silinince parça da silinir. Bu projede doktor klinikten ayrılsa da var olmaya devam ettiği için birleştirme, hasta kaydı hasta olmadan anlamsız olduğu için kompozisyon seçildi.

Etkinlik diyagramları:

- **Muayene:** Hasta randevuya gelir; doktor hasta bilgilerini kontrol eder. Bilgiler doğruysa muayene yapılır, değilse işlemden çıkılır. Muayeneden sonra tedavi hasta kaydına eklenir, rapor ya da reçete verilir; sevk durumu varsa sevk kağıdı verilir.
- **Ödeme:** Hasta vezneye gelir, bilgilerini söyler. Kaydı varsa veznedar tedavi ücretini hesaplar ve sigorta durumunu sorgular; sigortası varsa indirim uygulanır, yoksa ücret olduğu gibi alınır.
- **Randevu:** Hasta tarih ve klinik bilgisini söyler; uygun doktor varsa randevu kaydedilir, yoksa alternatif tarihler önerilir; hasta kabul ederse randevu verilir, etmezse çıkılır.

Durum diyagramları:

- **Hasta muayene durumu:** Randevu alınca "bekleme"; randevu tarihi gelince bilgi kontrolü; bilgiler doğrulanınca "muayene"; muayene bitince "ücret ödeme"; yeni randevu alınca tekrar "bekleme".
- **Doktor durumu** (ekrandan, 01:15:00):

```text
[başlangıç] --Doktor polikliniğe alındı--> Boşta
Boşta       --Randevu zamanı geldi-------> Muayenede
Muayenede   --Muayene bitti--------------> Boşta
Boşta       --Doktor poliklinikten ayrıldı--> [son]
```

- **Randevu durumu:** Randevu alınmadı → (tarih bilgisi verilince) randevu önerildi → onaylanmazsa randevu alınmadı ya da işlem iptal; onaylanırsa randevu alındı.
- **Vezne/ödeme durumu:** Boşta/bekleme → hasta gelince ücret hesaplama → kimlik numarası sunucuya gönderilir, SGK kontrolü → indirim hesaplama → ücret alımı → tekrar boşta.

Sıralama diyagramları: Ödemede veznedar "hasta bul" metoduyla hastayı listeden bulur, randevuyu bulur, ücreti hesaplar, hasta kaydından kimlik numarasını alıp SGK sorgulamasıyla indirimi öğrenir ve yeni bir ödeme nesnesi oluşturur. Randevuda istenen klinikteki doktorların listesi alınır, tarihle birlikte randevu aranır, uygun randevu varsa yeni randevu nesnesi oluşturulup listeye eklenir. Son olarak kavramsal sınıf diyagramına metotlar eklenerek tasarım sınıf diyagramı elde edildi.

Veri tabanında dört ana tablo vardır: klinik, doktor, hasta, randevu. Tablolar arasındaki ilişkiler kimlik alanlarıyla kuruldu; hasta tablosunda sigorta sorgusu için kimlik numarası, randevu tablosunda doktor, hasta, tarih, tedavi, ücret ve ödeme durumu tutuldu. Veri tabanı MySQL üzerinde oluşturuldu.

## 6. Medya Takip Bilgi Sistemi Projesi

### 6.1 Alan Tanımı, Kabuller ve Süreç

Sistem, şirket ve şahıs müşterilerine farklı kanal ve medya organlarında yayınlanan haberleri talebe göre izleme olanağı sunar, müşterilere farklı periyotlarda rapor verir ve medyadaki itibarlarını ve bilinirliklerini ölçmek için anket hazırlama imkanı sağlar.

- **Tasarımsal kabul ve kısıtlar:** Şirket ve şahıs müşteriler aynı sınıftadır, aralarındaki fark "müşteri tipi" özelliğiyle belirlenir. Anketler sistem üzerinden anketörler tarafından yapılır, sonuçlar istenirse müşterilere gönderilir. Ayrı bir yönetici sınıfı yoktur; yönetici girişi yapan kişi yönetici işlemlerine erişir ve bu işlemlerin metotları ilgili sınıflarda bulunur (rapor işlemi rapor sınıfında, medya organı işlemi medya organı sınıfında).
- **Sistemsel kabul ve kısıtlar:** JavaScript ile Node.js ortamında geliştirildi, MongoDB kullanıldı.

İş zaman çizelgesi: bir başlangıç toplantısı, bir haftalık proje planlama, ilk sınıf diyagramı, ardından tasarım ve kodun birlikte ilerlemesi. Grup, süreç boyunca tasarımın değişebildiğini ve tasarım ile gerçekleme sırasında değişiklik yapılabildiğini, bu yüzden aslında Scrum'a benzer bir süreç izlediğini söyledi. Organizasyonda planlama, tasarım, kod gerçekleme ve test alanları ve bir proje yöneticisi tanımlandı.

### 6.2 Risk Tablosu

Grubun risk tablosu (ekrandan, 01:25:00):

| Ad | Tip | Olasılık | Etki | Özet |
|---|---|---|---|---|
| Kapasite | Teknik | Orta | Orta | Hizmet sağlayıcı, donanım kısıtlamalarından dolayı sınırlı sayıda müşteriye hizmet verebilmektedir |
| Personel | Ekip | Yüksek | Yüksek | Bazı ekip üyelerinin belirli alanlarda tecrübesizliği ve genel olarak üyeler arasında yeteri kadar iyi iletişim sağlanamaması |
| Sistem gereksinim tanımaları | Proje | Yüksek | Orta - Düşük | Proje ilerledikçe sistem özellikleri ve varsayımlarda fikir ayrılığı ve tanım ve tasarım aşamalarındaki eksiklik ve hataların ortaya çıkmaya başlaması |

### 6.3 Kullanım Senaryoları ve İzlenebilirlik

**Yeni medya organı ekleme senaryosu:** Birincil aktör yöneticidir; ilgililer yönetici ve müşteridir. Yönetici işlemi doğru, hızlı ve kolay yapmak ister; müşteri farklı medya organlarından izlemek istediklerini seçebilmek ister. Ön koşul, izlenecek yeni bir medya organının ortaya çıkması ya da belirli bir medya organının izlenmesine karar verilmesidir. Son koşul, medya organının sisteme kaydedilmesi ve izlenmesidir. Ana senaryoda yönetici giriş yapar, medya organı düzenleme sayfasına geçer, eklemek istediğini belirleyip bilgilerini girer. Alternatif akış: medya organı zaten ekliyse yönetici onu güncelleme ya da silme seçeneğine sahiptir.

**Raporlama senaryosu** (ekrandan, 01:30:00):

- **Kullanım senaryosu:** Raporlama
- **Birincil aktör:** Sistem.
- **İlgililer ve ilgi alanları:** Müşteri: zamanında ve haberlere dair beklentilerinin karşılandığı bir rapor ister.
- **Ön koşullar:** Periyoda göre raporlama zamanı gelmiştir.
- **Son koşullar:** Rapor müşteriye gönderilmiştir.
- **Ana senaryo:** 1. Zamanı geldiğinde sistem medya organlarından ilgili haberleri toplar. 2. Sistem haberleri düzenleyerek raporu oluşturur. 3. Oluşturulan raporu müşteriye gönderir. 4. Müşteri rapora erişebilir.

Bu senaryo, birincil aktörün bir insan değil zamanla tetiklenen sistemin kendisi olabileceğini gösteren bir örnektir. Kullanım durumu diyagramında müşteri, yönetici ve anketör aktörleri vardı; müşteri raporları görüntüleyebilir ve kayıt olurken şahıs ya da şirket müşterisi seçeneklerini kullanır; yönetici anketörlerin iş planlarını düzenleyebilir.

İzlenebilirlik tablosu işlemler ile sınıflar arasındaki ilişkiyi gösterdi. Grup tabloyu ilişkilerin ne kadar karmaşık olduğunu izlemek için kullandığını söyledi: bir işlem çok sayıda sınıfla ilişkiliyse ilişkilerin basitleştirilmesi gerektiği tablodan anlaşılabilir.

### 6.4 Sınıf ve Durum Diyagramları

Dokuz sınıf (ve dokuz tablo) vardır. **Customer** sınıfı kullanıcı adı, e-posta, parola, raporlama tipi ve izlenen medya organlarının kimlik dizisini tutar. Raporlama tipleri standart (günlük, haftalık, aylık) ve özeldir; özel raporlarda kullanıcı örneğin 8 ya da 12 saatte bir gibi kendi periyodunu belirler. **Report** sınıfı müşteri kimliği, oluşturma tarihi ve periyodu tutar. **MediaOrgan** sınıfında metin, fotoğraf, başlık ve tarih içeren medyalar ile radyo, televizyon, gazete gibi medya organı tipleri vardır. Anket isteyen müşteri başlangıç-bitiş tarihini ve soruları belirtir; sistem bu tarihlerde müsait bir anketörü otomatik atar, yoksa hata mesajı döner. Anketör cevapları kendi sayfasından girer, müşteri sonuçları indirir.

**Soru:** İlişkilerin üzerinde çokluk değerleri yok mu? Çok silik çıkmış. **Cevap:** Bu diyagramda yoktu; ilişkiler metotlu diyagramda gösterildi.

Durum diyagramları bir öğrenci tarafından İngilizce anlatıldı. **Müşteri kaydı durum diyagramı** (ekrandan, 01:35:00):

```text
[başlangıç] -> New Account
New Account <-> Verify Account Information
New Account -> determining standard reports
determining standard reports <-> pricing reports
determining standard reports -> Choosing Media Organs
determining standard reports -> determining special reports
determining special reports <-> pricing reports
determining special reports -> Choosing Media Organs
Choosing Media Organs -> Logout -> [son]
```

Periyodik rapor sıralama diyagramında zamanı gelince sistem yeni bir rapor nesnesi oluşturur. Anket oluşturma diyagramında müşteri yeni anket ister, yönetici bir anketör atar; anketörün iş planı anket planına uymuyorsa yönetici yeni anketör ekler, uyuyorsa anket düzenlenip müşteriye gönderilir.

### 6.5 Birim Testleri

Testler JavaScript ile Mocha ve Chai kütüphaneleriyle yazıldı. Önce bir token (belirteç) değeri alınır; bu belirteç ön yüz ile arka yüz arasındaki veri alışverişinde kullanılan bir anahtardır ve sorgularda `Authorization` başlığına konur. Örnekler:

- "get all media organ types" testi, bütün medya organı tiplerini getiren isteğin 200 durum kodu döndürüp döndürmediğini kontrol eder. Grup, kütüphanenin söz diziminin İngilizce konuşma diline çok yakın olduğunu belirtti.
- Müşterileri listeleyen testte gelen her müşteride olması gereken anahtarların bulunup bulunmadığı kontrol edilir (ekrandan, 01:40:00):

```javascript
it('GET All Customers', () => {
  chai
    .request(server)
    .get('/v1.0/customers')
    .set('Authorization', token)
    .end((error, res) => {
      expect(res)
        .body.should.have.property('data')
        .that.includes.all.keys([
          '_id',
          'mediaOrgans',
          'reportingTypeId',
          'customerType',
          'username'
        ]);
    });
});
```

- Tek bir medya organı getirilirken verilen kimliğe karşılık gelen yanıttaki adın beklenen değere eşit olup olmadığı kontrol edildi.

Bu kod parça koddur, çalıştırılmadı.

## 7. İkinci Poliklinik Bilgi Sistemi Projesi

### 7.1 Roller, Kabuller ve Zaman Çizelgesi

Dört kişilik ekipte iki kişi **müşteri iletişim sorumlusu ve sistem analisti** (müşteriyle iletişim, sistem analizi, kullanım öyküleri ve şemaları), iki kişi **sistem ve program tasarımcısı** (kullanım öykülerinden sınıf diyagramları, durum, etkinlik ve sıralama diyagramları ve Java ile gerçekleme) olarak çalıştı.

Varsayılan özelliklere ek kabul ve kısıtlar:

- Yeni bir poliklinik açılabilmesi için o uzmanlık alanında en az 3 yıl deneyimli bir doktorun hastane personeli arasında olması gerekir.
- Yeni doktor işe alınırken uzman olduğu alanda bir poliklinik hastanede bulunmalıdır; yoksa doktor "yardımcı poliklinik"te görevlendirilir.
- Muayene randevusu o anki tarihten en fazla bir ay sonrası için verilir.
- İstenen tarihte boş doktor yoksa sistem sonraki bir ay içinde boş doktor bulunan en yakın tarihi önerir.
- Ödeme nakit ya da kredi kartıyla yapılır; ikisi aynı anda kullanılamaz, parçalı ödeme kabul edilmez.

Grup **şelale** yöntemiyle çalıştı: 6. haftada gereksinimlerin belirlenmesi; 7. haftada organizasyon, risk tablosu, kullanım öyküleri ve şemaları; 8. haftada sınıf modelleri, sıralama, etkinlik ve durum diyagramları; 9. haftada uygulama tasarımı ve birim testleri; 10. haftada eksiklerin giderilmesi; 11. ve 12. haftalarda rapor hazırlama ve teslim.

### 7.2 Risk Tablosu

Risk grubu etmenlerine göre elde edilen alt başlıkların etkileri ve olasılıkları tabloyla, analizleri grafikle yapıldı. Organizasyon etmeninin risk değerleri sistem analistleri öncülüğünde; kullanışlılık ve doğruluk ile araç ve tasarım gibi teknik unsurların risk değerleri sistem ve program tasarımcıları tarafından belirlendi (ekrandan, 01:45:00).

| ID | Risk | Risk Türü | Etki | Olasılık | Önlem |
|---|---|---|---|---|---|
| 1 | Yazılım geliştirme sürecinin planlanan takvime uymaması | Proje | Yüksek | Düşük | Projenin bir adımında planlanandan fazla süre harcanırsa, diğer işlerin süresini olabildiğince azaltmaya çalışarak teslim tarihine uyulması |
| 2 | Proje bütçesinin aşılması | Proje | Orta | Orta | Bütçe belirlerken olası aksaklıklara karşı ek bütçe istenmesi |
| 3 | İş gücü yetersizliği | Proje | Yüksek | Orta | Görevini tamamlayan görevlilerin diğer işlere yardımcı olması |
| 4 | Yazılım gerçekleme sürecinde sistemsel aksaklıklarla karşılaşmak | Teknik | Orta | Orta | Kod üzerinde yapılan her değişikliğin bulut ortamında yedeklenmesi |
| 5 | Veri tabanı güvenliği | Teknik | Yüksek | Düşük | Veri tabanı yedeklemesinin SHA256 şifreleme yöntemiyle yapılması |

> **Ders sonrası not:** SHA-256 bir şifreleme yöntemi değil, tek yönlü bir özet (hash) fonksiyonudur; özetten veri geri elde edilemediği için yedeklerin gizliliği için büyük olasılıkla AES gibi simetrik bir şifreleme algoritması kastedilmelidir. SHA-256 ise yedeğin bütünlüğünü doğrulamak için kullanılabilir.

### 7.3 Kullanım Senaryoları ve Sıralama Diyagramları

**Doktor ekleme:** Birincil aktör yöneticidir; yönetici eklemek istediği doktorun hızlı ve doğru eklenmesini ister, böylece yeni açılacak polikliniklerin işlemleri yavaşlamaz. Ön koşul yöneticinin kimliğinin doğrulanması, son koşul doktorun çalıştığı poliklinik bilgisiyle kaydedilmesidir. Ana öykü: doktor işe alınır, yönetici doktoru sisteme ekler, kimlik numarası, isim ve deneyim bilgilerini ve poliklinik bilgisini girer. Alternatif öykü: doktorun uzmanlık alanında poliklinik yoksa yardımcı polikliniğe eklenir. Sıralama diyagramında bu iki olasılık ayrı dallar olarak gösterildi.

**Poliklinik ekleme:** Hastane yeni poliklinik açma kararı alır; yönetici yeni polikliniği sisteme tanıtır; mevcut doktorlar arasından bir kurucu doktor seçer; uygun uzman doktorları atar; sistem seçilen doktorların görev yaptığı polikliniği günceller; yeni poliklinik ve görevli doktorlar yazdırılır. Alternatif öykü: alanda 3 yıl deneyimli doktor yoksa polikliniğin kurulamayacağını bildiren hata mesajı verilir.

**Randevu alma:** Birincil aktör kayıt görevlisidir; ilgililer kayıt görevlisi ve hastadır. Ön koşul hastanın kayıt görevlisini telefonla araması, son koşul hastanın muayene randevusunu almasıdır. Alternatif öyküler: istenen tarihte boş randevu yoksa sistem boş randevu arayıp önerir ve hasta birini seçer; girilen kimlik numarasıyla kayıtlı hasta yoksa yeni hasta ekleme başlatılır.

Randevu alma sıralama diyagramı (ekrandan, 01:50:00); yaşam çizgileri `kayitGorevlisi:KayitGorevlisi`, `:Hastane`, `:Hasta`:

```text
kayitGorevlisi -> Hastane : *[bulunan_sayi==0] tarih++; randevuSorgula(poliklinik:String, tarih:Date)
Hastane --> kayitGorevlisi : bulunan_sayi
kayitGorevlisi -> Hastane : hastaSorgula(tc:int)
Hastane --> kayitGorevlisi : sonuc
kayitGorevlisi -> Hasta : [sonuc==false] hastaEkle(tc:int, ad:String, soyad:String)
Hasta --> kayitGorevlisi : sonuc
kayitGorevlisi -> kayitGorevlisi : [sonuc==false] uyariVer()
kayitGorevlisi -> Hastane : randevuAl(tc:int, tarih:Date, doktor_sgk:int)
Hastane --> kayitGorevlisi : sonuc
kayitGorevlisi -> kayitGorevlisi : [sonuc==false] uyariVer()
```

İlk mesajdaki yıldız ve koşul bir **döngüyü** gösterir: bulunan randevu sayısı 0 olduğu sürece tarih bir gün ilerletilip yeniden sorgulanır; anlatıma göre bu arama 30 gün boyunca sürer. Sonra hastanın kimlik numarası istenir ve hasta sorgulanır; hasta varsa randevu doğrudan eklenir, yoksa hasta sınıfına gidilerek yeni hasta eklenir ve randevu işlemi yapılır.

**Muayene etme:** Doktor hastayı muayene eder, teşhisi sisteme girer; rapor ya da reçete gibi tanımlı belgelerden birini vermek isterse bu da muayene etme öyküsünün içindedir. **Ödeme:** Veznedar, hasta ve sosyal sigorta sunucusu etkileşir.

Hoca diğer öyküleri dinlemenin yeterli olduğunu söyleyip tasarım kısmına geçilmesini istedi.

### 7.4 Ödeme Durum Diyagramı, İzlenebilirlik ve Sınıf Diyagramı

Ödeme durum diyagramı: kimlik numarası girildikten sonra hasta bilgisini veznedara gösterme durumuna geçilir; son muayenenin ücreti sorgulanır ve gösterilir; sosyal sigorta sunucusundan indirim sorgulanır ve gösterilir; hastaya ücret söylendikten sonra ödeme beklenir; ödeme alınınca fatura kesilip hastaya verilir.

Sınıf düzeyinde izlenebilirlik tablosunun sütunlarında yönetici, doktor, kayıt görevlisi, hasta ve veznedar sınıfları, satırlarında işlemler yer aldı.

Metotlarla zenginleştirilmiş sınıf diyagramında `Personel` sınıfı yönetici, kayıt görevlisi ve veznedarı kapsayacak biçimde düzenlendi; reçete ve rapor gibi işlemler muayeneye bağlı ayrı bir "işlem" sınıfı olarak eklendi. `Hastane` ana sınıftır ve kod da onun üzerinden yürür; `Doktor`, `Poliklinik` ve `Hasta` sınıfları vardır. Metot örnekleri: ödemede "indirim oranı al", "ücret hesapla", "fatura kes"; kayıt görevlisinde "hasta ekle", "randevu sorgula", "randevu al" (hasta sorgulamayı hastane sınıfı üzerinden yapar); yönetici poliklinik sorgulamayı hastane üzerinden yapar; doktorda "hasta bilgisini getir", "hasta bilgisini güncelle", "işlem oluştur".

## Örnek Sorular

**Soru 1** (derste sözlü, 00:12:58): Risk tablonuzda risklerin grubunu ve önlemini yazdınız. Bu riskler için takip (izleme) planınız nasıl olur?

> **Çözüm (derste verilen):** Her risk, kategorisine göre projenin belirli bir aşamasında öne çıkar; risk ortaya çıkmadan önlem almak esastır. Gecikme riski gibi riskler her gün değil, her kilometre taşında o dönemin planına göre gecikme olup olmadığı kontrol edilerek izlenir; hata ve veri kaybı riskleri teslim öncesi testlerde kontrol edilir.

**Soru 2** (derste sözlü, 00:21:25): Sıralama diyagramınızda ya da metotlarınızda bir tasarım kalıbı (design pattern) kullanmayı düşündünüz mü?

> **Çözüm (derste verilmedi):** Derste gruplar kullanmadığını söyledi. Bu projelerde örneğin veri tabanı bağlantısını tutan `Database`/`DBOperations` sınıfı için tek bir örnek oluşturulmasını garanti eden Singleton, ürün türüne göre `Book`/`Magazine`/`DVD` nesnesi üreten Factory Method, rezervasyonu olan kullanıcılara ürün iade edildiğinde bildirim gönderen yapı için Observer kalıbı büyük olasılıkla uygun olurdu.

**Soru 3** (derste sözlü, 00:22:13): İzlenebilirlik tablosu nasıl hazırlanır?

> **Çözüm (derste verilen):** Tablo, hangi işlemde hangi veri tabanı ve uygulama parçalarının etkin olduğunu gösterir. Gruplar satırlarda sınıfları (ya da işlem adımlarını), sütunlarda kullanım senaryolarını yerleştirip bir senaryonun kullandığı her sınıfı işaretledi (bkz. Bölüm 3.3).

**Soru 4** (derste sözlü, 00:26:51): Test gerçekleştirirken yazılımı hazırladığınız dille ilişkili bir birim test oluşturdunuz mu?

> **Çözüm (derste verilen):** Java ile yazılan projede JUnit kullanıldı; diğer gruplarda JavaScript için Mocha ve Chai kullanıldı.

**Soru 5** (derste sözlü, 01:08:20): Yazılım geliştirme süreç modeliniz neydi? Bu zaman çizelgesindeki görevlerin öncülleri nasıl verildi?

> **Çözüm (derste verilen):** Grup Scrum'a benzer çalıştığını söyledi; hoca planın şelaleye benzemediğini belirtti. Öncüller, Microsoft Project'te "Öncüller" sütununa öncül görevin numarası yazılarak verildi.

**Soru 6** (derste sözlü, 01:32:44): Sınıf diyagramınızda ilişkilerin değerleri (çoklukları) görünmüyor; bunlar nerede?

> **Çözüm (derste verilen):** Kavramsal diyagramda yoktu; ilişkiler ve çoklukları metotlu tasarım sınıf diyagramında gösterildi.

## Dersin Toparlaması

Bu oturumda gruplar dönem projelerini derste işlenen yazılım mühendisliği etkinliklerinin sırasıyla sundu: proje planı, kabuller ve kısıtlar, fizibilite, süreç modeli seçimi, Gantt çizelgesi, maliyet, organizasyon şeması, risk tablosu, kullanım senaryoları, kullanım durumu diyagramı, izlenebilirlik tablosu, sınıf, etkinlik, durum ve sıralama diyagramları ve birim testleri. Aynı problemi (kütüphane bilgi sistemi) üç farklı grubun nasıl modellediği, aynı gereksinimlerden farklı sınıf yapılarına (ayrı alt sınıflar ya da tek sınıfta tip alanı), farklı izlenebilirlik tablosu yorumlarına ve farklı süreç modeli seçimlerine varılabileceğini gösterdi.

Hocanın sorularıyla öne çıkan noktalar şunlardır: risklere yalnız önlem yazmak değil, kilometre taşlarında izlemek gerekir; tasarım aşamasında hazır tasarım kalıpları düşünülmelidir; izlenebilirlik tablosu işlemleri etkilenen bileşenlere bağlamalıdır; birim testleri kullanılan dile uygun bir test çerçevesiyle yazılmalıdır; sınıf diyagramlarında ilişki çoklukları açıkça görünmelidir. Hoca bir sonraki derste konuların tekrarını yapacağını ve bazı konulara eklemeler yapacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
