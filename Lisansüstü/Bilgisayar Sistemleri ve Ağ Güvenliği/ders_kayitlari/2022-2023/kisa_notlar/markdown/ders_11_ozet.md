# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin yeri ve içeriği (ekrandan, 00:05:00)
  - Önceki derslerde bilgisayar ve ağ güvenliğinin yönetimsel süreçleri (risk analizi, planlama, insan kaynakları, fiziksel güvenlik, kontroller ve hukuki süreçler) işlenmişti. Bu dersle "3. Şifreleme Algoritmaları" kısmına geçilir.
  - Kısmın başlıkları: 3.1 Şifreleme Araçları, 3.2 Simetrik Şifreleme ve Mesaj Gizliliği, 3.3 Açık Anahtarlı Şifreleme ve İleti Kimlik Doğrulaması.
  - Bu ders, sonraki ayrıntılı konulara bağlam oluşturmak için şifreleme araçlarının hızlı bir tekrarıdır: simetrik şifreleme, mesaj doğrulama, hash fonksiyonları, açık anahtarlı şifreleme, dijital imza, sertifika, dijital zarf ve rastgele sayılar.
- Simetrik şifreleme (ekrandan, 00:10:00)
  - İletilen veya depolanan verilerin gizliliği için kullanılan evrensel ve çok eski bir tekniktir; geleneksel ya da tek anahtarlı şifreleme diye de anılır.
  - Aynı anahtar hem şifrelemede hem şifre çözmede kullanılır.
  - Güvenli kullanım için iki gereksinim: güçlü bir şifreleme algoritması; gönderici ve alıcının gizli anahtarın kopyalarını güvenli biçimde almış olması ve anahtarı güvende tutması.
  - Model: düz metin $X$ ve gizli anahtar $K$ şifreleme algoritmasına girer, şifreli metin $Y = E(K, X)$ çıkar; alıcı aynı anahtarla $X = D(K, Y)$ elde eder.
- Simetrik şifrelemeye saldırılar
  - Kriptoanalitik saldırı: algoritmanın yapısına ve bilinen düz metin–şifreli metin çiftlerine dayanarak anahtarı bulmaya çalışır. Anahtar bulunursa o anahtarla şifrelenmiş geçmiş ve gelecek bütün mesajlar çözülür.
  - Kaba kuvvet saldırısı: şifreli metin üzerinde olası anahtarlar, anlamlı bir düz metin çıkana kadar denenir. Ortalama olarak olası anahtarların yarısının denenmesi gerekir.
- DES (Veri Şifreleme Standardı) (ekrandan, 00:15:00)
  - NIST tarafından 1977'de FIPS PUB 46 olarak yayımlandı; Veri Şifreleme Algoritması (DEA) diye de anılır.
  - Blok şifredir: 64 bit düz metin bloğunu 56 bit anahtarla 64 bit şifreli metin bloğuna dönüştürür.
  - Algoritmanın kendisinde bugüne kadar ölümcül bir zayıflık bulunmadı; asıl sorun 56 bitlik anahtarın günümüz işlemci hızları karşısında yetersiz kalmasıdır.
- Üçlü DES (3DES)
  - DES'i art arda üç kez, farklı anahtarlarla uygular: iki anahtarla 112 bit, üç anahtarla 168 bit anahtar uzunluğu.
  - Finansal uygulamalar için ANSI X9.17 olarak standartlaştırıldı.
  - Avantajları: kaba kuvvete karşı dayanıklı, DES'e dayandığı için güvenilir. Dezavantajları: eski ve yavaş bir algoritma, hâlâ 64 bitlik blok kullanması.
