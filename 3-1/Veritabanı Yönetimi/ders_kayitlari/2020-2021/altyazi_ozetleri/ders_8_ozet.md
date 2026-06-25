# Ders 8 Çalışma Özeti

## Genel Konular

- **Veri Bütünlüğü (Data Integrity)**
  - Veritabanının tutarlılığını ve doğruluğunu sağlamak için kullanılan mekanizmalar
  - Built-in kısıtlar: Domain kısıtı, Primary Key kısıtı, Referential Integrity kısıtı
  - Bu kısıtlar sistemin varsayılan olarak sağladığı temel güvencelerdir
  - İşletim sistemi ve uygulama düzeyinin ötesinde, veritabanı düzeyinde ek korumalar gerekir

- **Assertion (Sağlama İfadesi)**
  - Veritabanı üzerinde özel kurallar tanımlamak için kullanılır
  - SQL ile yazılan program parçacıklarıdır
  - Genel grameri: `CREATE ASSERTION [isim] CHECK (koşul)`
  - Koşullar genellikle `NOT EXISTS` veya `EXISTS` içerir
  - Sağlanmadığında ilgili işleme izin verilmez, hata mesajı verilir

- **Assertion Örnekleri**
  - **Maaş Kısıtı (Salary Constraint):** Bir işçinin maaşı, çalıştığı departmanın yöneticisinin maaşından büyük olamaz
  - **Kayıt Sayısı Kısıtı:** Her bir section'daki öğrenci sayısı 30'u geçemez
  - **Mezuniyet Yılı Kısıtı:** Mezuniyet yılı belirli bir tarihten önce olamaz (yanlış girişleri engeller)
  - **Tek Ders Kısıtı:** Bir öğrenci aynı dersin birden fazla section'ından kayıt yaptıramaz

- **Trigger'lar (Tetikleyiciler)**
  - Veri bütünlüğünü daha detaylı ve aktif olarak sağlayan program parçacıklarıdır
  - Üç temel bileşen: Event (hadise), Condition (şart), Action (eylem)
  - Olaylar: INSERT, UPDATE, DELETE (sadece写ma işlemleri, okuma tetiklemez)

- **Trigger Zamanlaması**
  - BEFORE: İşlemden önce kontrol veya değişiklik
  - AFTER: İşlemden sonra tetikleme
  - INSTEAD OF: İşlem yerine alternatif bir eylem yapılması

- **Trigger Çalışma Düzeyi**
  - FOR EACH ROW (Satır bazlı): Değişen her satır için ayrı çalışır, yazılması daha kolay
  - FOR EACH STATEMENT (Ifade bazlı): Tüm ifade için bir kez çalışır, performans açısından daha avantajlı
  - Statement bazlı trigger'larda OLD ve NEW tabloları kullanılır (tablonun eski ve yeni halleri)
  - Row bazlı trigger'larda eski ve yeni satır değerleri referans edilir

- **Trigger Örnekleri**
  - **Log Grade Change:** Not değişikliklerini log dosyasına kaydeder (aynı not girilmezse loglama yapılmaz)
  - **Fix Invalid Grad Year:** Yanlış mezuniyet yılı girildiğinde otomatik düzeltme yapar
  - **Salary-Supervisor Kontrolü:** İşçinin maaşı, süpervizörünün maaşından yüksekse bilgilendirme yapar
  - **Total Salary Bakımı:** Departmandaki toplam maaş bilgisinin tutarlılığını 4 farklı trigger ile sağlar

- **Toplam Maaş (Total Salary) Bakım Trigger'ları**
  - **T1 (Insert):** Yeni işçi eklendiğinde ilgili departmanın toplam maaşını günceller
  - **T2 (Update):** Maaş değişikliğinde toplam maaşı günceller (FOR EACH ROW ve FOR EACH STATEMENT versiyonları gösterilmiştir)
  - **T3 (Delete):** İşçi silindiğinde toplam maaşı azaltır
  - **T4 (Transfer):** İşçi departman değiştirdiğinde hem eski hem yeni departmanın toplam maaşını günceller

- **Veritabanı Güvenliği**
  - **Authentication (Kimlik Doğrulama):** Kullanıcının gerçekten o kişi olduğunun ispatlanması (şifre, parmak izi vb.)
  - **Authorization (Yetkilendirme):** Doğrulanmış kullanıcının ne yapabileceğinin belirlenmesi

- **Yetkilendirme Yöntemleri**
  - **Discretionary Access Control (DAC) - Takdire Dayalı Erişim Kontrolü:**
    - Her kullanıcıya tablo/seviye bazında yetki tanımlanır
    - Yetkiler SQL ile `GRANT` ve `REVOKE` komutlarıyla yönetilir
    - Sahip olduğu yetkileri başkalarına aktarabilir (propagate)
    - Zayıf yönü: Yetkisi olan kişi veriyi kopyalayıp başkasına verebilir
  - **Mandatory Access Control (MAC) - Zorlayıcı Erişim Kontrolü:**
    - Hem kullanıcının hem de verinin güvenlik seviyesi vardır
    - Veri güvenlik seviyeleri: Top Secret, Certified, Public vb.
    - Kullanıcı yetki seviyesi, verinin güvenlik seviyesinin eşit veya üstünde olmalıdır
    - Veri kopyalansa bile güvenlik seviyesi korunur
    - DAC'a göre daha güvenlidir ama gerçekleştirilmesi daha zordur

- **Yetkiler (Privileges)**
  - Temel yetkiler: SELECT, INSERT, DELETE, UPDATE, REFERENCES, USAGE, TRIGGER, EXECUTE
  - Roller (Role) tanımlayarak yetki yönetimi kolaylaştırılabilir
  - Kullanıcılar birden fazla rolde olabilir
  - Roller kişi sayısına göre çok daha azdır, yönetimi basitleştirir

