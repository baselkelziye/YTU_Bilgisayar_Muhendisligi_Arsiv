# Ders 7 Genişletilmiş Notu: Makale Tartışması: Exokernel, Çekirdekte İnce Taneli Dinamik Enstrümantasyon ve BSD Dosya Sistemi Çalışması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. Exokernel Nedir?
- 3. Kütüphane İşletim Sistemi
- 4. Exokernel'in Tasarım İlkeleri
- 5. Abort Protokolü
- 6. Dinamik Enstrümantasyon
- 7. Makalenin Diğer Çalışmalardan Farkı
- 8. BSD Çalışması (BSD Study)
- 9. Örnek Sorular

## 1. Dersin Biçimi

Bu ders bir makale tartışması dersiydi. Öğrenciler o hafta verilen makaleleri önceden okumuştu. Hoca her makale için kısa ve odaklı sorular sordu, söz isteyen öğrencilere el kaldırma sırasıyla söz verdi, cevapları değerlendirdi ve sonunda makalenin özünü kendisi açıkladı. Tartışma Türkçe ve İngilizce karışık yürüdü.

Bu derste üç makale ele alındı:

- Exokernel makalesi (günün birinci makalesi)
- Hazır işletim sistemi çekirdeklerinin ince taneli dinamik enstrümantasyonu üzerine bir makale (listede 17 numara; hocanın okuduğu başlık "Fine-grained Dynamic Instrumentation of Commodity Operating System Kernels")
- BSD dosya sistemi çalışmasına atıf yapan bir dosya sistemi makalesi (listede 18 numara)

Kayıtta ekran paylaşımı yoktu; görüntü yalnız Zoom'da konuşan kişinin adını gösteriyordu. Bu yüzden notun tamamı altyazıdan hazırlandı. Hocanın makaleden sesli okuduğu cümleler İngilizce korunmuştur.

Hoca dersin başından sonuna kadar aynı noktayı vurguladı: sorulan şey makalenin özeti değil, bir kavramın kendisidir. Cevapların çoğu makalenin özetinde (abstract) ve giriş bölümünde açıkça yazmaktadır.

> **Hocanın vurgusu:** Makaleleri yalnız özetlemek yeterli değildir. İçinde ne yazdığını, nelerin önemli olduğunu ve nelere dikkat edilmesi gerektiğini incelemek gerekir. Sorulan sorular, makaleye genel olarak bakmış birinin hemen cevaplayabileceği temel noktalardır; ayrıntılı sayısal sonuçlar sorulmamaktadır.

## 2. Exokernel Nedir?

### 2.1 İlk cevaplar ve hocanın düzeltmesi

Hocanın ilk sorusu "exokernel nedir, kısa ve öz" oldu. Hoca, makalenin genel özetini anlatmaya başlayan bir cevabı keserek özellikle "exokernel nedir" diye sorduğunu, makale hakkında soru sormadığını belirtti.

Bir öğrencinin cevabı şöyleydi: normalde işletim sistemi fiziksel kaynakları yönetir, uygulamalar yalnız işletim sisteminden kaynak talep eder. Exokernel mimarisinde işletim sistemi ile uygulamalar arasında bir katman oluşturulur ve kaynaklar hakkındaki bilgi uygulamalara daha fazla verilir; böylece kaynak yönetimi iyileştirilir. Aynı öğrenci bir alternatif de söyledi: her uygulamaya bir sanal makine tahsis etmek. Bu yaklaşım performans açısından verimli olmadığı için exokernel mimarisi önerilmiştir.

Hoca bu cevabı sorgulamaya devam etti:

**Soru:** Yönetimin "bir miktarını" uygulamaya bırakıyor diyorsun. Ne kadarını?
**Cevap (öğrenci):** Güvenlikten arınmış şekilde donanıma erişebilecek kadarını. Yine de uygulamaların birbirinin ayağına basmasına izin verilmemeli.

**Soru:** O zaman güvenliği exokernel mi sağlıyor?
**Cevap (öğrenci):** Exokernel güvenliği sağlamıyor, donanımla ilgili daha fazla bilginin uygulamaya geçmesini sağlıyor.

Bu noktada hoca asıl soruyu sordu: **donanımın yönetimini kim yapıyor?** Uygulamalar mı, exokernel mi, yoksa ayrıca bir işletim sistemi mi var? Bir öğrenci exokernel'in kaynak yönetimini ve korumayı desteklediğini söyledi; hoca o halde korumayı kimin yaptığı sorusunun hâlâ açık durduğunu belirtti. Başka bir öğrenci güvenliği işletim sisteminin sürdürüyor "olması gerektiğini" söyledi. Hoca "olmalı" ifadesine dikkat çekti: makalede yazanı sordu, öğrencinin buna yorum kattığını söyledi.

