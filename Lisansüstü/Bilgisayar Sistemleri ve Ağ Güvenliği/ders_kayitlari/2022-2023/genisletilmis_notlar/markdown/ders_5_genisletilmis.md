# Ders 5 Genişletilmiş Notu: Fiziksel ve Altyapı Güvenliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: yönetim sorunları dizisindeki yeri
- 2. Mantıksal, fiziksel ve bina güvenliği
- 3. Fiziksel güvenliğin iki tamamlayıcı gereksinimi
- 4. Çevresel tehditler
- 5. Teknik tehditler
- 6. İnsan kaynaklı tehditler
- 7. Önleme ve etki azaltma yöntemleri
- 8. Fiziksel güvenlik ihlallerinden kurtarma
- 9. Fiziksel ve mantıksal güvenlik entegrasyonu
- 10. Korunan alanlar için güvenlik ve kontrol dereceleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Giriş: yönetim sorunları dizisindeki yeri

Ders, bilişim güvenliğinin yönetim bağlamında ele alındığı altı konuluk dizinin üçüncü konusudur. İçerik slaytında dizinin tamamı şöyle listelenir (ekrandan, 00:15:00):

- 2.1 BT Güvenlik Yönetimi ve Risk Değerlendirmesi
- 2.2 BT Güvenlik Kontrolleri, Planları ve Prosedürleri
- 2.3 Fiziksel ve Altyapı Güvenliği (bu dersin konusu)
- 2.4 İnsan Kaynakları Güvenliği
- 2.5 Güvenlik Denetimi
- 2.6 Bilişim Güvenliğinde Yasal ve Etik Hususlar

Önceki derslerde güvenlik yönetimi ve risk değerlendirmesi yapılmış, ardından bu değerlendirme sonucunda riski en aza indirmek için oluşturulan güvenlik kontrolleri, planları ve prosedürleri anlatılmıştı. Hoca bu derse şu gözlemle girer: bilişim sistemi güvenliği yalnız lojik (mantıksal) tabandaki güvenlikten ibaret değildir. Ağ için firewall, IDS ve IPS kurulabilir, parolalar için politikalar belirlenebilir, kimlik doğrulama için kartlar, biyometrik kartlar ya da parmak izi kullanılabilir. Lojik tarafta her şey sorunsuz çalışıyor olabilir. Ama biri sistem odasına girip diski söküp götürürse ya da yangın çıkarsa bütün lojik sistem çöker. Bu yüzden bütüncül bir güvenlikten söz edebilmek için mantıksal güvenlik yeterli değildir; fiziksel ve altyapı güvenliği de gereklidir.

Dersin akışı: fiziksel ve altyapı güvenliğine genel bakış, fiziksel güvenlik tehditlerinin tanımlanması, bu tehditleri önleme ya da önlenemiyorsa etkisini azaltma tedbirleri, fiziksel güvenlik ihlallerinden kurtarma ve son olarak fiziksel ile mantıksal güvenliğin entegrasyonu.

## 2. Mantıksal, fiziksel ve bina güvenliği

Slayt üç kavramı yan yana tanımlar (ekrandan, 00:20:00).

### 2.1 Mantıksal güvenlik

Mantıksal güvenlik, bilgisayar tabanlı verileri yazılım tabanlı ve iletişim tabanlı tehditlerden korur. Bir sistemdeki verinin, yazılımların ve ağın korunması bu kapsamdadır. Hoca yazılımların da birer hizmet sunduğunu vurgular: bir ERP yazılımı ya da finans yazılımı kurum için hizmettir ve bunların korunması mantıksal güvenlik sorunudur.

### 2.2 Fiziksel güvenlik

Fiziksel güvenliğe altyapı güvenliği de denir. Slayttaki maddeler:

- Altyapı güvenliği de denir.
- Veri içeren bilgi sistemlerini ve bu sistemleri kullanan, işleten ve bakımını yapan kişileri korur.
- Mantıksal güvenliği tehlikeye atabilecek her türlü fiziksel erişimi veya izinsiz girişi önlemelidir.

Hoca burada önemli bir ayrıntının altını çizer: altyapı güvenliği yalnız sunucuların, router'ların, firewall cihazlarının, fiber optik ve bakır kabloların, kablosuz ağ cihazlarının fiziksel olarak korunması değildir; bunları kullanan ve bakımını yapan kişilerin korunması da bu kavramın içindedir.

### 2.3 Bina güvenliği

Bina güvenliği, kurumsal veya tesis güvenliği olarak da bilinir. "Bina" derken tek bir bina değil, bir kampüs ya da bir tesis bütünü kastedilebilir. Slayttaki maddeler:

- Tüm bir alan, tesis veya bina(lar) içindeki insanları ve mülkü korur ve genellikle yasalar, yönetmelikler ve güvene dayalı yükümlülükler tarafından gerekli kılınır.
- Çevre güvenliği, erişim kontrolü, duman ve yangın algılama, yangın söndürme, bazı çevre koruma ve genellikle gözetim sistemleri, alarmlar ve güvenlik personeli içerir.

