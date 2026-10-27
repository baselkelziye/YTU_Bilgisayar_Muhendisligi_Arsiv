# Ders 14 Çalışma Özeti

## Genel Konular

- Kayıt 31 Mayıs 2023 Çarşamba günü online yapılan derse ait, yaklaşık 2 saat 54 dakika sürüyor.
- Ders, dönem projesi sunumlarının ikinci ve son günü. Önceki hafta sunmayan bütün gruplar sundu; on grup kadar sunum var. Konu anlatımı yok.
- Projeler yine üç vaka üzerine: yazılım evinin insan kaynakları sistemi, medya takip şirketi bilgi sistemi ve seyahat acentesi bilet/tatil sistemi.
- Sunumlarda proje planı, risk tablosu, use case diyagramı ve senaryo belgesi, izlenebilirlik tablosu, kavramsal ve tasarım sınıf diyagramları, sıralama, etkinlik ve durum diyagramları, tasarım kalıpları ve birim testleri anlatıldı.
- Hoca sunumlarda tekrar eden alan tanımlarını geçtirdi ve sorularını kavramlar üzerine yoğunlaştırdı. Bu özet hocanın sorularını ve geri bildirimlerini adsız olarak toplar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Alan tanımı herkes için aynı olduğundan yalnızca **gruba özgü** kabul ve kısıtlar anlatılmalı. Kabuller ve kısıtlar ayrı başlıklarda yazılmalı.
- Her grupta hangi **süreç modelinin** seçildiği soruldu. Çevik (agile) model seçildiyse Gantt diyagramında Scrum'daki sprintler, yani parça parça ilerleyen bölümler görünmeli. Şelale gibi "analiz bitti, tasarım başladı" düzeni çevik model değildir.
- Gantt diyagramında **milestone**'lar gösterilmeli: işin belli bir noktaya geldiği ve toplantı/değerlendirme yapılan yerler.
- Risk tablosunda **önlem** sütunu da olmalı. Önem derecesi olasılık ile etkinin çarpımından çıkar.
- Riskler **projenize özgü** yazılmalı. Bir dönem projesi için elektrik kesintisi veya genel veri güvenliği yerine "ekipten birinin dersi bırakması" ya da "bir üyenin bilgi eksikliği" gibi riskler daha anlamlıdır.
- Kavramsal sınıf diyagramı ile tasarım sınıf diyagramı farklı aşamalarda kullanılır. Hoca birçok gruba bunu sordu.
- **Etkinlik diyagramının amacı:** etkinliğin akışını, sırasını ve koşullarını göstermek. Özellikle farklı ortamlarda (kişi, birim) yürüyen paralel akışların nerede ayrılıp nerede birleştiğini göstermek için kullanılır.
- Use case diyagramında `include` ve `extend` oklarının **yönü** farklıdır.
- Tasarımda bir tasarım kalıbı (design pattern) kullanılıp kullanılmadığı soruldu.
- Sunum yapmayan veya programını asistana gösteremeyen gruplar asistana tekrar e-posta atmalı; onlara ayrıca zaman verilecek.

## Kısa Tekrar Notları

- **Kavramsal sınıf diyagramı:** analiz aşamasında, alan kavramlarını ve ilişkilerini gösterir; metotlar genellikle yoktur.
- **Tasarım sınıf diyagramı:** tasarım aşamasında, metotlar, görünürlük, tipler ve tasarım kalıplarıyla tamamlanmış hâli.
- **include:** temel use case dahil edilen use case'i her zaman çağırır. Ok temel use case'den dahil edilene doğrudur.
- **extend:** genişleten use case yalnızca belli bir koşulda temel use case'e eklenir. Ok genişletenden temel use case'e doğrudur.
- **Etkinlik diyagramı:** akış, koşullar (karar düğümleri), paralel akışlar (fork/join), ortamlar/sorumlular (kulvar, swimlane).
- **Durum diyagramı:** tek bir nesnenin (ör. personel aktif/pasif, proje aktif/pasif, bilet istendi/uygun/rezerve/ödendi) durumları ve geçişleri.
- **Gruplarda kullanılan tasarım kalıpları ve mimariler:** Singleton (veritabanı bağlantısı), DAO (veri erişim katmanı) ve servis katmanı, MVC ile Observer (arayüz), Builder (model nesnesi üretimi), Factory (çalışan alt sınıflarının üretimi), controller-service-repository katmanları.
- **Birim testi araçları:** JUnit ve Mockito (Java), GoogleTest (C++), PyTest (Python).

## Detaylı Açıklamalar

### Proje planı ve risk geri bildirimleri

- Bir grup risk tablosuna önlem eklememişti. Hoca önlemin de tabloda olması gerektiğini, önem derecesinin olasılık ve etkinin çarpımı olduğunu hatırlattı.
- Bir grup elektrik kesintisi, veri güvenliği gibi genel riskler yazmıştı. Hoca bunların bir dönem projesini doğrudan ilgilendirmediğini, riskleri ekibe ve projeye mal etmeleri gerektiğini söyledi.
- Gruplardan biri riskleri kullanıcı kaynaklı (gereksinimlerin sürekli değişmesi, kullanıcının ilgisizliği), teknik (gerçekçi olmayan plan, yanlış arayüz, gereksiz özellikler) ve personel kaynaklı (kilit personel yetenekleri, uygun olmayan yöntem, zayıf proje yönetimi) diye gruplamıştı.
- Bir grup bütçe aşımını iki kademede değerlendirdi: %20'ye kadar aşım olasılığı yüksek ama etkisi düşük; %20'yi aşan aşımın olasılığı düşük ama etkisi büyük.
- Bir grupta Gantt diyagramında milestone yoktu. Hoca milestone'u "özelliğin belli bir yere gelmesi ve toplantıların yapılması" diye açıkladı.

