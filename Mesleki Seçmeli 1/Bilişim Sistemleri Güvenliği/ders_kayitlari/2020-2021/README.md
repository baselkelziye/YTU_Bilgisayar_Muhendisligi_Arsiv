# Bilişim Sistemleri Güvenliği Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

### Genel Bilgiler

* **Ders:** Bilişim Sistemleri Güvenliği
* **Hoca:** Ali Gökhan Yavuz
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Bilişim sistemleri güvenliğinin temel problemi | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Kontrol akışını ele geçirme saldırıları | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Kontrol ve verinin karışması | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Güvenli tasarım ilkelerine giriş | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Unix/Linux güvenlik modelinin genişletilmesi | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 5 (Lab)** | Buffer overflow uygulama mantığı | [Özet](altyazi_ozetleri/ders_5_lab_ozet.md) | [PDF (İndir)](ders_5_lab_ozet.pdf) |
| **Ders 6** | Web güvenlik modeline giriş | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Cookie tabanlı saldırılar | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 7 (Lab)** | SQL injection laboratuvar ortamı | [Özet](altyazi_ozetleri/ders_7_lab_ozet.md) | [PDF (İndir)](ders_7_lab_ozet.pdf) |
| **Ders 9** | Ağ güvenliğine giriş | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 9 (Lab)** | SQL injection seviyelerinin derinleştirilmesi | [Özet](altyazi_ozetleri/ders_9_lab_ozet.md) | [PDF (İndir)](ders_9_lab_ozet.pdf) |
| **Ders 10** | ARP güvenliği | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 10 (Lab)** | Ağ saldırılarının gözlemlenmesi | [Özet](altyazi_ozetleri/ders_10_lab_ozet.md) | [PDF (İndir)](ders_10_lab_ozet.pdf) |
| **Ders 11** | Ağ saldırılarına karşı savunma | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 13** | Akademik içerik bulunmayan kayıt | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | Sertifika ve açık anahtar altyapısı | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

## Derslerin Detaylı Özetleri ve Kazanımları

### Ders 1: Bilişim sistemleri güvenliğinin temel problemi

#### Genel Konular

- Bilişim sistemleri güvenliğinin temel problemi
  - Yazılım hataları, sosyal mühendislik ve saldırı ekonomisi güvenlik risklerinin ana kaynakları olarak ele alınır.
  - Her hata aynı düzeyde risk üretmez; uygulamanın kontrol akışını değiştirmeye veya yetkisiz kod çalıştırmaya izin veren hatalar zafiyet niteliği kazanır.
- Güncel zafiyet ekosistemi
  - İşletim sistemleri, tarayıcılar, mobil platformlar, ofis yazılımları, PDF okuyucuları ve eklenti teknolojileri yaygın kullanım nedeniyle yüksek saldırı yüzeyine sahiptir.
  - Zafiyetlerin sayısı kadar yaygın kurulum tabanı da önemlidir; çok kullanılan ürünlerdeki tek bir açık çok geniş etki alanı oluşturabilir.
- Sosyal mühendislik
  - E-posta, SMS, sosyal medya veya bağlantı üzerinden gelen yönlendirmeler kullanıcıyı kimlik bilgisi paylaşmaya veya zararlı yazılım çalıştırmaya ikna edebilir.
  - Teknik güvenlik mekanizmaları kullanıcı davranışındaki zayıflıklarla aşılabilir.
- Saldırı ekonomisi
  - Zafiyet bulma, ele geçirilmiş makine kiralama, zararlı yazılım yükletme, veri çalma ve fidye yazılımı faaliyetleri ekonomik değer üretir.
  - Kripto para benzeri ödeme araçları saldırı pazarlarını kolaylaştırabilir.
- Zoom örneği üzerinden yerel servis zafiyeti
  - Tarayıcı ile yerel uygulama arasındaki bağlantıda yerel web sunucusu kullanılması saldırı yüzeyi oluşturabilir.
  - Herhangi bir web sitesinin yerel servise istek gönderebilmesi, kullanıcı bilgisi dışında toplantıya katılma veya istemciyi başlatma gibi davranışlara yol açabilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Kriptografi kütüphanesi kullanmak tek başına güvenlik anlamına gelmez
  - Şifreleme doğru protokol, doğru anahtar yönetimi ve doğru kullanım modeliyle anlamlıdır.
- Zafiyet değerlendirmesinde etki belirleyicidir
  - Basit hata ile kontrol akışını ele geçirmeye izin veren hata aynı kategoride düşünülmemelidir.
- Yaygınlık riski büyütür
  - Tarayıcı, Android, Office, PDF ve toplantı yazılımları çok kullanıldığı için saldırgan açısından cazip hedeflerdir.
- Güvenlik haberleri hem risk hem iyileştirme kaynağıdır
  - Ortaya çıkan zafiyetler mağduriyet üretir; fakat aynı zamanda ürünlerin daha sağlam hale getirilmesini sağlar.

#### Detaylı Açıklamalar

- Bilişim sistemleri güvenliğinde temel varsayım, karmaşık yazılımların hata içereceğidir. Hatalar algoritma seçiminden, kullanılan kütüphanelerden, sistem mimarisinden veya bileşenler arası etkileşimden kaynaklanabilir. Güvenlik açısından kritik olan, hatanın uygulamanın normal kontrol akışını değiştirip değiştirmediğidir.
- Sosyal mühendislik, teknik zafiyet kadar güçlü bir saldırı aracıdır. Kullanıcının o anda ilgilendiği konuyla uyumlu görünen bir mesaj, bağlantı veya form, kimlik ve banka bilgisi gibi hassas verilerin paylaşılmasına ya da zararlı kodun kurulmasına yol açabilir.
- Saldırıların arkasında ekonomik motivasyon bulunur. Ele geçirilmiş sistemler kiralanabilir, hedef makinelerde belirli kodların yüklenmesi için ödeme alınabilir, hassas veriler satılabilir veya veriler şifrelenerek fidye istenebilir.
- Zoom benzeri uygulamalarda tarayıcının yerel istemciyi başlatması kullanım kolaylığı sağlar; ancak yerel web sunucusu gibi ara mekanizmalar doğru sınırlandırılmazsa başka web siteleri bu mekanizmaya istek gönderebilir. Bu durum güvenlik tasarımında otomasyon ile yetki kontrolünün birlikte düşünülmesi gerektiğini gösterir.
### Ders 2: Kontrol akışını ele geçirme saldırıları

