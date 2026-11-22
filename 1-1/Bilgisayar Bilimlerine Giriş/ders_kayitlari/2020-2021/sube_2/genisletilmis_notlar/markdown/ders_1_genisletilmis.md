# Ders 1 Genişletilmiş Notu: Dersin Kapsamı, Algoritmaya Bakış ve Öğrenme Stilleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Dersin Konuları
- 3. Laboratuvar Uygulamalarının İçeriği
- 4. Kaynak Seçimi ve Çalışma İlkeleri
- 5. Öğrenmeyi Öğrenmek
- 6. Öğrenme Stilleri Testi

## 1. Dersin Yapısı

Bu ilk ders, dersin tanıtımına, bölüme uyum (oryantasyon) bilgilendirmesine ve öğrencinin kendi öğrenme biçimini tanımasına ayrılmıştır. Bu not yalnız dersin içeriğine ve çalışma yöntemine dair kısımları aktarır. Üniversite ve bölüm yapısı, sınav, notlama ve idari süreçlerle ilgili bölümler nota alınmamıştır.

Dersin iki parçası vardır. Haftada bir gün kuramsal ders yapılır, başka bir gün de laboratuvar saati vardır (ekrandan, 00:35:00). Normal dönemde laboratuvar takvimini asistanlar yürütür. Kalabalık gruplar ve sınırlı laboratuvar sayısı yüzünden her öğrenci iki haftada bir, toplam beş kez laboratuvara girebilir. Bu dönem eğitim çevrim içi olduğu için hoca laboratuvar saatlerini en verimli şekilde kullanmayı planlar. Üçüncü ya da dördüncü haftadan itibaren uygulamalar doğrudan hocayla yapılacaktır. Slaytta laboratuvar sayısı "büyük olasılıkla 11" olarak verilir (ekrandan, 00:55:00).

## 2. Dersin Konuları

Hoca dersin konularını sırasıyla tanıtır. Slayttaki "Course Outline" başlığı şu maddeleri içerir (ekrandan, 00:40:00):

- History: kısa bir özet.
- Basics: sayı sistemleri, işaretli/işaretsiz sayılar, tam sayılar, kayan noktalı sayılar.
- Introduction to algorithms: akış diyagramları, sözde kodlar.
- Flow charts: kontrol akışı elemanları.
- Arrays: karakter dizileri, çok boyutlu diziler.

Altyazıya göre bunların ardından C dili ile uygulama ile arama ve sıralama algoritmaları gelir.

### 2.1 Tarihçe ve Temeller

Ders, bilgisayar biliminin geçmişinden kısaca söz ederek başlayacaktır. Ardından öğrencilerin bir kısmını bildiği, bir kısmını unuttuğu temel konulara geçilir: sayı sistemleri ve sayı sistemleri arasında dönüşüm, işaretli ve işaretsiz sayılar, tam sayılar ve gerçek sayılar.

Bu konuların merkezindeki soru şudur: Bilgisayar sistemleri bugün ikili (binary) bir sistem kullanır, yani her şey 0 ve 1 ile ifade edilir. Yalnız 0 ve 1 yazılabilirken 3,14 gibi bir sayı nasıl ifade edilir? Sayıların bilgisayarda gösterimi bu sorunun cevabıdır.

### 2.2 Algoritmalar ve Akış Diyagramları

Hoca algoritmayı dersin en temel konusu olarak tanıtır. Kaba haliyle algoritma, **bir işin nasıl yapılacağının tarifidir**. Bu tarif birkaç şekilde ifade edilebilir. Bunlardan ikisi akış diyagramı (flowchart) ve sözde koddur (pseudocode).

Bu derste her zaman akış diyagramı çizilecektir. Bu yüzden akış diyagramının nasıl çizildiği ve hangi elemanlardan oluştuğu uzun süre konuşulacaktır. Akış diyagramları elle çizilir. Sınıf ortamında hoca bunları tahtaya, öğrenciler de defterlerine çizer. Bu kısım için bilgisayar gerekmez.

