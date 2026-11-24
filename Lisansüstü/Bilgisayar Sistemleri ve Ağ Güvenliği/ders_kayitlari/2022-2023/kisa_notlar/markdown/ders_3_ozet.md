# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin yönetimsel bölümünün yapısı
  - Ders üç ana bölümden oluşur: bilgisayar sistemleri güvenliğinin yönetimsel konuları, açık anahtarlı şifreleme ile mesaj ve bilgi güvenliği, güvenlik protokolleri.
  - "Yönetim Sorunları" bölümü altı alt başlık içerir (ekrandan, 00:05:00): BT güvenlik yönetimi ve risk değerlendirmesi; BT güvenlik kontrolleri, planları ve prosedürleri; fiziksel ve altyapı güvenliği; insan kaynakları güvenliği; güvenlik denetimi; bilişim güvenliğinde yasal ve etik hususlar.
  - Bu dersin konusu ilk alt başlıktır: BT güvenlik yönetimi ve risk değerlendirmesi.
- BT güvenlik yönetimine genel bakış
  - Güvenlik yönetimi üç soruyu cevaplama sürecidir (ekrandan, 00:10:00): Hangi varlıkların korunması gerekir? Bu varlıklar nasıl tehdit ediliyor? Bu tehditlere karşı ne yapılabilir?
  - Amaç, kritik varlıkların uygun maliyetle yeterince korunmasıdır. Koruma gerektiren her varlık için güvenlik riski değerlendirmesi yapılır.
  - Süreç, riskleri azaltmak için hangi yönetimsel, operasyonel ve teknik kontrollerin gerektiğine karar vermek için bilgi sağlar.
- ISO/IEC 27000 standart ailesi
  - 27000: bilgi güvenliği yönetim sistemlerine (BGYS) genel bakış ve terimler.
  - 27001: BGYS gereksinimleri (kurma, uygulama, işletme, izleme, gözden geçirme, sürdürme, iyileştirme).
  - 27002: bilgi güvenliği yönetimi uygulama kuralları; eski adı ISO 17799.
  - 27003: BGYS uygulama kılavuzu.
  - 27004: BGYS süreç ve kontrollerinin etkinliğini ölçme ve raporlama rehberi.
  - 27005: bilgi güvenliği risk yönetimi; ISO 13335'in 3. ve 4. bölümlerinin yerini aldı.
  - 27006: BGYS denetimi ve belgelendirmesi yapan kuruluşlar için gereklilikler.
- BT güvenlik yönetiminin tanımı ve işlevleri
  - Tanım (ekrandan, 00:15:00): uygun düzeyde gizlilik, bütünlük, kullanılabilirlik, hesap verebilirlik, özgünlük ve güvenilirlik elde etmek ve sürdürmek için kullanılan bir süreçtir.
  - İşlevler: kurumsal hedef, strateji ve politikaları belirlemek; kurumsal güvenlik gereksinimlerini belirlemek; BT varlıklarına yönelik tehditleri belirleyip analiz etmek; riskleri belirleyip analiz etmek; uygun önlemleri belirtmek; önlemlerin uygulanmasını ve işleyişini izlemek; güvenlik farkındalık programı geliştirip uygulamak; olayları algılamak ve tepki vermek.
  - Güvenlik yönetimi yukarıdan aşağıya (top-down) işler; girdisi kurumsal güvenlik politikaları ve organizasyonel bağlamdır.
  - Analiz seçeneklerinden biri seçilir, önlemler gerçeklenir, sonra bakım, değişim yönetimi ve olay müdahalesi gelir.
  - Planla, uygula, kontrol et, önlem al biçiminde sürekli dönen bir çevrim vardır.
- Kurumsal bağlamda güvenlik politikası
  - Politika düzenli olarak sürdürülür ve güncellenir: periyodik güvenlik incelemeleri yapılır, değişen teknik ve risk ortamı yansıtılır (ekrandan, 00:20:00).
  - Önce kuruluşun BT güvenliği incelenir: hedefler (istenen sonuçlar), stratejiler (hedeflere nasıl ulaşılır), politikalar (yapılması gerekenler).
  - Politikanın ele alması gerekenler: amaç ve kapsam (iş, yasal ve düzenleyici gereklilikler dahil), gereksinimler, sorumluluklar, risk yönetimi yaklaşımı, farkındalık ve eğitim, personel konuları ve yasal yaptırımlar, güvenliğin sistem geliştirmeye entegrasyonu, bilgilerin sınıflandırılması, acil durum ve iş sürekliliği planlaması, olay algılama ve işleme, politikanın gözden geçirilmesi.
  - Politika üst yönetim tarafından desteklenmelidir.