#### Genel Konular

- Kontrol akışını ele geçirme saldırıları
  - Saldırganın amacı hedef sistemde çalışan bir servisin veya programın kontrol akışını değiştirerek keyfi kod çalıştırmaktır.
  - Web, mail, DNS gibi sürekli çalışan servisler doğal saldırı vektörleri oluşturur; ancak kısa süreli çalışan programlarda da benzer zafiyetler bulunabilir.
- Temel zafiyet türleri
  - Buffer overflow, integer overflow, format string vulnerability, use after free ve double free kontrol akışını değiştirmede kullanılabilecek zafiyet türleri olarak ele alınır.
  - Buffer overflow genellikle en temel ve uygulanabilir örnek olarak anlatılır; format string zafiyetleri daha çok hassas veri sızdırma veya sınırlı kontrol elde etme amacıyla da kullanılabilir.
- Buffer overflow tarihçesi
  - Unix finger servisine yönelik ilk solucan örnekleri, bellek taşması zafiyetlerinin ağ üzerinde yayılabilen saldırılara dönüşebileceğini gösterir.
  - Bir zafiyetin etkisi yalnızca zafiyet sayısıyla değil, zafiyetli yazılımın kaç sistemde çalıştığıyla belirlenir.
- C/C++ ve çalışma zamanı ortamı
  - İşletim sistemleri, sistem kütüphaneleri ve çalışma zamanı bileşenlerinin büyük bölümü C/C++ ile yazıldığı için bellek güvenliği zafiyetleri güncel sistemleri etkilemeye devam eder.
  - Daha güvenli diller kullanılsa bile alt katmanda C/C++ kütüphaneleri bulunduğunda risk tamamen ortadan kalkmaz.
- Bellek düzeni ve stack frame
  - 32 bit Linux örneği üzerinden proses adres alanı, stack, heap, shared library bölgesi ve executable bölgesi açıklanır.
  - Stack frame; argümanlar, dönüş adresi, stack frame pointer, yerel değişkenler ve saklanan register değerlerinden oluşur.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Uygulama değil kontrol akışı ele geçirilir
  - Saldırgan programın tasarlanan davranışını bozarak kendi istediği kodu çalıştırır.
- Attack vector input kabul eden noktadır
  - Bir fonksiyon veya servis dış girdiyi kabul etmiyorsa o noktadan saldırı yapmak mümkün değildir.
- Stack düzeni saldırıyı anlamak için kritiktir
  - Dönüş adresinin stack üzerinde tutulması, taşan verinin kontrol bilgisine ulaşmasını mümkün kılar.
- Mimari bilgisi saldırı hazırlığında önemlidir
  - İşlemci komut seti, endian düzeni, işletim sistemi ve stack frame biçimi exploit kodunun çalışabilirliğini belirler.

#### Detaylı Açıklamalar

- Kontrol akışını ele geçirme saldırılarında saldırgan, hedef programın beklediği girdiyi manipüle ederek programın başka bir kod parçasını çalıştırmasını sağlar. Bu kod parçası çoğu zaman shellcode veya benzeri küçük bir makine kodudur.
- Buffer overflow örneğinde yerel buffer için ayrılan alanın sınırı aşılır. Eğer sınır kontrolü yoksa fazla veri stack üzerindeki dönüş adresine kadar ilerleyebilir. Dönüş adresi saldırganın belirlediği adrese çevrildiğinde fonksiyon dönüşünde kontrol saldırgan koduna geçer.
- C/C++ ortamında pointer kullanımı, manuel bellek yönetimi, sınır kontrolünün programcıya bırakılması ve düşük seviyeli sistem kütüphanelerinin yaygınlığı bu saldırı sınıfını önemli hale getirir. Modern diller üst seviyede güvenli görünse bile çalışma zamanı ve sistem çağrıları bu düşük seviyeli bileşenlerle etkileşir.
- Bellek düzeninin bilinmesi saldırgan için değerlidir. Paylaşılan kütüphanelerin yüklenme bölgesi, executable başlangıcı, stack büyüme yönü ve endian düzeni exploit oluşturma sürecinde doğrudan kullanılır.
### Ders 3: Kontrol ve verinin karışması

#### Genel Konular

- Kontrol ve verinin karışması
  - Buffer overflow, heap spraying, use after free, integer overflow ve format string saldırılarının temelinde veri ile kontrol bilgisinin aynı alanda veya aynı kanalda yorumlanması problemi bulunur.
  - Return address gibi kontrol verilerinin kullanıcı girdisiyle değiştirilebilir alanda tutulması kritik risk doğurur.
- In-band ve out-of-band kontrol
  - Uygulama verisiyle kontrol bilgisinin aynı kanaldan taşınması in-band kontrol olarak açıklanır.
  - Kontrol bilgisinin ayrı kanaldan taşınması out-of-band yaklaşımdır ve bazı saldırı sınıflarını azaltabilir.
- Captain Crunch analojisi
  - Telefon sistemlerinde ödeme bilgisinin konuşma hattıyla aynı kanaldan sinyallenmesi, sahte sinyalle sistemin kandırılmasına yol açmıştır.
  - Bu örnek, kontrol verisi ile kullanıcıya açık veri kanalının karışmasının bilgisayar güvenliğindeki karşılığına benzetilir.
- Savunma yaklaşımları
  - Hataları bulma ve düzeltme, type-safe diller kullanma, platform seviyesinde savunma ve uygulamaya runtime kontrol ekleme ana yaklaşımlar olarak ele alınır.
  - Savunmalar çoğu zaman tam ele geçirmeyi engeller; ancak saldırıyı hizmet kesintisine dönüştürebilir.
