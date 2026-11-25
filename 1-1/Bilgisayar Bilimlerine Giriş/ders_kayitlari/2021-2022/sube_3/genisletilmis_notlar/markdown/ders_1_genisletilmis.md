# Ders 1 Genişletilmiş Notu: Dersin Tanıtımı, Amacı ve Kapsamı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin amacı
- 2. Dersin içeriği
- 3. Konuların sırası
- 4. Öğrenim çıktıları
- 5. Kaynaklar
- 6. Bu derse nasıl çalışılmalı

## 1. Dersin amacı

Bu ilk ders bir tanışma ve tanıtım dersidir; teknik konulara henüz girilmez. Ekrandaki slayt dersin amacını tek cümleyle verir: "Daha önce hiç tecrübesi olmayan öğrencilere Bilgisayar Mühendisliği temel bilgilerinin öğretilmesi ve algoritma tasarlama yeteneğinin kazandırılması" (ekrandan, 00:20:00).

Hoca bu cümleyi açarken sınıfta oyun, mobil uygulama ya da web uygulaması yazmış öğrenciler olabileceğini, ama dersin herkesin hiçbir ön deneyimi olmadığı varsayımıyla bu tabandan başlayacağını söyler. Dersin iki ayağı vardır:

- Bilgisayar mühendisliğiyle ilgili temel bilgileri vermek.
- Algoritmik düşünmeyi kazandırmak: bir probleme analitik bir çözüm geliştirmek, bu çözümü algoritma olarak ifade etmek ve mümkün olduğunca etkin, yani başarımı iyi algoritmalar tasarlayabilmek.

> **Ek bilgi (derste anlatılmadı):** Algoritma, bir problemi çözmek için izlenecek, sırası belli, sonlu sayıda ve her adımı açıkça tanımlı işlemler dizisidir. Bilgisayar ancak böyle belirsizlik içermeyen adımları yürütebildiği için, algoritmik düşünme programlamanın ön koşulu sayılır.

## 2. Dersin içeriği

Hoca dersin değineceği konuları genel başlıklar hâlinde sıralar:

- **Tarihçe:** Bilgisayar nereden geldi, hesaplamalar hangi cihazlarla yapıldı, bugünkü yapıya nasıl ulaşıldı ve nereye gidiyor.
- **Temel kavramlar:** Bilgisayar mühendisliğinin temel araştırma problemleri ve araştırma alanları; yazılım ve donanımla ilgili temel kavramlar.
- **Bilgisayar mimarisi:** Algoritma tasarlarken hangi mimarinin esas alındığı; en azından bu dersteki algoritmaların hangi mimariye hitap ettiği.
- **Verinin işlenmesi ve depolanması:** Verinin yazılım ve donanım kullanılarak belirli bir mimaride nasıl işlendiği; sayıların bilgisayarda nasıl depolandığı; işaretli sayılar, işaretsiz sayılar ve kesirli sayıların ne olduğu, nasıl saklandığı ve nasıl kullanıldığı.
- **Sayı sistemleri:** Farklı mimarilerde farklı gösterimler ve sayı sistemleri kullanılabilir; bunlar arasındaki dönüşümlerin nasıl yapıldığı.
- **Algoritma:** Algoritmanın nasıl ifade edildiği ve gösterildiği; girdilerin ve çıktıların gösterimi; aritmetik işlemler, kontrol deyimleri ve defalarca yapılması gereken (tekrarlı) işlemlerin ifadesi.
- **Kodlama:** Algoritmaları pratiğe dökmek için C dili temel alınarak kodlamaya giriş; algoritma tasarımında ve gerçeklemede kullanılan temel veri tipleri; aynı tipteki verilerin bir araya gelmesiyle oluşan diziler ve bunlarla ilgili tanıtıcı örnek problemler.
- **Karakter dizileri ve çok boyutlu diziler:** Diziler yalnız sayılardan oluşmak zorunda değildir; karakter dizileri ve iki boyutla sınırlı kalmayan n boyutlu diziler.
- **Farklı çözüm yaklaşımlarının karşılaştırılması:** Aynı problemin farklı algoritmik yaklaşımlarla çözülebildiği, her yaklaşımın ne kazandırıp ne kaybettirdiği. Bunun için başka algoritmaların içinde de sık kullanılan iki temel problem ailesi incelenir: çok sayıda veri içinde aranan bir değeri bulmaya çalışan **arama algoritmaları** ve **sıralama algoritmaları**.
- **Karmaşıklık:** Bir algoritmanın etkinliğini, başarımını ölçmek için algoritma karmaşıklığının nasıl ifade edildiği. Bu derste yalnız farkındalık düzeyinde kalınır; biçimsel incelemesi ve ayrıntılı karmaşıklık hesapları ileride veri yapıları ve algoritma analizi derslerinde yapılır.

