# Ders 2 Çalışma Özeti

## Genel Konular

- Hayat bilgisi (commonsense knowledge)
  - Herkesin bildiğini varsaydığımız, bu yüzden kimseye söylemeye bile gerek duymadığımız bilgilerdir. İngilizcede commonsense knowledge ya da world knowledge diye geçer.
  - Slayttaki örnekler: "İnsanlar her gün yemek yer.", "İnsanlar geceleri uyur.", "Balıklar denizde yaşar.", "Elma yuvarlaktır.", "Kediler miyavlar." (ekrandan, 00:11:20).
  - Bu bilgilerin istisnaları olabilir (karada da yaşayabilen balıklar, geceleri uyumayan insanlar), ama genel olarak doğru kabul edilirler.
- Hayat bilgisi veri tabanlarına neden ihtiyaç var?
  - Bilgisayarlara her şeyi söylemek gerekir; söylediklerimizden söylemediklerimizi anlayamaz, tahmin edemezler.
  - Hoca, yapay zekânın tanımlarından birini "bilgisayarlar neden bu kadar aptal sorusuna cevap aramak" diye verdi.
  - Çözüm, bilgisayarlara hayat bilgisi vermektir. Böylece "Ali lokantada yemek yedi" cümlesinden "Ali para ödemiştir" bilgisi (olasılıkla) çıkarılabilir.
- Kurt ve kız hikâyesi (ekrandan, 00:20:00)
  - Metin: Küçük bir kız babaannesini ziyaret etmek için ormanda yürür. Aç bir kurt onu görür ve yemeye karar verir. Saldıracakken oduncuların şarkılarını duyar, çalılıkların ardına saklanıp kararından vazgeçer.
  - Sorular: "Kurt kararından neden vazgeçti?", "Küçük kız korktu mu?"
  - Bu soruların cevapları metinde yazmaz; insanlar cevabı hayat bilgisiyle çıkarır. Makineler için bu henüz pek mümkün değildir.
- Duygu durum analizinde hayat bilgisi (ekrandan, 00:24:20)
  - "Yemeğim 5 dakikada geldi. Çok teşekkürler XXX." olumlu; "Yemeğim 55 dakikada geldi. Çok teşekkürler XXX." kinayeli ve olumsuzdur.
  - "XXX sayesinde 1 saatlik filmi 3 saatte izledim." ve "XXX sayesinde 1 saatte 5 film indirdim." örnekleri de sürelere dair bilgi gerektirir.
  - İki metin arasındaki fark tek bir karakterdir. Yemeğin normalde ne kadar sürede geldiğini bilmeden örüntü eşleme (pattern matching) ile doğru karar verilemez.
- Hayat bilgisi veri tabanları nasıl oluşturulur? İki temel yaklaşım (ekrandan, 00:27:50)
  - Bilgileri az sayıda bilgi mühendisi özenle girsin: Cyc, 20 yılda 1,5 milyon kaliteli bilgi.
  - Bilgileri çok sayıda web kullanıcısı girsin: OpenMind, 8000 kişi, 3 yılda 1 milyon bilgi.
- Popüler çalışmalar (ekrandan, 00:30:00)
  - Cyc (1984, anlamsal ağ, uzman kişiler, elle).
  - WordNet (1985, anlamsal ağ, uzman kişiler, elle).
  - OpenMind / ConceptNet (2002, gönüllü kullanıcılar, otomatik).
  - NELL (2010, hayat bilgisi, yarı otomatik).
- Sinirsel dil modelleri ve hayat bilgisi
  - Sinirsel dil modelleri kendi kendine denetimli (self-supervised) görevlerle eğitilir: önceki kelimelerden sonraki kelimeyi tahmin etmek ya da cümleden silinen kelimeyi tahmin etmek. Bu görevlerin verisi derlemden etiketçi olmadan otomatik üretilir.
  - Bu modellerin yakalayamadığı hayat bilgisini harici olarak vermek gerekir. ConceptNet'i derin öğrenme mimarileriyle birleştirmek popüler bir çalışma alanıdır.
