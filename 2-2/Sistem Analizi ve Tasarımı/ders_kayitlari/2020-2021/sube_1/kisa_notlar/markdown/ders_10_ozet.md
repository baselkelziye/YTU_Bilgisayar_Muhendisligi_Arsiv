# Ders 10 Çalışma Özeti

## Genel Konular

- Kodlama ve test aşamasının tekrarı
  - Sistem gereksinimleri kabul edildikten sonra kodlama yapılır, programlar ortaya çıkar. Kod denetimden geçemezse revizyonla kodlamaya dönülür; geçerse test planına göre test yapılır (modüller, genel, onaylama) ve sistem kullanıma hazır olur (ekrandan, 00:10:00).
  - Programlama dili; genel uygulama alanına, algoritmanın karmaşıklığına, yazılımın kullanılacağı ortama ve geliştiricilerin o dildeki bilgi düzeyine göre seçilir.
  - Okunabilir kod: gerektiği kadar açıklama satırı, düzenli yazım, anlamlı tablo, modül, değişken ve kolon adları ya da kurumun standardına uyum.
- Tasarımdaki "kodlama" kavramı (girdi kodlaması)
  - Program kodu yazmaktan farklıdır. Sık geçen ve sınıflanacak, raporlanacak bir alan (öğrenim durumu, cinsiyet, hastalık tanısı, bölüm) serbest metin yerine sayı ya da harf koduyla tutulur.
  - Böylece herkesin farklı yazması önlenir, eşleşme ve listeleme (örneğin bütün diyabet hastaları) kolaylaşır.
  - Bölüm kodu gibi kodlar veri tabanında iki tablo arasında yabancı anahtar (foreign key) olarak ilişki kurar; birincil anahtar (primary key) ise satıra erişim için tekil alandır.
- Yazılım kalitesi ve test
  - Kaliteli yazılım: önceden belirlenmiş işlevsel gereksinimlere, geliştirme standartlarına ve bir yazılımdan beklenen bütün özelliklere uygun yazılım (ekrandan, 00:15:00).
  - Kalite faktörleri: doğruluk, güvenilirlik, verimlilik, kullanışlılık, güvenlik, hata bulma kolaylığı, kolay değişiklik, test edilebilirlik, taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik (interoperability).
  - Sınama basamakları: ünite (birim) testi, bütünlük testi, sistem testi, onaylama testi. Sınama, kodlamadan geriye doğru yürütülür (ekrandan, 00:20:00).
- Yeni sistemin kullanıma geçişi
  - Başarı hem sistemin nasıl hazırlandığına hem de nasıl kullanıma geçirildiğine bağlıdır.
  - Kullanıcı eğitimi üç gruba ayrı verilir: sistemle ilgilenecekler (işleten, düzenleyen), uç kullanıcılar, üst yönetim.
  - Geçiş yöntemleri: doğrudan, paralel, dereceli, prototip, dağıtılmış geçiş.
- Yazılım bakımı (maintenance)
  - Hata düzeltme, platform/veri tabanı/geliştirme ortamındaki yeni sürümlerden yararlanma ve performans artırma, kullanıcının iş süreçlerindeki değişikliklere uyarlama amacıyla yapılır.
- Örnek uygulama: Spor salonu bilgi sistemi
  - Problem tanımı, aktörler (üye, eğitmen, yönetim), anketle veri toplama.
  - Yapısal yaklaşım: veri akış diyagramları (taslak, 1. ve 2. seviye), veri sözlüğü, ER diyagramı, yapı diyagramı.
  - Nesneye yönelik yaklaşım: use case diyagramı ve senaryo dokümanı, sınıf diyagramı, ardışıl (sequence) diyagram.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğrudan geçiş en riskli yöntemdir
  - Eğitimin ve veri tabanı dönüşümünün (eski sistemdeki verinin kayıpsız yeni veri tabanına aktarılması) önceden çok iyi hazırlanması gerekir. Hazırlık iyiyse tek veri tabanıyla en temiz geçiştir; geri dönüş gerekirse çok sıkıntılıdır.
- Paralel geçişin zorluğu
  - Veri tutarsızlığını önlemek için her işlem hem eski hem yeni sistemde yapılmalıdır; zahmetlidir. Hocaya göre son yıllarda daha sık kullanılmaktadır.
- Dereceli ve prototip geçiş farkı
  - Dereceli geçişte yeni sistem işlev işlev devreye alınır, devreye alınan işlev eski sistemden kaldırılır. Prototip geçişte sistemin bütününün prototipi küçük bir bölümde denenir; prototipin yeri ve kullanıcıları doğru seçilmelidir.
- Veri akış diyagramı kuralları
  - Varlıktan varlığa ve varlıktan veri deposuna doğrudan akış olmaz, arada işlem bulunmalıdır. İşlemden işleme akış olabilir.
- Hangi yaklaşımda hangi diyagram
  - Yapısal: analizde taslak, 1. ve 2. düzey veri akış diyagramları ve ER diyagramı, tasarımda yapı diyagramı.
  - Nesneye yönelik: analizde use case diyagramı ve senaryo dokümanı, tasarımda sınıf ve ardışıl diyagram. ER diyagramı veri tabanına dönüşümü göstermek için eklenebilir.