Hoca örnek olarak binanın sağlamlığını, yangın ihbar ve güvenlik sistemlerini sayar; bunların her biri kendine özgü yasa ve yönetmeliklere göre kurulmalıdır. Gözetim sistemleri derken kapalı devre kamera sistemleri kastedilir. Sonuç olarak fiziksel güvenlik, fiziksel ve mantıksal sisteme zarar verebilecek her türlü bileşeni içine alan bütünleşik bir yapıdır.

## 3. Fiziksel güvenliğin iki tamamlayıcı gereksinimi

Genel bir tanımla fiziksel güvenlik, bilgilerin depolanmasını ve işlenmesini destekleyen varlıkların korunmasıdır. İki tamamlayıcı gereksinimi vardır:

- **Fiziksel altyapının zarar görmesini önlemek.** Fiziksel altyapı; bilgi sistemi donanımını, fiziksel tesisi (bina), elektrik sistemini, destek tesislerini ve destek ile kullanıcı personelini içerir. Hoca personelin de bu listede olmasının nedenini açıklar: sistemi kullanan ya da koruyan personel zarar görürse fiziksel sistemin zarar görmesi de mümkün hale gelir.
- **Fiziksel altyapının kötüye kullanılmasını önlemek.** Korunan bilginin kötüye kullanılmasına ya da zarar görmesine yol açabilecek biçimde altyapının kötüye kullanılması da engellenmelidir. Örnekler: vandalizm, yağma, ekipman hırsızlığı, kopyalama (örneğin içinde yedeklerin bulunduğu bir yedekleme biriminin kopyalanması), hizmet hırsızlığı ve alana yetkisiz giriş.

## 4. Çevresel tehditler

Bilgi sistemlerini tehdit eden fiziksel olay ve durumlar üç kategoride toplanır: çevresel tehditler, teknik tehditler ve insan kaynaklı tehditler. Bunların hepsi fiziksel altyapıya zarar verebilecek ya da mantıksal sistemin çalışmasını engelleyebilecek durumlardır. Çevresel tehditler denince ilk akla gelen doğal afetlerdir.

### 4.1 Doğal afetlerin özellikleri

Güvenlik politikasında her doğal afet için bir uyarı sistemi, tahliye kararı ve etkinin ne kadar süreceği düşünülmelidir. Slayttaki tablo (ekrandan, 00:25:00):

| Afet | Uyarı | Tahliye | Süresi |
|---|---|---|---|
| Tornado | Potansiyelin önceden uyarısı; tesise özel değil | Tesiste kal | Kısa ama yoğun |
| Hurricane | Önemli ön uyarı | Tahliye gerekebilir | Birkaç saatten birkaç güne |
| Deprem | Uyarı yok | Tahliye edilemeyebilir | Kısa süre; devam eden artçı sarsıntı tehdidi |
| Buz fırtınası/Blizzard | Genellikle birkaç gün önce uyarısı beklenir | Tahliye edilemeyebilir | Birkaç gün sürebilir |
| Şimşek/Yıldırım | Sensörler birkaç dakika önce uyarı verebilir | Tahliye gerekebilir | Kısa ama tekrarlayabilir |
| Sel/Taşkın | Genellikle birkaç gün önce uyarı beklenir | Tahliye edilemeyebilir | Tesis uzun süre izole edilebilir |

Tablonun altındaki not: bir tornado, yolu boyunca dar bir bantta hurricane gücünü aşan rüzgarlar üretebilir.

Hocanın tablo üzerindeki açıklamaları:

- **Tornado ve hurricane:** Meteorolojiden alınan bilgilerle personel önceden uyarılabilir. Hoca tornadonun daha düşük etkili olduğunu, uygun korunak varsa tesiste kalınabileceğini söyler. Hurricane'de rüzgar hızı daha yüksek olduğu ve binayı yıkabileceği için tahliye gerekebilir; etkisi hurricane'in durumuna bağlı olarak birkaç saatten birkaç güne kadar uzayabilir.
- **Deprem:** Uyarısı yoktur. Hoca burada Kahramanmaraş depremini örnek verir: yaklaşık 11 ili etkilemiş, yaklaşık 250 kilometrelik fay hattı boyunca ciddi can ve mal kaybına yol açmıştır. Uyarı olmadığı için tahliye etmeye fırsat bile bulunamayabilir. Sarsıntı, büyüklüğe bağlı olarak birkaç saniye ile birkaç dakika sürer; ama ardından gelen artçı sarsıntılar da ilk depremin büyüklüğüne bağlı olarak yıkıcı olabilir.
- **Buz fırtınası:** Meteorolojiden birkaç gün önce uyarı alınabilir. Isıtma sistemi varsa tahliye gerekmeyebilir; etkisi birkaç gün sürebilir.
- **Şimşek/yıldırım:** Yıldırım sensörleri birkaç dakika önce uyarı verebilir. Uygun izolasyon yapıldıysa tahliye gerekmeyebilir. Etkisi kısadır ama tekrarlanabilir.
- **Sel/taşkın:** Çok ve sürekli yağan yağmurun sonucudur; genellikle birkaç gün önce uyarı beklenir. Tahliye kararı tesisin konumuna bağlıdır: tesis bir dere yatağındaysa tahliye gerekebilir, birkaç kat yukarıdaysa ya da yüksek bir binadaysa gerekmeyebilir. Her durumda mantıksal sistem selden etkilenmeyecek şekilde izole edilmelidir.

