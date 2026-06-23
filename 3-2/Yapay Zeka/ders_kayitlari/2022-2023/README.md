# Yapay Zeka Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Yapay Zeka
* **Hoca:** Prof. Dr. Mehmet Fatih Amasyalı
* **Dönem:** Bahar
* **Akademik Yıl:** 2022-2023

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Yapay Zekaya Giriş: Kapsam, Zeka Yaklaşımları, Problem Temsili | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Yapay Zekanın Tarihsel Gelişimi ve Etmen (Agent) Mantığı | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Arama Problemlerine Giriş, Durum Uzayı ve Kör Arama (BFS, DFS) | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Sezgisel (Informed) Arama: Maliyet Tabanlı Arama, Sezgisel Fonksiyonlar ve A* Algoritması | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Lokal Arama Yöntemleri: Tepe Tırmanma (Hill Climbing) ve Lokal/Global Optimum Sınırları | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Genetik Algoritmalar: Evrimsel Arama, Kromozom Temsili ve Uygunluk Fonksiyonu | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Oyun Teorisi ve Karar Verme: İki Oyunculu Sıfır Toplamlı Oyunlar ve Minimax | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 8** | Bilgi Gösterimi ve Akıl Yürütme: Veri-Bilgi Ayrımı ve Bilgi İşleme Modelleri | [Özet](altyazi_ozetleri/ders_8_ozet.md) | [PDF (İndir)](ders_8_ozet.pdf) |
| **Ders 10** | Makine Öğrenmesine Giriş: Veriden Örüntü Öğrenme, Sınıflandırma vs. Regresyon | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Sınıflandırma Karar Yapıları: Karar Ağaçları | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Sınıflandırma Sınırları: YSA ve Kümeleme | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Pekiştirmeli Öğrenme (Reinforcement Learning) | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> Müfredat akışına göre *Ders 9* resmi tatil veya ara sınav haftası nedeniyle işlenmemiş ya da kayıt altına alınmamıştır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Yapay Zekaya Giriş: Kapsam, Zeka Yaklaşımları, Problem Temsili
* **Genel Konular:**
  - Yapay zeka dersinin kapsamı
    - Dersin yalnızca tek bir teknikten oluşmadığı; arama, oyunlar, bilgi gösterimi, çıkarım, makine öğrenmesi, yapay sinir ağları ve derin öğrenme gibi farklı alt alanlara yayıldığı anlatılır.
  - Zeka ve yapay zeka kavramı
    - Zekanın kesin ve tek cümlelik bir tanımının zor olduğu; algılama, karar verme, problem çözme, öğrenme ve uyum sağlama gibi yeteneklerle ilişkilendirildiği vurgulanır.
  - Yapay zekaya yaklaşım biçimleri
    - İnsan gibi düşünme/davranma ve rasyonel düşünme/davranma ayrımları üzerinden yapay zekanın nasıl ele alınabileceği açıklanır.
  - Problem çözme fikri
    - Yapay zekada birçok konunun bir problemi temsil etme, çözüm uzayında arama yapma ve uygun çözümü bulma fikrine dayandığı belirtilir.
  - Alanın uygulama çeşitliliği
    - Oyunlar, doğal dil, görüntü işleme, uzman sistemler, robotik ve öğrenen sistemler gibi farklı uygulama alanları üzerinden yapay zekanın genişliği tanıtılır.
* **Hocanın Vurgusu:**
  - Yapay zeka tek bir algoritma değildir.
    - Farklı problem türleri için farklı yaklaşım aileleri kullanılır; bu yüzden konuları birbirinden bağımsız ezberlemek yerine ortak problem çözme mantığını görmek gerekir.
  - Zekanın tanımı bağlama göre değişebilir.
    - İnsan zekasını birebir taklit etmek ile rasyonel karar veren sistem kurmak aynı şey değildir.
  - Problem temsili önemlidir.
    - Bir yapay zeka yönteminin başarısı, çoğu zaman problemin doğru şekilde modellenmesine bağlıdır.
  - Ders boyunca kavramlar birbirine bağlanacaktır.
    - Arama, bilgi gösterimi ve öğrenme gibi konular farklı görünse de hepsi akıllı davranış üretme amacı etrafında birleşir.
