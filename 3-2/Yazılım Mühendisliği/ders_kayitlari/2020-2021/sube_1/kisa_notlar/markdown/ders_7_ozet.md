# Ders 7 Çalışma Özeti

## Genel Konular

- Uygulama dersinin amacı ve yöntemi
  - Bu ders bir uygulama (alıştırma) dersidir. Doğal dille yazılmış gereksinim belgeleri (senaryolar) okunur, sistemin neler yapıp neler yapamadığı çıkarılır ve bu gereksinimlerden UML şemaları üretilir: sınıf şeması (alan modeli), kullanım senaryosu (use case belgesi), kullanım durumu (use case) şeması, sıralama (sequence) şeması ve durum (state) şeması.
  - Üç örnek işlenir: Online Anket Yönetimi Bilgi Sistemi, Süreli Yayın Yönetim Yazılımı (kütüphane dergi aboneliği) ve kütüphanede kitap ödünç verme sistemi.
- Örnek 2: Online Anket Yönetimi Bilgi Sistemi (ekrandan, 00:25:00)
  - Gereksinimler: İnternet üzerinden anket yapılacak ve anketlerle ilgili raporlar verilecek. Her anketin başlangıç ve bitiş süresi olacak. Anket seçenekleri yalnız metinden oluşmayacak, resim de içerebilecek. Anketlere yalnız kayıtlı kullanıcılar oy verebilecek. Bir anket yalnız o anketin yöneticisi olarak atanmış bir kullanıcı tarafından oluşturulabilecek.
  - Örnek sınıf şeması (ekrandan, 00:20:00):
    - `Anket`: `başlangıç, bitiş : Date`.
    - `Seçenek`: `resim`, `metin : String`, `seçenSayısı : int`. Anket ile Seçenek arasında 1–* ilişki vardır.
    - `Admin`, `Kullanıcı` sınıfından kalıtım alır (admin de bir kullanıcıdır). Anket ile Admin arasında 1–1, Anket ile Kullanıcı arasında 1–* ilişki vardır.
    - `seçenSayısı`, her seçeneği kaç kişinin seçtiğini tutar; raporlama bu değer üzerinden yapılır.
  - Örnek kullanım senaryosu: "Anket oluşturma"; birincil aktör anket yöneticisi (admin). Ön koşul: yönetici sisteme girmiştir. Ana senaryo: yeni anket oluşturulur, sorular oluşturulup ankete bağlanır, anket yayınlanır. Alternatif senaryo: soru resim içeriyorsa yönetici resim dosyasını da yükler.
    <!-- BELİRSİZ: Anket kullanım senaryosunun sayfası karelerde yok; maddelerin tam metni ve numaraları altyazıdan kuruldu. -->
- Örnek 1: Süreli Yayın Yönetim Yazılımı (ekrandan, 00:30:00)
  - Süreli yayın: aylık, üç aylık, dört aylık gibi periyotlarla çıkan ve bir adı olan dergi. Her süreli yayının adı ve onu diğerlerinden ayıran 8 karakterlik ISSN numarası vardır; ilk 7 karakter 0-9 arası sayı, son karakter 0-9 arası sayı ya da X'tir.
  - Abonelik yalnız basılı, yalnız elektronik ya da hem basılı hem elektronik olabilir. Elektronik yayınlar için derginin bütün sayılarına erişilen tek bir URL ve geriye dönük kaç yıllık sayıya erişildiğini gösteren `backfile` bilgisi tutulur; bazı elektronik yayınlarda backfile sınırı yoktur.
  - Basılı yayınlarda kütüphanedeki her sayının yıl ve sayı bilgisi saklanır. Kütüphaneci yeni sayı girerken mevcut sayılar yıl, sayı ve durum bilgisiyle kutucuklar içinde gösterilir. Durumlar "geldi" ve "bekleniyor"dur; sistem tarihe ve periyoda göre gelecek sayıları "bekleniyor" yapar, kütüphaneci gelen sayıyı "geldi" olarak işaretler.
  - Kayıt yoksa kütüphaneci ISSN, ad ve periyot bilgisini girip basılı/elektronik aboneliğe göre gereken bilgileri ekleyerek yeni kayıt oluşturur.
