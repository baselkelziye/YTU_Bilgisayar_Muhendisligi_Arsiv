# Ders 7 Genişletilmiş Notu: Mühendislik Etiği: Sorumluluklar ve Bilgisayar Mühendisleri İçin Etik İlkeler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Giriş: Kaldığımız Yer
- 2. Gerçekleştirme Aşamasında Etik
- 3. Gerçekleştirme Hatasına İki Tarihsel Örnek: Challenger ve DC-10
- 4. Sınama, Kurulum ve Bakım
- 5. Üretim ve Uygulama ile İlgili Sorumluluklar
- 6. Hata Kaynakları
- 7. Teknik Erekler ve Etkin Kişiler
- 8. Toplumsal Bağlam
- 9. Mühendisler ve Yöneticiler
- 10. Bilgisayar, Bilişim ve Yazılım Mühendisleri İçin Sekiz Etik İlke
- 11. Temel Etik İlkeler ve Etik Olmayan Davranışlar
- 12. Bilgisayar Etiğinin On Emri
- 13. Davranışların Etik Açıdan Yargılanması
- 14. Çalışanların Etik Olmayan Davranışları
- Örnek Sorular

## 1. Giriş: Kaldığımız Yer

Önceki derste meslek etiğinin ne olduğu, meslek odalarının buradaki rolü, mühendisliğin ne olduğu ve insan hayatına neler kattığı ele alınmış, ardından bir bilgi sistemi geliştirilirken her aşamada bilgisayar mühendisinin nelere dikkat etmesi gerektiğine geçilmişti. Ön inceleme ve fizibilite, kavram çalışması, çözümleme (analiz) ve tasarım aşamaları işlenmiş; anlatım gerçekleştirme (kodlama ve devreye almaya hazırlama, yani implementasyon) aşamasında kalmıştı. Bu ders tam bu noktadan devam ediyor.

Dersin asıl planlanan konusu kurum ve kuruluşların etik ilkelerini ele alan "kurumsal etik" idi. Hoca bu konuyu sonraki haftalara bıraktı ve bu derste meslek etiği ile mühendislik etiğinin, özellikle bilgisayar mühendisliğini ilgilendiren kısmını tamamladı.

## 2. Gerçekleştirme Aşamasında Etik

### 2.1 Hatasız yazılım yoktur

Bir bilgi sisteminin gerçekleştirilmesi hem yazılımı hem donanımı içerir (ekrandan, 00:10:00). Yazılımı geliştiren kişiler ya da takımlar, bir önceki aşamada hazırlanmış tasarım belgelerinden yola çıkarak yazılımı geliştirir. Hedef, geliştirilen yazılımın hatasız ve dayanıklı olmasıdır. Ancak hiç hatasız bir yazılımın geliştirildiği söylenemez. Hoca bunu "hatasız kul olmaz" sözüne benzetti: hatasız yazılım da olmaz. IDE'ler ve CASE araçları hata sayısını olabildiğince azaltmaya yarar, ama sıfır hatalı üretim her zaman mümkün değildir.

### 2.2 Geliştiricilerin etik olmayan davranışları

Slaytta, yazılım geliştirme aşamasında programcıların bulunabileceği etik olmayan dört davranış sayılıyor (ekrandan, 00:10:00):

- **İncelenmemiş yama.** Bazı geliştiriciler kolaya kaçmak için geçmiş projelerde yazdıkları program parçalarını "bunun aynısını zaten yapmıştım" diyerek yeni programa yamar. Bu, geliştirmeyi hızlandırır; ama yamanın yeni programa uygun olup olmadığı incelenmez ya da "ben onu zaten test etmiştim" denip umursanmaz. O başka bir projeydi, bu başka bir proje; zamanla uyumsuzluk, yanlış çalışma ya da beklendiği gibi çalışmama ortaya çıkabilir.
- **İçi incelenmemiş hazır kod.** Bazıları başkalarının hazırladığı program parçalarını olduğu gibi kullanır. Hoca bunu GitHub'dan birinin kodunu alıp yapıştırmaya, "çalıştı mı, çalıştı, devam" demeye benzetti. Kodun içinde ne olduğu ayrıntılı incelenmezse içinde zararlı bir şey ya da programın geri kalanını bozan kodlar bulunabilir; bu çok daha büyük sorunlara yol açabilir.
- **Sağlamlaştırmayı savsaklamak.** Programlar belli işlevleri yerine getirmek için hazırlanır, ama amacı sağlayan her program yeterli değildir. Program her koşulda çalışmalıdır; bunun için farklı giriş değerlerinde ve koşullarda çalışmasını sağlayacak eklemeler gerekir. Programcı "genelde çalışıyor, üç beş özel değer için uğraşmayalım, nasıl olsa kimse onları girmez" diyerek bu eklemeleri savsaklayabilir.
- **Bomba program gömmek.** Bazı programcılar "yarın öbür gün beni kovarlarsa program patlasın, onlar da çalışamasın" gibi kötü bir düşünceyle programın içine bomba gömer. Bombanın çalışma zamanını sürekli öteler; işten çıkarıldığında öteleyemeyeceği için bomba çalışır ve bütün bilgi sistemine büyük zarar verir.

Hoca bu dört durumu ikiye ayırdı. İlk üçü, etik değerlere özen göstermeyen mühendislere örnektir: bu davranışlar işletme sırasında sorunlara yol açabilir ve mühendis bu davranışlarından etik olarak sorumludur. Dördüncüsünde ise mühendis meslek etiğini bilinçli olarak, bilerek ve isteyerek çiğner.

> **Hocanın vurgusu:** Bomba program yerleştirmek yalnızca etik kuralların çiğnenmesi olarak düşünülmemeli; aynı zamanda bir suç eylemidir.

### 2.3 Donanım seçimi

İşin bir de donanım tarafı vardır. Donanım seçimi ve donanım gereksinimlerinin karşılanması da ciddi biçimde incelenmesi gereken bir konudur. "Teknik özellikleri sağlıyor ve ucuz, o yüzden bunu seçelim" yaklaşımı her zaman doğru değildir; ileride daha büyük sorunlara ve daha pahalı çözümlere yol açabilir. Bu nedenle gerçekleştirme aşamasındaki donanım seçimlerinde de bilgisayar mühendisi etiğe uygun davranmalıdır.

## 3. Gerçekleştirme Hatasına İki Tarihsel Örnek: Challenger ve DC-10

Hoca, gerçekleştirme aşamasındaki ihmallerin sonuçlarını göstermek için biri uzay çalışmalarından, biri havacılıktan iki eski ve bilinen örnek anlattı. Bu örneklere dersin ilerleyen kısmında sorumluluk türleri anlatılırken yeniden dönüldü.

### 3.1 Challenger uzay mekiği

NASA'nın Challenger mekiği fırlatıldıktan kısa süre sonra infilak etti ve içindeki 7 astronot öldü. Patlamadan sonra enkaz incelendi ve felaketin nedeni bulundu. Yakıtın sızmasını önlemek için kullanılan, yuvarlak O biçiminde bir conta vardı. Bu conta çalışma koşullarındaki beklentileri karşılayacak özelliklere (spesifikasyona) sahip değildi: yükseldikçe hava soğur ve çok düşük sıcaklıklarda contanın iyi çalışmadığı, hatta çatlayıp parçalandığı biliniyordu. Bu bilinmesine rağmen conta roketin yakıt sisteminde sızdırmazlık contası olarak kullanıldı. Ani sıcaklık düşüşüyle conta çatladı, yakıt sızdı ve mekik infilak etti. Tek bir contanın, gerçekleştirme aşamasında göz ardı edilen sorunu 7 kişinin hayatına mal oldu.

