# Ders 5 Çalışma Özeti

## Genel Konular

- Bilimsel yazımda üç temel öğe
  - Dersin ilk bölümünün konusu kaynak gösterme (how to cite), tablo hazırlama ve grafik hazırlamadır (ekrandan, 00:10:00).
  - Tablolar ve grafikler birbiriyle karşılaştırmalı ele alınır: hangi durumda tablo, hangi durumda grafik kullanılmalıdır.
  - Sık yapılan hata, aynı bilgiyi hem metinde hem tabloda hem grafikte tekrar etmektir. Bilgi bunlardan yalnız birinde verilmelidir.
- Kaynak gösterme (ekrandan, 00:15:00)
  - Kaynakçada yalnız önemli ve yayımlanmış kaynaklar yer almalıdır. Kaynak, yazılan yayınla aynı değerde ve basılmış olmalıdır.
  - Yayımlanmamış veriler, özetler, tezler ve benzeri ikincil malzemeler kaynakçayı doldurmamalıdır. Bu tür bir kaynak gerçekten gerekliyse metin içinde parantezle ya da dipnotla verilebilir.
  - Yayına kabul edilmiş bir makale, dergi adı ve ardından "In press" yazılarak kaynakçaya konabilir.
  - İstisnalar: bitmek üzere olan bir tezi sahibinden izin alarak ya da kendi basım aşamasındaki yayınınızı kaynak gösterebilirsiniz.
  - Son kontrol: metinde atıf yapılan her kaynak kaynakçada, kaynakçadaki her kaynak metinde bir yerde atıf almış olmalıdır.
- Atıf yapma biçimi
  - Önceki çalışmalar anlatılırken atıf yapılan kişi karalanmamalı; bir şeyi ihmal ettiği, yanlış yaptığı ya da beceremediği ima edilmemelidir. Çalışmanın kapsam dışında kaldığı ya da başarısının düşük olduğu nazikçe söylenebilir.
  - Atıf kayda değer bir şey için yapılmalıdır. "Smith'in zarif katkısı" gibi neyin katkı olduğunu söylemeyen bir atıf, yalnız birine selam vermek gibidir.
  - Cümle sonuna ard arda eklenmiş "tren gibi" atıflar, hangi atfın cümlenin hangi kısmıyla ilgili olduğunu belirsiz bırakır.
  - Hakem ya da editörden gelen atıf istekleri: atlanmış ilgili bir çalışmaya bakma önerisi etiktir; derginin kendi makalelerine ya da hakemin/editörün kendi yayınlarına atıf istenmesi etik dışıdır.
- Tablo hazırlama (ekrandan, 00:20:00)
  - Kural: tekrarlı veri sunmak zorunlu değilse tablo oluşturulmaz.
  - Birinci neden: laboratuvar defterindeki yığınla veriyi tabloya dökmek iyi bilim değildir; yalnız örnekler ve kırılma noktaları verilmelidir.
  - İkinci neden: tabloların yayın maliyeti metne göre çok yüksektir.
  - Tablo, sayısal değerleri ya da yazıyla anlatılması karmaşık olacak bir ilişkiyi daha temiz göstermek için kullanılır.
  - LaTeX'te bile tablolar en çok uğraştıran ve değişiklikte en çok iş çıkaran yapıdır; editörler ve yayın ofisleri metinle anlatılabilecek bir şeyi tabloda görmek istemez.
  - Kötü tablo örnekleri: iki sütunu hiç değişmeyen tablo, satırları sütunlara 4'e 2 dağılan ve bir cümleyle özetlenebilecek tablo, simülasyon parametrelerini "alışveriş listesi" gibi sıralayan uzun tablo.
- Tablo mı grafik mi (ekrandan, 00:25:00)
  - Kesin bir cevap yoktur; kararı bilginin içeriği ve anlatılmak istenen şey verir.
  - Aynı veri (iki ilaç ve birlikte kullanımlarında 2, 4, 6, 8. haftalarda negatif kültür yüzdesi) solda tablo, sağda çizgi grafik olarak gösterilir.
  - Grafikte iki düşük seri üst üste biner, değerleri okunamaz; 0-100 ölçeği yüksek değerli seri yüzünden daraltılamaz.