- Risk değerlendirmesi yaklaşımları
  - Temel (baseline), gayri resmi (informal), ayrıntılı (detaylı, formal) risk analizi ve bütünleşik (combined) yaklaşım.
- Risk değerlendirme süreci
  - Adımlar (ekrandan, 00:45:00): değerlendirmeye hazırlık, risk analizi (tehdit kaynakları ve olaylar, güvenlik açıkları, olasılık, etki büyüklüğü, risk), sonuçların iletilmesi, değerlendirmenin sürdürülmesi.
  - Bağlam oluşturma, varlıkların, tehditlerin ve güvenlik açıklarının belirlenmesi, risk analizi, mevcut kontrollerin analizi.
- Risk derecelendirme
  - Olasılık beş, sonuç altı kademelidir. İkisinin birleşimi riski ekstrem, yüksek, orta ya da düşük olarak sınıflandırır.
  - Her varlık için risk kaydı (risk register) tutulur.
- Risk çözümleme alternatifleri
  - Risk kabulü, riskten kaçınma, risk transferi, sonucu azaltma, olasılığı azaltma.
- Vaka çalışması: Gümüş Yıldız (Silver Star) Madenleri
  - Hayali bir madencilik şirketinin bütünleşik yaklaşımla yapılan risk değerlendirmesi ve risk kaydı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Riskleri bilmeden güvenlik sağlanamaz
  - Bir sistemi güvenlik altına almanın ilk yolu, güvenlik risklerinin belirlenmesi ve değerlendirilmesidir.
- Koruma maliyeti varlığın değerini aşmamalı
  - Korumanın maliyeti varlıktan büyükse korumanın anlamı yoktur. Hoca bunu araç sigortası benzetmesiyle anlattı: sigorta bedeli aracın değerine göre çok yüksekse ve risk düşük görülüyorsa sigorta yaptırılmayabilir.
- Güvenlik yalnız mantıksal (lojik) önlemlerden ibaret değildir
  - Güvenlik duvarı, IDS ve IPS kurmak yetmez. Yangın, diskin alınması, kablonun çekilmesi ya da fiber kablonun kesilmesi gibi fiziksel tehditler de hesaba katılmalıdır.
  - Sistemi kullanan, bakımını yapan ve güvenliğini sağlayan insan olduğu için insan kaynakları güvenliği de ayrı bir konudur.
- Güvenlik "anahtar teslim" bir iş değildir
  - Güvenlik "yap ve unut" şeklinde yapılmaz; 7/24 denetlenmesi ve denetim mekanizmalarının kurulması gerekir.
- Yönetim desteği birinci şarttır
  - BT güvenlik politikası üst yönetim tarafından desteklenmelidir.
- Farkındalık ve sorumluluk
  - Bütün çalışanlar güvenlik strateji, politika ve risklerinden haberdar edilmelidir; böylece üzerine düşeni yapmayan sorumlu tutulabilir.
- Risk = olasılık × maliyet
  - Her tehdit için genel bir risk derecesi türetilir: risk, tehdidin oluşma olasılığı ile kuruluş için maliyetinin çarpımıdır (ekrandan, 00:55:00). Kesin olasılık ve maliyet bulmak zor olduğu için niteliksel derecelendirme kullanılır.

## Kısa Tekrar Notları

