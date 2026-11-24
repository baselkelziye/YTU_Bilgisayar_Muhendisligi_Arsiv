# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin odak noktası: yazılım geliştirme yaşam döngüsü
  - Yazılım mühendisi, yazılımın bir fikir olarak doğduğu andan emekliye ayrıldığı ana kadar sürecin her aşamasında görev alabilir.
  - Ders, bu sürecin adımlarının hangi etkinliklerle ve nasıl yürütüleceği üzerine kuruludur; ders notlarındaki konu sırası da bu döngüyü izler.
  - Dersin yaklaşık %40-45'i teorik, %55'i uygulamalı kısımdır. Uygulamalı kısım çözümleme (analiz), tasarım ve sınamadır (test). Bir çözümleme ya da tasarım sorusunun tek bir doğru çözümü yoktur.
- Temel kaynaklar (ekrandan, 00:55:00)
  - Roger S. Pressman, *Software Engineering: A Practitioner's Approach*, 8. baskı.
  - Craig Larman, *Applying UML and Patterns: An Introduction to OOAD and Iterative Development*, 3. baskı.
  - Ian Sommerville, *Software Engineering*, 10. baskı; Martin Fowler, *UML Distilled*, 3. baskı.
  - *UML Distilled*, UML'in yanında nesneye yönelik modelleme dersleri de verir. Larman'ın kitabı daha kapsamlıdır: UML'in yanında tasarım kalıplarını da öğretir ve aynı proje üzerinde birden fazla yineleme (iterasyon) gösterir. Kütüphanedeki *UML 2.0 in a Nutshell* e-kitabı bazı bölümler için Larman'ın yerine kullanılabilir.
