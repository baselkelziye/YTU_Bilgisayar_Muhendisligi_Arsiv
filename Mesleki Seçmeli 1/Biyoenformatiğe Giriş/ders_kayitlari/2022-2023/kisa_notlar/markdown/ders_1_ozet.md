# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin genel yaklaşımı
  - Ders İngilizce anlatılır. Amaç bir programlama dili öğretmek değildir; anlatılan kavramlar ve algoritmalar herhangi bir dille (hocanın deyişiyle Assembler ile bile) uygulanabilir.
  - İlk haftalarda temel kavramlar ele alınır, ardından biyoenformatiğin temel konularına geçilir.
  - Kaynak olarak biyolojik dizi analizi, dizgiler/ağaçlar/diziler üzerine algoritmalar, Perl tabanlı biyoenformatik girişi, "Bioinformatics Computer Skills", genetik ve "Bioinformatics for Dummies" türünde kitaplar anıldı.
- "Bio" ile başlayan ilgili alanlar
  - Tıp mühendisliği (medical engineering): mühendislik kavramlarını ve teknolojiyi enstrümantasyon, tanı ve tedavi cihazları, yapay organlar ve hastanelerde gereken diğer tıbbi cihazların geliştirilmesinde kullanır (ekrandan, 00:25:00).
  - Biyomedikal mühendisliği: disiplinlerarası bir meslektir; mühendislik, matematik, hesaplama ve bilim yöntemlerini biyolojik ve fizyolojik problemlerin analizine uygular.
  - Klinik mühendislik: mühendisliğe yönetim kavramlarını da ekler; hastanede daha iyi hasta bakımını en az maliyetle sağlamayı, cihaz etkinliğini ve elektrik güvenliğini hedefler.
  - Biyomühendislik (bioengineering): biyoteknoloji ve genetik mühendisliğiyle yakından ilişkili, temel araştırma odaklı bir alandır; bitki/hayvan hücrelerinin değiştirilmesi ile yeni mikroorganizmalar geliştirilmesi buna örnektir (ekrandan, 00:30:00).
- Biyomühendislik "şemsiyesi" (ekrandan, 00:45:00)
  - Biyomalzemeler: ajanlar, nanoparçacıklar, biyouyumluluk, kimyasal kompozitler.
  - Görüntüleme: ultrason, BT/X ışını, MR, empedans.
  - İşaret işleme: EEG, ECG, EMG, ultrason.
  - Biyomekanik: implantlar, yapay organlar.
  - Mikro ve nano sistemler: MEMS, sensörler, SoC, kablosuz iletişim.
  - Rehabilitasyon ve tanı: simülasyon, modelleme, enstrümantasyon.
  - Tespit ve kestirim: yapay zekâ, bulanık mantık, sinir ağları.
  - Biyoenformatik: e-sağlık, teletıp, DNA dizi analizi.
- Biyoenformatiğin tanımları
  - Bilginin biyolojik sistemlerde, moleküler düzeyden başlayarak nasıl temsil edildiğini ve iletildiğini inceleyen alandır; bu tanıma göre bilgisayar gerektirmeyen bir disiplindir (ekrandan, 00:55:00).
  - NIH tanımı: biyolojik, tıbbi, davranışsal ya da sağlık verisinin kullanımını genişletmek için hesaplama araçları ve yaklaşımlarının araştırılması, geliştirilmesi ya da uygulanması; bu veriyi edinme, saklama, düzenleme, analiz etme ve görselleştirme dahil (ekrandan, 01:05:00).
  - Pratik tanım: büyük miktarda verinin toplanması, işlenmesi, analiz edilmesi ve iletilmesi (ekrandan, 01:15:00).
  - Disiplinlerarası tanım: biyolojik veriyi anlamak için bilgisayar bilimi, istatistik, matematik ve mühendisliği birleştirir. "In silico", bilgisayarda ya da bilgisayar benzetimiyle yapılan anlamına gelir.
- Moleküler biyolojinin ve genomiğin merkezi dogması (ekrandan, 01:10:00)
  - DNA → RNA → protein → hücresel fenotip.
  - Genom → transkriptom → proteom → hücresel fenotip.