> **Ders sonrası not:** Hoca mekiğin fırlatmadan 76 saniye sonra, yerden yaklaşık 15.000 m (15 km) yükseklikte infilak ettiğini söyledi; bir yerde de "15.000 fit" dedi. Büyük olasılıkla doğru değerler yaklaşık 73 saniye ve yaklaşık 14-15 km'dir (yaklaşık 46.000-48.000 fit); yani "metre" doğru, "fit" yanlıştır. Altyazıda geçen "Challenger 8" adı da büyük olasılıkla yanlış duyma ya da yanlış söylemedir; mekiğin adı Challenger'dır.

> **Ek bilgi (derste anlatılmadı):** Challenger kazası büyük olasılıkla 28 Ocak 1986'da yaşandı. Sorunlu parça, katı yakıtlı yardımcı roketlerin bağlantı yerlerindeki O-halka contalardı. Fırlatma sabahı hava olağandışı soğuktu ve conta üreticisi firmanın mühendisleri soğukta fırlatmaya karşı çıkmıştı.

### 3.2 THY'nin DC-10 kazası

McDonnell Douglas firmasının DC-9 ve DC-10 serisi uçakları vardı; artık üretilmiyorlar. DC-10, geniş gövdeli büyük bir yolcu uçağıdır. Firma, alt kısımdaki bagaj kapaklarının üretimini Convair adlı bir firmaya yaptırıyordu (altyazıda "Corvair"). Orada kapağın üretiminden sorumlu kıdemli mühendis Dan Applegate, kapağın tasarımında sorun olduğunu fark etti: kilitlenme mekanizması yanlış çalışıyordu ve özellikle yükseklikte basınç değiştiğinde kilidin kırılma olasılığı yüksekti. Kapağın yeniden tasarlanması gerektiğini yöneticilerine bildirdi.

Yöneticiler bunu kabul edip bir değişim programına aldı. Ancak bu sırada çok sayıda DC-10 serviste uçuyordu; bunlardan biri de Türk Hava Yolları'nın uçağıydı. Kapaklar belli bir sırayla değiştiriliyordu ve Applegate'in uyarısının üzerinden yaklaşık iki yıl geçmişti. Yöneticiler bu sürede bir kaza olmasını öngörmedi. Sonunda Paris'ten Londra'ya giden THY uçağının bagaj kapağı havada açıldı. Hoca bunu düdüklü tencereye benzetti: uçak yükseldiğinde kabin basıncı nedeniyle içerisi düdüklü tencere gibidir; kapak açılınca lastiği yırtılan tencere gibi basınç bir anda boşalır. Uçak havada parçalandı ve 346 kişi öldü.

Hoca iki örneği şöyle bağladı: gerçekleştirme aşamasındaki bazı sorunlar bazen 7 astronotun, bazen de hiçbir günahı olmayan 346 yolcunun ölümüne yol açabilir.

> **Ders sonrası not:** Hoca, McDonnell Douglas'ın bu kaza yüzünden iflas ettiğini söyledi. Büyük olasılıkla bu doğru değildir: şirket kazadan sonra da uçak üretmeye devam etti ve 1997'de Boeing ile birleşti.

> **Ek bilgi (derste anlatılmadı):** Bu kaza büyük olasılıkla 3 Mart 1974'te Paris yakınlarında düşen THY 981 sefer sayılı uçuştur. Applegate'in uyarısı, kazadan yaklaşık iki yıl önce (1972) yazdığı ve "Applegate memorandumu" olarak bilinen iç yazıdır.

### 3.3 Yazılım için neden önemli?

Hoca, "bunlar uçak ve roket; yazılımda en kötü ihtimalle program çalışmaz" itirazına karşı çıktı. Günümüzde pek çok sistem yazılımla denetleniyor: hava trafiği denetimi, trafik ışıkları, hastanede birimlere oksijen dağıtımı gibi. Böyle bir yazılımda gerçekleştirme aşamasında bir mühendisin "aman canım, ne olacak" deyip bir sorunu savsakladığını düşünün; bu can kaybına yol açabilir. Bu yüzden mühendislik etiği ilkelerine gerçekleştirme aşamasında da çok dikkat etmek gerekir.

## 4. Sınama, Kurulum ve Bakım

Bu aşamalar test, devreye alma ve bakımdır (ekrandan, 00:25:00).

### 4.1 Sınama

Büyük ölçekli bilişim sistemleri işletmeye alınmadan önce kesinlikle sınanmalıdır. Sınamalar, sistemi geliştirenlerin dışındaki ve onlardan bağımsız kişilerce yapılmalıdır. Hoca bunu bir bitirme tezi yazmaya benzetti: kendi yaptığınız hatayı beş kez okusanız da görmeyebilirsiniz, çünkü o hatayı siz yaptınız ve metin sizin eserinizdir. Ama ailenizden biri ya da bir arkadaşınız okuduğunda "burada ne demek istedin, bu yanlış" diyebilir.

Sınama mühendislerinin görevi, hazırlanmış yazılımı ya da daha geniş anlamda bütün bilişim sistemini her koşul altında çalışıp çalışmayacağı yönünden sınamaktır. Sınamada ortaya çıkan kusur ve hatalar mutlaka geliştiricilere geri bildirilir ve giderilmeleri istenir. Sorunlar giderildikten sonra sınama yinelenir.

> **Hocanın vurgusu:** Sınama sürecinde "gözden kaçmış", "bunu denememişim" gibi bir mazeret kabul edilemez. Uçak ve uzay mekiği örneklerinde olduğu gibi sonuç çok ağır olabilir.

### 4.2 Kurulum ve işletmeye alma

Kurulum ve işletmeye alma sırasında da sorunlarla karşılaşılabilir. Sorunların kaynağı saptanır ve ilgili bölüme ya da yetkiliye bilgi verilerek giderilmesi sağlanır. Bazen ticari kaygılarla sorunlar savsaklanır: "Lansmanı mutlaka şu tarihte yapmamız lazım, yapalım, sonra şurasını burasını düzeltiriz" denebilir. Hoca bir köprünün belirlenen tarihte açılıp lansmanından sonra aylarca inşaatın sürdüğünü, trafiğin tek şeritten verildiğini örnek verdi. Sonra sorunlar ortaya çıkmaya başladığında, kimin savsaklaması yüzünden bu olayın yaşandığı bir soruşturmayla anlaşılır.

### 4.3 Bakım

Bilişim sistemi tamamen çalışır ve devrededir. Özellikle yazılım kısmındaki bazı hatalar, gerçekleştirme ve sınama aşamasında bulunamayıp ancak kullanım sırasında, örneğin yük altında ortaya çıkar. Bunları düzeltmek için yama (patch) ve güncellemeler hazırlanır. Kusursuz yazılım olmadığı için bu tür kusurlar belli bir nitelik ve niceliğe kadar olağan karşılanır.

Etik davranış şudur: kusur ortaya çıktığında sistemi kullananlar hemen uyarılmalı, gerekli yama ve güncellemeler hemen hazırlanıp sunulmalıdır. Ticari kaygılarla hataları gizlemek ya da yamaları zamanında dağıtmamak etik değerlere uymaz. Hoca örnek olarak işlemcilerdeki güvenlik açıklarını verdi: açıklar bilinmesine rağmen bir süre örtbas edilmeye çalışıldı ve güncelleme çok yavaş ilerledi. <!-- BELİRSİZ: Altyazıda "Intel Mintel" geçiyor; büyük olasılıkla Intel işlemcilerindeki Meltdown/Spectre açıkları kastediliyor. -->

## 5. Üretim ve Uygulama ile İlgili Sorumluluklar