- ConceptNet
  - Oluşturulması (ekrandan, 00:35:40): çıkarım aşamasında gönüllülerin serbest formda girdiği cümleler (OMCS corpus) bilgi üçlülerine çevrilir; bu, bütün bilgilerin %90'ıdır. Zenginleştirme aşamasında mevcut bilgilerden yeni bilgiler üretilir; bu, bilgilerin %10'udur.
  - Yapısı (ekrandan, 00:36:45): 1,6 milyon (kavram-ilişki-kavram) üçlüsü, 20 ilişki türü. Slayttaki ilişki türleri şu gruplarda toplanır: nesneler (IsA, PartOf, PropertyOf, MadeOf, DefinedAs), mekân (LocationOf), olaylar (SubeventOf, LastSubeventOf, PrerequisiteEventOf, FirstSubeventOf), nedensellik (EffectOf, DesirousEffectOf), duygusal (DesireOf, MotivationOf), işlevsel (UsedFor, CapableOfReceivingAction), etmenler (CapableOf).
  - İlişkiler yönlü ya da yönsüz, geçişli ya da geçişsiz olabilir.
  - Örnek ağ (ekrandan, 00:40:00): "wake up in morning" düğümü; "eat breakfast"ın ön koşuludur (PrerequisiteOf); alt olayları "yawn", "check e-mail", "drink coffee"dir. "eat breakfast"ın etkisi "full stomach", alt olayları "chew food" ve "read newspaper"dır. "kitchen table" kahvaltı için kullanılır, "in house"da bulunur, parçası "chair"dir.
  - Uygulama örneği, Commonsense ARIA (ekrandan, 00:40:10): kullanıcının yazdığı e-postayı inceleyip içeriğine uygun fotoğraflar önerir ya da ekler. Hikâye üretimi de bir uygulama örneğidir.
- Grup çalışması: hayat bilgisini toplama, iyileştirme ve uygulama fikirleri
  - Gruplar beyin fırtınasıyla fikir üretti. Bir kısmı: atasözü ve deyimlerden genel yargı çıkarma, hayat bilgisi içermeyen cümleleri ayıklama, özel adları tür adlarıyla değiştirme, emojilerle etiketsiz duygu öğrenme, ders kitabı ve çocuk kitabı gibi öğretici metinlerden öğrenme, sokak görüntülerinden image captioning ile sık görülen durumları genel doğru sayma, çelişen bilgileri oylama ya da frekansa göre seçme, kaynak güvenilirliğine göre puanlama, görme engelliler için uyarı mekanizması.
- NELL (Never-Ending Language Learning)
  - 2010'da başladı. Web sayfalarında gezinerek bilgiyi (kavram, ilişki, kavram) üçlüleri biçiminde toplar. Yarı otomatik ve iteratif çalışır.
  - Morfolojik çözümleme, HTML kodu şablonları ve metin şablonları kullanır.
  - Başlangıçta her ilişki türü için doğruluğu bilinen kavram ikilileri (seed) verilir. Sistem bunlardan şablon öğrenir, şablonlarla yeni ikililer bulur, yeni ikililerden yeni şablonlar öğrenir.
  - Çevrim arttıkça doğruluk keskin biçimde düştüğü için her şablona kısıt konmuştur. Örneğin "bu nerede yapılır" ilişkisinde ikilinin ilki bir eylem, ikincisi bir mekân olmalıdır (ekrandan, 01:50:00).
  - Kısıta uyan ve uymayan ikililerin sayılarıyla şablon güvenilirlik katsayıları hesaplanmıştır.
  - 2010'dan bu yana 50 milyon aday ilişki öğrenmiş, bunların 1,8 milyonunun güvenilirliği yüksektir.
  - Güvenilirlik (ekrandan, 01:51:10): şablon güvenilirliği (ürettiği ikililerin doğruluk oranı); ilişki güvenilirliği (üretildiği şablonun güvenilirliği, kaç farklı şablondan üretildiği, kullanıcı geri beslemeleri).
- Şablon örneği: "Tüm X'ler Y'dir" (IsA) ilişkisi (ekrandan, 01:47:30)
  - Türkçe için bulunan şablonlar: "ve diğer", "ler ve diğer", "ve benzeri", "veya diğer", "türü olan", "ları ve diğer", "lar ve diğer", "ve her türlü", "lerden biri olan", "leri ve diğer", "larından biri olan", "lerinden biri olan", "lardan biri olan", "adı olan", "ve her tür".
  - Şablonlar, aralarında IsA ilişkisi olduğu bilinen ikililerin web'de aranıp etraflarındaki ortak metinlere bakılarak bulunur.
