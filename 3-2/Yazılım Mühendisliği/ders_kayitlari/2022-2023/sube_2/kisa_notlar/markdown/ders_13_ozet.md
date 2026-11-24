# Ders 13 Çalışma Özeti

## Genel Konular

- Yazılım proje yönetimine giriş
  - Yazılım projeleri önemli oranda başarısız olur. Zorluklar: yazılım geliştirmenin kendisi (zihinsel çaba), ölçek büyüklüğü (yazılım ölçeği, kişi ölçeği), kestirimdeki zorluklar, insanlarla çalışma, teknolojideki, gereksinimlerdeki, politik ve mali değişimler (ekrandan, 00:25:00).
  - Politik değişim yalnız ülke politikası değildir; şirket politikaları da projeyi en az onun kadar etkiler.
  - Proje yönetimi bu zorlukların çözümüne odaklanır. İlgi alanları önem sırasıyla: Kişiler, Ürün, Süreç, Proje.
  - Proje yönetimi disiplinler arasıdır: yazılım mühendisliği, problem alanı ve proje yönetimi bilgi ve deneyimi birlikte gerekir.
- Proje ölçeği (ekrandan, 00:30:00)
  - Küçük ölçekli: çok küçük (1-2 kişi, 1-2 ay), küçük (2-3 kişi, 2-3 ay); basit bir kullanıcı uygulaması tekniğiyle (ör. bir hesap tablosu) yönetilebilir.
  - Büyük ölçekli: 5-20 kişilik ekip, 2-3 yıl; çok sayıda alt sistem, başka sistemlerle tümleştirme gereksinimi; iş planlama ve kod yönetim uygulamaları zorunludur.
  - Uzun projeler çoğu zaman kendi içinde anlamlı fazlara bölünür; her faz ayrı bir proje gibi birkaç ay sürer.
  - Kod yönetim araçları sürümleri dondurup saklar; yeni kod smoke testi bozarsa demo, testi geçen önceki sürümle yapılabilir.
- Planlama yaklaşımları ve ilkeleri
  - Basitlik yaklaşımı: gelecekteki değişiklikler ayrıntılı planı çoğu zaman gereksiz kılar.
  - Geleneksel yaklaşım: plan bir yol haritasıdır; harita ne kadar ayrıntılıysa kaybolma olasılığı o kadar düşer.
  - Çevik yaklaşım: ön hazırlık gerekir, asıl harita proje ilerledikçe çizilir (ekrandan, 00:35:00).
  - İlkeler: sınırları belirle; müşteriyi planlamaya kat (öncelik, sınır ve zamanlamayı müşteri belirler, gerçekçilik için ekip pazarlık yapar); planlama yinelemelidir; bilgine dayanarak kestir; her aşamaya risk değerlendirmesi ekle; gerçekçi ol (ekrandan, 00:40:00).
  - Kısa vadeli planlar ince ayrıntılı, uzun vadeli planlar kaba ayrıntılı yapılır; zaman ilerledikçe kaba kısımlar inceltilir.
  - Kalite güvence eylemleri plana eklenir, değişikliklerin nasıl kabul edileceği sözleşmeye bağlanır, plan sürekli izlenir.
- Risk yönetimi
  - Sonradan (reactive) ve önceden (proactive) yaklaşım; derste proactive yaklaşım işlenir (ekrandan, 00:45:00).
  - Riskin uzlaşılan iki özelliği: olasılık (%100 kesin risk yoktur) ve kayıp.
  - Risk çeşitleri: proje riskleri (plan, zaman, bütçe, personel), teknik riskler (kalite ve zamanında bitirme; çözümleme, tasarım, gerçekleme, bakım), işletme riskleri (pazar, satış) (ekrandan, 00:50:00).
  - Risk tablosu: ID, ad, çeşit, olasılık, etki; olasılık-etki grafiği; seçilen riskler için risk bilgi sayfası (ekrandan, 00:55:00).
