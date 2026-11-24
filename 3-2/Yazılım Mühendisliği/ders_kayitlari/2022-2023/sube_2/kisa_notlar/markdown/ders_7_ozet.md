# Ders 7 Çalışma Özeti

## Genel Konular

- Etkinlik şemaları (activity diagrams)
  - Olayların akış sırasını gösteren UML şemasıdır. Konunun uzmanlarının (yazılımcı olmayanların) da okuyabileceği bir şema türüdür.
  - İki önemli avantajı vardır: iş kurallarını iyi gösterir ve paralel yürüyen etkinlikleri (çok iş parçacıklı çalışmayı) gösterebilir. Diğer UML şemalarında paralellik ya gösterilemez ya da önemli değildir.
  - Çizim öğeleri (ekrandan, 00:45:00): denetim akışı (düz ok), etkinlik başlangıcı (dolu daire), sinyal alma / olay kabul etme (bir ucu içe girintili beşgen), eylem (köşeleri yuvarlatılmış dikdörtgen), karar verme (elmas, `if`), eşgüdüm (kalın çubuk), etkinlik sonu (halka içinde dolu daire), sinyal gönderme (bir ucu sivri beşgen).
  - Sinyal alma ve sinyal gönderme şekilleri birbirini tamamlar; uç uca konunca dikdörtgen olurlar. Bir şemada ikisinin birlikte bulunması zorunlu değildir.
  - Şema başlangıç işaretiyle ya da sinyal alma işaretiyle başlar. Etkinlik sonu birden fazla konabilir; akışı en sona taşımak yerine bulunduğu yerde bitirmek şemayı sadeleştirir.
  - Karar koşulu elmasın içine yazılmaz; elmastan çıkan okların üstüne köşeli parantez içinde yazılır (`[check-in başarılı]`, `[else]`).
  - Eşgüdüm çubuğu: üstteki çubuk akışı paralel kollara ayırır (fork), alttaki çubuk kolları birleştirir (join). Birleştirme çubuğu bir bekleme noktasıdır: erken biten kol, geç biteni bekler (ekrandan, 00:50:00).
  - Sinyal alma da bekleme gerektirir: akış sinyal gelene kadar durur. Zamanlı olaylar (timer) da bu şekilde gösterilebilir.
  - Kulvarlar (swimlanes): Her etkinliği hangi aktörün yaptığı kulvarlarla gösterilir. Etkinlikler arasında aktarılan veri, akış okunun üstüne köşeli parantez içinde yazılır (örneğin `[yolcu listesi]`).
  - Genelde bir kullanım senaryosu için bir etkinlik şeması çizilir; `include`/`extend` ile ilişkili birkaç senaryo tek şemada da birleştirilebilir.
- Havayolu örneği: check-in etkinlik şeması (ekrandan, 00:45:00)
  - Yolcu check-in bankosuna gelir (sinyal alma) → Yolcu check-in yapar → karar: `[else]` ise etkinlik sonu, `[check-in başarılı]` ise eşgüdüm çubuğu → paralel olarak "Yolcu uçağa biner" ve "Bagajlar uçağa yüklenir" → birleştirme çubuğu → Uçak piste yönelir → son.
- Durum şemaları (state diagrams)
  - Bir varlığın içinde bulunabileceği durumları ve bu durumlar arasında geçiş kurallarını anlatır (ekrandan, 00:55:00).
  - Bilgi sisteminde çok önemli bir varlığın yaşam döngüsünü (hangi durumdan hangisine, ne zaman ve hangi koşulla geçtiğini) göstermek için çizilir.
  - Durumlar köşeleri yuvarlatılmış dikdörtgenlerle, geçişler oklarla gösterilir. Başlangıç ve bitiş öğeleri etkinlik şemasındakiyle aynıdır.
  - Her geçiş etiketi `«M»` ile başlar ve `/` ile biter: `«M» Olay [koşul] /`. M, "mutate" (nesnenin bir durumdan diğerine evrilmesi) anlamındadır.
  - Varlığın durumunu değiştirmeyen olay, aynı durumdan çıkıp aynı duruma dönen okla ya da durum kutusunun içine yazılarak gösterilir.
  - Başlangıçtan ilk duruma geçişte olay yazılmayabilir; diğer bütün geçişlerde mutlaka bir olay bulunur. Dış ya da iç bir etki olmadan varlık durum değiştirmez.
