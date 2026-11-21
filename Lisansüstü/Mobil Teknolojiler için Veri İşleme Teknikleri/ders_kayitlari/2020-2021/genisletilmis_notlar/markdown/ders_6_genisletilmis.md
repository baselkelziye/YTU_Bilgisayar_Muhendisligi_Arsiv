# Ders 6 Genişletilmiş Notu: Sürüş Analizi, Diğer Sensörler ve Konum Belirleme, Zaman ve Frekans Domeni Öznitelikleri, Veri Ön İşlemeye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Manyetometre, İvmeölçer ve Sinyal Vektör Büyüklüğü
- 2. Jiroskop ve Sürüş Analizi
- 3. Sürüş Konforu, Yorgunluk ve Sürücü Davranışı
- 4. Termometre, Parmak İzi Sensörü ve Ayırt Edici Öznitelikler
- 5. Diğer Sensörler: Sağlık, Stres ve Duygu
- 6. Konum Belirleme ve İç Mekân Konumlama
- 7. Sensör Kitleri, Basınç Sensörleri ve Park Yeri Tespiti
- 8. Sensörlerin Sınıflandırılması
- 9. Zaman ve Frekans Domeni Öznitelikleri
- 10. Yapay Zekâ, Makine Öğrenmesi, Derin Öğrenme, Veri Madenciliği ve Veri Bilimi
- 11. Veri Bölme ve Öğrenme Eğrisi Deneyi
- 12. Veri Ön İşlemeye Giriş
- 13. Mobil Cihazlarda Kural Tabanlı, Makine Öğrenmesi ve Hibrit Yaklaşımlar

## 1. Manyetometre, İvmeölçer ve Sinyal Vektör Büyüklüğü

Ders, bir önceki haftada sensörler konusunda kalınan yerden devam etti. Barometre ve manyetometreye kadar gelinmişti. Manyetometre, dünyanın manyetik alanına göre konumumuzu ve yönümüzü bulmamızı sağlayan bir sensördür; pusula da aynı ilkeyle çalışır. Manyetometre ayrıca manyetik alanın kendisini algıladığı için ulaşım türünün tanınmasında önemli rol oynar: kişinin metroda mı, otobüste mi, uçakta mı gittiği gibi sorularda araç türüne göre farklı manyetik izler oluşur. İvmeölçer tek başına belli bir başarı verirken manyetometre eklendiğinde, hareketin yarattığı titreşime ek olarak yön ve yönelim bilgisi de gelir ve başarı artar.

İvmeölçer, telefonun düşmesinden başlayarak geçen hafta anlatılmıştı: ölçüm m/s² cinsindendir ve x, y, z olmak üzere üç ekseni vardır. Literatürde sık geçen bir büyüklük sinyal vektör büyüklüğüdür (signal vector magnitude, SVM). Üç eksenin karelerinin toplamının karekökü alınarak bulunur:

$$SVM = \sqrt{x^2 + y^2 + z^2}$$

SVM birçok problemde "dördüncü eksen" olarak kullanılır. Hoca, aynı yaklaşımın jiroskop ve manyetometre için de uygulanabileceğini, üç eksenin birbiriyle büyüklük ilişkisini tek bir eksende toplamanın problem çözümünde gerçekten işe yaradığını söyledi. Hatta x, y, z eksenleri hiç kullanılmadan yalnız SVM ekseniyle de problemler çözülebilir ve oldukça yüksek başarı alınabilir. Bunun pratik getirisi şudur: pencere üç eksen üzerinde ayrı ayrı gezdirilmek yerine tek bir eksen üzerinde gezdirilir, hesap yükü azalır.

> **Ek bilgi (derste anlatılmadı):** SVM, cihazın yönelimine (telefonun cepte nasıl durduğuna) büyük ölçüde duyarsızdır; çünkü eksenler arasında dağılan aynı hareket, karelerin toplamında aynı büyüklüğü verir. Telefon hareketsizken SVM yaklaşık yerçekimi ivmesine (≈9,81 m/s²) eşittir.

## 2. Jiroskop ve Sürüş Analizi

### 2.1 Jiroskop

Jiroskop açısal hızı ölçer. Slaytta jiroskobun yönelim bilgisini daha yüksek hassasiyetle verebildiği yazıyordu; bu sensör sayesinde Android'in Photo Sphere kamera özelliği telefonun ne kadar ve hangi yöne döndürüldüğünü bilir, Google'ın Sky Map uygulaması da telefonun hangi takımyıldıza doğrultulduğunu anlar (ekrandan, 00:10:00).

Hoca jiroskobun nerelerde işe yarayabileceğini sordu. Bir öğrenci uçan cisimleri ve sondaları önerdi. Hoca cevabı genelleştirdi: üç boyutta hareket eden ve açılı hareket yapan bütün nesnelerde ve kişilerde işe yarar. İnsan hareketleri yalnız iki boyutta yürüme ve koşma gibi görünse de merdiven inip çıkma, yokuş çıkma ve inme gibi üç boyutlu yer değiştirmeler vardır. Jiroskop hem taşıtlı hem taşıtsız hareketlerin tanınmasına katkı sağlar. Katkı sağladığı bir alan daha sürüş analizidir.

### 2.2 Sürüş analizi nedir?

Hoca "sürüş analizi" denince akla ne geldiğini sordu. Bir öğrenci yoldaki pürüzleri, çukurları, tümsekleri, virajların sayısını ve yolun düz olup olmadığını saydı. Hoca bunu "yapısal olarak yoldaki bozuklukların tespiti ve bunun sürüş konforuna etkisi" diye özetledi ve bunun başlı başına bir bölüm (chapter) olabileceğini söyledi.

İkinci önemli nokta bir öğrenciden geldi: sigorta şirketlerinin cep telefonu üzerinden sürüşün ne kadar sağlıklı olduğunu ölçüp buna göre prim indirimi yapması. Hoca, eskiden de böyle sözleşmeler olduğunu ama çok basit, kural tabanlı (rule-based) bir yaklaşım kullanıldığını anlattı: bir yıl kazasız gidene %30 indirim, iki yıl üst üste kazasız gidene %40, %50, %60 gibi. Günümüz teknolojisiyle sigorta şirketleri kişinin kullanım alışkanlıklarını inceleyerek düzgün kullananlara daha uygun poliçe sunmaya çalışıyor. "Düzgün kullanım"dan kastedilenler:

- Freni daha az kullanmak.
- Hızlanırken daha az ivmeyle hızlanmak.
- Makas atmamak; şerit değiştirirken ani değişiklik yapmamak.

### 2.3 Sürüşün alt aktiviteleri

Hoca sürüşü bir aktivite olarak ele alıp alt aktivitelerini sordu. Bir öğrenci çevre farkındalığı, reaksiyon süresi, kol ve bacak aksiyonları gibi sürücünün bilişsel ve fiziksel süreçlerinden söz etti. Hoca burada sürücünün değil, aracın manevralarının kastedildiğini belirtip şu listeyi verdi:

- Hızlanma.
- Yavaşlama.
- Sabit hızla gitme.
- Dönme: sağa, sola ve U dönüşü.
- Durma.

Öğrencilerin katkısıyla listeye şerit değiştirme ve geri geri gitme eklendi. Hoca park etmenin de teknik olarak bir aktivite sayılabileceğini söyledi. Işıkta bekleme, korna çalma ve sürüş sırasında cihaz kullanma gibi davranışlar da değerlidir ama burada aracın fiziksel hareketinden çıkarılan sürüş aktiviteleri ayrı tutuldu.

### 2.4 Bu bilgiden ne çıkar?

Aracın alt aktivitelerini tespit etmenin motivasyonları derste şöyle toplandı:

- Sigorta şirketlerinin kişiye özel poliçe sunması.
- Yoldaki bozuklukların tespit edilip belediye ekiplerinin ilgili yerlere yönlendirilmesi.
- Bozuklukların bir risk haritasına işlenmesi ve sürücünün o noktaya yaklaşırken sesli uyarılması ("ileride büyük bir çukur var", "ileride büyük bir tümsek var"). Hoca bunun ciddi kazaları önleme ihtimali olduğunu söyledi.
- Anlık trafik yoğunluğunun belirlenmesi: bir öğrencinin önerisiyle, belli noktalardaki araçlardan GPS konumu ve hareket bilgisi (ne kadar hızlı gittiği, duruyor mu) toplanarak yoğunluk çıkarılabilir.
- Yakıt tüketimi: ani hareketler, özellikle ani hızlanma ve yavaşlama, benzin tüketimini artırır. Sürüş aktiviteleri hem güvenliği hem konforu hem de yakıtı etkiler. Yeni nesil araçlar sürücüye sürüşüyle ilgili geri bildirim vermeye başladı.
- Otonom araçlar: bugün sürücüyü değerlendiren aynı analiz, otonom araçta aracın yazılımını değerlendirmek için kullanılacak. Hoca, ileride markaların "daha konforlu sürüş", "daha düşük tüketim" üzerinden yarışacağını söyledi. Tüketimin bir alt sınırı vardır; sürüş aktiviteleri iyi yapılırsa tüketim bu sınıra kadar iner, kötü yapılırsa yüksek kalır.

## 3. Sürüş Konforu, Yorgunluk ve Sürücü Davranışı

### 3.1 100 puanlık sürüş konforu

Hoca, 0 ile 100 arasında puan veren bir sürüş konforu sistemi tasarlansa en iyi sürüşün neye göre belirleneceğini sordu. Bir öğrenci ani hareketlerin insanı tedirgin ettiğini ve yorduğunu söyledi. Hoca soruyu daralttı: A noktasından B noktasına teoride hiç yorulmadan gitmek için nasıl gitmek gerekir? Öğrencilerle birlikte şu koşullar çıktı:

