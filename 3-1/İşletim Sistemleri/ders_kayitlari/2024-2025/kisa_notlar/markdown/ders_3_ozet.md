# Ders 3 Çalışma Özeti

## Genel Konular

- İşletim sistemi yapılarının katmanlı görünümü
  - Kullanıcı ile donanım arasında birbirinden hizmet alan katmanlar vardır: kullanıcı arayüzü, sistem çağrısı arayüzü, işletim sistemi servisleri, donanım.
  - Her katman altındakinden istekte (request) bulunur, üstündekine yanıt (response) verir.
- İşletim sistemi servisleri
  - Kullanıcı arayüzü: komut satırı (CLI), grafik arayüz (GUI), toplu işlem (batch) arayüzü.
  - Program çalıştırma: programı belleğe yükleme, çalıştırma, normal ya da anormal sonlandırma.
  - G/Ç işlemleri: aygıt denetleyicileri ve aygıt sürücüleri üzerinden.
  - Dosya sistemi işlemleri: dosya ve klasör oluşturma, silme, yeniden adlandırma, izinler.
  - Haberleşme: aynı bilgisayarda ya da ağ üzerinden süreçler arası iletişim; paylaşımlı bellek (shared memory) ve mesaj geçirme (message passing).
  - Hata algılama: sıfıra bölme gibi exception'ları yakalayıp uygun eylemi almak, hata ayıklamaya yardımcı olmak.
  - Kaynak tahsisi, kaynak muhasebesi (accounting), koruma (protection) ve güvenlik (security).
  - Örnek: Farklı programlardan gelen yazdırma istekleri `write` isteklerine dönüşür ve işletim sistemince FIFO kuyruğunda sırayla yazıcıya gönderilir.
- Komut satırı arayüzü (shell)
  - Kullanıcıdan komut alır, çalıştırır, çıktısını gösterir. Bazı komutlar yerleşiktir (built-in), bazıları ayrı programlardır (eski sistemlerde `format`, `fdisk`).
  - Örnek komutlar: `cd`, `cd ..`, `dir`, `dir /w`, `dir /s`, `ls`, `pwd`, `ping` (ICMP paketleri), `gcc`.
  - Yetkisiz bir `format C:` denemesi koruma gereği reddedilir (erişim engellendi); harici bir diske format atılabilir.
  - Ctrl+C çalışan işe bir sinyal göndererek onu sonlandırır.
  - Göreli yol (relative path) programın taşınmasına dayanıklıdır; mutlak yol (absolute path) taşınınca bozulur.
- Grafik kullanıcı arayüzü (GUI)
  - Simgeler, klasörler, fare ve dokunmatik etkileşim. GUI işletim sisteminin bir parçasıdır ama çekirdekten bağımsız değiştirilebilir (Android telefonlarda markaya göre farklı arayüzler).
- Sistem çağrıları
  - İşletim sistemi servislerine erişen programlama arayüzü; genellikle C/C++ ile yazılır.
  - Uygulamalar çoğunlukla API'ler (Win32 API, POSIX API) üzerinden sistem çağrısı yapar. `fopen`, `printf` gibi fonksiyonlar API'dir; aşağıda aynı sistem çağrısına bağlanırlar.
  - Bir dosyayı diğerine kopyalama, baştan sona bir sistem çağrıları dizisidir (ekrandan, 00:42:30).
  - Her sistem çağrısının bir numarası (ID) vardır; sistem çağrısı arayüzü bu numaraya göre çekirdekteki ilgili rutini çağırır, işlem bitince durum ve dönüş değeri geri gelir.
  - Çağrı yapılırken kullanıcı modundan çekirdek moduna geçilir.
- Sistem çağrısında parametre geçirme (ekrandan, 00:56:00)
  - En basit yol: parametreleri register'larda geçirmek; parametre sayısı register sayısını aşabilir.
  - Parametreleri bellekte bir blok ya da tabloda tutup bloğun adresini bir register'da geçirmek (Linux, Solaris).
  - Parametreleri program yığına (stack) push eder, işletim sistemi pop eder.
  - Blok ve yığın yöntemleri parametre sayısını ve uzunluğunu sınırlamaz.
- Sistem çağrısı türleri (ekrandan, 01:13:00)
  - Süreç kontrolü, dosya işlemleri, aygıt işlemleri, bilgi bakımı, haberleşme, koruma.
  - Windows ve Unix karşılıkları: `CreateProcess()`/`fork()`, `ReadFile()`/`read()`, `CreatePipe()`/`pipe()`, `SetFileSecurity()`/`chmod()` gibi.
- Standart C kütüphanesi örneği (ekrandan, 01:14:30)
  - `printf("Greetings");` kullanıcı modunda standart C kütüphanesine gider, kütüphane çekirdek modunda `write()` sistem çağrısını çağırır.
  - `printf` ekrana basılan karakter sayısını döndürür.
