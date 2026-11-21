# Ders 2 Çalışma Özeti

## Genel Konular

- Bağlam farkındalığına (context-awareness) giriş
  - Elektronik cihazlar artık çevrelerini algılayabilen bir noktaya geldi: giyilebilir cihazlardan taşınabilir cihazlara, hatta dizüstü bilgisayarlara kadar birçok cihaza yeni sensörler ekleniyor.
  - İnsan, karar verirken hem geçmiş deneyimini hem de aynı anda birden fazla kaynaktan aldığı girdiyi kullanır. Bağlam farkında hesaplamada da kameradan gelen görüntü, mikrofondan gelen ses ve ivmeölçerden gelen bilgi birlikte harmanlanır.
  - Slayttaki kullanım alanları: masaüstü uygulamalar, web uygulamaları, mobil hesaplama, yaygın (pervasive/ubiquitous) hesaplama (ekrandan, 00:15:00).
  - Slayt notuna göre "ubiquitous computing" terimi Mark Weiser'ın 1991 tarihli "The Computer for the 21st Century" makalesiyle, "context-aware" terimi 1994'te Schilit ve Theimer ile ortaya çıktı; bugün kabul gören "context" ve "context-awareness" tanımları Abowd ve arkadaşlarına (1999) aittir (ekrandan, 00:15:00).
