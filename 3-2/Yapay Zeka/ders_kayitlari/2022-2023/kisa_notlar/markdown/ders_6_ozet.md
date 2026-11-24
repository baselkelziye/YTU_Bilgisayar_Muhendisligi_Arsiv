# Ders 6 Çalışma Özeti

## Genel Konular

- Lokal arama algoritmalarının tekrarı (ekrandan, 00:10:00 - 00:15:00)
  - Önceki arama algoritmalarında başlangıç ve hedef verilir, çözüm ikisi arasındaki yoldur (operatör dizisi). Lokal aramada ise yol önemsizdir; istenen, belirli kısıtları sağlayan ya da bir fayda fonksiyonunu maksimum yapan durumun kendisidir (örnek: n-vezir, zirve bulma).
  - Lokal arama da sezgiseldir: durumun hedefe ne kadar uygun olduğunu tahmin eden bir fonksiyon kullanır. Hafızada yalnız mevcut durum tutulur ve düzeltilmeye çalışılır; çok az hafıza gerekir.
  - Temel algoritma tepe tırmanmadır: her adımda mevcut durumu en çok iyileştiren yöne gidilir ("yoğun siste Everest'e tırmanmak"). Büyük arama uzaylarında bütün alanı görüp global optimuma gitmek mümkün değildir.
  - Çözüm alternatifleri: farklı başlangıçlarla tekrarlamak (random-restart), benzetimli tavlama (ara sıra kötüleştiren adımlara izin vermek), paralel tepe tırmanma (local beam search; tek dağcı yerine K dağcı).
- Genetik algoritmanın temel kavramları (ekrandan, 00:20:00)
  - Evrim mekanizmasına (en iyinin yaşaması) dayanır. Amaç uygunluk (fitness) fonksiyonunun maksimizasyonu ya da minimizasyonudur. Fitness fonksiyonu lokal aramadaki sezgisel fonksiyonun karşılığıdır.
  - Kromozom ya da birey bir çözüm önerisidir (durum). K adet rastgele üretilmiş kromozomun kümesine popülasyon (toplum) denir. Kromozomlar sıralı ya da sırasız karakter kümeleriyle, genelde sayılarla ya da 0-1 dizileriyle temsil edilir.
  - Paralel tepe tırmanmaya çok benzer. Tek fark, K bireyden yeni K bireyin üretilme biçimidir: seçme (selection), çaprazlama (crossover) ve mutasyon.
- Genetik algoritmanın sözde kodu (ekrandan, 00:25:00)
  - Her nesilde boş bir yeni popülasyon kurulur. Popülasyon büyüklüğü kadar tekrar: fitness'a göre rastgele iki ebeveyn seçilir, çaprazlamayla çocuk üretilir, küçük bir olasılıkla mutasyona uğratılır, yeni popülasyona eklenir. Sonra eski nesil yeni nesille değiştirilir.
  - Döngü, bir birey yeterince iyi olunca ya da yeterli zaman geçince biter. En iyi birey döndürülür.
- 8 vezir örneği (ekrandan, 00:30:00)
  - Birey, her sütundaki vezirin satır numarasını veren 8 rakamlık dizidir (örn. 24748552).
  - Fitness: birbirini tehdit etmeyen vezir çiftlerinin sayısı; en az 0, en çok $8 \cdot 7/2 = 28$. Hedef 28'e ulaşmaktır.
  - Dört bireyin fitness değerleri 24, 23, 20, 11; seçilme olasılıkları $24/78 \approx \%31$, $23/78 \approx \%29$, $20/78 \approx \%26$, $11/78 \approx \%14$.
  - Seçimde birinci birey bir, ikinci iki, üçüncü bir kez seçildi; dördüncü hiç seçilmedi. Eşlenen çiftler rastgele bir noktadan kesilip parçaları değiştirilerek iki çocuk üretildi; sonra birkaç rakam rastgele değiştirildi (mutasyon).
- Kromozom seçim türleri (ekrandan, 00:40:00)
  - Rulet tekeri seçimi: olasılık doğrudan fitness'la orantılıdır. Bir birey çok baskınsa (A=90, B=2, C=5, D=3 için A'nın olasılığı %90) hep aynı birey seçilir, aynı bireylerin çaprazlanması yeni bir şey üretmez, iş mutasyona kalır.
  - Sıralama seçimi: bireyler fitness'a göre sıralanıp en kötüye 1, en iyiye en büyük sıra verilir; olasılık sıra numarasıyla orantılıdır. Aynı örnekte A %40, B %10, C %30, D %20 olur. Bu seçim çeşitliliği korumaya yöneliktir.