- AES (Gelişmiş Şifreleme Standardı) (ekrandan, 00:20:00)
  - 3DES uzun süreli kullanım için makul olmadığından NIST 1997'de yeni bir algoritma için teklif çağrısı yaptı.
  - Çağrının koşulları: 3DES'e eşit ya da daha iyi güvenlik, önemli ölçüde iyileştirilmiş verimlilik, simetrik blok şifre, 128 bit veri bloğu ve 128/192/256 bit anahtar.
  - İlk turda 15 algoritma kabul edildi, ikinci turda alan 5 algoritmaya daraltıldı, Rijndael seçildi ve FIPS 197 olarak yayımlandı.
- Kaba kuvvet süreleri
  - 56 bitlik DES anahtarı saniyede $10^{13}$ deneme yapan bir düzenekle yaklaşık 1 saatte kırılır; 128 bitlik AES anahtarı aynı hızla yaklaşık $5{,}3 \times 10^{17}$ yıl sürer.
- Büyük mesajların şifrelenmesi (ekrandan, 00:25:00)
  - Elektronik kod kitabı (ECB) modu: düz metin $b$ bitlik $P_1, \dots, P_n$ bloklarına bölünür, her blok aynı $K$ ile şifrelenip $C_1, \dots, C_n$ elde edilir.
  - ECB'nin zayıflığı: düz metindeki tekrar eden kısımlar (protokol başlıkları gibi) şifreli metinde de tekrar eder ve kriptoanalize yardım eder. Bunun için çalışma modları (modes of operation) geliştirilmiştir.
  - Akış şifreleme: anahtar sözde rastgele bayt üretecine (anahtar akışı üreteci) girer, üretilen anahtar akışı düz metin bayt akışıyla XOR'lanır; alıcı aynı anahtarla aynı akışı üretip XOR ile düz metni geri alır.
- Blok ve akış şifre karşılaştırması
  - Blok şifre her seferinde bir blok işler, anahtar yeniden kullanılabilir, daha yaygındır.
  - Akış şifre girdiyi sürekli işler; daha hızlıdır ve daha az kodla gerçekleştirilir.
- Mesaj kimlik doğrulama
  - Amaç gizlilik değil, mesajın gerçek olduğunun doğrulanmasıdır: doğru kaynaktan, doğru zamanda ve sırada gelmiş ve içeriği değiştirilmemiş olmalıdır. Aktif saldırılara (mesajı değiştirme, tekrar gönderme, sahte kaynak) karşı korur.
  - Gizlilik olmadan mesaj doğrulamanın tercih edildiği durumlar (ekrandan, 00:30:00): aynı mesajın birçok hedefe yayınlanması; bir tarafın ağır yük altında olup gelen bütün mesajların şifresini çözecek zamanının olmaması; bir bilgisayar programının düz metin olarak kimlik doğrulaması.
  - Mesaj doğrulama kodu (MAC): gönderici, mesajdan ve paylaşılan gizli anahtardan bir MAC üretip mesaja ekler; alıcı aynı anahtarla MAC'i yeniden hesaplar ve gelenle karşılaştırır.
  - Hash fonksiyonu kullanan üç yöntem: hash değerini simetrik şifrelemek, hash değerini açık anahtarlı şifrelemeyle (gönderenin özel anahtarı) şifrelemek ve mesaja gizli bir değer ekleyip hash almak.
- Hash (özet) fonksiyonları (ekrandan, 00:35:00)
  - Her uzunlukta veri bloğunu kabul eder ve sabit uzunlukta çıktı üretir.
  - Özetten orijinal metne dönülememeli; aynı özeti veren iki farklı metin bulunamamalıdır.
  - Saldırı yaklaşımları: kriptoanaliz (algoritmadaki mantıksal zayıflıklar) ve kaba kuvvet (gücü yalnız hash kodunun uzunluğuna bağlıdır).
  - En yaygın algoritma SHA'dır; NIST tarafından geliştirilip 1993'te yayımlandı (sonra SHA-1, SHA-2 ailesi).
  - Ek uygulamalar: parolaların hash'inin işletim sistemi tarafından saklanması; her dosya için $H(F)$ saklanarak izinsiz değişikliğin tespiti.