Hoca neden Python yerine C ile başlandığı sorusunun akla gelebileceğini söyler. Gerekçenin hem Python'un dil yapısı ve değişken yapısının tasarımıyla hem de C'nin farklı tasarım yaklaşımıyla ilgili olduğunu belirtir, ama ayrıntılı tartışmayı C'ye geçilen haftaya bırakır.

> **Ek bilgi (derste anlatılmadı):** C, bellekle doğrudan çalışan (adresler, sabit boyutlu veri tipleri) ve değişkenlerin tipinin baştan bildirildiği bir dildir; Python'da ise tipler çalışma anında belirlenir ve bellek yönetimi dilin içinde gizlidir. Bu yüzden C, verinin bellekte nasıl tutulduğunu ve bir algoritmanın makinede nasıl çalıştığını görmeyi kolaylaştırdığı için giriş derslerinde büyük olasılıkla tercih edilir.

Son konu olarak işletim sistemleri ve bilgisayar ağlarına temel bir bakış yapılır. Hoca, adları çok farklı olsa da bu iki alanın temelde benzer kavramları paylaştığını ve problemleri benzer tasarım fikirleriyle çözdüğünü, bunun o haftada görüleceğini söyler.

## 3. Konuların sırası

Slayttaki ders planı (değişebileceği notuyla) konuları şu sırayla verir (ekrandan, 00:30:00):

- Tanışma ve ders tanıtımı.
- Bilgisayarın tarihçesi, veri depolama, sayı sistemleri.
- Bilgisayar mimarisi, veri manipülasyonu, tam sayılar ve kesirli sayılar.
- Bilgisayar bilimlerini tanıtıcı problemler.
- Algoritma kavramları, akış diyagramı, akış diyagramı sembolleri, algoritmalarda girdi, çıktı ve kontroller.
- Algoritmalarda yineleme yapıları, döngü koşulları.
- C programlama diline giriş, diziler.
- Tek boyutlu diziler.
- Karakter dizileri.
- Çok boyutlu diziler.
- Arama algoritmaları.
- Sıralama algoritmaları.
- İşletim sistemleri ve bilgisayar ağları.

Hoca bu akışı anlatırken akış diyagramlarında kullanılan sembollere ve alternatiflerine, girdinin nasıl alınıp çıktının nasıl verildiğine ve algoritmalardaki kontrol yapılarına ayrıca değinileceğini; yineleme kısmında tekrarlı yapıların, döngülerin ve döngü kontrol koşullarının işleneceğini söyler. Arama ve sıralama haftalarında, daha önce geliştirilmiş ve yayımlanmış hazır algoritmaların nasıl çalıştığı, neden ve nasıl çözüm ürettiği ve birbirlerinden farkları incelenir.

## 4. Öğrenim çıktıları

Slayttaki öğrenim çıktıları, dersi bitiren öğrencinin neler kazanmış olması gerektiğini sıralar (ekrandan, 00:25:00):

- Öğrenci bilgisayar mühendisliği ile ilgili temel kavramları öğrenir.
- Öğrenci doğru ve verimli algoritma tasarımını öğrenir.
- Öğrenci algoritmaları akış şemaları kullanarak betimlemeyi öğrenir.
- Öğrenci bilgisayar mühendisliğinin alt alanları hakkında bilgi sahibi olur.