### Analiz geri bildirimleri

- Hoca birkaç gruba use case belgesini (açıklamalı kullanım senaryosu dokümanı) sordu. Yalnızca diyagram göstermek yetmez; her use case'in metin tanımı da olmalı.
- Bir grubun diyagramında `include` ve `extend` okları aynı yöndeydi. Hoca sınıfa okların yönünün önemli olup olmadığını sordu; grup hatayı kabul etti.
- İzlenebilirlik tablolarında gereksinimler ile bunları gerçekleyen sınıflar veya modüller eşleştirildi.

### Tasarım geri bildirimleri

- Bir grup kavramsal sınıf diyagramına yanlışlıkla "tasarım sınıf diyagramı" başlığı yazmıştı. Hoca sorunca grup düzeltti.
- Hoca bir gruba, gösterdikleri iki sınıf diyagramından hangisinin hangi aşamada kullanıldığını sordu.
- Etkinlik diyagramı soruları: bir grubun ortam (kulvar) ayrımı yoktu. Hoca hangi işin hangi ortamda yapıldığının da gösterilmesi gerektiğini söyledi.
- Tasarım kalıbı kullananlar:
  - Bir grup veritabanı bağlantısı için Singleton, veri erişimi için DAO ve araya bir servis katmanı kullandı. Servis katmanı testleri ve bakımı kolaylaştırıyor. Arayüzde MVC ve Observer kullanıldı.
  - Bir grup Spring tabanlı backend'de controller-service-repository katmanlarını ve model nesneleri için Builder kalıbını kullandı.
  - Bir grup çalışan alt sınıflarını (programcı, analist, tasarımcı, yönetici) üretmek için Factory kalıbına benzer bir yapı kurdu.
  - Bazı gruplar hiç kalıp kullanmamıştı.

### Test geri bildirimleri

- Gruplar birim testlerini kişi başına iki test olacak şekilde bölüştürdü. Testler hepsi birden çalıştırılıp başarı sonuçları gösterildi.
- Bir grup dış bağımlılıkları sahte nesnelerle (mock) değiştirerek yalnızca ilgili metodu test etti. Örneğin bir rapor talebi oluşturulduğunda repository'nin `save` metodunun tam bir kez çağrıldığını doğruladı.
- Bir grup veritabanını bozmamak için test sırasında oluşturduğu kayıtları test sonunda sildi.
- İki grup birim testlerini yetiştiremediğini söyledi.

### Duyurular

- Programını asistana göstermeyen bir grup vardı. Hoca asistanla konuştuğunu ve gruba tekrar e-posta atmasını, kendilerine zaman verileceğini söyledi.
- Diğer şubeden olup bu gruplarda yer alan öğrencilerin bunu belirtmesi istendi; hoca onları ayrıca işaretledi.
- Ders, sınavlarda başarı dileğiyle kapandı.

### Ders sonrası notlar

- Bir öğrenci önce kavramsal sınıf diyagramının tasarım aşamasında, tasarım sınıf diyagramının analiz aşamasında kullanıldığını söyledi. Doğrusu tersidir: kavramsal sınıf diyagramı analizde, tasarım sınıf diyagramı tasarımda kullanılır.
- Bir öğrenci extend için "ana use case'den başka bir use case'e" dedi. UML'de extend oku genişleten (isteğe bağlı) use case'den temel use case'e çizilir. Include oku ise temel use case'den dahil edilen use case'e çizilir. Her iki ok da kesikli çizgiyle ve `<<include>>` / `<<extend>>` etiketiyle gösterilir.
- Bir öğrenci etkinlik diyagramını "her bir durum için kullanım durumları" diye tanımladı. Bu tanım yanlıştır; etkinlik diyagramı bir sürecin akışını ve paralel kollarını gösterir.
- Bir grup "PyTest'te Mockito gibi bir yapı yok, bu yüzden testler gerçek veritabanıyla çalıştı" dedi. Python'da `unittest.mock` modülü ve `pytest-mock` eklentisi aynı işi görür; veritabanı bağımlılığı mock'lanarak testler gerçek veriden bağımsız yapılabilir.
- Bir grup controller-service-repository katmanları arasındaki ilişkiyi bileşim (composition) olarak çizdi. Bu katmanlar genellikle bağımlılık enjeksiyonuyla (dependency injection) birbirine verilir; servis repository'nin yaşam döngüsünün sahibi değildir. Bu yüzden ilişki ya da bağımlılık olarak gösterilmesi daha doğrudur.
- Altyazıdaki "Ecail" agile, "artificial/ardışıl diagram" sıralama diyagramı, "Malston" milestone demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