* **Detaylı Açıklamalar:** Yapay zeka, karmaşık problemleri çözmek amacıyla insan zekasını taklit eden veya bağımsız akıllı sistemler geliştirmeyi hedefleyen çok disiplinli bir alandır. Ders kapsamında yapay zekanın sadece tek bir algoritma veya modelden (örneğin sadece derin öğrenme) ibaret olmadığı, aksine arama algoritmaları, oyun teorisi, bilgi gösterimi, makine öğrenmesi ve pekiştirmeli öğrenme gibi geniş bir yelpazeyi kapsadığı anlatılır. Zekanın tanımı yapılırken; algılama, muhakeme, problem çözme ve adapte olma yetenekleri tartışılır. Yapay zekaya yaklaşım biçimleri dört ana grupta ele alınır: İnsan gibi düşünenler, insan gibi davrananlar (Turing testi odaklı), rasyonel düşünenler (mantık kuralları odaklı) ve rasyonel davrananlar (hedefe yönelik en iyi kararı veren etmenler). Problemlerin doğru temsil edilmesi, çözüm uzayının verimli taranabilmesi için ilk ve en kritik adımdır.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 2: Yapay Zekanın Tarihsel Gelişimi ve Etmen (Agent) Mantığı
* **Genel Konular:**
  - Yapay zekaya girişin tamamlanması
    - Zeka, yapay zeka ve akıllı sistem kavramları önceki dersten devamla daha geniş bir çerçevede ele alınır.
  - Yapay zekanın tarihsel ve kavramsal gelişimi
    - Sembolik yapay zeka, bağlantıcı yaklaşımlar, makine öğrenmesi ve modern derin öğrenme yaklaşımları arasındaki farklar genel hatlarıyla tartışılır.
  - Etmen kavramı
    - Ortamdan algı alan, bu algılara göre karar veren ve eylem üreten sistemlerin etmen olarak düşünülebileceği anlatılır.
  - Etmen-ortam ilişkisi
    - Bir sistemin davranışını anlamak için yalnızca algoritmaya değil, sistemin içinde bulunduğu ortama, algılarına, eylemlerine ve hedeflerine bakılması gerektiği vurgulanır.
  - Bilgi, mantık ve öğrenme ilişkisi
    - Yapay zekada hem açıkça temsil edilen bilgi ve kuralların hem de veriden öğrenen modellerin kullanılabileceği açıklanır.
* **Hocanın Vurgusu:**
  - Yapay zeka tanımı dar tutulmamalıdır.
    - Yalnızca insan benzeri sistemler değil, belirli bir ortamda rasyonel kararlar veren sistemler de yapay zeka kapsamında değerlendirilebilir.
  - Etmen, yapay zeka problemlerini düşünmek için temel bir çerçevedir.
    - Algı, ortam, eylem ve hedef bileşenleri ayrıştırıldığında problem daha anlaşılır hale gelir.
  - Sembolik ve öğrenmeye dayalı yaklaşımlar birbirinin alternatifi olmak zorunda değildir.
    - Farklı problem türleri farklı temsil ve çözüm biçimleri gerektirir.
  - Bilgi temsili ile öğrenme arasındaki fark önemlidir.
    - Bazı sistemler kurallarla çalışırken bazı sistemler örneklerden örüntü öğrenir.
* **Detaylı Açıklamalar:** Yapay zekanın gelişimi tarihsel olarak sembolik (symbolic) ve bağlantıcı (connectionist) yaklaşımların çekişmesi ve işbirliği ile şekillenmiştir. Sembolik yapay zeka mantıksal kurallar ve bilgi ağaçları üzerine kurulurken, bağlantıcı yaklaşım yapay sinir ağları ve makine öğrenmesi gibi veri tabanlı örüntü tanıma modellerini temel alır. Modern yapay zekanın merkezinde "Etmen" (Agent) kavramı bulunur. Bir etmen; ortamı algılayıcılar (sensors) vasıtasıyla okuyan, bu algıları işleyerek kararlar alan ve aktüatörler (actuators) aracılığıyla ortamda eylemler gerçekleştiren bir sistemdir. Etmen tasarımı yapılırken ortamın yapısı (tamamen/kısmen gözlemlenebilir, deterministik/stokastik, statik/dinamik, ayrık/sürekli vb.) kullanılacak algoritmayı doğrudan belirler.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 3: Arama Problemlerine Giriş, Durum Uzayı ve Kör Arama (BFS, DFS)
* **Genel Konular:**
  - Arama problemlerine giriş
    - Bir problemin başlangıç durumu, hedef durumu, durum uzayı, operatörleri ve geçişleriyle modellenebileceği anlatılır.
  - Durum uzayı
    - Problemin olası tüm durumlarının bir grafik veya ağaç gibi düşünülebileceği; çözümün bu uzay içinde bir yol bulmak olduğu açıklanır.
  - Kör arama yöntemleri
    - Arama sırasında probleme özel ek bilgi kullanılmadığında yöntemlerin kör arama olarak değerlendirildiği belirtilir.
  - Genişlik öncelikli ve derinlik öncelikli arama
    - BFS ve DFS yaklaşımlarının arama sırası, bellek kullanımı, çözüm bulma davranışı ve derinlik ilişkisi üzerinden karşılaştırılması yapılır.
  - Maliyet kavramı
    - Her çözüm yolunun aynı kalitede olmayabileceği; bazı problemlerde en az maliyetli yolun aranması gerektiği anlatılır.