- Gezgin satıcı problemi (TSP) ve permütasyon kodlaması (ekrandan, 01:00:00 - 01:10:00)
  - Satıcı N şehrin hepsine birer kez uğrayacak; toplam yol en kısa olmalı. Birey şehirlerin bir permütasyonudur, fitness rotanın toplam uzunluğudur (küçük olan iyi).
  - Standart tek noktalı çaprazlama geçersiz rota üretir: bazı şehirler iki kez geçer, bazıları hiç geçmez.
  - Uniform crossover: rastgele 0-1 şablonu; 1'lerde ebeveyn değeri aynen alınır, 0'larda iki ebeveynin değerleri yer değiştirir. TSP için yine geçersiz çocuk üretir.
  - Sıra tabanlı (order-based) crossover: şablonda 1 olan yerler ebeveynden aynen alınır, 0 olan yerlerdeki şehirler diğer ebeveyndeki sıralarına göre dizilip boşluklara yerleştirilir. Çocuk her zaman geçerli bir permütasyondur.
  - Mona Lisa TSP: 100 bin noktayı elini kaldırmadan birleştiren rota. Olası rota sayısı faktöriyel olduğu için bulunan çözümün en iyi olduğunu kanıtlamak pratikte imkansızdır.
- Genetik algoritma ile fonksiyon optimizasyonu (ekrandan, 01:15:00)
  - $f(x) = \cos(x/3) \cdot \sin(x/4)$, $x \in [0, 127]$ tam sayı. 128 değer 7 bitle gösterilir. Başlangıç popülasyonu: a = 0000011, b = 1110111, c = 0010000, d = 0011010. Uygunluk ölçütü $f(x)$'in kendisidir.
  - Fonksiyonda çok sayıda lokal maksimum ve minimum vardır. Uzay küçük olduğundan bu örnekte hepsini denemek de mümkündür; parametre sayısı ve hassasiyet arttıkça (örn. $F(x,y) = x^2 - y^3 + xy^2$) tam tarama imkansızlaşır.
- Genetik algoritmanın performansını etkileyen faktörler
  - Popülasyon büyüklüğü, mutasyon oranı, çaprazlama nokta sayısı, çaprazlama sonucu elde edilen bireylerin nasıl değerlendirileceği, durumun kodlanması, başarı (fitness) değerlendirmesi.
- Değerlendirme (ekrandan, 01:20:00)
  - Olumlu: crossover ve mutasyon sayesinde lokal maksimum ve platolardan kurtulabilir; doğa temellidir.
  - Olumsuz: ayarlanması gereken çok parametre vardır, bir problemdeki başarı başka problemde zor tekrarlanır; farklı başlangıçlı tepe tırmanmadan ya da paralel tepe tırmanmadan daha iyi olduğuna dair matematiksel kanıt yoktur.
- Uygulamalar: alan tarama ve iki nokta arası yol bulma (ekrandan, 01:25:00)
  - Alanı az dönüşle tarayan yol: P adet çözümle başlanır, G nesil boyunca çaprazlama ve mutasyonla yeni çözümler üretilir; yeni nesle eski neslin ve yeni neslin bir kısmı alınır.
  - İki nokta arası yol: iyilik fonksiyonunun üç bileşeni vardır: min(açı), max(alan), max(sonun hedefe yakınlığı).
- İyilik fonksiyonlarının birleştirilmesi
  - Ölçekler farklıysa normalize etmek gerekir; min ve max bileşenleri aynı yöne çevrilmelidir; önem dereceleri farklıysa ağırlıklandırılır. Birleştirme toplama, çarpma, maksimum ya da minimum alma ile yapılabilir.
- Genetik programlama (ekrandan, 01:30:00)
  - Genetik algoritma değildir. Her geçerli program bir parse ağacı ile gösterilebilir; ağaçlar arasında alt ağaç değiştirerek (crossover) ve mutasyonla yeni programlar üretilir.
  - Zorluk sırası: verilen sayılardan bir sayı üretmek, 10 elemanlı diziyi sıralayan kod, N elemanlı diziyi sıralayan kod, herhangi bir görev tanımını koda dönüştürmek.
  - Sorunlar: fitness olarak K görevden kaçının başarıldığını kullanmak yanıltıcı olabilir; küçük bir değişiklik ($<$ yerine $>$) programı tamamen bozar; aynı işi yapan kodları karşılaştırmak ve gereksiz kod blokları da sorundur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Lokal aramanın asıl farkı çözdüğü problem türüdür.
  - Kullanıcı yolu değil, istenen özelliklere sahip son durumu ister. Optimal olmama bu algoritmalara özgü bir fark değildir; önceki derslerde de optimal olmayan algoritmalar görülmüştü.