Hoca "doğru ve verimli" ifadesini şöyle açar: algoritma, doğru girdi verildiğinde doğru çözüm üretmeli ve başarımı mümkün olduğunca iyi olacak şekilde verimli çalışmalıdır. Akış şemaları ise algoritmayı kâğıt üzerinde ya da başka bir ortamda göstermenin, ifade etmenin ve belgelemenin yoludur.

## 5. Kaynaklar

Dersin temel kaynağı derste anlatılanlar, gösterilen çizimler ve öğrencinin bunları anlayarak tuttuğu kendi notlarıdır. Hoca başkasının notuna ya da çoğaltılmış notlara güvenmemeyi önerir: herkes yalnız kendi anladığı kadar not tutar ve bir şeyi yanlış anlayıp notuna yanlış geçirmiş olabilir.

Basılı kaynaklar:

- **Temel kaynak:** Brookshear, *Computer Science: An Overview*. Derste 12. baskı gösterilir. Hoca son birkaç baskının birbirine çok benzediğini, farkların daha çok güncel teknolojilerle ilgili olduğunu söyler (örneğin megabayt ve gigabayttan söz edilen yerlerde yeni baskılarda terabayt ve petabayttan söz edilmesi). Temeller değişmediği için son baskılardan herhangi biri yeterlidir.
- **Türkçe yardımcı kaynak:** Fahri Vatansever, *Algoritma Geliştirme ve Programlamaya Giriş* (Seçkin Yayıncılık).

## 6. Bu derse nasıl çalışılmalı

Dersin ikinci hocası, giriş dersinin kolay görünse de dört yıllık eğitimin en önemli derslerinden biri olduğunu vurgular.

> **Hocanın vurgusu:** Bu derste öğrenilen temel bilgiler bir binanın temeli gibidir; geri kalan bütün dersler bunun üzerine inşa edilir. Bu derse özen göstermek sonraki dersleri kolaylaştırır.

Programlama bildiğini düşünen öğrenciler için de ders bir fırsattır: eksik ya da yanlış bilinen bilgiler bu derste düzeltilebilir.

Algoritmik düşünmeye alışma süresi kişiden kişiye değişir; kimi birkaç haftada, kimi birkaç ayda adapte olur. Hoca başta çok zorlanıp sonra çok başarılı olan öğrenciler olduğunu, bu yüzden umutsuzluğa kapılmamak gerektiğini söyler.

> **Hocanın vurgusu:** Derste çözülen soruları ve anlatılan konuları, çözüme bakmadan yeniden çözmeye çalışıp sonra kontrol etmek çok büyük yol aldırır. Ek olarak onlarca soru çözmeye gerek yoktur; dersteki örnekler, ödevler ve laboratuvar uygulamaları düzenli yapıldığında algoritmik düşünme yavaş yavaş oturur.

Hoca ayrıca derste duyulan bir bilgiyi araştırarak genişletmenin ilerleyen yıllarda karşılığını vereceğini, aynı bilginin başka derslerde tekrar karşılarına çıkacağını belirtir.

## Dersin Toparlaması

Bu ilk derste teknik konulara girilmeden dersin çerçevesi çizildi. Dersin iki hedefi, bilgisayar mühendisliğinin temel kavramlarını vermek ve doğru ve verimli algoritma tasarlama yeteneğini kazandırmaktır. Konu akışı bilgisayarın tarihçesi ve sayı sistemleriyle başlar; bilgisayar mimarisi ve sayıların bilgisayardaki gösterimiyle devam eder; ardından algoritma kavramı, akış diyagramları ve döngüler gelir. Algoritmalar C dilinde gerçeklenir ve diziler, karakter dizileri ve çok boyutlu dizilerle genişletilir. Dönemin sonunda arama ve sıralama algoritmaları üzerinden farklı çözüm yaklaşımları karşılaştırılır, karmaşıklık kavramı tanıtılır ve işletim sistemleri ile bilgisayar ağlarına kısa bir bakış yapılır.

Bir sonraki derste konulara gerçek giriş yapılacak; ilk konu bilgisayarın tarihçesi, veri depolama ve sayı sistemleridir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
