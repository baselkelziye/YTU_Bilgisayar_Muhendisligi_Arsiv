# Ders 11 Genişletilmiş Notu: Şifreleme Araçları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: şifreleme algoritmaları kısmı
- 2. Simetrik şifreleme
- 3. Simetrik blok şifreleme algoritmaları: DES, 3DES ve AES
- 4. Büyük mesajlar: ECB ve akış şifreleme
- 5. Mesaj kimlik doğrulama
- 6. Hash fonksiyonları
- 7. Açık anahtarlı şifreleme
- 8. Dijital imza, sertifika ve dijital zarf
- 9. Rastgele sayılar
- 10. Pratik uygulama: iletilen ve depolanan verinin şifrelenmesi
- Dersin Toparlaması

## 1. Giriş: şifreleme algoritmaları kısmı

Dersin ilk kısmında genel bir girişten sonra uzun bir bölüm boyunca bilgisayar ve ağ güvenliğinin yönetimsel süreçleri ele alınmıştı: risk analizi ve planlama, insan kaynakları güvenliği, fiziksel güvenlik, güvenlik kontrolleri ve en son hukuki süreçler. Bu dersle üçüncü kısma, şifreleme algoritmalarına geçilir. Kısım üç haftalık olarak planlanmıştır ve içeriği slaytta şöyle verilmiştir (ekrandan, 00:05:00):

- 3.1 Şifreleme Araçları
- 3.2 Simetrik Şifreleme ve Mesaj Gizliliği
- 3.3 Açık Anahtarlı Şifreleme ve İleti Kimlik Doğrulaması

Hoca, şifrelemenin öğrenciler tarafından bilindiğini varsaydı ve bu dersi bir hatırlatma olarak kurguladı. Amaç, sonraki haftalarda anlatılacak ayrıntılı konulara bağlam oluşturmaktır. Ders sırası şöyle özetlendi: önce simetrik şifreleme ve sağladığı gizlilik, sonra simetrik şifrelemeyi kullanan mesaj doğrulama ve hash fonksiyonları (bir fonksiyonun hash fonksiyonu olabilmesi için taşıması gereken özellikler), ardından açık anahtarlı şifreleme ve onun sık kullanıldığı dijital imza, anahtar yönetimi ve dijital zarflar, en son da rastgele ve sözde rastgele sayı üreteçleri ile bir dizinin rastgele sayılabilmesi için gereken kriterler.

## 2. Simetrik şifreleme

### 2.1 Tanım ve gereksinimler

Simetrik şifreleme, iletim ortamında kaynakla hedef arasındaki verinin ve depolanan verinin gizliliği için kullanılan evrensel bir tekniktir (ekrandan, 00:10:00). Geleneksel şifreleme ya da tek anahtarlı şifreleme diye de adlandırılır ve çok eskidir; hoca Antik Roma'ya kadar uzanan örnekler olduğunu söyledi. Tek bir anahtar vardır; aynı anahtarla şifrelenir ve aynı anahtarla çözülür.

Güvenli kullanım için slaytta iki gereksinim verilmiştir:

- Güçlü bir şifreleme algoritması.
- Gönderici ve alıcının gizli anahtarın kopyalarını güvenli bir şekilde almış olması ve anahtarı güvende tutması.

Hoca birinci gereksinimle ilgili önemli bir noktanın altını çizdi: algoritmanın bilinir olması onun zayıf olduğu anlamına gelmez. Bir algoritmanın yapısı çok iyi bilinebilir; hatta iyi bilinen bir algoritmanın zayıflıkları yıllar içinde bulunup düzeltilmiş demektir, bu yüzden kırılması daha zordur. Anahtar bilinmedikçe algoritmayı bilmek saldırgana yetmez. İkinci gereksinim için anahtarın güçlü olması gerekir: sözlük saldırısıyla, tahminle ya da sosyal mühendislikle bulunamayacak bir anahtar.

> **Hocanın vurgusu:** Güvenlik algoritmanın gizli tutulmasına değil, güçlü bir algoritmaya ve gizli tutulan güçlü bir anahtara dayanır.

### 2.2 Model

Model basittir. Düz metin $X$ ve gizli anahtar $K$ şifreleme algoritmasına girer ve şifreli metin üretilir:

$$Y = E(K, X)$$

Şifreli metin hem düz metnin hem anahtarın fonksiyonudur, ama ikisiyle de görünür bir ilişki taşımamalıdır; şifreli metinden düz metni ya da anahtarı tahmin etmek mümkün olmamalıdır. Alıcı tarafta şifre çözme algoritması aynı anahtarı kullanarak düz metni geri üretir:

$$X = D(K, Y)$$

Hoca anahtarın önemini bir öyküyle anlattı: eski zamanlarda bir kölenin saçları kazınır, mesaj kafa derisine işlenir ve saçlar uzayınca köle gönderilirmiş. Kölenin kendisi bile mesajdan habersizdir; "anahtar", saçların kazınması gerektiğini bilmektir. Bunu bilmeyen biri köleyi yakalasa da mesajı bulamaz.

