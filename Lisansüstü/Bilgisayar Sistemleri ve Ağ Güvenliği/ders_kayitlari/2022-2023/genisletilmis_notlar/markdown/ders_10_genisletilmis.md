# Ders 10 Genişletilmiş Notu: Bilişim Güvenliğinde Yasal ve Etik Hususlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: yönetim sorunlarının son konusu
- 2. Bilgisayar suçlarının tanımı ve sınıflandırılması
- 3. Avrupa Konseyi Siber Suçlar Sözleşmesi
- 4. CERT 2007 E-Suç İzleme Anketi
- 5. Yasaların uygulanmasındaki zorluklar
- 6. Siber suçlular ve siber suç kurbanları
- 7. Fikri mülkiyet: telif hakkı, patent ve ticari marka
- 8. Ağ ve bilgisayar güvenliğinde fikri mülkiyet, DMCA ve DRM
- 9. Mahremiyet ve ilgili yasal düzenlemeler
- 10. Gizlilik, veri gözetimi ve gizliliğin korunması
- 11. Etik hususlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş: yönetim sorunlarının son konusu

Ders, güvenliği bütüncül olarak ele almak amacıyla birkaç haftadır işlenen yönetimsel hususlar dizisinin devamıdır. Bu dizide daha önce dijital ya da ağ ortamında tehdit altındaki bir kurumun güvenlik ve risk değerlendirmesinin nasıl yapılacağı, fiziksel ve altyapı güvenliği, insan kaynakları güvenliği ve en son güvenlik denetimi (auditing) işlenmişti. Yönetimle ilgili son konu yasal ve hukuki boyuttur.

Hoca konuya "insanlar güvenlik tedbirlerini neden alır?" sorusuyla girdi. İlk cevap, kişinin ya da kurumun kendisi için değerli olan varlığı kaybetmemesidir: bir patent, bir çalışma, müşteri bilgileri ya da mali kayıtlar. Ancak tedbirin bir de yasal güvencesi olmalıdır; tedbir alınır ki bir şey olduğunda kurum haklarını hukuken savunabilsin. Ayrıca bazı kurumlar için tedbir almak yasal bir zorunluluktur. Örneğin bir banka ya da belediye kamuya ait bilgileri tuttuğu için başkalarına ait bilgi ve varlıkların zarar görmesini önleme yükümlülüğü taşır.

Dersin planı şöyledir: önce siber suçlar ve bilgisayar suçlarının dünyada ve Türkiye'de hukuken nasıl tanımlandığı, sonra fikri ve sınai mülkiyet hakları (telif hakkı, patent, ticari marka), ardından mahremiyet kavramı ve son olarak etik hususlar.

## 2. Bilgisayar suçlarının tanımı ve sınıflandırılması

### 2.1 ABD Adalet Bakanlığı sınıflaması

ABD Adalet Bakanlığı bilgisayar suçlarını bilgisayarın suç faaliyetinde oynadığı role göre üç kısma ayırır (ekrandan, 00:15:00):

| Kategori | Açıklama |
|---|---|
| Hedef olarak bilgisayarlar | Veri bütünlüğüne, sistem bütünlüğüne, veri gizliliğine, mahremiyete veya kullanılabilirliğe yönelik bir saldırı içerir. |
| Depolama aygıtı olarak bilgisayarlar | Çalınan parola listelerini, kredi kartı veya arama kartı numaralarını, özel şirket bilgilerini, pornografik görüntü dosyalarını veya korsan ticari yazılımları depolamak için bilgisayarı kullanma. |
| İletişim araçları olarak bilgisayarlar | Dolandırıcılık, kumar, çocuk pornografisi ve reçeteli ilaçların, kontrollü maddelerin, alkolün veya silahların yasa dışı satışı gibi çevrim içi işlenen suçlar. |

Birinci kategoride saldırının hedefi doğrudan bilgisayar sistemi ya da içindeki veridir; saldırgan tutulan verinin bütünlüğünü, gizliliğini ya da kullanılabilirliğini bozmak ister.

İkinci kategoride hedef bilgisayar değildir; bilgisayar bir depodur. Hoca bu kategorinin iki yönünü ayırdı. Bir yönde bilgisayarda çalınmış gizli bilgiler bulunur: kişilere ait parolalar, kredi kartı bilgileri, çalışanların sicil ve sağlık bilgileri ya da şirkete özel bilgiler. Öbür yönde bilgisayar, bulundurulması zaten suç olan içeriği (pornografik görüntüler, korsan ticari yazılımlar) saklamak ve dağıtmak için kullanılır.

Üçüncü kategoride bilgisayar bir iletişim aracıdır: dolandırıcılık, kumar, çocuk pornografisi, reçeteli ilaçların, kontrollü maddelerin, alkolün ya da silahın çevrim içi yasa dışı satışı. Hoca, yasa dışı içeriği depolamanın bir suç kategorisi, onu dağıtmak için bilgisayarı kullanmanın ise ayrı bir suç kategorisi olduğunu vurguladı.

### 2.2 Türk Ceza Kanunu'nda siber suçlar

Türkiye'de ABD'deki gibi üç temel ayrım yoktur. Siber suçlar Türk Ceza Kanunu'nun (TCK) farklı maddelerinde ve bazı maddelerin farklı bentlerinde ayrı ayrı tanımlanmıştır. Hocanın verdiği örnekler:

- Bilişim sistemine girme suçu: TCK madde 243.
- Banka veya kredi kartlarının kötüye kullanılması: TCK madde 245.
- Yasak cihaz veya program kullanma suçu: TCK madde 245/A.
- Müstehcenlik (pornografi): TCK madde 226.

<!-- BELİRSİZ: hoca 243'ten sonra "224'te tanımlanmış" diye bir madde daha söyledi ama hangi suç olduğu altyazıda yok; büyük olasılıkla TCK madde 244 (sistemi engelleme, bozma, verileri yok etme veya değiştirme) kastedildi; bu slayt karelerde yok -->