- Yazılımın tanımı (ekrandan, 01:15:00)
  - Yazılım, herhangi bir boyuttaki, herhangi bir tür donanımda çalışan bilgisayar programı VE basılı ya da elektronik ortamdaki her tür dokümanı içeren üründür.
  - Dokümanlar yazılım geliştirme ekibine (teknik belgelendirme) ya da son kullanıcıya (kullanıcı belgelendirmesi) yönelik olabilir.
  - Yazılım bir üründür, ama başka ürünler geliştirmeye yarayan bir araç da olabilir (ör. IDE'ler, UML şeması çizen araçlar, takım içi görev atama ve planlama yazılımları).
- Yaşam döngüsü ve yazılımın yetersizleşmesi
  - Yaşam döngüsü: yazılımın bir fikir olarak doğmasından kullanım dışı bırakılmasına kadar geçen süreç.
  - Yazılım fiziksel bir ürün olmadığı için aşınmaz, ama zamanla yetersizleşebilir.
  - Değişim kaçınılmazdır; değişiklikler yeni hatalar doğurabilir, yeni hatalar tam düzeltilmeden yeni değişiklikler gerekebilir.
  - Çözüm: yazılım mühendisliği ilkelerine uyularak daha iyi tasarlanmış yazılım.
- Yazılım türleri (ekrandan, 01:25:00 ve 01:40:00)
  - Sistem yazılımı: diğer programlara hizmet sunmak üzere hazırlanan programlar (derleyiciler, işletim sistemleri, sunucu sanallaştırma yazılımları, Linux pencere yöneticileri vb.).
  - Mühendislik / bilimsel yazılım: mühendislik ve bilimsel hesaplamalar için; büyük hacimli verilerle uğraşır ("numara öğütmek / number crunching").
  - Gömülü (embedded) yazılım: donanımla çok sıkı ilişkilidir, denetim amaçlıdır, gerçek zamanlıdır.
  - Uygulama yazılımı: farklı müşterilerin kullanabileceği genel amaçlı yazılımlar; product-line, shrink-wrapped, (commercial) off-the-shelf (COTS) diye de anılır. İlgili standart: TS/BS ISO/IEC 25051 COTS Yazılım Ürünleri standardı.
  - Kurumsal yazılım: belirli ticari iş gereksinimlerine yöneliktir, iş süreçleri bilgisini içermelidir, genellikle müşteriye özel tasarlanır ve zamanla "eski yazılım" haline dönüşür.
- Eski yazılım (legacy software) (ekrandan, 02:10:00)
  - İş sürecinin önemli bir parçası olan ve çok uzun süredir kullanılan yazılımlar.
  - Olumsuzluklar: eksik/hatalı dokümantasyon, zamanla karmaşıklaşmış kod, esnek olmayan yapı, eski donanımla çok sıkı ilişki, yazılım mühendisliğindeki gelişmelerden yoksunluk nedeniyle düşük kalite.
  - Değiştirme nedenleri: iş alanındaki yeni gereksinimler, güncel sistemlerle birlikte çalışabilmesi için uyumluluk kazandırılması, donanımın ömrünün dolması nedeniyle daha güncel ortama taşınma gerekliliği.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yazılım yalnız program değildir
  - Teknik belgelendirme ve kullanıcı belgelendirmesi neredeyse program kadar önemlidir. Güncellenmemiş dokümantasyon, işi kolaylaştıracağına zorlaştırır.
- "Yazılım mühendisliğinde değişmeyen tek şey değişimdir"
  - Hatalar, yan etkiler, pazar koşulları ve kanun/yönetmelik değişiklikleri yazılımı değişmeye zorlar. Değişiklikler biriktikçe kod en iyi tasarımdan uzaklaşır; bu süreç bakım aşamasıdır.
- Yazılım bir ekip işidir
  - Ayrıntılı ve karmaşık bir iştir; tek bir kişinin birkaç haftada çıkardığı bir iş gibi düşünülmemelidir.
- Gömülü yazılımda yeniden kullanım sıfır kabul edilmelidir
  - Benzer bir donanım için bile (ör. kısa menzilli füzeden orta menzilli füzeye) yazılım büyük ölçüde baştan yazılır; proje planı ve süre kestirimi buna göre yapılmalıdır.
- Gerçek zamanlı yazılımda hız, bilimsel yazılımda hassasiyet önceliklidir
  - Bilimsel hesaplama saatler, günler sürebilir; önemli olan doğruluktur. Gerçek zamanlı sistemde milisaniyelik kararlar gerekir; hassasiyetten çok hızlı başarım önemlidir.
- Standartları bilmek ve kütüphaneden erişmek
  - Standartlara uymak bileşen tümleştirmeyi kolaylaştırır, kaliteyi yükseltir, iyi tanımlı süreçle daha az çabayla daha iyi iş çıkarmayı sağlar ve uluslararası müşterilerle çalışmanın önünü açar. Ciddi bilgilere erişim için kütüphaneler kullanılmalıdır.
- Eski yazılımdan geçiş planlı ve kademeli yapılmalıdır
  - Belirli bir süre işlemler eski ve yeni sistemde paralel yürütülür; yeni sistem gerçek veriyle doğrulandıktan sonra eski sistem kapatılır.

## Kısa Tekrar Notları

- Yazılım = program + basılı/elektronik her tür doküman.
- Yaşam döngüsü: fikir olarak doğmasından kullanım dışı bırakılmasına kadar.
- Yazılım aşınmaz, yetersizleşir; değişim kaçınılmazdır.
- Sistem yazılımı: başka programlara hizmet eder; hizmet verdiği şeydeki değişikliklerden (ör. yeni Java sürümü ve derleyici) çok etkilenir.
- Mühendislik/bilimsel yazılım: büyük veri, number crunching, doğruluk öncelikli, alan uzmanlarıyla birlikte geliştirilir.
- Gömülü yazılım: donanıma sıkı bağlı, denetim amaçlı, gerçek zamanlı, hız öncelikli, yeniden kullanımı çok düşük.
- Uygulama yazılımı: genel amaçlı; product-line, shrink-wrapped, COTS; modüllerden oluşur, kod yeniden kullanımı kolaydır.
- TS/BS ISO/IEC 25051: COTS yazılım ürünleri standardı; numaradan sonra `:yıl` gelebilir, en yeni yıl tercih edilir.
- Kurumsal yazılım: iş süreci bilgisi + müşteriye özel tasarım; alan uzmanı ya da dış danışman gerekir.
- Eski yazılım: 5 olumsuzluk, 3 değiştirme nedeni; geçiş paralel çalıştırma ile kademeli yapılır.
- Akademik ve teknik bilgi için e-dergi veri tabanları: ACM ve IEEE.

## Detaylı Açıklamalar

- **Yazılımın neden yetersizleştiği.** Bir kalem kullandıkça aşınır, ucu körelir, yayı bozulur. Yazılım böyle değildir: üzerinde çalıştığı donanım arızalanmadıkça ve ona ek sorumluluk yüklenmedikçe aşınmadan çalışır. Ama zamanla yetersiz kalır. Birinci neden hatalardır: geliştirme zor bir iş olduğu için sınama aşamasında bulunamamış hatalar sonradan ortaya çıkar, düzeltmek için yapılan değişiklikler başka yerlerde beklenmedik yan etkiler doğurur. İkinci neden problemin kendisinin değişmesidir: bir süreci izleyen ya da raporlayan bir bilgi sistemi, pazar koşulları ya da kanun ve yönetmelikler değişince bu değişikliklere uymak zorundadır, yoksa müşteri onu kullanmayı bırakır. Bu değişiklikler biriktikçe kod en iyi tasarımdan uzaklaşır. Bu çabayı ve maliyeti azaltıp kârı artırmanın yolu, yazılım mühendisliği ilkeleriyle daha iyi tasarlanmış yazılımdır.
- **Yazılım türlerini neden öğreniyoruz.** Türlerin kategorizasyonu için herkesin kabul ettiği bir standart yoktur. Ama yazılım süreci gereksinimlerin belirlenmesiyle başlar; oradan çözümleme modeli, tasarım modeli, gerçekleme ve sınama gelir. Sürecin temelini gereksinimler belirlediği için, farklı yazılım türlerinin ortak gereksinimlerini bilmek kullanılacak süreci ürüne uyarlamak için önemli bir ilk bilgidir.
- **Mühendislik ve bilimsel yazılım örnekleri.** Bir binanın deprem, rüzgâr gibi dış etkilere dayanıklılığını hesaplayan statik analiz yazılımı; bir makine parçasının aşınmasını ya da ısınmasını hesaplayıp ısı haritası olarak gösteren yazılım; gök cisimlerinin hareketini ya da bir reaktördeki nükleer tepkimeyi modelleyen simülasyonlar. Ortak noktaları çok büyük hacimli, yorumlanmamış veriyi alıp "bu parça 800 saat sonra kırılır mı" gibi küçük hacimli, değerli bir bilgi üretmeleridir. Bu yüzden konu uzmanlarıyla birlikte geliştirilirler; kimi zaman da bilim insanları kodlamayı öğrenip yazılımı kendileri yazar.
- **Gömülü ve gerçek zamanlı yazılım örneği.** Asansör kontrol yazılımı, yeni yıkama programları yüklenebilen akıllı çamaşır/bulaşık makineleri gömülü yazılıma örnektir. Hoca gerçek zamanlılığı ısı güdümlü füze örneğiyle anlattı: füzenin, kaçınma manevrası yapan uçağı izlemesi, yeni bir yaklaşma rotasını (intercept course) hızla hesaplaması ve uçağın attığı parlak işaret fişeklerini (flare) ayırt edip yine uçağa yönelmesi gerekir. Füze uçağa tam isabet etmek zorunda değildir; yeterince yaklaşıp patladığında saçılan parçalar yeterlidir. Bu yüzden milimetrelik hassasiyetten çok milisaniyelik hız önemlidir. Aynı örnekte, menzil değişince yakıt miktarı, boy, ağırlık ve kontrol yüzeyleri değiştiği için eski güdüm yazılımının ancak çok küçük bir kısmı yeniden kullanılabilir.
- **Uygulama yazılımının lakapları.** Ofis uygulamaları, kelime işlemci, hesap tablosu, çek-senet ve cari hesap uygulamaları, hastane/postane/kütüphane otomasyonları uygulama yazılımıdır. *Product-line* denmesinin nedeni, bu yazılımların modüllerden (ör. kütüphane otomasyonunda ödünç verme, kataloglama, süreli yayınlar modülleri) oluşması ve fabrikadaki üretim hattı gibi modül modül geliştirilebilmesidir; benzer alandaki eski kod az değişiklikle yeniden kullanılabilir. *Shrink-wrapped* (naylon ambalajlı) ve *commercial off-the-shelf* adları, internetten dağıtım yaygınlaşmadan önce bu yazılımların mağaza rafından kutu içinde satın alınmasından gelir. Off-the-shelf adı, uygulamanın bazı parçalarının hazır açık kaynak çerçevelerden ya da kataloglardan seçilen bileşenlerle kurulabileceğine de işaret eder.
- **TS/BS ISO/IEC 25051 standardının adı.** ISO ve IEC birlikte çalışarak bu standardı oluşturmuştur. TS öneki Türk Standartları Enstitüsü'nün standardı kabul edip Türkçeye çevirdiğini, BS öneki İngiliz standartlar kurumunun kabul ettiğini gösterir (İngiltere'nin ölçü birimleri farklı olduğu için standartlar oraya çevrilerek uyarlanır). 25051 standardın numarasıdır; ardından iki nokta üst üste ve yıl gelebilir. Birden fazla yıl varsa en yeni olan kullanılmalıdır.
  - Ders sonrası not: Hoca ISO'yu "International Standards Organization" diye açtı; kurumun resmî adı büyük olasılıkla International Organization for Standardization'dır. Hocanın adını hatırlayamadığı IEC ise büyük olasılıkla International Electrotechnical Commission'dır.