### 5.1 Rol temelli sorumluluk

Mühendislik üretiminde mühendis yalnızca karar verip kararlarının uygulanmasını sağlayamaz. İşin içinde yöneticiler, uygulayıcılar ve sistemi çalıştıran operatörler de vardır ve bunların sonuç üzerinde büyük yetki ve sorumlulukları bulunur. Genellikle yöneticilerin kararı daha baskındır. Üretim ve uygulama sırasında görev alanlar, üstlendikleri görevle bağlantılı sorumluluk taşır; bu tür sorumluluğa **rol temelli sorumluluk** denir (ekrandan, 00:30:00).

Her ürün (bir taşıt, bir üretim sistemi ya da bir bilişim sistemi) kullanılmaya başlandığında bazı sorunların çıkabileceği kabul edilir. İnsanların beklentisi sistemin hiç sorun çıkarmamasıdır, ama sıfır sorunlu bir sistem oluşturulamaz. Sorun ürünün kendisinden de, uygun olmayan kullanım biçiminden de kaynaklanabilir. Bir sorun oluştuğunda nedenini araştırmak sonraki çalışmalar için öğretici olduğundan önemlidir; sorunun kaynağını ilgililere açıklamak da ayrı bir sorumluluktur.

### 5.2 Edilgen ve etken sorumluluk

- **Edilgen sorumluluk:** Sistem kullanılırken ortaya çıkan bir sorunu araştırmakla ilgili sorumluluktur. Sistem zaten yapılmış ve çalışmaktadır; sorun sonradan ortaya çıkmıştır ve araştıran kişi edilgen durumdadır.
- **Etken sorumluluk:** Üretim sırasında sorun oluşturabilecek şeyleri görebilmek, gerekli önlemleri almak ve sorun oluşturabilecek kısımla ilgili bilgileri üst yönetime iletmektir. Üretim aşamasında görev alanların sorumlulukları etken sorumluluk olarak tanımlanır.

### 5.3 Örneklerle sorumluluk türleri

**Challenger.** Contanın sıcaklık belli bir değerin altına düştüğünde çatlayacağını ve yakıt sızıntısına yol açabileceğini bir mühendis proje gerçekleştirilirken, yani üretim aşamasında fark etti ve üstlerine aktardı. Bu mühendis etken sorumluluğunu ve mesleki sorumluluğunu etik olarak yerine getirmiştir. Ancak conta üreticisi firma ile program yöneticileri arasında iletişim sorunları vardı. Ayrıca program başka sorunlar yüzünden birkaç kez ertelendiği için herkes roketi havada görmek istiyordu ve yöneticiler üzerinde büyük bir baskı vardı. "Madem bu kadar ertelendi, artık yapmamız lazım" denip küçük bir conta göz ardı edildi; astronotlar hayatını kaybetti, belki milyarlarca dolarlık bir proje çöpe gitti. Patlamadan sonra sorunun nereden kaynaklandığı, ilgilisinin kim olduğu örtbas edilmeden araştırıldı; bu da edilgen sorumluluk kapsamındaki faaliyetlerdir.

**DC-10.** Applegate sorunu görüp yöneticilere bildirdi ve kapağın yeniden tasarlanması gerektiğini söyledi; etken sorumluluğunu tamamen yerine getirdi. Yöneticiler de kapakları yeniden tasarlatıp uçaklara sırayla taktırdı. Ancak kaza riski öngörülmediği için uçağı işletenler (ör. THY) uyarılmadı. Hoca, uyarılsalardı uçağı hangara çekip bekletebileceklerini, operasyonda kullanmayabileceklerini söyledi. Uçak düştükten sonra nedeni toplumla paylaşıldı; bu yüzden edilgen sorumluluk da yerine getirilmiştir.

**Boeing 737.** Hoca, aradaki kısa bir parantezde daha yeni bir örnekten söz etti: bir Boeing 737 modelinin uçakları birkaç kez düştü. Uçakta hız ve yükseklik için birkaç sensör vardır; sensörlerden farklı veriler geldiğinde yazılım "sapıtıyor" ve otopilota burnu kaldırma ya da indirme gibi yapmaması gereken komutlar veriyordu. Hoca bu vakada etken sorumluluğun pek işletilmediğini, nedenin sonradan yapılan incelemelerle ortaya çıkarıldığını söyledi. Sorun bilinip duyurulduğu için dünyadaki pek çok havayolu bu uçakların uçuşlarını hemen durdurdu; ardından kapsamlı güncellemeler, testler ve yeni sınamalar yapıldı ve uçak yeniden güvenlik sertifikası aldı.

> **Ders sonrası not:** Hoca modeli "737'nin Next Generation denen, kompozit gövdeli yeni modeli" diye andı ve uçağın havada infilak ettiğini söyledi. Büyük olasılıkla söz konusu model 737 MAX'tır (Next Generation daha önceki bir seridir ve gövdesi kompozit değildir). Sorunlu yazılım MCAS, yanlış veri veren sensör hücum açısı (angle of attack) sensörüdür; uçaklar havada patlamamış, yere çakılmıştır. <!-- BELİRSİZ: Altyazıda 00:35:20 ile 00:35:48 arasında bir boşluk var; 737 örneğinin başı kayıtta eksik olabilir. -->

**İnternet bankacılığı vakası.** Önceki derste anlatılan vakaya dönüldü. Bankada girişte SMS ile doğrulama yapılıyordu. İş birimi, müşteriler cep telefonu numaralarını sık değiştirdiği için numaranın internet şubesinden değiştirilebilmesini istedi. Bankadaki bilgisayar mühendisleri buna kesinlikle karşı çıktı: bu, anahtarı ve kilidi aynı zarfta yollamak gibidir; telefon numarası mutlaka doğrulanmış başka bir kanaldan güncellenmelidir, yoksa kötü niyetli biri numarayı değiştirip kullanabilir. İş birimi "bana işimi mi anlatacaksın" diyerek kendi istediğini yaptırdı. Mühendisler sorunu defalarca açıkça belirterek etken sorumluluklarını sonuna kadar yerine getirdi; sonradan yapılan inceleme (edilgen sorumluluk) de mühendislerin haklı olduğunu ortaya koydu.

### 5.4 Sonuç: "Benden çıktı" denemez

Bir mühendis bir sistem geliştirdiğinde "bitti, artık benden çıktı" diyemez; araba, uçak ya da bilişim sistemi için durum aynıdır. Bilişim sistemlerinde devreye almadan sonraki bütün yaşam süresine bakım ve destek süreci denir. Bu süreçte hata varsa gidermekle yükümlüyüz ve kusuru gizlememeliyiz. "Kervan yolda düzülür, ürünü çıkaralım, hata oldukça düzeltiriz" yaklaşımıyla hareket eden bir firmanın etik kuralları çiğnediği rahatlıkla söylenebilir. Üretim ve uygulamadan sonra da sorumluluk sürer; edilgen sorumluluk hâline gelse de devam eder.

## 6. Hata Kaynakları

Hoca, sorunların nereden kaynaklanabileceğini dört başlıkta topladı.

