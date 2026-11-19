# Ders 26 Genişletilmiş Notu: Proje Soru-Cevap Oturumu: Dosya İşlemleri, Başlık Dosyaları ve Tasarım Kararları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Niteliği ve Proje Bağlamı
- 2. Kullanıcı Girdileri, Doğrulama ve Parametre Dosyası
- 3. fopen Sonrasında NULL Kontrolü
- 4. Sekmeyle Ayrılmış Metin Dosyası ve Excel
- 5. Dinamik Bellek: malloc Ne Zaman Kullanılır
- 6. Başlık Dosyaları ve #include
- 7. Kayıt Silme ve Güncelleme: Geçici Dosya
- 8. Gereksinimlerin Netleştirilmesi
- 9. Kimlik (ID) Tasarımı, İlişki Dosyaları ve Log
- 10. Dosyanın Başına Dönmek: fseek
- 11. Adlarda Boşluk
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Niteliği ve Proje Bağlamı

Bu oturum bir konu anlatımı değildir. Hocanın açılış slaytında ders müfredatının önceki hafta tamamlandığı, bu hafta soru gelirse onlar üzerinden konuşulacağı, gelmezse dersin erken bitirileceği yazar (ekrandan, 00:05:00). Oturum boyunca öğrenciler dönem projesiyle ilgili sorularını sohbet penceresinden ya da sesli olarak sordu. Hoca bu soruları cevaplarken C'de dosya işlemleri, başlık dosyaları, dinamik bellek ve yazılım tasarımıyla ilgili genel ilkelere değindi. Bu not o ilkeleri dersteki sırayla toplar.

Soruların çoğu, ekranda açılan proje metnine dayanır. Proje, öğrenci, ders ve öğretim üyesi bilgilerini dosyalarda tutan menülü bir kayıt sistemidir. Proje metninde ekranda okunan teknik kurallar şunlardır (ekrandan, 00:10:00):

- Programlarda statik ve global değişken kullanımı yasaktır.
- Her türlü bellek tahsisi dinamik bellek yönetimi fonksiyonlarıyla yapılmalıdır.
- Her dosyadaki nesne için uygun `struct` tanımlanmalıdır.
- Oluşturulacak dosyalar metin (text) biçiminde olmalıdır.
- İşlemler bir menüyle sunulmalı, her işlem için bir fonksiyon tasarlanmalı; benzer mantıkla çalışan fonksiyonlarda tekrardan kaçınmak için fonksiyon işaretçisi (function pointer) kullanılmalıdır.

İstenen işlemler de ekranda listelenir (ekrandan, 00:10:00 ve 00:30:00):

- Her bir dosya için ekle, sil ve güncelle işlemlerini fonksiyonlarda yapmak.
- Öğrenci, ders ve öğretim üyesi için ders ekleme, silme ve güncelleme işlemlerini yapmak.
- ID'si verilen öğretim üyesinin verdiği dersleri listelemek.
- Ders kodu verilen bir derse kayıtlı bütün öğrencileri listelemek.
- Numarası verilen bir öğrencinin aldığı bütün dersleri listelemek.
- ID'si verilen öğretim üyesinin verdiği bir dersin sınıf listesini `DERSKODU_SINIFLISTESI.txt` dosyasına yazmak.

Ayrıca hangi öğrencinin hangi dersi aldığı `<öğrenciNO-DersKodu>` eşleştirmesiyle bir dosyada saklanır; her eşleştirmenin 1'den başlayan, otomatik artan benzersiz bir ID'si, derse kayıt durumu (KAYITLI ya da BIRAKTI) ve kayıt tarihi vardır. Öğrenci derse kaydolurken kullanıcıdan alınan en çok ders sayısı ve en çok kredi değerine ulaşılınca ders ekleme engellenir (ekrandan, 00:10:00).

## 2. Kullanıcı Girdileri, Doğrulama ve Parametre Dosyası

İlk soru, en çok ders sayısı ve en çok kredinin kullanıcıdan alınmasıyla ilgiliydi: program her çalıştığında kullanıcı farklı değerler girebilir; bu tutarsızlık yaratmaz mı?

