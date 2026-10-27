# Ders 15 Çalışma Özeti

## Genel Konular

- Dersin tarihi 9 Kasım 2021 Salı. Ders Zoom üzerinden yapıldı.
  - Bu kayıt bir uygulama (laboratuvar) oturumudur. Oturumu dersin hocası değil, uygulamayı yürüten bir öğretim elemanı anlatıyor. Dersin hocası oturumu açıp yönetimi ona devrediyor.
  - Asıl anlatım yaklaşık 00:20'de başlar. İlk 20 dakika katılım bekleme ve öğrenci sorularıdır.
  - Uygulamaya dersin üç grubu (Grup 1, 2, 3) birlikte katıldı.
- Uygulamaların dönem planı
  - Toplam beş uygulama olacak: kabuk (shell) programlama (iki hafta), süreçler arası iletişim (interprocess communication), iş parçacıkları (thread) ve çekirdek modülü (kernel module).
  - Değerlendirme şekli henüz belli değil. Uygulamalardan bir proje verilebilir ya da uygulama içerikleri sınav sorusu olabilir.
- Kabuk (shell) nedir?
  - Çekirdek (kernel): dosya, süreç, bellek, G/Ç ve aygıt yönetimini yapan işletim sistemi çekirdeği.
  - Kabuk: işletim sistemi servislerine erişmek için kullanılan program. Örnekler: BASH (Bourne Again Shell), CSH (C Shell), KSH (Korn Shell), Windows'ta PowerShell.
  - Anlatım Ubuntu üzerinde BASH ile yapıldı. Komutlar dağıtımdan bağımsızdır.
- Temel dosya ve klasör komutları
  - `ls`, `mkdir`, `touch`, `cd`, `rm`, `rmdir`, `rm -r`, `mkdir -p`, `mv`, `cat`, `nano`, `gedit`, `clear`.
- Kullanıcı ve grup yönetimi
  - `sudo` ile yönetici (root) yetkisi; `useradd`, `usermod`, `userdel`, `groupadd`, `groupdel`.
- Dosya izinleri
  - `ls -l` çıktısı, dosya tipi karakteri, okuma-yazma-çalıştırma (rwx) izinleri, `chmod` ve `chown`.
- Kabuk programlamaya giriş
  - `echo` ve `echo -e` ile kaçış dizileri.
  - Sistem değişkenleri (`$USER`, `$HOME`, `$PWD`, `$COLUMNS`, `$LINES`) ve kullanıcı değişkenleri.
  - Aritmetik işlemler (`expr`), kullanıcıdan veri alma (`read`), joker karakterler (`*`, `?`).
  - Dosyaya yazma (`>`) ve sona ekleme (`>>`).

## Hocanın Özellikle Vurguladığı Kısımlar

- Uygulamalara katılmanız şiddetle tavsiye ediliyor.
  - Uygulamalardan değerlendirileceksiniz: laboratuvar, proje ya da sınav sorusu olabilir.
  - Laboratuvar takvimi AVESİS'te paylaşıldı. Takvim değişebilir, sürekli takip edin.
- Devamlılık önemli değil. Birkaç kişi aynı bilgisayardan izleyebilir.
- `chmod` ve `chown` komutlarını çok sık kullanacaksınız.
  - Yetkiniz olmayan bir dosyada işlem yapınca "permission denied" hatası alırsınız. Çözüm, dosyaya uygun izni vermektir.
  - Kullanıcı ekleme ve silme komutları o kadar önemli değil.
- Değişken tanımlarken başına `$` konmaz. Değişkenin değerini kullanırken başına `$` konur.
  - Bu başlangıçta çok unutulan bir ayrıntı.
- Sistem değişkenleri büyük harfle yazılır. Kendi değişkenlerinizi küçük harfle yazın.
  - Sistemi kullanan tek kişi siz olmadığınız için karışıklık olmasın.
- Kaçış dizilerinin (`\n`, `\t` gibi) çalışması için `echo -e` gerekir.
  - Slaytta bu parametre eksik; doğrusu `-e` eklemektir.
- `expr` içinde çarpma için `\*` yazılır, yani yıldız kaçış karakteriyle yazılır.
- Tek `>` dosyanın içeriğini silip baştan yazar (write). Çift `>>` sona ekler (append).

