# Ders 4 Çalışma Özeti

## Genel Konular

- Alt katmanlarla bağlantı
  - Ağ katmanında konuşulan hata kontrolü ve akış kontrolü tek bir katmanda yapılan işler değildir; alt katmanlarda (fiziksel katman, veri bağı katmanı ve ortam erişim kontrolü) neler yapıldığı bilinmeden üst katmandaki işler anlaşılamaz.
  - Ders OSI referans modeli üzerinden anlatılır. Ders kitabının modelinde fiziksel katman dahil altı katman vardır: ilk üç katman veri iletişimi dersinde, sonraki katmanlar bu derste işlenir.
- Yönlendirme (routing) ve iletme (forwarding)
  - Konu listesi (ekrandan, 00:05:00): optimality principle, shortest path algorithm, flooding, distance vector routing, link state routing, hierarchical routing, broadcast routing, multicast routing, anycast routing, routing for mobile hosts, routing in ad hoc networks.
  - Yönlendirme, ağ yollarını keşfetme sürecidir: ağ, düğümler ve bağlantılardan oluşan bir graf olarak modellenir, neyin optimize edileceğine karar verilir (ör. adillik ya da verimlilik), topoloji değişince (ör. arızalar) rotalar güncellenir (ekrandan, 00:25:00).
  - İletme (forwarding), paketlerin belirlenen yol boyunca gönderilmesidir: paketi tampondan al, uygun çıkış hattına koy.
  - Benzetme: yönlendirme ile iletme arasındaki ilişki, işletim sistemindeki zamanlayıcı (scheduler) ile dağıtıcı (dispatcher) arasındaki ilişkiye benzer. Biri kararı verir, öbürü kararı uygular.
  - Optimizasyon ölçütü olarak hat kapasitesinin verimli kullanımı, adillik ya da maliyet seçilebilir. ISS'ler arasında (IXP noktalarında) geçişler anlaşmalara bağlı olarak para tutabilir, bu yüzden maliyet de bir ölçüttür.
  - Yönlendirme algoritması hat özelliklerini toplar, seçilen ölçüte göre optimizasyon yapar ve ağdaki değişikliklere uyum sağlar. Proaktif (bilgiyi ihtiyaçtan önce, periyodik toplar) ya da reaktif (bilgiyi ihtiyaç anında toplar) olabilir.
- Optimallik ilkesi (optimality principle) ve sink tree
  - En iyi yolun her parçası da en iyi yoldur; bir yönlendiriciye giden en iyi yolların birleşimi "sink tree" denen bir ağaçtır. Örnekte "en iyi", en az hop demektir (ekrandan, 00:30:00).
  - Örnek: B'den M'ye en iyi yol B-C-J-N-M ise J ile N, J ile M arasındaki parçalar da en iyidir.
  - Her düğümün kendi sink tree'si vardır; topolojide birden fazla sink tree bulunur.
  - Gidiş ve dönüş yolları aynı olmayabilir (maliyet, güvenlik, politika, teknoloji; ör. uydu bağlantısında yukarı yönün maliyeti çok yüksektir).
- En kısa yol algoritması (Dijkstra)
  - Her bağlantıya negatif olmayan bir ağırlık atanır; en kısa yol toplam ağırlığı en düşük olan yoldur; bütün ağırlıklar 1 alınırsa en az hoplu yol bulunur (ekrandan, 00:35:00).
  - Algoritma: kaynaktan (sink) başla, diğer düğümlere uzaklığı sonsuz yap; uzaklıkları gevşet (relax); en düşük uzaklıklı düğümü sink tree'ye ekle; bütün düğümler ağaca girene kadar tekrarla.
  - Ağırlık fiziksel mesafe değil, maliyet olarak düşünülmelidir.
- Taşırma (flooding)
  - Bir paketi bütün düğümlere göndermenin basit yöntemi: her düğüm yeni gelen paketi geldiği hat dışındaki bütün hatlara gönderir (ekrandan, 00:40:00).
  - En güvenilir dağıtım yöntemidir ama ağı aşırı yükler. Tekrarlanan paketleri durdurmak için düğümler taşırılan paketleri kaydetmelidir; yalnız hop sınırı kullanmak bile üstel büyümeye yol açabilir.
  - Yerel ağlardaki karşılığı broadcast storm olarak bilinir.
