# Ders 3 Çalışma Özeti

Tarih: 4 Haziran 2026 Perşembe. Online ders, dönemin son konu anlatımı. Süre yaklaşık 1 saat 5 dakika. Slaytlar Prof. Dr. M. Fatih Amasyalı'nın ders notlarından ("YZ etik").

## Genel Konular

- Etik (ahlak) ve hukuk kavramları, aralarındaki fark.
- Yapay zekanın karar veren sistem olarak özel durumu: ölçek, kara kutu, önyargı, kültürel bağımlılık.
- Verilerdeki önyargı (bias) ve türleri. Önyargıyı azaltma yöntemleri.
- Korelasyon ile nedensellik (causality) karışıklığı.
- Sorumluluk: Yapay zekanın yanlış kararında suçlu kim?
- Açıklanabilirlik (explainability), kara kutu sorunu ve GDPR.
- Yapay zeka ve işsizlik: karamsar ve iyimser senaryolar, meslek risk haritası.
- Manipülasyon: sosyal medya algoritmaları, tıklama optimizasyonu, deepfake.
- Kişisel verilerin gizliliği ve sürekli izlenme.
- Avrupa Birliği Yapay Zeka Yasası (EU AI Act) ve etik ilkeler.
- Genel yapay zeka (AGI) ve otonom silahlar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hukuki olan her şey etik değildir. Yapay zekanın kararları hukuk ve etik açısından ayrı ayrı değerlendirilmelidir.
- Etik kurallar zamandan ve kültürden bağımsız değildir. Kölelik bir zamanlar hukukiydi.
- Bir insanın önyargısı tek bir şirketle sınırlı kalır. Aynı önyargı yapay zekaya öğretilirse milyonlarca karara yayılır.
- Model, verideki önyargıyı da öğrenir. Önyargılı veriyle eğitilen yapay zeka önyargılı karar verir.
- Birlikte değişen şeyler her zaman neden-sonuç ilişkisi içinde değildir. Korelasyonu nedensellik sanmak yapay zekayı yanıltır.
- Yalnız genel ortalama başarıya bakmak yeterli değildir. Her alt grupta hata oranı ayrı ayrı ölçülmelidir.
- İnsanların yapay zeka kararına itiraz etme ve açıklama talep etme hakkı vardır.
- Kullanıcı olarak sözleşme ve veri paylaşım metinlerini okuyun. Haklarınızı ve sorumluluklarınızı bilin.

## Kısa Tekrar Notları

- Etik: iyi ve kötünün ne olduğuna dair, genellikle sözlü ve geleneksel ilkeler.
- Hukuk: devletlerin veya ülkeler arası anlaşmaların yazılı kuralları.
- Yapay zekanın özel durumu:
  - ölçek: milyarlarca karar,
  - kara kutu: kararın gerekçesi açıklanamıyor,
  - önyargı,
  - hız ve maliyet avantajı.
- Önyargı türleri:
  - tarihsel (historical): geçmişteki ayrımcılık veriye yansır,
  - temsil (representation): bazı gruplar az temsil edilir,
  - ölçüm (measurement): bazı gruplar için veri daha hatalı ölçülür,
  - toplama (aggregation): farklı gruplar tek modelle temsil edilir.
- Önyargıyı azaltma: dengeli (temsili) veri toplama, alt grup testleri, adillik metrikleri (eşit hata oranı, demografik parite, eşit fırsat).
- Açıklanabilir yapay zeka araçları: LIME, SHAP, Grad-CAM.
- Önyargı ölçme araçları: IBM AI Fairness 360, Google What-If Tool, Microsoft Fairlearn.
- AB'nin güvenilir yapay zeka için 7 ilkesi: insan gözetimi, teknik sağlamlık ve güvenlik, gizlilik ve veri yönetişimi, şeffaflık, çeşitlilik ve adalet, toplumsal ve çevresel refah, hesap verebilirlik.
- EU AI Act cezası: 35 milyon avroya veya yıllık cironun %7'sine kadar.

## Detaylı Açıklamalar

### Etik ve hukuk

- Varsayımsal örnek: Bir devlet "adı Ahmet olanlar tıp okuyamaz" diye bir yasa çıkarabilir. Bu hukuki olur ama etik olmaz.
- Tarihsel örnek: Endülüs'ün düşüşünden sonra İspanya'da Müslüman ve Yahudilerin Hristiyanlaştırılması ve Engizisyon mahkemeleri. Yargılamalar yazılı kurallara göre yapıldı, yani "hukuka uygundu", ama etik değildi.
- Kredi, işe alım, mahkeme kararı gibi konularda yapay zeka karar verebiliyor. Bu kararların hem hukuki hem etik olup olmadığı ayrıca sorgulanmalı.
- Kültürel bağımlılık: Bir yerde doğru kabul edilen şey başka bir yerde yanlış kabul edilebilir. Yapay zeka hangi kültürün etiğine göre karar verecek?

