# Makale 6

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# Process Migration in DEMOS/MP

* Michael L. Powell ve Barton P. Miller tarafından yayınlanmıştır.
* Computer Science Division, Department of Electrical Engineering and Computer Sciences, University of California, Berkeley, CA 94720
* Yayın Bilgileri: ©1983 ACM 0-89791-115-6/83/010/0110 $00.75

# Hangi konu ile alakalı?

* Proseslerin çalışırken bir işlemciden başka bir işlemciye taşınabilmesini sağlayan mekanizmaların kurulması ile alakalıdır.

# Amacı nedir?

* Proses lerin taşınması işinin proses in bilgisi dahilinde kasıtlı ve isteyerek yapılmayan bir işlem olması gerektiğinden bahsetmiş.
  * İdealde bu sürecin hesaplamalarda ve haberleşmede herhangi bir görünür değişiklik yapması beklenmez.

# Kapsam ve çalışma nerelere dokunmuş?

* **DEMOS/MP** işletim sistemi üzerinde yapılan çalışmalara değinmektedir.
  * Message-base işletim sistemi
  * Inter-processor messages
  * Message paths
  * Called links
* Tek işlemci üzerinde çalışan proses ler ile aynı arayüzü kullanacak şekilde lokasyonundan bağımsız bir yapı kurgulamaya çalışmış.

# Deneysel çalışmalarda ne elde edilmiş?

* Dağıtık sistemlerde toplam performansı arttırmak için, yükü olabildiğince eşit dağıtmak ve sistemde paralelleştirmeyi sağlamak gerekir.
* Bir işlemciden başka bir işlemciye taşıma relocation a neden olsa da sistem performansını arttırmak için güzel bir fırsat ortaya çıkmış olur.
* Bir proses in durumu bir sürü tabloda tutulan dağıtık veriler bütününden oluşur. Bu durum taşıma işini zorlaştıran bir faktördür.

#  Neyi, ne kadar çözmüş?

* Proses lerin taşınması için merkezi bir algoritma ihtiyacı yoktur.
* Proses lerin taşınabiliyor olması, prosesin sorunsuzca başka bir processor e taşınması ve durumunun kaydedilerek yeni processor üzerinde yeniden başlatılabilmesini sağlar.
* Proseslerin durumlarının belleğe kaydediliyor olması, bozulan bir processor üzerinde çalışıyor olan bir uygulamanın başka bir processor üzerine sorunsuzca taşınarak çalışmaya devam edebiliyor olmasını sağlar.
* DEMOS/MP'de Link lerdeki adresler context ten bağımsızdır. Böylelikle linkler farklı processor lere geçilsede aynı process i temsil etmeye devam eder.
* Process in kendi kendini taşıma isteği oluşturması da mümkündür.

Prosesi taşımak için;
* Process in çalıştırılması durdurulur (marked in migration). 
* Hedef processor de yeni process state i allocate edilir.
* Resident state ve swappable state taşınır
* Code segment i taşınır.
* Yeni gelen (pending) mesajlar yeni processor e yönlendirilir (forwarding).
* Eski processor den state ler silinir (cleanup states) ve forwarding address eklenir.
* Yeni processor üzerinde process restart edilerek başlatılır.

# Çözmesi gereken şeyler kalmış mı (feature work)?

* Verimli ve efektif bir taşımaya karar verme kuralı hala aktif bir araştırma konusu olarak kalmıştır.
* Process taşındıktan sonra eski lokasyona işaret eden linklere gönderilen mesajlar problem oluşturmaktadır.
* Process load balancing algoritmaları ile ilgili çalışmaları devam ediyormuş.

# Conclusion

* Source ve Destination kernel leri migrate işini gerçekleştirmek için birbirleriyle haberleşebiliyor olmalıdırlar.
* Eski process link lerinin kaldırılması için 2 seçenek vardır.
  * Process öldüğünde (en kolayı).
  * Process in eski lokasyonunu gösteren tüm linkler güncellendiğinde (reference count gerektirir).
* DEMOS/MP üzerinde 1 adam/ay dan kısa bir sürede implemente edilip test edilebilecğini öne sürmüştür.
* Linklerin context ten bağımsız ve transparan olması sayesinde proseslerin taşınabilmesi ve bu process ile haberleşen diğer process lerin izole edilmesi mümkün kılınmıştır.