# Makale 7

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# Task Communication in DEMOS

* Forest Baskett, John H. Howard ve John T. Montague tarafından yayınlanmış.
* Adres: Los Alamos Scientific Laboratory Los Alamos, New Mexico 87545
* Yayınlanma Yeri: Proceedings of Sixth ACM Symposium on Operatlng Systems Principles (November 1977) 23-31.

# Hangi konu ile alakalı?

* Link tabanlı mesaj ve data paylaşım sistemleri semaphore ve monitor lere güzel bir alternif olarak öne sürülmüş.

# Amacı nedir?

Yardımcı ve birbiriyle ilişkisiz task ların haberleşmesi için bir mekanizma ortaya atmış.

İşletim sistemlerinin 2 şekilde haberleştiğini öne sürmüş
* Shared Variables (Semaphore Dijkstra, Monitor Hoare)
* Message System (Brinch Hansen)

DEMOS dakinin message system e daha yakın olduğunu söylüyor.

# Kapsam ve çalışma nerelere dokunmuş?

* Linkler üzerinden bir task tan başka bir task a mesaj gönderilebilir.
* Message system inde haberleşme orjinalde half duplex iken linklerde 2 yönlü olabiliyor.

# Deneysel çalışmalarda ne elde edilmiş?

* Task kendi sahip olduğu linklerden herhangi biri ile mesaj gönderebilir.
* Bazı durumlarda da veriyi diğer taskların memory lerinden okuyabilir veya memory lerine yazabilir.

# Neyi, ne kadar çözmüş?

4 tane link tipi mevcut:
* Request
* Resource
* Reply
* General

Reply link leri reply message ları için sadece 1 kez kullanılabilen linklerdir. Kullanımı sonrasında destroy edilirler.

3 tane mesaj tipi mevcut;
* Request
* Replies
* General

Messages;
* Linkler üzerinden gönderilen küçük bilgi paketleridir.
* Kernel tarafından buffer lanabilirler

Channels;
* Taskların gelen mesajları sınıflandırabilmesini sağlayan yapılardır.

Link Usage;
* CALL (Most used)
* REQUEST
* REPLY
* SEND
* MOVE
* RECEIVE

# Çözmesi gereken şeyler kalmış mı (feature work)?

* Circular wait condition ı tespit edip, deadlock kontrolü yapacak hibrit bir yöntem geliştirmeyi planlıyorlarmış.

# Conclusion

Task manager, task ların subtask lar oluşturabilmesi için aracı olup bellek ayıran bir programdır. Yeni oluşturulan subtask ana taska reply link aracılığıyla gönderilir.
