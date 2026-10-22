# Ders 28 Çalışma Özeti

## Genel Konular

- Dönem projesi videosu
  - 3-6 dakikalık bir video çekilir. Kamera açık olmalı ve öğrenci önce kendini tanıtmalıdır.
  - Projeye, onu ilk kez duyan birine anlatır gibi kısa bir giriş yapılır. Ardından ekran paylaşılarak programın çalışan ve çalışmayan kısımları komutlar girilerek gösterilir. Sonunda programın yapamadığı şeyler açıkça söylenir.
  - Zarın rastgele gelmesi bazı durumların videoda gösterilmesini zorlaştırır. Bunun için zarın rastgele mi atılacağını yoksa kullanıcı tarafından mı girileceğini seçtiren bir seçenek eklenebilir. Bu, videoda belirtilmelidir.
  - Videonun bağlantısı teslim edilen PDF'e konur. Video, indirme gerektirmeden doğrudan izlenebilecek bir yerde (ör. YouTube'da yalnızca bağlantıya sahip olanların görebileceği şekilde) bulunmalıdır.
  - PDF'teki "kısa açıklama" bölümünde bütün kurallar yazılmaz. Nasıl bir uygulamanın tasarlandığı kısaca anlatılır. Eklenen yeni kurallar mutlaka PDF'te belirtilmelidir.
- IP adresleri ve alan adları
  - IPv4 adresleri 32 bittir (4 byte). Dünyadaki bütün cihazların benzersiz bir adresle birbirine erişebilmesi için 128 bitlik IPv6'ya geçiş çalışmaları sürmektedir. Nesnelerin interneti (IoT) cihazlarının artması IPv6'yı zorunlu hâle getirmiştir.
  - Adresler genelde sayılarla değil alan adlarıyla (domain name) kullanılır. Üst düzey alan adları (top level domain): `edu`, `org`, `net`, `com`. Bunlara ülke kodları eklenebilir: `com.tr`, `co.uk`. Alan adlarının altında alt alan adları (subdomain) vardır.
  - IP adreslerini ve alan adlarını yöneten kâr amacı gütmeyen kuruluş ICANN'dir (Internet Corporation for Assigned Names and Numbers). Kurumlara belirli IP blokları tahsis edilir. Örneğin üniversiteye ayrılmış IP blokları vardır.
- İnternet uygulamaları ve protokoller
  - FTP (File Transfer Protocol): dosya aktarımı.
  - Telnet ve onun güvenli versiyonu SSH (Secure Shell): başka bir bilgisayara pencere arayüzü olmadan komut satırıyla bağlanıp işlem yapmayı sağlar.
  - HTTP (Hypertext Transfer Protocol): web sayfalarının aktarıldığı protokol. Güvenli versiyonu HTTPS'tir.
  - E-posta:
    - SMTP (Simple Mail Transfer Protocol): e-postaların posta sunucuları arasında aktarılması. Metin mesajlarını ASCII ile kodlar.
    - MIME (Multipurpose Internet Mail Extensions): ASCII olmayan verilerin (ekler gibi) e-postayla gönderilmesini sağlar.
    - E-postalara erişim: POP3 (Post Office Protocol version 3) ile mesajlar bilgisayara indirilir. IMAP (Internet Message Access Protocol) ile mesajlar sunucuda tutulur ve her yerden erişilir. Günümüzde IMAP daha yaygındır.
  - VoIP (Voice over Internet Protocol): ses, normal telefon hattının ses bandı yerine veri paketleriyle taşınır.