## Hocanın Özellikle Vurguladığı Kısımlar

- SQL'in bilgisayar bilimleri dünyasında 30-40 yıllık geçmişi olan vazgeçilmez bir sorgulama dili olduğu
- Temel sorgulama bilgilerinin ileriye taşınması gerektiği, bundan sonra öğrencilerin kendi gayretlerine kaldığı
- Sonraki konuların "yönetim, koordinasyon, güvenlik" ağırlıklı olacağı
- Assertion'ların yazıldıktan sonra zıt bir komut yazılarak test edilmesi gerektiği
- FOR EACH ROW'un yazılması kolay ama FOR EACH STATEMENT'in performans açısından daha avantajlı olduğu
- Toplam maaş (Total Salary) gibi türetilmiş niteliklerin veritabanında saklanmasının tehlikeli olduğu ve bütünlük mekanizmalarıyla korunması gerektiği
- For each statement trigger'larının, salary ve department'ın aynı anda değiştiği senaryoları daha kapsamlı yakaladığı
- Güvenlik konusunun son senelerde çok daha aktif bir çalışma konusu haline geldiği
- Roller sayesinde yetki yönetiminin çok daha kolaylaştırılabileceği

## Kısa Tekrar Notları

- Assertion: `CREATE ASSERTION [isim] CHECK (NOT EXISTS / EXISTS ile koşul)`
- Trigger yapısı: Event → Condition → Action
- Trigger türleri: BEFORE, AFTER, INSTEAD OF
- Çalışma düzeyleri: FOR EACH ROW (satır bazlı) vs FOR EACH STATEMENT (ifade bazlı)
- DAC: Kullanıcıya yetki verilir, veri güvenliği kullanıcıya bağlıdır
- MAC: Kullanıcı ve veri için güvenlik seviyesi tanımlanır, daha katı bir kontrol sağlar
- GRANT ile yetki verilir, REVOKE ile yetki alınır
- Roller ile yetki yönetimi basitleştirilir

## Detaylı Açıklamalar

### Assertion Mekanizması

Assertion'lar, veritabanı üzerinde tanımlanan özel kısıtlardır. Built-in kısıtlardan (primary key, foreign key, domain kısıtları) farklı olarak, uygulamaya özgü iş kurallarını ifade eder. Örneğin, bir işçinin maaşının çalıştığı departmanın yöneticisinin maaşından yüksek olmaması kuralı, standart veritabanı kısıtlarıyla tanımlanamaz. Bu tür kurallar assertion'larla ifade edilir.

Bir assertion yazdıktan sonra test etmek için, o assertion'a zıt düşen bir INSERT veya UPDATE komutu çalıştırılabilir. Eğer assertion doğru çalışıyorsa, bu işlem hata vermelidir.

### Trigger ve Veri Bütünlüğü İlişkisi

Trigger'lar, veri bütünlüğünüAssertion'lardan daha aktif bir şekilde sağlar. Assertion'lar pasif bir kontrol sağlarken, trigger'lar belirli bir olay gerçekleştiğinde otomatik olarak devreye girer. Bu, özellikle birden fazla tabloyu etkileyen değişikliklerde önemlidir.

Toplam maaş örneğinde görüldüğü gibi, bir tablodaki değişiklik (Employee tablosunda maaş değişikliği) başka bir tablodaki veriyi (Department tablosundaki toplam maaş) etkileyebilir. Bu tür çapraz etkileşimler trigger'larla yönetilir.

### FOR EACH ROW vs FOR EACH STATEMENT

FOR EACH ROW, bir UPDATE veya INSERT ifadesinin etkilediği her satır için ayrı ayrı çalışır. Bu, çoğu zaman yazılması daha kolaydır çünkü mevcut satıra (NEW) ve eski satıra (OLD) doğrudan erişilir.

FOR EACH STATEMENT ise tüm ifade için bir kez çalışır. Birden fazla satır etkilendiğinde bu yöntem daha hızlıdır çünkü tetikleme sayısı azalır. Ancak yazması daha zor olabilir çünkü eski ve yeni tablo halleri (OLD ve NEW tabloları) üzerinde çalışılır.

### Güvenlik Yaklaşımları

DAC'de yetki tanımları kullanıcıya özeldir. Bir kullanıcıya verilen yetki, o kullanıcı tarafından başkasına aktarılabilir. Bu esnek bir sistemdir ancak güvenlik açığı yaratabilir - yetkisi olan bir kişi veriyi kopyalayıp güvensiz bir ortamda paylaşabilir.

MAC'de ise hem kullanıcının hem de verinin bir güvenlik seviyesi vardır. Veri "Top Secret" olarak etiketlendiyse, bu veriye yalnızca o seviyede veya daha yüksek yetkisi olan kullanıcılar erişebilir. Veri herhangi bir yere kopyalansa bile güvenlik etiketi korunur, bu da MAC'i daha güvenli ancak gerçekleştirilmesi daha zor yapar.

### Rol Tabanlı Yetki Yönetimi

Gerçek hayatta binlerce kullanıcı ve onlarca tablo vardır. Her bir kullanıcıya tek tek yetki tanımlamak hem zaman alıcıdır hem de hata yapmaya açıktır. Roller (role) tanımlayarak bu sorun çözülür. Örneğin "Dekan" rolü, "Profesör" rolü, "Öğrenci" rolleri tanımlanır. Her role belirli yetkiler verilir, ardından kullanıcılar bu rollere atanır. Bir kişi hem Dekan hem de Profesör rolünde olabilir. Kişiler değiştiğinde rollerin yeniden tanımlanmasına gerek kalmaz, sadece yeni kişi ilgili role atanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