> **Ek bilgi (derste anlatılmadı):** Bu öykü mesajın içeriğini değil varlığını gizleyen steganografinin klasik bir örneğidir ve genellikle Herodot'un aktardığı bir Antik Yunan öyküsü olarak bilinir. Şifreleme ise mesajın varlığını gizlemez, içeriğini okunamaz hale getirir.

### 2.3 Simetrik şifrelemeye saldırılar

Şifreli metne yapılan saldırılar iki ana gruba ayrılır.

**Kriptoanalitik saldırılar.** Saldırgan algoritmanın yapısına ve zayıflıklarına, ayrıca elindeki bilinen düz metin–şifreli metin çiftlerine dayanır. Bu örnekler üzerinde matematiksel işlemlerle anahtarı bulmaya çalışır. Anahtar bulunursa iş kolaylaşır: simetrik şifrelemede anahtar değişmediği sürece, o anahtarla şifrelenmiş geçmişteki ve gelecekteki bütün mesajlar çözülebilir.

**Kaba kuvvet (brute force) saldırıları.** Şifreli metin üzerinde olası anahtarlar, anlamlı bir düz metin elde edilene kadar sırayla denenir. Hoca örnek olarak 8 karakterlik bir anahtar verdi: 29 harfli Türkçe alfabeden seçilen karakterlerle $29^8 \approx 5 \times 10^{11}$ farklı olasılık vardır (python ile hesaplandı: $29^8 = 500\,246\,412\,961$). Pratikte saldırgan önce sosyal mühendislikle tahmin edilebilir anahtarları dener: doğum tarihi, tuttuğu takım, yakınlarının adları gibi. Çünkü insanlar akılda tutmayı kolaylaştıran şeyleri anahtar olarak seçme eğilimindedir. Normal koşullarda ise istatistiksel olarak başarıya ulaşmak için olası bütün anahtarların en az yarısının denenmesi gerekir.

## 3. Simetrik blok şifreleme algoritmaları: DES, 3DES ve AES

### 3.1 DES

En eski ve en yaygın kullanılmış simetrik şifreleme algoritması DES'tir (Data Encryption Standard, Veri Şifreleme Standardı). Slayttaki bilgiler (ekrandan, 00:15:00):

- NIST tarafından 1977'de FIPS PUB 46 olarak uyarlanmıştır.
- Veri Şifreleme Algoritması (DEA) olarak da anılır.
- 64 bit şifreli metin bloğu oluşturmak için 64 bit düz metin bloğu ve 56 bit anahtar kullanır.

DES bir blok şifredir. Blok şifre, belirli bit büyüklüğündeki bir veri bloğunu belirli büyüklükteki bir anahtarla birlikte alır ve belirli büyüklükte bir çıkış üretir.

Slaytta DES'in gücüyle ilgili iki endişe sıralanır. Birincisi algoritmanın kendisidir. Ancak DES, var olan en çok çalışılmış şifreleme algoritmasıdır; 1977'den beri çok sayıda araştırmacı üzerinde çalışmış ama şimdiye kadar ölümcül bir hata bulunamamıştır. Hocanın ifadesiyle "algoritma cepte". İkinci endişe 56 bitlik anahtardır: $2^{56} \approx 7{,}2 \times 10^{16}$ olası anahtar 1977'nin bilgisayarları için çok uzun süre gerektiriyordu, ama ticari işlemcilerin bugünkü hızı ve veri merkezlerindeki dağıtık hesaplama bu anahtar uzunluğunu yetersiz kılmaktadır.

> **Hocanın vurgusu:** DES'te sorun algoritmada değil, anahtar büyüklüğündedir.

### 3.2 Üçlü DES (3DES)

Algoritma sağlamsa anahtarı büyütmenin en basit yolu, aynı algoritmayı art arda üç kez ve her seferinde farklı bir anahtarla uygulamaktır. İki farklı anahtar kullanılırsa $2 \times 56 = 112$ bit, üç farklı anahtar kullanılırsa $3 \times 56 = 168$ bit anahtar uzunluğu elde edilir.

> **Ders sonrası not:** Hoca bir yerde üç anahtar için "198 bit" ve "2 üzeri 198" dedi, hemen ardından doğru değeri (56 × 3 = 168 bit) verdi. Doğrusu 168 bit ve $2^{168}$ olası anahtardır.

3DES, para söz konusu olduğu için önce finansal uygulamalarda kullanılmış ve ANSI X9.17 olarak standartlaştırılmıştır. Avantajları:

- 168 bit anahtar uzunluğu sayesinde kaba kuvvet saldırısına dayanıklıdır.
- Temeli DES'e dayandığı için algoritma güvenilir ve yapısı basittir.

Dezavantajları:

- Algoritma çok eskidir; günümüzün paralel mimarilerine ve yazılım ortamlarına göre yavaştır.
- Hâlâ 64 bitlik blok kullanır.

Hoca 64 bitlik bloğun neden sorun olduğunu açıkladı. Eskiden e-postalar, mesajlar ve komutlar kısaydı; bugün ise video akışları ve web sayfaları gibi çok büyük mesajlar var. Bunlar 64 bitlik parçalara bölündüğünde, protokolün sabit başlık (header) ve kuyruk (trailer) alanları da parçalara düşer. Örneğin bir web sayfasının başındaki HTML sürüm satırı her sayfada aynıdır. Kriptoanalizin ihtiyaç duyduğu şey düz metin–şifreli metin çiftleri olduğundan, bu sabit alanlar saldırgana hazır çiftler sağlar ve anahtarın bulunmasını kolaylaştırabilir.

### 3.3 AES

Teknoloji ilerledikçe (paralel işleme, süper bilgisayarlar, dağıtık ve bulut mimarileri) 3DES'in de uzun süreli kullanım için makul olmadığı görüldü. Slayttaki akış şöyledir (ekrandan, 00:20:00):

- 3DES için bir yedek gerekiyordu; 3DES uzun süreli kullanım için makul değildi.
- NIST 1997'de yeni bir AES için teklif çağrısında bulundu. Koşullar:
  - 3DES'e eşit veya daha iyi bir güvenlik gücüne sahip olmalıdır.
  - Önemli ölçüde geliştirilmiş verimlilik.
  - Simetrik blok şifreleme.
  - 128 bit veri ve 128/192/256 bit anahtarlar.
- Kasım 2001'de seçilen Rijndael:
  - İlk değerlendirme turunda önerilen 15 algoritma kabul edildi.
  - İkinci tur, alanı 5 algoritmaya daralttı.
  - FIPS 197 olarak yayınlandı.

> **Ek bilgi (derste anlatılmadı):** Rijndael büyük olasılıkla Ekim 2000'de kazanan algoritma olarak açıklanmış, FIPS 197 standardı ise Kasım 2001'de yayımlanmıştır. Slayttaki "Kasım 2001" tarihi bu yüzden standardın yayım tarihine karşılık gelir.

DES ile karşılaştırıldığında AES, DES ve 3DES'in 64 bitlik bloğu yerine 128 bitlik blok alır ve 128 bitlik çıktı üretir. Anahtar DES'te 56 bit, 3DES'te 112 ya da 168 bit iken AES 128, 192 ya da 256 bitlik anahtar kabul eder ve anahtar boyutu ne olursa olsun çıktı 128 bittir.

### 3.4 Kaba kuvvet süreleri

Hoca güvenliği anahtar uzunluğu üzerinden karşılaştırdı. 56 bitlik DES anahtarı için $2^{56} \approx 7{,}2 \times 10^{16}$ olası anahtar vardır. Saniyede $10^{13}$ şifre çözme yapabilen dağıtık bir düzenek kurulursa, ki hoca bunun çok makul olduğunu söyledi, ortalama arama yaklaşık 1 saat sürer. Bu yüzden DES finansal işlemlerde artık kullanılmaz. Aynı hızla 128 bitlik AES anahtarının aranması yaklaşık $5{,}3 \times 10^{17}$ yıl sürer; 192 ve 256 bitlik anahtarlarda bu süre evrenin oluşumundan sonuna kadar geçecek süreden de uzundur.

Python ile kontrol (ortalama, anahtar uzayının yarısı):

- 56 bit, saniyede $10^{13}$ deneme: $2^{55}/10^{13} \approx 3{,}6 \times 10^{3}$ s, yani yaklaşık 1 saat.
- 128 bit, saniyede $10^{13}$ deneme: $2^{127}/10^{13} \approx 1{,}7 \times 10^{25}$ s, yani yaklaşık $5{,}4 \times 10^{17}$ yıl.
- 56 bit, saniyede $10^{9}$ deneme: $2^{55}/10^{9} \approx 3{,}6 \times 10^{7}$ s, yani yaklaşık 1,1 yıl.

> **Ders sonrası not:** Hoca saniyede bir milyar ($10^9$) deneme yapan bir bilgisayarda 56 bitlik anahtarın "bin yıldan biraz fazla" sürdüğünü söyledi. Hesaplanan süre yaklaşık 1,1 yıldır; hoca büyük olasılıkla değeri yanlış aktardı. Dağıtık düzenek için de "saniyede 10 bin" dedi; 1 saatlik sonucu veren hız saniyede $10^{13}$ denemedir.

## 4. Büyük mesajlar: ECB ve akış şifreleme

### 4.1 Elektronik kod kitabı (ECB) modu

