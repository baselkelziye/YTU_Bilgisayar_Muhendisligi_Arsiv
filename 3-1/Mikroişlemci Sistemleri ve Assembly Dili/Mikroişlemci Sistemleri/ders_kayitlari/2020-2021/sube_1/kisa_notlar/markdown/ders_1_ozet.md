# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin kapsamı
  - Dersin merkezinde Intel 8086 mikroişlemcisi vardır: iç yapısı, uç tanımları, yardımcı devreleri, assembly ile bağlantısı ve hafıza erişimi (ekrandan, 00:30:00).
  - 8086 ders boyunca **minimum modda** kullanılır. Minimum modda devrede tek bir mikroişlemci vardır. Maksimum modda ise 8087 matematik yardımcı işlemcisi gibi ikinci bir işlemci yollara hakim olabilir ve yol denetimi devredilir; bu daha karmaşık bir yapıdır.
  - İncelenecek arayüzler: 8255 programlanabilir paralel arayüz (Mod 0 el sıkışmasız; Mod 1 ve Mod 2 el sıkışmalı), 8251 seri haberleşme birimi, 8254 zamanlayıcı/sayıcı, ADC ve DAC, 8259 kesme denetleyicisi, son olarak bellek yapıları ve adres çözümleme (ekrandan, 00:15:00).
  - Çevre birimleri hem hazır programlanabilir entegrelerle hem de özel (custom) olarak kurulan giriş-çıkış devreleriyle ele alınır.
- Yoklama (polling) ve kesme
  - Yoklamada işlemci bir denetim yazmacındaki biti, istenen değere gelene kadar boş bir döngüde tekrar tekrar okur. Bu, işlemciyi gereksiz yere meşgul eder.
  - Kesme tabanlı yapıda bir istek geldiğinde işlemci o anki işi keser, kesme alt programını yürütür, sonra bıraktığı işe döner. 8259 bu isteklerin dış dünyadan gelmesini düzenler.
- ADC ve DAC'nin gerekçesi
  - Fiziksel dünya analogdur (sıcaklık, basınç, gerilim). İşlemcinin bu değerleri işlemesi için ADC ile sayısala çevrilmesi, hesaplanan denetim işaretinin de (motor, fan sürme) DAC ile tekrar analoga çevrilmesi gerekir.
- Bir mikroişlemcinin çalışması için gereken yardımcı devreler
  - Mikroişlemci tek başına enerji verilince çalışmaz. Saat darbesi üreteci, zaman çoğullamalı uçlardaki bilgiyi tutan tutucular (latch), giriş-çıkış çevre birimleri ve program/veri belleği gerekir. 8086'nın içinde program saklayacak bellek yoktur.
- Hesaplamanın tarihsel gelişimi
  - Mekanik çağ: abaküs (Babilliler; şekildeki Çin abaküsü 16 tabanında), Pascal'ın dişlili mekanik hesap makinesi (elde dişliler üzerinden otomatik aktarılır), delikli kartlarla desen veren dokuma tezgahı, Babbage'ın Analytical Engine'i (kavramsal olarak mekanik, genel amaçlı bilgisayar; döneminde tamamlanamadı).
  - Elektriksel çağ: Pascal makinesinin motorlu sürümleri; Hollerith'in 1890 ABD nüfus sayımı için delikli kartlı, elektrik motorlu veri işleme makinesi (ekrandan, 00:40:00). Hollerith'in kurduğu Tabulating Machine şirketi IBM'in temelidir.
  - Elektromekanik dönem: 1940'larda rölelerle anahtarlama. Konrad Zuse'nin Z3'ü röleli, genel amaçlı ilk bilgisayar sayılır.
  - Elektronik çağ: vakum tüpleri. Colossus özel amaçlıdır (şifre çözme). ENIAC genel amaçlıdır: 17000 vakum tüpü, 800 km kablo, 30 ton, saniyede 100000 işlem (ekrandan, 00:45:00). Programlama kabloların soketlerden çıkarılıp başka soketlere takılmasıyla yapılır.
  - Yarı iletken çağı: transistör, sonra entegre devre.
- Intel mikroişlemci ailesi
  - 4004: ilk mikroişlemci, 4 bit, adresleme kapasitesi 4096 x 4 bit, 45 komut, saniyede 50000 işlem (ekrandan, 00:50:00).
  - 8008 (1971): 8 bit, 16 KB adresleme kapasitesi, 48 komut (ekrandan, 00:55:00).
  - 8080: 64 KB adresleme kapasitesi.
  - 8086 (1978) ve bir yıl sonra 8088: 16 bit, 400 ns komut yürütme süresi (saniyede 2,5 milyon işlem), 1 MB adresleme kapasitesi, 4 veya 6 byte'lık komut kuyruğu, çarpma ve bölme komutları, varyasyonlarıyla 20000'i bulan komut sayısı (ekrandan, 01:00:00).
  - 80286: 16 MB. 80386: 32 bit, 4 GB. Ardından Core ailesi.