- Platform savunmaları
  - Kod enjekte edilen girdinin çalıştırılmasını engellemek, bellek bölgelerini çalıştırılamaz yapmak ve adres tahminini zorlaştırmak platform düzeyinde savunmanın temel mantığıdır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Asıl tasarım hatası data ve control bilgisini karıştırmaktır
  - Güvenli tasarımda kullanıcı verisi ile kontrol verisi mümkün olduğunca ayrılmalıdır.
- In-band kontrol kolaydır ama risklidir
  - Aynı kanalın hem veri hem kontrol amacıyla kullanılması pratik görünse de saldırganın kontrol bilgisini taklit etmesine yol açabilir.
- Savunmalar mutlak güvenlik sağlamaz
  - Çoğu savunma tam ele geçirmeyi engelleyip programın çökmesine neden olur; bu yine de daha kabul edilebilir bir sonuçtur.
- Type-safe dil tek başına yeterli değildir
  - Çalışma zamanı ortamı veya sistem kütüphaneleri C/C++ ile yazılmışsa zafiyet devam edebilir.

#### Detaylı Açıklamalar

- Stack smashing saldırısında return address, yerel değişkenlere komşu bir alanda bulunduğu için taşan veri tarafından değiştirilebilir. Bu, kullanıcı verisinin kontrol bilgisini ezmesidir. Use after free örneğinde ise serbest bırakılmış nesne alanının saldırgan tarafından vtable biçimine uygun veriyle doldurulması benzer şekilde kontrol akışını etkiler.
- In-band kontrol, mevcut iletişim kanalını yeniden kullanarak sistem tasarımını basitleştirir. Ancak kanal kullanıcı tarafından etkilenebiliyorsa saldırgan kontrol sinyalini taklit edebilir. Captain Crunch örneği, bilgisayar dışı bir sistemde aynı tasarım hatasının nasıl istismar edildiğini gösterir.
- Savunma üretirken yalnızca zafiyeti kapatmak değil, zafiyetin neden oluştuğunu anlamak gerekir. Mevcut kodu tamamen yeniden yazmak çoğu durumda maliyetlidir; bu nedenle platform seviyesinde DEP/NX, ASLR benzeri mekanizmalar veya uygulama içine eklenen runtime kontroller pratik hale gelir.
- Güvenlik tedbirlerinin önemli bir bölümü saldırganın kod çalıştırmasını engeller; ancak yanlış girdi geldiğinde programı durdurabilir. Bu durum hizmet kesintisi anlamına gelse de sistemin tamamen ele geçirilmesinden daha düşük risklidir.
### Ders 4: Güvenli tasarım ilkelerine giriş

#### Genel Konular

- Güvenli tasarım ilkelerine giriş
  - Hataların tamamen ortadan kaldırılamayacağı kabul edilerek zafiyetlerin etkisini sınırlandıracak kurallar ele alınır.
  - Tehdit modelini bilmek, hangi saldırıların nasıl gerçekleşebileceğini anlamak için temel gerekliliktir.
- Defense in depth
  - Tek bir savunma mekanizması yerine farklı katmanlarda birbirini tamamlayan mekanizmalar kullanılmalıdır.
  - Tarayıcı sekmesi izolasyonu, işletim sistemi proses izolasyonu, firmware koruması ve ağ içi yayılım engelleme aynı saldırıya karşı farklı katmanlardaki örneklerdir.
- Least privilege
  - Bir öznenin görevini yerine getirebilmesi için gereken minimum yetki, aynı zamanda sahip olması gereken maksimum yetkiyi tanımlar.
  - Gereğinden fazla yetki, hata, kötü niyet veya sistem ele geçirilmesi durumunda zararı büyütür.
- Privilege separation
  - Sistem, farklı yetki gereksinimlerine sahip bileşenlere ayrılmalıdır.
  - Bir bileşenin ele geçirilmesi saldırganın tüm sistemi ele geçirmesini engelleyecek şekilde sınırlandırılmalıdır.
- Subject, object, operation modeli
  - Güvenlik kuralları; işlemi yapan özne, üzerinde işlem yapılan nesne ve gerçekleştirilen operasyon üçlüsüyle ifade edilir.
  - Kullanıcı, proses, uygulama, domain veya cihaz subject olabilir; dosya, bellek, cookie, donanım ve ağ kaynağı object olabilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Tek hat savunması yeterli değildir
  - Farklı katmanlarda bağımsız ama tamamlayıcı savunma gerekir.
- Minimum yetki maksimum yetkidir
  - Görev için gerekmeyen hiçbir yetki verilmemelidir.
- Privilege separation saldırıyı hapseder
  - Bir modül ele geçirilse bile diğer modüllere geçiş engellenebilir.
- Subject-object-operation üçlüsü güvenlik analizinin temelidir
  - Bir ihlalde hangi öznenin, hangi nesne üzerinde, hangi işlemi hatalı yapabildiği sorulmalıdır.

#### Detaylı Açıklamalar

- Python gibi type-safe dillerde bile alt katmanda C ile yazılmış modüller bulunabilir. Python zipimport örneği, negatif veri boyutu üzerinden integer overflow ve heap tabanlı buffer overflow oluşabileceğini gösterir. Bu nedenle güvenli dil seçimi önemli olsa da tek başına yeterli kabul edilmez.
- Defense in depth yaklaşımı, bir zafiyet başarılı olsa bile zararın yayılmasını engellemeyi hedefler. Chrome örneğinde JavaScript yorumlayıcıdaki hata tek sekmeyle sınırlanmalı, işletim sistemi diğer proseslere erişimi engellemeli, donanım firmware kalıcılığını önlemeli ve ağ katmanı zararlının komşu sistemlere yayılmasını durdurmalıdır.
- Least privilege, kullanıcıdan uygulamaya, prosesten domaine kadar her özne için geçerlidir. Örneğin bir domain yalnızca kendi cookie değerlerini okuyabilmelidir; bir uygulama başka uygulamanın verisini değiştirememelidir; bir proses başka prosesin belleğini okuyamamalıdır.
- Unix güvenlik modelinde subject olarak kullanıcılar ve prosesler, object olarak dosyalar ve dosya gibi temsil edilen kaynaklar, operation olarak read, write ve execute kullanılır. Bu model daha sonraki erişim kontrol mekanizmalarının temelini oluşturur.
### Ders 5: Unix/Linux güvenlik modelinin genişletilmesi