- **Üretim hataları.** Uzay mekiğindeki contanın, soğukta çalışmadığı bilinmesine rağmen yanlış seçilmesi (hoca bunun belki başka kasıtlarla bilerek yapılmış bir hata olabileceğini de söyledi); DC-10'un bagaj kapağının tasarımındaki, belki bilmeden yapılmış hata; internet bankacılığındaki telefon numarası değiştirme kuralının yanlış kurgulanıp işletilmesi.
- **Yanlış kararlar.** Sorun çıkarma olasılığı olan bir fiziksel donanımı, parçayı ya da yöntemi bilerek uygulatmak ya da uygulamaktır. Genellikle yöneticiler tarafından verilir. Örnekler: sorun olduğunu bile bile uçuşlara devam ettirmek ve uçağı işleten firmalara yeterli bilgiyi vermemek; bankadaki mühendislerin "bu güvenlik açığıdır" uyarısına rağmen "böyle yapılacak" demek.
- **Öngörü.** Üretimde hata ya da yanlış karar olmasa bile ürün kullanılırken bazı sorunlar çıkabilir. Bunları öngörmek deneyim gerektirir; kötü olaylar edilgen sorumluluk gereği incelendikçe deneyimsizlikten ya da öngörü eksikliğinden kaynaklanan hatalara sık rastlanır. Hoca bir çamaşır makinesi örneği verdi: her şey doğru üretilmiş, yanlış karar yok; ama motordan kazana giden kayış, sürekli bin devire çıkıp sıfıra inmeyi bir yıl boyunca tekrarlayınca çatlıyor ya da kırılıyor. "Bu malzeme ileride esner", "bu algoritma, framework ya da API ileride şu sorunu çıkarır" diyebilmek öngörüdür; öngörememek bir hata kaynağıdır.
- **Eylem özgürlüğü.** Ürün kullanılırken bazı noktalarda uygulayıcının seçenekler arasından karar vermesi gerekir. Karar verme özgürlüğüne sahip kişi bilerek ve isteyerek yanlış yolu seçip soruna yol açıyorsa, sonuçlardan kendisi sorumludur.

## 7. Teknik Erekler ve Etkin Kişiler

### 7.1 Teknik erekler

Erek, ulaşılmak istenen hedef ya da hayaldir (ekrandan, 00:45:00). Mühendisler genellikle yeniliğe açık, heyecanlı kişilerdir; özellikle genç mühendislerin bu tür ereklerinin olması doğal karşılanmalı, hatta desteklenmelidir, çünkü çoğu buluş mühendislerin erekleri sonucunda gerçekleşmiştir. Ereklerine ulaşmak için hayatını tehlikeye atanlar, hatta ölenler bile olmuştur.

Ancak tek kişilik buluşların dönemi geçmiştir; günümüzde karmaşık ürünler takım çalışmasıyla ortaya konur. Takımda çok heyecanlı bir mühendisin bulunması doğaldır, ama onun hedef ve istekleri deneyimli mühendislerce değerlendirilmelidir. Hoca örnek olarak "10.000 fit yerine 15.000 fite çıksın", "kanadı şöyle yapalım", "iOS'u da desteklemek için şunu da ekleyelim" gibi istekleri verdi; bunlar uygulamanın genelinde sorunlara yol açabilir.

> **Hocanın vurgusu:** Salt bireysel heyecanı için projenin içeriğini değiştiren bir mühendis etik olarak doğru davranıyor sayılamaz; deneyimli mühendislerin bunu denetlemesi gerekir.

### 7.2 Etkin ve uzman kişiler

Kuruluş içinde bazı çalışanlar diğerlerine göre daha etkin konumdadır: yöneticiler ve kuruluş sahipleri ("patron ne derse o olur"). Bazı kişiler ise bazı konularda uzmandır ama yetkileri kısıtlıdır. Bankadaki bilgisayar mühendisi buna örnektir: uzmandır, uyarmıştır, ama projeyi durdurma yetkisi yoktur; daha baskın olan iş biriminin dediği yapılmıştır. Bir projenin başarıya ulaşması için etkin kişilerin uzmanların uzmanlığını da değerlendirerek karar alması gerekir. Etkin kişilerin etkinliklerini kullanarak projeyi yönlendirmesi etik bir davranış değildir.

## 8. Toplumsal Bağlam

Her ürün üretilirken toplum sağlığı göz önünde bulundurulmalıdır; hoca, etik değerlerde ilk önce kamunun geldiğini hatırlattı (ekrandan, 00:50:00). Üretilecek ürünün kendisi ya da türevleri toplum için zararlı sonuçlar doğurabilir. Kimyasal madde, silah ve patlayıcı üretimi gibi konuların toplum için yararlı mı zararlı mı olduğu her zaman tartışılır. Bazı mühendisler yüksek erek içgüdülerinin esiri olarak, yaptıkları araştırmaların ve ürünlerin nerede ve ne amaçla kullanılacağını düşünmez. Hoca en güzel örnek olarak İkinci Dünya Savaşı'nda büyük bir hevesle geliştirilen atom bombaları, roketler, mayınlar ve uzaktan kumandalı silah sistemlerini verdi.

Bilişim sistemlerinin ilk bakışta topluma zarar verebileceği düşünülmeyebilir; ama bazı bilişim uygulamaları bir bomba kadar, hatta daha güçlü etkilidir. Slayttaki örnekler:

- Bir ülkenin elektrik dağıtım sisteminin yönetimini izinsiz ele geçirecek bir bilişim sistemi oluşturmak. Hoca burada ABD'de bir santralin devreden çıkmasıyla oluşan yük değişiminin şebekeye dağıtılamadığı ve sistemlerin domino gibi devreden çıkarak büyük bir elektrik kesintisine yol açtığı olayı ve İran'ın nükleer programını hedef alan Stuxnet'i hatırlattı.
- Bir internet hizmet sağlayıcısının ilettiği e-postaların içeriklerini okuyup değerlendirmek üzere program hazırlamak.
- Hava yolu trafik sistemini ele geçirecek bir yazılım hazırlamak.
- Şehir içi trafik sistemini ele geçirecek bir yazılım hazırlamak.

> **Ders sonrası not:** Hoca ABD'deki büyük elektrik kesintisinin "galiba 10 yıl önce" olduğunu söyledi. Büyük olasılıkla kastedilen 2003 Kuzeydoğu ABD kesintisidir; bu da ders tarihinden yaklaşık 18 yıl öncedir. Hoca Stuxnet için "Amerika hacklemişti" dedi; büyük olasılıkla bu saldırı yaygın olarak ABD ve İsrail'e atfedilir, ama resmî olarak doğrulanmamıştır.

> **Hocanın vurgusu:** Bir mühendis "ben işimi yaparım, gerisi beni ilgilendirmez; ben kodumu yazarım, hayatıma devam ederim" diyemez. Yaptığı sistemin doğuracağı sonuçların sorumluluğunu taşıdığını bilmeli ve toplumsal bağlamı her zaman göz önünde tutmalıdır.

## 9. Mühendisler ve Yöneticiler

### 9.1 Kuruluştaki sınıflar

Bir kuruluşta yöneticiler (CEO, CTO, CFO gibi "CXO"lar), mali işlerden sorumlu kişiler ve mühendisler birlikte çalışır (ekrandan, 00:55:00). Bu sınıfların etkinlikleri ve yeterlilikleri farklıdır. Mühendisler sistem tasarlama ve gerçekleştirme konusunda uzmandır; bu nedenle kuruluşta üretim yapan sınıf olarak görülürler. Hoca bunu "biz işin mutfağıyız; mutfak olmadan hiçbir şey üretilemez" diye anlattı. Yöneticiler farklı meslek gruplarından gelebilir: mühendis kökenli de (hocaya göre bu daha iyidir), sosyal bilim kökenli de olabilirler. Mali konulardan sorumlular doğal olarak işletme, iktisat, muhasebe gibi alanlarda eğitim görmüştür.

### 9.2 Banka örneği