* **Hocanın Vurgusu:**
  - Arama problemi kurmadan algoritma seçmek anlamlı değildir.
    - Önce durumların, operatörlerin, başlangıcın ve hedefin net tanımlanması gerekir.
  - Durum uzayı büyüdükçe arama maliyeti hızla artar.
    - Bu yüzden arama algoritmalarında zaman ve bellek karmaşıklığı kritik hale gelir.
  - BFS ve DFS farklı avantajlara sahiptir.
    - BFS sığ çözümlerde güvenilirken daha fazla bellek kullanabilir; DFS daha az bellekle ilerleyebilir ama uygun olmayan dallarda derine gidebilir.
  - Çözümün bulunması ile en iyi çözümün bulunması aynı şey değildir.
    - Maliyetli problemlerde bulunan ilk çözüm her zaman en uygun çözüm olmayabilir.
* **Detaylı Açıklamalar:** Yapay zekada birçok problem bir arama problemi olarak modellenebilir. Bir arama problemi; başlangıç durumu (initial state), geçiş modeli ve operatörler (actions), hedef testi (goal test) ve yol maliyeti (path cost) bileşenlerinden oluşur. Tüm olası durumların oluşturduğu yapıya durum uzayı (state space) denir. Kör arama (uninformed/blind search) yöntemleri hedefe giden yol hakkında ek sezgisel bilgiye sahip olmayan, sadece durum uzayını sistematik olarak tarayan algoritmalardır. BFS (Breadth-First Search - Enlemesine Arama) durum uzayını seviye seviye arayarak en kısa yolu bulmayı garanti eder (optimaldir) ancak bellek gereksinimi üsteldir. DFS (Depth-First Search - Derinlemesine Arama) ise bir dal boyunca en derine kadar gider; bellek tüketimi düşüktür ancak sonsuz döngülere girebilir ve optimal yolu bulması garanti değildir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 4: Sezgisel (Informed) Arama: Maliyet Tabanlı Arama, Sezgisel Fonksiyonlar ve A* Algoritması
* **Genel Konular:**
  - Kör aramanın tamamlanması
    - Önceki dersteki arama modelleri ve maliyetli arama fikri üzerinden konu toparlanır.
  - Maliyet tabanlı arama
    - Yolların farklı maliyetlere sahip olduğu durumlarda aramanın toplam maliyeti dikkate alması gerektiği açıklanır.
  - Sezgisel aramaya giriş
    - Arama sürecini yönlendirmek için hedefe yakınlık veya tahmini maliyet gibi probleme özel bilgilerin kullanılabileceği anlatılır.
  - Sezgisel fonksiyon
    - Bir durumun hedefe ne kadar yakın olduğunu yaklaşık olarak değerlendiren fonksiyonun arama performansını belirlediği vurgulanır.
  - A* algoritması
    - Geçmiş yol maliyeti ile hedefe kalan tahmini maliyeti birlikte kullanan bir yaklaşım olarak ele alınır.
* **Hocanın Vurgusu:**
  - Sezgisel bilgi aramayı hızlandırır ama doğru tasarlanmalıdır.
    - Kötü sezgisel fonksiyon algoritmayı yanlış yönlendirebilir veya beklenen kazancı sağlamayabilir.
  - A* yalnızca sezgisel değere bakmaz.
    - Hem şu ana kadar oluşan maliyet hem de hedefe kalan tahmini maliyet birlikte değerlendirilir.
  - Sezgisel fonksiyonun problemle uyumlu olması gerekir.
    - Harita, oyun, yol bulma gibi problemlerde hedefe yakınlığı temsil eden ölçütler doğru seçilmelidir.
  - Arama algoritmalarında optimalite ve verimlilik ayrımı önemlidir.
    - Hızlı çalışan bir yöntem her zaman en iyi çözümü garanti etmeyebilir.
* **Detaylı Açıklamalar:** Sezgisel (informed) arama yöntemleri, kör aramalardan farklı olarak, hedefe olan kalan mesafeyi tahmin eden sezgisel fonksiyonlardan (h(n)) yararlanır. Maliyet tabanlı aramada (Uniform Cost Search) sadece başlangıçtan bulunulan düğüme kadar olan maliyet (g(n)) dikkate alınırken, A* algoritması hem geçmiş maliyeti (g(n)) hem de gelecekteki tahmini maliyeti (h(n)) birleştiren bir değerlendirme fonksiyonu (f(n) = g(n) + h(n)) kullanır. A* algoritmasının optimal ve eksiksiz (complete) olması için sezgisel fonksiyonun kabul edilebilir (admissible - gerçek maliyeti asla aşmayan) ve tutarlı (consistent - üçgen eşitsizliğini sağlayan) olması gerekir. Doğru tasarlanmış bir sezgisel fonksiyon, arama uzayını dramatik şekilde daraltarak performansı artırır.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 5: Lokal Arama Yöntemleri: Tepe Tırmanma (Hill Climbing) ve Lokal/Global Optimum Sınırları
* **Genel Konular:**
  - Sezgisel aramanın devamı
    - Önceki dersteki sezgisel arama mantığı hatırlatılır ve arama problemlerinde sezgisel yönlendirmenin önemi pekiştirilir.
  - Lokal arama
    - Tüm çözüm yolunu genişletmek yerine mevcut durumdan komşu durumlara geçerek daha iyi çözümler arayan yöntemler tanıtılır.
  - Tepe tırmanma yaklaşımı
    - Mevcut çözümün komşuları arasından daha iyi görünen duruma geçerek ilerleyen bir lokal arama yöntemi olarak anlatılır.
  - Lokal optimum problemi
    - Bir yöntemin bulunduğu noktada daha iyi komşu göremediği için durabileceği, fakat bunun global en iyi çözüm olmayabileceği açıklanır.
  - Sezgisel değerlendirme ve komşuluk
    - Lokal aramada çözüm kalitesini ölçen fonksiyonun ve hangi durumların komşu sayılacağının yöntemin başarısını etkilediği vurgulanır.