> **Ek bilgi (derste anlatılmadı):** Sözde kod, belirli bir programlama dilinin söz dizimine bağlı olmadan, adımları doğal dile yakın ama düzenli bir biçimde yazan gösterimdir. Akış diyagramı ise aynı adımları semboller ve oklarla görsel olarak gösterir. İkisi de aynı algoritmayı farklı biçimde anlatır.

### 2.3 Veri Yapıları ve C Dili

Akış diyagramlarından sonra temel veri yapılarına geçilir: diziler, karakter dizileri ve bunların özel bir durumu olan string yapısı, çok boyutlu diziler.

Akış diyagramlarıyla ve veri yapılarıyla ilgili konuşulanlar bir programlama dilinde uygulanır. Bu dil C'dir. Önce C'de çok temel bazı konular ele alınır. Bu kısımda program yazıp çalıştırmak için bilgisayara ihtiyaç vardır.

### 2.4 Arama ve Sıralama Algoritmaları

Veri yapılarından sonra farklı algoritmalar işlenir.

- **Arama (search):** En basiti sıralı (sequential ya da lineer) aramadır. Bu işi hızlandırmak için ikili arama (binary search) kullanılır. Veri dizi değil de ağaç yapısında tutuluyorsa aramanın nasıl yapılacağı da konuşulur.
- **Sıralama (sort):** Hoca sıralamayı bilgisayar mühendisliği açısından önemli bir problem olarak niteler. Bubble Sort, Quick Sort, Selection Sort ve Radix Sort sıralama algoritmalarından yalnız birkaçıdır. Derste mümkün olduğunca fazlası ele alınacaktır.

> **Ek bilgi (derste anlatılmadı):** İkili arama yalnız sıralı bir dizide çalışır. Her adımda aranan değeri dizinin ortasındaki elemanla karşılaştırır ve aramayı dizinin yarısına daraltır. Bu yüzden büyük dizilerde sıralı aramadan çok daha az karşılaştırma yapar.

## 3. Laboratuvar Uygulamalarının İçeriği

Hoca laboratuvarlarda pratik uygulamalar yapılacağını, öğrencilerin elle yaparak deneyim (hands-on experience) kazanmasını istediğini söyler.

### 3.1 İşletim Sistemi Kurulumu

İlk uygulama büyük olasılıkla bir işletim sistemi kurulumudur. İşletim sistemi kurmak denince çoğu zaman Linux anlaşılır. Laboratuvardan önce öğrencilerden bazı uygulamaları indirmeleri istenecek, laboratuvar saatinde hoca kurulumu adım adım gösterecek, öğrenciler de birlikte kuracaktır.

Kurulum adımları sırasında şu kavramlar konuşulacaktır:

- Önyükleyici (bootloader) nedir.
- Disk bölümlendirme (partitioning) nedir, nasıl ve neden yapılır.
- Sektör, silindir gibi disk kavramları.
- Dosya sistemi (file system) nedir, ne işe yarar.

**Soru:** Linux kurulunca bilgisayardaki Windows silinir mi? **Cevap:** Silinmez. Kurulum güvenli bir ortamda yapılır. Bilgisayarda zaten bir işletim sistemi vardır (Windows ya da Linux, fark etmez). Bunun üzerine bir emülatör yerleştirilir ve Linux o emülatörün içine kurulur. İstenirse aynı emülatörde yeni bir makine yaratılıp başka işletim sistemleri de kurulabilir. Hangilerinin kurulabileceği kullanılan emülatöre bağlıdır.

> **Ek bilgi (derste anlatılmadı):** Bu tür kurulumlarda kullanılan araçlar genellikle sanal makine (virtual machine) yazılımlarıdır. Bunlar, asıl işletim sistemi üzerinde çalışan ve kendi sanal diski, belleği ve işlemcisi olan ayrı bir bilgisayar gibi davranan bir ortam yaratır. Sanal makinenin diski, ana makinede yalnız bir dosya olarak durduğu için içindeki bölümlendirme ana diski etkilemez. Hocanın "emülatör" dediği araç büyük olasılıkla böyle bir sanal makine yazılımıdır.