Yöneticiler mühendislik alanından gelmiyorsa mühendislerle zaman zaman anlaşmazlığa düşebilir. Hoca bankaları örnek verdi. Türkiye'de bankacılık 1920'lerden itibaren gelişti; 1960'larda merkezi bilgisayarlar yaygınlaşıp bankalarda kullanılmaya başlandı. O dönemde bankacılar için önemli olan mali işlemlerdi ve bilgisayar güçlü bir hesap makinesi gibi görülüyordu. Bilgi işlem merkezinde çalışanlar da faiz hesabı, gelir hesabı, tablolar gibi hesapları otomatikleştiren programları yazmak ve işletmekten sorumlu kişiler olarak görülüyordu. Zamanla bilgisayarlar o kadar güçlendi ve merkeze geldi ki bilgisayarsız hiçbir iş yapılamaz oldu; bilgi işlem merkezi bilgi sistemine dönüştü ve bilgisayar mühendisleri pek çok yeni fikir ve proje üretmeye başladı.

Artık banka yöneticileri mühendislere "siz benim için güçlü bir hesap makinesinden başka bir şey değilsiniz, ben ne dersem o olur" diyemez. Mühendislerin yeteneklerini görmezden gelirlerse büyük hatalar yaparlar. İnternet bankacılığı vakasında mühendisler "bunu yapmayın, güvenlik açığı doğurur" demiş, yöneticiler dinlememiş; suç oluşmuş ve sorumluluk doğrudan bankada görülmüştü.

### 9.3 Görev paylaşımı

Bir kuruluşta yetkisi ve dolayısıyla etkisi olan kişiler mühendislerin yetkinliklerini dikkate almak zorundadır. "Yönetici benim, benim dediğim yapılacak" mantığı çok büyük zararlara yol açabilir. Kuruluş içinde herkes yetkisini, birikimini ve yeteneğini bilerek çalışmalı ve karar vermelidir; bu kurala **görev paylaşımı** denir. Günümüzde mühendis kökenli yöneticiler belli iş kollarında görev almaktadır ve bu kuruluşlarda yönetici-mühendis çatışmalarının daha az olduğu söylenebilir.

Birlikte çalışılan ortamlarda fikir çatışması olacaktır. Bunlar mantıklı fikir çatışmaları olabileceği gibi duygusal çatışmalar da olabilir; üst yöneticilerin bunların mantıklı olup olmadığına düzgün biçimde karar vermesi gerekir. Ancak üst yöneticiler de her zaman mantık çerçevesinde karar vermeyebilir. Hoca mühendis olarak objektif olmayı her zaman desteklediğini söyledi. İş hayatında bazı kişiler başkalarının başarısını kıskanabilir, onların başarısız olması için çalışabilir, olumsuz yönlerini bulup bire bin katarak üst yönetime aktarabilir, hatta yalan ve iftiraya başvurabilir. Bunların etik kurallarla bağdaşmadığı açıktır.

## 10. Bilgisayar, Bilişim ve Yazılım Mühendisleri İçin Sekiz Etik İlke

### 10.1 Kaynak ve amaç

Bilgisayar mühendisliği ve benzeri dallar (bilişim mühendisliği, yazılım mühendisliği, bilgi sistemleri mühendisliği vb.) için etik kuralları meslek örgütleri ortaya koymuştur. Temel kaynak IEEE Computer Society (IEEE-CS) ve ACM'nin (Association for Computing Machinery) hazırladığı kurallardır (ekrandan, 01:00:00). Hoca bunları tek tek değil, bir bileşke hâlinde sundu.

Amaç, yazılım mühendislerinin uyması gereken sorumluluk ve etik kuralları açıklamaktır. Mesleğin saygın bir meslek olması için mühendislerin projenin tüm aşamalarında (kavram geliştirme, gereksinimleri belirleme, çözümleme, tasarım, gerçekleştirme, sınama, uygulamaya alma ve bakım) sorumluluklarını bilmeleri ve etik değerlere göre hareket etmeleri istenir. Bir mühendis, halkın refahı, güvenliği ve sağlığına öncelik vererek aşağıdaki sekiz ilkeye bağlı kalmalıdır (ekrandan, 01:00:00):

1. **Kamu:** Kamu çıkarlarına uygun davranmalıdır. Bu nedenle yaptığı işin tüm sorumluluğunu üstlenmelidir.
2. **Müşteri ve İşveren:** Kamu çıkarına ters düşmemek koşuluyla müşteri ve işverenin çıkarına uygun davranmalıdır.
3. **Ürün:** Geliştirilecek ürünün kalitesinin ulaşılabilecek en üst düzeyde olması hedeflenmelidir.
4. **Yargı:** Yargıları tutarlılık ve bağımsızlık ilkesine uygun olmalıdır.
5. **Yönetim:** Yöneticiler yazılım geliştirme ve bakım ile ilgili yöntemlere uygun çalışmayı benimsemeli ve etik kurallara uymalıdır.
6. **Meslek:** Mesleğinin ününü toplumun çıkarlarını sağlayacak biçimde yükseltmelidir.
7. **İş arkadaşları:** Meslektaşlarına karşı adil ve destekleyici olmalıdır.
8. **Özü:** Yaşam boyu öğrenmeyi benimsemeli ve mesleği ile ilgili etik değerlerini geliştirmelidir.

> **Ek bilgi (derste anlatılmadı):** Bu sekiz ilke, büyük olasılıkla 1999'da IEEE-CS ve ACM ortak çalışmasıyla yayımlanan "Software Engineering Code of Ethics and Professional Practice" belgesine dayanır. Belgede "Özü" ilkesinin İngilizce karşılığı "Self"tir.

### 10.2 İlkelerin ayrıntısı