- İşletim sistemi örnekleri
  - MS-DOS: tek görevli (single tasking); açılışta komut yorumlayıcısı yüklenir, program boş belleğe yüklenir, bitince kabuk yeniden yüklenir.
  - FreeBSD: Unix türevi, çok görevli; kabuk `fork` ile yeni süreçler oluşturur. Programlar hatasız biterse 0, hatalıysa sıfırdan büyük bir değer döndürür.
- Sistem programları
  - Dosya yönetimi, durum bilgisi (tarih, saat, loglar), dosya değişikliği, programlama dili desteği (derleyici, assembler, debugger), program yükleme ve çalıştırma, haberleşme, arka plan servisleri.
  - Windows kayıt defteri (regedit) bir durum bilgisi aracı değil, programların ayarlarını tutan basit bir veritabanıdır.
- İşletim sistemi tasarımı ve gerçekleştirimi
  - Tasarım "çözülebilir" (solvable) bir problem değildir: Her işletim sistemini üreten tek bir algoritma yoktur; başarılı olduğu kanıtlanmış yaklaşımlar vardır.
  - Kullanıcı hedefleri (kolay kullanım, güvenilirlik, güvenlik, hız) ve sistem hedefleri (kolay tasarım, gerçekleştirim, bakım, esneklik, verimlilik).
  - Politika (ne yapılacak) ile mekanizma (nasıl yapılacak) ayrılmalıdır.
  - Dil: önce assembly, sonra Algol ve PL/1, bugün C/C++ (Rust da kullanılmaya başlandı); üst düzey sistem programları Python, Perl gibi dillerle yazılabilir.
- İşletim sistemi yapıları
  - Basit yapı (MS-DOS): modüllere ayrılmamış, uygulamalar donanıma doğrudan erişebilir.
  - Geleneksel Unix: kullanıcı, sistem çağrısı arayüzü, çekirdek ve çekirdek-donanım arayüzü olarak ayrılmış ama tam katmanlı değil.
  - Katmanlı yaklaşım: katman 0 donanım; her katman yalnız altındakinden hizmet alır. Modüler, bakımı ve hata bulması kolay (MVC benzetmesi).
  - Mikroçekirdek (microkernel): çekirdekte yalnız süreçler arası iletişim, bellek yönetimi ve CPU zamanlama; dosya sistemi ve sürücüler kullanıcı modunda, mesajlarla haberleşir (ekrandan, 01:47:00). Örnek: Mach. Dezavantajı kullanıcı-çekirdek geçişlerinin getirdiği ek yük.
  - Yüklenebilir çekirdek modülleri (Linux, Solaris).
  - Hibrit sistemler: Windows (büyük ölçüde monolitik), macOS (Mach, BSD, I/O Kit, çekirdek uzantıları), iOS, Android (değiştirilmiş Linux çekirdeği, güç yönetimi, Dalvik sanal makinesi).
- Hata ayıklama ve başarım ayarı
  - Log dosyaları; uygulama çökünce core dump, çekirdek çökünce crash dump.
  - Kaynak kullanım istatistikleri ile darboğazları bulma (Görev Yöneticisi).
  - Kernighan yasası: Hata ayıklamak, kodu yazmaktan iki kat zordur.
- Sistem üretimi ve önyükleme
  - SYSGEN, kurulumda donanımı tanıyıp çekirdeği yapılandırır.
  - Önyükleme iki aşamalıdır: ROM'daki önyükleme kodu çalışır, ardından bootstrap loader diskin bilinen bir bölgesinden (Master Boot Record, boot block) çekirdeği bulup belleğe yükler. Yaygın bir bootstrap loader GRUB'dur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kullanıcı donanıma doğrudan erişemez
  - Erişebilseydi işlemci süresini ve bellek miktarını kullanıcının ayarlaması gerekirdi; bu optimizasyonu bir programcının yapması mümkün değildir. İşletim sisteminin anlamı kalmazdı.
- API ile sistem çağrısı farklıdır
  - `printf`, `fopen`, `fread` birer API'dir; kendileri sistem çağrısı değildir, sistem çağrısını çağırırlar. Sistem çağrısının numarasını bilemeyeceğimiz için üst düzey fonksiyonları kullanırız.
- Sistem çağrıları küçük ve basit olmalıdır
  - Çok parametreli bir sistem çağrısı parametre geçişini zorlaştırır ve sorun çıkarması muhtemeldir.
- Çekirdekte ne kadar servis olmalı?
  - Gereğinden fazla servis çekirdeği hantallaştırır; gereğinden az servis ise yükü uygulama katmanına kaydırır (her yazıcı için ayrı uygulama gerekmesi gibi). Amaca uygun ölçü seçilmelidir.
- Saf tek bir model yoktur
  - Modern sistemler mikroçekirdek, yüklenebilir modül ve monolitik yapıları ihtiyaca göre birleştiren hibrit yapılardır. Hoca dönem boyunca "hangisi daha iyi?" sorusunu sık soracağını söyledi.
