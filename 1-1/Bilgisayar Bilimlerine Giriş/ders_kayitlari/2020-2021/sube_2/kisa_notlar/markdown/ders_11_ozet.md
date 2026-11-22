# Ders 11 Çalışma Özeti

## Genel Konular

- İşletim sistemiyle etkileşim yolları
  - Her işletim sistemi kullanıcıya farklı arayüzler sunar: telefonda dokunmatik ekran, masaüstü ve dizüstü bilgisayarda klavye ve fare ile kullanılan grafik arayüz.
  - Bir başka yol kabuktur (shell, komut satırı). Grafik arayüzde yapılan her şey, işletim sistemine doğrudan komut gönderilerek kabuktan da yapılabilir.
  - Ubuntu'da terminal; kenar çubuğundaki kısayoldan, Alt+F2 ile açılan komut penceresine `gnome-terminal` yazarak ya da "Show Applications" içinde "terminal" aratarak açılır. Arama sonucuna sağ tıklayıp "Add to Favorites" denirse sol menüye eklenir.
- Dosya sistemi içinde gezinme
  - `pwd`: terminalin o an dosya sisteminde hangi klasörde olduğunu gösterir. Terminal ana ekrandan açılınca kullanıcının ev klasöründe (`/home/<kullanıcı_adı>`) başlar (ekrandan, 00:25:00).
  - `ls` (list): dosya ve klasörleri listeler. Komut adları genelde yaptıkları işin kısaltmasıdır: `ls` list, `mv` move, `cd` change directory.
  - `cd Desktop/`: klasör değiştirir. Adın ilk harfleri yazılıp Tab'a basılırsa ad otomatik tamamlanır.
  - `ls -la`: `-l` sonucu uzun liste biçiminde, `-a` gizli dosyalarla birlikte verir. Adı nokta ile başlayan dosya ve klasörler gizlidir (`.bashrc`, `.cache`, `.config`, `.profile` gibi; ekrandan, 00:30:00). Bunlar uygulamaların geçici dosyalarını ve kullanıcı profiline ait ayarları tutar, kullanıcının elle değiştirmesi beklenmez.
- Mutlak ve göreli yol
  - Mutlak yol `/` (kök) ile başlar: `ls -la /home/<kullanıcı_adı>/`.
  - Göreli yol bulunulan klasöre göre verilir. `.` bulunulan klasörü, `..` bir üst klasörü gösterir. Masaüstündeyken `ls -la ../` ev klasörünü listeler; çıktı mutlak yolla alınan listeyle aynıdır (ekrandan, 00:30:00).
  - `ls`'e yol verilmezse bulunulan klasör listelenir; başka bir yol verilirse (örn. `/tmp`) o klasör listelenir.
- Dosya işlemleri (ekrandan, 00:35:00)
  - `touch test.txt`: boş dosya oluşturur.
  - `mv test.txt ../`: dosyayı bir üst klasöre taşır; `mv ../test.txt .`: geri getirir.
  - `cp test.txt ../`: üst klasörde bir kopyasını oluşturur.
  - `rm ../test.txt`, `rm test.txt`: verilen yoldaki (mutlak ya da göreli) dosyayı siler.
- Dosya adı, uzantı ve dosya türü
  - Dosya adı, noktadan önceki ad kısmı ve uzantıdan oluşur. Hoca bunun DOS'un 8+3 düzeninden geldiğini, bugün 255+3 biçiminde sürdüğünü söyledi.
  - Uzantı, masaüstü yöneticisinin dosyayı nasıl göstereceğini ve insanın dosyanın ne olduğunu anlamasını kolaylaştırır. Dosyanın türünü belirlemez: `.txt` dosyasının uzantısını `.jpg` yapmak içeriğini değiştirmez. Virüs saldırılarında resim uzantılı ama çalıştırılabilir dosyalar bu yüzden gönderilir.
  - `file` komutu içeriğe bakar. `first.c` ve onun kopyası `text.txt` için ikisinde de `C source, ASCII text` sonucunu verdi (ekrandan, 00:40:00).
- Editör ve derleyici
  - Derste editör olarak gedit, derleyici olarak GCC (GNU C Compiler) kullanılacak. gedit, Alt+F2 ile açılan pencereye `gedit` yazılarak çalıştırılır.
  - Hello World programı yazılıp `first.c` olarak kaydedilince gedit sözdizimini renklendirmeye başladı; uzantıdan bunun bir C programı olduğunu anladı. Aynı içerik `text.txt` adıyla kopyalanınca renklendirme olmadı.