- Süreli yayın için olası alan modelleri (metotsuz sınıf şemaları) (ekrandan, 00:35:00)
  - Model 1: `Süreli Yayın` (`isim, ISSN : String`, `periyot : int`, `sayılar[] : Sayı`, `e_dergi : ElektronikDergi`); `Sayı` (`sayiNo, yil : int`, `durum : String`) ile toplama (aggregation) ilişkisi; `ElektronikDergi` (`URL : String`, `backfile : int`) ile 1–0..1 ilişki. Notlar: periyot kaç ayda bir çıktığını gösteren sayıdır; backfile sınırsız ise 0 olur.
  - Model 2: soyut (`«abstract»`) `Süreli Yayın` (`isim, ISSN`, `periyot`) ve ondan kalıtım alan `BasılıSayı` (`sayiNo, yil`, `durum`) ile `ElektronikDergi` (`URL`, `backfile`). Not: sistemde aynı ISSN'li tek bir ElektronikDergi örneği, birden fazla BasılıSayı örneği bulunur.
  - Model 3: `Süreli Yayın` 1–* `Sayı`; `ElektronikDergi`, `Süreli Yayın`'dan kalıtım alır.
  - ISSN içinde X karakteri bulunabildiği için `String` tanımlanır.
- Kullanım senaryosu: Yeni Sayı Gelişi (check-in) (ekrandan, 00:40:00; 00:45:00)
  - Birincil aktör kütüphaneci; diğer ilgili yok. Ön koşul: kütüphaneci sisteme girmiştir. Son koşul: süreli yayın ve sayı kayıtları sisteme girilmiş ve/veya güncellenmiştir.
  - Ana senaryo: ISSN girilir; basılı abonelik varsa ad, ISSN, periyot ve bu yılın sayıları kutucuklarla gösterilir; elektronik abonelik varsa URL ve backfile gösterilir; kütüphaneci bilgileri günceller ve onaylar.
  - Alternatif senaryolar: 1a yeni abonelik (ISSN bulunamazsa abonelik oluşturma), 3a önceki yıla ait bir sayının işlenmesi.
- Olası UML kullanım durumu şemaları (ekrandan, 00:50:00)
  - Uygun şemalar: Kütüphaneci aktörü ile "Abonelik", "Yeni sayı gelişi", "Sisteme Giriş"; "Eski abonelik" ve "Yeni abonelik" durumlarının "Yeni sayı gelişi"ni `«extend»` etmesi.
  - Kütüphanecilik bilgisine göre en uygun şema: "Elektronik" ve "Basılı" durumlarının "Abonelik"i `«extend»` etmesi.
  - Yanlış şema: "Yeni sayı gelişi"nin "Basılı" ve "Elektronik"i `«include»` etmesi.
- Ek gereksinim: check-in kartı (ekrandan, 00:55:00)
  - Kütüphanecinin tıklayarak değiştirebildiği, okuyucunun yalnız içeriğini görebildiği dergi ekranına check-in kartı denir. Şemaya ikinci aktör olarak Okuyucu eklenir; "Yeni sayı gelişi" `«include»` "Check-in kartı gösterimi"; "Check-in kartı gösterimi" "Abonelik"i `«extend»` eder; "Check-in kartı düzenlemesi" "Check-in kartı gösterimi"ni `«extend»` eder.
- Örnek 3: Kitap ödünç verme (ekrandan, 01:00:00)
  - Okuyucu kitap alma sınırını doldurmuşsa yeni kitap verilmez. Toplam ceza (`Okuyucu.cezaMiktarı` + iade tarihi geçmiş kitaplardan doğan ceza) `Okuyucu.cezaSınırı`'ndan yüksekse yeni kitap verilmez. Aksi halde ödünç kaydı oluşturulup okuyucuya bağlanır; alış tarihi bugün, dönüş tarihi kitabın kaç günlüğüne verildiğine göre belirlenir.
