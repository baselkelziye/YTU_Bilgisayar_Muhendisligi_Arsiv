# Ders 6 Çalışma Özeti

## Genel Konular

- Lokal arama algoritmalarının tekrarı
  - Önceki arama problemlerinde (sekiz taş, iki şehir arası yol) başlangıç ve hedef verilir, istenen ikisi arasındaki yoldur. Lokal aramada hedefin kendisi verilmez, yalnızca hedefin özellikleri söylenir (sekiz vezirde "hiçbir vezir birbirini tehdit etmesin"); istenen yol değil, hedef durumun kendisidir.
  - Tepe tırmanma: bulunulan durumdan gidilebilecek durumlar üretilir, aralarından sezgisel (değerlendirme) fonksiyonu en yüksek olan seçilir; bu değer mevcut değerden yüksekse oraya gidilir, değilse durulur.
  - Sekiz vezirde rastgele başlangıçlarla tepe tırmanma denemelerin %14'ünde çözer, %86'sında lokal bir maksimuma takılır; $8^8 = 2^{24} \approx 17$ milyon durum vardır (ekrandan, 00:10:00).
  - Varılan yer başlangıç noktasına bağlıdır. Çözüm alternatifleri: farklı başlangıçlarla tekrarlama (random-restart hill climbing), benzetimli tavlama (simulated annealing), paralel tepe tırmanma (local beam search) (ekrandan, 00:15:00).
  - Benzetimli tavlamada iyileşme varsa kabul edilir, yoksa bir olasılıkla kabul edilir; bu olasılık başlangıçta yüksektir, zamanla azalır ve kötüleşme büyüdükçe küçülür.
- Genetik algoritmaların temel kavramları
  - Evrim mekanizmasına (en iyinin yaşaması) dayanır. Amaç uygunluk fonksiyonunun (fitness function) maksimizasyonu ya da minimizasyonudur (ekrandan, 00:20:00).
  - Uygunluk fonksiyonu, daha önceki derslerde konuşulan sezgisel fonksiyonla aynı şeydir; yalnızca jargon farklıdır.
  - Kromozom / birey / durum / çözüm hipotezi aynı anlamdadır: her biri tek başına problemin bir çözüm önerisidir. Bireylerden oluşan kümeye popülasyon (toplum) denir.
  - K adet rastgele üretilmiş kromozomla başlanır; her nesilde yine K bireylik yeni bir popülasyon üretilir ve eski neslin yerine yazılır. Bu yönüyle paralel tepe tırmanmanın bir versiyonu sayılabilir.
  - Kromozomlar sıralı ya da sırasız karakter kümeleriyle temsil edilir; genelde sayılardan ya da 0 ve 1'lerden oluşur.
- Üç operatör
  - Seçme (selection): Bir sonraki nesli üretecek kromozomlar uygunluk değerine göre olasılıklı seçilir.
  - Çaprazlama (crossover, "kol bacak değişimi"): İki bireyden yeni birey(ler) üretilir.
  - Mutasyon: Kromozomun bazı değerleri küçük bir olasılıkla rastgele değiştirilir.
- Genetik algoritma sözde kodu (ekrandan, 00:25:00)
  - Döngü, bir birey yeterince iyi olana ya da yeterli zaman (iterasyon) geçene kadar sürer; sonunda en iyi birey döndürülür.
  - Her iterasyonda popülasyon büyüklüğü kadar: `RANDOM_SELECTION` ile x ve y seçilir, `REPRODUCE(x, y)` ile çocuk üretilir, küçük bir olasılıkla `MUTATE` edilir, yeni popülasyona eklenir.
- Sekiz vezir için genetik algoritma (ekrandan, 00:30:00)
  - Her sütundaki vezirin satırı 3 bitle tutulur; $8 \times 3 = 24$ bit bir tahtayı temsil eder. Slaytta kromozomlar 8 rakamlı dizilerdir.
  - Uygunluk: birbirini tehdit etmeyen vezir çifti sayısı; en az 0, en çok $8 \cdot 7 / 2 = 28$.
  - Başlangıç popülasyonu 24748552, 32752411, 24415124, 32543213; uygunluklar 24, 23, 20, 11; seçilme olasılıkları %31, %29, %26, %14.
  - Seçilenler: 32752411, 24748552, 32752411, 24415124. Çaprazlama sonrası: 32748552, 24752411, 32752124, 24415411. Mutasyon sonrası: 32748152, 24752411, 32252124, 24415417.
- Seçim türleri
  - Rulet tekerleği seçimi: Uygunluk değerleri toplamlarına bölünerek seçilme olasılığına çevrilir.
  - Sıralama seçimi: Popülasyon uygunluğa göre küçükten büyüğe sıralanır, sıra numarası yeni uygunluk olarak atanır, sonra olasılığa çevrilir.
