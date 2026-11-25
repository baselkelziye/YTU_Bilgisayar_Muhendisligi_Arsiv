# Ders 14 Çalışma Özeti

## Genel Konular

- Dersin yapısı: dönem projesi proje planı sunumları
  - Bu derste öğrenciler dönem projelerinin proje planlarını sundu. Her sunumda proje tanımı, kapsam, gereksinimler, kabul ve kısıtlar, süreç modeli, ekip yapısı, iş kırılım yapısı, zaman planı (Gantt), bütçe ve risk planı ele alındı.
  - Hoca her sunumda planın belirli parçalarını (özellikle kabul/kısıt, Gantt, kilometre taşı, risk tablosu, use case) görmek istedi ve eksikleri kısa yorumlarla belirtti. Bu yorumlar dersin asıl akademik çıktısıdır ve aşağıda "Hocanın Özellikle Vurguladığı Kısımlar" bölümünde toplanmıştır.
- Toptan alışveriş e-ticaret sistemi
  - Tedarik sorunu yaşayan alıcıların alternatif toptancıları hızlıca bulmasını sağlayan bir e-ticaret sistemi. İşlevsel gereksinimler dört modüle ayrıldı: kullanıcı kayıt, ürün, satın alma ve yönetici modülü (ekrandan, 00:10:00).
  - İşlevsel olmayan gereksinimler: verimlilik (yaklaşık 10 bin kullanıcıyı destekleme), kullanılabilirlik ve kullanıcı dostu arayüz, güvenilirlik ve memnuniyet.
  - Ekip: iki yazılımcı, iki analist, bir sistem mimarı ve test uzmanı. Süreç modeli şelale (waterfall). Her aşama sonunda bütün ekibin katıldığı, sonuçları yazılı raporlanan gözden geçirmeler planlandı.
  - Aktivite listesi bir iş kırılım listesi tablosu olarak verildi: WBS numarası, görev adı, süre, başlangıç, bitiş, öncül (predecessor) ve kaynak sütunları; analiz, tasarım, gerçekleştirme ve test aşamaları ve her aşamanın sonunda 0 günlük "bitiş" görevi (ekrandan, 00:15:00).
- Web sitelerindeki değişiklikleri izleyen Telegram botu
  - Kullanıcının verdiği web adreslerindeki değişiklikleri yapısal (hash değeri tabanlı) ya da görsel olarak belirli aralıklarla kontrol edip Telegram üzerinden bildiren bir bot (ekrandan, 00:20:00).
  - Kabuller: dört kişilik ekipten eksilme olmaması, bütçenin aşılmaması, sunucunun en az %99,9 çalışma süresi (ekrandan, 00:20:00). Kısıtlar: en geç 3 ayda teslim, bütçe nedeniyle en fazla 200 eşzamanlı kullanıcı.
  - Teslim edilecekler: proje dokümanı, kaynak kodlar ve veri tabanı dosyaları. Use case diyagramı (bildirim talebi girme, görüntüleme, güncelleme, sorgulama sıklığı) ve varlık-ilişki diyagramı (kullanıcı, istek, anlık görüntü) hazırlandı.
  - İş kırılım yapısı grafik (ağaç) biçiminde, Gantt çizelgesi kilometre taşları elmas işaretiyle gösterilerek hazırlandı (ekrandan, 00:25:00).
- Hidroponik (topraksız) tarım için dijital veri takip sistemi
  - pH, EC, ışık ve nem gibi parametreleri sensörlerle toplayıp web ve mobil platformdan izlemeyi, ileride otonom ayar yapmayı hedefleyen bir sistem. Kart olarak Wi-Fi ve Bluetooth desteği nedeniyle ESP32 seçildi.
  - Süreç modeli şelale; test süresi bitki büyümesi zaman aldığı için uzun (yedi hafta) tutuldu. Risk tablosu risk tanımı, risk seviyesi ve B planı sütunlarıyla verildi (ekrandan, 00:35:00).