### Verilerdeki önyargı

- Bilmece: Baba ve oğlu kaza geçirir. Cerrah "Bu benim oğlum, ameliyat edemem" der. Çoğumuz cerrahın erkek olduğunu varsayarız. Oysa cerrah çocuğun annesidir. Meslek tahmininde cinsiyet kullanan bir model bu önyargıyı öğrenebilir.
- Sıradan şeyler yazıya geçmez: İnternette "sarı muz" ifadesi, "yeşil muz" veya "kırmızı muz"a göre az geçer. "Öldürdü" ifadesi "yemek yedi"den çok daha sık geçer. Bu verilerle eğitilen model dünyayı çarpık görür. Köpek insanı ısırırsa haber olmaz, insan köpeği ısırırsa haber olur.
- Amazon (2018): CV değerlendirme algoritmasının kadın adaylara düşük puan verdiği ortaya çıktı. Sistem kaldırıldı.
- Yüz tanıma (MIT, Gender Shades çalışması): Ticari sistemlerde açık tenli erkeklerde hata yaklaşık %1, koyu tenli kadınlarda yaklaşık %35. Nedeni dengesiz (imbalanced) veri seti.
- Kredi döngüsü: Kredi alamayan mahalle sakinlerinin kredi geçmişi oluşmaz. Model onlara düşük puan verir. Döngü kendini pekiştirir.
- Toplama önyargısı örneği: Kanserin alt türleri tek bir "var" sınıfına indirgenirse model "var" sınıfını iyi tanıyamayabilir.
- İsim önyargısı: Aynı CV'lerde "Emily" ve "Greg" gibi isimler, "Lakisha" ve "Jamal" gibi isimlere göre yaklaşık %50 daha fazla geri dönüş almış.
- COMPAS: ABD'de sanıkların yeniden suç işleme riskini tahmin eden sistem. Siyahi sanıklar beyazlara göre yaklaşık iki kat daha sık yanlışlıkla "yüksek riskli" etiketlenmiş. Hakimler bu skoru ceza kararında kullanıyordu.

### Korelasyon ve nedensellik

- Makine öğrenmesinde $y=f(x)$ fonksiyonu aranır. Bu, $x$'in değişiminin $y$'yi etkilediği varsayımıdır.
- Yazın dondurma ve terlik (veya klima) satışları birlikte artar. Aralarında nedensellik yoktur, ortak neden sıcaklıktır.
- Sahte korelasyon örnekleri:
  - 1990-2010 arasında internetin yaygınlaşması ve ağaçların azalması,
  - sosyal medyada kedi fotoğraflarının artması ve trafik kazalarının artması.
- Yoğun bakımda ölüm oranı yüksektir. Model "yoğun bakım ölüme yol açar" gibi ters bir neden-sonuç ilişkisi öğrenebilir.
- Belirli bir meslekteki insanlar ekonomik kriz yüzünden kredilerini ödeyemediyse, model o mesleği riskli sayabilir. Gerçek neden kriz olabilir.
- Doğru karar için nedensel çıkarım (causal inference) ve gerekirse alan uzmanı veya uzman sistem gerekir.

### Sorumluluk

- Uber (2018): Otonom araç bir yayaya çarptı ve yaya öldü. Suçlu kim: yazılımcı, üretici, araçtaki sürücü, düzenleme yapmayan devlet, yaya?
- Radyoloji örneği: FDA onaylı bir model kanseri gözden kaçırır, teşhis gecikir. Sorumlu FDA mı, yazılım mı, son kararı veren doktor mu?
- Olası sorumluluk türleri: ürün sorumluluğu, ihmal, ortak sorumluluk.
- Bu alanda bilinen ilk kapsamlı düzenleme, risk seviyesine göre kademeli olan AB Yapay Zeka Yasası'dır.

### Açıklanabilirlik

- Derin öğrenme modelleri çok sayıda parametreyle karar verir. Örneğin bir CNN'de filtre ve ağırlıkların neden o değerde olduğu açıklanamaz.
- Neden gerekli?
  - Hukuki hak: GDPR kapsamında kişi, hakkındaki otomatik karar için açıklama talep edebilir.
  - Güven: Doktorun yapay zekayla koyduğu teşhise ne kadar güvenebilirim?
  - Hata ayıklama: Önyargı ancak modelin nasıl karar verdiği görülünce tespit edilebilir.
  - İtiraz hakkı.