- Açık anahtarlı (asimetrik) şifreleme
  - İlk kez 1976'da Diffie ve Hellman tarafından önerildi; matematiksel bir fonksiyona dayanır.
  - Açık anahtar ve özel anahtar olmak üzere iki anahtar vardır; biriyle şifrelenen öbürüyle çözülür.
  - Gizlilik için: gönderici alıcının açık anahtarıyla şifreler, yalnız alıcı özel anahtarıyla çözebilir. Kimlik doğrulama için: gönderici kendi özel anahtarıyla şifreler, herkes onun açık anahtarıyla doğrulayabilir.
- Asimetrik algoritmalar (ekrandan, 00:40:00)
  - RSA (Rivest, Shamir, Adleman): 1977'de geliştirildi; en yaygın kabul gören yaklaşım; düz ve şifreli metnin bir $n$ için $0$ ile $n-1$ arasındaki tam sayılar olduğu blok şifre.
  - Diffie-Hellman: iki kullanıcının daha sonra simetrik şifrelemede gizli anahtar olarak kullanacağı bir sır üzerinde güvenle anlaşmasını sağlar; anahtar değişimiyle sınırlıdır.
  - DSS (Dijital İmza Standardı): SHA-1 ile yalnız dijital imza işlevi sağlar; şifreleme veya anahtar değişimi için kullanılamaz.
  - ECC (eliptik eğri kriptografisi): RSA gibi güvenlik, ama çok daha küçük anahtarlarla.
- Dijital imza
  - NIST FIPS 186-4 tanımı: doğru uygulandığında kaynağın kimlik doğrulamasını, veri bütünlüğünü ve imzanın inkâr edilemezliğini sağlayan kriptografik dönüşümün sonucudur.
  - FIPS 186-4'teki üç algoritma: DSA, RSA dijital imza algoritması ve ECDSA.
  - İşleyiş: mesajın hash'i alınır, gönderenin özel anahtarıyla imzalanır ve mesaja eklenir; alıcı hash'i yeniden hesaplar, imza ve gönderenin açık anahtarıyla doğrulama algoritması "geçerli/geçersiz" sonucu üretir.
- Açık anahtar sertifikası (ekrandan, 00:45:00)
  - İmzasız sertifika kullanıcının kimlik bilgisini, açık anahtarını ve sertifika otoritesinin (CA) bilgisini içerir.
  - CA bu bilgilerin hash'ini alıp kendi özel anahtarıyla imzalar. Alıcı, CA'nın açık anahtarıyla imzayı doğrulayarak açık anahtarın gerçekten o kullanıcıya ait olduğundan emin olur.
- Dijital zarf
  - Gönderici rastgele bir simetrik anahtar üretip mesajı onunla şifreler; simetrik anahtarı alıcının açık anahtarıyla şifreleyip zarfa ekler.
  - Alıcı önce kendi özel anahtarıyla simetrik anahtarı, sonra simetrik anahtarla mesajı çözer.
- Rastgele sayılar (ekrandan, 00:50:00)
  - Kullanım alanları: akış şifreleri için anahtar akışı, geçici oturum anahtarları, dijital zarftaki anahtarlar, tekrar (replay) saldırılarını önlemek için el sıkışmalarda kullanılan değerler.
  - Rastgelelik kriterleri: üniform dağılım (her sayının sıklığı yaklaşık aynı) ve bağımsızlık (dizideki hiçbir değer diğerlerinden çıkarılamaz).
  - Tahmin edilemezlik: her sayı diğerlerinden istatistiksel olarak bağımsızdır; rakip dizinin gelecekteki öğelerini önceki öğelere dayanarak tahmin edememelidir.
  - Sözde rastgele sayı üreteçleri deterministik algoritmalardır; gerçek rastgele sayı üreteçleri radyasyon, kondansatör gerilimi, gaz deşarjı gibi deterministik olmayan fiziksel kaynaklar kullanır.
