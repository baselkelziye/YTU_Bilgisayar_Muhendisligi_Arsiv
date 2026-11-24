# Ders 13 Çalışma Özeti

## Genel Konular

- Dersin yeri ve kapsamı (ekrandan, 00:20:00)
  - "Şifreleme Algoritmaları" bölümünün üç alt başlığı vardır: 3.1 Şifreleme Araçları (önceki derste genel giriş olarak işlendi), 3.2 Simetrik Şifreleme ve Mesaj Gizliliği (bu dersin konusu), 3.3 Açık Anahtarlı Şifreleme ve İleti Kimlik Doğrulaması (sonraki dersin konusu).
  - Simetrik şifrelemede odak mesaj gizliliğidir; açık anahtarlı şifrelemede odak kimlik doğrulama olacaktır.
  - Bu derste blok şifrelemenin ayrıntısı (Feistel yapısı, DES, 3DES, AES), akış şifreleme (RC4), blok şifreleme çalışma modları ve simetrik anahtar dağıtımı işlenmiştir.
- Simetrik (geleneksel) şifreleme
  - Literatürde geleneksel şifreleme, gizli anahtarlı şifreleme ya da tek anahtarlı şifreleme diye anılır.
  - 1970'lerin sonunda açık anahtarlı şifreleme ortaya çıkana kadar tek alternatifti; antik çağlardan beri kullanılır ve hâlâ yaygındır.
  - Güvenliği, anahtarı yalnız gönderici ile alıcının bilmesi varsayımına dayanır.
  - Beş bileşeni vardır: düz metin, şifreleme algoritması, gizli anahtar, şifreli metin, şifre çözme algoritması.
  - Şifreli metin hem algoritmanın hem de gizli anahtarın fonksiyonudur. Algoritmada zayıflık yoksa anahtarı bilmeyen biri yalnız algoritmadan yola çıkarak düz metni bulamaz.
- Kriptografik yöntemlerin sınıflandırılması: üç bağımsız boyut (ekrandan, 00:25:00)
  - Düz metni şifreli metne dönüştürmek için kullanılan işlemlerin türü:
    - Değiştirme (substitution): düz metindeki her öğe başka bir öğeye eşlenir.
    - Yer değiştirme (transposition): öğelerin kendisi değişmez, düz metindeki öğeler yeniden düzenlenir.
  - Kullanılan anahtar sayısı:
    - Gönderici ve alıcı aynı anahtarı kullanır: simetrik.
    - Gönderici ve alıcının her biri farklı bir anahtar kullanır: asimetrik.
  - Düz metnin işlenme şekli:
    - Blok şifreleyici: her seferinde bir öğe bloğunu işler.
    - Akış şifreleyici: giriş öğelerini sürekli olarak işler.
- Şifrelenmiş mesajlara yönelik saldırı türleri (ekrandan, 00:30:00)
  - Şifreyi kırmanın iki yolu vardır: kriptoanaliz ve kaba kuvvet saldırısı. Bu tablo kriptoanalitik saldırıları, kriptoanalistin elindeki bilgiye göre en zordan en kolaya sıralar.
  - Yalnızca şifreli metin: şifreleme algoritması ve çözülecek şifreli metin bilinir.
  - Bilinen düz metin: ek olarak gizli anahtarla oluşturulmuş bir veya daha fazla düz metin–şifreli metin çifti bilinir.
  - Seçilmiş düz metin: kriptoanalistin seçtiği düz metin ve gizli anahtarla oluşturulmuş karşılığı olan şifreli metin bilinir.
  - Seçilmiş şifreli metin: kriptoanalistin seçtiği sözde şifreli metin ve gizli anahtarla çözülmüş karşılığı olan düz metin bilinir.
  - Seçilmiş metin: seçilmiş düz metin ve seçilmiş şifreli metin bilgilerinin ikisi birden bilinir.