- Sabit hızla gitmek.
- Trafik olmaması.
- Kuş uçuşu, yani düz bir çizgide gitmek. Hoca bunun nedenini, dönerek gitmenin insanı çok yorduğunu hatırlatarak açıkladı.

Bu durumda optimum sürüş, yani 100 puan, harita üzerinde A'dan B'ye çizilen düz bir çizgi üzerinde inişsiz, çıkışsız, dönüşsüz ve sabit hızla gitmektir. Teoride hız değişmediği için ivme sıfırdır. Pratikte böyle değildir: hız sabitleyici devredeyken bile araç sürtünme, rüzgâr ve yol nedeniyle yavaşlar, otomatik sistem tekrar hızlandırır ve bu fark edilmeyecek düzeyde olur. Dolayısıyla uygulanan ivme sıfır olmaz.

Hoca'nın önerdiği yöntem şudur: düz ve kaliteli bir yolda belirli hızlarla giderken ölçülen ivme kaydedilir; bu, 100 puanlık sürüşün ivmesi olarak referans alınır. Ölçülen bir sürüş bu referansa ne kadar yakınsa 100 puana da o kadar yakındır. Farklı bir çözüm ailesi de her ani fren, ani dönüş gibi hareketi eksi puan sayıp 100'den düşer.

İvme üzerinde durmanın nedeni $F = m \cdot a$ ilişkisidir: ivme, kişiye uygulanan fiziksel kuvvetle doğru orantılıdır. Öne-arkaya ve yana her harekette kişiye bir ivme uygulanır.

### 3.2 Biyosensörlerle konfor ölçümü

Hoca, deneysel ortamlarda sürüş konforunu insanla ilişkilendirerek ölçen sistemlerde hangi sensörlerin kullanılabileceğini sordu. Bir öğrenci nabzı önerdi. Hoca nabzın bir seçenek olduğunu ama kişiden kişiye çok değiştiğini söyledi: kimisi yanında makas atılınca tedirgin olur, kimisi hiç etkilenmez.

Hoca'nın asıl örneği kas yorgunluğunu tespit etmek için vücuda bağlanan sensörlerdi. Kas yorgunluğunda laktik asit salgılanır. Bu sayede vücuda ivme uygulandığında koltuk ve aracın ağırlığı dahil ortamın konfor düzeyi daha iyi hesaplanabilir. Aynı ivme farklı araçlarda farklı hissedilir: ivmeyi sönümleyen bir koltukta ya da konforu yüksek, ağır ve kaliteli malzemeden yapılmış bir araçta 160 km/sa hızla giderken 90 ile gidiyormuş gibi hissedilebilir. Ses yalıtımı da önemlidir. Uçaklarda basınç dengelendiği için sabit hızda uygulanan ivme sıfıra yakındır ve yolcu duran bir ortamdaymış gibi hisseder.

Bu nedenle ivmeölçer sürüşle ilgili fiziksel bilgi verse de insan yorgunluğunun diğer etkenlerini hesaba katmak için kişinin üzerine sensör bağlamak gerekir. Hoca, kaslara bağlanıp gerginliği ölçen sensörlerin üretildiğini ve beyin sinyallerinden düşünceleri çıkarmaya çalışan çalışmalar olduğunu söyledi. Bu sensörlerin en büyük sorunu müdahaleci (intrusive) olmalarıdır: kafaya takılan bir başlık konforlu değildir; giyilebilir sensörler de ten teması nedeniyle henüz rahat değildir.

### 3.3 CAN bus verisi ve sürüş konforu haritası

Sürüş analizinde telefonların yanında araçların CAN bus verisi de kullanılır. CAN bus üzerinden motor devri, aracın ivmesi, benzin tüketimi gibi çok sayıda veri gelir ve bu veriler standart hale gelmiştir. Hoca, yeni araçların kendilerinin birer sensör düğümü gibi olacağını, hesapların araç üzerinde yapılıp sürücüye ne kadar yorulduğu, yolun hangi bölümünün zorladığı gibi istatistikler verileceğini söyledi; telefon tabanlı senaryolar daha çok eski tip araçlar için kurgulanır.

Hoca, bir yolu kimse gitmeden o rotanın konfor düzeyi hakkında bir şey söylenip söylenemeyeceğini sordu. Bir öğrenci rotanın planlarının, yani dijital haritanın elde olması gerektiğini söyledi. Hoca kabaca söylenebileceğini doğruladı: yolun eğimi, dönüşlerin keskinliği ve belli bir hızla gidildiğinde ne kadar yavaşlanacağı birleştirilerek genel sürüş karakteri tahmin edilebilir. Karşı yaklaşım, o yoldan geçen araçlardan toplanan bilgiyi biriktirmektir; araç sayısı arttıkça bir istatistik ve sonunda bir **sürüş konforu haritası** çıkar. Bugün hız haritası çıkarıldığı gibi konfor haritası da çıkarılabilir; bir rota önerilirken süresinin yanında konfor seviyesi de gösterilebilir. Dijital haritadan belirlenemeyen şeyler çukur ve asfalt kalitesi gibi yol kalitesi unsurlarıdır. Yol kalitesi de yorar: asfaltın yarattığı ses, uğultu ve açık cam yorgunluğu artırır.

### 3.4 Sürücü ile yolcunun yorgunluk farkı

Hoca şu soruyu sordu: boş bir yolda 130-140 km/sa sabit hızla, hız sabitleyiciyle gidiliyor; yanda bir yolcu, direksiyonda bir sürücü var. Yorgunlukları farklı mıdır? Öğrenciler sürücünün daha çok yorulduğunu söyledi; bir öğrenci nedenini sürücünün sürekli çevresine dikkat vermek zorunda olmasıyla açıkladı. Hoca duymak istediği cevabın bu olduğunu söyledi: hız arttıkça dikkat yoğunluğu da artmak zorundadır. Yavaş giderken ani olaylara rahat tepki verilebilir, hızlı giderken çevredeki bütün etkenler kontrol edilmelidir. Bu, doğrudan ölçülemeyen ama yorgunluğa etki eden ve sürücü açısından hesaba katılması gereken bir etkendir.

**Soru:** Dikkat vermenin getirdiği yorgunluk ölçülebilir mi? **Cevap:** Öğrenciler beyin aktivitesini ölçen başlıkları ve göz hareketlerinin takibini önerdi. Hoca, göz hareketlerini izleyen sistemler olduğunu söyledi: göz kırpma sıklığı, gözün normal açıklığına göre sürüş sırasında ne kadar kapandığı ve uykuya meyil izlenir; "kenara çek" diye uyaran sistemler artık vardır.

### 3.5 Sürücü davranış analizi ve ADAS

Sürücüyü kamerayla izlemek, kazaları önlemek için kurulmuş önemli bir yapıdır ve sürücü davranış analizi (driver behavior analysis) diye adlandırılır. Yalnız gözlerden dikkat yoğunluğu ölçülmez; gözlerin sağa sola hareketi, geriye ve iç aynaya bakışı da kişinin ne kadar güvenli kullandığını gösterir. Aynalara belirli bir periyotla bakmak gerekir; hiç aynaya bakmadan şerit değiştiren sürücüler bazı kazaların doğrudan nedenidir. Yanındakiyle konuşurken başını sürekli yana ya da arkaya çeviren sürücü de tehlikelidir; başın ne kadar ve kaç saniye döndüğü kamerayla tespit edilebilir.

Bu konular hem literatürde hem araç şirketlerinde çalışılıyor. Hoca bunları "level 3" düzeyi ve ADAS (Advanced Driver Assistance Systems) ile ilişkilendirdi: karar destek sistemleri sürücüye fark etmediği hataları gösterir ve uyarır; araçlar bunun için kamera dahil çeşitli sensörlerle donatılır. Kameranın sorunu KVKK ve GDPR gibi yasal kısıtlardır. Korna sesi ve ortamdaki ses miktarı da ölçülebilir.

İleride araçtan araca ağlarda (vehicle-to-vehicle network) öndeki ya da yaklaşan araçların güvenlik düzeyi otomatik olarak alınabilecek. Bu, güvenlik düzeyi yüksek bir araçta rahatlamayı gerektirmez ama düşük düzeyli bir araç varsa ekstra dikkat sağlar. Bugün bile belli bir mesafeye gelindiğinde araç hızı kendiliğinden kesip freni devreye alabiliyor ve arkadan çarpmaları önleyebiliyor. Hoca, nasıl bölünmüş yollar kaza oranlarını düşürdüyse bu karar destek sistemlerinin de hem sürücülü hem otonom araçların kaza olasılığını düşüreceğini söyledi.

## 4. Termometre, Parmak İzi Sensörü ve Ayırt Edici Öznitelikler

### 4.1 Termometre ve nem ölçer

Telefonlarda termometre ve nem ölçer (higrometre) vardır ama etkin kullanıldıkları söylenemez: ölçtükleri değer telefonun ve üzerindeki ısının etkisinde kalır, filtre uygulansa bile güvenilirlik sınırlıdır. Telefon cebe ya da çantaya konmadan bir yere sensör olarak bırakılırsa bu sensörlerden yararlanılabilir. Slaytta bir telefon üreticisinin hava nem sensörünü akıllı telefonda ilk kullananlardan olduğu ve verinin bir sağlık uygulamasında kullanıcının optimal sıcaklık ve nem içeren "konfor bölgesinde" olup olmadığını söylemek için kullanıldığı yazıyordu (ekrandan, 00:40:00).

### 4.2 Parmak izi sensörü ve Face ID

