# Ders 6 Çalışma Özeti

## Genel Konular

- Kilitli dolap probleminin çözüm deseni
  - Başta bütün dolaplar kapalıdır; birinci öğrenci hepsini açar, sonraki öğrenciler kendi numaralarının katı olan dolapların durumunu tersine çevirir.
  - Bir dolabın durumu, numarasının bölen sayısı kadar değişir. Bölenler çiftler hâlinde gelir; yalnız tam karelerde bir bölen kendisiyle eşleşir ve bir kez sayılır.
  - Bu yüzden tam kare numaralı dolaplar tek sayıda kez değişir ve başlangıç durumunun tersinde kalır; diğerleri başlangıç durumuna döner.
  - Hoca bu problemin aslında bir matematik problemi olduğunu, ama "çözüme başlamadan önce süreci düşünme" açısından iyi bir alıştırma olduğunu söyledi.
- Tekrar etmeyen sayıları sayma problemi ve zaman-bellek dengesi
  - Dizi üzerinde kaba kuvvetle (her elemanı diğerleriyle karşılaştırarak) arama $O(n^2)$ zaman alır.
  - Yardımcı bir dizi ya da veri yapısı kullanmak zamanı azaltır ama bellek (space) karmaşıklığını artırır; değerler çok büyük olabiliyorsa bu yardımcı yapı çok yer kaplar.
  - Hoca zaman ve bellek karmaşıklığının bazen dengelenmesi, kaynaklar kısıtlıysa bellekten yana tercih yapılması gerektiğini vurguladı.
- Doğrusal arama ve ikili arama tekrarı
  - İkili arama (binary search) yalnız sıralı dizide kullanılabilir.
  - Veri sırayla geliyorsa insertion sort mantığıyla her yeni eleman yerine eklenerek dizi sıralı tutulabilir; veri karışık geliyorsa önce sıralamak gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Zaman ve bellek karmaşıklığı arasındaki denge
  - Yardımcı veri yapısı zamanı kısaltır ama belleği artırır. Kaynak kısıtına göre karar verilir ve Büyük-O gösterimindeki karmaşıklık mümkün olduğunca azaltılmaya çalışılır.
- Kod yazmadan önce algoritma tasarlamak
  - Hoca, C kodu yazmaya geçmeden önce problemin nasıl çözüleceğinin ve karmaşıklık açısından nasıl bir çözüm geliştirileceğinin düşünülmesini istedi.
- İkili aramanın ön koşulu
  - Dizi sıralı değilse ikili arama uygulanamaz; ya önce sıralanır ya da veri baştan sıralı tutulur.

## Kısa Tekrar Notları

- Kilitli dolap: yalnız tam kare numaralı dolapların durumu başlangıcın tersine döner (bölen sayıları tektir).
- 100 dolapta, hepsi başta kapalıyken sonunda açık kalanlar: 1, 4, 9, 16, 25, 36, 49, 64, 81, 100.
- Kaba kuvvet tekrar kontrolü: $O(n^2)$ zaman, ek bellek yok.
- Yardımcı dizi: daha az zaman, daha fazla bellek; değer aralığı büyükse bellek sorunu çıkar.
- İkili arama için dizi sıralı olmalıdır.
- Sırayla gelen veride insertion sort mantığıyla dizi sürekli sıralı tutulabilir.

## Detaylı Açıklamalar

- Bu kayıt kısa bir uygulama oturumudur. Oturumun başında önceki uygulamada düşünülmek üzere bırakılan iki problem konuşuldu, ardından önceki teori dersindeki arama algoritmalarına kısaca dönüldü. Oturumun geri kalanı uygulamalı bir çalışmaya ayrıldı; o çalışmanın sorusu kayıtta görünmüyor.
- Kilitli dolap probleminde bir öğrenci deseni şöyle açıkladı: bir dolabın numarası tam kare ise son durumu ilk durumunun tersi olur, çünkü karekök olan bölen iki kez değil bir kez sayılır; tam kare değilse dolap hangi durumla başladıysa o durumda kalır. Bunun nedeni şudur: $k$ numaralı dolaba, $k$'yi bölen her öğrenci bir kez dokunur. Bölenler $d$ ve $k/d$ biçiminde çiftlenir; $d = k/d$ olması yalnız $k$ tam kare iken mümkündür. Böylece tam karelerin bölen sayısı tek, diğer sayılarınki çifttir.
- Ders sonrası not: Hoca toparlarken "tam kare olanların kapıları açık kalmıyor, tam kare olmayanların dolabı açık kalıyor" dedi. Başta bütün dolaplar kapalıyken doğrusu tersidir: tam kare numaralı dolaplar tek sayıda kez değiştiği için açık kalır, diğerleri kapanır (100 dolap için python ile denendi: 1, 4, 9, ..., 100 açık kalıyor). Öğrencinin söylediği desen doğrudur. <!-- BELİRSİZ: hocanın cümlesi altyazıda bozuk aktarılmış olabilir. -->
- Tekrar etmeyen sayıları sayma probleminde bir öğrenci, dizi üzerinde gezmek dışında bir yöntem bulamadığını, karmaşıklığın her durumda $O(n^2)$ çıktığını söyledi. <!-- BELİRSİZ: altyazıda "Ankara" yazıyor; bağlamdan "n kare" olarak yorumlandı. --> Farklı bir dizi oluşturmanın mümkün olduğunu, ama tam sayıların çok büyük değerler alabileceği durumda bunun çok yer gerektireceğini ekledi. Döngü koşullarıyla aramayı biraz kısıtlamak mümkün olsa da karmaşıklık değişmiyordu. Hoca bu tartışmanın değerli olduğunu, çünkü yedek dizi ya da yedek veri yapısı kullanmanın bellek karmaşıklığını artırdığını, zaman ve bellek karmaşıklığının bazen dengelenmesi gerektiğini söyledi.
- İkili arama tekrarında bir öğrenci dizinin sıralı olmadığını, bu yüzden ikili aramanın uygun olmadığını hatırlattı. Hoca önce dizinin sıralanması ya da sıralı olmasının garanti edilmesi gerektiğini söyledi. Veriler tek tek geliyorsa her biri insertion sort'taki gibi doğru yerine eklenerek dizi sıralı tutulabilir; karışık bir sırada toplu geliyorsa önceden sıralama yapılır. Dizi sıralıysa ikili aramada `low`, `mid`, `high` indisleriyle çalışılır; hoca bu indislerde kafası karışan öğrencilerin kodu yazıp denemesini önerdi.
- Hoca uygulamalı çalışmadan önce kod yazmadan algoritma tasarlamanın gerekli olduğunu, özellikle karmaşıklık açısından nasıl bir çözüm geliştirileceğinin düşünülmesini istedi. C kodlarının ANSI C standardında yazılması gerektiğini de hatırlattı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