#### Genel Konular

- Unix/Linux güvenlik modelinin genişletilmesi
  - Dosya sistemi kökü, kullanıcı kimlikleri, servis hesapları, yetki denetimi ve sistem çağrıları güvenlik açısından değerlendirilir.
  - `chroot` benzeri sınırlandırma mekanizmalarının saldırganı dar bir dosya sistemi görünümüne hapsetme amacı açıklanır.
- Sandbox yaklaşımı
  - Güvenilmeyen kodun sınırlı kaynaklarla ve sınırlı sistem çağrılarıyla çalıştırılması temel savunma yöntemi olarak ele alınır.
  - Sandbox yalnızca dosya erişimi değil; bellek, ağ, proses ve kernel etkileşimi açısından da sınır koymalıdır.
- Sistem çağrıları ve kalıcı etki
  - Tüm sistem çağrıları aynı risk düzeyinde değildir; dosya yazma, proses sonlandırma, ağ erişimi ve yetki değiştirme gibi çağrılar daha dikkatli denetlenmelidir.
  - Salt okuma davranışı bile hassas bilgi sızdırma riski oluşturabilir.
- Zararlı yazılım davranışları
  - Malware çalıştığı ortamı analiz ederek sandbox içinde olup olmadığını anlamaya çalışabilir.
  - Ortam tespiti, saldırı kodunun davranış değiştirmesine veya beklemeye geçmesine neden olabilir.
- Donanım ve bellek destekli savunmalar
  - Kullanıcı alanı, kernel alanı, TLB ve bellek erişim denetimleri güvenlik sınırlarının uygulanmasında kullanılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Sandbox mutlak güvenlik değildir
  - Saldırgan sandbox tespiti yapabilir veya izin verilen dar aralıktaki sistem çağrılarını kötüye kullanabilir.
- Kalıcı zararlı etki oluşturan çağrılar önceliklidir
  - Denetim mekanizmaları tüm çağrılara aynı sertlikte davranmak yerine riskli işlemlere odaklanmalıdır.
- Kullanıcı ve kernel alanı ayrımı kritiktir
  - Kernel alanına kaçış, sıradan uygulama zafiyetini sistem geneli ele geçirmeye dönüştürebilir.

#### Detaylı Açıklamalar

- Unix/Linux modelinde birçok kaynak dosya gibi temsil edildiği için erişim denetimi dosya sistemi kavramıyla yakından ilişkilidir. Kök dizin, kullanıcı kimliği, servis hesabı ve izinler birlikte düşünülür. `chroot`, bir prosesin görebildiği dosya sistemi ağacını değiştirerek saldırganın gerçek sistem dosyalarına ulaşmasını zorlaştırır.
- Sandbox yaklaşımı, güvenilmeyen kodun çalıştırılmasını tamamen yasaklamak yerine, etkisini sınırlı bir çevreye hapsetmeyi hedefler. Bu çevrede dosya erişimi, ağ erişimi, proses oluşturma, sistem çağrıları ve bellek erişimleri politika ile denetlenir.
- Sistem çağrılarının güvenlik etkisi farklıdır. Dosya açma çağrısı yalnızca okuma modunda daha düşük riskli görünse de hassas veri sızdırabilir; yazma, silme, proses öldürme veya yetki değiştirme ise kalıcı ve yıkıcı etki oluşturabilir.
- Zararlı yazılımlar sanal makine, sandbox, anormal zamanlama, kısıtlı donanım veya özel dosya izleri gibi göstergelerden analiz ortamında olduklarını anlayabilir. Bu nedenle sandbox tasarımında yalnızca kısıtlama değil, ortamın gerçekçi görünmesi de önemlidir.
### Ders 5 (Lab): Buffer overflow uygulama mantığı

#### Genel Konular

- Buffer overflow uygulama mantığı
  - Yerel buffer sınırının aşılması, stack üzerindeki kontrol verisinin değiştirilebilmesi ve shellcode çalıştırma fikri uygulamalı bağlamda ele alınır.
- Derleme ve çalışma zamanı etkileri
  - Derleyici seçenekleri, stack korumaları, yürütülebilir stack, ASLR ve canary mekanizmaları exploit davranışını değiştirir.
- Debug ve bellek gözlemi
  - Girdi uzunluğu, stack düzeni, dönüş adresi ve register değerleri debug araçlarıyla incelenir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Teori exploit üretmek için tek başına yetmez
  - Adresler, derleyici çıktısı ve çalışma zamanı korumaları pratikte kontrol edilmelidir.
- Koruma mekanizmaları bilinçli kapatıldığında saldırı gözlemlenebilir
  - Lab ortamı saldırıyı anlamak içindir; gerçek sistemlerde bu korumalar açık kalmalıdır.

#### Detaylı Açıklamalar

- Laboratuvar içeriğinde buffer overflow saldırısının yalnızca kavramsal değil, çalışma zamanı üzerinde nasıl gözlemlendiği vurgulanır. Girdi uzunluğu artırıldığında programın stack üzerinde hangi alanları ezdiği, dönüş adresinin nasıl etkilendiği ve saldırganın kontrol akışını nasıl yönlendirebildiği incelenir.
- Modern sistemlerde exploitin başarısı bellek korumalarıyla doğrudan ilişkilidir. ASLR adresleri rastgeleleştirir, stack canary dönüş adresinden önce beklenmeyen değişimi fark eder, NX/DEP veri alanlarının kod gibi çalıştırılmasını engeller. Bu mekanizmaların etkisini anlamak güvenli geliştirme ve zafiyet analizi için gereklidir.
### Ders 6: Web güvenlik modeline giriş

#### Genel Konular

- Web güvenlik modeline giriş
  - Web uygulamaları, tarayıcı, sunucu, cookie, JavaScript ve origin kavramları üzerinden erişim kontrolü incelenir.
  - Web modeli işletim sistemi güvenlik modeliyle benzer biçimde subject, object ve operation ilişkileriyle açıklanabilir.
