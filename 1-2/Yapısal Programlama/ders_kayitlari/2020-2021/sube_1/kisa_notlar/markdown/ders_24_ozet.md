# Ders 24 Çalışma Özeti

## Genel Konular

- Sıralı erişimden rastgele erişime (ekrandan, 00:05:00)
  - Şimdiye kadar dosyalar text ya da binary modda hep sıralı (sequential) okundu: ilk bayttan başlanıp her bayt sırayla işlendi.
  - Bir dosyada belirli bir kaydı bulmak için baştan o kayda kadar okumak gerekir. Dizilerde de doğrusal arama böyledir; hızlı arama için sıralı dizide ikili arama (binary search) kullanılır.
  - Dosya erişimi bellek erişiminden çok daha yavaştır. Dosyayı sıralamak da uzun sürer.
  - Amaç, dizide indeks vererek bir elemana gidildiği gibi dosyada da doğrudan istenen konuma gitmektir. Buna rastgele erişim (random access) denir. Bunun için iki temel fonksiyon vardır: `fseek()` ve `ftell()`.
- `fseek` fonksiyonu (ekrandan, 00:10:00)
  - İmza: `int fseek(FILE *stream, long int offset, int whence);`
  - `stream`: dosya işaretçisi. `offset`: kaç karakter (bayt) gidileceği, negatif olabilir. Binary dosyada bayt sayısıdır; text dosyada ya 0 ya da `ftell()`'in döndürdüğü bir değer olmalıdır.
  - `whence`: offset'in nereden sayılacağı. `stdio.h` içinde üç sabit vardır: `SEEK_SET` dosyanın başı, `SEEK_CUR` dosya konum işaretçisinin şu anki yeri, `SEEK_END` dosyanın sonu.
  - Örnek: `stat = fseek(fp, 10, SEEK_SET);` işaretçiyi akışın 10. karakterine götürür; bir sonraki okuma ya da yazma oradan yapılır (ekrandan, 00:15:00).
  - Akışlar da diziler gibi 0'dan başlar. Bu yüzden 10. karakter aslında 11. karakterdir.
  - İstek geçerliyse 0, değilse sıfırdan farklı bir değer döner. "0 ise sorun yok" diye düşünmek gerekir.
  - Salt okunur dosyada `fseek(fp, 1, SEEK_END)` geçersizdir, çünkü işaretçiyi dosya sonunun ötesine taşır. `SEEK_END` ile offset $\le 0$, `SEEK_SET` ile offset $\ge 0$ olmalıdır. Kural: dosya konum işaretçisi dosyanın dışına itilmez.
- `ftell` fonksiyonu
  - Tek parametresi dosya işaretçisidir. İşaretçinin dosyanın başından itibaren kaçıncı baytta olduğunu döndürür.
  - Text dosyada döndürdüğü değer yalnız bir `fseek` çağrısına offset olarak verildiğinde anlamlıdır.
- İndeksle sıralı okuma fikri (ekrandan, 00:20:00)
  - Kayıtları `PERSONALSTAT` yapısında olan büyük bir dosya düşünülür. Kayıtlar rastgele sıradadır ama ada göre alfabetik yazdırılmak istenir.
  - Dosyayı sıralamak çok zaman ve G/Ç işlemi ister. Üstelik ad, maaş, kıdem gibi farklı ölçütlere göre her seferinde yeniden sıralamak mantıksızdır.
  - Çözüm: dosya sırasız kalır, onun için bir ya da daha fazla indeks tutulur ve yalnız indeks sıralanır.
  - İndeks bir yapı dizisidir. Bir alanında anahtar (örneğin ad), diğerinde kaydın dosyadaki sıra numarası bulunur. Kayıt boyu sabit olduğu için sıra numarasından bayt konumu hesaplanır: kayıt 64 bayt ise 10. kayıt 640. bayttan başlar.
  - İndeks ayrı bir dosyaya da yazılabilir. Böylece program her açıldığında yeniden kurulmaz. Ama veri dosyası değişince indeks yenilenmelidir: ya hemen yeniden indekslenir ya da "dosya değişti" işareti konur ve indeksli çalışan program başlarken bu işarete bakıp indeksi tazeler.
  - Örnek tabloda ilk kayıt (indeks 0) Jordan, indeks 1 Bird, indeks 2 Irving'dir. Anahtara göre sıralanınca Bird (1), Irving (2), Johnson (4) diye gider. Tüm personel yazdırılırken önce 1. konuma, sonra 2. konuma, sonra 4. konuma gidilip kayıt okunur. <!-- BELİRSİZ: tablonun tamamı karelerde yok; yalnız altyazıda geçen adlar alındı -->