- Alan şeması (ekrandan, 01:05:00)
  - `Okuyucu` (`ad, soyad`, `üyeNo`, `kitapSınırı`, `cezaSınırı`, `cezaMiktarı`; `getKitapSayısı()`, `getCeza()`, `getToplamCeza()`, `kitapEkle(ÖdünçKaydı)`) ◇1–* `ÖdünçKaydı` (`alışTarihi`, `dönüşTarihi`; `getDonusTarihi()`, `getGunlukCeza()`) 1–1 `KitapKopyası` (`barkod`, `ödünçSüresi`, `günlükCeza`; `getGunlukCeza()`) *–1 `Kitap` (`adı, yazarı`, `basımYılı`).
- Etkileşim şeması: sıralama şeması (ekrandan, 01:10:00; 01:20:00)
  - Etkileşim şemaları ikiye ayrılır: işbirliği (collaboration) ve sıralama (sequence) şemaları. Nesneler arasında hangi mesajların hangi sırayla gönderildiğini gösterir.
  - Ödünç verme akışı: `okuyucuBul(okurBarkod)` → `getKitapSayısı()` → `getKitapSınırı()` → `getToplamCeza()` (içinde `getCeza()`, her kayıt için `getDonusTarihi()`, gecikme varsa `getGunlukCeza()`) → `getCezaSınırı()` → koşul sağlanırsa `ödünçVer(okurBarkod, kitapBarkod)` → `new` ödünç kaydı → `kitapEkle(yeniKayıt)`.
- Durum şeması (ekrandan, 01:25:00)
  - Durumlar: "Ödünç alabilir" ve "Ödünç alamaz". Başlangıç içi dolu daire, bitiş iç içe daire ile gösterilir. Limitler aşılmadıkça ödünç alabilir durumda kalınır; ödünç limiti ya da ceza limiti aşılınca ödünç alamaz durumuna geçilir; iade ya da ceza ödemesiyle limit altına düşülürse geri dönülür; okuyucu ilişiğini keserse bitiş durumuna gidilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- include ve extend ayrımı
  - `«include»` "bu işlem mutlaka şunu içermeli" demektir, bir zorunluluk ifade eder. Yeni sayı gelişinde basılı ya da elektronik abonelik bulunması zorunlu değildir (abonelik hiç olmayabilir, yalnız biri olabilir), bu yüzden "Yeni sayı gelişi"nin "Basılı" ve "Elektronik"i içermesi mantık olarak yanlıştır. Doğrusu aboneliği elektronik ve basılı olarak `«extend»` etmektir.
  - Yeni sayı girişinde check-in kartını görmek zorunludur, bu yüzden orada `«include»` kullanılır; abonelik oluştururken kartı görmek isteğe bağlıdır, orada `«extend»` kullanılır.
- Sıralama şemasında sıra
  - Sıralama şemasında metot çağrılarının sırası çok önemlidir. En üstteki mesaj en önce gerçekleşir; çağrılar, derleyicinin kodu çalıştırdığı sırayla yazılmalıdır.
- Etkileşim şeması ile etkinlik şeması farklıdır
  - Etkileşim şeması nesnelerin birbirine mesaj gönderip almasını gösterir; etkinlik şeması (activity diagram) ayrı bir şemadır, karıştırılmamalıdır.
- Toplama (aggregation) ve bileşim (composition)
  - Ödünç kaydı doğrudan bir okuyucuya ait olduğu için düz bir 1–* ilişki yerine daha kuvvetli bir bağ olan toplama (içi boş elmas) kullanılmıştır. Bileşim (içi dolu elmas) bundan da kuvvetlidir: parça bütünden ayrı düşünülemez.

## Kısa Tekrar Notları

