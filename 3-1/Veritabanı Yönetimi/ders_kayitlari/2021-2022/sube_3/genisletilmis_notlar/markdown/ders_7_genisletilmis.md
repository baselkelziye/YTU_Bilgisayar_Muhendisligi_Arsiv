# Ders 7 Genişletilmiş Notu: ER ve EER Tasarım Örnekleri ve ER'dan İlişkisel Modele Dönüşüm

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Gereksinim Raporundan Varlık ve Bağıntılara: COMPANY Veritabanı
- 2. İlk Tasarım ve İyileştirmeler
- 3. COMPANY UML ve ER Diyagramları
- 4. Şehir, Ülke ve Nehir Örneği
- 5. Bölüm ve Personel Örneği
- 6. Satış Formu Örneği ve Türetilmiş Nitelikler
- 7. Takım, Oyuncu ve Oyun Örneği
- 8. Banka Hesabı İşlemleri Örneği
- 9. Uçak Rezervasyon Sistemi
- 10. Genelleme Örneği (EER)
- 11. ER'dan İlişkisel Modele Dönüşüm
- 12. EER'dan İlişkisel Modele Dönüşüm
- 13. Gemi Takip Örneği
- Örnek Sorular
- Dersin Toparlaması

Ders Zoom üzerinden yapıldı ve önceki derste kullanılan "07-ER-UML" sunumuyla devam edildi (ekrandan, 02:35:00). Önceki derste ER, EER ve UML kavramları tanımlanmıştı; bu derste bunlar örneklerle pekiştirildi, ardından kavramsal tasarımın ilişkisel model tablolarına nasıl dönüştürüleceği işlendi. Ara verilen kısım (yaklaşık 01:14 ile 01:37 arası) notta yer almıyor.

## 1. Gereksinim Raporundan Varlık ve Bağıntılara: COMPANY Veritabanı

Hoca, orta ya da küçük ölçekli bir veritabanı için izlenecek adımları önceki derste gösterilen süreç şeması üzerinden hatırlattı ve doğrudan COMPANY veritabanının gereksinim listesine geçti. Slayttaki metin (ekrandan, 00:10:00):

```text
Örnek 1: COMPANY Database
We need to define a database schema design based on the following
(simplified) requirements of the COMPANY Database:
- The company is organized into DEPARTMENTs. Each department has a name,
  number and an employee who manages the department. We keep track of the
  start date of the department manager. A department may have several locations.
- Each department controls a number of PROJECTs. Each project has a unique
  name, unique number and is located at a single location.
- We store each EMPLOYEE's social security number, address, salary, and birthdate.
  - Each employee works for one department but may work on several projects.
  - We keep track of the number of hours per week that an employee currently
    works on each project.
  - We also keep track of the direct supervisor of each employee.
- Each employee may have a number of DEPENDENTs.
  - For each dependent, we keep track of their name, sex, birthdate, and
    relationship to the employee.
```

### 1.1 Özneler varlıklara, fiiller bağıntılara

Gereksinim raporunda cümlelerin özneleri genellikle varlık kümelerine işaret eder. Hoca bunun ezberlenecek bir kural olmadığını, bir "meleke" (deneyimle kazanılan yatkınlık) ya da heuristik olduğunu vurguladı: elimizde iki kere iki dört gibi bir algoritma yok.

İlk cümle bunun neden körü körüne uygulanamayacağını gösteriyor. "The company is organized into DEPARTMENTs" cümlesinin öznesi company'dir. Ama burada şirketlerin listelenmesi söz konusu değil: tek bir şirketin departmanları, projeleri, çalışanları ve onların ilişkileri takip ediliyor. Bir küme olmadığı için COMPANY diye bir varlık kümesi açmaya gerek yoktur. Hoca bunun en çok yapılan hatalardan biri olduğunu söyledi.

Hemen ardından departmanların adı, numarası, yöneticisi ve konumlarından bahsediliyor. Hocanın deyişiyle departman burada "ben varlık seti olmalıyım, çünkü benimle ilgili kayıtlar tutuluyor" diye bas bas bağırıyor. Aynı şekilde projelerin adı ve numarası, çalışanların SSN, adres, maaş ve doğum tarihi, çalışanların yakınlarının adı, cinsiyeti, doğum tarihi ve çalışanla yakınlığı tutuluyor. Böylece DEPARTMENT, PROJECT, EMPLOYEE ve DEPENDENT varlık kümeleri ortaya çıkar.

Kalın yazılmış fiiller ise bağıntılara işaret eder. Bir cümlede iki varlık kümesi varsa aralarında bir bağıntı sezilir:

- "department controls a number of projects": departman ile proje arasında kontrol bağıntısı.
- "employee works for one department but may work on several projects": works for ve works on bağıntıları.
- "number of hours per week that an employee currently works on each project": works on bağıntısının bir niteliği (çalışanın o projede haftada kaç saat çalıştığı).
- "direct supervisor of each employee": iki tarafı da EMPLOYEE olan bir yönetme (supervise) bağıntısı.
- "employee may have a number of dependents": EMPLOYEE ile DEPENDENT arasında bir bağıntı.

## 2. İlk Tasarım ve İyileştirmeler

### 2.1 İlk tasarım

İlk tasarım UML sınıflarıyla yapıldı (ders boyunca ağırlıklı olarak ER kullanılacak, UML ikinci planda). Her varlık kümesi için bir sınıf açıldı ve gereksinim raporunda geçen nitelikler yazıldı. Bu aşamada bağıntılar da henüz nitelik olarak duruyor (ekrandan, 00:25:00):

| DEPARTMENT | PROJECT | EMPLOYEE | DEPENDENT |
|---|---|---|---|
| number **BA** | number **BA** | Ssn **BA** | name |
| name | name | fName | dependsToEmp |
| manager | location | lName | birthDate |
| managerStartDate | controllingDept | department | relationships |
| locations | | birthDate | |
| | | salary | |
| | | worksOnProjects | |
| | | supervisor | |
| | | adress | |

(BA: belirleyici/aday anahtar.) Örneğin departmanın manager niteliği "employee who manages the department", managerStartDate "start date of the department manager", locations ise "a department may have several locations" ifadesinden geliyor.

### 2.2 İyileştirme kuralları

Slayttaki "İlk tasarım sonrası iyileştirmeler-1" (ekrandan, 00:20:00):

- Eğer mevcut nitelik başka bir varlığa işaret ediyorsa: Nitelik → Bağıntı haline dönüşmeli.
- Eğer mevcut nitelik çok değer alabiliyorsa: Nitelik → Varlık kümesi haline dönüşmeli.
- Eğer mevcut varlık kümesi sadece 1 niteliğe sahip ve bir bağıntısı varsa: Varlık kümesi → nitelik haline dönüşmeli.
- Varlık kümeleri arasında "genelleme" mümkünse yapılmalı. Yukarıdan aşağıya (top-down), aşağıdan yukarıya (bottom-up) yaklaşımlar kullanılmalı.
- Bağıntıların dereceleri tekrar değerlendirilmeli, gerekirse "kümeleme" ile daha açık yapılanmalar kullanılmalı.

Hoca sürecin geri beslemeli olduğunu, belli bir metodu uygulamaya çalıştığımız için bu maddelerle işi çerçevelediğimizi söyledi. Bir diğer iyileştirme noktası gereksiz bilginin ve tekrarların (redundancy) çıkarılmasıdır.

### 2.3 COMPANY'ye uygulanması

Nitelikler tek tek incelendi:

- DEPARTMENT.manager bir çalışana işaret eder, bu yüzden DEPARTMENT ile EMPLOYEE arasında bir yönetme bağıntısına dönüşür. managerStartDate bu bağıntının niteliği olur.
- DEPARTMENT.locations çok değerli bir niteliktir; bunun için ayrı bir varlık kümesi (LOCATION) ve departmanla arasında "locates in" bağıntısı tanımlanır. Hoca bunun asıl gerekçesinin normalizasyon olduğunu belirtti: çok değerli nitelikler ayrı bir tabloda saklanmazsa doğruluk zarar görebilir.
- PROJECT'in number, name ve location nitelikleri kendi nitelikleridir (projenin tek konumu vardır, departman gibi değildir). controllingDept ise departmana işaret eder: proje ile departman arasında bir bağıntı vardır. Hoca, dönemin başında ilişkisel modelde ezber gibi gördüğümüz yabancı anahtarın çıkış noktasının burası olduğunu söyledi.
- EMPLOYEE.department çalışanla departman arasında, worksOnProjects çalışanla proje arasında, supervisor ise EMPLOYEE ile yine EMPLOYEE arasında bağıntıdır. birthDate, salary ve adres kendi nitelikleridir.
- DEPENDENT.dependsToEmp yakının bağlı olduğu çalışanı gösterir, yani bağıntıdır. relationships ise yakınlık derecesidir (eşi, oğlu, kızı gibi); bunun için ayrı bir liste ya da varlık kümesi oluşturmaya gerek yoktur.

Bu dönüşümlerden sonra şu genel ilke görülür: aynı varlık kümeleri arasında birden çok bağıntı olabilir ("In general, more than one relationship type can exist between the same participating entity types"). EMPLOYEE ile DEPARTMENT arasında MANAGES ve WORKS_FOR farklı rollerde iki ayrı bağıntıdır; iki varlık kümesi arasındaki bağıntı sayısında bir kısıt yoktur.

> **Hocanın vurgusu:** Bu işler biraz el yordamıyla yapılır; her şeyin kuralının belli olmasını isteriz ama öyle değil. Küçük ölçekli dünyalarda yapılacak bir hata çok büyük sorunlar çıkarmaz.

## 3. COMPANY UML ve ER Diyagramları

### 3.1 UML diyagramı

Slayttaki "COMPANY DB UML DIAGRAMI" (ekrandan, 00:30:00) dört sınıfı ve LOCATION sınıfını gösteriyor. Üzeri çizilen nitelikler bağıntıya dönüşenlerdir:

```text
EMPLOYEE (Ssn BA, fName, lName, department, birthDate, salary,
          -worksOnProjects-, -supervisor-, adress)
DEPARTMENT (number BA, name, -manager-, -managerStartDate-, -locations-)
PROJECT (number BA, name, location, -controllingDept-)
DEPENDENT (name AN, -dependsToEmp-, birthDate, relationships)
LOCATION (city BA)

EMPLOYEE 1..*  ==> works for  1..1 DEPARTMENT
EMPLOYEE       ==> manages        DEPARTMENT
EMPLOYEE       ==> works on       PROJECT
EMPLOYEE       ==> supervises     EMPLOYEE   (recursive)
EMPLOYEE       ==> has            DEPENDENT
DEPARTMENT     ==> controls       PROJECT
DEPARTMENT     ==> locates in     LOCATION
```

Hoca, EMPLOYEE'deki department niteliğinin de works for bağıntısına dönüştüğü için üzerinin çizilmesi gerektiğini, slaytta bunun eksik kaldığını belirtti.

Sonraki adım, bağıntıların eleman sayılarını belirlemek ve onlara uygun adlar vermektir:

- WORKS_FOR: bir departmanda çok çalışan vardır, bir çalışan bir departmandadır. Her çalışan mutlaka bir departmanda, her departmanda en az bir çalışan bulunur; iki taraf da zorunlu katılımlıdır (ER'da çift çizgi).
- MANAGES: bir departmanın bir yöneticisi vardır, bir çalışan en fazla bir departman yönetir; 1:1 bağıntıdır. Departmanın mutlaka yöneticisi olması gerektiğinden departman tarafı zorunlu, çalışan tarafı isteğe bağlıdır. Yönetmeye başlama tarihi bağıntının niteliğidir.
- WORKS_ON: bir çalışan birden çok projede, bir projede birden çok çalışan çalışabilir; M:N'dir, iki taraf da zorunlu katılımlıdır ve çalışılan saat bağıntının niteliğidir.

### 3.2 ER diyagramı

Slayttaki "COMPANY DB ER DIAGRAM" (ekrandan, 00:35:00) şunları içerir:

```text
EMPLOYEE: Ssn (anahtar), Name (Fname, Minit, Lname), Bdate, Address, Salary, Gender
DEPARTMENT: Name, Number (anahtar), Locations (çok değerli),
            Number_of_employees (türetilmiş, kesikli elips)
PROJECT: Name, Number (anahtar), Location
DEPENDENT (zayıf): Name (kısmi anahtar), Gender, Birth_date, Relationship

EMPLOYEE  N --WORKS_FOR--  1 DEPARTMENT     (iki taraf da çift çizgi)
EMPLOYEE  1 --MANAGES----  1 DEPARTMENT     (Start_date; departman tarafı çift çizgi)
DEPARTMENT 1 --CONTROLS--  N PROJECT        (proje tarafı çift çizgi)
EMPLOYEE  M --WORKS_ON---  N PROJECT        (Hours)
EMPLOYEE  1 (Supervisor) --SUPERVISION-- N (Supervisee) EMPLOYEE
EMPLOYEE  1 ==DEPENDENTS_OF== N DEPENDENT   (tanımlayıcı bağıntı)
```

Hoca diyagramın adım adım çizilmesinin şart olmadığını söyledi. Önce nitelik, sonra varlık, sonra bağıntı diye düşünmek bir yardımdır; deneyim kazandıkça öznelerden varlıkları, yüklemlerden bağıntıları çıkararak doğrudan ER çizilebilir.

> **Hocanın vurgusu:** Gereksinim raporunu iyice anlayın, sonra boş bir kağıda ER diyagramını çizin ve slayttakiyle karşılaştırın. Sonraki örnekler de bu büyüklükte olacak.

### 3.3 Zayıf varlık: DEPENDENT

Gereksinim raporunda istenen nitelikleri tutmamız gerekir. Yakınlar için ad, cinsiyet, doğum tarihi ve yakınlık istenmiş; SSN gibi onları bütün veritabanında tek kılacak bir nitelik istenmemiş. Hoca bunu kendiliğinden eklememek gerektiğini söyledi. Böyle bir nitelik bulunmadığı için DEPENDENT zayıf varlık kümesi olur. Ayırt edici nitelik olarak Name seçildi: aynı adlı biri farklı çalışanların ailesinde olabilir, ama bir çalışanın iki yakını aynı adı taşımaz.

Bu kavramsal tasarım bittikten sonra yapılacak iş, belirli dönüşümlerle ilişkisel model tablolarını oluşturmak ve onlara veri yüklemektir (11. bölüm).

## 4. Şehir, Ülke ve Nehir Örneği

Slayt: "Örnek-2 (ER, UML): Şehirler, ülkeler ve nehirleri gösteren bir veritabanı tasarımı." (ekrandan, 00:40:00). Burada ayrıntılı bir gereksinim raporuna gerek yok; küçük dünya kendini zaten anlatıyor: dünyadaki ülkeler, şehirler ve nehirler takip edilecek.

Şehir ile ülke arasındaki bağıntı açıktır: bir ülkede çok şehir, bir şehir bir ülkededir (Şehir N - R - 1 Ülke). Bir ülke en az bir şehirden oluşur, bir şehir de mutlaka bir ülkeye aittir; iki taraf da zorunlu katılımlıdır. Hoca alttaki diyagramda ülke tarafındaki çift çizginin eksik kaldığını belirtti.

Kritik nokta nehrin neyle bağlanacağıdır:

```text
Tasarım 1:  Şehir N ==R== 1 Ülke,   Ülke N --S== M Nehir
Tasarım 2:  Şehir N ==R-- 1 Ülke,   Şehir N --S== M Nehir
            "Nehirlerin hangi şehirlerden geçtiğini tutmak istersek?"
```

İlk tasarımda nehirlerin hangi ülkelerden geçtiği bilinir, ama o ülkede hangi şehirlerden geçtiği tutulamaz. Bu da isteniyorsa nehir şehirle bağlanır. Şehir bir ülkeye ait olduğundan, nehrin geçtiği ülkeler de dolaylı olarak çıkarılabilir; yani ikinci tasarım birincisini kapsar.

Bedeli şudur: varlık kümeleri ve bağıntılar sonunda birer dosyaya (tabloya) karşılık gelir. Şehir-nehir bağıntısının yükü ülke-nehir bağıntısınınkinden fazladır, çünkü şehir sayısı ülke sayısından çok daha büyüktür. Hoca, her ülkede yirmi beş otuz şehir olsa ülke tarafındaki oranın yaklaşık otuz kat küçük olacağını söyledi. Buna karşılık daha ayrıntılı bilgi tutulmuş ve ülke bilgisi de kaybedilmemiş olur. Slaytın sağ tarafında aynı tasarımların UML karşılıkları için boş kutular var; hoca çalışırken ER'ın hemen ardından UML'ini de çizmeyi önerdi.

## 5. Bölüm ve Personel Örneği

Slayt (ekrandan, 00:45:00):

```text
Örnek 3
Bir şirketteki bölümler ve personel bilgilerini tutan Bölüm-Personel veri tabanını düşünelim.
- Her bölüm çok sayıda personele sahiptir ve her personel en fazla bir bölüme bağlıdır.
- Bir bölümün sadece bir yöneticisi (mutlaka) vardır.
Buna göre aşağıdaki durumları birbirinden bağımsız olarak cevaplayınız...
- Bir bölümün yöneticisi ancak o bölüme bağlı bir personel olabiliyor ise, nasıl bir ER modeli çizilebilir?
- Bir bölümün yöneticisi herhangi bir personel olabiliyor ise, nasıl bir ER modeli çizilebilir?
```

Bölüm ve personel varlık kümeleri yine aynı ilkelerle ortaya çıkar; aralarında bağlı olma ve yönetme olayları vardır.

Birinci durumda bölümün yöneticisi o bölümün personelinden biridir. O zaman ayrı bir bağıntıya gerek yoktur: B (1..1) "sahip" (0..*) P bağıntısına "Yöneticimi?" niteliği eklenerek yöneticinin kim olduğu takip edilebilir. Hoca, mümkün olduğunca az malzemeyle tasarım yapmaya çalıştığımızı, böylece sonraki dönüşümde daha az ilişkisel tablo çıkacağını söyledi.

İkinci durumda yönetici herhangi bir personel olabilir. Bu bilgi "sahip" bağıntısının içinde ifade edilemez; ayrı bir yönetme bağıntısı çizilmesi gerekir ve onun eleman sayısı farklı olur (bir bölümün tek yöneticisi). Küçük dünyadaki ifadede yapılan küçük bir değişiklik tasarımı ve ortaya çıkacak tabloları değiştirir. Eleman sayılarının ayrıntısını hoca öğrencilere bıraktı.

## 6. Satış Formu Örneği ve Türetilmiş Nitelikler

Slayttaki satış formu (ekrandan, 00:50:00):

| SatırNo | ParçaNo | Parçaİsim | Tanım | Miktar | Birim Fiyat | Toplam |
|---|---|---|---|---|---|---|
| 1 | 23645 | ayakkabı | Spor, basketbol | 1 | 110 | 110 |
| 2 | 12674 | gomlek | klasik tarz | 2 | 80 | 160 |
| 3 | ... | | ... | | | |

Formun üstünde SatışNO: 12 ve Tarih: 11.06.2009, altında GenelToplam: 880 yazıyor. Soru metni: "Yukarıda satış bilgileri tutan örnek bir satış formu içeriği görülmektedir. Buna karşılık gelen veri tabanı, SATIŞ, PARÇA ve SATIR olmak üzere 3 varlık setinden oluşmaktadır. (Aynı ParçaNolu parçalar farklı satırlarda tekrar edebilir.) Bu varlık setlerini, özeliklerini ve aralarındaki ilişkileri gösteren ER diyagramını çiziniz."

Hoca bunun bir mağaza veritabanı olabileceğini, ileride müşteri ve satış yapan çalışan bilgileri de eklenerek büyüyebileceğini, ama şimdilik yalnız satış formlarının takip edildiğini söyledi.

### 6.1 Varlıklar ve nitelikler

İlk etapta formdaki her bilgi diyagrama taşındı; ne fazladan bilgi eklendi ne de bir bilgi kayboldu:

- SATIŞ: sNO **BA**, tarih, genelToplam.
- PARÇA: pNo **BA**, isim, fiyat, tanım.
- SATIR: satırNo **AN**, satırToplamFiyat (ve miktar).

### 6.2 Türetilmiş nitelikler

İkinci etapta fazla nitelikler arandı. Satır toplam fiyatı, miktar ile birim fiyatın çarpımıdır:

- Satır 1: $1 \times 110 = 110$
- Satır 2: $2 \times 80 = 160$

Genel toplam da satır toplamlarının toplamıdır (formdaki 880, "..." ile gösterilen diğer satırları da içeriyor). Bu iki nitelik türetilmiş niteliktir; slayttaki notta "genelToplam ve satırToplamFiyatı nitelikleri türetilmiş nitelik. Kavramsal tasarımda yazılmasa da olur." yazıyor. Saklanabilirler, ama gerektiğinde SQL içinde çarpma ve toplama ile hesaplanabilirler.

Hoca bunu yaş örneğiyle karşılaştırdı: yaş, saklamak yerine güncel tarihten doğum tarihi çıkarılarak küçük bir fonksiyonla bulunabilir. Yaş her yıl değiştiği için onu saklamak daha kritiktir (güncellenmesi gerekir). Fatura sonradan değişmiyorsa toplamı saklamak yalnız ek depolama yüküdür.

**Soru:** (Bir öğrenci yazılı olarak sordu.) Genel toplam ve satır toplamının türetilmiş nitelik olduğu nasıl anlaşıldı? **Cevap:** Her parçanın fiyatı ve her satırdaki miktar bellidir. Satır toplamı bu ikisinin çarpımı, genel toplam da satır toplamlarının toplamıdır; sorulduğunda hesaplanabilir. Bunları ayrıca saklamak yanlış olmaz ama gereksiz bir yük getirir. Hoca, bu konudaki her şeyin "iki kere iki dört" gibi kesin olmadığını, aşırı yanlış olmadığı sürece farklı tasarımların kabul edilebileceğini, fazladan bir bağıntı ya da nitelik koymanın sistemi çökertmeyeceğini ama ek yük (fonksiyon, performans) getireceğini söyledi.

### 6.3 Bağıntılar ve zayıf varlık

Bağıntılar için iki seçenek düşünüldü: satış ile parça arasında mı, satış ile satır arasında mı bağıntı kurulmalı? Satış ile parça bağlanırsa o satışta hangi parçaların geçtiği bilinir, ama parçanın hangi satırda geçtiği için ayrıca parça-satır bağıntısı kurmak gerekir.

Hoca burada atlanan bir adımı hatırlattı: önce varlıkların nitelikleri incelenip güçlü mü zayıf mı oldukları belirlenmelidir. Önceki derste söylendiği gibi SATIR zayıf varlıktır. Satır numarası her faturada 1, 2, 3, 4 diye gider, yani bütün veritabanında tek değildir, ama bir satış içinde satırlar birbirinden farklıdır; bu yüzden satırNo ayırt edici niteliktir. Satırın güçlüsü satıştır. Parça güçlüsü olamaz: bir parça birden çok satırda geçebilir, oysa bir satır numarası bir satış formunda bir kez geçer.

Sonuç diyagram (ekrandan, 00:55:00): SATIŞ "==> sahip" SATIR, SATIR "==> var" PARÇA. Satış ile satır bağlandıktan sonra satış ile parça arasında ayrı bir bağıntıya gerek kalmaz; bir satıştaki parçalara satırlar üzerinden ulaşılır ve bilgi kaybı olmaz.

> **Hocanın vurgusu:** Diyagrama bakıp "tamam" demek yetmez. Boş kağıda çizdiğinizde çok yanlış şeyler çıkabiliyor; o alıştırmayı mutlaka yapın.

Hoca bu aşamada yabancı anahtar konusuna girmediklerini, kavramsal tasarımda yalnız varlıklar, bağıntılar ve eleman sayılarıyla ilgilendiklerini; kavramsal tasarımdan ilişkisel tablolara geçişin ve yabancı anahtarların birazdan işleneceğini söyledi.

## 7. Takım, Oyuncu ve Oyun Örneği

Slayt (ekrandan, 01:05:00 ve 01:10:00):

```text
Örnek 5
- Birden çok oyuncu içeren takımlar arasında, iki takım içeren oyunlar ile ilgili
  bilgiler tutulmak isteniyor. (Oyuncu en fazla bir takımın elemanı olabilir.)
- her oyunda hangi takımların yer aldığı (hangi takım ev sahibi hangisi misafir olduğu)
  ve oyunun tarihi ve sonucu gibi bilgiler tutuluyor.
- her oyunda takımın hangi oyuncularının yer aldığı bilgisi takip ediliyor.
```

Bu örneğin incelikli yanı, bir takımın örneğin 20 oyuncusu olsa da bir maçta yalnız bir kısmının sahaya çıkmasıdır; bunun da takip edilmesi gerekir.

Varlık kümeleri takım, oyuncu ve oyundur. Oyuncu ile takım arasında "ait" bağıntısı N:1'dir ve iki taraf da zorunludur: oyuncu olmak için bir takıma ait olmak, takım olmak için oyuncuları olmak gerekir.

### 7.1 Neden oyun ayrı bir varlık?

Oyun iki takım arasında oynandığına göre takım üzerinde recursive bir bağıntı da çizilebilirdi. Ama o zaman o maçta hangi oyuncuların oynadığını tutmak zor olurdu; üçlü bir bağıntıya ya da karmaşık çözümlere girmek gerekirdi. Bunun yerine oyun bir varlık kümesi yapıldı ve diyagram rahatladı:

```text
oyuncu N ==ait== 1 takım
oyuncu M --oynar-- N oyun
takım 1 --ev (skor)------ N oyun
takım 1 --misafir (skor)- N oyun
oyun: PK (tarih, sonuç)
```

Bir oyunda bir takım ev sahibi, bir takım misafirdir; bir takım ise ev sahibi ya da misafir olarak birçok oyunda yer alabilir, bu yüzden oyun tarafı N'dir. Skor bağıntıların niteliğidir: örneğin ev sahibi 1, misafir 3 gol attıysa maç 3-1 sonuçlanmış olur. Hangi oyuncuların oynadığı oyuncu-oyun arasındaki M:N "oynar" bağıntısıyla ifade edilir.

Hoca üçlü bağıntıların gösteriminde kitaplar arasında tam bir uzlaşma olmadığını, önceki derste anlattığı yorumun bazı kitaplarda geçtiğini, bu yüzden bu "riskli bölgeye" girmeden ikili bağıntılarla çözmenin tercih edildiğini söyledi.

### 7.2 Anahtarlar

Diyagram çizildikten sonra nitelikler ve anahtarlar belirlenmelidir. Takımlar ülke çapındaysa iki takımın adı aynı olamaz; bu durumda ID vermeye gerek yoktur, ad anahtar olabilir. Oyuncu için kimlik numarası olabilir. Hoca slaytta bu ayrıntıların işi uzatmamak için yazılmadığını, gerçek bir tasarımda yazılması gerektiğini belirtti.

Slaytta oyunun birincil anahtarı tarih ve sonuçtan oluşan bir birleşik anahtar (PK) olarak gösteriliyor. Hoca önce tarihin yeterli olabileceğini düşündü, sonra yeterli olmayacağını düzeltti: farklı takımlar aynı gün maç yapabilir. Daha iyi bir tasarım, oyunu zayıf varlık yapıp var olma bağıntıları üzerinden iki takıma bağlamaktır. O zaman oyunun anahtarı iki takımın adları ile tarihin birleşimi olur. İki takımın aynı gün birden çok maç yapmadığı varsayılırsa gün bilgisi ayırt edici nitelik olarak yeterlidir: A ve B takımları 20 Aralık'ta ve 25 Aralık'ta oynadıysa bu iki maç tarihle ayrılır.

Hoca buradaki tasarımların ilk çizimler olduğunu, eksikleri olabileceğini ama yanlış bir şey içermediğini söyledi.

## 8. Banka Hesabı İşlemleri Örneği

Slayt: "Örnek 6: Bir banka hesabına ait işlemler hakkında işlem zamanı (gün, saat), işlem tipi ve miktar bilgileri tutuluyor. Bu olayı takip eden ER diyagramı:" (ekrandan, 01:20:00). Çözüm (ekrandan, 01:40:00):

```text
hesap --ait== işlem (zayıf)
işlem nitelikleri: miktar, tip, GS (gün, saat)
Not: gün, saat partial key oluyor.
```

İşlemin nitelikleri (miktar, tip olarak para yatırma ya da çekme, gün ve saat) hepsi bir araya gelse bile bir işlemi tek başına belirlemez; işlem güçlü yapılamaz. Bu yüzden belli bir hesap altında ayırt edici nitelik belirlenir.

İş kuralı "bir hesapta bir saat içinde birden çok işlem yapılmaz" ise gün ve saat (GS) kısmi anahtar olarak yeterlidir. Örneğin 100 numaralı hesap belli bir pazartesi saat 11'de işlem yaptıysa, o saatte o hesaptan başka işlem olmayacağı için dakika ve saniye tutmaya gerek yoktur. Farklı hesapların aynı saatte, aynı miktar ve tipte işlem yapması sorun değildir, çünkü hesap numaraları farklıdır.

Aynı hesaptan bir saat içinde birden çok işlem yapılabiliyorsa daha ince zaman (dakika, saniye) tutulmalıdır. Hoca, ayrıntılı zaman bilgisini ayırt edici niteliğe dahil etmeden de tutabileceğimizi, çünkü anahtara eklenen her niteliğin ayrı bir yük olduğunu belirtti. Örnek, ihtiyaca göre niteliklerin ve ayırt edici niteliğin nasıl belirlendiğini gösteriyor.

## 9. Uçak Rezervasyon Sistemi

Hoca bu örneği daha kapsamlı ve gerçek hayatta (örneğin bir web uygulamasının arkasında) kullanılabilecek bir tasarım olarak tanıttı; şimdiye kadarki örnekler büyük veritabanlarının küçük prototipleri gibiydi.

### 9.1 Gereksinimler

Slayt (ekrandan, 01:45:00):

```text
UÇAK REZERVASYON SİSTEMİ
- Each FLIGHT is identified by a flight NUMBER, and consists of one or more
  FLIGHT_LEGs with LEG_NUMBERs 1, 2, 3, etc.
- Each leg has scheduled arrival and departure times and airports, and has many
  LEG_INSTANCEs--one for each DATE on which the flight travels.
  FARES are kept for each flight.
- For each leg instance, SEAT_RESERVATIONs are kept, as is the AIRPLANE used in
  the leg, and the actual arrival and departure times and airports.
- An AIRPLANE is identified by an AIRPLANE_ID, and is of a particular AIRPLANE_TYPE.
- CAN_LAND relates AIRPLANE_TYPEs to the AIRPORTs in which they can land.
- An AIRPORT is identified by an AIRPORT_CODE.
```

Hoca "leg" (ayak) kavramını bir aktarmalı uçuşla açıkladı: örneğin İstanbul'dan Almanya'ya, oradan New York'a, oradan Los Angeles'a giden bir uçuş birden çok ayaktan oluşur. Uçuş bir plandır (örneğin her pazartesi sabah 9'da kalkan sefer). "Instance" (olgu) ise o planın belirli bir tarihteki gerçekleşmesidir: 9'da kalkması planlanan uçak 9'u 3 geçe kalkmış, 11'de inmesi gereken uçak birkaç dakika rötarla inmiş olabilir. Koltuk rezervasyonu uçuşa değil, ayağın belirli bir tarihteki olgusuna yapılır.

### 9.2 ER diyagramı (Elmasri/Navathe Figure 3.17)

Slayttaki diyagram (ekrandan, 01:50:00):

```text
AIRPORT (AirportCode, Name, City, State)
FLIGHT (Number, Airline, Weekdays)
FLIGHT_LEG (zayıf; LegNo)          FLIGHT 1 ==LEGS== N FLIGHT_LEG
FARE (zayıf; Code, Amount, Restrictions)   FLIGHT 1 ==FARES== N FARE
LEG_INSTANCE (zayıf; Date, No-of-avail seats)
                                   FLIGHT_LEG 1 ==INSTANCE_OF== N LEG_INSTANCE
SEAT (zayıf; SeatNo)               LEG_INSTANCE 1 ==RESERVATION== N SEAT
                                   (CustomerName, CPhone)
AIRPORT 1 --DEPARTURE_AIRPORT-- N FLIGHT_LEG  (ScheduledDepTime)
AIRPORT 1 --ARRIVAL_AIRPORT---- N FLIGHT_LEG  (ScheduledArrTime)
AIRPORT 1 --DEPARTS-- N LEG_INSTANCE  (DepTime)
AIRPORT 1 --ARRIVES-- N LEG_INSTANCE  (ArrTime)
AIRPLANE_TYPE (TypeName, Max-seats, Company)
AIRPORT M --CAN_LAND-- N AIRPLANE_TYPE
AIRPLANE (AirplaneId, Total-no-of-seats)   AIRPLANE_TYPE 1 --TYPE-- N AIRPLANE
AIRPLANE 1 --ASSIGNED-- N LEG_INSTANCE
NOTES: (1) A LEG (SEGMENT) IS A NONSTOP PORTION OF A FLIGHT
       (2) A LEG INSTANCE IS A PARTICULAR OCCURRENCE OF A LEG ON A PARTICULAR DATE
```

### 9.3 Zayıf varlık zinciri

Uçuş planı ile ayakları 1:N bağlanır. FLIGHT_LEG için ekstra bir nitelik konmadı, yalnız LegNo var; bu satış formundaki satır numarası gibidir: bütün veritabanında anahtar olamaz ama bir uçuşun birinci, ikinci, üçüncü ayağını ayırır. Bu yüzden FLIGHT_LEG zayıftır.

Planlanan ayağın her tarihteki gerçekleşmesi LEG_INSTANCE'tır; bir ayağın birçok olgusu, bir olgunun tek ayağı vardır (1:N). Olgunun nitelikleri tarih ve boş koltuk sayısıdır. Hoca tarihin ayırt edici nitelik olarak yeterli olup olmadığını sordu ve yeterli olduğunu söyledi: aynı tarihte aynı uçuşun aynı ayağı bir kez gerçekleşir, farklı tarihlerde birçok kez gerçekleşebilir.

Koltuklar da zayıftır. Bir olgunun N koltuğu vardır ve bir koltuk o olguda bir kez rezerve edilir. Koltuk başka olgularda da kullanılır, ama olgu ile olay belirli bir ana sıkıştırıldığı için koltuk numarası ayırt edici nitelik olabilir. Örneğin İstanbul-Los Angeles uçuşunun birinci ayağının 20 Aralık tarihli olgusundaki koltuklar tek tek ayırt edilir.

Anahtarlar şöyle birikir:

- FLIGHT: Flight number
- FLIGHT_LEG: Flight number + LegNo
- LEG_INSTANCE: Flight number + LegNo + Date
- SEAT: Flight number + LegNo + Date + SeatNo

> **Hocanın vurgusu:** Bu çok güzel bir tasarım; zayıf, zayıf, zayıf ve bir tane güçlü. Doğru olduğu sürece varlıkları zayıf yapabilmek tasarım açısından başarıdır; burada tek birincil anahtar flight number'dır.

### 9.4 Diğer kısımlar

Ücretler (FARE) uçuşa bağlıdır; bir uçuşun farklı kategorilerde (hocanın örneğiyle business ya da normal yolcu gibi) birden çok ücreti olabilir. Ayağın planlanan kalkış ve varış havalimanları ve saatleri DEPARTURE_AIRPORT ve ARRIVAL_AIRPORT bağıntılarında, olgunun gerçek kalkış ve varış havalimanları ve saatleri DEPARTS ve ARRIVES bağıntılarında tutulur. Hocanın örneği: 9'da kalkması planlanan uçak 9'u 7 geçe kalkmış, 11:10'da inmesi beklenirken havada tur atıp 11:21'de inmiş. Böylece en çok rötar yapan uçuşlar gibi istatistikler çıkarılabilir.

Her olguda kullanılan uçak farklı olabilir (ASSIGNED). Uçağın tipi TYPE bağıntısıyla, bir tipin hangi havalimanlarına inebildiği CAN_LAND ile tutulur.

## 10. Genelleme Örneği (EER)

Slayt: "Örnek 9 (genelleme)", Figure 4.1 "EER diagram notation to represent subclasses and specialization" (ekrandan, 02:00:00). Bu örnek bağıntılardan çok varlık kümelerinin ayrıntılandırılmasıyla ilgilidir.

```text
EMPLOYEE (Name (Fname, Minit, Lname), Ssn, Birth_date, Address)
Three specializations of EMPLOYEE:
  {SECRETARY (Typing_speed), TECHNICIAN (Tgrade), ENGINEER (Eng_type)}  -> d
  {MANAGER}                                 MANAGER --MANAGES-- PROJECT
  {HOURLY_EMPLOYEE (Pay_scale), SALARIED_EMPLOYEE (Salary)}  -> d (çift çizgi)
                                   HOURLY_EMPLOYEE --BELONGS_TO-- TRADE_UNION

ER diyagramında IS A (AİT OLMA) bağıntısı
- Katılım, zorunlu ise çift çizgi ile, zorunlu değilse tek çizgi ile
- Ayrıklık, AND (disjoint) ise yuvarlak içinde d ile,
  OR (not disjoint) ise yuvarlak içinde o ile ifade ediliyor.
```

Üç cümle (işçilerin bir kısmı sekreter, teknisyen ya da mühendistir; bir kısmı yöneticidir; bir kısmı saat ücretli, bir kısmı maaşlıdır) üç ayrı özelleştirme oluşturdu. Bütün nitelikler EMPLOYEE'de toplansaydı, örneğin sekreter olmayan herkes için Typing_speed NULL kalırdı; her alt sınıfa özgü nitelik için aynı durum geçerli olurdu. Alt sınıflara ayırmak bu gereksiz ve boş verileri önler. Süper varlıktaki nitelikler ise bütün alt varlıklar için geçerlidir.

Bağıntılar da alt sınıfa bağlanabilir: proje yalnız yöneticiler tarafından yönetilir (MANAGES), sendikaya yalnız saat ücretli çalışanlar üye olur (BELONGS_TO). Bunlar EMPLOYEE'ye bağlansaydı bütün çalışanlar proje yönetebilirmiş gibi görünürdü.

Ayrıklık soruları: bir teknisyen aynı zamanda mühendis ya da sekreter olamaz (d), ama yönetici olabilir, çünkü bu farklı bir sınıflandırmadır. Bir teknisyenin Pay_scale niteliği olabilir (saat ücretliyse), ama bir kişinin hem Salary hem Pay_scale niteliği olamaz, çünkü o özelleştirme de ayrıktır.

Hoca ardından bir bilgisayar parçaları satış veritabanı örneğini gösterdi ve bağıntılarının anlaşılır olduğunu, uygun nitelikleri öğrencilerin belirleyebileceğini söyledi; bu örnekler ayrıntılı işlenmedi. Bu tasarımların ileride projelerde şablon olarak kullanılabileceğini ekledi.

## 11. ER'dan İlişkisel Modele Dönüşüm

Dönemin ilk kısmında SQL, ilişkisel model tabloları ve SQL fonksiyonları işlenmişti; son iki haftadır kavramsal tasarım işleniyor. Bu ikisi ER'dan ilişkisel modele dönüşüm (mapping) ile birleştirilir. Hoca normalde dönüşümden önce normalizasyon yapılması gerektiğini, ama normalizasyon daha zor olduğu için önce dönüşümün anlatılacağını söyledi; normalizasyon kavramsal tasarımdan sonra ya da dönüşümden sonra tablolar üzerinde yapılabilir. Toplam dokuz kural var ve hepsinin zemini (varlıkların ve bağıntıların anahtarları) daha önce hazırlandı.

### 11.1 Adım 1 ve 2: Güçlü ve zayıf varlıklar

Slayt (ekrandan, 02:05:00):

```text
Step 1: Mapping of Regular Entity Types.
- For each regular (strong) entity type E in the ER schema, set up a relation R
  that includes all the simple attributes of E.
- Choose one of the key attributes of E as the primary key for R.
- If the chosen key of E is composite, the set of simple attributes that form it
  will together form the primary key of R.
- Example: We create the relations EMPLOYEE, DEPARTMENT, and PROJECT in the
  relational schema corresponding to the regular entities in the ER diagram.
  SSN, DNUMBER, and PNUMBER are the primary keys for the relations EMPLOYEE,
  DEPARTMENT, and PROJECT as shown.
Step 2: Mapping of Weak Entity Types
- For each weak entity type W in the ER schema with owner entity type E, set up a
  relation R & include all simple attributes (or simple components of composite
  attributes) of W as attributes of R.
- Also, include as foreign key attributes of R the primary key attribute(s) of the
  relation(s) that correspond to the owner entity type(s).
- The primary key of R is the combination of the primary key(s) of the owner(s)
  and the partial key of the weak entity type W, if any.
- Example: Create the relation DEPENDENT in this step to correspond to the weak
  entity type DEPENDENT.
- Include the primary key SSN of the EMPLOYEE relation as a foreign key attribute
  of DEPENDENT (renamed to ESSN). The primary key of the DEPENDENT relation is the
  combination {ESSN, DEPENDENT_NAME} because DEPENDENT_NAME is the partial key of
  DEPENDENT.
```

Her güçlü varlık kümesi için mutlaka bir tablo kurulur; anahtarı kavramsal tasarımda (ya da normalizasyondan sonra) seçilen anahtardır, birleşikse bütün bileşenleriyle. Her zayıf varlık için de mutlaka bir tablo kurulur; anahtarı bağlı olduğu güçlü varlığın (ya da güçlülerin, ya da başka bir zayıf üzerinden ulaşılan güçlünün) anahtarı ile kendi kısmi anahtarının birleşimidir. Uçak rezervasyonunda SEAT tablosunun anahtarı yalnız SeatNo değil, Flight number + LegNo + Date + SeatNo'dur; zincir boyunca güçlüye kadar gidilir.

COMPANY için (ekrandan, 02:15:00): EMPLOYEE'nin birincil anahtarı Ssn; DEPARTMENT'ın anahtarı Name ya da Number olabilir (ikisi birlikte değil), Dnumber seçilmiş; PROJECT için Pnumber seçilmiş, Pname de anahtar olabilir ama birincil seçilmemiş. DEPENDENT zayıf olduğundan güçlüsü EMPLOYEE'ye gidilir ve anahtar Essn + Dependent_name olur. Essn, tanımlayıcı bağıntı yüzünden DEPENDENT'a taşınan yabancı anahtardır.

### 11.2 Adım 3: 1:1 bağıntılar

Slayt (ekrandan, 02:10:00):

```text
Step 3: Mapping of Binary 1:1 Relationship Types
- For each binary 1:1 relationship type R in the ER schema, identify the relations
  S and T that correspond to the entity types participating in R.
There are three possible approaches:
1. Foreign Key approach: Choose one of the relations-say S-and include a foreign key
   in S the primary key of T. It is better to choose an entity type with total
   participation in R in the role of S. (WHY?)
   - Example: 1:1 relation MANAGES is mapped by choosing the participating entity
     type DEPARTMENT to serve in the role of S, because its participation in the
     MANAGES relationship type is total.
2. Merged relation option: An alternate mapping of a 1:1 relationship type is
   possible by merging the two entity types and the relationship into a single
   relation. This may be appropriate when both participations are total.
3. Cross-reference or relationship relation option: The third alternative is to
   set up a third relation R for the purpose of cross-referencing the primary keys
   of the two relations S and T representing the entity types.
```

- Yabancı anahtar yaklaşımı en yaygın ve tercih edilen yoldur.
- Birleştirme: iki taraf da zorunlu katılımlıysa iki tablo tek tabloda toplanabilir. Ama bazı varlıklar için diğer tarafın nitelikleri NULL kalacağından, taraflardan birinin nitelik sayısı az olmalıdır.
- Ayrı bağıntı tablosu: 1:1'de bu tablonun anahtarı iki taraftan herhangi birinin anahtarıdır.

"WHY?" sorusunun cevabı MANAGES üzerinden verildi. Ayrı tablo kurulsaydı MANAGES (Dnumber, Ssn, Start_date) gibi bir tablo olurdu ve anahtarı Dnumber (ya da Ssn) olabilirdi. Yabancı anahtar yaklaşımında yöneticinin SSN'si zorunlu katılımlı taraf olan DEPARTMENT'a Mgr_ssn olarak eklendi. Her departmanın mutlaka yöneticisi olduğundan bu sütunda hiç NULL görülmez. EMPLOYEE'ye "yönettiği departman" diye yabancı anahtar eklemek de yanlış değildir, ama çalışanların belki yüzde biri, binde biri yönetici olduğundan sütun çoğunlukla NULL kalır. Bu yüzden yabancı anahtar zorunlu katılımlı tarafa eklenir.

### 11.3 1:N, M:N, recursive ve çok değerli nitelikler

1:N bağıntılarda yabancı anahtar N tarafına eklenir. Bu, bağıntının anahtarının N tarafının anahtarı olmasından gelir. WORKS_FOR'da bir çalışan tek departmanda, bir departmanda birçok çalışan vardır. Departman numarası EMPLOYEE'ye Dno olarak eklenir. Tersine, departmana çalışanın SSN'si eklenemezdi, çünkü bir departmanda tek kişi çalışmıyor. Ayrı bir WORKS_FOR tablosu kurulsaydı anahtarı Employee SSN olurdu: 100 numaralı çalışan bilgisayar mühendisliğinde, 101 numaralı elektronik mühendisliğinde, 102 numaralı yine bilgisayar mühendisliğinde gibi, her çalışan bir kez geçer, departman çok kez geçer.

CONTROLS (1:N) için departman numarası N tarafı olan PROJECT'e Dnum olarak taşındı. DEPENDENTS_OF da 1:N'dir ve N tarafı olan DEPENDENT'a çalışanın SSN'si eklendi; bu, zayıf varlığın birincil anahtar tanımıyla da örtüşür.

M:N bağıntılarda mutlaka yeni bir tablo kurulur. WORKS_ON'da bir çalışan birçok projede, bir projede birçok çalışan çalışır; ne çalışanın anahtarı PROJECT'e ne projenin anahtarı EMPLOYEE'ye yabancı anahtar olarak konabilir. Tablonun anahtarı Essn + Pno'dur, bağıntının niteliği Hours da bu tabloya girer.

Recursive SUPERVISION 1:N'dir; N tarafı denetlenenlerdir. Yabancı anahtar yine EMPLOYEE'ye eklenir (Super_ssn), ama başka bir tabloya değil, aynı tablonun Ssn sütununa işaret eder.

Çok değerli nitelik için de ayrı tablo kurulur. Departmanın konumları DEPARTMENT tablosuna yazılırsa (100 numaralı departman İstanbul, Ankara, Van; 200 numaralı yalnız İstanbul; 300 numaralı on farklı yer) nitelik atomik olmaktan çıkar. Hoca bunun hatalı bir tasarım olduğunu normalizasyonda göreceklerini söyledi. Bu yüzden DEPT_LOCATIONS tablosu kurulur ve anahtarı Dnumber + Dlocation'dır: bir departmanın birden çok konumu, bir konumda birden çok departman olabilir.

Sonuç şeması (ekrandan, 02:15:00 ve 02:20:00; altı çizili sütunlar birincil anahtar):

```text
EMPLOYEE (Fname, Minit, Lname, Ssn, Bdate, Address, Gender, Salary, Super_ssn, Dno)
DEPARTMENT (Dname, Dnumber, Mgr_ssn, Mgr_start_date)
DEPT_LOCATIONS (Dnumber, Dlocation)
PROJECT (Pname, Pnumber, Plocation, Dnum)
WORKS_ON (Essn, Pno, Hours)
DEPENDENT (Essn, Dependent_name, Gender, Bdate, Relationship)

Birincil anahtarlar: EMPLOYEE.Ssn, DEPARTMENT.Dnumber,
  DEPT_LOCATIONS.{Dnumber, Dlocation}, PROJECT.Pnumber,
  WORKS_ON.{Essn, Pno}, DEPENDENT.{Essn, Dependent_name}
Yabancı anahtarlar (oklar):
  EMPLOYEE.Super_ssn -> EMPLOYEE.Ssn      EMPLOYEE.Dno -> DEPARTMENT.Dnumber
  DEPARTMENT.Mgr_ssn -> EMPLOYEE.Ssn      DEPT_LOCATIONS.Dnumber -> DEPARTMENT.Dnumber
  PROJECT.Dnum -> DEPARTMENT.Dnumber      WORKS_ON.Essn -> EMPLOYEE.Ssn
  WORKS_ON.Pno -> PROJECT.Pnumber         DEPENDENT.Essn -> EMPLOYEE.Ssn
```

Genel kural şöyle özetlendi: ER diyagramında güçlü varlıklar, zayıf varlıklar, M:N bağıntılar ve çok değerli nitelikler için birer tablo kurulur; bu iskeleti oluşturur. Ardından 1:1 ve 1:N bağıntılar yabancı anahtarlara dönüşür, sonra nitelikler yazılır.

### 11.4 Genel 1:1, 1:N, M:N özeti

Hoca bir slayttaki X-R-Y gösterimiyle kuralları tekrar özetledi: R 1:1 ise X'in ya da Y'nin anahtarı diğer tarafa yabancı anahtar olarak gider; tercih edilen, zorunlu katılımlı tarafa gitmesidir, çünkü o zaman NULL görülmez. 1:1 için R'ye ayrı tablo kurmak tercih edilmez ama olabilir; iki tablo birleştirilip tek tablo da yapılabilir. R 1:N ise N tarafına yabancı anahtar taşınır. R M:N ise R için ayrı bir tablo kurulur ve iki tarafın anahtarlarını içerir. Üçlü bağıntıların dönüşümünden daha önce bahsedilmişti.

## 12. EER'dan İlişkisel Modele Dönüşüm

Slayt (ekrandan, 02:25:00):

```text
Mapping EER Model Constructs to Relations
Step8: Options for Mapping Specialization or Generalization.
- Convert each specialization with m subclasses {S1, S2, ..., Sm} and generalized
  superclass C, where the attributes of C are {k, a1, ... an} and k is the
  (primary) key, into relational schemas using one of the four following options:
  - Option 8A: Multiple relations-Superclass and subclasses
  - Option 8B: Multiple relations-Subclass relations only
  - Option 8C: Single relation with one type attribute
  - Option 8D: Single relation with multiple type attributes
```

- 8A: süper sınıf için bir tablo, her alt sınıf için ayrı bir tablo. Alt sınıf tabloları yabancı anahtarlarla süper tabloya bağlanır. Bu seçenek her zaman uygulanabilir.
- 8B: yalnız alt sınıflar için tablolar. Bunun için özelleştirmenin zorunlu (total) olması gerekir; ancak o zaman alt sınıf tabloları bütün varlıkları kapsar.
- 8C: tek tablo ve bir tür niteliği. Ayrık (disjoint) özelleştirmede bir "job type" niteliği hangi alt sınıf niteliklerinin geçerli olduğunu gösterir.
- 8D: tek tablo ve her alt sınıf için bir bayrak. Çakışan (overlap) özelleştirmede kullanılır. Örneğin parçalar için MFLAG, parçanın üretilmiş (manufactured) parça olup olmadığını gösterir; true ise ilgili nitelikler anlam kazanır. Satın alınan (purchased) parça bayrağı true iken tedarikçi niteliği NULL ise bu, "bilinmiyor" anlamına gelir.

Seçeneklerin hangi koşullarda kullanılabileceği slaytlardaki formal ifadelerde yazıyor; derste ayrıntılı işlenmedi.

## 13. Gemi Takip Örneği

Son olarak dönüşüm kurallarının bir uygulaması gösterildi. Gereksinim: dünya üzerindeki limanları ve gemi hareketlerini tutan bir veritabanı; limanların hangi ülkede ve hangi denizde/okyanusta olduğu, geminin ziyaret ettiği limanlar ve geminin hareket tarihçesi tutuluyor. Hoca bu şablonun uçak, otobüs ya da araba takibi gibi birçok takip (tracking) uygulamasında kullanılabileceğini söyledi.

ER diyagramındaki bütün güçlü ve zayıf varlıklar ile M:N bağıntılar için tablo kurulmuştur (çok değerli nitelik yok): SHIP_MOVEMENT, SHIP, PORT, SEA/OCEAN/LAKE, STATE/COUNTRY. Elde edilen ilişkiler (ekrandan, 02:30:00):

```text
Example-1: Relations
SHIP [Sname, Owner, scName, Pname, Type]
PORT [scName, Pname, solName]
STATE/COUNTRY [Name, Continent]
SEA/OCEAN/LAKE [Name]
SHIP_MOVEMENT [Sname, Date, Time, Longitude, Latitude]
SHIP_TYPE [Type, Tonnage, Hull]
VISITS [scName, Pname, Sname, startDate, EndDate]

Altı çizili (birincil anahtar): SHIP.Sname; PORT.{scName, Pname};
STATE/COUNTRY.Name; SEA/OCEAN/LAKE.Name; SHIP_MOVEMENT.{Sname, Date, Time};
SHIP_TYPE.Type; VISITS.{scName, Pname, Sname, startDate}
```

Parça parça inceleme:

- SHIP ile SHIP_TYPE arasında 1:N bağıntı var; N tarafı SHIP olduğundan SHIP_TYPE'ın anahtarı Type, SHIP'e yabancı anahtar olarak gider. Hoca, şemada yabancı anahtarların neye işaret ettiğinin oklarla gösterilmesi gerektiğini, burada eksik kaldığını söyledi.
- PORT ile SHIP arasındaki 1:N bağıntıda da N tarafı SHIP'tir; PORT'un anahtarı SHIP'e taşınır. PORT zayıftır, bu yüzden anahtarı yalnız liman adı (Pname) değildir; var olma bağıntısı üzerinden güçlüsüne gidilir ve anahtar Pname + bağlı olduğu ülkenin adı olur. Bu ad SHIP'e "scName" diye başka bir adla eklenmiştir; Pname + scName ikilisi birlikte PORT'a işaret eder.

**Soru:** (Bir öğrenci yazılı olarak sordu.) Gemi diyagramında SHIP'e yabancı anahtar olarak neden PName ile ülke adı birlikte eklendi? **Cevap:** PORT zayıf varlıktır. Onun güçlüsüne götüren yol çift çizgili var olma bağıntısıdır, bu yüzden PORT'un anahtarı liman adı ile güçlünün anahtarının birleşimidir ve yabancı anahtar olarak ikisi birlikte taşınır. Uçak rezervasyonunda da aynı durum vardı: SEAT'in anahtarı için çift çizgili bağıntılar boyunca FLIGHT'a kadar gidilir. COMPANY'de DEPENDENT'ın tek bağıntısı EMPLOYEE'ye gittiği için orada yol aramaya gerek yoktu. SHIP'teki Sname ve Owner kendi nitelikleridir; scName ve Pname PORT'tan, Type ise SHIP_TYPE'tan gelmiştir.

> **Hocanın vurgusu:** Kavramsal tasarımdan ilişkisel tablolara dönüşüm soruları sınavlarda en çok sorulan sorulardır ve dersin ana temasıdır. Bir niteliğin neden altı çizili olduğunu, yabancı anahtarın neden o tabloya gittiğini anlayarak çalışın; anlamadan gelinirse bu soru yapılamıyor ve çok puan kaybediliyor.

Hoca, internette ER ile ilgili çok örnek bulunabileceğini, ama oradaki notasyonların derste görülenle uyumlu olmayabileceğini; bunları dersteki ER notasyonuna uygun şekilde yeniden çizerek alıştırma yapılabileceğini söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:10:00): COMPANY veritabanının gereksinimlerine (1. bölümdeki metin) göre varlık kümelerini, niteliklerini ve bağıntılarını belirleyip ER diyagramını çiziniz.

> **Çözüm (derste verildi):** Varlıklar DEPARTMENT, PROJECT, EMPLOYEE ve zayıf varlık DEPENDENT (kısmi anahtar Name). Bağıntılar: WORKS_FOR (EMPLOYEE N : 1 DEPARTMENT, iki taraf zorunlu), MANAGES (1:1, departman tarafı zorunlu, Start_date), CONTROLS (DEPARTMENT 1 : N PROJECT), WORKS_ON (M:N, Hours), SUPERVISION (EMPLOYEE üzerinde 1:N recursive), DEPENDENTS_OF (1:N tanımlayıcı). Locations çok değerli niteliktir. Diyagram 3.2'de.

**Soru 2** (ekrandan, 00:40:00): Şehirler, ülkeler ve nehirleri gösteren bir veritabanı tasarlayınız. Nehirlerin hangi şehirlerden geçtiğini tutmak istersek tasarım nasıl değişir?

> **Çözüm (derste verildi):** Şehir N : 1 Ülke (iki taraf zorunlu). Nehir yalnız ülkeyle bağlanırsa (Ülke N : M Nehir) geçtiği şehirler bilinmez. Şehirlerden geçişi tutmak için nehir şehirle bağlanır (Şehir N : M Nehir); geçtiği ülkeler şehir-ülke bağıntısı üzerinden çıkarılır. Bağıntının yükü artar ama bilgi kaybolmaz.

**Soru 3** (ekrandan, 00:45:00): Her bölüm çok sayıda personele sahiptir ve her personel en fazla bir bölüme bağlıdır; bir bölümün sadece bir yöneticisi (mutlaka) vardır. (a) Bir bölümün yöneticisi ancak o bölüme bağlı bir personel olabiliyor ise, (b) bir bölümün yöneticisi herhangi bir personel olabiliyor ise nasıl bir ER modeli çizilebilir?

> **Çözüm (derste verildi):** (a) B (1..1) "sahip" (0..*) P bağıntısı ve bu bağıntıda "yönetici mi" niteliği yeterlidir. (b) Bu bilgi "sahip" bağıntısında ifade edilemez; bölüm ile personel arasında ayrı bir yönetme bağıntısı gerekir.

> **Çözüm (derste verilmedi):** (b) için eleman sayıları, büyük olasılıkla şöyle: her bölümün tam bir yöneticisi olduğundan bölüm tarafı zorunlu katılımlı ve 1; bir personelin en fazla bir bölümü yönettiği varsayılırsa yönetme bağıntısı 1:1, personel tarafı isteğe bağlıdır (COMPANY'deki MANAGES gibi).

**Soru 4** (ekrandan, 00:50:00): Satış formuna (6. bölümdeki tablo) karşılık gelen veritabanı SATIŞ, PARÇA ve SATIR olmak üzere 3 varlık setinden oluşmaktadır (aynı ParçaNolu parçalar farklı satırlarda tekrar edebilir). Bu varlık setlerini, özelliklerini ve aralarındaki ilişkileri gösteren ER diyagramını çiziniz.

> **Çözüm (derste verildi):** SATIŞ (sNO BA, tarih), PARÇA (pNo BA, isim, fiyat, tanım), SATIR zayıf (satırNo AN, miktar). SATIŞ "sahip" SATIR (tanımlayıcı, 1:N), SATIR "var" PARÇA (bir parça birçok satırda geçebilir). genelToplam ve satırToplamFiyatı türetilmiştir ($1 \times 110 = 110$, $2 \times 80 = 160$); kavramsal tasarımda yazılmasa da olur. Ayrı bir SATIŞ-PARÇA bağıntısına gerek yoktur.

**Soru 5** (ekrandan, 01:05:00): Birden çok oyuncu içeren takımlar arasında, iki takım içeren oyunlar ile ilgili bilgiler tutulmak isteniyor (oyuncu en fazla bir takımın elemanı olabilir). Her oyunda hangi takımların yer aldığı (ev sahibi, misafir), oyunun tarihi ve sonucu ve takımın hangi oyuncularının yer aldığı takip ediliyor. ER diyagramını çiziniz.

> **Çözüm (derste verildi):** oyuncu N ==ait== 1 takım; oyun ayrı varlık; takım 1 - ev (skor) - N oyun, takım 1 - misafir (skor) - N oyun; oyuncu M - oynar - N oyun. Slaytta oyunun anahtarı (tarih, sonuç); hoca daha iyi tasarım olarak oyunu zayıf yapıp anahtarı iki takımın adı + tarih olarak belirlemeyi önerdi.

**Soru 6** (ekrandan, 01:20:00): Bir banka hesabına ait işlemler hakkında işlem zamanı (gün, saat), işlem tipi ve miktar bilgileri tutuluyor. Bu olayı takip eden ER diyagramını çiziniz.

> **Çözüm (derste verildi):** hesap - ait - işlem; işlem zayıf varlıktır (miktar, tip, GS(gün, saat)). Bir hesapta bir saat içinde tek işlem yapılıyorsa gün ve saat kısmi anahtardır. Daha sık işlem varsa daha ince zaman bilgisi gerekir (ekrandan, 01:40:00).

**Soru 7** (derste sözlü, 01:49:23): Uçak rezervasyon sisteminde uçuşun bir ayağının tarihi, LEG_INSTANCE için ayırt edici nitelik olmaya yeterli mi?

> **Çözüm (derste verildi):** Evet. Aynı uçuşun aynı ayağı aynı tarihte bir kez gerçekleşir; farklı tarihlerde birçok kez gerçekleşebilir. LEG_INSTANCE'ın anahtarı Flight number + LegNo + Date olur.

**Soru 8** (ekrandan, 02:10:00): 1:1 bağıntının yabancı anahtar yaklaşımıyla dönüşümünde, zorunlu katılımlı varlık türünü S rolünde seçmek neden daha iyidir? (WHY?)

> **Çözüm (derste verildi):** Yabancı anahtar zorunlu katılımlı tarafa eklenirse o sütunda NULL oluşmaz. MANAGES'te her departmanın yöneticisi olduğu için Mgr_ssn DEPARTMENT'a eklenir; EMPLOYEE'ye eklenseydi çalışanların çok küçük bir kısmı yönetici olduğundan sütun çoğunlukla NULL kalırdı.

**Soru 9** (derste sözlü, 01:59:55): Genelleme örneğinde bir teknisyen yönetici olabilir mi? Bir teknisyenin Pay_scale niteliği olabilir mi? Bir kişinin hem Salary hem Pay_scale niteliği olabilir mi?

> **Çözüm (derste verildi):** Teknisyen sekreter ya da mühendis olamaz (ayrık), ama yönetici olabilir, çünkü MANAGER ayrı bir özelleştirmedir. Saat ücretliyse Pay_scale niteliği olabilir. Hem Salary hem Pay_scale olamaz, çünkü HOURLY/SALARIED özelleştirmesi de ayrıktır.

## Dersin Toparlaması

Bu derste önceki hafta tanımlanan ER, EER ve UML kavramları örneklerle pekiştirildi. COMPANY veritabanında gereksinim raporundaki öznelerden varlıklar, fiillerden bağıntılar çıkarıldı; ilk tasarımda nitelik olarak yazılan kavramlar iyileştirme kurallarıyla bağıntıya ya da varlık kümesine dönüştürüldü. Şehir-ülke-nehir, bölüm-personel, satış formu, takım-oyun, banka işlemleri ve uçak rezervasyonu örneklerinde küçük dünyadaki ifadelerin tasarımı nasıl değiştirdiği, türetilmiş niteliklerin neden saklanmayabileceği ve zayıf varlıkların ayırt edici niteliklerinin iş kurallarına göre nasıl seçildiği görüldü. Genelleme örneğinde alt sınıflara ayırmanın NULL değerleri ve yanlış bağıntıları nasıl önlediği gösterildi.

Dersin ikinci kısmında kavramsal tasarım ilişkisel modele bağlandı: güçlü ve zayıf varlıklar, M:N bağıntılar ve çok değerli nitelikler için tablolar kuruldu; 1:1 bağıntılarda yabancı anahtar zorunlu katılımlı tarafa, 1:N bağıntılarda N tarafına eklendi; özelleştirmeler için 8A-8D seçenekleri tanıtıldı. Hoca sonraki derste normalizasyonun işleneceğini söyledi; çok değerli niteliklerin neden ayrı tabloda tutulduğu da orada gerekçelendirilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