## Kısa Tekrar Notları

- `ls`: bulunulan klasördeki dosyaları listeler. `ls -l`: izinler, sahip, grup, tarih gibi ayrıntıları da gösterir.
- `mkdir klasor`: klasör oluşturur. `mkdir -p a/b`: iç içe klasörleri tek seferde oluşturur.
- `touch dosya`: boş dosya oluşturur.
- `cd klasor`: klasöre geçer. `cd ..`: bir üst klasöre çıkar. `.` bulunulan klasördür.
- `rm dosya`: dosya siler. `rmdir klasor`: yalnız boş klasörü siler. `rm -r klasor`: klasörü içindekilerle birlikte siler.
- `mv kaynak hedef`: dosyayı taşır. Aynı komut dosyanın adını değiştirmek için de kullanılır.
- `cat dosya`: dosyanın içeriğini ekrana yazar.
- `nano`: terminalde metin düzenleyici. `gedit`: grafik arayüzlü metin düzenleyici.
- Tab tuşu dosya ve klasör adını tamamlar.
- İzin dizisi: ilk karakter dosya tipi (`-` dosya, `d` klasör, `l` sembolik bağ, `c` karakter aygıtı, `b` blok aygıtı, `p` adlandırılmış boru, `s` soket). Sonra sahip, grup ve diğerleri için üçer karakter (`rwx`).
- `chmod 777 dosya`: herkese bütün izinler. `chmod 000 dosya`: bütün izinleri kaldırır.
  - Her rakam 3 bittir (r=4, w=2, x=1), bu yüzden 0-7 arası olur. `99` geçersizdir.
- `echo -e` kaçış dizileri: `\a` uyarı sesi, `\b` geri silme, `\c` sonraki çıktıyı keser, `\n` yeni satır, `\r` satır başı, `\t` sekme, `\\` ters eğik çizgi.
- `set`: bütün kabuk değişkenlerini listeler.
- `expr 1 + 2` → 3; `expr 3 \* 4` → 12; `expr 13 % 3` → 1.
- Komut çıktısını değişkene ya da `echo`'ya koymak için ters tırnak (backtick) kullanılır: `` `komut` ``.
- `read ad`: kullanıcıdan değer okur, C'deki `scanf`'e benzer.
- Joker karakterler: `*` sıfır ya da daha çok herhangi karakter, `?` tam olarak bir karakter.
  - `ls *.py`: `.py` ile biten dosyalar. `ls 1*`: 1 ile başlayan dosyalar.

## Detaylı Açıklamalar

Kabuk, kullanıcı ile çekirdek arasında duran programdır. Kullanıcı komut yazar, kabuk bu komutu çekirdeğin servislerine iletir. Kabuk betikleri (shell script) bu komutları bir dosyada toplar ve sırayla çalıştırır. Ubuntu kurulduğunda Python gelmeyebilir, ama kabuk her zaman gelir. Bu yüzden kabuk betiği hiçbir şey kurmadan yazılıp çalıştırılabilir.

**Dosya ve klasör işlemleri.** Uygulamada önce bir klasör oluşturuldu, içine `touch` ile dosya kondu, sonra dosya `rm` ile silindi. `rmdir` yalnızca boş klasörü siler. Klasörün içinde dosya varken `rmdir` hata verir. İçindekilerle birlikte silmek için `rm -r` kullanılır. İç içe klasör oluşturmak için `mkdir -p` gerekir; bunu bir öğrenci önerdi ve derste denendi.

**Kullanıcı ve grup yönetimi.** Yönetici işlemleri `sudo` ile yapılır. Kullanıcı eklemek için `useradd`, değiştirmek için `usermod`, silmek için `userdel` kullanılır. Gruplar için `groupadd`, `groupdel` ve `usermod -aG grup kullanıcı` kullanılır. Bir grubun var olup olmadığını görmek için `cat /etc/group | grep grup` yazılır. Slaytta `grep`'in önündeki boru (`|`) işareti yanlışlıkla `/` olarak yazılmış; derste düzeltildi.