### 2.2 Makaledeki tanım

Hoca cevabın makalenin özetinde yazdığını söyleyerek ilgili cümleyi okudu:

> "In the exokernel architecture, a small kernel securely exports all hardware resources through a low-level interface to untrusted library operating systems."

Hocanın bu cümleye dair açıklaması şöyledir:

- Buradaki "small kernel" işletim sisteminin kendisidir. Sistemde bir işletim sistemi, bir exokernel ve üstte bir katman gibi üç ayrı parça yoktur. Klasik, standart işletim sistemi alınır ve yerine exokernel konur.
- "Donanım kaynakları" şunlardır: bellek, giriş/çıkış cihazları, ağ cihazları, diskler, CPU'nun kendisi ve CPU üzerindeki özellikler, yani önbellek (cache) mekanizması ve TLB mekanizması.
- Exokernel bunların hepsini doğrudan kütüphane işletim sistemlerinin kullanımına açar.

### 2.3 Yönetim uygulamaya geçer

Hoca soruların cevabını şöyle toparladı. Exokernel donanım kaynaklarını olduğu gibi üst tarafa açıyorsa, bu kaynaklara erişim doğrudan uygulamalara verilmiş demektir; dolayısıyla bu kaynakları yönetecek olanlar da uygulamalardır. Normal bir bilgisayar sisteminde donanım kaynaklarını yöneten temel yazılım işletim sistemidir. Exokernel yaklaşımında işletim sistemi aradan çıkarılır ve normal yapıda üstlendiği görev uygulamanın kendisine bırakılır.

Bunun kazancı performanstır: uygulama donanımla etkileşeceği her seferinde araya işletim sisteminin girmesine gerek kalmaz. Bedeli ise sorumluluktur: uygulamalar kaynakları birbirlerinin ayaklarına basmayacak şekilde yönetmek zorundadır. Bu yüzden bir nevi işletim sistemi gibi davranırlar. Bunların hepsi kullanıcı alanında (user space), kullanıcı seviyesinde, yukarıda çalışır; bir kütüphane gibi düşünülebilir.

Hoca işletim sisteminin neden ön plana çıktığını da hatırlattı: işletim sistemi bir soyutlama sağlar. Uygulamalar donanımdan bağımsız biçimde işletim sisteminden hizmet alır ve yalnız kendi yapmak istedikleri işe yoğunlaşır. Ama bu soyutlamanın getirdiği bir takım yükler vardır. Kütüphane işletim sistemleri hem işletim sisteminin bu özelliklerini barındırır hem de uygulamaya özgü kalır.

> **Ek bilgi (derste anlatılmadı):** Exokernel makalesi büyük olasılıkla Engler, Kaashoek ve O'Toole'un 1995 tarihli "Exokernel: An Operating System Architecture for Application-Level Resource Management" çalışmasıdır. Makalenin temel sloganı kaynak korumasını kaynak yönetiminden ayırmaktır: exokernel yalnız korumayı yapar, yönetim politikalarını kütüphane işletim sistemlerine bırakır. Makaledeki prototip çekirdek Aegis, kütüphane işletim sistemi ise ExOS adını taşır.

## 3. Kütüphane İşletim Sistemi

### 3.1 Soru ve öğrenci cevapları

Hocanın ikinci sorusu "What is a library operating system?" oldu. Gelen cevaplar ve hocanın tepkileri:

- Bir öğrenci makaleden şu cümleyi okudu: kütüphane işletim sistemi fiziksel kaynakların yönetimini çekirdekten alıp güvenilmeyen kullanıcı seviyesi kütüphanelere taşır. Hoca yine "peki kütüphane işletim sistemi nedir" diye sordu ve şunu ekledi: "Örneğin bu exokernel'in üzerine ben bir kütüphane işletim sistemi yazabilir miyim?" Bu soruya cevap gelmedi.
- Başka bir öğrenci, kütüphane işletim sisteminin uygulamanın donanım kaynaklarına erişim biçimini belirlediğini, varsayılan bir kütüphanenin sağlandığını, istenirse özel (custom) bir kütüphaneye geçilerek performans artışı sağlanabileceğini söyledi. Hoca, makale kapsamında yazarların deneylerini yapabilmek için bir kütüphane işletim sistemi sağladığını, ancak kendisinin kavramın ne olduğunu sorduğunu belirtti.
- Bir öğrenci kütüphane işletim sisteminin exokernel arayüzünün üzerinde çalıştığını söyledi; hoca bunun zaten bilindiğini belirtti.