## Kısa Tekrar Notları

- Kodlama → denetim (revizyon döngüsü) → test planı → modül/genel/onaylama testi → kullanıma hazır sistem → kullanıma alma → bakım.
- Girdi kodlaması: serbest metin yerine kod; sınıflama ve raporlama kolaylaşır.
- Birim testi: modül doğru kodlanmış mı. Bütünlük: modüller birlikte doğru çalışıyor mu. Sistem testi: işletim sistemi uyumu, eş zamanlı kullanıcı, veri tabanı erişimi. Onaylama (kullanıcı) testi: kullanıcının istediklerini yapıyor mu.
- Eğitim grupları: işleten/düzenleyen (işletim sistemi, modül yapısı), uç kullanıcı (işlemler, menüler), üst yönetim (alınabilecek bilgiler, kısıtlar).
- Doğrudan: T anında tamamen yeni sisteme. Paralel: bir süre ikisi birlikte. Dereceli: işlev işlev. Prototip: küçük bir bölümde prototip, sonra tamamı. Dağıtılmış: kurumun bölümleri tek tek.
- Bakım nedenleri: hata, yeni sürüm/performans, iş süreci değişikliği.
- Gane-Sarson notasyonunda veri depoları D1, D2, ... ve işlemler 1.0, 2.0, ... diye numaralanır.
- ER (Chen): varlık dikdörtgen, nitelik elips, ilişki eşkenar dörtgen.
- Use case: `include` zorunlu alt davranış (sınıfa kaydolma → sınıf bilgisi görüntüleme), `extend` isteğe bağlı genişletme (özel ders talebi).
- Yapı diyagramında içi dolu uçlu ok kontrol bayrağı, içi boş uçlu ok veri; eşkenar dörtgen koşul (seçim), yarım daire ok döngü.
- Ardışıl diyagram: nesneler soldan sağa çağrılma sırasına göre dizilir, zaman yukarıdan aşağı akar.

## Detaylı Açıklamalar

- **Kodlama aşaması ve kalite.** Analiz ve tasarım (yapısal ya da nesneye yönelik) bittikten sonra kodlamaya geçilir. Önce programlama dili ve platform uygun şekilde seçilir. Kod, açıklama satırları, düzenli yazım ve anlamlı adlandırmayla okunabilir tutulur. <!-- BELİRSİZ: altyazıda "UML diyagramın niteliği düzenli bir kodlama tekniğine bağlıdır" geçiyor; büyük olasılıkla "yazılımın niteliği" kastedildi. --> Kaliteli yazılımın kullanıcı açısından kullanışlı, güvenli, verimli ve güvenilir olması; geliştirici açısından da hata bulma, değişiklik, test, taşıma (bir işletim sisteminden diğerine), yeniden kullanma ve başka sistemlerle birlikte çalışma kolaylığı sağlaması beklenir.

- **Tasarımda kodlama.** Hoca dersin başında katılımcılara tasarım aşamasında geçen ikinci "kodlama" kavramını sordu. Bir öğrencinin tekil anahtar (öğrenci numarası, kimlik numarası) cevabını hoca birincil anahtarla karıştırıldığını söyleyerek düzeltti. Girdi kodlamasında amaç, bir alanın değerlerini sayısal ya da tek karakterlik kodlara bağlayarak sınıflama ve raporlamayı kolaylaştırmaktır. Öğrenim durumu "ilkokul", "ortaokul" diye yazılırsa herkes farklı yazar; kodlanırsa bütün ilkokul mezunları tek sorguyla listelenir. Hastanede tanılar kodla tutulursa diyabet hastaları kolayca bulunur. Öğrenci numarasının başındaki giriş yılı ve bölüm kodu da bu tür kodlamadır; bölüm kodu veri tabanında bölüm tablosuyla öğrenci tablosu arasında yabancı anahtar olarak ilişki kurar.

- **Test basamakları.** Birim testi her modülün algoritmasının ve kodunun doğruluğunu sınar. Bütünlük testi modüller birleştirildiğinde de doğru çalışıp çalışmadığına bakar. Sistem testi işletim sistemiyle uyumu, aynı anda kaç kullanıcının çalışabileceğini ve veri tabanından okumayı denetler. Onaylama (kullanıcı) testinde kullanıcı, analiz sırasında istediği şeylerin gerçekten yapılıp yapılmadığını onaylar. Sınama bu sırayla yürütülür (ekrandan, 00:20:00).

- **Kullanıcı eğitimi.** Sistemle ilgilenecek olanlara (işleten, düzenleyen) işletim sistemi ve program modüllerinin yapısı hakkında daha ayrıntılı bilgi verilir. Uç kullanıcılara sistemde yapabilecekleri işlemler, hangi modülle ne yaptıkları ve menüler arasında nasıl geçecekleri anlatılır. Üst yönetime sistem aracılığıyla hangi bilgileri alabilecekleri ve sistemin kısıtları anlatılır.