- Araç finansmanı başvurusunun dijital kanala taşınması
  - Şubeden yürütülen araç kredisi başvurusunu mobil uygulamadan uçtan uca yapılabilir hale getiren bir proje. İki faz: önce yalnız başvuru (yaklaşık 4 ay), sonra uçtan uca süreç (yaklaşık 12 ay). Toplam yaklaşık 2000 adam-gün.
  - Çevik (agile) yöntem, haftalık ekip toplantıları. Paydaşlar: proje sponsoru, yönlendirme komitesi, yürütme komitesi (ekrandan, 00:40:00).
- Hastane yönetim sistemi (İngilizce sunum)
  - Büyük veriyle çalışan, kamu sağlık sistemlerinin kullanım zorluğuna çözüm arayan bir hastane yönetim yazılımı (ekrandan, 00:45:00). Organizasyon yapısı: proje yönlendirme komitesi, müşteri onaylayıcısı, müşteri proje yöneticisi, kullanıcı temsilcileri, proje yöneticisi (ekrandan, 00:50:00).
  <!-- BELİRSİZ: Bu sunumun altyazısı büyük ölçüde bozuk; ayrıntılar yalnız slayt başlıklarından alınabildi. -->
- Bir kamu bilgi sisteminde duyuru yönetim modülü
  - Merkez ve taşra kullanıcılarının belirli il/ilçe ve kurum gruplarına yayın süresi, gönderim tarihi ve öncelik belirleyerek duyuru yapabileceği bir panel. Mikroservis olarak, web API ile tasarlandı.
  - Süreç modeli: Stacey matrisinde problem basit (ihtiyaçlar açık, teknoloji biliniyor) olduğu için şelale. Planlama, analiz, tasarım, gerçekleştirme, bakım ve destek aşamalarından oluşan bir sistem geliştirme yaşam döngüsü kullanıldı (ekrandan, 01:00:00).
  - Analiz araçları olarak SWOT, PEST ve balık kılçığı diyagramı kullanıldı.
- POS cihazı yazılımı
  - Bankaların ödemelerini API'lerle gerçekleştiren POS cihazı için iki ayda teslim edilecek bir yazılım. Çevik Scrum, kilometre taşları, sürüm tablosu, müşteri tarafı hata bildirim kanalı tanımlandı; riskler liste halinde verildi.
- İHA sürüsü ile kol (formasyon) uçuşu
  - Lider-takipçi (master-slave) yapıda, merkezden uzakta da çalışabilen ve lider bozulduğunda yeni lider seçebilen hataya dayanıklı bir İHA sürüsü. Proje bir araştırma projesi başvuru formu biçiminde hazırlandı.
  - Yedi hedef ve yöntemleri: ARM tabanlı SoC ve wireless mesh (Zigbee, Bluetooth) haberleşme, Qt tabanlı masaüstü yer istasyonu, PID tabanlı uçuş kontrolü, Gazebo simülasyonu, mesh ağ üzerinden sürü haberleşmesi, oylama tabanlı (Raft) lider seçimi, lider merkezli rota planlama (ekrandan, 01:15:00). Süreç modeli şelale.
- Göğüs kanseri histopatoloji görüntülerinin sınıflandırılması
  - Normal, iyi huylu, in situ ve invaziv olmak üzere dört sınıflı bir veri kümesinde uzamsal öznitelik çıkarma (HOG, SIFT, SURF, LBP) ve makine öğrenmesi ile sınıflandırma. Görüntüler 64×64, 128×128 ve 256×256 boyutlarında saklandı.
  - Risklerde olasılık, etki, tür, açıklama ve önlem verildi (ekrandan, 01:25:00).
- Erasmus öğrencileri için ders denkliği ve dil bilgisi platformu
  - Ders denkliği, dersin öğretim dili ve ülke seçimi sorunlarına çözüm arayan bir web platformu. Scrum seçildi. Aktiviteler arası ilişkiler bitiş-başlangıç, başlangıç-başlangıç, bitiş-bitiş ve başlangıç-bitiş türleriyle yazıldı (ekrandan, 01:35:00).