**Dosya izinleri.** `ls -l` çıktısında ilk karakter dosya tipini gösterir. Sonraki dokuz karakter sırayla sahip (user), grup (group) ve diğerleri (others) için okuma, yazma, çalıştırma izinleridir. `-` işareti o iznin verilmediğini gösterir. `chmod` ile izinler sayıyla verilir. Her basamak 3 bittir, bu yüzden 0-7 arası değer alır. Örnek: `chmod 000 dosya` sonrasında `cat dosya` "permission denied" hatası verir. `chmod 777 dosya` herkese bütün izinleri verir.

**Değişkenler.** Kabukta iki tür değişken vardır: sistemle gelen sistem (ortam) değişkenleri ve kullanıcının tanımladığı değişkenler. Sistem değişkenleri programların birbirleriyle haberleşmesinde ve kurulumlarda kullanılır; örneğin Java'nın yolu bu değişkenlerle belirlenir. Derste `HTTP_PROXY` değişkeninin bir proxy aracı için tanımlı olduğu gösterildi.

```bash
degisken1=10
degisken2="deneme"
degisken3=deneme
degisken4=`pwd`
echo $degisken1 $degisken2 $degisken3 $degisken4
```

- Atama yaparken `=` çevresinde boşluk olmamalıdır.
- Tırnaklı ve tırnaksız string ikisi de çalışır.
- Değişken adları büyük-küçük harfe duyarlıdır.

**Aritmetik ve joker karakterler.** `expr 3 \* 4` yazılır, çünkü `*` kabukta joker karakterdir. Kaçış karakteri yazılmazsa kabuk yıldızı dosya adlarıyla genişletir. Bir öğrenci de bunu söyledi: yıldız klasördeki her şeyi seçebilir.

**Yazma ve sona ekleme.** Derste bir dosyaya sırayla `echo 1 > dosya`, `echo 3 > dosya`, `echo 1 >> dosya`, `echo 5 >> dosya` yazıldı. Sonuç `3 1 5` oldu. Nedeni: ikinci `>` dosyayı silip baştan yazdı, sonraki iki `>>` sona ekledi.

### Ders sonrası notlar

- Derste "tek nokta şu anki klasördeki bütün dosyalar, any demek" dendi. Bu yanlış. `.` bulunulan klasördür, `..` üst klasördür. "Bütün dosyalar" anlamı `*` joker karakterine aittir.
- Derste `\c` için "clear demek" dendi. Bu yanlış. `echo -e` içinde `\c` kendisinden sonraki çıktıyı keser ve sona yeni satır eklemez. Ekranı temizleyen komut `clear`'dır.
- Derste Ubuntu'da `dir` komutunun bir takma ad (alias) olduğu söylendi. Aslında `dir`, GNU coreutils içinde ayrı bir komuttur.
- Derste `chmod 000` sonrası `nano`'nun dosyayı açması için "nano otomatik root yetkisiyle açılıyor" dendi. Bu yanlış. `nano` kullanıcının yetkisiyle çalışır. Dosyayı okuyamaz ve kaydedemez; yalnızca boş bir tampon açar.
- Değişkenin başındaki `$`, C'deki adres ya da `%d` gibi biçim belirteciyle aynı şey değildir. `$` değişkenin değerinin yerine konmasını (genişletme, expansion) sağlar. Derste anlaşılır olsun diye bu benzetme yapıldı.
- Joker karakter `?` tam olarak bir karakterdir. Düzenli ifadelerde (regex) `?` "önceki öğe sıfır ya da bir kez" anlamına gelir; herhangi bir karakter ise `.` ile gösterilir. Derste ikisi aynıymış gibi anlatıldı.
- `set` bütün kabuk değişkenlerini ve fonksiyonlarını listeler. Yalnızca ortam değişkenlerini görmek için `env` ya da `printenv` kullanılır.
- Derste kullanıcıları listeleyen dosya hatırlanamadı. Kullanıcılar `/etc/passwd` dosyasındadır. Ders 17'de bu konu tekrar ele alınıyor.
- Ters tırnak yerine bugün daha çok `$(komut)` biçimi kullanılır. İkisi aynı işi yapar.
- Altyazıdaki "5", "beş" ve "şart programı" ifadeleri "shell" ve "shell programı", "AWS" ise AVESİS demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