- Grafik hazırlama
  - Verilecek kararlar: grafik formatı, grafik tipi, grafiğin özellikleri (başlık, eksenler, lejant) ve karşılaştırmada tekdüzelik.
  - Ölçek algıyı bozmamalıdır: çok yakın değerler, ekseni dar bir aralıktan başlatarak dev bir fark gibi gösterilmemelidir.
- Grafik formatları (ekrandan, 00:30:00)
  - EPS: PostScript dosyasıdır; 2B vektör grafik, bitmap görüntü ve metin içerebilir, bitmap önizleme gömülüdür.
  - TIFF (Tag Image File Format): raster (bitmap) görüntülerin uygulamalar arasında değişimi için yaygın format.
  - JPG/PNG: PNG kayıpsız sıkıştırmalı raster formatıdır; GIF'in yerine geliştirilmiştir.
  - Hoca LaTeX ile yazarken EPS ve TIFF kullanılmasını önerir; JPEG/PNG ölçek değişince bozulma gösterebilir.
- Grafik tipi seçimi
  - Bütünün parçalarını gösteren veri için pasta grafik (pie chart) kullanılabilir. <!-- BELİRSİZ: 00:30:48-00:31:15 arasında altyazı kesik; pasta grafik koşulunun tam ifadesi okunmuyor -->
  - Zamansal sürekliliği olan veri (ör. gün içinde saat saat değişen döviz kuru) çizgi grafikle; günde bir kez değişen veri çubuk grafikle verilebilir.
- Grafik özellikleri (ekrandan, 00:35:00)
  - Farklı seriler aynı renkte olmamalı; düz, tırtıklı, noktalı, nokta-çizgi gibi çizgi tipleriyle ayrılabilir.
  - Çizgi/çubuk kalınlığı, çift sütunlu yayında sıkışma ve okunabilirlik kontrol edilmelidir.
  - Her grafiğin başlığı ve lejantı olmalı; eksenlerin neyi ve hangi birimle gösterdiği yazılmalıdır.
  - Ara ölçek değerleri düzenli olmalı (0-20-100-5000 gibi atlamalar algıyı bozar).
  - Eksen, grafiğin gerektirdiğinden fazla uzatılmaz: veri 0-78 arasındaysa en üst değer 80 olmalıdır. Yüzdelerde 100'e uzatma isteğine direnilmelidir; yoksa grafiğin yaklaşık %20'si boş kalır ve canlı kısım sıkışır.
- Kötü grafik örnekleri (ekrandan, 00:40:00)
  - Aynı dokuz seri iki grafikte çizilir; birinde y ekseni 120'ye, diğerinde 100'e kadar gider.
  - Bir grafikte en fazla dört seri gösterilmesi önerilir; zorlansa altıdır. Sekiz seri gösterilecekse grafik dörder seriyle ikiye bölünür.
  - Karşılaştırılan grafiklerde ölçek ve bütün parametreler aynı olmalıdır.
  - Alt grafikli (a, b, c, d) şekiller çift sütunlu makalede alt alta, tek sütunlu makalede yan yana gruplanır.
- Makale gönderme ve değerlendirme süreci (ekrandan, 00:45:00)
  - Ana başlıklar: gönderim (yönetim sistemleri, kullanıcı bilgisi, hazırlık), değerlendirme süreci (süre, revizyon türleri, revizyonların ele alınması), nihai karar (kabul, ret).
  - Gönderim sistemleri: Manuscript Central / ScholarOne gibi sistemler. ORCID kimliği girilerek yazar bilgileri otomatik doldurulabilir.
  - Gönderimde başlık, özet, yazar listesi ve dergi ya da konferans formatında hazırlanmış metin girilir; bazı dergiler ek isterler (ör. Elsevier "highlights").
  - Editöre hitaben yazılan bir ön yazı (cover letter) gönderilir. Çalışma daha önce bir konferansta yayımlandıysa bu belirtilir ve yeni sürümün getirdiği fark açıklanır.
  - Kör değerlendirme (blind review): yazar hakemi bilmez. Çift kör (double blind review): hakem de yazarı bilmez.
