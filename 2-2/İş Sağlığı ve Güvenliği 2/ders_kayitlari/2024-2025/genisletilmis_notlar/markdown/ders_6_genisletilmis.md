# Ders 6 Genişletilmiş Notu: Yapı Sektöründe İş Kazası Analizi, İSG Eğitimleri ve İş İzni Sistemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Nereden Başlayacağız: Bir Yapı Projesinde İSG
- 2. Kaza Tiplerine Göre Analiz ve Önceliklendirme
- 3. Teknolojiyle Önlem: Kaçak Akım Rölesi ve Görüntü İşleme
- 4. Türkiye ve Avrupa'da Kaza Nedenleri
- 5. Yapı Türü, Şantiye Büyüklüğü ve Unvana Göre Kazalar
- 6. Saha Kontrolü ve İSG Eğitimleri
- 7. Piper Alpha Kazası ve İş İzni Sistemi
- 8. Etiketleme-Kilitleme (LOTO) Sistemi
- Örnek Sorular

## 1. Nereden Başlayacağız: Bir Yapı Projesinde İSG

Hoca derse, herhangi bir projede göreve başlayan bir mühendisin yalnız kendi mesleğini icra etmediğini hatırlatarak başladı. Her işin bir de iş sağlığı ve güvenliği (İSG) tarafı ve hukuki tarafı vardır; hangi iş yapılırsa yapılsın bu süreci yürütmek ve bu sürecin içinde görev almak gerekir. Slaytta "Nerden başlayacağız?" sorusu soruldu (ekrandan, 00:05:00).

Bu soruya cevap vermek için bir yapı (inşaat) projesinin İSG süreçlerini değerlendiren örnek bir vaka çalışması kullanıldı. Yapı projesinin seçilmesinin nedeni, en çok ölümlü iş kazasının görüldüğü sektörlerin başında inşaatın gelmesidir. Hocanın aktardığı SGK verisine göre Türkiye'deki ölümlü kazaların yaklaşık %34'ü inşaat sektöründe meydana gelir ve sonraki yıllarda da inşaat bu konudaki ilk sırasını bırakmaz.

Ancak hoca, "inşaatta ölümlü kaza çok" bilgisinin tek başına bir işe yaramadığını vurguladı. Bu bilgiden bir sonuç çıkarmak için **sektöre özel analiz** yapmak gerekir. Geçmişte yaşanan süreçlerin problemlerini ortaya çıkarmak, gelecekte ortaya çıkabilecek problemleri ortadan kaldırmaya götürür; geçmişteki hatalar gelecekteki hatalara işaret eder. İstatistiksel verilere göre yol alınırsa kısıtlı imkân ve zamanın planlaması da buna göre yapılabilir.

## 2. Kaza Tiplerine Göre Analiz ve Önceliklendirme

### 2.1 Veri kaynağı