- Mobil haberleşme nesilleri (1980'lerden itibaren)
  - 1G: analog ses, yalnızca kablosuz sesli görüşme.
  - 2G: ses dijital olarak kodlanır ve daha verimli taşınır. Mesaj gibi dijital veriler de gönderilmeye başlanır.
  - 3G: yüksek veri hızları. Görüntülü görüşme, video izleme, büyük resim gönderme.
  - 4G: çok yüksek hızlar ve paket anahtarlamalı IP ağı (packet switched IP network).
  - 5G: kullanılmaya başlanmıştır.
- Veri dağıtım şekilleri ve akış (streaming)
  - Unicast: bir kullanıcıdan bir kullanıcıya. N-unicast: aynı verinin birden fazla kullanıcıya ayrı ayrı gönderilmesi. Multicast: belirli bir gruba. Broadcast: ağdaki herkese.
  - İsteğe bağlı akış uygulamaları (on-demand streaming): Netflix, YouTube gibi uygulamalarda kullanıcı içeriği istediği zaman, istediği noktadan izler. Ses ve video aktarımı bant genişliğinde çok yer kaplar. Bu şirketler internet servis sağlayıcılarıyla anlaşarak bant genişliğinin bir kısmını kendilerine ayırır. Bu yüzden başka siteler yavaşken bile videolar kesintisiz ve kaliteli gelebilir.
- Web
  - Tarayıcı (browser), web sunucusundan (web server) HTTP ile istenen bilgiyi belirli bir formatta gösterir. Her web belgesinin bir URL'si (Uniform Resource Locator) vardır.
  - HTML (Hypertext Markup Language): sayfanın yapısını belirler (başlık, gövde, tablolar, paragraflar). Etiketlerle (tag) yazılır ve tarayıcı tarafından yorumlanır. Aynı sayfa farklı tarayıcılarda farklı görünebilir. Yeni versiyonu HTML5'tir.
  - CSS, sayfanın görünümünü (makyajını) belirler. HTML olmadan CSS'in bir anlamı yoktur.
  - HTML yalnızca statik sayfa üretir. Kullanıcıyla etkileşimli (dinamik) sayfalar için JavaScript, PHP gibi diller de kullanılır.
  - XML (Extensible Markup Language): verilerin temsil edilmesi ve bir noktadan diğerine taşınması için kullanılır. Muadili JSON'dur.
- Binary search (ikili arama) (ekrandan, 01:20:30)
  - Doğrusal arama (sequential/linear search) en kötü durumda N karşılaştırma yapar.
  - Binary search'ün olmazsa olmaz koşulu, dizinin sıralı olmasıdır. Sırasız dizide uygulanamaz.
  - Mantık: 0-100 arasında tutulan bir sayıyı "büyük mü, küçük mü" sorularıyla bulmaya benzer. Önce 50 sorulur, büyükse 75, küçükse 62... Her soruda arama aralığı yarıya iner.
  - Akış diyagramı:
    - N, `A[N]` ve aranan X okunur.
    - `first = 1`, `last = N`, `middle = (first + last) DIV 2`.
    - While: `first <= last AND A[middle] ≠ X`.
    - İçeride `X > A[middle]` ise `first = middle + 1`, değilse `last = middle − 1`. Sonra `middle = (first + last) DIV 2`.
    - Döngüden sonra `A[middle] = X` ise `middle` (bulunan yer) yazdırılır, değilse "bulunamadı".
  - Analiz (`1 2 3 4 5 7`, X = 4): first = 1, last = 6, middle = 3, A[3] = 3. 4 > 3 olduğu için first = 4. middle = 5, A[5] = 5. 4 < 5 olduğu için last = 4. middle = 4, A[4] = 4. Bulundu.
  - Analiz (`1 2 3 5 7 8`, X = 4): middle 3, sonra 5, sonra 4 olur. A[4] = 5 ≠ 4 olduğu için last = 3 olur. first > last olduğu için döngü biter. A[middle] ≠ 4 olduğu için "bulunamadı".
  - Karmaşıklık: $\log_2 N$. 8 elemanda 3 adım, 1024 elemanda doğrusal aramadaki 1024 kontrol yerine yaklaşık 10 kontrol.
  - Bir algoritmanın karmaşıklığı Big O notasyonuyla, girdi sayısı cinsinden ifade edilir: $O(1)$, $O(\log N)$, $O(N)$, $O(N \log N)$, $O(N^2)$, $O(N^3)$. Karmaşıklık, algoritmanın ne kadar verimli olduğunu gösterir. N ile log N arasındaki fark, N büyüdükçe çok açılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `first = middle + 1` ve `last = middle − 1` yazılmalıdır. Yalnızca `middle` atanırsa arama aynı noktada takılıp kalabilir.
- Her turda `middle` yeniden hesaplanmalıdır. Akış diyagramında tam sayı bölmesi `DIV` ile yazılmalıdır.
- AND ile bağlanan koşullarda ilk koşul yanlışsa ikinci koşul kontrol edilmez. Bu yüzden sınır kontrolü her zaman önce yazılmalıdır. Önce dizinin o indisine erişme hakkı olup olmadığına, sonra oradaki değere bakılır. Aksi hâlde erişilmemesi gereken bir yere erişilebilir.
- Döngü koşulundaki `first <= last` yerine `first < last` yazılması da doğru çalışır görünüyor. Çıkışta zaten `A[middle] = X` kontrolü yapıldığı için eşitlik bir tur fazla dönmeye yol açar.
- Sıralı dizilerle çalışmak ve log N karmaşıklığında algoritmalar tasarlamak verimliliği çok artırır.
- Sınava kitap ve defter kapalı, soruları kendi başınıza çözerek hazırlanın.
- İkinci sınıftan itibaren hocaların araştırma gruplarına katılmaya çalışın. Ara ve bitirme projelerinde sizi geliştirecek ve CV'nizde iyi duracak konular seçin.

## Kısa Tekrar Notları

- IPv4 32 bit, IPv6 128 bit. ICANN adresleri ve alan adlarını yönetir.
- FTP dosya, SSH güvenli uzak komut satırı, HTTP/HTTPS web, SMTP posta gönderme, POP3 indirme, IMAP sunucuda tutma, MIME ASCII olmayan ekler, VoIP ses.
- 1G analog ses, 2G dijital ses + mesaj, 3G yüksek veri hızı, 4G IP ağı.
- Unicast, multicast, broadcast.
- HTML yapı, CSS görünüm, JavaScript/PHP dinamiklik, XML/JSON veri taşıma.
- Binary search: sıralı dizi şart. `first`, `last`, `middle = (first+last) DIV 2`. Büyükse `first = middle+1`, küçükse `last = middle−1`.
- Doğrusal arama O(N), binary search O(log N).

## Detaylı Açıklamalar

Dönemin son dersidir. Önce dönem projesinin videosuyla ilgili kurallar açıklanır. Ardından ağ konusunun kalan kısımları (IP adresleri, alan adları, internet uygulamaları, mobil haberleşme, akış uygulamaları, web teknolojileri) kısaca anlatılır. Son bölümde binary search algoritması öğrencilere 20 dakika çözdürülür ve birlikte çizilip analiz edilir.

### Binary search'te durma koşulu

Bir öğrenci while yerine do-while kullanmış ve yalnızca `A[middle] ≠ X` koşulunu yazmıştı. Hoca, aranan eleman dizide yoksa döngünün bir noktada durması gerektiğini vurguladı. Bu yüzden ikinci bir koşul gerekir: `first <= last`. Aralık boşaldığında (first last'ı geçtiğinde) eleman dizide yoktur.

Bir başka öğrenci tek koşul kullanıp döngünün içinde ayrıca kontrol yapmayı önerdi. Hoca bunun da çalışacağını söyledi.

### Ders sonrası kontrol

Binary search, 0'dan başlayan indislerle C'ye çevrilip derlendi. Hem `first <= last` hem `first < last` koşuluyla, 1-20 elemanlı 20.000 rastgele sıralı dizide, dizide olan ve olmayan değerler aranarak denendi. İki versiyon da doğru sonuç verdi.

Bir nokta akış diyagramına özeldir. Diyagramda diziler 1'den başlıyor. Aranan değer bütün elemanlardan küçükse döngü `first = 1`, `last = 0` ile biter ve `middle = 0` olur. Çıkıştaki `A[middle] = X` kontrolü bu durumda dizide olmayan `A[0]` gözüne bakar. Kodda bu kontrolden önce `middle`'ın dizinin sınırları içinde olduğunu kontrol etmek güvenlidir. Bu, hocanın vurguladığı "önce sınır kontrolü" kuralının bir örneğidir.

```c
int ara(int A[], int N, int X)          /* bulunursa indis, yoksa -1 */
{
    int first=0,last=N-1,middle=(first+last)/2;
    while(first<=last && A[middle]!=X)
    {
        if(X>A[middle]) first=middle+1;
        else last=middle-1;
        middle=(first+last)/2;
    }
    if(middle>=0 && middle<N && A[middle]==X)
        return middle;
    return -1;
}
```

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