- Türkçe hayat bilgisi veri tabanı
  - Literatürdeki çalışmalar genelde İngilizcedir; Türkçe için bu ilk çalışmadır.
  - Seçenekler: Cyc gibi uzmanlara girdirmek, OpenMind gibi gönüllülere girdirmek, mevcutları tercüme etmek, frekans tabanlı bilgi çıkarımı. Tercüme ve frekans tabanlı çıkarım seçilmiştir.
  - Veri kaynakları (ekrandan, 01:53:30): ConceptNet ve özgün WordNet Google Translate ile çevrilip sisteme aktarıldı; Türkçe WordNet ve HTML sayfaları doğrudan sisteme girdi.
  - Frekans tabanlı çıkarımda 400 bin web sayfasının HTML kodu üzerinde morfolojik çözümleyici olarak Zemberek kullanıldı.
  - Otomatik çeviri sorunludur ama en az maliyetli yoldur. Elle düzeltmek ölçeklenebilir değildir.
- CSoyun
  - Bilgi kalitesini yükseltmek ve yeni bilgi eklemek için çok sayıda kişiden geri besleme alan, oyunlaştırma (gamification) kullanan bir web sitesi. İçinde beş oyun vardır; kullanıcılar her geri besleme için puan alır.
  - Kullanıcılar yeni kavram ve ilişki girebilir, yeni ilişki türü giremez.
  - Bildiklerim: bir ilişki türü seçilir, o ilişkiye sahip kavram ikilileri rastgele gösterilir, kullanıcı 0-5 arası oy verir.
  - Araştır: bir kavramla ilişkili kavramlar gösterilir, kullanıcı oy verir. Çeviriden kaynaklanan hatalar burada görülebiliyordu.
  - Tahminlerim: sistem, var olan ilişkilerden monotonik olmayan çıkarımla veri tabanında olmayan hipotezler üretir ve kullanıcılara sorar. CSoyun'u benzerlerinden ayıran en önemli özellik budur.
  - Kullanıcıya kavram ve ilişki türü verip ilişkili kavramları girdiren bir oyun ve iki kişilik bir oyun daha vardır. İki kişilik oyunda aynı soruya iki kişi aynı cevabı verirse bilgiye daha çok güvenilir. <!-- BELİRSİZ: Bu iki oyunun adları altyazıda bozuk ("JSON'e bana öğret", "Birlikte eğitim bana"); slaytta görülmedi. -->
- Monotonik ve monotonik olmayan çıkarım
  - Monotonik çıkarım: "Bütün X'ler Y'dir" ve "Bütün Y'ler Z'dir"den "Bütün X'ler Z'dir" çıkar. Sonuç kesindir; bu yüzden veri tabanına yazmaya gerek yoktur, gerektiğinde üretilir.
  - Monotonik olmayan çıkarım: sonucu doğru da yanlış da olabilecek çıkarımdır. Veri tabanına aday olarak eklenip insanlara sorulmaya değer olan budur.
  - Çıkarım kuralları ve örnekleri (ekrandan, 02:00:00) Detaylı Açıklamalar bölümündedir.
- Hayat bilgisi veri tabanlarının kalitesi (ekrandan, 02:06:55)
  - Doğruluk: sistemden rastgele seçilen 100 ilişkiden yüzde kaçının bir insan tarafından doğru bulunduğu.
  - Kapsayıcılık: gereken tahmini bilgi sayısı milyonlardır. Kavram sayısının ve ilişki sayısının yeterliliği ölçülür.
  - Bu ölçümlerle sürekli gelişen bir sistemin kapsayıcılık ve doğruluğunun zaman içindeki değişimi izlenebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hayat bilgisi çıkarımları kesin değil, olasılıklıdır
  - "Ali lokantada yemek yedi" cümlesinden "Ali para ödemiştir" büyük olasılıkla çıkar ama kesin değildir. Sistem bu olasılıklı çıkarımı yapabilmelidir.
- Bilgiye sahip olmak, ona gerektiğinde erişebilmeyi de gerektirir
  - Bir öğrenci sorunun bilgiyi depolamakta değil, depodan doğru bilgiyi hızlı getirmekte olduğunu söyledi. Hoca, bilginin bir yerde metin olarak durmasının işe yaramadığını, sahip olmanın ne zaman erişileceğini bilmeyi de içerdiğini belirtti.