- Güvenlik yönetimi üç soru: hangi varlık, hangi tehdit, ne yapılabilir.
- BT güvenlik yönetimi hedefleri: gizlilik, bütünlük, kullanılabilirlik, hesap verebilirlik, özgünlük, güvenilirlik.
- ISO 27000 ailesi: 27000 terimler, 27001 gereksinimler, 27002 uygulama kuralları (eski 17799), 27003 uygulama kılavuzu, 27004 ölçme, 27005 risk yönetimi (eski 13335-3/4), 27006 denetim ve belgelendirme kuruluşları.
- Dört risk değerlendirme yaklaşımı: temel, gayri resmi, ayrıntılı, bütünleşik.
  - Temel: ucuz, kolay, en iyi uygulamalar; riske özel değil; küçük kuruluşlar için.
  - Gayri resmi: analistin bilgisine dayanır; hızlı ve ucuz; yanlış değerlendirme riski; küçük ve orta ölçekli kuruluşlar için.
  - Ayrıntılı: en kapsamlı, en doğru, en pahalı; bankalar, telekom operatörleri, ISS'ler, devlet kurumları için; çoğu zaman yasal zorunluluk.
  - Bütünleşik: önce her sisteme temel önlemler, sonra yüksek riskli ya da kritik sistemlerde ayrıntılı analiz.
- Terimler: varlık, tehdit, güvenlik açığı, risk.
- Tehdit kaynakları: doğal, insan yapımı (kasıtlı ya da kazara).
- İnsan kaynaklı tehditte bakılanlar: motivasyon, yetenek, kaynaklar, saldırı yapmaya değer bulma ve caydırıcılık, önceki saldırı deneyimi.
- Risk oluşması için varlık, tehdit ve güvenlik açığı birlikte gerekir.
- Mevcut kontroller: yönetimsel, operasyonel, teknik; süreçler ve prosedürler.
- Olasılık kademeleri: 1 nadiren, 2 olası olmayan, 3 mümkün, 4 büyük ihtimalle, 5 neredeyse kesin.
- Sonuç kademeleri: 1 önemsiz, 2 küçük, 3 orta, 4 ciddi, 5 katastrofik, 6 kıyamet günü.
- Risk seviyeleri: ekstrem (üst yönetim ayrıntılı araştırma ve planlama), yüksek (yönetim dikkati, planlama ekip liderlerince), orta (özel izleme ve müdahale prosedürleri), düşük (rutin prosedürler).
- Risk çözümleme: kabul, kaçınma, transfer, sonucu azaltma, olasılığı azaltma.

## Detaylı Açıklamalar

- **Güvenlik yönetiminin kapsamı.** Hoca güvenliği bütüncül bir sistem olarak ele aldı: kenardaki sunuculardan kablolu cihazlara ve bilgisayarlara kadar bütün donanım, örneğin bir üniversitenin ya da bir firmanın bütün sistemi. Bu sistemi korumanın ilk adımı risklerin belirlenmesi ve değerlendirilmesidir. Riskler değerlendirildikten sonra üç yol vardır: bazı riskler göze alınır, bazılarına yatırım yapılıp önlem alınır, bazıları devredilir. Devretmeye örnek olarak e-posta sunucusu verildi: e-posta hizmeti kurum içinde işletilmek yerine büyük bir bulut sağlayıcısından alınır ve bu hizmetin riski sağlayıcıya geçer. Sonra güvenlik planları ve prosedürleri, fiziksel ve altyapı güvenliği, insan kaynakları güvenliği, sürekli denetim ve en sonda yasal ve etik konular gelir. Bunlar "Yönetim Sorunları" bölümünün altı alt başlığıdır.

- **Güvenlik yönetimi çevrimi.** Güvenlik yönetimine girdi olarak güvenlik politikaları ve organizasyonel bağlam (hedefler, stratejiler) girer. Ardından formal, informal ya da bütünleşik yöntemlerden biriyle risk analizi yapılır. Önlemler belirlenir ve gerçeklenir. Sonra takip süreci gelir: bakım, güvenlikle ilgili güncellemelerde değişim yönetimi ve olaylara müdahale. Hoca bunu bir çevrim olarak anlattı. İlgili taraflardan gelen girdiler ve bilgi güvenliği ihtiyaçlarına göre bir güvenlik planı yapılır, plan uygulanır, kontrol edilir. Kontrolde çıkan sonuçlara göre yönetimsel karar alınır; gerekirse yönetmelik ya da yönetimsel emir çıkarılır. Uygulamanın sonuçlarına göre yeniden planlanır ve çevrim sürekli devam eder.
  <!-- BELİRSİZ: Çevrim diyagramının slaydı karelerde yok; aşamaların adları altyazıdaki anlatımdan kuruldu. -->