## 3. Avrupa Konseyi Siber Suçlar Sözleşmesi

Avrupa Konseyi tarafından geliştirilmiş ve Amerika Birleşik Devletleri dahil 43 ülke tarafından onaylanmış bir sözleşme vardır (ekrandan, 00:20:00). Sözleşme suçları tanımlar; ancak bir suça ne kadar ceza verileceği ülkeden ülkeye değişir.

> **Ek bilgi (derste anlatılmadı):** Bu sözleşme büyük olasılıkla 2001'de Budapeşte'de imzaya açılan ve "Budapeşte Sözleşmesi" diye de bilinen Siber Suç Sözleşmesi'dir. Türkiye de büyük olasılıkla bu sözleşmeye taraftır. Onaylayan ülke sayısı slayttaki tarihten sonra artmıştır.

Slaytta yer alan maddeler (ekrandan, 00:20:00):

| Madde | Tanım |
|---|---|
| Madde 2: Yasa dışı erişim | Bir bilgisayar sisteminin tamamına veya herhangi bir kısmına hak olmaksızın erişimdir. |
| Madde 3: Yasa dışı durdurma | Bu tür bilgisayar verilerini taşıyan bir bilgisayar sisteminden elektromanyetik emisyonlar da dahil olmak üzere, bilgisayar verilerinin bir bilgisayar sistemine, sistemden veya bilgisayar sistemi içinde kamuya açık olmayan aktarımlarının teknik yollarla haksız olarak kesilmesidir. |
| Madde 4: Veriye müdahale | Bilgisayar verilerinin haksız yere zarar görmesi, silinmesi, bozulması, değiştirilmesi veya gizlenmesidir. |
| Madde 5: Sisteme müdahale | Bilgisayar verilerini girerek, ileterek, zarar vererek, silerek, bozarak, değiştirerek veya gizleyerek bir bilgisayar sisteminin işleyişinin hak olmaksızın ciddi şekilde engellenmesidir. |
| Madde 7: Bilgisayarla ilgili sahtecilik | Bilgisayar verilerinin girilmesi, değiştirilmesi, silinmesi veya gizlenmesi, verilerin doğrudan okunabilir ve anlaşılır olup olmadığına bakılmaksızın, yasal amaçlar doğrultusunda gerçekmiş gibi değerlendirilmesi veya üzerinde işlem yapılması amacıyla gerçek olmayan verilerle sonuçlanmasıdır. |

Hoca madde 3'ü açıklarken "elektromanyetik emisyonlar dahil" ifadesinin fiziksel müdahaleleri de kapsadığını, suçun özünde iletişimin teknik olarak kesilmesi olduğunu belirtti.

Tablonun ikinci yarısı karelerde yoktur; aşağıdaki maddeler altyazıdan kurulmuştur:

- Madde 6, cihazların kötüye kullanımı: 2-5. maddelerdeki suçlardan herhangi birini işlemek amacıyla cihazların üretilmesi, satılması vb. <!-- BELİRSİZ: altyazıda bu maddenin başı eksik; yalnız "satılması ... iki ile beş maddeler uyarınca belirlenen suçlardan herhangi birini işlemek amacıyla cihazlar" kısmı var -->
- Madde 8, bilgisayarla ilgili dolandırıcılık: bilgisayar verilerinin herhangi bir şekilde girilmesi, değiştirilmesi veya silinmesiyle ya da bir bilgisayar sisteminin işleyişine hileli ve dürüst olmayan şekilde müdahale ederek, kendisi veya başkası için ekonomik çıkar sağlamak amacıyla başka bir kişinin malının kaybına sebep olmak.
- Madde 9, çocuk pornografisiyle ilgili suçlar: bir bilgisayar sistemi aracılığıyla dağıtmak amacıyla çocuk pornografisi üretmek; sunmak veya erişilebilir kılmak; dağıtmak veya iletmek; kendisi veya başkası için temin etmek; bir bilgisayar sisteminde veya bilgisayar veri depolama ortamında bulundurmak.
- Madde 11, teşebbüs ve yardım veya yataklık: sözleşmenin ilgili maddelerinde (2-10) belirlenen suçlardan herhangi birinin işlenmesi niyetiyle yardım ve yataklık etmek de suçtur.

## 4. CERT 2007 E-Suç İzleme Anketi

Hoca daha sonra CERT'in 2007 e-suç izleme anketinin sonuçlarını gösterdi. Tabloda her suç türü için ankette işlendiği bildirilen net yüzde ile faillerin içeriden, dışarıdan ya da belirsiz olma yüzdeleri yer alır (ekrandan, 00:25:00):

| Suç türü | İşlenen (net) % | İçeriden % | Dışarıdan % | Belirsiz % |
|---|---|---|---|---|
| Virüs, solucanlar veya diğer kötü amaçlı kodlar | 74 | 18 | 46 | 26 |
| Bilgilere, sistemlere veya ağlara yetkisiz erişim/kullanım | 55 | 25 | 30 | 10 |
| Yasa dışı spam e-posta üretimi | 53 | 6 | 38 | 17 |
| Casus yazılım (reklam yazılımı hariç) | 52 | 13 | 33 | 18 |
| Hizmet reddi saldırıları | 49 | 9 | 32 | 14 |
| Dolandırıcılık (kredi kartı dolandırıcılığı vb.) | 46 | 19 | 28 | 5 |
| Oltalama-kimlik avı (abonelerinizden veya çalışanlarınızdan kişisel veri elde etmek amacıyla çevrim içi şirketiniz gibi davranan biri) | 46 | 5 | 35 | 12 |
| Müşteri kayıtları, mali kayıtlar vb. dahil diğer (özel) bilgilerin çalınması | 40 | 23 | 16 | 6 |
| Fikri mülkiyet hırsızlığı | 35 | 24 | 12 | 6 |
| Özel veya hassas bilgilerin kasıtlı olarak ifşa edilmesi | 35 | 17 | 12 | 9 |
| Müşterinin kimlik hırsızlığı | 33 | 13 | 19 | 6 |
| Sabotaj: bilgi, sistem veya ağların kasıtlı olarak bozulması, silinmesi veya yok edilmesi | 30 | 14 | 14 | 6 |
| Kuruluşun ağındaki zombi makineler/botlar/ağın BotNet'ler tarafından kullanımı | 30 | 6 | 19 | 10 |
| Web sitesi tahrifatı | 24 | 4 | 14 | 7 |
| Gasp | 16 | 5 | 9 | 4 |
| Diğer | 17 | 6 | 8 | 7 |

