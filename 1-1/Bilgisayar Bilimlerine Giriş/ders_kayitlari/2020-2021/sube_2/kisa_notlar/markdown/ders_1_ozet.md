# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı ve konu sırası
  - Ders, bilgisayar biliminin kısa bir tarihçesiyle başlar (ekrandan, 00:40:00).
  - Temeller kısmında sayı sistemleri ve sistemler arası dönüşüm, işaretli ve işaretsiz sayılar, tam sayılar ve gerçek (kayan noktalı) sayılar işlenir.
    - Bu sayıların bilgisayarda nasıl gösterildiği konuşulur. Bilgisayar ikili (binary) sistemle, yalnız 0 ve 1 ile çalışır. Buna rağmen 3,14 gibi bir gerçek sayının nasıl gösterildiği dersin sorularından biridir.
  - Algoritmalara giriş kısmında algoritmanın ne olduğu ve nasıl ifade edildiği işlenir. İki gösterim yolu vardır: akış diyagramı (flowchart) ve sözde kod (pseudocode). Bu derste hep akış diyagramı kullanılır.
  - Akış diyagramlarının kontrol akışı elemanları uzun süre işlenir.
  - Temel veri yapıları: diziler, karakter dizileri ve özel bir durum olarak string yapısı, çok boyutlu diziler.
  - Akış diyagramlarıyla kurulan çözümler C programlama dilinde uygulanır.
  - Arama (search) ve sıralama (sort) algoritmaları işlenir.
    - Arama: sıralı (sequential, lineer) arama, daha hızlı olan ikili arama (binary search), ağaç gibi dizi dışındaki veri yapılarında arama.
    - Sıralama: Bubble Sort, Quick Sort, Selection Sort, Radix Sort ve mümkün olduğunca fazlası.
- Algoritma kavramı
  - Kaba tanımıyla algoritma, bir işin nasıl yapılacağının tarifidir.
  - Bu tarif akış diyagramıyla ya da sözde kodla ifade edilebilir.
- Laboratuvar uygulamalarının içeriği
  - Uygulamalar pratik, "elle yaparak" (hands-on) deneyim kazandırmaya yöneliktir.
  - İlk uygulama bir işletim sistemi (çoğunlukla Linux) kurulumudur. Kurulum, mevcut işletim sisteminin üzerine yerleştirilen bir emülatörün içinde yapılır. Böylece bilgisayardaki asıl işletim sistemi silinmez.
  - Kurulum sırasında önyükleyici (bootloader), disk bölümlendirme (partitioning) ve neden yapıldığı, sektör ve silindir kavramları, dosya sistemi (file system) ve görevi konuşulur.
  - Ofis yazılımlarının (Word, Excel) bilinmeyen ayrıntıları ele alınır.
  - Programlamaya geçince bir IDE ya da derleyici ve editör kullanımı gösterilir.
