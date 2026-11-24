# Ders 13 Genişletilmiş Notu: Simetrik Şifreleme ve Mesaj Gizliliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: şifreleme algoritmaları bölümündeki yer
- 2. Simetrik şifreleme ve beş bileşeni
- 3. Kriptografik yöntemlerin sınıflandırılması
- 4. Şifrelenmiş mesajlara yönelik saldırı türleri
- 5. Hesaplama olarak güvenli şifreleme
- 6. Feistel şifre yapısı ve blok şifreleyici tasarımı
- 7. DES ve Üçlü DES
- 8. AES (Gelişmiş Şifreleme Standardı)
- 9. Akış şifreleyiciler ve RC4
- 10. Blok şifreleme çalışma modları
- 11. Simetrik anahtar dağıtımı
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş: şifreleme algoritmaları bölümündeki yer

Dersin bu bölümü "Şifreleme Algoritmaları" başlığını taşır ve üç alt başlıktan oluşur (ekrandan, 00:20:00):

- 3.1 Şifreleme Araçları
- 3.2 Simetrik Şifreleme ve Mesaj Gizliliği
- 3.3 Açık Anahtarlı Şifreleme ve İleti Kimlik Doğrulaması

Önceki derste şifreleme araçlarına genel bir giriş yapılmıştı: simetrik ve asimetrik şifrelemenin kullanım alanları, hash fonksiyonları ve bir fonksiyonun hash fonksiyonu sayılabilmesi için taşıması gereken özellikler. Hoca bunun aslında bu dersi almadan önce bilinmesi gereken ön koşul bilgisi olduğunu, hatırlatma amacıyla hızlıca tekrar edildiğini söyledi.

İki ana şifreleme yaklaşımı vardır: simetrik (tek anahtarlı) şifreleme ve asimetrik (açık anahtarlı) şifreleme. Bu derste simetrik şifreleme işlenir ve odak **mesaj gizliliğidir**. Bir sonraki derste açık anahtarlı şifreleme uygulama alanlarıyla birlikte işlenecek ve odak **kimlik doğrulama** olacaktır.

Önceki derste simetrik şifrelemenin blok şifreleme ve akış şifreleme olarak ikiye ayrıldığı görülmüştü. Blok şifrelemede veri belli uzunlukta bloklar hâlinde alınır; örneğin AES'te blok 128 bittir. Günümüz uygulamalarında mesajlar bu blok boyutundan çok daha büyüktür. Bu yüzden büyük mesajlarda ya akış şifreleme yöntemlerinden biri ya da blok şifrelemenin çalışma modları kullanılır. Bu derste akış şifrelemeden RC4 algoritması, blok şifrelemeden de çalışma modlarının blok diyagramları ele alınır.

Hoca bu ihtiyacın nedenini şöyle açıkladı: mesaj boyutu büyüdükçe ve mesajın doğası (örneğin bir PDF ya da HTML belgesi gibi standart bir belge olduğu) biliniyorsa, o belgede tekrar eden kısımlar da bilinir. Tekrar eden bu kısımlar, kriptoanalitik yöntemlerle anahtarı bulmayı mümkün kılar ya da kolaylaştırır.

## 2. Simetrik şifreleme ve beş bileşeni

Simetrik şifreleme literatürde geleneksel şifreleme, gizli anahtarlı şifreleme ya da tek anahtarlı şifreleme gibi farklı adlarla anılır. 1970'lerin sonunda iki anahtarlı (açık anahtarlı) şifreleme ortaya çıkana kadar şifrelemenin tek alternatifiydi ve antik çağlardan beri kullanılmaktadır. Bugün de yaygın olarak kullanılan şifreleme yöntemidir. Temel varsayımı, anahtarı yalnız alıcının ve göndericinin bilmesi, onların dışında kimsenin bilmemesidir.

Simetrik şifrelemenin beş bileşeni vardır:

- **Düz metin:** gizliliği istenen mesaj.
- **Şifreleme algoritması:** düz metni dönüştüren algoritma.
- **Gizli anahtar:** şifreleme algoritmasına ikinci girdi olarak giren anahtar.
- **Şifreli metin:** algoritmanın çıktısı. Hem algoritmanın hem de gizli anahtarın fonksiyonudur.
- **Şifre çözme algoritması:** alıcının, yalnız kendisinin bildiği anahtarla şifreli metinden düz metni geri elde ettiği algoritma.

Algoritmada bir zayıflık yoksa, anahtarı bilmeyen biri yalnız algoritmayı bilerek şifreli metinden düz metni bulamaz.

## 3. Kriptografik yöntemlerin sınıflandırılması

Kriptografik yöntemler üç bağımsız boyutta sınıflandırılır (ekrandan, 00:25:00):

| Boyut | Seçenekler |
|---|---|
| Düz metni şifreli metne dönüştürmek için kullanılan işlemlerin türü | Değiştirme (substitution): düz metindeki her öğe başka bir öğeye eşlenir. Yer değiştirme (transposition): düz metindeki öğeler yeniden düzenlenir. |
| Kullanılan anahtar sayısı | Gönderici ve alıcı aynı anahtarı kullanır: simetrik. Gönderici ve alıcının her biri farklı bir anahtar kullanır: asimetrik. |
| Düz metnin işlenme şekli | Blok şifreleyici: her seferinde girilen bir öğe bloğunu işler. Akış şifreleyici: giriş öğelerini sürekli olarak işler. |

