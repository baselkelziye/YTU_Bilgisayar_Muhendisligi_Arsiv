# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tanıtımı ve öğrencilerle tanışma (mezun olunan okul, çalışılan iş).
- Yazılım proje yönetiminin üç bileşeni: proje yönetimi bilgi ve deneyimi, genel yönetim bilgisi, yazılım mühendisliği teknikleri.
- Etkin proje yönetiminin 3P'si: insan (people), problem, süreç (process).
- Yazılım ölçümü (software metrics): doğrudan ve dolaylı ölçüm, işlev noktası (function point).
- Maliyet tahmin yöntemlerine kısa giriş.
- Proje yönetimi yol haritası (project management roadmap) ve PMI, PMBOK, PMP kavramları.
- Dersin işleyişi: vize, makale projesi, uygulama projesi, final.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bu ders yazılım mühendisliğinin üzerine kurulu bir derstir. Bilgisayar mühendisliği dışından gelenler Pressman'ın "Software Engineering" kitabını yan kitap olarak okumalıdır.
- "Ölçemediğimizi yönetemeyiz." Mühendislik yaklaşımının her adımında ölçme vardır.
- Yazılım geliştirmede en önemli kaynak insan kaynağıdır.
- Proje yöneticisinin yetkisi sınırlı, sorumluluğu çoktur. Kaynakları üst yönetimden almak zorundadır.
- Proje yönetimi yalnızca planlama demek değildir. Takip, kontrol ve kapanış da proje yönetimidir.
- Bilişim projeleri hem maliyetli hem de sonucu belirsiz projelerdir. Bu yüzden proje yöneticilerinin eğitimi önemlidir.
- Uygulama projesinde herkes aynı şablonu kullanmasın. TÜBİTAK, BAP, Sanayi Bakanlığı gibi farklı teklif formatları kullanılabilir.
- Makale projesi için seçilecek aday makaleler 2015 ve sonrasından olmalıdır.

## Kısa Tekrar Notları

- Yazılım proje yönetimi = proje yönetimi bilgisi (PMBOK) + genel yönetim bilgisi + yazılım mühendisliği teknikleri (SWEBOK).
- PMBOK: Project Management Body of Knowledge. SWEBOK: Software Engineering Body of Knowledge.
- 3P: People (insan kaynakları), Problem, Process (süreç).
- Yazılım geliştirme süreci: planlama, analiz, tasarım, gerçekleştirme, test.
- Doğrudan ölçüm: kod satırı sayısı (LOC), hız gibi doğrudan sayılan değerler.
- Dolaylı ölçüm: işlev, nitelik, karmaşıklık, etkinlik gibi özelliklerin birleşiminden hesaplanan değer (ör. function point).
- Maliyet tahmini: istatistiksel modeller, Delphi yöntemi (birkaç uzmana sorma), tek uzmana sorma, yazılımı ürüne veya üretim adımlarına göre bölerek tahmin.
- Proje yönetimi yol haritası: projenin tanımlanması ve anlaşılması, planlama, yürütme ve kontrol, kapanış.
- PMI: Project Management Institute. PMP: PMI'ın proje yöneticiliği sertifikası. Çevik (agile) projeler için ayrı bir sertifika da vardır.
- Değerlendirme: vize, makale projesi (sunum + makale), uygulama projesi (sunum + rapor), final.

## Detaylı Açıklamalar

### Yazılım proje yönetiminin bileşenleri

- **Proje yönetimi bilgi ve deneyimi:** Genel proje yönetimi kavramları PMBOK'tan alınır. PMBOK el kitabı ve web sayfası, proje yönetim ofislerinde geçerli güncel kuralları izler.
- **Yazılım mühendisliği teknikleri:** SWEBOK'tan gelen bilgilerle verilir.
- **Genel yönetim bilgisi:** Ekip kültürü geliştirme, organizasyon ve iş tasarımı, yetenek takibi, iş bölümü, toplantı ve yazışma yönetimi, üst yönetimle ve dış paydaşlarla iletişim.

### Etkin proje yönetimi: 3P

- **İnsan (People):**
  - Çalışanların seçimi.
  - Yeteneklerin yapılacak işle eşleştirilmesi.
  - Performans yönetimi, eğitim, kariyer geliştirme.
  - Ekip kültürünün oluşturulması.
- **Problem:**
  - Planlamadan önce projenin amacı belirlenir.
  - Hangi problemi çözdüğü, alternatif çözümler, teknik kısıtlar incelenir.
  - Fizibilite analizi bu kısımda yer alır.
- **Süreç (Process):**
  - Yazılım geliştirme sürecinin adımları: planlama, analiz, tasarım, gerçekleştirme, test.
  - Her adımda hangi işlerin yapıldığı, hangi tip çalışanların yüzde kaç oranla çalıştığı belirlenmelidir.
- Bazı kitaplar dördüncü bir P (proje, product) da ekler. Hoca genel olması için üçü üzerinde durdu.