Hoca tablodan şu değerleri okudu: kötü amaçlı kodların %46'sı dışarıdan, yetkisiz erişimin %30'u dışarıdan ve %25'i içeriden, web sitesi tahrifatının %14'ü dışarıdan, gaspın %9'u dışarıdandır. Tabloya bakıldığında çoğu suç türünde dışarıdan gelen oran içeriden gelenden yüksektir. Müşteri ve mali kayıtların çalınması (23'e 16), fikri mülkiyet hırsızlığı (24'e 12) ve hassas bilgilerin kasıtlı ifşası (17'ye 12) ise içeriden gelenlerin ağır bastığı kalemlerdir; sabotajda iki oran eşittir (14'e 14). Bu tür suçlar kurumun içindeki bilgiye erişimi olan kişilerin işine daha uygundur.

> **Ders sonrası not:** Satırlarda içeriden, dışarıdan ve belirsiz yüzdelerinin toplamı net yüzdeyi tutmaz (örneğin kötü amaçlı kodda $18 + 46 + 26 = 90 \neq 74$). Bu yüzden bu sütunlar büyük olasılıkla net yüzdenin parçaları değil, farklı bir tabana (örneğin her fail türünü bildiren katılımcıların oranına) göre hesaplanmış değerlerdir; "net yüzdenin %46'sı" gibi okunmamalıdır.

## 5. Yasaların uygulanmasındaki zorluklar

Siber suçlar bu kadar yaygınken neden hâlâ önlenemiyor? Hocaya göre en temel neden şudur: kolluk kuvvetlerinin bilgisayar ve ağ saldırıları üzerindeki caydırıcı etkisi, tutuklama ve kovuşturmanın başarı oranıyla ilişkilidir. Caydırıcı olabilmek için suçlunun yakalanması ve hükümle cezalandırılması gerekir. Oysa söz konusu olan internettir, yani "ağların ağı"; küresel bir mekanizmadır ve saldırgan VPN gibi araçlarla konumunu gizleyebilir.

Kolluk kuvvetlerinin yaşadığı zorluklar:

- Bu tür suçlarla mücadele konusunda bilgili ve deneyimli personel eksikliği. Hoca bunu en temel sebep olarak gördü.
- Suçları araştırabilecek yeterli teknoloji altyapısının ve bütçenin eksikliği.
- Siber suçların küresel doğası: saldırı dünyanın herhangi bir yerinden gelebilir, VPN'ler üzerinden farklı ülkelerden geçebilir. Suçluyu yakalamak için uzak ülkelerin kolluk kuvvetleriyle eşgüdüm halinde, üstelik gerçek zamanlı çalışmak gerekir; bu eşgüdüm çoğu zaman yoktur.

Suçlu yakalanamayınca doğal olarak cesaretlenir. Siber Suçlar Sözleşmesi suçlar için ortak bir terminoloji ve yasaların küresel olarak uyumlu hale getirilmesi için bir çerçeve sunar. Ancak hocanın belirttiği gibi sözleşmeyi 43 ülke kabul etmiştir ve dünyadaki ülke sayısı bundan çok fazladır. Suçların tanımlanmasından sonra her ülkenin kendi yasalarıyla bu suçları cezalandırması da gerekir.

## 6. Siber suçlular ve siber suç kurbanları

### 6.1 Siber suçlular

Siber suçluların adalete teslim edilememesi, sayılarının, cesaretlerinin ve operasyonlarının küresel ölçeğinin artmasına yol açmıştır. Sayıları çok fazladır; botlar ve zombi makineler yoluyla bir kullanıcı haberi olmadan saldırıya alet olabilir.

Adi suçlarda kolluk kuvvetleri bir suçlu profili oluşturur. Siber suçluların ise kesin bir profili yoktur. Genç ve bilgisayar meraklısı olma eğilimindedirler; bir kısmı bu yeteneklerini gelir elde etmek için değil, yeteneğini göstermek için kullanır. Davranışsal özelliklerinin aralığı geniştir, bu yüzden profil daraltılamaz; muhtemel şüphelilere işaret edebilecek bir siber suçlu veritabanı da şu ana kadar yoktur.

### 6.2 Siber suç kurbanları

Slayttaki akış şöyledir (ekrandan, 00:30:00):

```text
Kurbanlar, siber suçluların başarısından ve kolluk kuvvetlerinin
başarısızlığından etkilenirler
        |
        v
Bu kuruluşların çoğu, saldırıları önlemek için teknik, fiziksel ve
insan faktörü kaynaklarına yeterince yatırım yapmamıştır
        |
        v
Kolluk kuvvetlerine güven eksikliği, kurumsal itibarla ilgili endişeler
ve hukuki sorumlulukla ilgili endişeler nedeniyle ihbar oranları
düşük olma eğilimindedir
```

Hoca bu durumu bir kabullenmişlik olarak yorumladı. Örneğin fidye yazılımı (ransomware) sisteme girip verileri şifreler; veriler gittiği için kurum çoğu zaman "kuzu kuzu" fidyeyi öder. Kurumlar bilişime ciddi paralar harcamış, ama siber güvenlik her zaman en son düşünülmüş ve çoğu zaman saldırı olana kadar ihmal edilmiştir. Saldırı olduktan sonra da müşterinin gözünde kötü duruma düşme korkusuyla ihbar bile edilmez, olay "sineye çekilir".

### 6.3 Kolluk kuvvetleriyle çalışmak

Kurumların üst düzey yönetimi ve güvenlik yöneticileri yasa uygulamasını bir kaynak ve araç olarak görmelidir; yasa, yönetmelik ve bunların uygulaması da güvenlik tedbirlerinin bir parçasıdır. Yönetim şunları anlamalıdır:

- Adli bir soruşturma sürecinin nasıl yürütüldüğü.
- Yasalarda hangi hakların bulunduğu ve bunları takip etmek için hangi teknik bilgilere ihtiyaç duyulduğu.
- Bilirkişilerin ve hakimlerin soruşturma sırasında ihtiyaç duyacağı girdiler; kurum bunları tedarik edebilmelidir.
- Mağdurun soruşturmaya olumlu katkı sağlayabileceği. Mağdur, mağdur olduğunu söyleyebilmelidir ki araştırma ve takip yapılabilsin.

## 7. Fikri mülkiyet: telif hakkı, patent ve ticari marka

Fikri mülkiyetin (intellectual property) üç temel türü patentler, ticari markalar ve telif haklarıdır (copyright).

### 7.1 Telif hakkı

Telif hakkı bir fikrin somut veya sabit ifadesini korur; fikrin kendisini korumaz. Hoca bu cümleyi iki kez tekrarladı.

> **Hocanın vurgusu:** Telif hakkı fikrin kendisini değil, o fikrin somut ve sabit ifadesini korur.

Eserin yaratıcısı şu koşullarda telif hakkı talep edebilir ve bunu ulusal bir telif hakkı ofisinde tescil ettirebilir:

- Çalışma özgündür ve yaratıcısına aittir.
- Yaratıcı bu özgün fikri somut bir forma sokmuştur.

Tescil, eserin yaratıcısının kim olduğunu ve fikrin somut ifadesini koruma altına alır. Fikrin başkaları tarafından izinsiz kullanılması fiilen engellenemez; kullanıldıktan sonra hukuki mücadele vermek gerekir.

Telif hakkı sahibi ihlale karşı korunan şu münhasır haklara sahiptir (ekrandan, 00:35:00):

- Çoğaltma hakkı
- Değişiklik hakkı
- Dağıtım hakkı
- Herkese açık gösteri hakkı
- Herkese açık görüntüleme hakkı

Telif hakkının kapsadığı eser örnekleri (ekrandan, 00:35:00):

- Edebi çalışmalar (roman, hikâye, şiir)
- Müzikal eserler
- Dramatik eserler
- Pandomimler ve koreografik eserler
- Resim, grafik ve heykel çalışmaları
- Hareketli resimler ve diğer görsel-işitsel eserler
- Ses kayıtları
- Mimari işler
- Yazılımla ilgili işler

Hoca yazılımın bu listede biraz komik durduğunu söyledi: yazılan bir program roman gibi telif hakkıyla korunabilir, ama bu koruma zayıftır. Biri programı öğrendikten sonra bazı alanları değiştirerek aynı işi başka türlü yapabilir; bu yüzden yazılımda koruma hâlâ sorunludur.

### 7.2 Patent

Patent, mucide buluşuyla ilgili bir mülkiyet hakkı verir. Bu hak, başkalarının buluşu ilgili ülkede (patent hangi ülkede alındıysa, örneğin ABD'de ya da Türkiye'de) yapmasını, kullanmasını ve satmasını ya da buluşu o ülkeye ithal etmesini engeller. Patent türleri:

- Faydalı (utility) patent: herhangi bir yeni ve kullanışlı süreç, makine, imalat ürünü ya da madde bileşimi için alınır.
- Tasarım patenti: bir imalat ürünü için yeni, özgün ve süsleyici bir tasarım için alınır. <!-- BELİRSİZ: altyazıda bu tür "üsüslü, caycanlı tasarım" diye bozuk geçiyor; slayt karelerde yok -->
- Bitki patenti: farklı ve yeni bir bitki çeşidini keşfedip eşeysiz olarak yeniden üreten kişi bunu patentleyebilir.

### 7.3 Ticari marka

Ticari marka (trademark), mal ticaretinde kullanılan, malların kaynağını gösteren ve onları başkalarının mallarından ayıran bir kelime, isim ya da semboldür. Hoca bilinen spor giyim, içecek ve otomobil markalarını örnek verdi.

Ticari marka hakkı, başkalarının kafa karıştıracak kadar benzer markalar kullanmasını engeller. Hoca, iyi bilinen bir elektronik markasının adına çok benzeyen bir taklit adı örnek verdi. Ancak marka hakkı başkalarının aynı malları üretmesini ya da aynı mal ve hizmetleri açıkça farklı bir marka adıyla satmasını engellemez. Taklit ürün bulunursa toplatılabilir ya da dava açılabilir, ama marka tescili üretimi fiziksel olarak engellemez.

## 8. Ağ ve bilgisayar güvenliğinde fikri mülkiyet, DMCA ve DRM

### 8.1 Güvenlikle ilgili fikri mülkiyet biçimleri

Ağ ve bilgisayar güvenliği bağlamında şu fikri mülkiyet biçimleri önemlidir:

- Yazılım: ticari yazılım satıcılarının programları, paylaşılan yazılımlar (shareware), bir kuruluşun iç kullanım için geliştirdiği tescilli yazılımlar ve kişilerin geliştirdiği yazılımlar.
- Veri tabanları: potansiyel ticari değeri olan veriler. Örneğin e-ticaret siteleri müşteri eğilimlerini toplayıp veri tabanları oluşturur ve bunlar para karşılığı satılabilir.
- Dijital içerik: ses ve video dosyaları, multimedya, eğitim yazılımları, web sitesi içerikleri ve diğer özgün dijital çalışmalar.
- Algoritmalar: patentlenebilir algoritmalar. Hoca RSA açık anahtarlı şifreleme algoritmasını ve diğer şifreleme algoritmalarını örnek verdi.

### 8.2 ABD Dijital Milenyum Telif Hakkı Yasası (DMCA)

DMCA'nın temel özellikleri (ekrandan, 00:40:00):

- 1998'de kanunlaştı.
- Dijital telif hakkıyla korunan materyallerin korunmasını güçlendirmek için WIPO (Dünya Fikri Mülkiyet Örgütü) anlaşmalarını uygular.
- Telif hakkı sahiplerini, korunan eserlerini korumak için teknolojik önlemler almaya teşvik eder:
  - Esere erişimi engelleyen tedbirler.
  - Eserin kopyalanmasını önleyici tedbirler.
- Önlemleri atlama girişimlerini yasaklar:
  - Engelleme girişimlerine hem cezai hem de hukuki yaptırımlar uygulanır.

#### DMCA muafiyetleri

Bazı eylemler DMCA hükümlerinden ve diğer telif hakkı yasalarından muaftır:

- Adil kullanım.
- Tersine mühendislik: bir ürünü alıp tersine mühendislikle incelemek (birebir kopyasını üretmek değil) muaftır.
- Şifreleme araştırmaları: bir algoritmanın sahibi, başkasının o algoritmanın zayıflığını araştırmasını telif hakkını gerekçe göstererek engelleyemez.
- Güvenlik testleri.
- Kişisel mahremiyet.

Yani başkalarının patentli ürünleri güvenlik testine tabi tutulabilir, şifreleme açısından incelenebilir ve geliştirilmeye çalışılabilir; yasa araştırmanın önünde engel değildir.

Buna rağmen DMCA'nın meşru güvenlik ve şifreleme araştırmalarını engellediğine dair önemli endişeler vardır. Yasanın inovasyonu ve akademik özgürlüğü bastırdığı, açık kaynaklı yazılım geliştirmeyi tehdit ettiği düşünülür. Hoca, büyük bir yazılım şirketinin "bu benimkine benzedi" gerekçesiyle açık kaynak ürünlere ya da başka tarayıcı geliştiricilerine karşı açtığı türden gereksiz davaları örnek verdi.

### 8.3 Türkiye'de dijital ortamda telif hakkının korunması

Türkiye'de telif hakkı ihlaline karşı açılabilecek üç hukuk davası vardır:

- Tecavüzün ref'i (kaldırılması) davası.
- Tecavüzün men'i (durdurulması) davası.
- Maddi ve manevi tazminat davaları.

Bunların yanında ceza davası da açılabilir. Hocanın okuduğu hükme göre, bir eseri hak sahibinin yazılı izni olmaksızın işleyen, değiştiren, her türlü işaret, ses veya görüntü nakline yarayan araçlarla umuma ileten, yayan ya da kişisel kullanım amacı dışında elinde bulunduran veya depolayan kişi hakkında bir yıldan beş yıla kadar hapis veya adli para cezası hükmolunur. Bu hükme dayanarak dijital ortamdaki algoritma, patent ya da faydalı modelle ilgili ihlaller için ceza davası açılabilir.

> **Ders sonrası not:** Hoca bu ceza hükmünü Türk Ceza Kanunu'na bağladı. Bu hüküm büyük olasılıkla TCK'da değil, 5846 sayılı Fikir ve Sanat Eserleri Kanunu'nun 71. maddesindedir. Ref, men ve tazminat davaları da büyük olasılıkla aynı kanunda düzenlenmiştir.

### 8.4 Dijital Haklar Yönetimi (DRM)

Dijital Haklar Yönetimi (Digital Rights Management, DRM), dijital hak sahiplerinin açıkça tanınmasını ve eserleri için öngörülen ödemeyi almasını sağlayan sistem ve prosedürlerdir. Hoca, Türkiye'de lisanssız yazılım kullanımını takip eden BSA (Business Software Alliance) örneğini verdi: telifli, markalı ya da lisanslı yazılımlar izinsiz kullanıldığında kurum hukuki işlemle karşılaşabilir.

Tek bir DRM standardı ya da mimarisi yoktur. Amaç, içerik yönetiminin bütün yaşam döngüsü için mekanizmalar sağlamak ve farklı dijital içerik türleri, platformlar ve ortamlar içinde içeriğin kalıcı olarak korunmasını sağlamaktır.

## 9. Mahremiyet ve ilgili yasal düzenlemeler

### 9.1 Mahremiyet kavramı

Slayttaki temel noktalar (ekrandan, 00:45:00):

- Mahremiyet bilgisayar güvenliği ile örtüşür.
- Toplanan ve saklanan bilgi ölçeğinde çarpıcı bir artış vardır; bu artış kolluk kuvvetleri, ulusal güvenlik ve ekonomik teşvikler tarafından motive edilmiştir.
- Bireyler kişisel bilgilere ve yaşamlarıyla ilgili özel ayrıntılara erişim ve bunların kullanımı konusunda giderek daha fazla bilinçlenmeye başlamıştır.
- Mahremiyetten taviz vermenin boyutuyla ilgili endişeler, mahremiyet haklarının güçlendirilmesine yönelik çeşitli yasal ve teknik yaklaşımlara yol açmıştır.

Hoca günlük hayattan örnekler verdi: her yerde kişisel bilgiler toplanıyor; KVKK kapsamında izin verip vermediğimiz soruluyor, reklam e-postaları geliyor, bir mağazada indirimden yararlanmak için bile kişisel bilgi isteniyor. Sosyal medyanın ilk yıllarında insanlar gezdikleri yerleri rahatça paylaşırken, şimdi bu fotoğrafların akıbeti konusunda endişe duyuyor.

### 9.2 AB Veri Koruma Direktifi

Avrupa Birliği'nin Veri Koruma Direktifi, kişisel bilgiler işlenirken üye devletlerin temel gizlilik haklarının korunduğundan emin olmasını ister. Direktifin ilkeleri altyazıya göre şunlardır:

- Kişi verilerinin toplandığından haberdar olmalıdır.
- Kişi verilerinin toplanmasına rıza göstermelidir.
- Veriler tutarlı olmalıdır.
- Verilere kimlerin erişebildiği bilinmelidir.
- Veriler güvenli bir şekilde saklanmalıdır.
- Verilerin nereye aktarılacağı ve hangi uygulamalarda kullanılacağı bilinmelidir.

<!-- BELİRSİZ: bu slayt karelerde yok; ilkeler altyazıdan kuruldu, slayttaki adları farklı olabilir -->

> **Ders sonrası not:** Hoca direktifin 1998'de kabul edildiğini söyledi. Direktif (95/46/EC) büyük olasılıkla 1995'te kabul edilmiş, 1998'de yürürlüğe girmiştir; 2018'den beri yerini Genel Veri Koruma Tüzüğü (GDPR) almıştır.

### 9.3 ABD 1974 Gizlilik Yasası

ABD'de 1974 tarihli Gizlilik Yasası (Privacy Act):

- Federal kurumlar tarafından toplanan ve kullanılan kişisel bilgilerle ilgili işlemleri kapsar.
- Bireylerin hangi kayıtların tutulduğunu belirlemesine izin verir.
- Bireylerin kayıtlarının başka amaçlarla kullanılmasını engellemesine izin verir.
- Bireylerin kayıtlarına erişmesine, onları uygun şekilde düzeltmesine ve değiştirmesine izin verir.
- Kurumların kişisel bilgileri uygun şekilde toplamasını, muhafaza etmesini ve kullanmasını sağlar.
- Bireyler için bu konuda özel bir dava hakkı oluşturur.

### 9.4 Türkiye: KVKK

Türkiye'de bu alandaki düzenleme 2016 tarihli 6698 sayılı Kişisel Verilerin Korunması Kanunu'dur (KVKK). Kanun:

- Başta özel hayatın gizliliği olmak üzere kişilerin temel hak ve özgürlüklerini korur; kişisel verileri işleyen gerçek ve tüzel kişilerin yükümlülüklerini ve uyacakları usul ve esasları düzenler.
- Özel nitelikli ve genel kişisel verilerin işlenme şartlarını belirler.
- Kişisel verilerin silinmesi, yok edilmesi ve anonim hale getirilmesiyle ilgili hususları belirler.
- Kişisel verilerin aktarılması ve yurt dışına aktarılmasıyla ilgili hususları belirler.
- Veri sorumlusunun aydınlatma yükümlülüğünü tanımlar.
- Veri sahibinin haklarını ve veri güvenliğiyle ilgili yükümlülükleri tanımlar.
- Başvuru, şikâyet ve veri sorumlusuyla ilgili cezai hususları tanımlar.

### 9.5 ISO 27002

Standart dokümanlar arasında ilk akla gelen ISO 27002'dir. Slayttaki metin (ekrandan, 00:50:00):

> "Bir kuruluşun kişisel olarak tanımlanabilir bilgilerin gizliliği ve korunmasına yönelik veri politikası geliştirilmeli ve uygulanmalıdır. Bu politika, kişisel olarak tanımlanabilir bilgilerin işlenmesine dahil olan tüm kişilere iletilmelidir. Kişilerin mahremiyetinin ve kişisel olarak tanımlanabilir bilgilerin korunmasına ilişkin bu politikaya ve ilgili tüm mevzuat ve düzenlemelere uyum, uygun yönetim yapısı ve kontrolü gerektirir. Genellikle bu en iyi şekilde, yöneticilere, kullanıcılara ve hizmet sağlayıcılara bireysel sorumlulukları ve izlenmesi gereken özel prosedürler konusunda rehberlik etmesi gereken bir gizlilik görevlisi gibi bir sorumlu kişinin atanmasıyla elde edilir. Kişisel olarak tanımlanabilir bilgilerin işlenmesi ve gizlilik ilkeleri konusunda farkındalığın sağlanması sorumluluğu ilgili mevzuat ve düzenlemelere uygun olarak ele alınmalıdır. Kişisel olarak tanımlanabilir bilgileri korumak için uygun teknik ve organizasyonel önlemler uygulanmalıdır."

Hoca, bir kurum ISO 27002'ye dayalı bir sertifika almak istiyorsa bu koşulları sağlıyor olması gerektiğini belirtti.

## 10. Gizlilik, veri gözetimi ve gizliliğin korunması

### 10.1 Gizlilik ve veri gözetimi

Büyük şirketlerin, hükümetlerin ve kolluk kuvvetlerinin talepleri kişisel mahremiyete yönelik yeni tehditler yaratmıştır. Güvenliği sağlamak için her yere kameralar, parmak iziyle giriş sistemleri, turnikeler ve kartlar konmuştur. Bilimsel ve tıbbi araştırma için veri toplanması, kolluk kuvvetlerinin veri gözetimi ve özel kuruluşların profil oluşturması; bilimsel araştırma, halk sağlığı, ulusal güvenlik, kolluk ve kaynakların verimli kullanımı gibi alanlarda faydalı sonuçlar doğurur. Ama bu verilerin toplanması ile bireylerin mahremiyet haklarına saygı arasında bir çelişki vardır.

Hoca bu çelişkiyi iki örnekle açıkladı. Ne kadar çok veri toplanırsa kolluk kuvvetleri işini o kadar kolay yapar ve ortam daha güvenli olur. Sağlıkla ilgili veriler ne kadar çok işlenirse kişi hastalanmadan gerekli tedbirler alınabilir. Ancak kişisel verilerin bu ölçüde toplanması bireyin mahremiyetine ciddi bir müdahale demektir.

Diğer bir etken, halka açık ve sosyal medya sitelerinin kullanımındaki hızlı artıştır. Bu siteler bireyler ve onların diğer bireylerle ve kuruluşlarla etkileşimleri hakkında büyük miktarda veri toplar, analiz eder, paylaşır ve çoğu zaman ticari amaçla kullanır. Birçok kişi fotoğraflar ve durum güncellemeleri dahil büyük miktarda kişisel veriyi bilerek ve isteyerek yükler. Bu veriler ileride mevcut ve gelecekteki işverenler, sigorta şirketleri, özel dedektifler ve başkaları tarafından kullanılabilir.

> **Hocanın vurgusu:** Bugün bilerek ve isteyerek paylaştığınız bilgiler, on yıl sonra girmek istediğiniz bir işte başınıza bela olabilir.

### 10.2 Gizliliğin korunması

Slayttaki noktalar (ekrandan, 00:55:00):

- Gizliliği korumak için hem politika hem de teknik yaklaşımlar gereklidir.
- Teknik yaklaşımlar açısından, veri tabanı güvenliği için geliştirilen teknik mekanizmalar kullanılarak bilgi sistemlerinde depolanan verilerin gizliliğinin korunması gereklilikleri kısmen ele alınabilir.
- Sosyal medya siteleriyle ilgili olarak teknik kontroller şunları içerir:
  - Bireylere ilişkin verileri kimlerin görüntüleyebileceğini yönetmek için uygun gizlilik ayarlarının sağlanması.
  - Bir kişiye referans verildiğinde veya başka bir kişinin içeriğinde etiketlendiğinde bildirim.
  - Sosyal medya siteleri bu kontrollerin bir kısmını içerse de kontroller sürekli değişiyor ve bu mekanizmalara ayak uydurmaya çalışan kullanıcılar için hayal kırıklığı yaratıyor.
- Büyük veri analizinde mahremiyet endişelerini yönetmek için başka bir yaklaşım, analiz için araştırmacılara veya diğer kuruluşlara verilmeden önce verileri anonimleştirmek, kişisel olarak tanımlayıcı bilgileri kaldırmaktır.

Hoca etiketleme bildirimini bir örnekle açıkladı: on arkadaş birlikte bir tatil fotoğrafı çektirmiştir ve bunlardan biri fotoğrafı paylaşır. Paylaşan kişi kendi mahremiyetini değil, diğer dokuz kişinin mahremiyetini de etkilemiş olur. Bu yüzden etiketlenen kişiye bildirim gitmelidir.

Politika açısından, gizliliği korumak için büyük verilerin kullanımını ve yeniden kullanımını uygun kısıtlamalarla yöneten kanunlara, yönetmeliklere ve yönergelere ihtiyaç vardır. Bu politikaların ele aldığı konular:

- Rıza: kişinin verisinin kullanılmasına razı olması; katılımcıların araştırmaya katılım hakkında bilinçli karar verebilmesinin sağlanması.
- Mahremiyet ve gizlilik: mahremiyet, bireyin kişisel bilgilerine kimlerin erişebileceğini bilmesidir; gizlilik ise bilgiye yalnız yetkili kişilerin erişebilmesi ilkesidir.
- Mülkiyet ve yazarlık: verilerden kimin sorumlu olduğu ve bireyin hangi noktada kişisel verilerini kontrol etme hakkından vazgeçtiğinin bilinmesi.
- Veri paylaşımı: araştırmanın sosyal faydalarının değerlendirilmesi bağlamında veri eşleştirme ve bir kaynaktan ya da araştırma projesinden alınan verilerin başka bir kaynakta yeniden kullanılmasından doğan sosyal faydalar; yönetim ve gözetim.

## 11. Etik hususlar

### 11.1 Etiğin tanımı

Etik, belirli eylemlerin yararları ve zararları ile bu eylemlerin amaçlarının ve hedeflerinin doğruluğu ve yanlışlığıyla ilgili bir ahlaki ilkeler sistemidir. Bilgi ve elektronik iletişimin gizlilik ve güvenlik sorunları yaratan pek çok olası kötü kullanımı vardır. Medeniyetlerin geliştirdiği temel etik ilkeler burada da geçerlidir. Ancak bilgisayarlar bazı özgün sorunlar da getirir: daha önce mümkün olmayan ölçekte faaliyetler ve üzerinde daha önce anlaşmaya varılmış etik kuralların bulunmadığı yeni tür kuruluşların ortaya çıkması.

Hoca ayrıca bir etik hiyerarşi piramidinden söz etti. <!-- BELİRSİZ: altyazıda "en üstte ünvan itibar, altta profesyonelizm ve iç profesyonelizm" diye bozuk geçiyor; piramidin katmanları altyazıdan güvenilir biçimde çıkarılamıyor ve slayt karelerde yok -->

### 11.2 Bilgisayarla ilgili etik hususlar

Bilgisayar kullanımından kaynaklanan etik hususlar, bilgisayarların üstlendiği rollere göre sıralanır:

- Bilgi depoları ve bilgi işleyicileri olarak bilgisayarlar.
- Mevcut bilgiden yeni form ve yeni varlık türleri üreten bilgisayarlar.
- Eylem araçları olarak bilgisayarlar.
- Yıldırma ve aldatma sembolleri olarak bilgisayarlar.

Teknolojiyi anlayan, kullanan ve ona erişim iznine sahip olanların bu alanlarda bir etkisi, bir gücü vardır.

### 11.3 Mesleki ve etik sorumluluklar

Bir bilişim uzmanı mesleki sorumluluklarını etik ya da ahlaki sorumluluklarıyla dengelemek zorunda kalabilir. Bir profesyonelin etik görevi işverenine sadakatle çalışmaktır: işini savsaklamamak, şirkete ya da kamuya açıkça zarar verebilecek bir durum oluşturmamak ve şahsi çıkar sağlamamak. <!-- BELİRSİZ: hoca bu listede "ıslık çalmamak" dedi; bu büyük olasılıkla İngilizce "whistle-blowing" (kurum içindeki usulsüzlüğü dışarıya ihbar etme) teriminin birebir çevirisidir, slayt karelerde yok -->

> **Ek bilgi (derste anlatılmadı):** "Whistle-blowing" (ihbarcılık), bir çalışanın kurumundaki yasa dışı ya da kamuya zararlı bir uygulamayı yetkililere veya kamuoyuna bildirmesidir. Bilişim etiğinde işverene sadakat ile kamuya karşı sorumluluk arasındaki klasik ikilem büyük olasılıkla bu durumdur.

### 11.4 Davranış kuralları

Hoca, etiğin kesin bir yasalar ve gerçekler dizisi olmadığını vurguladı. Bazen bir şey yasal olur ama ahlaki olmaz; bazen de ahlaki olanı yapmaya çalışırken yasalar engel olur. Slayttaki noktalar (ekrandan, 01:00:00):

- Etik, kesin yasalar veya gerçekler dizisi değildir.
- Birçok alan etik belirsizlik sunabilir.
- Birçok profesyonel topluluk aşağıdakileri yapabilen etik davranış kurallarını benimsemiştir:
  - 1. Olumlu bir uyarıcı olur ve güven aşılar.
  - 2. Eğitici olur.
  - 3. Bir destek ölçüsü sağlar.
  - 4. Caydırıcılık ve disiplin aracı olur.
  - 5. Mesleğin kamusal imajını geliştirir.

Mesleğin imajına zarar vermemek de bu kuralların bir parçasıdır. Profesyonel toplulukların ayrıntılı etik kurallarını hoca derste okumadı, kendi kendine okunmasını önerdi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:12:50): İnsanlar ve kurumlar güvenlikle ilgili tedbirleri neden alır?

