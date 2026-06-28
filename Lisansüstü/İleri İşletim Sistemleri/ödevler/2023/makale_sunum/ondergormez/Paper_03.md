# Makale 3

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# Communicating Sequential Processes

* The Queen's University, Belfast, Northern Ireland daki C.A.R. Hoare tarafından yayınlanmış.
* Communications of the ACM, August 1978, Volume 21, Number 8
* 1978 ACM 0001-0782/78/0800-0666 $00.75

# Keywords

* Programming Primitives
* Program Structures
* Parallel Programming
* Concurrency
* Coroutines
* Data Representations
* Recursion
* Monitors

# Hangi konu ile alakalı?

* Process lerin girdilerden ve çıktılardan oluştuğunu ve ardı sıra gelen process lerin birbiri ile haberleştirilerek daha önceki process ler tarafından oluşturulan çıktıların kullanıp devam edebileceğini savunmaktadır. 
* Paralel komutların işlenmesi üzerine çalışmalar yapılmıştır.
* Birçok senkronizasyon gerektiren örnek üzerinden bu işlemlerin nasıl yapılacağı ile ilgili bilgiler vermiş.
* Veri yapılarında değinilen **Edsger W. Dijkstra** nın birçok makalesin atıfta bulunmuş.

# Amacı nedir?

* Amaç birden fazla işlemcisi olan makinelerde işlemcilerin arasındaki senkronizasyon ve birlikte çalışması için haberleşmesi problemlerine bir çözüm önerisi sunmak.

**Makaleden Alıntı**: three basic constructs;
* A repetitive construct (e.g. the while loop),
* An alternative construct (e.g. the conditional if..then..else),
* and normal sequential program composition (often denoted by a semicolon).

Farklı programlama dilleri farklı yaklaşımlar öne sürerek bunlar hakkında özellik implementasyonları gerçekleştirmişlerdir.
* Subroutines (Fortran), 
* procedures (Algol 60)
* entries (PL/I)
* coroutines (UNIX)
* classes (SIMULA67)
* processes and monitors (Concurrent Pascal)
* clusters (CLU)
* forms (ALPHARD) 
* actors (Hewitt)

# Kapsam ve çalışma nerelere dokunmuş?

* Paralel komut, içerdiği alt process lerin hepsi başarılı bir şekilde sonlanırsa başarılı sayılmaktadır.
Genel komutlardan bahsedilmiş. Sonrasında eş güdümlü olarak çalışan sequential process ler için gerekli olan diğer komutları anlatmış.
  
* Copy: Bir process in çıktısı diğer process in girdisi olarak copy yapılabilir.
* Squash: Replace etmek işlemi
* Disassemble: Input u ayrıştırma
* Assemble: Input u birleştirme
* Reformat: Formatını düzenleme

Subroutine lere gönderilen veriler "by value" gönderildikleri için class instance soyutlanmış data lar üzerinde çalışır. Üretilen sonucu geri döndürür.

# Deneysel çalışmalarda ne elde edilmiş?

* Günümüzde de kullanımı devam eden temel bounded buffer gibi yöntemlerden bahsetmiştir.
* Deadlock: 2 veya daha fazla process birbiriyle iletişim halinde olsa ve bunların input ve output ları birbirlerini bekliyor olsa meydana gelen durumdur.
* Monitor: Yöntem critical region a benzer ve senkronizasyon için özel değişkenlerden birini (events, queue veya condition variable) gerektirir.
* Producer - Consumer problem
* Integer semaphore un 100 kadar client tarafından kullanıldığı senaryo dan bahsetmiş.
* Dining philoshophers: Çözüm ya masaya 1 tane eksik filozof oturacak, ya da herkes ilk önce solundaki sonra sağındaki çatalı kontrol ettikten sonra eline çatalı alacak.
  * Odanın kullanımı
  * Çatalın kullanımı gibi konularda senkronizasyon yapılması gerekiyor.

# Çözmesi gereken şeyler kalmış mı (feature work)?

* Doğru programların oluşturulması için geliştirme ve doğrulama süreçleri hakkında gerekli olanları yoksaymıştır.
* Efektif program implementasyonu ile ilgili yapılması gerekenleri yoksaymıştır.
* Library lerin programlama dilinde kullanımıyla alakalı tasarım problemlerini yoksaymış.

# Conclusion

* Makaleyi yazan kişi kendisi bir programlama dili tasarlasa nasıl olacağına dair bilgiler vermiş.
* Automatic buffering (bir process in output unun girdi olacağı process input u hazır olana kadar bekletilmesi) kullanılmasına karşı çıkmış.
* Input, output ve concurrency önerilerinde bulunmuş.