- Hesaplamalı biyolojinin kapsamı (ekrandan, 01:30:00)
  - Hesaplamalı biyoloji en geniş şemsiyedir; içinde biyoenformatik, onun içinde genomik ve proteomik, proteomiğin içinde yapısal biyoenformatik yer alır.
  - Genomik: bir organizmadaki genetik malzemenin (DNA) incelenmesi.
  - Proteomik: proteomların büyük ölçekli incelenmesi; proteom sabit değildir, hücreden hücreye ve zamanla değişir (ekrandan, 01:35:00).
  - Fonksiyonel genomik: gen ve protein işlevlerini ve etkileşimlerini betimler; DNA dizisi gibi statik yönler yerine transkripsiyon, translasyon, gen ifadesinin düzenlenmesi ve protein-protein etkileşimi gibi dinamik yönlere odaklanır (ekrandan, 01:40:00).
- DNA ile Turing makinesi benzetmesi
  - Turing makinesinin temel öğeleri: kontrol birimi, şerit ve okuma-yazma kafası.
  - Merkezi dogmadaki bilgi akışı kavramsal olarak Turing makinesine benzer; DNA bir bilgi saklama sistemi gibi düşünülebilir.
- Biyoenformatiğin uygulama alanları
  - İlaç tasarım çevrimini kısaltma, toksikoloji, moleküler evrim, biyosensörler, biyomalzemeler, DNA hesaplama gibi biyolojik hesaplama modelleri, genetik ve kalıtsal hastalıklar, virüslerin yapısını anlama (COVID-19 örneği).
- İlaç geliştirme yaşam döngüsü (ekrandan, 01:45:00)
  - Keşif (2-10 yıl), klinik öncesi test (laboratuvar ve hayvan), Faz I (güvenlik ve doz için 20-30 sağlıklı gönüllü), Faz II (etkinlik ve yan etki için 100-300 hasta gönüllü), Faz III (sözlü olarak 1000-5000 hasta, uzun süreli kullanım izlenir), ardından otorite onayı.
  - Bir ilacın piyasaya çıkış süresi ortalama 12 yılın üzerindedir (ekrandan, 01:55:00).
- "Killer application" ve kişiselleştirilmiş tıp (ekrandan, 01:50:00)
  - Killer app: Dünyayı kapınıza getirecek, Ar-Ge, pazarlama ve üretimi finanse edecek tek uygulama; genel hesaplamada elektronik tablolama ve masaüstü lazer yazıcı örnekleridir.
  - Biyoteknolojide adayı kişiselleştirilmiş tıptır: hastanın doku örneğinden mikrodizi ile gen ifadesi elde edilir, tıbbi bilgilerle birlikte bir örüntü tanıma sistemine verilir ve kişiye uygun ilaç makul sürede tasarlanır.
- Biyoenformatik araçları
  - Web tabanlı grafik arayüzler çoğunlukla araç kullanıcıları (tool users) içindir; komut satırı araçları (çoğunlukla Linux) araç geliştiriciler (tool makers) içindir. Bilgisayar mühendisleri büyük olasılıkla araç geliştirici olur.
  - Örnek araçlar: BLAST, genom tarayıcıları.
- Biyoenformatik için programlama öğrenme ve tekrarlanabilir araştırma (ekrandan, 02:00:00 ve 02:15:00)
  - Plan yap, seçici ol, öğrenme ortamını düzenle, okumaları ve alıştırmaları yap, değerlendirmeleri yap.
  - İş akışı iyi belgelenmeli; bilgisayardaki bilgi düzenli tutulmalı; veri başkalarına anlaşılır biçimde açık olmalı; üst veri (metadata) önemlidir.
- Biyoenformatik araştırma alanları
  - Genomik, transkriptomik, proteomik, epigenetik, interaktomik, protein analizi ve yapı tahmini, yeni nesil dizileme, karşılaştırmalı analiz, sistem biyolojisi, metin madenciliği ve bilgi çıkarımı.