* **Hocanın Vurgusu:**
  - Lokal arama, durum uzayının tamamını saklamadan çalışabilir.
    - Bu nedenle büyük problemlerde bellek açısından avantaj sağlayabilir.
  - Tepe tırmanma basit ama sınırlı bir yöntemdir.
    - Yerel en iyi noktalara takılabilir; plato veya omuz gibi durumlarda ilerleme zorlaşabilir.
  - Komşuluk tanımı problemin çözüm kalitesini belirler.
    - Hangi hareketlerin mümkün sayıldığı, algoritmanın ulaşabileceği çözümleri doğrudan etkiler.
  - Değerlendirme fonksiyonu yalnızca teknik ayrıntı değildir.
    - Yanlış kalite ölçütü, algoritmanın yanlış çözümleri iyi sanmasına neden olabilir.
* **Detaylı Açıklamalar:** Lokal arama algoritmaları, hedefe giden yolu saklamak yerine sadece mevcut durumu (current state) ve onun komşularını inceleyerek çalışır. Bu nedenle bellek gereksinimleri son derece azdır (O(1)) ve çok büyük durum uzaylarında tercih edilirler. Tepe Tırmanma (Hill Climbing) algoritması, her adımda mevcut durumun komşuları arasından değeri (uygunluğu) en yüksek olan duruma geçerek sürekli "yukarı" tırmanır. Ancak bu algoritma lokal optimum (yerel en iyi) noktalarına, düzlüklere (plateau) veya sırtlara (ridge) takılarak küresel en iyiye (global optimum) ulaşamayabilir. Bu problemleri aşmak için rastgele adımlarla tırmanma, tavlama benzetimi (simulated annealing) veya lokal ışın arama (local beam search) gibi yöntemler kullanılır.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 6: Genetik Algoritmalar: Evrimsel Arama, Kromozom Temsili ve Uygunluk Fonksiyonu
* **Genel Konular:**
  - Genetik algoritmalara giriş
    - Doğal seçilim ve evrim fikrinden esinlenen arama/optimizasyon yaklaşımı olarak genetik algoritmalar tanıtılır.
  - Popülasyon ve birey
    - Tek bir çözüm yerine birçok aday çözümden oluşan bir popülasyonla çalışıldığı açıklanır.
  - Kromozom gösterimi
    - Aday çözümlerin genler veya kromozomlar biçiminde temsil edilmesi gerektiği anlatılır.
  - Uygunluk fonksiyonu
    - Bir çözümün ne kadar iyi olduğunu ölçen fonksiyonun genetik algoritmanın yönünü belirlediği belirtilir.
  - Seçilim, çaprazlama ve mutasyon
    - İyi bireylerin seçilmesi, bireylerden yeni bireyler üretilmesi ve rastgele değişikliklerle çeşitlilik sağlanması süreçleri ele alınır.
* **Hocanın Vurgusu:**
  - Genetik algoritmada çözüm temsili çok önemlidir.
    - Kromozom yapısı problemi iyi temsil etmezse algoritma anlamlı çözümler üretemez.
  - Uygunluk fonksiyonu algoritmanın hedefini belirler.
    - Neyin iyi çözüm sayılacağı açık tanımlanmadığında seçilim de doğru çalışmaz.
  - Çaprazlama ve mutasyon farklı amaçlara hizmet eder.
    - Çaprazlama iyi özellikleri birleştirirken mutasyon çeşitlilik sağlar ve aramanın sıkışmasını azaltabilir.
  - Genetik algoritmalar kesin çözüm garantisi vermekten çok iyi aday çözümler üretmeye yöneliktir.
    - Özellikle büyük ve karmaşık arama uzaylarında kullanışlıdır.