> **Ders sonrası not:** Hoca tablonun kaynağını "Amerikan itfaiye kuruluşu" diye andı. Tablodaki "Tahliye" sütunu için slayttaki ifadeler esas alındı; hocanın sözlü açıklamaları (örneğin buz fırtınasında ve yıldırımda tahliye gerekmeyebileceği) slayttaki ifadelerle tam örtüşmüyor.

### 4.2 Fujita tornado yoğunluk ölçeği

Tornado şiddetli bir rüzgardır. Tesiste kalıp kalmama ve uyarı mekanizmalarının kurulması için tornadonun şiddetine göre sınıflanması gerekir. Fujita ölçeği tornadoları F0'dan F5'e kadar altı kategoriye ayırır; her kategori için rüzgar hızı ve muhtemel hasar verilir (ekrandan, 00:30:00):

| Kategori | Rüzgar hızı | Hasar |
|---|---|---|
| F0 | 0-72 mil/sa, 64-116 km/sa | Hafif hasar. Bacalarda bazı hasarlar oluşur; ağaç dalları kırılır; sığ köklü ağaçlar devrilir; tabelalar hasar görür. |
| F1 | 73-112 mil/sa, 117-180 km/sa | Orta hasar. Tornado rüzgar hızının başlangıcıdır; çatı yüzeyleri soyulur; mobil evler temelden sökülür veya devrilir; hareketli arabalar yollardan savrulur. |
| F2 | 113-157 mil/sa, 181-252 km/sa | Önemli hasar. Evlerin çatıları sökülür; mobil evler yıkılır; yük vagonları savrulur; büyük ağaçlar devrilir veya kökünden sökülür; hafif nesneler uçuşur. |
| F3 | 158-206 mil/sa, 253-332 km/sa | Ciddi hasar. İyi yapılmış evlerin çatıları ve bazı duvarları yıkılır; trenler devrilir; ormandaki ağaçların çoğu kökünden sökülür; ağır arabalar yerden kaldırılır ve fırlatılır. |
| F4 | 207-260 mil/sa, 333-418 km/sa | Yıkıcı hasar. İyi inşa edilmiş evler tesviye edilir; zayıf temelli yapılar biraz uzağa savrulur; arabalar fırlatılır ve büyük cisimler uçuşur. |
| F5 | 261-318 mil/sa, 419-512 km/sa | İnanılmaz hasar. Güçlü çerçeve evler temelden kaldırılır ve hatırı sayılır bir mesafeye savrularak parçalanır; otomobil boyutunda cisimler havada 100 metreden fazla füze gibi uçar; ağaçlar soyulur. |

Hoca hasarları somutlaştırır: F0'daki yaklaşık 120 km/sa'in altındaki bir rüzgar bacaları yıkar, zayıf dalları kırar, sığ köklü ağaçları devirir, asılı tabelalara ve direklere zarar verir. F1'den itibaren fırtına artık tornado olarak adlandırılır. F2'de bir önceki kategoride yalnız soyulan çatılar tamamen sökülür, ağır yüklü tren vagonları raylarından çıkabilir. F5'te rüzgar o kadar hızlıdır ki ağaçların kabuklarını bile soyar.

> **Ders sonrası not:** Slaytta hız birimleri "mil/s" ve "km/s" diye yazılmış; doğrusu saatte mil ve saatte kilometredir (mil/sa, km/sa). Tablodaki mil ve km değerleri birbirine 1 mil ≈ 1,609 km ile tutarlıdır (python ile denetlendi; örneğin 72 mil/sa ≈ 116 km/sa, 318 mil/sa ≈ 512 km/sa). Hocanın sözlü verdiği bazı sınırlar (F4 için "330-420", F5 için "400-520") yuvarlanmıştır; tablodaki değerler slayttandır.

### 4.3 Saffir-Simpson hurricane ölçeği

Hurricane'ler Saffir-Simpson ölçeğiyle kategori 1'den 5'e kadar sınıflanır. Bu ölçek rüzgar hızının yanı sıra denizde oluşturduğu dalga (kabarma) yüksekliğini de dikkate alır. Hocanın sözlü verdiği değerler:

- Kategori 1: hasar minimum düzeydedir.
- Kategori 2: rüzgar hızı yaklaşık 150-177 km/sa; yaklaşık 3 metreye kadar dalga oluşturabilir; potansiyel hasar orta düzeydedir. Hoca slayttaki kategori numarasının yanlış yazıldığını, bu satırın 2 olması gerektiğini söyledi.
- Kategori 3: rüzgar hızı kabaca 180 ile 200 küsur km/sa arası; 4 metreye kadar dalgalar; daha geniş alanları kapsayan hasar.
- Kategori 5: 18 fitten (yaklaşık 5 metreden) büyük dalgalar; sonucu felakettir: can kaybı, büyük binalarda hasar, taşkınlar, büyük araçların sürüklenmesi.

<!-- BELİRSİZ: Saffir-Simpson tablosunun slaytı karelerde yok; kategori 1 ve 4'ün değerleri altyazıda yok, kategori 2-3 değerleri yalnız altyazıdan alındı. 18 ft ≈ 5,5 m (python ile denetlendi). -->

### 4.4 Sıcaklık ve yangın

Bilişim kaynaklarının hangi sıcaklıkta zarar görmeye başladığı, özellikle yangın ve aşırı sıcak durumları için önemlidir. Slayttaki tablo (ekrandan, 00:35:00):

| Bileşen veya ortam (medya) | Hasarın başlayabileceği sürekli ortam sıcaklığı |
|---|---|
| Floppy diskler ve manyetik kasetler vb. | 38 °C (100 °F) |
| Optik diskler | 49 °C (120 °F) |
| Hard diskler | 66 °C (150 °F) |
| Bilgisayar bileşenleri | 79 °C (175 °F) |
| Tehlikeli voltaj taşıyan teller üzerinde termoplastik yalıtım | 125 °C (257 °F) |
| Kağıt ürünleri | 177 °C (350 °F) |

Kaynak: National Fire Protection Association (Amerikan Ulusal Yangından Korunma Birliği).

Hocanın açıklamaları:

- Manyetik ortamlar fiziksel olarak hasar görmüş gibi görünmeyebilir; ama manyetik özelliklerini kaybettikleri için veriye dijital olarak erişilemez hale gelir.
- Bilgisayar bileşenlerinde yalıtım malzemeleri deforme olmaya başlar; çipler formunu ve işlevini kaybeder.
- Şebeke telleri gibi plastik yalıtımlı teller yaklaşık 125 °C'de formunu kaybeder; yalıtım eridiği ya da deforme olduğu için düzgün iletim mümkün olmaz.
- Kağıt yaklaşık 177 °C'de yanar. Bu, kağıt tabanlı kondansatörler gibi selüloz içeren bileşenler ve kağıt dokümanlar için de önemlidir.

> **Ders sonrası not:** Hoca bazı değerleri yuvarlayarak söyledi (optik disk "50", hard disk "70", bileşenler "80" derece). Tablodaki değerler slayttandır. °C ve °F değerleri birbirine tutarlıdır (python ile denetlendi; örneğin 125 °C = 257 °F).

Yangının verdiği zarar, ulaştığı sıcaklık ve süresiyle artar. Hoca, yangın süresi uzadıkça yangının çekirdeğindeki (kor) sıcaklığın yaklaşık 2300 °C'ye kadar çıkabileceğini söyler. Ardından bazı malzemelerin dayanım sıcaklıklarını sözlü olarak verir:

- Yaklaşık 260 °C: ahşap tutuşur (orman yangınlarında dalların sürtünmesiyle artan sıcaklığın tutuşturması örneğiyle).
- 326 °C: kurşun erir.
- 415 °C: çinko erir.
- 480 °C: hocanın ifadesiyle "yalıtılmış bir çelik malzeme" bükülmeye ve içeriğini açığa çıkarmaya başlar.
- Demir erir (sıcaklık değeri altyazıda yok).
- 1410 °C: sert çelik erir.

<!-- BELİRSİZ: Bu sıcaklık etkileri tablosunun slaytı karelerde yok; değerler altyazıdan, bazı satırlar (demirin ve muhtemelen alüminyumun erime sıcaklığı) altyazıda eksik. -->

> **Ek bilgi (derste anlatılmadı):** Bu tablonun kaynağı büyük olasılıkla bilgisayar güvenliği ders kitaplarındaki "sıcaklık etkileri" tablosudur; orada 480 °C satırı büyük olasılıkla "yalıtılmamış çelik dosya dolabının bükülüp açılması" olarak geçer ve aradaki satırlarda alüminyumun ve dökme demirin erime sıcaklıkları yer alır.

Hoca bu değerlerin neden önemli olduğunu şöyle bağlar: altyapı güvenliği düşünülürken binanın çelik konstrüksiyonu, kapı ve pencere doğramalarının alüminyum olup olmadığı, cihazların içindeki bakır, kurşun ve lehim gibi malzemelerin hangi sıcaklıkta bozulacağı bilinmelidir. Yangın uzadıkça kor sıcaklığı arttığı için alev sistem odasına ulaşmasa bile sıcaklık fiziksel bileşenlere ciddi zarar verir. Bir önceki tabloya bakıldığında manyetik ortamlar çok daha düşük sıcaklıklarda veriyi kaybetmeye başlar.