### 3.2 Sonraki Uygulamalar

Sonraki haftalarda daha pratik konulara da girilir. Örneğin bir hafta Word ve Excel kullanımına ayrılabilir. Öğrenciler bu programları biliyor olsa da kaçırdıkları ayrıntılar olabilir. Algoritmalardan sonra programlamaya geçildiğinde bir IDE ya da bir derleyici (compiler) ile editör kullanabilmek gerekir. Bunların kullanımı da laboratuvarda gösterilir. İlerleyen haftalarda öğrencilere problemler verilip çözümlerini sisteme yüklemeleri istenecektir.

## 4. Kaynak Seçimi ve Çalışma İlkeleri

### 4.1 İnternet Kaynakları ve Akış Diyagramı

Bazı konularda internetteki herhangi bir kaynaktan bilgi edinmekte sakınca yoktur. Örneğin tarihçe ya da arama ve sıralama algoritmaları için internette arama yapılabilir.

Akış diyagramı için ise hoca internet kaynaklarına hiç bakılmamasını ister. Akış diyagramı yalnız bilgisayar mühendisliğinde kullanılan bir yapı değildir. İnşaat mühendisliğinde, elektronikte ve başka birçok alanda kullanılır. Her alanın bu yapıda kendine has bir kullanımı vardır: semboller, sembollerin ne anlama geldiği, okların nereden nasıl birleştiği alandan alana değişir.

> **Hocanın vurgusu:** Bu derste esas alınacak olan, derste anlatılan akış diyagramı gösterimidir. Başka kaynaklardan alınan farklı çizimler kafa karıştırır ve değerlendirmede ciddi sorun yaratır.

### 4.2 Programlama Kaynakları ve break, continue, goto

Programlamayla ilgili kaynaklara bakarken iki ölçüt önerilir. Birincisi, mümkünse üniversitelerin web sayfaları kullanılmalıdır. İkincisi, bu sayfaların bilgisayar mühendisliği bölümlerine ait olmasına dikkat edilmelidir.

Hoca bunun nedenini bir örnekle açıklar. C dilinde `break`, `continue` ve `goto` gibi ifadeler vardır. Bilgisayar mühendisleri olarak bu ifadelerin kullanılmaması gerektiğini söylerler. Bu ifadelerin dilde bulunmasının nedeni dili daha etkili ya da rahat kılmak değildir. Hocaya göre amaç, önceki kuşakta programlama yapan insanları bir sonraki kuşağa taşıyabilmektir. Program yazma pratiği açısından bu ifadeler kodda karmaşaya yol açar. Yine de internetteki birçok C kodunda bunlarla karşılaşılır. Bu kodları örnek alan öğrenci derste sorun yaşar.

> **Hocanın vurgusu:** `break`, `continue` ve `goto` bu derste kullanılmaz. Hoca bunu derslerde defalarca tekrar edeceğini söyler.

> **Ek bilgi (derste anlatılmadı):** Bu görüş, yapısal programlama (structured programming) anlayışına dayanır. Bu anlayışa göre bir program yalnız sıralı adımlar, seçim (if) ve döngü yapılarıyla kurulmalıdır. Programın herhangi bir yerine atlamayı sağlayan `goto` ve döngüyü ortada kesen ifadeler, programın akışını izlemeyi ve doğruluğunu göstermeyi zorlaştırır.

### 4.3 Ders Kitabı ve Not Tutma

Derste belirli bir kitap önerilmez (ekrandan, 00:50:00). Hoca, mevcut Türkçe bir kitabı yeterince net bulmadığını, ders notlarına ve derste konuşulanlara bağlı kalınmasını söyler. Dersler kaydedildiği için tekrar dinlenebilir. Slaytta web kaynakları kullanıldığında her zaman kaynak gösterilmesi istenir (ekrandan, 00:50:00).

