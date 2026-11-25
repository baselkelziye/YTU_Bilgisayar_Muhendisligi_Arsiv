# Ders 12 Çalışma Özeti

## Genel Konular

- Ders bir makale tartışması biçiminde işlendi
  - Öğrenciler o haftanın makalelerini önceden okumuştu. Hoca her makale için soru sordu, el kaldıranlara sırayla söz verdi, cevapları değerlendirip makaledeki asıl ifadeyi kendisi okudu.
  - Tartışma Türkçe ve İngilizce karışık yürüdü. Kayıtta ekran paylaşımı yoktu; görüntüde yalnız konuşan kişinin adı vardı. Not altyazıdan hazırlandı.
  - Dört makale konuşuldu: Zipf yasası, güç yasası ve Pareto dağılımı üzerine bir sıralama makalesi; Google File System (GFS); MapReduce; RAID.
- Zipf yasası, güç yasası (power law) dağılımı ve Pareto dağılımı
  - Zipf yasası: $r$. en sık görülen olayın sıklığı (büyüklüğü) sırasıyla ($r$) ters orantılıdır. Makaledeki örnek İngilizce metinlerde kelime kullanım sıklığıdır.
  - Buradaki "büyüklük" (size) kelimenin uzunluğu değil, metinlerde kullanılma sıklığıdır.
  - Pareto dağılımı "kaç kişinin geliri $x$'ten büyüktür?" sorusunu sorar; bu bir birikimli dağılım fonksiyonudur (CDF). Yaygın örneği 80/20 kuralıdır.
  - Güç yasası dağılımı "geliri tam olarak $x$ olan kaç kişi var?" sorusunu sorar; bu bir olasılık dağılım fonksiyonudur.
  - Bilişimdeki önemi: sistem performansı ölçülürken farklı sıralama ve dağılım bakışları gerekir.
- Google File System (GFS)
  - Google'ın kendi büyük veri iş yükleri için tasarladığı dağıtık dosya sistemi; geleneksel dosya sistemleri bu ihtiyaca cevap vermiyordu.
  - Varsayımlar: çok sayıda ucuz bileşen olduğu için arızalar olağandır; dosyalar çok büyüktür; dosyalar çoğunlukla sona ekleme (append) ve okuma ile değişir; uygulamalarla birlikte tasarlanan ortak bir API gerekir.
  - Düşük gecikme (latency) yerine yüksek bant genişliği (bandwidth) önceliklidir; büyük veri topluca, yüksek hızda işlenir.
  - Tek master yapısı: master, chunk sunucuları arasındaki koordinasyonu, chunk yerleşimini ve kopya seçimini merkezi olarak yapar; bu tasarımı basitleştirir.
  - Okuma ve yazmada master araya girmez. İstemci chunk'ın hangi sunucuda olduğunu masterdan öğrenir, bu bilgiyi önbelleğe alır ve okuma/yazmayı doğrudan chunk sunucusuyla yapar.
  - Dosya sistemi ad alanı değişiklikleri (dosya oluşturma, silme, yeniden adlandırma) atomiktir ve master tarafından yapılır. Masterın işlem günlüğü (operation log) bu işlemlerin global toplam sırasını belirler.
  - Master dayanıklılığı: işlem günlüğü ve checkpoint'ler birden çok makineye kopyalanır. Bir değişiklik ancak günlüğü hem yerelde hem bütün master kopyalarında diske yazıldıktan sonra kesinleşmiş sayılır.
  - Kopyalarla ilgili bölümler: replica placement, creation, re-replication, re-balancing, garbage collection; yüksek erişilebilirlik altında chunk replication ve master replication.
- MapReduce
  - Büyük veri işlemede kullanılan programlama modeli. Kullanıcı Map ve Reduce fonksiyonlarını yazar; Map anahtar-değer (key-value) çiftleri üretir, Reduce aynı anahtarlı değerleri birleştirir.
  - Paralellik ve dağıtım altta gizlendiği için dağıtık sistem bilgisi az olan bir yazılımcı da dağıtık program yazabilir.
  - Makaledeki örnekler: distributed grep, URL erişim sıklığı sayımı, reverse web-link graph, term vector per host, inverted index, distributed sort.
  - Hata toleransı: hata alan işler yeniden çalıştırılır; hesaplamalar fazladan makinelerde tekrarlanabilir.
  - MapReduce altta GFS'nin ve ucuz (commodity) donanımın var olduğunu varsayar; GFS'nin kopyalama, güvenilirlik ve yüksek bant genişliği özelliklerinden yararlanır.