- Proje yönetiminde kişi etkenleri
  - Takım yöneticisi / teknik yönetici özellikleri (ekrandan, 01:20:00).
  - Teknik ekip, takım ruhu ve onu bozan etkenler (ekrandan, 01:25:00).
  - Takım yapıları: kapalı, rastgele, açık, eşzamanlı; takım içi ve takımlar arası resmi ve gayri resmi haberleşme (ekrandan, 01:35:00).
- Proje yönetiminde ölçüm
  - Proje ölçümü (teknik düzey, iç kalite) ve süreç ölçümü (yönetimsel düzey, dış kalite) (ekrandan, 01:40:00).
  - Kaliteyle ilgili etkenler, ölçüt toplama ve gizlilik düzeyleri (ekrandan, 01:45:00).
  - Süreç ölçütleri: hata sayısı, hata giderme etkinliği, doğruluk, bakım kolaylığı, güvenlik (ekrandan, 01:50:00).
  - Süreç ölçütlerinin kullanımı (ekrandan, 01:55:00).
- Maliyet tahmin yöntemleri
  - Bilirkişi takdiri, Delphi yöntemi, analiz yöntemi, istatistiksel modeller (Walston-Felix, COCOMO, PNR).

## Hocanın Özellikle Vurguladığı Kısımlar

- Proje yönetiminde ilk odak her zaman kişilerdir
  - Ürün, süreç ve proje ne kadar iyi yönetilirse yönetilsin, kişiler doğru yönetilemez, takım ruhu oluşturulamaz ve yeterince güdülenemezse proje başarısız olur. "Proje yönetimi" adına rağmen proje son sıradadır.
- Projenin sınırları belirlenmelidir
  - Örnek: Charles Babbage'ın Analitik Makinesi'nin tamamlanamamasının en büyük nedeni, sürekli yeni özellik eklenip tasarımın değişmesi, yani nerede duracağının bilinmemesidir.
- "Plan asla taşa yazılmaz"
  - Planlar değişecektir; planlama yinelemeli bir etkinliktir.
- Önemsiz riskler izlenmez
  - Olasılığı ve etkisi düşük riskleri izlemek ayrı bir çaba ister ve getirisi azdır ("attığın taş ürküttüğün kurbağaya değmez"). Olasılığı ve etkisi yüksek riskler mutlaka izlenir.
- Risk bilgi sayfasındaki işaretler ölçülebilir olmalı
  - "Bakım aşamasının ilk 6 ayında amorti oranının %50'nin altında kalması" gibi süresi, miktarı ve oranı belli işaretler öznel işaretlerden daha kullanışlıdır. Ara hedeflerde izleme yapıp önlem almak proaktiftir.
- En zor işleri hep aynı takıma vermeyin
  - Başarılı bir takıma sürekli en zor işler verilirse takım yıpranır ve uyumsuzlaşır ("çekici bile çok kullanırsan yıpranır").
- Ölçümler insanları utandırmak, övmek ya da tehdit etmek için kullanılmamalı
  - Bin satır başına hata sayısı en yüksek kişi, en zor işler ona verildiği için en yetenekli kişi olabilir; teknik yönetici kök nedeni araştırmalıdır.
- Ölçütler amaç değil araçtır
  - Ölçüme ayrılan çaba şirket ve proje boyutuyla orantılı olmalıdır; her ölçüt her projeye uymaz (ör. kalıtım kullanılmayan kodda kalıtım ağacı derinliği anlamsızdır).

## Kısa Tekrar Notları