* **Detaylı Açıklamalar:** Genetik algoritmalar (Genetic Algorithms), doğadaki evrimsel süreçleri ve doğal seçilim mekanizmasını taklit eden popülasyon tabanlı bir lokal arama ve optimizasyon yöntemidir. Arama uzayındaki olası çözümler "kromozom" (genellikle bit dizileri veya reel sayı dizileri) olarak temsil edilir. Algoritma; başlangıç popülasyonunun oluşturulması, her bireyin kalitesini ölçen uygunluk (fitness) fonksiyonunun hesaplanması, rulet tekerleği veya turnuva gibi yöntemlerle ebeveyn seçimi, çaprazlama (crossover - gen değişimi) ve mutasyon (rastgele genetik değişim) adımlarıyla yeni nesiller üretir. Başarının anahtarı, problemin kromozom üzerinde doğru şekilde kodlanması ve çeşitliliğin korunarak lokal minimumlardan kaçınılmasıdır.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 7: Oyun Teorisi ve Karar Verme: İki Oyunculu Sıfır Toplamlı Oyunlar ve Minimax
* **Genel Konular:**
  - Oyun problemlerine giriş
    - Yapay zekada oyunların, karar verme ve arama problemlerini modellemek için uygun örnekler sunduğu anlatılır.
  - İki oyunculu sıfır toplamlı oyunlar
    - Bir oyuncunun kazancının diğer oyuncunun kaybı olduğu oyun yapıları üzerinden akıl yürütme yapılır.
  - Oyun ağacı
    - Olası hamlelerin ve karşı hamlelerin ağaç yapısı içinde modellenebileceği açıklanır.
  - Minimax algoritması
    - Oyuncunun kendi kazancını maksimize etmeye, rakibin ise bunu minimize etmeye çalıştığı karar verme yaklaşımı anlatılır.
  - Alfa-beta budama
    - Minimax aramasında sonucu değiştirmeyecek dalların elenerek aramanın hızlandırılabileceği açıklanır.
* **Hocanın Vurgusu:**
  - Oyunlarda arama tek taraflı değildir.
    - Rakibin de en iyi hamleyi yapacağı varsayımı hesaba katılmalıdır.
  - Minimax mantığını anlamak, oyun yapay zekasının temelidir.
    - En iyi hamle yalnızca mevcut kazanca değil, rakibin olası cevaplarına göre seçilir.
  - Alfa-beta budama sonucu değiştirmeden arama maliyetini azaltır.
    - Budama, gereksiz dalları incelemeyerek aynı karara daha az işlemle ulaşmayı amaçlar.
  - Derinlik sınırı pratikte önemlidir.
    - Büyük oyun ağaçlarında tüm olasılıkları sona kadar aramak mümkün olmayabilir; değerlendirme fonksiyonları gerekir.
* **Detaylı Açıklamalar:** Yapay zekada oyun oynama problemleri, rakibin de akıllı ve rasyonel davrandığı dinamik ve düşmanca (adversarial) arama problemleri olarak ele alınır. İki oyunculu sıfır toplamlı (zero-sum) oyunlarda bir oyuncunun kazancı diğerinin kaybına eşittir. Minimax algoritması, bu tür oyunlarda karar vermek için kullanılır. MAX oyuncusu kendi kazancını maksimize etmeye çalışırken, MIN oyuncusu MAX'ın kazancını minimize etmeye çalışır. Oyun ağacının tamamını taramak üstel zaman alacağından (O(b^d)), performansı artırmak için Alfa-Beta Budama (Alpha-Beta Pruning) yöntemi uygulanır. Alfa-Beta budama, optimal kararı değiştirmeden ağacın değerlendirilmesi gerekmeyen dallarını budayarak arama süresini yarı yarıya azaltabilir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 8: Bilgi Gösterimi ve Akıl Yürütme: Veri-Bilgi Ayrımı ve Bilgi İşleme Modelleri
* **Genel Konular:**
  - Bilgi kavramı
    - Veri ile bilgi arasındaki fark tartışılır; bilginin işlenmiş, anlamlandırılmış ve kullanılabilir hale gelmiş veri olarak düşünülebileceği anlatılır.
  - Bilginin özellikleri
    - Bilginin doğrulanabilir, yanlışlanabilir, güncel, eksik, belirsiz veya bağlama bağlı olabileceği üzerinde durulur.
  - Bilgisayarda bilgi gösterimi
    - Bilginin bilgisayar sistemlerinde kurallar, semboller ve biçimsel yapılarla temsil edilebileceği açıklanır.
  - Kural tabanlı gösterim
    - Bilginin "eğer ... ise ..." türü kurallarla ifade edilmesi ve bu kuralların bir bilgi tabanı içinde tutulması anlatılır.
  - Çıkarım
    - Eldeki veriler ve kurallar kullanılarak yeni sonuçlara ulaşma süreci olarak çıkarım tanıtılır.
  - İleriye doğru zincirleme
    - Mevcut bilgilerden başlayarak uygulanabilir kurallarla yeni bilgilere ulaşma yaklaşımı ele alınır.