Hocanın cevabı, bu parametrelerin zaten değişebilir olduğudur. Üniversiteler birkaç yılda bir müfredatta değişiklik yapar; bir dersin dönemi ve kredisi değişebilir, bazen bir süre birden fazla müfredat aynı anda yürürlükte olur. Bu yüzden değerin kullanıcıdan alınması bir tutarsızlık değildir.

Hoca bunu somut senaryolarla destekledi. Proje metni programın hangi tür bir program için yazıldığını belirtmez. Bir sürekli eğitim merkezi programında yalnız üç ya da dört ders olabilir; bir tezsiz yüksek lisans programında on ders ve bir dönem projesi alınır, her ders üç krediyle toplam kırk kredi civarında bir sınır çıkar. Kullanıcı programın bir kopyasını lisans programı için bir dizinde, başka bir kopyasını tezsiz yüksek lisans için başka bir dizinde, farklı ayarlarla çalıştırabilir. Hocaya göre bunlar tutarsızlık değil, makul ve mantıklı senaryolardır.

Değerlerin her açılışta yeniden sorulmaması istenirse bunlar ayrı bir dosyaya, bir tür parametre dosyasına kaydedilebilir. Kullanıcı parametre dosyasını değiştirmek istemedikçe program her açıldığında ve kaldığı yerden devam ettiğinde bu parametrelerle çalışır.

Doğrulama için hoca şu kontrolleri önerdi: negatif kredi girilemez, sıfır ders sayısı girilemez. Çok küçük değerlere bir alt sınır konabilir; örneğin sekiz dönemlik bir lisans programında toplam iki üç ders anlamsızdır. Ama tek derslik bir sürekli eğitim programı bile olabileceği için alt sınırın çok katı olmaması gerekir.

## 3. fopen Sonrasında NULL Kontrolü

Bir öğrenci, dosyayı belirli bir kiple açarken `NULL` kontrolü yapmanın gerekip gerekmediğini sordu; dosya yoksa zaten oluşturulacağı için kontrolün gereksiz olduğunu düşünüyordu. <!-- BELİRSİZ: sorudaki açma kipi altyazıda bozuk ("ağır tığla açığımızda", "Atent ve okumak"); büyük olasılıkla a+ (ekleme ve okuma) kipi kastediliyor. -->

Hoca önce "gerekmez, dosya yoksa orada açılır" dedi, ama hemen küçük de olsa bir olasılık bulunduğunu ekledi: dosyayı açma yetkiniz olmayabilir, kendi bilgisayarınızda çalışmıyor olabilirsiniz ya da dosya adında Türkçe veya garip bir karakter kullandığınız için dosya oluşturulamamış olabilir. Hoca bunu "Murphy kuralları her an devreye girebiliyor" diye özetledi ve kontrolün her durumda yapılmasını önerdi: `NULL` kontrolü yapmanın hiçbir zararı yoktur. Bu yalnız proje için değil, genel amaçlı her program için geçerlidir.

> **Hocanın vurgusu:** Birçok şey ters gidebilir; dosya açıldıktan sonra `NULL` kontrolünü yine de yapın.

## 4. Sekmeyle Ayrılmış Metin Dosyası ve Excel

Bir öğrenci, istenen fonksiyonların yalnız ekrana yazdırıp yazdırmayacağını sordu. Hoca, söz konusu olanın ekrana yazdırmak olduğunu, bir Excel dosyasına aktarma beklenmediğini söyledi. Doğrudan Excel biçiminde yazmayı öğrenciler bilmiyordur; bunun için o biçimin ne olduğunu araştırmak gerekir.

Buna karşın pratik bir yol vardır: veriyi metin biçiminde kaydedip her alanın arasına `\t` (tab, sekme) karakteri koymak. Böyle bir dosya Excel'de bir iki basit adımla tablo olarak açılır.