- Genetik algoritmadaki "random selection" tamamen rastgele değildir.
  - Seçim fitness değerine göre ağırlıklı rastgeledir. Tamamen rastgele seçimde ilerleme olmaz.
- Olasılık kesinlik değildir.
  - %29 olasılıklı birey %31'likten daha çok seçilebilir, %14'lük hiç seçilmeyebilir.
- Çocukların ebeveynlerden daha iyi olacağının garantisi yoktur.
  - Temenni budur ama algoritma bunu garanti etmez. İlerlemeyi sağlamak için algoritmaya ekler yapılabilir (örn. eski neslin iyilerini yeni nesle taşımak).
- Genetik algoritmada "kötüleştiyse reddet" mekanizması yoktur.
  - Mutasyon kötüleştirse de uygulanır. Kötü bireyler yalnız seçilmedikleri için bir sonraki nesle aktarılamaz.
- Lokal arama algoritmaları optimal çözüm vaat etmez.
  - Amaçları çok büyük arama uzaylarında kabul edilebilir sürede yeterince iyi bir çözüm sunmaktır. Pratikte bir ay daha bekleyip birkaç kilometre daha kısa rota bulmayı kimse kabul etmez.
- Genetik programlama genetik algoritma değildir; isimleri benzer ama aynı şey değildir.

## Kısa Tekrar Notları

- Lokal arama: yol önemsiz, hedef durumun kendisi istenir; hafızada yalnız mevcut durum tutulur.
- Lokal arama yöntemleri başlangıç durumuna bağlıdır; farklı başlangıç farklı sonuç verir.
- Genetik algoritma = paralel tepe tırmanma + farklı üretim mekanizması (seçme, çaprazlama, mutasyon).
- Terimler: kromozom/birey = çözüm önerisi, popülasyon = K bireylik küme, fitness = sezgisel iyilik ölçüsü.
- Bir döngü turu = bir nesil. Sonunda popülasyonun en iyi bireyi döndürülür.
- 8 vezir fitness'ı: tehdit etmeyen çift sayısı, en çok 28.
- Rulet tekeri: olasılık fitness'la orantılı; baskın birey çeşitliliği öldürür.
- Sıralama seçimi: olasılık sırayla orantılı; çeşitliliği korur.
- TSP'de standart ve uniform crossover geçersiz rota üretir; sıra tabanlı crossover geçerli permütasyon üretir.
- 100 bin şehirli TSP'de bulunan çözümün en iyi olduğu bilinemez; olası rota sayısı faktöriyel düzeyindedir.
- Mutasyon oranı başlangıçta yüksek tutulup zamanla azaltılabilir (benzetimli tavlamadaki sıcaklığa benzer).
- GA'nın olumsuz yanı: çok hiperparametre, başarının problemden probleme taşınamaması, üstünlüğüne dair matematiksel kanıt olmaması.
- Birden çok fitness bileşeni birleştirilirken ölçek, yön (min/max) ve ağırlık dikkate alınır.
- Genetik programlama parse ağaçları üzerinde crossover ve mutasyon yapar.

## Detaylı Açıklamalar

- Lokal aramanın yeri
  - Önceki haftalarda görülen kör ve sezgisel arama algoritmalarında başlangıç ve hedef durumu verilir, çözüm bu ikisini bağlayan operatör dizisidir. Lokal arama ise farklı bir problem türünü çözer: kullanıcı yalnız istenen durumun özelliklerini söyler (örneğin n vezirin birbirini tehdit etmeden yerleştirilmesi) ve oraya nasıl gidildiğiyle ilgilenmez. Algoritma yine bir durumdan başlayıp adım adım iyileştirir, ama bunu yaparken yalnız mevcut durumu hafızada tutar.
  - Hoca sezginin rolünü önceki dersteki bozuk televizyon ve kasa örnekleriyle hatırlattı: televizyonda düğmeyi çevirince ekrandaki görüntünün iyileşip kötüleştiği görülür, yani bir sezgi vardır; kasada ise böyle bir geri bildirim yoktur, kör arama gerekir. Kasayı stetoskopla dinlemek bir sezgi edinme yoludur. Sezgi problemi daha iyi değil, daha hızlı çözmeyi sağlar.
  - Lokal arama algoritmalarının hepsi başlangıç durumuna bağlıdır. Bu yüzden farklı çözümlere ulaşmanın en yaygın yolu farklı başlangıçlarla denemektir. Benzetimli tavlama "konfor alanından çıkmak" fikrine benzer: sürekli iyileştirmek yerine ara sıra kötüleşmeye izin verilir. Paralel tepe tırmanmada ise tek dağcı yerine K dağcı gönderilir; genetik algoritma bu fikrin üzerine kuruludur.