- Farklı olasılıklarla seçim nasıl gerçekleştirilir
  - 1-100 arası rastgele sayı üretip 85'ten küçükse A, değilse B demek (bir öğrencinin önerisi).
  - Çok sayıda seçenek varsa `if` zinciri yerine öğeleri olasılıklarıyla orantılı sayıda içeren bir dizi kurup bu diziden rastgele indis seçmek.
- Gezgin satıcı problemi (TSP)
  - Şehirler arası bir rota bulunur: rota her şehirden geçmeli, toplam yol minimum olmalı (ekrandan, 01:05:00).
  - Kromozom şehirlerin sırasıdır; N şehir için N uzunluğunda bir permütasyon minimum yolu temsil etmeye yeter.
  - MATLAB TSP demosu: 40 rastgele nokta, temsil 40 noktanın indisi; T=0, T=t, T=t+k anlarındaki en iyi bireyin yolu giderek kısalır (ekrandan, 01:10:00).
  - Standart (tek noktalı) çaprazlama TSP'de geçersiz çocuklar üretir: bazı şehirler iki kez geçer, bazıları hiç geçmez.
  - Uniform crossover da bu sorunu çözmez.
  - Sıra tabanlı çaprazlama (order-based crossover) sorunu çözer (ekrandan, 01:15:00).
  - Mona Lisa TSP: 100 bin nokta, olası yol sayısı $100000!$; bulunan bir çözümün en iyi olduğunu bilmek pratikte mümkün değildir (ekrandan, 01:20:00).
- Genetik algoritmayla fonksiyon optimizasyonu (ekrandan, 01:25:00)
  - $f(x) = \cos(x/3)\sin(x/4)$, $x \in [0, 127]$ tam sayı; 128 değer için 7 bit yeterli. Uygunluk kriteri $f(x)$'in kendisidir.
  - İki değişkenli fonksiyonda kromozom 14 bit olur: ilk 7 bit $x_1$, son 7 bit $x_2$ (ekrandan, 01:30:00).
  - Türevlenebilen fonksiyonlarda sürekli uzayda optimizasyon daha mantıklıdır; genetik algoritma ayrık uzayda ya da türev alınamayan durumlarda tercih edilebilir.
- Genetik algoritmanın performansını etkileyen faktörler (ekrandan, 01:35:00 ve 01:50:00)
  - Popülasyon büyüklüğü, mutasyon oranı, kaç noktadan çaprazlama yapılacağı, çaprazlamayla elde edilen iki bireyin ikisinin mi birinin mi kullanılacağı, durum kodlaması, başarı değerlendirmesinin (uygunluk fonksiyonunun) nasıl yazıldığı.
- Olumlu ve olumsuz yönler, hiperparametreler
  - Olumlu: Çaprazlama ve mutasyon sayesinde lokal maksimumlardan ve platolardan kurtulma şansı; doğa temelli bir yaklaşım.
  - Olumsuz: Ayarlanabilir çok fazla parametre; bir problemde gösterilen başarıyı başka bir problemde tekrarlamak zor; başka yöntemlerden daha iyi olduğuna dair matematiksel kanıt yok.
  - Parametre ile hiperparametre farkı ve hiperparametre ayarının kendisinin bir lokal arama problemi olması.
- Uygulamalar: alan tarama ve iki nokta arası yol bulma
  - N×N'lik alanda 8 yöne hareketle, $N \cdot N - 1$ hareketle, minimum açıda dönüşle maksimum alanı gezmek; iyilik fonksiyonu min(açı) ve max(alan) bileşenlerine sahiptir (ekrandan, 01:45:00 sol panel).
  - İki nokta arası yol bulmada üçüncü bileşen eklenir: yolun sonunun hedefe yakınlığı. Örnek ayarlar: P=5000, mu=0.005, G=500, 2 noktadan çaprazlama, yeni nesil eskinin 1/4'ü ve yeninin 3/4'ü (ekrandan, 01:55:00).
  - Birden fazla iyilik fonksiyonunun birleştirilmesi: ölçekleri normalize etmek, min/maks yönlerini aynı yöne çevirmek, önem farkı varsa ağırlıklandırmak; toplama, çarpma, maksimum ya da minimum alma.

## Hocanın Özellikle Vurguladığı Kısımlar

- Lokal aramada istenen şey yol değil, hedef durumdur
  - Sekiz vezirde kullanıcıya yalnızca son tahta söylenir; hangi başlangıçtan ve nasıl ulaşıldığı kimseyi ilgilendirmez.