Hoca bunu ekran paylaşarak gösterdi. Not Defteri'nde alanları sekmeyle ayrılmış birkaç satır yazdı ve kaydetti. <!-- BELİRSİZ: yazılan örnek değerler altyazıda bozuk ("Kırk dört", "Şahıs 9"); bu anın karesi yok. --> Ardından Excel'de dosya açma penceresinde "bütün dosyalar" seçip metin dosyasını açtı ve "sınırlandırılmış" seçeneğini işaretledi. Excel karakter kodlamasını sordu. Hoca Windows altında çalıştığı için Türkçe Windows kodlamasının Türkçe karakterlerde en doğru sonucu vereceğini düşündü, ama önizlemede Türkçe karakterlerin bozulduğunu gördü ve başka kodlamaları (Türkçe ISO, UTF-8) denedi; Türkçe karakterlerin görünümü seçilen kodlamaya göre değişti. <!-- BELİRSİZ: hangi kodlamanın doğru sonucu verdiği altyazıdan net çıkmıyor ("UTF-8 böyleymiş. Bu denk geldi."); bu anın karesi yok. --> Sonraki adımda ayırıcı olarak sekme seçildi; başka ayırıcı karakterler de seçilebilir. Excel bir sütunun sayı yerine metin olarak alınması gibi seçenekler de sunar. İş bittikten sonra dosyanın Excel biçiminde kaydedilmesi, üzerinde Excel ile çalışılacaksa daha doğrudur.

Tersi de mümkündür: bir Excel tablosu "farklı kaydet" ile metin olarak kaydedilebilir. Hocanın gösterdiği biçimde Excel alanları birbirinden noktalı virgülle ayırır. Hoca bunu ileride çıkabilecek küçük dönüşüm ihtiyaçları için anlattı.

## 5. Dinamik Bellek: malloc Ne Zaman Kullanılır

Soru: proje metninde bellek tahsisinin dinamik yapılması isteniyor; bu her türlü değişken için mi geçerli?

Hocanın cevabı: hayır, her değişken için değil. Yalnız dinamik bellek ayırmak gerektiğinde geçerlidir. Projede n tane ders, n tane öğrenci ve n tane öğrenci-ders ilişkisi olacaktır; bunların sayısı önceden bilinmediği için `malloc` ile yönetilmeleri en doğrusudur. Programdan çıkılacağı zaman da ayrılan her şey sırasıyla `free` edilir, sonra çıkılır. Döngü sayacı gibi sıradan yerel değişkenler için `malloc` gerekmez.

## 6. Başlık Dosyaları ve #include

### 6.1 #include biçimleri

Soru: bir C dosyasında yazılan tanımları başka bir C dosyasında kullanmak için yalnız `#include` yapmak yeterli mi?

Hocanın cevabı: evet, yeterlidir; ama dosyanın bulunabilmesi gerekir. İki ekleme yöntemi vardır:

- Köşeli parantez (`#include <...>`): yalnız sistem kütüphane dosyaları için kullanılır.
- Tırnak (`#include "..."`): herhangi bir konumdaki dosya için kullanılır. Bu konum genelde `.c` dosyalarıyla aynı dizindir.

Dosya bulunamazsa onu proje dizinine kopyalamak denenebilir. Hoca, farklı IDE'lerin bu konuda farklı davranabileceğini ekledi. Bazı IDE'lerde proje ayarlarından başka bir dizindeki dosya da projeye eklenebilir.

### 6.2 Canlı deneme: yapı tanımlarını bilgi.h dosyasına taşımak

Hoca bir deneme yaptı. Dev-C++ 4'te önceki dersten kalan rastgele erişim örneğinin projesini açtı. Bu program dört kişinin bilgilerini kullanıcıdan alıp `records.dat` ikili dosyasına `fwrite` ile yazar. Kodun ekranda görülen kısmı şöyledir (ekrandan, 00:20:00 ve 00:25:00; döngünün kapanışından sonrası ekranda görünmüyor, bu yüzden kod parçadır ve derlenmedi):