Hoca, makalenin kavramı bazı yerlerde ipuçlarıyla, bazı yerlerde doğrudan anlattığını söyledi.

### 3.2 Hocanın açıklaması

Makalede yazarlar kütüphane işletim sistemini yeri geldiğinde "uygulama" olarak da adlandırdıklarını söylemiştir. Kütüphane işletim sistemi, işletim sisteminin klasik yapıda yaptığı kaynak yönetimini uygulama düzeyinde yapan, kullanıcı alanında çalışan bir kütüphanedir (ayrıntısı 2.3'te).

### 3.3 Makalenin 1. şekli

Hoca makaledeki 1 numaralı şekli anlattı. Şekilde iki kütüphane işletim sistemi gösterilmiştir ve üstlerinde "Applications" yazar:

- Birinin üzerinde Mosaic vardır. Mosaic, internette dolaşmayı sağlayan eski bir web tarayıcısıdır. Altında WWW (HTTP) katmanı, POSIX ve TCP bulunur.
- Diğer tarafta Barnes-Hut adlı bir dağıtık paylaşımlı bellek (Distributed Shared Memory) uygulaması vardır.

İkisinin arasında ve altında exokernel bulunur. Şekilde çok net görüldüğü gibi exokernel, alttaki donanım kaynakları ile üstteki uygulamalar yani kütüphane işletim sistemleri arasındaki güvenli bağlantıyı sağlar. Hoca "olay bu" diyerek kavramı özetledi.

```text
   Mosaic (uygulama)              Barnes-Hut DSM (uygulama)
   WWW (HTTP) / POSIX / TCP       ...
   --- kütüphane işletim sistemi ---  --- kütüphane işletim sistemi ---
   ----------------------- Exokernel (güvenli bağlantı) ----------------
   ------------------------------ Donanım ------------------------------
```

<!-- BELİRSİZ: Şekil ekranda gösterilmedi; yukarıdaki yerleşim hocanın sözlü anlatımından kuruldu. -->

## 4. Exokernel'in Tasarım İlkeleri

Hoca exokernel tasarımında öne çıkan ilkeleri sordu. Bir öğrenci kesin bilmediğini ama yüksek performans ve esnekliğin ön planda olduğunu düşündüğünü söyledi. Hoca bu sorunun doğrudan makalenin 3.1 alt bölümündeki "Design Principles" başlığından geldiğini belirtti. Oradaki ilkeler:

- **Securely expose hardware:** donanımı güvenli biçimde açmak.
- **Expose allocation:** kaynak tahsisini açmak.
- **Expose names:** adları (fiziksel adları) açmak.
- **Expose revocation:** kaynağın geri alınmasını açmak.

Hoca bunların altında politikayla (policy) ilgili maddelerin de devam ettiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Exokernel'de kaynakların kütüphane işletim sistemlerine güvenli biçimde bağlanması "secure binding" ile yapılır. Geri alma "visible revocation" biçimindedir: çekirdek bir kaynağı geri alacağını kütüphane işletim sistemine bildirir ve ona hangi kaynağı bırakacağını seçme fırsatı tanır. Abort protokolü bu işbirliğinin bozulduğu durum için vardır.

## 5. Abort Protokolü

Hoca exokernel'de bir abort protokolü bulunduğunu ve bunun neden var olduğunu sordu.

Öğrenci cevapları:

- Bir uygulama işbirliği yapmayıp bir kaynağı bırakmazsa çekirdek o kaynağa olan güvenli bağlantıyı koparır ve uygulamaya bir istisna (exception) gönderir.
- Türkçe kaynaklarda "iptal protokolü" diye geçer; kütüphane işletim sistemi cevap vermezse ya da hataya sebep olursa onun uygulamalarını sonlandırmak için kullanılır.
- Abort protokolü, exokernel tarafından işbirliği yapmayan kütüphane işletim sistemlerinin güvenli bağlantılarını zorla koparmak için kullanılır.

Hocanın özeti: donanım doğrudan yukarıya, uygulamaya açılmaktadır ve bir noktada o donanımı geri almak gerekir. Uygulama kaynağı geri vermiyorsa ne yapılacaktır? Abort edilir; yani yukarıya, uygulamaya açılmış olan kaynak zorla geri alınır.

## 6. Dinamik Enstrümantasyon

### 6.1 Kavram

İkinci makalenin başlığı hocanın okumasıyla "Fine-grained Dynamic Instrumentation of Commodity Operating System Kernels" idi. Hoca yine önce kavramı sordu: "What is dynamic instrumentation?" Hoca bunun makaleye özel bir soru olmadığını, genel bir kavram olduğunu, makalede bunun çekirdek için yapıldığını vurguladı.

Gelen cevaplar:

- Bir öğrenci makaleden şunu okudu: bu teknoloji, tamamen değiştirilmemiş ve çalışmakta olan hazır bir işletim sistemi çekirdeğinin hemen her makine kodu komutunun önüne dinamik olarak üretilmiş kod ekleyebilir.
- Bir öğrenci girişten optimizasyon ve eklentilerin değiştirilmemiş hazır çekirdeklerde yapılabilmesine dair bir cümle okudu.
- Bir öğrenci çalışma zamanında çekirdeğin herhangi bir yerinde değişiklik yapılabilmesi diye özetledi. Hoca "dinamik" tarafını anladığını, asıl "instrumentation" kavramını sorduğunu belirtti.
- Bir öğrenci dinamik enstrümantasyonun, çalışma sırasında istenen çekirdek kodu noktalarına kayıt (logging) kodu eklenerek çekirdek izleme (kernel tracing) için kullanılabileceğini söyledi.
- Bir öğrenci performans analizine göre uygulamayı iyileştirme ve hata durumlarını yakalamaya yönelik kararlar almayı sağlayan bir şey olabileceğini söyledi.

### 6.2 Hocanın tanımı

Hoca tanımı şöyle verdi: **enstrümantasyon, çalışan bir kodun çalışma anında nasıl çalıştığının incelenmesidir.**

- **Çevrim dışı (offline) yapılırsa:** kod yeniden derlenir ve belirli noktalardan ölçüm yapılabilecek şekilde düzenlemeler yapılır, kod parçaları eklenir.
- **Çevrim içi, yani dinamik yapılırsa:** kod çalışırken herhangi bir noktası ölçüm yapabilecek şekilde değiştirilebilir.

Makalede bu iş hazır alınabilen (commodity) bir işletim sistemi çekirdeği için yapılmıştır; yani gidip satın alabileceğiniz bir çekirdek. Yazarlar bunu UltraSPARC işlemcisinde çalışan Solaris çekirdeğinde yapmıştır. Hoca bugün için aynı şeyin örneğin Windows'ta yapılmak istenebileceğini söyledi.

### 6.3 Çekirdek seviyesinde kullanım alanları

**Soru:** Özellikle çekirdek seviyesinde dinamik enstrümantasyonu ne için yapmak isteriz?

Bir öğrenci performans analizi ve güvenlik testi için etkili bir yöntem olduğunu söyledi. Hoca başka kullanım alanlarını sordu. Bir öğrenci makaleden şu listeyi okudu ve hoca bunu cevap olarak kabul etti:

- Hata ayıklama (debugging)
- Kod kapsamı (code coverage)
- Güvenlik izleme (security monitoring)
- Çalışma zamanında kod optimizasyonu (runtime code optimization)
- Çekirdek optimizasyonu

Bunlara önceki cevaplardan performans analizi ve çekirdek izleme (tracing) de eklenebilir. Hoca bu cevap için makalenin bütün paragraflarını okumaya gerek olmadığını, cevabın çok basit olduğunu söyledi.

## 7. Makalenin Diğer Çalışmalardan Farkı

Hoca şunu sordu: dinamik enstrümantasyon yapılmayan bir şey değildir; ama bu makale onu farklı bir şekilde yapmaktadır. Diğer çalışmalardan önemli farkı nedir?

Gelen cevaplar ve hocanın değerlendirmesi:

- Bir öğrenci makalede bir uygulamanın dosya açmaya harcadığı zaman oranının yaklaşık yüzde 14'ten yüzde 7'ye indirildiğini okudu. Hoca bunun fark değil, bir etki (sonuç) olduğunu söyledi. <!-- BELİRSİZ: Oranlar altyazıda bozuk; ekranda gösterilmedi. -->
- Bir öğrenci yeniden derleme gerektirmeden yapılabilmesini önerdi. Hoca "tamam, ama daha da önemli bir şey var" dedi ve cevabın makalenin başlığında yazdığını hatırlattı: "Hiç merak ettiniz mi, fine-grained ne demek?"
- Bir öğrenci farkın, bu işin normalde hazır (commodity) işletim sistemlerinde yapılmamasına rağmen bu makalede yapılmış olması olduğunu söyledi. Hoca cevabın bu olmadığını belirtti.

Hoca asıl cevabı derste açıkça söylemedi; ipucu başlıktaki "fine-grained" kelimesiydi. Hoca bunun "tek ama çok güçlü bir fark" olduğunu söyledi.

<!-- BELİRSİZ: Hocanın beklediği cevap derste verilmedi. -->

> **Ek bilgi (derste anlatılmadı):** Bu makale büyük olasılıkla Tamches ve Miller'ın 1999 tarihli KernInst çalışmasıdır. "Fine-grained" ifadesi, enstrümantasyon noktasının yalnız fonksiyon girişi gibi kaba noktalarla sınırlı olmayıp hemen her makine komutu düzeyinde seçilebilmesini anlatır; derste bir öğrencinin okuduğu "hemen her makine kodu komutunun önüne kod eklenebilir" cümlesi de bu özelliği tarif eder. Çekirdeğin değiştirilmemesi, yeniden derlenmemesi ve yeniden başlatılmaması bu yaklaşımın tamamlayıcı özellikleridir.

## 8. BSD Çalışması (BSD Study)

Üçüncü makale listede 18 numaraydı. Hoca "What is the BSD study?" diye sordu.

Bir öğrenci BSD'nin bir UNIX işletim sistemi olduğunu, açılımının Berkeley Software Distribution olduğunu söyledi. Hoca BSD'nin ne olduğunu değil, "BSD study"nin ne olduğunu sorduğunu belirtti. Başka bir öğrenci makalenin özetinden Sprite dağıtık dosya sistemindeki dosya erişim örüntülerini ve önbellek davranışını incelediğini okudu; hoca sorunun bu çalışma hakkında değil, makalede adı geçen BSD çalışması hakkında olduğunu söyledi.

Hocanın cevabı: **BSD study, 1985 yılında Berkeley Üniversitesi'ndeki araştırmacıların BSD UNIX dosya sistemi üzerinde yapmış oldukları performans analizine verilen addır.** Bu bilgi makalenin özetinde, giriş cümlesinde, giriş bölümünde ve makalenin diğer yerlerinde yazmaktadır.

Hoca bu makaleyle dosya sistemleri konusuna geçildiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Burada tartışılan makale büyük olasılıkla Baker ve arkadaşlarının 1991 tarihli "Measurements of a Distributed File System" çalışmasıdır. Bu çalışma Sprite dağıtık dosya sisteminde kullanıcı düzeyindeki dosya erişim örüntülerini ve istemci önbelleklerinin davranışını ölçmüş ve sonuçlarını, Ousterhout ve arkadaşlarının 1985'te 4.2 BSD UNIX dosya sistemi üzerinde yaptığı iz tabanlı ölçümle ("BSD study") karşılaştırmıştır.

## 9. Örnek Sorular

Aşağıdaki sorular hocanın derste sözlü olarak sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:01:03): Exokernel nedir? Kısa ve öz olarak açıklayınız.