- Cookie ve oturum yönetimi
  - Sunucu, istemciye cookie göndererek oturum durumunu tarayıcıda saklatır.
  - Tarayıcı sonraki isteklerde domain/path gibi kriterlere uyan cookie değerlerini sunucuya geri gönderir.
- Same Origin Policy
  - Bir kaynağın başka bir kaynağın içeriğini okuyup okuyamayacağı origin bilgisine göre sınırlandırılır.
  - Origin; protokol, domain ve port bileşiminden oluşur.
- Cookie erişim kuralları
  - Domain ve path kapsamı cookie'nin hangi isteklerde gönderileceğini belirler.
  - Yanlış kapsamlandırılan cookie daha geniş alanda kullanılabilir ve saldırı yüzeyini büyütür.
- Web üzerinden saldırı yüzeyi
  - Kötü niyetli site yönlendirmeleri, router ele geçirilmesi, zararlı içerik ve cookie ele geçirme riskleri değerlendirilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Cookie kimlik doğrulamanın kritik parçasıdır
  - Cookie ele geçirilirse oturumun ele geçirilmesi mümkündür.
- Same Origin Policy içerik okuma sınırıdır
  - Kaynağa istek atabilmek ile cevabın içeriğini okuyabilmek aynı şey değildir.
- Cookie kapsamı dikkatli belirlenmelidir
  - Domain ve path değeri gereğinden geniş seçilirse least privilege ihlal edilir.

#### Detaylı Açıklamalar

- Web uygulamalarında HTTP stateless olduğu için sunucu, kullanıcıyı sonraki isteklerde tanımak amacıyla cookie kullanır. Kullanıcı adı ve parola ile başarılı girişten sonra sunucu session değeri içeren bir cookie döndürebilir. Tarayıcı bu cookie'yi saklar ve uygun isteklerde tekrar gönderir.
- Same Origin Policy, web güvenliğinin temel erişim kontrol mekanizmasıdır. Bir sayfa başka kaynağa istek gönderebilir; ancak cevabın okunması origin politikasına bağlıdır. Bu ayrım CSRF, XSS ve cookie theft gibi saldırıları anlamak için önemlidir.
- Cookie'lerin domain ve path kapsamı doğru belirlenmezse bir alt alan adı veya farklı yol beklenmeyen cookie değerlerine erişebilir ya da onları gönderebilir. Bu nedenle cookie kapsamı en az yetki ilkesiyle uyumlu ayarlanmalıdır.
### Ders 7: Cookie tabanlı saldırılar

#### Genel Konular

- Cookie tabanlı saldırılar
  - Cookie theft, JavaScript üzerinden `document.cookie` erişimi ve cookie'nin saldırgan sunucusuna aktarılması açıklanır.
  - HTTPOnly ve Secure cookie bayrakları cookie güvenliğini artıran mekanizmalar olarak ele alınır.
- Cross-Site Request Forgery
  - Kullanıcının oturumu açıkken saldırganın başka bir site üzerinden hedef uygulamaya istek göndermesi CSRF olarak tanımlanır.
  - Tarayıcı uygun cookie'leri otomatik eklediği için hedef uygulama isteği meşru kullanıcıdan gelmiş sanabilir.
- CSRF savunmaları
  - Secret token validation ile her form veya işlem için tahmin edilemeyen, session'a bağlı token kullanılır.
  - Token statik olmamalı, oturum ve işlem bağlamıyla ilişkilendirilmelidir.
- SameSite cookie
  - Cookie'nin cross-site isteklerde gönderilip gönderilmeyeceğini belirleyen ek savunma katmanıdır.
  - Strict gibi modlar CSRF riskini azaltır.
- SQL injection giriş
  - Kullanıcı girdisinin SQL sorgusuna kontrolsüz eklenmesi, saldırganın sorgu mantığını değiştirmesine izin verir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Cookie tek başına güvenilir kimlik doğrulama kanıtı değildir
  - Cookie çalınabilir veya tarayıcı tarafından saldırganın tetiklediği isteğe otomatik eklenebilir.
- CSRF durum değiştiren işlemlerde tehlikelidir
  - Para transferi, parola değiştirme veya ayar güncelleme gibi işlemler özellikle korunmalıdır.
- Token session'a özgü olmalıdır
  - Tahmin edilebilir veya sabit token savunma sağlamaz.
- HTTPOnly JavaScript erişimini engeller
  - Cookie ağ üzerinden gönderilebilir; ancak `document.cookie` ile okunamaz.

#### Detaylı Açıklamalar

- Cookie hırsızlığında saldırgan, hedef origin altında çalışan bir script aracılığıyla cookie değerini okuyup kendi sunucusuna gönderebilir. HTTPOnly bayrağı bu tür erişimi engeller; Secure bayrağı ise cookie'nin yalnız şifreli bağlantıda gönderilmesini sağlar.
- CSRF saldırısında saldırgan cookie'yi okumak zorunda değildir. Kullanıcı hedef uygulamada oturum açmışsa, tarayıcı hedef domaine yapılan isteğe cookie'yi otomatik ekler. Hedef uygulama yalnız cookie'ye bakarak karar verirse saldırganın tetiklediği işlem başarıya ulaşabilir.
- Secret token validation, sunucunun ürettiği ve kullanıcının formuna yerleştirdiği gizli token'ın istekle birlikte geri gelmesini bekler. Saldırgan token'ı bilemediği için geçerli istek oluşturamaz. SameSite cookie de tarayıcı düzeyinde ek koruma sağlar.
- SQL injection, web uygulamasının kullanıcı girdisini SQL sorgusuna doğrudan eklemesiyle oluşur. Girdi veri olarak değil komut parçası olarak yorumlandığında saldırgan sorgu koşulunu değiştirebilir, tabloları sorgulayabilir veya hassas veri elde edebilir.
### Ders 7 (Lab): SQL injection laboratuvar ortamı

#### Genel Konular

- SQL injection laboratuvar ortamı
  - PHP ve MySQL tabanlı bilinçli zafiyetli web uygulaması üzerinden SQL injection örnekleri uygulanır.
  - Apache, MySQL, PHP bağlayıcıları ve uygulama kaynak kodu kullanılarak test ortamı hazırlanır.