- Birinci program: kayıt dosyasını oluşturma (ekrandan, 00:30:00 ve 00:35:00)
  - `DATE` yapısı bit alanlıdır: `day : 5`, `month : 4`, `year : 11`. `PERSONALSTAT` yapısında `char ps_name[NAME_LEN], ps_tcno[11];` ve `DATE ps_birth_date;` vardır, `NAME_LEN` 19'dur.
  - `fopen("records.dat", "wb")` ile dosya yazma ve binary modda açılır. `+` olmadığı için var olan dosya silinir.
  - Dört kişinin adı, kimlik numarası ve doğum tarihi istenir. Bit alanına `scanf("%u", &ps2[j].ps_birth_date.day)` yazılamaz (bit alanının adresi alınamaz); bu yüzden geçici `val` değişkenine okunup alana atanır.
  - Her kayıt `fwrite(&ps2[j], sizeof(PERSONALSTAT), 1, fp);` ile yazılır.
- İkinci program: indeksi kurma, sıralama ve indeks sırasıyla yazdırma (ekrandan, 00:35:00 - 00:50:00)
  - `#define MAX_REC_NUM 1000`, `#define NAME_LEN 19`. İndeks yapısı: `typedef struct { int index; char key[NAME_LEN]; } INDEX;`
  - `get_records(FILE* data_file, INDEX names_index[], int max_rec_num)`: her kaydın yalnız ilk 19 baytını (ad alanı) `fread(namei, 1, NAME_LEN, data_file)` ile okur, `strcpy` ile indekse yazar, `offset += sizeof(PERSONALSTAT); fseek(data_file, offset, SEEK_SET);` ile bir sonraki kaydın başına gider. Döngü `counter < max_rec_num && nm == NAME_LEN` sürdükçe devam eder; okunan kayıt sayısını döndürür.
  - `compare_func` iki indeks elemanının `key` alanını `strcmp` ile karşılaştırır: sonuç $<0$, $0$ ya da $>0$ olur.
  - `sort_index`: önce `names_index[j].index = j;` ile her elemana dosyadaki sırasını yazar, sonra `qsort(names_index, index_count, sizeof(INDEX), pf);` çağırır. `pf`, `compare_func`'u gösteren bir fonksiyon işaretçisidir.
  - `print_indexed_records`: sıralı indeksteki her eleman için `fseek` ile `index * sizeof(PERSONALSTAT)` baytına gider, gidemezse `exit(1)`; gidebilirse bütün kaydı `fread` ile okuyup ekrana yazar.
  - `main(int argc, char *argv[])`: dosya adı komut satırından `argv[1]` ile alınır (`argv[0]` programın adıdır); argüman yoksa kullanıcıdan istenir. Dosya `"rb"` ile açılır, `get_records`, `sort_index`, `print_indexed_records` sırayla çağrılır, sonunda `fclose`.
- Programın çalıştırılması ve dosya konumunun izlenmesi
  - Dev-C++'ta iki ayrı proje: önce kayıtlar girildi, sonra indeks programı komut satırından kayıt dosyası verilerek çalıştırıldı. Kayıtlar ada göre alfabetik sırada yazıldı.
  - Kodun dosyayı nerede oluşturduğu çalıştırma şekline bağlıdır: IDE'den çalışınca IDE'nin kurulu olduğu dizin, komut satırından çalışınca bulunulan dizin kullanılabilir.
  - Hoca `ftell` çıktısı ekleyerek konumu izledi: başta 0, ilk 19 baytlık okumadan sonra 19.
- Dinamik bellek: `malloc` ile `free` eşleşir (öğrenci sorusu)

## Hocanın Özellikle Vurguladığı Kısımlar

- `fseek`'in dönüş değeri ters mantıktadır
  - 0 başarı, sıfırdan farklı değer hata demektir.
- Dosya konum işaretçisi dosyanın dışına çıkarılmamalıdır
  - Sistem izin verse bile mantıklı sınırlar içinde kalınmalıdır. C standartları ve işletim sistemleri farklı davranabilir; mantıklı kod taşınabilirliği (farklı platformlarda çalışabilmeyi) artırır.