> **Cevap (derste verildi, 00:08:31-00:09:54):** Exokernel, klasik işletim sisteminin yerine konan küçük bir çekirdektir. Bütün donanım kaynaklarını (bellek, giriş/çıkış ve ağ cihazları, diskler, CPU ve onun önbellek ve TLB mekanizmaları) düşük seviyeli bir arayüzle, güvenli biçimde, güvenilmeyen kütüphane işletim sistemlerine açar.

**Soru 2** (derste sözlü, 00:05:35): Exokernel mimarisinde donanımın yönetimini kim yapar: uygulamalar mı, exokernel mi, yoksa ayrıca bir işletim sistemi mi?

> **Cevap (derste verildi, 00:15:35-00:16:29):** Ayrı bir işletim sistemi yoktur. Kaynaklar doğrudan uygulamalara (kütüphane işletim sistemlerine) açıldığından yönetimi uygulamalar yapar; exokernel kaynakların güvenli biçimde açılmasını ve korunmasını sağlar.

**Soru 3** (derste sözlü, 00:09:54): Kütüphane işletim sistemi (library operating system) nedir? Exokernel'in üzerine bir kütüphane işletim sistemi yazılabilir mi?

> **Cevap (derste verildi, 00:15:17-00:18:12):** Kullanıcı alanında çalışan, uygulamaya bağlı bir kütüphane gibi düşünülen ve klasik işletim sisteminin kaynak yönetimi görevini uygulama düzeyinde üstlenen yazılımdır; makalede yeri geldiğinde "uygulama" diye de adlandırılır. Makalenin 1. şeklinde Mosaic ve Barnes-Hut DSM için iki ayrı kütüphane işletim sistemi exokernel'in üzerinde gösterilmiştir. Yazılıp yazılamayacağı sorusuna derste ayrıca cevap verilmedi; şekildeki iki örnek, exokernel üzerinde birden fazla kütüphane işletim sistemi bulunabildiğini gösterir.