- **Risk değerlendirme yaklaşımları.** İdeal olan, kurumdaki her varlığın tek tek incelenmesidir; ama bu pratikte pek mümkün değildir. Bu yüzden dört yaklaşım vardır.
  - Temel yaklaşımda en yaygın bilinen tehditlere karşı üzerinde anlaşmaya varılmış kontroller uygulanır. Sektörün en iyi uygulamalarını (best practice) kullanır, ucuz ve kolaydır, başka yerlere de aynen uygulanabilir. Kuruluşa özgü risklere özel önlem vermez; bazı kuruluşlarda yeterli, bazılarında çok az güvenlik sağlayabilir. Kaynağı az olan küçük kuruluşlar için önerilir.
  - Gayri resmi yaklaşım, BT sistemleri üzerinde resmi olmayan, pragmatik bir risk analizidir ve analistin bireysel bilgi ve uzmanlığına dayanır (ekrandan, 00:40:00). Hızlı ve ucuzdur, temel yaklaşımın ele almadığı açıklar hakkında yargıda bulunabilir. Ama bazı riskler yanlış değerlendirilebilir; sonuç analistin görüşlerine göre çarpık olabilir ve zamana göre değişir. Küçük ve orta ölçekli kuruluşlar için uygundur.
  - Ayrıntılı risk analizi en kapsamlı yaklaşımdır ve resmi, yapılandırılmış bir süreç kullanır. Varlıklar, tehditler, güvenlik açıkları, olasılıklar ve sonuçlar ayrıntılı belirlenir. Zaman, para ve farklı alanlarda uzmanlık gerektirir; en pahalı yaklaşımdır. Varlıkların değeri ya da yapılan iş nedeniyle gerekir: bankalar, e-ticaret siteleri, ISS'ler ve telekom operatörleri. Bankalar gibi kuruluşlarda yasal bir zorunluluk olarak istenir.
  - Bütünleşik yaklaşım temel, gayri resmi ve ayrıntılı yaklaşımları birleştirir. Önce bütün sistemlere uygun temel güvenlik önlemleri uygulanır. Sonra yüksek seviyeli bir değerlendirmeyle yüksek riskli ya da iş hedefleri için kritik sistemler belirlenir. Bu kritik sistemlerde ayrıntılı analiz yapılır ya da kontrolleri hızlıca uyarlamak için gayri resmi değerlendirme kullanılır.

- **Bağlam oluşturma ve varlıklar.** İlk adım, risk değerlendirmesinin temel parametrelerini belirlemek ve incelenecek varlıkları tanımlamaktır. Kuruluşun faaliyet gösterdiği siyasi ve sosyal ortam, yasal ve düzenleyici kısıtlamalar, kuruluşun misyonu, politikaları ve kabul edilebilir gördüğü risk seviyesi belirlenir. Sektörler riske duyarlılık bakımından bir yelpazede sıralanır: bankacılık ve finans, devlet kurumları, sağlık ve iletişim gibi sektörler; tarım, eğitim ve inşaat gibi sektörlere göre saldırıya daha duyarlıdır.
  <!-- BELİRSİZ: Sektör yelpazesinin slaydı karelerde yok; altyazıda sektör adları karışık okunuyor. -->
  Varlık, kuruluş için değeri olan ve hedefine ulaşmasına katkı yapan şeydir. Önemli varlıklar belirlenirken ilgili alanlardaki personelin uzmanlığından yararlanılır.

- **Terimler (ekrandan, 00:50:00).**
  - Varlık: koruma gerektiren, sahibine değer katan bir sistem kaynağı ya da yeteneği.
  - Tehdit: bir tehdit kaynağının bazı varlıklardaki bir güvenlik açığından yararlanma potansiyeli; meydana gelirse varlığın güvenliğini tehlikeye atabilir ve sahibine zarar verebilir.
  - Güvenlik açığı: bir varlığın tasarımında, uygulamasında ya da işletiminde ve yönetiminde bazı tehditlerin kullanabileceği kusur ya da zayıflık.
  - Risk: belirli bir tehdidin bir varlığa yönelik bazı açıklardan yararlanma olasılığı ile varlığın sahibine yol açan zararlı sonuçların büyüklüğünün birleşimi olarak hesaplanan kayıp potansiyeli.

