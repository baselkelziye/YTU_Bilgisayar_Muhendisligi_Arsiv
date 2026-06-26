# Ders 4 Çalışma Özeti

## Genel Konular

- Araştırma ödevi gereksinimleri
  - IEEE formatında 4-8 sayfa arası makale hazırlanması.
  - Ana konu: mobil kullanıcı deneyimi (mobile user experience); hangi faktörlerin önemli olduğu, neden kritik olduğu, iOS ve Android farklılıkları.
  - Mobile uygulama geliştirme konseptleri; karşılaştırmalı tablolar ve şekiller kullanılması.
  - Hikaye anlatımı (beginning-middle-end) önemli; sadece bilgi yığmak değil, akış oluşturmak gerekiyor.
  - Kaynakça (bibliyografi) zorunlu; sadece internet siteleri değil akademik makaleler de kullanılmalı.
  - Scholar Google kullanımı; üniversite kütüphanesi üzerinden IEEE, Springer, Elsevier, ACM gibi veritabanlarına erişim.

- JIT (Just-In-Time) ve AOT (Ahead-Of-Time) derleme kavramları
  - JIT: uygulama başlatıldığında, kullanılmadan hemen önce derlenmesi; her açılışta compile edilmesi gerektiği.
  - AOT: uygulama kurulduğunda bir kez derlenmesi, sonraki açılışlarda tekrar derlenmemesi.
  - AOT'un avantajı: zamandan tasarruf (her açılışta compile edilmediği için).
  - AOT'un dezavantajı: platform değişikliklerinde uyumsuzluk yaşanabilmesi, hata ile karşılaşma riski, disk alanı kullanımı.
  - Google ve Android'in her ikisinin kombinasyonunu kullandığı; Dalvik Virtual Machine yerine artık Android Runtime (ART) environment'ı kullanıldığı.
  - ART'ta Java veya Kotlin ile geliştirilen kodlar bir sanal işlemci üzerinde çalışır, oradan makine kodu üretilir.

- Android cihaz çeşitliliği
  - Android Studio yüklendiğinde geliştirme yapılabilecek cihaz türleri: akıllı telefon, tablet, akıllı saat (smart watch), Android Auto (arabalar için), Android Things (IoT cihazları), televizyonlar.
  - Her cihaz türünün farklı arayüz önerileri ve arka plan kütüphaneleri olduğu.
  - Proje açarken hangi ortam için geliştirileceğinin kritik bir karar olduğu.