Not tutma konusunda hoca şu uyarıyı yapar: Birinin ders sırasında tuttuğu not, o kişinin anladığı kadardır ve ders anlatımının yerini tutmaz. Başkasının notundan çalışan öğrenciye o notun hataları da bilgi olarak geçer. Hoca, geçmişte bir notun çoğaltılıp dağıtıldığını, sınavda bir algoritma sorulduğunda pek çok öğrencinin o nottaki yanlış cevabı yazdığını anlatır. Bu yüzden herkes kendi notunu kendisi tutmalıdır.

### 4.4 Bireysel Çalışma

Açıkça grup çalışması istenmedikçe yapılan her iş tek başına yapılmalıdır. Örneğin bir problem için akış diyagramı çizmeniz istendiğinde arkadaşlarınızla "şöyle mi yapsak, böyle mi yapsak" diye konuşabilirsiniz. Ama birinin çizdiği akışı başkasıyla paylaşması ya da internetten bulunan bir çözümü olduğu gibi kullanmak hem etik hem yönetmelik açısından sorundur.

## 5. Öğrenmeyi Öğrenmek

Dersin son kısmında hoca, yıllardır karşılaştığı bir sorundan söz eder: öğrencilerin kendi öğrenme süreçlerini tanımaya ihtiyacı vardır.

### 5.1 Amaçla Öğrenmek

Slayttaki başlık "Birey olarak öğrenirken, bir amacınız olmalı" şeklindedir (ekrandan, 02:55:00). Kendinize şu soruları sormalısınız:

- Neyi anlamaya çalışıyorum?
- Ne ile uzaklaşmak istiyorum?
- Hangi değerli bilgileri almaya çalışıyorum?

Belli bir amaçla öğrenildiğinde öğrenmeye daha çok dahil olunur ve öğrenilenler daha iyi hatırlanır. Hedefler için önemli olan şeyler belgelenmeli ve düzenlenmeli, bu birikim de sürekli güncellenmelidir. Bu cevapları bulmanın en net yolu soru sormaktır. Hoca, soru sorduğunuzda her zaman istediğiniz cevabı alamayabileceğinizi ama bunun eğitimin bir parçası olduğunu söyler.

### 5.2 Öğrenme Sürecini Anlamak

Slayttaki başlık "Öğrenme sürecini tam olarak anlamalısınız" şeklindedir (ekrandan, 03:00:00). Öğrenmeyi engelleyen ve motive eden şeyler anlaşılmalıdır:

- acı, endişe veya korku gibi zihinsel faktörler,
- yorgunluk gibi fiziksel faktörler,
- çevresel faktörler,
- sosyal faktörler,
- bu faktörlerin metodolojisi.

Kısaca öğrenmeyi öğrenmek gerekir.

Hoca örnekler verir. Sınava çalışırken sürekli "yapamayacak mıyım" diye endişeleniyorsanız bu zihinsel bir engeldir. Akşam çalışmaya karar verip her akşam yorgun oluyorsanız sabah çalışın. Kendinize ait bir oda yoksa ve ses sizi çok etkiliyorsa sessiz bir yer bulun ya da kendinizi çevreden soyutlamaya çalışın. Her faktörün sizin üzerinizdeki etkisinin farkına varıp ona göre önlem almalısınız.

## 6. Öğrenme Stilleri Testi

### 6.1 Testin Amacı ve Uygulanışı

Öğrenme stilleri, kişinin kendi öğrenme süreciyle ilgili farkındalık kazanmasını sağlar. Öğrenme bireysel bir yolculuktur. Bu farkındalıkla dönem boyunca ders dinlerken, arkadaşlarla ortak çalışırken ya da bireysel çalışırken doğru kaynak ve yöntem seçilebilir (ekrandan, 03:00:00).

