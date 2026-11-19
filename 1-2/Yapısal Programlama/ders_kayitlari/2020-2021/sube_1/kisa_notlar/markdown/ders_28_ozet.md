# Ders 28 Çalışma Özeti

## Genel Konular

- Dosya yönetimi fonksiyonları (ekrandan, 00:05:00)
  - Slayttaki dört fonksiyon `stdio.h` içinde bildirilir ve parametre olarak dosya adı alır:
    - `remove()`: dosyayı siler.
    - `rename()`: dosyanın adını değiştirir.
    - `tmpfile()`: adı önemsiz, geçici bir ikili (binary) dosya oluşturup `FILE *` döndürür.
    - `tmpnam()`: geçici dosya adı olarak kullanılabilecek bir karakter dizisi üretir.
  - Hoca bunların `fseek`, `fread` gibi fonksiyonlardan çok daha basit olduğunu, adlarının ne yaptıklarını anlattığını söyledi.
  - Ayrıntılı bildirimler için `stdio.h` dosyasının kendisine bakılabilir; derste dosya Not Defteri'nde açıldı (ekrandan, 00:50:00).
- `tmpnam` ile benzersiz geçici dosya adı üretmek
  - Hoca `tmpnam` fonksiyonunu derste denedi. Üretilen ad ters bölü (`\`) ile başlayan, rastgele görünen kısa bir dizgeydi (örneğin altyazıda geçen `s910`, `s6m4` gibi).
  - Ad doğrudan dosya adı olarak güvenli olmayabileceği için hoca ters bölüyü alt çizgiye çeviren bir `sanitizeFileName` fonksiyonu yazdı (ekrandan, 00:35:00). Sonuç ekranda `_sfao.` gibi bir addı (ekrandan, 00:55:00).
  - Slayta da şu not eklendi: `tmpnam` `\s` gibi güvensiz karakterler döndürebilir, bu yüzden temizlenmelidir (ekrandan, 00:50:00).
- `remove` ve `rename` denemesi
  - Hoca bir metin dosyası oluşturup programı komut satırından çalıştırdı; `remove` dosyayı sildi, `rename` dosyanın adını değiştirdi.
  - Dosya adı yol içermiyorsa dosya, programın çalıştırıldığı dizinde aranır.
  - Bir `FILE *` göstericisinden dosyanın adını öğrenen standart bir fonksiyon `stdio.h` içinde bulunamadı.
- Raporlarda ekran çıktısı: resim yerine metin
  - Kaynak kod ve program çıktısı gibi metin içerik rapora resim olarak değil, metin olarak yapıştırılmalıdır.
  - Gerekçeler: resimdeki yazı ölçeklendikçe bulanıklaşır, satıra sığdırılamaz, gri ton ve siyah arka plan baskıda okunurluğu düşürür ve mürekkep harcatır.
  - Komut istemi penceresinden metin "Düzen > İşaretle" ile seçilip kopyalanabilir.
  - Kod ve program çıktısı sabit genişlikli bir fontla (Consolas, Courier New) yazılmalıdır. Teknik raporlarda, dergilerde ve konferanslarda bu bir kuraldır.
- `scanf` ile boşluk içeren ad okumak
  - `%s` boşlukta durur; iki kelimelik bir ad tek `%s` ile okunamaz, kalan kelime sonraki okumaya geçer.
  - Hocanın önerisi: adı ve soyadı ayrı ayrı istemek ya da kullanıcıdan boşluk yerine alt çizgi girmesini istemek ve iki dönüşüm fonksiyonu yazmak (biri boşluğu alt çizgiye, öbürü alt çizgiyi boşluğa çevirir).
  - Diğer şube hocasının önerdiği tarama kümesi (`%[^;]`) yöntemi de doğru bir yoldur; hoca ayrıntısını ezbere bilmediğini söyledi.
- Geçici dosyalar ve fonksiyonlar arası yaşam döngüsü
  - İç içe çağrılan fonksiyonların her biri geçici dosya kullanıyorsa dosyaların yaşam döngüsü karışabilir.
  - Çağrılan fonksiyonun geçici dosyasına çağıran fonksiyonun da ihtiyacı varsa, dosya göstericisi dönüş değeri ya da parametre ile çağırana verilir; kapatma ve silme çağıranda, ihtiyaç bitince yapılır.
  - Farklı fonksiyonların aynı sabit adı (`temp.txt`) kullanması çakışma yaratabilir; her seferinde farklı ad üretmek için `tmpnam` kullanılabilir.
- Birim testi yaklaşımı
  - Bir öğrencinin kendi yazdığı test modülü üzerinden konuşuldu: her test başarılı ya da başarısız olması beklenen bir senaryoyu dener.
  - Java için JUnit, C# için benzeri test çerçeveleri var; C için de bir birim testi çerçevesi bulunduğu görüldü (ekrandan, 00:45:00).
  - İyi test kodu, test geçtiyse kısa bir "başarılı" mesajı verir; başarısızsa beklenen ve gerçekleşen sonucu ayrıntılı gösterir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Metin içerik metin olarak yapıştırılır
  - Hoca yıllardır gördüğü ödev ve tezlerde resim olarak konmuş metnin okunurluğunun çok düştüğünü söyledi; Word'de resim ile metni yan yana koyup karşılaştırarak gösterdi.
- Kod ve çıktı için sabit genişlikli font
  - Bu gelenek, her harfin aynı genişlikte olduğu daktilo ve papatya başlıklı (daisy wheel) yazıcılardan gelir.
- `#define` satırının sonuna noktalı virgül konmaz
  - Hoca derste `#define N 50;` yazınca derleme hatası aldı ve bunu hatırlattı: `#define` metin olarak yerine koyma yaptığı için noktalı virgül de yerine konan metnin parçası olur.
- Ters bölü karakter sabiti iki ters bölüyle yazılır
  - Tek ters bölü kaçış karakteridir; karakter sabiti olarak `'\\'` yazılmalıdır.
- Önce işlerin doğru çalıştığını gösterin
  - Proje raporunda önce ana başarılı senaryo gösterilmeli; zaman kalırsa yanlış işlemlerin engellendiği gösterilmelidir.
- Alt düzey dillerde davranış deneme yanılmayla öğrenilir
  - Taşınabilirliği düşük dillerde bazı davranışlar belgelenmez ya da sürümden sürüme değişir; hoca bunu "mesleğin cilveleri" diye niteledi.

## Kısa Tekrar Notları

- `remove(ad)` siler, `rename(eski, yeni)` adı değiştirir; ikisi de `FILE *` değil dosya adı alır.
- `tmpfile()` adsız geçici ikili dosya açar ve `FILE *` döndürür.
- `tmpnam(dizi)` geçici dosya adı üretir; çıktı ters bölü gibi karakterler içerebilir, kullanmadan önce temizlenmelidir.
- Karakter sabiti olarak ters bölü: `'\\'`.
- `#define N 50` satırına noktalı virgül konmaz.
- `scanf("%s", ...)` boşlukta durur; boşluklu ad için ayrı alanlar, alt çizgi dönüşümü ya da tarama kümesi kullanılır.
- Aynı sabit geçici dosya adını birden fazla yerde kullanmak çakışma yaratabilir.
- Raporda kod ve çıktı metin olarak ve sabit genişlikli fontla verilir.
- Test geçtiyse kısa mesaj, kalırsa ayrıntılı açıklama veren test kodu yazmak daha kullanışlıdır.

## Detaylı Açıklamalar

- Dosya yönetimi fonksiyonları ve `stdio.h`
  - Dersin akademik kısmı, önceki derslerde atlanan dosya yönetimi slaytıyla başladı. Hoca, `stdio.h` içindeki bildirimleri gösterdi (ekrandan, 00:50:00):

    ```c
    int   remove (const char* szFileName);
    int   rename (const char* szOldFileName, const char* szNewFileName);
    FILE* tmpfile ();
    char* tmpnam (char caName[]);
    ```

  - `rename` iki dosya adı alır ve hoca bunu DOS'taki ad değiştirme komutuna benzetti. Bildirimlerde parametrelerin `FILE *` değil dosya adı olduğu görülür.
  - Aynı dosyada `_tempnam (const char* szPath, const char* szPrefix)` bildirimi de görüldü; hoca bunun belki daha güvenli bir ad üretebileceğini ama emin olmadığını söyledi.
- `tmpnam` ve ad temizleme
  - Derste yazılan programın düzeltilmiş ve tamamlanmış hali aşağıdadır. Ekrandaki ilk sürümde parametre `char[] str` biçimindeydi (ekrandan, 00:35:00); bu C sözdizimine uymaz ve derleme hatası verir, doğrusu `char str[]` ya da `char *str` biçimidir. Aşağıdaki sürüm ajan tarafından düzeltildi, Linux'ta da çalışsın diye `/` karakteri de temizlendi; `gcc -Wall` ile derlendi ve çalıştırıldı.

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

  - Linux'ta çalıştırıldığında çıktı `The old name is: /tmp/filew4pEv5` ve `The new name is: _tmp_filew4pEv5` biçimindedir (ad her çalıştırmada değişir). Bağlayıcı ayrıca `tmpnam` kullanımının tehlikeli olduğu, yerine `mkstemp` önerildiği uyarısını verir.
  - Derste Windows'ta üretilen ad `\sfao.` gibiydi; temizlendikten sonra `_sfao.` oldu (ekrandan, 00:55:00). Hoca, sonuna `.tmp` uzantısı eklenip dosya adı olarak `fopen` ile yazma kipinde kullanılabileceğini söyledi.

  > **Ders sonrası not:** Hoca derste bu karakterden "slash" diye söz etti; ekrandaki kod ve slayt notu ters bölüyü (`\`, backslash) gösterir.

  > **Ders sonrası not:** Ekrandaki ilk sürümde `isim` dizisi `tmpnam` çağrılmadan önce yazdırılıyordu (ekrandan, 00:35:00); başlangıç değeri verilmemiş dizi yazdırıldığı için "old name" satırında anlamsız bir karakter çıktı (ekrandan, 00:55:00). Yukarıdaki sürümde yazdırma `tmpnam` çağrısından sonradır.

- `scanf` ve boşluk
  - Ekranda denenen program adı `scanf("%s", isim)` ile okuyordu (ekrandan, 00:20:00). Bir öğrenci, iki kelimelik adlarda ikinci kelimenin sonraki okumaya geçtiğini söyledi. Hoca önce `%s` ile okumanın boşlukları kabul etmesi gerektiğini düşündü, sonra adı ve soyadı ayrı sormayı önerdi.

  > **Ders sonrası not:** Hoca önce `%s` ile okumanın boşlukları kabul ettiğini söyledi; doğrusu `%s` ilk boşluk karakterinde durur. Ajanın denemesinde `Ali Veli` girişinde `isim` "Ali", sonraki `%s` okuması "Veli" oldu.

  > **Ek bilgi (derste anlatılmadı):** `%[^;]` tarama kümesi noktalı virgüle kadar olan her şeyi, boşluklar dahil okur, ama noktalı virgülün kendisini girdi akışında bırakır. Ayırıcı tüketilmezse sonraki okuma hemen o noktalı virgülde başarısız olur ve döngü ilerlemez; öğrencinin anlattığı sonsuz döngünün büyük olasılıkla nedeni budur. Biçim dizgesine ayırıcıyı ve baştaki boşlukları atlayan bir boşluk eklemek (`" %49[^;];%d"`) ve `fscanf` dönüş değerini kontrol etmek bu sorunu çözer.

- Geçici dosyaların yaşam döngüsü
  - Bir öğrenci, kayıt bırakma ve kredi güncelleme fonksiyonlarının ikisinin de `temp.txt` adlı geçici dosya kullandığını, dosyaları kapattığı halde bilgilerin aynı dosyaya karıştığını, adları değiştirince sorunun çözüldüğünü anlattı. Hoca kodu görmeden kesin cevap veremeyeceğini, iç içe çağrılarda yaşam döngüsünün karmaşıklaşabileceğini söyledi ve benzersiz ad için `tmpnam` kullanılmasını önerdi.
  - Sohbetten gelen bir yoruma göre, parametre olarak gelen `FILE *` göstericisi bazı ortamlarda o fonksiyonda kapatılamıyordu. Hoca bunun derleyici gerçeklemesinin bir eksikliği olabileceğini, bazı gerçeklemelerde gerçekten böyle davranıldığını söyledi.
- Birim testi
  - Hoca, Java'da JUnit ve C#'ta benzeri çerçevelerin test geçince yeşil bir çubuk, kalınca hangi testin başarısız olduğunu gösteren ayrıntı verdiğini anlattı. Bu yaklaşım test kodunu yazmayı zorlaştırır ama uzun çıktıları tek tek incelemek zorunluluğunu ortadan kaldırır; hoca bunu değip değmeyeceği geliştiriciye kalmış bir yatırım olarak niteledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