**Kamu.** Toplum her şeyin üstündedir. Örneğin üretilen bir yazılıma testler sonunda ancak şunlar sağlanıyorsa onay verilmelidir: sistem güvenli ve güvenilirdir; gereksinimleri karşılar; yaşam kalitesini azaltmaz; özel hayata saygılıdır (hoca burada KVKK'ya değindi); çevreye saygılıdır. Bunlara "tamam" denemiyorsa sistem kamu çıkarına uygun değildir ve onay verilmemeli, reddedilmelidir. Ayrıca yazılımla ilgili bütün belgelerde açık olunmalı, yalan ifade bulunmamalıdır.

**Müşteri ve işveren.** Kamu her zaman önde tutulmak koşuluyla müşteri ve işverenin çıkarına uygun davranılır. Yasa dışı ya da etik olmayan yollarla elde edilmiş açık ya da kapalı kaynaklı programlar kullanılmamalı; müşteri ya da işverenin sağladığı özel olanaklardan kişisel olarak yararlanılmamalı; fikri mülkiyet haklarına saygı gösterilmeli; gizlilik kurallarına uyulmalıdır.

**Ürün.** Ürünün kalitesi olabilecek en üst düzeyde hedeflenir. Mantıklı ve ölçülü bir bedel ve zaman talep edilir: bir ayda yapılabilecek bir iş için, yedi ay yatmak üzere "sekiz ay verin" denmez. Projeyle ilgili etik, ekonomik, kültürel, yasal ve çevresel kısıtlar net biçimde belirlenir. Projedeki elemanların gereksinimlere uygun özellikleri taşımasına dikkat edilir. Teknik şartnameler kesin ve anlaşılır tutulur ve müşteriyle karşılıklı onaylanır. Teknik, maddi ve zamanla ilgili konuların hepsinde müşteri ya da işverenle düzgün bir anlaşma sağlanır.

**Yargı.** Yargılar tutarlı ve bağımsız olmalı, gereksinimleri, özellikle insan gereksinimlerini desteklemelidir. Bir yazılım ya da belge değerlendirilirken adil davranılmalıdır. Rüşvet, sahtecilik gibi uygun olmayan finansal işlere karışılmamalıdır. Çıkar çatışması olan durumlarda kişi ortamda bulunmamalı ya da kendini işten çekmelidir. Hoca güncel bir örnek verdi: bir bakan kendi şirketinin bir ürününü bakanlığa satmış ve bu kabinede değişikliğe yol açmıştı. Ürün iyi de olabilir kötü de; ama kişi hem satan tarafta hem de alan kurumda karar mercii olduğu için çıkar çatışması vardır ve bunu yapmamalıdır.

**Yönetim.** Yöneticiler projeyi iyi yönetmeli; metrikler ve hedefler konusunda çalışan bütün mühendisleri bilgilendirmeli; kuruluş politikalarını çalışanlara bildirmeli; eğitim ve becerilerine göre görev vermeli; teklif edilen projeler için zaman, kaynak ve bedel önerilerini mantıklı ve gerçekçi yapmalı; maaşların adil olmasını sağlamalı; çalışanların fikri mülkiyet haklarını gözetmelidir. Kuruluşun etik değerlerine uymayan davranışlar için disiplin soruşturması ya da cezalandırma gibi gerekli işlemler yapılmalı, çalışanlardan kurallara aykırı isteklerde bulunulmamalıdır. Etik kaygısını açıklayan kınanmamalı ve cezalandırılmamalıdır: Applegate gibi bir mühendis "bu kapak yanlış" dediğinde "bizim kapaklarımız hep doğrudur, git işine" denmemeli, uyarı değerlendirilmelidir.

**Meslek.** Mesleğin ünü toplumun çıkarları gözetilerek yükseltilmeli; bunun için meslek örgütleri (ör. bilgisayar mühendisleri odası) desteklenmelidir. Meslek doğru tanıtılmalıdır; hoca "bilgisayar mühendisiyim" deyince ilk "bizim oğlana bir laptop alacağız, ne alalım?" sorusuyla karşılaşıldığını söyleyerek mesleğin ne olduğunun düzgün anlatılması gerektiğini vurguladı. Mesleki bilgi birikimini artırmak için mesleki toplantılara (akademik dünyada sempozyumlara) katılınmalıdır. Mesleğin çıkarı işveren ya da müşterinin çıkarının önüne konmamalı, yasalara ve yönetmeliklere uyulmalıdır. Örneğin üzerinde çalışılan bir yazılımda hata bulunduysa bu ortaya çıkarılmalı, gizlenmemeli, örtbas edilmemelidir.

**İş arkadaşları.** Meslektaşlara adil ve destekleyici olunmalı, onlar kurallara uymaya özendirilmeli ve gelişimleri desteklenmelidir. İş arkadaşlarının görüş, kaygı ve eleştirilerine saygı gösterilmeli; kuruluş politikalarına uygunluk konusunda gerektiğinde uyarılmalıdırlar. Kişi yetersiz kaldığı konularda iş arkadaşlarına ya da konunun uzmanlarına danışmayı bilmelidir.

**Özü (kendisi).** Etik değerlerin eskimemesi ve unutulmaması için çalışılmalıdır. Yazılım geliştirme süreçleriyle ilgili bilgiler sürekli geliştirilmelidir; hoca güncel standart olarak DevOps ve CI/CD'yi bilmenin ve kullanmanın gerektiğini söyledi. Güvenilir ve düşük maliyetli yazılım üretme yeteneği ve belgeleme yeteneği geliştirilmeli; bu konudaki yasalar, yönetmelikler, ölçütler, metrikler ve standartlar öğrenilmeli; önyargılı olunmamalı, açık olunmalıdır.

## 11. Temel Etik İlkeler ve Etik Olmayan Davranışlar

### 11.1 Temel etik ilkeler

Hoca meslek ve mühendislik etiği açısından temel ilkeleri hızlıca sıraladı ve ayrıntılı okumayı öğrencilere bıraktı:

- **Adalet:** Sorumluluğu eşit ve haklı biçimde paylaşmak; yöneticiyse adil dağıtım yapmak.
- **Eşitlik:** Yarar, sıkıntı ve hizmetlerin eşit dağıtılması; kayırma ve ayrım yapmamak.
- **Dürüstlük:** Herkese karşı doğru olmak.
- **Tarafsızlık:** İş arkadaşlarına yansız bakmak.
- **Sorumluluk:** Verilen görevi sorumluluk sahibi olarak yerine getirmek.
- **Bağlılık:** Mesleğe bağlı olmak, ilerlemeye istekli olmak; toplantılara, yayınlara ve kendini geliştirme faaliyetlerine katılmak.
- **Sevgi:** İşini ve iş arkadaşlarını sevmek, gelişmeleri için istek duymak.
- **Hoşgörü:** Hoca bunu "kendinizi onun yerine koyun; hoşunuza gider mi, gitmez mi?" diye özetledi.
- **Saygı:** İnsan oldukları için herkese saygılı olmak.
- **Tutumluluk:** Kaynakları verimli kullanmak.
- **Açıklık:** Görüşleri muğlak değil açıkça ifade etmek; eleştirileri amaçlı, yansız ve çıkarsız yapmak.
- **Emeğin karşılığı:** Emeğin hakkını, emekle orantılı olarak ödemek.
- **Yasa ve etik dışı emirlere karşı gelmek:** Yasalara ve etik kurallara aykırı isteklere direnme hakkı her zaman vardır.

<!-- BELİRSİZ: Temel ilkeler slaytının karesi yok (01:10:21-01:12:41 arası); liste altyazıdaki anlatımdan kuruldu. -->

### 11.2 Etik olmayan davranışlar

Slayttaki liste (ekrandan, 01:15:00):

- İş kalitesini önemsememek.
- Ürün sorumluluğunu ve güvenliğini önemsememek.
- Kurum varlıklarını kötü biçimde kullanmak.
- Görevi ihmal etmek.
- İş yerinde ayrımcılık yapmak.
- Çalışanlara eşit davranmamak.
- Kurumun olanaklarını kişisel amaç için kullanmak.
- Özel yaşama müdahale etmek.
- Rüşvet istemek veya vermek, hediye almak ve ağırlamak.
- Yanlış bilgilendirmek ya da bilgi saklamak.
- Belge ve raporlarda çıkar amaçlı değişiklik yapmak.
- Yetkisini kötüye kullanmak.
- Yetkililerle etik dışı ilişki kurmak.
- Çıkar çatışmalarına girmek.
- İş arkadaşlarını yıldırmak, korkutmak.
- İş arkadaşlarını sömürmek.
- İş yerinde hırsızlık yapmak.
- Ticari ya da mesleki sırları sızdırmak.
- Rakiplerle ilgili bilgilerin toplanmasında etik dışı yöntemler kullanmak.
- İş arkadaşları hakkında yalan ve karalayıcı söylemde bulunmak.
- Kurumdakilere karşı hakaret ve kaba sözler söylemek.
- Cinsel tacizde bulunmak.

Hoca bazı maddeleri açtı. Çalışanlara eşit davranmak bir yönetici için gerçekten zordur: işi iyi yapana genellikle daha çok iş verilir, yatana az iş verilir; bu yüzden dikkatli olunmalıdır. Belge ve raporlarda çıkar amaçlı değişikliğe, "hocam şurayı şöyle yazsan, seni arkadan görürüz" denerek yazdırılmak istenen bir bilirkişi raporu örnek verildi. Çıkar çatışmasına bakan örneğinin yanında hoca kendi alanından bir örnek verdi: bir öğretim üyesi bir firmaya danışmanlık yapıp onlarla proje geliştirirken, aynı firmanın TÜBİTAK'a yaptığı başka bir proje başvurusuna hakem olarak atanırsa bu çıkar çatışmasıdır. Firmayı ve iş yapış biçimini bildiği ve oradan para kazandığı için yanlı değerlendirme yapabilir; bu yüzden hakemliği reddetmelidir.

## 12. Bilgisayar Etiğinin On Emri

Washington DC'deki Computer Ethics Institute (Bilgisayar Etiği Enstitüsü), Musevilikteki on emre gönderme yaparak bilgisayar etiği için on emir yazmıştır. Hoca maddeleri yorumlayarak sıraladı:

1. Bilgisayarı diğer insanlara zarar vermek için kullanma. (Kamu ilkesinin başka bir dille söylenişi.)
2. Başkalarının bilgisayar çalışmalarını engelleme. (İş arkadaşları ve rakiplerle adil çalışma.)
3. Başkalarının bilgisayar dosyalarını araştırmaya kalkma. (İzin olmayan şeylere, örneğin başkasının e-postalarına burnunu sokma.)
4. Bilgisayarı hırsızlık amacıyla kullanma.
5. Yalancı tanıklık için bilgisayarı kullanma.
6. Parasını ödemediğin yazılımı kopyalama ve kullanma. (Lisans bedeli.)
7. Başkalarının bilgisayar kaynaklarını izin almadan ve gerekli ödemeyi yapmadan kullanma. (Hoca, "bu programı kullan, karşılığında senin CPU'nu bitcoin için kullanacağım" örneğini verdi.)
8. Başkalarının telif çalışmalarının üstüne konma. (Fikri ve sınai haklar.)
9. Yazdığın programın veya tasarladığın sistemin sosyal sonuçlarını düşün. (Yine kamu; atom bombası örneği.)
10. Bilgisayarı her zaman insanları düşünerek ve insanlara saygı göstererek kullan. (Çevre, kamu, toplum ve insan önceliği.)

<!-- BELİRSİZ: On emir slaytının karesi yok (01:16-01:18 arası); maddeler altyazıdaki anlatımdan aktarıldı. -->

> **Ek bilgi (derste anlatılmadı):** Bilgisayar etiğinin on emri büyük olasılıkla 1992'de Computer Ethics Institute adına Ramon C. Barquin tarafından yayımlanmıştır.

## 13. Davranışların Etik Açıdan Yargılanması

### 13.1 Etik kuralları çiğneme nedenleri

Önce meslek ve mühendislik etiğinin bileşenlerine, sonra üretimdeki sorumluluklara bakılmıştı. Şimdi etik kurallar çiğnendiğinde davranışın nasıl yargılanacağına geçildi. Etik kuralların çiğnenmesinin değişik nedenleri olabilir (ekrandan, 01:20:00):

- **Hırs:** meslek hırsı, rakiplerin önüne geçme hırsı, para kazanma hırsı. Hoca "her şey benim olacak" hırsını, eski bir Türk filmindeki açık artırmada eşeği almak isteyen karakterin "bineceğim üstüne, vuracağım kırbacı" sözüyle anlattı. <!-- BELİRSİZ: Altyazıda filmin adı "Sezercik" olarak geçiyor; hangi film olduğu kesin değil. -->
- **Yönetim erkini elinde bulundurma isteği:** "ben yöneteceğim, patron ben olacağım."
- **Deneyim eksikliği.**
- **Bencillik.**
- **Teknik yetersizlik.**
- **Yasaları, yönetmelikleri ve ölçünleri bilmeme:** Hoca bunun hoş karşılanamayacağını, bir mesleği yapan kişinin onun yasa, yönetmelik ve standartlarını bilmekle yükümlü olduğunu söyledi.
- **Bir olayın kuruluş veya kişiyi korumak amacıyla gizlenmesi, gizlemek için tanıklara menfaat sağlanması.**
- **Siyasi görüş.**

### 13.2 Kararı sınayan altı soru

Bir yönetici, mühendis ya da uygulamacı o anda karşılaştığı bir durumda vereceği kararın etik olup olmadığını sınamak için şu sorulara yanıt vermelidir. Sorulara düzgün yanıt verilebiliyorsa karar etiktir; kaçamak ya da yanlış yanıt veriliyorsa karar etik değildir (ekrandan, 01:20:00).

1. **Doğru mu?** Bir kararın doğru olup olmadığını belirlemek zordur. Hoca şöyle sormayı önerdi: "Bu kararı bir başkası verse rahatsızlık duyar mıydım?" Duymuyorsanız karar doğru sayılabilir. Bir başka yol, geçmişte yaşanan benzer olayların sonuçlarının iyi mi kötü mü olduğuna bakmaktır.
2. **Adil mi?** "Bu karar bana karşı uygulansaydı adil bulur muydum?" Bu, çift taraflı düşünmedir. Hoca kültürümüzdeki "kardeşim bana, babamın mirasından kendine istediği kadar pay versin" sözünü örnek verdi: iki kardeş üç tarlayı paylaşacaksa ve biri kendine iki tarla istiyorsa, diğerine de iki tarlayı uygun görmelidir; kendin için ne kadar istiyorsan karşındakine de o kadarını vermelisin.
3. **Verilecek karardan birisi zarar görecekse bu kimdir?** Bu soru faydacılık etiği kavramına uygundur. Karardan kimin kazançlı, kimin zararlı çıkacağı birlikte sorgulanır ve zarar görecek ya da kazanacak kişinin bunu gerçekten hak edip etmediğine bakılır; hak ediyorsa karar doğru sayılabilir.
4. **Eğer verdiğiniz karar basında ön sıralarda yer alırsa kendinizi rahatsız hisseder misiniz?** Hoca Kaz Dağları'ndaki bir altın madeni projesiyle ilgili bir madencilik şirketi yöneticisinin açıklamasını örnek verdi: "ormanları keseceğim, Kaz Dağları'nı kel bırakacağım" anlamına gelen bir karar gazetelerin birinci sayfasında yer aldığında rahatsız olmuyorsanız, bu kararı neden aldığınızı düzgünce açıklayabiliyorsunuz demektir.
5. **Aldığınız karar çevrenizdeki yakınlarınızı rahatsız eder mi?** Yanıt evetse sorun var demektir ve karar yeniden düşünülmelidir.
6. **Karar nasıl görünüyor?** Hoca bu maddede kararın oluşturacağı toplumsal davranışların sezilebileceğini ve öngörülebileceğini anlattı. Kötü bir sonuç öngörülüyor ya da bundan kuşkulanılıyorsa, karar oturup tartışılmalı ve belki gözden geçirilmelidir.

> **Ders sonrası not:** Slaytta ilk soru "Verilecek kararın doğru olmadığına ilişkin sorudur" diye yazılmış (ekrandan, 01:20:00). Büyük olasılıkla doğrusu, ikinci sorudaki gibi "doğru olup olmadığına ilişkin sorudur"; hocanın anlatımı da bu yöndedir.

## 14. Çalışanların Etik Olmayan Davranışları

Hoca, ileride şirket sahibi ya da yönetici olup birini işe alacak öğrencilere bir tavsiyede bulundu: işe alınan kişiye bu kurallar yazılı olarak verilmeli ve altına "okudum ve anladım" diye ıslak imza atması istenmelidir (ekrandan, 01:30:00). Böylece çalışan etik dışı davrandığında sorumlu tutulabilir ve kuruluşun etik kurulu ceza verebilir. Kamu kurumlarında bu kurallar yönetmelik ve mevzuatlarla tanımlıdır. Hoca öğrenciler için örnek olarak üniversitenin öğrenci yönetmeliğini ve onun disiplin hükümlerini gösterdi: disiplin yönetmeliği kurallara uymayan davranışların cezalarını (kınama, uzaklaştırma gibi) açık ve net biçimde ortaya koyar.

<!-- BELİRSİZ: Hoca kopya için örnek cezaları "kınama ya da bir hafta uzaklaştırma" diye kararsız biçimde söyledi; cezaların ayrıntısı nota alınmadı. -->

Slayttaki davranışlar ve hocanın açıklamaları (ekrandan, 01:30:00):

- **Ayrımcılık:** Önyargılı tutumla davranış sergilemek.
- **Kayırma:** Aile, akrabalık, arkadaşlık gibi parasal olmayan etkenlerle belli kişilere iş yerinde ayrıcalık tanımak ("bu benim arkadaşım, bu işi yapmasın, öbürü çalışsın" denince hem ayrımcılık hem kayırma yapılmış olur).
- **Rüşvet:** Para, mal ya da hediye kisvesi altında maddi çıkar sağlamak. Hem verene hem alana yaptırım uygulanmalıdır.
- **Yıldırma:** Yönetim gücünü birilerine baskı unsuru olarak kullanmak.
- **Savsaklama:** Görevi iyi yapmamak, uzatmak, geciktirmek.
- **Sömürü:** Bir çalışanı ya da bir kaynağı kendi çıkarı için kullanmak; kendi işini başkasına yaptırmak ya da kurumun sunucusunu özel işleri için kullanmak (hem kişi hem kaynak sömürüsü).
- **Bencillik:** Yalnız kendini ve kendi çıkarlarını düşünmek; oysa esas olan ekip, kamu ve şirketin tamamıdır.
- **Şiddet ve saldırganlık:** Sözel ve fiziksel kaba ve sert davranışlar.
- **Hakaret ve küfür:** Bu da bir saldırganlıktır.
- **Cinsel taciz:** Eylemli olduğu gibi sözlü de olabilir; etik değildir ve yasalarla da suçtur.
- **Yetkiyi kötüye kullanma:** Yönetim gücünü kendine çıkar sağlayacak ya da kuruluşa zarar verecek biçimde kullanmak.
- **Dedikodu:** Gerçek olup olmadığını bilmeden başkaları hakkında konuşmak.
- **Karalama:** Bir iş arkadaşını ya da yöneticiyi kınamak, kötülemek, suçlamak.
- **Yöneticiler ile ilişki:** Daha iyi olanaklar elde etmek için yöneticilerle etik olmayan ilişkiler kurmak.
- **Bilgi çalmak ve sızdırmak:** İş yerinin sırları ya da başka değerli bilgileri çalmak veya başkalarına açıklamak.
- **Bomba yerleştirme:** Hem etik dışı hem suçtur.
- **Kötülemek:** İş yerini, hizmetlerini ya da ürünlerini toplum içinde kötülemek.
- **Savurganlık:** Kaynakları bilerek ve isteyerek tutumsuz kullanmak; sömürüye yakındır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:36): Gerçekleştirme aşamasında sayılan dört etik dışı davranıştan ilk üçü (incelenmemiş yama, incelenmemiş hazır kod, sağlamlaştırmayı savsaklama) ile dördüncüsü (programa bomba gömmek) arasındaki fark nedir? Bombayı yerleştiren için ne söylenebilir?