- Uzaklık vektörü yönlendirmesi (distance vector)
  - Dağıtık bir algoritmadır; en kısa yol hesabı düğümler arasında paylaştırılır (ekrandan, 00:50:00).
  - Adımlar: her düğüm komşularına olan bağlantı uzaklıklarını bilir; bildiği en düşük uzaklıklardan oluşan vektörü bütün komşularına duyurur; aldığı vektörlerle kendi vektörünü günceller; bu periyodik tekrarlanır.
  - Bellman-Ford adıyla anılır. Uzaklık hop, maliyet, gecikme, hata oranı vb. olabilir.
  - Merkezi ve dağıtık yönlendirme karşılaştırıldı.
- Sonsuza sayma sorunu (count-to-infinity)
  - Arızalar, DV'nin ulaşılamayan bir düğüme yol ararken sonsuza saymasına yol açabilir: iyi haber hızlı yayılır, kötü haber yavaş öğrenilir (ekrandan, 01:00:00).
  - Pratik çözüm olarak sonsuz, 16 hop gibi bir üst sınırla temsil edilmiştir.
- Bağlantı durumu yönlendirmesi (link state)
  - DV'ye alternatiftir: daha fazla hesap ama daha basit dinamik; internette OSPF ve IS-IS olarak yaygındır (ekrandan, 01:25:00).
  - Her düğüm komşu bilgisini LSP'lerle (Link State Packet) taşırır, bütün düğümler tam ağ grafını öğrenir; her düğüm Dijkstra çalıştırarak her hedef için yolu hesaplar.
  - LSP'lerde sıra numarası (Seq.) ve yaş (Age) alanları vardır (ekrandan, 01:30:00).
- Hiyerarşik yönlendirme
  - Rota hesaplama işini azaltır ama düz yönlendirmeye göre biraz daha uzun yollar verebilir (ekrandan, 01:35:00).
- Broadcast, multicast ve anycast yönlendirme
  - Broadcast: bilgi bütün düğümlere gider; reverse path forwarding anlatıldı.
  - Multicast: grup denen düğüm alt kümesine gönderim; her kaynak ve grup için ayrı ağaç (dense case); seyrek durumda core-based tree (ekrandan, 01:45:00).
  - Anycast: paketi grubun bir (en yakın) üyesine gönderir; DNS sunucu gruplarında yük dengeleme ve hata toleransı için kullanılır (ekrandan, 01:50:00).
- Ad hoc ağlarda yönlendirme
  - Kablosuz algılayıcı ağlarında uzaklık vektörünün bir çeşidi (AODV) yeniden karşımıza çıkar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Topolojide birden fazla sink tree vardır
  - Her yönlendirici, her host kendini başlangıç noktası kabul edip kendi sink tree'sini oluşturur; "herkesin ağacı kendine özeldir".
- Flooding önemli bir algoritmadır
  - Kontrolsüz hali ağı yakıp yıkar; ama geldiği hatta geri göndermeme ve daha önce görülen paketi (tekil bir tanımlayıcıyla) tamponda tutup düşürme gibi basit dokunuşlarla kontrollü ve faydalı hale gelir.
  - Yönlendirme algoritmalarını kıyaslamak için temel referanstır; akıllı algoritmaların çoğu kontrollü bir flooding ile başlar.
- DV'de düğüm yalnız doğrudan komşularıyla ilgili değerlerden emindir
  - Komşudan gelen vektördeki diğer değerlerin hangi yol üzerinden hesaplandığını bilmez; sonsuza sayma sorunu buradan doğar.
- Ağırlık mesafe değil maliyettir
  - Kilometre ya da metre gibi düşünülmemeli; para, gecikme, güvenilirlik gibi bir maliyet olarak düşünülmelidir.
- DV tarihsel bir algoritmadır
  - "Nasıl düzeltirim" ile uğraşmak yerine tasarlandığı haliyle, sorunlarıyla birlikte öğrenilmeli; yine de ad hoc ve algılayıcı ağlarında uygulanabilir.

## Kısa Tekrar Notları