* **Hocanın Vurgusu:**
  - Veri ve bilgi aynı şey değildir.
    - Veri ham olabilir; bilgi ise bir bağlam içinde anlam kazanır ve karar vermede kullanılabilir.
  - Bilginin doğruluğu sorgulanabilir olmalıdır.
    - Bilimsel bilgi açısından doğrulanabilirlik veya yanlışlanabilirlik önemli bir ayrımdır.
  - Bilgi gösterimi, yapay zekada merkezi bir problemdir.
    - Bilgisayarın bilgiyi kullanabilmesi için bilginin uygun biçimde temsil edilmesi gerekir.
  - Knowledge base ve çıkarım mekanizması ayrımı önemlidir.
    - Bilgi tabanı kuralları ve bilgileri saklar; çıkarım mekanizması bunlardan yeni sonuçlar üretir.
  - Kurallar açık ve uygulanabilir olmalıdır.
    - Belirsiz veya eksik kural yapıları çıkarımı zorlaştırır.
* **Detaylı Açıklamalar:** Bilgi gösterimi (Knowledge Representation), akıllı sistemlerin dünyadaki olguları anlayıp çıkarım yapabilmesi için bilgiyi yapılandırılmış bir biçimde saklama yöntemidir. Veri (data) ham gözlemlerden oluşurken, bilgi (knowledge) bu verilerin bir bağlam içinde işlenip anlamlandırılması ve kurallarla ilişkilendirilmesiyle oluşur. Bilgi tabanlı etmenler (Knowledge-based agents), bir bilgi tabanına (Knowledge Base - KB) yeni bilgileri ekleme (TELL) ve bilgi tabanından çıkarım yapma (ASK) yeteneğine sahiptir. Bilgi gösteriminde önermeler mantığı (propositional logic), birinci dereceden mantık (First-Order Logic - FOL), ontolojiler ve anlamsal ağlar (semantic networks) gibi yapılar kullanılır. Çıkarım motorları (inference engines) bu kuralları işleterek yeni ve gizli bilgileri üretir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 10: Makine Öğrenmesine Giriş: Veriden Örüntü Öğrenme, Sınıflandırma vs. Regresyon
* **Genel Konular:**
  - Makine öğrenmesine giriş
    - Makine öğrenmesinin veriden örüntü çıkarma ve bu örüntülerle yeni örnekler hakkında karar verme süreci olduğu anlatılır.
  - Öğrenme problem türleri
    - Sınıflandırma, regresyon ve kümeleme gibi temel problem türleri tanıtılır.
  - Denetimli öğrenme
    - Girdi-çıktı eşleşmelerinin bulunduğu veriyle model eğitme fikri açıklanır.
  - Sınıflandırma ve regresyon ayrımı
    - Kategorik sonuçların sınıflandırma, sayısal/sürekli sonuçların regresyon problemi olarak ele alınabileceği belirtilir.
  - Kümeleme fikri
    - Etiketlenmemiş verilerde benzer örnekleri gruplama yaklaşımı tanıtılır.
  - Eğitim verisi ve model ilişkisi
    - Modelin geçmiş örneklerden öğrendiği, ancak amacın yalnızca eğitim verisini ezberlemek değil yeni örneklerde iyi genelleme yapmak olduğu vurgulanır.
* **Hocanın Vurgusu:**
  - Problem türünü doğru belirlemek gerekir.
    - Aynı veri farklı biçimde ele alınabilir; çıktı değişkeninin yapısı sınıflandırma mı regresyon mu yapılacağını belirler.
  - Makine öğrenmesi ezberleme değildir.
    - Modelin asıl başarısı görmediği verilerde doğru genelleme yapabilmesidir.
  - Veri temsili model başarısını etkiler.
    - Özelliklerin nasıl seçildiği ve ifade edildiği, öğrenme algoritmasının performansını doğrudan belirler.
  - Sınıflandırma, regresyon ve kümeleme birbirine karıştırılmamalıdır.
    - Her biri farklı çıktı yapısı ve farklı değerlendirme mantığı gerektirir.