- Hesaplama olarak güvenli şifreleme şemaları (ekrandan, 00:35:00)
  - Şifre kırmanın maliyeti bilginin değerini aşıyorsa şifreleme hesaplama açısından güvenlidir.
  - Şifreyi kırmak için gereken süre bilginin faydalı ömrünü aşıyorsa şifreleme hesaplama açısından güvenlidir.
  - Kırmak için gereken çabayı tahmin etmek genellikle çok zordur; kaba kuvvet saldırısının süresi ve maliyeti ise tahmin edilebilir (ortalama olarak olası anahtarların yarısı denenir).
- Feistel şifre yapısı (ekrandan, 00:40:00)
  - DES dahil birçok simetrik blok şifreleme algoritması, ilk olarak 1973'te IBM'den Horst Feistel'in açıkladığı yapıyı kullanır.
  - Girdi: $2w$ bit uzunluğunda bir düz metin bloğu ve bir $K$ anahtarı. Blok iki yarıya ($L_0$, $R_0$) ayrılır.
  - Her turda sağ yarı tur fonksiyonu $F$'den alt anahtar $K_i$ ile geçirilir, sonuç sol yarıyla XOR'lanır, sonra yarılar yer değiştirir.
  - Veri $n$ turdan geçtikten sonra iki yarı birleşerek $2w$ bitlik şifreli metin bloğunu oluşturur.
  - Alt anahtarlar $K_i$, $K$'den bir alt anahtar oluşturma algoritmasıyla üretilir ve genellikle birbirinden farklıdır.
- Blok şifreleyici tasarım öğeleri
  - Tekrarlanan turlar; anahtarın kontrol ettiği yerine koyma (substitution) ve permütasyon işlemleri.
  - Blok boyutu (genellikle 128 bit), anahtar boyutu (genellikle 128 bit), tur sayısı (tipik olarak 16 civarı), alt anahtar üretim algoritması, tur fonksiyonu.
  - Hızlı yazılım şifreleme/şifre çözme ve kolay analiz edilebilirlik.
- DES (Data Encryption Standard)
  - 1977'de NBS (bugünkü NIST) tarafından FIPS PUB 46 olarak yayımlandı; algoritmanın adı DEA'dır.
  - 64 bitlik düz metin bloğunu 56 bitlik anahtarla şifreleyip 64 bitlik şifreli metin üretir; Feistel ağının bir varyasyonunu kullanır.
  - Uzun süre incelenmiş, ölümcül bir algoritma zayıflığı bulunmamıştır; asıl sorun 56 bitlik anahtar boyutudur ($2^{56}$ olası anahtar).
  - Saniyede $10^{13}$ deneme yapabilen dağıtık bir sistemde kaba kuvvetle yaklaşık bir saatte kırılabilir.
- Üçlü DES (3DES)
  - DES üç kez, farklı anahtarlarla art arda uygulanır: $C = E(K_3, D(K_2, E(K_1, P)))$.
  - Toplam anahtar uzunluğu $3 \times 56 = 168$ bit olur; kaba kuvvet süresi yeniden çok uzun sürelere çıkar.
  - Şifre çözme ters sırayla yapılır: $P = D(K_1, E(K_2, D(K_3, C)))$.
  - Yazılımda yavaştır; 1970'lerin donanım odaklı algoritmasıdır.
- AES (Advanced Encryption Standard) (ekrandan, 00:45:00)
  - 3DES uzun süreli kullanım için makul değildi; NIST 1997'de yeni bir AES için teklif çağrısında bulundu.
  - Gereksinimler: 3DES'e eşit veya daha iyi güvenlik, önemli ölçüde geliştirilmiş verimlilik, simetrik blok şifreleme, 128 bit veri ve 128/192/256 bit anahtarlar.
  - İlk turda önerilen 15 algoritma kabul edildi, ikinci turda alan 5 algoritmaya daraltıldı; Rijndael seçildi ve FIPS 197 olarak yayımlandı.
  - Feistel yapısını kullanmaz. 128 bitlik blok $4 \times 4$ baytlık bir kare matrise dönüştürülür; 128 bitlik anahtar da kare matrise dönüştürülür ve bundan her biri 4 bayt olan 44 kelimelik genişletilmiş anahtar üretilir.
  - 128 bitlik anahtar için 10 tur; aşamalar: bayt yerine koyma (S-box), satırları kaydırma, sütunları karıştırma, tur anahtarı ekleme (XOR).