- Rulet tekerleği seçiminin zayıflığı
  - Bir birey ötekilerden çok daha iyiyse (100, 1, 1, 1) neredeyse her seçimde o seçilir; popülasyonun hepsi aynı birey olur.
  - Bir birey kendisiyle çaprazlanırsa nereden kesilirse kesilsin aynı birey çıkar; geriye yalnızca mutasyonun küçük oynamaları kalır.
  - "Aynı dağın üzerine birden fazla dağcı göndermenin anlamı yok": herkesi aynı yere toplayacaksak çok sayıda çözümü birlikte takip etmenin anlamı kalmaz.
  - Sıralama seçimi bu baskınlığı kaldırır ama en iyi kromozomların avantajı azaldığı için çözüme yaklaşmak yavaşlayabilir. Hangisinin daha iyi olduğu problemden probleme değişir.
- Çaprazlamanın asıl amacı
  - Farklı bireylerde bulunan, kendi içinde anlamlı küçük lokal parçaları bir araya getirmek (örneğin bir bireydeki iyi "3-2-7" parçası ile diğerindeki iyi "4-8-5-5-2" parçası).
- Mutasyon oranı
  - Bireyler birbirine benzemişse çaprazlama yeni çeşitlilik üretemez; tek kurtuluş mutasyondur.
  - Çok yüksek mutasyon (örneğin %80) çaprazlamanın işini ortadan kaldırır, süreci saf rastgeleliğe çevirir ve kararlı bir noktaya ulaşmayı engeller. Genelde başta yüksek tutulur, zamanla azaltılır (benzetimli tavlamaya benzer).
- Brute force'un sınırı
  - Tek değişken ve 128 değer için hepsini denemek kolaydır, ama 10 ya da 100 değişkenle $128^{10}$ gibi sayılara çıkılır; genetik algoritma bu durumda gerekebilir.
- Hiperparametre ayarı bir lokal arama problemidir
  - Her deneme pahalıysa (bir haftalık yapay sinir ağı eğitimi gibi) "rastgele denerim, tutar" yaklaşımı yerine sistematik ya da lokal arama stratejisi önemlidir.
  - Hiperparametre sayısı arttıkça algoritma esnekleşir ama ayarı başlı başına problem olur (uçak kokpitindeki çok sayıda düğme benzetmesi).

## Kısa Tekrar Notları

- Lokal arama: hedef verilmez, hedefin özellikleri verilir; aranan hedef durumun kendisidir.
- Tepe tırmanma başlangıca bağlıdır; sekiz vezirde denemelerin %14'ünü çözer.
- Genetik algoritma = paralel tepe tırmanma + seçme, çaprazlama, mutasyon.
- Uygunluk fonksiyonu = sezgisel fonksiyon; kromozom = birey = durum = çözüm hipotezi; popülasyon = bireyler kümesi.
- Sekiz vezir: uygunluk birbirini tehdit etmeyen çift sayısı, maksimum 28.
- Rulet tekerleği: $p_i = f_i / \sum_j f_j$. Sıralama seçimi: sıra numarası yeni uygunluk olur.
- TSP'de standart ve uniform çaprazlama geçersiz rota üretir; sıra tabanlı çaprazlama geçerli rota üretir.
- Çok parametreli fonksiyonda kromozom değişkenlerin bitlerinin art arda eklenmesidir.
- Popülasyon büyüklüğü: çeşitlilik ile hesaplama maliyeti arasında denge.
- Mutasyon oranı: düşükse sıkışma, çok yüksekse kararsızlık.
- Çok noktalı çaprazlama bazı problemlerde çok yararlıdır.
- Birden fazla amaç birleştirilirken normalizasyon, yön dönüşümü ve ağırlıklandırma gerekir.
- Hiperparametre: kullanıcı verir, algoritma öğrenemez. Parametre: model veriden öğrenir.

## Detaylı Açıklamalar

- **Sözde kod:** Ekrandaki genetik algoritma şöyledir (ekrandan, 00:25:00):

  ```text
  function GENETIC_ALGORITHM(population, FITNESS-FN) return an individual
    input: population, a set of individuals
           FITNESS-FN, a function which determines the quality of the individual
    repeat
      new_population <- empty set
      loop for i from 1 to SIZE(population) do
        x <- RANDOM_SELECTION(population, FITNESS_FN)
        y <- RANDOM_SELECTION(population, FITNESS_FN)
        child <- REPRODUCE(x, y)
        if (small random probability) then child <- MUTATE(child)
        add child to new_population
      population <- new_population
    until some individual is fit enough or enough time has elapsed
    return the best individual
  ```

  `RANDOM_SELECTION` adında "rastgele" geçse de tamamen rastgele değildir; uygunluğu yüksek bireyin seçilme olasılığı daha yüksektir. Sözde kodda her çiftten bir çocuk üretilir; derste gösterilen sekiz vezir örneğinde her çiftten iki çocuk üretilir. Bu durumda $n$ yerine $n/2$ çift yeterlidir, her çiftten tek çocuk üretilirse $2n$ seçim yapmak gerekir. Paralel tepe tırmanmayla tek fark, yeni popülasyonun nasıl üretildiğidir (döngünün içi).

