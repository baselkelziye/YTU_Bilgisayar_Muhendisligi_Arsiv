# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin tarihi 28 Mart 2023 Salı. Ders Zoom üzerinden yapıldı.
  - Asıl anlatım yaklaşık 00:04'te başlar. Slayt dosyası "BLM2042-05".
- Sistem analizinin ikinci aşaması: çözümleme
  - İş analizinde bulunan gereksinimler teknik bir dile dönüştürülür. Bu, tasarıma geçmeden önceki ilk teknik adımdır.
  - İki yöntem var: fonksiyonel (işlevsel) çözümleme ve nesneye dayalı çözümleme. Bu hafta fonksiyonel çözümleme işlendi; nesneye dayalı olan gelecek hafta.
  - Bu aşamanın çıktısı SRS (Software Requirements Specification, yazılım gereksinim belirtimi) dokümanıdır.
- Gereksinim analizinin amaçları
  - Problemi ve ihtiyaçları anlamak. Tasarım (çözüm önerisi) için temel oluşturmak.
  - Geçerleme için materyal üretmek: "Doğru ürünü yaptık mı?" sorusu bu gereksinimlerle test edilir.
- Analiz modeli (çember)
  - Üç dilim var: veri nesne tanımı, süreç tanımı (process specification), kontrol tanımı (control specification).
  - Ortada bu üç dilimi bağlayan veri sözlüğü var.
  - Bu derste veri nesne tanımına 10. hafta civarında, kontrol tanımına ise hiç girilmeyecek.
- Veri akış diyagramı (VAD, data flow diagram)
  - Dört öğe: varlık (dış varlık), süreç (işlem), veri akışı, veri deposu.
  - Gösterim: Gane-Sarson sembolleri kullanılıyor. Diğer gösterim DeMarco-Yourdon.
  - Çizim kuralları ve sık yapılan hatalar.
- VAD düzeyleri
  - Bağlam (taslak, context) diyagramı, 1. düzey, 2. düzey.
  - Örnek: hastane fatura sistemi.
- Mantıksal ve fiziksel VAD
  - Mantıksal VAD analiz modelidir. Fiziksel VAD gerçekleştirme ayrıntısı içerir ve tasarımda kullanılabilir. Bu derste yalnızca mantıksal VAD beklenir.
- Süreç tanımlama formu
  - Her süreç kutusu için bir form doldurulur. Süreç mantığı sözde kod (pseudocode), karar tablosu veya karar ağacıyla anlatılır.
- Veri sözlüğü
  - Veri akışları, veri depoları, veri yapıları, veri elemanları ve süreçler için girdiler (entry) içerir.
- Ders sonu sorusu: erişilebilirlik (ör. görme engelli kullanıcılar) hangi fizibilitenin konusudur?

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri akışlarının üzerine yalnızca isim yazılır, fiil yazılmaz.
  - "Siparişi doğrula" yanlıştır. Doğrusu "doğrulanmış sipariş" gibi bir isimdir. "Tamamla" gibi eylemler süreç kutusunun işidir.
- Süreçler emir kipindeki fiillerle adlandırılır.
  - Örnek: "Randevu al", "Fatura hazırla".
- Her süreçte girdi, işlem ve çıktı olmalıdır.
  - Yalnız çıktısı olan süreç ve yalnız girdisi olan süreç hatalıdır. Literatürde bunlara "mucize" ve "kara delik" denir.
- Girdiler, çıktıyı üretmeye yetecek kadar olmalıdır.
  - Maaş hesaplamak için yalnız çalışma saatleri yetmez. Çalışan bilgisi ve ücret tanımları da gerekir.
  - "Kalabalık olmasın diye çizmedim" kabul edilmez.
- Veri işlenmeden bir yerden bir yere akamaz.
  - Veri deposundan veri deposuna, varlıktan veri deposuna doğrudan ok çizilmez. Arada mutlaka bir süreç olmalıdır.
- Oklar tek yönlüdür ve her ok tek bir veri akışıdır.
  - Aynı veri iki sürece gidiyorsa tek ok çizilip sonra ikiye ayrılır.