Pratik bir sorun: DES ve 3DES 64 bitlik, AES 128 bitlik blok alır. Mesaj bundan büyükse ne yapılır? İlk akla gelen, mesajı blok boyutunda parçalara bölmek, her parçayı aynı anahtarla şifrelemek ve sonra birleştirip göndermektir. Slayttaki şekil (ekrandan, 00:25:00) bu durumu gösterir:

```text
Şifreleme:     P1 --(K)--> Encrypt --> C1    P2 --(K)--> Encrypt --> C2   ...   Pn --(K)--> Encrypt --> Cn
Şifre çözme:   C1 --(K)--> Decrypt --> P1    C2 --(K)--> Decrypt --> P2   ...   Cn --(K)--> Decrypt --> Pn
(her blok b bit; bütün bloklarda aynı anahtar K)
```

Düz metin $b$ bitlik $P_1, P_2, \dots, P_n$ bloklarına bölünür, her blok aynı $K$ ile şifrelenip $C_1, \dots, C_n$ elde edilir; alıcı aynı anahtarla her bloğu ayrı ayrı çözer. Sorun, düz metindeki tekrar eden kısımların şifreli metinde de aynen tekrar etmesidir. Web sayfası ya da e-posta gibi protokollerde bazı alanlar her mesajda tekrar eder; kriptoanalist bu tekrarlardan yararlanarak şifreyi daha kolay kırabilir. Bu endişeyi gidermek için farklı çalışma modları (modes of operation) geliştirilmiştir.

### 4.2 Akış şifreleme

Akış şifrelemede anahtar $K$, sözde rastgele bayt üretecine (anahtar akışı üreteci, key stream generator) girdi olarak verilir. Slayttaki şekil (ekrandan, 00:25:00):

```text
Gönderici:  K --> sözde rastgele bayt üreteci --> k
            düz metin bayt akışı M  XOR  k  -->  şifreli metin bayt akışı C
Alıcı:      K --> sözde rastgele bayt üreteci --> k   (aynı anahtar, aynı akış)
            C  XOR  k  -->  düz metin bayt akışı M
```

Aynı anahtar her iki tarafta aynı akışı ürettiği için alıcı şifreyi çözebilir. Her parça farklı bir anahtar değeriyle şifrelendiğinden tekrar eden metinlerden yararlanmak çok zorlaşır. Rastgele üreteçlerdeki temel beklenti de şudur: farklı bir anahtarla aynı diziyi elde etmek mümkün olmamalıdır.

### 4.3 Blok ve akış şifre karşılaştırması

- Blok şifre her seferinde bir blok alır ve her blok için bir şifreli blok üretir. Anahtar yeniden kullanılabilir ve daha yaygındır.
- Akış şifre girdiyi sürekli bir akış olarak işler ve akan veriden şifreli metin üretir. Mesajı bloklara bölme işi olmadığı için daha hızlıdır ve daha az kodla gerçekleştirilebilir.

## 5. Mesaj kimlik doğrulama

### 5.1 Neden gerekli?

Simetrik şifreleme mesajın gizliliğini sağlar. Ancak hocanın vurguladığı gibi her zaman derdimiz gizlilik değildir; mesajın kimden geldiğinin doğrulanması en az gizlilik kadar önemlidir. Örneğin bir e-postada "saat 3'te toplantı var" ya da "şu kişiye 300 lira gönder" yazıyor olabilir. İçeriğin gizli olması önemli değildir; önemli olan mesajın doğru kişiden gelmesidir.

Mesaj kimlik doğrulama aktif saldırılara karşı korur. Örneğin bir saldırgan şifreli bir mesajı saklayıp daha sonra yeniden gönderebilir ya da mesaj başka bir kaynaktan geliyor olabilir. Mesaj kimlik doğrulama şunlardan emin olmayı sağlar:

- Mesaj doğru kişiden, yani orijinal kaynaktan gelmiştir.
- Mesaj doğru zamanda ve doğru sırada gelmiştir.
- İçerik değiştirilmemiştir.

> **Hocanın vurgusu:** Mesaj doğrulamada amaç içeriği gizlemek değil, mesajın gerçek olduğunu doğrulamaktır; mesaj okunabilir, ama değiştirilmemiş olmalıdır.

### 5.2 Gizlilik olmadan mesaj doğrulama

Slayttaki maddeler (ekrandan, 00:30:00):

- İleti şifreleme tek başına güvenli bir kimlik doğrulama biçimi sağlamaz.
- Bir mesajı ve onun kimlik doğrulama etiketini şifreleyerek kimlik doğrulama ve gizliliği tek bir algoritmada birleştirmek mümkündür.
- Tipik olarak mesaj doğrulama, mesaj şifrelemeden ayrı bir fonksiyon olarak sağlanır.
- Gizlilik olmadan mesaj doğrulamanın tercih edilebileceği durumlar:
  - Aynı mesajın birkaç hedefe yayınlandığı uygulamalar.
  - Bir tarafın ağır bir yüke sahip olduğu ve gelen tüm mesajların şifresini çözecek zamanının olmadığı bir değişim.
  - Düz metin olarak bir bilgisayar programının kimlik doğrulaması.