- Routing: karar (yolu bulma); forwarding: kararın uygulanması (paketi çıkış hattına koyma).
- Optimallik ilkesi: en iyi yolun her alt yolu da en iyidir; en iyi yolların birleşimi sink tree'dir.
- Dijkstra: negatif olmayan ağırlıklar; ağırlık 1 ise en az hop.
- Flooding: geldiği hat dışındaki her hatta gönder; tekrarları sıra numarası/tanımlayıcı ile durdur.
- DV: komşu uzaklıkları + komşulardan gelen vektörler; yeni uzaklık $= \min_{\text{komşu}} (\text{komşuya gecikme} + \text{komşunun hedefe uzaklığı})$.
- Count-to-infinity: iyi haber hızlı, kötü haber yavaş; sonsuz 16 hop ile sınırlandı.
- Link state: LSP ile flooding, herkes tam grafı bilir, her düğüm Dijkstra çalıştırır; OSPF ve IS-IS.
- LSP'de Seq. (eski/yeni ayrımı) ve Age (paketin sonsuza dek dolaşmasını engelleme) alanları vardır.
- Hiyerarşik yönlendirme: örnekte 1A'nın tablosu 17 satırdan 7 satıra iner.
- Broadcast: herkese; multicast: gruba; anycast: grubun herhangi (en yakın) bir üyesine.

## Detaylı Açıklamalar

- **Yönlendirme ve iletme.** Ağdaki her cihaz, kendisine gelen paketi bir sonraki adımda nereye göndereceğine karar vermelidir. Bu kararın verilmesi yönlendirme, kararı oluşturan yapı yönlendirme algoritmasıdır. Kararın uygulanması, yani paketin tampondan alınıp uygun hattın kuyruğuna konması ise iletmedir. Slayttaki şekilde X ile X' arasında ortak bir hat ve bu hattan A-A', B-B', C-C' yönündeki akışlar gösterilir (ekrandan, 00:25:00). Algoritma hatların özelliklerini toplar, seçilen ölçüte göre (kapasite, adillik, maliyet, hız) optimizasyon yapar ve topolojideki değişikliklere uyum sağlar.
- **Optimallik ilkesi.** Slayttaki A'dan O'ya kadar adlandırılmış ağda B için çizilen sink tree şu bağlantılardan oluşur (ekrandan, 00:30:00): B-A, B-C, A-D, A-F, D-G, D-H, F-K, K-L, C-I, C-J, J-E, J-N, N-M, N-O. Ağırlıklar eşit (hop) alındığında B'den M'ye yol B-C-J-N-M olup 4 hoptur; B'den E'ye yol B-C-J-E olup 3 hoptur. B'den M'ye en iyi yol C, J ve N üzerinden geçiyorsa, J ile N arasındaki yol da en iyidir; öyle olmasaydı daha iyi bir yol bulunmuş olurdu. Böylece bir kaynak ile hedef arasındaki ara düğümler için de yönlendirme bilgisi elde edilir. Kavram tek yönlü (bir yöne giden trafik) için konuşulur; ters yöndeki trafiğin optimal yolu farklı olabilir.
- **En kısa yol.** Topoloji bir graftır ve başlangıçta bağlantılar çift yönlü kabul edilir. Dijkstra algoritması her bağlantıya negatif olmayan ağırlık atanmış grafta sink tree hesaplar (ekrandan, 00:35:00). Kavramsal denemelerde önce hop sayısıyla başlanır, sonra güvenilirlik, güvenlik ya da maliyet gibi farklı ağırlıklar eklenir. Uydu örneğinde uydudan aşağı göndermenin maliyeti düşük, yukarı göndermenin maliyeti çok yüksektir; yani iki yöndeki ağırlıklar farklı olabilir. Slayttaki A'dan D'ye adım adım Dijkstra örneği derste ayrıntılı anlatılmadı; algoritmalar dersindeki bilginin kullanılacağı söylendi.
- **Flooding.** Topolojide ne olursa olsun bilginin bütün düğümlere ulaşması isteniyorsa en garantili yöntem flooding'dir; hoca bunu sel taşkınına benzetti. Unicast için kullanılırsa, bir arkadaşa bir şey iletmek için herkesin birbirinin kulağına söylemesi gibidir. Optimallik ilkesi şeklindeki ağda B'nin iki, A'nın üç, D'nin dört komşusu vardır. Kontrolsüz flooding'de D her geleni dört yöne gönderir. İlk iyileştirme: paket hangi hattan geldiyse oraya geri gönderilmez (D'ye I'dan geldiyse yalnız H, G ve A'ya gider). İkinci iyileştirme: aynı paket I-J-E-H üzerinden dolaşıp D'ye yeniden gelebileceği için düğüm daha önce gördüğü paketleri tamponda tutar ve tekrar geleni düşürür; bunun için pakette tekil bir tanımlayıcı gerekir.
- **Merkezi ve dağıtık yönlendirme.** Merkezi yaklaşımda bir koordinatör bütün topoloji bilgisini toplar, her düğüm için sink tree'yi çevrim dışı hesaplar ve dağıtır. Küçük ve sık değişmeyen topolojilerde uygundur, hatta tasarım sırasında elle hesaplanabilir (by design); avantajı topoloji hakkında ayrıntılı bilgidir. Büyük topolojilerde bilgiyi toplamak bile yönlendirme gerektirir ve dağıtım bitmeden topoloji değişir. Bu yüzden böl ve yönet yaklaşımıyla dağıtık yapılır; bedeli, düğümlerin yalnız çevrelerini görmesidir. Hoca bunu İstanbul'dan Ankara'daki bir adrese gitme örneğiyle anlattı: yola çıkarken Ankara'daki sokağı değil, Ankara'ya nasıl çıkılacağını sorarsınız.
- **Uzaklık vektörü örneği.** Derste J düğümünün yeni vektörünü hesapladığı örnek anlatıldı (derste sözlü, 00:55:26). J'nin komşularına ölçtüğü gecikmeler: A'ya 8, I'ya 10, H'ye 12, K'ya 6. A'dan gelen vektör: A 0, B 12, C 25, D 40, E 14, F 23, G 18, H 17, I 21, J 9, K 24, L 29. J'nin B'ye uzaklığı: A üzerinden $12+8=20$, I üzerinden $36+10=46$, H üzerinden $31+12=43$, K üzerinden $28+6=34$; en küçüğü 20 (A üzerinden). C'ye uzaklık: $25+8=33$, $18+10=28$, $19+12=31$, $36+6=42$; en küçüğü 28 (I üzerinden). <!-- BELİRSİZ: Bu örneğin slaytı karelerde yok; değerler altyazıdan alındı. -->
  - Ders sonrası not: Hoca I üzerinden B için "36 artı 8, 44" dedi; J-I gecikmesi 10 olduğundan doğrusu $36+10=46$'dır. Sonuç (20, A üzerinden) değişmez.