### Yazılım ölçümü

- Mühendislik kelimesi "hendese"den, yani ölçmeden gelir.
- Mühendislik yaklaşımı yönetme, maliyet hesabı, planlama, modelleme, analiz, tasarım, gerçekleştirme ve bakımı kapsar. En çok öne çıkanlar tasarım ve ölçümdür.
- Yazılımda ölçülebilir hedef koymak zordur. Kullanım kolaylığı, güvenilirlik, bakım yapılabilirlik gibi kalite özellikleri doğrudan sayıyla ifade edilemez.
- Bu yüzden yazılım projelerinin gerçek maliyetini ve ürün kalitesini ölçmek zordur. Kalitede daha çok kullanıcıların belli bir kullanım süresinde karşılaşacağı hata olasılıklarına bakılır.
- **Doğrudan ölçüm:** Yazılımın büyüklüğü için kod satırı sayılır ("kaç bin satırlık yazılım").
- **Dolaylı ölçüm:** İşlev, nitelik, karmaşıklık ve etkinliğin birleşiminden hesaplanır.

### İşlev noktası (Function Point)

- Hesapta kullanılan sayımlar:
  - Kullanıcı giriş sayısı.
  - Kullanıcı çıktı sayısı.
  - Sorgu sayısı.
  - Dosya sayısı.
  - Dış arabirim sayısı.
- Her sayım bir ağırlık faktörüyle çarpılır. Ağırlık yazılımın karmaşıklığına göre değişir.
- Örnek: dosya sayısının ağırlığı basit yazılımda 7, orta karmaşıklıkta 10, karmaşık yazılımda 15'tir.
- Function point, sayılar ve ağırlık faktörlerinin toplamından elde edilir. Ayrıntısı ileriki derslerde görülecek.
- Büyüklük bilindiğinde, benzer büyüklükteki eski projelerin süre, maliyet ve kişi sayısı verilerinden yeni proje için tahmin yapılır.

### Maliyet tahmini

- İstatistiksel modeller: Eski projelerin verilerinden model geliştirilir ve yeni projenin maliyeti tahmin edilir.
- Delphi yöntemi: Birkaç uzmana soru sorularak tahmin yapılır.
- Tek uzman görüşü de kullanılabilir.
- Büyük bir yazılımın maliyetini bir anda tahmin etmek zordur. Yazılım ürüne veya üretim adımlarına göre bölünür. Her parçanın süresi ve maliyeti ayrı bulunur.
- İnsan kaynakları planlamasında ne kadar ve hangi türden kişinin çalışacağı ve organizasyonun nasıl olacağı belirlenir.

### Proje yönetimi süreç adımları (yol haritası)

1. **Başlangıç (project understanding / defining):**
  - Proje neden başlatıldı?
  - Hangi problemi çözüyor?
  - Yapılabilirliği nedir? Harcamalarını ne kadar sürede karşılar? Girmeye değer mi?
  - Proje yöneticisi bu aşamada belirlenir. Proje tanınır ve anlaşılır.
2. **Planlama:**
  - Hangi adımlarda gerçekleştirileceği.
  - Riskler, kısıtlar, varsayımlar.
  - İş adımlarına göre gereken insan gücü ve bunun tipi.
  - Yaklaşık maliyet.
  - PERT ve Gantt diyagramlarıyla zaman planı (hangi takvim adımında kimin çalışacağı).
3. **Yürütme ve kontrol (project running / project control):** Projenin plana göre gidip gitmediği izlenir.
4. **Kapanış:**
  - Projeden kazanımlar.
  - Risk takibinin nasıl gittiği.
  - Arşiv ve kazanım bilgilerinin kaydedilmesi.
  - Bitmiş projenin ölçülmesi.

- Proje ofisleri bunu bazen dört adımda toplar: giriş, planlama, yürütme ve izleme, kapanış.

### Müşteri ve kullanıcı ilişkisi

- Dış tedarikçiler, ürün alınan firmalar ve potansiyel kullanıcılar proje paydaşıdır.
- Başka bir şirkete yazılım geliştirildiğinde karşı şirket müşteridir.
- Aynı kurum içinde başka bir departmana geliştirildiğinde o departmanın yönetimi müşteri, çalışanları kullanıcıdır.
- Bu kişilerle yönetim ilkeleri çerçevesinde iletişim kurulmalıdır.

### PMI ve sertifikalar

- PMI (Project Management Institute) proje yönetimi alanında uluslararası bir kuruluştur. Türkiye'de de temsilciliği vardır.
- PMP sertifikası proje yönetimi uzmanlığını gösterir. Eğitim almak tek başına yetmez. Çalışılan proje sayısı ve süresi istenir, ayrıca sınav vardır.
- Bu dersin alınması PMP başvurusunda eğitim olarak gösterilebilir.
- Hoca, bu organizasyonun toplantılarında proje yöneticilerinin ağırlıklı olarak bilişim alanından geldiğini gözlemliyor.
- Standish Group'un farklı yıllardaki çalışmaları, bilişim projelerinde çok sayıda tamamlanmamış ve başarısız proje olduğunu göstermiştir. Son yıllarda yazılım mühendisliğine ve proje yönetimine verilen önemle durum iyileşmiştir.
- Çevik (agile) projeler arttığı için PMI çevik projeler için ayrı bir sertifika da vermektedir.

