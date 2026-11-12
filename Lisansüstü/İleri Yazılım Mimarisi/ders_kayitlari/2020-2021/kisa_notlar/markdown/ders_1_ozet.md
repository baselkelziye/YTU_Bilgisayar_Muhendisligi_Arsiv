# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı: yüksek seviyeli mimari tasarım
  - Ders, özellikle günümüzün modern ve yüksek hacimli uygulamaları için yüksek seviyeli mimari tasarımların nasıl yapıldığını inceler (ekrandan, 00:17:20).
  - Odak, yazılımın detaylı tasarımı değil mimari tasarımdır. Mimariyi ifade edebilmek için önce yazılımın analizi ve tasarımı doğru biçimde yapılmalıdır.
  - Analiz ve tasarım nesneye yönelik yaklaşımla ele alınır. Geleneksel ya da işlevsel (fonksiyonel) yaklaşımlara girilmez.
- Dersin beklediği ön bilgi
  - Yazılım mühendisliği temelleri ve/veya sektörde yazılım geliştirme deneyimi (ekrandan, 00:17:20).
  - En az bir programlama dilinde kod yazabilme.
- Ders akışı: beş bölüm (ekrandan, 00:19:05)
  - 1. Bölüm, Giriş: yazılım ve yazılım mühendisliğinin temel problemleri hatırlanır.
  - 2. Bölüm, UML ve Analiz: bir tasarım problemi nasıl analiz edilir, UML ve OCL ile nasıl tanımlanır, analizin statik ve dinamik yönleri nelerdir.
  - 3. Bölüm, Yazılım Mimarisi: mimariler hakkında düşünmek, onları ifade etmek, işlevsel olmayan gereksinimlerin mimari belirlenmesine etkileri, mimari tasarımın gerçekleştirilecek modüllere dönüştürülmesi.
  - 4. Bölüm, Yazılım Tasarımı: nesne tasarımı, tasarım kalıpları, tasarım prensipleri, tasarım gözden geçirimi.
  - 5. Bölüm, Modern Mimari Yaklaşımlar: monolitikten sunucusuz mimarilere kadar yenilikçi yaklaşımlar.
- Beşinci bölümün içeriği
  - Monolitik yaklaşım, servis tabanlı yaklaşım ve mikro çekirdek (microkernel) tabanlı yaklaşım.
  - Mikroservis mimarisi ve mikroservis tasarım kalıpları (software architectural design patterns). Hoca bunu dersin en önemli kısmı olarak sunar.
  - Sunucusuz mimari (serverless architecture) ve üst düzey mimari tasarım.
  - Orta katman (middleware) çözümleri ve mimari tasarım kalıpları da dönemin ikinci yarısının konularıdır (ekrandan, 00:23:03).
- Ders hedefleri (ekrandan, 00:22:20)
  - Bir uygulamanın analiz ve tasarımını UML ile ifade edebilmek.
  - Yazılım mimarilerini tanımlayıp değerlendirebilmek.
  - Uygun mimari biçimi seçip kullanabilmek (hocanın örneği: bir problem için Pipe and Filter mimarisini seçmek).
  - Nesneye yönelik tasarım tekniklerini anlayıp uygulayabilmek.
  - Uygun yazılım tasarım kalıplarını seçip kullanabilmek, özellikle mikroservis dünyasında hangi kalıbın hangi problemde seçileceğini bilmek.
- Haftalık konu planının ekranda görünen ilk yedi haftası (ekrandan, 00:22:55)
  - Giriş ve genel bilgiler.
  - Tasarım kavramları, UML, nesneye yönelik analiz, UML sınıf modelleri.
  - Tasarım çalışmaları, formal tanımlama, OCL.
  - Davranış modelleme.
  - Yazılım mimarisi, mimari görünümler.
  - Mimari biçimler, işlevsel olmayan gereksinimler.
  - Orta katman çözümleri.
  <!-- BELİRSİZ: Planın yedinci haftadan sonraki satırları ekranda gösterilmedi. -->
- Kaynak kitaplar (ekrandan, 00:30:10)
  - Len Bass, Paul Clements, Rick Kazman: *Software Architecture in Practice*, 3. baskı.
  - Richard N. Taylor, Nenad Medvidovic, Eric M. Dashofy: *Software Architecture: Foundations, Theory, and Practice*.
  - Paul Clements ve diğerleri: *Documenting Software Architectures: Views and Beyond*, 2. baskı.
  - Dominic Duggan: *Enterprise Software Architecture and Design: Entities, Services, and Resources*.

## Hocanın Özellikle Vurguladığı Kısımlar