- **Sonsuza sayma.** Slayttaki A-B-C-D-E zincirinde (ekrandan, 01:00:00) A ağa katılınca B 1, C 2, D 3, E 4 değerini sırasıyla 1, 2, 3, 4 değişimden sonra öğrenir. A'nın bağlantısı kopunca ise tablodaki değerler şöyle ilerler:

  | Değişim | B | C | D | E |
  |---|---|---|---|---|
  | Başlangıç | 1 | 2 | 3 | 4 |
  | 1 | 3 | 2 | 3 | 4 |
  | 2 | 3 | 4 | 3 | 4 |
  | 3 | 5 | 4 | 5 | 4 |
  | 4 | 5 | 6 | 5 | 6 |
  | 5 | 7 | 6 | 7 | 6 |
  | 6 | 7 | 8 | 7 | 8 |

  B, A'ya doğrudan ulaşamaz ama C'nin "A'ya 2" bilgisine güvenerek 3 der; C bunu görüp 4 der, böyle devam eder. Hoca bunu "kötü haber tez duyulur" sözünün tersi olarak anlattı. Topolojinin kaç hop genişliğinde olduğu bilinmediği için çözüm, 16 hop'un sonsuz (ulaşılamaz) kabul edilmesi olmuştur; bu değer o dönemin küçük topolojilerine göre seçilmiştir.
- **Link state ve LSP'ler.** Slayttaki ağda bağlantılar ve ağırlıkları: A-B 4, A-E 5, B-C 2, B-F 6, C-D 3, C-E 1, D-F 7, E-F 8 (ekrandan, 01:30:00). Her düğümün LSP'si Seq. ve Age alanlarından sonra komşularını ve ağırlıklarını listeler: A (B 4, E 5), B (A 4, C 2, F 6), C (B 2, D 3, E 1), D (C 3, F 7), E (A 5, C 1, F 8), F (B 6, D 7, E 8). Sıra numarası eski ve yeni paketlerin karışmasını önler ve flooding'de "bu paketi daha önce ilettim mi" kontrolünde tanımlayıcı olarak kullanılır. Age alanı ise paketin ağda sonsuza dek dolaşmasını engeller; her düğümde azaltılır, sıfıra inince paket düşürülür. Yeni LSP'ler geldikleri hatta onaylanır (acknowledge) ve diğer hatlara iletilir; böylece güvenilir, kontrollü bir flooding yapılır. Herkes topolojinin tamamını bildiği için DV'deki sonsuza sayma sorunu oluşmaz. Önemli ayar güncelleme sıklığıdır: çok sık güncelleme flooding'e dönüşür, çok seyrek güncelleme ağdaki değişikliklerin kaçırılmasına yol açar.
  - Ders sonrası not: Hoca IS-IS'i "inter-system routing" diye açtı; doğrusu büyük olasılıkla "Intermediate System to Intermediate System"dir.
  - Ders sonrası not: Hoca OSPF dokümanlarında yerel ağlar için 3 saniyelik bir güncelleme aralığı geçtiğini söyledi; OSPF'te yayın ağlarındaki varsayılan Hello aralığı büyük olasılıkla 10 saniye, LSA yenileme süresi 30 dakikadır.
  - Ders sonrası not: Hoca age/TTL alanının günümüzde istisnasız hop cinsinden verildiğini söyledi; bu IP başlığındaki TTL için doğrudur, OSPF'te LSA yaşı ise büyük olasılıkla saniye cinsinden tutulur (en fazla 1 saat).