### 4.5 Su hasarı

Rüzgar ve yangından sonra su gelir. Slayttaki maddeler (ekrandan, 00:40:00):

- Birincil tehlike elektriksel kısa devredir.
- Su borusu, hattaki bir arızadan veya donmadan patlayabilir.
- Sprinkler sistemleri (yangın söndürme sistemleri) yanlışlıkla devreye girebilir.
- Sel suyu balçık bırakır ve katı parça sürükler.
- İki kat yukarıdan gelen suyun tehlike oluşturmaması için gerekli özen gösterilmelidir.

Hoca su hasarı için illa sel ya da baskın olmasının gerekmediğini vurgular: yakından geçen bir su borusu deformasyon ya da donma nedeniyle patlayabilir; yangın söndürme sistemi elektronik bir arızayla, kasten ya da yanlışlıkla çalışıp tavandan su püskürtebilir. Su sel yoluyla geldiyse suyun kendi etkisine ek olarak balçık ve sürüklediği katı atıklar da hasar verir. Üst katlardan şelale gibi akan su da önlem gerektirir.

### 4.6 Kimyasal, radyolojik ve biyolojik tehditler

Bu tehditler kasıtlı bir saldırgandan ya da kazara bir salınımdan kaynaklanabilir: kazara kimyasal saçılma ya da deşarj, havalandırma sistemindeki sorunlar, açık pencereler; radyasyon söz konusuysa çevre duvarlardan yayılma. Sel de beraberinde biyolojik ve kimyasal kirleticiler getirebilir.

### 4.7 Toz ve istila

Toz genellikle gözden kaçan bir tehdittir. Bilgisayar fanları ve ortam havalandırma fanları gibi dönen, hareketli parçaları olumsuz etkiler; bunları çalışamaz ya da tam işlevli çalışamaz hale getirir ve sonunda sistemin zarar görmesine yol açar. Havalandırmanın çalışmaması ortam sıcaklığının düşürülememesine ve bileşenlerin ısınarak zarar görmesine neden olur. Toz; fırtınanın getirdiği enkazdan, bir toz bulutundan ya da bina içindeki inşaat veya bakım çalışmalarından kaynaklanabilir.

İstila çok çeşitli canlılardan kaynaklanır: haşereler, kemirgenler, böcekler, mikroorganizmalar. Yüksek nem koşulları küflenmeye yol açar; nem ve küf yalıtkan ortamların iletken hale gelmesine ve sistemin zarar görmesine neden olur.

## 5. Teknik tehditler

Slayttaki içerik (ekrandan, 00:45:00):

- Ekipmanı çalıştırmak için elektrik gücü gereklidir.
  - Güç hizmeti sorunları:
    - Düşük voltaj: düşüklük/kesintiler, hizmeti kesintiye uğratıyor.
    - Aşırı voltaj: dalgalanmalar/arızalar/parlama, çipleri yok edebilir.
    - Gürültü: elektrik hatlarında, cihazın çalışmasını engelleyebilir.
- Elektromanyetik girişim (EMI):
  - Güç kaynağı hattı, motorlar, fanlar, ağır ekipman, diğer bilgisayarlar, cep telefonları, mikrodalga röle antenleri ve yakındaki radyo istasyonları gürültü üretir.
  - Gürültü, elektrik hatlarının yanı sıra boşlukta da iletilebilir.
  - Bilgisayarlarda aralıklı sorunlara neden olabilir.

Hoca düşük voltajda sistemin çalışmayacağını ve hizmetin aksayacağını, aşırı voltaj ve dalgalanmaların özellikle yüksek gerilimli cihazlarda parlamaya, arızaya, yanmaya ve çiplerde bozulmaya yol açabileceğini anlatır. Gürültü, besleme voltajı üzerindeki yüksek frekanslı dalgalanmalardır. Bilgisayar sistemleri DC voltajla çalışsa da bu gürültüler iletim hatlarında endüktif gerilim oluşmasına ve kapasitif elemanların hatalı çalışmasına, sonuçta bütün sistemin arızalanmasına neden olabilir. Elektromanyetik girişim ise bilişim sisteminin yakınındaki güç hatları, motorlar, jeneratörler, fanlar ve ağır ekipmanla, cep telefonları, mikrodalga röle antenleri ya da yakındaki radyo istasyonlarının yaydığı elektromanyetik dalgaların sistemi etkilemesidir. Bu gürültü hem elektrik hatları üzerinden hem de elektromanyetik dalga olarak boşlukta ilerler ve gücüne bağlı olarak bilgisayarlarda sorun çıkarır.

## 6. İnsan kaynaklı tehditler

İnsan kaynaklı tehditler daha az öngörülebilirdir. Doğal afetler için meteorolojik veriler, toz için bina içi tadilat bilgisi, elektromanyetik girişim için izolasyon gibi önlemler planlanabilir; ama insan kaynaklı tehditler önleme yöntemlerini aşmak üzere tasarlanabilir ve başa çıkılması zordur. Hoca bunun nedenini şöyle açıklar: tehdidi önlemek için görevlendirilen kişi bizzat tehdit olabilir. Bir güvenlik görevlisi güvenlik zafiyetine yol açabilir; bilgisayar sistemlerinin bakımından sorumlu bir teknik eleman sisteme zarar veren kişi olabilir.