- Pratik uygulama
  - Simetrik şifreleme hem iletilen verilerin hem depolanan (arşivlenmiş) verilerin şifrelenmesinde kullanılır; depolanan veri için genellikle üçüncü parti yazılım ve cihazlar kullanılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritmanın bilinmesi zayıflık değildir
  - İyi bilinen ve çok incelenmiş bir algoritmanın zayıflıkları zaten bulunup düzeltilmiştir. Güvenlik algoritmanın gizliliğine değil, anahtarın gizliliğine ve gücüne dayanır.
- DES'te sorun algoritma değil anahtar boyutu
  - Binlerce kişinin incelemesine rağmen DES'te ölümcül bir hata bulunamadı; zayıflık 56 bitlik anahtarın kaba kuvvete dayanamamasıdır. 3DES bu yüzden aynı algoritmayı üç kez uygular.
- 64 bitlik blok sorunu
  - Web sayfası, e-posta gibi büyük mesajlar parçalandığında başlık ve sabit satırlar (ör. HTML sürüm satırı) bilinen düz metin–şifreli metin çiftleri oluşturur; bu da kriptoanalizi kolaylaştırır.
- Mesajın kimden geldiği en az gizliliği kadar önemlidir
  - "Saat 3'te toplantı var" ya da "şu kişiye para gönder" gibi bir mesajın içeriği gizli olmayabilir; önemli olan doğru kişiden geldiğinin ve değiştirilmediğinin doğrulanmasıdır.
- Kaba kuvvette sosyal mühendislik
  - Saldırgan önce doğum tarihi, tuttuğu takım, yakınlarının adları gibi tahmin edilebilir anahtarları dener; çünkü insanlar akılda kalan şeyleri anahtar olarak seçer.

## Kısa Tekrar Notları

- Simetrik şifreleme: tek anahtar; güçlü algoritma + güvenle paylaşılmış gizli anahtar.
- Saldırılar: kriptoanaliz (algoritma ve düz/şifreli metin çiftleri) ve kaba kuvvet (ortalama anahtar uzayının yarısı).
- DES: 64 bit blok, 56 bit anahtar, FIPS PUB 46 (1977).
- 3DES: 112 veya 168 bit anahtar, ANSI X9.17, yavaş, hâlâ 64 bit blok.
- AES: Rijndael, FIPS 197; 128 bit blok, 128/192/256 bit anahtar.
- ECB: aynı anahtarla bağımsız bloklar; tekrar eden düz metin tekrar eden şifreli metin verir.
- Akış şifre: anahtar → sözde rastgele anahtar akışı → XOR.
- MAC: paylaşılan anahtarla üretilip mesaja eklenen doğrulama kodu.
- Hash: değişken girdi, sabit çıktı; tek yönlü ve çakışmaya dayanıklı; SHA (NIST, 1993).
- Asimetrik: açık + özel anahtar; RSA (1977), Diffie-Hellman (yalnız anahtar değişimi), DSS (yalnız imza), ECC (küçük anahtar).
- Dijital imza: hash + gönderenin özel anahtarı; doğrulama açık anahtarla; FIPS 186-4.
- Sertifika: kullanıcı kimliği + açık anahtar + CA bilgisi, CA'nın özel anahtarıyla imzalı.
- Dijital zarf: mesaj rastgele simetrik anahtarla, simetrik anahtar alıcının açık anahtarıyla şifrelenir.
- Rastgele sayı gereksinimleri: üniform dağılım, bağımsızlık, tahmin edilemezlik.

## Detaylı Açıklamalar