- Low seviye SQL injection
  - Kullanıcı girdisinin doğrudan SQL sorgusuna eklenmesiyle syntax hatası, yorum satırı ve `UNION` gibi SQL özellikleri üzerinden sorgu manipülasyonu yapılır.
  - Veritabanı sürümü, aktif veritabanı adı, tablo ve kolon bilgileri gibi metadata elde edilebilir.
- Hata mesajlarının bilgi sızdırması
  - SQL hatalarının doğrudan kullanıcıya gösterilmesi saldırgana kullanılan veritabanı ve sorgu yapısı hakkında ipucu verir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- SQL injection komutun veriyle karışmasıdır
  - Kullanıcı girdisi veri olarak sınırlandırılmazsa SQL komutu haline gelebilir.
- Hata mesajları saldırıyı kolaylaştırır
  - Veritabanı hatası web katmanında aynen gösterilmemelidir.
- `UNION` saldırganın ek sorgu sonucu almasını sağlar
  - Sorgu kolon sayısı ve tipleri uyumlu hale getirilirse başka tablolardan veri çekilebilir.

#### Detaylı Açıklamalar

- Laboratuvar uygulamasında zafiyetli web formuna girilen değerlerin arka planda SQL sorgusuna nasıl eklendiği incelenir. Tek tırnak gibi karakterler sorgu dizgisini bozarak hata üretir; bu hata uygulamanın girdiyi güvenli biçimde ayırmadığını gösterir.
- Saldırgan yorum işaretleriyle sorgunun kalan kısmını devre dışı bırakabilir veya `UNION` ile kendi seçtiği sorgu sonuçlarını mevcut sorguya ekletebilir. Bu yöntemle veritabanı sürümü, aktif kullanıcı, tablo adları, kolon adları ve hassas kayıtlar adım adım elde edilebilir.
- Güvenli tasarım açısından parametreli sorgular, prepared statement kullanımı, hata mesajlarını gizleme, minimum veritabanı yetkisi ve girdi doğrulama birlikte uygulanmalıdır.
### Ders 9: Ağ güvenliğine giriş

#### Genel Konular

- Ağ güvenliğine giriş
  - Oturum yönetimi konusu ağ güvenliği bağlamına bağlanarak katmanlı ağ mimarisi üzerinden güvenlik değerlendirmesi yapılır.
  - Fiziksel katman, veri bağlantı katmanı, ağ katmanı, taşıma katmanı ve uygulama katmanı arasındaki görev ayrımı açıklanır.
- IP adresleme
  - IPv4 ve IPv6 adreslerinin gösterimi, kısaltılması ve ağ/host ayrımı ele alınır.
  - IP adresi mantıksal adresleme sağlar; paketlerin ağlar arasında yönlendirilmesi bu adreslere dayanır.
- TCP ve UDP kavramları
  - TCP bağlantılı, sıralı ve güvenilir aktarım sağlamaya çalışır.
  - UDP bağlantısızdır; daha düşük yükle çalışır fakat güvenilirlik ve sıra garantisi vermez.
- DNS yapısı
  - Alan adlarının IP adreslerine çevrilmesi, recursive resolver, authoritative server ve hiyerarşik sorgu mantığı üzerinden incelenir.
  - DNS cevaplarının doğruluğu ve resolver davranışı ağ güvenliği açısından önem taşır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Ağ katmanlarında güvenlik varsayımı dikkatli kurulmalıdır
  - Alt katmandaki güven eksikliği üst katmandaki protokolü etkileyebilir.
- TCP byte stream olarak düşünülmelidir
  - Gönderilen veri alıcıda aynı parça sınırlarıyla gelmek zorunda değildir.
- DNS yalnız isim çözme değil güvenlik yüzeyidir
  - Yanlış veya manipüle edilmiş DNS cevabı kullanıcıyı yanlış hedefe yönlendirebilir.

#### Detaylı Açıklamalar

- Ağ güvenliği, tek bir protokolün güvenliği olarak görülmemelidir. Ethernet, IP, TCP/UDP ve DNS gibi katmanlar birlikte çalışır. Bir katmanda yapılan sahtecilik, yönlendirme hatası veya kimlik doğrulama eksikliği üst katmandaki uygulamayı etkileyebilir.
- TCP, uygulamaya kesintisiz byte akışı sunar; alıcı bir seferde bir byte, yüz byte veya bin byte okuyabilir. Bu nedenle uygulama protokolleri kendi mesaj sınırlarını doğru tanımlamalıdır. UDP ise hızlı ve düşük maliyetlidir; fakat kayıp, tekrar veya sıra bozulması uygulama tarafından ele alınmalıdır.
- DNS, kullanıcıların alan adıyla hizmetlere ulaşmasını sağlar. Ancak DNS cevabı yanlışsa kullanıcı doğru alan adını yazmış olsa bile yanlış IP'ye gidebilir. Bu nedenle DNS güvenliği, ağ tabanlı saldırıların anlaşılmasında merkezi öneme sahiptir.
### Ders 9 (Lab): SQL injection seviyelerinin derinleştirilmesi

#### Genel Konular

- SQL injection seviyelerinin derinleştirilmesi
  - Düşük seviyedeki doğrudan sorgu manipülasyonundan sonra daha fazla kontrol, filtreleme ve doğrulama içeren senaryolar incelenir.
  - Saldırı girdisinin uygulama katmanı ve veritabanı katmanı arasında nasıl yorumlandığı gözlemlenir.
- Veritabanı keşfi
  - Metadata tabloları, tablo/kolon adları, kullanıcı kayıtları ve hassas alanların bulunması SQL injection uygulamasının temel adımlarıdır.
- Savunma etkisi
  - Filtreleme, tırnak kaçışlama ve sorgu yapısındaki küçük değişikliklerin saldırı yöntemini nasıl etkilediği değerlendirilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Saldırı tek komuttan ibaret değildir
  - SQL injection keşif, doğrulama, veri çıkarma ve yetki değerlendirme aşamalarından oluşur.
- Filtreleme yeterli olmayabilir
  - Esas savunma parametreli sorgu ve veritabanı yetki sınırlandırmasıdır.

#### Detaylı Açıklamalar