* **Detaylı Açıklamalar:** Makine öğrenmesi, açık kurallar yazmak yerine verilerden örüntüler (patterns) ve ilişkiler öğrenen algoritmaların tasarımıyla ilgilenir. Temel olarak denetimli öğrenme (supervised learning), denetimsiz öğrenme (unsupervised learning) ve pekiştirmeli öğrenme (reinforcement learning) olmak üzere üç sınıfa ayrılır. Denetimli öğrenmede model, girdilerin ve bunlara karşılık gelen hedef etiketlerin (labels) bulunduğu bir veri kümesiyle eğitilir. Çıktı değişkeni sürekli/sayısal bir değer ise problem bir regresyon (regression), kategorik/sınıfsal bir değer ise bir sınıflandırma (classification) problemidir. Modelin başarısı, eğitim verisine aşırı uyum sağlamadan (overfitting) yeni ve görülmemiş verilere genelleme (generalization) yapabilme yeteneğiyle ölçülür.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 11: Sınıflandırma Karar Yapıları: Karar Ağaçları
* **Genel Konular:**
  - Makine öğrenmesi problem türlerinin pekiştirilmesi
    - Sınıflandırma ve regresyon ayrımı çeşitli örnekler üzerinden yeniden ele alınır.
  - Etiket ve çıktı değişkeni
    - Bir problemin türünü belirlerken etiketin adına değil, etiketin temsil ettiği anlam ve değer türüne bakılması gerektiği anlatılır.
  - Model seçimi
    - Farklı algoritmaların farklı veri yapıları ve problem türleri için uygun olabileceği vurgulanır.
  - Sınıflandırmaya giriş
    - Verileri sınıflara ayıran karar sınırları ve sınıflandırma modellerinin genel mantığı açıklanır.
  - Karar ağaçları
    - Veriyi sorular veya koşullar üzerinden bölerek sınıflandırma yapan yorumlanabilir modeller olarak ele alınır.
  - Model başarısı ve genelleme
    - Eğitim verisindeki başarı ile gerçek başarı arasında fark olabileceği; genellemenin temel hedef olduğu belirtilir.
* **Hocanın Vurgusu:**
  - Problem türüne yalnızca etiket adına bakarak karar verilmez.
    - Sayı gibi görünen bir çıktı sınıf etiketi olabilir, isim gibi görünen bir çıktı da farklı biçimde modellenebilir.
  - Sınıflandırma ve regresyon ayrımı kavramsal olarak anlaşılmalıdır.
    - Çıktının kategorik mi sürekli mi olduğu temel belirleyicidir.
  - Karar ağaçları yorumlanabilirlik açısından önemlidir.
    - Modelin hangi koşullarla karar verdiğini görmek çoğu zaman mümkündür.
  - Eğitim başarısı tek başına yeterli değildir.
    - Modelin yeni örneklerdeki davranışı makine öğrenmesinin asıl meselesidir.
* **Detaylı Açıklamalar:** Sınıflandırma problemlerinde en yaygın ve açıklanabilir (explainable) modellerden biri Karar Ağaçlarıdır (Decision Trees). Karar ağaçları, veri kümesini belirli özniteliklere göre alt kümelere bölerek ağaç yapısında kurallar oluşturur. Bölme işlemi yapılırken her adımda en homojen alt grupları elde etmek amaçlanır. Bunun için bilgi kazancı (Information Gain) ve entropi (Entropy) veya Gini katsayısı gibi metriklere başvurulur. Entropi, veri kümesindeki belirsizliği/düzensizliği ölçer. Bölme sonrasında entropideki düşüş bilgi kazancını verir. En yüksek bilgi kazancını sağlayan öznitelik kök veya düğüm olarak seçilir. Karar ağaçları, veri hazırlığı gereksiniminin azlığı ve kararların görselleştirilebilir olması nedeniyle son derece güçlüdür ancak aşırı büyüdüklerinde overfitting riski taşırlar; bu durum budama (pruning) yöntemleriyle engellenir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 12: Sınıflandırma Sınırları: YSA ve Kümeleme
* **Genel Konular:**
  - Sınıflandırma algoritmalarının devamı
    - Karar sınırı, sınıflandırma başarısı ve farklı sınıflandırma algoritmalarının davranışları üzerinde durulur.
  - Doğrusal ve doğrusal olmayan karar sınırları
    - Bazı problemlerin düz bir karar sınırıyla ayrılabileceği, bazı problemlerde ise daha karmaşık sınırlara ihtiyaç duyulacağı anlatılır.
  - Yapay sinir ağları
    - Sınıflandırma ve regresyon problemlerinde kullanılabilen, özellikle karmaşık örüntülerde esnek karar sınırları öğrenebilen modeller olarak ele alınır.
  - Kümeleme algoritmaları
    - Etiketsiz verilerde benzer örnekleri gruplama fikri anlatılır.
  - Kümeleme türleri
    - Hiyerarşik, merkez tabanlı ve yoğunluk tabanlı kümeleme yaklaşımlarının farklı mantıklara dayandığı açıklanır.
  - Regresyon algoritmaları
    - Sürekli değer tahmini yapan modeller; basit lineer regresyon, KNN regresyon ve regresyon ağaçları gibi örnekler üzerinden tartışılır.