- Proje yönetimi ilgi alanları (önem sırası): Kişiler > Ürün > Süreç > Proje.
- Küçük proje: 1-3 kişi, 1-3 ay. Büyük proje: 5-20 kişi, 2-3 yıl; iş planlama ve kod yönetim aracı zorunlu.
- Planlama yaklaşımları: basitlik, geleneksel, çevik. Küçük ve hızlı değişen projede basitlik, şelale ile yürüyen büyük projede geleneksel yaklaşım daha uygundur.
- Kısa vade ince ayrıntılı, uzun vade kaba ayrıntılı planlanır.
- Risk = olasılık + kayıp. Çeşitleri: proje, teknik, işletme.
- Risk tablosu: ID, ad, çeşit, olasılık, etki. Olasılık-etki grafiğinde sağ üst izlenir, sol alt izlenmez, diğer köşeler duruma göre seçilir.
- Risk bilgi sayfası: ID, ad, olasılık, etki, tür, açıklama, işaretler, önlemler.
- Takım ruhunu bozan etkenler: telaşlı iş ortamı, sık hayal kırıklığı ve başarısızlık, doğru yönetilemeyen süreç, belirsiz takım yapısı ve rolleri.
- Takım yapıları: kapalı (geleneksel hiyerarşi), rastgele (bireysel, yaratıcı), açık (demokratik), eşzamanlı (alt parçalara bölünen problem).
- Proje ölçümü: teknik düzey, iç kalite. Süreç ölçümü: yönetimsel düzey, dış kalite.
- Ölçüt gizliliği: bireysel ölçüt kişiye, takım ölçütü takıma, proje ölçütü tüm çalışanlara özel.
- $\text{HGE} = \dfrac{\text{TÖ}}{\text{TÖ} + \text{TS}}$; ardışık aşamalar için $\text{HGE}_i = \dfrac{A(i)}{A(i) + A(i+1)}$.
- Delphi: koordinatör, birbirinden habersiz bilirkişiler, yinelenen yazılı tahminler, ortak değere yakınsama.
- Analiz yöntemi: ürün ve üretim analiz kartları, aşağıdan yukarı toplama; ağırlıklı tahmin $\dfrac{a + 4m + b}{6}$.
- İstatistiksel modeller: $y = a x^b$; $a$ ve $b$ en küçük kareler yöntemiyle bulunur.
- Temel COCOMO: $H = a \cdot KLOC^b$, $T = c \cdot H^d$. Orta COCOMO: EAF çarpanı (0,90-1,40).
- PNR: teknoloji katsayısı $C_k$ ile yıllık iş hacmi; işgücü zamana göre eşit dağılmaz.

## Detaylı Açıklamalar

- **Proje ölçeği ve araçlar.** Projenin büyüklüğü hangi yönetim ve denetim mekanizmalarının, araçların ve teknolojilerin kullanılacağını belirler. Küçük projelerde basit bir görev listesi ya da hesap tablosu yeterli olabilir. Büyük projelerde iş kalemleri arasında "şu bitmeden şu başlayamaz" türünden bağımlılıklar vardır; bunları elle planlamak zordur, iş planlama yazılımları kullanılır. Kod yönetim araçları (Git gibi) kod havuzuna katkıyı kurallara bağlar, belirli eşikleri geçemeyen kodu havuza almaz ve sürümleri dondurarak saklar. Hoca, demodan önce eklenen bir kod smoke testi bozarsa testi geçmiş önceki sürüme dönüp demoyu onunla yapmanın hayat kurtardığını söyledi.

- **Planlama yaklaşımları.** Basitlik yaklaşımına göre ayrıntılı planlar değişikliklere karşı hassastır ve çabuk geçersizleşir; sürekli yeniden plan yapmak gerekir. Geleneksel yaklaşıma göre plan bir yol haritasıdır ve ayrıntı kaybolma olasılığını düşürür. Çevik yaklaşım ikisini dengeler: ön hazırlık şarttır, ama harita proje ilerledikçe ayrıntılanır. Hoca kendini çevik yaklaşımdan yana gördüğünü, ancak yazılım evinin süreçlerine ve proje ölçeğine göre diğer iki yaklaşımın da seçilebileceğini söyledi.