- Türkçe yazım denetimi ve değerlendirme aracı
  - Türkçe için yazım ve dil bilgisi denetimi yapan bir editör. BERT tabanlı modeller (metin türü ve duygu sınıflandırma, varlık adı tanıma), Python ve Java arka uç. Yedi iş paketi ve önem yüzdeleriyle bir proje takvimi (ekrandan, 01:50:00). Şelale seçildi.
- Mobil imza platformu
  - 5070 sayılı Elektronik İmza Kanunu ve ilgili mevzuata uygun, operatör tarafında çalışan bir mobil imza platformu. Modüller: kayıtçı (sertifika yönetimi), mesajlaşma (SIM kart ile SMS haberleşmesi), doğrulama. Özel anahtar SIM kartta, platform açık anahtarla doğrulama yapar.
  - Şelale seçildi, çünkü ayrıntılar kanun ve mevzuatta önceden belli. Coğrafi yedeklilik için iki sunucu ve iki veri tabanı bütçelendi.
- Uzaktan algılama ile av balığı yoğunluğu tahmini
  - Uydu (MODIS, Sentinel) ve çok bantlı drone görüntülerinden plankton yoğunluğu, akıntı, sıcaklık gibi verilerle balık popülasyonunun konumunu tahmin eden bir yazılım. Derin öğrenme modeli (ResNet, U-Net gibi) deneysel seçilecek. 18 ay, beş iş paketi (ekrandan, 02:15:00).
- İş güvenliği raporu paylaşım platformu
  - Bir müşteri şirketin, birlikte çalıştığı firmalarla iş güvenliği raporlarını paylaştığı web platformu. Üç kullanıcı tipi: yönetici, şirket çalışanı, firma çalışanı. Şelale gibi başlayıp çevik yönteme dönüşen bir plan.
- Metinlerin çizge veri tabanında tutulması
  - Her kelimenin düğüm, kelimeler arası bağlantının kenar olduğu merkezi bir çizge veri modeli (Neo4j, Play Framework, Scala) ve bu modeli kullanan iki uygulama: akademik makale karşılaştırma ve spor haberleri analizi.
- Online sağlıklı beslenme rehberi
  - Kullanıcı, diyetisyen ve yönetici rolleri olan, kullanıcı bilgisine göre beslenme ve egzersiz planı öneren bir uygulama. Kabul ve kısıtlar ayrı yazıldı, şelale seçildi, Gantt MS Project'te hazırlandı.