- Bilgi sistemlerinin temelleri
  - Enformatik (informatics) terimi: 1956'da Alman bilgisayar bilimci Karl Steinbuch "Informatik" sözcüğünü (otomatik bilgi işleme) türetti; Fransızca "informatique" 1962'de Philippe Dreyfus tarafından türetildi; terim "information" ve "automatic" sözcüklerinden oluşur (ekrandan, 02:25:00).
  - Veri-bilgi-bilgi birikimi (data-information-knowledge): veri yorum ve analiz eklenmemiş işlenmemiş olgulardır (ekrandan, 02:30:00); bilgi veriden çıkarılır; bilgi birikimi (knowledge) çıkarılmış bilgi, geçmiş deneyim ve iç görünün (insight) birleşimidir.
  - Faydalı verinin koşulları: amaçla ilgili, eksiksiz, doğru ve zamanında olmalı.
  - Sistem: düzenli biçimde birbirine bağlı parçaların oluşturduğu, tanımlı bir amacı gerçekleştiren bütün. Kontrol teorisi bakışıyla girdi → süreç → çıktı ve geri besleme (ekrandan, 02:45:00).
  - Bilgi teknolojisinin bileşenleri: donanım (kalem-kâğıt dahil), yazılım, insanlar ve prosedürler.
  - Sayısal sistem: ayrık girdileri ve ayrık iç durumları alıp ayrık çıktılar üreten sistem. Bilgi ayrık olmak zorundadır, çünkü sonsuz bilgiyi saklayacak sonsuz zaman ve yer yoktur.
  - Tipik ölçüm sistemi: fizyolojik/dış enerji → dönüştürücü (transducer) → yükselteç/algılayıcı → analog işaret işleme → bilgisayar içinde analog-sayısal dönüştürücü → işaret saklama/tamponlama → işaret işleme → görüntüleme (ekrandan, 02:55:00).
  - Girdi dönüştürücülerine sensör, çıktı dönüştürücülerine eyleyici (actuator) denir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Biyoenformatik özünde bilgiyle ilgilidir
  - Tanımdaki anahtar sözcük "bilgi"dir. Biyoenformatik bilgisayarsız da yapılabilir (eskiden dizi bantları kâğıt üzerinde elle okunuyordu), ama günümüzdeki veri miktarında bilgisayar kullanılmadan bilgi çıkarmak çok uzun sürer. Bilgisayar, bilgiyi olabildiğince hızlı, ideal olarak anında çıkarmak için kullanılır.
- Veriyi işlemek değil, bilgi çıkarmak amaçtır
  - Örneğin ECG verisi kaydetmenin amacı veriyi işlemek değil, kalp hakkında bilgi çıkarmaktır; işleme bunun aracıdır. "Doğru bilgiyi almak ve bilgiyi doğru almak" önemlidir.
- Bilgisayar mühendisleri "yarı biyoenformatikçi"dir
  - Programlama, algoritmalar, ayrık matematik, bilgi kuramı, istatistik, yapay zekâ, veri madenciliği, görselleştirme gibi becerilerin çoğu zaten bilgisayar mühendisinde vardır; eksik olan temel biyoloji bilgisidir.
- Hesaplamalı biyoloji ve biyoenformatik
  - İkisi çoğu zaman birbirinin yerine kullanılır, ama hesaplamalı biyoloji daha geniş bir şemsiyedir.
- Fonksiyonel genomik yapısal genomikten zordur
  - Yapısal genomik oldukça gelişmiş bir alandır; fonksiyonel genomik ve protein-protein/gen-gen etkileşimleri hâlâ sıcak araştırma konusudur.
- Belgeleme her zaman önemlidir
  - Program yazarken ve veri kaydederken belgeleme yapılmalıdır.
- Deneyerek öğrenme
  - Konfüçyüs'e atfedilen söz: "Duydum unuttum, gördüm hatırladım, yaptım öğrendim." Deney yapmak öğrenmenin en kalıcı yoludur.

## Kısa Tekrar Notları

- Biyoenformatik: bilginin biyolojik sistemlerde moleküler düzeyden başlayarak temsil edilmesi ve iletilmesi; pratikte büyük biyolojik verinin toplanması, işlenmesi, analizi ve iletimi.
- NIH tanımındaki işlemler: edinme, saklama, düzenleme, analiz, görselleştirme.
- Merkezi dogma: DNA → RNA → protein → fenotip; genomik karşılığı: genom → transkriptom → proteom → fenotip.
- Kapsam: hesaplamalı biyoloji ⊃ biyoenformatik ⊃ {genomik, proteomik}; proteomik ⊃ yapısal biyoenformatik.
- Proteom sabit değildir: hücreden hücreye ve zamanla değişir.
- In silico = bilgisayarda/benzetimle yapılan.
- Turing makinesi: kontrol birimi, şerit, okuma-yazma kafası; DNA bilgi akışına benzetilir.
- İlaç geliştirme: keşif 2-10 yıl; Faz I 20-30 sağlıklı gönüllü; Faz II 100-300 hasta; Faz III 1000-5000 hasta; toplam 12 yılın üzeri.
- Killer app adayı: kişiselleştirilmiş tıp.
- Araç kullanıcıları web arayüzü, araç geliştiriciler komut satırı kullanır.
- Enformatik: Steinbuch 1956 (Informatik), Dreyfus 1962 (informatique).
- Veri → bilgi → bilgi birikimi (knowledge = bilgi + deneyim + iç görü).
- Faydalı veri: ilgili, eksiksiz, doğru, zamanında.
- Sistem modeli: girdi, süreç, çıktı, geri besleme.
- Sayısal sistemde bilgi ayrıktır.
- Ölçüm zinciri: dönüştürücü → yükselteç → analog işleme → ADC → saklama → işleme → görüntüleme. Sensör girdi, eyleyici çıktı dönüştürücüsüdür.

