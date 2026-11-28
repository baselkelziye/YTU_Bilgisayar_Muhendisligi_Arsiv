# Ders 11 Çalışma Özeti

## Genel Konular

- Dönem projesi sunumları ve sunumların genel yapısı
  - Bu ders, öğrenci gruplarının dönem projelerini sunduğu bir oturumdur. Üç grup kütüphane bilgi sistemi, iki grup poliklinik bilgi sistemi, bir grup da medya takip bilgi sistemi sundu.
  - Sunumlar aynı iskeleti izledi: proje alan tanımı, kabuller ve kısıtlar, yazılım geliştirme süreç modeli seçimi, fizibilite, iş-zaman çizelgesi (Gantt), ekip organizasyon şeması, risk tablosu, kullanım senaryoları ve kullanım durumu diyagramı, izlenebilirlik tablosu, sınıf diyagramı (kavramsal ve metotlu), etkinlik, durum ve sıralama diyagramları, birim testleri.
  - Hoca bu derste projelerin yalnız modelleme ve proje yönetimi kısımlarını inceledi; kod ve çalışan modül kısmı ayrı bir oturuma bırakıldı.
- Proje planı: kapsam, kabuller, kısıtlar ve fizibilite
  - Kütüphane projesinde müşteri ihtiyaçları maddelendi: genişletilebilir envanter kategorileri, yönetici/öğrenci/memur/öğretim üyesi kullanıcı sınıfları, sınıfa göre değiştirilebilir ödünç alma kuralları, gecikme cezasının kullanıcı bakiyesinden düşülmesi, başkasındaki ürüne rezervasyon ve iade bildirimi, e-posta ile bildirim (ekrandan, 00:05:00).
  - Kabuller örnekleri: açık kaynak ve dosya tabanlı veri tabanı, sistem yöneticisinin kütüphane çalışanı olması, 100 bin ürün ve 5 bin kullanıcıya kadar her işlemin 5 saniyenin altında kalması, veri girişinin geliştirmeyle eş zamanlı yapılması, giriş ve para yükleme için kimlik kartı kullanılması.
  - Kapsam, plandaki ve müşteriyle belirlenen ihtiyaçlardan çıkarılan kullanıcı hikayeleriyle sınırlandırıldı. Fayda tanımında personelin iş yükünün önemli bir kısmından kurtulması hedeflendi.
  - Kısıtlar: zaman (teslim tarihi), bütçe ve ekip büyüklüğü. Genel kabuller: insan kaynağında azalma olmaması, proje başladıktan sonra müşteriden yeni istek gelmemesi, toplantılara herkesin katılması.
  - Fizibilite: teknik (arayüz için JavaFX, e-posta için JavaMail, PostgreSQL; başka gruplarda C# + MySQL, Node.js + MongoDB, Java + MySQL), donanım, yasal (kullanıcı bilgilerinin güvenliği ve kötüye kullanılmaması) ve ekonomik fizibilite.
- Yazılım geliştirme süreç modeli seçimi
  - Bir grup, ürünün önceki projelere benzemesi, karmaşıklığın düşük ve sürenin kısa olması nedeniyle şelale modelini seçti.
  - Başka bir grup tasarımı kodla birlikte değiştirerek ilerlediği için çalışmasını Scrum'a benzetti; hoca da bir grubun planının şelaleye benzemediğini belirterek süreç modelini sordu.
- Proje zaman planı ve maliyet
  - Gantt çizelgelerinde planlanan ve gerçekleşen süreler ayrı gösterildi; adımlar: proje planı (alan, risk, kabul, kısıt), zaman planı ve fizibilite, isteklerin modellenmesi, nesneye dayalı modelleme ve tasarım, programlama, birim testleri ve dokümantasyon.
  - Bir grubun çizelgesi Microsoft Project'te hazırlandı; her görevin süresi, başlangıç-bitiş tarihi ve öncül görev numarası (Öncüller sütunu) yazıldı (ekrandan, 01:10:00).
  - Maliyet kalemleri: işçilik (bir grupta 26 günlük süre için 2600 dolar), yazılım lisansları, kiosk donanımı, çalışan masrafları, risk ve genel gider payları ve %20 kâr; toplam 3900 dolar.
- Ekip organizasyonu ve roller
  - Ürün sahibi müşteri istekleriyle ekip arasında köprü kurar, kullanıcı senaryolarını önceliklendirir ve doğru işlendiğini kontrol eder.
  - Proje yöneticisi görevlerin sırasını ve koordinasyonu yönetir; geliştiriciler kodlamayı, kalite güvence uzmanı hangi birim testlerinin yapılacağını belirler (ekrandan, 00:10:00).
  - Bir grupta müşteri iletişim sorumlusu ve sistem analisti ile sistem ve program tasarımcısı rolleri ayrıldı.
- Risk yönetimi
  - Risk tablolarında risk adı, kategorisi/türü (proje, teknik, ekip), olasılığı, etkisi ve önlemi yer aldı. Olasılık ile etki çarpılarak riskin önemi bulundu.
  - Örnek riskler: ekibin önerilenden az kişiyle kurulması, kiosk arızası, kapasite (donanım kısıtları nedeniyle sınırlı müşteriye hizmet), personelin bazı alanlarda tecrübesizliği ve iletişim eksikliği, gereksinimlerde fikir ayrılığı, bütçenin aşılması, veri tabanı güvenliği (ekrandan, 01:25:00; ekrandan, 01:45:00).
  - Bir grup risk bilgi sayfası hazırladı: risk, işaretleri ve önlemleri.
- İsteklerin modellenmesi: kullanım senaryoları ve kullanım durumu diyagramı
  - Kullanım senaryosu metni: birincil aktör, ilgililer ve ilgi alanları, ön koşullar, son koşullar, ana senaryo (adımlar) ve alternatif akışlar.
  - Kütüphane örneği (parça ödünç alma): kullanıcı kartla giriş yapar, barkodu taratır, onaylar, fiş alır. Alternatif akışlar: kart tanınmaz, barkod geçersiz, kullanıcının borcu var, ödünç alma limiti aşılır, ders kitabı türündeki parçayı öğretim üyesi olmayan biri ister, kullanıcı onaylamaz.
  - Poliklinik kullanım durumu diyagramında randevu verme sistem sorgulamayı, hasta kaydı randevu vermeyi içerir (include); muayenede rapor veya reçete, ödemede kredi kartı veya nakit isteğe bağlıdır (extend).
  - Medya takip örneğinde birincil aktörü "sistem" olan zaman tetiklemeli bir raporlama senaryosu yazıldı (ekrandan, 01:30:00).
- İzlenebilirlik tablosu
  - Gruplar sınıf düzeyinde izlenebilirlik tablosu hazırladı: satırlarda sınıflar, sütunlarda kullanım senaryoları (işlemler); bir senaryonun kullandığı sınıflar işaretlenir (ekrandan, 00:35:00).
  - Bir grup tabloyu her işlemin hangi adımları/koşulları gerektirdiğini göstermek için kullandı; başka bir grup ilişkilerin aşırı karmaşıklaşıp karmaşıklaşmadığını izlemek için kullandı.
- Nesneye dayalı modelleme ve tasarım diyagramları
  - Sınıf diyagramları: kalıtım (Person'dan Officer/Student/Teacher; soyut Product'tan Book/Magazine/DVD), kompozisyon (User–SmartCard), birleştirme (Doktor–Klinik), ilişki sınıfları (Relation, Borrow, Reservation, Randevu) (ekrandan, 00:15:00; ekrandan, 00:40:00).
  - Durum diyagramları: kütüphane kullanıcısı (Ödünç Alabilir / Ödünç Alamaz), parça (ödünç alınabilir / alınamaz, rezervasyon), kiosk, doktor (Boşta / Muayenede), randevu ve vezne durumları (ekrandan, 00:20:00; ekrandan, 01:15:00).
  - Etkinlik diyagramları: ödünç alma, iade (gecikme cezası, bakiye kontrolü, rezervasyon bildirimi), muayene, ödeme, randevu (ekrandan, 01:00:00).
  - Sıralama diyagramları: ödünç alma ve iade, ödeme (SGK sorgulama ve indirim), randevu alma (bulunan randevu sayısı 0 iken tarihi ilerleten döngü) (ekrandan, 01:50:00).
- Birim testleri
  - Kütüphane grubu 10 test yöntemi listeledi: yeni kullanıcı ekleme, aynı kimlik numarasıyla kullanıcı ekleme, yeni parça ekleme, limit üzerinde parça verme, iade sonrası eldeki parça sayısı ve stok, limitlerin güncellenmesi, bakiye yükleme, öğretim üyesi dışındakine ders kitabı verme (ekrandan, 00:25:00).
  - Kullanılan araçlar: Java için JUnit, JavaScript için Mocha ve Chai; testler "assertTrue/assertFalse" ya da beklenen HTTP durum kodu ve yanıt anahtarlarının kontrolüyle yazıldı (ekrandan, 00:45:00; ekrandan, 01:40:00).
  - Testlerde boş olmayan, gerçekçi örnek veri kümeleriyle çalışmanın önemi vurgulandı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Risklerin izlenmesi
  - Risk tablosunda önlem yazmak yeterli değildir; risklerin nasıl izleneceği de planlanmalıdır. Hoca, örneğin gecikme riskinin her kilometre taşında (milestone) "gecikme var mı" diye kontrol edilmesi gerektiğini belirtti.
- Tasarımda tasarım kalıplarının düşünülmesi
  - Hoca iki gruba da sıralama diyagramlarında ya da metotlarda bir tasarım kalıbı (design pattern) kullanıp kullanmadıklarını sordu; gruplar kullanmadığını söyledi. Tasarım aşamasında hazır kalıpların düşünülmesi bekleniyor.
- İzlenebilirlik tablosunun anlamı
  - Tablo, hangi işlemin hangi veri tabanı ve uygulama parçalarını etkilediğini göstermelidir.
- Birim testinin kullanılan programlama diline uygun bir test çerçevesiyle yazılması
  - Hoca grupların yazılım dilleriyle ilişkili bir birim test aracı kullanıp kullanmadığını sordu.
- Sınıf diyagramında ilişki çoklukları
  - İlişkilerin üzerinde çokluk değerleri görünmelidir; hoca silik çıkan bir diyagramda bunları sordu.

## Kısa Tekrar Notları

- Proje planı: alan tanımı, kapsam, kabuller, kısıtlar, fizibilite (teknik, donanım, yasal, ekonomik).
- Süreç modeli seçimi gerekçelendirilmeli: benzer, az karmaşık, kısa proje için şelale; değişken tasarım için çevik/Scrum.
- Gantt çizelgesinde görev, süre, başlangıç-bitiş ve öncül görevler yer alır; planlanan ve gerçekleşen ayrı gösterilebilir.
- Risk tablosu: ad, tür, olasılık, etki, önem (olasılık × etki), önlem; ayrıca izleme planı.
- Kullanım senaryosu: birincil aktör, ilgililer, ön ve son koşul, ana senaryo, alternatif akışlar.
- Include: her zaman yapılan ortak alt işlem; extend: isteğe bağlı genişleme.
- İzlenebilirlik tablosu: senaryolar ile sınıflar (ya da işlemler ile bileşenler) arasındaki bağlantı.
- Kompozisyon güçlü parça-bütün ilişkisi; birleştirme (aggregation) daha zayıf ilişkidir.
- Birim testleri dile uygun çerçeveyle (JUnit, Mocha/Chai) ve gerçekçi verilerle yazılır.

## Detaylı Açıklamalar

- Kütüphane bilgi sistemi projeleri
  - Ortak alan: akıllı kart sahibi kullanıcılar (öğrenci, öğretim üyesi, memur) kiosklar üzerinden self-servis ödünç alma ve iade yapar. Yayınlar kitap ve dergidir, DVD sonradan eklenebilir. Bir grubun aktardığı kurallarda aynı anda alınabilecek en fazla yayın sayısı öğrenci ve memur için 3, öğretim üyesi için 6 <!-- BELİRSİZ: altyazıda memur yerine bozuk bir kelime var -->; ödünç süresi öğrenci ve memur için 1 ay, öğretim üyesi için 3 ay; ders kitapları yalnız öğretim üyelerine verilir; gecikmenin her günü için 1 TL ceza akıllı karttan düşülür (ekrandan, 00:50:00).
  - Yöneticinin limitleri değiştirmesi yalnız sonraki ödünç işlemlerini etkiler, o anki aktif işlemleri etkilemez.
  - Kullanıcı durum diyagramı (ekrandan, 00:20:00): kayıt olunca "Ödünç Alabilir"e geçilir. "Ödünç Alma [ödünç alma limiti aşılmadı AND ceza limiti aşılmadı]" kendine döner; "Ödünç Alma [ödünç alma limiti aşıldı OR ceza limiti aşıldı]" ile "Ödünç Alamaz"a geçilir. "İade [ödünç alma limiti altına düşüldü AND ceza limiti aşılmadı]" ya da "Ceza Ödendi [ceza limiti altına düşüldü AND ödünç alma limiti aşılmadı]" ile geri dönülür. Kullanıcı sistemden ayrılınca son duruma gidilir.
  - Bir grubun ilk sınıf diyagramı: SmartCard–User (1–1), Relation–User ve Relation–Item (1–1), User–Library (*–1), Item–Library (*–1), Library–DBOperations (1–1); ayrıca Person'dan kalıtılan Officer, Student, Teacher (ekrandan, 00:15:00). Grup sonra bu alt sınıfları boş bırakıp kullanıcı türünü akıllı karttaki bir "type" alanıyla tuttu.
  - Başka bir grubun sınıf diyagramında soyut Product (id, copy_id, name) sınıfından Book, Magazine, DVD kalıtılır; Database sınıfı Admin, User, SmartCard, Borrow, Reservation ve Mail sınıflarını kullanır; User–SmartCard arasında kompozisyon vardır (ekrandan, 00:40:00). Sistem, işlem sırasında gerekli kaydı veri tabanından çekip nesne oluşturur, işlem bitince nesneyi siler; böylece tüm veri belleğe yüklenmez.
  - Borç ödeme senaryosu: bakiye borçtan azsa bakiye kadar borç ödenir.
- Poliklinik bilgi sistemi projeleri
  - Aktörler: kayıt görevlisi, randevu görevlisi, doktor, yönetici, veznedar. Ek kabuller: yeni poliklinik için alanında en az 3 yıl deneyimli bir doktor gerekir; uygun poliklinik yoksa doktor "yardımcı poliklinik"e atanır; randevu en fazla bir ay sonrası için verilir; boş doktor yoksa sonraki bir ay içindeki en yakın tarih önerilir; ödeme nakit ya da kredi kartıyla yapılır, parçalı ödeme yoktur.
  - Sınıf diyagramında doktor–klinik birleştirme (aggregation), hasta–hasta kaydı kompozisyon; randevu sınıfı bir doktor ve bir hastayı bağlar; muayene belgesinden rapor ve reçete kalıtılır.
  - Randevu sıralama diyagramı (ekrandan, 01:50:00): kayıt görevlisi `*[bulunan_sayi==0] tarih++; randevuSorgula(poliklinik, tarih)` döngüsüyle randevu arar, `hastaSorgula(tc)` ile hastayı sorgular, sonuç yoksa `hastaEkle(tc, ad, soyad)` çağrılır, sonra `randevuAl(tc, tarih, doktor_sgk)`; başarısızlıkta `uyariVer()`.
  - Doktor durum diyagramı (ekrandan, 01:15:00): "Doktor polikliniğe alındı" ile Boşta; "Randevu zamanı geldi" ile Muayenede; "Muayene bitti" ile Boşta; "Doktor poliklinikten ayrıldı" ile son durum.
- Medya takip bilgi sistemi projesi
  - Şirket ve şahıs müşterileri aynı sınıfta, müşteri tipi özelliğiyle ayrılır; ayrı yönetici sınıfı yoktur, yönetici işlemleri ilgili sınıflardadır. Raporlama tipleri standart (günlük, haftalık, aylık) ve özel (kullanıcının belirlediği periyot) olabilir. Anket oluşturulurken uygun bir anketör otomatik atanır, yoksa hata döner.
  - Birim testlerinde önce bir yetkilendirme belirteci (token) alınır, sonra uç noktalara istek atılıp durum kodu (200) ve yanıt anahtarları kontrol edilir (ekrandan, 01:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