**Soru 4** (derste sözlü, 00:18:41): Exokernel'in tasarımında öne çıkan ilkeler nelerdir?

> **Cevap (derste verildi, 00:19:50-00:20:13):** Makalenin 3.1 alt bölümüne göre: securely expose hardware, expose allocation, expose names, expose revocation.

**Soru 5** (derste sözlü, 00:20:17): Exokernel'de abort protokolü neden vardır?

> **Cevap (derste verildi, 00:22:57-00:23:33):** Donanım doğrudan uygulamaya açıldığı için bir noktada geri alınması gerekir. Uygulama (kütüphane işletim sistemi) işbirliği yapmayıp kaynağı geri vermezse exokernel güvenli bağlantıyı zorla koparır ve kaynağı geri alır.

**Soru 6** (derste sözlü, 00:24:26): Dinamik enstrümantasyon nedir?

> **Cevap (derste verildi, 00:28:54-00:29:45):** Enstrümantasyon, çalışan bir kodun çalışma anında nasıl çalıştığının incelenmesidir. Çevrim dışı yapıldığında kod yeniden derlenir ve ölçüm noktalarına kod eklenir; dinamik yapıldığında kod çalışırken herhangi bir noktası ölçüm yapacak şekilde değiştirilir.

**Soru 7** (derste sözlü, 00:30:15): Dinamik enstrümantasyon özellikle çekirdek seviyesinde ne için yapılmak istenir?