Parmak izi sensörü kişinin parmak izini okuyup cihazın kilidini açar (ekrandan, 00:40:00) ve son 5-6 yılda çok popüler oldu. Hoca yerini neyin aldığını sordu: Face ID. Hoca, ikisinin aynı olma (yanlış eşleşme) olasılıkları arasında 100 ya da 1000 kat kadar bir güvenilirlik farkı olduğunu söyledi ve bunun pazarlamada kullanıldığını ama gerçekten böyle olduğunu ekledi.

> **Ders sonrası not:** Hoca aradaki farkı "100 ya da 1000 kat" diye verdi. Üreticinin açıkladığı değerler büyük olasılıkla parmak izi için yaklaşık 1/50.000, Face ID için yaklaşık 1/1.000.000 yanlış eşleşme olasılığıdır; bu yaklaşık 20 katlık bir farka karşılık gelir.

Önemli olan eşleştirmenin nasıl yapıldığıdır. Face ID'de yüzün pikselleri tek tek karşılaştırılmaz; yüzün belirli nirengi noktaları alınır. Parmak izinde de seste de durum aynıdır: belirli bilgiler alındıktan sonra ayırt edici noktalar öne çıkarılır ve yüzün ya da sesin "parmak izi" çıkarılarak eşleşme kontrol edilir. Shazam ve SoundHound gibi şarkı tanıma uygulamaları da bundan yararlanır; bütün melodinin aynı olup olmadığına bakılsaydı istemciden sunucuya gidip eşleşip geri dönmek o kadar kısa sürede mümkün olmazdı.

### 4.3 Sesten ya da görüntüden parmak izi çıkarmak

Hoca sesten ya da görüntüden parmak izinin nasıl çıkarılabileceğini sordu. Bir öğrenci öznitelik (feature) çıkarmayı, örneğin frekans bilgisini, farklı filtrelerle konvolüsyon uygulamayı önerdi. Hoca vurgulamak istediği noktayı şöyle açıkladı: doğru öznitelikleri çıkarmak gerekir. Frekans domeni ve zaman domeni vardır; ikisi birleşince zaman-frekans domeni ortaya çıkar, ama çoğunlukla zaman ve frekans domeni ayrı ayrı kullanılır. Örneğin insan sesi belli bir frekans bandındadır; ortamdan alınan sesin bu bant dışındaki frekansları atılabilir, bunları sunucuya göndermenin anlamı yoktur.

Bilgiyi temsil eden en değerli bilgilere **ayırt edici öznitelikler (discriminative features)** denir. Bu öznitelikler ne kadar az ve ayırt ediciliği ne kadar yüksek olursa işlem yükü o kadar azalır. Hoca, sınıflandırma ve kümeleme çalışmalarında önce problemin çözüldüğünü, sonra kullanılan öznitelik sayısının azaltılmaya çalışıldığını anlattı. Çünkü her özniteliği hesaplamak bir maliyettir ve özniteliklerin bazıları birbiriyle koreledir; aynı ilişkiyi veren bir öznitelik zaten varsa diğeri tutulmamalıdır.

> **Hocanın vurgusu:** Bilgi transferi artık görüntünün, sesin ya da verinin ham halinin tamamen gönderilmesi değildir. Öznitelik bilginin toplandığı yerde çıkarılır ve yalnız öznitelikler sunucuya aktarılır. Buna yerinde işleme (in situ processing ya da on-premise processing) denir. Bu dersteki cihazların hepsinin kaynak kısıtı vardır; zaman ve frekans domeni özniteliklerinin ne kadar enerji harcayacağına ve aktarımın maliyetine dikkat edilmelidir. Bilgi komple gönderilirse iletişim maliyeti yüksek olur.

Aradan sonra hoca bu noktayı tekrar özetledi: mobil cihazlar için daha az öznitelik kullanmak gereklidir ve bu öznitelikler genelde uç (edge) tarafta çıkarılır.

## 5. Diğer Sensörler: Sağlık, Stres ve Duygu

### 5.1 Akıllı şehir ve kişisel sensörler

Akıllı şehirlerde ve binalarda başka sensörler devreye girer. Hava nem sensörü ortamdaki nem oranını ölçer; evlerde aşırı kuruluk ya da aşırı nem sorun yaratabildiği için düzenleme yapmak adına önemlidir, dış ortamda da bu sensörlere ihtiyaç vardır. Daha kişisel sensörler arasında pedometre vardır; hoca bunun artık çok kritik olmadığını, fiziksel olarak ayrı bir sensör değil diğer fiziksel sensörlerden türetilmiş sanal bir sensör olduğunu söyledi. Nabız ölçer (heart rate monitor) saatlere kadar indi ve saatin telefondan daha iyi sonuç verdiği daha önce konuşulmuştu.

### 5.2 Slayttaki diğer sensörler

"Other Sensors" slaytındaki liste (ekrandan, 01:05:00):

- Radyasyon
- Hava kalitesi
- Alkol
- Glikoz
- Nefes analizi
- Sağlık (healthcare): tek kanallı EKG (one-lead ECG), vücut sıcaklığı, kan şekeri, nabız, kan oksijen satürasyonu, vücut yağ oranı, stres seviyesi.

Radyasyon ölçen cihazlar açık arazide ve nükleer faaliyetlerde kullanılır. Glikoz sensörü vücuttaki şeker miktarını ölçer. Hoca, pandemi döneminde hastaların evde aldıkları ölçümleri uygulamalar aracılığıyla otomatik olarak doktorlarına gönderdiğini söyledi.

**Soru:** Pandemi döneminde en çok talep gören sensör hangisidir? **Cevap:** Öğrenciler kandaki oksijen ölçeri ve ateş ölçeri söyledi; hoca ikisini de doğruladı. Ateş ölçümünün farklı yöntemleri vardır: temassız, alından, kulaktan ya da bilekten. Oksijen ölçerin de saatlere girdiği düşünülürse ilginç gelişmeler beklenir.

### 5.3 Stres seviyesi

Hoca, stres seviyesini yönetebilen insanların daha uzun yaşama ihtimaline sahip olduğunu ve stres arttıkça sağlık sorunlarının da arttığını söyledi. Bir kişinin stresli olduğu nasıl anlaşılır? Öğrenciler vücutta dışa ve içe yansıyan belirtileri saydı; hoca bunların çoğunun kolayca gözlemlenebilecek belirtiler olmadığını söyledi. Buna karşılık anlık stres seviyesi belli oranda yüz ifadelerinden, ses tonundan, kan basıncından ve nabızdan tahmin edilebilir; bazı kişilerin "poker face" denen ifadesi bunu zorlaştırır.

Hoca birkaç yıl önce çağrı merkezi konuşmaları üzerine yapılan çalışmaları örnek verdi: konuşma biçimleri, karşı tarafın gerginliğini azaltan konuşmalar ve verilen cevaplar incelenip çalışanın performansı da hesaplanıyor. Bu analizler sesten de görüntüden de yapılabiliyor.

### 5.4 Duygu farkındalığı

Stresin ötesinde insanların duygularını analiz edip ölçmeye çalışan duygu farkındalığı (emotion awareness), bu alanın önemli konferanslarından PerCom'da (pervasive computing) ayrı bir çalıştay olarak başladı. Hoca "robotlara duygu katılabilecek mi?" diye fütüristik bir soru sordu; öğrenciler bilimkurgu dizilerinden örnekler verdi. Hoca, robotların şimdilik duygu durumundan çok insanın hayatını kolaylaştırmaya odaklandığını, örneğin mağazada müşteriyi yönlendiren ya da fiyat bilgisi veren robotların günlük hayata girmeye başladığını, araştırmaların ise şu anda daha çok insanların duygularını anlamaya yöneldiğini söyledi.

## 6. Konum Belirleme ve İç Mekân Konumlama

### 6.1 Dış mekânda konum

Konum tespiti çok önemlidir ve konum üzerinden çok iş yapılır. Dış mekânda GPS kullanılır. Amerika'nın GPS'inin yanında Rusya'nın GLONASS'ı gibi başka uydu sistemleri de vardır ve birçok mobil cihaz bunların hepsini destekler. GPS'in çok yüksek pil tükettiği bilinir.

**Soru:** GPS'in alternatifi konum ölçme yöntemleri nelerdir? **Cevap:** Bir öğrenci Wi-Fi erişim noktalarının MAC adreslerini söyledi. İkinci yöntem baz istasyonlarıdır: telefon genelde birden fazla baz istasyonunun menzilindedir; her birine olan uzaklık sinyal seviyesinden ölçülür ve üçgenleme (triangulation) mantığıyla yaklaşık konum bulunur.

Enerji tüketimi en yüksekten en düşüğe GPS, baz istasyonu ve Wi-Fi erişim noktasıdır. Şehirde yakında çok sayıda erişim noktası olduğu için Wi-Fi ile oldukça başarılı sonuç alınabilir. Açık alana çıkıldığında erişim noktası bulmak zorlaşır, baz istasyonları da genelde çok yakın değildir; açık alanda en iyi seçenek GPS'tir.

Slaytta "Location Capabilities" başlığı altında GPS, Wi-Fi ağ üçgenlemesi, iç mekân konumlama, RFID ve geniş etiketli NFC (Extended Large Tag NFC) sıralanıyordu (ekrandan, 01:15:00).

### 6.2 RFID ve NFC

RFID ve NFC doğrudan konum bulmak için kullanılmaz ama konumla ilgili işlerde kullanılır. Örneğin bir tır çıkışında ürünlerin bir noktadan ayrılıp ayrılmadığı uygun bir RFID seçilmezse tek tek taratılmak zorunda kalınır. Köprü ve otoyol gişelerindeki geçiş sistemleri de bu tür haberleşme sayesinde araçları yüksek başarıyla tespit eder; aksaklığa karşı kameralar plakaları da okur.

