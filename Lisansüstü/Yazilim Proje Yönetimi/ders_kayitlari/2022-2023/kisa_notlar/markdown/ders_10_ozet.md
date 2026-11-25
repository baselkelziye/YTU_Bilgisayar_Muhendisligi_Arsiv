# Ders 10 Çalışma Özeti

## Genel Konular

- Bu derste öğrenciler yazılım proje yönetimiyle ilgili makaleler sundu. Hoca sunumlar arasında sorular sordu ve kısa yorumlar yaptı. Üç sunumun teknik içeriği aşağıda sırayla verilmiştir.
- Yazılım proje yönetimi için artırımlı varlık oluşturma süreç modeli ("A New Process Model of Incremental Asset Building for Software Project Management"; ekrandan, 00:05:00)
  - Problem: yazılım talebi hızla artmasına rağmen yazılım projelerinin başarı oranı düşüktür ve firmalar kâr edemez. Makaleye göre ana neden, her müşteriye baştan özel yazılım geliştiren geleneksel proje yönetimidir.
    - Her müşteri için özel yazılım geliştirmek gereksiz ek zaman ve kaynak harcar.
    - Yeniden kullanılabilir bileşen az olduğu için benzer işler her seferinde yeniden yapılır.
    - Özelleştirilmiş yazılımın bütün maliyetinin tek bir müşteriye faturalanması mantıksızdır, kâr sıfıra yaklaşır ve firmanın sürdürülebilirliği azalır.
  - Öneri: artırımlı varlık modeli. Hedeflenen pazar segmentine göre temel ve yeniden kullanılabilir bileşenler oluşturulur, projeler bu bileşenler entegre edilerek en az özelleştirmeyle geliştirilir. Toplam maliyet benzer ihtiyaçları olan birçok müşteriye yayılır, müşteri başına maliyet düşer (ekrandan, 00:20:00).
  - Modelin aşamaları (ekrandan, 00:10:00):
    - Market analizi: belirli bir pazarın özelliklerini belirleme, bilgileri analiz etme, proje kapsamını tanımlama ve yeniden kullanılabilir bileşenleri oluşturma süreci.
    - Proje seçimi: hedeflenen pazar segmentine göre belirli bir etki alanı tabanlı proje seçme süreci.
    - Yeniden kullanılabilir bileşenler: bileşen geliştirme ve ürünü sonraki projelerde kullanmak için kademeli olarak daha fazla bileşen ekleme süreci.
  - Süreç bir aktivite diyagramıyla gösterilir. Kulvarlar: pazar analisti, yönetici direktör, proje yöneticisi ve testçi.
    - Pazar analizi yapılır ve hedef pazar seçilir. Direktör analiz raporuna göre bir proje seçer.
    - Projenin temel bileşenleri kontrol edilir. Bileşen varsa doğrudan projeye entegre edilir; yoksa yeniden kullanılabilir bileşen geliştirilip entegre edilir.
    - Proje kalite için test edilir ve müşteriye teslim edilir.
  - Her aşama için girdi, aktiviteler, çıktı ve eserler (artifact) tablo halinde verilmiştir.
    - Pazar analizi: girdi pazar bilgisi ve bilgi toplama teknikleri; çıktı hedef pazar segmenti; eser analiz raporu ve seçilen pazara genel bakış.
    - Proje seçimi: girdi analiz raporu; eserler karar verme kanıtları, proje seçim iletişimi ve proje genel bakışı.
    - Geliştirme: proje kapsamını anlama, bileşenleri kontrol etme, eksik bileşenleri oluşturma, entegre edip test etme; eserler yeni/güncellenmiş kaynak kod ve birim test durumu.
    - Entegrasyon ve teslim: çıktı yeni sürüm ve sürüm notları.
  - Sonuç: yazılım endüstrisi şirket içi geliştirme ve sözleşmeli projelerle başladı; artık yeniden kullanılabilir bileşenleri olan şirketler aynı yazılımı az özelleştirmeyle birçok müşteriye sunabilir. Bunun için pazar analizi proje yönetiminin ilk faaliyeti olmalıdır (ekrandan, 00:15:00).