## Detaylı Açıklamalar

- Ders, biyoenformatiğin hangi geniş alanın parçası olduğunu göstermek için "bio" önekli alanları tek tek tanımlayarak başlar. Tıp mühendisliği cihaz ve enstrümantasyon geliştirmeye, klinik mühendislik hastanede teknoloji ve yönetimi birleştirerek hasta bakımını iyileştirmeye, biyomühendislik ise biyoteknoloji ve genetik mühendisliğine yakın temel araştırmaya odaklanır. Biyomühendislik şemsiyesi altında biyomalzemeler, görüntüleme, işaret işleme, biyomekanik, mikro/nano sistemler, rehabilitasyon ve tanı, tespit ve kestirim ile biyoenformatik yer alır. İşaret işleme anlatılırken ECG'nin kalbin elektriksel etkinliğini incelemek için kullanılan işaret olduğu, SoC'nin (system-on-chip) sensörler ve işlemciler dahil bütün sistemi tek bir yongaya toplamaya çalıştığı ve vücuda yerleştirilen sistemlerle veri alışverişinin kablosuz yapılması gerektiği söylendi.
- Biyoenformatiğin tanımları farklı kaynaklardan verildi. İlk tanıma göre biyoenformatik, bilginin biyolojik sistemlerde nasıl temsil edilip iletildiğini inceler ve bu haliyle bilgisayar gerektirmez. Ancak veri miktarı arttıkça bilgisayar zorunlu hale gelir. NIH tanımı hesaplama araçlarını öne çıkarır ve bu işlerin (edinme, saklama, düzenleme, analiz, görselleştirme) doğrudan bilgisayar mühendisliğinin işleri olduğunu gösterir. Hesaplamalı biyoloji ise veri analitiği ve kuramsal yöntemler, matematiksel modelleme ve hesaplamalı benzetim tekniklerinin biyolojik, davranışsal ve sosyal sistemlere uygulanmasıdır. Biyoenformatikte kullanılan teknikler örüntü tanıma, veri madenciliği, makine öğrenmesi, algoritmalar ve görselleştirmedir; bu algoritmalar graf kuramı, yapay zekâ, yumuşak hesaplama, işaret işleme ve benzetim gibi alanlara, onlar da ayrık matematik, kontrol kuramı, sistem kuramı, bilgi kuramı ve istatistik gibi kuramsal temellere dayanır. Bilimsel literatürden bilgi çıkarmak için doğal dil işleme de kullanılır.
- Biyoenformatiğe üç bakış açısı slaytlarda gösterildi: merkezi dogma (DNA'dan proteine bilgi akışı), bireysel organizma düzeyinde zaman içindeki, vücut bölgeleri arasındaki ve farklı fizyolojik/patolojik durumlardaki değişimler ve bakteriler, arkeler ve ökaryotları kapsayan yaşam ağacı. <!-- BELİRSİZ: Altyazıda ikinci ve üçüncü bakış açısının slayt metni bozuk; yaşam ağacındaki üçüncü dal Whisper'da "nükleotis" diye geçiyor, büyük olasılıkla "eukaryota". -->
- Genomik bir organizmanın genetik malzemesinin (DNA) incelenmesidir. Proteomik ise bir organizma, sistem ya da biyolojik bağlamda üretilen proteinlerin bütünü olan proteomun büyük ölçekli incelenmesidir. Proteom bir türün (örneğin Homo sapiens) ya da bir organın (örneğin karaciğer) proteomu olarak ele alınabilir. Protein etkinliği yalnız ifade düzeyine değil başka etkenlere de bağlı olduğu için proteomik, genomikten daha zordur. Proteomik; proteinlerin ne zaman ve nerede ifade edildiğini, üretim, yıkım ve kararlı durum miktarlarını, nasıl değiştirildiklerini, hücre içi bölmeler arasındaki hareketlerini, metabolik yolaklara katılımlarını ve birbirleriyle etkileşimlerini inceler. Yapısal biyoenformatik protein, RNA ve DNA gibi makromoleküllerin üç boyutlu yapısının analizi ve tahminiyle ilgilenir. Fonksiyonel genomik ise genom ve RNA dizileme projelerinin verisini kullanarak gen ve protein işlevlerini ve etkileşimlerini betimler.
- Biyoenformatiğin hâlâ "sıcak" bir alan olmasının nedeni arz-talep dengesizliğidir: hem biyolojide hem bilgisayar biliminde yeterince eğitimli az sayıda insan vardır, buna karşılık genom dizileme ve mikrodiziler çok büyük miktarda veri üretmektedir. Bu veri büyük veri (big data) kavramına da girer.
- İlaç geliştirme yaşam döngüsü uzun ve pahalıdır: keşif 2-10 yıl, ardından laboratuvar ve hayvan deneyleri, Faz I'de 20-30 sağlıklı gönüllüyle güvenlik ve doz, Faz II'de 100-300 hasta gönüllüyle etkinlik ve yan etkiler, Faz III'te binlerce hastayla uzun süreli kullanım izlenir; sonunda otorite (ABD'de FDA) onayı gerekir. Ortalama piyasaya çıkış süresi 12 yılın üzerindedir. Biyoenformatik bu çevrimi kısaltmak için kullanılır. <!-- BELİRSİZ: 01:49:11 civarında Faz I/II/III'ten geçme oranları sözlü verildi ("30%", "80%") ama altyazı bozuk ve slayt karesi yok. --> Hoca altyazıda "FASTA, Federal Drug Agency" diye geçen kurumu andı.