- Dosyayı değil indeksi sıralamak
  - Sıralama pahalıdır; birden çok ölçüt için birden çok indeks tutmak mantıklıdır. İndeksin güncel tutulması programcının sorumluluğudur.
- Ortak yapı tanımı tek yerde olmalı
  - Aynı `struct` iki programda ayrı ayrı tanımlandı. Normalde ayrı bir başlık dosyasına konup eklenmesi en doğrusudur; yapı değişince her yerde ayrı düzeltme gerekmez.
- Kodun okunabilirliği
  - Uzun bir satırı bölmek gibi anlaşılabilirliği artıran her değişiklik değerlidir.
- Önce doğru çalışan kod, sonra iyileştirme
  - Önce kod doğru çalışır hale getirilir ve yedeklenir. Sonra iyileştirme (refactoring) yapılır, kod yine doğru çalışıyorsa son hali kabul edilir.

## Kısa Tekrar Notları

- `fseek(fp, offset, whence)`: `whence` = `SEEK_SET` (baş), `SEEK_CUR` (şu an), `SEEK_END` (son). Başarıda 0 döner.
- `ftell(fp)`: işaretçinin baştan kaçıncı baytta olduğunu döndürür.
- Akış konumu 0'dan başlar: konum 10 = 11. karakter.
- Text dosyada `fseek` offset'i ya 0 ya da `ftell` değeri olmalı.
- `SEEK_END` ile offset $\le 0$, `SEEK_SET` ile offset $\ge 0$.
- Sabit boyutlu kayıtta $n$. kaydın bayt konumu: $n \times$ `sizeof(kayıt)`.
- İndeks = (anahtar, kayıt sıra numarası) çiftlerinden oluşan dizi; yalnız indeks sıralanır, dosya olduğu gibi kalır.
- `qsort(dizi, eleman_sayısı, eleman_boyu, karşılaştırma_fonksiyonu)`; karşılaştırma fonksiyonu işaretçiyle verilir.
- Bit alanının adresi alınamaz: `scanf` ile geçici değişkene okunur.
- `fread` okuduğu bayt kadar konumu ilerletir; bir sonraki `fread`'e kadar konum değişmez.
- `malloc` ile alınan her alan bir kez `free` edilir; `free` tek tip, tek parametrelidir.

## Detaylı Açıklamalar

- **Rastgele erişimin gerekçesi.** Sıralı erişimde bir çalışanın kaydını bulmak için dosyanın başından o kayda kadar okumak gerekir. Bellekte bir diziye indeksle doğrudan gidebildiğimiz gibi dosyada da doğrudan bir konuma gitmek istenir. `fseek` dosya konum işaretçisini istenen bayta taşır, `ftell` şu anki konumu söyler. İkisi birlikte "istediğin yere git, oradan oku" düzenini kurar.

- **`fseek` parametreleri.** Birinci parametre dosya işaretçisi, ikincisi kaç bayt gidileceği, üçüncüsü bu sayımın nereden başlayacağıdır. Geri gitmek için offset negatif olabilir. Binary dosyada offset doğrudan bayt sayısıdır; text dosyada satır sonu dönüşümleri yüzünden yalnız 0 ya da daha önce `ftell` ile alınmış bir değer güvenlidir (ekrandan, 00:10:00). `fseek(fp, 10, SEEK_SET)` dosyanın başından 10 bayt ileri gider; sayım 0'dan başladığı için okunacak karakter 11. karakterdir (ekrandan, 00:15:00).

  > **Ders sonrası not:** Hoca 00:13:03'te `fseek(fp, 10, SEEK_SET)` için "şu an bulunduğumuz noktadan 10 bayt ileri git" dedi; doğrusu dosyanın başından 10 bayt ileridir. "Şu anki konumdan" anlamı `SEEK_CUR`'a aittir. Hoca 01:26:54'te slaytı açıp `SEEK_SET`'in "beginning" demek olduğunu kendisi de düzeltti.

- **Geçersiz istekler.** Salt okunur bir dosyada `fseek(fp, 1, SEEK_END)` dosya sonunun ötesine gitmeye çalıştığı için geçersizdir ve sıfırdan farklı döner. Hoca, yazma modunda dosya sonunun ötesine gidilip yazılırsa aradaki boşluğun neyle doldurulacağını bilmediğini, bunu da mantıksız bulduğunu söyledi. Ana kural: işaretçi dosyanın dışına itilmez.