- **Tehditler ve güvenlik açıkları.** Tehdit, bir varlığın gizliliğini, bütünlüğünü, kullanılabilirliğini, hesap verebilirliğini, özgünlüğünü ya da güvenilirliğini bozabilecek her şeydir. Kaynağı doğal (deprem, sel, şiddetli kış) ya da insan yapımı olabilir; insan kaynaklı tehdit kasıtlı ya da kazara olabilir. İnsan kaynaklı tehditte saldırganın motivasyonu, yeteneği, kullandığı kaynaklar (araçlar, yazılımlar), bu varlığa saldırmaya değer bulup bulmadığı ve sonuçların caydırıcı olup olmadığı değerlendirilir. Kuruluşun yaşadığı önceki saldırılar da dikkate alınır. Güvenlik açığı, kuruluşun BT sistemlerinde ya da süreçlerinde istismar edilebilir kusurlardır; bir tehdidin kuruluşa uygulanabilirliğini ve önemini belirler. Risk oluşması için varlık, tehdit ve güvenlik açığı bir arada olmalıdır. Bu adımın çıktısı, tehditlerin ve açıkların nasıl ve nereden gelebileceğine dair kısa açıklamalarla bir listesidir.

- **Risk analizi ve mevcut kontroller.** Mevcut kontroller göz önüne alınarak her tehdidin gerçekleşme olasılığı ve gerçekleşirse sonucu belirlenir (ekrandan, 00:55:00). Kesin olasılık ve gerçekçi maliyet bulmak zor olduğu için niceliksel değil niteliksel derecelendirme kullanılır.
  - Ders sonrası not: Hoca niteliksel değerlendirmeyi bir yerde "kuantatif" diye adlandırdı; doğrusu "kalitatif"tir (niteliksel = qualitative, niceliksel = quantitative).
  - Mevcut kontroller yönetimsel, operasyonel ve teknik kontroller ile süreç ve prosedürlerdir. Bunları belirlemek için kontrol listeleri kullanılır ve kilit personelle görüşülür.

- **Olasılık ve sonuç kademeleri.** Olasılık: (1) nadiren, yalnız istisnai durumlarda olur; (2) olası olmayan, mevcut kontroller altında beklenmez ama olabilir; (3) mümkün, olma ve olmama olasılığı yaklaşık eşit, dış etkiler yüzünden kontrol etmek zor; (4) büyük ihtimalle, bazı durumlarda olur ve olursa şaşırtmaz; (5) neredeyse kesin, er geç gerçekleşmesi beklenir. Sonuç (ekrandan, 01:00:00):

  | Derece | Sonuç | Özet tanım |
  |---|---|---|
  | 1 | Önemsiz | Tek alanda küçük ihlal; birkaç günden az sürer; küçük harcamayla düzelir. |
  | 2 | Küçük | Bir-iki alanda ihlal; bir haftadan az sürer; üst yönetim müdahalesi olmadan proje düzeyinde çözülür. |
  | 3 | Orta | Sınırlı sistemik (muhtemelen devam eden) ihlaller; 2 haftaya kadar sürer; yönetim müdahalesi gerekir ama proje ya da ekip düzeyinde ele alınır. |
  | 4 | Ciddi | Devam eden sistemik ihlal; 4-8 hafta sürer; önemli yönetim müdahalesi ve kaynak gerekir. |
  | 5 | Katastrofik (felaket) | Büyük sistemik ihlal; 3 ay ya da daha fazla sürer; üst yönetim olay süresince müdahale eder; iş kaybı beklenir. |
  | 6 | Kıyamet günü | Büyük sistemik ihlallerin birden çok örneği; süresi belirlenemez; şirket gönüllü yönetime ya da büyük yeniden yapılandırmaya gidebilir. |

- **Risk seviyesi matrisi.** Hocanın anlatımına göre: neredeyse kesin satırında kıyamet günü, katastrofik, ciddi ve orta sonuçlar ekstrem, küçük ve önemsiz yüksektir. Büyük ihtimalle satırında ilk üç sonuç ekstrem, orta ve küçük yüksek, önemsiz orta. Nadiren satırında kıyamet günü ekstrem, katastrofik ve ciddi yüksek, orta orta, küçük ve önemsiz düşüktür.
  <!-- BELİRSİZ: Matris slaydı karelerde yok. Hoca "mümkün" satırının "büyük ihtimalle" ile aynı olduğunu söyledi; ama aynı dersteki risk kaydında mümkün + küçük = orta verilmiş. "Olası olmayan" satırı anlatılmadı. -->

