# Ders 7 Lab Çalışma Özeti

## Genel Konular

- tr (Translate) Komutu
  - Metin editörlerindeki replace (değiştirme) işlemlerini komut satırında yapar.
  - Case-sensitive/insensitive dönüşümü, karakter değiştirme, karakter silme gibi işlemler yapabilir.
  - Kullanım: `cat dosya | tr 'a-z' 'A-Z'` (küçük harfleri büyüğe çevirir).
  - `tr ';' ','` (noktalı virgülü virgüle çevirir).
  - `tr -d ';'` (noktalı virgülü siler).

- awk Komutu
  - CSV gibi yapılandırılmış dosyaları parse etmek için kullanılır.
  - Alanlara göre filtreleme, dönüştürme yapabilir.
  - `awk -F';' '$2 > 3 {print $0}' dosya` (noktalı virgülle ayrılmış, ikinci kolonu 3'ten büyük olan satırları yazdır).
  - `$1` birinci kolon, `$2` ikinci kolon, `$0` tüm satır.
  - `awk -F'delim' 'şart {eylem}' dosya` temel sözdizimi.

- bc (Basic Calculator) Komutu
  - Komut satırında hesap makinesi olarak çalışır.
  - `bc` yazıp Enter ile hesap makinesi açılır; çıkmak için `quit`.
  - Karşılaştırma operatörleri: `3 > 1` (doğruysa 1, yanlışsa 0 döner).
  - Atama: `x = 5`, `x = x + 1`.
  - Mantıksal operatörler: `&&` (ve), `||` (veya), `!` (değil).
  - `echo "scale=4; 22/7" | bc` pipe ile kullanım.
  - Logaritma, üstel fonksiyonlar için `-l` bayrağı (`bc -l`).

- Shell Script Argümanları
  - `$1`, `$2`, ..., `$9`: Komut satırı argümanları.
  - `\\$#`: Argüman sayısı.
  - `$@`: Tüm argümanlar.
  - `$?`: Son komutun çıkış kodu (exit code).
  - `$$`: Shell'in PID'si.

- if Koşul Yapıları
  - `if [ koşul ]; then ... elif [ koşul ]; then ... else ... fi` temel yapısı.
  - Karşılaştırma operatörleri: `-eq` (eşit), `-ne` (eşit değil), `-gt` (büyük), `-lt` (küçük), `-ge` (büyük eşit), `-le` (küçük eşit).
  - Dosya testleri: `-f` (dosya), `-d` (dizin), `-r` (okunabilir), `-w` (yazılabilir), `-x` (çalıştırılabilir).
  - `if [ -f dosya ]` dosya var mı, `if [ -d dizin ]` dizin var mı.
  - Mantıksal operatörler: `&&` (ve), `||` (veya).
  - Tek satır if: `[ \\$# -gt 3 ] && echo "..."`

- Döngüler (Loops)
  - `for` döngüsü:
    - `for i in 1 2 3 4 5; do echo $i; done` (1'den 5'e kadar).
    - `for i in {1..5}; do echo $i; done` (range ile).
    - `for i in {1..10..2}; do echo $i; done` (1, 3, 5, 7, 9 - 2'şer artarak).
    - `for dosya in $(ls); do echo $dosya; done` (ls çıktısı üzerinde).
    - `for dosya in *; do ... done` (mevcut dizindeki tüm dosyalar).
  - `while` döngüsü:
    - `while [ koşul ]; do ... done` (koşul doğru olduğu sürece).
  - `until` döngüsü:
    - `until [ koşul ]; do ... done` (koşul yanlış olduğu sürece).

- Dosya Tipleri ve İzinler
  - `ls -la`: Detaylı liste.
  - Dosya tipi: `-` (dosya), `d` (dizin), `l` (link), `b` (block), `c` (character), `p` (pipe), `s` (socket).
  - `-F` veya `ls -d` ile dizinleri belirginleştirme.

- awk ile Veri İşleme
  - `awk -F';' '{print $1, $2}'` belirli kolonları yazdırır.
  - `awk -F';' 'NR==1 {print $1}'` belirli satırdaki veriyi alır.
  - `awk` içinde `printf` ile formatlı çıktı.
  - `awk` ile toplam, ortalama hesaplama.
  - `awk -F';' '{sum += $2} END {print sum}'` toplam hesaplar.

## Hocanın Özellikle Vurguladığı Kısımlar

- tr Komutunun Kullanım Alanları
  - Hoca vurgular: tr komutu normal editörde yapılan replace işlemlerini (bul-değiştir, büyük-küçük harf dönüşümü, silme) komut satırında yapmayı sağlar. Script içinde otomasyon için çok kullanışlıdır.

- awk'ın Gücü
  - "awk komutunda farklı parametreler de var. Bu find parametresi. Noktalı bilgilerle delimetr'i ayrıca belirtmemiz gerekiyor. Delimetrimiz noktalı virgül. Daha sonra noktalı virgülden parçaları her bir parçayı bir değişken atıyor." Hoca awk'ın parse yeteneğini vurgular.

- \$# ile Argüman Sayısı Kontrolü
  - "Number of anlamına gelir. Bir şeyin sayısıdır aslında. Polar da koyduğunuz zaman bu aslında programa gönderdiğiniz argümanların sayısı. Parametrelerin sayısı demek." Hoca `\$#` değişkeninin önemini vurgular.

- if Koşul Yapısının Sözdizimi
  - Hoca açıkça ifade eder: "if'ten sonra bir `den` gelmesi gerekiyor. if condition'ımız, den, gerek komutlarımız, as, gerek komutlarımız ve fi ile bitiyor. Çünkü parantez olmadığı için if'in bitişini fi ile bitiriyoruz."

- Döngü Sözdizimi Kolaylığı
  - "C'de değişken hatırlamamız gerekiyor, sonra condition geliyor, sonra da artırım ifadesi geliyor. Şu 13. satırda verilen condition gibi. Ama Shell'de çok daha basit bir söz dizimi söz konusu. For e in 1-2-3-4-5 demek 1'den 5'e kadar dönmek, döngü başlatmak demek."

- JS Shell'de Çalışmaz
  - "JS dosyasını çalıştırmak için bir browser ihtiyacın olacaktır. Çünkü JS dosyaları browser tarafından tanımlanıyor, browser tarafından çalıştırılıyor. Bir browser ihtiyacın olacaktır. Ama Shell ile bir browser açıp o browserdan da JS dosyasını çalıştırabilirsin."

- -V Bayrağı (Verbose)
  - Hoca açıklar: "Çizgi V var. Writeable, readable demek. Eğer bir dosya okunabilirse çizgi V ile bu şekilde kontrol edebilirsiniz."

## Kısa Tekrar Notları

- `tr`: karakter dönüşümü/silme.
- `awk`: CSV parse, alan filtreleme (`$1`, `$2`, `$0`).
- `bc`: komut satırı hesap makinesi.
- `if [ koşul ]; then ... fi`: koşul yapısı.
- `for i in {1..5}; do ... done`: döngü.
- `while [ koşul ]; do ... done`: döngü.
- `\$#`: argüman sayısı.
- `-eq, -ne, -gt, -lt`: sayısal karşılaştırma.
- `-f, -d, -r, -w, -x`: dosya testleri.

## Detaylı Açıklamalar

Ders 7 Lab, shell script programlamanın ileri konularını ele alır. Geçen haftaki temel komutlardan sonra, metin işleme, koşul yapıları ve döngüler anlatılır.

`tr` (translate) komutu, metin üzerinde karakter bazlı dönüşüm yapar. `tr 'a-z' 'A-Z'` tüm küçük harfleri büyüğe çevirir. `tr ';' ','` noktalı virgülü virgüle değiştirir. `tr -d ';'` noktalı virgülü siler. Pipe ile birlikte kullanıldığında çok güçlüdür: `cat dosya | tr 'a-z' 'A-Z'` dosyadaki tüm küçük harfleri büyüğe çevirir.

`awk` komutu, yapılandırılmış metin dosyalarını (özellikle CSV) işlemek için kullanılır. `-F` bayrağı ile alan ayracı belirlenir (`-F';'` noktalı virgül için). `$1` birinci alan, `$2` ikinci alan, `$0` tüm satır anlamına gelir. Koşullu ifadeler: `awk -F';' '$2 > 3 {print $0}'` ikinci alanı 3'ten büyük olan satırları yazdırır. `END {print sum}` blok ile toplam hesaplanır.

`bc` (basic calculator) komutu, komut satırında hesap makinesi olarak çalışır. `bc` yazıp Enter ile hesap makinesi açılır. `3 > 1` ifadesi true (1) döner, `4 > 3` ifadesi false (0) döner. Atama operatörü `=` ile yapılır. `bc -l` ile logaritma, üstel fonksiyonlar gibi matematik fonksiyonlar etkinleşir. `echo "scale=4; 22/7" | bc` pipe ile 22/7'yi 4 ondalık hassasiyetle hesaplar.

Shell script argümanları önemli bir konudur. `$1`, `$2`, ... gibi değişkenler komut satırında verilen argümanlara erişim sağlar. `\$#` toplam argüman sayısını verir. `$@` tüm argümanları liste olarak verir. `$?` son komutun çıkış kodunu verir (0 = başarılı, 0'dan farklı = hata).

if koşul yapıları detaylı açıklanır. `if [ koşul ]; then ... elif [ koşul ]; then ... else ... fi` yapısı C'deki if-else yapısına benzer, ancak `[ ]` test komutu yerine kullanılır. Sayısal karşılaştırma operatörleri: `-eq` (eşit), `-ne` (eşit değil), `-gt` (büyük), `-lt` (küçük), `-ge` (büyük eşit), `-le` (küçük eşit). Dosya testleri: `-f` (dosya var mı), `-d` (dizin var mı), `-r` (okunabilir mi), `-w` (yazılabilir mi), `-x` (çalıştırılabilir mi).

Döngüler (loops) shell'in güçlü özelliklerindendir. `for` döngüsü: `for i in 1 2 3 4 5; do echo $i; done` (1'den 5'e kadar yazdır). `for i in {1..5}` range sözdizimi daha okunabilir. `{1..10..2}` step sözdizimi (2'şer artarak). `while` döngüsü koşul doğru olduğu sürece tekrarlanır. `until` koşul yanlış olduğu sürece tekrarlanır. `for dosya in $(ls); do ... done` komut çıktısı üzerinde döngü kurar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