```c
#include <stdio.h>
#include <stdlib.h>
#include "bilgi.h"

int main(int argc, char *argv[]){
   int j; FILE *fp; unsigned int val;
   PERSONALSTAT ps2[4];
   fp=fopen("records.dat", "wb");
   for(j=0; j<4; j++){
       printf("Enter name of the %d-th person:\n", j+1);
       scanf("%s", ps2[j].ps_name);
       printf("Enter tcno of the %d-th person:\n", j+1);
       scanf("%s", ps2[j].ps_tcno);
       printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
       // NOT ALLOWED: scanf("%u", &ps2[j].ps_birth_date.day);
       scanf("%u", &val); ps2[j].ps_birth_date.day=val;
       printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
       scanf("%u", &val); ps2[j].ps_birth_date.month=val;
       printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
       scanf("%u", &val); ps2[j].ps_birth_date.year=val;
       fwrite(&ps2[j], sizeof(PERSONALSTAT), 1, fp);
       //OR: char *stz="\n"; fwrite(stz, 1, 1, fp);
   }
   /* ... (ekranda görünmüyor) */
```

Hoca, yapı tanımlarının (`DATE` ve `PERSONALSTAT`) `Untitled1.c` dosyasından kesilip yeni oluşturulan ve aynı dizine kaydedilen `bilgi.h` dosyasına yapıştırılmasını istedi. Bu tanımlar ders slaytındaki rastgele erişim örneğinin başındaki tanımlardır (ekrandan, 00:40:00):

```c
#include <stdio.h>
typedef struct {
      unsigned int day : 5;
      unsigned int month : 4;
      unsigned int year : 11;
} DATE;
typedef struct {
    char ps_name[19], ps_tcno[11];
    DATE ps_birth_date;
} PERSONALSTAT;
//to be continued in the next slide
```

Sonra kodun başına `#include "bilgi.h"` eklendi ve proje derlendi. Derleyici penceresinde "Project 1 compiled successfully" mesajı görülür (ekrandan, 00:20:00). Hoca, bu ekleme yapılmasaydı `PERSONALSTAT` türü tanınmayacağı için derleme hatası alınacağını belirtti.

> **Ek bilgi (derste anlatılmadı):** Koddaki "NOT ALLOWED" yorumunun nedeni, C'de bir bit alanının adresinin alınamamasıdır; `scanf` ise değeri yazacağı yerin adresini ister. Bu yüzden değer önce sıradan bir `unsigned int` değişkene (`val`) okunur, sonra bit alanına atanır. Yorumdaki satır gcc ile derlenmeye çalışıldığında "cannot take address of bit-field 'day'" hatası alınır (ajan tarafından denendi).

### 6.3 Birlikte teslim ve taşınabilirlik

Hoca, kaynak kod paylaşılırken farklı kütüphanelerden toplanan bütün dosyaların birlikte verilmesi gerektiğini söyledi. Örnekte `Untitled1.c` ve `bilgi.h` aynı dizindedir; ikisi birlikte sıkıştırılıp tek dosya halinde verilmelidir. `bilgi.h` başka bir dizinde, örneğin kişisel bir kod kitaplığı dizininde durur ve bağlantı IDE'nin proje ayarlarından kurulursa, kod başka bir bilgisayarda derlenmeyebilir. Bu yüzden ya her şey tek dosyada yazılmalı ya da eklenen dosyalar aynı dizine alınıp birlikte verilmelidir.

## 7. Kayıt Silme ve Güncelleme: Geçici Dosya

### 7.1 Soru: geçici dosyadan başka bir çözüm var mı?

Bir öğrenci, dosyadaki kayıtları silmek ve güncellemek için ek bir geçici dosya kullanmaktan başka bir çözüm olup olmadığını sordu; imlecin (dosya konum göstergesinin) davranışının işletim sistemine göre değişebileceğini düşünüyordu. Hoca bu gözleme katıldı ve geçici dosya kullanmanın güzel bir çözüm olduğunu söyledi. Projede verinin illa aynı dosyaya yazılması gibi bir kısıt yoktur; düzgün çalışan yol seçilmelidir.

Hoca bu soru üzerinden genel bir uyarı yaptı: öğrencilerin kimi farklı Linux dağıtımlarında, kimi Windows'ta, kimi Mac'te kod yazıyor; ama değerlendirmenin hangi sistemde yapılacağı belli değildir. Bu yüzden kod taşınabilir olmalıdır.

### 7.2 Soru: konum göstergesiyle yerinde değişiklik mi, geçici dosya mı?