Hoca değiştirme ile yer değiştirme arasındaki farkı vurguladı: değiştirmede metin birebir başka öğelerle değiştirilir; yer değiştirmede öğenin kendisi değişmez, yalnız metin içindeki yeri değişir. Gönderici ve alıcı aynı anahtarı kullanıyorsa yöntem simetrik ya da gizli anahtarlı şifrelemedir; farklı anahtarlar kullanıyorsa asimetrik şifrelemedir. Düz metin blok blok işleniyorsa blok şifreleyici, sürekli bir akış (stream) hâlinde işleniyorsa akış şifreleyici söz konusudur.

## 4. Şifrelenmiş mesajlara yönelik saldırı türleri

Önceki derste şifrelenmiş bir metinden şifreyi kırmanın iki yolu olduğu söylenmişti: kriptoanaliz ve kaba kuvvet (brute force) saldırısı. Kaba kuvvet saldırısında istatistik olarak olası anahtarların ortalama yarısını denemek gerekir. Örneğin 56 bitlik bir anahtarda $2^{56}$ farklı anahtar vardır. Hoca bunu dört haneli rakamlardan oluşan bir şifre örneğiyle somutlaştırdı: olası değerlerin en az yarısının denenmesi gerekir.

Hoca kaba kuvveti bir kenara bırakıp kriptoanalitik saldırılara odaklandı. Saldırı tiplerini, kriptoanalistin karşılaştığı zorluğa göre en zordan en kolaya sıraladı; çünkü bir algoritmayı güçlendirmek için bu zorluk sıralamasını hesaba katmak gerekir (ekrandan, 00:30:00):

| Saldırı tipi | Kriptoanalist tarafından bilinen |
|---|---|
| Yalnızca şifreli metin | Şifreleme algoritması; şifresi çözülecek şifreli metin |
| Bilinen düz metin | Şifreleme algoritması; şifresi çözülecek şifreli metin; gizli anahtarla oluşturulmuş bir veya daha fazla düz metin–şifreli metin çifti |
| Seçilmiş düz metin | Şifreleme algoritması; şifresi çözülecek şifreli metin; kriptoanalist tarafından seçilen düz metin mesajı ve gizli anahtarla oluşturulan karşılık gelen şifreli metin |
| Seçilmiş şifreli metin | Şifreleme algoritması; şifresi çözülecek şifreli metin; gizli anahtarla oluşturulan karşılık gelen şifresi çözülmüş düz metinle birlikte kriptoanalist tarafından seçilen sözde şifreli metin |
| Seçilmiş metin | Şifreleme algoritması; şifresi çözülecek şifreli metin; kriptoanalist tarafından seçilen düz metin mesajı ve karşılık gelen şifreli metin; kriptoanalist tarafından seçilen sözde şifreli metin ve karşılık gelen şifresi çözülmüş düz metin |

**En zor durum:** Kriptoanalistin elinde yalnız bir şifreli metin vardır ve metnin hangi algoritmayla (örneğin AES ya da DES) şifrelendiği bilinir. Saldırgan farklı anahtarlar deneyerek şifreli metinden anlamlı bir düz metin çıkarmaya çalışır. Düz metnin neye benzediğini bilmediği için doğru sonucu tanımak bile zordur.

**Bilinen düz metin:** Saldırgan bir şifreli metni ve onun düz hâlini ele geçirmiştir. Elinde algoritma, şifreli metin ve düz metin vardır; dolayısıyla sonucun neye benzeyeceğini bilir ve anahtarı bulmaya çalışır.

**Seçilmiş düz metin:** Bir önceki durumun geliştirilmiş hâlidir. Saldırgan anahtarı bilmez, ama örneğin içeriden birini bularak kendi hazırladığı bir metni şifrelettirir. Anahtarı ortaya çıkarmaya uygun bir düz metin hazırlamışsa bu çifti kullanabilir.

Sonraki satırlarda saldırganın elindeki bilgi giderek artar: aynı anahtarla oluşturulmuş birden fazla çift, seçilmiş düz metin çiftleri vb. Kriptoanalistin elinde ne kadar çok veri olursa şifreyi çözmesi o kadar kolaylaşır.

## 5. Hesaplama olarak güvenli şifreleme

Hoca bir şifrelemenin güvenli olduğuna nasıl karar verildiğini sordu. İlk akla gelen "kırılmıyorsa güvenlidir" cevabıdır, ama kırılmayan şifre yoktur; masrafı yapılırsa her şifre kırılır. Bir şifreleme şu durumlarda hesaplama açısından güvenlidir (ekrandan, 00:35:00):

- Şifre kırmanın maliyeti bilginin değerini aşıyorsa. Bu durumda kimse şifreyi kırmak için o maliyetin altına girmez.
- Şifreyi kırmak için gereken süre bilginin faydalı ömrünü aşıyorsa.

Hoca ikinci ölçütü bir örnekle açıkladı: şifrelenmiş bir bilgi ertesi gün gerçekleşecek bir olayla ilgiliyse, bu bilgi ancak olaydan makul bir süre önce elde edilirse işe yarar. Olay gerçekleştikten sonra bilgiyi elde etmenin pratik bir anlamı kalmaz.