### 6.3 İç mekân konumlama teknikleri

Slayttaki "Indoor Locationing Techniques" karşılaştırması (ekrandan, 01:15:00):

| Teknik | Slayttaki özellikler |
|---|---|
| Wi-Fi/WLAN | WLAN "parmak izi" (Wi-Fi sinyal verisi veritabanı) doğruluğu artırır; çoğunlukla iç mekân haritalarıyla birlikte kullanılır |
| Bluetooth | Menzil 10-30 m, hassasiyet 5-10 m; çok sayıda erişim noktası gerekir |
| RFID | 200 m'ye kadar menzil |
| UWB | Yüksek hassasiyet (<0,3 m), yüksek veri hızı, düşük menzil; henüz akıllı telefonlarda yok, maliyeti yüksek |
| Zigbee | Slayta göre UWB ile aynı temel teknoloji; bugün akıllı telefonlarda doğrudan yok |
| Ultrason | Yüksek hassasiyet (~1 cm), çok sayıda sensör, girişime açık |
| IR (kızılötesi) | Görüş hattı gerektirir, çok yüksek hassasiyet (~1 mm), yerini başka teknolojilere bıraktı |

> **Ders sonrası not:** Slayt Zigbee için "UWB ile aynı temel teknoloji" diyor. Zigbee büyük olasılıkla IEEE 802.15.4 tabanlı düşük güçlü bir dar bant protokolüdür ve UWB ile aynı fiziksel katmanı kullanmaz; UWB ise IEEE 802.15.4a/z ile tanımlanan ayrı bir fiziksel katmandır. Ayrıca slayttaki "henüz akıllı telefonlarda yok" bilgisi büyük olasılıkla eskimiştir; UWB yongası büyük olasılıkla 2019'dan itibaren bazı telefonlarda bulunmaya başladı.

Hoca bu teknikleri şöyle yorumladı: Bluetooth Low Energy işaretçileri (beacon) üzerinden çalışan teknoloji özellikle mağazalarda ve alışveriş merkezlerinde insanların hareketliliğini, bir yerde geçirdikleri süreyi ve vitrine bakma sürelerini hesaplamak için kullanılır; hata payı vardır. UWB'nin doğruluğu çok yüksektir ama menzili düşüktür ve maliyeti belirleyicidir. Zigbee, ultrason ve kızılötesi ile de bir nesnenin diğerine uzaklığı bulunabilir. Ultrason araçlarda park sensörü olarak karşımıza çıkar.

**Soru:** Kızılötesi daha çok nerede karşımıza çıkar? **Cevap:** Bir öğrenci otomatik kapıları söyledi. Hoca doğruladı ve özellikle apartman içindeki mekanizmalarda kullanıldığını, bunların bir kısmının pasif kızılötesi (PIR), bir kısmının aktif kızılötesi olduğunu ekledi. Hareketi algılamak görüş hattı (line of sight) gerektirir; önde bir engel varsa sorun çıkar.

Her konumlama tekniği farklı engellerden farklı etkilenir. Sinyalin kırılması ve girişim (interference) ortamdaki nesnelerin kalınlığına bağlıdır. Örneğin Bluetooth kalın duvarlardan çok etkilenir; sinyal kırılır ve menzil düşer.

## 7. Sensör Kitleri, Basınç Sensörleri ve Park Yeri Tespiti

### 7.1 Akıllı telefona bağlanan sensör kitleri

Hoca, telefonla birlikte kullanılabilen çok sensörlü kitlerden söz etti. Slaytta "Sensordrone - 11 Sensors For Your Smartphone" başlığıyla şu sensörler listeleniyordu (ekrandan, 01:20:00):

- Hassas gaz sensörü: hava kalitesi, karbon monoksit seviyesi.
- İndirgen gaz sensörü: metan, propan ve doğal gaz kaçağı.
- Oksitleyici gaz sensörü: ozon ve klor kaçağı.
- Temassız termometre: yiyecek sıcaklığı, motor teşhisi.
- Nem sensörü: ısı indeksi, uygun gıda saklama koşulları, evde küf oluşumunun önlenmesi.
- Sıcaklık sensörü: ortam sıcaklığı.
- Işık sensörü: ışık şiddeti, güneş ışığı izleme.
- Renk sensörleri: renk ölçer, renk eşleştirici, örüntü tanıma.
- Basınç sensörü: barometre ya da altimetre; bir basınç manşetine bağlanarak tansiyon ölçer olarak da kullanılabilir.
- Yakınlık sensörü: duvar içi dikme bulucu ya da sıvı seviyesi izleyici.
- Genişleme bağlantısı: EKG, termal yazıcı gibi başka sensörler için dijital (TTL UART ve I2C) ve analog (0-3 V) arayüz.

Slaytın devamında kitin Bluetooth 2.1 ve 4.0 kablosuz haberleşme içerdiği ve 0-3 V analog ya da dijital (TTL UART veya I2C) cihazlarla API üzerinden Bluetooth kodu yazmadan çalışılabildiği yazıyordu (ekrandan, 01:30:00). Hoca bunları bir tür taşınabilir sensör istasyonu olarak tanımladı: telefonla Wi-Fi ya da Bluetooth üzerinden, gerektiğinde kabloyla haberleşir. Böylece yalnız telefon değil, telefona bağlanan bir kit taşınarak çok daha fazla sensör etkin şekilde kullanılabilecektir.

### 7.2 Basınç sensörleri ve zemin sensörleri

Hoca basınç sensörünün barometre olarak geçtiğini hatırlattı ve yere yerleştirilip üzerine basılma miktarını ölçen bir versiyonu olduğunu söyledi. Öğrenciler piezoelektrik ve yük hücresi (load cell) gibi isimler önerdi; hoca aradığı ismin bunlar olmadığını ama benzer bir sensörden söz ettiğini söyledi. <!-- BELİRSİZ: Hocanın hatırlayamadığı zemin basınç sensörünün adı derste belirlenmedi. --> Bu tür sensörler yere konarak bölgedeki hareketlilik izlenebilir; sorunları maliyet ve yerleştirme zorluğudur.

### 7.3 Park yeri tespiti

Hoca, bir bölgede park yerlerinin boş olduğunu, boşaldığını ya da boşalmak üzere olduğunu nasıl tespit edebileceğimizi sordu. Tartışmada şu çözümler çıktı:

- **Kapalı otoparklar ve AVM'ler:** Bir öğrenci kızılötesi önerdi. Hoca AVM'lerde kızılötesi ya da ultrason sensörlerinin kullanıldığını doğruladı: park yerinde mesafeye bağlı olarak nesne algılanırsa yer kırmızı, algılanmazsa yeşil görünür.
- **Sokaklar:** Bir öğrenci sokağa giren ve çıkan araçları saymayı ve binaların kamera sistemlerini önerdi. Hoca kameranın teknik olarak bir çözüm olduğunu ama kamusal alanı izlemenin sorunları nedeniyle şu an uygulanmadığını söyledi. Bazı ülkelerde sistem kişisel sorumluluğa dayanır: sürücü ücreti öder, ara sıra geçen bir denetçi ödemeyeni cezalandırır.
- **Paylaşıma dayalı uygulamalar:** Park yerinden çıkan kullanıcı konumunu işaretler, başka kullanıcılar bunu görür, işaretleyen puan kazanır. Sorun, herkesin aynı anda görmesi ve önce gidenin yeri almasıdır.
- **Rezervasyon:** Bir öğrenci önceden park yeri rezervasyonu fikrini anlattı. Hoca bunun girişte plaka okunan ve aracı rezerve edilen yere yönlendiren kapalı otoparklar için işe yaradığını, sokak aralarındaki park yerleri için ise kullanılamadığını söyledi.
- **Yola gömülen sensörler:** Her park noktasının altına küçük bir sensör yerleştirip üzerinde araç olup olmadığına bakmak bir çözümdür ama her sokağa döşemek çok maliyetlidir.

Büyük şehirlerde sürekli park yeri aramak hem benzin hem zaman kaybıdır; hoca bunun çözülmesi gereken bir problem olduğunu vurguladı.

Son olarak hoca havalimanı otoparkları gibi bin, iki bin araçlık büyük açık otoparklar için basit bir yöntem sordu. Bir öğrenci kamerayı önerdi ve girişe kamera koyup giren ve çıkan araçları sayarak doluluğun bilinebileceğini söyledi. Hoca bunun kapasiteyi verdiğini ama boşalan yerin nerede olduğunu söylemediğini belirtti: bin araçlık bir otoparkta tek bir yer kalmışsa içeri giren sürücü o yeri nasıl bulacak? Hoca tek bir kamera koyma şartı koydu. Bir öğrenci kamerayı yüksek bir yere koymayı önerdi ve hoca çözümü tamamladı: açık otoparkta yüksek bir direğe 360 derece görebilen çok yönlü (omnidirectional) bir kamera konursa görüntü sabittir, bütün alan görülür ve park çizgileri zaten çizilidir. Bir bölgede araç olup olmadığı kolayca tespit edilir, araç çıkınca o alanın boşaldığı anlaşılır ve içeri giren araç doğrudan boş yere yönlendirilebilir. Benzer şekilde ormanların güvenliği de yüksek bir noktaya yerleştirilen kamerayla izlenebilir.

## 8. Sensörlerin Sınıflandırılması

Slayttaki "Categorization" başlığı sensörleri üç yaklaşımla sınıflandırıyordu (ekrandan, 01:30:00):