- Öğrenmeyi öğrenmek ve öğrenme stilleri
  - Öğrenirken bir amaç olmalıdır. Neyi anlamaya çalıştığınızı ve hangi değerli bilgiyi almaya çalıştığınızı bilmelisiniz (ekrandan, 02:55:00).
  - Öğrenmeyi engelleyen ve motive eden etkenler anlaşılmalıdır: zihinsel (acı, endişe, korku), fiziksel (yorgunluk), çevresel ve sosyal etkenler (ekrandan, 03:00:00).
  - 14 soruluk bir öğrenme stili testi uygulanır. Her soruda A, B ya da C seçilir. En çok seçilen harf baskın öğrenme stilini gösterir (ekrandan, 03:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Akış diyagramı için internet kaynaklarına bakılmamalı
  - Akış diyagramı inşaat, elektronik gibi birçok alanda kullanılır. Her alanın kendine göre sembolleri ve okların bağlanma kuralları vardır.
  - Derste esas alınan, derste anlatılan gösterimdir. Başka kaynaklardaki farklı çizimler kafa karıştırır ve değerlendirmede sorun çıkarır.
- Programlama kaynakları seçilirken dikkatli olunmalı
  - Mümkünse üniversitelerin, tercihen bilgisayar mühendisliği bölümlerinin sayfaları kullanılmalıdır.
  - C dilindeki `break`, `continue` ve `goto` ifadeleri derste kullanılmaz. Hocaya göre bu ifadeler dili daha etkili kılmak için değil, önceki kuşak programcıları yeni dile taşımak için vardır. Program akışında karmaşa yaratırlar. İnternetteki kodlarda sıkça görülseler de bu derste kabul edilmez.
- Çalışmalar bireysel yapılmalı
  - Grup çalışması istenmedikçe her iş tek başına yapılır. Bir problem üzerine arkadaşlarla konuşmak serbesttir, ama başkasının akış diyagramını ya da internetten bulunan bir çözümü olduğu gibi kullanmak etik değildir.
- Herkes kendi notunu tutmalı
  - Başkasının notu, onun anladığı kadardır ve ders anlatımının yerini tutmaz. Başkasının notundaki hatalar size bilgi olarak geçer.
- Öğrenme stili testinin doğru ya da yanlış cevabı yoktur
  - Test bir değerlendirme değil, farkındalık içindir. Bir kişi birden fazla stilden farklı oranlarda beslenebilir.

## Kısa Tekrar Notları

- Algoritma, bir işin nasıl yapılacağının tarifidir. Gösterim yolları: akış diyagramı ve sözde kod. Bu derste akış diyagramı kullanılır.
- Konu sırası: tarihçe, sayı sistemleri ve sayıların gösterimi, algoritmalar, akış diyagramları, diziler ve stringler, C ile uygulama, arama ve sıralama algoritmaları.
- Bilgisayar ikili sistemle (0 ve 1) çalışır. Tam ve gerçek sayıların bu sistemde gösterimi dersin konusudur.
- Arama: sıralı (lineer) arama, ikili arama, ağaçta arama. Sıralama: Bubble, Quick, Selection, Radix Sort.
- Laboratuvarlarda Linux, bir emülatör içine kurulur. Bootloader, partitioning, sektör ve silindir, dosya sistemi konuşulur.
- Akış diyagramında yalnız derste anlatılan gösterim kullanılır.
- `break`, `continue`, `goto` bu derste kullanılmaz.
- Öğrenme stilleri: A görsel, B işitsel, C dokunsal (kinestetik).

## Detaylı Açıklamalar

- **Dersin akışı:** Ders, bilgisayar biliminin kısa tarihçesiyle açılır. Ardından öğrencilerin kısmen bildiği temel konular ele alınır: sayı sistemleri, sistemler arası dönüşüm, işaretli ve işaretsiz sayılar, tam ve kayan noktalı sayılar. Bilgisayarda her şey 0 ve 1 ile ifade edildiği için, bu sayıların ikili sistemde nasıl gösterildiği önemli bir sorudur. Ardından dersin en temel konusu olan algoritmalara geçilir. Algoritma bir işin yapılış tarifidir. Bu tarif akış diyagramı ya da sözde kodla yazılabilir, bu derste akış diyagramı kullanılır. Akış diyagramının elemanları ve kontrol akışı uzun süre işlenir. Sonra diziler, karakter dizileri, stringler ve çok boyutlu diziler gelir. Bu konular C dilinde uygulanır. Son olarak arama (sıralı ve ikili arama, ağaç yapısında arama) ve sıralama algoritmaları (Bubble, Quick, Selection, Radix Sort) işlenir. Hoca sıralamayı bilgisayar mühendisliğinde önemli bir problem olarak tanıtır.
- **Bilgisayar gereksinimi:** Akış diyagramları elle, kağıt üzerinde çizilebilir. Bu kısım için bilgisayar şart değildir. C ile program yazmak, işletim sistemi kurmak ve laboratuvar uygulamalarını yapmak için ise bilgisayar gerekir.
- **Laboratuvar uygulamaları:** Normal dönemde laboratuvarlar asistanlarla, sınırlı sayıda yapılır. Bu dönemde uygulamalar çevrim içi ve hocayla birlikte yürütülür. İlk iş Linux kurulumudur. Kurulum, kullanılan bilgisayardaki işletim sistemi (Windows ya da Linux) üzerine kurulan bir emülatörün içinde yapılır. Aynı emülatörde yeni bir sanal makine yaratıp başka işletim sistemleri de kurulabilir. Bu yüzden asıl işletim sistemi kaybolmaz. Kurulum adımlarında bootloader, partitioning, sektör, silindir ve dosya sistemi kavramları açıklanır. Sonraki uygulamalarda ofis yazılımları ile IDE, derleyici ve editör kullanımı ele alınır.
- **Kaynak seçimi:** Tarihçe ya da arama ve sıralama algoritmaları için internet kaynakları kullanılabilir. Akış diyagramında ise her alanın kendi sembol kuralları olduğundan yalnız derste anlatılan gösterime bağlı kalınmalıdır. Programlama kaynaklarında üniversitelerin bilgisayar mühendisliği sayfaları tercih edilmelidir. `break`, `continue` ve `goto` ifadeleri dilde tarihsel uyumluluk için bulunur ve programın akışını karmaşıklaştırır. Bu derste kullanılmazlar.
- **Öğrenmeyi öğrenmek:** Bir şeyi öğrenirken amaç bilinmelidir: neyi anlamaya çalıştığınızı, neyden uzaklaşmak istediğinizi, hangi değerli bilgiyi almaya çalıştığınızı. Amaçla öğrenilen şeye daha çok dahil olunur ve daha iyi hatırlanır. Öğrenilenler belgelenmeli, düzenlenmeli ve güncellenmelidir. Engelleyici etkenlere örnek olarak hoca şunu verir: akşamları hep yorgunsanız sabah çalışın, ses sizi etkiliyorsa sessiz bir yer bulun.
- **Öğrenme stili testi:** 14 soruda öğrenci kendine en uygun şıkkı seçer. A çoğunluktaysa görsel ağırlıklı stil (görerek ve okuyarak, renkli, grafik ve harita içeren kaynaklarla öğrenme), B çoğunluktaysa işitsel ağırlıklı stil (işiterek, dinleyerek ve tartışarak öğrenme), C çoğunluktaysa dokunsal ya da kinestetik ağırlıklı stil (yaparak, fiziksel temasla öğrenme) baskındır (ekrandan, 03:10:00). Hocanın önerisi şöyledir: dokunsal ağırlıklı öğrenci akış diyagramı konusunda kendine problem kurup tekrar tekrar akış çizmeli, işitsel ağırlıklı öğrenci kayıtlı dersleri yeniden dinlemeli, görsel ağırlıklı öğrenci okumalı ve slaytları izlemeli. Akış çizerek çalışmak her stil için faydalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