- **Risk kaydı örneği (derste sözlü).** Varlık internet yönlendiricisi, tehdit dışarıdan saldırgan, mevcut kontrol yalnız yönetici parolası. Basit ya da birden çok yerde kullanılan parolalar kırılabileceği için olasılık "mümkün", sonuç "orta", risk "yüksek", öncelik 1. İkinci satır veri merkezinin kaza sonucu yangın ya da su baskını ile zarar görmesidir. Felaket kurtarma planı yok, olasılık düşük (olası olmayan), sonuç ciddi, risk yüksek.

- **Risk çözümleme alternatifleri (ekrandan, 01:05:00).**
  - Risk kabulü: iş nedeniyle normalden yüksek bir risk düzeyini kabul etmek (örneğin bir web sitesindeki anket ya da forum için önlem almamak).
  - Riskten kaçınma: riski oluşturan faaliyete ya da sisteme devam etmemek (örneğin e-posta ya da dosya paylaşımı hizmeti vermemek).
  - Risk transferi: riskin sorumluluğunu üçüncü bir tarafla paylaşmak (sigorta, güvenlik firması, dış kaynaklı ağ yönetimi).
  - Sonucu azaltma: riskin etkisini azaltmak için varlığın yapısını ya da kullanımını değiştirmek (örneğin dosya paylaşım sistemine gizli dosyaları koymamak).
  - Olasılığı azaltma: açıktan yararlanma olasılığını azaltan uygun kontroller uygulamak.
  - Risk seviyesi arttıkça önlemin maliyeti de artar; risk yönetiminde optimum bir maliyet aranır.

- **Vaka çalışması: Gümüş Yıldız Madenleri (ekrandan, 01:10:00).** Küresel bir madencilik şirketinin hayali operasyonudur. Geniş bir BT altyapısı vardır. Yaygın yazılımlar (e-posta, muhasebe, ERP) ile özel yazılımlar (SCADA, raylı sistem, aydınlatma ve havalandırma kontrolü) birlikte kullanılır; bazıları doğrudan sağlık ve güvenlikle ilgilidir. Önceden izole ağda çalışan sistemler artık ortak ağa bağlıdır. Bütünleşik yaklaşıma karar verilmiştir. Madencilik, ticari işlem yükü olmadığı için risk yelpazesinin daha az riskli tarafındadır; ama yasal ve düzenleyici gerekliliklere tabidir. Yönetim orta ve düşük riskleri kabul eder, yüksek riskler için harcama yapmak ister. Risk kaydı (ekrandan, 01:15:00):

  | Varlık | Tehdit / açık | Mevcut kontrol | Olasılık | Sonuç | Risk | Öncelik |
  |---|---|---|---|---|---|---|
  | SCADA düğümlerinin ve ağın güvenilirliği ve bütünlüğü | Kontrol sisteminde yetkisiz değişiklik | Katmanlı güvenlik duvarları ve sunucular | Nadiren | Ciddi | Yüksek | 1 |
  | Depolanan dosya ve veritabanı bilgilerinin bütünlüğü | Bozulma, hırsızlık ve bilgi kaybı | Güvenlik duvarı ve politikalar | Mümkün | Ciddi | Ekstrem | 2 |
  | Finansal sistemin kullanılabilirliği ve bütünlüğü | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı ve politikalar | Mümkün | Ciddi | Yüksek | 3 |
  | Tedarik sisteminin mevcudiyeti ve bütünlüğü | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı ve politikalar | Mümkün | Orta | Yüksek | 4 |
  | Bakım/üretim sisteminin kullanılabilirliği ve bütünlüğü | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı ve politikalar | Mümkün | Küçük | Orta | 5 |
  | Posta hizmetlerinin kullanılabilirliği, bütünlüğü ve gizliliği | Sistemi etkileyen saldırılar/hatalar | Güvenlik duvarı, harici posta ağ geçidi | Neredeyse kesin | Küçük | Yüksek | 6 |

  - Ders sonrası not: Matrise göre "mümkün + ciddi" ekstrem olmalıdır (depolanan dosya satırında olduğu gibi). Finansal sistem satırında risk "yüksek" yazıyor; büyük olasılıkla bu satırın sonucu kaynak kitapta "orta"dır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