### Dersin içeriği

- Proje nedir, ne değildir? Genel proje yönetimi teknikleri ve araçları.
- Proje yönetimi yol haritasının adımları, yazılım projesi örnekleriyle.
- Yazılım ölçümü, maliyet tahmin yöntemleri, yazılım risk yönetimi.
- Konfigürasyon yönetimi ve sürüm yönetimi (release management).
- Bir öğrenci genel yönetim bilimine daha fazla ağırlık verilmesini istedi. Hoca bunun eksik bir konu olduğunu kabul etti. Mezunların çalıştığı kurumlardan da bu yönde geri bildirim geldiğini söyledi. Bu konuya ağırlık vereceğini belirtti.

### Dersin işleyişi ve değerlendirme

- Dönemin ilk 7-8 haftası hocanın anlatımıyla geçecek. Vize araya veya 8. haftaya konacak. Sonra makale ve uygulama projesi sunumları yapılacak.
- **Vize:** Anlatılan kavramlar üzerine olacak. Test mi klasik mi olacağı sınav yaklaşınca söylenecek.
- **Makale projesi:**
  - Dersin konusuyla ilgili bir makale seçilecek ya da konu birlikte belirlenecek.
  - Sunum ve makale yazımı olacak. Geçen dönemki kalite dersinde IEEE formatında yaklaşık 6 sayfalık makale istenmişti; bu derste de benzer bir çalışma istenecek.
- **Uygulama projesi:**
  - Bir proje yönetim programıyla bir yazılım projesinin planlama ve takip aşaması yürütülecek. Sunum ve rapor hazırlanacak.
  - Proje yönetim ofisi gibi çalışılıp proje yönetimi teknikleri gösterilecek.
  - MS Project benzeri bir araç kullanılabilir. Trello daha çok çevik süreçte adımları takip etmeye yarar.
  - Çıktı bir proje teklifi olabilir: bitirme projesi için TÜBİTAK teklifi, şirkette başlayacak bir projenin planı, tez için BAP teklifi gibi. BAP genelde yalnızca Gantt şeması ister; burada planlama tarafı genişletilmeli.
  - Proje plan dokümanında olması gerekenler derste verilecek. IEEE'nin proje planlama standardı da vardır.
  - Proje çok büyük olmak zorunda değil. Bir bitirme projesini start-up olarak geliştirme planı da olabilir: risk yönetimi, pazar tahmini, kime satılabileceği.
  - Tüm uygulama projelerinde bulunması gereken asgari belgeler belirtilecek.
- **Final:** Dönem sonunda yapılacak.

### Ödev: makale araştırması

- Önümüzdeki haftaya kadar dergilerde ders konularıyla ilgili makaleler incelenecek.
- Kütüphanenin uzaktan erişimli dergileri kullanılabilir.
- Önerilen kaynaklar:
  - IEEE Software.
  - IEEE Transactions on Software Engineering.
  - IEEE Transactions on Engineering Management (genel proje yönetimi).
  - Proje yönetimi ve proje ölçümü konferansları.
- Aranacak konu: yazılım veya bilişim projelerinin yönetiminde yapay zekâ ya da bilgisayar mühendisliğindeki yeni yaklaşımlarla nasıl ilerlemeler sağlandığı. Eleman seçimi veya eğitim anlatan makaleler istenmiyor.
- Konu belirleme için ilk üç hafta süre verilecek. Uygulama projesi konusu da düşünülmeli.

### Gelecek ders

- Proje nedir, ne değildir?
- Proje başarı faktörleri.
- Proje yönetimi yol haritası adımlarının ayrıntılı tanıtımı.

### Ders sonrası notlar

- Altyazıda "SVEVOK" geçen yer SWEBOK (Software Engineering Body of Knowledge), "Presman" Pressman, "ecel projeler" çevik (agile) projelerdir.
- Bir öğrenci "PMBOK sertifikası" dedi. PMBOK bir bilgi kılavuzudur, sertifika değildir. Kastedilen PMI'ın PMP sertifikasıdır. Hoca da PMP sertifikasından bahsetti. Çevik projeler için PMI'ın ayrı sertifikası PMI-ACP'dir.
- Ders başında yaşanan ekran paylaşımı sorunu nedeniyle ilk slayt anlatımı kesildi ve yeniden başlandı (yaklaşık 00:15-00:21). Bu aralığın bir kısmı altyazıda yok.

**Not:** İsterseniz bu kayıtları NotebookLM gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