> **Cevap (derste verildi):** Birincisi, kendileri için değerli olan varlıkları (patent, çalışma, müşteri bilgileri, mali kayıtlar) kaybetmemek için. İkincisi, bir olay olduğunda haklarını yasal olarak savunabilmek için. Üçüncüsü, başkalarına ait bilgileri tutan kurumlar (banka, belediye) için tedbir almak hukuki bir yükümlülüktür.

**Soru 2** (ekrandan, 00:25:00; derste sözlü, 00:24:27): CERT 2007 E-Suç İzleme Anketi tablosuna göre suçlar en çok nereden gelmektedir, içeriden mi dışarıdan mı?

> **Cevap (derste kısmen verildi):** Çoğu suç türünde dışarıdan gelen oran yüksektir (örneğin kötü amaçlı kodlarda %46 dışarıdan, %18 içeriden; web sitesi tahrifatında %14 dışarıdan, %4 içeriden). İçeriden gelen oranın daha yüksek olduğu kalemler müşteri/mali kayıtların çalınması (23'e 16), fikri mülkiyet hırsızlığı (24'e 12) ve hassas bilgilerin kasıtlı ifşasıdır (17'ye 12); sabotajda oranlar eşittir (14'e 14). Kalemlerin karşılaştırması tablodan python ile kontrol edilmiştir.