Hoca bunun bir sınav ya da değerlendirme olmadığını, cevapların kendisini ilgilendirmediğini söyler. Şıklarda doğru ya da yanlış yoktur, yalnız size en uygun olan vardır. Her soru ekranda 10-15 saniye kalır. Öğrenci her soru için A, B ya da C'den birini not eder. Kararsız kalınan yerde "en çok hangisi" diye düşünülerek biri seçilir.

### 6.2 Sorular

Sorular hocanın sesli okuduğu biçimiyle (derste sözlü, 03:02:01 ile 03:05:26 arası) şöyledir. 12. ve 13. soruların metni ekrandan alınmıştır (ekrandan, 03:05:00).

1. Bir şey yapmayı öğrenirken en iyi şöyle öğrenirim: A) birisi bana gösterirken izlersem, B) birisi bana anlatırsa ve ben dinlersem, C) kendi kendime yapmaya çalışırsam.
2. Bir şeyi okurken: A) okuduklarımı gözümün önüne getiririm, B) yüksek sesle okur ya da sözcüklerin seslerini kafamın içinde duyarım, C) genellikle kıpır kıpır olurum ve okuduklarımı hissetmeye çalışırım.
3. Bir yer tarif etmem istenirse: A) yeri gözümün önüne getiririm ya da çizerek tarif ederim, B) sözle tarif etmekte güçlük çekmem, C) elimle ya da bütün bedenimle hareket ederek tarif ederim.
4. Bir sözcüğün nasıl yazılacağından emin değilsem: A) yazıp doğru görünüp görünmediğine bakarım, B) söyleyerek doğru olup olmadığına bakarım, C) yazıp bana iyi gelip gelmediğine bakarım.
5. Yazı yazarken: A) harflerin ve sözcüklerin düzenli görünmesine dikkat ederim, B) harfleri ve sözcükleri kendi kendime söylerim, C) kalemimi bastırıp yazının akışını hissetmeye çalışırım.
6. Bir listeyi aklımda tutmam gerekirse: A) listeyi yazarım, B) kendi kendime tekrar ederim, C) hareket ederken parmaklarımla listedeki maddeleri ilişkilendiririm.
7. Tercih ettiğim öğretmenler: A) ders anlatırken tahta ya da tepegöz kullananlar, B) etkili bir şekilde ders anlatanlar, C) hareketli katılımımızı sağlayanlar.
8. Konsantre olmakta güçlük çektiğim durumlar: A) sınıfta çok fazla kalabalık ve hareket varsa, B) sınıfta çok fazla gürültü varsa, C) uzun süre hareketsiz oturmam istenirse.
9. Problem çözerken: A) problemi görebilmek için şekil çizerim, B) problemi kendi kendime seslendiririm, C) hareket eder ya da nesneleri hareket ettirerek düşünürüm.
10. Bir şey inşa etmek için yönergeler verildiğinde: A) sessizce okur ve parçaların nasıl birleşeceğini gözümün önüne getiririm, B) yönergeleri yüksek sesle okur, parçaları birleştirirken kendi kendime konuşurum, C) önce parçaları birleştirir, sonra yönergeleri okurum.
11. Bir şeyi beklerken kendimi meşgul etmek için: A) etrafa bakınırım, başkalarını izler ya da okurum, B) başkalarıyla konuşur ya da onları dinlerim, C) etrafta dolaşır, elimdeki bir şeyle oynar ya da ayaklarımı sallarım.
12. Eğer sözlü olarak birisine bir şeyi tarif etmem gerekirse: A) kısaca anlatırım çünkü uzun konuşmayı sevmem, B) çok detaylı anlatırım çünkü konuşmayı severim, C) konuşurken hareketlerle de desteklerim.
13. Birisi bana sözlü olarak bir şeyi anlatırken: A) söylediklerini gözümün önüne getirmeye çalışırım, B) dinlemekten hoşlanırım ama kesip ben konuşmak isterim, C) eğer anlatımı detaylı ve uzun olursa sıkılırım.
14. İsim hatırlamaya çalışırken: A) yüzleri hatırlarım ama isimleri unuturum, B) isimleri hatırlarım ama yüzleri unuturum, C) isim ya da yüz hatırlamam ama o kişiyi tanıdığım durumu hatırlarım.

