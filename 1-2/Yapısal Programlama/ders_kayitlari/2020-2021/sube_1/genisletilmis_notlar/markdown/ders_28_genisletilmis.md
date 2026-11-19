# Ders 28 Genişletilmiş Notu: Dosya Yönetimi Fonksiyonları ve Proje Soru-Cevap

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Oturumun Niteliği
- 2. Dosya Yönetimi Fonksiyonları
- 3. Raporlarda Ekran Çıktısı: Resim mi, Metin mi?
- 4. scanf ile Boşluk İçeren Ad Okumak
- 5. Proje Gereksinimi: Sınıf Listesi
- 6. Geçici Dosyalar ve Fonksiyonlar Arası Yaşam Döngüsü
- 7. tmpnam ile Benzersiz Geçici Dosya Adı
- 8. Test Modülü ve Birim Testi Yaklaşımı
- 9. tmpfile, stdio.h Bildirimleri, remove ve rename Denemesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Oturumun Niteliği

Bu, dönemin son oturumudur ve müfredat konuları önceki derslerde tamamlanmıştır. Hoca oturumu iki amaçla kullandı: önceki derslerde anlatmayı atladığı dosya yönetimi fonksiyonlarını kısaca göstermek ve öğrencilerin dönem projesiyle ilgili sorularını cevaplamak. Soru beklerken boş durmamak için fonksiyonları geliştirme ortamında (Dev-C++) denedi. Bu yüzden ders, kısa konu anlatımları ile soru-cevapların iç içe geçtiği bir akış izler. Bu not akademik kısımları dersteki sırayla toplar.

## 2. Dosya Yönetimi Fonksiyonları

Hoca, sunumun son slaytında yer alan dosya yönetimi fonksiyonlarını önceki derslerde anlatmayı atladığını söyleyerek başladı. Slayt şu dört fonksiyonu listeler (ekrandan, 00:05:00):

- `remove()`: bir dosyayı siler.
- `rename()`: bir dosyanın adını değiştirir.
- `tmpfile()`: geçici bir ikili (binary) dosya oluşturur.
- `tmpnam()`: geçici bir dosyanın adı olarak kullanılabilecek bir karakter dizisi üretir.

Slaytın son maddesi, fonksiyon tanımları için `stdio.h` dosyasına bakılmasını söyler. Hocaya göre bu fonksiyonlar `fseek` ya da `fread` gibi fonksiyonlardan çok daha basittir; adları ne yaptıklarını anlatır ve öğrenciler bunları kendi başlarına rahatça keşfedebilir. Bir dosyayı silmek isteyen `remove`, adını değiştirmek isteyen `rename` kullanır. Adı önemli olmayan bir geçici dosya isteniyorsa `tmpfile` vardır. Geçici dosyanın adı da tutulmak isteniyorsa `tmpnam` ile bir ad üretilir.

Hoca bu fonksiyonları denemek için bir program açtığı sırada sohbet penceresinden bir soru geldi ve konu bir süre rapor yazımına kaydı. Fonksiyonların denenmesine dersin ilerleyen kısımlarında dönüldü (bölüm 7 ve 9).

## 3. Raporlarda Ekran Çıktısı: Resim mi, Metin mi?

### 3.1 Soru ve ilke

Sohbetten gelen soru şuydu: proje raporunda ekran çıktılarının kopyalanması istenmiş; bunun yerine ekran görüntüsü konsa olur mu? (ekrandan, 00:10:00)

Hoca "olabilir" dedi, ama genel bir ilke koydu: ekran çıktısı bir resim değilse, yani kaynak kod ya da düz metin gibi metin biçimindeyse, onu her zaman metin olarak yapıştırmakta yarar vardır. Gerekçe okunurluktur. En boy oranı gibi etkenler yüzünden resim olarak konan metnin okunurluğu düşer. Hoca 2008'den beri çok sayıda ödev, tez ve kod gördüğünü, metinsel bilginin resim olarak gösterildiğinde okunurluğun çok düşebildiğini söyledi.

### 3.2 Word'de karşılaştırma

Hoca bunu göstermek için soruyu içeren sohbet satırının ekran görüntüsünü alıp bir Word belgesine yapıştırdı ve aynı metni yanına yazı olarak yazdı (ekrandan, 00:10:00). Karşılaştırmada şunlar görüldü:

- Resmin boyutuyla oynanarak sayfada biraz yer açılabilir, ama resimdeki metin ne yapılırsa yapılsın tek satıra düşürülemez. Yazı olarak yazılmış metin ise istenirse tek satırda durur.
- Harfler aynı büyüklüğe getirildiğinde bile yazı olarak yazılmış metin daha nettir.
- Resimdeki yazı biraz gridir. Yazıcının mürekkebi bitmeye yüz tutmuşsa resimdeki yazı düzgün çıkmaz, metin olarak yazılan yazı ise okunur.

Hocanın özeti: ödevlerde metin ağırlıklı bir içerik, yani kaynak kod ya da program çıktısı varsa, bunun metin olarak gösterilmesi tercih edilir.

### 3.3 Sabit genişlikli font

Hoca ikinci bir kural ekledi: kod ve program çıktısı sabit font genişliğine sahip bir fontla, örneğin Consolas ya da Courier New ile yazılmalıdır. Sabit genişlikli fontta her harf aynı genişliktedir. Hoca bunu Word'de gösterdi: normal fontta "i" dar, "C" geniştir; sabit genişlikli fontta ikisi aynı genişliktedir.

Bu gelenek daktilo zamanına kadar gider. Eski daktilolarda ve ilk yazıcılarda, örneğin papatya başlıklı (daisy wheel) yazıcılarda her harf aynı genişlikteydi. Bu gelenekten gelen nedenlerle bir rapor, ödev, makale ya da metin yazılırken bilgisayar kodu ya da bilgisayar çıktısı olan içerik sabit genişlikli fontla yazılır.

> **Hocanın vurgusu:** Birçok dergide ya da konferansta, yani teknik bir rapor yazıyorsanız, kodun sabit genişlikli fontla yazılması uyulması gereken bir kuraldır.

### 3.4 Menü ekranları ve komut istemi çıktısı

**Soru:** Bizim ekran çıktılarımız çoğunlukla "güncelleme başarılı" ya da "başarısız", "ders eklendi" ya da "eklenmedi" gibi kısa mesajlar. Bunları tek tek yazıya dökmenin anlamı var mı?

**Cevap:** Nasıl kolayınıza geliyorsa öyle yapın. Hoca, menüyle çalışan bir programda kendisinin şöyle yapacağını söyledi: "Program başladı", ardından ana menü ekranı ve "Seçiminizi girin" satırı metin olarak yazılır; altına "ana menü ekranımız budur" gibi bir açıklama konur. Her aşamada ekran siliniyorsa her ekran ayrı ayrı gösterilir. Hoca ekran görüntüsü yerine metni tercih ettiğini söyledi.

Hoca bir de komut satırından çalışan programlar için bir uyarı yaptı. Komut isteminde arka plan siyah, metin beyazdır. Bu ekran Print Screen ile alınıp basıldığında hem daha çok mürekkep harcanır, çünkü sayfanın çoğu siyahtır, hem de okunurluk daha da kötüleşir (ekrandan, 00:15:00). Bunun yerine pencerenin üstündeki simgeden "Düzen > İşaretle" seçilip metin işaretlenir ve Enter ile kopyalanır, sonra rapora yapıştırılır. Bütün ekranı almak da gerekmez; yalnız ilgili alan alınır.

## 4. scanf ile Boşluk İçeren Ad Okumak

### 4.1 Soru

Bir öğrenci projede `scanf` ile biçimli okuma yaptığını, ama iki kelimelik adlarda aradaki boşluk yüzünden adın doğru okunmadığını söyledi: ikinci kelime soyadı alanına geçiyordu. Diğer şubenin hocası, köşeli parantez içinde şapka işareti ve noktalı virgülle (`%[^;]`) okumayı önermişti; ama öğrenci bunu kullandığında `while` döngüsü sonsuz döngüye giriyor, sürekli ilk noktalı virgüle kadar olan yeri okuyup başa dönüyordu.

### 4.2 Derste yapılan deneme