- Değerlendirme adımları (ekrandan, 00:50:00)
  - Editoryal kontrol: kapsam, yayın stili ve kuralları, etik (intihal vb.).
  - Editör atanması: editör makaleyi doğrudan reddedebilir, hakemleri bulur ve atar; yazardan önerilen hakem listesi ve kara liste istenebilir.
  - Karar türleri: küçük revizyon (minor revision), büyük revizyon (major revision), ret (reject), kabul (accept). Doğrudan kabul çok nadirdir.
  - İki büyük revizyon genelde ret sayılır; ikinci turdan sonrası çok nadirdir.
  - Kabulden sonra dil ve biçim için bir editoryal kontrol daha yapılır.
  - Her değerlendirme turu için hakem yorumlarına tek tek yanıt veren bir açıklama metni hazırlanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aynı bilgi birden fazla biçimde verilmez
  - Metin, tablo ve grafikten yalnız biri seçilmelidir; tekrar okuru yormaktan başka işe yaramaz.
- Kaynakça ile metin içi atıflar birebir eşleşmeli
  - Atlanan bir atıf anlık bir unutkanlık olsa da hakem bunu bir şeyi sahiplenme (kendine mal etme) girişimi olarak algılayabilir.
- Atıf istekleri ve etik
  - Derginin ya da hakemin kendi yayınlarına atıf istenmesi etik dışıdır; bu durumda yazar bir seçim yapmak zorunda kalır.
- Grafik okunabilir, takip edilebilir ve anlaşılabilir olmalı
  - Tablo-grafik örneğinde grafikteki üst üste binen seriler, değerlerin yanlış okunmasına yol açar.
- Ölçekle algı oynanmaz
  - Bilimsel grafiğin amacı pazarlama değildir; ölçek düzenli olmalı, karşılaştırılan grafiklerin ölçekleri aynı olmalıdır.
- Bir grafikte en fazla dört seri
  - Fazlası okunabilirliği bitirir; gerekiyorsa grafik bölünür.
- Hakem yorumlarına yanıt
  - Hakem her zaman haklı değildir; makul bir karşı argüman nazik bir dille sunulabilir.
  - Yorum yazanın da çoğu zaman ana dili İngilizce değildir. Olumsuz yorum okunup kenara konmalı, bir gün sonra tekrar okunmalı, iyice anlaşılana kadar birkaç kez okunmalıdır.

## Kısa Tekrar Notları

- Kaynakça: yalnız önemli ve yayımlanmış kaynaklar; kabul edilmiş makale "In press" ile.
- Yayımlanmamış veri, özet ve tez gerekiyorsa parantezle ya da dipnotla.
- Son kontrol: metindeki her atıf kaynakçada, kaynakçadaki her kaynak metinde.
- Atıf nazik, gerekçeli ve cümlenin ilgili kısmına bağlı olmalı.
- Tekrarlı veri zorunlu değilse tablo yok; tablo pahalıdır.
- Tablo mı grafik mi: içeriğe göre karar.
- Formatlar: EPS, TIFF, JPG/PNG.
- Sürekli zaman verisi çizgi, günlük tek değer çubuk, parça-bütün pasta grafik.
- Başlık, lejant, eksen adı ve birimi zorunlu.
- Ekseni gereğinden fazla uzatma (0-78 ise üst sınır 80).
- Grafikte en fazla 4 seri (zorlansa 6).
- Değerlendirme: editoryal kontrol, editör atanması, hakemler, karar (minor, major, reject, accept).
- Kör ve çift kör değerlendirme.

## Detaylı Açıklamalar