- Uçak yaşam döngüsü örneği (ekrandan, 01:00:00)
  - Durumlar: Sipariş aşamasında, Bakımda, Kullanıma hazır, Bakım sırası beklemede.
  - Geçişler: `«M» Uçağın alım emri verildi /` (başlangıç → Sipariş aşamasında), `«M» Uçak teslim edildi /` (→ Bakımda), `«M» Bakım tamamlandı /` (→ Kullanıma hazır), `«M» Arıza bulundu /` (Kullanıma hazır → Bakımda), `«M» Bakım isteği geldi /` (Kullanıma hazır → Bakım sırası beklemede), `«M» Uçuş yap [atanmış uçuş kalmamışsa] /` (Bakım sırası beklemede → Bakımda), `«M» Uçak emekli edildi /` (Bakımda → son).
  - Kullanıma hazır durumunda kendine dönen ok: `«M» Uçuş ata / «M» Uçuş yap /`. Bakım sırası beklemede durumunun içinde: `«M» Uçuş yap [atanmış uçuş varsa] /`.
  - Yorum: Bakım isteği gelen uçak önce bakım sırasına alınır, planlanmış uçuşlarını yapar, uçuşları bitince bakıma alınır.
- Geçişlerde yürütülecek komutlar
  - `/` işaretinden sonra olay gerçekleşince yürütülecek komutlar (özellikle veritabanı işlemleri) sözde kodla yazılabilir: kaydı oluşturma (create), alana kullanıcı girdisini atama (`set kayıtNo := input` benzeri), kaydı silme (delete) ya da pasife çekme.
  - Komut yazmak isteğe bağlıdır; ama `«M»`, olay adı ve `/` her geçişte bulunmalıdır.
- NextGenPOS tasarım modeli (ekrandan, 01:10:00)
  - Kullanım senaryosu metni ve alan modelinden yola çıkılarak bir etkinlik, bir durum ve bir sınıf şeması çizilir. Tasarım modelindeki sınıf şemasının farkı, yönsüz ilişki bırakılmaması ve metotların eklenmesidir.
  - Derste "Satış İşlemi" senaryosu için etkinlik şeması ve kasanın durum şeması Violet UML ile birlikte çizildi; sınıf şeması sonraki derse kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Karar koşulu elmasın içine yazılmaz
  - Koşul, elmastan çıkan okların üstünde köşeli parantez içinde yazılır. Elmas içine yazı sığdırmak için şekil çok büyütülmek zorunda kalınır.
- Eylemlerde özne kullanın
  - "Bagajlar uçağa yüklenir" gibi edilgen ifadeler yerine işi kimin yaptığını belirten ifadeler tercih edilmelidir. Hocanın kendi ders notundaki etkinlik şemasında da özneler eksikti; şemayı anlamak için senaryo metnine dönmek gerekmemelidir.
- Alternatif öyküleri baştan okuyun
  - Etkinlik şemasını yalnız ana öyküye göre çizip alternatifleri sonra eklemek yerleşimi zorlaştırır. Kâğıtta çiziliyorsa alternatif öyküler baştan göz önünde tutulmalıdır.
- Durum şemasında biçim kuralı
  - Her geçişte `«M»`, olay adı ve sondaki `/` aranacaktır. Komut kısmı isteğe bağlıdır.
- Durumları doğru belirlemek
  - Durum şemasının en zor kısmı durumları doğru teşhis etmektir. Olay ile durum karıştırılmamalıdır (barkod okuma bir olaydır, durum değildir). Durum adları fiil olarak değil, durum olarak yazılmalıdır.