- Genetik algoritmanın işleyişi
  - Fonksiyon bir popülasyon ve bir fitness fonksiyonu alır, bir birey döndürür. Her nesilde yeni popülasyon boş başlar. Popülasyon büyüklüğü kadar tekrarlanan döngüde iki ebeveyn fitness'a göre ağırlıklı rastgele seçilir, çaprazlamayla bir çocuk üretilir, çocuk küçük bir olasılıkla mutasyona uğratılır ve yeni popülasyona eklenir. Döngü bitince yeni popülasyon eskisinin yerine geçer, yani eski nesil "ölür". Bu dış döngünün her turu bir nesil geçişidir.
  - Seçimin amacı bir sonraki nesli oluşturacak bireyleri belirlemektir. Fitness'ı yüksek olanların seçilme olasılığı daha yüksek olmalıdır ki çözümler iyileşsin; ama olasılık kullanıldığı için düşük fitness'lı bireyler de seçilebilir.
- 8 vezir örneği (ekrandan, 00:30:00)
  - Birey 24748552 ise birinci sütunda vezir 2. satırda, ikinci sütunda 4. satırda, üçüncü sütunda 7. satırdadır. Başlangıç popülasyonu 24748552, 32752411, 24415124, 32543213 bireylerinden oluşur; fitness değerleri sırasıyla 24, 23, 20, 11'dir (python ile doğrulandı). Toplam 78'dir; seçilme olasılıkları yaklaşık %31, %29, %26, %14 olur.
  - Seçilenler 32752411, 24748552, 32752411, 24415124'tür. Birinci çift üçüncü rakamdan sonra kesilerek 32748552 ve 24752411; ikinci çift beşinci rakamdan sonra kesilerek 32752124 ve 24415411 çocukları üretilir. Mutasyonla üç rakam rastgele değişir: 32748552 → 32748152, 32752124 → 32252124, 24415411 → 24415417.
  - Hoca, 8 vezirde çaprazlamanın iki tahtanın sol ve sağ parçalarını birleştirmek demek olduğunu gösterdi. Bir çiftten iki çocuk da üretilebilir, tek çocuk da; bu tercih probleme göre deneme yanılmayla yapılır.
- Seçim türleri (ekrandan, 00:40:00)
  - Rulet tekeri seçiminde fitness değerleri doğrudan olasılığa çevrilir. Fitness'lar A=90, B=2, C=5, D=3 ise olasılıklar %90, %2, %5, %3 olur ve neredeyse her seferinde A (örneğin [3 2 7 8 1 5 6 4]) seçilir. Aynı iki birey çaprazlanırsa nereden kesilirse kesilsin kendileri çıkar; çaprazlamanın katkısı kaybolur, iş tamamen mutasyona kalır.
  - Sıralama seçiminde en düşük fitness'a 1, sonrakine 2, ... en yükseğe 4 verilir ve olasılık sıra / (1+2+3+4) olur: A → 4/10 = %40, B → 1/10 = %10, C → 3/10 = %30, D → 2/10 = %20. Farklar küçüldüğü için çeşitlilik korunur. Rulet tekeri ise hep iyi olanın kazanmasına odaklanır.