- **İndeks yaklaşımı.** Dosya kayıtları sırasız durur. Ada göre sıralı bir görünüm için her kaydın adı ve dosyadaki sıra numarası bir `INDEX` dizisine okunur, yalnız bu dizi sıralanır. Sıra numarası ile bayt konumu birbirine çevrilebildiği için ikisinden biri tutulur; derste sıra numarası tutuldu, bayt konumu `index * sizeof(PERSONALSTAT)` ile hesaplandı. Farklı ölçütler için farklı indeksler tutulabilir; indeks kalıcı olsun diye dosyaya da yazılabilir. Veri dosyası değişirse indeks yeniden kurulmalı ya da "yeniden indekslenmeli" işareti konmalıdır.

- **Kayıt yapısı ve boyutu.** `DATE` yapısındaki bit alanları 5 + 4 + 11 = 20 bittir.

  > **Ders sonrası not:** Hoca 00:27:47'de "5 bayt, 4 bayt, 11 bayt ... 20 bayt" dedi; doğrusu 5, 4 ve 11 **bit**, toplam 20 bittir. Bu 20 bit tek bir 32 bitlik `unsigned int` içine sığar (16 bite sığmaz). Ajanın derlediği programda `sizeof(DATE)` 4, `sizeof(PERSONALSTAT)` 36 çıktı (19 + 11 = 30 bayt karakter, 2 bayt hizalama boşluğu, 4 bayt tarih). Derste ekranda görünen `records.dat` dosyasının boyutu da 4 kayıt için 144 bayttı (ekrandan, 01:10:00), bu da $4 \times 36$ eder.

- **`get_records` ve dosya konumu.** Fonksiyon her kaydın yalnız ad alanını okur. Hoca, ilk `fread`'den sonra işaretçinin 19. bayta geldiğini, ardından `offset` kayıt boyu kadar artırılıp `SEEK_SET` ile atlandığını anlattı. Ders sırasında `SEEK_SET`'i "şu anki konum" sandığı için ikinci kaydın ad alanının atlanacağından şüphelendi. Çalıştırınca sorun çıkmadı: `offset` toplamlı (kümülatif) tutulduğu ve dosyanın başından sayıldığı için her seferinde doğru kaydın başına gidiliyor; çarpma işlemine de gerek kalmıyor. `ftell` izinde başta 0, ilk okumadan sonra 19 görüldü. <!-- BELİRSİZ: sonraki ftell değerleri altyazıda "0, 19, 75" diye geçiyor; 36 baytlık kayıtla beklenen 55'tir, ekran karesi yok -->

- **Sıralama ve fonksiyon işaretçisi.** `qsort` her türden diziyi sıralayabilsin diye karşılaştırmayı programcıya bırakır: iki elemandan hangisinin önce geleceğine karar veren fonksiyon işaretçi olarak verilir. Derste `compare_func` yalnız `strcmp` çağırır; hoca bunu ayrı fonksiyon yapmanın tek satırlık iş için biraz fazla olduğunu, ama farklı anahtar alanları için yeniden kullanılabilirliği artırdığını söyledi (ekrandan, 00:45:00).

  > **Ders sonrası not:** Slayttaki `int (*pf) (); pf = compare_func;` ve `compare_func(INDEX *p, INDEX *q)` yazımı eski C standartlarında derlenir. Ajanın denemesinde gcc 15 (varsayılan C23) bu kodu `-Wall` ile hata vererek reddetti, `-std=gnu17` ile derlendi. Taşınabilir yazım: `int compare_func(const void *a, const void *b)` ve `int (*pf)(const void *, const void *)`.

- **`main` ve komut satırı.** `argv[0]` çalıştırılabilir dosyanın adı, `argv[1]` ilk parametredir. Argüman verilmezse program dosya adını kullanıcıdan ister (ekrandan, 00:50:00). Ajanın birleştirdiği tam program (iki program ayrı ayrı, `print_indexed_records` anlatımdan yeniden kuruldu) `gcc -Wall` ile derlendi; 4 kayıtla çalıştırıldığında `num_recs_read: 4` yazdı ve kayıtları ada göre alfabetik sırada listeledi.

- **`malloc` ve `free`.** Bir öğrenci, yapı içindeki `char *` alanına süslü parantezle ilk değer verilirse `free` gerekip gerekmediğini sordu. Hoca gerekmediğini söyledi: `free` yalnız `malloc` ile alınan alanlar için yapılır. `free`'nin türleri yoktur, tek parametresi işaretçidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