- **Sensör kullanan cihazlar yaklaşımı**
  - Cep telefonları, akıllı telefonlar, tabletler: ivmeölçer, manyetometre, jiroskop, ortam ışığı, yakınlık, sıcaklık ve nem sensörleri, gaz algılama.
  - Aktivite izleyiciler: ivmeölçer, hava basıncı sensörü.
  - Fitness ve spor izleyiciler: nabız sensörü, ivmeölçer, hava basıncı sensörü.
  - Kişisel sağlık: tartı, sıcaklık sensörü, nabız ölçer.
  - Evde kullanılan tıbbi cihazlar: EKG monitörü, tansiyon ölçer, glikoz ölçer.
- **Algılama uygulaması yaklaşımı**
  - Hareket algılama: ivmeölçer, manyetometre, jiroskop, hava basıncı sensörü.
  - Yakınlık algılama: optik, kapasitif ve diğer yöntemler.
  - Gaz algılama: yarı iletken sensörler, optik sensörler ve diğer yöntemler.
- **Pazar ve iş yaklaşımı**
  - Pazar görünümü.
  - Sensör ve algılamanın maliyeti ve değeri.
  - Fikri mülkiyet: patent ve lisanslama.

## 9. Zaman ve Frekans Domeni Öznitelikleri

### 9.1 Zaman domeni öznitelikleri

Hoca sensör sunumunun son slaytına geçmeden önce "zaman domeni özniteliği" denince ne anlaşıldığını sordu. Bir öğrenci yakıt tüketimini önerdi; hoca bunun olmayacak bir şey olmadığını ama çalışılan alana özgü bir bilgi olduğunu, kendisinin istatistiksel olarak her alanda geçerli olabilecek öznitelikleri aradığını söyledi. Ardından şu öznitelikler konuşuldu:

- **Tekrar sayısı (histogram):** Veri setinde her değerin kaç kez tekrar ettiği bulunursa histogram çıkarılmış olur. Görüntüde bu, 0-255 arası gri seviyelerinin her birinin kaç kez tekrar ettiğidir. Birçok sinyalde işe yarar.
- **Değişim miktarı:** Sinyalin $t$ anından $t+1$ anına (ya da $t-1$, $t-k$, $t+k$ gibi daha uzak anlara) geçişte ne kadar arttığı ya da azaldığı.
- **Ortalama, standart sapma, medyan:** Hoca, pencereleme (windowing) yapısını hatırlattı; veri pencerelere ayrıldığında her pencerenin kendi karakteristiği çıkar ve bu bir örüntü hakkında fikir verir.
- **Kovaryans ve öz vektörler:** Bir öğrencinin önerisiydi; hoca mantıklı buldu.
- **Sıfır geçiş oranı (zero crossing rate).**

### 9.2 Sıfır geçiş oranı ve türevleri

Hoca sıfır geçiş oranını bilen olup olmadığını sordu. Bir öğrenci "sinyalin sıfırlanma sayısı" dedi; hoca bunu düzeltti: sinyalin sıfır noktasını kesme sayısıdır, yani pozitiften negatife ya da negatiften pozitife geçme sayısı. İvmeölçer, jiroskop ve manyetometre sinyallerinde özellikle kullanılır. Sıfır geçiş oranı sinyalin kaç kez değişim gösterdiğini, yani değişkenliğini anlatır.

**Soru:** Sıfır geçiş oranı aynı yapıda başka nasıl kurgulanabilir? **Cevap:** Bir öğrenci önceden belirlenmiş bir değeri kesmeyi önerdi. Hoca buna ortalama geçiş oranı (mean crossing rate) ve medyan geçiş oranı (median crossing rate) gibi geçiş oranlarını ekledi. Bunların literatüre tam yerleşmiş öznitelikler olmadığını ama birçok çalışmada faydalı olduklarının görüldüğünü söyledi.

Bir adım ötesi birden fazla çizgi kullanmaktır. Sıfır ekseninin yukarısına da x eksenine paralel kademeler konabilir; hoca bunu çift eşik (double threshold) mantığı olarak tanımladı. Sinyalin bu çizgiler arasında ne kadar gidip geldiğine bakılır. Sinyal bazen bir bantta sıkışıp orada gidip gelmeye başlar; sıfır geçiş oranı bunu göstermeyebilir ama ek çizgiler bir örüntü verir. Özellikle sinyalin hareketli olduğu problemlerde birden fazla geçiş çizgisi belirlemek katkı sağlar.

### 9.3 Slayttaki tanımlar

Sunumun son slaytındaki "Time-Domain and Frequency Features" tanımları (ekrandan, 01:35:00):

- **Sıfır geçişleri (zero crossings):** Sinyalin, sinyal aralığının yarısına karşılık gelen belirli bir değeri kestiği nokta sayısı. Kaynaktaki çalışmada bu değer pencere bölümünün ortalamasıdır.
- **Karekök ortalama (RMS):** $n$ ayrık değerden ($x_1, x_2, \ldots, x_n$) oluşan $x$ sinyalinin RMS'i bir formülle hesaplanır ve anlamlı bağlam bilgisiyle ilişkilendirilebilir.
- **Spektral enerji:** Sinyalin enerjisi, spektral katsayılarının karelerinin toplamının örnek penceresinin uzunluğuna bölünmesiyle hesaplanır.
- **Ortalama:** Penceredeki tüm örnek değerlerinin ortalaması.
- **Varyans:** Penceredeki örnek değerlerinin ortalamadan farklarının karelerinin ortalaması.
- **Standart sapma:** Varyansın karekökü.
- **Medyan:** Penceredeki örneklerin üst yarısını alt yarısından ayıran değer.
- **FFT katsayılarının toplamı:** FFT katsayılarının toplamı; kaynaktaki çalışmada ana frekans bileşenlerini içerdiği için ilk beş FFT katsayısı alınır.

Slaytta RMS formülünün kendisi görünmüyordu. Tanımların matematiksel karşılıkları şöyledir:

> **Ek bilgi (derste anlatılmadı):** $N$ örnekli bir pencerede ortalama $\mu = \frac{1}{N}\sum_{i=1}^{N} x_i$, varyans $\sigma^2 = \frac{1}{N}\sum_{i=1}^{N}(x_i-\mu)^2$, standart sapma $\sigma = \sqrt{\sigma^2}$, RMS $= \sqrt{\frac{1}{N}\sum_{i=1}^{N} x_i^2}$ ve spektral enerji $E = \frac{1}{N}\sum_{k} |X_k|^2$ biçimindedir; burada $X_k$, pencerenin FFT katsayılarıdır.

Slayttaki sıfır geçiş tanımı, derste sıfır noktasını kesme olarak anlatılan kavramı sinyal aralığının ortası ya da pencere ortalaması gibi bir referans değere göre tanımlar; bu, yukarıdaki "ortalama geçiş oranı" fikrine karşılık gelir.

### 9.4 Frekans domeninin maliyeti

Frekans domeni öznitelikleri için önce Fourier dönüşümüyle frekans domenine geçmek gerekir. Bu birçok durumda enerji tüketiminin artması, yani maliyet demektir. Hızlı Fourier dönüşümü (FFT) algoritması kullanılsa bile gelen her pencereyi bir dönüşümden geçirmek gerekir. Bu yüzden mobil cihazlardaki problemler mümkünse zaman domeni öznitelikleriyle çözülür. Spektral enerji gibi frekans domeni öznitelikleri sonraki derslerde daha yakından ele alınacak.

> **Hocanın vurgusu:** Mobil cihazlarda mümkünse zaman domeni öznitelikleri tercih edilir; frekans domenine geçmek her pencere için ayrı bir dönüşüm ve enerji maliyeti demektir.

## 10. Yapay Zekâ, Makine Öğrenmesi, Derin Öğrenme, Veri Madenciliği ve Veri Bilimi

Son bölümde ders yeni bir konuya, dersin adının ikinci kısmına, yani mobil teknolojiler için veri işleme tekniklerine geçti. Şimdiye kadar verinin nereden ve nasıl toplanacağı, cihazların yetenekleri ve fiziksel sensörler, sanal kaynaklar (SMS, uygulama bilgileri, loglar) gibi kaynaklardan gelen veriyle karar mekanizmaları kurulabileceği konuşulmuştu. Şimdi öğrenme ve bilgiyi yorumlama kısmına gelindi.

Hoca şu kavramların birbirine göre nerede durduğunu sordu: yapay zekâ (artificial intelligence), makine öğrenmesi (machine learning), derin öğrenme (deep learning), veri madenciliği (data mining) ve veri bilimi (data science). Öğrenciler farklı sıralamalar önerdi: kimi veri bilimini en üste koydu, kimi veri madenciliğini ikinci sıraya yerleştirdi. Bir öğrenci yapay zekâyı en üste, makine öğrenmesini altına, derin öğrenmeyi makine öğrenmesinin altına ya da yanına koydu; veri madenciliğinin bunlardan biraz farklı ve yanda duran bir alan, veri biliminin ise bunların çoğunu birlikte yapan ve neredeyse fiilî (de facto) bir terim olduğunu söyledi. Hoca en doğru yaklaşımın bu olduğunu söyledi.

Hoca, bu kavramların sıkça karıştırıldığını ve herkesin o dönem popüler olan ismi kullandığını söyledi: bir dönem herkes makine öğrenmesi yapıyordu, sonra herkes derin öğrenme yapmaya başladı; "derin neye göre, sığ (shallow) neye göre?" algısı ise tam oturmadı. Hoca kavramları şöyle tanımladı:

- **Yapay zekâ:** En tepededir. Günlük problemleri insan beyninin çözme biçimini bilgisayara öğreten her türlü çözüm yapay zekânın parçasıdır.
- **Makine öğrenmesi:** Zamanla geçmiş veriden ve deneyimden öğrenen bir yapıyı bilgisayarda gerçekleme ihtiyacı doğdu. Veriyi kullanarak geçmiş veriden ve deneyimden öğrenen sistemler makine öğrenmesi başlığı altındadır ve yapay zekânın bir alt kategorisidir. Literatürde zaman zaman sığ öğrenme (shallow learning) diye de anılır.
- **Derin öğrenme:** Sinir ağı yapısında katman ve nöron sayısının arttığı, yeni ağ türlerinin işe karıştığı, verinin ve onu işleyen donanımın kapasitesinin arttığı bir dönemde ortaya çıkan çözümdür. Esas mesele katman ve nöron sayısının ve epoch sayısının artması ve güçlü GPU'lar eşliğinde çok büyük verinin, örneğin görüntülerin piksel piksel kullanılarak öğrenilmesidir. Özellikle doğrusal olmayan problemlerde sık kullanılır; doğrusal problemlerde daha geride kalabilir.
- **Veri madenciliği:** Verideki ilişkili bilgileri ortaya çıkarmaktır: satış verisinde satılan ürünler arasındaki ilişki, finansal bir gelişmenin diğer araçlarla ilişkisi. Makine öğrenmesinin içinde birebir denemez; makine öğrenmesi ve derin öğrenme ondan yararlanır. Yapay zekânın altında, ikisiyle de doğrudan ilişkili başka bir alan olarak düşünülebilir.
- **Veri bilimi:** Hoca bunu ortaya çıkmış "harika bir pazarlama ismi" olarak niteledi. Veriyle uğraşan herkes veri bilimiyle uğraşıyor kabul edilir. Yalnız bilgisayar bilimi değil, diğer meslek ve mühendislik alanları da yapay zekâ, veri madenciliği ve makine öğrenmesini kullandıkları ölçüde veri bilimine dokunur. Bu yüzden hoca veri bilimini diğerleriyle aynı kümeye değil, farklı bir kümeye koydu.

Hoca derin öğrenmenin yeni adla anılmasının bir nedenini de gradyan kaybolması (vanishing gradient) problemiyle ilişkilendirdi: sinir ağlarında öğrenmenin belirli bir noktada takılıp gerçek sonuca ulaşamaması sorunu derin öğrenmeyle gelen yeni yöntemlerle aşıldı.

> **Ders sonrası not:** Hoca gradyan kaybolması problemini "lokal minimum ya da lokal maksimumda kalma" olarak tarif etti. Bu iki ayrı sorundur. Gradyan kaybolması, geri yayılımda gradyanların katmanlar boyunca çarpılarak çok küçülmesi ve ilk katmanların ağırlıklarının neredeyse hiç güncellenememesidir; yerel minimuma takılma ise optimizasyon yüzeyinin şekliyle ilgili ayrı bir sorundur. Derin öğrenmede ReLU gibi aktivasyon fonksiyonları, uygun ağırlık başlatma, batch normalization ve artık (residual) bağlantılar büyük olasılıkla gradyan kaybolmasını hafifletmek için kullanılan başlıca yöntemlerdir.

> **Hocanın vurgusu:** "Derin öğrenme her şeyi çözer, en iyi sonucu verir" algısı yanlıştır. Derin öğrenmenin başarısız olduğu ya da diğer yöntemlerle başa baş kaldığı durumlar bilinmektedir.

Makine öğrenmesinin amacı, bizim gibi küçüklükten öğrenerek büyüyüp geçmiş tecrübelerimizle karar vermemizi sağlayan bir yapı kurmaktır. Hoca, ilk derste de söylediği bir sorunu hatırlattı: sistemler genelde bir kez öğrenir; veri tekrar tekrar beslenmez, bir model oluşturulup onunla devam edilir. Oysa amaç modelin sürekli güncellenmesi ve sürekli yeni veriyle beslenmesidir.

## 11. Veri Bölme ve Öğrenme Eğrisi Deneyi

Hoca, modelin yeni veriyle beslendikçe nasıl değiştiğini görmek için bir deney düzeni anlattı. Akademik yönleri şöyledir.

### 11.1 Eğitim, doğrulama ve test

Veri seti eğitim (train), doğrulama (validation) ve test olmak üzere üç parçaya ayrılır. Sağlıklı olanı üç parçaya ayırmaktır; veri azsa yalnız eğitim ve test olarak ikiye ayrılabilir.

**Soru:** Eğitim, doğrulama ve test oranları genelde kaçtır? **Cevap:** Bir öğrenci 70-15-15 dedi. Hoca bunun makul olduğunu ama literatürde daha çok 6-2-2 ya da 8-1-1 oranlarının görüldüğünü söyledi; 70 ve 15 birbirinin tam katı olmadığı için de bu oranlar daha düzenlidir.

### 11.2 Artan eğitim verisiyle başarı

Deney düzeni şöyledir:

- Veri 8-1-1 oranında bölünür. Doğrulama ve test kümeleri sabit tutulur.
- Eğitim kümesinin önce %10'uyla model eğitilir, doğrulama ve test başarısı ölçülür.
- Sonra %20, %30 diye eğitim verisi artırılarak aynı ölçüm tekrarlanır ve eğitim kümesinin tamamına varılır.
- Eğitim verisinin hangi parçalarının seçileceği rastgele olmalıdır. Rastgelelik sağlanmazsa veri bir tarafa doğru düzgün dağılmışsa sonuçlar yanıltıcı biçimde iyi ya da kötü çıkabilir. Bu yüzden her denemede veri karıştırılır, tüm deney 10 kez tekrarlanır ve ortalama sonuç verilir.
- 10 denemenin en büyük ve en küçük sonuçlarını göstermek için kutu grafiği (box plot) kullanılabilir.
- En az üç farklı öğrenme yöntemi kullanılmalı ve yöntemler birbirine çok benzememelidir. Örneğin destek vektör makinesi (SVM), rastgele orman (random forest) ve k-en yakın komşu (k-NN) uygun bir üçlüdür. Karar ağacı ve rastgele orman ise ikisi de ağaç yapısında olduğu için aynı tip sayılır; biri topluluk öğrenmesidir (ensemble learning), diğeri değildir.
- Yöntemler hazır araçlarla uygulanabilir: Weka, scikit-learn, MATLAB ya da Python.

**Soru:** 8-1-1'de eğitim kümesinin %10'u alındığında bu tüm verinin ne kadarıdır? Doğrulama ve test de her seferinde değişecek mi? **Cevap:** Eğitim kümesi tüm verinin %80'idir; onun %10'u tüm verinin %8'ine karşılık gelir. Hoca, adımların eğitim kümesinin %10'u ya da tüm verinin %10'u şeklinde tasarlanabileceğini, bunun tasarım kararı olduğunu söyledi. Doğrulama ve test kümeleri her zaman aynı kalır; ilk aşamada onları tekrar rastgele değiştirmek çok fazla kombinasyon yaratacağı için yapılmaz. Hoca, ileride doğrulama kümesinin parametre ayarı için kullanılıp test üzerindeki değişime bakılabileceğini de söyledi.

$$0{,}10 \times 0{,}80 = 0{,}08$$

### 11.3 Başarı metrikleri

**Soru:** Sınıflandırmada hangi başarı metrikleri vardır? **Cevap:** Öğrenciler karışıklık matrisini (confusion matrix), doğruluğu (accuracy), kesinliği (precision) ve duyarlılığı (recall) saydı. Hoca karışıklık matrisinin en ayrıntılı gösterim olduğunu ve diğer metriklerin çoğunun ondan çıkarıldığını söyledi.

> **Ek bilgi (derste anlatılmadı):** İkili sınıflandırmada karışıklık matrisinden doğru pozitif (TP), yanlış pozitif (FP), doğru negatif (TN) ve yanlış negatif (FN) sayıları okunur. Doğruluk $\frac{TP+TN}{TP+TN+FP+FN}$, kesinlik $\frac{TP}{TP+FP}$, duyarlılık $\frac{TP}{TP+FN}$ biçiminde hesaplanır.

### 11.4 Deneyin amacı: verinin miktarı ve niteliği

Hoca deneyden görülmesini istediği şeyleri şöyle sıraladı: birincisi, veri miktarının fazla ya da eksik olmasının başarıya gerçekten etkisi; ikincisi, rastgelelik değiştikçe sonuçların ne kadar saptığı. Ardından sonraki haftalarda işlenecek konulara bağladı. Ayırt edici öznitelikleri tutmak ve kararı bozan özniteliklerden kurtulmak gerekir (öznitelik seçimi, feature selection). Bunun ötesinde örnek seçimi (instance selection) vardır: aynı tipteki örnekleri eğitimde tekrar tekrar kullanmak akıllıca değildir, boşuna zaman kaybıdır. Bir de aykırı değerler (outlier) vardır: öğrenmeye yanlış bilgi vererek öğrenme eğrisini ve modeli bozan örneklerdir. Eğitim verisine rastgele parçalar eklendikçe başarının bazen iyiye bazen kötüye gitmesinin bir nedeni budur. Beklenen yorumlar şunlardır: grafik hiç değişmedi mi, ekledikçe kötüye mi gitti, çok az veriyle eğitmekle tümüyle eğitmek aynı sonucu mu verdi?

## 12. Veri Ön İşlemeye Giriş

Bu bölümün slaytları bir veri ön işleme sunumundan alınmıştı (ekrandan, 02:20:00). Sunumun ana başlıkları arasında entegrasyon, temizleme ve dönüşümler; kusurlu veri (imperfect data); veri azaltma (data reduction) ve son değerlendirmeler vardı (ekrandan, 02:35:00).

### 12.1 Neden ön işleme?

Hoca, veri bilimi, makine öğrenmesi, veri madenciliği ve derin öğrenmenin hepsinde veriyle uğraşırken ilk adımın veri ön işleme olduğunu söyledi. Gelen veride mutlaka bir sorun vardır. Hoca'ya göre en düzgün ve kurumsal görünen şirketlerin verisinde bile kirlilik vardır. Bunun nedenleri:

- Bazı alanların kullanıcıdan gelmesi.
- Hızla kaydetme zorunluluğu.
- Bazı alanların standardının belirlenmemiş olması ve serbest metin (string) olarak bırakılması.

**Soru:** Veri ön işlemenin katkısı nedir? **Cevap:** Bir öğrenci veriyi gürültüden arındırmanın eğitim başarısını artırdığını; çok daha fazla veriyle beslemenin bile bu başarıyı vermeyebileceğini, temiz veriyle çalışmanın daha az maliyetli olduğunu söyledi. Hoca bunu insanla benzetti: kendisine doğru bilgi verilen insan her zaman daha doğru karar verir; yanlış, hatalı, kirli bilgi yanlış karara götürür.

> **Hocanın vurgusu:** Kaliteli veri kullanmak başarının birinci anahtarıdır. Hatta bazen seçilen algoritmadan daha önemlidir. Doğru veriyle ve veriyi temizleyerek çalışmak gerekir.

Slayttaki tanım şuydu: veri ön işleme, bilgi çıkarma algoritmalarından önce kaliteli veriyi ortaya çıkarmaya yönelik işlerdir ("Tasks to discover quality data prior to the use of knowledge extraction algorithms"). Slayttaki döngüde problem tanımı, problemi anlama, veri ön işleme, veri madenciliği, değerlendirme ve sonuçların kullanılması adımları yer alıyordu; veriden bilgiye (knowledge) giden bu süreçte ön işleme, problemi anlamanın hemen ardından gelir (ekrandan, 02:20:00). Sunumun girişinde D. Pyle'ın "Data Preparation for Data Mining" (1999) kitabından şu alıntı vardı: veri hazırlamanın temel amacı ham veriyi, veri setinde saklı bilgi içeriği ortaya çıkacak ya da daha kolay erişilebilir olacak biçimde işlemek ve dönüştürmektir (ekrandan, 02:35:00).

### 12.2 Ön işleme adımları

Hoca ön işleme adımlarını öğrencilere sordu ve şu liste çıktı:

- **Gürültüyü temizleme.**
- **Eksik veri:** Veride boş alanlar olabilir; eksik bilgiyle nasıl baş edileceğine bakılmalıdır.
- **Hatalı veri:** Bir öğrenci yaşın negatif olması örneğini verdi. Hoca, belirli bir mantıksal aralıkta olması gereken ama bu aralığın dışına çıkan verilerin tespit edilip ya düzeltilmesi ya da kullanılmaması gerektiğini söyledi.
- **Normalizasyon:** Veri çok kaliteli olsa bile normalize edilmek istenir.
- **Dönüşüm ve entegrasyon:** Örneğin bankadaki para dolar, avro ve TL olarak tutuluyorsa öğrenmeye vermeden önce tek birime çevrilmelidir. Hoca, maaş gibi bir öznitelikte kişinin dolar ya da TL olarak almasının bir anlamı kalmadığını, ne kadar aldığının aynı birimde karşılaştırılması gerektiğini söyledi.
- **Tutarlılık:** Aralık dışı değerin ötesinde, alanlar birbiriyle çelişebilir: yaş 15 verilmişken doğum tarihi buna uymayabilir. Genelde ikisinden biri seçilerek kullanılır.
- **Veri azaltma:** Ön işleme verinin küçültülmesine de katkı sağlar.

### 12.3 Normalizasyon

**Soru:** Normalizasyonda hangi aralıklar kullanılır? **Cevap:** Ağırlıklı olarak [0, 1] ya da [-1, 1].

**Soru:** Hangi durumda [-1, 1] tercih edilmelidir? **Cevap:** Bir öğrenci birbirine zıt değerler olduğunda dedi. Hoca, [-1, 1] aralığının genelde pozitiflik ve negatiflik olduğunda, sıfırın da aralarında ilişki olmadığını gösterdiği durumlarda tercih edildiğini; çoğunlukla ise [0, 1] aralığına indirgendiğini söyledi.

**Soru:** [0, 1] aralığına normalizasyon için veri grubunda neyi bulmak gerekir? **Cevap:** En küçük ve en büyük değeri; diğer değerler bunlara göre [0, 1] aralığına çekilir.

> **Hocanın vurgusu:** Bu konular basit görünse de çok önemlidir. Birçok hazır fonksiyon vardır ama arka plandaki basit matematiği unutmamak gerekir.

> **Ek bilgi (derste anlatılmadı):** Min-max normalizasyonu $x' = \frac{x - x_{min}}{x_{max} - x_{min}}$ ile [0, 1] aralığına, $x' = 2\cdot\frac{x - x_{min}}{x_{max} - x_{min}} - 1$ ile [-1, 1] aralığına dönüştürür. Eğitimde bulunan $x_{min}$ ve $x_{max}$ değerleri test verisine de aynen uygulanmalıdır.

**Soru:** Normalizasyon neden yapılır? **Cevap:** Bir öğrenci, farklı özniteliklerin farklı aralıkları olabileceğini (yaş 0-80, başka bir öznitelik 0-1000) ve geniş aralıklı özniteliğin daha ağırlıklı olmasını engellemek istendiğini söyledi. Hoca doğruladı: 0-10 arasındaki 9'un etkisi ile 0-100 arasındaki 9'un etkisi farklıdır; ikisi olduğu gibi alınırsa bir öznitelik öğrenme algoritmasına diğerinden farklı etki eder. Bu her zaman böyle yapılmaz ama çoğunlukla yapılır: özniteliklerin eşit ağırlıkla etki etmesi isteniyorsa normalizasyon yapılır; bazı özniteliklerin daha etkin olması isteniyorsa başka yaklaşımlar gerekir.

### 12.4 Kirli veri ve aykırı değerler

Slayta göre gerçek veri kirli olabilir ve işe yaramaz örüntü ya da kuralların çıkarılmasına yol açabilir. Bunun başlıca nedenleri (ekrandan, 02:30:00):

- Eksik veri (incomplete data): öznitelik değerlerinin eksik olması.
- Gürültülü veri (data with noise): hata ya da aykırı değer içermesi.
- Tutarsız veri (inconsistent data): uyuşmazlıklar içermesi.

Slaytın devamındaki ikinci madde, ön işlemenin orijinalden daha küçük bir veri seti üretebileceğini söylüyordu (ekrandan, 02:30:00).

**Soru:** Aykırı değerler nasıl tespit edilir? **Cevap:** Bir öğrenci çeyrekler açıklığını (interquartile range) bulup bu açıklığın dışında kalanları aykırı değer olarak işaretlemeyi önerdi. Başka bir yaklaşım veriye özgü kurallardır: yalnız pozitif değer bekleniyorsa negatifler doğrudan elenebilir.

**Soru:** Gözetimsiz (unsupervised) öğrenmeyle aykırı değer tespiti yapılabilir mi? **Cevap:** Bir öğrenci kümeleme yöntemlerinde grupların kendiliğinden oluşacağını ve kimin ne etkisi olduğunun daha net görülebileceğini söyledi. Hoca bunu tamamladı: önce gruplar oluşturulur, sonra grupların içindeki eleman sayılarına ve grupların birbirine uzaklığına bakılır. Bu grup bazında da tek tek eleman bazında da yapılabilir; çeyrekler açıklığı yaklaşımındaki uzaklık kavramı da işe katılabilir. Çekirdek (kernel) tabanlı algoritmalar da kullanılabilir; uzaklık hesaplanarak en uzaktaki noktalar dışarıda bırakılır.

Hoca asıl önemli noktanın bir değerin gerçekten aykırı olup olmadığına doğru karar vermek olduğunu söyledi. Bazı veri gruplarında uç değerler gerçek hayatta da vardır. Uç değer kararı bozmuyorsa tutulmasında sakınca yoktur. Kararı engelliyor ve yanlış karara sevk ediyorsa gerçek hayatta var olsa bile atılmalıdır. Katkı sağlıyorsa uçta görünse de tutulmalıdır. Bunu ölçmek kolay değildir; tecrübe devreye girer ve tamamen bilgisayara bırakılamaz.

Hoca ön işleme tekniklerinin sonraki derslerde ayrıntılı işleneceğini, ardından veri işleme tekniklerine geçileceğini söyledi.

## 13. Mobil Cihazlarda Kural Tabanlı, Makine Öğrenmesi ve Hibrit Yaklaşımlar

Dersin sonunda hoca bir soru sordu. Makine öğrenmesinin öncülü, daha basit versiyonu kural tabanlı (rule-based) yaklaşımlardır. Elimizde kural tabanlı yaklaşımlar, makine öğrenmesi algoritmaları ve makine öğrenmesinin alt kümesi sayılan derin öğrenme algoritmaları var. Cep telefonları ve akıllı saatlerde hangisi tercih edilmelidir?

Bir öğrenci, kişiye özel yorumlamalar yapılacaksa derin öğrenmenin daha doğru olacağını söyledi. Başka bir öğrenci kaynak tüketimi açısından kural tabanlı yaklaşımın daha az enerji harcayacağını, ama artık mobil cihazlarda daha karmaşık işlemlerin de yapılabildiğini ve uygulamaya göre bakmak gerektiğini söyledi.

Hoca kesinlikle uygulama bazında değerlendirmek gerektiğini kabul etti ve şu ilkeyi verdi: başarı oranı kural tabanlı sistemle tatmin edici bir seviyeye geliyorsa, kaynak tüketimi düşünüldüğünde en akıllıca çözüm kural tabanlı sistemdir. Düşme tespitinde (fall detection) bu görülmüştü: belli bir eşiğin üstünde ya da altında kalmak net bir karar vermeyi sağlıyordu, iki eşik arasında kalındığında ise daha gelişmiş bir öğrenme modeline gidiliyordu.