- Düzeyler arasında denge korunmalıdır.
  - Bağlam diyagramındaki varlıklar ve veri akışları 1. düzeyde de aynen görünmelidir. 1. düzeydeki bir sürecin girdi ve çıktıları 2. düzeye aynen taşınmalıdır.
- Bu derste en fazla 2. düzeye inilir.
  - Daha ayrıntılı mantık süreç tanım formlarıyla anlatılır.
- Ayrıntılı dokümantasyon (veri sözlüğü, formlar) günlük işte her zaman yapılmaz.
  - Ama görev açısından kritik (mission critical) projelerde, uzay ve savunma projelerinde yapılması zorunlu olabilir. O gün "bilmiyorum" dememek için öğrenilmeli.
- VAD'yi başka kaynaklardan da çalışın, örnek çizin.
  - Projelerde analiz modelini oluştururken VAD kullanılacak.

## Kısa Tekrar Notları

- Analiz modeli = veri nesne tanımı + süreç tanımı + kontrol tanımı; merkezde veri sözlüğü.
- VAD öğeleri:
  - Süreç: köşeleri yuvarlatılmış dikdörtgen, üstte hiyerarşik numara (1.0, 2.1).
  - Veri akışı: üzerinde isim olan ok.
  - Veri deposu: bir yanı açık dikdörtgen, numaralı (D1, D2).
  - Dış varlık: dikdörtgen. Tekrar çizilen varlık köşesine çentikle işaretlenir.
- Bağlam (context) diyagramı:
  - Sistem tek bir kutudur (kara kutu).
  - Yalnızca ana varlıklar ve temel girdi/çıktılar gösterilir. Veri deposu yoktur.
- 1. düzey: ana süreçler (1.0, 2.0, ...), veri depoları ve aralarındaki akışlar.
- 2. düzey: 1. düzeydeki bir sürecin içi (2.1, 2.2, ...).
- Mantıksal VAD analizi gösterir. Fiziksel VAD donanım, yazılım ve dosya gibi ayrıntılarla tasarımı gösterir.
- Süreç tanım formu alanları:
  - Numara, ad, tanım.
  - Girdiler, çıktılar.
  - Süreç tipi (çevrim içi/otomatik ya da elle tetiklenen).
  - Süreç mantığı.
  - Çözülmeyen sorunlar.
- Süreç mantığını anlatma araçları:
  - Sözde kod: sıralı ifadeler, kararlar, döngüler.
  - Karar tablosu: çok koşullu (kombinatoryal) durumlar.
  - Karar ağacı: daha görsel, az karmaşık durumlar.
- Veri sözlüğü girdi türleri: veri akışı, veri deposu, veri yapısı, veri elemanı, süreç.

## Detaylı Açıklamalar

Fonksiyonel çözümleme, sistemi işlevlerine (süreçlerine) ayırma işidir. Her süreç girdi alır, işler ve çıktı üretir. Bu süreçlerin hangi varlıklarla ve hangi veri depolarıyla veri alışverişi yaptığı VAD ile gösterilir.

### VAD öğeleri

- **Varlık (dış varlık, source/sink):** Sistemle etkileşen kişi, kurum, birim ya da başka bir sistem. Sisteme veri verir ya da sistemden çıktı alır. Use case'lerdeki aktörlere karşılık gelir.
- **Veri akışı:** Bir kaynaktan hedefe giden veri. Tek bir öğrenci numarası da olabilir, grafikli büyük bir rapor da. Diyagramda hepsi tek bir oktur.
- **Süreç (işlem):** Sistemin bir sorumluluğunu yerine getiren etkinlik. Emir kipinde adlandırılır.
- **Veri deposu:** Verinin kalıcı olarak saklandığı yer. Dosya, klasör, veritabanı tablosu, form ya da rapor olabilir. Yalnızca veritabanı tablosu demek değildir.

### Sık yapılan çizim hataları

