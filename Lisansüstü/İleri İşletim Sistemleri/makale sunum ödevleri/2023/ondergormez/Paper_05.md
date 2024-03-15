# Makale 5

Ad Soyad: Önder Görmez  
Öğrenci No: 21501035

# Experience with Processes and Monitors in Mesa

* Xerox Palo Alto Research Center dan Butler W. Lampson ve Xerox Business Systems den David D. Redell ortaklaşa bu makaleyi yayınlamışlar.
* Communications of the ACM 23, 2 (Feb. 1980), pp 105-117 yayınlanma bilgileri.

# Keywords

* Concurrency
* Condition Variable
* Deadlock
* Module
* Monitor
* Operating System
* Process
* Syncronization
* Task

# Hangi konu ile alakalı?

* Eş güdümlülükte ortaya çıkan sorunların çözümü için kullanılan monitörlerin kullanımı ve kontrol edilmesiyle alakalı konuları işlemektedir.
* Pilot diye bir uygulama geliştirmişler (24 Bin satır kod)

# Amacı nedir?

Makelede ortaya attıkları çözümlerin aşağıdaki amaçlarla kullanılmasını hedeflemişler;
* **Local concurrent programming**: Birden çok process birbirleri ile haberleşerek bir programı sorunsuzça oluşturabileceklerdir.
* **Global resource sharing**: Birbirinden bağımsız programlar aynı kaynakları birbirlerini etkilemeden kullanabileceklerdir.
* **Replacing interrupts**: Interrupt lar üzerinden dallanma yapmak yerine ilgili process in diret uyandırılarak çalıştırılmasını sağlayacak şekilde düzenlemeler yapılması.

# Kapsam ve çalışma nerelere dokunmuş?

Dijkstra, Hoare ve Brinch Hansen monitor ü icat etmişler. Fakat yaptığı çalışmalarda çözülmemiş problemler kalmış. Bunları çözmek için çalışmalar yapmışlar. Özet listesi;
* Programlama yapısı (Program Structure)
* Proses lerin Oluşturulması (Process Creation)
* Monitörlerin Oluşturulması (Creating Monitors)
* İç içe Monitör Çağrıları (WAIT in a nested monitor call)
* İstisna Durumları (Excpetions)
* Çizelgeleme (Scheduling)
* Giriş - Çıkış (Input - Output)

# Neyi, ne kadar çözmüş?

Mesa da aşağıdaki problemleri çözmeye odaklanmış ve çözmüş;
* İç içe monitör çağrıları
* WAIT çağrılarının anlamının tanımlanması ve netleştirilmesi
* Öncelikli çizelgeleme (priority scheduling)
* Zaman aşımlarının işlenmesi
* İptal (abort) ve diğer istisna durumların işlenmesi
* Process oluşturulması ve öldürülmesi ile monitörlerin ilişkilendirilmesi
* Çok sayıda küçük objenin monitör edilmesi