> **Cevap (derste verildi, 00:31:42):** Performans analizi ve izleme yanında hata ayıklama, kod kapsamı, güvenlik izleme, çalışma zamanında kod optimizasyonu ve çekirdek optimizasyonu.

**Soru 8** (derste sözlü, 00:32:09): Bu makalenin dinamik enstrümantasyonu diğer çalışmalardan farklı yapmasının önemli farkı nedir?

> **Çözüm (derste verilmedi):** Hoca cevabın başlıkta yazdığını söyleyip "fine-grained" ifadesine dikkat çekti. Büyük olasılıkla beklenen cevap, enstrümantasyonun yalnız fonksiyon girişi gibi kaba noktalarda değil, değiştirilmemiş ve çalışan çekirdeğin hemen her makine komutu düzeyinde yapılabilmesidir. "Hazır işletim sistemine uygulanması" ve sayısal kazançlar fark olarak kabul edilmedi.

**Soru 9** (derste sözlü, 00:36:44): BSD study nedir?

> **Cevap (derste verildi, 00:38:53):** 1985 yılında Berkeley'deki araştırmacıların BSD UNIX dosya sistemi üzerinde yaptığı performans analizine verilen addır.

## Dersin Toparlaması

Bu derste üç makale üzerinden işletim sistemi tasarımının farklı yüzleri tartışıldı. Exokernel makalesinde klasik işletim sisteminin yerine konan küçük bir çekirdeğin donanımı güvenli biçimde kütüphane işletim sistemlerine açtığı, kaynak yönetiminin uygulama düzeyine taşındığı ve bunun karşılığında uygulamaların birbirini rahatsız etmeyecek şekilde kaynak yönetmek zorunda kaldığı görüldü; tasarım ilkeleri ve işbirliği yapmayan kütüphane işletim sistemine karşı abort protokolü de konuşuldu. İkinci makalede enstrümantasyonun çalışan kodu ölçmek olduğu, dinamik enstrümantasyonun bunu kod çalışırken yaptığı ve makalenin bunu hazır bir çekirdekte (UltraSPARC üzerinde Solaris) ince taneli biçimde uyguladığı ele alındı.

Son olarak BSD çalışmasının 1985'te BSD UNIX dosya sistemi üzerine yapılmış bir performans analizi olduğu belirtildi. Bu makaleyle dosya sistemleri konusuna geçiş yapıldı; sonraki makaleler dosya sistemleri üzerine olacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
