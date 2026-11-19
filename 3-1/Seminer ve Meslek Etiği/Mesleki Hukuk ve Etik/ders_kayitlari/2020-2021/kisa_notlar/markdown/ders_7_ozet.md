# Ders 7 Çalışma Özeti

## Genel Konular

- Bilgi sistemi projesinde gerçekleştirme aşamasının etiği (ekrandan, 00:10:00)
  - Gerçekleştirme hem yazılımı hem donanımı içerir. Yazılımın hatasız ve dayanıklı olması istenir; ama hatasız yazılım yoktur. IDE ve CASE araçları hata sayısını azaltır, sıfırlamaz.
  - Etik olmayan dört geliştirici davranışı slaytta sayıldı:
    - Eski projedeki program parçasını, yeni programa uygun olup olmadığını incelemeden "yama" olarak eklemek.
    - Başkasının hazırladığı kodu (ör. GitHub'dan alınan bir parça) içini incelemeden olduğu gibi kullanmak.
    - Programı farklı giriş değerlerinde ve koşullarda sağlamlaştıracak eklemeleri "kimse o değeri girmez" diyerek savsaklamak.
    - Programın içine, belirlenen bir zamanda bütün bilgi sistemine zarar verecek bomba program gömmek.
  - İlk üçü etik değerlere özen göstermemektir. Dördüncüsü bilerek meslek etiğini çiğnemektir ve aynı zamanda suçtur.
  - Donanım seçiminde "teknik özellikleri karşılıyor ve ucuz" gerekçesi her zaman doğru değildir; ileride daha büyük ve pahalı sorunlar doğurabilir.
- Gerçekleştirme hatasına iki tarihsel örnek
  - Challenger uzay mekiği: yakıt sızdırmazlığı için kullanılan O-halka contanın çok düşük sıcaklıkta çatladığı biliniyordu, buna rağmen kullanıldı. Conta çatladı, yakıt sızdı, mekik fırlatıldıktan kısa süre sonra infilak etti ve 7 astronot öldü.
  - THY'nin DC-10 uçağı: McDonnell Douglas, bagaj kapağının üretimini Convair'e yaptırmıştı. Oradaki kıdemli mühendis Dan Applegate kapağın kilit mekanizmasının basınç farkında kırılabileceğini yöneticilere bildirdi. Kapaklar bir program dahilinde sırayla değiştirilirken, Paris'ten Londra'ya giden THY uçağının bagaj kapağı havada açıldı, uçak parçalandı ve 346 kişi öldü.
  - Günümüzde trafik ışıkları, hava trafiği, hastanedeki oksijen dağıtımı gibi pek çok sistem yazılımla yönetildiği için yazılımda savsaklanan bir hata da can kaybına yol açabilir.
- Sınama, kurulum ve bakım (ekrandan, 00:25:00)
  - Büyük ölçekli sistemler işletmeye alınmadan önce mutlaka sınanır. Sınamayı geliştiricilerden bağımsız kişiler yapmalıdır.
  - Sınamada bulunan kusurlar geliştiricilere bildirilir, giderilir ve sınama yinelenir. "Gözden kaçmış" mazereti kabul edilmez.
  - Kurulum ve işletmeye almada sorunların kaynağı saptanıp ilgili bölüme bildirilmelidir. Ticari kaygıyla (lansman tarihine yetiştirmek gibi) sorunları savsaklamak etik değildir.
  - Bakımda ortaya çıkan kusurlar belli bir ölçüye kadar olağandır. Kullanıcılar hemen uyarılmalı ve yamalar hemen dağıtılmalıdır. Hataları gizlemek ya da yamaları geciktirmek etik değildir.
- Üretim ve uygulama ile ilgili sorumluluklar (ekrandan, 00:30:00)
  - Rol temelli sorumluluk: görev alan herkes üstlendiği görevle bağlantılı sorumluluk taşır.
  - Edilgen sorumluluk: sistem kullanılırken ortaya çıkan bir sorunu sonradan araştırmak ve kaynağını ilgililere açıklamak.
  - Etken sorumluluk: üretim sırasında sorun çıkarabilecek şeyleri görüp önlem almak ve bunu üst yönetime iletmek.
  - Challenger'da contayı fark edip üstlerine bildiren mühendis etken sorumluluğunu yerine getirdi; patlamadan sonra yapılan inceleme edilgen sorumluluktur. DC-10'da mühendis ve yöneticiler etken sorumluluğu yerine getirdi, ama uçağı işleten havayolları uyarılmadı.
  - Bir mühendis "sistemi geliştirdim, artık benden çıktı" diyemez; bakım süreci boyunca sorumluluk sürer.
- Hata kaynakları (dört tür)
  - Üretim hataları (yanlış conta seçimi, kapak tasarım hatası, internet bankacılığında telefon numarası değiştirme kuralının yanlış kurgulanması).
  - Yanlış kararlar: sorun çıkarabileceği bilinen bir parçayı ya da yöntemi bilerek uygulatmak. Genellikle yöneticiler verir.
  - Öngörü eksikliği: ürün kullanılırken çıkabilecek sorunları önceden görememek (çamaşır makinesinin sürekli hızlanıp duran kayışının bir yıl sonra çatlaması örneği).
  - Eylem özgürlüğü: kullanım sırasında seçenekler arasından bilerek yanlışı seçen uygulayıcı sonuçtan sorumludur.
- Teknik erekler ve etkin kişiler (ekrandan, 00:45:00)
  - Genç ve heyecanlı mühendislerin erekleri doğaldır ve desteklenmelidir; ama deneyimli mühendislerce değerlendirilmelidir. Salt bireysel heyecanı için projenin içeriğini değiştiren mühendis etik davranmış sayılmaz.
  - Yöneticiler ve kuruluş sahipleri etkin, uzmanlar ise yetkisi kısıtlı olabilir. Etkin kişilerin uzmanları dinlemeden etkinliklerini kullanarak projeyi yönlendirmesi etik değildir.
- Toplumsal bağlam (ekrandan, 00:50:00)
  - Her ürün üretilirken toplum sağlığı gözetilmelidir. Bazı mühendisler yüksek erek içgüdüsüyle ürünlerinin nerede, ne amaçla kullanılacağını düşünmez (İkinci Dünya Savaşı silahları örneği).
  - Bilişim uygulamaları bir bomba kadar etkili olabilir: elektrik dağıtım sistemini izinsiz ele geçiren yazılım, e-posta içeriklerini okuyan internet servis sağlayıcısı programı, hava yolu ya da şehir içi trafik sistemini ele geçiren yazılım.
  - Mühendis "ben işimi yaparım, gerisi beni ilgilendirmez" diyemez.
- Mühendisler ve yöneticiler (ekrandan, 00:55:00)
  - Kuruluşta yöneticiler, mali işlerden sorumlular ve mühendisler birlikte çalışır. Mühendisler tasarım ve gerçekleştirmede uzmandır, üretim yapan sınıftır.
  - Mühendislik kökenli olmayan yöneticilerle anlaşmazlık çıkabilir. Bankalarda bilgi işlem merkezinin "güçlü hesap makinesi" olarak görülmesinden bilgi sistemine dönüşmesi örneği verildi.
  - "Yönetici benim, benim dediğim yapılacak" mantığı büyük zararlara yol açar. Herkesin yetkisini, birikimini ve yeteneğini bilerek çalışmasına görev paylaşımı denir.
  - Kıskançlıkla başkasının başarısızlığına çalışmak, kusurları abartmak, iftira etmek etik değildir.
- Bilgisayar, bilişim ve yazılım mühendisleri için sekiz etik ilke (IEEE-CS ve ACM) (ekrandan, 01:00:00)
  - Kamu, Müşteri ve İşveren, Ürün, Yargı, Yönetim, Meslek, İş Arkadaşları, Özü (kendisi).
- Temel etik ilkeler: adalet, eşitlik, dürüstlük, tarafsızlık, sorumluluk, bağlılık, sevgi, hoşgörü, saygı, tutumluluk, açıklık, yapıcı eleştiri, emeğin karşılığını ödeme, yasa ve etik dışı emirlere karşı gelme.
- Etik olmayan davranışlar (ekrandan, 01:15:00) ve çalışanların etik olmayan davranışları (ekrandan, 01:30:00)
- Bilgisayar etiğinin on emri (Computer Ethics Institute, Washington DC)
- Davranışların etik açıdan yargılanması (ekrandan, 01:20:00)
  - Etik kuralları çiğneme nedenleri: hırs, yönetim erkini elde tutma isteği, deneyim eksikliği, bencillik, teknik yetersizlik, yasa ve ölçünleri bilmeme, bir olayı gizleme ve tanıklara menfaat sağlama, siyasi görüş.
  - Bir kararın etik olup olmadığını sınamak için altı soru (aşağıda).

## Hocanın Özellikle Vurguladığı Kısımlar

- Hatasız yazılım yoktur, ama bu hataları savsaklamanın mazereti değildir.
  - Gerçekleştirmedeki küçük bir ihmal (bir conta, bir kapak kilidi) 7 ya da 346 kişinin ölümüne yol açabildi. Yazılımla yönetilen sistemlerde de aynı risk vardır.
- Bomba program gömmek yalnız etik ihlal değil, suçtur.
  - Hoca bunu ilk üç davranıştan (özensizlik) ayırdı: dördüncüsünde mühendis bilerek ve isteyerek meslek etiğini çiğner.
- Sınama geliştiricilerden bağımsız kişilerce yapılmalıdır.
  - Kişi kendi yaptığı hatayı göremez; bitirme tezini beş kez okusanız da kendi hatanızı kaçırabilirsiniz, başkası hemen görür.
- Etken ve edilgen sorumluluk ayrımı.
  - Etken: üretim sırasında sorunu görüp bildirmek. Edilgen: kullanımda çıkan sorunu araştırıp örtbas etmeden açıklamak. Örnekler Challenger, DC-10 ve internet bankacılığı vakası üzerinden eşleştirildi.
- Kamu her zaman önce gelir.
  - Sekiz ilkenin ilki kamudur; müşteri ve işverenin çıkarı ancak kamu çıkarına ters düşmüyorsa gözetilir.
  - Bir yazılım ancak güvenli ve güvenilir, gereksinimleri karşılayan, yaşam kalitesini azaltmayan, özel hayata ve çevreye saygılı ise onaylanmalıdır.
- Çıkar çatışması.
  - Kendi şirketinin ürününü yönettiği kuruma satan bakan örneği ve danışmanlık yaptığı firmanın TÜBİTAK projesine hakem atanan öğretim üyesi örneği verildi. Böyle durumda kişi kendini o işten çekmelidir.
- İşe alırken etik kuralları yazılı verip "okudum ve anladım" imzası almak.
  - Böylece etik dışı davranışta çalışan sorumlu tutulabilir ve kuruluşun etik kurulu ceza verebilir.

## Kısa Tekrar Notları

- Gerçekleştirmede etik dışı: incelenmemiş yama, incelenmemiş hazır kod, sağlamlaştırmayı savsaklama, bomba program.
- Donanımda "ucuz ama yeterli" seçimi ileride daha pahalıya patlayabilir.
- Challenger: soğukta çatlayan O-halka conta, 7 astronot. DC-10 (THY): bagaj kapağı kilidi, 346 kişi.
- Sınama bağımsız kişilerce; "gözden kaçmış" mazereti yok.
- Bakım: kusuru hemen duyur, yamayı hemen dağıt.
- Rol temelli, etken (üretimde önlem), edilgen (kullanımda araştırma) sorumluluk.
- Hata kaynakları: üretim hatası, yanlış karar, öngörü eksikliği, eylem özgürlüğü.
- Heyecanlı mühendisin erekleri deneyimlilerce denetlenmeli; etkin kişi uzmanı dinlemeli.
- Toplumsal bağlam: "ben işimi yaparım, gerisi beni ilgilendirmez" denemez.
- Görev paylaşımı: herkes yetkisini, birikimini, yeteneğini bilerek çalışır.
- Sekiz ilke: Kamu, Müşteri ve İşveren, Ürün, Yargı, Yönetim, Meslek, İş Arkadaşları, Özü.
- On emir: zarar verme, engelleme, dosya karıştırma, hırsızlık, yalancı tanıklık, lisanssız kopya, izinsiz kaynak kullanımı, fikri ürüne konma yok; sosyal sonuçları düşün; insanlara saygıyla kullan.
- Etik sınama soruları: Doğru mu? Adil mi? Kim zarar görür? Basında çıksa rahatsız olur musun? Yakınların rahatsız olur mu? Karar nasıl görünüyor?

## Detaylı Açıklamalar

- **Gerçekleştirme aşaması.** Geliştirme takımları bir önceki aşamada hazırlanan tasarım belgelerinden yola çıkarak yazılımı geliştirir. Hoca etik dışı dört davranışı slayttaki sırayla anlattı (ekrandan, 00:10:00). Eski projeden alınan bir parça geliştirmeyi hızlandırır, ama "ben onu zaten test etmiştim" diye yeni projeye uygunluğu incelenmezse uyumsuzluk ve yanlış çalışma doğurabilir. Başkasının kodunu "çalıştı mı, devam" diye içine bakmadan kullanmak, içinde zararlı ya da programın geri kalanını bozan kod bulunma riskini taşır. Programın yalnız genel durumda çalışması yetmez; birkaç özel giriş değeri için gereken eklemeleri "kimse onları girmez" diyerek savsaklamak etik değildir. Son olarak "beni kovarlarsa program patlasın" düşüncesiyle gömülen ve çalışma zamanı sürekli ötelenen saatli bomba, programcı işten çıkınca çalışır ve bütün sisteme zarar verir.
- **Challenger ve DC-10.** Hoca bu iki eski örneği hem gerçekleştirme aşamasında hem de sorumluluk türlerinde kullandı. Challenger'da contanın soğukta çatladığı biliniyordu ve bir mühendis bunu fark edip üstlerine iletmişti. Ama conta üreticisi ile program yöneticileri arasında iletişim sorunu vardı ve program daha önce birkaç kez ertelendiği için büyük bir baskı oluşmuştu; küçük bir conta göz ardı edildi. DC-10'da kapak yeniden tasarlandı ve uçaklara sırayla takılıyordu; kaza öngörülmediği için THY gibi işletenler uyarılmadı. Hoca, uyarılsalardı uçağı hangarda bekletebileceklerini söyledi.
  > **Ders sonrası not:** Hoca mekiğin fırlatmadan 76 saniye sonra, yaklaşık 15.000 m'de infilak ettiğini söyledi (bir yerde "15.000 fit" dedi). Büyük olasılıkla doğrusu yaklaşık 73 saniye ve yaklaşık 14-15 km'dir (yaklaşık 46.000-48.000 fit). Mekiğin adı yalnızca Challenger'dır; altyazıdaki "Challenger 8" büyük olasılıkla bir yanlış duyma ya da yanlış söylemedir.
  > **Ders sonrası not:** Hoca McDonnell Douglas'ın bu kaza yüzünden iflas ettiğini söyledi. Büyük olasılıkla bu doğru değildir: şirket kazadan (1974) sonra uçak üretmeye devam etti ve 1997'de Boeing ile birleşti.
- **Boeing 737 örneği.** Hoca, sensörlerden farklı veriler geldiğinde yazılımın uçağa yanlış burun kaldırma ya da indirme komutu verdiği ve uçakların düştüğü bir Boeing 737 modelinden söz etti. Olay bilinip duyurulunca dünyadaki birçok havayolu bu uçakların uçuşlarını durdurdu, kapsamlı güncelleme ve sınamalardan sonra uçak yeniden uçuş sertifikası aldı. Hoca bu vakada etken sorumluluğun pek işletilmediğini söyledi.
  > **Ders sonrası not:** Hoca modeli "737 Next Generation, kompozit gövdeli" diye andı ve uçağın havada infilak ettiğini söyledi. Büyük olasılıkla söz konusu model 737 MAX'tır; sorunlu yazılım MCAS, yanlış veri veren sensör hücum açısı (angle of attack) sensörüdür ve uçaklar havada patlamamış, yere çakılmıştır. <!-- BELİRSİZ: Altyazıda 00:35:20 ile 00:35:48 arasında bir boşluk var; 737 örneğinin başı kayıtta eksik olabilir. -->
- **Bakım ve ticari kaygı.** Bakım, sistemin devreye alındıktan sonraki bütün ömrünü kapsar. Hoca "kervan yolda düzülür" diyerek ürünü çıkarıp hataları sonradan düzeltmeyi planlayan firmanın etik kuralları çiğnediğini söyledi. İşlemcilerdeki güvenlik açıklarının bir süre örtbas edilmeye çalışılmasını ve güncellemenin yavaş ilerlemesini örnek verdi. <!-- BELİRSİZ: Altyazıda "Intel Mintel" geçiyor; büyük olasılıkla Intel işlemcilerindeki Meltdown/Spectre açıkları kastediliyor. -->
- **Sekiz ilkenin ayrıntısı.** Kamu: testler sonunda sistem güvenli ve güvenilir, gereksinimleri karşılıyor, yaşam kalitesini azaltmıyor, özel hayata ve çevreye saygılıysa onay verilir; belgelerde yalan ifade bulunmaz. Müşteri ve işveren: yasa dışı ya da etik dışı yollarla elde edilen yazılım kullanılmaz, müşterinin olanakları kişisel çıkar için kullanılmaz, fikri mülkiyete ve gizliliğe uyulur. Ürün: kalite en üst düzeyde hedeflenir, bir ayda yapılacak işe sekiz ay istenmez, etik, ekonomik, kültürel, yasal ve çevresel kısıtlar belirlenir, teknik şartname müşteriyle karşılıklı onaylanır. Yargı: yargılar tutarlı, bağımsız ve adil olur; rüşvet ve sahteciliğe karışılmaz; çıkar çatışmasında kişi kendini işten çeker. Yönetim: proje iyi yönetilir, metrikler ve kuruluş politikası çalışanlara bildirilir, öneriler gerçekçi yapılır, maaşlar adil olur, çalışanların fikri mülkiyet hakları gözetilir, etik kaygısını dile getiren kınanmaz ve cezalandırılmaz. Meslek: meslek örgütleri (ör. meslek odası) desteklenir, meslek doğru tanıtılır, mesleki toplantılara katılınır, yasalara uyulur, bulunan hata gizlenmez. İş arkadaşları: meslektaşlara adil ve destekleyici olunur, görüş ve eleştirilerine saygı gösterilir, gerektiğinde uzmana danışılır. Özü: yaşam boyu öğrenme; yazılım geliştirme süreçleri (hoca güncel örnek olarak DevOps ve CI/CD'yi verdi), belgeleme, yasa ve standartlar sürekli öğrenilir.
- **Etik sınama soruları** (ekrandan, 01:20:00). Doğru mu? sorusu "bu kararı başkası verse rahatsız olur muydum?" diye ya da geçmişteki benzer kararların sonuçlarına bakılarak sınanır. Adil mi? sorusu "bu karar bana uygulansaydı adil bulur muydum?" diye çift taraflı düşünmektir; hoca "kardeşim bana, babamın mirasından kendine istediği kadar pay versin" sözünü örnek verdi. Üçüncü soru (kim zarar görecek, kim kazanacak, bunu hak ediyor mu) faydacılık etiğine uygundur. Dördüncü soru, kararın gazetelerin ön sayfasında yer almasından rahatsız olup olmayacağınızdır. Beşinci soru kararın yakınlarınızı rahatsız edip etmeyeceğidir. Altıncı soru (karar nasıl görünüyor) için hoca, kararın doğuracağı toplumsal davranışların öngörülmesini ve kötü bir sonuç sezilirse kararın gözden geçirilmesini anlattı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