Kırmak için gereken çaba miktarını tahmin etmek genellikle çok zordur. Saldırganlar süreyi kısaltmak için mümkün olduğunca çok bilgi toplamaya çalışır. Kaba kuvvet saldırısının süresi ve maliyeti ise tahmin edilebilir: istatistik olarak anahtar uzayının en az yarısının denenmesi gerekir.

## 6. Feistel şifre yapısı ve blok şifreleyici tasarımı

### 6.1 Feistel ağı

DES dahil birçok simetrik blok şifreleme algoritması, ilk olarak 1973'te IBM'den Horst Feistel tarafından açıklanan yapıya sahiptir (ekrandan, 00:40:00). Slayttaki şekil "Classical Feistel Network" başlığını taşır.

Yapının girdisi $2w$ bit uzunluğunda bir düz metin bloğu ve bir $K$ anahtarıdır. DES'te bu blok 64 bittir. Hoca 64 bitlik blok üzerinden anlattı:

```text
Düz metin (2w bit)
  -> sol yarı L0 (w bit), sağ yarı R0 (w bit)
Tur i (i = 1..n):
  sağ yarı, alt anahtar Ki ile F fonksiyonuna girer
  F çıktısı sol yarıyla XOR'lanır
  yarılar yer değiştirir:
    yeni sol  = önceki sağ yarı
    yeni sağ  = önceki sol yarı XOR F(önceki sağ yarı, Ki)
Son turdan sonra yarılar bir kez daha çaprazlanır (L(n+1), R(n+1))
  -> birleşerek şifreli metin (2w bit)
```

Yani 64 bitlik veri, 32 bitlik sol ve 32 bitlik sağ parçaya bölünür. Sağ parça $F$ fonksiyonu ile şifrelenir, çıktısı sol parçayla XOR'lanır ve bu sonuç ikinci turda sağ yarı olur; önceki turun sağ yarısı ise sol yarı olur. İşlem $n$ kez tekrarlanır ve sonunda iki yarı birleştirilerek karıştırılmış (şifrelenmiş) $2w$ bitlik şifreli metin elde edilir. Alt anahtarlar $K_i$ genellikle hem $K$'den hem de birbirlerinden farklıdır ve bir alt anahtar oluşturma algoritmasıyla $K$'den üretilir.

> **Ek bilgi (derste anlatılmadı):** Feistel yapısının önemli bir özelliği, şifre çözmenin aynı yapıyla, yalnız alt anahtarlar ters sırada ($K_n$'den $K_1$'e) kullanılarak yapılabilmesidir. Bu yüzden $F$ fonksiyonunun tersinir olması gerekmez.

### 6.2 Blok şifreleyici tasarım öğeleri

Hoca bir blok şifreleyicinin yapısında şunların bulunduğunu söyledi: bir dizi tekrar (tur) ve anahtar tarafından kontrol edilen, yani anahtarın fonksiyonu olan yerine koyma ve permütasyon işlemleri. Tasarım öğeleri şunlardır:

- **Blok boyutu:** genellikle 128 bit.
- **Anahtar boyutu:** genellikle 128 bit.
- **Tur sayısı:** tipik olarak 16 civarı.
- **Alt anahtar üretim algoritması:** anahtardan her tur için alt anahtar üretir.
- **Tur fonksiyonu:** XOR, toplama ve kaydırma gibi işlemlerden oluşur.
- **Hızlı yazılım şifreleme/şifre çözme:** veri blokları hızla geldiği için şifreleme ve şifre çözme mümkün olduğunca az saat çevriminde yapılabilmelidir.
- **Analiz kolaylığı.**

Hoca analiz kolaylığının bir zayıflık olmadığını özellikle belirtti. Algoritmanın anahtara göre nasıl işlem yaptığı bilinse bile, anahtar bilinmeden sonuçtan anahtarı çıkarmak mümkün olmaz. Ayrıca algoritma kolay analiz edilebilirse onu inceleyen kişi sayısı artar ve hatalar önceden tespit edilip düzeltilebilir.

## 7. DES ve Üçlü DES

### 7.1 DES

En yaygın kullanılmış blok şifreleme yöntemi Veri Şifreleme Standardı (Data Encryption Standard, DES) olmuştur. NIST'in eski adı olan NBS (National Bureau of Standards, Ulusal Standartlar Bürosu) tarafından kabul edilmiş ve 1977'de FIPS PUB 46 olarak yayımlanmıştır. Algoritma Veri Şifreleme Algoritması (DEA) olarak da adlandırılır.

DES 64 bitlik veri bloğunu alır ve 56 bitlik anahtarla şifreleyerek yine 64 bitlik bir şifreli metin üretir. Feistel ağının bir varyasyonunu kullanır.

Önceki derste söylendiği gibi DES araştırmacılar tarafından uzun süre incelenmiş ve algoritmada hayati bir hata bulunmamıştır. En büyük güvenlik sorunu anahtar boyutunun 56 bit olmasıdır. $2^{56}$ farklı anahtar vardır ve kaba kuvvet saldırısında bunun yarısı denendiğinde şifre elde edilir. Hoca, saniyede $10^{13}$ işlem yapabilen dağıtık ya da bulut tabanlı bir ağda DES'in kırılmasının yaklaşık bir saate kadar indiğini söyledi.

Bu hesap şöyle doğrulanır (python ile kontrol edildi):