- Dosya içeriğine bakma ve yardım
  - `cat first.c`: dosya içeriğini ekrana yazar.
  - `wc text.txt`: satır, kelime ve karakter sayısını verir. Derste çıktı `10 10 79 text.txt` oldu (ekrandan, 00:45:00).
  - `man wc`: komutun nasıl çalıştığını, parametrelerini ve çıktısını anlatan kılavuz sayfası. Space ile ilerlenir, `q` ile çıkılır. `man man` man'in kendi kılavuzudur. `man cd` için "No manual entry for cd" çıktı.
- Klasör işlemleri (ekrandan, 00:45:00)
  - `mkdir First`, `mkdir FiRst`, `mkdir FiRsT` üç ayrı klasör oluşturdu: Linux dosya sisteminde büyük-küçük harf ayrımı vardır (case sensitive).
  - `rm FiRst/` "Is a directory" hatası verir. Klasörü `rm` ile silmek için `-r` (recursive) gerekir; daha sade yol `rmdir <klasör>` kullanmaktır.
- Süreçleri izleme
  - `ps`: yalnız o terminalde çalışan süreçleri gösterir. `ps -ef`: sistemdeki bütün süreçleri gösterir.
  - `top`: çalışan süreçleri işlemci ve bellek kullanımına göre sıralı gösterir; süreç sahibi kullanıcıyı, toplam bellek ve işlemci kullanımını da verir (ekrandan, 00:50:00).
  - Terminal bir tampondur; geriye doğru belli bir sınıra kadar eski çıktılar görülebilir. Yukarı/aşağı ok tuşları önceki komutlarda gezdirir, Ctrl+R eski komutlar arasında arama yapar.
- Log izleme: `tail`
  - `tail <dosya>` dosyanın son 10 satırını gösterir; `-n` ile sayı değiştirilir (örn. 100).
  - `tail /var/log/syslog`: sistem olaylarının, uyarıların, bilgilerin ve hataların düştüğü log dosyasının sonunu gösterir.
  - `tail -f` dosyayı izlemeye devam eder. Derste yeni bir terminal açılınca loga "Started VTE child process 4958 launched by gnome-terminal-server process 3913" satırı düştü (ekrandan, 00:55:00).
  - Çalışmakta olan süreç başka terminalden `kill` ile ya da kendi terminalinde Ctrl+C ile durdurulur.
- Boru hattı (pipe) ve filtreleme
  - Bir komutun ekrana düşecek çıktısı `|` ile başka bir komuta aktarılır. Türkçe Q klavyede `|`, AltGr ile sol Shift'in yanındaki `<>` tuşuna birlikte basılarak yazılır.
  - `grep <kelime>`: çıktıdan o kelimenin geçtiği satırları ayıklar ve eşleşmeyi renkli gösterir.
  - `more`: çıktıda Enter ile satır satır, Space ile sayfa sayfa ilerletir.
  - Derste kullanılan zincir: `ps -ef | grep <kullanıcı_adı> | more`.
- Paket kurulumu ve GCC
  - `gcc` yazılınca "Command 'gcc' not found, but can be installed with: sudo apt install gcc" mesajı geldi. Yanlış yazılan bir komutta (`gyh`) terminal benzer komutları önerdi (ekrandan, 01:00:00).
  - Ubuntu bir dağıtımdır: Linux çekirdeği ve sistem yazılımları alınır, çevresine sistem uygulamaları ve dağıtıcının kendi uygulamaları eklenir, bir paket olarak sunulur. Küçük değişiklikler güncellemeyle, çekirdek ya da temel sistem paketlerindeki büyük değişiklikler yeni sürümle gelir.
  - Hoca sürümlerden çift sayıların kararlı, tek sayıların test sürümü olduğunu söyledi. LTS (Long Term Support) ibaresi üreticinin o sürümü uzun süre destekleyeceğini gösterir; 18.04 LTS hâlâ güncelleme alır.
  - Ubuntu, Debian'ın paket biçimini (deb, dpkg) kullanır: önceden derlenmiş ikili dosya, gerekli dosyalarla birlikte paketlenir ve kurulumda ilgili yerlere otomatik yerleştirilir. Alternatif, kaynak kodu derleyip ikiliyi `bin` altına, ayar dosyasını `etc` altına koymak, `var/log` altında klasör açıp izinleri ayarlamak gibi işleri elle yapmaktır.
  - Uygulama kurmak yönetimsel bir iştir, root yetkisi gerekir: `sudo apt install gcc`. Sorulan şifre, kurulumda verilen kullanıcı şifresidir.
  - Paketler arasında bağımlılık (dependency) vardır. Kurulum aracı dağıtıcının deposundaki (repository) bilgilere bakıp gerekli paketleri (binutils, cpp-9, gcc-9 vb.) bulur, indirir ve kurar (ekrandan, 01:05:00). Ekranda "9 upgraded, 21 newly installed" ve "Need to get 28,7 MB/36,9 MB of archives" görüldü.
  - APT ilk kez çalıştırıldığı için önce `sudo apt update` ile depo bilgileri güncellendi, sonra kurulum tekrarlandı ve tamamlandı (ekrandan, 01:10:00).