- Kaynak göstermenin iki tarafı vardır: neye atıf yapılacağı ve atfın nasıl yazılacağı. Kaynakçaya girecek kayıt, yazılan yayınla aynı nitelikte, yani basılmış bir yayın olmalıdır. Devam eden çalışmalar ancak özel durumlarda (sahibinin izniyle bir tez, yazarın kendi basım aşamasındaki makalesi) kullanılabilir. Slayttaki öneriye göre böyle bir kaynak gerçekten gerekliyse kaynakçaya değil, metin içinde parantezle ya da dipnotla verilir; kabul almış bir makale ise dergi adı ve "In press" ibaresiyle kaynakçaya girebilir (ekrandan, 00:15:00). Yazım bittikten sonra kaynakçadaki her kaydın metinde, metindeki her atfın kaynakçada bulunduğu kontrol edilmelidir. LaTeX ve BibTeX gibi araçlar kullanılmadığında referansların sırası ve numarası metin değiştikçe bozulabilir; bu yüzden son kontrol daha da önemlidir.
- Atıflar önceki çalışmaları anlatmak için verilir. Bu anlatımda başka bir araştırmacının işi küçümsenmez; yalnız kapsamının farklı olduğu ya da başarısının düşük kaldığı nazikçe belirtilir. Atıf somut bir katkıya işaret etmelidir. Cümlenin sonuna art arda eklenen atıflarda okur hangi atfın neyi desteklediğini bulmak için aramak zorunda kalır; bu da iyi karşılanmaz.
- Tablo kararı için slayttaki genel kural, tekrarlı verinin sunulmasının zorunlu olmadığı durumda tablo kurulmamasıdır (ekrandan, 00:20:00). Derste gösterilen kötü örneklerde bilgi bir iki cümleyle anlatılabilecekken yarım sayfalık tablo harcanır. Ağ (network) yayınlarında simülasyon parametrelerinin uzun bir "look-up table" olarak verilmesi de hoca tarafından aynı kapsamda eleştirilir. <!-- BELİRSİZ: kötü tablo örneklerinin slaytları karelerde yok; içerik altyazıdan aktarıldı -->
- Tablo ile grafiğin karşılaştırıldığı slaytta (ekrandan, 00:25:00) streptomisin, izoniazid ve ikisinin birlikte kullanımı için 2, 4, 6 ve 8. haftalarda negatif kültür yüzdeleri hem tabloda hem çizgi grafikte gösterilir. Tablodan 4. haftada streptomisin için 10, izoniazid için 12 değeri doğrudan okunur; grafikte ise bu iki seri birbirine çok yakın ve 0-100 ölçeğinde sıkışık olduğu için değerler kestirilemez. Birlikte kullanım serisi 100'e ulaştığından ölçek 0-40'a daraltılamaz. Sonuç: hangi biçimin daha iyi olduğunu veri belirler; bu veride tablo daha okunur, grafik ise belki çizgi yerine başka bir tiple daha iyi olabilirdi.
- Grafik oluştururken format, tip, özellikler ve tekdüzelik kararları verilir. Hoca, ölçekle algıyı çarpıtmanın örneği olarak, 800 bin ile 801 bin satış arasındaki binde birlik farkın, eksen dar bir aralıktan başlatılarak dev bir fark gibi çizildiği gazete grafiklerini anlatır. Bilimsel grafiğin amacı bu tür bir pazarlama değil, algıyı bozmayan bir karşılaştırmadır.
- Eksen kuralı (ekrandan, 00:35:00): ordinat ya da apsis grafiğin gerektirdiğinden fazla uzatılmaz. Veri 0 ile 78 arasındaysa en üst değer 80 olmalıdır. Yüzde verilerinde ekseni 100'e uzatma isteği güçlüdür ama direnilmelidir; yoksa genişliğin ya da yüksekliğin %20 kadarı boş kalır ve verinin olduğu kısım küçülür.
- Kötü grafik örneğinde (ekrandan, 00:40:00) aynı dokuz seri iki grafikte çizilmiştir. Soldaki grafikte y ekseni hiç kullanılmayan 120 değerine kadar uzatıldığı için alan beş yerine altı parçaya bölünür; verinin olduğu kısım altıda beşlik alana sıkışır. Sağdaki bu yüzden bir tık daha okunurdur. Ama ikisi de kötüdür, çünkü bir grafikte dokuz seri vardır; önerilen üst sınır dörttür.
- Gönderim ve değerlendirme sürecinde (ekrandan, 00:45:00 ve 00:50:00) önce editoryal kontrol kapsamı, stili ve etiği denetler. Ardından atanan editör bir "süper hakem" gibidir: makaleyi doğrudan reddedebilir ya da hakem bulur. Hakem kararları küçük revizyon, büyük revizyon, ret ve kabuldür. Büyük revizyon yapısal değişiklik gerektirdiği için tehlikelidir; ikinci bir büyük revizyon genelde ret anlamına gelir. Her turda hakem yorumlarına tek tek yanıt veren bir metin hazırlanır; katılınmayan yoruma makul ve nazik bir karşı argümanla itiraz edilebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