- Anahtar uzayının yarısı: $2^{55} \approx 3{,}6 \times 10^{16}$ anahtar.
- Saniyede $10^{13}$ denemeyle süre: $3{,}6 \times 10^{16} / 10^{13} \approx 3600$ saniye $\approx 1$ saat.

> **Ders sonrası not:** Hoca tek makine için "1 GHz'lik bir makinede birkaç bin yıl" dedi. Saniyede $10^9$ denemede $2^{55}$ deneme yaklaşık 1,1 yıl sürer. "Binlerce yıl" rakamı büyük olasılıkla mikrosaniyede bir deneme (saniyede $10^6$) varsayımından gelir; bu varsayımla süre yaklaşık 1142 yıldır.

### 7.2 Üçlü DES (3DES)

DES algoritması güvenli olsa da anahtar boyutu yüzünden sakıncalıdır. Hoca bunu bir önceki bölümdeki güvenlik ölçütlerine bağladı: finansal verinin parasal bir değeri vardır, dolayısıyla saldırgan dağıtık ağlar kurmak gibi ciddi yatırımlar yapmayı göze alabilir ve bu yatırımın karşılığını aldığı verilerle çıkarabilir. Çözüm şu fikirle bulunmuştur: algoritma güçlü olduğuna göre aynı algoritma üç kez, farklı anahtarlarla tekrar edilirse anahtar 56 bit yerine $3 \times 56$ bit olur. Böylece Üçlü DES önerilmiştir.

Şifreleme üç aşamada yapılır (E: DES şifreleme, D: DES şifre çözme):

```text
Şifreleme:     P --E(K1)--> A --D(K2)--> B --E(K3)--> C
Şifre çözme:   C --D(K3)--> B --E(K2)--> A --D(K1)--> P
```

Düz metin $P$ önce $K_1$ anahtarıyla DES şifreleme algoritmasından geçer ve $A$ elde edilir. $A$, bu kez $K_2$ anahtarıyla şifre çözme algoritmasından, yani şifrelemenin tersi olan algoritmadan geçirilir ve $B$ elde edilir. $B$ de $K_3$ ile yeniden şifrelenir ve $C$ elde edilir:

$$C = E(K_3, D(K_2, E(K_1, P)))$$

Şifre çözme bu işlemin tersidir: $C$, $K_3$ ile şifre çözme algoritmasından geçer ve $B$ elde edilir; $B$, $K_2$ ile şifrelenir ve $A$ elde edilir; $A$, $K_1$ ile çözülür ve düz metne ulaşılır:

$$P = D(K_1, E(K_2, D(K_3, C)))$$

Her anahtar 56 bit olduğundan toplam anahtar uzunluğu $3 \times 56 = 168$ bittir. Bu durumda kaba kuvvet saldırısının süresi saatlerden yeniden binlerce yıla çıkar.

> **Ders sonrası not:** Hoca 3DES'in FIPS PUB 46-3 olarak 1985'te, X9.17 olarak 1999'da standartlaştığını söyledi. Büyük olasılıkla doğrusu tersidir: 3DES ilk kez 1985'te finansal uygulamalar için ANSI X9.17 standardıyla, 1999'da ise FIPS PUB 46-3 ile DES'in parçası olarak standartlaştırılmıştır.

## 8. AES (Gelişmiş Şifreleme Standardı)

### 8.1 AES'in ortaya çıkışı

DES üç kez art arda uygulanarak anahtar boyutunun küçüklüğünden doğan zayıflık giderilmişti, ama 3DES 1970'lerin algoritmasıdır ve yazılımda işlenmesi zordur. Özellikle hızlı işlem gerektiren durumlarda sorun çıkarır. Slayttaki özet şöyledir (ekrandan, 00:45:00):

- **3DES için bir yedek gerekiyordu:** 3DES uzun süreli kullanım için makul değildi.
- **NIST, 1997'de yeni bir AES için teklif çağrısında bulundu.** Gereksinimler:
  - 3DES'e eşit veya daha iyi bir güvenlik gücüne sahip olmalı.
  - Önemli ölçüde geliştirilmiş verimlilik.
  - Simetrik blok şifreleme.
  - 128 bit veri ve 128/192/256 bit anahtarlar.
- **Rijndael seçildi:** ilk değerlendirme turunda önerilen 15 algoritma kabul edildi, ikinci tur alanı 5 algoritmaya daralttı, seçilen algoritma FIPS 197 olarak yayımlandı.

Hoca gereksinimleri şöyle özetledi: güvenlik 3DES kadar olsun, ama programlama açısından kolay olsun; 128 bitlik blok alsın; 128, 192 ya da 256 bitlik anahtar kabul edebilsin; çıktı yine 128 bit olsun.

### 8.2 AES'in çalışması

AES de DES ve 3DES gibi turlardan oluşur; 128 bitlik anahtarda 10 tur vardır. Ancak Feistel ağını kullanmaz. İşleyiş şöyledir:

- 128 bitlik blok önce $4 \times 4$ baytlık bir kare matrise dönüştürülür.
- 128 bitlik anahtar da bir kare bayt matrisine dönüştürülür. Bu anahtardan her biri 4 bayt olan 44 kelimelik genişletilmiş anahtar üretilir.
- Her turda blok bayt yerine koyma (substitution), satırları kaydırma, sütunları karıştırma ve tur anahtarıyla XOR'lama işlemlerinden geçer. Şifre çözmede bu işlemlerin tersleri uygulanır.