- Mikroservis mimarisi ve tasarım kalıpları dersin en önemli kısmıdır
  - Mikroservis mimarisinde uyulması gereken tasarım kalıpları ayrıntılı araştırılıp öğrenilecektir.
  - Hocaya göre mikroservis tasarım kalıpları beş ana başlık altında toplanır ve her birinin alt kırılımları vardır. Her kalıp için şu sorular sorulur: hangi problemi nasıl çözer, neden vardır, mikroservis modelinde nereye ve nasıl uygulanır.
- Sunucusuz mimari her problemde değil, gerektiği yerde kullanılmalıdır
  - Serverless yaygınlaşıyor, ama her probleme uygun bir çözüm değildir.
- UML ile "kitabına uygun" ifade
  - Analiz ve tasarım modeli UML ile olması gerektiği gibi, doğru biçimde ifade edilmelidir.
- Tasarım öğretilmez, yaparak öğrenilir (ekrandan, 00:23:03)
  - Derste modelleme ve teknolojilerden bahsedilir. Tasarım problemlerini çözerken bunlardan yararlanılır.
- Agile ile bu dersin farkı
  - Agile bir süreç yönetimi yaklaşımıdır. Bu ders ise süreç yönetimine değil, ürünün kendisinin (mimarisinin) geliştirilmesine odaklanır.

## Kısa Tekrar Notları

- Ders: detaylı tasarım yerine yüksek seviyeli mimari tasarım, nesneye yönelik yaklaşım.
- Beş bölüm: Giriş, UML ve Analiz (UML, OCL, statik ve dinamik yön), Yazılım Mimarisi (işlevsel olmayan gereksinimlerin etkisi, modüllere dönüşüm), Yazılım Tasarımı (kalıplar, prensipler, gözden geçirme), Modern Mimari Yaklaşımlar.
- Modern mimariler: monolitik, servis tabanlı, mikro çekirdek, mikroservis, sunucusuz.
- Dönemin ikinci yarısının konuları: orta katman (middleware) ve mimari tasarım kalıpları, özellikle mikroservis kalıpları.
- Hedef: UML ile analiz ve tasarım, mimari değerlendirme ve seçim, nesneye yönelik tasarım, uygun tasarım kalıbı seçimi.
- Temel kaynak: *Documenting Software Architectures*. Yanında *Software Architecture in Practice*.
- Agile süreç yönetimidir. Bu dersin konusu ürünün mimarisidir.

## Detaylı Açıklamalar

Bu ilk ders, dönemin ilk haftasında yapılan tanıtım dersidir. Akademik içerik dersin kapsamı, akışı, hedefleri ve kaynaklarıyla sınırlıdır.

Dersin temel sorusu şudur: modern ve yüksek hacimli bir uygulamanın yüksek seviyeli mimarisi nasıl tasarlanır ve nasıl ifade edilir? Hoca, mimariyi ifade etmenin ön koşulunun yazılımın doğru analizi ve tasarımı olduğunu söyler. Bu yüzden dersin ilk bölümleri UML ile nesneye yönelik analize ayrılır. Bu bölümde analizin statik yönü (sınıf modelleri) ve dinamik yönü (davranış modelleme) ile OCL kullanılarak formal tanımlama işlenir. Ardından yazılım mimarisinin ne olduğu, mimari görünümler, mimari biçimler ve işlevsel olmayan gereksinimlerin mimariye etkisi gelir. Yazılım tasarımı bölümünde nesne tasarımı, tasarım kalıpları, tasarım prensipleri ve tasarım gözden geçirimi ele alınır.

Dersin yarısını oluşturan son bölüm modern mimari yaklaşımlardır. Monolitik yaklaşımdan başlanır, servis tabanlı ve mikro çekirdek tabanlı yaklaşımlara bakılır. Asıl ağırlık mikroservis mimarisindedir: mikroservis mimarisinin ne olduğu ve bu mimaride uyulması gereken tasarım kalıpları. Son olarak sunucusuz (serverless) mimariler ve üst düzey mimari tasarım işlenir.

Hoca, mimari seçimin problemden geldiğini bir örnekle anlatır. Çok sayıda satıcısı ve milyonlarca alıcısı olan bir alışveriş sitesi, kampanya dönemlerinde ani yük artışı yaşar. Bu talebin, hizmet yavaşlamadan ve sistem mümkün olduğunca kararlı kalarak karşılanması için nasıl bir mimari tasarım gerektiği sorusu, dersin ele aldığı türden bir problemdir. Hoca, böyle bir çözümün örneğin bir bulut sağlayıcısı (AWS) üzerinde sunucusuz bir mimariyle kurgulanabileceğini de söyler.

Hoca dersi lisansta da seçimlik olarak açtığını, orada yalnız temel mimarilere değinip mikroservis tasarım kalıplarına girmediğini belirtir. Lisansüstü dersin farkı bu ileri konulardır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