- Benzin istasyonlarında dağıtık yazılım güncelleme
  - Pompalardaki yazılımların bir sunucudan istemcilere gece saatlerinde güncellendiği açık kaynak, Linux tabanlı bir sistem. 12 ay, şelale; en uzun aşamalar gerçekleştirme ve test (4'er ay).

## Hocanın Özellikle Vurguladığı Kısımlar

- Kabuller ve kısıtlar ayrı ayrı yazılmalı
  - Birlikte yazan sunumların hepsinde hoca bunları ayırmanın daha doğru olduğunu söyledi. Olumlu bir durumun var olduğunu ya da olmadığını kabul etmek bir varsayımdır (kabuldür); örneğin eğitim verisinde argo olmadığını varsaymak kısıt değil kabuldür.
- Gantt çizelgesinde tarihler, bağımlılıklar ve kilometre taşları görünmeli
  - Hoca her sunumda Gantt'ın nerede hazırlandığını (Excel, MS Project, çevrimiçi araçlar) ve kilometre taşlarının nerede olduğunu sordu. Kilometre taşı olmayan planlarda bunu eksik saydı.
  - Seçilen süreç modeli çizelgede görülmeli: şelale seçildiyse aşamaların ardışıklığı (biri bitmeden diğerinin başlamaması) Gantt'ta görünmelidir. Paralel çubuklarla çizilmiş bir planda "şelalenin ardışıklığını göremiyoruz" dedi.
- İş kırılım yapısının iki gösterimi de doğrudur
  - İş kırılım yapısı (WBS) grafik ağaç olarak da, iç içe numaralı liste olarak da gösterilebilir; ikisi de doğrudur.
- Risk tablosunda olasılık ve etki ayrı ayrı belirtilmeli
  - Risk seviyesi olasılık ve etki düşünülmeden "kafadan" yazılmamalı. Yalnız olasılık ya da yalnız etki veren tablolarda hoca eksik sütunu sordu. Tablo yerine liste halinde verilen riskleri de eksik saydı.
- Gereksinimler kısa ve madde madde yazılmalı
  - Her işlevsel gereksinim kısa bir cümle olmalı; işlevsel olmayan gereksinimler de alt başlıklar altında (örneğin performans için) tek tek maddelenmeli.
- Use case diyagramı ve use case belgesi istenir
  - Hoca işlevsel gereksinimleri anlatan sunumlarda use case diyagramı ve belgesini sordu; akış diyagramıyla gösterilmesini de not etti.
- Proje planı sıfırdan başlıyormuş gibi hazırlanmalı
  - Şirkette ya da önceki bir çalışmada yapılmış bir proje sunulabilir, ancak oradaki hazır belge değil, derste verilen formata yakın, yeni başlayan bir proje gibi planlanmış bir belge sunulmalıdır. Zaman planı olmayan "zaten bitti" sunumlarında bunu eksik saydı.
- Bütçe kalemleri alt kırılımlarla gösterilmeli
  - Örneğin bilgisayar ve grafik kartı ayrı ayrı yazılmak yerine "donanım" kaleminin alt kırılımları olarak gösterilmeli.
- Tek kişilik projede de yöntem ve kilometre taşı gerekir
  - Tek kişi geliştirse de bir yazılım geliştiriliyor; işin nasıl bölündüğü, hangi aşamalarda değerlendirme yapıldığı ve kilometre taşları belirtilmelidir. Böyle bir çalışmada da çalışma ortamı, donanım hataları, danışman görüşmeleri gibi birçok risk vardır.

## Kısa Tekrar Notları

- Bir proje planının iskeleti: tanım ve amaç, kapsam, gereksinimler, kabuller, kısıtlar, süreç modeli ve gerekçesi, ekip, iş kırılım yapısı, Gantt (kilometre taşlarıyla), kaynak/bütçe, risk planı, test planı, projenin kapatılması.
- Kabul (varsayım) ≠ kısıt. Ayrı başlıklarda yazılır.
- Şelale (waterfall): ihtiyaçlar ve teknoloji belli, müşteriyle sık geri bildirim gerekmiyorsa uygundur (Stacey matrisinde "basit" bölge). Gantt'ta aşamalar ardışık görünmelidir.
- Çevik/Scrum: müşteri geliştirme sürecinde yer almak istiyorsa ya da gereksinim sık değişiyorsa; bazı planlar şelale gibi başlayıp çevike dönüşür.
- Kilometre taşı (milestone): proje akışındaki dönüm noktası; süresi 0 gün olan, bir aşamanın bitişini gösteren olay. Gantt'ta genelde elmasla gösterilir.
- Aktivite ilişkileri: bitiş-başlangıç (F/S), başlangıç-başlangıç (S/S), bitiş-bitiş (F/F), başlangıç-bitiş (S/F).
- Risk tablosu: risk tanımı, olasılık, etki, (seviye), önlem (B planı, gerekirse C planı).
- Balık kılçığı diyagramı: ana problem balığın başına yazılır, nedenler alt dallara ayrılır, her dal ayrı ele alınarak ana problem çözülür.
- WBS: grafik ağaç ya da numaralı liste.
- Bütçe: personel, donanım (alt kırılımlarıyla), sunucu/hizmet, bakım giderleri.

## Detaylı Açıklamalar

- Bu derste yeni bir teori anlatılmadı; dönem boyunca işlenen proje planlama kavramları öğrenci projeleri üzerinde uygulandı. Her sunumda hoca proje tanımını kısa tutturup doğrudan plana geçmeyi istedi: kabul ve kısıtlar, süreç modeli, iş kırılımı, Gantt, risk. Bu yüzden en çok tekrar edilen yorumlar planın bu parçalarına aittir.
- Kabul ve kısıt ayrımı: kabuller projenin doğru olduğu varsayılan koşullarıdır (örneğin ekipten kimsenin ayrılmaması, bütçenin aşılmaması, sunucunun %99,9 çalışma süresi). Kısıtlar projeyi sınırlayan koşullardır (örneğin en geç 3 ayda teslim, en fazla 200 eşzamanlı kullanıcı, belirli bir bütçe ve süre). Bir metin işleme çalışmasında eğitim verisinde argo olmadığını varsaymak tartışıldı: sunum bunu kısıt olarak yazmıştı; hoca olumlu bir durumun varlığını ya da yokluğunu kabul etmenin bir varsayım olduğunu, dolayısıyla kabuller altında yer alması gerektiğini söyledi.
- Gantt ve süreç modeli uyumu: e-ticaret projesinde aktivite listesi WBS numaraları, süreler, başlangıç-bitiş tarihleri ve öncüllerle verilmişti; aşama sonlarındaki "Analizin Bitmesi", "Tasarımın Bitmesi" gibi 0 günlük görevler kilometre taşı işlevi görür (ekrandan, 00:15:00). Telegram botu planında analiz, tasarım, geliştirme ve test aşamaları ardışık çubuklarla ve her aşamanın sonunda elmasla gösterilmişti; bu, şelalenin Gantt'taki beklenen görünümüdür (ekrandan, 00:25:00). Balık tahmini projesinde ise iş paketleri aynı tarihte başlayan paralel çubuklarla çizildiği için hoca şelalenin ardışıklığının görülmediğini belirtti (ekrandan, 02:15:00).
- Risk planı: hidroponik sistem sunumunda risk seviyesi olasılık ve etki belirlenmeden yazılmıştı (ekrandan, 00:35:00); hoca bunu sordu. Göğüs kanseri projesinde her risk için olasılık, etki, tür, açıklama ve önlem ayrı ayrı verilmişti (ekrandan, 01:25:00). Erasmus platformunda etki, B planı ve C planı vardı ama olasılık yoktu (ekrandan, 01:35:00). İHA projesinde başvuru formu yalnız risk ve tedbir istediği için ekip olasılığı eklemişti; hoca etkiyi de sordu.
- Süreç modeli gerekçeleri: şelale seçenler gerekçe olarak ihtiyaçların ve teknolojinin belli olmasını (Stacey matrisinde basit bölge), iş paketlerinin birbirinin çıktısına bağlı olmasını, ayrıntıların kanun ve mevzuatta önceden belirlenmiş olmasını ya da doğrudan müşteri etkileşimi olmamasını gösterdi. Çevik seçenler ise müşterinin geliştirmeye katılmak istemesini ve iki fazlı, bağımlılıkları yoğun bir yapıyı gösterdi. Bir sunum, temelde Scrum olup süreç boyunca bağımsız demo uygulamalarla riskleri sürekli analiz ettiği için spiral modeli andıran bir yaklaşım anlattı.
- Balık kılçığı diyagramı: hoca bir sunumda diyagramın özelliğini sordu. Cevap: ana problem balığın baş tarafına yazılır, problem alt dallara (nedenlere) ayrılır, her alt probleme ayrı odaklanılıp çözüm getirilerek ana problem çözülür. Örnekte ana problem duyuru sisteminin yavaşlığı, süreksizliği, yönetsel sorunları ve eski teknolojisiydi.
- Aktivite ilişkileri (ekrandan, 01:35:00): "Analiz bitmeden tasarım başlayamaz" bitiş-başlangıç (F/S), "Analizle veri tabanı oluşturma aynı anda yürüyebilir" başlangıç-başlangıç (S/S), "Dokümantasyon, kodlama bitmeden bitemez" bitiş-bitiş (F/F), "Proje tamamlanmadan test tamamlanmalıdır" başlangıç-bitiş (S/F) olarak yazılmıştı.
<!-- BELİRSİZ: Son maddedeki S/F etiketi slayttan aynen alındı; ilişkinin anlamı S/F tanımıyla tam örtüşmüyor olabilir. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