- Girdisi olmayan süreç ("mucize").
- Çıktısı olmayan süreç ("kara delik").
- Çıktıyı üretmeye yetmeyen girdiler.
- Süreçten geçmeden veri deposu–veri deposu ya da varlık–veri deposu akışı.
- İki uçlu ok. Bir süreç bir depodan veri alıp aynı veriyi geri yazıyorsa model yanlıştır. Doğrusu: A akışı okunur, işlenir, farklı bir B akışı yazılır.
- Aynı veri için iki ayrı ok. Doğrusu: tek ok çizip ikiye ayırmak.
- Hiçbir işlemden geçmeden aynı sürece geri dönen akış. Özel bir özyineleme gösterilmiyorsa beklenmez.
- Akış üzerine fiil yazmak.

### Düzeyler: hastane fatura sistemi örneği

- **Bağlam diyagramı:** Tek bir kutu, "fatura sistemi".
  - Girdiler: Doktordan muayene kaydı, hastadan sigorta formu.
  - Çıktılar: Hastaya hasta faturası, sigorta şirketine sigorta faturası.
- **1. düzey:** Dört süreç ve dört veri deposu.

| Süreç | Girdi | Çıktı |
| :--- | :--- | :--- |
| 1.0 Muayene Kaydı İnceleme ve Ücret Hesabı | Muayene kaydı (doktor), ücret (D1 Ücret Listeleri) | Doğrulanmış ücret |
| 2.0 Fatura Hazırlama | Sigorta formu (hasta), doğrulanmış ücret, sigorta şirketi adı ve adresi (D3), hasta adresi (D2) | Hasta faturası, sigorta faturası |
| 3.0 Hasta Ödemeleri İşleme | Hasta ödemesi | D4 Muhasebe Kayıtları |
| 4.0 Sigorta Ödemeleri İşleme | Sigorta ödemesi | D4 Muhasebe Kayıtları |