Hoca, bu konuda İstanbul Teknik Üniversitesi kaynaklı bir çalışmayı örnek verdi. Çalışmada 1979-2010 yılları arasında yapı şantiyelerinde meydana gelen toplam 5239 iş kazası incelenmiştir. Bunların 4347'si arşivdeki iş kazası dosyalarından, 892'si ise mahkemelere yansımış dava dosyalarından ve bilirkişi raporlarından elde edilmiştir ($4347 + 892 = 5239$; dava dosyaları toplamın yaklaşık %17'sidir). Bu sayıda kaza, Türkiye'deki yapı sektörü iş kazalarını analiz etmek için iyi bir veri tabanıdır.

<!-- BELİRSİZ: Altyazıda "bilgisayar raporlarına" geçiyor; büyük olasılıkla "bilirkişi raporları" kastedildi. -->

### 2.2 Kaza tiplerine göre dağılım tablosu

Slaytta gösterilen tablo (ekrandan, 00:10:00), "Yapı Şantiyelerinde İncelenen 5239 İş Kazasının Kaza Tiplerine Göre Dağılımı":

| No | Kaza tipi | Ölüm sayı | Ölüm % | Yaralanma sayı | Yaralanma % | Toplam sayı | Toplam % |
|---|---|---|---|---|---|---|---|
| 1 | İnsan düşmesi | 1028 | 42,9 | 934 | 32,9 | 1962 | 37,4 |
| 2 | Malzeme düşmesi | 251 | 10,5 | 278 | 9,8 | 529 | 10,1 |
| 3 | Malzeme sıçraması | 10 | 0,4 | 211 | 7,4 | 221 | 4,2 |
| 4 | Kazı kenarının göçmesi | 138 | 5,8 | 53 | 1,9 | 191 | 3,6 |
| 5 | Yapı kısmının çökmesi | 167 | 7,0 | 73 | 2,6 | 240 | 4,6 |
| 6 | Elektrik çarpması | 293 | 12,2 | 80 | 2,8 | 373 | 7,1 |
| 7 | Patlayıcı madde kazaları | 50 | 0,2 | 82 | 2,9 | 132 | 2,5 |
| 8 | Yapı makinası kazaları | 206 | 8,6 | 97 | 3,4 | 303 | 5,8 |
| 9 | Uzuv kaptırma | 1 | 0,0 | 604 | 21,3 | 605 | 11,5 |
| 10 | Uzuv sıkışması | 1 | 0,0 | 200 | 7,0 | 201 | 3,8 |
| 11 | El aleti ile ele vurma | 0 | 0,0 | 42 | 1,5 | 42 | 0,8 |
| 12 | Sivri uçlu keskin kenarlı cisim yaralanması | 0 | 0,0 | 75 | 2,6 | 75 | 1,4 |
| 13 | Şantiye içi trafik kazaları | 168 | 7,0 | 38 | 1,3 | 206 | 3,9 |
| 14 | Diğer tip kazalar | 85 | 3,5 | 74 | 2,6 | 159 | 3,0 |
| | Toplam | 2398 | 100,0 | 2841 | 100,0 | 5239 | 100,0 |

Tablodaki toplamlar python ile kontrol edildi: ölüm sütunu 2398, yaralanma sütunu 2841, genel toplam 5239 eder.

> **Ders sonrası not:** Slayttaki tabloda patlayıcı madde kazalarının ölüm yüzdesi %0,2 yazıyor. $50/2398 \approx \%2{,}1$ olduğu için slayttaki değer büyük olasılıkla yazım hatasıdır. Diğer satırların yüzdeleri sayılarla tutarlıdır.

### 2.3 Tehlike kök sebeptir: yükseklik örneği

Hoca, önceki dönemde işlenen tehlike analizini hatırlattı: tehlike, kök sebeptir. Tablonun ilk iki satırı olan insan düşmesi ve malzeme düşmesi iki ayrı risktir, ama ikisinin de kök tehlikesi aynıdır: **yükseklik**. Yükseklik bir tehlike olmaktan çıkarılırsa insan düşmesi ve malzeme düşmesi riskleri de kendiliğinden engellenmiş olur.

Aynı kök sebebe bağlı bu iki kalem toplanırsa:

$$42{,}9 + 10{,}5 = 53{,}4$$

Yani yalnız yükseklik tehlikesine yönelerek yapı sektöründeki ölümlü kazaların yarısından fazlası (%53,4) ortadan kaldırılabilir.

> **Hocanın vurgusu:** Organizasyon içindeki bir yönetici ya da amir, istatistiğe bakarak kısıtlı zamanını ve imkânını en verimli biçimde kullanabilir. Yükseklik temelli tehlikeyi gidermeye yönelik bir plan, tek başına ölümlü kazaların yarısından fazlasını önler.

### 2.4 Listede aşağı inmek

Hoca listede aşağı doğru inerek yüksek oranları aradı: insan düşmesi %42,9, malzeme düşmesi %10,5, malzeme sıçraması %0,4 ve %12,2 ile **elektrik çarpması**. Elektrik de eklenince (ara adım eklendi):

$$53{,}4 + 12{,}2 = 65{,}6$$

yani %65'in üzerinde bir ölümlü kaza önlenebilir. Ardından 13. sıradaki **şantiye içi trafik kazaları** (%7,0; 168 ölüm) ve **yapı makinesi kazaları** (%8,6; 206 ölüm) gösterildi. Bunlar da eklenince (ara adım eklendi):

$$65{,}6 + 7{,}0 = 72{,}6, \qquad 72{,}6 + 8{,}6 = 81{,}2$$

Hoca, birkaç kaleme öncelik verilerek ölümlü kazaların %70-80'inin, birkaç kalem daha eklenerek %90'a yakınının hedeflenebileceğini söyledi.

> **Ders sonrası not:** Hoca bir yerde toplamı "%53,5'e, %54'e yakın" diye yuvarladı; tablodan hesaplanan değer %53,4'tür.

### 2.5 Şantiye içi trafik kazaları

Hoca, şantiye içi trafik kazalarında 168 kişinin hayatını kaybetmesini çok acı ve büyük bir rakam olarak niteledi; çünkü çözümü çok basittir. Şantiye içindeki transfer yolları, depo alanları, sevkiyat sahaları ve geçiş yollarının trafik düzeninin tasarlanması, bazı yerlerde tek yön uygulanması, araç park yerlerinin belirlenmesi ve insan geçiş yollarıyla araç geçiş yollarının birbirinden ayrılması gibi temel idari önlemlerle bu ölümler engellenebilirdi.

## 3. Teknolojiyle Önlem: Kaçak Akım Rölesi ve Görüntü İşleme

### 3.1 Elektrik çarpması

Elektrik görülmez, kokusu olmaz; ancak çarptığı zaman insanı sarsar ve hissettirir. Ölümlü kaza oranı %12,2'dir. Hoca, önceki dönemde anlatılan basit bir teknik önlemi hatırlattı: **kaçak akım rölesi**. Kaçak akım rölesi kullanıldığında kaçak anında devre kesileceği için elektrik kaçağı ölümlü bir kazayla sonuçlanmaz.

### 3.2 Görüntü işleme ile İSG

Yapı makinesi kazalarından bahsederken hoca konuya geniş bir perspektiften bakılması gerektiğini söyledi. Görüntü işleme teknolojisi İSG'ye entegre edildiğinde:

- Sahaya çıkan çalışanın üzerinde yelek ya da baret yoksa geçiş izni verilmez, açmak istediği kapılar açılmaz.
- Kamera, sahaya giren kişide baret, yelek ya da iş ayakkabısı olmadığını algılayıp uyarı verebilir.
- Bir iş makinesinin yakın çevresine insan yaklaştığında önce görsel ve sesli uyarı yapılır; kişi yaklaşmaya devam ederse kazayı engellemek için makine otomatik olarak yavaşlatılır ya da durdurulur.

> **Hocanın vurgusu:** Bu sistemler günümüzde yapılması zor olmayan uygulamalardır ve arka planda bunları kuran ve yöneten kişiler bilgisayar mühendisleridir.

## 4. Türkiye ve Avrupa'da Kaza Nedenleri

### 4.1 Türkiye

Slaytta "Yapı İşlerinde Kaza Nedenleri – Türkiye" başlıklı pasta grafik gösterildi (ekrandan, 00:15:00):

| Neden | Oran |
|---|---|
| Düşme | %40 |
| Makine | %14 |
| Düşen cisimler | %14 |
| Elektrik | %8 |
| Diğer | %24 |

Düşme, makine, düşen cisimler ve elektrik toplamı $40 + 14 + 14 + 8 = 76$, yani yapı işlerindeki kazaların %76'sıdır.

### 4.2 Avrupa ile karşılaştırma

Hoca ardından aynı grafiğin Avrupa'daki karşılığını gösterdi. İki dağılım arasında elektrik dışında yalnız 1-2 puanlık farklar vardır; Avrupa'da elektrik kaynaklı kazaların oranı %8'den yaklaşık %4'e düşer.

<!-- BELİRSİZ: Avrupa grafiğinin karesi yok; Avrupa oranları yalnız altyazıdan alındı. -->

Bundan çıkan sonuç şudur: Bu işin doğası ve sektörel yapısı gereği, gerekli önlemler alınmazsa karşılaşılacak kaza oranları dünyanın her yerinde aşağı yukarı benzerdir. Yüksekte çalışma tehlikesini, elektrik konularını ve makinelerin sebep olduğu kazaları gidermek sürecin büyük kısmını tamamlar.

Elektrikteki farkın nedeni, Avrupa ülkelerinde meslek icrası için mesleki yeterliliğin ve bunun denetiminin çok sıkı olmasıdır. Orada elektrik işini gerçekten elektrikçi olanlar yapar; alaylı biri bile temel eğitimini alıp belgesini almak zorundadır, eğitim almamış birinin çalışmasına izin verilmez. Bu nedenle elektrik işlerindeki kaza oranında yaklaşık iki katlık fark vardır.

> **Ders sonrası not:** Hoca bu farkı "%100 fark" diye ifade etti; %8'in %4'e inmesi oranın yarıya düşmesidir, yani Türkiye'deki oran Avrupa'dakinin iki katıdır.

## 5. Yapı Türü, Şantiye Büyüklüğü ve Unvana Göre Kazalar

### 5.1 Yapı türü

Hocanın aktardığı dağılımda yol yapımında yaklaşık %8,5, köprü işlerinde yaklaşık %3,6 gibi oranlar vardır; en fazla kaza ise **bina inşaatlarında** görülür. Bunun nedeni yalnızca çok sayıda bina yapılması değildir; asıl neden yükseklik kaynağının en fazla binalarda bulunması ve **değişken bir yükseklik kaynağı** ile çalışılmasıdır.

<!-- BELİRSİZ: Yapı türüne göre dağılımın karesi yok; oranlar ve kalem adları yalnız altyazıdan alındı ("demir yolu tespit edilmemiş" ifadesi net değil). -->

### 5.2 Şantiye büyüklüğü

Şantiyedeki çalışan sayısına göre kaza oranları hocanın anlatımına göre şöyledir:

| Çalışan sayısı | Kaza oranı |
|---|---|
| 1-10 | %20,6 |
| 11-50 | %3,6 |
| 50-100 | %2,3 |
| 100-500 | büyük bir değişim yok |
| 500'den fazla | %1,6 |

<!-- BELİRSİZ: Bu tablonun karesi yok; değerler altyazıdan alındı. -->

Hoca, 1-10 kişiden 11-50 kişiye geçildiğinde oranın birden düştüğüne dikkat çekti. Nedeni, iş kazalarındaki en önemli etkenlerden biri olan **tehlikeli davranışlardır**: personel sayısı arttıkça kontrol ve koordinasyon artar, bir organizasyon şeması içinde birim amirleri ortaya çıkar. Proje büyüdükçe kaza oranı azalır. 100-500 aralığında operasyonel yapı değişmediği için oran benzer kalır; 500'den fazla çalışanı olan kurumlarda tekrar düşer. Kurgulanan operasyonel ve hiyerarşik süreçler bu anlamda fayda sağlar.

> **Ders sonrası not:** Hoca 20,6'dan 3,6'ya düşüşü "yedide bir" ve "7 kat" diye ifade etti; $20{,}6 / 3{,}6 \approx 5{,}7$ olduğu için düşüş yaklaşık 5,7 kattır. 3,6'dan 2,3'e düşüş "%33'e yakın" denildi; hesaplanan azalma yaklaşık %36'dır.

### 5.3 Unvana göre dağılım

Slaytta "İncelenen İş Kazalarının, Kazaya Uğrayanların İşyerindeki Unvanlarına Göre Dağılımı" tablosu gösterildi (ekrandan, 00:20:00). Tablonun kaynağı İTÜ İnşaat Mühendisliği kaynaklı bir çalışmadır.

| Unvan | Ölüm sayı | Ölüm % | Yaralanma sayı | Yaralanma % | Toplam sayı | Toplam % |
|---|---|---|---|---|---|---|
| Vasıfsız işçi | 174 | 56,9 | 347 | 50,0 | 521 | 52,1 |
| Usta | 51 | 16,7 | 230 | 33,1 | 281 | 28,1 |
| Çırak | 3 | 1,0 | 15 | 2,2 | 18 | 1,8 |
| Nezaretçi personel | 17 | 5,6 | 21 | 3,0 | 38 | 3,8 |
| İş makinesi operatörü | 13 | 4,2 | 14 | 2,0 | 27 | 2,7 |
| Taşıt şoförü | 17 | 5,6 | 14 | 2,0 | 31 | 3,1 |
| Operatör veya şoför yardımcısı | 7 | 2,3 | 12 | 1,7 | 19 | 1,9 |
| Teknik personel | 13 | 4,2 | 23 | 3,3 | 36 | 3,6 |
| Diğer | 11 | 3,6 | 18 | 2,6 | 29 | 2,9 |
| Toplam | 306 | 100,0 | 694 | 100,0 | 1000 | 100,0 |

Ölüm sütunu python ile kontrol edildi: toplam 306, yüzdeler sayılarla tutarlıdır.

Hoca üç unvanı yorumladı:

- **Vasıfsız işçi (%56,9):** Kontrol ve koordinasyona girmeden, kendini kontrol etmeden, yeterli önlem almadan çalışır ve tehlike algısı gelişmemiştir.
- **Usta (%16,7):** Usta işinde uzmandır; buna rağmen kaza oluyorsa başka bir sorun vardır. Sorun genellikle ustanın kendine güvenmesi ve bu yüzden önlem almadan çalışmasıdır; aşırı özgüven kazaya götürür.
- **Çırak (%1,0):** Çırak cesaretiyle bazen yetkisi olmayan işlere girebildiği için kaza ihtimali ortaya çıkar.

Bu üç kalem toplamı $56{,}9 + 16{,}7 + 1{,}0 = 74{,}6$'dır; hoca da toplamın %74-75'ine birkaç kalemle ulaşılabildiğini söyledi.

## 6. Saha Kontrolü ve İSG Eğitimleri

### 6.1 İSG nerede başlar

> **Hocanın vurgusu:** İş sağlığı ve güvenliği tasarımda başlar, proje kapsamında devam eder, sahada hayat bulur ve asla bitmez. Hiçbir zaman bitmeyen bir döngüdür; sürekli kontrol ve koordinasyon sağlanmalıdır.

### 6.2 Sınır güvenliği ve yetkilendirme

Yapı alanlarında mutlaka **sınır güvenliği** sağlanmalıdır; sınırlar kontrol edilemiyorsa içerideki hiçbir şeyin kontrolünden söz edilemez. Kapı girişleri, yollar ve geçilecek güzergâhlar belli olmalıdır. Kimse "ben bu projede çalışıyorum" deyip izinsiz içeri girememelidir. Bunun için kart sistemi kurulabilir.

Basit bir çözüm de barete yapıştırılan yetki etiketleridir. Örneğin yük asansörünün sorumlusu olan kişinin baretinde asansör yetkisi etiketi bulunur ve asansörü yalnız o kullanır. Vinç kullanacak ya da sapancılık yapacak kişinin baretinde buna ait, yüksekte çalışacak kişinin baretinde yüksekte çalışma belgesine ait bir etiket olur. Kişi bu yetkiye, belgeleri tamsa ve ilgili eğitimi aldıysa sahip olur.

<!-- BELİRSİZ: Altyazıda "Parade üzerine gördüğümüz stickerlar", "bayatın üzerine" geçiyor; bağlamdan baret kastedildiği anlaşılıyor. -->

### 6.3 Eğitim konuları

Hoca daha önce de değinilen **çalışanların İSG eğitimlerinin usul ve esasları hakkındaki yönetmeliği** hatırlattı. Bu yönetmelikte eğitim konuları üç gruptur:

- **Genel konular:** Çalışma mevzuatı, çalışanların yasal hak ve sorumlulukları ve bunlardan doğan hukuki sonuçlar.
- **Teknik konular:** Kimyasal, fiziksel ve ergonomik risk etmenleri, elle kaldırma ve taşıma, parlama ve patlama gibi teknik konular.
- **Sağlık konuları:** Meslek hastalıkları ve bunlardan korunma prensipleri, biyolojik ve psikososyal risk etmenleri, ilk yardım.

### 6.4 Zorunlu ve gerekli eğitimler

Hocanın saydığı **zorunlu eğitimler**:

- Temel iş güvenliği eğitimi
- Mesleki eğitim
- İSG kurulu eğitimi (50'den fazla çalışan varsa kurul kurulması zorunludur)
- Acil durum ekiplerinin oluşturulması ve eğitilmesi
- İlk yardım eğitimi (ilk yardım eğitmeni tarafından)
- Yangın eğitimi
- Yüksekte çalışma eğitimi

**Gerekli eğitimler** ise: beyaz yakaya yönelik eğitim, oryantasyon (işbaşı) eğitimi, çalışan temsilcisi eğitimi, koruma-kurtarma-tahliye eğitimleri, risk analizi ekibi eğitimi, toolbox eğitimi ve kullanılan makine ve ekipmanların eğitimidir.

<!-- BELİRSİZ: Altyazıda "Ağzorlu ekipleri" ve "Yangın Hoca'sı" geçiyor; büyük olasılıkla "acil durum ekipleri" ve "yangın eğitmeni" kastedildi. -->

> **Ek bilgi (derste anlatılmadı):** "Toolbox" eğitimi, işe başlamadan önce sahada ekip düzeyinde birkaç dakikalık kısa güvenlik konuşmasıdır. O günkü işin tehlikeleri ve alınacak önlemler hatırlatılır.

### 6.5 Eğitimin önemi ve hedefi

Slayttaki ifade (ekrandan, 00:25:00): "Eğitimler iş güvenliği profesyonelleri ile çalışanlar arasında etkileşimin başladığı ilk noktadır. Başarılı bir son için etkin bir başlangıç şarttır." Eğitimler online ya da yüz yüze düzenlenebilir ve diğer İSG profesyonelleri ile kurumdaki diğer çalışanlar da sürece katılabilir. Hoca, işin bir kişiden bağımsız olarak bir **sistem kurma** işi olduğunu, sistemi doğru kuran ve yönetenin başarılı olacağını söyledi.

> **Hocanın vurgusu:** Eğitimin ilk hedefi davranış değişikliğidir. Davranış değişikliğine neden olmuyorsa eğitimin anlamı yoktur. Eğitim sahada hayat bulmalı, çalışana ve sisteme değer katmalı ve belgelenebilir olmalıdır.

### 6.6 Öğrenilenlerin hatırlanma oranları

Hocanın aktardığı oranlara göre insanlar:

| Öğrenme biçimi | Hatırlanan oran |
|---|---|
| Okuduklarının | %10 |
| Duyduklarının | %20 |
| Gördüklerinin | %30 |
| Hem görüp hem duyduklarının | %50 |
| Görüp, işitip söylediklerinin | %80 |
| Görüp, işitip söyleyip yaptıklarının | %90 |

<!-- BELİRSİZ: Bu oranların karesi yok; altyazı bozuk ("hem gökühanlıklarının"), son iki satırın ayrımı bağlamdan kuruldu. -->

> **Ek bilgi (derste anlatılmadı):** Bu tür oranlar genellikle "öğrenme piramidi" ya da Edgar Dale'in "deneyim konisi" ile anılır. Bazı kaynaklarda "söylenenler" için %70 verilir; bu oranların bilimsel dayanağı tartışmalıdır ve sezgisel bir yaklaşım olarak kullanılır.

## 7. Piper Alpha Kazası ve İş İzni Sistemi

### 7.1 Olay

Hoca bir örnek vaka ("kısa bir kıssa") anlattı. 6 Temmuz 1988'de Kuzey Denizi'nde, İskoçya'nın doğu kıyısının yaklaşık 100 mil açığındaki **Piper Alpha** petrol platformunda alevlenebilir gaz sızıntısı sonucu bir patlama ve yangın meydana geldi; 167 kişi hayatını kaybetti. Platformun sahibi Occidental grubu tahminen 4 milyar doları aşan bir zarar ve tazminatla karşılaştı. Bunun yanında balıklara ve okyanusa verilen çevre zararı uzun süre devam etti; kaza bölgenin bitki örtüsünü ve canlı popülasyonunu değiştirdi.

### 7.2 Kazanın nedeni

Kazanın temel sebebi, bir kondensat pompasının hizmete alınması sırasında pompa hattının aşağı kısmında bulunması gereken basınç rölyef vanasının bakım için sökülmüş olmasıdır. Vananın söküldüğü yerden sıvılaştırılmış, alevlenebilir gaz basınç altında sızdı.

Slayttaki ifade (ekrandan, 00:30:00): Kazadan sonra yapılan araştırmada, pompayı devreye alan kişilerin kendi yaptıkları faaliyet üzerinde açık, doğrudan ve önemli etkileri olabilecek basınç rölyef vanasının daha önce sökülmüş olduğunun farkında olmadıkları görülmüştür. Kazanın oluşuyla ilgili en büyük faktör olarak Piper Alpha'nın iş izni sisteminin şu alanlardaki yetersizliği bulunmuştur:

- Risk değerlendirmelerinin yetersiz oluşu
- Sistemdeki bilinen eksikliklerin giderilmemiş olması
- İş izni sisteminin uygulamasına yeterli önemin verilmemesi
- İş izni sistemi ile ilgili resmi bir eğitim alınmamış olması
- İş izni sisteminin yeterince denetlenmemesi
- Üst yönetimin iş sağlığı ve güvenliği taahhüdünün yetersizliği

> **Ders sonrası not:** Altyazıda araştırma sonucu "farkında oldukları görülmüş" diye geçiyor; slayttaki doğru ifade "farkında olmadıkları görülmüştür" biçimindedir.

### 7.3 Hocanın anlatımıyla olayın akışı

Hoca olayı şöyle canlandırdı: Bir ekip platformdaki rölyef vanasını söküyor. Hatlar ve vanalar çok büyük olduğu için vinçlerle bağlamak, sökmek ve tekrar monte etmek saatler sürüyor; ekip vanayı sökmüş ama işi henüz bitmemiş. Bu arada vardiya değişiyor ya da başka bir ekip geliyor. Yeni gelen ekip vanaların kapalı ve sistemde akış olmadığını görüyor. Platformda her dakika para demektir; petrol çekiminin sürmesi gerekir. Vananın söküldüğünden habersiz olan ekip sistemi tekrar devreye alıyor; sökülen yerden sızıntı başlıyor, patlama oluyor ve platform tamamen yok oluyor.

Bakıldığında burada çok basit bir yapının uygulanmadığı görülür: **iş izni sistemi**. Nerede, kim çalışıyor, ne yapıyor, iş nasıl ilerliyor; bunun kayıt altında işlemesi gerekirdi. Ayrıca etiketleme-kilitleme sistemi de doğru uygulanmamıştır.

Hoca ayrıca Health and Safety Executive (HSE) tarafından yapılan bir araştırmaya göre kimya sanayisinde meydana gelen kazaların üçte birinin bakım sırasında ve iş izni sisteminin yokluğu ya da eksikliği nedeniyle olduğunu aktardı. Demek ki iş izni sistemi hayati önem taşır.

### 7.4 İş izni sistemi nasıl kurulur

Hocanın anlattığı ilkeler:

- Son kullanıcının ya da uygulayıcının kontrolü ve denetimi dışında herhangi bir hattın devreye alınmasını ve bir problemin çıkmasını engellemek amaçlanır.
- İş izni sistemi risk analizi sistemiyle entegre edilir; her işe başlamadan önce işe özel risk analizi yapılarak sahada en doğru çalışma usulü uygulanır.
- Yapılacak çalışmalardan etkilenebilecek diğer çalışanlara önceden bildirim yapılır, kontrol ve koordinasyon sağlanır. Gerekirse işe özel eğitimler düzenlenir.
- Yapılacak işin niteliği, nasıl yapılacağı, hangi tekniklerin uygulanacağı, hangi malzeme ve iş ekipmanlarının kullanılacağı konusunda bilgilendirme yapılır.

<!-- BELİRSİZ: 00:32:21-00:32:36 arasında altyazıda boşluk var; iş izni sisteminin kurulmasına dair ilk madde eksik olabilir. -->

### 7.5 Örnek iş izni akışı

Hocanın anlattığı örnek akış (yapı projesinde):

```text
1. İşi yapacak yapım birimi iş için dosya hazırlar ve yapı birim amirine sunar;
   yapım metodunu ve kullanacağı malzemeleri bildirir.
2. Yapım yöntemleri ve metotları incelenir; teknik birim, iş güvenliği birimi
   ve iş şefleri onaylar.
3. Yapı birimi, metot onayına dayanarak işe başlamak için izin talep eder.
4. İş izni, birim amirinin onayından sonra onaylanır.
5. İSG birimi çalışma yerini yerinde inceler, risk analizi yapar, gerekirse
   ek önlem aldırır ve risk analizinin bir kopyasını çalışma yerine bırakır.
6. İSG biriminin onayından sonra işe başlanır.
7. İş bitiminde İSG birimine haber verilir.
```

<!-- BELİRSİZ: Bu akışın karesi yok; adımlar bozuk altyazıdan kuruldu. -->

### 7.6 Tanım

İş izni sistemi, özellikle birden fazla ekibin ya da kalabalık ekiplerin bir arada bulunduğu süreçlerde, proses güvenliğinde ve hatlarda uygulanması gereken bir yapıdır. Yüksekte çalışma, kapalı alanda çalışma gibi risklerin bulunduğu yerlerdeki özel çalışmaların önceden izin alınarak, koordinasyonu yapılarak ve tüm birimlere bildirilerek uygulanmasını sağlar.

## 8. Etiketleme-Kilitleme (LOTO) Sistemi

Etiketleme-kilitleme sistemi Türkiye'de kısaca "EKET" (etiketleme-kitleme) diye de anılır; uluslararası adı **LOTO**'dur.

> **Ders sonrası not:** Hoca LOTO'nun açılımını "look out, take out" diye söyledi; doğrusu "Lockout/Tagout" (kilitleme/etiketleme) biçimindedir.

İşleyiş şöyledir: Hat üzerinde çalışacak kişi hattı kilitler ve üzerine etiket olarak kendi adını ve orada yaptığı çalışmayı yazar. Hat gerçek bir anahtarlı kilitle kilitlendiği için, o kişi kilidi açmadıkça hattı kimse devreye alamaz. Böylece kişi hat üzerinde çalıştığı süre boyunca güvenle çalışır. Aynı uygulama mekanik tesisatta, borularda ve vanalarda, elektrik tesisatında, kablo hatlarında ve enerji hatlarının transferinde de geçerlidir; etiket ve kilitler panolara ya da vanalara takılır.

Uzun bir hatta birden fazla kişi çalışıyorsa herkes kendi kilidini ayrı ayrı takar. Hat, ancak tüm çalışanlar işini bitirip güvende olduğundan emin olunduktan sonra tekrar devreye alınabilir.

Hoca Türkiye'den de benzer bir senaryo anlattı: Uzun bir elektrik hattında çalışmaya bir ekip gönderilir. Arkadan gelen başka bir ekip hattın kapalı olduğunu görür, kimseye sormadan ve araştırmadan hattı tekrar devreye alır; hattın ucunda çalışan ekip hayatını kaybeder. Bu ve benzeri olaylar maalesef sık yaşanmaktadır.

> **Hocanın vurgusu:** Etiketleme-kilitleme sistemlerinin otomasyonu ve uzaktan izlenebilir hale getirilmesi gibi uygulamalar teknolojiyle birlikte gelişen, ölümleri önleyebilecek yapılardır ve bilgisayar mühendislerinin katkı verebileceği alanlardır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:05:00): Bir yapı projesinde iş sağlığı ve güvenliğine nereden başlanmalıdır?

> **Cevap (derste verildi):** Geçmiş kaza verilerinin sektöre özel analiziyle başlanır. Geçmişteki kazalar gelecekteki hatalara işaret eder; istatistiğe göre en yüksek orana sahip kök tehlikelere öncelik verilerek kısıtlı zaman ve imkân en verimli biçimde kullanılır. Örneğin yükseklik tehlikesi giderilirse insan ve malzeme düşmesi birlikte önlenir ve ölümlü kazaların %53,4'ü ortadan kalkar.

**Soru 2** (derste sözlü, 00:19:51): Ölümlü kazalarda vasıfsız işçilerin oranı neden bu kadar yüksektir? Ustalarda ve çıraklarda kazanın nedeni nedir?

> **Cevap (derste verildi):** Vasıfsız işçi kontrol ve koordinasyona girmeden, yeterli önlem almadan ve tehlike algısı gelişmeden çalışır. Usta işinde uzman olduğu için kendine güvenir ve önlem almadan çalışır. Çırak ise cesaretle yetkisi olmayan işlere girebilir.

**Soru 3** (derste sözlü, 00:17:02): Yapı kazaları neden en çok bina inşaatlarında görülür?

> **Cevap (derste verildi):** Yalnız çok bina yapıldığı için değil; asıl neden yükseklik kaynağının en fazla binalarda bulunması ve değişken bir yükseklik kaynağı ile çalışılmasıdır.

**Soru 4** (ekrandan, 00:30:00): Piper Alpha kazasının oluşunda en büyük faktör olarak hangi sistemin, hangi alanlardaki yetersizliği bulunmuştur?

> **Cevap (derste verildi):** İş izni sisteminin yetersizliği: risk değerlendirmelerinin yetersizliği, bilinen eksikliklerin giderilmemesi, iş izni uygulamasına yeterli önem verilmemesi, iş izniyle ilgili resmi eğitim alınmamış olması, sistemin yeterince denetlenmemesi ve üst yönetimin İSG taahhüdünün yetersizliği.

## Dersin Toparlaması

Bu derste bir yapı projesinde İSG çalışmasının geçmiş kaza verisinin analiziyle başladığı görüldü. Yapı şantiyelerindeki 5239 kazalık veri, tehlike-risk ayrımıyla birlikte okunduğunda yükseklik, elektrik, yapı makineleri ve şantiye içi trafik gibi birkaç kök tehlikeye öncelik vermenin ölümlü kazaların büyük kısmını önleyebileceği ortaya kondu. Türkiye-Avrupa karşılaştırması mesleki yeterlilik denetiminin, şantiye büyüklüğü verisi kontrol ve koordinasyonun, unvan dağılımı ise insan davranışının kazadaki rolünü gösterdi.

Dersin ikinci yarısında sınır güvenliği ve yetkilendirme, yönetmelikteki genel-teknik-sağlık eğitim konuları, zorunlu ve gerekli eğitimler ile eğitimin davranış değişikliği hedefi anlatıldı. Son olarak Piper Alpha kazası üzerinden iş izni sisteminin ve etiketleme-kilitleme (LOTO) sisteminin, birden fazla ekibin aynı hatta çalıştığı durumlarda neden hayati olduğu açıklandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
