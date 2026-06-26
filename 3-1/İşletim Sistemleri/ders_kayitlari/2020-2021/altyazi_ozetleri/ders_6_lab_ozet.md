# Ders 6 Lab Çalışma Özeti

## Genel Konular

- Shell Nedir?
  - Shell, kernel (çekirdek) üzerinde çalışan, işletim sistemi servislerine erişilebilen bir program parçasıdır. Kernel komutlarını ve daha fazlasını yapmayı sağlayan programlama dili/kabuk olarak da tanımlanabilir.
  - Farklı shell çeşitleri vardır: Bourne Shell (sh), C Shell, Korn Shell, Bash (Bourne Again Shell), Windows'ta PowerShell.

- Temel Dosya ve Dizin İşlemleri
  - `mkdir`: Yeni dizin oluşturur.
  - `cd`: Dizin değiştirir.
  - `ls`: Dosya ve dizinleri listeler.
  - `rmdir`: Boş dizini siler (dolu dizini silemez).
  - `touch`: Boş bir text dosyası oluşturur.
  - `rm`: Dosya siler.
  - `mv`: Dosya taşıma/yeniden adlandırma.
  - `cat`: Dosya içeriğini terminale yazdırır.
  - `nano`: Terminal tabanlı metin editörü.
  - `man`: Komut için kılavuz (manual) sayfası açar.

- Dosya İzinleri (Permissions)
  - `chmod`: Dosya izinlerini değiştirir.
  - Üç aktör vardır: Dosya sahibi (owner/user), grup (group), diğerleri (others).
  - Üç izin türü: Read (r=4), Write (w=2), Execute (x=1).
  - Örnek: `chmod 777 dosya` → tüm kullanıcılar için tüm izinler.
  - Örnek: `chmod 644 dosya` → sahip rw, grup r, diğerleri r.
  - Dosya tipi: `-` (dosya), `d` (dizin), `l` (sembolik link).
  - SUID bit ile dosya sahibinin yetkileriyle çalıştırma.
  - SGID bit ile grup yetkileriyle çalıştırma.
  - Sticky bit ile sadece sahibi veya root dosyayı silebilir (`/tmp` gibi).

- Pipe ve Yönlendirme
  - `|` (pipe): Bir komutun çıktısını diğerine girdi olarak verir. `ls | grep .txt`
  - `>` (yönlendirme): Çıktıyı dosyaya yazar (üzerine yazar).
  - `>>`: Çıktıyı dosyaya ekler.
  - `<`: Dosyayı komuta girdi olarak verir.

- Kullanıcı ve Grup İşlemleri
  - `sudo useradd`: Yeni kullanıcı oluşturur.
  - `sudo userdel -r`: Kullanıcıyı ev diziniyle birlikte siler.
  - `sudo usermod`: Kullanıcı özelliklerini değiştirir (yetki, grup).
  - `sudo groupadd/groupdel`: Grup oluşturur/siler.