* **Hocanın Vurgusu:**
  - Her problem doğrusal karar sınırıyla çözülemez.
    - Veri yapısı karmaşıksa daha esnek modeller gerekebilir.
  - Yapay sinir ağları güçlüdür ama her durumda tek doğru seçenek değildir.
    - Veri miktarı, problem yapısı ve yorumlanabilirlik ihtiyacı model seçimini etkiler.
  - Kümeleme ile sınıflandırma aynı şey değildir.
    - Sınıflandırmada etiketler vardır; kümelemede amaç etiketsiz örnekleri benzerliklerine göre ayırmaktır.
  - Kümeleme başarısını değerlendirmek sınıflandırmadan daha zordur.
    - Çünkü çoğu zaman elde hazır doğru etiketler yoktur.
  - Regresyon ağaçları ve karar ağaçları benzer yapıyı farklı çıktı türleri için kullanır.
    - Sınıflandırmada yapraklar sınıf, regresyonda ise sayısal tahmin üretebilir.
* **Detaylı Açıklamalar:** Veri noktalarını sınıflarına göre ayıran geometrik çizgilere veya hiper-düzlemlere karar sınırları (decision boundaries) denir. Bazı problemler (örneğin AND/OR mantıksal kapıları) tek bir doğruyla ayrılabilirken (doğrusal karar sınırı), XOR gibi problemler doğrusal olmayan (non-linear) karar sınırları gerektirir. Yapay Sinir Ağları (YSA), doğrusal olmayan bu karmaşık fonksiyonları öğrenmek için tasarlanmış, biyolojik beyin hücrelerinden esinlenen modellerdir. Çok katmanlı algılayıcılar (MLP) aktivasyon fonksiyonları (Sigmoid, ReLU, Tanh) kullanarak doğrusal olmayan ilişkileri başarıyla modeller. Denetimsiz öğrenmede ise etiketlenmemiş verileri benzerliklerine göre gruplamak için K-Ortalamalar (K-Means) ve hiyerarşik kümeleme gibi Kümeleme (Clustering) algoritmaları kullanılır.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 13: Pekiştirmeli Öğrenme (Reinforcement Learning)
* **Genel Konular:**
  - Pekiştirmeli öğrenmeye giriş
    - Bir ajanın ortamla etkileşerek ödül ve ceza geri bildirimleri üzerinden davranış öğrenmesi anlatılır.
  - Ajan ve ortam ilişkisi
    - Ajanın bir durumda bulunduğu, bir eylem seçtiği, ortamdan yeni durum ve ödül aldığı döngü açıklanır.
  - Durum, eylem ve ödül kavramları
    - Pekiştirmeli öğrenmede karar verme sürecinin state, action ve reward bileşenleriyle kurulduğu belirtilir.
  - Politika
    - Hangi durumda hangi eylemin seçileceğini belirleyen yapı olarak politika tanıtılır.
  - Değer kavramı
    - Bir durumda veya durum-eylem çiftinde gelecekte beklenen ödülün öneminden bahsedilir.
  - Q-learning
    - Durum-eylem çiftleri için değer tutan Q tablosu üzerinden politikanın zamanla iyileştirilmesi anlatılır.
* **Hocanın Vurgusu:**
  - Pekiştirmeli öğrenme, denetimli öğrenmeden farklıdır.
    - Model doğrudan doğru cevap etiketleriyle değil, ortamdan aldığı ödül/ceza geri bildirimiyle öğrenir.
  - Amaç anlık ödülü değil uzun vadeli toplam getiriyi iyi hale getirmektir.
    - Bir eylem o anda iyi görünmese bile gelecekte daha iyi sonuçlara götürebilir.
  - Politika öğrenmenin merkezindedir.
    - Ajanın amacı, hangi durumda hangi hareketi yapacağını belirleyen politikayı iyileştirmektir.
  - Keşif ve sömürü dengesi önemlidir.
    - Ajan hem bildiği iyi eylemleri kullanmalı hem de daha iyi seçenekler bulmak için yeni durumları denemelidir.
  - Q tablosu durum-eylem değerlerini temsil eder.
    - Q-learning sürecinde bu değerler deneyimle güncellenerek daha iyi kararlar üretir.
* **Detaylı Açıklamalar:** Pekiştirmeli öğrenme (Reinforcement Learning - RL), bir ajanın deneme-yanılma yoluyla bir ortamda (environment) en yüksek uzun vadeli toplam ödülü (reward) almak için eylemler gerçekleştirdiği makine öğrenmesi dalıdır. RL modeli; etmen, ortam, durum (state), eylemler (actions) ve ödül (reward) bileşenlerinden oluşur ve genellikle Markov Karar Süreçleri (MDP) çerçevesinde modellenir. Etmen, her durumda hangi eylemi seçeceğini belirleyen bir politika (policy) takip eder. Keşif (exploration - yeni yollar deneme) ve sömürü (exploitation - bilinen en iyi yolu kullanma) arasındaki dengeyi kurmak RL'de en kritik zorluktur. Q-Öğrenme (Q-Learning) gibi algoritmalar, durum-eylem değer fonksiyonunu (Q-tablosu) güncelleyerek optimal politikayı öğrenir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

