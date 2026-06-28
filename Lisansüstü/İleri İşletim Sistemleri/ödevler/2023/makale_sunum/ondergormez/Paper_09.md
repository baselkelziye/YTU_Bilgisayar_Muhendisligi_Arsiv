# Makale 9

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# First-Class User-Level Threads


* Brian D. Marsh, Michael L. Scott, Thomas J. LeBlanc ve Evangelos P. Markatos tarafından yayınlamıştır.

* Adres: Computer Science Department, University of Rochester, Rochester, NY, 14627-0226

* Dergi: 1991 ACM 0-89791-447-3/91/0009/0110... $1.50

# Keywords

Spinlock: In software engineering, a spinlock is a lock that causes a thread trying to acquire it to simply wait in a loop while repeatedly checking whether the lock is available. Since the thread remains active but is not performing a useful task, the use of such a lock is a kind of busy waiting. Source: [Wikipedia](https://en.wikipedia.org/wiki/Spinlock)

# Hangi konu ile alakalı?

User level thread lerin oluşturulması ve kullanılmasına standart yöntemler getirmeye çalışmış.

# Amacı nedir?

* Birbirine benzer olmayan (dissimilar) thread kütüphanelerinin haberleşmesi ve veri paylaşımı o günlerde zorlayıcı problemler arasındaymış. Bunu çözmeyi amaçlamış.

* Verimlilik, şeffaflık ve port edilme kolaylığı açısından işlemci sayısından bağımsız olarak birden fazla process ten oluşan paralel programların yazılması tercih edilmektedir.

* Kernel process i oluşturulması ve senkronizasyonu maliyetlidir. Bu nedenle **bir çok runtime sistem leightweight process olarak adlandırılan user space threadlerini implemente etmeye** başlamış.

# Kapsam ve çalışma nerelere dokunmuş?

User level thread leri temsil etmek için kernel seviyesi proseslerin kullanılması düşünülmüş fakat;
* Semantic inflexibility: 
* Poor performance: kernel space e girip çıkmanın oluşturduğu kayıp
sorunları ortaya çıkmıştır.

nedeniyle vazgeçilmiştir.

# Deneysel çalışmalarda ne elde edilmiş?

* Multi-model programlama için yaptıkları çalışmalarda kernel-implemented thread lerin paralel programlama için gerekli olan yapıyı desteklemediğini gözlemlemişler.

* User level thread lerinde critical section da preempt edildiğinde veya bloklandığında performans kayıpları olduğunu gözlemlemişlerdir.

# Neyi, ne kadar çözmüş?

Taskların doğru zamanda ve doğru sayıda oluşturulması için, merkezi olmayan bir task generation mekanizması kurmuşlar. Bununla birlikte başlamış olan tasklar bitmeden yeni taskların oluşturulmasını engelleyen two-minute warning yapısına geçmişler. Böylelikle sistemin overload olmasını engellemişler.

# Conclusion

* Kernel ve thread paketinin haberleşmesi için uygun olan durumlarda shared memory nin kullanılmasını ve böylelikle senkron işlemlerin azaltılmasını sağlamışlardır.
* Çizelgeleme ihtiyacı oluştuğunu anlamak için kernel yazılımsal kesme bulunan thread kütüphanesi sağlar.