- Android uygulama geliştirme gereksinimleri
  - Android SDK: uygulama geliştirmek için gerekli.
  - JDK (Java Development Kit) ve JRE (Java Runtime Environment): native development için gerekli.
  - NDK (Native Development Kit): alt seviye geliştirme (C/C++ ile) için gerekli, ama zorunlu değil.
  - Bilgisayar: Linux, macOS veya Windows işletim sistemi.
  - Emülatör veya Android cihaz: test ve çalıştırma için.
  - IDE: Android Studio (IntelliJ IDEA altyapısına dayalı, 2013'ten beri); Android uygulama geliştirmek için olmazsa olmaz seçeneklerden biri.
  - Android Studio dışında cross-platform araçları da kullanılabilir; "Android uygulama geliştirmek" ile "native Android uygulama geliştirmek" kavramları farklıdır.
  - Donanım gereksinimleri: en az 4 GB RAM (8 GB önerilir), belirli disk alanı (4 GB civarı).

## Hocanın Özellikle Vurguladığı Kısımlar

- Araştırma ödevi için copy-paste yapılmaması gerektiği
  - "Copy paste mantığıyla değil, okuduklarınızı belirli bir süzgeçten geçirerek aktarmanız"; bazı temel bilgiler kullanılabilir ama hikaye size ait olmalı.
  - İngilizce yazıp bir yerden copy paste alındığı düşünülen ödevin notunun sıfır olacağı; Türkçe yazmanın bu riski azaltacağı.
  - Şekil ve tablo kullanımının desteklendiği; anlatım dilinin önemli olduğu, hikayenin başı-sonu-gelişmesi olması gerektiği.

- API level uyumunun önemi
  - Farklı API level'larında farklı sıkıntılar çıkabileceği; hocanın belirlediği API level'a uyulması gerektiği.
  - Önümüzdeki haftadan itibaren Android Studio kurulumu ve API level'ın konuşulacağı.

- ART (Android Runtime) ile gelen performans kazanımı
  - JIT ve AOT kombinasyonu sayesinde Android'in performans avantajı elde ettiği; Dalvik VM'in yerini ART'ın aldığı.
  - Java veya Kotlin kodunun bir sanal işlemci üzerinde çalışıp oradan makine kodu üretilmesi süreci.

- Derse aktif katılımın önemi
  - Sorulara cevap veremeyen öğrencilerin notlarının olumsuz etkileneceği uyarısı.
  - Sınıfta söz alarak düşüncelerin paylaşılması gerektiği.

- Bilgisayar mühendisliğinin farklı alanlarında uzmanlaşmanın önemi
  - Bilgisayar mühendislerinin sadece kod yazmak yerine farklı alanlarda da yetkin olması gerektiği.
  - Android uygulama geliştirmenin sadece kod yazmaktan ibaret olmadığı, kavramsal bilginin de önemli olduğu.

## Kısa Tekrar Notları

- Ödev: IEEE format, 4-8 sayfa, mobile user experience konusu, kaynakça zorunlu.
- JIT: her açılışta derleme; AOT: kurulumda bir kez derleme.
- Android, JIT+AOT kombinasyonu kullanır; ART (Android Runtime) Dalvik VM'in yerini almıştır.
- Android cihaz türleri: telefon, tablet, akıllı saat, Android Auto, Android Things, TV.
- Geliştirme gereksinimleri: Android SDK, JDK, NDK (opsiyonel), IDE (Android Studio), emulator/cihaz.
- Android Studio: IntelliJ IDEA tabanlı, 2013'ten beri.
- Donanım: min 4 GB RAM (8 GB önerilir), ~4 GB disk.
- Cross-platform ≠ native: aynı kavram değil.

## Detaylı Açıklamalar

Dersin başlangıcında araştırma ödevi hakkında detaylı bilgi verilmiştir. Ödevin IEEE formatında 4-8 sayfa arasında bir makale olarak hazırlanması beklendiği, dökümanda belirli başlıklar önerildiği ancak bunların zorunlu olmadığı, hatta kendi belirlenecek başlıklarla hareket etmenin daha iyi olacağı belirtilmiştir. Çünkü herkesin konuyu farklı bir hale getirebileceği, temelde mobile user experience konusunda hangi önemli faktörlerin olduğu ve neden bu konunun kritik olduğunun anlatılması gerektiği söylenmiştir. iOS ve Android tarafındaki farklılıklara da değinilebileceği, mobile uygulama geliştirme konseptleri özelinde farklı bakış açılarının incelenebileceği belirtilmiştir. Şekil ve tablo kullanımının özellikle desteklendiği, anlatım dilinin önemli olduğu, hikayenin bir başı ve sonu olması gerektiği vurgulanmıştır. Kaynakça bölümünün olmazsa olmaz olduğu, sadece internet sitelerinin değil akademik makalelerin de kullanılması gerektiği, Scholar Google kullanımının öğrenilmesi gerektiği, üniversite kütüphanesi üzerinden IEEE, Springer, Elsevier, ACM gibi veritabanlarına erişim sağlanabileceği anlatılmıştır. Hoca, son hafta sonuna bırakılmaması gerektiğini, hafta sonu itibarıyla arama işinin başlatılması gerektiğini ısrarla vurgulamıştır.

Dersin ana konusuna, yani Android'e ve geliştirme ortamına geçildiğinde ilk olarak JIT (Just-In-Time) ve AOT (Ahead-Of-Time) derleme kavramları işlenmiştir. JIT'de uygulamanın başlatıldığı anda, kullanılmadan hemen önce derlendiği ve her açılışta bu derleme sürecinin tekrarlandığı açıklanmıştır. AOT'da ise uygulamanın kurulduğu anda bir kez derlendiği, sonraki açılışlarda tekrar derlenmesine gerek kalmadığı belirtilmiştir. AOT'un performans açısından zaman kazancı sağladığı, her seferinde compile edilmediği için hızlı açıldığı söylenmiştir. Ancak AOT'un bazı dezavantajları da vurgulanmıştır: platformda değişiklikler olduğunda önceden derlenmiş versiyonla uyumsuzluk çıkabilir, hata ile karşılaşılabilir ve disk alanı açısından daha fazla yer kaplayabilir. Google ve Android'in her iki yaklaşımın kombinasyonunu kullandığı, Dalvik Virtual Machine yerine artık Android Runtime (ART) environment'ının kullanıldığı belirtilmiştir. ART'ta Java veya Kotlin ile geliştirilen kodların bir sanal işlemci üzerinde çalıştığı, oradan makine kodu üretilerek dönüşümün sağlandığı açıklanmıştır.

Android Studio yüklendiğinde geliştirme yapılabilecek cihaz türleri öğrencilerle birlikte listelenmiştir. Akıllı telefon, tablet, akıllı saat, Android Auto (arabalar için), Android Things (IoT cihazları için), televizyonlar bu cihaz türleri arasında sayılmıştır. Her bir cihaz türünün farklı arayüz önerileri ve arka planda farklı kütüphaneler kullandığı, proje açarken hangi ortam için geliştirileceğinin kritik bir karar olduğu vurgulanmıştır.

Android uygulama geliştirme gereksinimleri detaylı olarak ele alınmıştır. Android SDK'nın uygulama geliştirme için gerekli olduğu, JDK ve JRE'nin native development için gerekli olduğu belirtilmiştir. NDK'nın (Native Development Kit) alt seviye geliştirme (C/C++ ile) için gerekli olduğu ancak zorunlu olmadığı, sadece belirli durumlarda gerektiği söylenmiştir. Bilgisayar tarafında Linux, macOS veya Windows işletim sistemi kullanılabileceği, her biri için uygun yazılımların indirilmesi gerektiği belirtilmiştir. Emülatör veya Android cihazın test ve çalıştırma için gerekli olduğu vurgulanmıştır. IDE olarak Android Studio'nun olmazsa olmaz seçeneklerden biri olduğu, IntelliJ IDEA altyapısına dayalı olduğu ve 2013'ten beri kullanıldığı belirtilmiştir. Android Studio dışında cross-platform araçlarıyla da Android uygulaması geliştirilebileceği, ancak "Android uygulama geliştirmek" ile "native Android uygulama geliştirmek" kavramlarının farklı olduğu vurgulanmıştır. Donanım gereksinimleri olarak en az 4 GB RAM (8 GB önerilen), belirli bir disk alanı (yaklaşık 4 GB) gerektiği belirtilmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