- Akış şifreleyiciler (ekrandan, 00:50:00)
  - Girdi öğelerini sürekli olarak işler; anahtar rastgele bir bit üretecine giriştir.
  - Üreteç rastgele benzeri sayılardan oluşan bir anahtar akışı üretir; bu akış giriş anahtarı bilinmeden öngörülemez.
  - Şifreli çıktı, düz metin baytlarıyla anahtar akışının XOR'udur.
  - Örnek algoritma: RC4 (anahtar planlama algoritması ve sözde rastgele üretim algoritması).
- Blok şifreleme çalışma modları (ekrandan, 00:55:00)
  - ECB, CBC, CFB, OFB ve CTR; her birinin tanımı ve tipik uygulama alanı.
  - ECB dışındaki modların ortak amacı, aynı düz metin bloğu tekrar ettiğinde farklı şifreli metin üretmektir.
- Simetrik anahtar dağıtımı (ekrandan, 01:05:00)
  - Dört seçenek: fiziksel teslim, üçüncü tarafın fiziksel teslimi, eski anahtarla yeni anahtarın gönderilmesi, anahtar dağıtım merkezi (KDC) üzerinden şifreli kanallarla dağıtım.
  - Bağlantı yönelimli protokol için otomatik anahtar dağıtımı dört adımda işler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Büyük mesajlarda tekrar eden kısımlar tehlikelidir
  - Mesajın türü (PDF, HTML vb.) biliniyorsa, belgenin tekrar eden kalıpları da bilinir; bu kalıplar kriptoanalitik yöntemlerle anahtarı bulmayı kolaylaştırır. Akış şifreleme ve blok şifreleme modlarının önemi buradan gelir.
- Kırılmaz şifre yoktur
  - "Kırılmazsa güvenlidir" düşüncesi yanlıştır; masrafı yapılırsa her şifre kırılır. Güvenlik iki ölçütle değerlendirilir: kırma maliyeti bilginin değerini, kırma süresi bilginin faydalı ömrünü aşmalıdır.
- DES'in zayıflığı algoritma değil anahtar boyutudur
  - Algoritma güçlü kabul edildiği için çözüm aynı algoritmayı üç kez farklı anahtarlarla uygulamak (3DES) olmuştur. Finansal veride bilginin değeri yüksek olduğundan saldırgan büyük yatırım yapmayı göze alabilir.
- Kolay analiz edilebilirlik zayıflık değildir
  - Algoritmanın nasıl çalıştığının bilinmesi, anahtar bilinmeden sonuçtan anahtarı çıkarmayı mümkün kılmaz. Ne kadar çok kişi analiz ederse hatalar o kadar erken bulunup düzeltilir.
- Aynı düz metin, farklı şifreli metin
  - CBC, CFB ve CTR gibi modlarda $P_1$ ile $P_2$ birebir aynı olsa bile şifreli blokları farklı olur; bu, kriptoanalistin işini zorlaştırır.
- Anahtar değişim aralığı
  - Eski anahtarla yeni anahtar gönderiliyorsa, eski anahtar ele geçirilmişse yeni anahtar da ele geçer. Değişim aralığı saldırganın anahtarı kırma süresinden kısa, ama gereksiz trafik yaratmayacak kadar uzun olmalıdır.

## Kısa Tekrar Notları