- **Planlama ilkeleri.** Sınırları belli olmayan proje ya yarı yolda kalır ya da gereksiz yere uzar. Müşteri öncelikleri, sınırları ve zamanlamayı belirler. Ekip ise gerçekçiliği korumak için pazarlık yapar: istenen süre yetmiyorsa süre uzatılır ya da iş alt fazlara bölünür. Kestirimin doğruluğu, kullanılan bilginin kapsamına, doğruluğuna ve belirginliğine bağlıdır; geçmiş deneyime dayalı tahminler bazen matematiksel modellere yakın sonuç verir. Ekip üyelerinin kapasitesi çalışma ve güdülemeyle bir noktaya kadar artar, sınırsız artmaz: "Yazılımcı süpermen veya robot değildir." Plan izlenir; sapma varsa nedeni araştırılır, gereksinimlerdeki zorunlu değişikliklerden kaynaklanıyorsa yeniden planlama yapılır.

- **Reaktif ve proaktif risk yönetimi.** Hoca itfaiyeci ile işçi/elektrikçi benzetmesini kullandı. Elektrik altyapısındaki bir sorundan çıkan yangını itfaiyeci gelip söndürür; bu reaktiftir ve kayıpları azaltır. Proaktif yaklaşımda ise elektrik mühendisi planı simülasyonlardan geçirir, işçiler kablolamayı düzgün yapar, elektrikçiler sigorta panolarını dikkatle bağlar, müteahhit kaliteli malzeme kullanır; böylece yangın baştan önlenir. Slaytta aynı düşünce "Kızını dövmeyen dizini döver" sözüyle de verildi (ekrandan, 00:45:00).

- **Risk çeşitleri.** Proje riskleri proje planını tehdit eder. Gerçekleşirse zamanlama sarkar, personele daha uzun süre ödeme yapıldığı için maliyet artar. Örnekler: bütçe (nakit akışı sağlanamazsa proje batar), zaman (kestirim hataları), personel (nitelikli personeli kurumda tutmak giderek zorlaşıyor). Teknik riskler yazılımın kalitesini ve zamanında bitmesini etkiler. Gerçekleşirse gerçekleme zorlaşır, hatta imkânsızlaşır. Örnek: ilk kez kullanılan ya da "son teknoloji" bir çatı. Öğrenme eğrisi yüksek olabilir, bilinmeyen hatalar (bug) içerebilir, belgelemesi eksik olabilir, yarın da yaşayıp yaşamayacağı belirsizdir. Desteği kesilirse yapılan yatırım boşa gider. İşletme riskleri pazar (ürüne talep olacak mı?) ve satış (pazarlama ekibi ürünü nasıl satacağını biliyor mu?) riskleridir. Hoca bunların daha çok MIS/MBA konuları olduğunu söyledi (ekrandan, 00:50:00).