### 6.3 Puanlama ve Sonuç

Test bitince kaç tane A, kaç tane B ve kaç tane C seçildiği sayılır. Toplam her zaman 14'tür. Hoca örnek dağılım olarak 6, 4, 4 verir; "6, 5, 4" deyince de bunun 15 ettiğini söyleyip düzeltir.

> **Ders sonrası not:** Hoca örneklerden birini "5, 4, 4" diye verdi; bunun toplamı 13'tür, 14 soruluk testte olamaz. Örneğin 5, 5, 4 ya da 6, 4, 4 olmalıdır.

Sonuç slaytı şöyledir (ekrandan, 03:10:00):

- **A: Görsel ağırlıklı öğrenme stili.** Görerek ve okuyarak öğrenmeyi tercih ederler. Kendi kendine okuyarak öğrenirler. Renkli şeyleri, grafik ve haritaları tercih ederler.
- **B: İşitsel ağırlıklı öğrenme stili.** İşiterek, dinleyerek ve tartışarak öğrenmeyi tercih ederler.
- **C: Dokunsal / kinestetik ağırlıklı öğrenme stili.** Bazılarının aklında hareket enerjisi daha iyi kalır. Bu kişiler öğrenecekleri şeylerle fiziksel temas kurarak, yaparak öğrenirler.

### 6.4 Bu Derse Uygulanması

Hoca stillerin bu derse nasıl yansıyacağını örnekler:

- Dokunsal ağırlıklı öğrenci, akış diyagramlarına gelindiğinde kendine tekrar tekrar problem kurup akış çizmelidir. Hoca bunun aslında herkes için geçerli olduğunu ekler.
- İşitsel ağırlıklı öğrenci, kaydedilen dersleri tekrar tekrar dinlemelidir.
- Görsel ağırlıklı öğrenci, bir yandan okumalı, bir yandan da slaytları izlemelidir.

Bir kişi yalnız tek bir stile sahip değildir. Stillerin hepsinden farklı oranlarda beslenebilir. Hoca, testin yurt dışında geliştirildiğini, bir öğretim üyesi tarafından Türkçeye çevrilip denendiğini, bu yüzden Türkçe uygunluğu ve güvenilirliği konusunda soru işaretleri olabileceğini söyler. Amaç yalnız bir farkındalık yaratmaktır.

## Dersin Toparlaması

Bu ilk derste dersin yol haritası çizildi. Ders tarihçe ve sayı sistemleriyle başlayacak, bilgisayarın her şeyi 0 ve 1 ile nasıl gösterdiğini inceleyecek, ardından dersin merkezindeki algoritma kavramına geçecektir. Algoritma, bir işin nasıl yapılacağının tarifidir ve bu derste akış diyagramlarıyla ifade edilecektir. Akış diyagramlarından sonra diziler ve stringler, C dilinde uygulama, arama ve sıralama algoritmaları gelecektir. Laboratuvarlarda ise işletim sistemi kurulumuyla başlayan pratik uygulamalar yapılacaktır. Akış diyagramında yalnız derste anlatılan gösterime bağlı kalmak ve C'de `break`, `continue`, `goto` kullanmamak dersin baştan konan iki ilkesidir.

Dersin ikinci yarısında öğrencinin kendi öğrenme sürecini tanıması üzerinde duruldu. Amaçla öğrenmek, engelleyici etkenleri fark etmek ve kendi öğrenme stiline uygun çalışmak dönem boyunca kullanılacak çalışma ilkeleridir. Konu sırasına göre dersin ilk akademik konuları tarihçe ve sayı sistemleridir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
