# Ders 7 Çalışma Özeti

## Genel Konular

- Dersin biçimi: makale tartışması
  - Ders, haftalık verilen klasik işletim sistemi makaleleri üzerine soru-cevap biçiminde yürüdü. Hoca her makale için kısa ve odaklı sorular sordu, öğrenciler cevap verdi, sonra hoca makalenin özünü kendisi açıkladı.
  - Kayıtta ekran paylaşımı yoktu; içerik altyazıdan alındı.
- Exokernel mimarisi
  - Klasik işletim sistemi çekirdeğinin yerine küçük bir çekirdek (exokernel) konur. Bu çekirdek bütün donanım kaynaklarını düşük seviyeli bir arayüzle, güvenli biçimde, güvenilmeyen kütüphane işletim sistemlerine (library operating system) açar.
  - Açılan kaynaklar: bellek, giriş/çıkış cihazları, ağ cihazları, diskler, CPU'nun kendisi ve CPU üzerindeki önbellek (cache) ve TLB mekanizmaları.
  - Kaynak yönetimi kullanıcı seviyesindeki kütüphane işletim sistemlerine, yani uygulamalara bırakılır; exokernel yalnız güvenli bağlantıyı (koruma) sağlar.
  - Tasarım ilkeleri (makalenin 3.1 alt bölümü): donanımı güvenli biçimde açmak (securely expose hardware), tahsisi açmak (expose allocation), adları açmak (expose names), geri almayı açmak (expose revocation).
  - Abort protokolü: işbirliği yapmayan bir kütüphane işletim sistemi kaynağı geri vermezse exokernel güvenli bağlantıyı zorla koparır ve kaynağı geri alır.
- Kütüphane işletim sistemi (library operating system)
  - Exokernel'in üzerinde, kullanıcı alanında çalışan, uygulamaya bağlı bir kütüphane gibi düşünülür; uygulamanın donanıma erişim biçimini belirler.
  - Makalede kütüphane işletim sistemi yeri geldiğinde "uygulama" olarak da adlandırılır.
  - Varsayılan bir kütüphane sağlanabilir; istenirse uygulamaya özel bir kütüphane kullanılarak performans artırılabilir.
  - Makalenin 1. şeklinde iki örnek vardır: üzerinde WWW, POSIX ve TCP katmanları bulunan Mosaic web tarayıcısı ve Barnes-Hut dağıtık paylaşımlı bellek (DSM) uygulaması. Exokernel bunlarla alttaki donanım arasında güvenli bağlantıyı sağlar.
- Dinamik enstrümantasyon (dynamic instrumentation)
  - Enstrümantasyon: çalışan bir kodun çalışma anında nasıl çalıştığının ölçülmesi ve incelenmesi.
  - Çevrim dışı (statik) enstrümantasyonda kod yeniden derlenir ve ölçüm yapılacak noktalara kod parçaları eklenir.
  - Dinamik enstrümantasyonda kod çalışırken herhangi bir noktası ölçüm yapacak şekilde değiştirilir.
  - Tartışılan makalede bu iş hazır alınabilen (commodity) bir işletim sisteminin çekirdeğinde yapılmıştır: UltraSPARC üzerinde çalışan Solaris çekirdeği.
  - Çekirdek seviyesinde kullanım alanları: performans analizi, çekirdek izleme (tracing), hata ayıklama (debugging), kod kapsamı (code coverage), güvenlik izleme, çalışma zamanında kod optimizasyonu ve çekirdek optimizasyonu.
- BSD çalışması (BSD study)
  - 1985'te Berkeley'deki araştırmacıların BSD UNIX dosya sistemi üzerinde yaptığı performans analizine verilen addır.
  - Bu makaleyle dosya sistemleri konusuna geçiş yapıldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Soruya odaklı ve kısa cevap
  - Hoca makale özeti değil, sorulan kavramın kendisini istedi ("exokernel nedir", "kütüphane işletim sistemi nedir", "dinamik enstrümantasyon nedir"). Cevapların çoğu makalenin özetinde (abstract) ve giriş bölümünde açıkça yazıyordu.
  - Makaleden okunan cümle ile kişisel yorum ayrılmalıdır; hoca "makalede yazan nedir" diye sordu.
- Exokernel'de yönetimi kim yapıyor?
  - Ayrı bir klasik işletim sistemi kalmaz; exokernel onun yerini alır. Donanım kaynaklarının yönetimi uygulamalara (kütüphane işletim sistemlerine) geçer.
  - Performans kazancının nedeni: uygulama donanımla etkileşirken araya sürekli işletim sistemi girmez.
  - Bedeli: uygulamalar birbirinin ayağına basmayacak şekilde kaynakları yönetmek zorundadır, yani bir nevi işletim sistemi gibi davranırlar.
