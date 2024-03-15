# Makale 1

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# A Hardware Architecture for Implementing Protection Rings

* **Communications of the ACM** dergisinin **March 1972** Volume 15, Number 3 ünde yayınlanmış.

İlk başlarda software access control ile çözmeye çalışıyorlar. Fakat olmuyor. Sonrasında hardware access control yöntemleriyle devam ediyorlar.

1972 de ortaya atılmış. Intel in feyz aldığı access control mekanizmalarının temeli bir makaledir.  
MIT ve Honeywell labs tarafından geliştirilmiştir.

# Abbreviations

SDW: Segment Descriptor Words  
DBR: Descriptor Base Register  
IPR: Instruction Pointer Register  
TPR: Temporary Pointer Register  
IND: Indirect words  
EAP-type: “Effective Address to Pointer Register”-type  

# Keywords

Protection  
Protection Rings  
Protection Hardware  
Access Control  
Hardware Access Control  
Computer Utility  
Time-sharing  
Shared Information  
Segmentation  
Virtual Memory  
Multics  


# Hangi konu ile alakalı?

* Honeywell 645 işlemcisi üzerinde multics kullanılarak yapılan çalışmalar ile ilgili bilgileri içeriyor.
* Time-Sharing ve multiple users in one computer ile alakalı.  
* Aynı bilgisayarı kullanan kullanıcıların kolay bir şekilde bir birleriyle haberleşmesi, birlikte çalışması ve birbirlerinin yaptıkları işlerin üzerine ekleyerek geliştirmeler yapabilmesi amaçlanmıştır.

# Amacı nedir?

* Amacı ana düşüncesi: Her process her yere erişemesin.
* Amaç MIT laboratuvarlarında çalışan mühendislerin birbirlerinin işlerinin bitmesini beklemeden bir arada aynı bilgisayar üzerinde birbirlerini etkilemeden çalışmalarını sağlamak.
* Aynı bilgisayar üzerinde çalışan 2 farklı user programın birbirini etkilemeden gerekirse birbiri ile ilişkili bir şekilde çalışabilmesini sağlamak.
* Depolanan bilgilere erişimin kontrolünü donanım implementasyonu ile yöneten yaklaşımı açıklamak.

# Kapsam ve çalışma nerelere dokunmuş?

* Multics, Honeywell 645 bilgisayar sistemlerinde implemente edilmiş.
* 645 yazılımı protection ring leri implemente etmeye zorlayarak temel bir segmente edilmiş sanal bellek (virtual memory) yapısı oluşturmuş.
* Honeywell 6000 serisi ise protection ring lerin neredeyse tamammını donanımsal olarak implemente etmiş.

**Bir bilgisayar programı için 4 kriter**;
* Functional capability
* Economy
* Simplicity
* Programming Generality

## Controlling Access in a Segmented Virtual Memory

* Kullanıcılar sisteme giriş yaptığında, kullanıcı için özel olarak sanal bellek oluşturulur. Kullanıcılar yapıtıkları işlemleri bu bellekler üzerinde yaparlar.
* A kullanıcısı kendi sahip oldu sanal bellekteki bir alana B kullanıcısının erişmesini isteyebilir. Bunu özel olarak hazırladığı programlar vasıtasıyla gerçekleştirir.

# Deneysel çalışmalarda ne elde edilmiş?
Bir process ile ilişkili olabilecek domain sayısını kısıtlamışlar. Bunu problemin zorluğunu azaltmak ve 4 kritere uyabilmek için trade-off yapmışlar. Sonuç olarak protection ring ler çıkmış.

# Neyi, ne kadar çözmüş?

**3 temel problemi çözer;**
* Başkaları için korumalı
* Diğerlerinden izole edilmiş bir şekilde
* Kendi programını debug ederken kullanıcıyı kendisinden koruyor.

Bir process sadece kendi virtual memory sindeki braket larda bulunanlara read, write ve execute hakkına sahiptir.

Yeni yazılmış ve test edilmemiş programların farklı user ların segmentlerine ve datalarına erişmelerini engellemek için Ring 5 ve üzerinde (Ring 6, Ring 7) çalıştırılır. Böylelikle yanlışlıkla dataların corrupt olması önlenir.

# Çözmesi gereken şeyler kalmış mı (feature work)?

* **Makaleden Alıntı**: Processor mechanisms to provide dynamic, stacked return gates are not obvious at this time.
* **Makaleden Alıntı**: Two subtle features may be included at this point by using a more sophisticated stack segment selection rule.
* **Makaleden Alıntı**: The complete description of a software access control facility based on rings that allows them to be used in the manner just outlined would require another paper.

# Conclusion

**Makaleden Alıntı**;  
The hardware mechanisms derived and described in this paper implement a methodical generalization of the traditional supervisor user protection scheme that is compatible with a shared virtual memory based on segmentation. This generalization solves three significant kinds of problems of a general purpose system to be
used as a computer utility:
* users can create arbitrary, but protected, subsystems
for use by others;
* the supervisor can be implemented in layers which
are enforced;
* the user can protect himself while debugging his own
(or borrowed) programs.