- Mobil hesaplama ve ilişkili alanlar
  - Kullanıcılar işlerini giderek tarayıcı yerine özelleşmiş mobil uygulamalarla yapıyor. Uygulama sayısının artması sorununa karşı birkaç MB'lık, modül bazında indirilebilen anlık uygulamalar (instant apps) çıktı; bu yaklaşım mikro servis mantığına benzer.
  - Mobil hesaplamanın üç ana başlığı: mobil iletişim (communication), mobil donanım (hardware), mobil yazılım (software).
  - Dokunduğu alanlar: dağıtık sistemler, nesnelerin interneti (IoT), konum tabanlı hesaplama, yapay zekâ, mobil ağlar, insan-bilgisayar etkileşimi (HCI), yaygın hesaplama.
  - Mobil haberleşme teknolojileri: Bluetooth, Bluetooth Low Energy (beacon'larda ve iç mekân konumlandırmada), Wi-Fi, ZigBee, IEEE 802.15.4, NFC, GPS, baz istasyonu protokolleri (UMTS, HSDPA, LTE; 2G, 3G, 4.5G, 5G). Hepsinin altında taşıyıcı olarak radyo frekansı vardır.
- 5G ve gecikme
  - 5G'nin çığır açacak farkı, hedeflenen yaklaşık 1 ms'lik tepki süresidir (latency); çok sayıda eş zamanlı bağlantı da önemli bir farktır.
  - Düşük gecikme otonom araçlar için kritiktir; ancak araçların çevrim içi olması yeni güvenlik riskleri (aracın uzaktan ele geçirilmesi) doğurur.
- İnsan-bilgisayar etkileşimi ve sanal asistanlar
  - Klavye ve farenin ötesinde: sanal klavye, dokunmatik ekran, basınç duyarlı (üç boyutlu) dokunma, sesli komut.
  - Derste anılan bir çalışmaya göre anlık mesajlaşmada uzun metinleri sesle girmek, yazmaya göre enerji açısından daha verimli bulunmuş.
  - Sanal asistanlar (Siri, Google sesli asistanı, Alexa, sohbet botları) iki yapıya dayanır: ses işleme (speech-to-text, text-to-speech) ve doğal dil işleme.
  - Duygu farkında hesaplama (emotion-aware computing): kullanıcının duygu durumunu sesten, yüz ifadesinden algılayıp ona göre çözüm üretmek. Hoca bunu tez konusu olmaya uygun yeni bir alan olarak gösterdi.
- Yaygın (pervasive / ubiquitous) hesaplama ve veri yönetimi
  - Her an, her yerden, her cihazdan, her formatta erişilebilen yapı. "N kişinin bir cihazı kullanmasından" "bir kişinin N cihazı kullanmasına" geçildi.
  - Teknik sorun veri yönetimidir: her cihazda farklı ve yinelenen (redundant) veri oluşur; bunun çözüm alanı bulut bilişimdir (cloud computing), ama iyi organize edilmezse veri yine yinelenir.
  - Asıl gelecekteki sorun sensör ağları ve IoT cihazlarının üreteceği veri miktarıdır (yakın gelecekte on milyarlarca IP alan cihaz).
  - Çözüm: ham veriyi göndermek yerine yerinde işlemek (in-situ / on-premise processing) ve uç bilişim (edge computing). Uç cihazlar ham veriden bilgi (information, knowledge) çıkarıp yalnız onu buluta göndermelidir.
- Sensör ağları
  - Enerjisi ve işlem kapasitesi kısıtlı düğümler; ağırlıklı olarak dış ortamda (askerî, tarım uygulamaları) kullanılır. Düğümlerin özel IP adresi yoktur, tek tek erişilemez.
  - Küme başı (cluster head): veriyi toplayıp harmanlayan ve merkeze gönderen düğüm. Ya daha güçlü özel bir düğüm atılır ya da düğümler aynıysa görev dönüşümlü devredilir; böylece her düğüm eşit enerji harcar ve ağın ömrü uzar.
  - Yinelenen veri sensör ağında işe yarar: komşu sensörler 22, 22 derece ölçerken 78 derece gösteren sensör aykırı değer (outlier) olarak bozuk sayılır.
  - Veri akışı tek yönlüdür: düğümlerden alıcıya (sink / baz istasyonu), oradan düşük ve yüksek uçlu cihazlara ve buluta (ekrandan, 02:05:00).
- Büyük veri
  - Bir verinin büyük veri sayılması yalnız hacme bağlı değildir: hacim (volume), hız (velocity), çeşitlilik (variety), doğruluk (veracity) kuralı (3V/4V).
  - Tek tip, yavaş değişen veri (ör. birkaç TB sıcaklık verisi) büyük veri problemi sayılmaz.
- IoT ve ara katman (middleware)
  - IoT cihazına doğrudan IP ile erişmek adresleme ve özellikle güvenlik sorunu yaratır. Çözüm ara katmandır.
  - Slayt tanımı: ara katman, ağ işletim sistemi ile uygulama arasında duran ve heterojenlik, birlikte çalışabilirlik, güvenlik, güvenilirlik gibi sık karşılaşılan sorunlara bilinen, yeniden kullanılabilir çözümler sunan yazılım katmanıdır (ekrandan, 00:45:00).
  - Ara katman çözümlerinin istenen özellikleri: cihaz yönetimi, birlikte çalışabilirlik, platform taşınabilirliği, bağlam farkındalığı, güvenlik ve mahremiyet (ekrandan, 01:05:00).
  - Örnek M2M ara katman platformundaki modüller: ID Management, Config Management, Service Application, Device Status Management, Device Authentication, Device Interface, Application Service Interface, Security Management, Remote Device Management, M2M Protocol I/F, Logging (ekrandan, 01:05:00).
- IoT verisinin yönetimi
  - Her mesajda aktarılması gereken: zaman damgası, verinin kendisi, verinin hangi sensöre ait olduğu. Konum bilgisi (ya da cihaz kimliği/IP ile eşlemesi) de önemlidir.
  - Bazı bilgiler belirli aralıklarla güncellenir (ör. batarya durumu), bazıları hiç değişmez (ör. örnekleme frekansı); değişmeyen bilgi tekrar tekrar alınmamalıdır.
  - Mesajlaşma protokolleri: MQTT yaygın; CoAP rakibidir. Henüz oturmuş, standart bir çözüm yoktur.
  - Veri biçimi: XML ve JSON; M2M haberleşmede en çok JSON kullanılır.
  - Saklama: genellikle NoSQL (ör. MongoDB) veritabanları; büyük veri tarafında Hadoop.
  - Güvenlik ve mahremiyet: veri yalnız korunmamalı, aynı zamanda karartılmalı (anonimleştirilmeli); hangi eve ait olduğu bilinmemelidir.
- İnternetin evrimi ve IoT tanımları
  - Ağ → İnternet → Mobil İnternet → Mobil + İnsan + PC → Nesnelerin İnterneti (birbirine bağlı nesneler) (ekrandan, 01:15:00).
  - Slayt notu: IoT terimi ilk kez 1998'de Kevin Ashton tarafından kullanıldı, 2005'te ITU raporuyla resmîleşti (ekrandan, 01:15:00).
  - Tanım: "Things have identities and virtual personalities operating in smart spaces using intelligent interfaces to connect and communicate within social, environment, and user contexts." Veri → Bilgi → Bilgi birikimi → Bilgelik piramidi (Raw → Meaning → Context → Application) (ekrandan, 01:35:00).
  - İkinci tanım: IoT, standart iletişim protokollerine dayanan, tekil olarak adreslenebilen (uniquely addressable) birbirine bağlı nesnelerin dünya çapındaki ağıdır (ekrandan, 01:35:00).
  - "Anything, anyone, anytime, any place, any service, any network."
- IoT türleri ve kategorileri
  - Bilgi teknolojisi (PC, sunucu, sanallaştırma, yönlendirici, anahtar), kişisel teknoloji (tablet, akıllı telefon, akıllı saat, ev enerjisi/eğlencesi/kontrolü, medikal implantlar ve giyilebilirler), operasyonel teknoloji (endüstriyel kontrol sistemleri, SCADA, medikal makineler, kiosklar, üretim, bulut altyapısı, çevre izleme) (ekrandan, 01:40:00).
  - En çok yenilik görülen kategoriler (Venture Scanner grafiği): IoT Home 138, Health Care 101, Fitness 96, Lifestyle and Entertainment 90, Platform and Components 88 şirket (ekrandan, 02:05:00).
- Sanal sensörler
  - IP paketleri, ağ akışları ve cihaz kayıtları (log) da bilgi kaynağıdır: saldırı tespiti ya da çökme nedeni bulmak için kullanılır.
  - Takvim, mesajlar gibi kaynaklar sanal sensördür: toplantı sırasında telefonu sessize almak, mesajları sınıflandırmak, gelen numarayı rehberle eşleştirmek.
- Sensör ağı ile IoT farkları
  - Sensör ağında veri ağırlıklı olarak tek yönlü merkeze akar; IoT'de çift yönlü bir konuşma vardır.
  - Sensör ağları uygulama odaklıdır (application-specific), IoT insan odaklıdır (human-specific).
  - IoT cihazı sayılmak için eyleyici (actuator) ile bir eylem yapmak gerekir; eylem yoksa sensör ağından söz edilir.
- IoT'nin temel özellikleri (ekrandan, 02:10:00)
  - Zekâ (sensör verilerinin birleştirilmesi), mimari (olay güdümlü ve zaman güdümlü veri toplama; derste ayrıca sorgu tabanlı toplama), karmaşık sistem (sensör ve eyleyiciler), boyut (50-100 milyar cihaz), zaman (gerçek zamanlı işleme), mekân (konum bağlam farkında hesaplamada önemli), her şey hizmet olarak (everything-as-a-service).
- IoT cihazlarında işletim sistemi
  - Sensör düğümleri için bile Contiki ve TinyOS tasarlandı; ama işletim sistemi enerji ve kaynak maliyeti getirir.
  - Açık soru: IoT cihazları birden fazla iş yapacaksa sıfırdan yazmak yerine Android gibi mevcut sistemlerin seyreltilmiş sürümleri kullanılabilir. Otonom araçlar, bilgisayara yakın yapıları nedeniyle bu konunun en çok gündeme geleceği alandır.
- Bağlam (context)
  - Tanım: "Context is any information that can be used to characterise the situation of an entity. An entity is a person, place, or object that is considered relevant to the interaction between a user and an application, including the user and applications themselves." (ekrandan, 02:25:00)
  - Bağlam bilgisi ham sensör verisinin işlenmesiyle elde edilir; tutarlılığı denetlenir ve üst veri eklenir (ekrandan, 02:30:00).
  - Olaylar: kesikli (discrete; kapının açılması/kapanması, arabaya binme) ve sürekli (continuous; yağmurun yağması, araba yolculuğu).
  - Bağlam farkında sistem: bağlamı kullanarak kullanıcının görevine göre ilgili bilgi ya da hizmeti sunan sistem. Gereken dört özellik: edinme (acquisition), temsil (representation), iletme (delivery), tepki (reaction).
  - Bağlam modeli ve bağlam özniteliği (context attribute): öznitelik, modeli tanımlayan, kimliği, türü, değeri ve isteğe bağlı özellikleri olan elemandır (ekrandan, 02:35:00).
  - Bağlam kalitesi: geçerlilik (validity), hassasiyet (precision), güncellik (up-to-dateness) (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Ham veri yerine bilgi
  - Ham veriyi kullanmak tercih edilen bir yol değildir; veriyi işleyip anlamlandırmak, bilgi düzeyine getirmek gerekir. Uç bilişim ve yerinde işleme kavramları not edilmelidir.
- Az enerji, az veri
  - Bağlam bilgisi çıkarırken en az enerji tüketen ve en az veri toplayan sensör tercih edilmelidir. Tek pahalı sensör yerine üç ucuz sensör kullanmak daha akıllıcadır: hareket tanımada saatteki ivmeölçer, jiroskop ve manyetometre, evdeki kamera sisteminden daha akıllıca bir seçimdir.
- Sanal sensörler
  - Yalnız fiziksel sensörler değil, bilgi üreten her uygulama ya da birim (takvim, mesajlar, ağ paketleri) bağlam ekosisteminin bir sensörü olarak görülmelidir.
- IoT verisinde zorunlu alanlar
  - Zaman damgası, veri ve verinin hangi sensöre ait olduğu her turda mutlaka aktarılmalıdır; değişmeyen bilgi tekrar sorgulanmamalıdır.
- Bağlamı doğru tanımlamak
  - Bağlam iyi tanımlanmazsa sensörler de doğru seçilemez ve yapı kurulamaz.
- Araştırma alanları
  - Duygu farkında hesaplama, IoT mesajlaşma protokolleri, JSON'a alternatif veri biçimleri, sanallaştırma, sürüş analizi ve akıllı ulaşım açık araştırma konuları olarak gösterildi.

## Kısa Tekrar Notları

- Mobil hesaplamanın üç başlığı: iletişim, donanım, yazılım.
- 5G hedefi: yaklaşık 1 ms gecikme; otonom araçlar için kritik.
- Yaygın hesaplama: her an, her yerden, her cihazdan erişim; bir kişi N cihaz.
- Veri fazlalığına çözüm: yerinde işleme, uç bilişim.
- Küme başı dönüşümlü seçilirse enerji dengelenir, ağ ömrü uzar.
- Yinelenen sensör verisi aykırı değer tespitine yarar.
- Büyük veri: volume, velocity, variety, veracity.
- Ara katman: işletim sistemi ile uygulama arasında; IoT güvenliği ve erişim sorununu çözer.
- IoT mesajı: zaman damgası + veri + sensör kimliği (+ konum).
- Protokoller: MQTT, CoAP; veri biçimi JSON; saklama NoSQL.
- Sensör ağı: tek yönlü akış, uygulama odaklı, eylem yok. IoT: çift yönlü, insan odaklı, eyleyici var.
- Veri toplama: olay güdümlü, zaman güdümlü, sorgu tabanlı.
- Bağlam: bir varlığın durumunu tanımlayan her bilgi.
- Olaylar: kesikli ve sürekli.
- Bağlam farkındalığı: edinme, temsil, iletme, tepki.
- Bağlam kalitesi: geçerlilik, hassasiyet, güncellik.

## Detaylı Açıklamalar

- Bağlam farkında hesaplamanın temel fikri, cihazın çevresini insan gibi birden fazla kaynaktan algılaması ve buna göre davranmasıdır. Eskiden bu, ışık açık mı, kombi çalışıyor mu, sıcaklık düştü mü gibi standart sensör olaylarına dayanan çevresel zekâ (ambient intelligence) ile sınırlıydı. Bugün ortamı algılayan çok sayıda sensör olduğu için kısıtlar genişledi ve hedef insanın duygu durumunu da algılamaya kaydı. Çağrı merkezi görüşmelerinde sessizlik süresi, sesin yükselmesi, görüşmenin memnuniyetle bitip bitmediği gibi analizler bu yönün ilk örnekleridir.
- Yaygın hesaplamada her kişinin çok sayıda cihazı olması veri yönetimi sorununu doğurdu. Bulut bilişim dağıtık sistemlerin bugünkü adı gibi görülebilir, ama birebir aynı kavram değildir. İyi organize edilmezse aynı veri her cihazın yerelinde ayrı ayrı bulunur ve depolama dolar. Daha büyük sorun, sensör ağları ve IoT cihazlarının sürekli ürettiği veridir: görüntü çözünürlüğü ya da saniyedeki kare sayısı biraz artınca boyut çok büyür, bir ormana dağıtılmış sensörler aynı bölgeden aynı bilgiyi tekrar tekrar gönderir. Bu yüzden veri uç noktada işlenmeli, buluta yalnız anlamlı sonuç gönderilmelidir; bu hem bant genişliği hem maliyet açısından gereklidir.
- Sensör ağlarında küme başı yaklaşımı enerji kısıtından doğdu. Düğümler eşit kapasitedeyse küme başı görevi dönüşümlü olarak düğümler arasında devredilir; görevi devralan düğüm komşularına yeni bilgi olup olmadığını sorar ve veriyi toplamaya devam eder. Bu sayede her düğüm eşit enerji harcar ve ağ uzun süre kopmadan çalışır. Her düğümde her bilgi bulunmaz; düğümler yalnız kendi ölçtükleri bilgiyi küme başına, küme başı da ara düğümler üzerinden merkeze iletir.
- IoT'de cihaza doğrudan IP ile erişmek mümkün olsa da IPv4 adres alanı yetersizdir. Bugün NAT ile bir ağ geçidinin arkasındaki cihazlar farklı adreslenerek ara çözüm üretiliyor; servis sağlayıcılar NAT arkasına bir NAT daha koyuyor, bu da gecikme ve güvenlik sorunları getiriyor. Kalıcı çözüm IPv6'dır. Güvenlik tarafında ise ara katman, cihazların periyodik olarak bildirdiği veriyi toplayıp düzenleyen bir dağıtım merkezi gibi çalışır; uygulamalar tek tek cihazları değil ara katmanı sorgular.
- Standartlaşma IoT'nin en çok ihtiyaç duyduğu konulardandır. Akaryakıt istasyonlarında araçtan inmeden temassız ödeme örneğinde her banka ve operatör kendi yapısını kurduğunda uyumluluk sorunu çıkar; çözüm ortak protokollerdir.
- Sürüş analizi derste bağlam farkındalığının uygulama örneği olarak ele alındı. Sigorta şirketleri telefondan sürüş verisi toplayarak sürücünün ne kadar agresif kullandığına göre poliçe fiyatlandırıyor; ancak telefonun eldeki sallanmasını aracın sallanmasından ayırmak zor olduğu için ileride veri araç üzerindeki sensörlerden, CAN veri yolu üzerinden alınacak (devir, frene ve gaza basma şiddeti, yakıt tüketimi). Sürüş analizi yakıt tasarruflu sürüş önerisi, yoldaki kasis ve çukurların tespiti ve toplu taşıma araçlarının kullanım analizi için de kullanılabilir. Yolun mu sürücünün mü sorunlu olduğunu ayırmak ayrı bir araştırma problemidir.
- Derste anlatılan bir yorgunluk çalışmasında araçların ürettiği ivme ve kuvvet bilgisiyle ulaşım araçlarının ve rotaların yorgunluk düzeyi hesaplandı. Hava koşulları normal kabul edildiğinde uçak en az yorucu çıktı (yaklaşık 1'e 8 oranında daha konforlu), çünkü kalkış ve iniş dışında sabit hızla gidilir ve doğrusal ivme sıfıra yakındır. Raylı sistemler tekerlekli sistemlerden daha konforlu bulundu; karayolu titreşim, fren ve hızlanma nedeniyle en yorucudur. Buradan, yalnız süreye göre değil, dönüşü ve çukuru az, yol kalitesi yüksek yolları seçen bir "yorgunluk haritası" fikri çıkar.
- Kesikli ve sürekli olay ayrımı bağlam izlemede iki farklı iş gerektirir: sürekli olaylar için bağlamın devam ettiği güncel olarak denetlenir, kesikli olaylar için anlık gelişme tespit edilip bildirilir. Bağlam kalitesinde geçerlilik verinin kaynağına duyulan güveni (birden fazla kaynak varsa kaynakları puanlamayı), hassasiyet sensörün ölçüm inceliğini (ör. yüz tanımak için düşük çözünürlük yetmiyorsa yüksek çözünürlüklü kamera), güncellik ise karar anında en yeni verinin kullanılmasını anlatır; otonom araçta birkaç saniye önceki veriyle karar vermek kazaya yol açabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