- RAID (Redundant Arrays of Inexpensive Disks)
  - Neden: CPU ve bellek hızla gelişirken G/Ç performansı geride kaldı. Tek büyük pahalı disk (SLED) kapasite olarak yeterli ama hız olarak yetersizdi. Çözüm: çok sayıda ucuz diski bir arada kullanmak.
  - Makale farklı performans ve maliyetli beş seviye tanımlar.
  - Seviye 1: yansıtma (mirroring); her veri iki diske yazılır, kullanılabilir kapasite yarıya iner.
  - Seviye 2: hata düzeltme için Hamming kodu kullanır. Küçük G/Ç işlemlerinde verimi çok düşüktür; büyük ve ardışık veri işleyen süper bilgisayarlara uygundur, işlem (transaction) yoğun sistemlere uygun değildir.
  - Seviye 3: bir grup için tek bir kontrol (parity) diski kullanır; daha az kontrol diski gerektiği için disk başına etkin performans seviye 2'den yüksektir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sorulan şey makalenin özeti değil, sorunun kendisidir
  - GFS'nin varsayımları sorulduğunda makalenin özetini okuyan cevabı hoca kabul etmedi; tasarımın dayandığı varsayımları istedi.
- "Tek şeyi kontrol etmek kolaydır" yeterli bir cevap değildir
  - Tek master tercihinin ardındaki asıl gerekçe sorulmalıdır: chunk yerleşimi ve kopyalama kararlarının merkezi bilgiyle basitçe verilmesi.
- Dosya sistemi mutasyonu "çok basit" bir kavramdır
  - Dosya oluşturma, silme, yeniden adlandırma, metadata değişikliği. Ağaç yeniden kurma gibi karmaşık cevaplara gerek yoktur.
- Pareto ile güç yasasının farkı
  - Biri "$x$'ten fazla olanların sayısı" (birikimli), diğeri "tam $x$ olanların sayısı" (olasılık dağılımı). Performans ölçümünde ikisi farklı sorulara karşılık gelir ve çoğu zaman birden fazlası birlikte kullanılır.
- grep ile find farkı
  - grep bir ya da daha çok dosyanın içinde kelime veya düzenli ifade arar; dosya adı aramak find'ın işidir.

## Kısa Tekrar Notları

- Zipf: $r$. sıradaki olayın sıklığı $\propto 1/r$.
- Pareto: $P(X > x)$ biçiminde birikimli; güç yasası: tam $x$ değerinin olasılığı.
- Performansta: "işlerin kaçı $T$ veya daha kısa sürede bitiyor?" Pareto tarzı; "bir işlem tam $T$ sürede biter mi?" güç yasası tarzı soru.
- GFS: bileşen arızası olağan, büyük dosyalar, append ağırlıklı, yüksek bant genişliği, tek master.
- GFS'de veri yolu masterdan geçmez; master yalnız metadata ve konum bilgisi verir.
- Ad alanı mutasyonları atomik, master yapar; işlem günlüğü global sıra belirler.
- Master kopyalanması: günlük ve checkpoint'ler çok makinede; günlük her yerde diske yazılınca commit.
- MapReduce: Map → anahtar-değer; Reduce → aynı anahtarlıları birleştir.
- URL erişim sıklığında anahtar URL, değer sayıdır.
- MapReduce hata toleransı: yeniden çalıştırma; altta GFS ve commodity donanım.
- RAID 1: mirror, kapasite %50. RAID 2: Hamming kodu, süper bilgisayara uygun. RAID 3: tek parity diski.

## Detaylı Açıklamalar