- İşletim sistemi bir yazılım mühendisliği örneğidir
  - Gereksinim analizinden gerçekleştirime kadar bütün süreçleri iyi bir yazılım mühendisliği ürünü olarak incelenebilir; güncelleme gelince sistemi baştan kurmak gerekmez.

## Kısa Tekrar Notları

- Katmanlar: kullanıcı arayüzü → sistem çağrısı arayüzü → işletim sistemi servisleri → donanım.
- Arayüz türleri: CLI, GUI, batch.
- Servisler: program çalıştırma, G/Ç, dosya sistemi, haberleşme, hata algılama, kaynak tahsisi, muhasebe, koruma ve güvenlik.
- API (Win32, POSIX) → sistem çağrısı → servis → donanım.
- Sistem çağrısı numarası ile çekirdekteki rutin bulunur.
- Parametre geçirme: register, bellek bloğu (adresi register'da), yığın.
- `printf` → standart C kütüphanesi → `write()`; `printf` yazdığı karakter sayısını döndürür.
- MS-DOS tek görevli, FreeBSD çok görevli.
- Sistem programları sistem çağrısı değildir.
- Politika ne yapılacağını, mekanizma nasıl yapılacağını belirler.
- Yapılar: basit, geleneksel Unix, katmanlı, mikroçekirdek, modüler, hibrit.
- Core dump: uygulama; crash dump: çekirdek.
- Önyükleme iki aşamalı; MBR, GRUB.

## Detaylı Açıklamalar

- **Dosya kopyalama örneği.** Slayttaki örnekte (ekrandan, 00:42:30) bir kaynak dosyanın içeriğini hedef dosyaya kopyalamak için yapılan sistem çağrıları dizisi şöyledir:

  ```text
  Girdi dosyasının adını al
    Ekrana istem yaz
    Girdiyi kabul et
  Çıktı dosyasının adını al
    Ekrana istem yaz
    Girdiyi kabul et
  Girdi dosyasını aç
    dosya yoksa iptal et
  Çıktı dosyasını oluştur
    dosya varsa iptal et
  Döngü
    Girdi dosyasından oku
    Çıktı dosyasına yaz
  Okuma başarısız olana kadar
  Çıktı dosyasını kapat
  Ekrana tamamlandı mesajı yaz
  Normal sonlan
  ```

  Ekrana yazma, girdi alma, dosya açma ve okuma yazma adımlarının her birinde bir sistem çağrısı görev alır.
- **Sistem çağrısının gerçekleşmesi.** Kullanıcı programı örneğin `fopen` çağırdığında kullanıcı modundadır. Gerçek işi yapan çağrı için sistem çekirdek moduna geçer, çağrının numarasına göre çekirdekteki fonksiyon bulunur ve çalıştırılır; fonksiyon dönene kadar beklenir. Sonuç olarak dosyanın açıldığı ya da açılamadığı (erişim hakkı yok, dosya yok, donanım hatası) bildirilir. Bir veritabanına bağlanmak da aynı mantıkla bağlantı açıldı ya da açılamadı yanıtıyla sonuçlanır. Ders arasında bir soruya verilen yanıta göre sistem çağrısı numaraları onaltılık tabanda gösterilir ama bilgisayarda ikilik olarak saklanır.
- **Fonksiyon çağrısı ve yığın.** Ana program `fx`'i, `fx` de `gx`'i çağırdığında her çağrıda dönüş adresi ve yerel değişkenlerin durumu yığına push edilir; fonksiyonlardan dönüldükçe pop edilerek eski yere gelinir. Dönüş adresini tek bir register'da (örneğin AX) tutmak iç içe çağrıda adresin üzerine yazılmasına yol açar. Sistem çağrılarında parametrelerin bu yüzden blok ya da yığın yöntemiyle geçirilmesi gerekir.
- **Standart C kütüphanesi.** Slayttaki örnekte (ekrandan, 01:14:30) `main` içinde `printf("Greetings");` çağrısı kullanıcı modundaki standart C kütüphanesine gider, kütüphane çekirdek modundaki `write()` sistem çağrısını çağırır ve sonuç programa döner. `fprintf` kullanılsaydı hedef dosyanın da (dosya işaretçisi) `write`'a parametre olarak verilmesi gerekirdi. Hocanın önerdiği deneme ajan tarafından yapıldı: `printf("Greetings")` 9 döndürür (scratchpad'de `gcc -Wall` ile derlenip çalıştırıldı).
- **Mikroçekirdek.** Slayttaki şemada (ekrandan, 01:47:00) uygulama programı, dosya sistemi ve aygıt sürücüsü kullanıcı modundadır ve mikroçekirdek üzerinden mesajlarla haberleşir. Çekirdekte yalnız süreçler arası iletişim, bellek yönetimi ve CPU zamanlama bulunur. Okuma yazma gibi servisler çekirdekte olmadığı için kullanıcı modu ile çekirdek modu arasında sık geçiş olur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
