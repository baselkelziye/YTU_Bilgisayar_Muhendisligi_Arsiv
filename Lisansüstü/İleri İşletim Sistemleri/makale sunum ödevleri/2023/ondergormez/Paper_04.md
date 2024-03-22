# Makale 4

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# Monitors: An Operating System Structuring Concept

* The Queen's University of Belfast, Northern Ireland daki C.A.R. Hoare tarafından yayınlanmış.
* Communications of the ACM, October 1974, Volume 17, Number 10

# Keywords

* Monitors
* Operating Systems
* Scheduling
* Mutual Exclusion
* Synchronization
* System Implementation Languages
* Structured Multiprogramming

# Hangi konu ile alakalı?

Monitor kavramının ne olduğunu nasıl çalıştığını açıklamış ve örnekler sunmuş.

# Amacı nedir?

* Brinch-Hansen'in ortaya attığı monitor kavramını geliştirmek için yapılan çalışmaları yayınlamış.
* Amacı **resource utilization**. Yani bir çok program tarafından kullanılan ortak kaynakların olabildiğince verimli ve güvenli bir şekilde kullanılmasını sağlayabilmek.

# Kapsam ve çalışma nerelere dokunmuş?

Bir çok durumda, beklemenin birden fazla nedeni olabileceğini görmüşler. Bu nedenle yeni bir tip olarak **condition variable** kavramını literatüre kazandırmışlardır.
Birden çok yerde bekleme varsa 2-3 tane condition variable tanımlayarak bunların kullanılmasıyla daha anlaşılır bir çözüme gidilmiştir.

Mesela producer tarafında;

```
condition_variable bufferFull;
bufferFull.wait;

condition_variable consoleWrite;
consoleWrite.wait;
```

Monitor içerisinde **busy** diye bir değişken var. Bu true ise, resource çağrımını yapan beklemek durumunda kalmaktadır.

# Deneysel çalışmalarda ne elde edilmiş?

* Aynı anda sadece 1 tane programın bir kaynağa erişmesi ve onu kullanması hedeflenmiştir. Diğer çağrım yapan ve resource u kullanmaya çalışan program beklemede kalacaktır.
* Semaphore lar monitor ile implemente ediliyormuş. Monitörleri semaphore larla implemente etmeyi denemişler. Semaphore ların özel hali mutex (mutual exclusion) ile çözmüşler.

# Neyi, ne kadar çözmüş?

* Birden fazla program waiting conditionda ise, signal işlemi **en uzun bekleyen programı** çalıştıracak şekilde düzenlenmiştir. Bu da basit bir **fifo** yapısında her programın çalışma imkanı yakalayabilmesini sağlamıştır.
* Buna priority de ekleyerek beklemedeki process lerin önceliklendirilmesi ile ilgili de çalışmalar yapmış.
* Ayrıca ek olarak priority si düşüklerin her zaman arkada kalıp starvation oluşmasını engellemek için yaşlandırma (aging) mekanizması kurulumundan da bahsetmiş.
* Condition variable ların computer science a kazandırılmasıyla monitor lerin kullanılması mümkün olmuştur. Önceden **deadly embrace** dedikleri (ölümcül kucaklama) nın oluşmasına neden oluyormuş. (deadlock)

# Çözmesi gereken şeyler kalmış mı (feature work)?

* Verimlilik için condition variable ları semaphore lar kullanarak implemente etmek yerine direkt donanım desteğiyle implemente edilebileceğini söylemiş.

# Conclusion

Teoride birbirinden farklı türde olan kaynakların bağımsız bir şekilde çizelgelenmesi dead lock a neden olabilir diye belirtilmiş.