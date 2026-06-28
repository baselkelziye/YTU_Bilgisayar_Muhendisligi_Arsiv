# Makale 2

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# Practical, transparent operating system support for superpages

* Rice University deki Juan Navarro ve arkadaşları yazmıştır.
* Proc. of the 5th Usenix Symposium on Operating Systems Design and Implementation, Boston, MA, December 2002 de yayınlanmış

## Abbreviations

PTE: Page Table Entry

# Hangi konu ile alakalı?

* Yaygın kullanılan yüksek boyutlu hafıza sayfalarına sahip olan işlemcilerle çalışacak bir işletim sistemi incelemesi yapılmaktadır.  
* Yüksek boyutlu hafızaya superpages da denilmektedir.

# Amacı nedir?

* Daha genel ve açık bir şekilde superpage i yönetecek bir sistem tasarlamayı amaçlamışlardır.

* TLB boyutları küçük olduğu için yüksek miktarda memory kullanan uygulamalar çalışırken **TLB miss** miktarı çok artmaktadır. Bu durum %30 a kadar performans kaybına neden olmaktadır.  
* Bunun üstesinden gelmek için superpage denilen daha büyük boyutlu sayfalar oluşturularak performansın arttırılması denenmiştir. Sayfa boyutu arttırıldığı zaman TLB de temsil edilen memory adresi daha büyük bir alanı temsil ediyor. Böylelikle daha büyük memory alanları cover edilmiş oluyor.

#  Kapsam ve çalışma nerelere dokunmuş?

* FreeBSD on the Alpha CPU üzerinde yaptıkları çalışmaları gerçek yük üzerinde deneme ve karşılaştırma fırsatı bulmuşlar.
* Az memory ayırarak ihtiyaç oldukça memory ayırmak yerine, superpage in olabileceği maksimum alan kadar bellek ayırarak ihtiyaç oldukça bu alanları uygulamaya map lemek reallocation ihtiyacını azaltmaktadır.

#  Deneysel çalışmalarda ne elde edilmiş?

* Superpage boyutları çok çok arttırılırsa bu durumda da kullanılmadığı halde programlar hafızada daha fazla yer kaplamaya ve daha çok memory ihtiyacı duymaya başlayacaktır.
* Birden fazla page size ı yönetmek daha zor olacağı için birçok işletim sistemi hiç superpage i desteklememeyi veya çok az desteklemeyi seçmişlerdir.
* Page size lar processor üreticisine bağımlı olduğu için farklı processor ler için farklı boyutlar seçilmeli. Bu da işletim sistemi tasarımında dikkate alınması gereken karmaşıklaştırıcı bir faktör olmuştur.

#  Neyi, ne kadar çözmüş?

* Superpage fiziksel ve sanal adres belleği aralığında devam eden aralıksız alanlar olarak tanımlanmalı.
* Policy tanımlayarak bellek yetmediğini tespit ettikleri (page fault handler) programlar için daha çok bellek ayırmaya, yetenler için ise fit edeceği daha küçük belleklere geçmeye yarayan bir mekanizma tasaralamaya çalışmışlardır.
* Population map denen bir radix tree ile sorunu çözmeye çalışmışlar.

Population map aşağıdaki gibi kullanılır;
* Reserved frame lookup
* Overlap avoidance
* Promotion decisions
* Preemption assistance

# Çözmesi gereken şeyler kalmış mı (feature work)?

* Kirli (dirty) bit i setlenmiş superpage diske yazılması gerekiyorsa, sadece setlenen bitin değil tüm superpage in diske yazılması gerekiyor. Bir kısmı hiç dokunulmamış olsa da. Bu durum performans sorunlarına yol açabilir.
* Bir çözüm hash ini almak SHA-1 160 bit ve bunun çakışması olasılığı (2^80) donanımın arıza yapmasından daha düşük bir ithimal. Buna benzer bir çözüm ile %60 a kadar performans artışı olabileceğini öngörmüşler.

# Conclusion

* Superpage ler aslında boyutu arttırlmış fiziksel page lerdir. Böylelikle tasarlanan sistemlerin TLB coverage ları artmaktadır.
* TLB miss ler azalmaktadır. Böylelikle uygulama performanslarının artması beklenmektedir.
* %30 ile %60 arası performans artışı olabileceği gözlemlenmiştir.