- **Risk tablosu ve grafik.** Risk işleme tüm ekip ya da farklı departmanlardan kişilerin oluşturduğu bir risk ekibiyle yapılır. Herkes kendi uzmanlık alanındaki riskleri adlandırır. Teknik risk örnekleri: planlanandan düşük yeniden kullanım oranı (ör. kodun %30'unun eski projelerden karşılanacağı planlanmışsa ve tutmazsa ek mesai ya da plan ötelemesi gerekir), kullanılan gereçlerde deneyimsizlik. Olasılık ve etki 3, 4 ya da 5 basamaklı ölçekle (düşük, orta, yüksek gibi) değerlendirilir. Tablo ID, ad, çeşit, olasılık ve etki sütunlarından oluşur (ekrandan, 00:55:00). Riskler olasılık-etki grafiğine ID'leriyle yerleştirilir ve grafik dört bölgeye ayrılır. Sağ üst (olasılığı ve etkisi yüksek) mutlaka izlenir. Sol alt hiç izlenmez. Sağ alt (olası ama etkisi küçük) ve sol üst (olasılığı düşük ama gerçekleşirse yıkıcı) ise projenin, yazılım evinin ve müşterinin durumuna göre seçilir. <!-- BELİRSİZ: Derste 9 riskli örnek tablo ve grafik ekranda gösterildi ama bu slaytın karesi yok; tablo satırları ve hangi riskin hangi bölgeye düştüğü (9 numaralı risk sağ üstte, 4, 7, 8 sol altta) yalnız altyazıdan alındı. -->

- **Örnek risk bilgi sayfası** (ekrandan, 01:00:00): Risk #09: Pazarlama. Olasılık: Yüksek. Etki: Büyük. Türü: Ticari. Açıklama: Firma yalnız yazılım geliştiricilerden oluşan çekirdek kadroyla çalışmaktadır; ürünün piyasada çok fazla alternatifi vardır. İşaretler: (1) müşteri adaylarıyla görüşmede dinleyicilerin ilgisizliği ve "Biz zaten X yazılımını kullanıyoruz. Neden sizi seçelim?" türü yorumlar; (2) bakım aşamasının ilk altı ayında ürünün kendini amorti etme oranının %50'nin altında kalması. Önlemler: (1) bir programcıya MBA yaptırmak; (2) gereksinim mühendisliği aşamasında konu uzmanlığı odaklı danışmanlık hizmeti almak; (3) bir ya da iki firmayla pilot uygulama yapmak ve bu firmalara ürünü özel indirimle satmak. Hoca birinci işaretin öznel olduğunu, ikincisinin ise süresi, miktarı ve oranı belli nesnel bir işaret olduğunu vurguladı. Ürünün bir yılda kendini amorti etmesi planlanıyorsa altı ayda yaklaşık %50, üç ayda yaklaşık %25 beklenir. Pilot uygulama bir kazan-kazan durumudur: ürün sahada, gerçek ortamlarda ve farklı kullanıcılarca sınanır, hatalar erken bulunur; kazancın bir kısmı da indirimle pilot müşteriyle paylaşılır.

- **Takım yöneticisi.** Takım yöneticisi teknik ekibin bir parçası olduğu için teknik yetenekleri yüksek olmalıdır. İşi ağırlıklı olarak insanlarla ilgili olduğundan sosyal ve yönetimsel yetenekleri de yüksek olmalıdır. Teknik proje yöneticisi ve teknik olmayan proje yöneticisi olmak üzere iki yaklaşım vardır. Teknik olmayan yönetici endüstri mühendisliği ya da işletme gibi alanlardan gelebilir; bazen projenin konu alanında uzmandır (ör. CAD/CAM yazılımında makine mühendisi). İkisi birlikte çalışıyorsa yetki sınırları iyi belirlenmelidir, yoksa yetki çatışması takım ruhunu bozar. İyi bir teknik yönetici ekibi istekli kılar, kişileri ve süreci ürüne göre küçük ya da büyük ölçekte düzenler, ekibi yaratıcı fikirlere teşvik eder, iyi bir sorun çözücüdür (tanı koyar, plan yapar, seçtiği çözüm tıkanınca ısrar etmez) ve sorumluluk alır (ekrandan, 01:20:00). Hoca, görüştüğü bir teknik yöneticinin kendini "müşteri ile teknik ekip arasında sıkışmış bir sünger" gibi hissettiğini aktardı; çünkü paydaşların çıkarları çatışabilir.

- **Takım ruhu.** Takım üyeleri birbirine saygı duymalı, ortak amaç (çalışan, doğru yazılımı zamanında müşteriye sunmak) etrafında kenetlenmeli ve birbirini tamamlayan yeteneklere sahip olmalıdır. Örneğin ayrıntıya önem veren biriyle yaratıcı düşünen biri birbirinin zayıf yanını kapatır. Takım ruhunu bozan etkenler (ekrandan, 01:25:00): telaşlı iş ortamı (sürekli acil işlerin bıraktığı zihinsel yorgunluk), sık hayal kırıklığı ve başarısızlıkların üyeler arasındaki sürtüşmeyi artırması (insanlar kusuru hep başkasında arar), doğru yönetilemeyen süreç (klasik süreçte sıkı denetim mekanizmaları gevşetilirse ya da sürecin parçaları bütünlüğü bozacak biçimde değiştirilirse) ve takım yapısının ve rollerinin belirsiz tanımlanması (ya aynı işi iki kişi sahiplenir ya da kimse yapmaz).

- **Takım yapıları.** Kapalı yaklaşım geleneksel yetki hiyerarşisi ve denetim mekanizmaları içerir. Şelale gibi geleneksel süreçlere uygundur ve geçmişte başarılmış benzer projeleri tekrarlamakta başarılıdır, ama yaratıcılığı engeller; Ar-Ge projelerine uygun değildir. Rastgele yaklaşımda takım üyeleri bireysel ve teknik yeteneklerine göre kendi aralarında örgütlenir. Yaratıcı fikirler için en uygun yaklaşımdır ama disiplin sağlamak zordur. Açık yaklaşım bu ikisinin arasında yer alır: denetim mekanizmaları vardır ama yapılanma serbest ve demokratiktir. Karmaşık problemlerin çözümüne uygundur. Örneğin 7 kişilik bir takımda 6 üyenin oyları 3-3 bölünürse eşitliği yöneticinin oyu bozar. Tartışmalar uzarsa yönetici "kifayet-i müzakere" deyip kararı verir; verimlilik sağlamak zordur. Eşzamanlı yaklaşım, takıma düşen problem alt parçalara ayrılabildiğinde kullanılır: her alt takım bir parçada çalışır, alt takımlar arası etkileşim azdır. RAD sürecinin avantaj ve dezavantajları burada da geçerlidir (ekrandan, 01:35:00).

- **Haberleşme.** Resmi yollar yazı (e-posta da yazıdır), zamanlı ve kurallı mesajlaşma ve zamanlanmış toplantılardır; belli bir form ve protokolle yürür. Gayri resmi yollar sözlü iletişim, kişisel etkileşim ve gün içinde gerektikçe yapılan, yalnız ilgililerin katıldığı görüşmelerdir (ekrandan, 01:35:00).

- **Proje ölçümü ve süreç ölçümü.** Proje ölçümü, proje ilerlemesinin ve proje çıktısı olan yazılımın ölçülmesidir. Odağı teknik düzeydir, amacı iç kalite ölçütlerini (geliştirici ekibi ilgilendiren nitelikler) yüksek tutmaktır, yöntemi ölçüm sonuçlarına göre ekibi iyiye yönlendirmektir. Süreç ölçümü yazılım geliştirme sürecinin ölçülmesidir. Odağı yönetimsel düzeydir, amacı dış kalite ölçütleridir (kullanıcıyı ilgilendiren nitelikler). Yöntemi, sürecin tüm aşamalarında istatistik tutup süreçleri teknik ve yönetimsel açıdan iyileştirmektir (ekrandan, 01:40:00). Örnek: hata bulma etkinliği düşükse otomatik test durumu üretme araçlarına geçilir; kritik hatalara dönüşler aksıyorsa hatalara önem derecesi verilip dereceye göre farklı dönüş süresi tanımlanır. Bu, CMM'nin 5. düzeyindeki (optimizing) sürekli iyileştirmeye koşuttur.

- **Kaliteyle ilgili etkenler ve gizlilik** (ekrandan, 01:45:00). Kişiler (yetenek ve isteklilik en önemli etkendir), ürün (karmaşıklık kaliteyi olumsuz etkiler, artan zorluk takımın maneviyatını kırabilir), teknoloji (araç ve donanımın olgunluğu, yeterliliği, etkinliği ve eğitimsel belgeleri), çevresel koşullar (müşterinin iletişim ve işbirliği yeteneği, iş akışı kuralları, şirket kültürü). Ölçüt toplama düzeyleri: bireysel düzey kişiye, takım düzeyi takıma, proje düzeyi tüm çalışanlara özel olmalıdır. Başka bir yaklaşımda üst, astlarının ölçütlerini izleyebilir ama denkler birbirininkini göremez. Amaç insanları utandırmak, övmek ya da tehdit etmek olmamalıdır.

- **Süreç ölçütleri** (ekrandan, 01:50:00). Bakım aşamasından önce ve sonra bulunan hataların sayısı ayrı öneme sahiptir, çünkü sahaya çıkmış yazılımda hata düzeltmek çok daha zordur. Hata giderme etkinliği:
  - $\text{HGE} = \dfrac{\text{TÖ}}{\text{TÖ} + \text{TS}}$; $\text{TÖ}$: ürünün müşteriye tesliminden önce bulunan hata sayısı, $\text{TS}$: teslimden sonra (bakım aşamasında) bulunan hata sayısı. $\text{TÖ}$ arttıkça $\text{HGE}$ %100'e yaklaşır.
  - $\text{TÖ}$ ve $\text{TS}$ yerine sürecin ardışık adımları $A(i)$ ve $A(i+1)$ kullanılabilir. Örneğin $A(i)$ çözümlemede bulunan hata sayısı, $A(i+1)$ tasarımda bulunan çözümleme kaynaklı hata sayısıdır: $\text{HGE}_i = \dfrac{A(i)}{A(i) + A(i+1)}$. Çevik süreçte ardışık iterasyonlar kullanılabilir. Etkinlik azalma eğilimindeyse sınamaya daha fazla zaman, ek iterasyon ya da daha fazla regresyon testi gibi önlemler alınır.
  - Doğruluk: bulunan hata sayısının proje boyutuna (ör. kod satırına) oranı. Bakım kolaylığı: bir hatanın bulunması ile giderilmesi arasında geçen zaman (ortalaması); bu değer bakım ekibinin yeteneğinden de etkilenir. Güvenlik: bulunan güvenlik açıkları ve ciddilik düzeyleri.

- **Bilirkişi takdiri ve Delphi.** Bilirkişi takdiri, maliyeti ve süresi bilinen eski projelerle yeni projenin karşılaştırılmasıdır. Doğruluğu bilirkişinin deneyimine ve iki proje arasındaki farkları doğru hesaplamasına bağlıdır. Delphi yöntemi, sosyal bilimlerdeki bir anket yönteminin proje takdirine uyarlanmasıdır. Tahmini tek kişiye bağımlı olmaktan çıkarıp hatayı azaltmayı amaçlar. Koordinatör bilirkişilere sistem tanımlama belgelerini ve tahmin formunu verir; bilirkişiler birbirinden habersiz, gerekçeli tahminlerini yazılı bildirir. Koordinatör ortanca ve aykırı sonuçları paylaşıp yeniden tahmin ister. Bu, ortak bir değere yaklaşılıncaya kadar yinelenir (ekrandan, 02:15:00). Tahminlerin tam eşitlenmesi gerekmez; belirli bir oranda (ör. %10) yakınsama yeterlidir ve buna koordinatör karar verir.

- **Analiz yöntemi** (ekrandan, 02:20:00). Ürün ya da üretim hiyerarşik olarak öğelerine ayrılır, en alt öğelerden başlanarak yukarı doğru gider takdir edilir. Ürün analiz kartı: Ürün altında Girdi Sistemi (Oku Modülü, Veri Yapıları Alt Sistemi), Değiştirme Alt Sistemi (Veri Denetimi, Bilgisayar Sonuçları) ve Çıktı Alt Sistemi; hocanın anlatımına göre çıktı alt sisteminin alt bileşeni yoktur. <!-- BELİRSİZ: Karede "Bilgisayar Sonuçları" kutusunun hangi alt sisteme bağlı olduğu çizgilerden net okunmuyor; altyazıya göre değiştirme alt sistemi altına yazıldı. --> Üretim analiz kartı: Proje Yönetimi (Plan, İnceleme), Geliştirme (Tasarım, Kodlama, Birim Testi), Sınama (Birleştirme, Kabul), Servisler (Yayın, Bakım), Garanti. Birim testi geliştirmenin altındadır, çünkü kodu yazan kişi yapar. Giderler KLOC ya da FP ve kişi-ay ölçülerine dayanır; kişi-ay kişi sayısına bölünerek süre bulunur. Bir kalem için birden çok tahmin varsa en kötü ($a$) ve en iyimser ($b$) tahmine 1, en olası ($m$) tahmine 4 ağırlık verilir: $E = \dfrac{a + 4m + b}{6}$.

- **İstatistiksel modeller** (ekrandan, 02:25:00). Doğrudan ölçülemeyen bir değer ($y$), ölçülebilen bir bağımsız değişkenle ($x$) $y = f(x)$ biçiminde kestirilir. Yazılımda genellikle $y = a x^b$ kullanılır. $x$ adayları: KLOC, fonksiyon noktası (FP), proje süresi (T), iş hacmi (H). $y$ adayları: iş hacmi, proje süresi, belge sayfası, KLOC. Kestirilen değişken bağımsız değişken olarak kullanılmaz. $a$ ve $b$ geçmiş projelerin verilerinden en küçük kareler yöntemiyle bulunur.
  - Walston-Felix (60 proje, 4.000-467.000 satır kod): $H = 5{,}2 \cdot KLOC^{0{,}91}$ (kişi-ay); $T = 4{,}1 \cdot KLOC^{0{,}36}$ ya da $T = 2{,}47 \cdot H^{0{,}35}$; işgücü $I = 0{,}54 \cdot H^{0{,}06}$; belge sayfası $B = 49 \cdot KLOC^{1{,}01}$. <!-- BELİRSİZ: Walston-Felix slaytının karesi yok; katsayılar altyazıdan. İşgücü katsayısı altyazıda "0.4" duyuluyor; aynı slaytın başka yıl kaydında 0,54 olduğu görüldü, burada 0,54 yazıldı. --> Kendi firmanızın geçmiş projelerinden farklı katsayılar bulabilirsiniz.
  - COCOMO (B. Boehm, Constructive Cost Model; 63 proje) üç basamaklıdır: Temel, Orta (EAF çaba düzeltme çarpanı eklenir) ve İleri (sürecin her aşaması için ayrı fonksiyon) (ekrandan, 02:30:00). Temel COCOMO: $H = a \cdot KLOC^b$, $T = c \cdot H^d$. Uygulama programları $H = 2{,}4 \cdot KLOC^{1{,}05}$, $T = 2{,}5 \cdot H^{0{,}38}$; yardımcı programlar $H = 3{,}0 \cdot KLOC^{1{,}12}$, $T = 2{,}5 \cdot H^{0{,}35}$; sistem yazılımları $H = 3{,}6 \cdot KLOC^{1{,}20}$, $T = 2{,}5 \cdot H^{0{,}32}$. <!-- BELİRSİZ: Temel COCOMO tablosunun karesi yok; katsayılar altyazıdan alındı. --> Hocanın yorumu: sistem yazılımları en zor ve kritik olduğu için iş hacmi katsayıları en büyüktür. Uygulama programlarında gereksinimler daha hızlı değiştiği için süre üssü ($0{,}38$) sistem yazılımlarınınkinden ($0{,}32$) büyüktür; sistem yazılımında girdi ve çıktı bellidir.
  - Orta COCOMO: Boehm EAF'ın duruma göre 0,90-1,40 arasında alınmasını önerir. Örnek: bir mikroişlemcide uzaktan haberleşme amacıyla kullanılan 10.000 satır kodlu gömülü sistem yazılımı, EAF = 1,17: $H = 3{,}6 \cdot 10^{1{,}20} \cdot 1{,}17 = 66{,}8$ programcı-ay, $T = 2{,}5 \cdot 66{,}8^{0{,}32} = 9{,}6$ ay (ekrandan, 02:35:00).
  - PNR (Putnam-Norden-Rayleigh): yıllık iş hacmini KLOC'a, teknoloji katsayısı $C_k$'ye ve yıl olarak geliştirme süresine bağlar; süre formülde 4. kuvvetiyle yer alır. $C_k$: düşük teknoloji ortamında 2000, iyi teknoloji ortamında 8000, otomatik yazılım araçlarının kullanıldığı ortamda 12000. İşgücü zamana eşit dağılmaz: kodlama ve gerçekleme aşamasında tepe yapar, sonraki sınama aşamalarında azalır. <!-- BELİRSİZ: PNR slaytının karesi yok; formülün tam biçimi altyazıdan okunamadı, yalnız sürenin 4. kuvveti duyuluyor. --> COCOMO 2'ye girilmedi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