Aynı konu daha sonra yeniden soruldu: C, konum göstergesini değiştirip istenen konuma gelerek veri eklemeye izin veriyor; bu mu daha kolay, geçici dosya mı? Hoca, geçici dosyanın en taşınabilir yol olduğunu söyledi. Kolaylık kişiden kişiye değişse de kendisi geçici dosyayla çalışmayı daha kolay bulur. Konum göstergesini oynatarak yerinde değişiklik yapmanın taşınabilirliği daha düşüktür; kod bir bilgisayar sisteminde çalışıp başka birinde çalışmayabilir. Projede oluşturulacak dosyalar çok büyük olmayacağı için geçici dosyanın işlem süresine etkisi önemli değildir.

> **Hocanın vurgusu:** Kolay yol ve taşınabilir yol geçici dosya kullanmaktır.

> **Ek bilgi (derste anlatılmadı):** Geçici dosya yönteminde asıl dosya okuma kipinde, geçici dosya yazma kipinde açılır; her kayıt okunur, silinecek kayıt atlanır, güncellenecek kayıt değiştirilerek, diğerleri olduğu gibi geçici dosyaya yazılır. İki dosya kapatıldıktan sonra standart kütüphanedeki `remove` ile asıl dosya silinir ve `rename` ile geçici dosyaya asıl dosyanın adı verilir. Bu iki fonksiyon `stdio.h` içindedir.

## 8. Gereksinimlerin Netleştirilmesi

Bir öğrencinin isterlerdeki bir ifadeyi anlayamaması üzerine hoca proje metnindeki maddeleri açıkladı. Her dosya (öğrenci, ders, öğretim üyesi) için ekleme, silme ve güncelleme vardır. Bir dersin kodu ve adı, bir öğretim üyesinin adı ve unvanı güncellenebilir. Öğrenci açısından ise derse ekleme ve dersten silme vardır; "öğrenci için ders güncelleme" diye ayrı bir işlem yoktur. Hoca, metnin bir sayfaya sığması için maddelerin kompakt yazıldığını, bu yüzden bazı ifadelerin her duruma tam uymayabileceğini söyledi.

Ardından genel bir noktaya geçti: normal yazılım geliştirme sürecinde iletişim çok önemlidir. Projenin isterleri belirlenirken müşterinin konu uzmanıyla konuşmak, gereksinimleri netleştirmek kritik bir etkinliktir. Hoca bunu binanın temelini sağlam atmaya benzetti: yazılımda temel, gereksinimlerin net belirlenmesidir. Gereksinimler karşılıklı sorularla ve belirli süreç adımlarıyla belirlenir, ayrıntılandırılır ve işlenir. Hoca bu konuların sistem analizi ve yazılım mühendisliği derslerinde ayrıntılı ele alınacağını söyledi.

## 9. Kimlik (ID) Tasarımı, İlişki Dosyaları ve Log

### 9.1 Ders kodu kimlik olarak kullanılırsa

Bir öğrenci, ders kodunun dersin kimliği (ID) yerine geçtiğini, bu yüzden ilişki dosyasında öğrencinin aldığı dersin yanına ders kodunun yazılacağını belirtti. Ders kodu güncellenebiliyorsa her yerde değiştirilmesi gerekecekti; bunun bilerek mi istendiğini, yoksa farklı bir ID yöntemi kullanılıp kullanılamayacağını sordu.

Hoca, öğrencilerin projeyi farklı kapsamlarda yapabileceğini, zamanı olanların ek özellikler eklemek isteyebileceğini söyledi. Ders bilgisi güncellendiğinde, o bilgiyi kullanan diğer dosyalarda da gerekli düzenleme yapılmalıdır. Aynı anda iki ayrı müfredatın yürüyebileceği bir senaryo düşünülürse bu ekstra menü seçenekleri, ekstra dosyalar ve ekstra ilişkiler gerektirir; hoca bu işlere girilmemesini önerdi. En mantıklısı, ilişkinin geçtiği her dosyada kod değişikliğini tekrarlamaktır.

### 9.2 Yapılara özellik eklemek