- 5 dakika kısa, 55 dakika uzun demek tek başına anlamlı değildir
  - 55 dakika yemek teslimatı için uzun, bir film için kısadır. Değerlendirme bağlama göre değişir; bu yüzden bağlama duyarlı hayat bilgisine ihtiyaç vardır.
- Monotonik çıkarımla üretilen bilgiyi saklamanın anlamı yoktur
  - Kaplumbağa sorusu: "Bir kaplumbağanın sol ön ayağındaki bir hücrenin endoplazmik retikulumu var mıdır?" Herkes "vardır" der ama bu bilgiyi kimse aklında saklamaz; kaplumbağa hayvandır, hayvan hücrelerinde endoplazmik retikulum vardır diye gerektiğinde çıkarır.
  - İnsanlar bilgiyi hiyerarşik ve gerektiğinde çıkarılabilir biçimde tutar. Hoca buna bilgi ekonomisi dedi.
- Önemli olan teknik değil, arkasındaki fikirler
  - CSoyun sitesi artık erişilemese de dersin kapsamında önemli olan, kullandığı tekniklerdir (oyunlaştırma, oylama, monotonik olmayan çıkarımla hipotez üretme, iki kişinin uyuşması).
- Metinsel olmayan bilgi
  - Bilgilerimizin hepsi metinle ifade edilemez: görsel bilgi ve bisiklete binmek gibi beceriler. Hayat bilgisi veri tabanları metinsel bilgiyle sınırlıdır; dünyanın fiziğini öğrenme çalışmaları henüz emekleme aşamasındadır.

## Kısa Tekrar Notları

- Hayat bilgisi: herkesin bildiğini varsaydığımız, istisnaları olabilen genel bilgiler (commonsense / world knowledge).
- İhtiyaç: bilgisayarlar söylenmeyeni çıkaramaz; hayat bilgisi verilirse "lokantada yemek yedi" → "para ödemiştir" gibi olasılıklı çıkarım yapılabilir.
- İki yaklaşım: az sayıda uzman özenle (Cyc, 20 yılda 1,5 milyon bilgi) ya da çok sayıda gönüllü (OpenMind, 8000 kişi, 3 yılda 1 milyon bilgi).
- Popüler çalışmalar: Cyc (1984), WordNet (1985), OpenMind/ConceptNet (2002), NELL (2010).
- ConceptNet: 1,6 milyon (kavram-ilişki-kavram) üçlüsü, 20 ilişki türü; %90 cümleden üçlüye çeviri, %10 zenginleştirme.
- NELL: seed ikililerden şablon öğrenme, şablondan yeni ikili, iteratif; kısıtlar ve güvenilirlik katsayıları; 50 milyon adaydan 1,8 milyonu yüksek güvenilirlikli.
- Şablon güvenilirliği = ürettiği ikililerin doğruluk oranı; ilişki güvenilirliği = şablon güvenilirliği + şablon sayısı + kullanıcı geri beslemesi.
- IsA için Türkçe şablonlar: "ve diğer", "ve benzeri", "türü olan", "lerden biri olan", "adı olan" vb.
- Türkçe veri tabanı: ConceptNet ve WordNet'in Google Translate ile çevirisi, Türkçe WordNet, 400 bin web sayfasından Zemberek ile frekans tabanlı çıkarım.
- CSoyun: oyunlaştırma, beş oyun, oylarla güvenilirlik, monotonik olmayan çıkarımla hipotez (Tahminlerim).
- Monotonik çıkarım kesindir, saklanmaz; monotonik olmayan çıkarım belirsizdir, aday olarak sorulur.
- Kalite: doğruluk (100 rastgele ilişkiden yüzde kaçı doğru) ve kapsayıcılık (kavram ve ilişki sayısının yeterliliği).

## Detaylı Açıklamalar

### Hayat bilgisi ve makinelerin sınırı

Hayat bilgisi, o kadar bariz ki kimseye söylemediğimiz bilgilerdir. Bir metni anlarken insan, metinde yazmayan bu bilgileri arka planda kullanır. Kurt ve kız hikâyesinde kurtun neden vazgeçtiği yazmaz. İnsan şunu çıkarır: kurt saldırırsa kız bağırır, oduncular çığlığı duyup yardıma gelir, kurtu görünce ona zarar verir; kurt bunu öngördüğü için vazgeçmiştir. Küçük kızın korkup korkmadığı sorusunda da metinde kızın kurdu fark ettiğine dair bir şey yoktur; kurdu görse kaçar, bağırırdı. Dolayısıyla kızın korktuğuna dair bilgi yoktur. İnsanlar bu bilgileri doğduklarından itibaren dünyayı deneyimleyerek öğrenir; makinelerin böyle bir süreci yoktur. Dersin sorusu, bu bilgilerin makinelere nasıl verileceğidir.