- **Sekiz vezir örneği (ekrandan, 00:30:00):** "24748552" kromozomu, 1. sütundaki vezirin 2. satırda, 2. sütundakinin 4. satırda, 3. sütundakinin 7. satırda olduğunu söyler. Uygunluk değerleri ve olasılıklar:

  | Başlangıç | Uygunluk | Olasılık |
  |---|---|---|
  | 24748552 | 24 | %31 |
  | 32752411 | 23 | %29 |
  | 24415124 | 20 | %26 |
  | 32543213 | 11 | %14 |

  Olasılık $24/(24+23+20+11) = 24/78 \approx \%31$ biçiminde hesaplanır. Seçimde 2., 1., 2. ve 3. bireyler seçilmiş, 4. birey (en düşük olasılıklı) hiç seçilmemiştir. Bu rastgeleliğin sonucudur; en yüksek olasılıklı bireyin en çok seçileceği garanti değildir. Birinci çift 3. rakamdan sonra, ikinci çift 5. rakamdan sonra kesilerek çaprazlanmıştır: 32752411 ve 24748552 çiftinden 32748552 ve 24752411; 32752411 ve 24415124 çiftinden 32752124 ve 24415411. Mutasyonda 32 rakamdan (%10 oranla yaklaşık) 3'ü rastgele değiştirilmiş: 32748**1**52, 32**2**52124, 2441541**7**. Uygunluk değerleri python ile doğrulandı. Süreç, bir bireyin uygunluğu 28 olana ya da en fazla nesil sayısı aşılana kadar sürer.

- **Sıralama seçimi örneği (ekrandan, 01:00:00):** Orijinal uygunluklar 1, 1, 1, 100 olsun. Sıra değerleri 1, 2, 3, 4 olur; olasılıklar $1/10, 2/10, 3/10, 4/10$ (10, sıra değerlerinin toplamı). En iyi birey %40 ile yine en olası olandır, ama diğerlerinin de seçilme şansı vardır.
  - Ders sonrası not: Ekranda rulet tekerleğiyle 100, 1, 1, 1 uygunluklarının olasılığı "99" ve "0.33" diye yazıldı. Doğrusu $100/103 \approx \%97.1$ ve $1/103 \approx \%0.97$'dir. Hocanın asıl vurgusu (en iyi bireyin neredeyse her seçimde seçileceği) değişmez.

- **Sıra tabanlı çaprazlama (ekrandan, 01:15:00):** Kromozom boyutunda rastgele 0/1 şablonu (template) oluşturulur. Child1 için şablonda 1 olan indislerde Parent1'in değerleri aynı indislere konur. Şablonda 0 olan indislerdeki Parent1 değerleri, Parent2'deki geçiş sırasına göre dizilir ve Child1'in boşluklarına bu sırayla yerleştirilir. Child2 için roller değişir.

  | | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
  |---|---|---|---|---|---|---|---|
  | Parent 1 | A | B | C | D | E | F | G |
  | Parent 2 | E | B | D | C | F | G | A |
  | Template | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
  | Child 1 | E | B | C | D | G | F | A |
  | Child 2 | A | B | D | C | E | G | F |

  Child1: B, C, F yerinde kalır; A, D, E, G, Parent2 sırasına göre E, D, G, A olur. Child2: B, D, G yerinde kalır; E, C, F, A, Parent1 sırasına göre A, C, E, F olur. Hiçbir şehir kaybolmaz ya da tekrar etmez (python ile doğrulandı).

- **Tek ve çok noktalı çaprazlama (ekrandan, 01:40:00):** ABCDEFGH ile 12345678 tek noktadan (3. karakterden sonra) çaprazlanınca ABC45678 ve 123DEFGH; iki noktadan (2. ve 6. karakterden sonra) çaprazlanınca AB3456GH ve 12CDEF78 elde edilir.

- **İki değişkenli fonksiyon (ekrandan, 01:30:00):** B1 = 0000011 0011010, B2 = 0010000 1110111 gibi 14 bitlik kromozomlarda ilk 7 bit $x_1$'i, son 7 bit $x_2$'yi gösterir. Hoca, tek bir noktadan çaprazlamak yerine her değişkenin bit alanı içinde ayrı ayrı çaprazlama yapmanın mantıklı olabileceğini söyledi.
  - Ders sonrası not: Hoca bu kısımda "cross-validation" dedi; kastettiği çaprazlamadır (crossover). Cross-validation, makine öğrenmesinde modeli değerlendirme yöntemidir.
  <!-- BELİRSİZ: Hocanın 01:30 civarında çizdiği değişken içi çaprazlama örneğinin bitleri karede okunamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