- Genel tanımlar ve karşılaştırmalar (ekrandan, 01:15:00)
  - ALU, yazmaç, akümülatör, CPU, mikroişlemci, mikrodenetleyici, SoC.
  - Harvard ve von Neumann mimarisi; CISC, RISC, EPIC.
  - Little endian ve big endian; veri, adres ve kontrol yolları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Adres ucu sayısı, adreslenebilir göz sayısının 2 tabanında logaritmasıdır
  - 4004: $\log_2 4096 = 12$ adres ucu; her göz 4 bit olduğu için 4 veri ucu.
  - Bu dersten itibaren, aksi söylenmedikçe her bellek gözü 8 bit (1 byte) kabul edilir. 8008'in 16 KB kapasitesi $2^4 \cdot 2^{10} = 2^{14}$ göz, yani 14 adres ucu demektir.
  - K = $2^{10}$ = 1024, M = $2^{20}$, G = $2^{30}$.
- 8086 ile 8088 farkı
  - İkisinde de 20 adres ucu (1 MB) ve 16 bitlik yazmaçlar vardır. 8086'da 16, 8088'de 8 veri ucu vardır (ekrandan, 01:10:00). 8088 16 bitlik bir veriyi iki çevrimde okur.
- Komut kuyruğu
  - Belleğe gidip komut getirmek işlemcinin en pahalı işlerindendir. Bellek bir kez etkinleşmişken sıradaki 4 veya 6 byte okunup kuyruğa alınır.
  - Sıradaki komut koşulsuz (JMP) ya da koşullu dallanma ise kuyruktaki komutlar çöpe gider. Bu yüzden günümüz işlemcilerinde dallanma tahmini (branch prediction) önemlidir.
  - Komut kuyruğu instruction cache ile aynı şey değildir; kuyruk yalnız sıralı komutları alır, ikisi bir arada da bulunabilir.
- Akümülatör özel bir yazmaçtır
  - Hız olarak diğer yazmaçlardan farkı yoktur. Farkı, ona özel komutların ve donanımın bulunmasıdır: aynı işlem AX ile daha kısa ve daha az saat çevriminde yapılabilir. 8086'da akümülatör AX'tir.
- 8086 von Neumann mimarisindedir, little endian çalışır ve CISC'tir.
- Yollar bütün birimlere ortaktır
  - Veri, adres ve kontrol yolları bütün bellek ve çevre birimlerine gider. Aynı anda yalnız bir birimle konuşulabilmesi için adres çözümleme devresi, verilen adrese göre yalnız ilgili birimi etkinleştirir.

## Kısa Tekrar Notları

- 8086 derste minimum modda, tek işlemcili kullanılır.
- Mikroişlemci = tek çipte ALU + kontrol birimi (komut çözücü dahil) + yazmaçlar + bunları bağlayan yollar.
- CPU daha genel kavramdır; bu birimlerin ayrık entegrelerle kart üzerinde kurulduğu hali de kapsar.
- Mikrodenetleyici: işlemci + saat, bellek, giriş-çıkış gibi çevre birimleri tek çipte. Basit, tekrarlı işler için (Atmel/ATmega, Arduino, PIC).
- SoC: işlemciye ek olarak Wi-Fi, GSM, ekran sürme gibi modülleri de tek çipte toplayan yapı (cep telefonları).
- Harvard: program ve veri belleği ayrı yollardan (PIC; ekranda ARM ve PIC örneği). Von Neumann: ortak yol (8086).
- CISC: karmaşık komutlar, farklı yürütme süreleri ve farklı komut boyları, karmaşık kontrol devresi. RISC: komutlar genelde 1, özel durumda 2 saat çevrimi, eşit boy.
- EPIC: paralel yürütülecek komutları derleyici belirler (Intel Itanium).
- Little endian: düşük anlamlı byte düşük adrese. 12345678h, 100h'den itibaren: 78h, 56h, 34h, 12h.
- Big endian: yüksek anlamlı byte düşük adrese: 12h, 34h, 56h, 78h.
- $n$ farklı komut için en az $\lceil \log_2 n \rceil$ bit gerekir: 45 komut için 6 bit.
- 386: 32 adres ucu, $2^{32}$ = 4 GB.