- İşletim sisteminin soyutlama rolü
  - İşletim sistemi bir soyutlama sağlar; uygulamalar donanımdan bağımsız biçimde ondan hizmet alıp kendi işlerine yoğunlaşır. Bunun bir yükü vardır; exokernel bu yükü kaldırmaya çalışır.
- Dinamik enstrümantasyon makalesinin farkı
  - Hoca makalenin diğer dinamik enstrümantasyon çalışmalarından önemli bir farkı olduğunu, bunun başlıkta yazdığını söyledi ve "fine-grained ne demek?" diye ipucu verdi. "Hazır işletim sistemine uygulanması" ve "yeniden derleme gerektirmemesi" asıl cevap olarak kabul edilmedi.
  <!-- BELİRSİZ: Hoca asıl cevabı derste açıkça söylemedi; başlıktaki "fine-grained" vurgusu ipucu olarak kaldı. -->

## Kısa Tekrar Notları

- Exokernel = küçük çekirdek; donanımı düşük seviyeli arayüzle güvenli biçimde kütüphane işletim sistemlerine açar.
- Kaynak yönetimi uygulamada, koruma exokernel'dedir.
- Kütüphane işletim sistemi kullanıcı alanında, uygulamaya bağlı çalışır; uygulamaya özel olabilir.
- Tasarım ilkeleri: securely expose hardware, expose allocation, expose names, expose revocation.
- Abort protokolü: kaynağı geri vermeyen kütüphane işletim sisteminin güvenli bağlantısını zorla koparır.
- Enstrümantasyon: çalışan kodun çalışma anında ölçülmesi; dinamik olanı kod çalışırken yapılır.
- Makaledeki uygulama: UltraSPARC üzerinde Solaris çekirdeği, değiştirilmemiş ve çalışan çekirdek.
- Kullanım: performans analizi, izleme, hata ayıklama, kod kapsamı, güvenlik izleme, çalışma zamanı optimizasyonu.
- BSD study: 1985, Berkeley, BSD UNIX dosya sisteminin performans analizi.

## Detaylı Açıklamalar

- Exokernel fikri
  - Normal bir sistemde donanım kaynaklarını yöneten temel yazılım işletim sistemidir; uygulamalar kaynakları işletim sisteminden ister ve geri kalan bütün sorumluluğu ona bırakır. Exokernel makalesinde işletim sistemi aradan çıkarılır ve onun normalde üstlendiği yönetim görevi uygulamanın kendisine bırakılır. Ortada üç katman (işletim sistemi, exokernel, üstte bir katman) yoktur: klasik işletim sistemi kaldırılıp yerine exokernel konur.
  - Exokernel'in görevi donanım kaynaklarını olduğu gibi yukarıya açmak ve bu açmayı güvenli yapmaktır. Kaynaklar doğrudan uygulamalara verildiği için yönetimi de uygulamalar yapar. Uygulamalar birbirlerinin kaynaklarına müdahale etmeyecek şekilde yönetmek zorunda olduklarından kütüphane işletim sistemleri bir nevi işletim sistemi gibi davranır; hepsi kullanıcı alanında (user space) çalışır.
  - Bir öğrencinin belirttiği alternatif: her uygulamaya bir sanal makine ayırmak. Bu yaklaşım performans açısından verimli bulunmadığı için exokernel mimarisi önerilmiştir.
- Abort protokolü
  - Donanım doğrudan uygulamaya açıldığına göre bir noktada geri alınması gerekebilir. Uygulama kaynağı geri vermezse exokernel abort eder, yani yukarıya açtığı kaynağı zorla geri alır. Makaledeki ifadeyle abort protokolü, işbirliği yapmayan kütüphane işletim sistemlerinin güvenli bağlantılarını (secure binding) zorla koparmak için kullanılır.
- Dinamik enstrümantasyon
  - Statik yaklaşımda kod yeniden derlenip ölçüm noktalarına kod parçaları eklenir. Dinamik yaklaşımda kod çalışırken herhangi bir noktası ölçüm yapacak şekilde değiştirilir. Makalede bu, tamamen değiştirilmemiş ve çalışmakta olan hazır bir çekirdeğin hemen her makine komutunun önüne dinamik olarak üretilen kod eklenmesi biçiminde yapılmıştır. Bugün aynı şey örneğin Windows çekirdeğinde yapılmak istenebilir.
- BSD study
  - Makaleyi okurken "BSD study" adının neyi kastettiği özetin ilk cümlesinde ve giriş bölümünde yazmaktadır: Berkeley'deki araştırmacıların 1985'te BSD UNIX dosya sistemi üzerinde yaptığı performans analizi. Bir öğrenci makalenin Sprite dağıtık dosya sistemindeki erişim örüntülerini ve önbellek davranışını incelediğini okudu; hoca sorunun bu çalışma değil, adı geçen BSD çalışması hakkında olduğunu belirtti.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