Hoca, metnin içindeki bir bilgiyi sormanın ("Kurt nereye saklanıp kararından vazgeçti?") makineler için çözülebilir olduğunu, asıl zorluğun metinde olmayan ama gereken bilgiye erişmek olduğunu belirtti.

### ConceptNet

ConceptNet, OpenMind projesinden türemiştir. Gönüllü kullanıcılar serbest formda cümleler girer; bu cümleler "kavram 1, ilişki türü, kavram 2" biçimindeki bilgi üçlülerine çevrilir. Zenginleştirme aşamasında mevcut bilgilerden çıkarım yapılarak yeni bilgiler üretilir. Hoca, ConceptNet'te dünyadaki bütün ünlülerin doğum tarihleri ya da canlıların Latince adları gibi herkesin bildiği türden olmayan bilgilerin de bulunduğunu, bunların bazı alanlarda işe yarayabileceğini ama hayat bilgisi sayılmayacağını belirtti.

İlişkilerin özellikleri farklıdır. Zıt anlamlılık yönsüzdür; "A, B için kullanılır" yönlüdür. "Yakınlık" gibi bir ilişki geçişli görünse de zincir uzadıkça (A-B, B-C, C-D) A ile D artık yakın olmayabilir.

### NELL ve şablonlarla bilgi çıkarımı

NELL'e başlangıçta her ilişki türü için örneğin yüzer tane doğru kavram ikilisi (seed) verilir. Bu ikililer web'de aranır, dönen sayfalarda X ile Y'nin arasındaki ya da etrafındaki metinlere bakılır. Ortak metinler şablon olarak öğrenilir. Örneğin "Tüm X'ler Y'dir" (IsA) ilişkisi için "X ve diğer Y" bir şablondur. Sonra yalnız şablon aranır ve şablonun sağındaki ve solundaki kavramlar arasında da IsA ilişkisi olduğu varsayılır. Yeni ikililerden yeni şablonlar öğrenilir. Sistem aynı sayfalara tekrar tekrar döner.

Bir öğrenci bu sistemin çok yanılabileceğini söyledi. Hoca bunu doğruladı ve çözüm olarak güvenilirlik hesabını anlattı. Şablonun ürettiği ikililerden bir kısmı elle kontrol edilir; örneğin şablonun %60 olasılıkla doğru, %40 olasılıkla yanlış ürettiği bulunur. Bir ilişki ne kadar çok farklı şablondan ve cümleden üretilmişse ona o kadar çok güvenilir. NELL'in sayfasında kullanıcılar öğrenilen bilgilere yukarı/aşağı oy verebilir; bu geri beslemeler de ilişki güvenilirliğinde kullanılır.

### Türkçe hayat bilgisi veri tabanı

Hocanın grubunun çalışmasında Cyc gibi uzmanlara girdirme ya da OpenMind gibi gönüllülere girdirme yerine mevcutları tercüme etmek ve frekans tabanlı bilgi çıkarımı seçildi. ConceptNet ve İngilizce WordNet Google Translate ile otomatik çevrildi; Türkçe WordNet ve web sayfalarından şablonlarla çıkarılan bilgiler de eklendi. Veri tabanı oluşturulurken kaynakların farklı formatları basit bir ortak formatta birleştirildi.

Veri tabanından örnekler (ekrandan, 01:54:15):

| Bunun için ne gerekir? | Neye sebep olur? | Bundan neler yapılır? |
|---|---|---|
| yazmak-araştırmak | öldürmek-ceza | taş-köprü |
| denemek-para | doğurmak-hayat | çelik-makine |
| uyumak-yatmak | sevmek-umut | su-bulut |
| seyahat etmek-enerji | sevmek-acı | kağıt-gazete |
| öğrenmek-okumak | ateş-acı | yün-kumaş |
| yaşam-yiyecek | öldürmek-üzüntü | kumaş-gömlek |