- **Hiyerarşik yönlendirme.** Slayttaki örnekte beş bölge vardır; bölgelerdeki yönlendirici sayıları 3, 4, 2, 3, 5 olup toplam 17'dir (ekrandan, 01:35:00). 1A'nın tam tablosu 17 satır, hiyerarşik tablosu 7 satırdır:

  | Hedef | Hat | Hop |
  |---|---|---|
  | 1A | – | – |
  | 1B | 1B | 1 |
  | 1C | 1C | 1 |
  | 2 | 1B | 2 |
  | 3 | 1C | 2 |
  | 4 | 1C | 3 |
  | 5 | 1C | 4 |

  Bölge 5 için seçilen 1C hattı 5C dışındaki düğümler için en iyi seçimdir; tam tabloda 5C'ye 1B üzerinden 5 hopla gidilir. Kendi bölgesindeki bilgiyi ayrıntılı, diğer bölgeleri ise yalnız "oraya nasıl gidilir" düzeyinde tutmak tablo boyutunu ve yönlendirme trafiğini azaltır. Hoca kampüsteki fakülte ve bölümleri bilme örneğini verdi.
- **Broadcast ve reverse path forwarding.** Bilgi bütün düğümlere yayılırken geçtiği yerler pakete eklenirse geriye doğru yol bulunur; hoca bunu Hansel ile Gretel'in ekmek kırıntılarına benzetti. Önce ileri yönde yayın (flooding), sonra geri yönde yol oluşturulur.
  - Ders sonrası not: Reverse path forwarding'in kitaptaki tanımı büyük olasılıkla şöyledir: yönlendirici bir broadcast paketini, kaynağa paket gönderirken kendisinin kullandığı hattan geldiyse diğer hatlara iletir, başka bir hattan geldiyse kopya sayıp atar.
- **Multicast.** Slayttaki yoğun (dense) örnekte grup 1 ve grup 2 üyeleri olan bir ağda S kaynağından yayılan ağaç, gruplara ait olmayan dallar budanarak grup 1 ve grup 2 için ayrı multicast ağaçlarına dönüştürülür (ekrandan, 01:45:00). Seyrek (sparse) durumda her kaynak için ayrı ağaç yerine bir çekirdek (core) etrafında ortak ağaç kurulur: gönderici paketi çekirdeğe ya da ağaç üzerindeki en yakın düğüme gönderir, paket ağaç boyunca hop hop dağıtılır ve geldiği yöne geri gönderilmez.
- **Anycast.** Paket grubun bir (en yakın) üyesine gönderilir; normal yönlendirme, birçok yerde bulunan tek bir düğüme yönlendirme gibi işler (ekrandan, 01:50:00). Coğrafi anycast araçlar arası haberleşmede (fren ya da kaza bilgisi arkadaki araçlardan birine gider, o da yayar) ve eşdeğer DNS sunucularında yük dengeleme ve hata toleransı için kullanılır.
- **Ad hoc ağlar.** Önceden tasarlanmayan, düğümlerin açıldıkları anda kablosuz bağlantılarla komşularını belirledikleri ağlardır. Algılayıcı ağlarında yükü hafif ve basit olduğu için uzaklık vektörü (AODV) yeniden kullanılır.
  - Ders sonrası not: Hoca AODV'yi "ad hoc distance vector" diye açtı; doğrusu "Ad hoc On-demand Distance Vector"dür.
- Ders, ağ katmanında tıkanıklık kontrolüne (congestion control) giriş slaytıyla bitti; bu konunun ağ ve taşıma katmanlarının ortak sorumluluğu olduğu ve sonraki derste devam edileceği belirtildi (ekrandan, 01:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