- **Geçiş yöntemleri.** Amaç eski sistemden veri ve iş kaybı olmadan yeni sisteme geçmektir.
  - Doğrudan geçiş: belirlenen bir tarihten (T anı) itibaren eski sistem tamamen bırakılır (ekrandan, 00:25:00). Yeni veri tabanı eski sistemin verisi dönüştürülerek önceden hazırlanır, bütün kullanıcılar eğitilmiş olur.
  - Paralel geçiş: eski ve yeni sistem belirlenen süre boyunca birlikte çalışır; verilerin tutarlı kalması için her işlem iki sistemde de yapılır. Eğitim geçiş süreci sırasında da verilebilir.
  - Dereceli geçiş: yeni sistem belli işlevleriyle devreye girer, diğer işlevler zamanla aşamalı aktarılır, yeni sistem tüm işlevleriyle çalışmaya başlayınca eski sistem kaldırılır (ekrandan, 00:30:00). Kademeler birbiriyle uyumlu seçilmelidir.
  - Prototip geçiş: dereceli geçişe göre daha organizedir. Sistemin bir prototipi küçük bir bölüm için kullanıma alınır, eski sistem bir süre prototiple birlikte çalışır, sonuçlara göre düzeltmeler yapıldıktan sonra tamamen yeni sisteme geçilir. Hoca örnek olarak bir bankanın yeni uygulamasını önce küçük bir şubesinde denemesini verdi.
  - Dağıtılmış geçiş: kurumun bölümleri ya da departmanları tek tek yeni sisteme dahil edilir; sistem belli periyotlarla değerlendirilip bakımı yapılır.

- **Bakım.** Donanım arızasında bakım yapıldığı gibi yazılım da kullanıma alındıktan sonra bakımdan geçer: birkaç ay sonra çıkan hataların düzeltilmesi, geliştirme ortamı ya da veri tabanının yeni sürümleriyle iyileştirme, kullanıcının işleyişindeki değişikliklere uyarlama.

- **Spor salonu örneği, analiz.** Var olan sistemde üyeler salona gidip kayıt oluyor. Yeni sistemde üyeler online üye olacak, sınıfların takvim ve eğitmen bilgilerini görecek, kontenjanı olan sınıflara kaydolacak, ödeme yapacak, özel ders talep edebilecek. Aylık sabit ücret dışında pilates, dans gibi sınıflar ve özel dersler ayrı ücretlendirilir (ekrandan, 00:55:00). Yönetim üyelikleri onaylar, sınıf oluşturur, tarih-saat ve eğitmen belirler. Eğitmen bilgilerini günceller ve sınıflarının katılımcı listesini görür. Veri toplamak için açık ve kapalı uçlu sorulardan oluşan anket kullanılır.

- **Veri akış diyagramı (Gane-Sarson).** Taslak (context) diyagramda tek süreç olarak "Spor Salonu Sistemi" ve dış varlıklar üye, eğitmen, yönetim görülür. 1. seviyede yedi işlem vardır (ekrandan, 01:05:00): 1.0 Üye Olma, 2.0 Sınıf Oluşturma, 3.0 Ödeme Yapma, 4.0 Sınıf Bilgileri Görüntüleme, 5.0 Sınıfa Kaydolma, 6.0 Katılımcıları Görüntüleme, 7.0 Bilgilerini Güncelleme; veri depoları D1 Üyeler, D2 Sınıf Bilgileri, D3 Ücretler, D4 Eğitmenler. 2. seviyede 3.0 Ödeme Yapma; ücretin hesaplanması, ödemenin alınması ve kalan borcun hesaplanması alt işlemlerine açılır.

- **Veri sözlüğü ve ER diyagramı.** Veri sözlüğü veri akış diyagramındaki her elemanı (veri akışı, veri deposu) adı, tanımı, miktarı gibi özellikleriyle tanımlar. ER diyagramında (ekrandan, 01:10:00) Üye, Sınıf, Eğitmen, Yönetim, Muhasebe varlıkları; Kaydol, Ders Ver, Sınıf Oluştur, Ödeme Yap, Raporla ilişkileriyle bağlanır.

- **Nesneye yönelik analiz ve tasarım.** Use case diyagramında aktörler üye, eğitmen, yönetimdir; sınıfa kaydolma, sınıf bilgisini görüntülemeyi `include` ile içerir, özel ders talebi `extend` ile genişletir. Ödeme senaryosu dokümanında birincil aktör üye, ön koşul üyelik ve online erişim, son koşul ödeme bilgilerinin doğrulanmasıdır; ana akışta üye tutarı görür, kart ve fatura bilgisini girer, onayla ödeme gerçekleşir; bilgi yanlışsa sistem hata verir (alternatif akış). Sınıf diyagramında aerobik, dans, pilates dersleri "Ders" üst sınıfından genelleme ile türeyen alt sınıflardır. Ardışıl diyagram (ekrandan, 01:20:00) üye olma, sınıfa kaydolma ve borç öğrenme sırasındaki metot çağrılarını gösterir; borç `saatUcreti*katılımSüresi` olarak hesaplanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