Sohbet penceresinden gelen bir soru, ek özellikler için tanımlı yapıların değiştirilmesinin sorun olup olmadığıydı. Hoca, ekleme biçiminde yapılırsa sorun olmayacağını söyledi. Projenin test edilmesi sırasında yapıdaki zıt değişiklikler değerlendirmeyi zorlaştırır, hatta eksik içerik gibi görülebilir. Bu yüzden değişiklikler temel isterlerin üstüne konan ekler olarak düşünülmeli, var olan alanlar silinmemelidir.

### 9.3 Log dosyası ve kod değişikliği

Bir öğrenci, ders kodunu ID olarak kullandıkları için kodu hem kayıt (log) dosyasında hem öğrenci listesinde hem öğretim üyesi dosyasında tuttuklarını söyledi. Hoca loga başka bir gözle bakılmasını önerdi: log, bir şeyin geçmişteki ayrıntılı ayak izidir. Bir dersin kodu değişmişse logdaki eski kayıtlar eski haliyle kalmalıdır. Loga "şu dersin kodu şu şekilde değişti" diye bir satır eklenir; bundan sonraki kayıtlar yeni kodla yazılır.

Öğrenci bunun bir sorun doğurduğunu belirtti: öğrencinin aldığı ders sayısını tutan ayrı bir dosya yoktur, bu yüzden ders sayısı sınırını denetlemek için kayıtlar sayılmaktadır. Hoca, kendisi olsa bu amaçla ayrı bir dosya tutacağını, bir öğrencinin o ana kadar aldığı dersleri log dosyasından çıkarmak yerine ayrı bir dosyada saklayacağını söyledi. Öğrenci "log" derken aslında derse kayıt (enrollment) dosyasını kastettiğini sonradan açıkladı.

### 9.4 Otomatik artan ID

Başka bir öğrenci, derslere otomatik artan (auto-increment) bir ID verip ders kodunu dersin adı gibi yalnız bir bilgi alanı olarak tutmanın, ilişki dosyasında kodu kullanmamanın uygun olup olmadığını sordu. Hoca "olur" dedi, ama bir koşulla: böyle yapılan her şey raporda mutlaka belirtilmelidir. Okuyan kişi "burada ne yapılmış" diye kodu çözmeye çalışmak zorunda kalmamalıdır.

> **Hocanın vurgusu:** Verdiğiniz ekstra kararları ve yaptığınız değişiklikleri mutlaka raporunuzda belirtin.

## 10. Dosyanın Başına Dönmek: fseek

### 10.1 Soru ve ilk cevap

Bir öğrenci, `while (!feof(...))` döngüsüyle dosyanın sonuna gelindikten sonra başa dönmek için dosyayı kapatıp yeniden açmanın gerekip gerekmediğini sordu. Hoca gerekmediğini, `fseek` ile devam edilebileceğini söyledi: `fseek(fp, 0, SEEK_SET)` dosyanın başından 0. bayt konumuna gel demektir; kapatıp açmaya gerek yoktur.

Hoca ardından bir terslik olmasın diye ders notlarına baktı. Önce `fseek`'in yalnız ikili (binary) kipte geçerli olduğunu hatırlar gibi oldu ve öğrenci metin kipinde çalıştığı için bu durumda kapatıp açmanın pratik bir çözüm olabileceğini söyledi.

### 10.2 Ders notlarından doğrulama

Ders slaytlarındaki `fseek` anlatımı şöyledir (ekrandan, 00:45:00):

- Örnek: `stat = fseek(fp, 10, SEEK_SET);` dosya konum göstergesini akışın 10. karakterine taşır; bir sonraki okunacak ya da yazılacak karakter bu olur.
- Akışlar diziler gibi 0. konumdan başlar; bu yüzden 10. karakter aslında akıştaki 11. karakterdir.
- `fseek()` istek geçerliyse 0, değilse sıfırdan farklı bir değer döndürür. Bunun birçok nedeni olabilir; örneğin `fp` salt okuma için açılmışsa `stat = fseek(fp, 1, SEEK_END)` geçersizdir, çünkü konum göstergesini dosya sonunun ötesine taşımaya çalışır.
- Salt okunur dosyalarda `SEEK_END` kullanılıyorsa ofset 0'a eşit ya da 0'dan küçük olmalıdır.
- Benzer biçimde `SEEK_SET` kullanılıyorsa ofset 0'a eşit ya da 0'dan büyük olmalıdır.
- Konum göstergesini dosyanın dışına itmeyin.