Hoca önce, adın yapıda örneğin 50 karakterlik bir dizi olarak tutulduğunu ve `%s` ile okunduğunda normalde boşlukları kabul etmesi gerektiğini düşündüğünü söyledi. Bunu denemek için şu programı yazdı (ekrandan, 00:20:00):

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
   int j; FILE *fp; unsigned int val;
    char isim[50], soyad[50];
      printf("Enter name of the person:");
      scanf("%s", isim);
      printf("You have entered: %s", isim);
    fclose(fp);

    system("PAUSE");
    return 0;
}
```

Öğrenci, `scanf` satırına bir `%s` daha ekleyip soyadını da okumasını istedi. Hoca ise adı ve soyadı ayrı ayrı sormayı önerdi: önce "Adını girin", sonra ayrı bir satırda "Soyadını girin". Tek satırda girilirse boşluk ayırıcı olarak algılanır; iki ayrı satırda girilmesinde bir sakınca yoktur.

> **Ders sonrası not:** Hoca önce `%s` ile okumanın boşlukları kabul ettiğini söyledi; doğrusu `%s` ilk boşluk karakterinde durur ve kalan kelime girdi akışında bir sonraki okumayı bekler. Öğrencinin gözlemi doğrudur. Ajanın denemesinde, ad ve soyadı ayrı `%49s` okumalarıyla alan bir programa `Ali Veli` girildiğinde ad "Ali", soyad "Veli" olarak okundu; ikinci istem beklenmeden geçildi.

> **Ders sonrası not:** Ekrandaki programda `fp` hiç açılmadan `fclose(fp)` çağrılıyor (ekrandan, 00:20:00). Başlangıç değeri verilmemiş bir göstericiyle `fclose` çağırmak tanımsız davranıştır; büyük olasılıkla bu satır önceki bir denemeden kalmıştır.

### 4.3 Tarama kümesi ve alternatifler

Öğrenci köşeli parantezli okumanın nasıl kullanıldığını merak ettiğini söyleyince hoca bunu ezbere bilmediğini söyledi. C gibi alt düzey, string yapısı olmayan dillerde karakter dizileriyle böyle oynamanın gerçekten zahmetli olduğunu ekledi.

Hocanın önerdiği bir alternatif: kullanıcıya "adınızda boşluk varsa boşluk yerine alt çizgi girin" gibi bir açıklama gösterilir. Kullanıcı alt çizgiyle girer. Programda iki fonksiyon yazılır: biri (kodlama) boşlukları alt çizgiye, öbürü (çözme) alt çizgileri boşluğa çevirir; bunlar uygun yerlerde çağrılır. Hoca, diğer şube hocasının önerisinin de doğru olduğunu, ama başka yolların da bulunduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** `%[^;]` noktalı virgüle kadar olan her şeyi, boşluklar dahil okur, ama noktalı virgülün kendisini girdi akışında bırakır. Ayırıcı tüketilmezse sonraki okuma hemen o noktalı virgülde başarısız olur ve döngü ilerlemez; öğrencinin anlattığı sonsuz döngünün büyük olasılıkla nedeni budur. Biçim dizgesine ayırıcıyı eklemek ve satır sonlarını atlamak için başa bir boşluk koymak (`" %49[^;];%d"`) ve döngüde `fscanf` dönüş değerini kontrol etmek sorunu çözer. Ajanın denemesinde `Ali Riza;101` ve `Ayse Nur;102` satırları bu biçimle doğru okundu.

## 5. Proje Gereksinimi: Sınıf Listesi

İki öğrenci proje teslimiyle ilgili hatırlatma yaptı; hoca teslim yerini sistemde tanımladı. Ardından proje metnindeki bir madde soruldu.

**Soru:** Öğretim üyesinin ID'si kullanılarak verdiği bütün dersler için teker teker sınıf listesi mi yapılacak, yoksa kullanıcıdan ders kodu istenip tek bir sınıf listesi mi?

**Cevap:** Hem öğretim üyesinin ID'si hem de ders kodu alınır ve tek bir ders için sınıf listesi yapılır, hepsi için değil. Hoca maddedeki anahtar kelimenin "bir ders" olduğunu vurguladı.

## 6. Geçici Dosyalar ve Fonksiyonlar Arası Yaşam Döngüsü

### 6.1 Soru

Bir öğrenci, güncelleme işlemlerini yeni bir dosya oluşturup kayıtları ona aktararak yaptığını anlattı. Bir fonksiyonun içinden başka bir fonksiyon çağırdığında ikisi de `temp.txt` adlı geçici dosyayı oluşturuyor, kullanıyor ve kapatıyordu. Dosyaları kapattığından emin olduğu halde program bitince bütün bilgiler aynı dosyaya basılmış görünüyordu; geçici dosyaların adlarını değiştirince sorun çözüldü. C bu işlemleri biriktirip program bittikten sonra mı yapıyordu?

### 6.2 Hocanın cevabı

Hoca, bir fonksiyon içinde başka bir fonksiyon çağrıldığında, ilk fonksiyonda bir geçici dosya, onun çağırdığı fonksiyonda başka bir geçici dosya varsa bunların yaşam döngüsünün karmaşıklaşabileceğini söyledi. Kesin bir şey söylemek için koda bakmak gerekir.

Hocanın genel önerisi: ikinci fonksiyondaki geçici dosyaya çağıran fonksiyonun da ihtiyacı varsa, iş iç içe yapılmaz. İkinci fonksiyon kendi oluşturduğu geçici dosyanın dosya göstericisini dönüş değeri ya da parametre yoluyla çağıran fonksiyona verir. Kapatma ve silme işi, dosyaya ihtiyaç bittikten sonra çağıran fonksiyonda yapılır.

Öğrenci, iki fonksiyonun birbirine bir şey döndürmediğini açıkladı: biri öğrencinin dersi bırakmasını kaydediyor, öbürü ardından kredi bilgisini güncelliyordu; ikisi de `void` fonksiyonlardı ve yalnız oluşturdukları geçici dosyanın adı aynıydı. Hoca bunun üzerine tam o sırada incelemekte oldukları `tmpfile` ve `tmpnam` fonksiyonlarına döndü: her seferinde farklı bir geçici dosya adı üretmek bu tür çakışmaları önler (bölüm 7).

### 6.3 Başka fonksiyonda kapatılan dosya

Sohbetten bir öğrenci, dosya göstericisi bir fonksiyona parametre olarak gönderildiğinde dosya o fonksiyonda açılmadığı için orada kapatılamadığını okuduğunu yazdı. Hoca bunu ilgili derleyici gerçeklemesinin bir eksikliği olarak gördüğünü söyledi: dosya göstericisinin illa onu oluşturan fonksiyonda kapatılması zorunluluğu bir eksiklik olur. Ama bazı gerçeklemelerde gerçekten böyle olabileceğini kabul etti.

Hoca buradan genel bir değerlendirme yaptı: C gibi alt düzey ve taşınabilirliği düşük dillerde böyle davranışlar ancak deneme yanılmayla keşfedilir. Belgelenmez; belgelense bile sonraki bir sürümde eski belgelere tamamen ters davranışlar görülebilir. Hoca bunu "mesleğin cilveleri" diye niteledi.

> **Ek bilgi (derste anlatılmadı):** C standardı `fclose` çağrısının hangi fonksiyonda yapılacağına bir kısıt koymaz; geçerli bir `FILE *` göstericisi parametre olarak alınıp başka bir fonksiyonda kapatılabilir. Asıl dikkat edilmesi gereken, aynı göstericinin iki kez kapatılmaması ve kapatıldıktan sonra kullanılmamasıdır.

## 7. tmpnam ile Benzersiz Geçici Dosya Adı

### 7.1 İlk deneme

Hoca `tmpnam` fonksiyonunun ne ürettiğini merak ettiğini söyleyerek bir program yazdı: bir karakter dizisi tanımladı, `tmpnam` ile bu diziye bir ad ürettirdi ve ekrana yazdırdı. İlk denemede çıktıyı anlamlandıramadı; sonra üretilen adın `s910` gibi kısa ve rastgele görünen bir dizge olduğunu, başında da bir bölü işareti bulunduğunu fark etti. Dosya adı isterken başında bölü işareti bulunan bir şey gelmesinin dosya adı olarak nasıl çalışacağını sorguladı ve "çok acayip bir olay" dedi.

### 7.2 Ad temizleme fonksiyonu

Bunun üzerine hoca, üretilen adı dosya adına uygun hale getiren bir `sanitizeFileName` fonksiyonu yazdı. Fonksiyon dizinin her karakterine bakar, ters bölü karakterini alt çizgiyle değiştirir. Hoca alt çizginin dosya adlarında emniyetli bir karakter olduğunu söyledi. Ekranda görülen sürüm şudur (ekrandan, 00:35:00):

```c
#include <stdio.h>
#include <stdlib.h>
void sanitizeFileName( char[] str, int len ) {
     int i;
     for( i=0; i<len; i++ )
         if( str[i] == '\\' )
             str[i] = '_';
}
int main(int argc, char *argv[]){

     char isim[50];
    printf("The old name is: %s\n", isim);
     tmpnam(isim);
    printf("The new name is: %s\n", isim);

     system("PAUSE");
     return 0;
}
```

> **Hocanın vurgusu:** Ters bölü karakteri tırnak içinde iki kez yazılmalıdır: `'\\'`. Tek ters bölü kaçış karakteridir.

Hoca dizi boyutu için bir sabit tanımlamak istedi ve `#define` ile 50 değerini verdi. Derleme sırasında iki hata çıktı:

- Fonksiyon başlığındaki parametre bildirimi derleyiciye uymadı. Hoca bir süre uğraştı ve alt düzey dillerin "insanı deli ettiğini" söyledi. <!-- BELİRSİZ: Hocanın parametreyi nasıl düzelttiği karede görünmüyor; ekrandaki "char[] str" biçimi C'de geçersizdir, doğrusu "char str[]" ya da "char *str". -->
- `#define` satırının sonuna noktalı virgül konmuştu.

> **Hocanın vurgusu:** `#define` satırının sonuna noktalı virgül konmaz. `#define N 50;` yazılırsa kodda `N` geçen her yere `50;` konur ve derleme hatası çıkar.

Düzeltmelerden sonra program çalıştı. Bir çalıştırmada ad `\s6m4.`, bir sonrakinde tesadüfen anlamlı bir İngilizce kelimeye benzeyen bir ad geldi; hoca adların hep aynı karakterle başladığını gözledi. Komut satırından yapılan bir çalıştırmada temizlenmiş ad `_sfao.` oldu (ekrandan, 00:55:00).

Hoca sonucu şöyle bağladı: proje boyunca birden fazla geçici dosyaya ihtiyaç varsa, her seferinde farklı ad `tmpnam` ile sağlanabilir. Üretilen ad dosya adına uygun hale getirilir ve sonuna `.tmp` uzantısı eklenebilir. Hoca bu bilgiyi slayta da not olarak ekledi: `tmpnam`, `\s` gibi güvensiz karakterler döndürebilir, bu yüzden temizlenmelidir (ekrandan, 00:50:00).