- Böylece güvenlik gereksinimlerini karşılamada hem kimlik doğrulama hem de şifreleme için yer vardır.

Hoca bu maddeleri örneklerle açtı. Şifreleme gizliliği sağlar ama mesajın doğru zamanda ve orijinal kaynaktan gelip gelmediğini tek başına garanti etmez. Mesajla birlikte zaman damgası ve kaynakla ilgili bilgiler de şifrelenirse ve alıcı bunları kontrol ederse, doğrulama ve gizlilik birleştirilebilir. Birinci durum için verilen örnek: bir kurum aynı duyuruyu bütün çalışanlarına gönderiyorsa her birine ayrı anahtar dağıtmak ve bu anahtarların gizliliğini sağlamak anlamsızdır. İkinci durum, ağır işlem yükü altındaki ve gelen her mesajın şifresini çözecek zamanı olmayan gerçek zamanlı uygulamalardır.

### 5.3 Mesaj doğrulama kodu (MAC)

En basit yöntem mesaj doğrulama kodudur (Message Authentication Code, MAC). Gönderici, mesajı ve alıcıyla paylaştığı gizli anahtarı MAC algoritmasına verir, bir MAC üretir ve bunu orijinal mesaja ekleyerek gönderir. Alıcı aynı anahtara sahiptir; aynı MAC algoritmasıyla kendisi bir kod üretir ve gelen kodla karşılaştırır. İki kod aynıysa mesaj değiştirilmemiştir, doğru kaynaktan, doğru zamanda ve doğru sırada gelmiştir. Mesaj içeriği şifrelenmediği için alıcının yükü daha azdır.

### 5.4 Hash fonksiyonuyla mesaj doğrulamanın üç yolu

Hoca mesaj doğrulamanın üç farklı yolunu anlattı. Üçünde de önce mesajın özeti (hash'i) alınır.

1. **Simetrik şifrelemeyle:** Mesajın hash'i alınır. Hash fonksiyonu girdi boyutu ne olursa olsun sabit büyüklükte çıktı ürettiği için bu çıktı tek bir blok gibi simetrik şifrelenebilir. Şifrelenmiş özet mesaja eklenir. Alıcı mesajın hash'ini kendisi hesaplar, gelen şifreli özeti paylaşılan anahtarla çözer ve ikisini karşılaştırır. Özet de şifreli olduğu için saldırgan mesajı değiştirip özeti yeniden hesaplayamaz.
2. **Açık anahtarlı şifrelemeyle:** Özet açık anahtarlı şifrelemeyle şifrelenip mesaja eklenir.
3. **Gizli değerle:** Mesajın önüne ya da arkasına yalnız gönderici ve alıcının bildiği gizli bir değer eklenir, bütünün hash'i alınır ve bu hash mesajla birlikte gönderilir. Gizli değer olmadan aynı hash'i elde etmek mümkün değildir; alıcı aynı işlemi yapıp karşılaştırarak mesajı doğrular.

> **Ders sonrası not:** Hoca açık anahtarlı yöntemi anlatırken önce özetin alıcının açık anahtarıyla şifrelendiğini söyledi, sonra "ya da tersi" diyerek gönderenin özel anahtarıyla şifreleyip herkesin açık anahtarla açabileceğini ekledi. Kimlik doğrulama için doğru olan ikincisidir: özet gönderenin özel anahtarıyla şifrelenir, alıcı gönderenin açık anahtarıyla doğrular. Alıcının açık anahtarıyla şifreleme gizlilik sağlar, gönderenin kimliğini kanıtlamaz.

## 6. Hash fonksiyonları

### 6.1 Gereksinimler

Bir fonksiyonun hash (özet) fonksiyonu olabilmesi için:

- Herhangi büyüklükte bir veri bloğunu kabul edebilmeli ve sabit uzunlukta bir çıktı üretmelidir.
- Özetten orijinal metni bulmak mümkün olmamalıdır.
- Aynı özete sahip iki farklı metin bulunamamalıdır.

> **Ek bilgi (derste anlatılmadı):** Bu özellikler literatürde tek yönlülük (preimage direnci), zayıf çakışma direnci (verilen bir metinle aynı özeti veren başka metin bulamama) ve güçlü çakışma direnci (aynı özeti veren herhangi iki metni bulamama) diye adlandırılır. Ayrıca özetin her girdi için kolay hesaplanabilmesi beklenir.

### 6.2 Hash fonksiyonlarının güvenliği

Slayttaki yapı (ekrandan, 00:35:00):

- Güvenli bir H fonksiyonuna saldırmak için iki yaklaşım vardır:
  - Kriptoanaliz: algoritmadaki mantıksal zayıflıklardan yararlanır.
  - Kaba kuvvet saldırısı: hash fonksiyonunun gücü sadece algoritma tarafından üretilen hash kodunun uzunluğuna bağlıdır.
- SHA en yaygın kullanılan hash algoritmasıdır: NIST tarafından geliştirildi ve 1993'te yayınlandı.
- Ek güvenli hash fonksiyonu uygulamaları:
  - Parolalar: bir parolanın hash'i işletim sistemi tarafından saklanır.
  - İzinsiz giriş tespiti: her dosya için $H(F)$'yi bir sistemde saklayın ve hash değerlerini güvenceye alın.

Kaba kuvvet saldırısında saldırgan aynı özeti verebilecek olası girdileri deneyerek sonuca ulaşmaya çalışır. SHA'nın ilk sürümünden sonra SHA-1 ve SHA-256 gibi SHA-2 ailesi üyeleri yayımlandı.

Hoca uygulamaları önceki derslerle bağladı. Parolalar açık metin olarak değil, tuz (salt) eklenerek hash'lenmiş halde (Unix'teki gölge, shadow dosyası gibi) saklanır. Giriş sırasında girilen parolanın aynı algoritmayla hash'i alınıp saklananla karşılaştırılır; böylece sistem parolanın kendisini saklamadan doğrulama yapabilir. Dosya bütünlüğü için de dosya saklanırken hash'i de saklanır; hash dosyanın içeriğine ve özniteliklerine bağlıdır. Daha sonra erişimde yeniden hash alınıp karşılaştırılır; değer değişmemişse dosya orijinal haliyle duruyordur.