> **Çözüm (derste verildi):** İlk üçü etik değerlere özen göstermemektir; mühendis bu davranışlardan doğan sorunlardan etik olarak sorumludur. Dördüncüsünde mühendis meslek etiğini bilerek ve isteyerek çiğner; bu yalnız etik ihlal değil, aynı zamanda bir suç eylemidir.

**Soru 2** (derste sözlü, 00:33:56): Challenger faciasında contanın soğukta çatlayacağını fark edip üstlerine bildiren mühendis hakkında nasıl bir yorum yapılabilir? Patlamadan sonra yapılan inceleme hangi sorumluluk türüne girer?

> **Çözüm (derste verildi):** Mühendis sorunu üretim aşamasında görüp bildirdiği için mesleki sorumluluğunu ve etken sorumluluğunu yerine getirmiştir. Patlamadan sonra sorunun kaynağının ve ilgilisinin örtbas edilmeden araştırılması edilgen sorumluluktur.

**Soru 3** (derste sözlü, 00:34:52): DC-10 bagaj kapağı vakasında etken ve edilgen sorumluluk yerine getirilmiş midir? Eksik kalan nedir?

> **Çözüm (derste verildi):** Mühendis sorunu bildirdi, yöneticiler kapağı yeniden tasarlatıp uçaklara sırayla taktırdı; etken sorumluluk hem mühendis hem yöneticiler tarafından yerine getirildi. Kazadan sonra neden toplumla paylaşıldığı için edilgen sorumluluk da yerine getirildi. Eksik kalan, kaza riski öngörülmediği için uçağı işleten havayollarının (ör. THY) uyarılmamasıdır.