- Süreç adındaki "ve" ("İnceleme ve Ücret Hesabı"), bu sürecin 2. düzeyde iki alt sürece ayrılacağını gösterir.
- **2. düzey (2.0'ın içi):** Sigorta durumunu inceleme, listelenen miktarla faturayı karşılaştırma, hasta faturasını hazırlama gibi alt süreçler. 2.0'a giren ve çıkan bütün akışlar burada da aynen görünür.
- Müşteri, modeli görünce eksik bir şeyi fark edebilir. Örnek: "Faturaları Sağlık Bakanlığı'na da raporluyoruz." Bu durumda yeni bir varlık ve yeni bir akış eklenir. Teknik ayrıntılar (protokol, kimlik doğrulama) tasarımın işidir.

Düzey adları kaynaktan kaynağa değişir. Bazı kaynaklar bağlam diyagramına "düzey 0" der. Bu derste bağlam/taslak, 1. düzey ve 2. düzey adları kullanılıyor.

### Dengesizlik örneği

- Bağlam diyagramında Varlık 1'den A akışı geliyor. 1. düzeyde ise A, Varlık 3'ten geliyor ve Varlık 4'ten C akışı var.
- Bu bir düzeyler arası tutarsızlıktır. Bağlam diyagramı güncellenmeli ya da 1. düzey düzeltilmelidir.
- İkinci soruda bir sürece "A ve B" tek okla giriyor. Alt düzeyde ise A ve B ayrı ayrı giriyor.
  - A ve B tek kaynaktan bileşik bir yapı olarak geliyorsa kabul edilebilir.
  - Farklı kaynaklardan geliyorsa iki ayrı ok çizilmelidir.
  - En temiz yol ikisini ayrı ok olarak çizmektir.

### Süreç tanım formu ve karar yapıları

- Eczane örneğinde "Ödeme Al" süreci için sözde kod:

```text
Miktarı oku
Ödemeyi al
IF ödeme > ödenecek miktar
    Para üstü ver; ödeme = tamam
ELSE IF ödeme = ödenecek miktar
    ödeme = tamam
ELSE
    ödeme = tamam değil
IF ödeme tamam
    Fatura üret
ELSE
    Hastaya "ödeme eksik" bilgisi ver
```

- Formdaki "çözülmeyen sorunlar" alanına analizdeki boşluklar yazılır. Örnekler: "Nakit dışı ödeme var mı?", "Reçete bilgisi bu sürece nereden geliyor?"
- Stok kontrolü örneği (sözde kod, case yapısı):
  - Stok kritik seviyenin üstündeyse hiçbir şey yapma.
  - Kritik seviyedeyse eczane çalışanını uyar.
  - Kritik seviyenin altındaysa otomatik sipariş üret.
  - Stok sıfırsa muadil ilaçları göster.
  - Her eylem ayrı bir alt süreçtir.
- **Karar tablosu (İlaç İndirim Hesapla):**

| Koşullar | Kural 1 | Kural 2 | Kural 3 | Kural 4 |
| :--- | :---: | :---: | :---: | :---: |
| Çalışan hasta | E | E | H | H |
| Emekli hasta | H | H | E | E |
| Toplam tutar ≤ 50 TL | E | H | E | H |
| Toplam tutar > 50 TL | H | E | H | E |
| **Eylemler** | | | | |
| İndirim oranı 1 | X | | | |
| İndirim oranı 2 | | X | | |
| İndirim oranı 3 | | | X | |
| İndirim oranı 4 | | | | X |
| Ek %10 indirim | | | | X |

- Çalışan ve emekli satırları birbirini dışlar (mutually exclusive). Başka hasta tipi yoksa tek satır ("Çalışan mı?") yeterlidir. Aynı şey "≤ 50" ve "> 50" satırları için de geçerlidir.
- **Karar ağacı (burs örneği):**
  - Disiplin cezası almışsa burs yok.
  - Almamışsa not ortalaması 70'ten büyük mü, sonra giriş puanı ortalamanın üstünde mi diye dallanır.
  - Yapraklar: tam burs, yarım burs, bir yıllık burs, burs yok.
- Daha karmaşık, olay güdümlü ya da eş zamanlı sistemlerde sonlu durum makineleri ve durum diyagramları kullanılır. Bu derste bu konuya girilmiyor.

### Veri sözlüğü

- **Veri akışı girdisi:** Ad (ör. "Fatura Basma"), tanım, kaynak (1.1), hedef (1.2), içerik (fatura detayları, müşteri detayları; bileşik mi elementer mi).
- **Veri deposu girdisi:** Ad (ör. "Satış Sipariş Form Dosyası"), tanım, içerdiği veri yapısı, hacim, erişim yetkisi.
  - Hacim örneği: Günde yaklaşık 100 kayıt yılda $100 \times 365 = 36\,500$ kayıt eder. Kayıt başına 1 MB ile yılda yaklaşık 36,5 GB yer gerekir.
  - Erişim örneği: Yalnızca sipariş bölümü personeli erişebilir.
- **Veri yapısı girdisi:** Ör. satış sipariş kaydı.
  - Müşteri numarası (elementer), sipariş numarası (elementer), tarih (bileşik).
  - Parça numarası, miktar, birim fiyat.
- **Veri elemanı girdisi:** Ör. müşteri numarası: nümerik, 4 basamak, 1–6999 aralığı. Değerleri sınırlı ise kod tablosu (enumerasyon) verilir.
- **Süreç girdisi:** Numara (2.0), ad, girdiler, işlemler, çıktılar.

### Ders sonrası notlar

- **Sembol adları:** Altyazıda "Gain ve Sarson" ve "Demarco-Jurdon" geçiyor. Doğru adlar Gane-Sarson ve DeMarco-Yourdon'dur.
- **Fatura örneğindeki ok:** 1. düzey diyagramda "Ücret" oku 1.0'dan D1 Ücret Listeleri'ne doğru çizilmiş. Hoca bunun ters olduğunu söyledi. 1.0 ücreti listeden okumalıdır, yani ok D1'den 1.0'a gelmelidir.
- **Kontrol tanımı terimleri:** Altyazıda "stake çarklar / stake diagramlar" diye geçen terim "statechart" ve "state diagram"dır (durum diyagramı).
- **"Mutually eksplosif":** Altyazıdaki bu ifadenin doğrusu "mutually exclusive" (birbirini dışlayan).
- **Erişilebilirlik sorusu:** Hoca erişilebilirliği sosyal fizibilite kapsamında değerlendirdi. Bazı kaynaklar bunu kullanıcıların sistemi kullanabilmesi açısından işletimsel (operasyonel) fizibilite altında ele alır. Sınavda dersin kendi sınıflandırmasını kullanın.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