- Laboratuvar içeriğinde saldırgan bakış açısıyla önce zafiyetin varlığı doğrulanır, ardından sorgu yapısı anlaşılır. Kolon sayısı, veri tipleri ve dönen sonuç alanları belirlendikten sonra `UNION` gibi yöntemlerle sistem tablolarından bilgi elde edilir.
- Savunma tarafında yalnızca belirli karakterleri filtrelemek saldırıyı tamamen durdurmayabilir. Farklı kodlama biçimleri, yorum işaretleri, alternatif SQL söz dizimleri veya uygulama mantığı filtreleri aşabilir. Bu nedenle SQL komutu ile kullanıcı verisinin yapısal olarak ayrılması gerekir.
### Ders 10: ARP güvenliği

#### Genel Konular

- ARP güvenliği
  - IP adresinden MAC adresine dönüşüm ARP ile yapılır.
  - ARP broadcast ve gratuitous ARP mekanizmaları kimlik doğrulama içermediği için sahte ARP duyuruları yapılabilir.
- IP spoofing
  - IP paketlerinde kaynak adres alanı sahte yazılabilir; IP'nin özgün tasarımında kaynak doğrulama yoktur.
  - Sahte kaynak adresi DDoS ve yansıtma saldırılarında kullanılır.
- DNS rebinding ve DNSSEC
  - DNS cevaplarının zaman içinde farklı IP'lere bağlanması web güvenlik sınırlarını zorlayabilir.
  - DNSSEC, DNS verisinin bütünlüğünü ve kaynağını doğrulamaya yönelik mekanizma olarak ele alınır.
- DDoS ve amplification
  - Açık DNS resolver'lar ve UDP tabanlı servisler küçük istekle büyük cevap üretip hedefe yansıtılabilir.
  - Botnet, sahte IP ve yüksek hacimli trafik hizmet kesintisi üretir.
- SYN flood ve SYN cookie
  - TCP handshake sırasında yarım açık bağlantılar kaynak tüketimine yol açabilir.
  - SYN cookie, sunucunun bağlantı durumunu saklamadan doğrulama yapmasını sağlayan savunmadır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- ARP ve IP tasarımında güvenlik varsayımı zayıftır
  - Protokoller çalışır ağ varsayımıyla tasarlandığı için kimlik doğrulama sonradan eklenmek zorunda kalır.
- UDP amplification ciddi DDoS aracıdır
  - DNS gibi servisler sahte kaynak IP ile hedefe büyük trafik yönlendirebilir.
- SYN cookie protokol davranışını dikkatli kullanır
  - Sunucu kaynak tüketimini azaltırken TCP handshake mantığını korur.

#### Detaylı Açıklamalar

- ARP protokolünde bir host, belirli IP adresinin hangi MAC adresine ait olduğunu yayınla sorar. Doğru hostun cevap vermesi beklenir; ancak protokol cevap verenin gerçekten o IP'ye sahip olduğunu doğrulamaz. Gratuitous ARP ile hostlar kendi eşleşmelerini duyurabilir; saldırgan bu mekanizmayı yanlış eşleşme yaymak için kullanabilir.
- IP protokolü paket taşımada hedef adrese odaklanır. Kaynak adresin doğruluğu ağ genelinde zorunlu olarak doğrulanmadığında saldırgan sahte kaynak IP kullanabilir. Bu, özellikle UDP tabanlı amplifikasyon saldırılarında hedefe yüksek hacimli cevap yönlendirmek için kullanılır.
- TCP SYN flood saldırısında saldırgan çok sayıda bağlantı başlatır, fakat handshake'i tamamlamaz. Sunucu yarım açık bağlantılar için kaynak ayırdığı için kapasite tükenebilir. SYN cookie, bağlantı bilgisini sunucu belleğinde tutmak yerine doğrulanabilir bir değer olarak istemciye yansıtarak bu riski azaltır.
### Ders 10 (Lab): Ağ saldırılarının gözlemlenmesi

#### Genel Konular

- Ağ saldırılarının gözlemlenmesi
  - ARP, DNS, TCP/UDP ve HTTP trafiği araçlarla izlenerek paket seviyesinde güvenlik etkileri incelenir.
- SQL injection veya web güvenliği uygulamalarının sürdürülmesi
  - Web uygulamasında zafiyetli girdi noktaları, HTTP istekleri ve veritabanı etkileri pratik olarak değerlendirilir.
- Trafik analizi
  - Paket başlıkları, kaynak/hedef adresleri, portlar ve protokol alanları saldırı davranışını anlamada kullanılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Paket düzeyi gözlem teoriyi somutlaştırır
  - ARP, IP, TCP ve DNS alanları doğrudan incelendiğinde protokol zayıflıkları daha anlaşılır hale gelir.
- Uygulama saldırıları ağ izlerinden takip edilebilir
  - Web formu, HTTP isteği, SQL sorgusu ve dönen cevap arasında ilişki kurulmalıdır.

#### Detaylı Açıklamalar

- Laboratuvar düzeyinde ağ güvenliği, paketlerin başlık ve içerik alanlarını inceleyerek anlaşılır. Kaynak/hedef IP, MAC adresi, port numarası, TCP bayrakları ve DNS cevapları saldırı türünü sınıflandırmada kullanılır.
- Web güvenliği uygulamalarında tarayıcıdan çıkan HTTP isteği ile sunucunun veritabanına gönderdiği sorgu arasında bağlantı kurmak önemlidir. Bu ilişki kurulmadan SQL injection, CSRF veya cookie tabanlı saldırıların etkisi tam anlaşılamaz.
### Ders 11: Ağ saldırılarına karşı savunma

#### Genel Konular

- Ağ saldırılarına karşı savunma
  - ARP, BGP, IP, UDP ve TCP gibi protokollerdeki güven varsayımlarının etkileri özetlenir.
  - TLS kullanımı, karma içerik, cookie bayrakları ve güvenli kanalın sınırları değerlendirilir.
- IP spoofing önleme
  - Ingress filtering ile servis sağlayıcı kendi ağından çıkan paketlerin kaynak IP adreslerini denetler.
  - Sahte kaynak IP kullanımının engellenmesi DDoS ve amplification saldırılarını azaltır.