- Küresel yazılım geliştirme (GSD) bağlamında genişletilmiş COCOMO II tabanlı maliyet tahmin modeli (ekrandan, 00:25:00)
  - GSD projelerinin başarısı kalite, zaman ve maliyetle ölçülür. Amaç, GSD'ye özgü kritik maliyet etkenlerini COCOMO II'ye ekleyerek daha doğru bir efor/maliyet tahmini yapmaktır.
  - Araştırma yöntemi: sistematik literatür taramasıyla maliyet etkenleri belirlenir, sektörde doğrulanmış verilerle istatistiksel analiz yapılır, COCOMO II mevcut ve kritik etkenlerle genişletilir, yeni metrikler formüle edilir, yeni tahmin denklemi kurulur, performans ölçülür ve uzman görüşüyle doğrulanır.
  - Maliyet tahmin modelleri (ekrandan, 00:30:00):
    - Algoritmik: önceden atanmış parametrelerle matematiksel hesap yapar. SLIM tabanlı (GSD için SLIM) ve COCOMO II tabanlı (GSD için COCOMO II, offshoring için COCOMO II, Cost Xpert).
    - Bileşik (composite): COBRA tabanlı, Effort Overhead modeli.
    - Diğer (algoritmik olmayan): use case points, analoji tabanlı, makine öğrenmesi tabanlı. Önceki projelerin verilerinden yararlanır (uzman yargısı, yapay sinir ağları, bulanık mantık, regresyon).
  - Model üç fazdan oluşur:
    - Faz 1: GSD'deki kritik maliyet etkenlerinin ve temel tahmin modelinin seçilmesi. Etkenler dört kategoride toplanır: insanlarla ilgili, süreçle ilgili, projeyle ilgili ve dış kaynak (outsourcing) ile ilgili.
    - Faz 2: COCOMO II'nin genişletilmesi; metrik formülasyonu ve denklem değişikliği.
    - Faz 3: yeni denklemle tahmin ve hata oranının hesaplanması.
  - Etken kategorileri:
    - İnsan: ekip üyelerinin özellikleri, müşteri katılımı, ekibin iş yapma potansiyeli, ekip içi güven (team trust).
    - Proje: müşteri ihtiyaçlarının doğru anlaşılması ve karşılanması.
    - Dış kaynak: ülkeler arası zaman farkı, coğrafi farklılık, dil farkı.
    - Süreç: süreç modeli, süreç olgunluğu, süreç uyumu, iletişim süreçleri.
  - Metrik formülasyonu örneği, müşteri katılımı (ekrandan, 00:35:00):

    | Kategori | Ölçüt (müşteriyle oturum/toplantı sayısı) | Değer |
    |---|---|---|
    | Low | Ayda 2'den az | 1.25 |
    | Medium | Ayda 2-4 | 1.10 |
    | High | Ayda 4'ten fazla | 1.00 |

    - Müşteriyle toplantı azaldıkça çarpan büyür, yani tahmini efor artar.
  - COCOMO II denklemi: $PM = A \times Size^{E} \times \prod_{i} EM_i$. Sunumda $A = 2.94$ olarak verildi. $E$ ölçek üssü beş ölçek faktörüne bağlıdır: öncelik (precedentedness), geliştirme esnekliği, risk çözümü, ekip uyumu ve süreç olgunluğu. $EM_i$ efor çarpanlarıdır. <!-- BELİRSİZ: denklem slaytı karelerde yok; denklem altyazıdaki anlatıma ve standart COCOMO II biçimine göre yazıldı. -->
  - Yeni modelde 14 kritik maliyet etkeni (insan, süreç, proje ve dış faktörler) denkleme ek çarpan olarak girer.
  - Performans ölçütü: göreli hata büyüklüğü $MRE = \frac{|\text{gerçek efor} - \text{tahmini efor}|}{\text{gerçek efor}}$. Sunucuya göre genişletilmiş modelin hatası standart COCOMO II'ye göre belirgin biçimde düşmüştür. <!-- BELİRSİZ: hata karşılaştırma grafiğinin sayısal değerleri karelerde yok. -->
  - Uzman değerlendirmesi: en az 10 yıl proje yöneticiliği deneyimli sektör uzmanları seçilir. Yazar bir kontrol listesi hazırlar, uzmanlara iletir, uzmanlar kavramsal modeli inceleyip yanıt verir, yazar revizyon yapar. Model kabul, ret ya da gözden geçirme olarak değerlendirilir (ekrandan, 00:40:00).