- VMware'de internet bağlantısı
  - Varsayılan oluşturulan sanal makinede internet bağlantısı vardır. Yoksa Virtual Machine Settings > Network Adapter bölümünde aygıtın bağlı (Connected, Connect at power on) olduğu kontrol edilir. Bağlantı NAT olarak bırakılırsa, bilgisayarın interneti varsa sanal makinenin de interneti olur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Komut satırı neden gösteriliyor
  - Grafik arayüzle de aynı işler yapılabilir. Ama sistemin çalışma mantığını görmek için komut satırında alıştırma yapmak gerekir. Sunucular ve asıl bilgisayar sistemleri hâlâ bu yolla yönetilir; orada editör seçenekleri de sınırlıdır.
- İş içeriktedir, uzantıda değil
  - Uzantı insanın ve editörün işini kolaylaştırır. Dosyanın ne olduğunu sistem içeriğe bakarak anlar (`file` komutu).
- Kılavuz sayfalarını okumak
  - Derste komutların yalnız en basit kullanımı gösterildi. `man` sayfalarında çok daha fazla seçenek vardır; ara ara okumakta fayda var.
- GCC kurulmuş olmalı
  - İlerideki laboratuvarlarda C ile kod yazılacağı için GCC kurulumu önceden tamamlanmalı, son dakikaya bırakılmamalı.
- Sorun bildirirken bilgi vermek
  - "Çalışmıyor" demek yerine hata mesajı ya da ekran çıktısı paylaşılmalı; sorun ancak ipucu ve bilgiyle çözülür.
- for ve while seçimi
  - Tekrar sayısı biliniyorsa for, bir koşul sağlanana kadar dönülecekse while kullanılır.

## Kısa Tekrar Notları

- `pwd` bulunulan klasör, `ls` liste, `ls -la` uzun liste + gizli dosyalar, `cd` klasör değiştir, Tab otomatik tamamla.
- Mutlak yol `/` ile başlar; göreli yolda `.` bulunulan, `..` üst klasör.
- `touch` dosya oluştur, `mv` taşı, `cp` kopyala, `rm` sil, `mkdir` klasör oluştur, `rmdir` klasör sil, `rm -r` klasörü içiyle sil.
- Nokta ile başlayan adlar gizlidir.
- Uzantı dosya türünü belirlemez; `file` içeriğe bakar.
- `cat` içeriği yazar, `wc` satır/kelime/karakter sayar, `man` kılavuzu açar (Space ilerle, `q` çık).
- Linux dosya sisteminde büyük-küçük harf farklıdır.
- `ps`, `ps -ef`, `top` süreçleri gösterir; `kill` ya da Ctrl+C süreci durdurur.
- `tail` son 10 satır, `-n` satır sayısı, `-f` izlemeyi sürdür; `/var/log/syslog` sistem logu.
- `|` çıktıyı başka komuta aktarır; `grep` süzer, `more` sayfalar.
- Ok tuşları komut geçmişi, Ctrl+R geçmişte arama.
- `sudo apt update`, `sudo apt install gcc`; apt bağımlılıkları kendisi çözer.
- LTS = uzun süreli destek.
- VMware ağ bağdaştırıcısı NAT ise sanal makine ana bilgisayarın internetini kullanır.

## Detaylı Açıklamalar

- Bu laboratuvar oturumunda, önceki hafta VMware üzerine kurulan Ubuntu sisteminde Linux ve Unix'te ortak olan temel komutlar uygulamalı gösterildi. Amaç, ilerideki derslerde C kodu yazmaya, derlemeye ve çalıştırmaya hazır bir ortam kurmaktı.
- Gezinme için önce `pwd` ile ev klasöründe olunduğu görüldü, `ls` ile Desktop, Documents, Downloads, Music, Pictures, Public, Templates ve Videos klasörleri listelendi. `cd Desktop/` ile masaüstüne geçildi; masaüstü boş olduğu için `ls` bir şey göstermedi. `ls -la` çıktısında ise her zaman `.` (bulunulan klasör) ve `..` (üst klasör) satırları görülür (ekrandan, 00:25:00). Ev klasörü `ls -la` ile listelenince adı nokta ile başlayan gizli dosyalar ortaya çıktı. Aynı liste hem mutlak yolla hem `ls -la ../` göreli yoluyla alındı ve iki çıktının aynı olduğu gösterildi.
- Dosya işlemleri sırasıyla şöyle yapıldı (ekrandan, 00:35:00):