- Banka örneği: Kredi kartı limit artırma talepleri "değerlendirmemiz sonucunda reddedilmiştir" diye, gerekçesiz reddedilebiliyor. Hoca kendi yaşadığı bir hatalı ret örneğini anlattı; bankayla yazışınca sistem hatası düzeltilmiş.
- Araçlar:
  - LIME: her tahmin için yerel doğrusal açıklama üretir.
  - SHAP: her özelliğin katkısını oyun teorisiyle (Shapley değerleri) hesaplar.
  - Grad-CAM: görüntü modelinin görüntüde nereye odaklandığını gösterir.
- AB Yapay Zeka Yasası (2024), yüksek riskli sistemler için açıklanabilirlik, insan denetimi ve kayıt tutmayı zorunlu kılıyor.

### Yapay zeka ve işsizlik

- Karamsar senaryo: Rutin işlerin çoğunu yapay zeka ve robotlar devralır. Robotu tamir eden robot olunca insana neredeyse gerek kalmaz. Bazı ülkeler vatandaşlık maaşı (temel gelir) gibi düzenlemeler planlıyor.
- İyimser senaryo (tarihsel örüntü): Matbaa, dokuma makinesi, biçerdöver ve sanayi devrimi eski meslekleri yok etti ama yenilerini yarattı.
- Hocanın görüşü: Tarihsel örüntü bu kez tekrar etmeyebilir. Çünkü yeni yaratılacak görevlerin çoğunu da makineler devralabilir.
- Risk haritası:
  - Yüksek risk: veri girişi, belge sınıflandırma, rutin muhasebe, çağrı merkezi.
  - Orta risk: radyoloji okuma (yapay zeka okur, uzman kontrol eder).
  - Düşük risk: empatik bakım, liderlik, yaratıcı tasarım, karmaşık müzakere, sahne sanatları.
  - Yeni meslekler: prompt mühendisi, yapay zeka eğiticisi. Bunlar da ileride devralınabilir.
- Asıl soru: Dönüşümün yükünü kim taşıyacak, kim ne kaybedip ne kazanacak?

### Manipülasyon

- Stuart Russell'a göre öneri algoritmaları, insanların ne istediğini öğrenmek yerine insanları daha tahmin edilebilir hâle getirerek hedefini optimize etti. İnsanlar bireysellikten uzaklaşıp yönlendirilebilir hâle geldi.
- Türler:
  - ticari: "X'i alma, Y'yi al",
  - siyasi: "A partisine değil, B'ye oy ver",
  - nefret politikaları.
- Tıklama oranı optimizasyonu: Hedef, kullanıcının platformda en uzun süre kalması. Hoca, Turkcell ile yaptığı doktora çalışmasında (2020) bir müzik uygulaması için akustik özelliklere dayalı müzik öneri sistemi geliştirdiğini anlattı.
- Cambridge Analytica: 87 milyon Facebook kullanıcısının verisi izinsiz alındı, psikografik profiller çıkarıldı. Bu profillerin ABD seçiminde kullanıldığı ileri sürüldü.
- Deepfake: Ses, görüntü, video ve metin gerçeğinden ayırt edilemeyecek kadar iyi üretilebiliyor. Hong Kong'da bir finans çalışanı, sahte bir video konferansta "CFO"nun talebiyle yaklaşık 25 milyon dolar transfer etti.

### Kişisel veriler ve gizlilik

- Ham veri: tıklanan haberler, konum, alışveriş geçmişi, uyku saatleri, ziyaret edilen sayfalar.
- Target örneği: Alışveriş alışkanlıklarından hamile müşterileri tespit eden bir model kurdu. Bir baba, kızına gelen hamilelik ürünleri reklamlarından durumu öğrendi.
- Sigorta örneği: Bazı sigorta şirketleri Instagram paylaşımlarına göre prim belirlemek istiyor. Sigara içerken poz veren kişiye yüksek prim, koşarken fotoğrafı olana düşük prim gibi. Kullanıcılar da bu durumda yapay zekayı yanıltmaya çalışabilir.
- Olması gerekenler:
  - verinin hangi amaçla ve nasıl kullanılacağı açıkça söylenmeli,
  - kişi kendi verisini görebilmeli ve silebilmeli (ör. Google hesabı),
  - üçüncü taraflarla paylaşım için ayrıca onay alınmalı.
- Sağlık verileri erken teşhis için faydalıdır. Ama sigorta şirketleri, işverenler veya devletle sınırsız paylaşılmamalı. Gerekirse maskelenmiş veya anonimleştirilmiş paylaşılmalı.
- Çin'deki sosyal kredi sistemi: Trafik ihlali, kredi ödemesi gibi davranışlara göre puan verilir. Puanı düşenler uçuş ve tren yasağı gibi kısıtlamalarla karşılaşabilir. Hoca bunu Orwell'ın *1984*'ündeki "Büyük Birader"e (Big Brother) bağladı.

### AB Yapay Zeka Yasası