> **Ek bilgi (derste anlatılmadı):** 128 bitlik anahtarda 44 kelime şu hesaptan gelir: ilk tur anahtarı eklemesi ve 10 turun her biri için 4'er kelimelik bir tur anahtarı gerekir, yani $(10 + 1) \times 4 = 44$ kelime.

**Bayt yerine koyma (S-box):** AES'te yerine koyma işleminde AES'in S-box tablosu kullanılır. Her bayt onaltılık iki haneyle yazılır; bu hanelerin her biri 4 bittir ve tabloda biri satırı, diğeri sütunu seçer. Hocanın tablodan gösterdiği örnekler:

- $00$ baytının yerine $63$ gelir.
- $66$ baytının yerine $33$ gelir.
- $04$ baytının yerine $F2$ gelir.

Şifre çözmede ters S-box kullanılır. Hoca doğrulamayı ters tablodan yaptı: $63$ için satır $6$, sütun $3$'e bakıldığında $00$ çıkar. Benzer şekilde $9B$'nin yerine $14$ geldiği, ters tabloda satır $1$, sütun $4$'e bakıldığında $9B$ çıktığı gösterildi. Bu değerler python ile AES S-box'ı hesaplanarak doğrulanmıştır: $S(00)=63$, $S(66)=33$, $S(04)=F2$, $S(9B)=14$; $S^{-1}(63)=00$, $S^{-1}(14)=9B$.

> **Ders sonrası not:** Hoca bir yerde "dört bitlik kelimelerden 44 tane" dedi. AES'te bir kelime 4 bayttır (32 bit); 4 bit, S-box'ta satır ya da sütunu seçen tek onaltılık hanedir.

**Satırları kaydırma ve sütunları karıştırma:** S-box ile karıştırılan matriste satırlar kaydırılır; böylece tek tek baytlar bir sütundan diğerine taşınır ve yayılır. Sütun karıştırmada her sütun ayrı işlenir; sütundaki 4 baytın her biri, sütundaki dört baytın hepsinin bir fonksiyonu olarak yeniden hesaplanır. Bunun için sonlu alanlar üzerinde denklemler ve tablolar kullanılır. Turun sonunda, genişletilmiş anahtardan gelen tur anahtarı bitleriyle basit bir XOR işlemi yapılır.

## 9. Akış şifreleyiciler ve RC4

### 9.1 Blok şifreleme ile akış şifreleme farkı

Blok şifrelemede, ister 64 bitlik ister 128 bitlik blok kullanılsın, ister DES, 3DES ya da AES olsun, her seferinde belli bir blok gelir ve bu blok anahtarla ya da anahtar üretecinden gelen alt anahtarlarla şifrelenir. Akış şifrelemede ise veri akar ve bayt bayt şifrelenir.

Hoca buradaki kritik noktayı şöyle belirtti: veride tekrarlar varsa ve aynı anahtar kullanılıyorsa, kriptoanalistin elindeki düz metin–şifreli metin çiftlerinin sayısı artar ve anahtarı elde etmek mümkün hâle gelir.

### 9.2 Akış şifreleyicinin yapısı

Slayttaki özet (ekrandan, 00:50:00):

- Akış şifreleyici girdi öğelerini sürekli olarak işler.
- Anahtar, rastgele bir bit üretecine giriştir.
  - Üreteç rastgele benzeri sayılardan oluşan bir akış üretir.
  - Bu akış, giriş anahtarı bilinmeden öngörülemez.
  - Çıktı, düz metin baytlarıyla anahtar akışının XOR'udur.

Yani her bayt alınır, anahtardan sözde rastgele üreteçle alt anahtarlar (anahtar akışı) üretilir ve bunlarla hızlı bir XOR işlemi yapılarak şifreli bayt elde edilir. Blok şifreleme ile karşılaştırıldığında yapı benzerdir: blok şifrelemede belli bir blok anahtarla ya da türetilmiş anahtarla şifrelenir; akış şifrelemede gelen $b$ bitlik veri, anahtardan sözde rastgele üreteçle elde edilen anahtar akışıyla XOR'lanır.

### 9.3 Performans karşılaştırması

Hoca, AES'in elektronik kod kitabı (ECB) moduyla şifreleme ve şifre çözme hızlarını, anahtar boyutuna bağlı olarak akış şifreleme ile karşılaştıran bir tablo gösterdi. Söylediğine göre 3 GHz işlemcili bir makinede akış şifreleme daha yüksek bir hıza çıkar ve blok şifrelemeden akış şifrelemeye geçildiğinde yaklaşık %30'a yakın bir performans artışı olur.

<!-- BELİRSİZ: Hız karşılaştırma tablosu (yaklaşık 00:51:26–00:52:34) karelerde yok. Altyazıda "12 Mbps" ve "yaklaşık %30" geçiyor, ama tablo değerleri ve birimleri (Mbps / MBps) doğrulanamadı. -->

### 9.4 RC4

RC4'ün akış diyagramında iki parça vardır: bir anahtar planlama (key scheduling) algoritması ve bir sözde rastgele üretim (pseudo-random generation) algoritması. Durum dizisi 0'dan 255'e kadar indekslenir. Anahtar kullanılarak bu dizi karıştırılır, ardından yerine koyma ve yer değiştirmelerle anahtar akışı (stream) elde edilir.