Bu ders, dönemin üçüncü kısmı olan şifreleme algoritmalarına giriştir ve öğrencilerin daha önce bildiği varsayılan şifreleme araçlarını hızla hatırlatır. Simetrik şifrelemede düz metin $X$ ve gizli anahtar $K$ şifreleme algoritmasına verilir, ortaya çıkan şifreli metin hem metnin hem anahtarın fonksiyonudur ama ikisiyle de görünür bir ilişki taşımamalıdır. Alıcı aynı anahtarla şifre çözme algoritmasını çalıştırarak düz metni geri alır. Güvenlik iki şeye dayanır: algoritmanın güçlü olması ve anahtarın yalnız gönderici ile alıcı tarafından bilinmesi. Hoca anahtarın sözlük saldırısıyla ya da sosyal mühendislikle tahmin edilemeyecek kadar güçlü olması gerektiğini vurguladı. Bir anahtarın gizli kalmasına dair benzetme olarak Antik Roma'da mesajın bir kölenin kazınmış kafa derisine yazılıp saçları uzayınca gönderildiği öyküsünü anlattı.

> **Ek bilgi (derste anlatılmadı):** Hocanın anlattığı köle örneği, mesajın varlığını gizleyen steganografinin klasik bir örneğidir ve genellikle Herodot'un aktardığı bir Antik Yunan öyküsü olarak bilinir. Şifrelemeden farkı, mesajın içeriğini değil varlığını gizlemesidir.

Simetrik şifrelemeye yapılan saldırılar ikiye ayrılır. Kriptoanalitik saldırılar algoritmanın matematiksel yapısından ve elde edilmiş düz metin–şifreli metin çiftlerinden yararlanarak anahtarı bulmaya çalışır. Anahtar bulunduğunda, anahtar değişmediği sürece geçmiş ve gelecek bütün trafik çözülebilir. Kaba kuvvet saldırısında olası anahtarlar sırayla denenir; istatistiksel olarak başarı için anahtar uzayının en az yarısını denemek gerekir. Hoca örnek olarak 8 karakterlik ve 29 harfli Türkçe alfabeden seçilen bir anahtar için $29^8 \approx 5 \times 10^{11}$ olasılık bulunduğunu belirtti.

DES, NIST'in 1977'de FIPS PUB 46 ile yayımladığı, 64 bitlik blokları 56 bitlik anahtarla şifreleyen bir blok şifredir. $2^{56} \approx 7{,}2 \times 10^{16}$ olası anahtar 1977'nin bilgisayarları için büyük bir sayıydı ama günümüzde dağıtık hesaplama karşısında yetersizdir. İlk çözüm 3DES oldu: aynı algoritmayı üç kez farklı anahtarlarla uygulamak. İki anahtarla 112, üç anahtarla 168 bitlik anahtar elde edilir. 3DES ANSI X9.17 ile finansal uygulamalarda standartlaştı. Ancak algoritma eski olduğundan yazılımda yavaştır ve 64 bitlik blok, büyük mesajların çok sayıda parçaya bölünmesine yol açar; bu parçalardaki sabit başlıklar kriptoanalize malzeme sağlar.

> **Ders sonrası not:** Hoca bir yerde üç anahtarlı 3DES için "198 bit" ve "2 üzeri 198" dedi, hemen ardından doğru değeri (3 × 56 = 168 bit) verdi. Doğrusu 168 bit ve $2^{168}$ olası anahtardır.

NIST 1997'de yeni bir standart için çağrı yaptı. Koşullar slaytta açıkça verildi (ekrandan, 00:20:00): 3DES'e eşit ya da daha iyi güvenlik, önemli ölçüde daha iyi verimlilik, simetrik blok şifre, 128 bit veri ve 128/192/256 bit anahtar. İlk turda 15 algoritma kabul edildi, ikinci turda 5'e inildi ve sonunda Rijndael seçilip FIPS 197 olarak yayımlandı. AES 128 bitlik blok alır ve anahtar boyutu ne olursa olsun 128 bitlik çıktı üretir. Hoca kaba kuvvet sürelerini karşılaştırdı: saniyede $10^{13}$ deneme yapan bir düzenek 56 bitlik anahtarı yaklaşık 1 saatte bulurken, 128 bitlik anahtar için yaklaşık $5{,}3 \times 10^{17}$ yıl gerekir; 192 ve 256 bit için bu süre evrenin yaşından çok daha uzundur. Bu sonuçlar python ile doğrulandı ($2^{55}/10^{13} \approx 3600$ s; $2^{127}/10^{13} \approx 5{,}4 \times 10^{17}$ yıl).