- Durum şemasının sınırı
  - Durumları izlemek kolaydır, ama "uçuş hangi koşullarda yapılır?" gibi olay merkezli bir soruyu yanıtlamak için bütün şemayı incelemek gerekir; aynı olay farklı durumlarda farklı geçişlere yol açabilir. Olay akışı için etkinlik ya da sıralama şeması daha uygundur.

## Kısa Tekrar Notları

- Etkinlik şeması: akış sırası, iş kuralları, paralellik. Konunun uzmanları da okuyabilir.
- Eşgüdüm çubuğu: fork (ayırma) ve join (birleştirme); join bekleme noktasıdır.
- Sinyal alma: akış sinyal gelene kadar bekler; zamanlı olaylar da böyle gösterilir.
- Karar koşulu oklarda `[...]` içinde; elmasın boş köşesi üçlü seçenek için kullanılabilir ya da `if-else if` zinciri kurulabilir.
- Kulvar: hangi aktörün hangi etkinliği yaptığını gösterir; aktarılan veri ok üstünde `[...]`.
- Bir kullanım senaryosu adımlar aralığında (örneğin 3-7) her an olabilecek bir alternatif varsa, her adıma karar elması koymak yerine o bölüm bir dikdörtgen alanla çevrilip not eklenir.
- Durum şeması: önemli bir varlığın yaşam döngüsü. Geçiş etiketi `«M» Olay [koşul] / komutlar`.
- Başlangıçtan ilk duruma geçişte olay şart değildir; diğer geçişlerde şarttır.
- Aynı şema için tek doğru çözüm yoktur; mantıklı ve tutarlı kabuller yeterlidir.

## Detaylı Açıklamalar

Etkinlik şemaları, birinci sınıftaki akış şemalarına benzer bir mantıkla olayların sırasını gösterir. Denetim akışı düz okla çizilir, eylemler köşeleri yuvarlatılmış dikdörtgenlerle yazılır, kararlar elmasla verilir. Şemanın akış şemasından farkı paralelliği gösterebilmesidir: kalın eşgüdüm çubuğu tek akışı birden fazla kola ayırır, alttaki çubuk bu kolları yeniden tek akışa toplar. Kolların ne kadar süreceği ya da hangisinin önce başlayacağı şemada belirtilmez, ama birleştirme çubuğunda erken biten kol geç biteni bekler. Havayolu örneğinde check-in başarılı olunca yolcunun uçağa binmesi ve bagajların yüklenmesi paralel yürür, ikisi de bitince uçak piste yönelir.

Sinyal alma (olay kabul etme) şekli bir dış olayın gelmesini bekler; şema bununla da başlayabilir. Kulvarlar etkinlikleri yapan aktörlere göre ayırır. Havayolu kulvar örneğinde müşteri hizmetleri yer hizmetlerinden yolcu listesini ister, yer hizmetleri listeyi oluşturup gönderir; iki eylem arasındaki okun üstüne `[yolcu listesi]` yazılır. Verinin e-posta eki, veritabanı ya da FTP ile gitmesi fark etmez; önemli olan iki eylem arasında bu verinin aktarılmasıdır. Bu ok bir elmastan çıkmadığı için koşul ile karışmaz. Hoca, kullandığı Violet UML aracının kulvarları desteklemediğini; kulvar gerekiyorsa etkinlikler hizalanıp kulvarların sonradan bir resim düzenleyiciyle çizilebileceğini söyledi.

Durum şemaları önemli bir varlığın sistemdeki yaşam döngüsünü anlatır. Uçak örneği aşama aşama karmaşıklaştırıldı: önce sipariş, bakım, kullanıma hazır ve emeklilik; sonra uçuş atama ve uçuş yapma olayları; en son da bakım sırası. Burada aynı "Uçuş yap" olayı üç farklı biçimde görünür: Kullanıma hazır durumunda koşulsuz (durum değişmez), Bakım sırası beklemede durumunda `[atanmış uçuş varsa]` (durum değişmez) ve `[atanmış uçuş kalmamışsa]` (Bakımda durumuna geçilir). Bu, durum şemasında olayları izlemeyi ve tutarlılık denetimini zorlaştırır. Hoca örnekleri Craig Larman'ın kitabından aldığını belirtti.