> **Ders sonrası not:** Hoca durum dizisinin "255 bite kadar" gittiğini söyledi. Büyük olasılıkla doğrusu, RC4 durum dizisinin 0–255 indeksli 256 bayttan oluşmasıdır.

> **Ek bilgi (derste anlatılmadı):** RC4'te anahtar planlama aşamasında $S$ dizisi $0, 1, \dots, 255$ ile doldurulur ve anahtara bağlı yer değiştirmelerle karıştırılır. Üretim aşamasında her adımda dizinin iki elemanı yer değiştirir ve dizideki bir eleman anahtar akışının bir baytı olarak çıkar; bu bayt düz metin baytıyla XOR'lanır.

## 10. Blok şifreleme çalışma modları

### 10.1 Modlar tablosu

Blok şifrelemede beş çalışma modu vardır (ekrandan, 00:55:00):

| Mod | Tanım | Tipik uygulama |
|---|---|---|
| Elektronik Kod Kitabı (ECB) | 64 düz metin bitlik her blok, aynı anahtar kullanılarak bağımsız olarak kodlanır. | Tek değerlerin güvenli iletimi (ör. bir şifreleme anahtarı) |
| Şifreleme Blok Zincirleme (CBC) | Şifreleme algoritmasının girdisi, sonraki 64 bit düz metnin ve önceki 64 bit şifreli metnin XOR'udur. | Genel amaçlı blok yönelimli iletim; kimlik doğrulama |
| Şifreleme Geribildirimi (CFB) | Giriş bir seferde $s$ bit olarak işlenir. Önceki şifreli metin, sonraki şifreli metin birimini üretmek için düz metinle XOR'lanan sözde rastgele çıktıyı üretmek üzere şifreleme algoritmasına girdi olarak kullanılır. | Genel amaçlı akış odaklı iletim; kimlik doğrulama |
| Çıkış Geribildirimi (OFB) | CFB'ye benzer; tek farkı şifreleme algoritmasına girişin önceki DES çıkışı olmasıdır. | Gürültülü kanal üzerinden akış yönelimli iletim (ör. uydu iletişimi) |
| Sayaç (CTR) | Her düz metin bloğu şifreli bir sayaçla XOR'lanır. Sayaç sonraki her blok için artırılır. | Genel amaçlı blok yönelimli iletim; yüksek hız gereksinimleri |

### 10.2 Elektronik Kod Kitabı (ECB)

En basit moddur. Mesaj bloklara bölünür ve her blok aynı anahtarla, diğerlerinden bağımsız olarak şifrelenir. Metinde tekrar eden bloklar varsa, aynı düz metin–şifreli metin çifti tekrar tekrar ortaya çıkar: tekrar eden düz metin, şifreli metinde de tekrar eden blok olarak görülür. Bu yüzden ECB uzun mesajlar için güvenli değildir ve tipik olarak tek bir değerin, örneğin bir şifreleme anahtarının güvenli iletiminde kullanılır.

Bu güvenlik eksikliğini aşmak için, aynı düz metin bloğu tekrar ettiğinde farklı şifreli metin üreten modlar gerekir: CBC, CFB, OFB ve CTR.

### 10.3 Şifreleme Blok Zincirleme (CBC)

CBC'nin amacı, metin tekrar ettiğinde aynı şifreli metnin elde edilmesini önlemektir. Şifreleme algoritmasının girdisi, sıradaki düz metin bloğu ile önceki şifreli bloğun XOR'udur; sonuç aynı anahtarla şifrelenir:

$$C_1 = E(K, P_1 \oplus IV), \qquad C_i = E(K, P_i \oplus C_{i-1})$$

İlk blok için önceki bir şifreli blok olmadığından bir başlangıç değeri kullanılır. Hoca bunu, bir önceki metin parçasının son bloğunun şifreli hâlinin girdi olarak alınması diye anlattı. $C_1$, ikinci düz metin bloğu $P_2$ ile XOR'lanıp şifrelenerek $C_2$ elde edilir ve zincir böyle sürer.

> **Hocanın vurgusu:** $P_1$ ile $P_2$ aynı olsa bile, XOR'a giren önceki değer farklı olduğu için $C_1$, $C_2$, …, $C_n$ birbirinden farklı olur.

### 10.4 Şifreleme Geribildirimi (CFB)

CFB'de bir kaydırma yazmacı (shift register) vardır. Slayttaki şekil "$s$-bit Cipher Feedback (CFB) Mode" başlığını taşır (ekrandan, 01:00:00):

```text
Şifreleme:
  Başlangıçta kaydırma yazmacı = IV (64 bit)
  1. Yazmaç K ile şifrelenir (Encrypt) -> 64 bit çıktı
  2. Çıktının s biti seçilir, kalan b - s bit atılır
  3. Seçilen s bit, P1'in s bitiyle XOR'lanır -> C1
  4. C1 yazmaca geri beslenir: yazmaç s bit sola kayar,
     C1 sağdaki s bitlik alana girer
  5. Aynı adımlar P2, ..., PM için tekrar edilir -> C2, ..., CM
Şifre çözme:
  Aynı yazmaç ve yine "Encrypt" bloğu kullanılır;
  seçilen s bit Ci ile XOR'lanır -> Pi,
  yazmaca geri beslenen değer yine Ci'dir
```