- Zipf, güç yasası ve Pareto. Günün ilk makalesi birkaç tanım içeren kısa bir makaleydi. Zipf yasası, bir olayın büyüklüğünün (makalede bir kelimenin İngilizce metinlerdeki kullanım sıklığı) bu büyüklüğe göre yapılan sıralamadaki yeriyle ters orantılı olduğunu söyler: en sık kelime ikinciden yaklaşık iki kat daha sık görülür. Hoca makaleden "size here denotes the frequency of use of the word in English text, and not the length of the word itself" cümlesini okuyarak büyüklüğün kelime uzunluğu olmadığını vurguladı. Pareto dağılımında soru sıralamadaki yer değil, geliri $x$'ten büyük olan kişi sayısıdır; bu bir toplam olduğundan birikimli dağılım fonksiyonudur. Güç yasası dağılımı ise geliri tam $x$ olan kişi sayısını, yani bir olasılık dağılımını verir. Üçü birbirine çok yakındır ve aynı olgunun farklı bakışlarıdır. Bir öğrenci 80/20 kuralını (etkilerin yaklaşık %80'inin nedenlerin %20'sinden gelmesi) örnek verdi. Hoca bunların bilişimdeki önemini performans ölçümüyle bağladı: bir işin ne kadar hızlı bittiği, gelen işlerin kaçının $T$ veya daha kısa sürede bittiği ve bir işlemin tam $T$ sürede bitme olasılığı farklı sorulardır. <!-- BELİRSİZ: 00:03:35'te bir öğrencinin "birinci sırada 1-10 oranında azalıyor" dediği kısım altyazıda anlaşılmıyor. -->
- GFS. GFS, Google'ın kendi büyük veri ihtiyaçları için geliştirdiği dağıtık dosya sistemidir. Tasarım varsayımları: çok sayıda bileşen vardır ve birinin bozulması olağandır, bu yüzden sürekli izleme ve kurtarma gerekir; dosyalar çok büyüktür; dosyalar çoğunlukla sonuna eklenerek ve okunarak kullanılır; uygulamalarla birlikte tasarlanan bir API gerekir. Google düşük gecikme yerine yüksek bant genişliğini seçmiştir, çünkü büyük veri topluca işlenir. Tek master, chunk sunucuları arasındaki koordinasyonu ve chunk yerleşimini merkezi bilgiyle yaparak tasarımı basitleştirir. İstemci chunk konumunu masterdan alıp önbelleğe aldığı için ardışık işlemleri masteri tekrar sormadan doğrudan chunk sunucusuyla yapar. Ad alanı mutasyonları atomiktir; master ad alanı kilitlemesiyle doğruluğu sağlar ve işlem günlüğü bu işlemlerin global toplam sırasını tanımlar. Master tek olsa da durumu kopyalanır: günlük ve checkpoint'ler birden çok makinede tutulur ve bir değişiklik ancak günlüğü yerelde ve bütün master kopyalarında diske yazıldığında kesinleşir.
- MapReduce. Kullanıcı yalnız Map ve Reduce fonksiyonlarını tanımlar; Map paralel olarak anahtar-değer çiftleri üretir, Reduce aynı anahtarlı değerleri birleştirir. Hoca örnekleri anahtar-değer gözüyle tartıştırdı. Distributed grep için hoca anahtarı aranan kelime ya da düzenli ifade, değeri o kelimenin bulunduğu dosyanın adı olarak açıkladı; Reduce sonunda yalnız kelimeyi içeren dosyalar kalır. URL erişim sıklığında anahtar URL, değer sayıdır. Reverse web-link graph bir hedefe hangi yollardan gelindiğini gösterir; hoca bunun kullanıcı hareketlerine göre reklam ve satış için önemli olduğunu söyledi. Term vector per host TF-IDF benzeri terim istatistikleriyle ilgilidir. Inverted index için bir öğrenci URL sayımına benzediğini, hoca ise "ters" yapısı nedeniyle reverse web-link graph'a daha çok benzeyebileceğini söyledi. Hata toleransı, hata alan işlerin yeniden çalıştırılmasıyla sağlanır. MapReduce altta GFS'yi ve ucuz donanımı varsayar.
- RAID. RAID makalesi, CPU ve bellek hızlanırken G/Ç'nin geride kalması sorununa ucuz diskleri bir arada kullanarak çözüm arar. Seviye 1 yansıtmadır ve kapasitenin yarısını kopyaya ayırır. Seviye 2 Hamming kodu kullanır; küçük G/Ç'de verimi çok düşük olduğu için işlem yoğun sistemlere uygun değildir, büyük veri işleyen süper bilgisayarlara uygundur. Seviye 3 her grup için tek kontrol diski kullanır; kontrol diski sayısı azaldığı için disk başına etkin performans artar. Bir öğrenci seviye 3'te kontrol diski payının %4 ile %10 arasında olduğunu söyledi. <!-- BELİRSİZ: 00:51:23'te bir öğrencinin RAID 2 için verdiği yüzdeler (küçük G/Ç'de %6, büyük G/Ç'de %60) altyazıda kesin değil. -->
- Ders sonrası not: Bir öğrenci TF-IDF'i "Term Frequency, Inverse Term Frequency" diye açtı ve hoca onayladı; doğrusu "Term Frequency – Inverse Document Frequency"dir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