İnsan kaynaklı tehditlerin yol açabilecekleri:

- **Yetkisiz fiziksel erişim:** Bilgi varlıkları genellikle kısıtlı alanlarda bulunur. Bu alanlara yetkisiz erişim hırsızlığa, vandalizme ya da kötüye kullanım gibi başka tehditlere yol açabilir.
- **Ekipman ya da veri hırsızlığı.**
- **Gizli dinleme ve telefon dinleme.**
- **Vandalizm:** ekipmana ya da veriye zarar verme.
- **Kaynakların kötüye kullanımı.**

Bu tehditler kurumun içinden gelebileceği gibi, yetkisiz erişim kazanıp kampüse ya da sistem odasına fiziksel olarak girebilmiş dışarıdan biri tarafından da oluşturulabilir.

## 7. Önleme ve etki azaltma yöntemleri

### 7.1 Genel önlemler

Slayttaki içerik (ekrandan, 00:50:00):

- İlk önleme önlemi, bulut bilişimin kullanılmasıdır.
- Uygun olmayan sıcaklık ve nem: çevre kontrol ekipmanı, güç kaynağı.
- Ateş ve duman: alarmlar, önleyici tedbirler, yangın azaltma; duman dedektörleri, sigara içilmez.
- Su: hatları, ekipman konumunu, kesme sensörlerini yönet.
- Diğer tehditler: uygun teknik karşı önlemler, toz girişini sınırlama, haşere kontrolü.

Hoca bulut bilişimi en basit önlem olarak açıklar: tehdidi oluşturabilecek kaynağı ortadan kaldırmak, yani bilişim altyapısını komple buluta taşımak ("put in the cloud"). Sıcaklık ve nem için iklimlendirme tedbirleri, güç kaynağı için regülatörler, online UPS'ler ya da jeneratörler kullanılabilir. Ateş ve duman için alarmlar, duman ve sıcaklık dedektörleri kurulur, ateşle yaklaşılmaması ve sigara içilmemesi sağlanır. Su kaçaklarına karşı hatlar uygun düzenlenir, uygun ekipman kullanılır ve anlık kesme sensörleri kurulup yönetilir. Dışarıdan gelen tehditlere karşı kamera sistemleri, tel çitler, kartlı sistemler, toz girişini sınırlama ve haşereye karşı ilaçlama sayılabilir.

### 7.2 Teknik tehditlere karşı

- Her kritik ekipman için kesintisiz güç kaynağı (UPS) kullanmak, teknik tehditlere karşı ilk akla gelen yöntemdir.
- Kritik ekipman için bir acil durum güç kaynağı konulabilir. UPS kısa süreli dalgalanma ve kesintileri karşılar; uzun süreli kesintilerde jeneratör gibi bir kaynak gerekir.
- Elektromanyetik girişimle başa çıkmak için ekranlama ve filtre kombinasyonu kullanılır.

### 7.3 İnsan kaynaklı fiziksel tehditlere karşı

- Bina girişini kısıtlamak.
- Kontrollü alanları korumak için devriye gezen güvenlik personeli bulundurmak.
- Kapılara kilit koymak; duvar ya da başka mekanizmalarla perdeleme yapmak.
- Hareketli kaynaklar için kapalı devre güvenlik (kamera) sistemi kurmak.
- Güvenlik birimi tarafından denetlenen akıllı kartlar kullanmak.
- Hırsızlığa karşı hırsızlık alarmları kullanmak.
- Kayıt yapan ve gerçek zamanlı uzaktan görüntüleme ve algılama sistemleri kullanmak: kamera sistemleri, hareket dedektörleri, sıcaklık dedektörleri.

## 8. Fiziksel güvenlik ihlallerinden kurtarma

Fiziksel bir tehdit gerçekleştiğinde kurtarma devreye girer. Slayttaki içerik (ekrandan, 00:55:00):

- Kurtarmanın en temel unsuru yedeklemedir.
  - Veri kaybından kurtarma sağlar.
  - İdeal olarak, tüm önemli veriler saha dışında bulunmalı ve mümkün olduğunca sık güncellenmelidir.
  - Toplu şifreli uzaktan yedekleme kullanılabilir.
  - Kritik durumlar için, operasyonu anında devralmaya hazır bir uzak sıcak site oluşturulabilir.
- Fiziksel ekipman hasar kurtarma
  - Hasarın ve temizlemenin doğasına bağlıdır.
  - Olağanüstü durum kurtarma uzmanlarına ihtiyaç duyabilir.