- Çevik pratikler ve yazılım proje yönetimi karşıt paternleri ("Agile and Software Project Management Antipatterns: Clarifying the Partnership", IEEE Software, 2021; ekrandan, 01:15:00)
  - Karşıt patern (antipattern): yazılım proje yönetimi süreçlerini sekteye uğratan, ileri aşamada projenin başarısız olmasına yol açan kötü yaklaşımlardır.
  - Makalenin dayanağı: alıntılanan bir IBM çalışmasına göre proje başarısızlıklarının %53'ü kötü yönetimden, yalnız %3'ü teknik zorluklardan kaynaklanır.
  - Yaygın hata nedenleri: bilgi eksikliği, tembellik, kibir ve acelecilik. Proje yöneticisinin bilgi eksikliği en yaygın nedendir. Etkileri müşteriyi, takım üyelerini ve proje yöneticisini kapsar; kontrol, motivasyon ve personel yönetimini olumsuz etkiler (ekrandan, 01:05:00).
  - Yöntem: çevik pratikler son 10 yıldaki literatür ve bir sektör raporuyla doğrulanır; karşıt paternler 2015'te yayımlanmış 22 kalemlik bir envanterden alınır. Pratik-patern etki tablosu yazarların sektör deneyimine ve çoğu sertifikalı Scrum Master olan 30 uygulayıcıyla yapılan birer saatlik görüşmelere dayanır.
  - Etki türleri (ekrandan, 01:10:00):
    - Onay işareti (%42): pratik karşıt paterni azaltır. Örnek: günlük stand-up toplantısı herkesin varlığını gerektirdiği için Absentee Manager (yönetici yokluğu) sorununu çözer.
    - Büyüteç (%35): pratik paterni kaldırmaz ama belirtilerini tespit etmeye yardım eder. Örnek: sprint planlama, Rising Upstart (aşırı ve hızlı iş üstlenmeye çalışan üye) durumunun fark edilmesini kolaylaştırır.
    - Çarpı (%22): pratiğin paterne etkisi yoktur. Örnek: sprint review; All You Have Is a Hammer, Appointed Team ya da aşırı ayrıntılı plana bağlılık gibi sorunları çözmez.
    - Ünlem (%1): pratik paterni kötüleştirir. Tek örnek: Single Team pratiği herkesin her rolü üstlenebileceği varsayımıyla Domino Effect paternine yol açabilir.
  - En çok karşıt paterne çözüm getiren pratikler: sprint planlama, planning poker ve agile UX. Fire Drill, Mushroom Management ve Myopic Delivery müşteriye özellikle zarar veren paternlerdir.
  - Çıkarımlar: bir pratiğin uygulama maliyeti ile çözdüğü sorunlar arasında kâr-zarar analizi yapılmalıdır (agile UX müşteri katılımı gerektirdiği için maliyetlidir). Tek pratik çoğu zaman yetmez, birkaç pratik birlikte gerekebilir. Pratikler takımları kendiliğinden kurtarmaz; her organizasyon bütçe ve zaman kısıtlarına göre risklerini kendisi belirlemelidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kulvarlı süreç diyagramları UML aktivite diyagramına karşılık gelir
  - Birinci sunumdaki diyagram her aktörün (pazar analisti, direktör, proje yöneticisi, testçi) yaptığı işleri ayrı kulvarlarda gösterir. Nesneye yönelik yazılım geliştirmede bu gösterim aktivite diyagramıdır.
- Proje başarısının üç ölçütü
  - Başarısız proje denince ilk bakılan üç şey: zamanında bitti mi, ayrılan kaynakla (maliyetle) bitti mi, istenen kapsam tutturuldu mu.
  - "Yazılım projelerinin başarı oranı düşüktür" cümlesi makalelerin girişinde bir klişe haline gelmiştir. Güncel Gartner raporlarına bakılmalıdır; çevik süreçler kapsam konusunda baştan anlaşmayı kolaylaştırdığı için son yıllarda başarı oranı artmış olabilir.
- Maliyet tahmini
  - Matematiksel işlem içeren maliyet tahmin modelleri, yazılım proje yönetiminde çok eski yıllardan beri üzerinde durulan bir konudur ve son yıllarda gerekliliği daha da artmıştır.
- Çevik süreçler ve karşıt paternler
  - Çevik süreçler, yazılım proje yönetimindeki karşıt paternleri azaltmak için kullanılmaya uygundur.

## Kısa Tekrar Notları