- Yasaklanan sistemler:
  - sınırlı istisnalar dışında, halka açık alanlarda gerçek zamanlı uzaktan yüz tanıma,
  - sosyal skor sistemleri,
  - bilinçaltı manipülasyon teknikleri.
- Sıkı denetime tabi alanlar: sağlık, eğitim, istihdam, yargı, kritik altyapı. Bu alanlarda risk değerlendirmesi, şeffaflık ve insan denetimi zorunlu.
- Yaklaşım farkları: AB risk bazlı (önce temel hakları korumak için), ABD sektör bazlı, Çin devlet yönlendirmeli.
- Türkiye'de Kişisel Verileri Koruma Kanunu (KVKK) GDPR'a benzer korumalar sağlıyor. Yapay zekaya özel düzenleme çalışmaları sürüyor.

### Geliştiriciler ne yapabilir?

- Yalnız k-katlı çapraz doğrulamanın ortalamasına bakmayın, alt grup testleri yapın.
- Eğitim verisinin nereden geldiğini belgeleyin.
- Model kartı (model card) yazın: amaçlar, kısıtlar ve başarısızlık senaryoları.

### Genel yapay zeka ve geleceğe dair sorular

- Genel amaçlı bir yapay zekanın (AGI) değerlerini kim belirleyecek?
- Yapay zekanın hakları olacak mı?
- Otonom silahlar ("ölüm robotları"): Yaklaşık 30 ülke yasaklanmasını istiyor, uluslararası bir anlaşma henüz yok.
- Yapay zekanın hedefleri insanın etik ve ahlaki değerleriyle uyumlu olmalı. Umut veren gelişmeler: AB yasası, açıklanabilirlik araçları, artan yapay zeka okuryazarlığı.

### Ders sonrası notlar

- Endülüs örneğinde Gırnata (Granada) 1492'de Kastilya ve Aragon'un ortak hükümdarları Ferdinand ve Isabella'ya düştü. İspanyol Engizisyonu 1478'de, Gırnata'nın düşüşünden önce kuruldu ve ilk hedefi Hristiyanlığa geçmiş Yahudilerdi.
- Hong Kong deepfake dolandırıcılığı (Arup şirketi) 2023'te değil, Ocak-Şubat 2024'te oldu. Transfer edilen tutar yaklaşık 200 milyon Hong Kong doları, yani yaklaşık 25 milyon ABD dolarıdır.
- Stuart Russell'ın sözü *Human Compatible* kitabından (2019). Hoca 2020 dedi.
- GDPR'da "açıklama hakkı" açıkça yazılı bir madde değildir. 22. madde otomatik kararlara karşı insan müdahalesi ve itiraz hakkı tanır. 13-15. maddeler "işleme mantığı hakkında anlamlı bilgi" verilmesini ister.
- Gender Shades çalışmasında (Buolamwini ve Gebru, 2018) en yüksek hata koyu tenli kadınlarda %34,7, en düşük hata açık tenli erkeklerde %0,8'dir.
- İsim önyargısı çalışması Bertrand ve Mullainathan'ın 2004 tarihli deneyidir. Karşılaştırılan isimler beyaz ve siyahi Amerikalılarla özdeşleşen isimlerdir.
- COMPAS'ın açılımı: Correctional Offender Management Profiling for Alternative Sanctions. Bulgular ProPublica'nın 2016 analizine aittir.
- Hocanın "IBM Payness" dediği araç IBM AI Fairness 360'tır. LIME ve Grad-CAM'in yanında anlatılan oyun teorisine dayalı araç SHAP'tir.
- Çin'deki sosyal kredi sistemi tek ve merkezi bir puan sistemi değildir; kurumlara ve şehirlere göre farklı uygulamalardan oluşur. "Yabancı marka telefon alınca puan düşer" iddiası belgelenmiş bir kural değildir.
- AB'nin 7 ilkesi, 2019'da yayımlanan "Güvenilir Yapay Zeka için Etik Yönergeler"den (Ethics Guidelines for Trustworthy AI) gelir. AB Yapay Zeka Yasası 1 Ağustos 2024'te yürürlüğe girdi; hükümleri kademeli olarak uygulanıyor.

### Duyurular

- Bu dersle dönemin konuları tamamlandı.
- Gelecek hafta büyük olasılıkla ders yapılmayacak; telafi sınavı olacak.
- Final sınavı vizeye benzer olacak: tüm konuları kapsayan, tek doğru cevaplı test. Ayrıntılar WhatsApp kanalından duyurulacak.
- Projelerin son günü bu dersin günüydü. Projeler kısa sürede asistanlara iletilecek.
- Etik slaytı daha sonra paylaşılacak. Önyargı araçları ve çevrim içi kurslar için slayttaki kaynaklar incelenebilir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