| Ne için kullanılır? | Bu ne yapabilir? | Nerede bulunur? |
|---|---|---|
| asker-savaş | kuş-uçmak | oda-bina |
| çatal-yemek | kişi-yürümek | kişi-oda |
| top-oynamak | bilgisayar-düşünmek | elbise-mağaza |
| ördek-yemek | çocuk-düşmek | kemik-kişi |
| hastalık-öldürmek | bıçak-kesmek | asker-savaş |
| baş-düşünmek | gemi-batmak | öğrenci-okul |

### CSoyun ve monotonik olmayan çıkarım

CSoyun'da kullanıcının verdiği oyun doğru mu yanlış mı bilinemez; bilinseydi oyuna gerek kalmazdı. Bunun yerine bir ilişkiye verilen oyların ortalamasına bakılır: bazıları yanlış oy verse de doğru söyleyenlerin daha çok olacağı varsayılır. Hoca bunu "demokrasiye güvenmek" diye anlattı. Araştır oyununda "kedi nerede bulunur" için gelen cevaplar arasında makul olanların yanında çeviri hatasından doğan saçma olanlar da vardı.

Tahminlerim oyununda kullanılan çıkarım kuralları ve örnekleri (ekrandan, 02:00:00):

| Çıkarım türü | Örnek çıkarım |
|---|---|
| (X-R1-Y) ve (Y-R2-Z) → (X-R3-Z) | (martı - altkavramıdır - kuş) ve (martı - bu ne yapabilir - uçmak) → (kuş - bu ne yapabilir - uçmak) |
| (X-R1-Y) → (X-R2-Y) | (sinemaya gitmek - içerdiği olaylar nelerdir - mısır yemek) → (sinemaya gitmek - bunun için ilk önce ne yaparsın - mısır yemek) |
| (X-R1-T) ve (Z-R1-T) ve (X-R2-Y) → (Z-R2-Y) | (kedi - altkavramıdır - memeli) ve (köpek - altkavramıdır - memeli) ve (kedi - sahiptir - kürk) → (köpek - sahiptir - kürk) |
| (X-R1-Y) ve (X-R2-Z) → (Z-R3-Y) | (bıçak - nerede bulunur - mutfak), (bıçak - ne için kullanılır - kesmek) → (kesmek - nerede yapılır - mutfak) |

Martı örneğinde alt kavramın yapabildiği bir şey üst kavrama aktarılır. Bu doğru da olabilir yanlış da: aynı kural penguen (uçamaz) için uygulansa "kuş uçamaz" sonucu çıkar. Kedi-köpek örneğinde aynı üst kavrama bağlı iki kardeş kavramdan birinin sahip olduğu özelliğin diğerinde de olup olmadığı sorulur. Bu çıkarımların hepsi monotonik değildir; üretilen hipotezler kullanıcılara sorulur, onaylananlar ilişkiler tablosuna kaydedilir.

- Ders sonrası not: Hoca 02:01:43 civarında "Mühim olan elde edilmeye kalktığımızda doğru olmama ihtimali olan şeyleri üretmek. Monotonik çıkarım da bu." dedi. Bağlama göre doğrusu "monotonik olmayan çıkarım"dır; büyük olasılıkla dil sürçmesi ya da altyazı hatasıdır.
- Ders sonrası not: Hoca popüler çalışmaları sayarken OpenMind için "2012" dedi; slaytta OpenMind/ConceptNet için 2002 yazıyor.

### Hayat bilgisi veri tabanının kalitesi

Doğruluk, rastgele seçilen ilişkilerin insanlarca etiketlenmesiyle kabaca ölçülebilir. Asıl kritik konu kapsayıcılıktır: az miktarda ama çok kaliteli bilgi yetmez. Kavram sayısının yeterliliği için, örneğin büyük metin derlemlerinde geçen kavramların yüzde kaçının veri tabanında bulunduğuna bakılabilir. Kavram tek kelime olmak zorunda değildir, birden fazla kelimeden oluşabilir. İlişki sayısının yeterliliği için, bir insana rastgele bir kavram verilip belirli bir sürede aklına gelen ilişkilerin yüzde kaçının veri tabanında bulunduğuna bakılabilir. İnsanlar farklı olduğu için bu ölçümler tek kişiyle değil, çok sayıda kişiyle yapılmalıdır. <!-- BELİRSİZ: Kavram yeterliliği ölçütündeki kaynak altyazıda bozuk ("Büyük Metin Kikipanelerindeki"); "büyük metin derlemleri" olarak yorumlandı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