- Shell Script Temelleri
  - `#!/bin/bash`: Shebang satırı, script'in bash ile çalıştırılacağını belirtir.
  - Değişken atama: `degisken=deger` (boşluk olmadan).
  - Erişim: `$degisken` veya `${degisken}`.
  - Özel değişkenler: `$1`, `$2`, ... komut satırı argümanları; `$#` argüman sayısı; `$@` tüm argümanlar; `$?` son komutun çıkış kodu.
  - Koşul ifadeleri: `if [ koşul ]; then ... fi`
  - Karşılaştırma operatörleri: `-eq`, `-ne`, `-gt`, `-lt`, `-ge`, `-le`, `-f` (dosya), `-d` (dizin), `-r` (okunabilir), `-w` (yazılabilir), `-x` (çalıştırılabilir).
  - Döngüler: `for`, `while`, `until`.
  - Backtick (`): Komut çıktısını değişkene atar.

- `echo` Komutu
  - Terminale yazı yazdırır. `echo "Merhaba Dünya"`
  - Çift ve tek tırnak farkı: Çift tırnakta değişkenler yorumlanır, tek tırnakta düz metin olarak alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `rm -rf` Komutunun Tehlikesi
  - Hoca özellikle uyarır: `rm -rf /` komutu root dizininde çalıştırılırsa sistemdeki her şeyi siler. "Mesela şu an rm -rf'yi alsam her şeyim gidecek. Bütün ekran da kapanacak. O yüzden çok tehlikeli bir komut. Kullanırken dikkat edin."

- `chmod` ile İzin Verme
  - "Permission denied" hatası alındığında çözüm `chmod`'dur. Dosya sahibi bile olsa, okuma/yazma hakkı yoksa erişemez.

- `~` (Tilde) İşareti
  - Home dizinini temsil eder. Tilde tuşu (Alt+ı, Türkçe klavyede) ile yazılır. Kullanıcının home dizinine hızlıca gitmek için kullanılır.

- Türkçe Karakter Sorunu
  - Hoca vurgular: Sunumdaki tırnaklar ile Linux'taki tırnaklar farklıdır. Sunumdan kopyalayıp yapıştırmak hata verebilir. Düz çift tırnak (`"`) yerine eğri çift tırnak kullanmamaya dikkat edin.

- Shell vs Tarayıcı
  - JS dosyaları tarayıcıda çalışır, shell'de doğrudan çalışmaz. Shell'de tarayıcı açıp JS çalıştırılabilir ama uğraştırır.

- `touch` Komutu
  - Hoca açıklar: `touch` text dosyası oluşturur (binary değil). Uzantı belirtilmezse uzantısız dosya oluşur, yine de text dosyasıdır.

## Kısa Tekrar Notları

- `ls`, `cd`, `mkdir`, `rm`, `mv`, `cp`, `cat`, `nano`, `chmod` temel komutlar.
- `|` pipe, `>` yönlendirme operatörleri.
- `chmod 777` tüm izinler, `chmod 644` sahip rw, diğerleri r.
- `if [ -f dosya ]; then ... fi` koşul yapısı.
- `$1`, `$2`, `$#`, `$@` shell değişkenleri.
- `rm -rf` çok tehlikeli.
- `/etc/passwd` kullanıcı bilgilerini tutar.
- `~` home dizinini temsil eder.

## Detaylı Açıklamalar

Ders 6 Lab, shell programlamaya giriş niteliğindedir. İki haftaya yayılan içeriğin ilk haftasıdır. Lab asistanı, Linux üzerinde (sanal makinede Ubuntu/Kubuntu) shell komutlarını uygulamalı olarak gösterir.

Temel dizin ve dosya işlemleri uygulamalı olarak gösterilir. `mkdir sample_dir` ile yeni dizin oluşturulur, `cd sample_dir` ile dizine geçilir, `touch sample.txt` ile boş dosya oluşturulur. `ls -l` ile detaylı liste alınır; dosya izinleri, sahibi, boyutu görülür. `cat dosya` ile içerik okunur, `nano dosya` ile düzenlenir. `cd ..` ile üst dizine çıkılır. `rmdir` ile boş dizin silinir, dolu dizin için `rm -rf` kullanılır (dikkatli!).

Dosya izinleri detaylı şekilde anlatılır. Her dosya/dizin için 3 aktör (sahip, grup, diğerleri) × 3 izin (read, write, execute) söz konusudur. `chmod` ile izinler değiştirilir. Sayısal gösterimde: r=4, w=2, x=1, toplamları yazılır. Örneğin `chmod 777` tüm izinler, `chmod 644` ise sahip için rw (6), grup ve diğerleri için r (4) anlamına gelir. `ls -l` çıktısında dosya tipi ilk karakterde görülür: `-` (normal dosya), `d` (dizin), `l` (sembolik link).

Kullanıcı yönetimi komutları açıklanır. `sudo useradd kullanici` yeni kullanıcı oluşturur, `sudo passwd kullanici` şifre atar, `sudo userdel -r kullanici` kullanıcıyı ev dizini ile birlikte siler. Her kullanıcının UID'si vardır; root kullanıcının UID'si 0'dır. `/etc/passwd` dosyası kullanıcı bilgilerini, `/etc/shadow` şifre hash'lerini tutar. `usermod -aG grup kullanici` ile kullanıcı gruba eklenir.

Pipe ve yönlendirme kavramları açıklanır. `|` operatörü bir komutun çıktısını diğerine girdi olarak bağlar. Örneğin `ls | wc -l` dosya sayısını verir, `cat dosya | grep "arama"` dosyada arama yapar. `>` çıktıyı dosyaya yönlendirir (üzerine yazar), `>>` ekler. `<` dosyayı komuta girdi olarak verir.

Shell script'in temelleri ele alınır. `#!/bin/bash` shebang satırı, `echo "mesaj"` ekrana yazar, `degisken="deger"` atama yapar, `$degisken` ile erişilir. `if [ koşul ]; then ... fi` koşul yapısıdır. Koşul ifadelerinde `[ ]` kullanılır. `if [ $# -gt 3 ]` argüman sayısı 3'ten büyük mü kontrol eder. `if [ -f dosya ]` dosya var mı kontrol eder. `if [ -d dizin ]` dizin var mı kontrol eder.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