> **Ders sonrası not:** Hoca saniyede $10^9$ deneme yapan bir bilgisayarda 56 bitlik anahtarın "bin yıldan biraz fazla" sürdüğünü söyledi. Hesapla ($2^{55}/10^9$ s) bu süre yaklaşık 1,1 yıldır; hoca büyük olasılıkla tablodaki değeri yanlış okudu. Hız için de "saniyede 10 bin" dedi; 1 saatlik sonucu veren hız saniyede $10^{13}$ denemedir.

Mesaj bir bloktan büyük olduğunda ilk akla gelen yöntem, mesajı bloklara bölüp her bloğu aynı anahtarla şifrelemektir; buna elektronik kod kitabı (ECB) modu denir (ekrandan, 00:25:00). Düz metindeki tekrarlar şifreli metinde de tekrarlanacağı için bu yöntem kriptoanalize açıktır. Akış şifrelemede anahtar bir sözde rastgele bayt üretecine verilir, üretilen anahtar akışı düz metin baytlarıyla XOR'lanır. Alıcı aynı anahtarla aynı akışı üretip yeniden XOR'layarak düz metni elde eder. Farklı anahtarla aynı akışı üretmek mümkün olmamalıdır. Blok şifreler daha yaygındır ve anahtarı yeniden kullanabilir; akış şifreler daha hızlı ve daha az kodla gerçekleştirilir.

Mesaj kimlik doğrulama, mesajın içeriğini gizlemekten farklı bir hedeftir: mesajın doğru kaynaktan, doğru zamanda ve doğru sırada geldiğini ve değiştirilmediğini garanti eder. Hoca, şifrelemenin tek başına bunu sağlamadığını ve doğrulama ile gizliliğin ayrı ayrı ele alınması gerektiğini anlattı (ekrandan, 00:30:00). MAC yönteminde gönderici paylaşılan anahtarla mesajdan bir kod üretip ekler; alıcı aynı hesabı yapar ve kodlar aynıysa mesajın değiştirilmediğine ve doğru kaynaktan geldiğine güvenir. Hash fonksiyonuyla doğrulamanın üç yolu anlatıldı: mesaj özetini simetrik şifrelemek, özeti açık anahtarlı şifrelemeyle şifrelemek ve mesaja yalnız iki tarafın bildiği gizli bir değer ekleyip hash almak.

> **Ders sonrası not:** Hoca açık anahtarlı doğrulamada önce özetin alıcının açık anahtarıyla şifrelendiğini söyledi, sonra "ya da tersi" diye gönderenin özel anahtarını andı. Kimlik doğrulama için özet gönderenin özel anahtarıyla şifrelenir ve herkes gönderenin açık anahtarıyla doğrular; alıcının açık anahtarıyla şifreleme gizlilik sağlar, gönderenin kimliğini doğrulamaz.

Hash fonksiyonu her boyutta girdiyi alıp sabit uzunlukta özet üretir; özetten girdiye dönülememeli ve aynı özeti veren iki farklı girdi bulunamamalıdır. Hash fonksiyonlarına da kriptoanaliz ve kaba kuvvetle saldırılır; kaba kuvvete karşı güç yalnız özet uzunluğuna bağlıdır (ekrandan, 00:35:00). En yaygın aile NIST'in 1993'te yayımladığı SHA'dır. Hash'ler parolaların açık metin yerine (tuzla birlikte) özet olarak saklanmasında ve dosyaların özetlerinin saklanarak izinsiz değişikliklerin tespit edilmesinde kullanılır.