Geçiş etiketinde `/` işaretinden sonra o olay gerçekleşince yürütülecek komutlar yazılabilir. Uçak örneğinde alım emri verilince uçak kaydı veritabanında oluşturulur ve kayıt numarası kullanıcı girdisinden atanır; teslim edilince teslim tarihi alanı kullanıcı girdisiyle güncellenir; emekli edilince kayıt silinir. Hoca silmek yerine kaydı pasife çekip açıklama yazmanın (başka şirkete verildi, depolamaya alındı gibi) da mümkün olduğunu söyledi. <!-- BELİRSİZ: Komut gösterimini içeren slaytların (yaklaşık 01:07-01:09) karesi yok; sözde kodun ve aynı geçişe ikinci olay eklenirken kullanılan ayırıcı biçimin tam yazımı altyazıdan net çıkmıyor. -->

NextGenPOS etkinlik şeması (ekrandan, 02:00:00) şu akışla çizildi: başlangıç → Kasiyerin kimliği doğrulanır → Müşteri kasaya gelir → Kasiyer yeni satış başlatır → Kasiyer ürün barkodu girer → karar: `[barkod geçerli]` ise Sistem satış maddesi oluşturur, `[else]` ise barkod girişine dönülür → karar: `[daha ürün varsa]` barkod girişine dönülür, `[else]` ise Kasiyer toplamı bildirir ve ödeme ister → Ödeme tahsili → Sistem fiş verir → Müşteri ayrılır → son. "Müşteri bir kalemi alışverişten çıkartmak ister" alternatifi 3. ile 7. adımlar arasında her an olabileceği için bu bölüm bir dikdörtgenle çevrildi ve köşesine "Bkz. Ürün İptal Alt. Sen." notu yazıldı. Hoca, döngü için elmas kullanmanın kod yazarken kurulan `while` döngüsünün karşılığı olduğunu belirtti.

Kasanın durum şeması (ekrandan, 02:35:00) için önce durumlar belirlendi: Boşta bekleme, Yeni satış bekleme, Satış kaydetme, Ürün silme, Uyarı verme, Ödeme bekleme/tahsil, Fiş basma durumu. Geçişler: `«M»Güç açıldı/` (başlangıç → Boşta bekleme), `«M»Kasiyer login/` (→ Yeni satış bekleme), `«M»Kasiyer logoff/` (geri Boşta bekleme), `«M»Müşteri geldi/` (→ Satış kaydetme), `«M»Barkod oku [barkod geçerli]/` (Satış kaydetme kendine), `«M»Barkod oku [barkod geçersiz]/` (→ Uyarı verme), `«M»Sinyal süresi bitimi/` (Uyarı verme → Satış kaydetme), `«M»Ürün iptal/` (→ Ürün silme), `«M»Barkod oku [silme]/` (Ürün silme → Satış kaydetme), `«M»Alınacak ürün kalmadı/` (→ Ödeme bekleme/tahsil), `«M»Ödeme başarılı/` (→ Fiş basma durumu), `«M»Fiş basımı bitti/` (→ Yeni satış bekleme), `«M»Kapatma komutu/` (Boşta bekleme → son). Hocanın ders notundaki şema (ekrandan, 02:40:00) daha az durumla aynı işi yapar: login durumu ayrı tutulmaz, bunun yerine `«M» Satış başlatıldı / [Kasiyer login olmuş ise]` geçişindeki koşul kullanılır. Hoca bu etikette `/` işaretinin yanlış yerde olduğunu, koşuldan sonraya taşınması gerektiğini; barkod girildi döngüsüne de `[barkod geçerli]` koşulu eklenmesi gerektiğini söyledi. İki çözüm de uygundur; ayrıntılı olmak genelde tercih edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