Hoca `fseek`'in parametre açıklamasını okuyunca kendini düzeltti: `fseek` metin dosyalarında da kullanılabilir. İkili kipte ofset parametresi bayt sayısıdır. Metin kipinde ise ofset ya 0 olur ya da `ftell`'in döndürdüğü bir konum olur. Yani metin dosyasında da `fseek(fp, 0, SEEK_SET)` ile başa dönmek ve `ftell` ile önceden kaydedilmiş bir yere gitmek mümkündür; kapatıp açmaya gerek yoktur. <!-- BELİRSİZ: hocanın bu cevaba eklediği bir ifade altyazıda "Karakitap, evet karakitap" diye bozuk geçiyor; anlamı çıkarılamadı. -->

> **Ek bilgi (derste anlatılmadı):** Standart kütüphanedeki `rewind(fp)` fonksiyonu da konum göstergesini dosyanın başına alır; `fseek(fp, 0L, SEEK_SET)` çağrısına denktir, ayrıca akışın hata göstergesini temizler. `feof` ile döngü kurulduğunda dosya sonu göstergesi de `fseek` ya da `rewind` çağrısıyla temizlenir.

## 11. Adlarda Boşluk

Sohbet penceresinden gelen son teknik soru, adlarda boşluk yerine alt çizgi (underscore) kullanmanın sorun olup olmadığıydı. Hoca boşluk kullanılmasını istedi: iki adı olan biri mutlaka olacaktır ve bu durum çözülmelidir. Hiç çözülemezse alt çizgi son çaredir, ama hoca bu fikirden hoşlanmadığını söyledi.

Hoca boşluk sorununun nasıl aşılabileceğine dair iki yol gösterdi:

- Kayıt yapısı (`struct`) kullanılıyorsa, örneğin ad için 20, soyad için 20 karakterlik sabit uzunluklu alanlar tanımlanırsa boşluk sorun çıkarmaz; iki kelimelik bir ad alan boyutuna kadar tek alan olarak okunur. Hoca alan boyutunun 20 yerine ikinin kuvveti olarak 32 seçilmesini önerdi.
- Metin kipinde çalışılıyorsa okuma boşluk görene kadar değil, satır satır yapılırsa boşluklar ayrı bir kayıt bilgisi olarak ele alınmaz.

Arka planda boşlukları alt çizgiyle kaydedip dosyadan yükledikten sonra ekranda alt çizgileri boşluğa çevirmek de kabul edilir, ama hocaya göre buna gerek olmayacaktır.

> **Ek bilgi (derste anlatılmadı):** `scanf` ya da `fscanf` ile `%s` biçimi okumayı ilk boşlukta keser; bu yüzden "iki kelimelik ad" iki ayrı alan gibi okunur. Satırın tamamını okumak için `fgets` kullanılır; `fgets` satır sonundaki `\n` karakterini de diziye aldığı için genellikle bu karakter sonradan silinir. Alanlar sekmeyle ayrılmışsa `fscanf` ile `%[^\t]` gibi bir tarama kümesi de kullanılabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:38:07): `while (!feof(fp))` ile bir metin dosyasının sonuna kadar okunduktan sonra dosyanın başına dönmek için dosyayı kapatıp yeniden açmak gerekir mi?

> **Çözüm:** Gerekmez. `fseek(fp, 0, SEEK_SET)` konum göstergesini dosyanın başından 0. bayta taşır. Metin kipinde de geçerlidir; metin kipinde ofset ya 0 ya da `ftell`'den dönen bir değer olmalıdır (derste ders notlarından doğrulandı, 00:41:36).

**Soru 2** (derste sözlü, 00:15:13): Projede bellek tahsisinin dinamik yapılması isteniyor. Bu, programdaki her değişken için `malloc` kullanmak anlamına mı gelir?

> **Çözüm:** Hayır. `malloc` yalnız dinamik bellek gerektiğinde kullanılır; projede sayısı önceden bilinmeyen dersler, öğrenciler ve öğrenci-ders ilişkileri `malloc` ile yönetilir, programdan çıkarken hepsi sırasıyla `free` edilir.