> **Ders sonrası not:** ABD'deki ilaç onay kurumu Food and Drug Administration'dır (FDA). Altyazıdaki "Federal Drug Agency" büyük olasılıkla Whisper hatası ya da sözlü bir kaymadır.

- Kişiselleştirilmiş tıpta aynı şikâyetle gelen iki hastanın sorunu farklı nedenlerden kaynaklanabilir. Hastanın doku örneğinden mikrodizi ile gen ifadesi elde edilir; bu bilgi tıbbi önem, tedavi bilgisi ve kaynaklarla birlikte bir örüntü tanıma sistemine verilir ve kişiye özel ilaç makul bir sürede hazırlanmalıdır. Bunun için yüksek başarımlı hesaplama altyapısı gerekir.
- Dersin ikinci bölümünde bilgi sistemlerinin temelleri hatırlatıldı. Enformatik yalnız elektronik bilgisayarla sınırlı değildir; bilgiyi oluşturma, saklama, bulma, işleme ve paylaşma elle de yapılabilir. Veri yorumsuz ham olgulardır (örneğin bir hastanın ECG işaretinin diske kaydedilmiş hali); bilgi bu veriden çıkarılır; knowledge ise bilgi, geçmiş deneyim ve iç görünün birleşimidir. Sistem kavramı farklı mühendislik dallarında farklı anlaşılsa da ortak tanım, tanımlı bir amacı gerçekleştiren, düzenli biçimde bağlı parçalar bütünüdür. Bilgi sistemi, kurumların bilgiyi saklama, taşıma, düzenleme ve işleme yollarıdır; bilgi teknolojisi bunu gerçekleştiren donanım, yazılım, insanlar ve prosedürlerdir.
- Sayısal sistem ayrık girdiler ve ayrık iç durumlarla ayrık çıktılar üretir. Bir öğrencinin yanıtına göre zaman ekseni sonsuz parçaya bölünebildiği için bilgisayara sonsuz bilgi giremeyiz; hoca da sonsuz zamanımız, gücümüz ve depolama yerimiz olmadığından bilginin sonlu, yani ayrık olması gerektiğini ekledi. Tipik ölçüm sisteminde sıcaklık, ses, basınç ya da ışık gibi sürekli bir büyüklük önce dönüştürücüyle elektrik enerjisine (gerilim ya da akım) çevrilir, çıkışı küçük olduğu için yükseltilir, analog-sayısal dönüştürücüyle sayısallaştırılır, saklanır, işlenir ve görüntülenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