Bu yüzden telefon ve akıllı saatlerde genelde **hibrit yapı** tercih edilir: kararın net olacağı noktalarda kural tabanlı bir yapı kurulur, kararın belirsiz olabileceği yerler makine öğrenmesi ya da derin öğrenmeyle çözülür. Bir, iki, üç `if` problemi çözüyorsa ve veride örüntüsel bir değişiklik yoksa öğrenmeye gerek yoktur ve enerji tüketimi önemli ölçüde azalır. Hoca, düşme tespiti üzerine bir çalışmada her şeyi makine öğrenmesine göndermek ile yalnız iki eşik arasında kalan örnekleri göndermek arasında ciddi bir enerji farkı görüldüğünü anlattı.

> **Hocanın vurgusu:** Hibrit modeller giyilebilir ve taşınabilir cihazlar üzerinde daha iyi performans verir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:05): Bir sürüş konforu sistemi 0-100 arası puan verecekse, 100 puanlık referans sürüş nasıl tanımlanır ve pratikte nasıl ölçülür?

> **Çözüm (derste verildi):** Teoride A noktasından B noktasına düz bir çizgide, inişsiz-çıkışsız ve dönüşsüz, trafiksiz ve sabit hızla gitmek 100 puandır; hız değişmediği için ivme sıfırdır. Pratikte hız sabitleyici bile küçük hızlanmalar ürettiği için ivme sıfır olmaz. Kaliteli düz bir yolda belirli hızlarla giderken ölçülen ivme referans alınır; ölçülen sürüş buna ne kadar yakınsa puan o kadar yüksektir. İvmenin seçilme nedeni $F = m \cdot a$ ilişkisiyle kişiye uygulanan kuvvetle doğru orantılı olmasıdır.

**Soru 2** (derste sözlü, 00:41:31): Sesten ya da görüntüden bir "parmak izi" nasıl çıkarılır ve bu yaklaşım mobil cihazlar için neden önemlidir?

> **Çözüm (derste verildi):** Ham veri yerine zaman ya da frekans domeninde ayırt edici öznitelikler çıkarılır; örneğin insan sesinin bandı dışındaki frekanslar atılır, yüzde yalnız nirengi noktaları alınır. Öznitelikler ne kadar az ve ayırt edici olursa işlem yükü o kadar azalır. Öznitelik veriyi toplayan cihazda çıkarılıp yalnız öznitelik gönderildiği için (yerinde işleme) iletişim maliyeti de düşer.

**Soru 3** (derste sözlü, 01:24:48): Bin-iki bin araçlık büyük bir açık otoparkta, yalnız bir kamera kullanarak boşalan park yerleri nasıl bulunur ve giren araca nasıl gösterilir?

> **Çözüm (derste verildi):** Girişteki kamera yalnız doluluk sayısını verir, boş yerin nerede olduğunu söylemez. Yüksek bir direğe 360 derece görebilen çok yönlü bir kamera konursa sabit görüntüde bütün alan ve park çizgileri görülür. Her park alanında araç olup olmadığı tespit edilir, araç çıkınca alan boş olarak işaretlenir ve içeri giren araç doğrudan boş yere yönlendirilir.

**Soru 4** (derste sözlü, 01:31:10): Sıfır geçiş oranı nedir? Aynı fikirle başka hangi öznitelikler tanımlanabilir?

> **Çözüm (derste verildi):** Sinyalin pozitiften negatife ya da negatiften pozitife geçiş sayısıdır ve sinyalin değişkenliğini gösterir. Aynı mantıkla önceden belirlenmiş bir değeri kesme sayısı, ortalama geçiş oranı ve medyan geçiş oranı tanımlanabilir. Ayrıca x eksenine paralel birden fazla eşik çizgisi belirlenip sinyalin bu çizgiler arasında gidip gelmesi izlenebilir; sinyal bir bantta sıkıştığında sıfır geçiş bunu göstermese de ek çizgiler örüntüyü yakalar.

**Soru 5** (derste sözlü, 01:52:38): Yapay zekâ, makine öğrenmesi, derin öğrenme, veri madenciliği ve veri bilimi birbirine göre nasıl konumlanır?

> **Çözüm (derste verildi):** En üstte yapay zekâ vardır. Makine öğrenmesi, geçmiş veriden ve deneyimden öğrenen sistemler olarak yapay zekânın alt kategorisidir. Derin öğrenme, katman ve nöron sayısının arttığı sinir ağlarıyla makine öğrenmesinin içinde ya da hemen yanında yer alır. Veri madenciliği verideki ilişkileri ortaya çıkarır; makine öğrenmesi ve derin öğrenmeyle ilişkilidir ama ayrı bir alandır. Veri bilimi bu yöntemleri veri üzerinde kullanan herkesi kapsayan geniş bir kavram olarak farklı bir kümeye konur.

**Soru 6** (derste sözlü, 02:10:27): Veri 8-1-1 oranında bölünüp eğitim kümesinin %10'uyla model eğitildiğinde bu tüm verinin yüzde kaçıdır? Doğrulama ve test kümeleri her adımda değişir mi?

> **Çözüm (derste verildi):** Eğitim kümesi tüm verinin %80'idir; onun %10'u $0{,}10 \times 0{,}80 = 0{,}08$, yani tüm verinin %8'idir (python ile doğrulandı). Doğrulama ve test kümeleri sabit tutulur; yalnız eğitim verisi %10, %20, ... diye artırılır ve rastgele seçimler 10 kez tekrarlanıp ortalama alınır.

**Soru 7** (derste sözlü, 02:23:56 ve 02:24:08): [0, 1] aralığına normalizasyon için veri grubunda neyi bulmak gerekir? Normalizasyon neden yapılır?

> **Çözüm (derste verildi):** En küçük ve en büyük değer bulunur, diğer değerler bunlara göre [0, 1] aralığına çekilir. Amaç farklı aralıklardaki özniteliklerin öğrenmeye eşit ağırlıkla etki etmesidir: 0-10 aralığındaki 9 ile 0-100 aralığındaki 9'un etkisi farklıdır. Pozitif-negatif karşıtlığı olan verilerde [-1, 1] aralığı tercih edilebilir.

**Soru 8** (derste sözlü, 02:28:28): Aykırı değerler nasıl tespit edilir ve tespit edilen her aykırı değer atılmalı mıdır?

> **Çözüm (derste verildi):** Çeyrekler açıklığının dışında kalan değerler işaretlenebilir; veriye özgü kurallar uygulanabilir (yalnız pozitif beklenen bir alanda negatiflerin elenmesi); kümeleme ya da uzaklık tabanlı yöntemlerle gruplardan uzak noktalar bulunabilir. Her uç değer atılmaz: kararı bozuyorsa gerçek hayatta var olsa bile atılır, katkı sağlıyorsa uçta görünse de tutulur. Bu karar tecrübe ister.

**Soru 9** (derste sözlü, 02:32:04): Kural tabanlı, makine öğrenmesi ve derin öğrenme yaklaşımlarından hangisi telefon ve akıllı saatlerde tercih edilmelidir?

> **Çözüm (derste verildi):** Uygulamaya göre değerlendirilir, ama başarı kural tabanlı sistemle tatmin ediciyse kaynak tüketimi açısından en akıllıca çözüm odur. Genelde hibrit yapı tercih edilir: kararın net olduğu bölgede (örneğin düşme tespitinde eşiğin üstü ve altı) kural, belirsiz bölgede (iki eşik arası) makine öğrenmesi ya da derin öğrenme kullanılır. Böylece ciddi enerji tasarrufu sağlanır.

## Dersin Toparlaması

Dersin ilk yarısında sensörler konusu tamamlandı. Manyetometre ve ivmeölçerin tekrarında sinyal vektör büyüklüğünün tek eksenle hesap azaltma fikri öne çıktı. Jiroskop üzerinden sürüş analizine geçildi: sürüşün alt aktiviteleri, bunların sigorta, yol bakımı, risk haritası, trafik, yakıt ve otonom araçlar için kullanımı, ivmeye dayalı 100 puanlık konfor ölçümü, biyosensörler, sürücü yorgunluğu, göz ve baş takibi ile ADAS konuşuldu. Ardından termometre, parmak izi ve Face ID üzerinden ayırt edici öznitelik ve yerinde işleme fikri vurgulandı. Sağlık, stres ve duygu sensörleri, dış ve iç mekân konumlama teknikleri, telefona bağlanan sensör kitleri, park yeri tespiti ve sensörlerin sınıflandırılmasıyla sensör bölümü kapandı. Son olarak zaman domeni öznitelikleri, özellikle sıfır geçiş oranı ve türevleri, ile frekans domeninin mobil cihazlardaki maliyeti tartışıldı.

İkinci yarıda dersin veri işleme kısmına geçildi. Yapay zekâ, makine öğrenmesi, derin öğrenme, veri madenciliği ve veri biliminin birbirine göre yeri netleştirildi. Artan eğitim verisiyle başarının nasıl değiştiğini ölçen bir deney düzeni, veri bölme oranları ve başarı metrikleri anlatıldı. Veri ön işlemeye giriş yapıldı: kirli verinin nedenleri, ön işleme adımları, normalizasyon ve aykırı değerler. Ders, mobil cihazlarda kural tabanlı ve öğrenme tabanlı yaklaşımları birleştiren hibrit modellerin enerji açısından avantajıyla kapandı. Ön işleme teknikleri, öznitelik seçimi, örnek seçimi ve frekans domeni öznitelikleri sonraki derslerde ayrıntılı ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