- Artırımlı varlık modeli: önce pazar analizi, sonra proje seçimi, ardından yeniden kullanılabilir bileşenlerin kontrolü/geliştirilmesi, entegrasyon, test ve teslim.
- Bileşen varsa entegre et, yoksa yeniden kullanılabilir olarak geliştir; maliyet birçok müşteriye yayılır.
- Kulvarlı süreç gösterimi = UML aktivite diyagramı.
- Proje başarısı: zaman, maliyet (kaynak), kapsam (ve kalite).
- Maliyet tahmin modelleri: algoritmik (SLIM, COCOMO II), bileşik (COBRA), diğer (use case points, analoji, makine öğrenmesi).
- COCOMO II: $PM = A \times Size^{E} \times \prod EM_i$; $E$ beş ölçek faktörüne bağlıdır.
- GSD için genişletilmiş COCOMO II: 14 kritik maliyet etkeni ek çarpan olarak eklenir; dört kategori: insan, süreç, proje, dış kaynak.
- Müşteri katılımı çarpanı: ayda <2 toplantı 1.25, 2-4 toplantı 1.10, >4 toplantı 1.00.
- MRE = |gerçek − tahmin| / gerçek.
- Karşıt patern etki türleri: azaltır %42, tespit ettirir %35, etkisiz %22, kötüleştirir %1.
- Daily stand-up → Absentee Manager'ı çözer; Single Team → Domino Effect riskini artırır.
- En çok pattern'e çözüm getiren pratikler: sprint planlama, planning poker, agile UX; ama maliyetleri de hesaba katılmalıdır.

## Detaylı Açıklamalar

- Artırımlı varlık modelinde firma önce hangi pazar segmentine hizmet edeceğini belirler, o segmentteki müşterilerin ortak ihtiyaçlarını çıkarır ve bu ihtiyaçlar için yeniden kullanılabilir bileşenler (varlıklar) üretir. Her yeni proje bu bileşenleri kullanır; eksik bileşen ortaya çıkarsa yeniden kullanılabilir biçimde geliştirilir ve varlık havuzuna eklenir. Böylece havuz proje projeden büyür (artırımlı), özelleştirme miktarı ve müşteri başına maliyet azalır. Sınıftaki tartışmada, müşteriye özgü yapılan çözümlerin bilgisinin kişilere bağlı kaldığı, genelleştirilmiş bir çözümün ise hem yeniden kullanım hem ekip içi bilgi paylaşımı açısından faydalı olduğu dile getirildi. Ortak çözüm kurmanın firmanın büyüklüğüne ve müşteri çeşitliliğine göre zorlaşabileceği de belirtildi.
- Maliyet tahmininde algoritmik modeller girdiyi (boyut, etkenler) matematiksel bir denklemle eforun karşılığına çevirir. COCOMO II eforu proje boyutunun bir kuvveti olarak hesaplar; üs $E$ ölçek ekonomisini/ölçek kaybını, çarpanlar ise ürün, platform, personel ve proje özelliklerini temsil eder. Küresel yazılım geliştirmede zaman dilimi, coğrafya, dil, müşteri katılımı ve ekip içi güven gibi etkenler standart modelde yeterince yer almadığından makale bunları ek çarpan olarak ekler. Her yeni etken için ölçülebilir bir metrik tanımlanır; örneğin müşteri katılımı aylık toplantı sayısıyla ölçülür ve düşük katılım eforu %25 artıran 1.25 çarpanına karşılık gelir. Modelin doğruluğu MRE ile ölçülür ve uzmanların değerlendirmesiyle desteklenir.
- Çevik pratikler her soruna doğrudan çözüm değildir. Makalenin pratik-patern tablosu, bir pratiğin bir karşıt paterni azaltabildiğini, yalnızca belirtilerini görünür kılabildiğini, hiç etkilemeyebildiğini ya da kötüleştirebildiğini gösterir. Örneğin günlük toplantılar yöneticinin takımla temasını zorunlu kıldığı için yönetici yokluğunu giderir; sprint planlamada görev tahminleri ve dağılımı yapıldığı için aşırı iş üstlenen üyeler fark edilir; sprint review ürünü müşteriye göstermeye yönelik olduğundan ekip kurulumu ya da aşırı ayrıntılı planlama sorunlarını çözmez. Herkesin her işi yapabileceği varsayımına dayanan Single Team pratiği ise bir kişinin başka işe kaydırılmasıyla zincirleme gecikmelere (domino etkisi) yol açabilir. Bu yüzden pratik seçimi, takımın sorunlarına, bütçe ve zaman kısıtlarına göre maliyet-fayda analiziyle yapılmalıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