Hoca, şifre çözmenin bu işlemin tersi olduğunu söyledi. Şekilde görüldüğü gibi şifre çözme tarafında da şifreleme fonksiyonu kullanılır; değişen, XOR'a şifreli metnin girmesi ve düz metnin çıkmasıdır.

### 10.5 Çıkış Geribildirimi (OFB)

OFB, CFB'ye benzer. Tek farkı, şifreleme algoritmasına geri beslenen değerin önceki şifreli metin değil, şifreleme algoritmasının önceki çıkışı olmasıdır. Tipik uygulaması gürültülü kanallardan, örneğin uydu bağlantısı üzerinden akış yönelimli iletimdir. Derste OFB'nin blok diyagramı ayrıca anlatılmamıştır.

### 10.6 Sayaç (CTR)

CTR'de sayaç $K$ anahtarıyla şifrelenir, sonra $P_1$ bloğuyla XOR'lanır ve şifreli çıkış $C_1$ elde edilir. Yani şifreli çıkış, sayacın $K$ anahtarıyla şifrelenmiş hâlinin $P_1$ ile XOR'udur. Sonra sayaç bir artırılır, yine $K$ ile şifrelenir ve $P_2$ ile XOR'lanarak $C_2$ elde edilir. Bu, sayaç $n-1$ kez artırılana kadar sürer:

$$C_i = P_i \oplus E(K, \text{sayaç} + i - 1)$$

Gönderici ve alıcı sayacı her blok için senkron olarak artırır. Alıcı anahtarı da biliyorsa şifreyi kolayca çözer.

> **Hocanın vurgusu:** $P_1, P_2, \dots, P_n$ bloklarından herhangi ikisi birebir aynı olsa bile, sayaç farklı olduğu için XOR sonucu farklı olur. Böylece aynı veriden farklı şifreli metinler elde edilir ve kriptoanalistin işi zorlaşır.

> **Ders sonrası not:** Hoca anlatımın bir yerinde "her seferinde K anahtarı artıyor" dedi. Artırılan anahtar değil sayaçtır; $K$ anahtarı bütün bloklarda aynıdır.

## 11. Simetrik anahtar dağıtımı

### 11.1 Dört dağıtım seçeneği

Simetrik şifrelemenin iki ana öğesi algoritma ve anahtardır. Anahtar yalnız alıcı ve verici tarafından bilinmeli, başka hiç kimse tarafından bilinmemelidir. Bu durumda anahtarın nasıl dağıtılacağı sorusu doğar. Hoca dört yol anlattı:

- **Fiziksel teslim:** $A$ anahtarı seçer ve $B$'ye fiziksel olarak, örneğin bir kuryeyle teslim eder.
- **Üçüncü tarafın fiziksel teslimi:** $A$ ile $B$'nin ikisinin de güvendiği üçüncü bir anahtar sağlayıcı anahtarı belirler ve $A$ ile $B$'ye elden teslim eder.
- **Eski anahtarla yeni anahtar:** $A$ ile $B$ daha önce güvenli biçimde bir anahtar teslim almışsa ve bu anahtarı yalnız kendilerinin bildiğini düşünüyorsa, yeni anahtarı eski anahtarla şifreleyerek değiş tokuş edebilir. Böylece anahtar belli aralıklarla güncellenir.
- **Anahtar dağıtım otoritesi:** $A$ ve $B$'nin her biriyle şifreli bir kanalı olan bir $C$ otoritesi varsa, $C$ iki taraf arasında kullanılacak anahtarı bu şifreli kanallar üzerinden dağıtır. Anahtar ulaştıktan sonra $A$ ile $B$ doğrudan iletişim kurar.

Üçüncü yöntemde kritik nokta, eski anahtarın saldırgan tarafından ele geçirilmemiş olmasıdır. Eski anahtar ele geçirilmişse yeni anahtar da doğal olarak ele geçer. Bu yüzden anahtar değişim aralığı, saldırganın anahtarı ele geçirmesi için gereken süreden kısa olmalıdır. Ama aralık çok kısa da olmamalıdır; gereksiz yere anahtar değiştirmek gereksiz trafik oluşturur.

### 11.2 Anahtar dağıtım merkezi ile otomatik dağıtım

Slayttaki şekil "Automatic Key Distribution for Connection-Oriented Protocol" başlığını taşır (ekrandan, 01:05:00). Şekilde iki makine (HOST), her birinde bir uygulama (Application) ve bir güvenlik servisi (Security service), aralarında bir ağ (Network) ve ağa bağlı bir anahtar dağıtım merkezi (Key distribution center, KDC) vardır. Adımlar:

- 1. Makine bağlantı isteyen paketi gönderir.
- 2. Güvenlik servisi paketi tamponlar ve KDC'den oturum anahtarı ister.
- 3. KDC oturum anahtarını iki makineye de dağıtır.
- 4. Tamponlanan paket iletilir.