- Firewall
  - Kaynak/hedef IP, protokol, kaynak/hedef port gibi alanlara göre trafik filtreleme yapılır.
  - Durum bilgili firewall içeriden dışarıya kurulan bağlantıları takip ederek dönüş trafiğine izin verebilir.
- IDS/IPS
  - Saldırı tespit sistemleri ağ trafiğini veya host davranışını analiz ederek şüpheli örüntüleri yakalar.
  - İmza tabanlı ve davranış tabanlı yaklaşımlar farklı güçlü ve zayıf yönlere sahiptir.
- VPN
  - IPsec ve OpenVPN gibi teknolojiler ağlar veya istemciler arasında şifreli tünel kurar.
  - VPN gizlilik ve bütünlük sağlar; ancak uç sistem güvenliğini tek başına garanti etmez.

#### Hocanın Özellikle Vurguladığı Kısımlar

- TLS tek başına yeterli değildir
  - Sayfanın bir kısmı HTTPS, bir kısmı HTTP ise karma içerik güvenliği bozar.
- Ingress filtering yaygın uygulanmadığında küresel etki oluşur
  - Bir ağın sahte IP'ye izin vermesi başka ağlara saldırı olarak dönebilir.
- Firewall kuralı doğru bağlamda yazılmalıdır
  - Sadece port engellemek her uygulama saldırısını durdurmaz.

#### Detaylı Açıklamalar

- Sahte IP adresi, yansıtma ve amplifikasyon saldırılarının temel araçlarından biridir. Servis sağlayıcılar kendi müşterilerinden çıkan trafiğin kaynak IP'sini denetlerse, kendilerine ait olmayan adresle dışarı çıkan paketleri durdurabilir. Bu mekanizma ağ genelinde yaygın uygulanmadığında saldırganlar açık kalan ağlardan yararlanır.
- Firewall, ağ sınırında veya host üzerinde çalışabilir. Basit kurallar belirli porta gelen trafiği düşürebilir; daha gelişmiş durum bilgili firewall bağlantı durumunu takip eder. Uygulama katmanındaki SQL injection gibi saldırılar için yalnız port filtresi yetmez; içerik analizi veya uygulama güvenliği gerekir.
- IDS/IPS sistemleri bilinen saldırı imzalarını, anormal trafik hacmini veya protokol dışı davranışı tespit etmeye çalışır. VPN ise iletişimi şifreleyerek dış gözlemciye karşı koruma sağlar; fakat uç nokta ele geçirilmişse tünelin güvenliği saldırıyı engellemez.
### Ders 13: Akademik içerik bulunmayan kayıt

Bu derste işlenen akademik bir içerik bulunmamaktadır.
### Ders 14: Sertifika ve açık anahtar altyapısı

#### Genel Konular

- Sertifika ve açık anahtar altyapısı
  - Kod parçalarının ve sunucuların dijital sertifikalarla doğrulanması güvenli çalıştırma ve güvenli haberleşme açısından ele alınır.
  - Açık anahtar, gizli anahtar ve sertifika ilişkisi açıklanır.
- Anahtar saklama problemi
  - Şifreleme güvenliği yalnız algoritmaya değil, anahtarın güvenli saklanmasına bağlıdır.
  - Web sunucusu HTTPS anahtarı, disk şifreleme anahtarı veya bellek şifreleme anahtarı açıkta tutulursa güvenlik zayıflar.
- Donanım destekli güvenlik
  - Anahtarların donanım içinde saklanması ve kriptografik işlemlerin donanım tarafından yapılması gizli anahtarın dışarı çıkmasını önleyebilir.
  - TPM/HSM benzeri mantıkla veri donanıma verilir, şifreleme/deşifreleme sonucu alınır.
- Hash ve özet değerleri
  - Verinin bütünlüğünü kontrol etmek ve içerik karşılaştırmak için hash değerleri kullanılır.
  - Güvenli hash fonksiyonlarında küçük değişiklik büyük özet farkı üretmelidir.
- Public key kriptografi uygulamaları
  - Sertifika doğrulama, güvenli kanal kurma, kod imzalama ve kimlik doğrulama açık anahtar kriptografisine dayanır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Anahtar güvenliği kriptografinin merkezidir
  - Algoritma güçlü olsa bile anahtar sızarsa güvenlik kaybolur.
- Sertifika güven zinciri gerektirir
  - Bir sertifikaya güvenmek için sertifikanın doğrulanabilir bir otorite zinciriyle ilişkilendirilmesi gerekir.
- Donanım anahtarı dışarı vermeden işlem yapabilir
  - Bu yaklaşım gizli anahtarın yazılım tarafından okunmasını engeller.

#### Detaylı Açıklamalar

- Dijital sertifikalar, bir açık anahtarın belirli bir kimliğe ait olduğunu doğrulamak için kullanılır. HTTPS sunucuları sertifika göndererek istemcinin doğru sunucuyla konuştuğunu kanıtlamaya çalışır. Kod imzalama da benzer biçimde çalıştırılan kodun güvenilir kaynak tarafından üretildiğini doğrulamayı hedefler.
- Şifreleme sistemlerinde anahtarın saklanması algoritma kadar önemlidir. Anahtar yazılım belleğinde açık biçimde bulunuyorsa bellek sızıntısı, debug, zararlı yazılım veya yan kanal saldırılarıyla ele geçirilebilir. Bu nedenle anahtarın donanım içinde tutulduğu ve dışarı çıkarılmadığı tasarımlar tercih edilebilir.
- Hash fonksiyonları, verinin kısa ve sabit uzunlukta özetini üretir. Bütünlük kontrolü, dosya karşılaştırma, parola saklama ve imza süreçlerinde temel bileşendir. Güvenli hash fonksiyonlarının çakışmaya dayanıklı ve tersine çevrilmesi pratikte imkansız olması beklenir.
- Açık anahtar kriptografisinde public key paylaşılabilir, private/secret key ise korunur. Sertifika altyapısı, bu anahtarların kimliklerle güvenilir biçimde eşlenmesini sağlar. TLS ve kod imzalama gibi pratik sistemler bu modele dayanır.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