**Soru 3** (derste sözlü, 00:25:07): Siber suçlar bu kadar yaygınken neden hâlâ önlenemiyor?

> **Cevap (derste verildi):** Caydırıcılık yakalanma ve cezalandırılma başarısına bağlıdır. Kolluk kuvvetlerinde bilgili ve deneyimli personel ile teknoloji altyapısı ve bütçe eksiktir. Suç küreseldir ve VPN gibi araçlarla gizlenebilir; yakalamak için farklı ülkelerin kolluk kuvvetlerinin gerçek zamanlı eşgüdümü gerekir. Ayrıca kurbanlar yeterince yatırım yapmamakta ve itibar kaygısıyla ihbar etmemektedir.

## Dersin Toparlaması

Bu derste bilişim güvenliğinin yönetimsel boyutunun son halkası olan yasal ve etik hususlar işlendi. Bilgisayar suçları ABD'de bilgisayarın rolüne göre (hedef, depolama aygıtı, iletişim aracı) üç gruba ayrılırken, Türkiye'de TCK'nın farklı maddelerinde ayrı ayrı tanımlanır; Avrupa Konseyi Siber Suçlar Sözleşmesi ise ortak bir terminoloji sunar. CERT anketi suç türlerinin dağılımını ve içeriden/dışarıdan kaynaklarını gösterdi. Yasaların uygulanmasını zorlaştıran etkenler (personel, altyapı, küresellik) ve kurbanların ihbar etmeme eğilimi tartışıldı. Fikri mülkiyet başlığında telif hakkı, patent ve ticari marka ayrımı, DMCA'nın koruma ve muafiyetleri, Türkiye'deki dava yolları ve DRM ele alındı.

Mahremiyet başlığında AB Veri Koruma Direktifi, ABD Gizlilik Yasası, KVKK ve ISO 27002 karşılaştırıldı; veri toplamanın faydası ile bireyin mahremiyeti arasındaki çelişki ve bunu yönetmek için teknik (gizlilik ayarları, etiket bildirimi, anonimleştirme) ve politik (rıza, mülkiyet, paylaşım) yaklaşımlar anlatıldı. Son olarak etiğin tanımı, bilgisayarların doğurduğu etik sorunlar ve profesyonel davranış kuralları verildi. Hoca bir sonraki derste şifrelemeye genel bir girişle başlanacağını, ardından tek anahtarlı (simetrik) ve açık anahtarlı şifrelemeye geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