- Simetrik şifreleme = tek anahtar, beş bileşen (düz metin, şifreleme algoritması, gizli anahtar, şifreli metin, şifre çözme algoritması).
- Sınıflandırma: işlem türü (substitution / transposition), anahtar sayısı (simetrik / asimetrik), işleme şekli (blok / akış).
- Saldırı türleri en zordan en kolaya: yalnızca şifreli metin → bilinen düz metin → seçilmiş düz metin → seçilmiş şifreli metin → seçilmiş metin.
- Hesaplama açısından güvenli: maliyet > bilginin değeri veya süre > bilginin faydalı ömrü.
- Feistel: $2w$ bit blok, iki yarı, $n$ tur, $F$ fonksiyonu ve alt anahtarlar $K_i$, XOR ve yarıların yer değiştirmesi.
- DES: 64 bit blok, 56 bit anahtar, FIPS PUB 46 (1977); kaba kuvvete karşı yetersiz.
- 3DES: E–D–E, üç anahtar, 168 bit.
- AES (Rijndael, FIPS 197): 128 bit blok, 128/192/256 bit anahtar, Feistel değil; 128 bit anahtarda 10 tur ve 44 kelimelik (4'er bayt) genişletilmiş anahtar.
- AES S-box örnekleri: $S(00)=63$, $S(66)=33$, $S(04)=F2$; ters S-box'ta $63 \to 00$, $14 \to 9B$.
- Akış şifreleme: anahtar → sözde rastgele üreteç → anahtar akışı ⊕ düz metin baytları. Örnek: RC4.
- Modlar: ECB (bağımsız bloklar), CBC (önceki şifreli blokla XOR), CFB ($s$ bitlik geri besleme, kaydırma yazmacı), OFB (CFB benzeri, geri besleme şifreleme çıktısından), CTR (şifrelenmiş sayaç ⊕ düz metin).
- Anahtar dağıtımı: fiziksel teslim, üçüncü taraf, eski anahtarla şifreli gönderim, KDC.

## Detaylı Açıklamalar

### Simetrik şifrelemenin bileşenleri

Simetrik şifrelemede gönderici, gizliliği korunacak düz metni bir şifreleme algoritmasına verir; algoritmaya ikinci girdi olarak gizli anahtar girer ve sonuçta şifreli metin elde edilir. Şifreli metin alıcıya ulaştığında alıcı aynı gizli anahtarı ve şifre çözme algoritmasını kullanarak düz metni geri elde eder. Bu yüzden simetrik şifreleme beş bileşenle anlatılır. Güvenlik, anahtarın yalnız iki tarafça bilinmesine dayanır; algoritma gizli değildir.

### Kriptoanalistin karşılaştığı zorluk

Kaba kuvvet saldırısında istatistik olarak olası anahtarların ortalama yarısını denemek gerekir. Kriptoanalitik saldırıda ise saldırganın işi elindeki bilgiye bağlıdır. Yalnız şifreli metin ve algoritma biliniyorsa, saldırgan farklı anahtarlarla anlamlı bir düz metin çıkarmaya çalışır; bu en zor durumdur. Düz metin–şifreli metin çiftleri biliniyorsa saldırgan sonucun neye benzeyeceğini bilir. Saldırgan kendi hazırladığı bir düz metni (örneğin içeriden birine verip şifrelettirerek) şifreli hâliyle elde edebiliyorsa, anahtarı ortaya çıkarmaya uygun bir metin seçebilir. Elde edilen çiftlerin sayısı arttıkça kırma ihtimali artar. Tasarımcılar algoritmayı bu zorluk sıralamasını düşünerek güçlendirir.

### Feistel ağı

$2w$ bitlik blok (örneğin DES'te 64 bit) $w$ bitlik iki yarıya ayrılır. Her turda sağ yarı $F$ fonksiyonuna o turun alt anahtarı $K_i$ ile girer; $F$'nin çıkışı sol yarıyla XOR'lanır. Bu sonuç bir sonraki turun sağ yarısı, önceki turun sağ yarısı ise bir sonraki turun sol yarısı olur. İşlem $n$ tur tekrar edilir; son turdan sonra yarılar birleştirilerek $2w$ bitlik şifreli metin elde edilir (ekrandan, 00:40:00).

### DES ve 3DES

DES 64 bitlik bloğu 56 bitlik anahtarla şifreler. Algoritmanın kendisinde ciddi bir zayıflık bulunmamıştır, ama $2^{56}$ anahtar uzayı bugün küçüktür: saniyede $10^{13}$ deneme yapan bir sistem anahtar uzayının yarısını ($2^{55}$) yaklaşık bir saatte tarar. 3DES'te düz metin önce $K_1$ ile DES şifrelemesinden geçer ($A$), sonra $A$, $K_2$ ile DES şifre çözme algoritmasından geçer ($B$), en sonda $B$, $K_3$ ile tekrar şifrelenir ($C$). Şifre çözmede $C$, $K_3$ ile çözülür ($B$), $B$, $K_2$ ile şifrelenir ($A$), $A$, $K_1$ ile çözülür ve düz metin elde edilir.

> **Ders sonrası not:** Hoca, kaba kuvvet süresi için "1 GHz'lik bir makinede birkaç bin yıl" dedi. Saniyede $10^9$ denemede $2^{55}$ deneme yaklaşık 1,1 yıl sürer; "binlerce yıl" rakamı büyük olasılıkla mikrosaniyede bir deneme (saniyede $10^6$) varsayımından gelir (python ile hesaplandı).

> **Ders sonrası not:** Hoca 3DES için FIPS PUB 46-3'ü 1985'e, X9.17'yi 1999'a bağladı. Büyük olasılıkla doğrusu tersidir: 3DES ilk kez 1985'te ANSI X9.17 standardıyla finansal uygulamalar için, 1999'da ise FIPS PUB 46-3 ile standartlaştırılmıştır.

### AES'in yapısı ve S-box

AES'te 128 bitlik blok $4 \times 4$ baytlık bir duruma (state) dönüştürülür. 128 bitlik anahtar da kare matrise yerleştirilir ve her biri 4 bayt olan 44 kelimelik genişletilmiş anahtar üretilir. Her turda bayt yerine koyma, satırları kaydırma, sütunları karıştırma (sonlu alan aritmetiğiyle) ve tur anahtarıyla XOR işlemleri yapılır. Bayt yerine koymada her baytın onaltılık iki hanesi S-box tablosunda satır ve sütun indeksi olarak kullanılır. Hocanın verdiği örneklerde $00 \to 63$, $66 \to 33$, $04 \to F2$ olur; ters S-box ile kontrol edildiğinde $63 \to 00$ ve $14 \to 9B$ çıkar (python ile doğrulandı). Şifre çözmede bu işlemlerin tersleri uygulanır.

> **Ders sonrası not:** Hoca bir yerde AES'in "4 bitlik kelimelerinden 44 tane" olduğunu söyledi; doğrusu her kelimenin 4 bayt (32 bit) olmasıdır. 4 bit, S-box'ta satır ya da sütunu seçen tek onaltılık hanedir.

### Akış şifreleme ve RC4

Blok şifrelemede her seferinde sabit bir blok, anahtar ya da anahtardan türetilen alt anahtarlarla şifrelenir. Akış şifrelemede ise veri akarken bayt bayt şifrelenir: anahtar sözde rastgele bir üretece girer, üretilen anahtar akışı düz metin baytıyla XOR'lanır. Veride tekrar olur ve aynı anahtar akışı kullanılırsa, kriptoanalistin elindeki düz metin–şifreli metin çiftlerinin sayısı artar. RC4'te bir anahtar planlama algoritması ve bir sözde rastgele üretim algoritması vardır; 0'dan 255'e kadar indekslenen bir durum dizisi anahtarla karıştırılıp yer değiştirmelerle anahtar akışı üretilir.

> **Ders sonrası not:** Hoca RC4 durum dizisi için "255 bit" dedi; büyük olasılıkla doğrusu 0–255 indeksli 256 baytlık dizidir.

<!-- BELİRSİZ: Hocanın blok şifreleme ile akış şifrelemenin hızını karşılaştırdığı tablo (yaklaşık 00:51:26–00:52:34; "3 GHz işlemci", "12 Mbps", "yaklaşık %30 performans artışı") karelerde yok; sayılar altyazıdan doğrulanamadı. -->

### Blok şifreleme çalışma modları (ekrandan, 00:55:00)

| Mod | Tanım | Tipik uygulama |
|---|---|---|
| Elektronik Kod Kitabı (ECB) | 64 düz metin bitlik her blok, aynı anahtar kullanılarak bağımsız olarak kodlanır. | Tek değerlerin güvenli iletimi (ör. bir şifreleme anahtarı) |
| Şifreleme Blok Zincirleme (CBC) | Şifreleme algoritmasının girdisi, sonraki 64 bit düz metnin ve önceki 64 bit şifreli metnin XOR'udur. | Genel amaçlı blok yönelimli iletim; kimlik doğrulama |
| Şifreleme Geribildirimi (CFB) | Giriş bir seferde $s$ bit olarak işlenir. Önceki şifreli metin, sonraki şifreli metin birimini üretmek için düz metinle XOR'lanan sözde rastgele çıktıyı üretmek üzere şifreleme algoritmasına girdi olarak kullanılır. | Genel amaçlı akış odaklı iletim; kimlik doğrulama |
| Çıkış Geribildirimi (OFB) | CFB'ye benzer; tek farkı şifreleme algoritmasına girişin önceki DES çıkışı olmasıdır. | Gürültülü kanal üzerinden akış yönelimli iletim (ör. uydu iletişimi) |
| Sayaç (CTR) | Her düz metin bloğu şifreli bir sayaçla XOR'lanır. Sayaç sonraki her blok için artırılır. | Genel amaçlı blok yönelimli iletim; yüksek hız gereksinimleri |

- ECB'de tekrar eden düz metin blokları tekrar eden şifreli bloklar üretir; bu yüzden uzun mesajlar için güvenli değildir.
- CBC'de $C_1 = E(K, P_1 \oplus IV)$, $C_i = E(K, P_i \oplus C_{i-1})$. Başlangıç değeri farklı olduğundan $P_1 = P_2$ olsa bile $C_1 \ne C_2$ olur.
- CFB'de 64 bitlik kaydırma yazmacı (başta IV) şifrelenir, çıktının en soldaki $s$ biti seçilir (kalan $b-s$ bit atılır), $P_1$'in $s$ bitiyle XOR'lanarak $C_1$ elde edilir; $C_1$ yazmaca sağdan girer, yazmaç $s$ bit sola kayar ve işlem tekrar eder. Şifre çözmede de şifreleme fonksiyonu kullanılır, XOR'a $C_i$ girer ve $P_i$ çıkar (ekrandan, 01:00:00).
- CTR'de sayaç $K$ ile şifrelenir ve $P_1$ ile XOR'lanarak $C_1$ elde edilir; sayaç bir artırılır, şifrelenir ve $P_2$ ile XOR'lanır; bu $n-1$ kez artırılarak sürdürülür. Gönderici ve alıcı sayacı senkron artırır.

> **Ders sonrası not:** Hoca CTR anlatımında bir yerde "her seferinde K anahtarı artıyor" dedi; artırılan anahtar değil sayaçtır, anahtar $K$ bütün bloklarda aynıdır.

### Simetrik anahtar dağıtımı

Anahtar yalnız iki tarafça bilinmelidir; bu yüzden dağıtımı ayrı bir sorundur. (1) $A$ anahtarı seçip $B$'ye fiziksel olarak (örneğin kuryeyle) teslim eder. (2) İki tarafın da güvendiği üçüncü bir taraf anahtarı seçip ikisine fiziksel olarak teslim eder. (3) $A$ ile $B$ daha önce güvenli biçimde bir anahtar paylaşmışsa, yeni anahtarı eski anahtarla şifreleyerek değiş tokuş eder. (4) $A$ ve $B$'nin her biriyle şifreli bağlantısı olan bir $C$ otoritesi (anahtar dağıtım merkezi, KDC), iki taraf arasında kullanılacak anahtarı bu şifreli kanallar üzerinden dağıtır.

Bağlantı yönelimli protokolde otomatik anahtar dağıtımı şöyle işler (ekrandan, 01:05:00): (1) Uygulama bağlantı isteyen paketi gönderir. (2) Güvenlik servisi paketi tamponlar ve KDC'den oturum anahtarı ister. (3) KDC oturum anahtarını iki makineye dağıtır. (4) Tamponlanan paket iletilir. Güvenlik servisi taşıma katmanının üstünde, uygulamanın altında yer alan bir ara katmandır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