## 7. Açık anahtarlı şifreleme

### 7.1 Temel fikir

Açık anahtarlı (asimetrik) şifreleme ilk kez 1976'da Diffie ve Hellman tarafından önerildi. Temeli matematiksel bir fonksiyondur; bu, eliptik eğri fonksiyonları ya da iki büyük asal sayının çarpımına dayanan bir fonksiyon olabilir. İki anahtar vardır: açık anahtar ve özel anahtar. Bir anahtarla şifrelenen metin ancak diğer anahtarla çözülebilir; aynı anahtarla hem şifreleme hem şifre çözme yapılamaz. Açık anahtarların dağıtımı için ayrıca özel bir protokol gerekir.

Bileşenler: düz metin, şifreleme algoritması, şifre çözme algoritması, şifreli metin ve anahtar çifti.

### 7.2 İki kullanım biçimi

**Gizlilik.** Bob, Alice'e mesaj göndermek istesin. Bob mesajı Alice'in açık anahtarıyla şifreler. Şifreli mesajı Alice'in özel anahtarından başka bir şey açamaz; böylece mesajın yalnız Alice tarafından okunacağından emin olunur.

**Kimlik doğrulama.** Alice mesajın gerçekten Bob'dan geldiğinden emin olmak isteyebilir. Bu durumda Bob mesajı kendi özel anahtarıyla şifreler, Alice de Bob'un açık anahtarıyla çözer. Bob'un özel anahtarına yalnız Bob sahip olduğu için mesajın kesinlikle Bob'dan geldiği doğrulanır.

### 7.3 Asimetrik şifreleme algoritmaları

Slayttaki karşılaştırma (ekrandan, 00:40:00):

- RSA (Rivest, Shamir, Adleman):
  - 1977'de geliştirildi.
  - Açık anahtar şifrelemeye yönelik en yaygın kabul gören ve uygulanan yaklaşım.
  - Bazı $n$ için düz metin ve şifreli metnin $0$ ile $n-1$ arasında tam sayılar olduğu blok şifre.
- Diffie-Hellman anahtar değişim algoritması:
  - İki kullanıcının, mesajların daha sonra simetrik olarak şifrelenmesi için gizli anahtar olarak kullanılabilecek paylaşılan bir sır hakkında güvenli bir şekilde anlaşmaya varmasını sağlar.
  - Anahtar değişimi ile sınırlıdır.
- Dijital İmza Standardı (DSS):
  - SHA-1 ile yalnızca dijital imza işlevi sağlar.
  - Şifreleme veya anahtar değişimi için kullanılamaz.
- Eliptik eğri kriptografisi (ECC):
  - RSA gibi güvenlik, ancak çok daha küçük anahtarlarla.

Hoca bu algoritmaları üç uygulama alanına göre karşılaştırdı: dijital imza, simetrik anahtar dağıtımı ve gizli anahtarların şifrelenmesi. RSA ve ECC her üç alanda kullanılabilen genel algoritmalardır. Diffie-Hellman yalnız anahtar dağıtımı (anahtar değişimi), DSS yalnız dijital imza içindir. ECC'nin RSA'dan farkı, aynı güvenliği daha küçük anahtarla sağlamasıdır.

### 7.4 Açık anahtarlı şifrelemenin gereksinimleri

Hoca sözlü olarak şu gereksinimleri saydı:

- Anahtar çiftini oluşturmak hesaplama açısından kolay olmalıdır.
- Bir anahtarla şifrelemek ve diğer anahtarla şifreyi çözmek kolay olmalıdır.
- Anahtarlar birbirinin yerine kullanılamamalıdır.

<!-- BELİRSİZ: 00:41:19 civarında altyazıda bir boşluk var ve gereksinimlerden biri yalnız "...bulunamamalı" diye kalmış. Büyük olasılıkla açık anahtardan özel anahtarın ya da açık anahtar ve şifreli metinden düz metnin hesaplanamaması kastediliyor; bu ana ait kare yok. -->

## 8. Dijital imza, sertifika ve dijital zarf

### 8.1 Dijital imza

Açık anahtarlı şifrelemenin ilk uygulama alanı dijital imzadır. NIST'in FIPS 186-4 standardındaki tanıma göre dijital imza, doğru şekilde uygulandığında kaynağın kimlik doğrulamasını, veri bütünlüğünü ve imzanın inkâr edilemezliğini sağlayan bir mekanizma sunan kriptografik bir dönüşümün sonucudur. Yani bir değerdir: bir dosyanın, mesajın ya da başka bir veri bloğunun fonksiyonu olarak üretilen belirli bit uzunluğunda bir veri bloğu.

FIPS 186-4'te üç dijital imza algoritması tanımlanmıştır:

- DSA (Digital Signature Algorithm; standardın adıyla DSS).
- RSA dijital imza algoritması.
- ECDSA (Elliptic Curve Digital Signature Algorithm).

İşleyiş:

1. Bob mesajı yazar; mesajın özeti bir hash algoritmasıyla alınır.
2. Özet, Bob'un özel anahtarıyla imza algoritmasından geçirilir ve imza mesaja eklenir.
3. Alice mesajı alınca mesajın hash'ini kendisi hesaplar.
4. Bu hash, gelen imza ve Bob'un açık anahtarı doğrulama algoritmasına girer; algoritma doğru/yanlış (geçerli/geçersiz) sonucu üretir. İmza Bob'a aitse sonuç "doğru", değilse "yanlış" olur.

### 8.2 Açık anahtar sertifikası

Kimlik doğrulamanın ön koşulu, Bob'un açık anahtarının gerçekten Bob'a ait olduğundan emin olmaktır. Bunun için sertifika kullanılır. Slayttaki şekil (ekrandan, 00:45:00) iki aşamayı gösterir:

```text
İmzalı sertifika oluşturma:
  İmzasız sertifika = [Bob'un kimlik bilgisi | Bob'un açık anahtarı | CA bilgisi]
  İmzasız sertifika --H--> hash kodu
  hash kodu + CA'nın özel anahtarı --SG (imza üretimi)--> dijital imza
  İmzalı sertifika = İmzasız sertifika + dijital imza

Sertifikayla Bob'un açık anahtarını doğrulama:
  Sertifikanın imza hariç kısmı --H--> hash kodu
  hash kodu + imza + CA'nın açık anahtarı --SV (imza doğrulama)--> imza geçerli / geçersiz
```

İmzasız sertifika kullanıcının kimliğini, açık anahtarını ve sertifika otoritesi (CA) ile ilgili bilgiyi içerir. Bu bilgilerin hash'i alınır ve CA kendi özel anahtarıyla imzalar. Karşı taraf sertifikanın imza dışındaki kısmının hash'ini alır ve imzayı CA'nın açık anahtarıyla doğrular. Sonuç geçerliyse, sertifikadaki açık anahtarın Bob'a ait olduğu güvenle kabul edilir. Hocanın özetiyle bu, Bob'un kendi açık anahtarını karşı tarafa güvenilir biçimde göndermesinin yoludur.

### 8.3 Dijital zarf

Bir başka uygulama dijital zarftır. Amaç hem mesajın gizliliğini sağlamak hem de mesajın yalnız doğru kişi tarafından açılabilmesini garanti etmektir.

Gönderici tarafı:

1. Rastgele bir simetrik anahtar üretilir.
2. Mesaj bu simetrik anahtarla şifrelenir ve zarfa konur.
3. Simetrik anahtar alıcının açık anahtarıyla şifrelenir ve o da zarfa konur.
4. Zarf gönderilir.

Alıcı tarafı:

1. Zarftaki şifreli simetrik anahtarı kendi özel anahtarıyla çözer.
2. Elde ettiği simetrik anahtarla mesajın şifresini çözer.

Böylece büyük mesaj hızlı simetrik şifrelemeyle korunur, simetrik anahtarın güvenli dağıtımı ise açık anahtarlı şifrelemeyle sağlanır.

## 9. Rastgele sayılar

### 9.1 Kullanım alanları

Hoca, hem dijital zarfta hem akış şifrelemede rastgele sayılardan söz edildiğine dikkat çekti. Rastgele sayılar şu amaçlarla kullanılır:

- Simetrik bir akış şifresi için anahtar akışı üretmek.
- Geçici oturum anahtarları (session key) üretmek.
- Dijital zarflardaki anahtarları üretmek.
- Tekrar (replay) saldırılarını önlemek için el sıkışmalarda (handshake) kullanılan değerleri üretmek.

### 9.2 Rastgele sayı gereksinimleri

Bir sayı dizisinin rastgele sayılabilmesi için iki ana kriter vardır (ekrandan, 00:50:00):

- Rastgelelik. Kriterler:
  - Üniform dağılım: sayıların her birinin oluşma sıklığı yaklaşık olarak aynı olmalıdır.
  - Bağımsızlık: dizideki hiçbir değer diğerlerinden çıkarılamaz.
- Tahmin edilemezlik:
  - Her sayı dizideki diğer sayılardan istatistiksel olarak bağımsızdır. Hocanın örneğiyle, 3'ten sonra 5 gelmesi istatistiksel olarak bağımsızdır.
  - Rakip, dizinin gelecekteki öğelerini daha önceki öğelere dayanarak tahmin edememelidir.

### 9.3 Sözde rastgele ve gerçek rastgele sayı üreteçleri

Kriptografik uygulamalarda, örneğin tekrar saldırılarını önlemek için el sıkışmalarda, tipik olarak algoritmik rastgele sayı üreteçleri kullanılır. Bu algoritmalar deterministiktir: aynı girdi her zaman aynı diziyi üretir. Bu nedenle ürettikleri diziler gerçekte rastgele değildir; ama istatistiksel rastgelelik testlerini geçerler. Bunlara sözde rastgele (pseudorandom) sayılar denir ve aynı girdiye karşı aynı diziyi ürettikleri için tahmin edilebilir olmaları mümkündür.

Gerçek rastgele sayı üreteçleri ise deterministik olmayan kaynaklar kullanır: radyasyon, bir kondansatördeki gerilim, gaz deşarjı gibi fiziksel olaylar. Hoca modern işlemcilerde de bu tür deterministik olmayan kaynakların kullanıldığını ekledi.

> **Ders sonrası not:** Hoca bu kısımda "deterministik" ve "nondeterministik" terimlerini yer yer karıştırdı (örneğin sözde rastgele üreteçler için bir yerde "nondeterministik" dedi). Doğrusu: sözde rastgele sayı üreteçleri deterministik algoritmalardır; gerçek rastgele sayı üreteçleri deterministik olmayan fiziksel kaynaklar kullanır.

## 10. Pratik uygulama: iletilen ve depolanan verinin şifrelenmesi

Simetrik şifrelemenin en genel kullanım alanı iletilen verilerin şifrelenmesidir: A kaynağından B'ye iletilen verinin gizliliği şifrelemeyle sağlanır. İkinci alan depolanan, özellikle arşivlenen verilerin şifrelenmesidir. Hoca depolanan verilerin şifrelenmesinde piyasada genellikle üçüncü parti uygulama ve cihazların kullanıldığını belirtti. <!-- BELİRSİZ: 00:53:13 ile 00:53:24 arasında altyazıda boşluk var; depolanan verinin şifrelenmesine dair anlatımın bir kısmı eksik. -->

## Dersin Toparlaması

Bu ders, şifreleme algoritmaları kısmına giriş olarak şifreleme araçlarını bir bütün halinde hatırlattı. Simetrik şifrelemede güvenliğin güçlü bir algoritmaya ve gizli tutulan güçlü bir anahtara dayandığı, DES'in algoritma olarak sağlam ama 56 bitlik anahtarı yüzünden yetersiz kaldığı, 3DES'in anahtarı büyüttüğü ama yavaş ve 64 bit bloklu olduğu, AES'in ise 128 bit blok ve 128/192/256 bit anahtarla bu sorunları çözdüğü görüldü. Büyük mesajlarda ECB'nin tekrar eden blokları ele verdiği, akış şifrelerinin anahtardan üretilen sözde rastgele akışla XOR'ladığı anlatıldı.

İkinci yarıda gizlilikten ayrı bir hedef olan mesaj kimlik doğrulama, MAC ve hash fonksiyonlarıyla doğrulama yöntemleri, hash fonksiyonlarının gereksinimleri ve kullanım alanları işlendi. Açık anahtarlı şifrelemede iki anahtarın gizlilik ve kimlik doğrulama için nasıl kullanıldığı, RSA, Diffie-Hellman, DSS ve ECC'nin karşılaştırması, dijital imza, sertifika ve dijital zarf anlatıldı. Son olarak rastgele sayıların gereksinimleri ile sözde rastgele ve gerçek rastgele üreteçlerin farkı ele alındı. Kısmın sonraki derslerinde simetrik şifreleme ve mesaj gizliliği ile açık anahtarlı şifreleme ve ileti kimlik doğrulaması daha ayrıntılı işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