```text
touch test.txt       # masaüstünde boş dosya
mv test.txt ../      # ev klasörüne taşı
mv ../test.txt .     # geri getir
cp test.txt ../      # ev klasörüne kopyala
rm ../test.txt       # kopyayı sil
rm test.txt          # aslını sil
```

- Ardından gedit'te bir Hello World programı yazıldı ve masaüstüne `first.c` adıyla kaydedildi (ekrandan, 00:45:00; `cat first.c` çıktısı):

```c
#include <stdio.h>

int main(void)  {


	printf("Hello World");


	return 0;
}
```

  Bu kod ajan tarafından `gcc -Wall` ile derlenip çalıştırıldı ve `Hello World` yazdı. Girinti sekme karakteriyle yazıldığında bu dosyaya `wc` aynı sonucu (`10 10 79`) veriyor: 10 satır, 10 kelime (`printf("Hello` ve `World");` iki ayrı kelime sayılır), 79 karakter.
- `cp first.c text.txt` ile aynı içerik `.txt` uzantısıyla kopyalandı. gedit `.c` dosyasını renklendirdi, `.txt` dosyasını düz metin gibi gösterdi. Ama `file first.c` ve `file text.txt` ikisi için de `C source, ASCII text` dedi (ekrandan, 00:40:00). Buradan çıkan sonuç: uzantı yalnız insana ve uygulamalara bir ipucudur, dosyanın türü içeriğindedir.
- `mkdir` ile `First`, `FiRst`, `FiRsT` adlı üç klasör oluşturulabildi, çünkü Linux'ta adlar büyük-küçük harfe duyarlıdır. `rm FiRst/` komutu `rm: cannot remove 'FiRst/': Is a directory` hatasını verdi (ekrandan, 00:45:00). Hoca klasör silmek için `rm -r` yerine `rmdir`'i önerdi. Sonunda `first.c` `First` klasörüne taşındı, `text.txt` silindi.
- Sistem yönetimine yakın komutlarda `top` çıktısında süreçlerin PID, kullanıcı, öncelik, bellek, %CPU, %MEM ve komut sütunları görüldü (ekrandan, 00:50:00). `tail -f /var/log/syslog` açıkken yeni bir terminal açılıp kapatılınca loga ilgili satırlar düştü. `tail -f` arka planda çalışmayı sürdürdüğü için başka bir terminalde `ps -ef` ile görülebildi; `kill` ile ya da Ctrl+C ile sonlandırıldı (ekrandan, 00:55:00).
- Çok uzun çıktılar boru hattıyla işlenir: `ps -ef` çıktısı `grep` ile kullanıcının kendi süreçlerine indirildi, bu da `more` ile sayfa sayfa okundu.
- GCC sistemde kurulu değildi. Terminal, komutun hangi paketle kurulabileceğini söyledi. `sudo apt install gcc` komutu ek paketleri ve bağımlılıkları listeleyip onay istedi (ekrandan, 01:05:00). Depo bilgileri eski olduğu için önce `sudo apt update` çalıştırıldı, sonra kurulum tamamlandı ve son satırda `Setting up gcc (4:9.3.0-1ubuntu2)` görüldü (ekrandan, 01:10:00).
- Ders sonrası not: Hoca Ubuntu'da çift sayılı sürümlerin kararlı, tek sayılıların test sürümü olduğunu söyledi. Ubuntu sürüm numarası büyük olasılıkla yıl.ay biçimindedir (20.04 = 2020 Nisan). LTS sürümleri çift yılların Nisan sürümleridir; aradaki sürümler (20.10, 21.04 gibi) test sürümü değil, desteği kısa süren (yaklaşık 9 ay) normal sürümlerdir.
- Ders sonrası not: Hoca `man cd` için kılavuz olmamasını komutun çok basit olmasına bağladı. Asıl neden büyük olasılıkla `cd`'nin ayrı bir program değil, kabuğun yerleşik (builtin) komutu olmasıdır; bilgisi `help cd` ile alınır.
- Ders sonrası not: Hoca adların bugün "255+3" düzeninde olduğunu söyledi. Linux'un ext4 dosya sisteminde büyük olasılıkla 255 bayt sınırı uzantı dahil bütün dosya adı içindir; uzantı ayrı bir alan değil, adın bir parçasıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