**Soru 3** (derste sözlü, 00:15:57): Bir dosyada yazılan tanımları başka bir C dosyasında kullanmak için `#include` yeterli mi? `#include <...>` ile `#include "..."` arasındaki fark nedir?

> **Çözüm:** Yeterlidir, yeter ki dosya bulunabilsin. Köşeli parantez sistem kütüphane dosyaları içindir; tırnak kullanıcının kendi dosyaları içindir ve dosya genelde `.c` dosyasıyla aynı dizinde aranır. Derste yapı tanımları `bilgi.h` dosyasına taşınıp `#include "bilgi.h"` ile eklendi ve proje derlendi (ekrandan, 00:20:00).

**Soru 4** (derste sözlü, 00:19:01 ve 00:26:41): Dosyadaki bir kaydı silmek ya da güncellemek için geçici dosya kullanmak mı, konum göstergesini oynatıp yerinde değiştirmek mi daha uygundur?

> **Çözüm:** Hocanın önerisi geçici dosyadır: kolay ve taşınabilirdir, küçük dosyalarda süre maliyeti önemsizdir. Konum göstergesiyle yerinde değişiklik mümkündür ama taşınabilirliği daha düşüktür.

**Soru 5** (derste sözlü, 00:46:41): Adlarda boşluk yerine alt çizgi kullanmak gerekir mi?

> **Çözüm:** Önerilmez; boşluk desteklenmelidir. Sabit uzunluklu yapı alanları (örneğin 32 karakter) ya da metin kipinde satır satır okuma ile boşluklu adlar sorunsuz saklanır. Alt çizgiyle saklayıp ekranda boşluğa çevirmek kabul edilir ama gerekmez.

**Soru 6** (ekrandan, 00:20:00 ve 00:25:00): Derste gösterilen kodda `scanf("%u", &ps2[j].ps_birth_date.day);` satırı neden "NOT ALLOWED" diye yoruma alınmış ve yerine ne yazılmıştır?

> **Çözüm (derste verilmedi):** `day` bir bit alanıdır (`unsigned int day : 5;`) ve C'de bir bit alanının adresi alınamaz; `scanf` ise adres ister. Bu yüzden değer önce `val` adlı sıradan bir `unsigned int` değişkene okunur, sonra `ps2[j].ps_birth_date.day = val;` ile atanır. Yorumdaki satır gcc ile derlenmeye çalışıldığında "cannot take address of bit-field" hatası verir (ajan tarafından denendi).

## Dersin Toparlaması

Bu oturumda yeni konu işlenmedi; müfredat önceki hafta tamamlanmıştı ve süre dönem projesine dair sorulara ayrıldı. Cevaplar dönem boyunca öğrenilen dosya işlemlerinin pratikteki kullanımını bir araya getirdi: her `fopen` sonrasında `NULL` kontrolü, `fseek(fp, 0, SEEK_SET)` ile dosyanın başına dönme (metin kipinde ofsetin 0 ya da `ftell` değeri olması), kayıt silme ve güncellemede taşınabilir çözüm olarak geçici dosya, sekmeyle ayrılmış metin dosyalarının Excel'de açılması. Başlık dosyası denemesiyle yapı tanımlarının ayrı bir `.h` dosyasına taşınıp tırnaklı `#include` ile kullanılabildiği gösterildi.

Tasarım tarafında hoca, sayısı bilinmeyen veriler için dinamik bellek kullanmayı, kimlik olarak kullanılan bir alan değiştiğinde ilişkili bütün dosyaları güncellemeyi ya da otomatik artan bir ID seçmeyi, logu geçmişin değiştirilmeyen ayak izi olarak tutmayı, yapılara silmeden ekleme yapmayı ve bütün bu kararları raporda açıklamayı önerdi. Taşınabilirlik ve gereksinimlerin karşılıklı iletişimle netleştirilmesi oturumun bütününe yayılan iki ana fikirdi; ikincisinin sistem analizi ve yazılım mühendisliği derslerinde ayrıntılı işleneceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