- Gereksinim metnindeki adlar sınıf ve nitelik adaylarıdır (süreli yayın → sınıf, periyot → nitelik).
- "X de bir Y'dir" ifadesi kalıtım (is-a) ilişkisine işaret eder: Admin bir Kullanıcıdır.
- Kullanım senaryosu bileşenleri: birincil aktör, diğer ilgililer, ilgi alanları, ön koşullar, son koşullar, ana senaryo, alternatif senaryolar.
- Alternatif senaryo numarası, ana senaryonun ayrıldığı adımın numarası ve bir harften oluşur (1a, 3a); alt adımları ayrıca numaralanır.
- Kullanım durumu şemasında insan aktör çöp adamla gösterilir; durum yalnız kişi ile sistem arasındaysa tek aktör yeter.
- `«include»`: zorunlu içerme; `«extend»`: koşullu, isteğe bağlı genişletme.
- Sıralama şemasında dolu oklu düz çizgi istek (mesaj, metot çağrısı), kesik çizgi dönüş (cevap) anlamındadır; nesnenin kendi metodunu çağırması kendine dönen okla gösterilir; köşeli parantez koşul bildirir; cevap beklenmeyen çağrıda dönüş oku çizilmez.
- Durum şemasında başlangıç içi dolu daire, bitiş iç içe dairedir; geçişler `olay [koşul]` biçiminde yazılır.

## Detaylı Açıklamalar

- Anket örneğinde sınıf şeması gereksinim cümlelerinden doğrudan çıkarılır. "Her anketin başlangıç ve bitiş süresi olmalıdır" cümlesi `Anket` sınıfına iki `Date` niteliği verir. "Seçenekler resim de içerebilir" cümlesi seçeneklerin ayrı bir sınıf olmasını daha iyi bir tasarım yapar; bir ankette birden çok seçenek olduğundan ilişki 1–*'dır. Rapor istenmesi her seçeneğin `seçenSayısı` değerini tutmasını gerektirir. Anketi yalnız kendi yöneticisi oluşturabildiği ve yönetici de bir kullanıcı olduğu için `Admin`, `Kullanıcı` sınıfının alt sınıfı olarak modellenir.
- Süreli yayın örneğinde üç farklı alan modeli tartışılır. İlk modelde sayılar süreli yayının içinde bir dizi olarak toplama ilişkisiyle tutulur, elektronik dergi ise 0..1 ilişkiyle bağlanır (bir yayının ya hiç elektronik aboneliği yoktur ya da tek bir URL'li tek bir elektronik versiyonu vardır). İkinci modelde ortak alanlar soyut bir üst sınıfta toplanır, basılı sayı ve elektronik dergi alt sınıf olur. Üçüncü modelde sayılar 1–* ilişkiyle bağlanır, elektronik dergi de süreli yayının alt sınıfı olarak ek alanlarını (URL, backfile) taşır.
- Ödünç verme sıralama şemasında kütüphaneci önce okuru bulur, sonra okurun kitap sayısını ve kitap sınırını alır. Toplam ceza okuyucu nesnesinde hesaplanır: önce geçmiş ceza (`getCeza()`) alınır, sonra her ödünç kaydının dönüş tarihine bakılır; tarih bugünden küçükse (iade tarihi geçmişse) gecikme gün sayısı ile kitap kopyasından alınan günlük ceza çarpılıp toplam cezaya eklenir. Ardından ceza sınırı alınır ve `toplamCeza < cezaSınırı AND kitapSayısı < kitapSınırı` koşulu sağlanırsa `ödünçVer` çağrılır, yeni bir `ÖdünçKaydı` nesnesi oluşturulur ve `kitapEkle(yeniKayıt)` ile okuyucuya bağlanır.
- Durum şemasında okuyucu kütüphaneye kayıt olunca "Ödünç alabilir" durumuna girer. Limitler aşılmadıkça ödünç alma bu durumda kalır. Limitlerden biri aşılınca "Ödünç alamaz" durumuna geçilir. Kitap iadesi ya da ceza ödemesiyle limit altına inilirse yeniden "Ödünç alabilir" durumuna dönülür; iadeye rağmen ceza limiti aşılmış kalıyorsa okuyucu "Ödünç alamaz" durumunda kalır.
  - Ders sonrası not: Slayttaki geri dönüş etiketi "İade [ceza limiti altına düşüldü] / Ceza ödeme [ödünç limiti altına düşüldü]" biçimindedir (ekrandan, 01:25:00). Anlatıma göre koşullar büyük olasılıkla yer değiştirmiştir: iade ödünç (kitap) limitinin, ceza ödemesi ceza limitinin altına düşülmesini sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