- **Kurumsal yazılım.** Bir bankanın bireysel emeklilik fon yönetimi uygulaması, bir telekom operatörünün faturalama sistemi, büyük bir üreticinin kurumsal kaynak planlama (ERP) yazılımı örnektir. Her kurumun iç süreçleri, ülkesinin yasalarına ek olarak o kadar farklıdır ki ortak bir payda kodlayıp çeşitlendirmek çoğu zaman mümkün olmaz; yazılım müşteriye özel tasarlanır. Uzun süre aynı alanda çalışan bir yazılım evi zamanla farklı müşterileri kapsayan bir ürün geliştirebilir. Farklı alanlarda proje yapan yazılım mühendisi de bu alanların temel bilgisini ve jargonunu edinir; "bilgisayar mühendisi her şeyden anlar" sözü buradan gelir.
- **Eski yazılımın olumsuzlukları.** Dokümantasyon, kod değiştikçe zaman ve maliyet baskısıyla güncellenmez; güncel dokümantasyon hatanın yerini kabaca bulmayı kolaylaştırırken bayat dokümantasyon zaman kaybettirir. Kod, öngörülemeyen değişikliklerle "yamalı bohça"ya döner; açıklama yazılmadan yorum satırına alınmış eski kod parçaları anlaşılırlığı daha da azaltır. Eski donanıma (ör. IBM AS/400 gibi ana çerçeve sistemler, Fortran ya da COBOL kodu) bağımlılık, yedek parça ve teknik servis bulunamaması riskini getirir; hoca, eski donanımı toplayıp çalışır hâle getirerek ona muhtaç kurumlara yüksek fiyata satan firmalar bulunduğunu anlattı.
- **Eski yazılımın değiştirilme nedenleri.** Yeni gereksinimler eski yazılıma eklenemeyebilir ya da eski dili bilen uzman bulmak zordur: pandeminin başında ABD'de yardım ödemelerini hesaplayacak sistemlerin ana çerçevede COBOL ile yazılmış olması, emekli programcıların yeniden çağrılmasına yol açtı. İnternetin olmadığı dönemde yazılmış bir sistemi web ya da mobil üzerinden açmak için ara katmanlar gerekir ve bunlar verimsizdir. Desteği kesilmiş bir veri tabanına (ör. FoxPro) bağlı yazılım daha güncel bir ortama taşınmak zorundadır. Bu durumlarda geçiş acil değil planlı yapılmalı, bir süre iki sistem paralel çalıştırılmalı, sonra kademeli olarak yeni sisteme geçilmelidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