**Soru 4** (derste sözlü, 01:33:36): Bir öğrenci kripto paraların, özellikle madencilik (mining) yapan ve yeni token çıkaranların etiğinin ders kapsamına girip girmediğini sordu.

> **Çözüm (derste verildi):** Hoca konunun finans sektörüne ait olduğunu, finansal düzenlemelerin bu dersin kapsamında olmadığını söyledi. Ama madenciliğin çok elektrik harcadığını ve kaçak elektrik hattına bağlanıp sunucularla bitcoin üretmenin, bedeli başkalarının cebinden çıktığı için etik olmadığını, hak yemek olduğunu belirtti.

**Soru 5** (derste sözlü, 01:20:50 - 01:25:50): Bir kararın etik olup olmadığını sınamak için kendimize hangi soruları sormalıyız?

> **Çözüm (derste verildi):** Doğru mu? (başkası verse rahatsız olur muydum?), Adil mi? (bana uygulansa adil bulur muydum?), Karardan kim zarar görecek, kim kazanacak ve bunu hak ediyor mu? (faydacılık), Karar basında ön sırada yer alsa rahatsız olur muyum?, Karar yakınlarımı rahatsız eder mi?, Karar nasıl görünüyor, hangi toplumsal sonuçları doğurur? Sorulara düzgün yanıt verilebiliyorsa karar etiktir.

## Dersin Toparlaması

Bu derste bir bilgi sistemi projesinin gerçekleştirme, sınama, kurulum ve bakım aşamalarında bilgisayar mühendisinin etik sorumlulukları tamamlandı. Hatasız yazılımın olmadığı, ama incelenmemiş yama ve hazır kod kullanmanın, sağlamlaştırmayı savsaklamanın ve özellikle bomba program gömmenin kabul edilemeyeceği anlatıldı. Challenger ve DC-10 örnekleri, küçük bir ihmalin can kaybına yol açabileceğini ve rol temelli, etken ve edilgen sorumluluk kavramlarını somutlaştırdı. Hata kaynakları (üretim hatası, yanlış karar, öngörü eksikliği, eylem özgürlüğü), teknik erekler, etkin ve uzman kişiler, toplumsal bağlam ve mühendis-yönetici ilişkisinde görev paylaşımı ele alındı.

Dersin ikinci yarısında IEEE-CS ve ACM'nin sekiz etik ilkesi (Kamu, Müşteri ve İşveren, Ürün, Yargı, Yönetim, Meslek, İş Arkadaşları, Özü), temel etik ilkeler, etik olmayan davranışlar ve Bilgisayar Etiği Enstitüsü'nün on emri incelendi. Son olarak etik kuralları çiğneme nedenleri, bir kararın etik olup olmadığını sınayan altı soru ve işe alımda etik kuralların yazılı olarak imzalatılması önerisiyle çalışanların etik olmayan davranışları sıralandı. Sonraki derslerde kurumsal etik konusuna geçilecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