Hoca örnek olarak bir e-postanın güvenli gönderilmesini düşündü. Uygulamanın altında, ara katmanda bir güvenlik servisi vardır; bu servis taşıma katmanının üzerinde, uygulama katmanının altında yer alır ve iletimi güvenli hâle getirir. Hoca bunun gerekçesini, TCP ve IP'nin kendi başına güvenlik sağlamaması olarak açıkladı. Uygulama güvenlik servisinden güvenli iletişim talep ettiğinde, servisin $B$ ile ortak bir anahtarı yoksa ikinci adımda $A$ ile $C$ arasındaki şifreli kanal üzerinden $C$'ye başvurur: "$B$ ile iletişim kurmak istiyorum, bana anahtar ver." $C$, $A$ ile $B$'nin kullanacağı anahtarı şifreli kanallar üzerinden hem $A$'ya hem $B$'ye gönderir. Artık anahtar yalnız $A$ ve $B$ tarafından bilinir; dördüncü adımda güvenlik servisi bağlantıyı kurar ve uygulamalar güvenli biçimde veri alışverişine başlar.

> **Ek bilgi (derste anlatılmadı):** IP katmanında güvenlik daha sonra IPsec ile eklenmiştir; IPv6'da IPsec desteği başlangıçta zorunlu tutulmuş, sonradan önerilen duruma getirilmiştir. Derste geçen "IP'nin güvenlik barındırmaması" ifadesi, büyük olasılıkla temel IP protokolünün kendisinin şifreleme sunmamasına işaret eder.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:42): AES'te blok 128 bittir, ama günümüz uygulamalarında mesaj boyutu bundan çok büyüktür. Büyük mesajlar nasıl şifrelenir?

> **Cevap (derste verildi):** Akış şifreleme yöntemlerinden biri (örneğin RC4) ya da blok şifrelemenin çalışma modlarından biri (CBC, CFB, OFB, CTR) kullanılır. Mesajın türü biliniyorsa tekrar eden kısımlar kriptoanalize açık olduğundan, aynı düz metin bloğunun aynı şifreli bloğu üretmemesi gerekir.

**Soru 2** (derste sözlü, 00:29:46): Bir kriptoanalist için en zor durum hangisidir; elinde ne vardır, ne yapabilir?

> **Cevap (derste verildi):** Yalnızca şifreli metin saldırısıdır. Elinde yalnız şifreleme algoritması (örneğin AES ya da DES olduğu) ve çözülecek şifreli metin vardır. Farklı anahtarlar deneyerek şifreli metinden anlamlı bir düz metin çıkarmaya çalışır; düz metnin neye benzediğini bilmediği için bu en zor durumdur.

**Soru 3** (derste sözlü, 00:33:04): Bir şifrelemenin güvenli olduğuna nasıl karar verilir?

> **Cevap (derste verildi):** "Kırılmıyorsa güvenlidir" denemez; masrafı yapılırsa her şifre kırılır. Şifreleme, kırmanın maliyeti bilginin değerini aşıyorsa ya da kırmak için gereken süre bilginin faydalı ömrünü aşıyorsa hesaplama açısından güvenlidir (ekrandan, 00:35:00).

**Soru 4** (derste sözlü, 00:48:14): AES S-box'ta $00$ baytının yerine $63$, $9B$ baytının yerine $14$ geldiği gösterildi. Bunun doğru olduğu ters S-box ile nasıl kontrol edilir?

> **Cevap (derste verildi):** Ters S-box'ta satır $6$, sütun $3$'e bakılır ve $00$ bulunur; satır $1$, sütun $4$'e bakılır ve $9B$ bulunur. Python ile hesaplanan AES S-box'ı bu değerleri doğrular: $S(00)=63$, $S^{-1}(63)=00$, $S(9B)=14$, $S^{-1}(14)=9B$.

**Soru 5** (derste sözlü, 01:02:16): Simetrik şifrelemede anahtar yalnız alıcı ve verici tarafından bilinmeli. Anahtar nasıl dağıtılır?

> **Cevap (derste verildi):** Dört yol vardır: $A$ anahtarı fiziksel olarak $B$'ye teslim eder; güvenilir üçüncü taraf anahtarı ikisine fiziksel olarak teslim eder; daha önce paylaşılmış bir anahtarla yeni anahtar şifrelenerek gönderilir; $A$ ve $B$ ile şifreli kanalı olan bir anahtar dağıtım merkezi anahtarı bu kanallardan dağıtır.

## Dersin Toparlaması

Bu derste simetrik şifreleme, mesaj gizliliği açısından ayrıntılı olarak işlendi. Önce simetrik şifrelemenin beş bileşeni ve kriptografik yöntemlerin üç boyutlu sınıflandırması hatırlatıldı. Ardından kriptoanalistin elindeki bilgiye göre saldırı türleri en zordan en kolaya sıralandı ve bir şifrelemenin hesaplama açısından güvenli sayılması için gereken iki ölçüt (maliyet ve süre) verildi. Blok şifreleme tarafında Feistel yapısı, DES'in 56 bitlik anahtar sorunu, bu soruna çözüm olarak 3DES'in E–D–E yapısı ve yazılımda verimli, Feistel kullanmayan AES anlatıldı; AES'in S-box tablosu örnek baytlarla kontrol edildi.

Büyük mesajlarda tekrar eden kalıpların kriptoanalize kapı açtığı vurgulanarak akış şifreleyiciler (RC4) ve blok şifreleme çalışma modları (ECB, CBC, CFB, OFB, CTR) işlendi; ECB dışındaki modların aynı düz metinden farklı şifreli metin üretme amacı öne çıkarıldı. Son olarak simetrik anahtarın dağıtımı ve anahtar dağıtım merkeziyle otomatik dağıtım ele alındı. Bir sonraki derste açık anahtarlı şifreleme ve ileti kimlik doğrulaması işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