## Detaylı Açıklamalar

- **Çin abaküsü ve 16 tabanı.** Ekrandaki abaküste her çubuk bir onaltılık basamaktır. Orta çizginin üstünde 2, altında 5 boncuk vardır (ekrandan, 00:35:00). Üstteki boncukların her biri 5, alttakilerin her biri 1 değerindedir. Böylece bir çubukta $2 \cdot 5 + 5 \cdot 1 = 15$, yani F değerine kadar çıkılabilir.
- **4004 örneği.** "4096 x 4" yazımı 4096 bellek gözü ve her gözde 4 bit demektir. 4096 farklı adres üretmek için $4096 = 2^2 \cdot 2^{10} = 2^{12}$ olduğundan 12 adres ucu gerekir. Bir gözdeki 4 bit tek seferde aktarılacağı için 4 veri ucu gerekir. 45 komutun her biri birbirinden farklı (varyasyon değil) kabul edilirse komut kelimesi en az 6 bit olmalıdır: 5 bit $2^5 = 32$ komut verir ve yetmez; 6 bit $2^6 = 64$ komut verir, 19 kod kullanılmadan kalır.
- **Neden 8086'da adres ve veri genişlikleri farklı?** 16 bitlik bir işlemcide 20 bitlik adres üretmek zordur: iki yazmaç birlikte kullanılarak 20 bitlik değer oluşturulur. 32 bitlik işlemcilerde 32 bitlik adres yazmacı doğrudan adres yoluna verilebilir. 32 adres ucuyla erişilebilen alan dönemin bellekleri için yeterince büyük olduğu için ayrıca genişletmeye gerek kalmamıştır.
- **8086'nın önemi.** Günümüz Intel tabanlı işlemcilerin komut kümesi bu aileye dayanır. Güncel işlemcilerin iç yapısı ders kapsamında incelenemeyecek kadar karmaşık olduğundan temel 8086 üzerinden verilir. Hocaya göre geriye yönelik komut desteği en az 386/486'nın 32 bitlik komutlarına kadar gider. 8086 gibi 16 bitlik, real mode programlar ise günümüzde doğrudan çalışmaz: real mode belleğin tamamına erişmek demektir, günümüz işletim sistemleri ise her programı yetkilendirilmiş bir bellek alanıyla sınırlar.
- **CISC ve RISC.** CISC'te çarpma, bölme gibi karmaşık komutlar ve onları destekleyen donanım vardır. Örneğin toplama 2, çarpma 10 saat çevrimi sürebilir; iki yazmacı toplayan komut 2 byte, bellekten veri okuyan bir MOV 5 byte olabilir. Bu çeşitlilik kontrol devresini karmaşıklaştırır. RISC'te her komut genelde bir saat çevriminde yürür ve bütün komutların boyu eşittir. Hocaya göre CISC genel amaçlı işlemcilerde, RISC mikrodenetleyici ve cep telefonu SoC'leri gibi yapılarda kullanılır.
- **Harvard ve von Neumann.** Harvard mimarisinde işlemci program belleğiyle ve veri belleğiyle ayrı yollardan haberleşir; ayrı adres uçları ve iki yol için ayrı denetim gerekir. Avantajı program ile verinin karışmamasıdır. Von Neumann mimarisinde ikisi aynı yolları kullanır; denetim daha basittir ama program ve veri aynı RAM'de olduğu için dikkatsiz durumlarda birbirini bozabilir.
- **Little ve big endian örneği.** 32 bitlik 12345678h değeri 8 onaltılık basamaktır (her basamak 4 bit). 100h adresinden itibaren saklanırsa:

  ```text
  Adres   Little endian (8086)   Big endian
  100h    78h                    12h
  101h    56h                    34h
  102h    34h                    56h
  103h    12h                    78h
  ```

<!-- BELİRSİZ: Endian çizimi kayıttaki karelere düşmedi; değer altyazıdan (01:32:42, "1, 2, 3, 4, 5, 6, 7, 8") alındı. -->

- **Ders sonrası notlar.**
  - Hoca 4004'ün TTL yapısında olduğunu söyledi, slaytta RTL yazıyor (ekrandan, 00:50:00); 4004 büyük olasılıkla PMOS teknolojisiyle üretilmiştir.
  - Hoca Colossus'u Alan Turing'e bağladı; Colossus büyük olasılıkla Tommy Flowers tarafından tasarlanmıştır, Turing'in adı daha çok Bombe makinesiyle anılır.
  - Hoca "8286" dedi; kastedilen 80286'dır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