Açık anahtarlı şifreleme 1976'da Diffie ve Hellman tarafından önerildi. İki anahtar vardır ve biriyle şifrelenen ancak öbürüyle çözülebilir. Bob, Alice'e gizli bir mesaj göndermek istediğinde Alice'in açık anahtarıyla şifreler; mesajı yalnız Alice'in özel anahtarı açar. Alice mesajın Bob'dan geldiğinden emin olmak istediğinde ise Bob kendi özel anahtarıyla şifreler ve Alice onun açık anahtarıyla çözer. Algoritmalar slaytta karşılaştırıldı (ekrandan, 00:40:00): RSA her üç uygulamada (dijital imza, simetrik anahtar dağıtımı, gizli anahtarların şifrelenmesi) kullanılır; Diffie-Hellman yalnız anahtar değişimi, DSS yalnız dijital imza içindir; ECC RSA kadar genel olup aynı güvenliği daha küçük anahtarla sağlar. Açık anahtarlı şifrelemenin gereksinimleri olarak anahtar çiftinin, şifrelemenin ve şifre çözmenin hesaplama açısından kolay olması sayıldı. <!-- BELİRSİZ: 00:41:19 civarında gereksinimlerin bir kısmı altyazıda eksik ("...bulunamamalı"); büyük olasılıkla açık anahtardan özel anahtarın ve şifreli metinden düz metnin hesaplanamaması kastediliyor. -->

Dijital imza NIST FIPS 186-4'te, doğru uygulandığında kaynağın kimlik doğrulamasını, veri bütünlüğünü ve inkâr edilemezliği sağlayan kriptografik dönüşüm sonucu olarak tanımlanır; standart DSA, RSA ve ECDSA olmak üzere üç algoritma tanımlar. Gönderici mesajın özetini kendi özel anahtarıyla imzalar; alıcı özeti yeniden hesaplar ve gönderenin açık anahtarıyla doğrulama algoritmasını çalıştırır, sonuç geçerli ya da geçersiz olur. Sertifikada (ekrandan, 00:45:00) Bob'un kimlik bilgisi, açık anahtarı ve CA bilgisi bulunur; CA bunların özetini kendi özel anahtarıyla imzalar. Alıcı imzayı CA'nın açık anahtarıyla doğrulayarak Bob'un açık anahtarının gerçekten Bob'a ait olduğuna güvenir. Dijital zarfta mesaj rastgele üretilmiş bir simetrik anahtarla şifrelenir, bu anahtar da alıcının açık anahtarıyla şifrelenip zarfa konur; böylece hem gizlilik hem de mesajın yalnız alıcı tarafından açılabilmesi sağlanır.

Rastgele sayılar akış şifrelerinde, oturum anahtarlarında, dijital zarflarda ve tekrar saldırılarını önleyen el sıkışma değerlerinde kullanılır. Bir dizinin rastgele sayılabilmesi için üniform dağılım ve bağımsızlık (rastgelelik) ile tahmin edilemezlik kriterlerini sağlaması gerekir (ekrandan, 00:50:00). Kriptografik uygulamalardaki algoritmik üreteçler deterministiktir; aynı girdi aynı diziyi verdiği için ürettikleri sayılar gerçekte rastgele değil sözde rastgeledir, ama istatistiksel rastgelelik testlerini geçer. Gerçek rastgele sayı üreteçleri ise radyasyon, kondansatör gerilimi ya da gaz deşarjı gibi deterministik olmayan fiziksel kaynaklardan yararlanır.

> **Ders sonrası not:** Hoca bu kısımda "deterministik" ve "nondeterministik" terimlerini yer yer karıştırdı. Doğrusu: sözde rastgele sayı üreteçleri deterministik algoritmalardır, gerçek rastgele sayı üreteçleri deterministik olmayan fiziksel kaynaklar kullanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