Hoca yedeklemenin en azından bir önceki yedeğe dönmeyi sağladığını söyler. İdeal olan, verilerin saha dışında canlı olarak (sürekli eşlenerek) yedeklenmesi ya da en azından sık aralıklarla kampüs dışında başka bir bölgede tutulmasıdır. Sistemin ya da verinin yedeğini alıp aynı makinede tutmak yedekleme sayılmaz, çünkü aynı fiziksel olaydan etkilenir. Uzaktan yedekleme şifreli kanallar üzerinden, örneğin SSH kullanılarak yapılabilir. Kritik sistemler için uzakta bir yedek sistem kurulur; bir tarafta sorun olduğunda öteki otomatik olarak devreye girer.

Fiziksel ekipmanın kurtarılması hasarın türüne bağlıdır; örneğin sel sonrası bırakılan balçık ve katı maddelerin verdiği zarar temizlik sürecini belirler. Bunun için olağanüstü durum kurtarma uzmanlarına ve bir olağanüstü durum kurtarma planına ihtiyaç vardır.

## 9. Fiziksel ve mantıksal güvenlik entegrasyonu

Bir kurumda çok sayıda algılama ve önleme cihazı bulunur: kamera sistemleri, yangın algılama ve ihbar sistemleri, mantıksal tarafta firewall'lar. Bunlar bütüncül olarak tek bir merkezden yönetilebiliyorsa güvenlik daha etkili olur. Ayrıca otomatikleştirilmiş fiziksel ve mantıksal güvenlik işlemleri de entegre edilmelidir. Bunun için:

- Tek bir güvenlik kimlik kartı kullanılmalıdır.
- Kart kaydı tek adımda yapılmalı, sonlandırma da tek adımda yapılmalıdır.
- Merkezi bir kimlik yönetim sistemi kullanılmalıdır.
- Birleşik olay izleme ve korelasyon analizi yapabilen yazılımlar kullanılmalıdır.

Bu alandaki ihtiyaçlar FIPS 201 standardında verilmiştir: federal çalışanların ve yüklenicilerin kişisel kimlik doğrulaması (Personal Identity Verification, PIV) standardı. Hocanın anlattığı FIPS 201 entegrasyon modelinde kişisel kimlik kartları, PIN numaraları ve biyometrik okuyucular bir sisteme bağlıdır; bu sistem de erişim kontrol sistemine bağlanır ve hem fiziksel giriş-çıkışı hem de mantıksal giriş-çıkışı denetler.

Modelin bir uygulamasında sistemin bileşenleri şunlardır: insan kaynakları veritabanı, Active Directory ve diğer dizin hizmetleri, optik kart okuyucular, akıllı kart okuyucular, kart yazıcılar ve kameralar. Bunlar PIV sistemine girer; PIV sistemi erişim kontrol sistemi ve sertifika otoritesiyle birlikte çalışır. Örneğin bir ticaret merkezinde yazar kasalara ve otomatlara bağlı kart okuyucular ya da bilgisayarlara akıllı kartla giriş aynı yapıdan beslenir. Böylece fiziksel ve mantıksal entegrasyon tek bir kontrol mekanizmasında birleştirilmiş olur.

<!-- BELİRSİZ: FIPS 201 entegrasyon modeli ve uygulama diyagramının slaytları karelerde yok; bileşenler ve aralarındaki bağlantılar yalnız altyazıdan alındı ("otomat" ifadesi altyazıda bozuk geçiyor). -->

## 10. Korunan alanlar için güvenlik ve kontrol dereceleri

Kampüsler, bölgeler ve binalar korunacak alanlar olarak dört güvenlik ve kontrol derecesine ayrılır. Slayttaki tablo (ekrandan, 01:00:00):

| Sınıfı | Tanım |
|---|---|
| Sınırsız | Güvenlikle ilgisi olmayan bir tesis alanı. |
| Kontrollü | Kısıtlı bir alanın, genellikle sınırlı veya hariç tutulan bir alana yakın veya onu çevreleyen bölümü. Kontrollü alana giriş, erişim ihtiyacı olan personel ile sınırlıdır. Yetkili personelin bu alan içindeki hareketi mutlaka kontrol edilmez, çünkü alana yalnızca giriş güvenlik çıkarlarına erişim sağlamaz. Kontrollü alan, idari kontrol için, güvenlik için veya sınırlı veya hariç tutulan alan için derinlemesine güvenlik için bir tampon bölge olarak sağlanır. |
| Kısıtlı | Bir güvenlik bölgesinin yakınında bulunan kısıtlı alan. Kontrolsüz hareket, menkul kıymet çıkarlarına erişime izin verebilir. Eskortlar ve diğer dahili kısıtlamalar, sınırlı alanlarda erişimi engelleyebilir. |
| Girilmez | Bir güvenlik alanı. Kontrolsüz hareket, güvenliğe doğrudan tecavüz anlamına gelir. |

Hocanın açıklamaları:

- **Sınırsız alan:** Güvenlikle ilgili olmayan, tasnif dışı alanlardır; bahçe ve park gibi.
- **Kontrollü alan:** Bu alana yalnız kontrollü biçimde girilir. Hocanın örneği bir üniversite kampüsüdür: kimlik kartıyla kampüse girilir, ama kampüs içindeki hareket ayrıca denetlenmez.
- **Kısıtlı alan:** Burada kişi yalnız erişim yetkisi olan bölümlere girebilir, diğer yerler engellenir; gerekirse yanında bir eskortla birlikte belirli kısıtlamalarla dolaşır.
- **Girilmez alan:** Kontrolsüz hareket yoktur; yetkisiz birinin buraya girmesi doğrudan güvenlik ihlalidir.

Ardından gelen bir diyagramda bu sınıflar iç içe bölgeler olarak gösterilir: dışarıda kontrolsüz giriş olan sınırsız alan, içe doğru kartlarla, biyometrik kartlarla ve kişisel kimlik kartlarıyla geçilen kontrollü, sınırlı ve girilmez (exclusion) alanlar. Hoca bunu bir kampüs örneğine uygular: sol alt köşede ziyaretçi alanı ve ziyaretçi kaydı; yönetim binaları ve yemekhane, spor tesisleri gibi ortak tesisler kontrollü alandır; laboratuvarlar ve diğer hassas yerler yalnız yetkililerin girebildiği sınırlı alandır; girilmez alan ise yalnız o işe özel yetkilendirilmiş kişilerin girebildiği, diğer herkesin erişiminin engellendiği alandır.

<!-- BELİRSİZ: iç içe bölgeler ve kampüs diyagramının slaytları karelerde yok; bölgelerin yerleşimi yalnız altyazıdan alındı. -->

## Örnek Sorular

Derste ekranda soru gösterilmedi ve öğrenci sorusu gelmedi. Aşağıdakiler hocanın anlatım sırasında sınıfa sorup kendisinin cevapladığı sorulardır.

**Soru 1** (derste sözlü, 00:23:18): Bilgi sistemlerini tehdit eden fiziksel olaylar ve durumlar nelerdir?

> **Cevap (derste verildi):** Üç kategoride toplanır: çevresel tehditler (doğal afetler, yangın, su, kimyasal/radyolojik/biyolojik tehditler, toz, istila), teknik tehditler (düşük ve aşırı voltaj, gürültü, elektromanyetik girişim) ve insan kaynaklı tehditler (yetkisiz erişim, hırsızlık, dinleme, vandalizm, kötüye kullanım).

**Soru 2** (derste sözlü, 00:39:47): Su basmasında birinci tehlike nedir? Su hasarı için sel olması şart mıdır?

> **Cevap (derste verildi):** Birinci tehlike elektriksel kısa devredir. Sel şart değildir: yakından geçen bir su borusu arıza ya da donma nedeniyle patlayabilir, sprinkler sistemi yanlışlıkla devreye girebilir. Su selle geldiyse ayrıca balçık ve sürüklenen katı parçalar hasar verir.

**Soru 3** (derste sözlü, 00:53:42): Fiziksel bir tehdit gerçekleştiğinde kurtarmanın en temel unsuru nedir?

> **Cevap (derste verildi):** Yedeklemedir. Veriler saha dışında, mümkünse canlı ya da sık aralıklarla yedeklenmeli, aynı makinede tutulmamalıdır; şifreli uzaktan yedekleme ve kritik sistemler için devralmaya hazır uzak bir sıcak site kullanılabilir.

## Dersin Toparlaması

Bu derste bilişim güvenliğinin yalnız mantıksal önlemlerle sağlanamayacağı, fiziksel ve altyapı güvenliğinin de bütüncül güvenliğin parçası olduğu işlendi. Fiziksel güvenlik hem donanımı ve tesisi hem de sistemi kullanan ve bakımını yapan kişileri korur; altyapının zarar görmesini ve kötüye kullanılmasını önlemeyi amaçlar. Tehditler çevresel, teknik ve insan kaynaklı olmak üzere üç grupta incelendi: doğal afetler uyarı, tahliye ve süre üzerinden; tornado ve hurricane şiddeti Fujita ve Saffir-Simpson ölçekleriyle; yangın tehlikesi bilişim ortamlarının hasar sıcaklıklarıyla; su, toz, istila, güç sorunları ve elektromanyetik girişim de kendi önlemleriyle ele alındı. İnsan kaynaklı tehditlerin en zor öngörülen grup olduğu vurgulandı.

Önlem tarafında bulut bilişim, iklimlendirme, UPS ve jeneratör, ekranlama ve filtreleme, erişim kısıtlama, kamera ve alarm sistemleri; kurtarma tarafında saha dışı ve sık güncellenen yedekleme ve sıcak site anlatıldı. Son olarak FIPS 201 tabanlı tek kart ve merkezi kimlik yönetimiyle fiziksel ve mantıksal güvenliğin entegrasyonu ve korunan alanların sınırsız, kontrollü, kısıtlı ve girilmez olarak derecelendirilmesi verildi. Yönetim sorunları dizisi bir sonraki konu olan insan kaynakları güvenliği ile devam eder.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
