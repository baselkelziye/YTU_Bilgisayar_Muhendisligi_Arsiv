# Ders 12 Çalışma Özeti

## Genel Konular

- Bu derste öğrenciler yazılım proje yönetimiyle ilgili makaleler sundu. Hoca sunumlar arasında kısa yorumlar yaptı. Sekiz sunumun teknik içeriği aşağıda sırayla verilmiştir.
- Büyük ölçekli çevik yöntemlerin karşılaştırılması (sistematik literatür taraması, IEEE TSE 2021; ekrandan, 00:10:00 ve 00:15:00)
  - Çevik yöntemler ekip düzeyinde başarılı olunca kuruluşlar bu başarıyı organizasyon düzeyine taşımak ister. Bunun için büyük ölçekli çevik çerçeveler kullanılır.
  - Karşılaştırılan çerçeveler: SAFe, LeSS (Large Scale Scrum), Scrum at Scale, DAD (Disciplined Agile Delivery) ve Spotify modeli. Nokia, Ericsson gibi kuruluşların kendine özgü yöntemleri de karşılaştırmaya alınmıştır.
    - LeSS: Scrum'ın temel ilke ve uygulamalarını korur, basit ve esnektir. Birden çok Scrum ekibi tek bir ürün üzerinde, tek bir ürün sahibiyle çalışır.
    - SAFe: çok sayıda ekip ve birden fazla ürünü olan büyük organizasyonları hedefler. Portföy, program ve ekip düzeyinde katmanları vardır. Agile Manifesto ilkelerine dayanır, ek süreçlerle genişletilmiştir.
    - DAD: çevik, kısmen çevik ve geleneksel yöntemleri birleştiren kapsamlı bir çerçevedir. Yaşam döngüsünün tüm aşamalarına rehberlik eder, esneklik ile uyumluluk arasında denge kurmaya çalışır.
    - Scrum at Scale: Scrum'ı çoklu ekiplere ve bütün organizasyona ölçekler. Ekipler bir üst düzey ürün sahibiyle koordine olur.
  - Karşılaştırma ölçütleri: ölçek (LeSS ve Scrum at Scale birden çok Scrum ekibi; SAFe ve DAD daha geniş organizasyon), yapı ve kapsam, süreç uygulamaları, esneklik. Seçimde organizasyonun ihtiyaçları, projenin ölçeği ve kültürel uyum dikkate alınmalıdır.
  - Araştırma soruları: yöntemlerin ampirik olarak ne ölçüde incelendiği, hangi soyutlama düzeyinde (ilke, uygulama, araç, metrik) incelendiği ve bilgi boşlukları, bildirilen zorluklar, bildirilen başarı faktörleri.
  - Arama terimleri üç gruba ayrılıp AND ile bağlanmıştır: yöntem adları (VersionOne raporundan), yazılım/bilgi sistemi geliştirme, büyük ölçekli ortam. 191 makale üzerinde kalite değerlendirmesi yapılmıştır.
  - Sonuç: büyük ölçekli çevik konusundaki ampirik çalışmalar son yıllarda hızla artmıştır. <!-- BELİRSİZ: önceki taramayla karşılaştırmadaki sayılar (2013'e kadar 6 makale, 191 çalışmanın kaçının ampirik olduğu) altyazıda bozuk. -->
- Yazılım proje çizelgeleme probleminin (SPSP) taraması (International Journal of Production Economics, 2018; ekrandan, 00:20:00)
  - Önceki taramaların çoğu kaynak kısıtlı proje çizelgeleme (RCPS) problemine odaklanır. Bu tarama yazılım projelerine özgü çizelgeleme problemine odaklanan ilk kapsamlı çalışmadır.
  - Yöntem: sistematik haritalama çalışması (araştırma hedefleri, arama dizgeleri, arama motorları, dahil etme/dışlama ölçütleri). 57 makaleden filtrelerle 30 makale kalır: 16'sı konferans, 14'ü dergi.
  - Proje planlama modeli: çalışanlar becerileri, maaşları ve projeye ayırabildikleri zamanla; görevler gereken beceri ve eforla tanımlanır. Alba ve Chicano (2007) modeli çoğu çalışmada temel alınmıştır (ekrandan, 00:25:00).
    - Diğer modeller beceri düzeylerini ayrıntılandırır: 0-5 arası beceri puanı ve fazla mesai ücreti, acemi/genç/kıdemli/uzman düzeyleri, çalışanların projeye dinamik girip çıkması.
  - Optimizasyon hedefleri: 30 makalenin 18'inde yalnızca proje maliyeti ve süresi en aza indirilir. Diğerlerinde fazla mesai, beklenen hata sayısı ve parçalanma (fragmentation) da hedeflere eklenir.
  - Algoritmalar: 30 makalenin 27'sinde evrimsel algoritmalar, bunların 19'unda genetik algoritma kullanılmıştır. Çok amaçlı GA (MOGA) çözümleri $M \times N$ boyutlu bir görev-çalışan tahsis matrisiyle kodlar. Altı çalışmada sürü zekâsı kullanılmıştır (4 karınca kolonisi, 1 parçacık sürüsü, 1 ateş böceği).
  - Değerlendirme: kıyaslama örnekleri ve parametre ayarları. 11 çalışma Alba ve Chicano'nun kıyaslama örneklerini kullanmıştır. Yapay veriyle 48 proje örneği üretilmiştir (ekrandan, 00:30:00).
  - Bulgular: MOCell (çok amaçlı hücresel GA) gerçekçi problemlerde, PAES ölçeklenebilir (çok görevli, çok çalışanlı) problemlerde iyi sonuç verir. Karınca kolonisi GA'dan daha yüksek başarı oranı elde etmiştir. İsabet oranı bildiren 6 çalışmanın 3'ünde 30 ve üzeri görevli problemlerde sonuç sıfırdır, bu da gerçek projelere uygulanabilirliği sınırlar (ekrandan, 00:35:00).
- Şelale ve Scrum'ı birleştiren hibrit çevik model (konferans bildirisi; ekrandan, 00:40:00 ve 00:45:00)
  - Hibrit çevik, çevik ve çevik olmayan geliştirme stratejilerini birleştiren bir modeldir. İki yöntemin birleşimiyle birinin zayıflığı diğerinin güçlü yönüyle giderilir.
  - Şelale: yönetimi kolay, planlaması proje başlamadan ayrıntılı. Scrum: kısa sürede geliştirme, kullanıcıdan doğrudan geri bildirim, küçük ve dinamik ortamlara uygun.
  - Yöntem: görüşme protokolü geliştirilip uzman onayından geçirilmiş, 5-10 yıl deneyimli yazılım mühendisleriyle görüşülmüş, transkriptler tematik analizle incelenmiştir. Katılımcılardan biri yalnızca XP kullandığı için hibrit modele uymamaktadır.
  - Bulgular: şirketler projeye göre bazen şelale, bazen Scrum, çoğu zaman ikisinin karışımını kullanır. Karışımın nedeni olarak proje karmaşıklığı öne çıkar.
  - Sonuç: tek bir metodoloji tüm projelere evrensel olarak uygulanamaz. Scrum tek başına da şelale tek başına da yeterli değildir. Hibrit model planlama, geliştirme ve kalitede esneklik, hız, şeffaflık ve iletişim kazandırır (ekrandan, 00:50:00).
- Yazılım projelerinde sistem düşüncesi: yapay sinir ağlarıyla proje başarısı tahmini (IEEE Access, 2020; ekrandan, 00:55:00-01:10:00)
  - Amaç: kritik başarı faktörleri (CSF) arasındaki doğrusal olmayan ilişkileri ve etkileşimleri hesaba katarak proje başarısını tahmin etmek.
  - Proje başarısının üç boyutu: proje yönetimi başarısı (bütçe, zaman), ürün başarısı (paydaşlara fayda), stratejik başarı (pazar, gelecekteki iş).
  - CSF kategorileri: müşteri, teknik, proje yönetimi, organizasyon, takım.
  - Veri: anket ve proje yöneticileriyle görüşme, 35 firmadan 47 proje. Projeler K-means ile kümelenmiş (ekrandan, 01:05:00), başarı eşiği 4 alınmıştır.
  - İki ağ: çok girdili tek çıktılı (MISO, 20 CSF girdisi, genel başarı çıktısı) ve çok girdili çok çıktılı (MIMO, üç başarı boyutu). Eğitim algoritmaları: Resilient Backpropagation ve Scaled Conjugate Gradient.
  - Doğruluk: MISO yaklaşık 0,83, MIMO yaklaşık 0,72. YSA tabanlı model doğrusal modellerden daha doğrudur, uzman görüşüyle birlikte yorumlanmıştır.
- Makine öğrenmesiyle yazılım efor tahmini ve COCOMO karşılaştırması (2018 konferans bildirisi; ekrandan, 01:15:00 ve 01:20:00)
  - Tahmin yöntemleri uzman tabanlı ve model tabanlı olabilir (fonksiyon noktası, use case point, COCOMO).
  - COCOMO (Boehm, 1981) kod satırı sayısına dayanır. Üç düzeyi vardır: Basic, Intermediate, Detailed. Intermediate düzeyde 15 maliyet sürücüsü (çarpan) kullanılır.
  - Veri seti: NASA'nın 93 projesi (1971-1987). Aşırı uç 3 proje çıkarılıp 90 proje kullanılmıştır. Gerçek efor üç sınıfa (düşük, orta, yüksek; her biri 30 örnek) ayrılmıştır. 15 çarpanın çarpımının logaritması yeni özellik olarak türetilmiştir.
  - Naive Bayes, lojistik regresyon ve Random Forest, COCOMO'dan daha iyi tahmin vermiştir. Random Forest önde, Naive Bayes ROC eğrisinde ona yakındır.
- Yazılım geliştirmede duygusal takım koçluğu (IEEE Software, 2021; ekrandan, 01:25:00-01:40:00)
  - Lean Kanban ile çalışan deneyimli bir ekipte her iterasyondan sonraki iyileşmenin azaldığı ve motivasyonun düştüğü gözlenmiştir.
  - Duygusal zekâ: kendini harekete geçirme, dürtü kontrolü, empati, umut. Ekip düzeyinde güven, grup kimliği ve ortak hedef gerekir.
  - ETEC süreci beş oturumdur: iç algı, dış algı, büyümenin sınırlarının belirlenmesi, olası önlemlerin belirlenmesi, eylem planı. Teknikler: nominal grup tekniği, TEI testi, toplantı takibi, takım görsel algısı, beyin fırtınası, takım geri bildirimi, Philips 6-3-5, SMART hedefler.
  - Bulgular: izolasyon, dış görünürlük eksikliği, bürokrasi ve net hedeflerin yokluğu motivasyonu düşürür. Önlem olarak yeni teknoloji kullanımı ve düzenli kahve toplantıları seçilmiştir.
  - Altı ay sonunda ortalama motivasyon artmış, motivasyonu düşük kıdemli üyeler ayrılmış, yeni üyeler motive olmuştur.
- Makine öğrenmesiyle yazılım proje yönetimi (sistematik literatür taraması, 2021; ekrandan, 01:55:00-02:10:00)
  - Üç kütüphanede bulunan 1291 makaleden eleme adımlarıyla 111 makaleye inilmiştir.
  - Genel ML adımları: veri toplama, özellik çıkarma (ör. terim sıklığı-ters belge sıklığı), model kurma, çıktının uzmanlarca analizi.
  - Uygulama alanları: risk yönetimi, efor tahmini (MLP, SVM), maliyet tahmini (karar ağaçları), yazılım hata tahmini (SFP), değer tabanlı karar verme (Bayes koşullu olasılık tabloları).
  - Zorluk: genel açık veri setleri kuruma özgü projeyi temsil etmeyebilir; kurumun kendi proje verisi daha değerlidir.
- Proje yönetiminde zaman planlaması ve kaynak tahsisi (2019; ekrandan, 02:40:00 ve 02:45:00)
  - Küçük bir web/grafik tasarım şirketinde mevcut ERP sistemleri incelenmiş, gözlem ve görüşmelerle işlevsel gereksinimler çıkarılmış, web tabanlı bir proje yönetim sistemi önerilmiştir.
  - Proje başlangıcında sorulacak üç soru: "Daha önce nasıldı?", "Nasıl olacak?", "Daha iyi nasıl yapılır?"
  - Sorunlar: çalışanların görevleri anlamaması, elektronik tablolarla takip yapılamaması, öngörülemeyen planlama.
  - Maliyet; performans, zaman ve kapsamın fonksiyonudur. Biri artınca diğerleri de etkilenir.
  - Önerilen çözüm üç katmanlı bir mimaridir ve tam bir ERP sistemine genişletilebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- İnsan kaynağı en önemli kaynaktır
  - Yazılım proje çizelgelemesinde asıl planlanan şey insan kaynağıdır.
- Proje yönetimi araştırmalarında veri toplamak zordur
  - Anketlerle veri seti oluşturmak zordur ve anketler her zaman doğruyu vermez. Uzman görüşüyle yorumlama sonucu netleştirir.
- İnsan ve duygu faktörü projeleri beklenmeyecek kadar etkiler
  - Teknik çalışanlar bu konuyu çoğu zaman göz ardı eder, ama kişisel durumların projeye etkisi büyüktür. Yalnızca teknik açıdan bakmak yetersiz kalır.
- Makine öğrenmesinin yazılım proje yönetimindeki yeri
  - ML önce hata tahmininde kullanılmaya başlandı. Sonra başarı ve kritik başarı faktörleri tahmini, risk belirleme, hata önleme ve ölçümde yaygınlaştı.
- Hibrit modeller ve efor tahmini daha önceki derslerde de ele alınan konulardır
  - Hoca tekrarlayan konularda sunumları kısaltmalarını istedi; arama stratejisi ayrıntıları yerine bulgulara odaklanılmasını önerdi.

## Kısa Tekrar Notları

- Büyük ölçekli çevik çerçeveler: SAFe, LeSS, Scrum at Scale, DAD, Spotify. LeSS ve Scrum at Scale Scrum'a yakın; SAFe ve DAD daha kapsamlı.
- SPSP: Alba ve Chicano modeli temel; hedef çoğunlukla maliyet + süre; en çok GA ve MOGA; MOCell gerçekçi, PAES ölçeklenebilir problemlerde iyi.
- Hibrit çevik = şelale + Scrum; tek metodoloji her projeye uymaz.
- YSA ile proje başarısı: CSF'ler arası doğrusal olmayan ilişkiler; üç başarı boyutu (proje yönetimi, ürün, strateji); MISO > MIMO.
- COCOMO: Basic / Intermediate (15 çarpan) / Detailed; ML yöntemleri (özellikle Random Forest) NASA verisinde COCOMO'dan iyi.
- ETEC: beş oturumlu duygusal takım koçluğu; sorun motivasyon, görünürlük ve bürokrasi.
- ML in SPM: efor, maliyet, risk, hata tahmini, değer tabanlı karar verme; kuruma özgü veri önemli.
- Maliyet = f(performans, zaman, kapsam).

## Detaylı Açıklamalar

- **Büyük ölçekli çevik yöntemler.** Çevik yöntemler küçük ekipler için tasarlanmıştır. Büyük kuruluşlar birden çok ekibin aynı ürün ya da ürün ailesi üzerinde çalışmasını koordine etmek için ölçeklenmiş çerçevelere başvurur. LeSS, standart Scrum'ı mümkün olduğunca koruyarak birden çok ekibi tek ürün sahibi ve tek ürün iş listesiyle yönetir. Scrum at Scale da Scrum'ı temel alır ama bütün organizasyonu Scrum'a dönüştürmeyi hedefler. SAFe, portföy-program-ekip katmanlarıyla en kapsamlı ve en yapılandırılmış çerçevedir. DAD ise çevik ile geleneksel yöntemleri karıştırabilen, yaşam döngüsünün tamamına rehberlik eden bir karar çerçevesidir. Sunulan tarama, bu yöntemlerin ilke, uygulama, araç ve metriklerini standart bir biçimde karşılaştıran ilk çalışma olduğunu belirtir.
- **Yazılım proje çizelgeleme problemi.** Problem, görevleri becerisi uygun çalışanlara, ne kadar zaman ayıracaklarıyla birlikte atamaktır. Alba ve Chicano modelinde bir görevin süresi, görevin eforunun o göreve atanan çalışanların ayırdığı toplam zamana bölünmesiyle bulunur. Kısıtlar: her görev tamamlanmalı, çalışanlar azami çalışma süresini aşmamalı, görevlerin gerektirdiği beceriler karşılanmalı. Çözüm genellikle her hücresi bir çalışanın bir göreve ayırdığı payı gösteren bir matristir ve bu matris genetik algoritmayla aranır. Popülasyon büyüklüğü, mutasyon oranı ve ebeveyn seçimi (ikili turnuva, rulet çarkı) gibi parametreler sonucu etkiler.

> **Ek bilgi (derste anlatılmadı):** Alba ve Chicano modelinde $x_{ij}$, çalışan $i$'nin görev $j$'ye ayırdığı zaman oranıdır ve görev süresi büyük olasılıkla $t_j = \dfrac{\text{effort}_j}{\sum_i x_{ij}}$ biçiminde tanımlanır. Proje maliyeti ise her çalışanın maaşının bu görevlerde harcadığı zamanla çarpılıp toplanmasıyla bulunur.

- **Hibrit çevik.** Bildiri az sayıda katılımcıyla yapılmış nitel bir çalışmadır. Sunum yapan öğrenci örneklemin küçüklüğünü eleştirdi. Hoca bu alanda veri toplamanın zor olduğunu, konferans bildirilerinde bu eksikliğin daha sık görüldüğünü söyledi. Katılımcıların ortak görüşü, şelalenin planlama gücü ile Scrum'ın esnekliğinin birlikte kullanılmasının tek başına kullanımlardan daha etkili olduğudur.
- **YSA ile proje başarısı tahmini.** Önceki tahmin modelleri CSF'ler ile başarı arasında doğrusal ilişki varsayar ve faktörlerin birbirini etkilediğini göz ardı eder. Bu çalışmada YSA, yinelemeli eğitimle doğrusal ve doğrusal olmayan ilişkileri öğrenir. Veri setinin türü ve girdi-çıktı sayısı konusunda kısıtı olmaması yöntemi yazılım projelerine uygun kılar. MISO modeli genel başarıyı, MIMO modeli üç başarı boyutunu ayrı ayrı tahmin eder. MISO daha yüksek doğruluk vermiştir; veri büyüdükçe MIMO'nun da iyileşeceği öngörülür. <!-- BELİRSİZ: hangi eğitim algoritmasının hangi modelde doğruluk ve süre açısından üstün olduğu sunumda karışık anlatıldı ve sunucu bir yerde kendini düzeltti. -->
- **COCOMO ve ML.** COCOMO'nun hata payı yüksek olduğunda projeler gecikir ve bütçe aşılır. Çalışma, COCOMO sürücülerinin nominal değerlerini sayısal çarpanlara çevirip ML sınıflandırıcılarına girdi olarak vermiş ve efor sınıfını tahmin etmiştir. <!-- BELİRSİZ: COCOMO'nun hata oranı için söylenen sayı (yüzde 21 ve "19 tanesi") altyazıda net değil. -->

> **Ek bilgi (derste anlatılmadı):** Basic COCOMO'da efor $E = a \cdot (\text{KLOC})^{b}$ adam-ay olarak hesaplanır; $a$ ve $b$ proje tipine (organik, yarı ayrık, gömülü) göre değişir. Intermediate COCOMO bu sonucu 15 maliyet sürücüsünün çarpımı olan efor ayarlama çarpanıyla (EAF) çarpar.

- **Duygusal takım koçluğu.** Retrospektiflerin teoride sürekli iyileşme sağlaması beklenir, ama motivasyon düştüğünde bu iyileşme durur. ETEC'in ilk iki oturumu teşhis içindir: ekip önce kendini değerlendirir, sonra koçlar dışarıdan değerlendirir ve iki sonuç örtüşür. Sonraki üç oturum eyleme yöneliktir: düşük motivasyonun kök nedenleri bulunur, önlemler oylanır, sorumlulukları ve takvimi olan bir eylem planı hazırlanır. Takım geri bildiriminde herkes diğerleri hakkında isimsiz olarak iki olumlu ve bir geliştirilebilir yön yazar; insanlar kendi olumlu yönlerini beklemedikleri kadar çok görünce motive olur.
- **ML ile yazılım proje yönetimi.** Taramada hata tahmini için örnek bir çalışmada özellik seçimi bir meta-sezgisel algoritmayla yapılmış, k-katlı çapraz doğrulama sonrası KNN, karar ağacı ve doğrusal ayırtaç analiziyle modülün hatalı olup olmadığı sınıflandırılmıştır. Değer tabanlı karar vermede kuruma özgü değer unsurları görüşmelerle çıkarılır ve Bayes koşullu olasılık tablolarıyla karar toplantılarına sayısal destek sağlanır.
- **Zaman planlaması ve kaynak tahsisi.** Çalışılan şirkette talep müşteriden yöneticiye, oradan proje yöneticisine e-postayla iletiliyor, teklif ve görev planlaması elle yürütülüyordu. Önerilen sistem verileri merkezde toplayıp ilgili taraflara gerçek zamanlı göstererek gereksiz e-postaları ve yanlış aktarımları azaltır. Tüm proje ve görevler şirketin toplam yükünü gösteren tek bir plan şemasında izlenebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