- Gezgin satıcı problemi
  - Örnekte 40 noktalık bir haritada 100 bireylik popülasyonla çalışılır; birinci nesildeki en iyi rota çok karışıkken ilerleyen nesillerde belirgin şekilde düzelir (ekrandan, 01:00:00, slayt önizlemesi).
  - Standart çaprazlamada CityList1 = (3 5 7 | 2 1 6 4 8) ve CityList2 = (2 5 7 | 6 8 1 3 4) kesilirse (ekrandan, 01:00:00, slayt önizlemesi) (3 5 7 6 8 1 3 4) ve (2 5 7 2 1 6 4 8) çıkar; birincisinde 3 iki kez geçer, 2 hiç geçmez, ikincisinde tersi olur. Bunlar çözüm değildir.
  - Uniform crossover örneği (ekrandan, 01:00:00): P1 = A B C D E F G H I J, P2 = E F J H B C I A D G, T = 1 0 1 1 0 0 0 1 0 1. Sonuç C1 = A F C D B C I H D J, C2 = E B J H E F G A I G. C1'de C ve D, C2'de E ve G tekrar eder.
  - Sıra tabanlı crossover örneği (ekrandan, 01:05:00): Parent1 = A B C D E F G, Parent2 = E B D C F G A, Template = 0 1 1 0 0 1 0. Child1'e 1 olan yerlerden B, C, F aynen gelir; 0 olan yerlerdeki A, D, E, G Parent2'deki sıraya göre E, D, G, A diye dizilip boşluklara konur: Child1 = E B C D G F A. Child2 için aynı yöntemle (E C F A) Parent1 sırasına göre (A C E F) olur: Child2 = A B D C E G F. Her çocuk kendi ebeveyninin yeniden düzenlenmiş halidir; ikinci ebeveyn yalnız sıralamayı belirler (python ile doğrulandı).
- Optimalliği kanıtlamanın imkansızlığı
  - 100 bin noktalı Mona Lisa rotasında bulunan çözümden daha iyisinin olmadığını göstermek için bütün olasılıkları denemek gerekir; bunların sayısı 100 bin faktöriyel düzeyindedir. Küçük örneklerde iyi çalışan bir algoritmanın büyük örnekte de en iyiyi bulacağı söylenemez; zaten küçük örnekte bile bunu garanti etmek zordur. Pratikte yeterince iyi bir çözümü makul sürede bulmak yeterlidir.
- Fonksiyon optimizasyonu ve performans faktörleri
  - $f(x) = \cos(x/3)\sin(x/4)$ örneğinde 0-127 arası tam sayılar 7 bitlik ikili dizilerle kodlanır; bu kodlamada standart crossover sorun çıkarmaz. Başlangıç bireyleri a = 0000011 (3), b = 1110111 (119), c = 0010000 (16), d = 0011010 (26) şeklindedir.
  - Hoca mutasyonu benzetimli tavlamadaki sıcaklığa benzetti: başlangıçta yüksek tutulup zamanla azaltılabilir. Bütün bireyler aynı küçük tepeye ya da aynı platoya sıkışmışsa crossover işe yaramaz; o zaman mutasyon devreye girer. İki farklı değiştirme mekanizmasının olmasının avantajı budur.
- Uygulama ayrıntıları (ekrandan, 01:25:00)
  - Alan tarama uygulamasında P = 5000, mutasyon oranı 0,01, G = 200 nesil, 2 noktadan çaprazlama kullanıldı; yeni nesil eski ve yeni neslin en iyi yarılarından oluştu. Grafikte popülasyonun ortalama fitness'ı ve en iyi bireyin fitness'ı nesiller boyunca azalır (burada küçük fitness iyidir).
  - İki nokta arası yol uygulamasında P = 5000, mutasyon oranı 0,005, G = 500, 2 noktadan çaprazlama kullanıldı; yeni nesil eskinin 1/4'ü ve yeni neslin 3/4'ünden oluştu. Amaç dümdüz gitmek değil, devriye atar gibi olabildiğince çok yer gezip yumuşak dönüşlerle hedefe varmaktır.
  - Fitness bileşenleri birleştirilirken biri 500-5000, diğeri 0-50 aralığındaysa doğrudan toplamak büyük ölçekli bileşenin etkisini artırır; bilerek yapılmıyorsa normalize edilmelidir.
- Genetik programlama (ekrandan, 01:30:00)
  - Slayttaki örnekte $x \cdot x - (x \cdot y) \cdot 2$ ağacı ile $(x \cdot x + y)/2$ ağacı arasında alt ağaçlar değiştirilir: birinci ağaçtaki $x \cdot y$ alt ağacı ile ikinci ağaçtaki $x \cdot x + y$ alt ağacı yer değiştirince $x \cdot x - (x \cdot x + y) \cdot 2$ ve $(x \cdot y)/2$ elde edilir.
  - Sıralama kodu üretirken fitness, rastgele üretilmiş birçok test dizisinden kaçının doğru sıralandığı olabilir. Ama 10 görevden 7'sini başaran kod 9'unu başarana göre gerçekten daha mı kötüdür, belli değildir; doğru çalışan bir sıralama kodunda $<$ yerine $>$ yazmak başarıyı 10'da 10'dan 10'da 0'a düşürebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