> **Ders sonrası not:** Hoca derste bu karakterden "slash" (bölü) diye söz etti; ekrandaki kod ve slayt notu ters bölüyü (`\`, backslash) gösterir. Windows'ta yol ayırıcı ters bölüdür; Linux'ta `tmpnam` `/tmp/...` biçiminde, düz bölü içeren bir yol döndürür.

> **Ders sonrası not:** Ekrandaki sürümde `isim` dizisi `tmpnam` çağrılmadan önce yazdırılıyor; başlangıç değeri verilmemiş dizi yazdırıldığı için "old name" satırında anlamsız bir karakter çıktı (ekrandan, 00:55:00). Ayrıca `char[] str` parametre biçimi C'de geçersizdir.

### 7.3 Düzeltilmiş ve derlenmiş sürüm

Aşağıdaki program derste yazılan kodun ajan tarafından düzeltilmiş halidir: parametre `char str[]` yapıldı, `#define` noktalı virgülsüz yazıldı, eski ad `tmpnam` çağrısından sonra yazdırıldı ve Linux'ta da çalışsın diye `/` karakteri de temizlendi. `gcc -Wall` ile derlendi ve çalıştırıldı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

void sanitizeFileName(char str[], int len) {
    int i;
    for (i = 0; i < len; i++)
        if (str[i] == '\\' || str[i] == '/')
            str[i] = '_';
}

int main(void) {
    char isim[N];
    tmpnam(isim);
    printf("The old name is: %s\n", isim);
    sanitizeFileName(isim, strlen(isim));
    printf("The new name is: %s\n", isim);
    return 0;
}
```

Linux'ta bir çalıştırmanın çıktısı:

```text
The old name is: /tmp/filew4pEv5
The new name is: _tmp_filew4pEv5
```

Ad her çalıştırmada değişir. Bağlayıcı ayrıca "`tmpnam` kullanımı tehlikelidir, `mkstemp` kullanın" uyarısını verir.

> **Ek bilgi (derste anlatılmadı):** `tmpnam` yalnız bir ad üretir, dosyayı oluşturmaz. Ad üretildikten sonra dosya açılana kadar geçen sürede başka bir program aynı adı kullanabilir; bu yüzden modern kütüphaneler uyarı verir. Adı gerekmeyen durumlarda `tmpfile`, adın da gerektiği POSIX sistemlerinde `mkstemp` daha güvenli seçeneklerdir.

## 8. Test Modülü ve Birim Testi Yaklaşımı

### 8.1 Bir öğrencinin test modülü

Bir öğrenci rapor için kendi yazdığı test modülünü ekranını paylaşarak gösterdi (ekrandan, 00:40:00). Modül önce bütün dosyaların silineceği konusunda uyarıyor ve onay istiyordu; hoca bunu, testten önce ortamı temiz biçimde kurmak olarak niteledi. Ardından her test, başarılı ya da başarısız olması beklenen bir senaryoyu deniyordu:

- Beş öğretim üyesi ve altı ders eklenmesi: başarılı olmalı.
- Aynı ders koduyla ders eklenmesi, geçersiz öğretim üyesi ID'siyle ders eklenmesi, aynı öğrenci numarasıyla öğrenci eklenmesi: başarısız olmalı.
- En çok ders sayısına ulaşmış bir öğrenciye ders eklenmesi: başarısız olmalı.

Her testin başında beklenen sonuç, ardından programın gerçek çıktısı yazdırılıyordu; ekleme testlerinden sonra silme testlerine geçiliyordu.

**Soru:** Bu test modülünün çıktısını rapora koysam ve tek bir fonksiyon çağırarak kontrol eden kişinin de görebilmesini sağlasam olur mu, yoksa menüden tek tek girip mi yazayım?

**Cevap:** Madem yapılmış, gönderilebilir. Hoca, menüye ayrı bir "test" seçeneği eklenebileceğini de önerdi. Ama rapor hazırlanırken menüden en az bir kez giriş yapılmasını istedi. Hocanın ölçütü proje metnindeki "fonksiyonların doğru çalıştığını gösterin" ifadesidir: asıl beklenen, ana başarılı senaryoda her şey doğru girildiğinde sonuçların doğru göründüğünü göstermektir. Kısıtlar da gösterilebilir, örneğin en çok ders sayısından fazlası girilemez ve bunu denediğinizde hata mesajı alırsınız. Bütün güvenlik kontrollerinin raporda gösterilmesi gerekmez.

> **Hocanın vurgusu:** Önce işlerin doğru çalıştığını gösterin; zaman kaldıkça yanlış işlerin yapılamadığını gösterin.

### 8.2 Birim testi çerçeveleri

Öğrencinin ayrıntılı test senaryoları üzerine hoca birim testi çerçevelerine değindi. Java, C# gibi nesneye yönelik dillerde çok iyi iş yapan test çerçeveleri vardır: Java için JUnit, C# için de benzeri bir çerçeve. <!-- BELİRSİZ: C# çerçevesinin adı altyazıda "JSUnit"/"CS unit" diye geçiyor; büyük olasılıkla csUnit ya da NUnit kastediliyor. --> Hoca ders sırasında C için de bir birim testi çerçevesi olup olmadığına baktı ve CUnit adlı bir çerçeve bulunduğunu gördü (ekrandan, 00:45:00). JUnit'in 3 ve 4 sürümleri için hızlı bir kullanım kılavuzunun kendi lisansüstü dersinin notlarında bulunduğunu söyledi ve nesneye yönelik programlama dersinde de proje verileceğini, birim testlerinin orada da yararlı olacağını ekledi.

Hoca birim testlerinin, istenmese bile kodun doğru çalıştığından emin olmak için yararlı olduğunu söyledi. Ardından iyi bir test çıktısının nasıl olması gerektiğini anlattı:

- Test başarılıysa ayrıntılı çıktı yerine kısa bir "test başarılı" mesajı verilir.
- Test başarısızsa ayrıntılı çıktı verilir: ne olması gerekiyordu, ne oldu.

Bunun dezavantajı test kodunun daha zor yazılması ve daha çok emek istemesidir. Karşılığında, testler geçtiğinde uzun bir ekran çıktısına bakıp gerçekten olmuş mu olmamış mı diye didikleme masrafından kurtulunur. Hoca bunu bir yatırım olarak niteledi; değip değmeyeceğine geliştirici karar verir. JUnit gibi çerçeveler de bu şekilde çalışır: sorun yoksa yeşil bir çubuk gösterir, sorun varsa hangi testin başarısız olduğunu ayrıntılı verir.

## 9. tmpfile, stdio.h Bildirimleri, remove ve rename Denemesi

### 9.1 stdio.h bildirimleri

Hoca, fonksiyonların bildirimlerini görmek için `stdio.h` dosyasını Not Defteri'nde açtı. "File Operations" bölümünde şu bildirimler görülür (ekrandan, 00:50:00):

```c
FILE*  fopen (const char* szFileName, const char* szMode);
FILE*  freopen (const char* szNewFileName, const char* szNewMode,
               FILE* fileChangeAssociation);
int    fflush (FILE* fileFlush);
int    fclose (FILE* fileClose);
int    remove (const char* szFileName);
int    rename (const char* szOldFileName, const char* szNewFileName);
FILE*  tmpfile ();
char*  tmpnam (char caName[]);
char*  _tempnam (const char* szPath, const char* szPrefix);
```

`tmpfile` hiçbir parametre almaz; ad bile verilmeden bir geçici dosya açar ve `FILE *` döndürür. Hoca, kendisinin bunun yerine `tmpnam` ile üretilip temizlenen adı kullanarak `fopen` ile yazma kipinde dosya açmayı tercih edeceğini söyledi. `_tempnam` bildiriminde bir yol ve bir önek parametresi bulunur; hoca bunun belki daha güvenli bir ad üretebileceğini ama bilmediğini söyledi.

Hoca bir `FILE *` göstericisinin gösterdiği dosyanın adını öğrenmenin bir yolu olup olmadığını da merak etti. `stdio.h` içindeki fonksiyonlara göz attı ve dosya adını öğrenen böyle bir fonksiyon bulunmadığı sonucuna vardı.

### 9.2 remove ve rename denemesi

Hoca bildirimlerde `remove` ve `rename` fonksiyonlarının dosya göstericisi değil dosya adı aldığını belirtti; `rename`'in eski ad ve yeni ad olmak üzere iki parametresi vardır ve DOS'taki ad değiştirme komutu gibi çalışır.

Denemede hoca önce programın bulunduğu dizinde bir metin dosyası oluşturdu, programda `remove` ile bu dosyanın adını verdi ve programı komut satırından çalıştırdı. Dosya adında yol olmadığı için programın çalıştırıldığı dizin esas alınır; bu yüzden programı geliştirme ortamı yerine o dizinden komut satırında çalıştırmayı mantıklı buldu. Çalıştırmadan sonra dosyanın silindiği görüldü. Sonra yeni bir metin dosyası oluşturup `rename` ile adını değiştirdi; bu da beklendiği gibi çalıştı. <!-- BELİRSİZ: remove ve rename denemesinin kodu ve kullanılan dosya adları karelerde görünmüyor; altyazıda dosya adları "deneme" ve "test" diye geçiyor. -->

Derste yazılan kod karede görünmediği için aşağıda aynı işlemi yapan küçük bir program verilmiştir. Bu program derste yazılmadı; ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve çalıştırıldı.

```c
#include <stdio.h>
int main(void) {
    FILE *fp = fopen("deneme.txt", "w");
    if (fp == NULL) return 1;
    fprintf(fp, "deneme\n");
    fclose(fp);
    if (rename("deneme.txt", "test.txt") == 0)
        printf("rename basarili\n");
    if (remove("test.txt") == 0)
        printf("remove basarili\n");
    return 0;
}
```

Çalıştırıldığında iki satır da yazdırıldı: `rename basarili` ve `remove basarili`. İki fonksiyon da başarıda 0, hata durumunda sıfırdan farklı bir değer döndürür.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:28): `scanf("%s", isim)` ile iki kelimelik bir ad (örneğin "Ali Veli") okunmak istendiğinde ne olur? Boşluklu adlar için hangi yollar kullanılabilir?

> **Çözüm (derste verilmedi):** `%s` ilk boşlukta durur; `isim` dizisine yalnız "Ali" yazılır, "Veli" girdi akışında kalır ve bir sonraki `scanf` çağrısı onu okur. Derste önerilen yollar: ad ve soyadı ayrı istemek, kullanıcıdan boşluk yerine alt çizgi girmesini isteyip dönüşüm fonksiyonları yazmak ya da tarama kümesi kullanmak. Tarama kümesiyle `" %49[^;];%d"` biçimi noktalı virgüle kadar olan adı boşluklarıyla okur ve noktalı virgülü tüketir; ajanın denemesinde `Ali Riza;101` satırı `[Ali Riza] 101` olarak okundu (`gcc -Wall` ile derlendi).

**Soru 2** (derste sözlü, 00:27:08): İki farklı `void` fonksiyon da geçici kayıtlar için `temp.txt` adlı dosyayı kullanıyor ve bilgiler karışıyor. Bu çakışma nasıl önlenir?

Derste verilen cevap: yaşam döngüsü iç içe geçen geçici dosyalarda, çağrılan fonksiyonun dosya göstericisi dönüş değeri ya da parametre ile çağırana verilir ve kapatma/silme çağıranda yapılır. Fonksiyonlar bağımsızsa her geçici dosya için `tmpnam` ile farklı bir ad üretilir; ad dosya adına uygun hale getirilir ve `.tmp` uzantısı eklenebilir.

**Soru 3** (derste sözlü, 00:24:54): Öğretim üyesi ID'si verildiğinde sınıf listesi bütün dersleri için mi, yoksa tek bir ders için mi oluşturulur?

Derste verilen cevap: hem öğretim üyesi ID'si hem ders kodu alınır, tek bir ders için sınıf listesi oluşturulur.

**Soru 4** (ekrandan, 00:35:00): Aşağıdaki kodda derleme hatasına yol açan iki yer hangisidir?

```c
#define N 50;
void sanitizeFileName( char[] str, int len ) { /* ... */ }
```

> **Çözüm (derste verilmedi):** `#define N 50;` satırındaki noktalı virgül `N` geçen her yere `50;` olarak kopyalanır; `char isim[N];` ifadesi `char isim[50;];` olur ve derlenmez. `char[] str` biçimi C'de geçersizdir; parametre `char str[]` ya da `char *str` olarak yazılmalıdır. Düzeltilmiş sürüm (bölüm 7.3) `gcc -Wall` ile derlendi.

## Dersin Toparlaması

Bu son oturumda önceki derslerde atlanan dosya yönetimi fonksiyonları tamamlandı. `remove` ve `rename` dosya adıyla çalışır ve dosya silme ile ad değiştirme işlerini görür. `tmpfile` adsız bir geçici dosya açar, `tmpnam` ise geçici dosya adı üretir. Derste yapılan denemelerde `tmpnam` çıktısının ters bölü gibi dosya adında güvensiz karakterler içerebildiği görüldü; bu yüzden üretilen ad bir temizleme fonksiyonundan geçirilmelidir. Aynı denemeler `#define` satırına noktalı virgül konmaması ve ters bölü karakter sabitinin `'\\'` yazılması gibi C ayrıntılarını da hatırlattı.

Soru-cevap kısmı dönem projesinde karşılaşılan pratik sorunlara odaklandı: boşluklu adların `scanf` ile okunması, aynı adlı geçici dosyaların çakışması ve dosya göstericilerinin fonksiyonlar arasında paylaşılması. Hoca ayrıca raporlarda kod ve çıktının resim yerine metin olarak, sabit genişlikli fontla verilmesini ve test kodunun başarılı durumda kısa, başarısız durumda ayrıntılı çıktı vermesini önerdi. Birim testi çerçeveleri (JUnit ve benzerleri) nesneye yönelik programlama dersinde de yararlı olacak bir araç olarak tanıtıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
